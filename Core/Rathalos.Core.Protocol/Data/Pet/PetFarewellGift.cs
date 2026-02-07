using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetFarewellGift
    {
        [TsvColumn("亲密度星级")]
        public int IntimacyStarLevel { get; set; }

        [TsvColumn("补偿物品ID1")]
        public int CompensationItemId1 { get; set; }

        [TsvColumn("数量1")]
        public int Count1 { get; set; }

        [TsvColumn("补偿物品ID2")]
        public int CompensationItemId2 { get; set; }

        [TsvColumn("数量2")]
        public int Count2 { get; set; }

        [TsvColumn("补偿物品ID3")]
        public int CompensationItemId3 { get; set; }

        [TsvColumn("数量3")]
        public int Count3 { get; set; }
    }
}
