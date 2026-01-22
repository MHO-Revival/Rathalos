using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Utils.Collections;
using Rathalos.Servers.Base.Core.Network;

namespace Rathalos.Servers.Base.Services
{
	public class NetworkService<TClient> : INetworkClient<TClient>
		where TClient : BaseClient
	{
		private readonly ConcurrentList<TClient> _clients = new();

		public int Count => _clients.Count;

		public void AddClient(TClient client)
		{
			_clients.Add(client);
		}
		public void RemoveClient(TClient client)
		{
			_clients.Remove(client);
		}

		public void DisconnectClientsBy(Predicate<TClient> predicate)
		{
			var clientsToDisconnect = _clients.Where(_ => predicate(_)).ToArray();
			foreach (var client in clientsToDisconnect)
			{
				_ = client.Disconnect();
			}
		}

		public void Send(Message message)
		{
			foreach (var client in _clients)
			{
				client.Send(message);
			}
		}

		public void ForEach(Action<TClient> action)
		{
			foreach (var client in _clients)
			{
				action(client);
			}
		}

		public void ForEachIf(Func<TClient, bool> predicate, Action<TClient> action)
		{
			foreach (var client in _clients.Where(predicate))
			{
				action(client);
			}
		}

		public List<TClient> GetClients()
		{
			return _clients.ToList();
		}
	}
}
