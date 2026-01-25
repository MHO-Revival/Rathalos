using Microsoft.Extensions.Logging;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Configurations;
using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;

namespace Rathalos.Servers.World.Core.Network
{
    public sealed class WorldServer : BaseServer<WorldClient, WorldServerConfiguration>
    {
        public WorldServer(LoggingService loggingService) : base(loggingService)
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
