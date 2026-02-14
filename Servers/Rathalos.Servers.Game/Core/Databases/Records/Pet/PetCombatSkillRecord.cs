using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_combat_skills")]
    public record PetCombatSkillRecord : BaseRecord
    {
        public int SkillId { get; set; }
        public int SkillGroupId { get; set; }
        public int CdReductionSkillGroup { get; set; }
        public string? SkillGroupName { get; set; }
        public string? SkillName { get; set; }
        public int LearnJobLimit { get; set; }
        public int CanBeRandom { get; set; }
        public int CanBeUpgradeRandom { get; set; }
        public int RandomWeight { get; set; }
        public int LearnLevelLimit { get; set; }
        public int SkillLevel { get; set; }
        public int IsEliteSkill { get; set; }
        public int SkillType { get; set; }
        public int SubType { get; set; }
        public int ComprehensionCount { get; set; }
        public int SkillPointCost { get; set; }
        public int IntimacyHeartLevel { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int MutualExclusionGroup1 { get; set; }
        public int MutualExclusionGroup2 { get; set; }
        public int MutualExclusionGroup3 { get; set; }
        public int ActiveSkillId { get; set; }
        public int ActiveSkillTriggerRate { get; set; }
        public int SelfPassiveBuff { get; set; }
        public int OwnerPassiveBuff { get; set; }
        public int SelfSkillBuff { get; set; }
        public int OwnerSkillBuff { get; set; }
        public string? OwnerEffect { get; set; }
        public string? SelfEffect { get; set; }
        public string? MonsterEffect { get; set; }
        public string? SkillDescription { get; set; }
        public string? Icon { get; set; }
        public int NewType { get; set; }
        public int TalkId { get; set; }
    }
}
