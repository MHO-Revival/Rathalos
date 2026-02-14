using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_farewell_gifts")]
    public record PetFarewellGiftRecord : BaseRecord
    {
        public int IntimacyStarLevel { get; set; }
        public int CompensationItemId1 { get; set; }
        public int Count1 { get; set; }
        public int CompensationItemId2 { get; set; }
        public int Count2 { get; set; }
        public int CompensationItemId3 { get; set; }
        public int Count3 { get; set; }
    }
}
