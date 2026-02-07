using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Pet
{
    public class PetAptitudeQuality
    {
        public int ID { get; set; }

        [TsvColumn("资质")]
        public int Aptitude { get; set; }

        [TsvColumn("品质")]
        public int Quality { get; set; }

        [TsvColumn("性格")]
        public int Personality { get; set; }

        [TsvColumn("固定技能ID")]
        public int FixedSkillId { get; set; }

        [TsvColumn("初始技能点")]
        public int InitialSkillPoints { get; set; }

        [TsvColumn("技能成长点")]
        public int SkillGrowthPoints { get; set; }

        [TsvColumn("潜能成长点")]
        public int PotentialGrowthPoints { get; set; }

        [TsvColumn("等级上限")]
        public int MaxLevel { get; set; }

        [TsvColumn("精英技能装备数量")]
        public int EliteSkillSlots { get; set; }

        [TsvColumn("主动技能槽数量")]
        public int ActiveSkillSlots { get; set; }

        [TsvColumn("被动技能槽数量")]
        public int PassiveSkillSlots { get; set; }

        [TsvColumn("支援被动技能槽数量")]
        public int SupportPassiveSkillSlots { get; set; }

        [TsvColumn("支援主动技能槽数量")]
        public int SupportActiveSkillSlots { get; set; }

        [TsvColumn("初始攻击力")]
        public int InitialAttack { get; set; }

        [TsvColumn("攻击力成长系数")]
        public float AttackGrowthCoef { get; set; }

        [TsvColumn("初始防御力")]
        public int InitialDefense { get; set; }

        [TsvColumn("防御力成长系数")]
        public float DefenseGrowthCoef { get; set; }

        [TsvColumn("初始生命值")]
        public int InitialHp { get; set; }

        [TsvColumn("生命值成长系数")]
        public float HpGrowthCoef { get; set; }

        [TsvColumn("初始行动力")]
        public int InitialActionPower { get; set; }

        [TsvColumn("行动力成长系数")]
        public float ActionPowerGrowthCoef { get; set; }

        [TsvColumn("初始观察力")]
        public int InitialObservation { get; set; }

        [TsvColumn("观察力成长系数")]
        public float ObservationGrowthCoef { get; set; }

        [TsvColumn("初始负荷力")]
        public int InitialLoadCapacity { get; set; }

        [TsvColumn("负荷力成长系数")]
        public float LoadCapacityGrowthCoef { get; set; }

        [TsvColumn("普通技能栏上限")]
        public int NormalSkillSlotMax { get; set; }

        [TsvColumn("笛子技能栏上限")]
        public int FluteSkillSlotMax { get; set; }

        [TsvColumn("勋章技能栏上限")]
        public int MedalSkillSlotMax { get; set; }

        [TsvColumn("天生技能上限")]
        public int InnateSkillMax { get; set; }

        [TsvColumn("支援技能上限")]
        public int SupportSkillMax { get; set; }

        [TsvColumn("普通技能槽初始锁定信息")]
        public string? NormalSkillSlotLockInfo { get; set; }

        [TsvColumn("普通技能槽1解锁条件")]
        public string? NormalSkillSlot1UnlockCondition { get; set; }

        [TsvColumn("普通技能槽2解锁条件")]
        public string? NormalSkillSlot2UnlockCondition { get; set; }

        [TsvColumn("普通技能槽3解锁条件")]
        public string? NormalSkillSlot3UnlockCondition { get; set; }

        [TsvColumn("笛子技能槽初始锁定信息")]
        public string? FluteSkillSlotLockInfo { get; set; }

        [TsvColumn("笛子技能槽1解锁条件")]
        public string? FluteSkillSlot1UnlockCondition { get; set; }

        [TsvColumn("笛子技能槽2解锁条件")]
        public string? FluteSkillSlot2UnlockCondition { get; set; }

        public float Defence { get; set; }

        public float PhyPDRatio { get; set; }

        public float MonsterAtkPet { get; set; }

        public float PlayerAtkPet { get; set; }
    }
}
