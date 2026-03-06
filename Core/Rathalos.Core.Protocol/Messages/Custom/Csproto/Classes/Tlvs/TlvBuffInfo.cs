using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for buff information.
    /// C++ Reader: crygame.dll+sub_101FBF80 (UnkTlv0207)
    /// C++ Printer: crygame.dll+sub_101FC250
    /// </summary>
    public class TlvBuffInfo : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        /// <summary>
        /// Buff ID.
        /// Field ID: 1
        /// </summary>
        public int BuffId { get; set; }

        /// <summary>
        /// Unique ID.
        /// Field ID: 2
        /// </summary>
        public int UId { get; set; }

        /// <summary>
        /// Owner ID.
        /// Field ID: 3
        /// </summary>
        public int OwnerId { get; set; }

        /// <summary>
        /// Retain time.
        /// Field ID: 4
        /// </summary>
        public int RetainTime { get; set; }

        /// <summary>
        /// Expire time.
        /// Field ID: 5
        /// </summary>
        public int ExpireTime { get; set; }

        /// <summary>
        /// Count.
        /// Field ID: 6
        /// </summary>
        public short Count { get; set; }

        /// <summary>
        /// Stack.
        /// Field ID: 7
        /// </summary>
        public short Stack { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: BuffId = reader.ReadInt(); break;
                    case 2: UId = reader.ReadInt(); break;
                    case 3: OwnerId = reader.ReadInt(); break;
                    case 4: RetainTime = reader.ReadInt(); break;
                    case 5: ExpireTime = reader.ReadInt(); break;
                    case 6: Count = reader.ReadShort(); break;
                    case 7: Stack = reader.ReadShort(); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, BuffId);
            WriteTlvInt(writer, 2, UId);
            WriteTlvInt(writer, 3, OwnerId);
            WriteTlvInt(writer, 4, RetainTime);
            WriteTlvInt(writer, 5, ExpireTime);
            WriteTlvShort(writer, 6, Count);
            WriteTlvShort(writer, 7, Stack);
        }
    }
}
