using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetInfo
    {
        public int ID { get; set; }

        [TsvColumn("是否随机属性")]
        public int IsRandomAttribute { get; set; }

        [TsvColumn("默认名字")]
        public string? DefaultName { get; set; }

        [TsvColumn("等级")]
        public int Level { get; set; }

        [TsvColumn("种类")]
        public int Species { get; set; }

        [TsvColumn("专精")]
        public int Specialization { get; set; }

        [TsvColumn("资质")]
        public int Aptitude { get; set; }

        [TsvColumn("品质")]
        public int Quality { get; set; }

        [TsvColumn("性格")]
        public int Personality { get; set; }

        [TsvColumn("攻击倾向")]
        public int AttackTendency { get; set; }

        [TsvColumn("攻击方式")]
        public int AttackMethod { get; set; }

        [TsvColumn("钻地血量百分比")]
        public int BurrowHpPercent { get; set; }

        [TsvColumn("回血速度")]
        public int HpRecoverySpeed { get; set; }

        [TsvColumn("支援技能")]
        public string? SupportSkill { get; set; }

        [TsvColumn("天生技能组")]
        public string? InnateSkillGroup { get; set; }

        [TsvColumn("泡泡组")]
        public string? BubbleGroup { get; set; }

        public string? EntityName { get; set; }

        [TsvColumn("类")]
        public int Class { get; set; }

        [TsvColumn("定制名")]
        public string? CustomName { get; set; }

        public string? Icon { get; set; }

        [TsvColumn("皮肤")]
        public int Skin { get; set; }

        [TsvColumn("描述")]
        public string? Description { get; set; }
    }
}
