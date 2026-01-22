using Rathalos.Core.ORM.Config;

namespace Rathalos.Servers.Base.Core.Configurations
{
	public abstract class BaseServerConfiguration
	{
		public string AddressIP { get; set; } = "127.0.0.1";
		public virtual int Port { get; set; }
		public string ProtocolVersion { get; set; } = "1.0.3+56e1f37";
		public string SecurityKey { get; set; } = "Rathalos4EverBest!Rathalos4EverBest!";
		public virtual ORMConfiguration Database { get; set; } = new ORMConfiguration();
		public string IPCAddressIP { get; set; } = "127.0.0.1";
		public short IPCPort { get; set; } = 9000;
		public TimeSpan SaveInterval { get; set; } = TimeSpan.FromHours(1);
	}
}
