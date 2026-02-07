using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSkin
    {
        public int ID { get; set; }

        [TsvColumn("权重")]
        public int Weight { get; set; }

        public string? Icon { get; set; }

        [TsvColumn("描述")]
        public string? Description { get; set; }
    }
}
