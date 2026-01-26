using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Handlers.Game;
using System.Globalization;

namespace Rathalos.Servers.World.Handlers.Tqqapi
{
    public abstract class TqqapiPacketHandlerAttribute : Attribute, IPacketHandlerAttribute
    {
        public abstract int ProtocolMessageId { get; }
        public abstract Type MessageType { get; }
    }
    [AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
    public sealed class TqqapiPacketHandlerAttribute<TMessage> : TqqapiPacketHandlerAttribute
        where TMessage : TPDUExt
    {
        private int? _protocolId = null;
        public override int ProtocolMessageId => _protocolId ??= Convert.ToInt32(typeof(TMessage).GetField(nameof(TPDUExtAuthDataAuthQQV1.ProtocolIdConst))?.GetValue(null), CultureInfo.InvariantCulture);
        public override Type MessageType => typeof(TMessage);
    }
}
