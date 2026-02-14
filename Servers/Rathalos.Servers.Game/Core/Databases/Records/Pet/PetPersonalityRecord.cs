using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_personalities")]
    public record PetPersonalityRecord : BaseRecord
    {
        public int PersonalityId { get; set; }
        public int Weight { get; set; }
    }
}
