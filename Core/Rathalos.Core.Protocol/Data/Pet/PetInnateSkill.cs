using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetInnateSkill
    {
        [TsvColumn("技能ID")]
        public int SkillId { get; set; }

        [TsvColumn("技能组")]
        public int SkillGroup { get; set; }

        [TsvColumn("技能名称")]
        public string? SkillName { get; set; }

        [TsvColumn("等级")]
        public int Level { get; set; }

        [TsvColumn("是否精英技能")]
        public int IsEliteSkill { get; set; }

        [TsvColumn("升级等级限制")]
        public int UpgradeLevelLimit { get; set; }

        [TsvColumn("升级所需物品1")]
        public int UpgradeItem1 { get; set; }

        [TsvColumn("升级所需物品1数量")]
        public int UpgradeItem1Count { get; set; }

        [TsvColumn("升级所需物品2")]
        public int UpgradeItem2 { get; set; }

        [TsvColumn("升级所需物品2数量")]
        public int UpgradeItem2Count { get; set; }

        [TsvColumn("升级所需物品3")]
        public int UpgradeItem3 { get; set; }

        [TsvColumn("升级所需物品3数量")]
        public int UpgradeItem3Count { get; set; }

        [TsvColumn("升级后技能ID")]
        public int UpgradedSkillId { get; set; }
    }
}
