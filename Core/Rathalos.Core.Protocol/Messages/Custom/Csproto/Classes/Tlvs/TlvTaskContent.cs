using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for task content with arguments.
    /// C++ Reader: crygame.dll+sub_1013F3D0 (UnkTlv0058)
    /// C++ Printer: crygame.dll+sub_1013F770
    /// </summary>
    public class TlvTaskContent : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        /// <summary>
        /// Task identifier.
        /// Field ID: 1
        /// </summary>
        public int Id { get; set; }

        /// <summary>
        /// Library identifier.
        /// Field ID: 2
        /// </summary>
        public int Lib { get; set; }

        /// <summary>
        /// Content byte.
        /// Field ID: 3
        /// </summary>
        public byte Content { get; set; }

        /// <summary>
        /// Argument 1.
        /// Field ID: 4
        /// </summary>
        public int Arg1 { get; set; }

        /// <summary>
        /// Argument 2.
        /// Field ID: 5
        /// </summary>
        public int Arg2 { get; set; }

        /// <summary>
        /// Argument 3.
        /// Field ID: 6
        /// </summary>
        public int Arg3 { get; set; }

        /// <summary>
        /// NPC identifier.
        /// Field ID: 7
        /// </summary>
        public int Npc { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: Id = reader.ReadInt(); break;
                    case 2: Lib = reader.ReadInt(); break;
                    case 3: Content = reader.ReadByte(); break;
                    case 4: Arg1 = reader.ReadInt(); break;
                    case 5: Arg2 = reader.ReadInt(); break;
                    case 6: Arg3 = reader.ReadInt(); break;
                    case 7: Npc = reader.ReadInt(); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, Id);
            WriteTlvInt(writer, 2, Lib);
            WriteTlvByte(writer, 3, Content);
            WriteTlvInt(writer, 4, Arg1);
            WriteTlvInt(writer, 5, Arg2);
            WriteTlvInt(writer, 6, Arg3);
            WriteTlvInt(writer, 7, Npc);
        }
    }
}
