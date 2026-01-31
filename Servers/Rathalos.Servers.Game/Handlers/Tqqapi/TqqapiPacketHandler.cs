using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Handlers.Tqqapi;
using System.Reflection;

namespace Rathalos.Servers.World.Handlers
{
    public sealed class TqqapiPacketHandler : WarmupService<TqqapiPacketHandler>
    {
        private readonly Dictionary<int, (Type Type, Func<object, WorldClient, ITqqMessage, Task> Lambda)> _handlers = new();
        private readonly IServiceProvider _provider;
        private readonly Assembly _assembly;
        private readonly ILogger _logger;


        public TqqapiPacketHandler(IServiceProvider provider, ILogger<TqqapiPacketHandler> logger)
        {
            _provider = provider;
            _logger = logger;
            _assembly = Assembly.GetExecutingAssembly();
        }

  
        public override void Initialize()
        {
            foreach (var (messageId, messageType, type, method) in from type in _assembly.GetTypes()
                                                                   from method in type.GetMethods()
                                                                   let attribute = method.GetCustomAttribute<TqqapiPacketHandlerAttribute>()
                                                                   where attribute is not null
                                                                   select (attribute.ProtocolMessageId, attribute.MessageType, type, method))
            {

                var factory = method.CreateDelegate<WorldClient, ITqqMessage, Task>();
                _handlers.TryAdd(messageId, (type, factory));
            }
        }

        public async Task HandleMessage(WorldClient client, TPDUExt message, byte[] body)
        {
            try
            {
                if (!_handlers.TryGetValue(message.ProtocolId, out var handler))
                {
                    _logger.LogWarning($"Received a message not handled : {message.GetType().Name}");
                    return;
                }



                using (var scope = _provider.CreateScope())
                {
                    var handlerService = scope.ServiceProvider.GetService(handler.Type) ?? null;

                    if (handlerService == null)
                        return;

                    await handler.Lambda(handlerService, client, message);
                }
            }
            catch (Exception ex)
            {
                _logger.LogError(ex.ToString());
                _ = client.Disconnect();
            }
        }
    }
}
