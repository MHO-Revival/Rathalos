using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("init_attributes")]
    public record InitAttributeRecord : BaseRecord
    {
        public string AttrName { get; set; } = string.Empty;
        public string? AttrValue { get; set; }
    }
}
