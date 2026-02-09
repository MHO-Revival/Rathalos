using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_names")]
    public record PetNameRecord : BaseRecord
    {
        public int PetNameId { get; set; }
        public string Name { get; set; } = string.Empty;
        public int Weight { get; set; }
    }

    [Table("pet_farewell_gifts")]
    public record PetFarewellGiftRecord : BaseRecord
    {
        public int IntimacyStarLevel { get; set; }
        public int CompensationItemId1 { get; set; }
        public int Count1 { get; set; }
        public int CompensationItemId2 { get; set; }
        public int Count2 { get; set; }
        public int CompensationItemId3 { get; set; }
        public int Count3 { get; set; }
    }

    [Table("pet_qualities")]
    public record PetQualityRecord : BaseRecord
    {
        public int QualityId { get; set; }
        public int Weight { get; set; }
    }

    [Table("pet_personalities")]
    public record PetPersonalityRecord : BaseRecord
    {
        public int PersonalityId { get; set; }
        public int Weight { get; set; }
    }

    [Table("pet_attack_tendencies")]
    public record PetAttackTendencyRecord : BaseRecord
    {
        public int TendencyId { get; set; }
        public int Weight { get; set; }
    }

    [Table("pet_attack_methods")]
    public record PetAttackMethodRecord : BaseRecord
    {
        public int MethodId { get; set; }
        public int Weight { get; set; }
    }

    [Table("pet_skins")]
    public record PetSkinRecord : BaseRecord
    {
        public int SkinId { get; set; }
        public int Weight { get; set; }
        public string? Icon { get; set; }
        public string? Description { get; set; }
    }

    [Table("pet_levels")]
    public record PetLevelRecord : BaseRecord
    {
        public int Level { get; set; }
        public int UpgradeExp { get; set; }
        public int SkillPointGrowth { get; set; }
        public int PotentialPointGrowth { get; set; }
        public int AttackGrowth { get; set; }
        public int DefenseGrowth { get; set; }
        public int HpGrowth { get; set; }
        public int ActionPowerGrowth { get; set; }
        public int ObservationGrowth { get; set; }
        public int LoadCapacityGrowth { get; set; }
    }

    [Table("pet_skill_slot_unlocks")]
    public record PetSkillSlotUnlockRecord : BaseRecord
    {
        public int SlotId { get; set; }
        public int ItemId { get; set; }
        public int ItemCount { get; set; }
    }
    [Table("pet_infos")]
    public record PetInfoRecord : BaseRecord
    {
        public int PetId { get; set; }
        public int IsRandomAttribute { get; set; }
        public string? DefaultName { get; set; }
        public int Level { get; set; }
        public int Species { get; set; }
        public int Specialization { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int Personality { get; set; }
        public int AttackTendency { get; set; }
        public int AttackMethod { get; set; }
        public int BurrowHpPercent { get; set; }
        public int HpRecoverySpeed { get; set; }
        public string? SupportSkill { get; set; }
        public string? InnateSkillGroup { get; set; }
        public string? BubbleGroup { get; set; }
        public string? EntityName { get; set; }
        public int Class { get; set; }
        public string? CustomName { get; set; }
        public string? Icon { get; set; }
        public int Skin { get; set; }
        public string? Description { get; set; }
    }

    [Table("pet_aptitude_qualities")]
    public record PetAptitudeQualityRecord : BaseRecord
    {
        public int AptitudeQualityId { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int Personality { get; set; }
        public int FixedSkillId { get; set; }
        public int InitialSkillPoints { get; set; }
        public int SkillGrowthPoints { get; set; }
        public int PotentialGrowthPoints { get; set; }
        public int MaxLevel { get; set; }
        public int EliteSkillSlots { get; set; }
        public int ActiveSkillSlots { get; set; }
        public int PassiveSkillSlots { get; set; }
        public int SupportPassiveSkillSlots { get; set; }
        public int SupportActiveSkillSlots { get; set; }
        public int InitialAttack { get; set; }
        public float AttackGrowthCoef { get; set; }
        public int InitialDefense { get; set; }
        public float DefenseGrowthCoef { get; set; }
        public int InitialHp { get; set; }
        public float HpGrowthCoef { get; set; }
        public int InitialActionPower { get; set; }
        public float ActionPowerGrowthCoef { get; set; }
        public int InitialObservation { get; set; }
        public float ObservationGrowthCoef { get; set; }
        public int InitialLoadCapacity { get; set; }
        public float LoadCapacityGrowthCoef { get; set; }
        public int NormalSkillSlotMax { get; set; }
        public int FluteSkillSlotMax { get; set; }
        public int MedalSkillSlotMax { get; set; }
        public int InnateSkillMax { get; set; }
        public int SupportSkillMax { get; set; }
        public string? NormalSkillSlotLockInfo { get; set; }
        public string? NormalSkillSlot1UnlockCondition { get; set; }
        public string? NormalSkillSlot2UnlockCondition { get; set; }
        public string? NormalSkillSlot3UnlockCondition { get; set; }
        public string? FluteSkillSlotLockInfo { get; set; }
        public string? FluteSkillSlot1UnlockCondition { get; set; }
        public string? FluteSkillSlot2UnlockCondition { get; set; }
        public float Defence { get; set; }
        public float PhyPDRatio { get; set; }
        public float MonsterAtkPet { get; set; }
        public float PlayerAtkPet { get; set; }
    }
    [Table("pet_innate_skills")]
    public record PetInnateSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int SkillGroup { get; set; }
        public string? SkillName { get; set; }
        public int Level { get; set; }
        public int IsEliteSkill { get; set; }
        public int UpgradeLevelLimit { get; set; }
        public int UpgradeItem1 { get; set; }
        public int UpgradeItem1Count { get; set; }
        public int UpgradeItem2 { get; set; }
        public int UpgradeItem2Count { get; set; }
        public int UpgradeItem3 { get; set; }
        public int UpgradeItem3Count { get; set; }
        public int UpgradedSkillId { get; set; }
    }

    [Table("pet_combat_skills")]
    public record PetCombatSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int SkillGroupId { get; set; }
        public int CdReductionSkillGroup { get; set; }
        public string? SkillGroupName { get; set; }
        public string? SkillName { get; set; }
        public int LearnJobLimit { get; set; }
        public int CanBeRandom { get; set; }
        public int CanBeUpgradeRandom { get; set; }
        public int RandomWeight { get; set; }
        public int LearnLevelLimit { get; set; }
        public int SkillLevel { get; set; }
        public int IsEliteSkill { get; set; }
        public int SkillType { get; set; }
        public int SubType { get; set; }
        public int ComprehensionCount { get; set; }
        public int SkillPointCost { get; set; }
        public int IntimacyHeartLevel { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int MutualExclusionGroup1 { get; set; }
        public int MutualExclusionGroup2 { get; set; }
        public int MutualExclusionGroup3 { get; set; }
        public int ActiveSkillId { get; set; }
        public int ActiveSkillTriggerRate { get; set; }
        public int SelfPassiveBuff { get; set; }
        public int OwnerPassiveBuff { get; set; }
        public int SelfSkillBuff { get; set; }
        public int OwnerSkillBuff { get; set; }
        public string? OwnerEffect { get; set; }
        public string? SelfEffect { get; set; }
        public string? MonsterEffect { get; set; }
        public string? SkillDescription { get; set; }
        public string? Icon { get; set; }
        public int NewType { get; set; }
        public int TalkId { get; set; }
    }

    [Table("pet_support_skills")]
    public record PetSupportSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public string? SkillName { get; set; }
        public int Level { get; set; }
        public int BuffId { get; set; }
        public int UpgradeLevelLimit { get; set; }
        public int UpgradeItem1 { get; set; }
        public int UpgradeItem1Count { get; set; }
        public int UpgradeItem2 { get; set; }
        public int UpgradeItem2Count { get; set; }
        public int UpgradeItem3 { get; set; }
        public int UpgradeItem3Count { get; set; }
        public int UpgradedSkillId { get; set; }
        public string? Description { get; set; }
        public string? Icon { get; set; }
    }

    [Table("pet_skill_triggers")]
    public record PetSkillTriggerRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int TriggerType { get; set; }
        public string? PreCastStartAnimation { get; set; }
        public string? PreCastLoopAnimation { get; set; }
        public int PreCastCount { get; set; }
        public string? CastAnimation { get; set; }
        public string? EffectModifierParam { get; set; }
        public int SkillPointCost { get; set; }
        public int Priority { get; set; }
        public int CD { get; set; }
        public int CastDelayMin { get; set; }
        public int CastDelayMax { get; set; }
        public int CastCountMax { get; set; }
        public float MinTriggerDistance { get; set; }
        public float MaxTriggerDistance { get; set; }
        public int Target { get; set; }
        public string? EmergencyCondition { get; set; }
        public string? EmergencyConditionParam1 { get; set; }
        public string? EmergencyConditionParam2 { get; set; }
        public string? EmergencyConditionAndOr { get; set; }
        public string? NormalCondition { get; set; }
        public string? NormalConditionParam1 { get; set; }
        public string? NormalConditionParam2 { get; set; }
        public string? NormalConditionAndOr { get; set; }
    }

    [Table("pet_production_skills")]
    public record PetProductionSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int CdReductionSkillGroup { get; set; }
        public int SkillGroupId { get; set; }
        public string? SkillGroupName { get; set; }
        public string? SkillName { get; set; }
        public int LearnJobLimit { get; set; }
        public int CanBeRandom { get; set; }
        public int CanBeUpgradeRandom { get; set; }
        public int RandomWeight { get; set; }
        public int LearnLevelLimit { get; set; }
        public int SkillLevel { get; set; }
        public int IsEliteSkill { get; set; }
        public int SkillType { get; set; }
        public int SubType { get; set; }
        public string? MatchResourcePoint { get; set; }
        public string? LearnCondition { get; set; }
        public int SkillPointCost { get; set; }
        public int IntimacyHeartLevel { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int ActionPower { get; set; }
        public int Observation { get; set; }
        public int LoadCapacity { get; set; }
        public int MutualExclusionGroup1 { get; set; }
        public int MutualExclusionGroup2 { get; set; }
        public int MutualExclusionGroup3 { get; set; }
    }

    [Table("pet_production_skill_effects")]
    public record PetProductionSkillEffectRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int GatherPointType { get; set; }
        public string? EffectCondition { get; set; }
        public int IntimacyIncrease { get; set; }
        public int ExpIncreasePercent { get; set; }
        public int EnergyReductionPercent { get; set; }
        public int ToolBreakReduction { get; set; }
        public int GatherCountIncrease { get; set; }
        public int ConstructionIncreasePercent { get; set; }
        public int NoConsumeChance { get; set; }
        public int RewardRandomIncrease { get; set; }
    }
}
