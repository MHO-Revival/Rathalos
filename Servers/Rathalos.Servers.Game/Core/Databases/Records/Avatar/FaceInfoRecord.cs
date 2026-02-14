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
}
