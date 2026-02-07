using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSkillSlotUnlock
    {
        public int ID { get; set; }

        [TsvColumn("道具ID")]
        public int ItemId { get; set; }

        [TsvColumn("道具数量")]
        public int ItemCount { get; set; }
    }
}
