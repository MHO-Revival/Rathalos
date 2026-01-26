using Rathalos.Core.ORM;
using Rathalos.Core.Utils.I18N;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.Base.Core.Databases.Configurations
{
    [Table("informations")]
	public record ServerConfigurationRecord : BaseRecord
	{
        public string Name { get; set; }
		public byte CharactersSlots { get; set; }
		public ushort MaxCharactersCount { get; set; }
		public DateTime CreationDate { get; set; }
		public Languages Lang { get; set; }
		public string Version { get; set; }
    }
}
