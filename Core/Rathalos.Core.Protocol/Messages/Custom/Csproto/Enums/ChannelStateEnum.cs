using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum ChannelStateEnum
    {
        Idle = 1,
        Normal = 2,
        Busy = 3,
        Full = 4,
        Maintenance = 5
    }
}
