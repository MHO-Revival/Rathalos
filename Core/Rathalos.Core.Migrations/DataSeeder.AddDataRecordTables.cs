using Microsoft.EntityFrameworkCore.Migrations;
using Rathalos.Core.Protocol.Data.AvatarAttrInfo;
using Rathalos.Core.Protocol.Data.HRLevel;
using Rathalos.Core.Protocol.Data.MonsterAttribute;
using Rathalos.Core.Protocol.Data.MonsterData;
using Rathalos.Core.Protocol.Data.NewPlayerInit;
using Rathalos.Core.Protocol.Data.NpcDataNew;
using Rathalos.Core.Protocol.Data.NpcSale;
using Rathalos.Core.Protocol.Data.Pet;
using Rathalos.Core.Protocol.Data.PlayerAttribute;
using Rathalos.Core.Protocol.Data.PlayerLevelUp;
using Rathalos.Core.Protocol.Tools;
using System.Reflection;

namespace Rathalos.Core.Migrations;

/// <summary>
/// Data seeder that reads TSV files and inserts data into tables during migrations.
/// Uses reflection for automatic property-to-column mapping.
/// </summary>
public static partial class DataSeeder
{
    private static string GetFilesPath()
    {
        // Try multiple paths to find the Files directory
        var possiblePaths = new[]
        {
            Path.Combine(AppContext.BaseDirectory, "Files"),
            Path.Combine(Directory.GetCurrentDirectory(), "Files"),
            Path.Combine(Directory.GetCurrentDirectory(), "Core", "Rathalos.Core.Migrations", "Files")
        };

        foreach (var path in possiblePaths)
        {
            if (Directory.Exists(path))
                return path;
        }

        throw new DirectoryNotFoundException("Could not find Files directory for TSV data. Tried: " + string.Join(", ", possiblePaths));
    }

    /// <summary>
    /// Seeds data into a table using reflection to map properties to columns.
    /// </summary>
    /// <typeparam name="T">The type of records to seed</typeparam>
    /// <param name="migrationBuilder">The migration builder</param>
    /// <param name="tableName">The database table name</param>
    /// <param name="records">The records to insert</param>
    /// <param name="columnMappings">Optional dictionary mapping property names to column names. If null, property names are used as column names.</param>
    /// <param name="excludeProperties">Optional set of property names to exclude from insertion</param>
    private static void SeedTable<T>(
        MigrationBuilder migrationBuilder,
        string tableName,
        IEnumerable<T> records,
        Dictionary<string, string>? columnMappings = null,
        HashSet<string>? excludeProperties = null) where T : class
    {
        var recordList = records.ToList();
        if (recordList.Count == 0) return;

        columnMappings ??= [];
        excludeProperties ??= [];

        var properties = typeof(T).GetProperties(BindingFlags.Public | BindingFlags.Instance)
            .Where(p => p.CanRead && !excludeProperties.Contains(p.Name))
            .ToList();

        var columns = properties
            .Select(p => columnMappings.TryGetValue(p.Name, out var col) ? col : p.Name)
            .ToArray();

        foreach (var record in recordList)
        {
            var values = properties.Select(p => p.GetValue(record)).ToArray();
            migrationBuilder.InsertData(table: tableName, columns: columns, values: values!);
        }
    }

    public static void SeedAddDataRecordTables(MigrationBuilder migrationBuilder)
    {
        var filesPath = GetFilesPath();

        SeedAvatarData(migrationBuilder, filesPath);
        SeedPlayerAttributeData(migrationBuilder, filesPath);
        SeedNpcData(migrationBuilder, filesPath);
        SeedMonsterData(migrationBuilder, filesPath);
        SeedMonsterAttributeData(migrationBuilder, filesPath);
        SeedHRLevelData(migrationBuilder, filesPath);
        SeedNewPlayerInitData(migrationBuilder, filesPath);
        SeedNpcSaleData(migrationBuilder, filesPath);
        SeedPetData(migrationBuilder, filesPath);
    }


    public static void SeedPlayerLevelUpData(MigrationBuilder migrationBuilder)
    {
        var filesPath = GetFilesPath();

        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "playerlevelup.tsv"));
        SeedTable(migrationBuilder, "player_level_ups",
            reader.GetSheet("LevelUp")?.ReadAs<PlayerLevelUpInfo>() ?? [],
            new Dictionary<string, string> { ["Id"] =  "Level" });
    }

    private static void SeedAvatarData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "avatarattrinfo.tsv"));

        SeedTable(migrationBuilder, "face_infos",
            reader.GetSheet("FaceInfo")?.ReadAs<FaceInfo>() ?? [],
            new Dictionary<string, string> { ["Id"] = "FaceId" });

        SeedTable(migrationBuilder, "hair_infos",
            reader.GetSheet("HairInfo")?.ReadAs<HairInfo>() ?? [],
            new Dictionary<string, string> { ["Id"] = "HairId" });

        SeedTable(migrationBuilder, "tattoo_infos",
            reader.GetSheet("TattooInfo")?.ReadAs<TattooInfo>() ?? [],
            new Dictionary<string, string> { ["Id"] = "TattooId" });

        SeedTable(migrationBuilder, "underclothes_infos",
            reader.GetSheet("UnderclothesInfo")?.ReadAs<UnderclothesInfo>() ?? [],
            new Dictionary<string, string> { ["Id"] = "UnderclothesId" });
    }

    private static void SeedPlayerAttributeData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "playerattribute.tsv"));

        SeedTable(migrationBuilder, "player_attributes",
            reader.GetSheet("Attribute")?.ReadAs<PlayerAttributeInfo>() ?? [],
            new Dictionary<string, string> { ["ID"] = "AttributeId" });
    }

    private static void SeedNpcData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "npcdatanew.tsv"));

        SeedTable(migrationBuilder, "npc_daily_works",
            reader.GetSheet("NPCDailyWork")?.ReadAs<NpcDailyWork>() ?? [],
            new Dictionary<string, string> { ["ID"] = "WorkId", ["NPCID"] = "NpcId" });

        SeedTable(migrationBuilder, "npc_data",
            reader.GetSheet("NPCData")?.ReadAs<NpcDataInfo>() ?? [],
            new Dictionary<string, string> { ["ID"] = "NpcId" });
    }

    private static void SeedMonsterData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "monsterdata.tsv"));

        SeedTable(migrationBuilder, "monster_abnormal_states",
            reader.GetSheet("AbnormalState")?.ReadAs<AbnormalState>() ?? []);

        SeedTable(migrationBuilder, "monster_emotions",
            reader.GetSheet("Emotion")?.ReadAs<MonsterEmotion>() ?? []);

        SeedTable(migrationBuilder, "monster_infos",
            reader.GetSheet("Monsters")?.ReadAs<MonsterInfo>() ?? [],
            excludeProperties: ["xx"]);

        SeedTable(migrationBuilder, "monster_lemons",
            reader.GetSheet("Lemon")?.ReadAs<MonsterLemon>() ?? []);

        SeedTable(migrationBuilder, "monster_part_defences",
            reader.GetSheet("PartDefence")?.ReadAs<MonsterPartDefence>() ?? []);

        SeedTable(migrationBuilder, "monster_parts",
            reader.GetSheet("Parts")?.ReadAs<MonsterPart>() ?? []);

        SeedTable(migrationBuilder, "monster_perceptions",
            reader.GetSheet("Perceptions")?.ReadAs<MonsterPerception>() ?? []);

        SeedTable(migrationBuilder, "monster_states",
            reader.GetSheet("States")?.ReadAs<MonsterState>() ?? []);
    }

    private static void SeedMonsterAttributeData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "monsterattribute.tsv"));

        SeedTable(migrationBuilder, "monster_attributes",
            reader.GetSheet("Attribute")?.ReadAs<MonsterAttributeInfo>() ?? [],
            new Dictionary<string, string> { ["ID"] = "AttributeId" });
    }

    private static void SeedHRLevelData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "hrlevel.tsv"));

        SeedTable(migrationBuilder, "hr_levels",
            reader.GetSheet("HRLevel")?.ReadAs<HRLevelInfo>() ?? []);
    }

    private static void SeedNewPlayerInitData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "newplayerinit.tsv"));

        SeedTable(migrationBuilder, "init_attributes",
            reader.GetSheet("Attribute")?.ReadAs<InitAttribute>() ?? []);

        SeedTable(migrationBuilder, "init_items",
            reader.GetSheet("Item")?.ReadAs<InitItem>() ?? [],
            new Dictionary<string, string> { ["Id"] = "InitId" });

        SeedTable(migrationBuilder, "init_quick_supplies",
            reader.GetSheet("QuickSupply")?.ReadAs<InitQuickSupply>() ?? [],
            new Dictionary<string, string> { ["Index"] = "Index" });

        SeedTable(migrationBuilder, "init_shortcuts",
            reader.GetSheet("Shortcut")?.ReadAs<InitShortcut>() ?? [],
            new Dictionary<string, string> { ["ShorcutPos"] = "ShortcutPos" });

        SeedTable(migrationBuilder, "init_stores",
            reader.GetSheet("Store")?.ReadAs<InitStore>() ?? []);
    }

    private static void SeedNpcSaleData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "npcsale.tsv"));

        SeedTable(migrationBuilder, "npc_shop_mappings",
            reader.GetSheet("NPC与商店对应关系")?.ReadAs<NpcShopMapping>() ?? [],
            new Dictionary<string, string> { ["Id"] = "MappingId", ["NPCID"] = "NpcId" });

        SeedTable(migrationBuilder, "shop_infos",
            reader.GetSheet("商店信息")?.ReadAs<ShopInfo>() ?? []);

        SeedTable(migrationBuilder, "random_groups",
            reader.GetSheet("随机分组")?.ReadAs<RandomGroup>() ?? [],
            new Dictionary<string, string> { ["Id"] = "GroupId" });

        SeedTable(migrationBuilder, "random_products",
            reader.GetSheet("随机商品")?.ReadAs<RandomProduct>() ?? [],
            new Dictionary<string, string> { ["Id"] = "ProductRecordId" });

        SeedTable(migrationBuilder, "random_pools",
            reader.GetSheet("随机库")?.ReadAs<RandomPool>() ?? [],
            new Dictionary<string, string> { ["Id"] = "PoolId" });
    }

    private static void SeedPetData(MigrationBuilder migrationBuilder, string filesPath)
    {
        var reader = TsvReader.CreateFromFile(Path.Combine(filesPath, "pet.tsv"));

        SeedTable(migrationBuilder, "pet_names",
            reader.GetSheet("名称")?.ReadAs<PetName>() ?? [],
            new Dictionary<string, string> { ["ID"] = "PetNameId" });

        SeedTable(migrationBuilder, "pet_farewell_gifts",
            reader.GetSheet("告别赠礼")?.ReadAs<PetFarewellGift>() ?? []);

        SeedTable(migrationBuilder, "pet_qualities",
            reader.GetSheet("品质")?.ReadAs<PetQuality>() ?? [],
            new Dictionary<string, string> { ["ID"] = "QualityId" });

        SeedTable(migrationBuilder, "pet_innate_skills",
            reader.GetSheet("天生技能")?.ReadAs<PetInnateSkill>() ?? []);

        SeedTable(migrationBuilder, "pet_infos",
            reader.GetSheet("宠物信息")?.ReadAs<PetInfo>() ?? [],
            new Dictionary<string, string> { ["ID"] = "PetId" });

        SeedTable(migrationBuilder, "pet_personalities",
            reader.GetSheet("性格")?.ReadAs<PetPersonality>() ?? [],
            new Dictionary<string, string> { ["ID"] = "PersonalityId" });

        SeedTable(migrationBuilder, "pet_combat_skills",
            reader.GetSheet("战斗技能")?.ReadAs<PetCombatSkill>() ?? []);

        SeedTable(migrationBuilder, "pet_skill_slot_unlocks",
            reader.GetSheet("技能槽解锁条件")?.ReadAs<PetSkillSlotUnlock>() ?? [],
            new Dictionary<string, string> { ["ID"] = "SlotId" });

        SeedTable(migrationBuilder, "pet_skill_triggers",
            reader.GetSheet("技能触发")?.ReadAs<PetSkillTrigger>() ?? []);

        SeedTable(migrationBuilder, "pet_support_skills",
            reader.GetSheet("支援技能")?.ReadAs<PetSupportSkill>() ?? []);

        SeedTable(migrationBuilder, "pet_attack_tendencies",
            reader.GetSheet("攻击倾向")?.ReadAs<PetAttackTendency>() ?? [],
            new Dictionary<string, string> { ["ID"] = "TendencyId" });

        SeedTable(migrationBuilder, "pet_attack_methods",
            reader.GetSheet("攻击方式")?.ReadAs<PetAttackMethod>() ?? [],
            new Dictionary<string, string> { ["ID"] = "MethodId" });

        SeedTable(migrationBuilder, "pet_production_skills",
            reader.GetSheet("生产技能")?.ReadAs<PetProductionSkill>() ?? []);

        SeedTable(migrationBuilder, "pet_production_skill_effects",
            reader.GetSheet("生产技能效果")?.ReadAs<PetProductionSkillEffect>() ?? []);

        SeedTable(migrationBuilder, "pet_skins",
            reader.GetSheet("皮肤")?.ReadAs<PetSkin>() ?? [],
            new Dictionary<string, string> { ["ID"] = "SkinId" });

        SeedTable(migrationBuilder, "pet_levels",
            reader.GetSheet("等级")?.ReadAs<PetLevel>() ?? []);

        SeedTable(migrationBuilder, "pet_aptitude_qualities",
            reader.GetSheet("资质品质")?.ReadAs<PetAptitudeQuality>() ?? [],
            new Dictionary<string, string> { ["ID"] = "AptitudeQualityId" });
    }
}
