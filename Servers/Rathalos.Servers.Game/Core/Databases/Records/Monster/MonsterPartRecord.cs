using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_parts")]
    public record MonsterPartRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public int PartID { get; set; }
        public string? PartName { get; set; }
        public int StateID { get; set; }
        public int Unbalance { get; set; }
        public float UnbalanceMulti { get; set; }
        public int Scar { get; set; }
        public int Fall { get; set; }
        public float FallMulti { get; set; }
        public int WaterAcc { get; set; }
        public float WaterAccMulti { get; set; }
        public int FireAcc { get; set; }
        public float FireAccMulti { get; set; }
        public int ElectricAcc { get; set; }
        public float ElectricAccMulti { get; set; }
        public int DragonAcc { get; set; }
        public float DragonAccMulti { get; set; }
        public int IceAcc { get; set; }
        public float IceAccMulti { get; set; }
        public int NoneAcc { get; set; }
        public float NoneAccMulti { get; set; }
        public int DmgVal1 { get; set; }
        public int ProcessLv1 { get; set; }
        public int Hammer1 { get; set; }
        public int Cut1 { get; set; }
        public int Shoot1 { get; set; }
        public int Water1 { get; set; }
        public int Fire1 { get; set; }
        public int Electric1 { get; set; }
        public int Dragon1 { get; set; }
        public int Ice1 { get; set; }
        public int LootSkillLv1 { get; set; }
        public int DmgVal2 { get; set; }
        public int ProcessLv2 { get; set; }
        public int Hammer2 { get; set; }
        public int Cut2 { get; set; }
        public int Shoot2 { get; set; }
        public int Water2 { get; set; }
        public int Fire2 { get; set; }
        public int Electric2 { get; set; }
        public int Dragon2 { get; set; }
        public int Ice2 { get; set; }
        public int LootSkillLv2 { get; set; }
        public int DmgVal3 { get; set; }
        public int ProcessLv3 { get; set; }
        public int Hammer3 { get; set; }
        public int Cut3 { get; set; }
        public int Shoot3 { get; set; }
        public int Water3 { get; set; }
        public int Fire3 { get; set; }
        public int Electric3 { get; set; }
        public int Dragon3 { get; set; }
        public int Ice3 { get; set; }
        public int LootSkillLv3 { get; set; }
        public int DmgVal4 { get; set; }
        public int ProcessLv4 { get; set; }
        public int Hammer4 { get; set; }
        public int Cut4 { get; set; }
        public int Shoot4 { get; set; }
        public int Water4 { get; set; }
        public int Fire4 { get; set; }
        public int Electric4 { get; set; }
        public int Dragon4 { get; set; }
        public int Ice4 { get; set; }
        public int LootSkillLv4 { get; set; }
        public int DmgVal5 { get; set; }
        public int ProcessLv5 { get; set; }
        public int Hammer5 { get; set; }
        public int Cut5 { get; set; }
        public int Shoot5 { get; set; }
        public int Water5 { get; set; }
        public int Fire5 { get; set; }
        public int Electric5 { get; set; }
        public int Dragon5 { get; set; }
        public int Ice5 { get; set; }
        public int LootSkillLv5 { get; set; }
    }
}
