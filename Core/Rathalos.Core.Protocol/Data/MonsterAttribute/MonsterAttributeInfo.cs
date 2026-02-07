using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.MonsterAttribute
{
    public class MonsterAttributeInfo
    {
        public int ID { get; set; }

        [TsvColumn("CName")]
        public string ChineseName { get; set; } = string.Empty;

        public string Name { get; set; } = string.Empty;

        public string Type { get; set; } = string.Empty;

        public int Bonus { get; set; }

        public int Sync { get; set; }

        public string? Lower { get; set; }

        public string? Upper { get; set; }

        public string? Wrapper { get; set; }
    }
}
