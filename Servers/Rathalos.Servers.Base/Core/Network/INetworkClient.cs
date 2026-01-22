using Rathalos.Core.Protocol.Messages;

namespace Rathalos.Servers.Base.Core.Network
{
	public interface INetworkClient<T> : INetworkClient
		where T : BaseClient
	{
		List<T> GetClients();
    }

	public interface INetworkClient
	{
		void Send(Message message);
	}
}
