using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for level mode data with byte and int arrays.
    /// C++ Reader: crygame.dll+sub_10147B50 (UnkTlv0071)
    /// C++ Printer: crygame.dll+sub_10148060
    /// </summary>
    public class TlvLevelModeBlock : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxDataCount = 10;

        /// <summary>
        /// Level mode.
        /// Field ID: 1
        /// </summary>
        public int LevelMode { get; set; }

        /// <summary>
        /// Mode stat count (derived from arrays).
        /// Field ID: 2
        /// </summary>
        public byte ModeStatCnt => (byte)(StatKeys?.Length ?? 0);

        /// <summary>
        /// Stat key bytes.
        /// Field ID: 3
        /// </summary>
        public byte[] StatKeys { get; set; } = [];

        /// <summary>
        /// Stat values (int array).
        /// Field ID: 4
        /// </summary>
        public int[] StatValues { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: LevelMode = reader.ReadInt(); break;
                    case 2: reader.ReadByte(); break; // modeStatCnt, derived from arrays
                    case 3:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxDataCount)
                            StatKeys = reader.ReadBytes(byteLen);
                        break;
                    case 4: StatValues = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, LevelMode);
            WriteTlvByte(writer, 2, ModeStatCnt);
            WriteTlvByteArray(writer, 3, StatKeys, ModeStatCnt);
            WriteTlvIntArray(writer, 4, StatValues, ModeStatCnt);
        }
    }
}
