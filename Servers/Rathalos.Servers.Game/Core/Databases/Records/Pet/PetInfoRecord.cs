using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("pet_infos")]
    public record PetInfoRecord : BaseRecord
    {
        public int PetId { get; set; }
        public int IsRandomAttribute { get; set; }
        public string? DefaultName { get; set; }
        public int Level { get; set; }
        public int Species { get; set; }
        public int Specialization { get; set; }
        public int Aptitude { get; set; }
        public int Quality { get; set; }
        public int Personality { get; set; }
        public int AttackTendency { get; set; }
        public int AttackMethod { get; set; }
        public int BurrowHpPercent { get; set; }
        public int HpRecoverySpeed { get; set; }
        public string? SupportSkill { get; set; }
        public string? InnateSkillGroup { get; set; }
        public string? BubbleGroup { get; set; }
        public string? EntityName { get; set; }
        public int Class { get; set; }
        public string? CustomName { get; set; }
        public string? Icon { get; set; }
        public int Skin { get; set; }
        public string? Description { get; set; }
    }
}
