using Rathalos.Core.Utils.IO;
using System.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// TLV Structure for various time trackers.
    /// C++ Reader: crygame.dll+sub_1011C900 (UnkTlv0018)
    /// C++ Printer: crygame.dll+sub_1011C990
    /// </summary>
    public class TlvGuildTimes : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxEliteGuilds = 200; // 0xC8

        /// <summary>
        /// Wage time.
        /// Field ID: 1
        /// </summary>
        public uint WageTime { get; set; }

        /// <summary>
        /// Log time.
        /// Field ID: 2
        /// </summary>
        public uint LogTime { get; set; }

        /// <summary>
        /// Depot fetch count time.
        /// Field ID: 3
        /// </summary>
        public uint DepotFetchCountTime { get; set; }

        /// <summary>
        /// Random commodity time.
        /// Field ID: 4
        /// </summary>
        public uint RandCommodityTime { get; set; }

        /// <summary>
        /// Daily 3 time.
        /// Field ID: 6
        /// </summary>
        public uint Daily3Time { get; set; }

        /// <summary>
        /// Week 3 time.
        /// Field ID: 7
        /// </summary>
        public uint Week3Time { get; set; }

        /// <summary>
        /// Elite guild count.
        /// Field ID: 8
        /// </summary>
        public byte EliteGuildCount { get; set; }

        /// <summary>
        /// Elite guilds array (guild IDs).
        /// Field ID: 9
        /// </summary>
        public long[] EliteGuilds { get; set; } = [];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: WageTime = (uint)reader.ReadInt(); break;
                    case 2: LogTime = (uint)reader.ReadInt(); break;
                    case 3: DepotFetchCountTime = (uint)reader.ReadInt(); break;
                    case 4: RandCommodityTime = (uint)reader.ReadInt(); break;
                    case 6: Daily3Time = (uint)reader.ReadInt(); break;
                    case 7: Week3Time = (uint)reader.ReadInt(); break;
                    case 8: EliteGuildCount = reader.ReadByte(); break;
                    case 9: EliteGuilds = ReadTlvLongArray(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            // --- BOUNDARY CHECK ---
            if (EliteGuilds.Length > MaxEliteGuilds)
                throw new InvalidDataException($"[TlvGuildTimes] EliteGuilds array length ({EliteGuilds.Length}) exceeds maximum of {MaxEliteGuilds}.");

            WriteTlvInt(writer, 1, (int)WageTime);
            WriteTlvInt(writer, 2, (int)LogTime);
            WriteTlvInt(writer, 3, (int)DepotFetchCountTime);
            WriteTlvInt(writer, 4, (int)RandCommodityTime);
            WriteTlvInt(writer, 6, (int)Daily3Time);
            WriteTlvInt(writer, 7, (int)Week3Time);
            WriteTlvByte(writer, 8, EliteGuildCount);
            WriteTlvLongArray(writer, 9, EliteGuilds);
        }
    }
}
