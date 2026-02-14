using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_emotions")]
    public record MonsterEmotionRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int StateFrom { get; set; }
        public int StateTo { get; set; }
        public string? Condition { get; set; }
        public string? AndOr { get; set; }
        public string? Param1 { get; set; }
        public string? Param2 { get; set; }
        public string? Param3 { get; set; }
    }
}
