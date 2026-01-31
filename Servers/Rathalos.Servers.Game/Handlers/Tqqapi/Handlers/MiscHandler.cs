using Rathalos.Core.Protocol.Messages.Custom;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Handlers.Tqqapi.Handlers
{
    public sealed class MiscHandler : IMessageHandler
    {
        [TqqapiPacketHandler<TpduNone>]
        public async Task HandleNoneMessage(WorldClient client, TpduNone message, byte[] body)
        {
            // This is a keep-alive or no-op message
        }
    }
}
