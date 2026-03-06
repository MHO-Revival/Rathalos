using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for action point data.
    /// C++ Reader: crygame.dll+sub_101660B0 (UnkTlv0104)
    /// C++ Printer: crygame.dll+sub_10166570
    /// </summary>
    public class TlvActionPointData : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxResetTimes = 2;

        /// <summary>
        /// Next reset times (int array, max 2).
        /// Field ID: 2
        /// </summary>
        public int[] NextResetTime { get; set; } = [];

        /// <summary>
        /// Unknown field.
        /// Field ID: 3
        /// </summary>
        public int Field3 { get; set; }

        /// <summary>
        /// Action point flags.
        /// Field ID: 4
        /// </summary>
        public uint ActionPointFlags { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 2: NextResetTime = ReadTlvIntArray(reader); break;
                    case 3: Field3 = reader.ReadInt(); break;
                    case 4: ActionPointFlags = (uint)reader.ReadInt(); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvIntArray(writer, 2, NextResetTime);
            WriteTlvInt(writer, 3, Field3);
            WriteTlvInt(writer, 4, (int)ActionPointFlags);
        }
    }
}
