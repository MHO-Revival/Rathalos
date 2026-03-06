using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for single int array (20 max).
    /// C++ Reader: crygame.dll+sub_10180360 (UnkTlv0144)
    /// C++ Printer: crygame.dll+sub_101805F0
    /// </summary>
    public class TlvSingleIntArray : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 20;

        /// <summary>
        /// Integer data array.
        /// Field ID: 1
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
                    case 1: Data = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvIntArray(writer, 1, Data);
        }
    }
}
