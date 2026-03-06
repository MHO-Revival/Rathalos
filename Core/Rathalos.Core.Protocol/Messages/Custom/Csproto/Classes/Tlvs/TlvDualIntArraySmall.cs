using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for dual int arrays (4 max each).
    /// C++ Reader: crygame.dll+sub_10201480 (UnkTlv0214)
    /// C++ Printer: crygame.dll+sub_10201930
    /// </summary>
    public class TlvDualIntArraySmall : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxElements = 4;

        /// <summary>
        /// First integer array.
        /// Field ID: 1
        /// </summary>
        public int[] DataA { get; set; } = [];

        /// <summary>
        /// Second integer array.
        /// Field ID: 2
        /// </summary>
        public int[] DataB { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: DataA = ReadTlvIntArray(reader); break;
                    case 2: DataB = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvIntArray(writer, 1, DataA);
            WriteTlvIntArray(writer, 2, DataB);
        }
    }
}
