using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NpcSale
{
    public class RandomGroup
    {
        [TsvColumn("标识")]
        public int Id { get; set; }

        [TsvColumn("随机次数")]
        public int RandomCount { get; set; }

        [TsvColumn("单价加成重置周期")]
        public int PriceResetPeriod { get; set; }

        [TsvColumn("单价加成重置时间")]
        public string? PriceResetTime { get; set; }

        [TsvColumn("单价加成数量1")]
        public int PriceBonus1 { get; set; }

        [TsvColumn("单价加成数量2")]
        public int PriceBonus2 { get; set; }

        [TsvColumn("单价加成数量3")]
        public int PriceBonus3 { get; set; }

        [TsvColumn("单价加成数量4")]
        public int PriceBonus4 { get; set; }

        [TsvColumn("单价加成数量5")]
        public int PriceBonus5 { get; set; }
    }
}
