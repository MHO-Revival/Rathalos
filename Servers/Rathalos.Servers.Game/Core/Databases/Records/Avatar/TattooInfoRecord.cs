using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("tattoo_infos")]
    public record TattooInfoRecord : BaseRecord
    {
        public int TattooId { get; set; }
        public int? MaleModelId { get; set; }
        public int? FemaleModelId { get; set; }
    }
}
