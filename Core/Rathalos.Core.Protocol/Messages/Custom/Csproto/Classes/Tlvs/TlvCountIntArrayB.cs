using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for count + int array (100 max).
    /// C++ Reader: crygame.dll+sub_101756A0 (UnkTlv0128)
    /// C++ Printer: crygame.dll+sub_10175B40
    /// </summary>
    public class TlvCountIntArrayB : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 100;

        /// <summary>
        /// Element count (derived from Data array).
        /// Field ID: 1
        /// </summary>
        public int Count => Data?.Length ?? 0;

        /// <summary>
        /// Integer data array.
        /// Field ID: 2
        /// </summary>
        public int[] Data { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: reader.ReadInt(); break; // count, derived from array
                    case 2: Data = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, Count);
            WriteTlvIntArray(writer, 2, Data, Count);
        }
    }
}
