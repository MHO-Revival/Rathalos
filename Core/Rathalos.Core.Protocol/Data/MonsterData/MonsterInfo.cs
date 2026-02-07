using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.MonsterData
{
    public class MonsterInfo
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

        [TsvColumn("美术索引ID")]
        public int ArtIndexId { get; set; }

        public int LootSize { get; set; }

        public float Size { get; set; }

        public int CaptureHPPercent { get; set; }

        public int ExistTime { get; set; }

        [TsvColumn("BB:InitState")]
        public int BBInitState { get; set; }

        [TsvColumn("BB:MaxHealth")]
        public int BBMaxHealth { get; set; }

        [TsvColumn("图标")]
        public string? IconCN { get; set; }

        [TsvColumn("可否剥取")]
        public int CanLoot { get; set; }

        [TsvColumn("可否捕获")]
        public int CanCapture { get; set; }

        [TsvColumn("暴击率")]
        public int CritRate { get; set; }

        [TsvColumn("爆击修正")]
        public int CritDamageModifier { get; set; }

        [TsvColumn("水属性修正值")]
        public int WaterModifier { get; set; }

        [TsvColumn("火属性修正值")]
        public int FireModifier { get; set; }

        [TsvColumn("雷属性修正值")]
        public int ThunderModifier { get; set; }

        [TsvColumn("龙属性修正值")]
        public int DragonModifier { get; set; }

        [TsvColumn("冰属性修正值")]
        public int IceModifier { get; set; }

        [TsvColumn("斩击修正值")]
        public int SlashModifier { get; set; }

        [TsvColumn("打击修正值")]
        public int ImpactModifier { get; set; }

        [TsvColumn("弹系修正值")]
        public int ShotModifier { get; set; }

        [TsvColumn("水属性蓄积值")]
        public int WaterAccum { get; set; }

        [TsvColumn("火属性蓄积值")]
        public int FireAccum { get; set; }

        [TsvColumn("雷属性蓄积值")]
        public int ThunderAccum { get; set; }

        [TsvColumn("龙属性蓄积值")]
        public int DragonAccum { get; set; }

        [TsvColumn("冰属性蓄积值")]
        public int IceAccum { get; set; }

        [TsvColumn("无属性蓄积值")]
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

        public string? xx { get; set; }

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
