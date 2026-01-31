using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.World.Core.Configurations;
using System.Net.Sockets;

namespace Rathalos.Servers.World.Core.Network
{
    public sealed class WorldServer : BaseServer<WorldClient, WorldServerConfiguration>
    {
        public WorldServer(ILogger<WorldServerConfiguration> logger) : base(logger)
        {
        }

        protected override WorldClient CreateClient(Socket clientSocket)
        {
            return new WorldClient(clientSocket, _logger);
        }

        protected override void OnServerStarted()
        {
            _logger.LogInformation($"Server started on {Configuration.AddressIP}:{Configuration.Port}");
            //TODO: start battle server
        }
    }
}
