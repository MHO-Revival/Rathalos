using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("init_shortcuts")]
    public record InitShortcutRecord : BaseRecord
    {
        public int ShortcutPos { get; set; }
        public int ItemId { get; set; }
    }
}
