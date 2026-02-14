using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("underclothes_infos")]
    public record UnderclothesInfoRecord : BaseRecord
    {
        public int UnderclothesId { get; set; }
        public int MaleWrist { get; set; }
        public int MaleChest { get; set; }
        public int MaleLegs { get; set; }
        public int FemaleWrist { get; set; }
        public int FemaleChest { get; set; }
        public int FemaleLegs { get; set; }
    }
}
