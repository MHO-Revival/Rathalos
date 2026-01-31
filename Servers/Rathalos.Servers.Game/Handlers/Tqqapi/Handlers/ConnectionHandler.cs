using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Protocol.Messages.Custom;
namespace Rathalos.Servers.World.Handlers.Tqqapi.Handlers
{
    public sealed class ConnectionHandler : IMessageHandler
    {
        [TqqapiPacketHandler<TpduCloseConnection>]
        public async Task HandleConnectionEstablished(WorldClient client, TpduCloseConnection message, byte[] body)
        {
            await client.Disconnect();
        }

        [TqqapiPacketHandler<TPDUExtRelay>]
        public async Task HandleRelayMessage(WorldClient client, TPDUExtRelay message, byte[] body)
        {
            // TODO: Implement reconnection logic here
            
        }
    }
}
