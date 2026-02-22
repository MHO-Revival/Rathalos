using Rathalos.Core.Utils.IO;
using System.Collections.Generic;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// Reconstructed TLV Structure (Manufacturing Skills).
    /// C++ Writer: crygame.dll+sub_101F1260
    /// </summary>
    public class TlvManuSkill : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundaries from C++ Client ---
        public const int MaxManuSkills = 5;
        public const int MaxIngredients = 640;
        public const int MaxFormulaBits = 640;
        public const int MaxExpressions = 256;

        // --- STRICT EXACT BOUNDARY ---
        public const int ExactSkillWeapons = 13; // The C++ strictly loops 0xD (13) times

        public int Version { get; set; }

        public List<TlvSkillItem> ManuSkills { get; set; } = new List<TlvSkillItem>();
        public List<TlvIngredientItem> Ingredients { get; set; } = new List<TlvIngredientItem>();
        public List<TlvSkillWeaponItem> SkillWeapons { get; set; } = new List<TlvSkillWeaponItem>();
        public byte[] FormulaBits { get; set; } = new byte[0];
        public List<TlvExpressionItem> Expressions { get; set; } = new List<TlvExpressionItem>();

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1: Version = reader.ReadVarInt(); break;
                    case 2: reader.ReadVarShort(); break; // ManuSkillCount
                    case 3: ManuSkills = ReadTlvList<TlvSkillItem>(reader); break;
                    case 4: reader.ReadVarShort(); break; // IngredientCount
                    case 5: Ingredients = ReadTlvList<TlvIngredientItem>(reader); break;
                    case 6: SkillWeapons = ReadTlvList<TlvSkillWeaponItem>(reader); break;
                    case 7: reader.ReadVarInt(); break; // FormulaBitCount
                    case 8: FormulaBits = reader.ReadBytes(reader.ReadInt()); break;
                    case 9: reader.ReadVarShort(); break; // ExpressionCount
                    case 10: Expressions = ReadTlvList<TlvExpressionItem>(reader); break;
                    default: SkipTlvField(reader, wireType); break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            // --- STRICT EXACT CHECK ---
            if (SkillWeapons.Count != ExactSkillWeapons)
                throw new InvalidDataException($"[TlvManuSkill] SkillWeapons count is {SkillWeapons.Count}. It MUST be exactly {ExactSkillWeapons}.");

            // --- STANDARD MAXIMUM CHECKS ---
            if (ManuSkills.Count > MaxManuSkills)
                throw new InvalidDataException($"[TlvManuSkill] ManuSkills count ({ManuSkills.Count}) exceeds maximum of {MaxManuSkills}.");
            if (Ingredients.Count > MaxIngredients)
                throw new InvalidDataException($"[TlvManuSkill] Ingredients count ({Ingredients.Count}) exceeds maximum of {MaxIngredients}.");
            if (FormulaBits.Length > MaxFormulaBits)
                throw new InvalidDataException($"[TlvManuSkill] FormulaBits length ({FormulaBits.Length}) exceeds maximum of {MaxFormulaBits} bytes.");
            if (Expressions.Count > MaxExpressions)
                throw new InvalidDataException($"[TlvManuSkill] Expressions count ({Expressions.Count}) exceeds maximum of {MaxExpressions}.");


            // --- SERIALIZATION ---
            WriteTlvInt(writer, 1, Version);

            WriteTlvShort(writer, 2, (short)ManuSkills.Count);
            WriteTlvList(writer, 3, ManuSkills);

            WriteTlvShort(writer, 4, (short)Ingredients.Count);
            WriteTlvList(writer, 5, Ingredients);

            WriteTlvList(writer, 6, SkillWeapons);

            WriteTlvInt(writer, 7, FormulaBits.Length);
            WriteTlvByteArray(writer, 8, FormulaBits); // Assuming you're using the standard 3-param overload here

            WriteTlvShort(writer, 9, (short)Expressions.Count);
            WriteTlvList(writer, 10, Expressions);
        }
    }
}