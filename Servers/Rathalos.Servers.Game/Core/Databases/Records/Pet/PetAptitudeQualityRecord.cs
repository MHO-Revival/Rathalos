using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_aptitude_qualities")]
    public record PetAptitudeQualityRecord : BaseRecord
    {
        public int AptitudeQualityId { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int Personality { get; set; }
        public int FixedSkillId { get; set; }
        public int InitialSkillPoints { get; set; }
        public int SkillGrowthPoints { get; set; }
        public int PotentialGrowthPoints { get; set; }
        public int MaxLevel { get; set; }
        public int EliteSkillSlots { get; set; }
        public int ActiveSkillSlots { get; set; }
        public int PassiveSkillSlots { get; set; }
        public int SupportPassiveSkillSlots { get; set; }
        public int SupportActiveSkillSlots { get; set; }
        public int InitialAttack { get; set; }
        public float AttackGrowthCoef { get; set; }
        public int InitialDefense { get; set; }
        public float DefenseGrowthCoef { get; set; }
        public int InitialHp { get; set; }
        public float HpGrowthCoef { get; set; }
        public int InitialActionPower { get; set; }
        public float ActionPowerGrowthCoef { get; set; }
        public int InitialObservation { get; set; }
        public float ObservationGrowthCoef { get; set; }
        public int InitialLoadCapacity { get; set; }
        public float LoadCapacityGrowthCoef { get; set; }
        public int NormalSkillSlotMax { get; set; }
        public int FluteSkillSlotMax { get; set; }
        public int MedalSkillSlotMax { get; set; }
        public int InnateSkillMax { get; set; }
        public int SupportSkillMax { get; set; }
        public string? NormalSkillSlotLockInfo { get; set; }
        public string? NormalSkillSlot1UnlockCondition { get; set; }
        public string? NormalSkillSlot2UnlockCondition { get; set; }
        public string? NormalSkillSlot3UnlockCondition { get; set; }
        public string? FluteSkillSlotLockInfo { get; set; }
        public string? FluteSkillSlot1UnlockCondition { get; set; }
        public string? FluteSkillSlot2UnlockCondition { get; set; }
        public float Defence { get; set; }
        public float PhyPDRatio { get; set; }
        public float MonsterAtkPet { get; set; }
        public float PlayerAtkPet { get; set; }
    }
}
