using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rathalos.Core.Protocol
{
    public interface IDataProtocol
    {
        public int ProtocolId { get; }
    }
}
