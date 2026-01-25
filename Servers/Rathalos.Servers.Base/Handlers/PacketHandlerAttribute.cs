using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages;
using System.Globalization;

namespace Rathalos.Servers.Base.Handlers
{
	public abstract class PacketHandlerAttribute : Attribute, IPacketHandlerAttribute
	{
		public abstract int ProtocolMessageId { get; }
		public abstract Type MessageType { get; }
	}
	[AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
	public sealed class PacketHandlerAttribute<TMessage> : PacketHandlerAttribute
		where TMessage : IDataProtocol
	{
		public override int ProtocolMessageId => Convert.ToInt32(typeof(TMessage).GetField(nameof(PacketHandlerAttribute.ProtocolMessageId))?.GetValue(null), CultureInfo.InvariantCulture);
		public override Type MessageType => typeof(TMessage);
	}
}
