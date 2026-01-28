using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Tqqapi.Custom
{
    public class TpduCloseConnection : TPDUExt
    {
        public const TPDU_CMD ProtocolIdConst = TPDU_CMD.TPDU_CMD_CLOSE;
        public int ProtocolId => (int)ProtocolIdConst;

        public void Deserialize(IDataReader reader)
        {
        }

        public void Serialize(IDataWriter writer)
        {
        }
    }
}
