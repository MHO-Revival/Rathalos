using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Tqqapi
{
    public sealed class TqqMessage<TExt, TBody> : ITqqMessage
        where TExt : TPDUExt, new()
        where TBody : new()
    {
        public int ProtocolId => Extension.ProtocolId;
        public TExt Extension { get; set; }
        public TBody Body { get; set; }

        public void DeserializeBody(IDataReader reader)
        {
            Body = Activator.CreateInstance<TBody>();
            // call with reflection the Deserialize method of TBody
            var deserializeMethod = typeof(TBody).GetMethod("Deserialize");
            if (deserializeMethod != null)
            {
                deserializeMethod.Invoke(Body, new object[] { reader });
            }
        }
    }
}
