using Rathalos.Core.Utils.Cryptography;
using Rathalos.Core.Utils.IO;
using System.Text;

namespace Rathalos.Core.Protocol.Tools
{
    public sealed class CryXmlReader
    {
        private struct CryXmlNode
        {
            public int NameOffset;
            public int ContentOffset;
            public short AttributeCount;
            public short ChildCount;
            public int ParentId;
            public int FirstAttrIdx;
            public int FirstChildIdx;
            public int Reserved;
        }

        private struct CryXmlReference
        {
            public int NameOffset;
            public int ValueOffset;
        }

        public const uint Magic = 0x686DFFFF;
        private readonly byte[] _encContent;

        public CryXmlReader(byte[] encContent)
        {
            _encContent = encContent;
        }

        public string Content { get; private set; }

        public static CryXmlReader Create(byte[] encContent)
        {
            var reader = new CryXmlReader(encContent);
            reader.Read();
            return reader;
        }

        public void Read()
        {
            var reader = new FastLittleEndianReader(_encContent);
            var magic = reader.ReadUInt();
            if (magic != Magic)
                throw new InvalidOperationException("Invalid magic number for CryXml format.");

            var fileContent = reader.ReadBytes((uint)reader.BytesAvailable);
            var decryptedContent = CryXmlCrypto.Decrypt(fileContent);
            using (MemoryStream ms = new MemoryStream(decryptedContent))
            using (BinaryReader br = new BinaryReader(ms))
            {
                // 1. Read Header
                // Read C-style string for signature
                string signature = ReadCString(br);

                // C++ uses strncmp(header, "CryXmlB", 7)
                if (signature != "CryXmlB")
                {
                    Content = Encoding.UTF8.GetString(decryptedContent);
                    return;
                }

                int fileSize = br.ReadInt32();

                // Table Offsets and Counts
                int nodeTableOffset = br.ReadInt32();
                int nodeTableCount = br.ReadInt32();

                int attrTableOffset = br.ReadInt32();
                int attrTableCount = br.ReadInt32();

                int childTableOffset = br.ReadInt32();
                int childTableCount = br.ReadInt32();

                int dataTableOffset = br.ReadInt32();
                int dataTableSize = br.ReadInt32();

                // 2. Read Node Table
                ms.Position = nodeTableOffset;
                var nodes = new CryXmlNode[nodeTableCount];
                for (int i = 0; i < nodeTableCount; i++)
                {
                    nodes[i] = new CryXmlNode
                    {
                        NameOffset = br.ReadInt32(),
                        ContentOffset = br.ReadInt32(),
                        AttributeCount = br.ReadInt16(),
                        ChildCount = br.ReadInt16(),
                        ParentId = br.ReadInt32(),
                        FirstAttrIdx = br.ReadInt32(),
                        FirstChildIdx = br.ReadInt32(),
                        Reserved = br.ReadInt32()
                    };
                }

                // 3. Read Attribute Table
                ms.Position = attrTableOffset;
                var attributes = new CryXmlReference[attrTableCount];
                for (int i = 0; i < attrTableCount; i++)
                {
                    attributes[i] = new CryXmlReference
                    {
                        NameOffset = br.ReadInt32(),
                        ValueOffset = br.ReadInt32()
                    };
                }

                // Note: The C++ code reads the Child Table but doesn't actually use it 
                // for the logic (it relies on ParentId). We skip reading it to save resources.

                // 4. Construct XML Document using string builder to preserve original names
                var xmlBuilder = new StringBuilder();
                var nodeContents = new string[nodeTableCount];
                var nodeBuilders = new StringBuilder[nodeTableCount];

                // Initialize builders for each node
                for (int i = 0; i < nodeTableCount; i++)
                {
                    nodeBuilders[i] = new StringBuilder();
                }

                // The C++ logic iterates attributes sequentially using a global index
                int globalAttrIndex = 0;

                // Base offset for string lookups (data table)
                int stringBaseOffset = dataTableOffset;

                // Pass 1: Build opening tags with attributes and collect text content
                for (int i = 0; i < nodeTableCount; i++)
                {
                    CryXmlNode node = nodes[i];
                    var sb = nodeBuilders[i];

                    // Read Tag Name (preserve original, just escape XML special chars in values)
                    string tagName = ReadStringAt(decryptedContent, stringBaseOffset + node.NameOffset);
                    if (string.IsNullOrEmpty(tagName)) tagName = "Unknown";

                    sb.Append('<').Append(tagName);

                    // Process Attributes
                    for (int j = 0; j < node.AttributeCount; j++)
                    {
                        if (globalAttrIndex < attrTableCount)
                        {
                            var attrRef = attributes[globalAttrIndex];
                            string attrName = ReadStringAt(decryptedContent, stringBaseOffset + attrRef.NameOffset);
                            string attrValue = ReadStringAt(decryptedContent, stringBaseOffset + attrRef.ValueOffset);

                            if (!string.IsNullOrEmpty(attrName))
                            {
                                sb.Append(' ').Append(attrName).Append("=\"").Append(EscapeXmlValue(attrValue)).Append('"');
                            }
                            globalAttrIndex++;
                        }
                    }

                    sb.Append('>');

                    // Store text content
                    string textContent = ReadStringAt(decryptedContent, stringBaseOffset + node.ContentOffset);
                    nodeContents[i] = textContent;
                }

                // Pass 2: Build complete XML with hierarchy
                // We need to process nodes in order, adding children between open and close tags
                var processedChildren = new List<int>[nodeTableCount];
                for (int i = 0; i < nodeTableCount; i++)
                {
                    processedChildren[i] = new List<int>();
                }

                // Group children by parent
                for (int i = 0; i < nodeTableCount; i++)
                {
                    int parentId = nodes[i].ParentId;
                    if (parentId >= 0 && parentId < nodeTableCount)
                    {
                        processedChildren[parentId].Add(i);
                    }
                }

                // Recursive function to build node XML
                string BuildNodeXml(int nodeIndex)
                {
                    var node = nodes[nodeIndex];
                    string tagName = ReadStringAt(decryptedContent, stringBaseOffset + node.NameOffset);
                    if (string.IsNullOrEmpty(tagName)) tagName = "Unknown";

                    var result = new StringBuilder();
                    result.Append(nodeBuilders[nodeIndex]);

                    // Add text content if present and no children
                    var children = processedChildren[nodeIndex];
                    if (!string.IsNullOrEmpty(nodeContents[nodeIndex]))
                    {
                        result.Append(EscapeXmlValue(nodeContents[nodeIndex]));
                    }

                    // Add children
                    foreach (int childIndex in children)
                    {
                        result.Append(BuildNodeXml(childIndex));
                    }

                    // Close tag
                    result.Append("</").Append(tagName).Append('>');

                    return result.ToString();
                }

                // Find root nodes and build XML
                for (int i = 0; i < nodeTableCount; i++)
                {
                    if (nodes[i].ParentId == -1)
                    {
                        xmlBuilder.Append(BuildNodeXml(i));
                    }
                }

                // 5. Save XML
                Content = xmlBuilder.ToString();
            }
        }

        /// <summary>
        /// Reads a null-terminated string from the current stream position.
        /// </summary>
        private static string ReadCString(BinaryReader br)
        {
            List<byte> buffer = new List<byte>();
            while (true)
            {
                // Safeguard against end of stream
                if (br.BaseStream.Position >= br.BaseStream.Length) break;

                byte b = br.ReadByte();
                if (b == 0) break;
                buffer.Add(b);
            }
            return Encoding.UTF8.GetString(buffer.ToArray());
        }

        /// <summary>
        /// Reads a UTF-8 null-terminated string from a specific offset in the raw data array.
        /// </summary>
        private static string ReadStringAt(byte[] data, int offset)
        {
            if (offset < 0 || offset >= data.Length) return string.Empty;

            int end = offset;
            while (end < data.Length && data[end] != 0)
            {
                end++;
            }

            return Encoding.UTF8.GetString(data, offset, end - offset);
        }

        /// <summary>
        /// Escapes special XML characters in attribute values and text content.
        /// </summary>
        private static string EscapeXmlValue(string value)
        {
            if (string.IsNullOrEmpty(value))
                return string.Empty;

            return value
                .Replace("&", "&amp;")
                .Replace("<", "&lt;")
                .Replace(">", "&gt;")
                .Replace("\"", "&quot;")
                .Replace("'", "&apos;");
        }
    }
}
