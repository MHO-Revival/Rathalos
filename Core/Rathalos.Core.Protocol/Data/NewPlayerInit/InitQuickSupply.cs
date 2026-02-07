using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.NewPlayerInit
{
    public class InitQuickSupply
    {
        public int Index { get; set; }

        [TsvColumn("道具ID")]
        public int ItemId { get; set; }

        [TsvColumn("道具数量")]
        public int ItemCount { get; set; }
    }
}
