using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.Base.Services;
using System.Reflection;

namespace Rathalos.Servers.Base.Handlers
{
	public abstract class BasePacketHandler<TClient, TMessage, TAttribute, THandler> : WarmupService<THandler>
		where TClient : BaseClient
		where TMessage : Message
		where TAttribute : Attribute, IPacketHandlerAttribute
		where THandler : BasePacketHandler<TClient, TMessage, TAttribute, THandler>
	{
		private readonly Dictionary<ushort, (Type Type, Func<object, TClient, TMessage, Task> Lambda)> _handlers = new();
		private readonly IServiceProvider _provider;
		private readonly Assembly _assembly;
		private readonly ILogger _logger;

		public BasePacketHandler(IServiceProvider provider, Assembly assembly, LoggingService loggingService)
		{
			_provider = provider;
			_assembly = assembly;
			_logger = loggingService.CreateLogger<THandler>();
		}

		public override void Initialize()
		{
			foreach (var (messageId, messageType, type, method) in from type in _assembly.GetTypes()
																   from method in type.GetMethods()
																   let attribute = method.GetCustomAttribute<TAttribute>()
																   where attribute is not null
																   select (attribute.ProtocolMessageId, attribute.MessageType, type, method))
			{

				var factory = method.CreateDelegate<TClient, TMessage, Task>();
				_handlers.TryAdd(messageId, (type, factory));
			}
		}

		public virtual async Task HandleMessage(TClient client, TMessage message)
		{
			try
			{
				if (!_handlers.TryGetValue(message.ProtocolMessageId, out var handler))
				{
					_logger.LogWarning($"Received a message not handled : {message.GetType().Name}");
					return;
				}

				var handlerService =
					_provider?.GetService(handler.Type) ?? null;

				if (handlerService == null)
					return;

				await handler.Lambda(handlerService, client, message);
			}
			catch (Exception ex)
			{
				_logger.LogError(ex.ToString());
				_ = client.Disconnect();
			}
		}
	}
}
