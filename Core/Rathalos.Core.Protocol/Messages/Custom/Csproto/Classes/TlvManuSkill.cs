using Rathalos.Core.Utils.IO;
using System.Collections.Generic;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes
{
    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101F1260 (and sub_101F26E0 for limits)
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_XXXXX
    /// </summary>
    public class TlvManuSkill : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundaries from C++ Client ---
        public const int MaxManuSkills = 5;
        public const int MaxIngredients = 640;
        public const int MaxSkillWeapons = 13; // The C++ loops exactly 0xD times
        public const int MaxFormulaBits = 640;
        public const int MaxExpressions = 256;

        public int Version { get; set; }

        public List<TlvSkillItem> ManuSkills { get; set; } = new List<TlvSkillItem>();
        public List<TlvIngredientItem> Ingredients { get; set; } = new List<TlvIngredientItem>();

        // This array is hardcoded to 13 elements in the C++ client loop
        public List<TlvSkillWeaponItem> SkillWeapons { get; set; } = new List<TlvSkillWeaponItem>();

        public byte[] FormulaBits { get; set; } = new byte[0];

        public List<TlvExpressionItem> Expressions { get; set; } = new List<TlvExpressionItem>();

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;

                switch (fieldId)
                {
                    case 1: Version = reader.ReadVarInt(); break;
                    case 2: reader.ReadVarShort(); break; // ManuSkillCount (Skip, we use List.Count)
                    case 3: ManuSkills = ReadTlvList<TlvSkillItem>(reader); break;
                    case 4: reader.ReadVarShort(); break; // IngredientCount
                    case 5: Ingredients = ReadTlvList<TlvIngredientItem>(reader); break;
                    case 6: SkillWeapons = ReadTlvList<TlvSkillWeaponItem>(reader); break;
                    case 7: reader.ReadVarInt(); break; // FormulaBitCount
                    case 8: FormulaBits = reader.ReadBytes(reader.ReadInt()); break;
                    case 9: reader.ReadVarShort(); break; // ExpressionCount
                    case 10: Expressions = ReadTlvList<TlvExpressionItem>(reader); break;
                    default: SkipTlvField(reader, tag); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            // --- BOUNDARY CHECKS ---
            if (ManuSkills.Count > MaxManuSkills)
                throw new InvalidDataException($"[TlvManuSkill] ManuSkills count ({ManuSkills.Count}) exceeds maximum of {MaxManuSkills}.");

            if (Ingredients.Count > MaxIngredients)
                throw new InvalidDataException($"[TlvManuSkill] Ingredients count ({Ingredients.Count}) exceeds maximum of {MaxIngredients}.");

            if (SkillWeapons.Count > MaxSkillWeapons)
                throw new InvalidDataException($"[TlvManuSkill] SkillWeapons count ({SkillWeapons.Count}) exceeds maximum of {MaxSkillWeapons}.");

            if (FormulaBits.Length > MaxFormulaBits)
                throw new InvalidDataException($"[TlvManuSkill] FormulaBits length ({FormulaBits.Length}) exceeds maximum of {MaxFormulaBits} bytes.");

            if (Expressions.Count > MaxExpressions)
                throw new InvalidDataException($"[TlvManuSkill] Expressions count ({Expressions.Count}) exceeds maximum of {MaxExpressions}.");

            WriteTlvInt(writer, 1, Version);

            WriteTlvShort(writer, 2, (short)ManuSkills.Count);
            WriteTlvList(writer, 3, ManuSkills);

            WriteTlvShort(writer, 4, (short)Ingredients.Count);
            WriteTlvList(writer, 5, Ingredients);

            WriteTlvList(writer, 6, SkillWeapons);

            WriteTlvInt(writer, 7, FormulaBits.Length);
            WriteTlvByteArray(writer, 8, FormulaBits);

            WriteTlvShort(writer, 9, (short)Expressions.Count);
            WriteTlvList(writer, 10, Expressions);
        }
    }


    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101ECF70
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101ED330
    /// </summary>
    public class TlvSkillItem : TlvStructure
    {
        public int Id { get; set; }
        public int Value { get; set; }
        public int Level { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                switch (tag >> 4)
                {
                    case 1: Id = reader.ReadVarInt(); break;
                    case 2: Value = reader.ReadVarInt(); break;
                    case 3: Level = reader.ReadVarInt(); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, Id);
            WriteTlvInt(writer, 2, Value);
            WriteTlvInt(writer, 3, Level);
        }
    }

    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101ED5D0
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101ED8D0
    /// </summary>
    public class TlvIngredientItem : TlvStructure
    {
        public int Id { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                if ((tag >> 4) == 1) Id = reader.ReadVarInt();
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, Id);
        }
    }

    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101EEE50
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101EF2F0
    /// </summary>
    public class TlvExpressionItem : TlvStructure
    {
        public int Id { get; set; }
        public int Level { get; set; }
        public int Point { get; set; }
        public int CollectLevel { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                switch (tag >> 4)
                {
                    case 1: Id = reader.ReadVarInt(); break;
                    case 2: Level = reader.ReadVarInt(); break;
                    case 3: Point = reader.ReadVarInt(); break;
                    case 4: CollectLevel = reader.ReadVarInt(); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvInt(writer, 1, Id);
            WriteTlvInt(writer, 2, Level);
            WriteTlvInt(writer, 3, Point);
            WriteTlvInt(writer, 4, CollectLevel);
        }
    }

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

    /// <summary>
    /// Reconstructed TLV Structure (Nested inside TlvSkillWeaponItem).
    /// C++ Writer: Inlined within crygame.dll+sub_101EF630
    /// C++ Printer: Inlined within crygame.dll+sub_101F0B50
    /// </summary>
    public class TlvSkillLearnIdItem : TlvStructure
    {
        public int Id { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                if ((tag >> 4) == 1) Id = reader.ReadVarInt();
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvVarInt(writer, 1, Id);
        }
    }

    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101EE0C0
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101EE510
    /// </summary>
    public class TlvTalentLearnItem : TlvStructure
    {
        public int Id { get; set; }
        public byte Level { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                switch (tag >> 4)
                {
                    case 1:
                        Id = reader.ReadVarInt();
                        break;
                    case 2:
                        Level = reader.ReadByte();
                        break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvVarInt(writer, 1, Id);
            WriteTlvByte(writer, 2, Level);
        }
    }

    /// <summary>
    /// Reconstructed TLV Structure.
    /// C++ Writer: crygame.dll+sub_101EE780
    /// C++ Reader: crygame.dll+sub_XXXXX
    /// C++ Printer: crygame.dll+sub_101EEBD0
    /// </summary>
    public class TlvTalentEquipItem : TlvStructure
    {
        public int Id { get; set; }
        public byte Idx { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                switch (tag >> 4)
                {
                    case 1:
                        Id = reader.ReadVarInt();
                        break;
                    case 2:
                        Idx = reader.ReadByte();
                        break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            WriteTlvVarInt(writer, 1, Id);
            WriteTlvByte(writer, 2, Idx);
        }
    }
}