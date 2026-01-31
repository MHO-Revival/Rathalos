using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Handlers.Game.Handlers
{
    public sealed class NetworkHandler : IMessageHandler
    {
        [GamePacketHandler<CSMultiNetIpinfo>]
        public Task HandleMultiNetIpInfo(WorldClient client, CSMultiNetIpinfo message)
        {
            // Handle multi-network IP info here
            // This is maybe for switching servers or optimizing network routes with a tpdu server as front door.
            // For demonstration, we'll just log the received IP info
            Console.WriteLine($"Received MultiNet IP Info from Client {client.SyncGuid}: {message.SelectIP}, Domain: {message.DomainName}");
            return Task.CompletedTask;
        }

    }
}
