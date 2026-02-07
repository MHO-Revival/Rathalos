using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.AvatarAttrInfo
{
    public class HairInfo
    {
        [TsvColumn("编号")]
        public int Id { get; set; }

        [TsvColumn("男模型编号")]
        public int MaleModelId { get; set; }

        [TsvColumn("女模型编号")]
        public int FemaleModelId { get; set; }
    }
}
