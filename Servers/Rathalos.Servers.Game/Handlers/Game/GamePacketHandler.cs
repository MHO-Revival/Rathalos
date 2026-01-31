using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;
using System.Reflection;

namespace Rathalos.Servers.World.Handlers.Game
{
    public sealed class GamePacketHandler : BasePacketHandler<WorldClient, CSPkgBody, GamePacketHandlerAttribute, GamePacketHandler>
    {
        public GamePacketHandler(IServiceProvider provider, ILogger<GamePacketHandler> logger)
            : base(provider, Assembly.GetExecutingAssembly(), logger)
        {
        }
    }
}
