using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_lemons")]
    public record MonsterLemonRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string? LemonSkill { get; set; }
        public int? Tag { get; set; }
    }
}
