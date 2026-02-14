using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_states")]
    public record MonsterStateRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int StateID { get; set; }
        public string? StateName { get; set; }
        public int BBInitValue { get; set; }
        public int BBMaxValue { get; set; }
        public int CurrentAccumValue { get; set; }
        public int AccumValueMin { get; set; }
        public int ReleaseAccumValue { get; set; }
        public float AccumDecayRate { get; set; }
        public float ActionSpeed { get; set; }
        public float AttackMultiplier { get; set; }
        public float DefenseMultiplier { get; set; }
    }
}
