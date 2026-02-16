using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Core.Utils.IO;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Handlers.Tqqapi;
using System.Reflection;

namespace Rathalos.Servers.World.Handlers
{
    public sealed class TqqapiPacketHandler : WarmupService<TqqapiPacketHandler>
    {
        private readonly Dictionary<int, (bool LogPacket, Type HandlerType, Type TqqMessageType, Func<object, WorldClient, ITqqMessage, Task> Lambda)> _handlers = new();
        private readonly IServiceProvider _provider;
        private readonly Assembly _assembly;
        private readonly ILogger _logger;


        public TqqapiPacketHandler(IServiceProvider provider, ILogger<TqqapiPacketHandler> logger)
        {
            _provider = provider;
            _logger = logger;
            _assembly = Assembly.GetExecutingAssembly();
        }


        public override Task Initialize()
        {
            foreach (var (attribute, type, method) in from type in _assembly.GetTypes()
                                                      from method in type.GetMethods()
                                                      let attribute = method.GetCustomAttribute<TqqapiPacketHandlerAttribute>()
                                                      where attribute is not null
                                                      select (attribute, type, method))
            {
                var factory = method.CreateDelegate<WorldClient, ITqqMessage, Task>();

                var tqqMessageType = method.GetParameters()
                    .Select(p => p.ParameterType)
                    .FirstOrDefault(t => t.IsGenericType && t.GetGenericTypeDefinition() == typeof(TqqMessage<,>));

                if (tqqMessageType is null)
                {
                    throw new Exception($"[Tqqapi] Error impossible to find TqqMessage type for handler {type.Name}.{method.Name} for message {attribute.ProtocolMessageId} ({attribute.MessageType.Name})");
                }

                _handlers.TryAdd(attribute.ProtocolMessageId, (attribute.LogPacket, type, tqqMessageType, factory));
            }

            return Task.CompletedTask;
        }

        public async Task HandleMessage(WorldClient client, TPDUExt message, BigEndianReader bodyReader)
        {
            try
            {
                if (!_handlers.TryGetValue(message.ProtocolId, out var handler))
                {
                    _logger.LogWarning($"[Tqqapi] Received a message not handled : {message.GetType().Name}");
                    return;
                }

                var tqqMessage = (ITqqMessage)Activator.CreateInstance(handler.TqqMessageType)!;

                var extensionProperty = handler.TqqMessageType.GetProperty("Extension")!;
                extensionProperty.SetValue(tqqMessage, message);

                tqqMessage.DeserializeBody(bodyReader);

                using var scope = _provider.CreateScope();
                var handlerService = scope.ServiceProvider.GetService(handler.HandlerType);

                if (handlerService == null)
                    return;

                if (handler.LogPacket)
                    _logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) [TPDU] {Name}", ConsoleFormat.ReceivePacket, client, message.GetType().Name);

                await handler.Lambda(handlerService, client, tqqMessage);
            }
            catch (Exception ex)
            {
                _logger.LogError(ex.ToString());
                _ = client.Disconnect();
            }
        }
    }
}
