using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_qualities")]
    public record PetQualityRecord : BaseRecord
    {
        public int QualityId { get; set; }
        public int Weight { get; set; }
    }
}
