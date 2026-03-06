using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for group preference data.
    /// C++ Reader: crygame.dll+sub_1022A470 (UnkTlv0264)
    /// C++ Printer: crygame.dll+sub_1022A820
    /// </summary>
    public class TlvGroupPreference : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxPreferDataLength = 1024;

        /// <summary>
        /// Group ID.
        /// Field ID: 1
        /// </summary>
        public int GroupId { get; set; }

        /// <summary>
        /// Prefer count (derived from PreferData).
        /// Field ID: 2
        /// </summary>
        public int PreferNum => PreferData?.Length ?? 0;

        /// <summary>
        /// Preference data bytes.
        /// Field ID: 3
        /// </summary>
        public byte[] PreferData { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: GroupId = reader.ReadInt(); break;
                    case 2: reader.ReadInt(); break; // preferNum, derived from array
                    case 3:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxPreferDataLength)
                            PreferData = reader.ReadBytes(byteLen);
                        break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, GroupId);
            WriteTlvInt(writer, 2, PreferNum);
            WriteTlvByteArray(writer, 3, PreferData, PreferNum);
        }
    }
}
