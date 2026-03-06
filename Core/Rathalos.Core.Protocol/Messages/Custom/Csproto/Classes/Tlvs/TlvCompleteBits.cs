using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for complete bits.
    /// C++ Reader: crygame.dll+sub_10192CF0 (UnkTlv0158)
    /// C++ Printer: crygame.dll+sub_10192F70
    /// </summary>
    public class TlvCompleteBits : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxBitDataLength = 128;

        /// <summary>
        /// Complete bit count (derived from BitData).
        /// Field ID: 1
        /// </summary>
        public int CompleteBitCount => BitData?.Length ?? 0;

        /// <summary>
        /// Bit data bytes.
        /// Field ID: 2
        /// </summary>
        public byte[] BitData { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: reader.ReadInt(); break; // completeBitCount, derived from array
                    case 2:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxBitDataLength)
                            BitData = reader.ReadBytes(byteLen);
                        break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, CompleteBitCount);
            WriteTlvByteArray(writer, 2, BitData, CompleteBitCount);
        }
    }
}
