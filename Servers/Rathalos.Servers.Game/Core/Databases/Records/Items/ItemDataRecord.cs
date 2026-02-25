using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("item_data")]
    public record ItemDataRecord : BaseRecord
    {
        // --- Identity ---
        public int DataId { get; set; }
        public string Name { get; set; } = string.Empty;
        public string? Description { get; set; }
        public string? IconId { get; set; }
        public int? Rarity { get; set; }
        public int? Rank { get; set; }
        public int? ItemLevel { get; set; }
        public int? FarmPoints { get; set; }
        public long? BuyPrice { get; set; }
        public long? SellPrice { get; set; }
        public int? IsMallItem { get; set; }
        public int? IsDestroyable { get; set; }
        public int? IsDecomposable { get; set; }
        public long? ExpiryTime { get; set; }
        public string? ExpiryTag { get; set; }
        public string? ModelMale { get; set; }
        public string? ModelFemale { get; set; }
        public int? SortParam { get; set; }
        public int? MallIndexId { get; set; }
        public int? CanBeStolen { get; set; }

        // --- Classification ---
        public int MainCategory { get; set; }
        public int MiddleCategory { get; set; }
        public int? SubCategory { get; set; }

        // --- Basic Logic ---
        public int BindType { get; set; }
        public int? KeepAfterDungeon { get; set; }
        public int? OwnLimit { get; set; }
        public int? StackLimit { get; set; }
        public int? CarryLimit { get; set; }
        public int? UnbindItemId { get; set; }
        public int? UnbindItemCount { get; set; }

        // --- Requirements ---
        public int? ReqLevel { get; set; }
        public int GenderReq { get; set; }
        public int? ReqRace { get; set; }
        public int? ReqStarClass { get; set; }
        public int? ReqStarLevel { get; set; }
        public int? ReqSkill1Id { get; set; }
        public int? ReqSkill1Min { get; set; }
        public int? ReqSkill1Max { get; set; }
        public int? ReqSkill2Id { get; set; }
        public int? ReqSkill2Min { get; set; }
        public int? ReqSkill2Max { get; set; }
        public int? ReqGuildLevel { get; set; }
        public int? ReqPetLevel { get; set; }

        // --- Extended Requirements ---
        public string? ReqAreaId { get; set; }
        public string? ReqLevelMode { get; set; }
        public string? ReqStageId { get; set; }

        // --- Usage Logic ---
        public int? UseCount { get; set; }
        public int? Cooldown { get; set; }
        public int? CooldownGroup { get; set; }
        public int? CooldownPersist { get; set; }
        public int? UseTarget { get; set; }
        public string? ActionSkill { get; set; }
        public string? DamageInfo { get; set; }
        public int? DungeonUseLimit { get; set; }
        public int? SharedCarryLimitGroupId { get; set; }
        public int? RandomHuntPoints { get; set; }

        // --- Material Classification (1-10) ---
        public int? MatCat1 { get; set; }
        public int? MatVal1 { get; set; }
        public int? MatCat2 { get; set; }
        public int? MatVal2 { get; set; }
        public int? MatCat3 { get; set; }
        public int? MatVal3 { get; set; }
        public int? MatCat4 { get; set; }
        public int? MatVal4 { get; set; }
        public int? MatCat5 { get; set; }
        public int? MatVal5 { get; set; }
        public int? MatCat6 { get; set; }
        public int? MatVal6 { get; set; }
        public int? MatCat7 { get; set; }
        public int? MatVal7 { get; set; }
        public int? MatCat8 { get; set; }
        public int? MatVal8 { get; set; }
        public int? MatCat9 { get; set; }
        public int? MatVal9 { get; set; }
        public int? MatCat10 { get; set; }
        public int? MatVal10 { get; set; }

        // --- Item Functions (1-4) ---
        public string? Func1Name { get; set; }
        public string? Func1Param1 { get; set; }
        public string? Func1Param2 { get; set; }
        public string? Func1Param3 { get; set; }
        public string? Func2Name { get; set; }
        public string? Func2Param1 { get; set; }
        public string? Func2Param2 { get; set; }
        public string? Func2Param3 { get; set; }
        public string? Func3Name { get; set; }
        public string? Func3Param1 { get; set; }
        public string? Func3Param2 { get; set; }
        public string? Func3Param3 { get; set; }
        public string? Func4Name { get; set; }
        public string? Func4Param1 { get; set; }
        public string? Func4Param2 { get; set; }
        public string? Func4Param3 { get; set; }
    }
}
