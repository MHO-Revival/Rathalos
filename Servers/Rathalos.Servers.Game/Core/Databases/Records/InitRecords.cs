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

    [Table("init_items")]
    public record InitItemRecord : BaseRecord
    {
        public int InitId { get; set; }
        public int ItemId { get; set; }
        public int Count { get; set; }
        public int AutoEquip { get; set; }
        public int AutoStore { get; set; }
    }

    [Table("init_quick_supplies")]
    public record InitQuickSupplyRecord : BaseRecord
    {
        public int Index { get; set; }
        public int ItemId { get; set; }
        public int ItemCount { get; set; }
    }

    [Table("init_shortcuts")]
    public record InitShortcutRecord : BaseRecord
    {
        public int ShortcutPos { get; set; }
        public int ItemId { get; set; }
    }

    [Table("init_stores")]
    public record InitStoreRecord : BaseRecord
    {
        public string StoreParam { get; set; } = string.Empty;
        public string? StoreValue { get; set; }
    }
}
