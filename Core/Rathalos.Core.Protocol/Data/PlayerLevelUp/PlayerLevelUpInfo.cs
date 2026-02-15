using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.PlayerLevelUp
{
    public class PlayerLevelUpInfo
    {
        [TsvColumn("角色等级")]
        public int Level { get; set; }
        [TsvColumn("升级经验")]
        public int LevelUpExp { get; set; }
        [TsvColumn("最大生命")]
        public int? MaxHp { get; set; }
        [TsvColumn("力量")]
        public int? Strength { get; set; }
        [TsvColumn("爆发")]
        public int? Burst { get; set; }
        [TsvColumn("运气")]
        public int? Luck { get; set; }
        [TsvColumn("体力")]
        public int? Stamina { get; set; }
        [TsvColumn("直升50级增加HR点数")]
        public int HRPoints { get; set; }
    }
}
