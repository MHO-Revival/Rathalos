using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Servers.World.Handlers.Tqqapi
{
    public sealed class AuthHandler : IMessageHandler
    {
        [PacketHandler<TPDUExtAuthInfo>]
        public Task HandleAuthentication(WorldClient client, TPDUExtAuthInfo message)
        {
            return Task.CompletedTask;
        }
    }
}
