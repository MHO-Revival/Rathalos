using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_production_skill_effects")]
    public record PetProductionSkillEffectRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int GatherPointType { get; set; }
        public string? EffectCondition { get; set; }
        public int IntimacyIncrease { get; set; }
        public int ExpIncreasePercent { get; set; }
        public int EnergyReductionPercent { get; set; }
        public int ToolBreakReduction { get; set; }
        public int GatherCountIncrease { get; set; }
        public int ConstructionIncreasePercent { get; set; }
        public int NoConsumeChance { get; set; }
        public int RewardRandomIncrease { get; set; }
    }
}
