using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_skill_triggers")]
    public record PetSkillTriggerRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int TriggerType { get; set; }
        public string? PreCastStartAnimation { get; set; }
        public string? PreCastLoopAnimation { get; set; }
        public int PreCastCount { get; set; }
        public string? CastAnimation { get; set; }
        public string? EffectModifierParam { get; set; }
        public int SkillPointCost { get; set; }
        public int Priority { get; set; }
        public int CD { get; set; }
        public int CastDelayMin { get; set; }
        public int CastDelayMax { get; set; }
        public int CastCountMax { get; set; }
        public float MinTriggerDistance { get; set; }
        public float MaxTriggerDistance { get; set; }
        public int Target { get; set; }
        public string? EmergencyCondition { get; set; }
        public string? EmergencyConditionParam1 { get; set; }
        public string? EmergencyConditionParam2 { get; set; }
        public string? EmergencyConditionAndOr { get; set; }
        public string? NormalCondition { get; set; }
        public string? NormalConditionParam1 { get; set; }
        public string? NormalConditionParam2 { get; set; }
        public string? NormalConditionAndOr { get; set; }
    }
}
