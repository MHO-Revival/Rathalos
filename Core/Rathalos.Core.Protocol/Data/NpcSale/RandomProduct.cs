using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NpcSale
{
    public class RandomProduct
    {
        [TsvColumn("标识")]
        public int Id { get; set; }

        [TsvColumn("商品RowID")]
        public int ProductRowId { get; set; }

        [TsvColumn("分组")]
        public int Group { get; set; }

        [TsvColumn("商品ID")]
        public int ProductId { get; set; }

        [TsvColumn("商品数量")]
        public int ProductCount { get; set; }

        [TsvColumn("权重")]
        public int Weight { get; set; }
    }
}
