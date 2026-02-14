using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("init_stores")]
    public record InitStoreRecord : BaseRecord
    {
        public string StoreParam { get; set; } = string.Empty;
        public string? StoreValue { get; set; }
    }
}
