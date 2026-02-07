namespace Rathalos.Core.Protocol.Data.MonsterData
{
    public class MonsterEmotion
    {
        public int MonsterID { get; set; }

        public int StateFrom { get; set; }

        public int StateTo { get; set; }

        public string? Condition { get; set; }

        public string? AndOr { get; set; }

        public string? Param1 { get; set; }

        public string? Param2 { get; set; }

        public string? Param3 { get; set; }
    }
}
