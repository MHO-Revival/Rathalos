using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.World.Core.Network;
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

            var result = CharacterService.Instance.CreateCharacter(client, message);
            SendCharacterCreateResponse(client, result);
            if (result == CreateErrorResultEnum.OK)
                SendCharacterListResponse(client);
        }

        [GamePacketHandler<CSDeleteRoleReq>]
        public async Task HandleCharacterDeleteRequest(WorldClient client, CSDeleteRoleReq message)
        {
            _logger.LogInformation($"Received character delete request from account {client.Account.Id} for character index {message.RoleIndex}.");
            CharacterService.Instance.DeleteCharacter(client, message.RoleIndex);

            SendCharacterDeleteResponse(client);
            SendCharacterListResponse(client);
        }

        [GamePacketHandler<CSSelectRoleReq>]
        public async Task HandleCharacterSelectRequest(WorldClient client, CSSelectRoleReq message)
        {
            _logger.LogInformation($"Received character select request from account {client.Account.Id} for character index {message.RoleIndex}.");
            
        }

        public static void SendCharacterDeleteResponse(WorldClient client)
        {
            client.Send(new CSDeleteRoleRsp
            {
                RoleState = 0,
                RoleStateEndLeftTime = 0,
            });
        }

        public static void SendCharacterCreateResponse(WorldClient client, CreateErrorResultEnum errorCode)
        {
            client.Send(new CSPkgBodyCreateRoleRsp
            {
                BanTime = 0,
                ErrNo = (uint)errorCode,
                LastLoinRoleIndex = 0,
                RoleList = new CSRoleList
                {
                    Role = []
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
