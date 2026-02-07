using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.ItemData
{
    public class ItemDataInfo
    {
        [TsvColumn("总表ID")]
        public int Id { get; set; }

        [TsvColumn("物品名称")]
        public string Name { get; set; } = string.Empty;

        [TsvColumn("说明")]
        public string? Description { get; set; }

        [TsvColumn("物品等级")]
        public int ItemLevel { get; set; }

        [TsvColumn("稀有度")]
        public int Rarity { get; set; }

        [TsvColumn("图标ID")]
        public string? IconId { get; set; }

        [TsvColumn("离开副本是否保留")]
        public int KeepOnLeave { get; set; }

        public int RANK { get; set; }

        [TsvColumn("物品主类")]
        public int MainCategory { get; set; }

        [TsvColumn("物品中类")]
        public int SubCategory { get; set; }

        [TsvColumn("物品子类")]
        public int ChildCategory { get; set; }

        [TsvColumn("绑定类型")]
        public int BindType { get; set; }

        [TsvColumn("拥有上限")]
        public int OwnLimit { get; set; }

        [TsvColumn("携带上限")]
        public int CarryLimit { get; set; }

        [TsvColumn("堆叠上限")]
        public int StackLimit { get; set; }

        [TsvColumn("农场精算点数")]
        public int FarmPoints { get; set; }

        [TsvColumn("可否摧毁")]
        public int CanDestroy { get; set; }

        [TsvColumn("购买价格")]
        public int BuyPrice { get; set; }

        [TsvColumn("出售价格")]
        public int SellPrice { get; set; }

        [TsvColumn("是否商城道具")]
        public int IsMallItem { get; set; }

        [TsvColumn("可否分解")]
        public int CanDisassemble { get; set; }

        [TsvColumn("物品过期时间")]
        public int ExpirationTime { get; set; }

        [TsvColumn("物品过期Tag")]
        public string? ExpirationTag { get; set; }

        [TsvColumn("模型资源(男)")]
        public string? MaleModel { get; set; }

        [TsvColumn("模型资源(女)")]
        public string? FemaleModel { get; set; }

        [TsvColumn("角色等级需求")]
        public int RequiredLevel { get; set; }

        [TsvColumn("种族需求")]
        public int RequiredRace { get; set; }

        [TsvColumn("星级职业需求")]
        public int RequiredStarClass { get; set; }

        [TsvColumn("星级等级需求")]
        public int RequiredStarLevel { get; set; }

        [TsvColumn("需求技能1ID")]
        public int RequiredSkill1Id { get; set; }

        [TsvColumn("需求技能1等级MIN")]
        public int RequiredSkill1LevelMin { get; set; }

        [TsvColumn("需求技能1等级MAX")]
        public int RequiredSkill1LevelMax { get; set; }

        [TsvColumn("需求技能2ID")]
        public int RequiredSkill2Id { get; set; }

        [TsvColumn("需求技能2等级MIN")]
        public int RequiredSkill2LevelMin { get; set; }

        [TsvColumn("需求技能2等级MAX")]
        public int RequiredSkill2LevelMax { get; set; }

        [TsvColumn("猎团等级需求")]
        public int RequiredGuildLevel { get; set; }

        [TsvColumn("宠物等级需求")]
        public int RequiredPetLevel { get; set; }

        [TsvColumn("性别需求")]
        public int RequiredGender { get; set; }

        [TsvColumn("需求地区ID")]
        public int RequiredRegionId { get; set; }

        [TsvColumn("需求LevelMode")]
        public int RequiredLevelMode { get; set; }

        [TsvColumn("需求关卡ID")]
        public int RequiredStageId { get; set; }

        [TsvColumn("物品使用次数")]
        public int UseCount { get; set; }

        [TsvColumn("CD时间")]
        public int CooldownTime { get; set; }

        [TsvColumn("共享CD组")]
        public int SharedCooldownGroup { get; set; }

        [TsvColumn("CD下线是否保留")]
        public int KeepCooldownOnLogout { get; set; }

        [TsvColumn("使用目标")]
        public int UseTarget { get; set; }

        [TsvColumn("动作技能")]
        public string? ActionSkill { get; set; }

        [TsvColumn("物品使用功能1名称")]
        public string? UseFunction1Name { get; set; }

        [TsvColumn("物品使用功能1参数1")]
        public string? UseFunction1Param1 { get; set; }

        [TsvColumn("物品使用功能1参数2")]
        public string? UseFunction1Param2 { get; set; }

        [TsvColumn("物品使用功能1参数3")]
        public string? UseFunction1Param3 { get; set; }

        [TsvColumn("物品使用功能2名称")]
        public string? UseFunction2Name { get; set; }

        [TsvColumn("物品使用功能2参数1")]
        public string? UseFunction2Param1 { get; set; }

        [TsvColumn("物品使用功能2参数2")]
        public string? UseFunction2Param2 { get; set; }

        [TsvColumn("物品使用功能2参数3")]
        public string? UseFunction2Param3 { get; set; }

        [TsvColumn("物品使用功能3名称")]
        public string? UseFunction3Name { get; set; }

        [TsvColumn("物品使用功能3参数1")]
        public string? UseFunction3Param1 { get; set; }

        [TsvColumn("物品使用功能3参数2")]
        public string? UseFunction3Param2 { get; set; }

        [TsvColumn("物品使用功能3参数3")]
        public string? UseFunction3Param3 { get; set; }

        [TsvColumn("物品使用功能4名称")]
        public string? UseFunction4Name { get; set; }

        [TsvColumn("物品使用功能4参数1")]
        public string? UseFunction4Param1 { get; set; }

        [TsvColumn("物品使用功能4参数2")]
        public string? UseFunction4Param2 { get; set; }

        [TsvColumn("物品使用功能4参数3")]
        public string? UseFunction4Param3 { get; set; }

        [TsvColumn("可否被偷窃")]
        public int CanBeStolen { get; set; }

        [TsvColumn("共享携带上限组ID")]
        public int SharedCarryLimitGroup { get; set; }

        [TsvColumn("物品伤害信息")]
        public string? DamageInfo { get; set; }

        [TsvColumn("排序参数")]
        public int SortParam { get; set; }

        [TsvColumn("商城索引ID")]
        public string? MallIndexId { get; set; }

        [TsvColumn("副本中使用次数")]
        public int? InstanceUseCount { get; set; }

        [TsvColumn("随机狩猎奖励点")]
        public int? RandomHuntRewardPoints { get; set; }

        [TsvColumn("解绑道具")]
        public int? UnbindItem { get; set; }

        [TsvColumn("解绑道具数量")]
        public int? UnbindItemCount { get; set; }
    }
}
