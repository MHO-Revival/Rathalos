using Microsoft.EntityFrameworkCore;
using Rathalos.Core.ORM;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.IO;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Network;
using System.Text;

namespace Rathalos.Servers.World.Handlers.Tqqapi.Handlers
{
    public sealed class AuthHandler : IMessageHandler
    {
        private readonly RathalosDbContext _database;
        private readonly ILogger<AuthHandler> _logger;

        public AuthHandler(RathalosDbContext database, ILogger<AuthHandler> logger)
        {
            _database = database;
            _logger = logger;
        }

        [TqqapiPacketHandler<TPDUExtAuthInfo>]
        public async Task HandleAuthentication(WorldClient client, TPDUExtAuthInfo message, byte[] body)
        {
            (uint uin, string passHash) = message.AuthData switch
            {
                TQQUnifiedAuthInfo ua => (ua.Uin, Encoding.UTF8.GetString([.. ua.SigInfo])),
                TPDUExtAuthDataAuthQQV1 v1 => (v1.Uin, Encoding.UTF8.GetString([.. v1.SignData])),
                TPDUExtAuthDataAuthQQV2 v2 => (v2.Uin, Encoding.UTF8.GetString([.. v2.SignData])),
                _ => throw new NotImplementedException($"Unsupported {message.AuthData.GetType().Name} as AuthData type"),
            };

            var account = await _database.Query<AccountRecord>(x => x.Id == uin && x.PasswordHash == passHash.Replace("\0", "")).FirstOrDefaultAsync();

            if (account == null)
            {
                _logger.LogError("Authentication failed for UIN {uin}", uin);

                client.Send(new TPDUExtStop
                {
                    StopReason = TPDU_STOP_REASON.TPDU_REASON_AUTH_FAIL
                });
                return;
            }

            client.Account = account;
            _logger.LogInformation("Authentication successful for UIN {uin}", uin);
            client.SyncGuid = Guid.NewGuid();
            client.Send(new TPDUExtSyn
            {
                EncryptSynInfo = client.Crypto.Encrypt(client.SyncGuid.ToByteArray())
            });
        }

        [TqqapiPacketHandler<TPDUExtSynAck>]
        public async Task HandleSyncAck(WorldClient client, TPDUExtSynAck message, byte[] body)
        {
            _logger.LogInformation("Client UIN {uin} synchronized successfully.", client.Account!.Id);
            if (message.EncryptSynInfo == null)
            {
                var synInfo = client.Crypto.Decrypt(message.EncryptSynInfo);
                if (synInfo.SequenceEqual(client.SyncGuid.ToByteArray()))
                {
                    _logger.LogError("Synchronization failed for UIN {uin}: Sync GUID mismatch.", client.Account.Id);
                    client.Send(new TPDUExtStop
                    {
                        StopReason = TPDU_STOP_REASON.TPDU_REASON_REASON_SYNACK_FAIL
                    });
                    return;
                }
            }

            var identWriter = new BigEndianWriter();
            TQQUserIdent ident = new TQQUserIdent
            {
                Pos = 0,
                Uin = (uint)client.Account.Id,
                Ident = [.. client.Account.PasswordHash.Take(TqqapiConstants.TQQ_IDENT_LEN)],
            };
            ident.Serialize(identWriter);

            client.Send(new TPDUExtIdent
            {
                EncryptIdent = client.Crypto.Encrypt(identWriter.Data)
            });

            var skey = Guid.NewGuid().ToByteArray();

            client.Send(new TPDUExtChgSkey
            {
                EncryptSkey = client.Crypto.Encrypt(skey),
            });

            client.Crypto.SetKey(skey);
        }
    }
}
