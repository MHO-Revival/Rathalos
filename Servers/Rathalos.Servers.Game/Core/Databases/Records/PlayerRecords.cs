using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("player_attributes")]
    public record PlayerAttributeRecord : BaseRecord
    {
        public int AttributeId { get; set; }
        public string ChineseName { get; set; } = string.Empty;
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public int Version { get; set; }
        public int Self { get; set; }
        public int Appear { get; set; }
        public int Query { get; set; }
        public int Bonus { get; set; }
        public int SaveDB { get; set; }
        public int Sync { get; set; }
        public string? InitVal { get; set; }
        public string? PvPInitVal { get; set; }
        public int Event { get; set; }
        public string? ResetVal { get; set; }
        public int Reset1 { get; set; }
        public int Reset2 { get; set; }
        public int Reset3 { get; set; }
        public int Reset4 { get; set; }
        public string? Lower { get; set; }
        public string? Upper { get; set; }
        public int InUse { get; set; }
        public string? Note { get; set; }
        public string? Other { get; set; }
    }

    [Table("hr_levels")]
    public record HRLevelRecord : BaseRecord
    {
        public int HRLevel { get; set; }
        public int UnlockPoints { get; set; }
        public string? UnlockStage { get; set; }
        public string? Buffs { get; set; }
    }
}
