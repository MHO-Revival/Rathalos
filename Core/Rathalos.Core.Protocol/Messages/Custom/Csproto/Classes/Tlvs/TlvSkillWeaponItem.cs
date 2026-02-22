using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101EF630
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101F0B50
    /// </summary>
    public class TlvSkillWeaponItem : TlvStructure
    {
        // --- Hardcoded Boundaries ---
        public const int MaxSkillLearns = 4;
        public const int MaxTalentLearns = 16;
        public const int MaxTalentEquips = 8;
        public const int MaxRages = 5;

        public int SkillLearnCount { get; set; }
        public List<TlvSkillLearnIdItem> SkillLearns { get; set; } = new List<TlvSkillLearnIdItem>(); // Newly discovered Field 3!

        public List<TlvTalentLearnItem> TalentLearns { get; set; } = new List<TlvTalentLearnItem>();
        public List<TlvTalentEquipItem> TalentEquips { get; set; } = new List<TlvTalentEquipItem>();

        public int RageIdx { get; set; }
        public int[] Rages { get; set; } = new int[0];
        public int[] BushidoRages { get; set; } = new int[0];

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                switch (tag >> 4)
                {
                    case 2: SkillLearnCount = reader.ReadByte(); break;
                    case 3: SkillLearns = ReadTlvList<TlvSkillLearnIdItem>(reader); break; // NEW
                    case 4: reader.ReadByte(); break; // TalentLearnCount (Skip)
                    case 5: TalentLearns = ReadTlvList<TlvTalentLearnItem>(reader); break;
                    case 6: reader.ReadByte(); break; // TalentEquipCount (Skip)
                    case 7: TalentEquips = ReadTlvList<TlvTalentEquipItem>(reader); break;
                    case 8: RageIdx = reader.ReadByte(); break;
                    case 9: reader.ReadByte(); break; // RageCount (Skip)
                    case 10: Rages = ReadTlvVarIntArray(reader); break;
                    case 11: reader.ReadByte(); break; // BushidoRageCount (Skip)
                    case 12: BushidoRages = ReadTlvVarIntArray(reader); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            // --- BOUNDARY CHECKS ---
            if (SkillLearns.Count > MaxSkillLearns)
                throw new InvalidDataException($"[TlvSkillWeaponItem] SkillLearns count exceeds max of {MaxSkillLearns}.");
            if (TalentLearns.Count > MaxTalentLearns)
                throw new InvalidDataException($"[TlvSkillWeaponItem] TalentLearns count exceeds max of {MaxTalentLearns}.");
            if (TalentEquips.Count > MaxTalentEquips)
                throw new InvalidDataException($"[TlvSkillWeaponItem] TalentEquips count exceeds max of {MaxTalentEquips}.");
            if (Rages.Length > MaxRages)
                throw new InvalidDataException($"[TlvSkillWeaponItem] Rages array exceeds max of {MaxRages}.");
            if (BushidoRages.Length > MaxRages) // Uses the same max count (5)
                throw new InvalidDataException($"[TlvSkillWeaponItem] BushidoRages array exceeds max of {MaxRages}.");

            // --- SERIALIZATION ---
            WriteTlvByte(writer, 2, (byte)SkillLearns.Count); // C++ writes the count first
            WriteTlvList(writer, 3, SkillLearns);

            WriteTlvByte(writer, 4, (byte)TalentLearns.Count);
            WriteTlvList(writer, 5, TalentLearns);

            WriteTlvByte(writer, 6, (byte)TalentEquips.Count);
            WriteTlvList(writer, 7, TalentEquips);

            WriteTlvByte(writer, 8, (byte)RageIdx);

            WriteTlvByte(writer, 9, (byte)Rages.Length);
            WriteTlvVarIntArray(writer, 10, Rages);

            WriteTlvByte(writer, 11, (byte)BushidoRages.Length);
            WriteTlvVarIntArray(writer, 12, BushidoRages);
        }
    }
}