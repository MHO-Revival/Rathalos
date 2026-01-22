using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.IO;
using Microsoft.Extensions.Logging;
using System.Net.Sockets;
using Rathalos.Core.Protocol;

namespace Rathalos.Servers.Base.Core.Network
{
	public abstract class MHOBaseClient : BaseClient
	{
		protected MHOBaseClient(Socket socket, ILogger logger) : base(socket, logger)
		{
		}

		protected override async Task OnDataReceived(IDataReader reader)
		{
			var rawMessage = new RawMessage();
			while (rawMessage.Parse(reader) && !_tokenSource.IsCancellationRequested)
			{
				var message = MessageReceiver.BuildMessage(rawMessage.MessageId, new BigEndianReader(rawMessage.RawBody));
				if (message == null)
					continue;

				_logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) {Name}", 
					ConsoleFormat.ReceivePacket, this, message.GetType().Name);

				await OnMessageReceived(message);
			}

		}

		protected abstract Task OnMessageReceived(Message message);

	}
}
