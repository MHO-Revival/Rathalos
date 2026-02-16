using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.Base.Services;
using System.Reflection;

namespace Rathalos.Servers.Base.Handlers
{
    public abstract class BasePacketHandler<TClient, TMessage, TAttribute, THandler> : WarmupService<THandler>
        where TClient : BaseClient
        where TMessage : IDataProtocol
        where TAttribute : Attribute, IPacketHandlerAttribute
        where THandler : BasePacketHandler<TClient, TMessage, TAttribute, THandler>
    {
        private readonly Dictionary<int, (bool LogPacket, Type Type, Func<object, TClient, TMessage, Task> Lambda)> _handlers = new();
        private readonly IServiceProvider _provider;
        private readonly Assembly _assembly;
        private readonly ILogger _logger;

        public BasePacketHandler(IServiceProvider provider, Assembly assembly, ILogger<THandler> logger)
        {
            _provider = provider;
            _assembly = assembly;
            _logger = logger;
        }

        public override Task Initialize()
        {
            foreach (var (attribute, type, method) in from type in _assembly.GetTypes()
                                                      from method in type.GetMethods()
                                                      let attribute = method.GetCustomAttribute<TAttribute>()
                                                      where attribute is not null
                                                      select (attribute, type, method))
            {

                var factory = method.CreateDelegate<TClient, TMessage, Task>();
                _handlers.TryAdd(attribute.ProtocolMessageId, (attribute.LogPacket, type, factory));
            }

            return Task.CompletedTask;
        }

        public async Task HandleMessage(TClient client, TMessage message)
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

                    if (handler.LogPacket)
                        _logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) [GAME] {Name}", ConsoleFormat.ReceivePacket, client, message.GetType().Name);

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
