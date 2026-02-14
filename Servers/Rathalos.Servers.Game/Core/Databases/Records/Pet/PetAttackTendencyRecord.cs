using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_attack_tendencies")]
    public record PetAttackTendencyRecord : BaseRecord
    {
        public int TendencyId { get; set; }
        public int Weight { get; set; }
    }
}
