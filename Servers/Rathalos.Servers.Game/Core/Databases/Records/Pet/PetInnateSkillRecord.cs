using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_innate_skills")]
    public record PetInnateSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int SkillGroup { get; set; }
        public string? SkillName { get; set; }
        public int Level { get; set; }
        public int IsEliteSkill { get; set; }
        public int UpgradeLevelLimit { get; set; }
        public int UpgradeItem1 { get; set; }
        public int UpgradeItem1Count { get; set; }
        public int UpgradeItem2 { get; set; }
        public int UpgradeItem2Count { get; set; }
        public int UpgradeItem3 { get; set; }
        public int UpgradeItem3Count { get; set; }
        public int UpgradedSkillId { get; set; }
    }
}
