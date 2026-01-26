using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Handlers.Tqqapi;
using System.Reflection;

namespace Rathalos.Servers.World.Handlers
{
    public sealed class TqqapiPacketHandler : BasePacketHandler<WorldClient, TPDUExt, TqqapiPacketHandlerAttribute, TqqapiPacketHandler>
    {
        public TqqapiPacketHandler(IServiceProvider provider, LoggingService loggingService)
            : base(provider, Assembly.GetExecutingAssembly(), loggingService)
        {
        }
    }
}
