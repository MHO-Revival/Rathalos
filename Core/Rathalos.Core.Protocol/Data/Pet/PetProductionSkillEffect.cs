using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetProductionSkillEffect
    {
        [TsvColumn("技能ID")]
        public int SkillId { get; set; }

        [TsvColumn("采集点类型")]
        public int GatherPointType { get; set; }

        [TsvColumn("效果生效条件")]
        public string? EffectCondition { get; set; }

        [TsvColumn("亲密度增加值")]
        public int IntimacyIncrease { get; set; }

        [TsvColumn("经验增加百分比")]
        public int ExpIncreasePercent { get; set; }

        [TsvColumn("精力消耗减少百分比")]
        public int EnergyReductionPercent { get; set; }

        [TsvColumn("工具损坏几率减少值")]
        public int ToolBreakReduction { get; set; }

        [TsvColumn("采集点采集次数增加值")]
        public int GatherCountIncrease { get; set; }

        [TsvColumn("采集点建设度增加百分比")]
        public int ConstructionIncreasePercent { get; set; }

        [TsvColumn("采集次数不消耗几率")]
        public int NoConsumeChance { get; set; }

        [TsvColumn("奖励随机次数增加值")]
        public int RewardRandomIncrease { get; set; }
    }
}
