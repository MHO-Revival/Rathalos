using Microsoft.EntityFrameworkCore;
using Rathalos.Core.ORM;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Handlers.Tqqapi
{
    public sealed class AuthHandler : IMessageHandler
    {
        private readonly RathalosDbContext _database;

        public AuthHandler(RathalosDbContext database)
        {
            _database = database;
        }

        [TqqapiPacketHandler<TPDUExtAuthInfo>]
        public async Task HandleAuthentication(WorldClient client, TPDUExtAuthInfo message)
        {
            (uint uin, string passHash) = message.AuthData switch
            {
                TQQUnifiedAuthInfo ua => (ua.Uin, BitConverter.ToString([.. ua.SigInfo])),
                TPDUExtAuthDataAuthQQV1 v1 => (v1.Uin, BitConverter.ToString([.. v1.SignData])),
                TPDUExtAuthDataAuthQQV2 v2 => (v2.Uin, BitConverter.ToString([.. v2.SignData])),
                _ => throw new NotImplementedException($"Unsupported {message.AuthData.GetType().Name} as AuthData type"),
            };

            var account = await _database.Query<AccountRecord>(x => x.Id == uin && x.PasswordHash == passHash).FirstOrDefaultAsync();

            if (account == null)
            {
                LoggingService.Instance.LogError($"Authentication failed for UIN {uin}");

                client.Send(new TPDUExtStop
                {
                    StopReason = TPDU_STOP_REASON.TPDU_REASON_AUTH_FAIL
                });
                return;
            }

            client.Account = account;
            LoggingService.Instance.LogInformation($"Authentication successful for UIN {uin}");
            client.SyncGuid = Guid.NewGuid();
            client.Send(new TPDUExtSyn
            {
                EncryptSynInfo = client.Crypto.Encrypt(client.SyncGuid.ToByteArray())
            });
        }

        [TqqapiPacketHandler<TPDUExtSynAck>]
        public async Task HandleSyncAck(WorldClient client, TPDUExtSynAck message)
        {
            // At this point, authentication is complete
            LoggingService.Instance.LogInformation($"Client UIN {client.Account?.Id} synchronized successfully.");
            // Proceed with post-authentication logic, e.g., sending character list
            if(message.EncryptSynInfo == null || !message.EncryptSynInfo.SequenceEqual(client.SyncGuid.ToByteArray()))
            {
                LoggingService.Instance.LogError($"Synchronization failed for UIN {client.Account?.Id}: Sync GUID mismatch.");
                client.Send(new TPDUExtStop
                {
                    StopReason = TPDU_STOP_REASON.TPDU_REASON_REASON_SYNACK_FAIL
                });
                return;
            }



            await Task.CompletedTask;
        }
    }
}
