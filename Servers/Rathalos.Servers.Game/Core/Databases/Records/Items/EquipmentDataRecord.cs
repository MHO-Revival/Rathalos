using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("equipment_data")]
    public record EquipmentDataRecord : BaseRecord
    {
        // --- Identity ---
        public int DataId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; }
        public string? IconId { get; set; }
        public int? Rarity { get; set; }
        public int? Rank { get; set; }
        public int? ItemLevel { get; set; }
        public int? FarmPoints { get; set; }
        public long? BuyPrice { get; set; }
        public long? SellPrice { get; set; }
        public int? IsMallItem { get; set; }
        public int? IsDestroyable { get; set; }
        public int? IsDecomposable { get; set; }
        public long? ExpiryTime { get; set; }
        public string? ExpiryTag { get; set; }
        public string? ModelMale { get; set; }
        public string? ModelFemale { get; set; }
        public int? SortParam { get; set; }
        public int? MallIndexId { get; set; }
        public int? CanBeStolen { get; set; }

        // --- Classification ---
        public int MainCategory { get; set; }
        public int MiddleCategory { get; set; }
        public int? SubCategory { get; set; }

        // --- Basic Logic ---
        public int BindType { get; set; }
        public int? KeepAfterDungeon { get; set; }
        public int? OwnLimit { get; set; }
        public int? StackLimit { get; set; }
        public int? CarryLimit { get; set; }
        public int? UnbindItemId { get; set; }
        public int? UnbindItemCount { get; set; }

        // --- Requirements ---
        public int? ReqLevel { get; set; }
        public int GenderReq { get; set; }
        public int? ReqRace { get; set; }
        public int? ReqStarClass { get; set; }
        public int? ReqStarLevel { get; set; }
        public int? ReqSkill1Id { get; set; }
        public int? ReqSkill1Min { get; set; }
        public int? ReqSkill1Max { get; set; }
        public int? ReqSkill2Id { get; set; }
        public int? ReqSkill2Min { get; set; }
        public int? ReqSkill2Max { get; set; }
        public int? ReqGuildLevel { get; set; }
        public int? ReqPetLevel { get; set; }

        // --- Core Identity ---
        public int? Material { get; set; }
        public string? Remarks { get; set; }
        public int? WeaponType { get; set; }
        public int? IsDefaultWeapon { get; set; }

        // --- Upgrades & Fortification ---
        public int? CanUpgradeRank { get; set; }
        public int? RankUpgradeRule { get; set; }
        public int? CanUpgradeLevel { get; set; }
        public int? LevelUpgradeRule { get; set; }
        public int? CanUpgrade { get; set; }
        public int? CanFortify { get; set; }
        public int? MaxFortifyLevel { get; set; }
        public int? MaxBreakthroughLevel { get; set; }
        public int? BreakthroughReqFortify { get; set; }
        public int? FortifyRule { get; set; }
        public string? FortifyEffect1 { get; set; }
        public string? FortifyEffect2 { get; set; }
        public string? FortifyEffect3 { get; set; }
        public string? BreakthroughEffect1 { get; set; }
        public string? BreakthroughEffect2 { get; set; }
        public string? BreakthroughEffect3 { get; set; }
        public int? AwakenIndex { get; set; }
        public int? AwakenLv1 { get; set; }
        public int? AwakenLv2 { get; set; }
        public int? AwakenLv3 { get; set; }
        public string? DirectUpgradeRule { get; set; }

        // --- Combat Stats ---
        public int? RangeType { get; set; }
        public int? WeaponLength { get; set; }
        public int? InitialSlots { get; set; }
        public int? MaxSlots { get; set; }
        public int? Attack { get; set; }
        public int? Defense { get; set; }
        public int? Affinity { get; set; }
        public int? Durability { get; set; }
        public int? BonusHp { get; set; }

        // --- Sharpness ---
        public int? MaxSharpness { get; set; }
        public int? SharpRed { get; set; }
        public int? SharpOrange { get; set; }
        public int? SharpYellow { get; set; }
        public int? SharpGreen { get; set; }
        public int? SharpBlue { get; set; }
        public int? SharpWhite { get; set; }
        public int? SharpPurple { get; set; }
        public int? SharpBronze { get; set; }
        public int? SharpSilver { get; set; }
        public int? SharpGold { get; set; }

        // --- Elements & Resistances ---
        public int? AtkWater { get; set; }
        public int? AtkFire { get; set; }
        public int? AtkThunder { get; set; }
        public int? AtkDragon { get; set; }
        public int? AtkIce { get; set; }
        public int? AtkPoison { get; set; }
        public int? AtkSleep { get; set; }
        public int? AtkPara { get; set; }
        public int? AtkBlast { get; set; }
        public int? ResWater { get; set; }
        public int? ResFire { get; set; }
        public int? ResThunder { get; set; }
        public int? ResDragon { get; set; }
        public int? ResIce { get; set; }

        // --- Attributes & Passives ---
        public int? Strength { get; set; }
        public int? Burst { get; set; }
        public int? Luck { get; set; }
        public int? Constitution { get; set; }
        public int? Gene1 { get; set; }
        public int? Gene2 { get; set; }
        public int? Gene3 { get; set; }
        public int? Gene4 { get; set; }
        public int? Gene5 { get; set; }
        public int? Gene6 { get; set; }
        public int? Skill1Id { get; set; }
        public float? Skill1Val { get; set; }
        public int? Skill2Id { get; set; }
        public float? Skill2Val { get; set; }
        public int? Skill3Id { get; set; }
        public float? Skill3Val { get; set; }
        public int? Skill4Id { get; set; }
        public float? Skill4Val { get; set; }
        public int? Skill5Id { get; set; }
        public float? Skill5Val { get; set; }
        public int? Skill6Id { get; set; }
        public float? Skill6Val { get; set; }
        public int? RandomSkillGroup { get; set; }

        // --- Melee Gauges ---
        public int? SpiritGaugeMax { get; set; }
        public float? DecayRate { get; set; }
        public int? SpiritLv1Time { get; set; }
        public int? SpiritLv2Time { get; set; }
        public int? SpiritLv3Time { get; set; }
        public int? FullSpiritTime { get; set; }
        public int? PowerGauge1 { get; set; }
        public int? PowerGauge2 { get; set; }
        public int? ExtraPowerValue { get; set; }
        public int? HyperGaugeMax { get; set; }
        public float? HyperRatio { get; set; }
        public int? ExtraAdd { get; set; }

        // --- Bow Mechanics ---
        public string? ChargeLv1 { get; set; }
        public string? ChargeLv2 { get; set; }
        public string? ChargeLv3 { get; set; }
        public string? ChargeLv4 { get; set; }
        public int? AccumulateCount { get; set; }
        public int? FillSpeed { get; set; }
        public int? BowFillValue { get; set; }
        public string? Quiver { get; set; }
        public int? CarryQuantity { get; set; }
        public int? StringToughness { get; set; }
        public int? ArcShot1 { get; set; }
        public int? ArcShot2 { get; set; }
        public int? ArcShot3 { get; set; }
        public int? ArcShot4 { get; set; }
        public int? Bottle1Type { get; set; }
        public int? Bottle1Count { get; set; }
        public int? Bottle2Type { get; set; }
        public int? Bottle2Count { get; set; }
        public int? Bottle3Type { get; set; }
        public int? Bottle3Count { get; set; }
        public int? Bottle4Type { get; set; }
        public int? Bottle4Count { get; set; }
        public int? Bottle5Type { get; set; }
        public int? Bottle5Count { get; set; }
        public int? SpecArrow1Type { get; set; }
        public int? SpecArrow1Count { get; set; }
        public int? SpecArrow2Type { get; set; }
        public int? SpecArrow2Count { get; set; }
        public int? SpecArrow3Type { get; set; }
        public int? SpecArrow3Count { get; set; }

        // --- Bowgun Mechanics ---
        public string? ReloadSpeed { get; set; }
        public string? Deviation { get; set; }
        public string? Recoil { get; set; }
        public string? FireRate { get; set; }
        public int? Mod1 { get; set; }
        public int? Mod2 { get; set; }
        public int? Mod3 { get; set; }
        public string? Mod3Param { get; set; }
        public int? Mod4 { get; set; }

        // --- Ammo Slots (1-15) ---
        public int? Ammo1 { get; set; }
        public int? Ammo1Count { get; set; }
        public int? Ammo1FireType { get; set; }
        public int? Ammo1Recoil { get; set; }
        public int? Ammo2 { get; set; }
        public int? Ammo2Count { get; set; }
        public int? Ammo2FireType { get; set; }
        public int? Ammo2Recoil { get; set; }
        public int? Ammo3 { get; set; }
        public int? Ammo3Count { get; set; }
        public int? Ammo3FireType { get; set; }
        public int? Ammo3Recoil { get; set; }
        public int? Ammo4 { get; set; }
        public int? Ammo4Count { get; set; }
        public int? Ammo4FireType { get; set; }
        public int? Ammo4Recoil { get; set; }
        public int? Ammo5 { get; set; }
        public int? Ammo5Count { get; set; }
        public int? Ammo5FireType { get; set; }
        public int? Ammo5Recoil { get; set; }
        public int? Ammo6 { get; set; }
        public int? Ammo6Count { get; set; }
        public int? Ammo6FireType { get; set; }
        public int? Ammo6Recoil { get; set; }
        public int? Ammo7 { get; set; }
        public int? Ammo7Count { get; set; }
        public int? Ammo7FireType { get; set; }
        public int? Ammo7Recoil { get; set; }
        public int? Ammo8 { get; set; }
        public int? Ammo8Count { get; set; }
        public int? Ammo8FireType { get; set; }
        public int? Ammo8Recoil { get; set; }
        public int? Ammo9 { get; set; }
        public int? Ammo9Count { get; set; }
        public int? Ammo9FireType { get; set; }
        public int? Ammo9Recoil { get; set; }
        public int? Ammo10 { get; set; }
        public int? Ammo10Count { get; set; }
        public int? Ammo10FireType { get; set; }
        public int? Ammo10Recoil { get; set; }
        public int? Ammo11 { get; set; }
        public int? Ammo11Count { get; set; }
        public int? Ammo11FireType { get; set; }
        public int? Ammo11Recoil { get; set; }
        public int? Ammo12 { get; set; }
        public int? Ammo12Count { get; set; }
        public int? Ammo12FireType { get; set; }
        public int? Ammo12Recoil { get; set; }
        public int? Ammo13 { get; set; }
        public int? Ammo13Count { get; set; }
        public int? Ammo13FireType { get; set; }
        public int? Ammo13Recoil { get; set; }
        public int? Ammo14 { get; set; }
        public int? Ammo14Count { get; set; }
        public int? Ammo14FireType { get; set; }
        public int? Ammo14Recoil { get; set; }
        public int? Ammo15 { get; set; }
        public int? Ammo15Count { get; set; }
        public int? Ammo15FireType { get; set; }
        public int? Ammo15Recoil { get; set; }

        // --- Horn & Gunlance ---
        public int? MusicNote1 { get; set; }
        public int? MusicNote2 { get; set; }
        public int? MusicNote3 { get; set; }
        public int? Melody1 { get; set; }
        public int? Melody2 { get; set; }
        public int? Melody3 { get; set; }
        public int? Melody4 { get; set; }
        public int? Melody5 { get; set; }
        public int? Melody6 { get; set; }
        public int? Melody7 { get; set; }
        public int? Melody8 { get; set; }
        public int? Melody9 { get; set; }
        public int? Melody10 { get; set; }
        public int? ShellingType { get; set; }
        public int? ShellingLevel { get; set; }
        public int? MaxShells { get; set; }

        // --- Cosmetic & System ---
        public int? DyeRule { get; set; }
        public int? IsReleased { get; set; }
        public int? HighHeels { get; set; }
        public int? SetId { get; set; }
        public int? IsTransmogged { get; set; }
        public int? CanTransmog { get; set; }
        public string? TransmogCost { get; set; }
        public int? RefineRule { get; set; }
        public int? RefineMaxLevel { get; set; }
        public int? AllowAnneal { get; set; }
        public int? UpgradeCostRule { get; set; }
        public int? LevelCapIncrease { get; set; }
        public int? AdhesiveId { get; set; }
        public int? AdhesiveCount { get; set; }
        public int? IsBrokenWeapon { get; set; }
        public int? TalismanRule { get; set; }

        // --- Growth Stats ---
        public float? G_Attack { get; set; }
        public float? G_Defense { get; set; }
        public float? G_Hp { get; set; }
        public float? G_WaterAtk { get; set; }
        public float? G_FireAtk { get; set; }
        public float? G_ThunderAtk { get; set; }
        public float? G_DragonAtk { get; set; }
        public float? G_IceAtk { get; set; }
        public float? G_WaterRes { get; set; }
        public float? G_FireRes { get; set; }
        public float? G_ThunderRes { get; set; }
        public float? G_DragonRes { get; set; }
        public float? G_IceRes { get; set; }
        public float? G_Strength { get; set; }
        public float? G_Burst { get; set; }
        public float? G_Luck { get; set; }
        public float? G_Constitution { get; set; }
        public float? G_Poison { get; set; }
        public float? G_Sleep { get; set; }
        public float? G_Para { get; set; }
        public float? G_Blast { get; set; }
    }
}
