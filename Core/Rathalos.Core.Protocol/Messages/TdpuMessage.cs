using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rathalos.Core.Protocol.Messages
{
    public abstract record TdpuMessage : Message
    {
        public override bool IsTdpu => true;

        protected override void WriteHeader(IDataWriter writer, uint bodyLen)
        {
            
        }
    }
}
