using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NpcSale
{
    public class RandomPool
    {
        [TsvColumn("标识")]
        public int Id { get; set; }

        [TsvColumn("随机方式")]
        public int RandomType { get; set; }

        public int RefreshPeriod { get; set; }

        public string? RefreshTime { get; set; }

        public string? Groups { get; set; }

        [TsvColumn("购买时间间隔")]
        public int BuyTimeInterval { get; set; }

        [TsvColumn("点券")]
        public int Points { get; set; }

        [TsvColumn("绑定点券")]
        public int BindPoints { get; set; }

        [TsvColumn("解锁卡片")]
        public int UnlockCard { get; set; }

        [TsvColumn("刷新次数1")]
        public int RefreshCount1 { get; set; }

        [TsvColumn("刷新加价1")]
        public int RefreshPrice1 { get; set; }

        [TsvColumn("刷新次数2")]
        public int RefreshCount2 { get; set; }

        [TsvColumn("刷新加价2")]
        public int RefreshPrice2 { get; set; }

        [TsvColumn("刷新次数3")]
        public int RefreshCount3 { get; set; }

        [TsvColumn("刷新加价3")]
        public int RefreshPrice3 { get; set; }

        [TsvColumn("刷新次数4")]
        public int RefreshCount4 { get; set; }

        [TsvColumn("刷新加价4")]
        public int RefreshPrice4 { get; set; }

        [TsvColumn("刷新次数5")]
        public int RefreshCount5 { get; set; }

        [TsvColumn("刷新加价5")]
        public int RefreshPrice5 { get; set; }
    }
}
