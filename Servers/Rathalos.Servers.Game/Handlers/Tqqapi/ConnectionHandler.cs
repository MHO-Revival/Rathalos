using Rathalos.Servers.Base.Handlers;
using Rathalos.Core.Protocol.Messages.Tqqapi.Custom;
using Rathalos.Servers.World.Core.Network;
namespace Rathalos.Servers.World.Handlers.Tqqapi
{
    public class ConnectionHandler : IMessageHandler
    {
        [TqqapiPacketHandler<TpduCloseConnection>]
        public async Task HandleConnectionEstablished(WorldClient client, TpduCloseConnection message)
        {
            await client.Disconnect();
        }
    }
}
