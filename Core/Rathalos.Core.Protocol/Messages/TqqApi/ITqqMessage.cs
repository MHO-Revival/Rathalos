using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Tqqapi
{
    public interface ITqqMessage
    {
        public int ProtocolId { get; }
        void DeserializeBody(IDataReader reader);
    }
}
