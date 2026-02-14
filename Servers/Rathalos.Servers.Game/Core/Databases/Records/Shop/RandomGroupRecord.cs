using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    /// <summary>
    /// Random Group
    /// </summary>
    [Table("random_groups")]
    public record RandomGroupRecord : BaseRecord
    {
        public int GroupId { get; set; }
        public int RandomCount { get; set; }
        public int PriceResetPeriod { get; set; }
        public string? PriceResetTime { get; set; }
        public int PriceBonus1 { get; set; }
        public int PriceBonus2 { get; set; }
        public int PriceBonus3 { get; set; }
        public int PriceBonus4 { get; set; }
        public int PriceBonus5 { get; set; }
    }
}
