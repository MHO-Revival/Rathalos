using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_levels")]
    public record PetLevelRecord : BaseRecord
    {
        public int Level { get; set; }
        public int UpgradeExp { get; set; }
        public int SkillPointGrowth { get; set; }
        public int PotentialPointGrowth { get; set; }
        public int AttackGrowth { get; set; }
        public int DefenseGrowth { get; set; }
        public int HpGrowth { get; set; }
        public int ActionPowerGrowth { get; set; }
        public int ObservationGrowth { get; set; }
        public int LoadCapacityGrowth { get; set; }
    }
}
