using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("hair_infos")]
    public record HairInfoRecord : BaseRecord
    {
        public int HairId { get; set; }
        public int MaleModelId { get; set; }
        public int FemaleModelId { get; set; }
    }
}
