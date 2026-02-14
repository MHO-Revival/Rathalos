using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    /// <summary>
    /// NPC and Shop Relationship mapping
    /// </summary>
    [Table("npc_shop_mappings")]
    public record NpcShopMappingRecord : BaseRecord
    {
        public int MappingId { get; set; }
        public int NpcId { get; set; }
        public string? NpcName { get; set; }
        public int? Shop01Id { get; set; }
        public string? Shop01Name { get; set; }
        public int? Shop02Id { get; set; }
        public string? Shop02Name { get; set; }
        public int? Shop03Id { get; set; }
        public string? Shop03Name { get; set; }
        public int? Shop04Id { get; set; }
        public string? Shop04Name { get; set; }
        public int? Shop05Id { get; set; }
        public string? Shop05Name { get; set; }
        public int? Shop06Id { get; set; }
        public string? Shop06Name { get; set; }
    }
}
