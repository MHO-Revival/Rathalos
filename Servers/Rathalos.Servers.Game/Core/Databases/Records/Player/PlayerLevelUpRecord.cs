using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("player_level_ups")]
    public record PlayerLevelUpRecord : BaseRecord
    {
        public int Level { get; set; }
        public int LevelUpExp { get; set; }
        public int? MaxHp { get; set; }
        public int? Strength { get; set; }
        public int? Burst { get; set; }
        public int? Luck { get; set; }
        public int? Stamina { get; set; }
        public int HRPoints { get; set; }
    }
}
