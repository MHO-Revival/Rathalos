using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_support_skills")]
    public record PetSupportSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public string? SkillName { get; set; }
        public int Level { get; set; }
        public int BuffId { get; set; }
        public int UpgradeLevelLimit { get; set; }
        public int UpgradeItem1 { get; set; }
        public int UpgradeItem1Count { get; set; }
        public int UpgradeItem2 { get; set; }
        public int UpgradeItem2Count { get; set; }
        public int UpgradeItem3 { get; set; }
        public int UpgradeItem3Count { get; set; }
        public int UpgradedSkillId { get; set; }
        public string? Description { get; set; }
        public string? Icon { get; set; }
    }
}
