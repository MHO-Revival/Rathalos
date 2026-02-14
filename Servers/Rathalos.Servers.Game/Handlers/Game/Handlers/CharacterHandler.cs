using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Services;

namespace Rathalos.Servers.World.Handlers.Game.Handlers
{
    public sealed class CharacterHandler : IMessageHandler
    {
        private readonly ILogger<CharacterHandler> _logger;

        public CharacterHandler(ILogger<CharacterHandler> logger)
        {
            _logger = logger;
        }

        [GamePacketHandler<CSListRoleReq>]
        public async Task HandleCharacterListRequest(WorldClient client, CSListRoleReq message)
        {
            _logger.LogInformation($"Received character list request from account {client.Account.Id}.");
            SendCharacterListResponse(client);
        }

        [GamePacketHandler<CSRoleCreateInfo>]
        public async Task HandleCharacterCreateRequest(WorldClient client, CSRoleCreateInfo message)
        {
            _logger.LogInformation($"Received character create request from account {client.Account.Id} for character name '{message.Name}'.");
            //var initInfo = RathalosDbService.Instance.Query<>
            //var record = new CharacterRecord
            //{
            //    Name = message.Name,
            //    AccountId = client.Account.Id,
            //    Account = client.Account,
            //    AvatarSetId = 0,
            //    Experience = 0,
            //}
            CharacterService.Instance.CreateCharacter(client, message);
            SendCharacterCreateResponse(client, 0);
        }

        public static void SendCharacterCreateResponse(WorldClient client, int errorCode)
        { 
            client.Send(new CSPkgBodyCreateRoleRsp
            {
                BanTime = client.Account.IsBannedUntil?.GetUnixTimeStamp() ?? 0,
                ErrNo = 0,
                LastLoinRoleIndex = client.GetLastSelectedCharacterId(),
                RoleList = new CSRoleList
                {
                    Role = [.. client.Characters.Select(x => x.GetCSRoleBaseInfo())]
                }
            });
        }

        public static void SendCharacterListResponse(WorldClient client)
        {
            client.Send(new CSPkgBodyListRoleRsp
            {
                BanTime = client.Account.IsBannedUntil?.GetUnixTimeStamp() ?? 0,
                ErrNo = 0,
                LastLoinRoleIndex = client.GetLastSelectedCharacterId(),
                RoleList = new CSRoleList
                {
                    Role = [.. client.Characters.Select(x => x.GetCSRoleBaseInfo())]
                }
            });
        }
    }
}
