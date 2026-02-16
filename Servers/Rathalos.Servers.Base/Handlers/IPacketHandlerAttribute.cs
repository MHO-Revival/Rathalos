namespace Rathalos.Servers.Base.Handlers
{
	public interface IPacketHandlerAttribute
	{
		public abstract int ProtocolMessageId { get; }
		public abstract Type MessageType { get; }
		public bool LogPacket { get; }
    }
}
