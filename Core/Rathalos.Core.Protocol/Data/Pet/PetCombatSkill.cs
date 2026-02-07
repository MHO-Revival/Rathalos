using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetCombatSkill
    {
        [TsvColumn("技能ID")]
        public int SkillId { get; set; }

        [TsvColumn("技能组ID")]
        public int SkillGroupId { get; set; }

        [TsvColumn("减CD用技能组")]
        public int CdReductionSkillGroup { get; set; }

        [TsvColumn("技能组名称")]
        public string? SkillGroupName { get; set; }

        [TsvColumn("技能名称")]
        public string? SkillName { get; set; }

        [TsvColumn("学习职业限制")]
        public int LearnJobLimit { get; set; }

        [TsvColumn("是否可被随机")]
        public int CanBeRandom { get; set; }

        [TsvColumn("是否可被升级随机")]
        public int CanBeUpgradeRandom { get; set; }

        [TsvColumn("随机权重")]
        public int RandomWeight { get; set; }

        [TsvColumn("学习等级限制")]
        public int LearnLevelLimit { get; set; }

        [TsvColumn("技能等级")]
        public int SkillLevel { get; set; }

        [TsvColumn("是否精英技能")]
        public int IsEliteSkill { get; set; }

        [TsvColumn("技能类型")]
        public int SkillType { get; set; }

        [TsvColumn("子类型")]
        public int SubType { get; set; }

        [TsvColumn("领悟次数")]
        public int ComprehensionCount { get; set; }

        [TsvColumn("消耗技能点数")]
        public int SkillPointCost { get; set; }

        [TsvColumn("亲密度心级")]
        public int IntimacyHeartLevel { get; set; }

        [TsvColumn("资质")]
        public int Aptitude { get; set; }

        [TsvColumn("品质")]
        public int Quality { get; set; }

        [TsvColumn("互斥技能组ID1")]
        public int MutualExclusionGroup1 { get; set; }

        [TsvColumn("互斥技能组ID2")]
        public int MutualExclusionGroup2 { get; set; }

        [TsvColumn("互斥技能组ID3")]
        public int MutualExclusionGroup3 { get; set; }

        [TsvColumn("对应的主动技能")]
        public int ActiveSkillId { get; set; }

        [TsvColumn("主动技能发动几率")]
        public int ActiveSkillTriggerRate { get; set; }

        [TsvColumn("对自己的被动buff")]
        public int SelfPassiveBuff { get; set; }

        [TsvColumn("对主人的被动buff")]
        public int OwnerPassiveBuff { get; set; }

        [TsvColumn("对自己的技能buff")]
        public int SelfSkillBuff { get; set; }

        [TsvColumn("对主人的技能buff")]
        public int OwnerSkillBuff { get; set; }

        [TsvColumn("对主人的效果")]
        public string? OwnerEffect { get; set; }

        [TsvColumn("对自己的效果")]
        public string? SelfEffect { get; set; }

        [TsvColumn("对怪物的效果")]
        public string? MonsterEffect { get; set; }

        [TsvColumn("技能效果说明")]
        public string? SkillDescription { get; set; }

        public string? Icon { get; set; }

        [TsvColumn("新类型")]
        public int NewType { get; set; }

        [TsvColumn("说话ID")]
        public int TalkId { get; set; }
    }
}
