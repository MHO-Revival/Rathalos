using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for VIP information.
    /// C++ Reader: crygame.dll+sub_1019CDE0 (UnkTlv0173)
    /// C++ Printer: crygame.dll+sub_1019D220
    /// </summary>
    public class TlvVipInfo : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        /// <summary>
        /// VIP Level.
        /// Field ID: 1
        /// </summary>
        public int VipLevel { get; set; }

        /// <summary>
        /// VIP Experience.
        /// Field ID: 2
        /// </summary>
        public int VipExp { get; set; }

        /// <summary>
        /// QQ Game MHO VIP Level.
        /// Field ID: 3
        /// </summary>
        public int QqGameMhoVipLevel { get; set; }

        /// <summary>
        /// QQ Game MHO VIP End Time.
        /// Field ID: 4
        /// </summary>
        public int QqGameMhoVipEndTime { get; set; }

        /// <summary>
        /// QQ Game MHO VIP Last Update Time.
        /// Field ID: 5
        /// </summary>
        public int QqGameMhoVipLastUpdateTime { get; set; }

        /// <summary>
        /// VIP Base Latest End Time.
        /// Field ID: 6
        /// </summary>
        public int VipBaseLatestEndTime { get; set; }

        /// <summary>
        /// VIP Pay Request.
        /// Field ID: 7
        /// </summary>
        public byte VipPayReq { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: VipLevel = reader.ReadInt(); break;
                    case 2: VipExp = reader.ReadInt(); break;
                    case 3: QqGameMhoVipLevel = reader.ReadInt(); break;
                    case 4: QqGameMhoVipEndTime = reader.ReadInt(); break;
                    case 5: QqGameMhoVipLastUpdateTime = reader.ReadInt(); break;
                    case 6: VipBaseLatestEndTime = reader.ReadInt(); break;
                    case 7: VipPayReq = reader.ReadByte(); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, VipLevel);
            WriteTlvInt(writer, 2, VipExp);
            WriteTlvInt(writer, 3, QqGameMhoVipLevel);
            WriteTlvInt(writer, 4, QqGameMhoVipEndTime);
            WriteTlvInt(writer, 5, QqGameMhoVipLastUpdateTime);
            WriteTlvInt(writer, 6, VipBaseLatestEndTime);
            WriteTlvByte(writer, 7, VipPayReq);
        }
    }
}
