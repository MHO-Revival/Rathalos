using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;

namespace Rathalos.Servers.Base.Core.Network
{
	public interface INetworkClient<T> : INetworkClient
		where T : BaseClient
	{
		List<T> GetClients();
    }

	public interface INetworkClient
	{
        void Send(TPDUExt message);
        void Send(CSPkgBody message);
    }
}
