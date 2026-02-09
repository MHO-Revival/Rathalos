using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_abnormal_states")]
    public record MonsterAbnormalStateRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string Name { get; set; } = string.Empty;
        public int PoisonTol { get; set; }
        public int Poison { get; set; }
        public int PoisonAdd { get; set; }
        public int PoisonMax { get; set; }
        public int PoisonWeaken { get; set; }
        public int PoisonBuff { get; set; }
        public int PoisonDmg { get; set; }
        public int PoisonCount { get; set; }
        public int PoisonWeakenScale { get; set; }
        public int ParalysisTol { get; set; }
        public int Paralysis { get; set; }
        public int ParalysisAdd { get; set; }
        public int ParalysisMax { get; set; }
        public int ParalysisWeaken { get; set; }
        public int ParalysisBuff { get; set; }
        public int ParalysisCount { get; set; }
        public int ParalysisWeakenScale { get; set; }
        public int SleepTol { get; set; }
        public int Sleep { get; set; }
        public int SleepAdd { get; set; }
        public int SleepMax { get; set; }
        public int SleepWeaken { get; set; }
        public int SleepBuff { get; set; }
        public int SleepCount { get; set; }
        public int SleepWeakenScale { get; set; }
        public int DynamiteTol { get; set; }
        public int Dynamite { get; set; }
        public int DynamiteAdd { get; set; }
        public int DynamiteMax { get; set; }
        public int DynamiteWeaken { get; set; }
        public int DynamiteBuff { get; set; }
        public int DynamiteDmg { get; set; }
        public int DynamiteCount { get; set; }
        public int DynamiteWeakenScale { get; set; }
        public int StunTol { get; set; }
        public int Stun { get; set; }
        public int StunAdd { get; set; }
        public int StunMax { get; set; }
        public int StunWeaken { get; set; }
        public int StunBuff { get; set; }
        public int StunCount { get; set; }
        public int StunWeakenScale { get; set; }
        public int? TrapTol { get; set; }
        public int? TrapTimeLower { get; set; }
        public int TrapCount { get; set; }
        public int? ParaTrapTol { get; set; }
        public int? ParaTrapTimeLower { get; set; }
        public int ParaTrapCount { get; set; }
        public int? AdvTrapTol { get; set; }
        public int? AdvTrapTimeLower { get; set; }
        public int AdvTrapCount { get; set; }
        public int? FlareTol { get; set; }
        public int? FlareTimeLower { get; set; }
        public int FlareCount { get; set; }
        public int TrapWeakenScale { get; set; }
        public int? ParaTrapWeakenScale { get; set; }
        public int? AdvTrapWeakenScale { get; set; }
        public int FlareWeakenScale { get; set; }
        public int? SonicTol { get; set; }
        public int? SonicWeakenScale { get; set; }
        public int? SonicTimeLower { get; set; }
        public int? FalldownTol { get; set; }
        public int? FalldownWeakenScale { get; set; }
        public int? FalldownTimeLower { get; set; }
        public int AnesthesiaCount { get; set; }
        public int Anesthesia { get; set; }
        public int AnesthesiaWeakenScale { get; set; }
    }

    [Table("monster_emotions")]
    public record MonsterEmotionRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int StateFrom { get; set; }
        public int StateTo { get; set; }
        public string? Condition { get; set; }
        public string? AndOr { get; set; }
        public string? Param1 { get; set; }
        public string? Param2 { get; set; }
        public string? Param3 { get; set; }
    }

    [Table("monster_lemons")]
    public record MonsterLemonRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string? LemonSkill { get; set; }
        public int? Tag { get; set; }
    }

    [Table("monster_states")]
    public record MonsterStateRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int StateID { get; set; }
        public string? StateName { get; set; }
        public int BBInitValue { get; set; }
        public int BBMaxValue { get; set; }
        public int CurrentAccumValue { get; set; }
        public int AccumValueMin { get; set; }
        public int ReleaseAccumValue { get; set; }
        public float AccumDecayRate { get; set; }
        public float ActionSpeed { get; set; }
        public float AttackMultiplier { get; set; }
        public float DefenseMultiplier { get; set; }
    }


    [Table("monster_attributes")]
    public record MonsterAttributeRecord : BaseRecord
    {
        public int AttributeId { get; set; }
        public string ChineseName { get; set; } = string.Empty;
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public int Bonus { get; set; }
        public int Sync { get; set; }
        public string? Lower { get; set; }
        public string? Upper { get; set; }
        public string? Wrapper { get; set; }
    }

    [Table("monster_infos")]
    public record MonsterInfoRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string? Icon { get; set; }
        public string? Name { get; set; }
        public int? InheritFrom { get; set; }
        public int MonsterType { get; set; }
        public string? SpawnAppear { get; set; }
        public int MonsterGroup { get; set; }
        public string? EntityName { get; set; }
        public string? EntityClass { get; set; }
        public string? EntityCustomType { get; set; }
        public int Race { get; set; }
        public int CameraDelayTime { get; set; }
        public string? DeathCamera { get; set; }
        public string? DeathCameraPoint { get; set; }
        public string? InteractCamera { get; set; }
        public string? InteractCameraPoint { get; set; }
        public string? CatchCamera { get; set; }
        public string? CatchCameraPoint { get; set; }
        public int ChangeAreaType { get; set; }
        public int Difficulty { get; set; }
        public int ArtIndexId { get; set; }
        public int LootSize { get; set; }
        public float Size { get; set; }
        public int CaptureHPPercent { get; set; }
        public int ExistTime { get; set; }
        public int BBInitState { get; set; }
        public int BBMaxHealth { get; set; }
        public string? IconCN { get; set; }
        public int CanLoot { get; set; }
        public int CanCapture { get; set; }
        public int CritRate { get; set; }
        public int CritDamageModifier { get; set; }
        public int WaterModifier { get; set; }
        public int FireModifier { get; set; }
        public int ThunderModifier { get; set; }
        public int DragonModifier { get; set; }
        public int IceModifier { get; set; }
        public int SlashModifier { get; set; }
        public int ImpactModifier { get; set; }
        public int ShotModifier { get; set; }
        public int WaterAccum { get; set; }
        public int FireAccum { get; set; }
        public int ThunderAccum { get; set; }
        public int DragonAccum { get; set; }
        public int IceAccum { get; set; }
        public int NoneAccum { get; set; }
        public float BodySize { get; set; }
        public string? IdleSequenceName { get; set; }
        public string? InterestPointType { get; set; }
        public int MaxPower { get; set; }
        public int PowerRecoverySpeed { get; set; }
        public int EmotionAngryTime { get; set; }
        public string? AngryDamagePeakRange { get; set; }
        public string? AngryDamagePeakValue { get; set; }
        public float EmotionAngryAnimSpeed { get; set; }
        public float SkillSpeed { get; set; }
        public int RegionMaxTime { get; set; }
        public int RegionMinTime { get; set; }
        public float DistBodySize { get; set; }
        public string? PreLoadBTOnServer { get; set; }
        public string? LootBone { get; set; }
        public string? LootOffset { get; set; }
        public string? LootRotation { get; set; }
        public int EnableLemonSystem { get; set; }
        public int MinTag { get; set; }
        public int MaxTag { get; set; }
        public int EnterLemonMinHP { get; set; }
        public int EnterLemonMaxHP { get; set; }
        public int LemonTime { get; set; }
        public int LeaveLemonMinHP { get; set; }
        public int LeaveLemonMaxHP { get; set; }
        public int NeedShowEvEDmg { get; set; }
        public int NeedHidePVEDmg { get; set; }
        public int UseCombatNPCAtkModify { get; set; }
    }

    [Table("monster_parts")]
    public record MonsterPartRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int PartID { get; set; }
        public string? PartName { get; set; }
        public int StateID { get; set; }
        public int Unbalance { get; set; }
        public float UnbalanceMulti { get; set; }
        public int Scar { get; set; }
        public int Fall { get; set; }
        public float FallMulti { get; set; }
        public int WaterAcc { get; set; }
        public float WaterAccMulti { get; set; }
        public int FireAcc { get; set; }
        public float FireAccMulti { get; set; }
        public int ElectricAcc { get; set; }
        public float ElectricAccMulti { get; set; }
        public int DragonAcc { get; set; }
        public float DragonAccMulti { get; set; }
        public int IceAcc { get; set; }
        public float IceAccMulti { get; set; }
        public int NoneAcc { get; set; }
        public float NoneAccMulti { get; set; }
        public int DmgVal1 { get; set; }
        public int ProcessLv1 { get; set; }
        public int Hammer1 { get; set; }
        public int Cut1 { get; set; }
        public int Shoot1 { get; set; }
        public int Water1 { get; set; }
        public int Fire1 { get; set; }
        public int Electric1 { get; set; }
        public int Dragon1 { get; set; }
        public int Ice1 { get; set; }
        public int LootSkillLv1 { get; set; }
        public int DmgVal2 { get; set; }
        public int ProcessLv2 { get; set; }
        public int Hammer2 { get; set; }
        public int Cut2 { get; set; }
        public int Shoot2 { get; set; }
        public int Water2 { get; set; }
        public int Fire2 { get; set; }
        public int Electric2 { get; set; }
        public int Dragon2 { get; set; }
        public int Ice2 { get; set; }
        public int LootSkillLv2 { get; set; }
        public int DmgVal3 { get; set; }
        public int ProcessLv3 { get; set; }
        public int Hammer3 { get; set; }
        public int Cut3 { get; set; }
        public int Shoot3 { get; set; }
        public int Water3 { get; set; }
        public int Fire3 { get; set; }
        public int Electric3 { get; set; }
        public int Dragon3 { get; set; }
        public int Ice3 { get; set; }
        public int LootSkillLv3 { get; set; }
        public int DmgVal4 { get; set; }
        public int ProcessLv4 { get; set; }
        public int Hammer4 { get; set; }
        public int Cut4 { get; set; }
        public int Shoot4 { get; set; }
        public int Water4 { get; set; }
        public int Fire4 { get; set; }
        public int Electric4 { get; set; }
        public int Dragon4 { get; set; }
        public int Ice4 { get; set; }
        public int LootSkillLv4 { get; set; }
        public int DmgVal5 { get; set; }
        public int ProcessLv5 { get; set; }
        public int Hammer5 { get; set; }
        public int Cut5 { get; set; }
        public int Shoot5 { get; set; }
        public int Water5 { get; set; }
        public int Fire5 { get; set; }
        public int Electric5 { get; set; }
        public int Dragon5 { get; set; }
        public int Ice5 { get; set; }
        public int LootSkillLv5 { get; set; }
    }

    [Table("monster_part_defences")]
    public record MonsterPartDefenceRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int PartID { get; set; }
        public int StateID { get; set; }
        public int BreakLevel { get; set; }
        public int DefenceLevel { get; set; }
        public int Faint { get; set; }
        public int Cut { get; set; }
        public int Hammer { get; set; }
        public int Shoot { get; set; }
        public int Fire { get; set; }
        public int Water { get; set; }
        public int Electric { get; set; }
        public int Ice { get; set; }
        public int Dragon { get; set; }
    }

    [Table("monster_perceptions")]
    public record MonsterPerceptionRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string? EyeBoneLeft { get; set; }
        public string? EyeBoneRight { get; set; }
        public string? EyeBoneCenter { get; set; }
        public float VisionConeHeight { get; set; }
        public float VisionConeAngle { get; set; }
        public float VisionConeAngleAlert { get; set; }
        public string? HearingBone { get; set; }
        public float HearingDistance { get; set; }
        public float HearingDistanceExNear { get; set; }
        public float HearingDistanceNear { get; set; }
        public float HearingDistanceMedium { get; set; }
        public float HearingDistanceFar { get; set; }
        public float HearingThredAlert { get; set; }
        public float HearingThredPreComb { get; set; }
    }
}
