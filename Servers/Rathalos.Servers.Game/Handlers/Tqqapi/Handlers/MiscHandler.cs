using Org.BouncyCastle.Bcpg;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Tqqapi.Classes;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Handlers.Game;

namespace Rathalos.Servers.World.Handlers.Tqqapi.Handlers
{
    public sealed class MiscHandler : IMessageHandler
    {
        private readonly ILogger _logger;
        public MiscHandler(ILogger<MiscHandler> logger)
        {
            _logger = logger;
        }

        [TqqapiPacketHandler<TpduNone>(LogPacket = false)]
        public async Task HandleNoneMessage(WorldClient client, TqqMessage<TpduNone, CSPkg> message)
        {
            var body = message.Body.Body;
            // This is a keep-alive or no-op message
            await GamePacketHandler.Instance.HandleMessage(client, body);
        }
    }
}
