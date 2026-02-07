using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.AvatarAttrInfo
{
    public class UnderclothesInfo
    {
        [TsvColumn("编号")]
        public int Id { get; set; }

        [TsvColumn("男性内衣腕部")]
        public int MaleWrist { get; set; }

        [TsvColumn("男性内衣胸部")]
        public int MaleChest { get; set; }

        [TsvColumn("男性内衣腿部")]
        public int MaleLegs { get; set; }

        [TsvColumn("女性内衣腕部")]
        public int FemaleWrist { get; set; }

        [TsvColumn("女性内衣胸部")]
        public int FemaleChest { get; set; }

        [TsvColumn("女性内衣腿部")]
        public int FemaleLegs { get; set; }
    }
}
