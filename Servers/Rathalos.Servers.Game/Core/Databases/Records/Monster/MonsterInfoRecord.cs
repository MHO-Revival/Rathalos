using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
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
}
