using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("npc_daily_works")]
    public record NpcDailyWorkRecord : BaseRecord
    {
        public int WorkId { get; set; }
        public int NpcId { get; set; }
        public string StartTime { get; set; } = string.Empty;
        public string? Intrestring1 { get; set; }
        public string? Intrestring2 { get; set; }
        public string? Intrestring3 { get; set; }
        public string? Intrestring4 { get; set; }
        public string? Intrestring5 { get; set; }
    }
}
