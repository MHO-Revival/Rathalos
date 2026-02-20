using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes
{
    public sealed class TlvDebug : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Debug;
        protected override void SerializeContent(IDataWriter writer)
        {
        }
        override protected void DeserializeContent(IDataReader reader)
        {
        }
    }
}
