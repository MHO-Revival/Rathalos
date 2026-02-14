using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    /// <summary>
    /// Random Pool
    /// </summary>
    [Table("random_pools")]
    public record RandomPoolRecord : BaseRecord
    {
        public int PoolId { get; set; }
        public int RandomType { get; set; }
        public int RefreshPeriod { get; set; }
        public string? RefreshTime { get; set; }
        public string? Groups { get; set; }
        public int BuyTimeInterval { get; set; }
        public int Points { get; set; }
        public int BindPoints { get; set; }
        public int UnlockCard { get; set; }
        public int RefreshCount1 { get; set; }
        public int RefreshPrice1 { get; set; }
        public int RefreshCount2 { get; set; }
        public int RefreshPrice2 { get; set; }
        public int RefreshCount3 { get; set; }
        public int RefreshPrice3 { get; set; }
        public int RefreshCount4 { get; set; }
        public int RefreshPrice4 { get; set; }
        public int RefreshCount5 { get; set; }
        public int RefreshPrice5 { get; set; }
    }
}
