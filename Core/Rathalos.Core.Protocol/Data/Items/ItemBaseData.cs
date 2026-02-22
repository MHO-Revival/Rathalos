using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Items
{
    public abstract class ItemBaseData
    {
        // --- Identity ---
        [TsvColumn("总表ID")] public int Id { get; set; }
        [TsvColumn("物品名称")] public string Name { get; set; } = string.Empty;
        [TsvColumn("说明")] public string? Description { get; set; }
        [TsvColumn("图标ID")] public string? IconId { get; set; }
        [TsvColumn("稀有度")] public int? Rarity { get; set; }
        [TsvColumn("RANK")] public int? Rank { get; set; }
        [TsvColumn("物品等级")] public int? ItemLevel { get; set; }
        [TsvColumn("农场精算点数")] public int? FarmPoints { get; set; }
        [TsvColumn("购买价格")] public long? BuyPrice { get; set; }
        [TsvColumn("出售价格")] public long? SellPrice { get; set; }
        [TsvColumn("是否商城道具")] public int? IsMallItem { get; set; }
        [TsvColumn("可否摧毁")] public int? IsDestroyable { get; set; }
        [TsvColumn("可否分解")] public int? IsDecomposable { get; set; }
        [TsvColumn("物品过期时间")] public long? ExpiryTime { get; set; }
        [TsvColumn("物品过期Tag")] public string? ExpiryTag { get; set; }
        [TsvColumn("模型资源(男)")] public string? ModelMale { get; set; }
        [TsvColumn("模型资源(女)")] public string? ModelFemale { get; set; }
        [TsvColumn("排序参数")] public int? SortParam { get; set; }
        [TsvColumn("商城索引ID")] public int? MallIndexId { get; set; }
        [TsvColumn("可否被偷窃")] public int? CanBeStolen { get; set; }


        // --- Classification ---
        [TsvColumn("物品主类")] public ItemMainCategory MainCategory { get; set; }
        [TsvColumn("物品中类")] public ItemMiddleCategory MiddleCategory { get; set; }

        // --- Basic Logic ---
        [TsvColumn("绑定类型")] public BindType BindType { get; set; }
        [TsvColumn("离开副本是否保留")] public int? KeepAfterDungeon { get; set; }
        [TsvColumn("拥有上限")] public int? OwnLimit { get; set; }
        [TsvColumn("堆叠上限")] public int? StackLimit { get; set; }
        [TsvColumn("携带上限")] public int? CarryLimit { get; set; }
        [TsvColumn("解绑道具")] public int? UnbindItemId { get; set; }
        [TsvColumn("解绑道具数量")] public int? UnbindItemCount { get; set; }

        // --- [REQUIREMENTS] ---
        [TsvColumn("角色等级需求")] public int? ReqLevel { get; set; }
        [TsvColumn("性别需求")] public GenderRequirement GenderReq { get; set; }
        [TsvColumn("种族需求")] public int? ReqRace { get; set; }
        [TsvColumn("星级职业需求")] public int? ReqStarClass { get; set; }
        [TsvColumn("星级等级需求")] public int? ReqStarLevel { get; set; }
        [TsvColumn("需求技能1ID")] public int? ReqSkill1Id { get; set; }
        [TsvColumn("需求技能1等级MIN")] public int? ReqSkill1Min { get; set; }
        [TsvColumn("需求技能1等级MAX")] public int? ReqSkill1Max { get; set; }
        [TsvColumn("需求技能2ID")] public int? ReqSkill2Id { get; set; }
        [TsvColumn("需求技能2等级MIN")] public int? ReqSkill2Min { get; set; }
        [TsvColumn("需求技能2等级MAX")] public int? ReqSkill2Max { get; set; }
        [TsvColumn("猎团等级需求")] public int? ReqGuildLevel { get; set; }
        [TsvColumn("宠物等级需求")] public int? ReqPetLevel { get; set; }
    }
}
