using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("init_items")]
    public record InitItemRecord : BaseRecord
    {
        public int InitId { get; set; }
        public int ItemId { get; set; }
        public int Count { get; set; }
        public int AutoEquip { get; set; }
        public int AutoStore { get; set; }
    }
}
