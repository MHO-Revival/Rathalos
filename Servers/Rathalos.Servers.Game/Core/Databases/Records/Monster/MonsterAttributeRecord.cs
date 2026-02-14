using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_attributes")]
    public record MonsterAttributeRecord : BaseRecord
    {
        public int AttributeId { get; set; }
        public string ChineseName { get; set; } = string.Empty;
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public int Bonus { get; set; }
        public int Sync { get; set; }
        public string? Lower { get; set; }
        public string? Upper { get; set; }
        public string? Wrapper { get; set; }
    }
}
