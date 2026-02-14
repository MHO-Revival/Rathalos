using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("item_data")]
    public record ItemDataRecord : BaseRecord
    {
        public int ItemId { get; set; }
        public string? ItemName { get; set; }
        public string? Description { get; set; }
        public int ItemLevel { get; set; }
        public int Rarity { get; set; }
        public int IconId { get; set; }
        public int KeepOnLeaveDungeon { get; set; }
        public int Rank { get; set; }
        public int MainCategory { get; set; }
        public int SubCategory { get; set; }
        public int ChildCategory { get; set; }
        public int BindType { get; set; }
        public int MaxOwned { get; set; }
        public int MaxCarried { get; set; }
        public int MaxStacked { get; set; }
        public int FarmPoints { get; set; }
        public int CanDestroy { get; set; }
        public int BuyPrice { get; set; }
        public int SellPrice { get; set; }
        public int IsMallItem { get; set; }
        public int CanDisassemble { get; set; }
        public int ExpirationTime { get; set; }
        public string? ExpirationTag { get; set; }
        public string? ModelResourceMale { get; set; }
        public string? ModelResourceFemale { get; set; }
        public int CharacterLevelRequired { get; set; }
        public int RaceRequired { get; set; }
        public int StarClassRequired { get; set; }
        public int StarLevelRequired { get; set; }
        public int RequiredSkill1Id { get; set; }
        public int RequiredSkill1LevelMin { get; set; }
        public int RequiredSkill1LevelMax { get; set; }
        public int RequiredSkill2Id { get; set; }
        public int RequiredSkill2LevelMin { get; set; }
        public int RequiredSkill2LevelMax { get; set; }
        public int GuildLevelRequired { get; set; }
        public int PetLevelRequired { get; set; }
        public int GenderRequired { get; set; }
        public int RequiredRegionId { get; set; }
        public int RequiredLevelMode { get; set; }
        public int RequiredStageId { get; set; }
        public int UseCount { get; set; }
        public int CooldownTime { get; set; }
        public int SharedCooldownGroup { get; set; }
        public int DungeonUseCount { get; set; }
        public int KeepCooldownOnLogout { get; set; }
        public int UseTarget { get; set; }
        public string? ActionSkill { get; set; }
        public string? UseFunction1Name { get; set; }
        public string? UseFunction1Param1 { get; set; }
        public string? UseFunction1Param2 { get; set; }
        public string? UseFunction1Param3 { get; set; }
        public string? UseFunction2Name { get; set; }
        public string? UseFunction2Param1 { get; set; }
        public string? UseFunction2Param2 { get; set; }
        public string? UseFunction2Param3 { get; set; }
        public string? UseFunction3Name { get; set; }
        public string? UseFunction3Param1 { get; set; }
        public string? UseFunction3Param2 { get; set; }
        public string? UseFunction3Param3 { get; set; }
        public string? UseFunction4Name { get; set; }
        public string? UseFunction4Param1 { get; set; }
        public string? UseFunction4Param2 { get; set; }
        public string? UseFunction4Param3 { get; set; }
        public int CanBeStolen { get; set; }
        public int SharedCarryLimitGroup { get; set; }
        public string? ItemDamageInfo { get; set; }
        public int SortParam { get; set; }
        public int MallIndex { get; set; }
        public int RandomHuntRewardPoints { get; set; }
        public int UnbindItemId { get; set; }
        public int UnbindItemCount { get; set; }
    }
}
