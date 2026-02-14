using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_skill_slot_unlocks")]
    public record PetSkillSlotUnlockRecord : BaseRecord
    {
        public int SlotId { get; set; }
        public int ItemId { get; set; }
        public int ItemCount { get; set; }
    }
}
