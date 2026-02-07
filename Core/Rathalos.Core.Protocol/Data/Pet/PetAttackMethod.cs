using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetAttackMethod
    {
        public int ID { get; set; }

        [TsvColumn("权重")]
        public int Weight { get; set; }
    }
}
