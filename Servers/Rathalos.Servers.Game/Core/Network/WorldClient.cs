using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Core.Network;
using System.Net.Sockets;

namespace Rathalos.Servers.World.Core.Network
{
    public sealed class WorldClient : MHOBaseClient
    {
        public WorldClient(Socket socket, ILogger logger) : base(socket, logger)
        {
        }

        protected override Task OnMessageReceived(TPDUExt message)
        {
            return Task.CompletedTask;
        }

        protected override Task OnMessageReceived(CSPkgBody message)
        {
            return Task.CompletedTask;
        }
    }
}
