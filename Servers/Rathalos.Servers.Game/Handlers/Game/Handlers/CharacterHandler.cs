using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Network;

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
            //client.Send(new CSPkgBodyListRoleRsp
            //{
            //    BanTime = 0,
            //    ErrNo = 0,
            //    LastLoinRoleIndex = 0,
            //    RoleList = new CSRoleList()
            //    {
            //        Role = [
            //            new CSRoleBaseInfo
            //            {
            //                Equip
            //            }
            //        ]
            //    }
            //});
        }
    }
}
