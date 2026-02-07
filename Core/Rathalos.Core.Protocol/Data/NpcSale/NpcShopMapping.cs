using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NpcSale
{
    public class NpcShopMapping
    {
        [TsvColumn("标识ID")]
        public int Id { get; set; }

        public int NPCID { get; set; }

        [TsvColumn("NPC名字")]
        public string? NpcName { get; set; }

        [TsvColumn("商店01ID")]
        public int? Shop01Id { get; set; }

        [TsvColumn("商店01名称")]
        public string? Shop01Name { get; set; }

        [TsvColumn("商店02ID")]
        public int? Shop02Id { get; set; }

        [TsvColumn("商店02名称")]
        public string? Shop02Name { get; set; }

        [TsvColumn("商店03ID")]
        public int? Shop03Id { get; set; }

        [TsvColumn("商店03名称")]
        public string? Shop03Name { get; set; }

        [TsvColumn("商店04ID")]
        public int? Shop04Id { get; set; }

        [TsvColumn("商店04名称")]
        public string? Shop04Name { get; set; }

        [TsvColumn("商店05ID")]
        public int? Shop05Id { get; set; }

        [TsvColumn("商店05名称")]
        public string? Shop05Name { get; set; }

        [TsvColumn("商店06ID")]
        public int? Shop06Id { get; set; }

        [TsvColumn("商店06名称")]
        public string? Shop06Name { get; set; }
    }
}
