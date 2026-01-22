namespace Rathalos.Servers.Base.Handlers
{
	public interface IPacketHandlerAttribute
	{
		public abstract ushort ProtocolMessageId { get; }
		public abstract Type MessageType { get; }

	}
}
