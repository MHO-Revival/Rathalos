using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_production_skills")]
    public record PetProductionSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int CdReductionSkillGroup { get; set; }
        public int SkillGroupId { get; set; }
        public string? SkillGroupName { get; set; }
        public string? SkillName { get; set; }
        public int LearnJobLimit { get; set; }
        public int CanBeRandom { get; set; }
        public int CanBeUpgradeRandom { get; set; }
        public int RandomWeight { get; set; }
        public int LearnLevelLimit { get; set; }
        public int SkillLevel { get; set; }
        public int IsEliteSkill { get; set; }
        public int SkillType { get; set; }
        public int SubType { get; set; }
        public string? MatchResourcePoint { get; set; }
        public string? LearnCondition { get; set; }
        public int SkillPointCost { get; set; }
        public int IntimacyHeartLevel { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int ActionPower { get; set; }
        public int Observation { get; set; }
        public int LoadCapacity { get; set; }
        public int MutualExclusionGroup1 { get; set; }
        public int MutualExclusionGroup2 { get; set; }
        public int MutualExclusionGroup3 { get; set; }
    }
}
