using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NpcSale
{
    public class ShopInfo
    {
        [TsvColumn("rowid")]
        public int RowId { get; set; }

        [TsvColumn("商店ID")]
        public int ShopId { get; set; }

        [TsvColumn("商店类型")]
        public int ShopType { get; set; }

        [TsvColumn("商店名字")]
        public string? ShopName { get; set; }

        [TsvColumn("行数标识")]
        public int RowIndex { get; set; }

        [TsvColumn("贩卖物品ID")]
        public int SaleItemId { get; set; }

        [TsvColumn("默认购买数量")]
        public int DefaultBuyCount { get; set; }

        [TsvColumn("购买单价")]
        public int UnitPrice { get; set; }

        [TsvColumn("是否总价")]
        public int IsTotalPrice { get; set; }

        [TsvColumn("贩卖物品名称")]
        public string? SaleItemName { get; set; }

        [TsvColumn("售卖绑定类型")]
        public int SaleBindType { get; set; }

        [TsvColumn("猎人工会解锁索引")]
        public int HunterGuildUnlockIndex { get; set; }

        [TsvColumn("随机方式")]
        public int RandomType { get; set; }

        [TsvColumn("购买周期限制")]
        public int BuyPeriodLimit { get; set; }

        [TsvColumn("周期最大购买数量")]
        public int PeriodMaxBuyCount { get; set; }

        [TsvColumn("是否优先使用绑金")]
        public int PriorityBindGold { get; set; }

        [TsvColumn("货币显示")]
        public string? CurrencyDisplay { get; set; }

        [TsvColumn("NPC组")]
        public int NpcGroup { get; set; }

        [TsvColumn("友好度需求等级")]
        public int FriendlyLevelRequired { get; set; }

        [TsvColumn("打折")]
        public float Discount { get; set; }

        [TsvColumn("星级限制")]
        public int StarLevelLimit { get; set; }

        [TsvColumn("狩魂石阶数限制")]
        public int HuntSoulStoneLimit { get; set; }

        [TsvColumn("售卖开始时间")]
        public string? SaleStartTime { get; set; }

        [TsvColumn("售卖结束时间")]
        public string? SaleEndTime { get; set; }

        [TsvColumn("特殊点数1类型")]
        public int SpecialPoint1Type { get; set; }

        [TsvColumn("特殊点数1数量")]
        public int SpecialPoint1Count { get; set; }

        [TsvColumn("特殊点数1折扣")]
        public float SpecialPoint1Discount { get; set; }

        [TsvColumn("特殊点数2类型")]
        public int SpecialPoint2Type { get; set; }

        [TsvColumn("特殊点数2数量")]
        public int SpecialPoint2Count { get; set; }

        [TsvColumn("交换物品ID01")]
        public int ExchangeItemId01 { get; set; }

        [TsvColumn("交换物品名称01")]
        public string? ExchangeItemName01 { get; set; }

        [TsvColumn("数量01")]
        public int ExchangeCount01 { get; set; }

        [TsvColumn("交换物品ID02")]
        public int ExchangeItemId02 { get; set; }

        [TsvColumn("交换物品名称02")]
        public string? ExchangeItemName02 { get; set; }

        [TsvColumn("数量02")]
        public int ExchangeCount02 { get; set; }

        [TsvColumn("交换物品ID03")]
        public int ExchangeItemId03 { get; set; }

        [TsvColumn("交换物品名称03")]
        public string? ExchangeItemName03 { get; set; }

        [TsvColumn("数量03")]
        public int ExchangeCount03 { get; set; }

        [TsvColumn("交换物品ID04")]
        public int ExchangeItemId04 { get; set; }

        [TsvColumn("交换物品名称04")]
        public string? ExchangeItemName04 { get; set; }

        [TsvColumn("数量04")]
        public int ExchangeCount04 { get; set; }

        [TsvColumn("交换物品ID05")]
        public int ExchangeItemId05 { get; set; }

        [TsvColumn("交换物品名称05")]
        public string? ExchangeItemName05 { get; set; }

        [TsvColumn("数量05")]
        public int ExchangeCount05 { get; set; }

        [TsvColumn("是否有效")]
        public int IsValid { get; set; }

        [TsvColumn("分组")]
        public int Group { get; set; }

        [TsvColumn("加成1")]
        public string? Bonus1 { get; set; }

        [TsvColumn("加成2")]
        public string? Bonus2 { get; set; }

        [TsvColumn("加成3")]
        public string? Bonus3 { get; set; }

        [TsvColumn("加成4")]
        public string? Bonus4 { get; set; }

        [TsvColumn("加成5")]
        public string? Bonus5 { get; set; }

        [TsvColumn("装备预览")]
        public string? EquipPreview { get; set; }

        [TsvColumn("是否统一商店")]
        public int IsUnifiedShop { get; set; }

        [TsvColumn("等级限制")]
        public int LevelLimit { get; set; }

        [TsvColumn("系统解锁")]
        public int SystemUnlock { get; set; }

        public string? FeatureTags { get; set; }

        [TsvColumn("物品分类1")]
        public int ItemCategory1 { get; set; }

        [TsvColumn("物品分类2")]
        public int ItemCategory2 { get; set; }

        [TsvColumn("物品分类3")]
        public int ItemCategory3 { get; set; }
    }
}
