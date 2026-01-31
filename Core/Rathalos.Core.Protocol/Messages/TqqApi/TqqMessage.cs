using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Tqqapi
{
    public sealed class TqqMessage<TExt, TBody> : ITqqMessage
        where TExt : TPDUExt
    {
        public int ProtocolId => Extension.ProtocolId;
        public TExt Extension { get; set; }
        public TBody Body { get; set; }

        public void Deserialize(IDataReader reader)
        {
            Extension = Activator.CreateInstance<TExt>();
            Extension.Deserialize(reader);
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
