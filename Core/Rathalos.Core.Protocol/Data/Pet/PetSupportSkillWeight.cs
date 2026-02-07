using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSupportSkillWeight
    {
        public int ID { get; set; }

        [TsvColumn("技能名称")]
        public string? SkillName { get; set; }

        [TsvColumn("权重")]
        public int Weight { get; set; }
    }
}
