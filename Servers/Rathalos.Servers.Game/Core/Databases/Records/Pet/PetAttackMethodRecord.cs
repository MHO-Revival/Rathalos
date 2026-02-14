using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_attack_methods")]
    public record PetAttackMethodRecord : BaseRecord
    {
        public int MethodId { get; set; }
        public int Weight { get; set; }
    }
}
