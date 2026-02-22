using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Items
{
    public class ItemData : ItemBaseData
    {
        // --- Classification ---
        [TsvColumn("物品子类")] public ItemSubCategory? SubCategory { get; set; }

        // --- [EXTENDED REQUIREMENTS] ---
        [TsvColumn("需求地区ID")] public string? ReqAreaId { get; set; }
        [TsvColumn("需求LevelMode")] public string? ReqLevelMode { get; set; }
        [TsvColumn("需求关卡ID")] public string? ReqStageId { get; set; }

        // --- [USAGE LOGIC] ---
        [TsvColumn("物品使用次数")] public int? UseCount { get; set; }
        [TsvColumn("CD时间")] public int? Cooldown { get; set; }
        [TsvColumn("共享CD组")] public int? CooldownGroup { get; set; }
        [TsvColumn("CD下线是否保留")] public int? CooldownPersist { get; set; }
        [TsvColumn("使用目标")] public int? UseTarget { get; set; }
        [TsvColumn("动作技能")] public string? ActionSkill { get; set; }
        [TsvColumn("物品伤害信息")] public string? DamageInfo { get; set; }
        [TsvColumn("副本中使用次数")] public int? DungeonUseLimit { get; set; }
        [TsvColumn("共享携带上限组ID")] public int? SharedCarryLimitGroupId { get; set; }
        [TsvColumn("随机狩猎奖励点")] public int? RandomHuntPoints { get; set; }

        // --- [MATERIAL CLASSIFICATION (1-10)] ---
        [TsvColumn("素材分类_1")] public int? MatCat1 { get; set; }
        [TsvColumn("素材价值_1")] public int? MatVal1 { get; set; }
        [TsvColumn("素材分类_2")] public int? MatCat2 { get; set; }
        [TsvColumn("素材价值_2")] public int? MatVal2 { get; set; }
        [TsvColumn("素材分类_3")] public int? MatCat3 { get; set; }
        [TsvColumn("素材价值_3")] public int? MatVal3 { get; set; }
        [TsvColumn("素材分类_4")] public int? MatCat4 { get; set; }
        [TsvColumn("素材价值_4")] public int? MatVal4 { get; set; }
        [TsvColumn("素材分类_5")] public int? MatCat5 { get; set; }
        [TsvColumn("素材价值_5")] public int? MatVal5 { get; set; }
        [TsvColumn("素材分类_6")] public int? MatCat6 { get; set; }
        [TsvColumn("素材价值_6")] public int? MatVal6 { get; set; }
        [TsvColumn("素材价值_7")] public int? MatVal7 { get; set; }
        [TsvColumn("素材分类_7")] public int? MatCat7 { get; set; }
        [TsvColumn("素材价值_8")] public int? MatVal8 { get; set; }
        [TsvColumn("素材分类_8")] public int? MatCat8 { get; set; }
        [TsvColumn("素材价值_9")] public int? MatVal9 { get; set; }
        [TsvColumn("素材分类_9")] public int? MatCat9 { get; set; }
        [TsvColumn("素材分类_10")] public int? MatCat10 { get; set; }
        [TsvColumn("素材价值_10")] public int? MatVal10 { get; set; }

        // --- [ITEM FUNCTIONS (1-4)] ---
        [TsvColumn("物品使用功能1名称")] public string? Func1Name { get; set; }
        [TsvColumn("物品使用功能1参数1")] public string? Func1Param1 { get; set; }
        [TsvColumn("物品使用功能1参数2")] public string? Func1Param2 { get; set; }
        [TsvColumn("物品使用功能1参数3")] public string? Func1Param3 { get; set; }

        [TsvColumn("物品使用功能2名称")] public string? Func2Name { get; set; }
        [TsvColumn("物品使用功能2参数1")] public string? Func2Param1 { get; set; }
        [TsvColumn("物品使用功能2参数2")] public string? Func2Param2 { get; set; }
        [TsvColumn("物品使用功能2参数3")] public string? Func2Param3 { get; set; }

        [TsvColumn("物品使用功能3名称")] public string? Func3Name { get; set; }
        [TsvColumn("物品使用功能3参数1")] public string? Func3Param1 { get; set; }
        [TsvColumn("物品使用功能3参数2")] public string? Func3Param2 { get; set; }
        [TsvColumn("物品使用功能3参数3")] public string? Func3Param3 { get; set; }

        [TsvColumn("物品使用功能4名称")] public string? Func4Name { get; set; }
        [TsvColumn("物品使用功能4参数1")] public string? Func4Param1 { get; set; }
        [TsvColumn("物品使用功能4参数2")] public string? Func4Param2 { get; set; }
        [TsvColumn("物品使用功能4参数3")] public string? Func4Param3 { get; set; }
    }
}
