using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    /// <summary>
    /// Shop Information
    /// </summary>
    [Table("shop_infos")]
    public record ShopInfoRecord : BaseRecord
    {
        public int RowId { get; set; }
        public int ShopId { get; set; }
        public int ShopType { get; set; }
        public string? ShopName { get; set; }
        public int RowIndex { get; set; }
        public int SaleItemId { get; set; }
        public int DefaultBuyCount { get; set; }
        public int UnitPrice { get; set; }
        public int IsTotalPrice { get; set; }
        public string? SaleItemName { get; set; }
        public int SaleBindType { get; set; }
        public int HunterGuildUnlockIndex { get; set; }
        public int RandomType { get; set; }
        public int BuyPeriodLimit { get; set; }
        public int PeriodMaxBuyCount { get; set; }
        public int PriorityBindGold { get; set; }
        public string? CurrencyDisplay { get; set; }
        public int NpcGroup { get; set; }
        public int FriendlyLevelRequired { get; set; }
        public float Discount { get; set; }
        public int StarLevelLimit { get; set; }
        public int HuntSoulStoneLimit { get; set; }
        public string? SaleStartTime { get; set; }
        public string? SaleEndTime { get; set; }
        public int SpecialPoint1Type { get; set; }
        public int SpecialPoint1Count { get; set; }
        public float SpecialPoint1Discount { get; set; }
        public int SpecialPoint2Type { get; set; }
        public int SpecialPoint2Count { get; set; }
        public int ExchangeItemId01 { get; set; }
        public string? ExchangeItemName01 { get; set; }
        public int ExchangeCount01 { get; set; }
        public int ExchangeItemId02 { get; set; }
        public string? ExchangeItemName02 { get; set; }
        public int ExchangeCount02 { get; set; }
        public int ExchangeItemId03 { get; set; }
        public string? ExchangeItemName03 { get; set; }
        public int ExchangeCount03 { get; set; }
        public int ExchangeItemId04 { get; set; }
        public string? ExchangeItemName04 { get; set; }
        public int ExchangeCount04 { get; set; }
        public int ExchangeItemId05 { get; set; }
        public string? ExchangeItemName05 { get; set; }
        public int ExchangeCount05 { get; set; }
        public int IsValid { get; set; }
        public int Group { get; set; }
        public string? Bonus1 { get; set; }
        public string? Bonus2 { get; set; }
        public string? Bonus3 { get; set; }
        public string? Bonus4 { get; set; }
        public string? Bonus5 { get; set; }
        public string? EquipPreview { get; set; }
        public int IsUnifiedShop { get; set; }
        public int LevelLimit { get; set; }
        public int SystemUnlock { get; set; }
        public string? FeatureTags { get; set; }
        public int ItemCategory1 { get; set; }
        public int ItemCategory2 { get; set; }
        public int ItemCategory3 { get; set; }
    }
    /// <summary>
    /// Random Group
    /// </summary>
    [Table("random_groups")]
    public record RandomGroupRecord : BaseRecord
    {
        public int GroupId { get; set; }
        public int RandomCount { get; set; }
        public int PriceResetPeriod { get; set; }
        public string? PriceResetTime { get; set; }
        public int PriceBonus1 { get; set; }
        public int PriceBonus2 { get; set; }
        public int PriceBonus3 { get; set; }
        public int PriceBonus4 { get; set; }
        public int PriceBonus5 { get; set; }
    }
    /// <summary>
    /// Random Pool
    /// </summary>
    [Table("random_pools")]
    public record RandomPoolRecord : BaseRecord
    {
        public int PoolId { get; set; }
        public int RandomType { get; set; }
        public int RefreshPeriod { get; set; }
        public string? RefreshTime { get; set; }
        public string? Groups { get; set; }
        public int BuyTimeInterval { get; set; }
        public int Points { get; set; }
        public int BindPoints { get; set; }
        public int UnlockCard { get; set; }
        public int RefreshCount1 { get; set; }
        public int RefreshPrice1 { get; set; }
        public int RefreshCount2 { get; set; }
        public int RefreshPrice2 { get; set; }
        public int RefreshCount3 { get; set; }
        public int RefreshPrice3 { get; set; }
        public int RefreshCount4 { get; set; }
        public int RefreshPrice4 { get; set; }
        public int RefreshCount5 { get; set; }
        public int RefreshPrice5 { get; set; }
    }
    /// <summary>
    /// Random Product
    /// </summary>
    [Table("random_products")]
    public record RandomProductRecord : BaseRecord
    {
        public int ProductRecordId { get; set; }
        public int ProductRowId { get; set; }
        public int Group { get; set; }
        public int ProductId { get; set; }
        public int ProductCount { get; set; }
        public int Weight { get; set; }
    }
}
