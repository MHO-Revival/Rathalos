using Rathalos.Core.ORM;
using Rathalos.Core.ORM.Attributes;
using Rathalos.Core.Utils.I18N;

namespace Rathalos.Servers.Base.Core.Databases.Configurations
{
    [CollectionName("informations")]
	public class ServerConfigurationRecord : BaseRecord
	{
        public string Name { get; set; }
		public byte CharactersSlots { get; set; }
		public ushort MaxCharactersCount { get; set; }
		public DateTime CreationDate { get; set; }
		public Languages Lang { get; set; }
		public string Version { get; set; }
    }
}
