using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.MonsterData
{
    public class MonsterState
    {
        public int MonsterID { get; set; }

        public int StateID { get; set; }

        public string? StateName { get; set; }

        [TsvColumn("BB:InitValue")]
        public int BBInitValue { get; set; }

        [TsvColumn("BB:MaxValue")]
        public int BBMaxValue { get; set; }

        [TsvColumn("当前状态蓄积值")]
        public int CurrentAccumValue { get; set; }

        [TsvColumn("状态蓄积值下限")]
        public int AccumValueMin { get; set; }

        [TsvColumn("状态解除蓄积值")]
        public int ReleaseAccumValue { get; set; }

        [TsvColumn("状态下蓄积值衰减倍率")]
        public float AccumDecayRate { get; set; }

        [TsvColumn("状态下动作速度")]
        public float ActionSpeed { get; set; }

        [TsvColumn("状态攻击倍率")]
        public float AttackMultiplier { get; set; }

        [TsvColumn("状态防御倍率")]
        public float DefenseMultiplier { get; set; }
    }
}
