using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for level stat data with byte and int arrays.
    /// C++ Reader: crygame.dll+sub_10145360 (UnkTlv0068)
    /// C++ Printer: crygame.dll+sub_10145870
    /// </summary>
    public class TlvLevelStatBlock : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxStatCount = 10;

        /// <summary>
        /// Stat count (derived from arrays, stored as short).
        /// Field ID: 1
        /// </summary>
        public short LevelStatCnt => (short)(StatKeys?.Length ?? 0);

        /// <summary>
        /// Stat key bytes.
        /// Field ID: 2
        /// </summary>
        public byte[] StatKeys { get; set; } = [];

        /// <summary>
        /// Stat values (int array).
        /// Field ID: 3
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
                    case 1: reader.ReadShort(); break; // levelStatCnt, derived from arrays
                    case 2:
                        int byteLen = reader.ReadInt();
                        if (byteLen > 0 && byteLen <= MaxStatCount)
                            StatKeys = reader.ReadBytes(byteLen);
                        break;
                    case 3: StatValues = ReadTlvIntArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvShort(writer, 1, LevelStatCnt);
            WriteTlvByteArray(writer, 2, StatKeys, LevelStatCnt);
            WriteTlvIntArray(writer, 3, StatValues, LevelStatCnt);
        }
    }
}
