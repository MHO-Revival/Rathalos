using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.HRLevel
{
    public class HRLevelInfo
    {
        public int HRLevel { get; set; }

        [TsvColumn("解锁点数")]
        public int UnlockPoints { get; set; }

        [TsvColumn("解锁关卡")]
        public string? UnlockStage { get; set; }

        public string? Buffs { get; set; }
    }
}
