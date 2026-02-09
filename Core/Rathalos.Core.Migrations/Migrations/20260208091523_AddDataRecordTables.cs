using System;
using Microsoft.EntityFrameworkCore.Migrations;
using Npgsql.EntityFrameworkCore.PostgreSQL.Metadata;

#nullable disable

namespace Rathalos.Core.Migrations.Migrations
{
    /// <inheritdoc />
    public partial class AddDataRecordTables : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "face_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    FaceId = table.Column<int>(type: "integer", nullable: false),
                    MaleModelId = table.Column<int>(type: "integer", nullable: false),
                    FemaleModelId = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_face_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "hair_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    HairId = table.Column<int>(type: "integer", nullable: false),
                    MaleModelId = table.Column<int>(type: "integer", nullable: false),
                    FemaleModelId = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_hair_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "hr_levels",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    HRLevel = table.Column<int>(type: "integer", nullable: false),
                    UnlockPoints = table.Column<int>(type: "integer", nullable: false),
                    UnlockStage = table.Column<string>(type: "text", nullable: true),
                    Buffs = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_hr_levels", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "init_attributes",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    AttrName = table.Column<string>(type: "text", nullable: false),
                    AttrValue = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_init_attributes", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "init_items",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    InitId = table.Column<int>(type: "integer", nullable: false),
                    ItemId = table.Column<int>(type: "integer", nullable: false),
                    Count = table.Column<int>(type: "integer", nullable: false),
                    AutoEquip = table.Column<int>(type: "integer", nullable: false),
                    AutoStore = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_init_items", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "init_quick_supplies",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Index = table.Column<int>(type: "integer", nullable: false),
                    ItemId = table.Column<int>(type: "integer", nullable: false),
                    ItemCount = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_init_quick_supplies", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "init_shortcuts",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    ShortcutPos = table.Column<int>(type: "integer", nullable: false),
                    ItemId = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_init_shortcuts", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "init_stores",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    StoreParam = table.Column<string>(type: "text", nullable: false),
                    StoreValue = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_init_stores", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_abnormal_states",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    PoisonTol = table.Column<int>(type: "integer", nullable: false),
                    Poison = table.Column<int>(type: "integer", nullable: false),
                    PoisonAdd = table.Column<int>(type: "integer", nullable: false),
                    PoisonMax = table.Column<int>(type: "integer", nullable: false),
                    PoisonWeaken = table.Column<int>(type: "integer", nullable: false),
                    PoisonBuff = table.Column<int>(type: "integer", nullable: false),
                    PoisonDmg = table.Column<int>(type: "integer", nullable: false),
                    PoisonCount = table.Column<int>(type: "integer", nullable: false),
                    PoisonWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    ParalysisTol = table.Column<int>(type: "integer", nullable: false),
                    Paralysis = table.Column<int>(type: "integer", nullable: false),
                    ParalysisAdd = table.Column<int>(type: "integer", nullable: false),
                    ParalysisMax = table.Column<int>(type: "integer", nullable: false),
                    ParalysisWeaken = table.Column<int>(type: "integer", nullable: false),
                    ParalysisBuff = table.Column<int>(type: "integer", nullable: false),
                    ParalysisCount = table.Column<int>(type: "integer", nullable: false),
                    ParalysisWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    SleepTol = table.Column<int>(type: "integer", nullable: false),
                    Sleep = table.Column<int>(type: "integer", nullable: false),
                    SleepAdd = table.Column<int>(type: "integer", nullable: false),
                    SleepMax = table.Column<int>(type: "integer", nullable: false),
                    SleepWeaken = table.Column<int>(type: "integer", nullable: false),
                    SleepBuff = table.Column<int>(type: "integer", nullable: false),
                    SleepCount = table.Column<int>(type: "integer", nullable: false),
                    SleepWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    DynamiteTol = table.Column<int>(type: "integer", nullable: false),
                    Dynamite = table.Column<int>(type: "integer", nullable: false),
                    DynamiteAdd = table.Column<int>(type: "integer", nullable: false),
                    DynamiteMax = table.Column<int>(type: "integer", nullable: false),
                    DynamiteWeaken = table.Column<int>(type: "integer", nullable: false),
                    DynamiteBuff = table.Column<int>(type: "integer", nullable: false),
                    DynamiteDmg = table.Column<int>(type: "integer", nullable: false),
                    DynamiteCount = table.Column<int>(type: "integer", nullable: false),
                    DynamiteWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    StunTol = table.Column<int>(type: "integer", nullable: false),
                    Stun = table.Column<int>(type: "integer", nullable: false),
                    StunAdd = table.Column<int>(type: "integer", nullable: false),
                    StunMax = table.Column<int>(type: "integer", nullable: false),
                    StunWeaken = table.Column<int>(type: "integer", nullable: false),
                    StunBuff = table.Column<int>(type: "integer", nullable: false),
                    StunCount = table.Column<int>(type: "integer", nullable: false),
                    StunWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    TrapTol = table.Column<int>(type: "integer", nullable: true),
                    TrapTimeLower = table.Column<int>(type: "integer", nullable: true),
                    TrapCount = table.Column<int>(type: "integer", nullable: false),
                    ParaTrapTol = table.Column<int>(type: "integer", nullable: true),
                    ParaTrapTimeLower = table.Column<int>(type: "integer", nullable: true),
                    ParaTrapCount = table.Column<int>(type: "integer", nullable: false),
                    AdvTrapTol = table.Column<int>(type: "integer", nullable: true),
                    AdvTrapTimeLower = table.Column<int>(type: "integer", nullable: true),
                    AdvTrapCount = table.Column<int>(type: "integer", nullable: false),
                    FlareTol = table.Column<int>(type: "integer", nullable: true),
                    FlareTimeLower = table.Column<int>(type: "integer", nullable: true),
                    FlareCount = table.Column<int>(type: "integer", nullable: false),
                    TrapWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    ParaTrapWeakenScale = table.Column<int>(type: "integer", nullable: true),
                    AdvTrapWeakenScale = table.Column<int>(type: "integer", nullable: true),
                    FlareWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    SonicTol = table.Column<int>(type: "integer", nullable: true),
                    SonicWeakenScale = table.Column<int>(type: "integer", nullable: true),
                    SonicTimeLower = table.Column<int>(type: "integer", nullable: true),
                    FalldownTol = table.Column<int>(type: "integer", nullable: true),
                    FalldownWeakenScale = table.Column<int>(type: "integer", nullable: true),
                    FalldownTimeLower = table.Column<int>(type: "integer", nullable: true),
                    AnesthesiaCount = table.Column<int>(type: "integer", nullable: false),
                    Anesthesia = table.Column<int>(type: "integer", nullable: false),
                    AnesthesiaWeakenScale = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_abnormal_states", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_attributes",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    AttributeId = table.Column<int>(type: "integer", nullable: false),
                    ChineseName = table.Column<string>(type: "text", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Type = table.Column<string>(type: "text", nullable: false),
                    Bonus = table.Column<int>(type: "integer", nullable: false),
                    Sync = table.Column<int>(type: "integer", nullable: false),
                    Lower = table.Column<string>(type: "text", nullable: true),
                    Upper = table.Column<string>(type: "text", nullable: true),
                    Wrapper = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_attributes", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_emotions",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    StateFrom = table.Column<int>(type: "integer", nullable: false),
                    StateTo = table.Column<int>(type: "integer", nullable: false),
                    Condition = table.Column<string>(type: "text", nullable: true),
                    AndOr = table.Column<string>(type: "text", nullable: true),
                    Param1 = table.Column<string>(type: "text", nullable: true),
                    Param2 = table.Column<string>(type: "text", nullable: true),
                    Param3 = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_emotions", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    Icon = table.Column<string>(type: "text", nullable: true),
                    Name = table.Column<string>(type: "text", nullable: true),
                    InheritFrom = table.Column<int>(type: "integer", nullable: true),
                    MonsterType = table.Column<int>(type: "integer", nullable: false),
                    SpawnAppear = table.Column<string>(type: "text", nullable: true),
                    MonsterGroup = table.Column<int>(type: "integer", nullable: false),
                    EntityName = table.Column<string>(type: "text", nullable: true),
                    EntityClass = table.Column<string>(type: "text", nullable: true),
                    EntityCustomType = table.Column<string>(type: "text", nullable: true),
                    Race = table.Column<int>(type: "integer", nullable: false),
                    CameraDelayTime = table.Column<int>(type: "integer", nullable: false),
                    DeathCamera = table.Column<string>(type: "text", nullable: true),
                    DeathCameraPoint = table.Column<string>(type: "text", nullable: true),
                    InteractCamera = table.Column<string>(type: "text", nullable: true),
                    InteractCameraPoint = table.Column<string>(type: "text", nullable: true),
                    CatchCamera = table.Column<string>(type: "text", nullable: true),
                    CatchCameraPoint = table.Column<string>(type: "text", nullable: true),
                    ChangeAreaType = table.Column<int>(type: "integer", nullable: false),
                    Difficulty = table.Column<int>(type: "integer", nullable: false),
                    ArtIndexId = table.Column<int>(type: "integer", nullable: false),
                    LootSize = table.Column<int>(type: "integer", nullable: false),
                    Size = table.Column<float>(type: "real", nullable: false),
                    CaptureHPPercent = table.Column<int>(type: "integer", nullable: false),
                    ExistTime = table.Column<int>(type: "integer", nullable: false),
                    BBInitState = table.Column<int>(type: "integer", nullable: false),
                    BBMaxHealth = table.Column<int>(type: "integer", nullable: false),
                    IconCN = table.Column<string>(type: "text", nullable: true),
                    CanLoot = table.Column<int>(type: "integer", nullable: false),
                    CanCapture = table.Column<int>(type: "integer", nullable: false),
                    CritRate = table.Column<int>(type: "integer", nullable: false),
                    CritDamageModifier = table.Column<int>(type: "integer", nullable: false),
                    WaterModifier = table.Column<int>(type: "integer", nullable: false),
                    FireModifier = table.Column<int>(type: "integer", nullable: false),
                    ThunderModifier = table.Column<int>(type: "integer", nullable: false),
                    DragonModifier = table.Column<int>(type: "integer", nullable: false),
                    IceModifier = table.Column<int>(type: "integer", nullable: false),
                    SlashModifier = table.Column<int>(type: "integer", nullable: false),
                    ImpactModifier = table.Column<int>(type: "integer", nullable: false),
                    ShotModifier = table.Column<int>(type: "integer", nullable: false),
                    WaterAccum = table.Column<int>(type: "integer", nullable: false),
                    FireAccum = table.Column<int>(type: "integer", nullable: false),
                    ThunderAccum = table.Column<int>(type: "integer", nullable: false),
                    DragonAccum = table.Column<int>(type: "integer", nullable: false),
                    IceAccum = table.Column<int>(type: "integer", nullable: false),
                    NoneAccum = table.Column<int>(type: "integer", nullable: false),
                    BodySize = table.Column<float>(type: "real", nullable: false),
                    IdleSequenceName = table.Column<string>(type: "text", nullable: true),
                    InterestPointType = table.Column<string>(type: "text", nullable: true),
                    MaxPower = table.Column<int>(type: "integer", nullable: false),
                    PowerRecoverySpeed = table.Column<int>(type: "integer", nullable: false),
                    EmotionAngryTime = table.Column<int>(type: "integer", nullable: false),
                    AngryDamagePeakRange = table.Column<string>(type: "text", nullable: true),
                    AngryDamagePeakValue = table.Column<string>(type: "text", nullable: true),
                    EmotionAngryAnimSpeed = table.Column<float>(type: "real", nullable: false),
                    SkillSpeed = table.Column<float>(type: "real", nullable: false),
                    RegionMaxTime = table.Column<int>(type: "integer", nullable: false),
                    RegionMinTime = table.Column<int>(type: "integer", nullable: false),
                    DistBodySize = table.Column<float>(type: "real", nullable: false),
                    PreLoadBTOnServer = table.Column<string>(type: "text", nullable: true),
                    LootBone = table.Column<string>(type: "text", nullable: true),
                    LootOffset = table.Column<string>(type: "text", nullable: true),
                    LootRotation = table.Column<string>(type: "text", nullable: true),
                    EnableLemonSystem = table.Column<int>(type: "integer", nullable: false),
                    MinTag = table.Column<int>(type: "integer", nullable: false),
                    MaxTag = table.Column<int>(type: "integer", nullable: false),
                    EnterLemonMinHP = table.Column<int>(type: "integer", nullable: false),
                    EnterLemonMaxHP = table.Column<int>(type: "integer", nullable: false),
                    LemonTime = table.Column<int>(type: "integer", nullable: false),
                    LeaveLemonMinHP = table.Column<int>(type: "integer", nullable: false),
                    LeaveLemonMaxHP = table.Column<int>(type: "integer", nullable: false),
                    NeedShowEvEDmg = table.Column<int>(type: "integer", nullable: false),
                    NeedHidePVEDmg = table.Column<int>(type: "integer", nullable: false),
                    UseCombatNPCAtkModify = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_lemons",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    LemonSkill = table.Column<string>(type: "text", nullable: true),
                    Tag = table.Column<int>(type: "integer", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_lemons", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_part_defences",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    PartID = table.Column<int>(type: "integer", nullable: false),
                    StateID = table.Column<int>(type: "integer", nullable: false),
                    BreakLevel = table.Column<int>(type: "integer", nullable: false),
                    DefenceLevel = table.Column<int>(type: "integer", nullable: false),
                    Faint = table.Column<int>(type: "integer", nullable: false),
                    Cut = table.Column<int>(type: "integer", nullable: false),
                    Hammer = table.Column<int>(type: "integer", nullable: false),
                    Shoot = table.Column<int>(type: "integer", nullable: false),
                    Fire = table.Column<int>(type: "integer", nullable: false),
                    Water = table.Column<int>(type: "integer", nullable: false),
                    Electric = table.Column<int>(type: "integer", nullable: false),
                    Ice = table.Column<int>(type: "integer", nullable: false),
                    Dragon = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_part_defences", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_parts",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    PartID = table.Column<int>(type: "integer", nullable: false),
                    PartName = table.Column<string>(type: "text", nullable: true),
                    StateID = table.Column<int>(type: "integer", nullable: false),
                    Unbalance = table.Column<int>(type: "integer", nullable: false),
                    UnbalanceMulti = table.Column<float>(type: "real", nullable: false),
                    Scar = table.Column<int>(type: "integer", nullable: false),
                    Fall = table.Column<int>(type: "integer", nullable: false),
                    FallMulti = table.Column<float>(type: "real", nullable: false),
                    WaterAcc = table.Column<int>(type: "integer", nullable: false),
                    WaterAccMulti = table.Column<float>(type: "real", nullable: false),
                    FireAcc = table.Column<int>(type: "integer", nullable: false),
                    FireAccMulti = table.Column<float>(type: "real", nullable: false),
                    ElectricAcc = table.Column<int>(type: "integer", nullable: false),
                    ElectricAccMulti = table.Column<float>(type: "real", nullable: false),
                    DragonAcc = table.Column<int>(type: "integer", nullable: false),
                    DragonAccMulti = table.Column<float>(type: "real", nullable: false),
                    IceAcc = table.Column<int>(type: "integer", nullable: false),
                    IceAccMulti = table.Column<float>(type: "real", nullable: false),
                    NoneAcc = table.Column<int>(type: "integer", nullable: false),
                    NoneAccMulti = table.Column<float>(type: "real", nullable: false),
                    DmgVal1 = table.Column<int>(type: "integer", nullable: false),
                    ProcessLv1 = table.Column<int>(type: "integer", nullable: false),
                    Hammer1 = table.Column<int>(type: "integer", nullable: false),
                    Cut1 = table.Column<int>(type: "integer", nullable: false),
                    Shoot1 = table.Column<int>(type: "integer", nullable: false),
                    Water1 = table.Column<int>(type: "integer", nullable: false),
                    Fire1 = table.Column<int>(type: "integer", nullable: false),
                    Electric1 = table.Column<int>(type: "integer", nullable: false),
                    Dragon1 = table.Column<int>(type: "integer", nullable: false),
                    Ice1 = table.Column<int>(type: "integer", nullable: false),
                    LootSkillLv1 = table.Column<int>(type: "integer", nullable: false),
                    DmgVal2 = table.Column<int>(type: "integer", nullable: false),
                    ProcessLv2 = table.Column<int>(type: "integer", nullable: false),
                    Hammer2 = table.Column<int>(type: "integer", nullable: false),
                    Cut2 = table.Column<int>(type: "integer", nullable: false),
                    Shoot2 = table.Column<int>(type: "integer", nullable: false),
                    Water2 = table.Column<int>(type: "integer", nullable: false),
                    Fire2 = table.Column<int>(type: "integer", nullable: false),
                    Electric2 = table.Column<int>(type: "integer", nullable: false),
                    Dragon2 = table.Column<int>(type: "integer", nullable: false),
                    Ice2 = table.Column<int>(type: "integer", nullable: false),
                    LootSkillLv2 = table.Column<int>(type: "integer", nullable: false),
                    DmgVal3 = table.Column<int>(type: "integer", nullable: false),
                    ProcessLv3 = table.Column<int>(type: "integer", nullable: false),
                    Hammer3 = table.Column<int>(type: "integer", nullable: false),
                    Cut3 = table.Column<int>(type: "integer", nullable: false),
                    Shoot3 = table.Column<int>(type: "integer", nullable: false),
                    Water3 = table.Column<int>(type: "integer", nullable: false),
                    Fire3 = table.Column<int>(type: "integer", nullable: false),
                    Electric3 = table.Column<int>(type: "integer", nullable: false),
                    Dragon3 = table.Column<int>(type: "integer", nullable: false),
                    Ice3 = table.Column<int>(type: "integer", nullable: false),
                    LootSkillLv3 = table.Column<int>(type: "integer", nullable: false),
                    DmgVal4 = table.Column<int>(type: "integer", nullable: false),
                    ProcessLv4 = table.Column<int>(type: "integer", nullable: false),
                    Hammer4 = table.Column<int>(type: "integer", nullable: false),
                    Cut4 = table.Column<int>(type: "integer", nullable: false),
                    Shoot4 = table.Column<int>(type: "integer", nullable: false),
                    Water4 = table.Column<int>(type: "integer", nullable: false),
                    Fire4 = table.Column<int>(type: "integer", nullable: false),
                    Electric4 = table.Column<int>(type: "integer", nullable: false),
                    Dragon4 = table.Column<int>(type: "integer", nullable: false),
                    Ice4 = table.Column<int>(type: "integer", nullable: false),
                    LootSkillLv4 = table.Column<int>(type: "integer", nullable: false),
                    DmgVal5 = table.Column<int>(type: "integer", nullable: false),
                    ProcessLv5 = table.Column<int>(type: "integer", nullable: false),
                    Hammer5 = table.Column<int>(type: "integer", nullable: false),
                    Cut5 = table.Column<int>(type: "integer", nullable: false),
                    Shoot5 = table.Column<int>(type: "integer", nullable: false),
                    Water5 = table.Column<int>(type: "integer", nullable: false),
                    Fire5 = table.Column<int>(type: "integer", nullable: false),
                    Electric5 = table.Column<int>(type: "integer", nullable: false),
                    Dragon5 = table.Column<int>(type: "integer", nullable: false),
                    Ice5 = table.Column<int>(type: "integer", nullable: false),
                    LootSkillLv5 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_parts", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_perceptions",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    EyeBoneLeft = table.Column<string>(type: "text", nullable: true),
                    EyeBoneRight = table.Column<string>(type: "text", nullable: true),
                    EyeBoneCenter = table.Column<string>(type: "text", nullable: true),
                    VisionConeHeight = table.Column<float>(type: "real", nullable: false),
                    VisionConeAngle = table.Column<float>(type: "real", nullable: false),
                    VisionConeAngleAlert = table.Column<float>(type: "real", nullable: false),
                    HearingBone = table.Column<string>(type: "text", nullable: true),
                    HearingDistance = table.Column<float>(type: "real", nullable: false),
                    HearingDistanceExNear = table.Column<float>(type: "real", nullable: false),
                    HearingDistanceNear = table.Column<float>(type: "real", nullable: false),
                    HearingDistanceMedium = table.Column<float>(type: "real", nullable: false),
                    HearingDistanceFar = table.Column<float>(type: "real", nullable: false),
                    HearingThredAlert = table.Column<float>(type: "real", nullable: false),
                    HearingThredPreComb = table.Column<float>(type: "real", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_perceptions", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "monster_states",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MonsterID = table.Column<int>(type: "integer", nullable: false),
                    StateID = table.Column<int>(type: "integer", nullable: false),
                    StateName = table.Column<string>(type: "text", nullable: true),
                    BBInitValue = table.Column<int>(type: "integer", nullable: false),
                    BBMaxValue = table.Column<int>(type: "integer", nullable: false),
                    CurrentAccumValue = table.Column<int>(type: "integer", nullable: false),
                    AccumValueMin = table.Column<int>(type: "integer", nullable: false),
                    ReleaseAccumValue = table.Column<int>(type: "integer", nullable: false),
                    AccumDecayRate = table.Column<float>(type: "real", nullable: false),
                    ActionSpeed = table.Column<float>(type: "real", nullable: false),
                    AttackMultiplier = table.Column<float>(type: "real", nullable: false),
                    DefenseMultiplier = table.Column<float>(type: "real", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_monster_states", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "npc_daily_works",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    WorkId = table.Column<int>(type: "integer", nullable: false),
                    NpcId = table.Column<int>(type: "integer", nullable: false),
                    StartTime = table.Column<string>(type: "text", nullable: false),
                    Intrestring1 = table.Column<string>(type: "text", nullable: true),
                    Intrestring2 = table.Column<string>(type: "text", nullable: true),
                    Intrestring3 = table.Column<string>(type: "text", nullable: true),
                    Intrestring4 = table.Column<string>(type: "text", nullable: true),
                    Intrestring5 = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_npc_daily_works", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "npc_data",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    NpcId = table.Column<int>(type: "integer", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: true),
                    Title = table.Column<string>(type: "text", nullable: true),
                    EntityName = table.Column<string>(type: "text", nullable: true),
                    EntityClass = table.Column<string>(type: "text", nullable: true),
                    EntityCustomType = table.Column<string>(type: "text", nullable: true),
                    MinimapIcon = table.Column<string>(type: "text", nullable: true),
                    DeathCamera = table.Column<string>(type: "text", nullable: true),
                    DeathCameraPoint = table.Column<string>(type: "text", nullable: true),
                    CameraDelayTime = table.Column<int>(type: "integer", nullable: false),
                    InteractCamera = table.Column<string>(type: "text", nullable: true),
                    InteractCameraPoint = table.Column<string>(type: "text", nullable: true),
                    HideNamepad = table.Column<int>(type: "integer", nullable: false),
                    AppearTask = table.Column<int>(type: "integer", nullable: true),
                    DisappearTask = table.Column<int>(type: "integer", nullable: true),
                    ReappearTask = table.Column<int>(type: "integer", nullable: true),
                    DisappearTask2 = table.Column<int>(type: "integer", nullable: true),
                    ReappearTask2 = table.Column<int>(type: "integer", nullable: true),
                    DisappearTask3 = table.Column<int>(type: "integer", nullable: true),
                    ReappearTask3 = table.Column<int>(type: "integer", nullable: true),
                    DisappearTask4 = table.Column<int>(type: "integer", nullable: true),
                    ReappearTask4 = table.Column<int>(type: "integer", nullable: true),
                    DisappearTask5 = table.Column<int>(type: "integer", nullable: true),
                    ReappearTask5 = table.Column<int>(type: "integer", nullable: true),
                    AppearType = table.Column<int>(type: "integer", nullable: true),
                    AppearCondition = table.Column<int>(type: "integer", nullable: true),
                    ForgeEnabled = table.Column<int>(type: "integer", nullable: false),
                    SupplyBoxEnabled = table.Column<int>(type: "integer", nullable: false),
                    TurnInBoxEnabled = table.Column<int>(type: "integer", nullable: false),
                    Mail = table.Column<int>(type: "integer", nullable: true),
                    Auction = table.Column<int>(type: "integer", nullable: true),
                    LegendLevelUp = table.Column<int>(type: "integer", nullable: true),
                    LegendInlayAndTakeDown = table.Column<int>(type: "integer", nullable: true),
                    LegendDerive = table.Column<int>(type: "integer", nullable: true),
                    Enhance = table.Column<int>(type: "integer", nullable: true),
                    RankUp = table.Column<int>(type: "integer", nullable: true),
                    ManufactureLearn = table.Column<int>(type: "integer", nullable: true),
                    Storage = table.Column<int>(type: "integer", nullable: true),
                    Daily = table.Column<int>(type: "integer", nullable: true),
                    MaterialDecompose = table.Column<int>(type: "integer", nullable: true),
                    PetForge = table.Column<int>(type: "integer", nullable: true),
                    PetShop = table.Column<int>(type: "integer", nullable: true),
                    LevelEntrustList = table.Column<int>(type: "integer", nullable: true),
                    LevelEntrustGo = table.Column<int>(type: "integer", nullable: true),
                    Found = table.Column<int>(type: "integer", nullable: true),
                    CreateHunterGroup = table.Column<int>(type: "integer", nullable: true),
                    QuestHunterGroup = table.Column<int>(type: "integer", nullable: true),
                    SearchHunterGroup = table.Column<int>(type: "integer", nullable: true),
                    EquipEmbed = table.Column<int>(type: "integer", nullable: true),
                    FarmCollectionPoint = table.Column<int>(type: "integer", nullable: true),
                    FarmEquipGallery = table.Column<int>(type: "integer", nullable: true),
                    FarmTrain = table.Column<int>(type: "integer", nullable: true),
                    FarmSeed = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupEditIcon = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupSalary = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupEditBaseName = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupDisBand = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupRecRuitUP = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupStorehouseUP = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupTradeUP = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupGoldStore = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupUnlockShop = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupSkill = table.Column<int>(type: "integer", nullable: true),
                    FirePet = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupTrainUP = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupInventory = table.Column<int>(type: "integer", nullable: true),
                    ClanCreate = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupLeagueRegistration = table.Column<int>(type: "integer", nullable: true),
                    PvpLineup8 = table.Column<int>(type: "integer", nullable: true),
                    PvpQuitLine = table.Column<int>(type: "integer", nullable: true),
                    CharmFound = table.Column<int>(type: "integer", nullable: true),
                    CharmMix = table.Column<int>(type: "integer", nullable: true),
                    WeaponWake = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupLeagueStart = table.Column<int>(type: "integer", nullable: true),
                    EquipUpgrade = table.Column<int>(type: "integer", nullable: true),
                    ContestJoin = table.Column<int>(type: "integer", nullable: true),
                    Contestrank = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupLeagueStartPK = table.Column<int>(type: "integer", nullable: true),
                    HunterGroupLeaguePKMap = table.Column<int>(type: "integer", nullable: true),
                    SuperStar = table.Column<int>(type: "integer", nullable: true),
                    GiveUpLeagueReg = table.Column<int>(type: "integer", nullable: true),
                    Exchange = table.Column<int>(type: "integer", nullable: true),
                    GetAward = table.Column<int>(type: "integer", nullable: true),
                    FarmAward = table.Column<int>(type: "integer", nullable: true),
                    RapidHunt = table.Column<int>(type: "integer", nullable: true),
                    SkyKing = table.Column<int>(type: "integer", nullable: true),
                    EquipQuench = table.Column<int>(type: "integer", nullable: true),
                    EquipUnQuench = table.Column<int>(type: "integer", nullable: true),
                    EquipReborn = table.Column<int>(type: "integer", nullable: true),
                    Unbind = table.Column<int>(type: "integer", nullable: true),
                    ItemLevelUpgrade = table.Column<int>(type: "integer", nullable: true),
                    PetRandomShop = table.Column<int>(type: "integer", nullable: true),
                    PetTreasure = table.Column<int>(type: "integer", nullable: true),
                    ItemExchange = table.Column<int>(type: "integer", nullable: true),
                    PvpBattleList = table.Column<int>(type: "integer", nullable: true),
                    LoginCoachView = table.Column<int>(type: "integer", nullable: true),
                    StarStoneDevelop = table.Column<int>(type: "integer", nullable: true),
                    StarStoneInlay = table.Column<int>(type: "integer", nullable: true),
                    StarStoneRepair = table.Column<int>(type: "integer", nullable: true),
                    NianMonsterHunt = table.Column<int>(type: "integer", nullable: true),
                    NianMonsterFireworks = table.Column<int>(type: "integer", nullable: true),
                    MatchEntryView = table.Column<int>(type: "integer", nullable: true),
                    NianMonsterExchange = table.Column<int>(type: "integer", nullable: true),
                    WildHuntSignUp = table.Column<int>(type: "integer", nullable: true),
                    WildHuntInfo = table.Column<int>(type: "integer", nullable: true),
                    HunterWebApp = table.Column<int>(type: "integer", nullable: true),
                    Transfer = table.Column<int>(type: "integer", nullable: true),
                    WildHuntAward = table.Column<int>(type: "integer", nullable: true),
                    WildHuntWinnerLevel = table.Column<int>(type: "integer", nullable: true),
                    CatFoodNew = table.Column<int>(type: "integer", nullable: true),
                    WeaponTrial = table.Column<int>(type: "integer", nullable: true),
                    XmasGrow = table.Column<int>(type: "integer", nullable: true),
                    XmasShare = table.Column<int>(type: "integer", nullable: true),
                    XmasTree = table.Column<int>(type: "integer", nullable: true),
                    Dinivation = table.Column<int>(type: "integer", nullable: true),
                    QuickSupplyEdit = table.Column<int>(type: "integer", nullable: true),
                    QuickSupplyApply = table.Column<int>(type: "integer", nullable: true),
                    PvpRank = table.Column<int>(type: "integer", nullable: true),
                    GuildActivity = table.Column<int>(type: "integer", nullable: true),
                    Firework = table.Column<int>(type: "integer", nullable: true),
                    ApplyForCommander = table.Column<int>(type: "integer", nullable: true),
                    WorldMap = table.Column<int>(type: "integer", nullable: true),
                    SecretResearch = table.Column<int>(type: "integer", nullable: true),
                    NewYearRedPacket = table.Column<int>(type: "integer", nullable: true),
                    SkillFile = table.Column<string>(type: "text", nullable: true),
                    Animation1 = table.Column<string>(type: "text", nullable: true),
                    Animation2 = table.Column<string>(type: "text", nullable: true),
                    Animation3 = table.Column<string>(type: "text", nullable: true),
                    Animation4 = table.Column<string>(type: "text", nullable: true),
                    Animation5 = table.Column<string>(type: "text", nullable: true),
                    Animation6 = table.Column<string>(type: "text", nullable: true),
                    Animation7 = table.Column<string>(type: "text", nullable: true),
                    Animation8 = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_npc_data", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "npc_shop_mappings",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MappingId = table.Column<int>(type: "integer", nullable: false),
                    NpcId = table.Column<int>(type: "integer", nullable: false),
                    NpcName = table.Column<string>(type: "text", nullable: true),
                    Shop01Id = table.Column<int>(type: "integer", nullable: true),
                    Shop01Name = table.Column<string>(type: "text", nullable: true),
                    Shop02Id = table.Column<int>(type: "integer", nullable: true),
                    Shop02Name = table.Column<string>(type: "text", nullable: true),
                    Shop03Id = table.Column<int>(type: "integer", nullable: true),
                    Shop03Name = table.Column<string>(type: "text", nullable: true),
                    Shop04Id = table.Column<int>(type: "integer", nullable: true),
                    Shop04Name = table.Column<string>(type: "text", nullable: true),
                    Shop05Id = table.Column<int>(type: "integer", nullable: true),
                    Shop05Name = table.Column<string>(type: "text", nullable: true),
                    Shop06Id = table.Column<int>(type: "integer", nullable: true),
                    Shop06Name = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_npc_shop_mappings", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_aptitude_qualities",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    AptitudeQualityId = table.Column<int>(type: "integer", nullable: false),
                    Aptitude = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<int>(type: "integer", nullable: false),
                    Personality = table.Column<int>(type: "integer", nullable: false),
                    FixedSkillId = table.Column<int>(type: "integer", nullable: false),
                    InitialSkillPoints = table.Column<int>(type: "integer", nullable: false),
                    SkillGrowthPoints = table.Column<int>(type: "integer", nullable: false),
                    PotentialGrowthPoints = table.Column<int>(type: "integer", nullable: false),
                    MaxLevel = table.Column<int>(type: "integer", nullable: false),
                    EliteSkillSlots = table.Column<int>(type: "integer", nullable: false),
                    ActiveSkillSlots = table.Column<int>(type: "integer", nullable: false),
                    PassiveSkillSlots = table.Column<int>(type: "integer", nullable: false),
                    SupportPassiveSkillSlots = table.Column<int>(type: "integer", nullable: false),
                    SupportActiveSkillSlots = table.Column<int>(type: "integer", nullable: false),
                    InitialAttack = table.Column<int>(type: "integer", nullable: false),
                    AttackGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    InitialDefense = table.Column<int>(type: "integer", nullable: false),
                    DefenseGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    InitialHp = table.Column<int>(type: "integer", nullable: false),
                    HpGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    InitialActionPower = table.Column<int>(type: "integer", nullable: false),
                    ActionPowerGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    InitialObservation = table.Column<int>(type: "integer", nullable: false),
                    ObservationGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    InitialLoadCapacity = table.Column<int>(type: "integer", nullable: false),
                    LoadCapacityGrowthCoef = table.Column<float>(type: "real", nullable: false),
                    NormalSkillSlotMax = table.Column<int>(type: "integer", nullable: false),
                    FluteSkillSlotMax = table.Column<int>(type: "integer", nullable: false),
                    MedalSkillSlotMax = table.Column<int>(type: "integer", nullable: false),
                    InnateSkillMax = table.Column<int>(type: "integer", nullable: false),
                    SupportSkillMax = table.Column<int>(type: "integer", nullable: false),
                    NormalSkillSlotLockInfo = table.Column<string>(type: "text", nullable: true),
                    NormalSkillSlot1UnlockCondition = table.Column<string>(type: "text", nullable: true),
                    NormalSkillSlot2UnlockCondition = table.Column<string>(type: "text", nullable: true),
                    NormalSkillSlot3UnlockCondition = table.Column<string>(type: "text", nullable: true),
                    FluteSkillSlotLockInfo = table.Column<string>(type: "text", nullable: true),
                    FluteSkillSlot1UnlockCondition = table.Column<string>(type: "text", nullable: true),
                    FluteSkillSlot2UnlockCondition = table.Column<string>(type: "text", nullable: true),
                    Defence = table.Column<float>(type: "real", nullable: false),
                    PhyPDRatio = table.Column<float>(type: "real", nullable: false),
                    MonsterAtkPet = table.Column<float>(type: "real", nullable: false),
                    PlayerAtkPet = table.Column<float>(type: "real", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_aptitude_qualities", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_attack_methods",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    MethodId = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_attack_methods", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_attack_tendencies",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    TendencyId = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_attack_tendencies", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_combat_skills",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    SkillGroupId = table.Column<int>(type: "integer", nullable: false),
                    CdReductionSkillGroup = table.Column<int>(type: "integer", nullable: false),
                    SkillGroupName = table.Column<string>(type: "text", nullable: true),
                    SkillName = table.Column<string>(type: "text", nullable: true),
                    LearnJobLimit = table.Column<int>(type: "integer", nullable: false),
                    CanBeRandom = table.Column<int>(type: "integer", nullable: false),
                    CanBeUpgradeRandom = table.Column<int>(type: "integer", nullable: false),
                    RandomWeight = table.Column<int>(type: "integer", nullable: false),
                    LearnLevelLimit = table.Column<int>(type: "integer", nullable: false),
                    SkillLevel = table.Column<int>(type: "integer", nullable: false),
                    IsEliteSkill = table.Column<int>(type: "integer", nullable: false),
                    SkillType = table.Column<int>(type: "integer", nullable: false),
                    SubType = table.Column<int>(type: "integer", nullable: false),
                    ComprehensionCount = table.Column<int>(type: "integer", nullable: false),
                    SkillPointCost = table.Column<int>(type: "integer", nullable: false),
                    IntimacyHeartLevel = table.Column<int>(type: "integer", nullable: false),
                    Aptitude = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup1 = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup2 = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup3 = table.Column<int>(type: "integer", nullable: false),
                    ActiveSkillId = table.Column<int>(type: "integer", nullable: false),
                    ActiveSkillTriggerRate = table.Column<int>(type: "integer", nullable: false),
                    SelfPassiveBuff = table.Column<int>(type: "integer", nullable: false),
                    OwnerPassiveBuff = table.Column<int>(type: "integer", nullable: false),
                    SelfSkillBuff = table.Column<int>(type: "integer", nullable: false),
                    OwnerSkillBuff = table.Column<int>(type: "integer", nullable: false),
                    OwnerEffect = table.Column<string>(type: "text", nullable: true),
                    SelfEffect = table.Column<string>(type: "text", nullable: true),
                    MonsterEffect = table.Column<string>(type: "text", nullable: true),
                    SkillDescription = table.Column<string>(type: "text", nullable: true),
                    Icon = table.Column<string>(type: "text", nullable: true),
                    NewType = table.Column<int>(type: "integer", nullable: false),
                    TalkId = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_combat_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_farewell_gifts",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    IntimacyStarLevel = table.Column<int>(type: "integer", nullable: false),
                    CompensationItemId1 = table.Column<int>(type: "integer", nullable: false),
                    Count1 = table.Column<int>(type: "integer", nullable: false),
                    CompensationItemId2 = table.Column<int>(type: "integer", nullable: false),
                    Count2 = table.Column<int>(type: "integer", nullable: false),
                    CompensationItemId3 = table.Column<int>(type: "integer", nullable: false),
                    Count3 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_farewell_gifts", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    PetId = table.Column<int>(type: "integer", nullable: false),
                    IsRandomAttribute = table.Column<int>(type: "integer", nullable: false),
                    DefaultName = table.Column<string>(type: "text", nullable: true),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    Species = table.Column<int>(type: "integer", nullable: false),
                    Specialization = table.Column<int>(type: "integer", nullable: false),
                    Aptitude = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<int>(type: "integer", nullable: false),
                    Personality = table.Column<int>(type: "integer", nullable: false),
                    AttackTendency = table.Column<int>(type: "integer", nullable: false),
                    AttackMethod = table.Column<int>(type: "integer", nullable: false),
                    BurrowHpPercent = table.Column<int>(type: "integer", nullable: false),
                    HpRecoverySpeed = table.Column<int>(type: "integer", nullable: false),
                    SupportSkill = table.Column<string>(type: "text", nullable: true),
                    InnateSkillGroup = table.Column<string>(type: "text", nullable: true),
                    BubbleGroup = table.Column<string>(type: "text", nullable: true),
                    EntityName = table.Column<string>(type: "text", nullable: true),
                    Class = table.Column<int>(type: "integer", nullable: false),
                    CustomName = table.Column<string>(type: "text", nullable: true),
                    Icon = table.Column<string>(type: "text", nullable: true),
                    Skin = table.Column<int>(type: "integer", nullable: false),
                    Description = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_innate_skills",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    SkillGroup = table.Column<int>(type: "integer", nullable: false),
                    SkillName = table.Column<string>(type: "text", nullable: true),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    IsEliteSkill = table.Column<int>(type: "integer", nullable: false),
                    UpgradeLevelLimit = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem1 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem1Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem2 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem2Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem3 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem3Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradedSkillId = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_innate_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_levels",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    UpgradeExp = table.Column<int>(type: "integer", nullable: false),
                    SkillPointGrowth = table.Column<int>(type: "integer", nullable: false),
                    PotentialPointGrowth = table.Column<int>(type: "integer", nullable: false),
                    AttackGrowth = table.Column<int>(type: "integer", nullable: false),
                    DefenseGrowth = table.Column<int>(type: "integer", nullable: false),
                    HpGrowth = table.Column<int>(type: "integer", nullable: false),
                    ActionPowerGrowth = table.Column<int>(type: "integer", nullable: false),
                    ObservationGrowth = table.Column<int>(type: "integer", nullable: false),
                    LoadCapacityGrowth = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_levels", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_names",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    PetNameId = table.Column<int>(type: "integer", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_names", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_personalities",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    PersonalityId = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_personalities", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_production_skill_effects",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    GatherPointType = table.Column<int>(type: "integer", nullable: false),
                    EffectCondition = table.Column<string>(type: "text", nullable: true),
                    IntimacyIncrease = table.Column<int>(type: "integer", nullable: false),
                    ExpIncreasePercent = table.Column<int>(type: "integer", nullable: false),
                    EnergyReductionPercent = table.Column<int>(type: "integer", nullable: false),
                    ToolBreakReduction = table.Column<int>(type: "integer", nullable: false),
                    GatherCountIncrease = table.Column<int>(type: "integer", nullable: false),
                    ConstructionIncreasePercent = table.Column<int>(type: "integer", nullable: false),
                    NoConsumeChance = table.Column<int>(type: "integer", nullable: false),
                    RewardRandomIncrease = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_production_skill_effects", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_production_skills",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    CdReductionSkillGroup = table.Column<int>(type: "integer", nullable: false),
                    SkillGroupId = table.Column<int>(type: "integer", nullable: false),
                    SkillGroupName = table.Column<string>(type: "text", nullable: true),
                    SkillName = table.Column<string>(type: "text", nullable: true),
                    LearnJobLimit = table.Column<int>(type: "integer", nullable: false),
                    CanBeRandom = table.Column<int>(type: "integer", nullable: false),
                    CanBeUpgradeRandom = table.Column<int>(type: "integer", nullable: false),
                    RandomWeight = table.Column<int>(type: "integer", nullable: false),
                    LearnLevelLimit = table.Column<int>(type: "integer", nullable: false),
                    SkillLevel = table.Column<int>(type: "integer", nullable: false),
                    IsEliteSkill = table.Column<int>(type: "integer", nullable: false),
                    SkillType = table.Column<int>(type: "integer", nullable: false),
                    SubType = table.Column<int>(type: "integer", nullable: false),
                    MatchResourcePoint = table.Column<string>(type: "text", nullable: true),
                    LearnCondition = table.Column<string>(type: "text", nullable: true),
                    SkillPointCost = table.Column<int>(type: "integer", nullable: false),
                    IntimacyHeartLevel = table.Column<int>(type: "integer", nullable: false),
                    Aptitude = table.Column<int>(type: "integer", nullable: false),
                    Quality = table.Column<int>(type: "integer", nullable: false),
                    ActionPower = table.Column<int>(type: "integer", nullable: false),
                    Observation = table.Column<int>(type: "integer", nullable: false),
                    LoadCapacity = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup1 = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup2 = table.Column<int>(type: "integer", nullable: false),
                    MutualExclusionGroup3 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_production_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_qualities",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    QualityId = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_qualities", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_skill_slot_unlocks",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SlotId = table.Column<int>(type: "integer", nullable: false),
                    ItemId = table.Column<int>(type: "integer", nullable: false),
                    ItemCount = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_skill_slot_unlocks", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_skill_triggers",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    TriggerType = table.Column<int>(type: "integer", nullable: false),
                    PreCastStartAnimation = table.Column<string>(type: "text", nullable: true),
                    PreCastLoopAnimation = table.Column<string>(type: "text", nullable: true),
                    PreCastCount = table.Column<int>(type: "integer", nullable: false),
                    CastAnimation = table.Column<string>(type: "text", nullable: true),
                    EffectModifierParam = table.Column<string>(type: "text", nullable: true),
                    SkillPointCost = table.Column<int>(type: "integer", nullable: false),
                    Priority = table.Column<int>(type: "integer", nullable: false),
                    CD = table.Column<int>(type: "integer", nullable: false),
                    CastDelayMin = table.Column<int>(type: "integer", nullable: false),
                    CastDelayMax = table.Column<int>(type: "integer", nullable: false),
                    CastCountMax = table.Column<int>(type: "integer", nullable: false),
                    MinTriggerDistance = table.Column<float>(type: "real", nullable: false),
                    MaxTriggerDistance = table.Column<float>(type: "real", nullable: false),
                    Target = table.Column<int>(type: "integer", nullable: false),
                    EmergencyCondition = table.Column<string>(type: "text", nullable: true),
                    EmergencyConditionParam1 = table.Column<string>(type: "text", nullable: true),
                    EmergencyConditionParam2 = table.Column<string>(type: "text", nullable: true),
                    EmergencyConditionAndOr = table.Column<string>(type: "text", nullable: true),
                    NormalCondition = table.Column<string>(type: "text", nullable: true),
                    NormalConditionParam1 = table.Column<string>(type: "text", nullable: true),
                    NormalConditionParam2 = table.Column<string>(type: "text", nullable: true),
                    NormalConditionAndOr = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_skill_triggers", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_skins",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkinId = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    Icon = table.Column<string>(type: "text", nullable: true),
                    Description = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_skins", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "pet_support_skills",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    SkillId = table.Column<int>(type: "integer", nullable: false),
                    SkillName = table.Column<string>(type: "text", nullable: true),
                    Level = table.Column<int>(type: "integer", nullable: false),
                    BuffId = table.Column<int>(type: "integer", nullable: false),
                    UpgradeLevelLimit = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem1 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem1Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem2 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem2Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem3 = table.Column<int>(type: "integer", nullable: false),
                    UpgradeItem3Count = table.Column<int>(type: "integer", nullable: false),
                    UpgradedSkillId = table.Column<int>(type: "integer", nullable: false),
                    Description = table.Column<string>(type: "text", nullable: true),
                    Icon = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_pet_support_skills", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "player_attributes",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    AttributeId = table.Column<int>(type: "integer", nullable: false),
                    ChineseName = table.Column<string>(type: "text", nullable: false),
                    Name = table.Column<string>(type: "text", nullable: false),
                    Type = table.Column<string>(type: "text", nullable: false),
                    Version = table.Column<int>(type: "integer", nullable: false),
                    Self = table.Column<int>(type: "integer", nullable: false),
                    Appear = table.Column<int>(type: "integer", nullable: false),
                    Query = table.Column<int>(type: "integer", nullable: false),
                    Bonus = table.Column<int>(type: "integer", nullable: false),
                    SaveDB = table.Column<int>(type: "integer", nullable: false),
                    Sync = table.Column<int>(type: "integer", nullable: false),
                    InitVal = table.Column<string>(type: "text", nullable: true),
                    PvPInitVal = table.Column<string>(type: "text", nullable: true),
                    Event = table.Column<int>(type: "integer", nullable: false),
                    ResetVal = table.Column<string>(type: "text", nullable: true),
                    Reset1 = table.Column<int>(type: "integer", nullable: false),
                    Reset2 = table.Column<int>(type: "integer", nullable: false),
                    Reset3 = table.Column<int>(type: "integer", nullable: false),
                    Reset4 = table.Column<int>(type: "integer", nullable: false),
                    Lower = table.Column<string>(type: "text", nullable: true),
                    Upper = table.Column<string>(type: "text", nullable: true),
                    InUse = table.Column<int>(type: "integer", nullable: false),
                    Note = table.Column<string>(type: "text", nullable: true),
                    Other = table.Column<string>(type: "text", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_player_attributes", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "random_groups",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    GroupId = table.Column<int>(type: "integer", nullable: false),
                    RandomCount = table.Column<int>(type: "integer", nullable: false),
                    PriceResetPeriod = table.Column<int>(type: "integer", nullable: false),
                    PriceResetTime = table.Column<string>(type: "text", nullable: true),
                    PriceBonus1 = table.Column<int>(type: "integer", nullable: false),
                    PriceBonus2 = table.Column<int>(type: "integer", nullable: false),
                    PriceBonus3 = table.Column<int>(type: "integer", nullable: false),
                    PriceBonus4 = table.Column<int>(type: "integer", nullable: false),
                    PriceBonus5 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_random_groups", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "random_pools",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    PoolId = table.Column<int>(type: "integer", nullable: false),
                    RandomType = table.Column<int>(type: "integer", nullable: false),
                    RefreshPeriod = table.Column<int>(type: "integer", nullable: false),
                    RefreshTime = table.Column<string>(type: "text", nullable: true),
                    Groups = table.Column<string>(type: "text", nullable: true),
                    BuyTimeInterval = table.Column<int>(type: "integer", nullable: false),
                    Points = table.Column<int>(type: "integer", nullable: false),
                    BindPoints = table.Column<int>(type: "integer", nullable: false),
                    UnlockCard = table.Column<int>(type: "integer", nullable: false),
                    RefreshCount1 = table.Column<int>(type: "integer", nullable: false),
                    RefreshPrice1 = table.Column<int>(type: "integer", nullable: false),
                    RefreshCount2 = table.Column<int>(type: "integer", nullable: false),
                    RefreshPrice2 = table.Column<int>(type: "integer", nullable: false),
                    RefreshCount3 = table.Column<int>(type: "integer", nullable: false),
                    RefreshPrice3 = table.Column<int>(type: "integer", nullable: false),
                    RefreshCount4 = table.Column<int>(type: "integer", nullable: false),
                    RefreshPrice4 = table.Column<int>(type: "integer", nullable: false),
                    RefreshCount5 = table.Column<int>(type: "integer", nullable: false),
                    RefreshPrice5 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_random_pools", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "random_products",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    ProductRecordId = table.Column<int>(type: "integer", nullable: false),
                    ProductRowId = table.Column<int>(type: "integer", nullable: false),
                    Group = table.Column<int>(type: "integer", nullable: false),
                    ProductId = table.Column<int>(type: "integer", nullable: false),
                    ProductCount = table.Column<int>(type: "integer", nullable: false),
                    Weight = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_random_products", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "shop_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    RowId = table.Column<int>(type: "integer", nullable: false),
                    ShopId = table.Column<int>(type: "integer", nullable: false),
                    ShopType = table.Column<int>(type: "integer", nullable: false),
                    ShopName = table.Column<string>(type: "text", nullable: true),
                    RowIndex = table.Column<int>(type: "integer", nullable: false),
                    SaleItemId = table.Column<int>(type: "integer", nullable: false),
                    DefaultBuyCount = table.Column<int>(type: "integer", nullable: false),
                    UnitPrice = table.Column<int>(type: "integer", nullable: false),
                    IsTotalPrice = table.Column<int>(type: "integer", nullable: false),
                    SaleItemName = table.Column<string>(type: "text", nullable: true),
                    SaleBindType = table.Column<int>(type: "integer", nullable: false),
                    HunterGuildUnlockIndex = table.Column<int>(type: "integer", nullable: false),
                    RandomType = table.Column<int>(type: "integer", nullable: false),
                    BuyPeriodLimit = table.Column<int>(type: "integer", nullable: false),
                    PeriodMaxBuyCount = table.Column<int>(type: "integer", nullable: false),
                    PriorityBindGold = table.Column<int>(type: "integer", nullable: false),
                    CurrencyDisplay = table.Column<string>(type: "text", nullable: true),
                    NpcGroup = table.Column<int>(type: "integer", nullable: false),
                    FriendlyLevelRequired = table.Column<int>(type: "integer", nullable: false),
                    Discount = table.Column<float>(type: "real", nullable: false),
                    StarLevelLimit = table.Column<int>(type: "integer", nullable: false),
                    HuntSoulStoneLimit = table.Column<int>(type: "integer", nullable: false),
                    SaleStartTime = table.Column<string>(type: "text", nullable: true),
                    SaleEndTime = table.Column<string>(type: "text", nullable: true),
                    SpecialPoint1Type = table.Column<int>(type: "integer", nullable: false),
                    SpecialPoint1Count = table.Column<int>(type: "integer", nullable: false),
                    SpecialPoint1Discount = table.Column<float>(type: "real", nullable: false),
                    SpecialPoint2Type = table.Column<int>(type: "integer", nullable: false),
                    SpecialPoint2Count = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemId01 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemName01 = table.Column<string>(type: "text", nullable: true),
                    ExchangeCount01 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemId02 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemName02 = table.Column<string>(type: "text", nullable: true),
                    ExchangeCount02 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemId03 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemName03 = table.Column<string>(type: "text", nullable: true),
                    ExchangeCount03 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemId04 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemName04 = table.Column<string>(type: "text", nullable: true),
                    ExchangeCount04 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemId05 = table.Column<int>(type: "integer", nullable: false),
                    ExchangeItemName05 = table.Column<string>(type: "text", nullable: true),
                    ExchangeCount05 = table.Column<int>(type: "integer", nullable: false),
                    IsValid = table.Column<int>(type: "integer", nullable: false),
                    Group = table.Column<int>(type: "integer", nullable: false),
                    Bonus1 = table.Column<string>(type: "text", nullable: true),
                    Bonus2 = table.Column<string>(type: "text", nullable: true),
                    Bonus3 = table.Column<string>(type: "text", nullable: true),
                    Bonus4 = table.Column<string>(type: "text", nullable: true),
                    Bonus5 = table.Column<string>(type: "text", nullable: true),
                    EquipPreview = table.Column<string>(type: "text", nullable: true),
                    IsUnifiedShop = table.Column<int>(type: "integer", nullable: false),
                    LevelLimit = table.Column<int>(type: "integer", nullable: false),
                    SystemUnlock = table.Column<int>(type: "integer", nullable: false),
                    FeatureTags = table.Column<string>(type: "text", nullable: true),
                    ItemCategory1 = table.Column<int>(type: "integer", nullable: false),
                    ItemCategory2 = table.Column<int>(type: "integer", nullable: false),
                    ItemCategory3 = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_shop_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "tattoo_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    TattooId = table.Column<int>(type: "integer", nullable: false),
                    MaleModelId = table.Column<int>(type: "integer", nullable: true),
                    FemaleModelId = table.Column<int>(type: "integer", nullable: true),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_tattoo_infos", x => x.Id);
                });

            migrationBuilder.CreateTable(
                name: "underclothes_infos",
                columns: table => new
                {
                    Id = table.Column<long>(type: "bigint", nullable: false)
                        .Annotation("Npgsql:ValueGenerationStrategy", NpgsqlValueGenerationStrategy.IdentityByDefaultColumn),
                    UnderclothesId = table.Column<int>(type: "integer", nullable: false),
                    MaleWrist = table.Column<int>(type: "integer", nullable: false),
                    MaleChest = table.Column<int>(type: "integer", nullable: false),
                    MaleLegs = table.Column<int>(type: "integer", nullable: false),
                    FemaleWrist = table.Column<int>(type: "integer", nullable: false),
                    FemaleChest = table.Column<int>(type: "integer", nullable: false),
                    FemaleLegs = table.Column<int>(type: "integer", nullable: false),
                    LastTimeModified = table.Column<DateTime>(type: "timestamp with time zone", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_underclothes_infos", x => x.Id);
                });

            DataSeeder.SeedAddDataRecordTables(migrationBuilder);

        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "face_infos");

            migrationBuilder.DropTable(
                name: "hair_infos");

            migrationBuilder.DropTable(
                name: "hr_levels");

            migrationBuilder.DropTable(
                name: "init_attributes");

            migrationBuilder.DropTable(
                name: "init_items");

            migrationBuilder.DropTable(
                name: "init_quick_supplies");

            migrationBuilder.DropTable(
                name: "init_shortcuts");

            migrationBuilder.DropTable(
                name: "init_stores");

            migrationBuilder.DropTable(
                name: "monster_abnormal_states");

            migrationBuilder.DropTable(
                name: "monster_attributes");

            migrationBuilder.DropTable(
                name: "monster_emotions");

            migrationBuilder.DropTable(
                name: "monster_infos");

            migrationBuilder.DropTable(
                name: "monster_lemons");

            migrationBuilder.DropTable(
                name: "monster_part_defences");

            migrationBuilder.DropTable(
                name: "monster_parts");

            migrationBuilder.DropTable(
                name: "monster_perceptions");

            migrationBuilder.DropTable(
                name: "monster_states");

            migrationBuilder.DropTable(
                name: "npc_daily_works");

            migrationBuilder.DropTable(
                name: "npc_data");

            migrationBuilder.DropTable(
                name: "npc_shop_mappings");

            migrationBuilder.DropTable(
                name: "pet_aptitude_qualities");

            migrationBuilder.DropTable(
                name: "pet_attack_methods");

            migrationBuilder.DropTable(
                name: "pet_attack_tendencies");

            migrationBuilder.DropTable(
                name: "pet_combat_skills");

            migrationBuilder.DropTable(
                name: "pet_farewell_gifts");

            migrationBuilder.DropTable(
                name: "pet_infos");

            migrationBuilder.DropTable(
                name: "pet_innate_skills");

            migrationBuilder.DropTable(
                name: "pet_levels");

            migrationBuilder.DropTable(
                name: "pet_names");

            migrationBuilder.DropTable(
                name: "pet_personalities");

            migrationBuilder.DropTable(
                name: "pet_production_skill_effects");

            migrationBuilder.DropTable(
                name: "pet_production_skills");

            migrationBuilder.DropTable(
                name: "pet_qualities");

            migrationBuilder.DropTable(
                name: "pet_skill_slot_unlocks");

            migrationBuilder.DropTable(
                name: "pet_skill_triggers");

            migrationBuilder.DropTable(
                name: "pet_skins");

            migrationBuilder.DropTable(
                name: "pet_support_skills");

            migrationBuilder.DropTable(
                name: "player_attributes");

            migrationBuilder.DropTable(
                name: "random_groups");

            migrationBuilder.DropTable(
                name: "random_pools");

            migrationBuilder.DropTable(
                name: "random_products");

            migrationBuilder.DropTable(
                name: "shop_infos");

            migrationBuilder.DropTable(
                name: "tattoo_infos");

            migrationBuilder.DropTable(
                name: "underclothes_infos");
        }
    }
}
