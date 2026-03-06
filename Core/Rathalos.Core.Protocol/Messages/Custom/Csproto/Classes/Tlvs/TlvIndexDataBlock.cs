using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for index with dual int arrays.
    /// C++ Reader: crygame.dll+sub_10202E10 (UnkTlv0216)
    /// C++ Printer: crygame.dll+sub_10203470
    /// </summary>
    public class TlvIndexDataBlock : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 1256;

        /// <summary>
        /// Index (short).
        /// Field ID: 1
        /// </summary>
        public short Index { get; set; }

        /// <summary>
        /// Data length (derived from DataBytes).
        /// Field ID: 2
        /// </summary>
        public int DataLen => DataBytes?.Length ?? 0;

        /// <summary>
        /// First data array (byte[] - reads individual bytes).
        /// Field ID: 3
        /// </summary>
        public byte[] DataBytes { get; set; } = [];

        /// <summary>
        /// Second int array.
        /// Field ID: 4
        /// </summary>
        public int[] DataInts { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: Index = reader.ReadShort(); break;
                    case 2: reader.ReadInt(); break; // dataLen, derived from array
                    case 3:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxElements)
                            DataBytes = reader.ReadBytes(byteLen);
                        break;
                    case 4: DataInts = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvShort(writer, 1, Index);
            WriteTlvInt(writer, 2, DataLen);
            WriteTlvByteArray(writer, 3, DataBytes, DataLen);
            WriteTlvIntArray(writer, 4, DataInts);
        }
    }
}
