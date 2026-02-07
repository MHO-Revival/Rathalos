using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSkillTrigger
    {
        [TsvColumn("技能ID")]
        public int SkillId { get; set; }

        [TsvColumn("技能发动类型")]
        public int TriggerType { get; set; }

        [TsvColumn("技能前摇起始动画")]
        public string? PreCastStartAnimation { get; set; }

        [TsvColumn("技能前摇循环动画")]
        public string? PreCastLoopAnimation { get; set; }

        [TsvColumn("技能前摇次数")]
        public int PreCastCount { get; set; }

        [TsvColumn("技能发动动画")]
        public string? CastAnimation { get; set; }

        [TsvColumn("技能效果修饰参数")]
        public string? EffectModifierParam { get; set; }

        [TsvColumn("消耗技能点数")]
        public int SkillPointCost { get; set; }

        [TsvColumn("优先级")]
        public int Priority { get; set; }

        public int CD { get; set; }

        [TsvColumn("释放延迟下限")]
        public int CastDelayMin { get; set; }

        [TsvColumn("释放延迟上限")]
        public int CastDelayMax { get; set; }

        [TsvColumn("释放次数上限")]
        public int CastCountMax { get; set; }

        [TsvColumn("最小发动距离")]
        public float MinTriggerDistance { get; set; }

        [TsvColumn("最大发动距离")]
        public float MaxTriggerDistance { get; set; }

        [TsvColumn("目标")]
        public int Target { get; set; }

        [TsvColumn("紧急条件")]
        public string? EmergencyCondition { get; set; }

        [TsvColumn("紧急条件参数1")]
        public string? EmergencyConditionParam1 { get; set; }

        [TsvColumn("紧急条件参数2")]
        public string? EmergencyConditionParam2 { get; set; }

        [TsvColumn("紧急条件与或关系")]
        public string? EmergencyConditionAndOr { get; set; }

        [TsvColumn("普通条件")]
        public string? NormalCondition { get; set; }

        [TsvColumn("普通条件参数1")]
        public string? NormalConditionParam1 { get; set; }

        [TsvColumn("普通条件参数2")]
        public string? NormalConditionParam2 { get; set; }

        [TsvColumn("普通条件与或关系")]
        public string? NormalConditionAndOr { get; set; }
    }
}
