using Rathalos.Core.Protocol.Messages;
using System.Globalization;

namespace Rathalos.Servers.Base.Handlers
{
	public abstract class PacketHandlerAttribute : Attribute, IPacketHandlerAttribute
	{
		public abstract ushort ProtocolMessageId { get; }
		public abstract Type MessageType { get; }
	}
	[AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
	public sealed class PacketHandlerAttribute<TMessage> : PacketHandlerAttribute
		where TMessage : Message
	{
		public override ushort ProtocolMessageId => Convert.ToUInt16(typeof(TMessage).GetField(nameof(Message.ProtocolMessageId))?.GetValue(null), CultureInfo.InvariantCulture);
		public override Type MessageType => typeof(TMessage);
	}
}
