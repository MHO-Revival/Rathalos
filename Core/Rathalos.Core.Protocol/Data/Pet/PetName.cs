using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetName
    {
        public int ID { get; set; }

        [TsvColumn("名字")]
        public string Name { get; set; } = string.Empty;

        [TsvColumn("权重")]
        public int Weight { get; set; }
    }
}
