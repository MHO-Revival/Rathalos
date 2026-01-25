using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;
using System.Reflection;

namespace Rathalos.Servers.World.Handlers
{
    public sealed class GamePacketHandler : BasePacketHandler<WorldClient, CSPkgBody, PacketHandlerAttribute<CSPkgBody>, GamePacketHandler>
    {
        public GamePacketHandler(IServiceProvider provider, Assembly assembly, LoggingService loggingService) : base(provider, assembly, loggingService)
        {
        }
    }
}
