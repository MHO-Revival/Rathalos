using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetSupportCatSkill
    {
        public int ID { get; set; }

        [TsvColumn("出场动画")]
        public string? EntranceAnimation { get; set; }

        [TsvColumn("退场动画")]
        public string? ExitAnimation { get; set; }

        [TsvColumn("技能循环次数")]
        public int SkillLoopCount { get; set; }

        [TsvColumn("技能释放起始动画")]
        public string? SkillStartAnimation { get; set; }

        [TsvColumn("技能释放循环动画")]
        public string? SkillLoopAnimation { get; set; }

        [TsvColumn("技能释放结束动画")]
        public string? SkillEndAnimation { get; set; }
    }
}
