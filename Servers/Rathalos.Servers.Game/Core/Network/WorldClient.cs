using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Cryptography;
using Rathalos.Core.Utils.IO;
using Rathalos.Servers.Base.Core.Network;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Game.Actors;
using Rathalos.Servers.World.Handlers;
using Rathalos.Servers.World.Services;
using System.Net.Sockets;

namespace Rathalos.Servers.World.Core.Network
{
    public sealed class WorldClient : MHOBaseClient
    {
        public WorldClient(Socket socket, ILogger logger) : base(socket, logger)
        {
            _crypto = new TpduCryptoAes128();
        }

        public AccountRecord Account { get; internal set; }
        public Guid SyncGuid { get; internal set; }
        public List<Character> Characters { get; internal set; } = [];
        public Character SelectedCharacter { get; internal set; }

        public uint GetLastSelectedCharacterId()
        {
            var lastUsedCharacter = Characters.OrderByDescending(c => c.Record.LastLogin).FirstOrDefault();
            if (lastUsedCharacter is null)
                return 0;

            return (uint)Characters.IndexOf(lastUsedCharacter);
        }

        protected override async Task OnMessageReceived(TPDUExt message, BigEndianReader bodyReader)
        {
            await TqqapiPacketHandler.Instance.HandleMessage(this, message, bodyReader);
        }

        public override void OnDisconnected()
        {
            Save();
            base.OnDisconnected();
        }

        public void Save()
        {

            RathalosDbService.Instance.ExecuteInTransaction(db =>
            {
                if (Account is not null)
                    db.Save(Account);

                SelectedCharacter?.Save(db);
            });
        }
    }
}
