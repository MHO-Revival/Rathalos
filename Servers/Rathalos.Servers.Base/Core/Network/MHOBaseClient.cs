using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.IO;
using Microsoft.Extensions.Logging;
using System.Net.Sockets;
using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Utils.Cryptography;

namespace Rathalos.Servers.Base.Core.Network
{
    public abstract class MHOBaseClient : BaseClient
    {
        public byte[] Key { get; set; } = null;
        protected MHOBaseClient(Socket socket, ILogger logger) : base(socket, logger)
        {
        }

        protected override async Task OnDataReceived(IDataReader reader)
        {
            var rawMessage = new RawMessage();
            while (rawMessage.Parse(reader) && !_tokenSource.IsCancellationRequested)
            {
                var headExtensionReader = new BigEndianReader(reader.ReadBytes(rawMessage.HeaderExtensionLength));
                TPDUExt ext = ProtocolTypeManager.Get<TPDUExt>(rawMessage.Id);
                if (ext is not null)
                {
                    ext?.Deserialize(headExtensionReader);

                    _logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) [TPDU] {Name}",
                        ConsoleFormat.ReceivePacket, this, ext.GetType().Name);

                    await OnMessageReceived(ext);
                }
                var data = reader.ReadBytes(rawMessage.BodyLength);
                var decryptedBody = new TpduCryptoAes128(Key).Decrypt(data);
                var csPacket = new CSPkg();
                csPacket.Deserialize(new BigEndianReader([.. decryptedBody.Skip(rawMessage.EncryptedHeaderLen)]));
                _logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) [Game] {Name}",
                     ConsoleFormat.ReceivePacket, this, ext.GetType().Name);

                await OnMessageReceived(csPacket.Body);
            }

        }

        protected abstract Task OnMessageReceived(TPDUExt message);
        protected abstract Task OnMessageReceived(CSPkgBody message);

    }
}
