using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using System.Globalization;

namespace Rathalos.Servers.World.Handlers.Game;

public abstract class GamePacketHandlerAttribute : Attribute, IPacketHandlerAttribute
{
    public abstract int ProtocolMessageId { get; }
    public abstract Type MessageType { get; }
}
[AttributeUsage(AttributeTargets.Method, AllowMultiple = true)]
public sealed class GamePacketHandlerAttribute<TMessage> : GamePacketHandlerAttribute
    where TMessage : CSPkgBody
{
    private int? _protocolId = null;
    public override int ProtocolMessageId => _protocolId ??= Convert.ToInt32(typeof(TMessage).GetField(nameof(CSPkgBodyClientSendLog.ProtocolIdConst))?.GetValue(null), CultureInfo.InvariantCulture);
    public override Type MessageType => typeof(TMessage);
}
