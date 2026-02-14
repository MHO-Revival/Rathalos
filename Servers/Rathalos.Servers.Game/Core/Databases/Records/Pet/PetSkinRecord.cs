using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_skins")]
    public record PetSkinRecord : BaseRecord
    {
        public int SkinId { get; set; }
        public int Weight { get; set; }
        public string? Icon { get; set; }
        public string? Description { get; set; }
    }
}
