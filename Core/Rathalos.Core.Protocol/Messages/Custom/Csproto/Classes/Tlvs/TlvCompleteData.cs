using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for complete data with short array and byte array.
    /// C++ Reader: crygame.dll+sub_102204F0 (UnkTlv0249)
    /// C++ Printer: crygame.dll+sub_10220CF0
    /// </summary>
    public class TlvCompleteData : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 2048;

        /// <summary>
        /// Complete count (derived from arrays).
        /// Field ID: 1
        /// </summary>
        public int CompleteCount => Items?.Length ?? 0;

        /// <summary>
        /// Item IDs (short array).
        /// Field ID: 2
        /// </summary>
        public short[] Items { get; set; } = [];

        /// <summary>
        /// Status bytes.
        /// Field ID: 3
        /// </summary>
        public byte[] StatusData { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: reader.ReadInt(); break; // completeCount, derived from arrays
                    case 2: Items = ReadTlvShortArray(reader); break;
                    case 3:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxElements)
                            StatusData = reader.ReadBytes(byteLen);
                        break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, CompleteCount);
            WriteTlvShortArray(writer, 2, Items);
            WriteTlvByteArray(writer, 3, StatusData, StatusData?.Length ?? 0);
        }
    }
}
