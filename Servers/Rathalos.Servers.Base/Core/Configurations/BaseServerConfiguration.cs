using Rathalos.Core.ORM.Config;

namespace Rathalos.Servers.Base.Core.Configurations
{
	public abstract class BaseServerConfiguration
	{
		public string AddressIP { get; set; } = "127.0.0.1";
		public virtual int Port { get; set; }
		public string SecurityKey { get; set; } = "Rathalos4EverBes";
		public virtual ORMConfiguration Database { get; set; } = new ORMConfiguration();
		public TimeSpan SaveInterval { get; set; } = TimeSpan.FromHours(1);
	}
}
