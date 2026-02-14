using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("hr_levels")]
    public record HRLevelRecord : BaseRecord
    {
        public int HRLevel { get; set; }
        public int UnlockPoints { get; set; }
        public string? UnlockStage { get; set; }
        public string? Buffs { get; set; }
    }
}
