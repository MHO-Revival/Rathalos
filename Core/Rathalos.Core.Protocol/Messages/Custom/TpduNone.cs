using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages.Custom
{
    public sealed class TpduNone : TPDUExt
    {
        public const TPDU_CMD ProtocolIdConst = TPDU_CMD.TPDU_CMD_NONE;
        public int ProtocolId => (int)ProtocolIdConst;

        public void Deserialize(IDataReader reader)
        {
        }

        public void Serialize(IDataWriter writer)
        {
        }
    }
}
