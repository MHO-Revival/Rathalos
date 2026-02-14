using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_names")]
    public record PetNameRecord : BaseRecord
    {
        public int PetNameId { get; set; }
        public string Name { get; set; } = string.Empty;
        public int Weight { get; set; }
    }
}
