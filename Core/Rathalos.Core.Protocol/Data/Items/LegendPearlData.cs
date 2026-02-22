using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Items
{
    public class LegendPearlData : SkillPearlData
    {
        // --- Leveling & Growth ---
        [TsvColumn("初始等级")] public int StartLevel { get; set; }
        [TsvColumn("最大等级")] public int MaxLevel { get; set; }

        // --- Strategy IDs (Linked to separate logic sheets) ---
        [TsvColumn("升级消耗策略")] public int UpgradeStrategyId { get; set; }
        [TsvColumn("随机属性策略")] public int RandomAttrStrategyId { get; set; }

        // --- Point Increase Steps (Required levels to gain +1 point) ---
        [TsvColumn("加1需要提升等级1")] public int GrowthStep1 { get; set; }
        [TsvColumn("加1需要提升等级2")] public int GrowthStep2 { get; set; }
        [TsvColumn("加1需要提升等级3")] public int GrowthStep3 { get; set; }
        [TsvColumn("加1需要提升等级4")] public int GrowthStep4 { get; set; }
    }
}
