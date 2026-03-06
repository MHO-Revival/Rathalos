using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for fixed times with block arguments.
    /// C++ Reader: crygame.dll+sub_10163300 (UnkTlv0098)
    /// C++ Printer: crygame.dll+sub_10163560
    /// </summary>
    public class TlvFixedTimesBlock : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        /// <summary>
        /// Fixed times value.
        /// Field ID: 1
        /// </summary>
        public int FixedTimes { get; set; }

        /// <summary>
        /// Block argument 1.
        /// Field ID: 2
        /// </summary>
        public int BlockArg1 { get; set; }

        /// <summary>
        /// Block argument 2.
        /// Field ID: 3
        /// </summary>
        public int BlockArg2 { get; set; }

        /// <summary>
        /// Block argument 3.
        /// Field ID: 4
        /// </summary>
        public int BlockArg3 { get; set; }

        /// <summary>
        /// Block argument 4.
        /// Field ID: 5
        /// </summary>
        public int BlockArg4 { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: FixedTimes = reader.ReadInt(); break;
                    case 2: BlockArg1 = reader.ReadInt(); break;
                    case 3: BlockArg2 = reader.ReadInt(); break;
                    case 4: BlockArg3 = reader.ReadInt(); break;
                    case 5: BlockArg4 = reader.ReadInt(); break;
                    case 6: reader.ReadInt(); break; // completeBitCount - skip
                    case 7: SkipTlvField(reader, wireType); break; // completeBit array - skip
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, FixedTimes);
            WriteTlvInt(writer, 2, BlockArg1);
            WriteTlvInt(writer, 3, BlockArg2);
            WriteTlvInt(writer, 4, BlockArg3);
            WriteTlvInt(writer, 5, BlockArg4);
        }
    }
}
