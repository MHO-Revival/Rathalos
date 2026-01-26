using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Handlers.Tqqapi
{
    public sealed class AuthHandler : IMessageHandler
    {
        [TqqapiPacketHandler<TPDUExtAuthInfo>]
        public Task HandleAuthentication(WorldClient client, TPDUExtAuthInfo message)
        {
            string? passwordHash = null;
            if (message.AuthData is TQQUnifiedAuthInfo unifiedAuth)
            {
                passwordHash = BitConverter.ToString(unifiedAuth.SigInfo.ToArray());
            }
            else if (message.AuthData is TPDUExtAuthDataAuthQQV1 qqv1)
            {
                LoggingService.Instance.LogError($"TqqAuthInfo not supported");
                // TODO send error rsp
                return Task.CompletedTask;
            }
            else if(message.AuthData is TPDUExtAuthDataAuthQQV2 guest)
            {
                LoggingService.Instance.LogError($"Guest AuthData not supported");
                // TODO send error rsp
                return Task.CompletedTask;
            }
            else
            {
                LoggingService.Instance.LogError($"Requested AuthData not supported");
                // TODO send error rsp
                return Task.CompletedTask;
            }

            //client.Account = new Core.Accounts.WorldAccount()
            //{
            //    Uin = message.AuthData is TQQUnifiedAuthInfo ua ? ua.Uin :
            //          message.AuthData is TPDUExtAuthDataAuthQQV1 v1 ? v1.Uin :
            //          message.AuthData is TPDUExtAuthDataAuthQQV2 v2 ? v2.Uin : 0,
            //    PasswordHash = passwordHash,
            //};

            return Task.CompletedTask;
        }
    }
}
