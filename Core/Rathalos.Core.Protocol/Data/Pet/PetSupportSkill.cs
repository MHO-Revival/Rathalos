using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSupportSkill
    {
        [TsvColumn("技能ID")]
        public int SkillId { get; set; }

        [TsvColumn("技能名称")]
        public string? SkillName { get; set; }

        [TsvColumn("等级")]
        public int Level { get; set; }

        [TsvColumn("对应buff")]
        public int BuffId { get; set; }

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

        [TsvColumn("描述")]
        public string? Description { get; set; }

        public string? Icon { get; set; }
    }
}
