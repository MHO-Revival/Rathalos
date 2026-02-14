using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    /// <summary>
    /// Random Product
    /// </summary>
    [Table("random_products")]
    public record RandomProductRecord : BaseRecord
    {
        public int ProductRecordId { get; set; }
        public int ProductRowId { get; set; }
        public int Group { get; set; }
        public int ProductId { get; set; }
        public int ProductCount { get; set; }
        public int Weight { get; set; }
    }
}
