using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetLevel
    {
        [TsvColumn("等级")]
        public int Level { get; set; }

        [TsvColumn("升级经验")]
        public int UpgradeExp { get; set; }

        [TsvColumn("技能点成长标准值")]
        public int SkillPointGrowth { get; set; }

        [TsvColumn("潜能点成长标准值")]
        public int PotentialPointGrowth { get; set; }

        [TsvColumn("攻击力成长标准值")]
        public int AttackGrowth { get; set; }

        [TsvColumn("防御力成长标准值")]
        public int DefenseGrowth { get; set; }

        [TsvColumn("生命值成长标准值")]
        public int HpGrowth { get; set; }

        [TsvColumn("行动力成长标准值")]
        public int ActionPowerGrowth { get; set; }

        [TsvColumn("观察力成长标准值")]
        public int ObservationGrowth { get; set; }

        [TsvColumn("负荷力成长标准值")]
        public int LoadCapacityGrowth { get; set; }
    }
}
