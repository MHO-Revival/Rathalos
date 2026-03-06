using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for trace data with short array and byte array.
    /// C++ Reader: crygame.dll+sub_10222970 (UnkTlv0253)
    /// C++ Printer: crygame.dll+sub_10223100
    /// </summary>
    public class TlvTraceData : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 24;

        /// <summary>
        /// Trace count (derived from arrays).
        /// Field ID: 3
        /// </summary>
        public int TraceCount => Items?.Length ?? 0;

        /// <summary>
        /// Item IDs (short array).
        /// Field ID: 4
        /// </summary>
        public short[] Items { get; set; } = [];

        /// <summary>
        /// Status bytes.
        /// Field ID: 5
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
                    case 3: reader.ReadInt(); break; // traceCount, derived from arrays
                    case 4: Items = ReadTlvShortArray(reader); break;
                    case 5:
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
            WriteTlvInt(writer, 3, TraceCount);
            WriteTlvShortArray(writer, 4, Items);
            WriteTlvByteArray(writer, 5, StatusData, StatusData?.Length ?? 0);
        }
    }
}
