using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("init_quick_supplies")]
    public record InitQuickSupplyRecord : BaseRecord
    {
        public int Index { get; set; }
        public int ItemId { get; set; }
        public int ItemCount { get; set; }
    }
}
