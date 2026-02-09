using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("face_infos")]
    public record FaceInfoRecord : BaseRecord
    {
        public int FaceId { get; set; }
        public int MaleModelId { get; set; }
        public int FemaleModelId { get; set; }
    }

    [Table("hair_infos")]
    public record HairInfoRecord : BaseRecord
    {
        public int HairId { get; set; }
        public int MaleModelId { get; set; }
        public int FemaleModelId { get; set; }
    }

    [Table("tattoo_infos")]
    public record TattooInfoRecord : BaseRecord
    {
        public int TattooId { get; set; }
        public int? MaleModelId { get; set; }
        public int? FemaleModelId { get; set; }
    }

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
