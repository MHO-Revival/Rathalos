using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.World.Handlers;
using Rathalos.Servers.World.Handlers.Game;
using System.Net.Sockets;

namespace Rathalos.Servers.World.Core.Network
{
    public sealed class WorldClient : MHOBaseClient
    {
        public WorldClient(Socket socket, ILogger logger) : base(socket, logger)
        {
        }

        protected override async Task OnMessageReceived(TPDUExt message)
        {
            await TqqapiPacketHandler.Instance.HandleMessage(this, message);
        }

        protected override async Task OnMessageReceived(CSPkgBody message)
        {
            await GamePacketHandler.Instance.HandleMessage(this, message);
        }
    }
}
