using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_part_defences")]
    public record MonsterPartDefenceRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int PartID { get; set; }
        public int StateID { get; set; }
        public int BreakLevel { get; set; }
        public int DefenceLevel { get; set; }
        public int Faint { get; set; }
        public int Cut { get; set; }
        public int Hammer { get; set; }
        public int Shoot { get; set; }
        public int Fire { get; set; }
        public int Water { get; set; }
        public int Electric { get; set; }
        public int Ice { get; set; }
        public int Dragon { get; set; }
    }
}
