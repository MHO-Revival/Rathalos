using Microsoft.Extensions.Logging;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.IO;
using System.Net.Sockets;

namespace Rathalos.Servers.Base.Core.Network
{
    public abstract class MHOBaseClient : BaseClient
    {
        protected MHOBaseClient(Socket socket, ILogger logger) : base(socket, logger)
        {
        }

        protected override async Task OnDataReceived(IDataReader reader)
        {
            var rawMessage = new RawMessage();
            while (rawMessage.Parse(reader) && !_tokenSource.IsCancellationRequested)
            {
                if (rawMessage.Frame.Head.Ext is not null)
                {
                    _logger.LogInformation("{ReceivePacket} ({MHOBaseClient}) [TPDU] {Name}",
                        ConsoleFormat.ReceivePacket, this, rawMessage.Frame.Head.Ext.GetType().Name);

                    var data = rawMessage.Frame.Body.ToArray();
                    var decryptedBody = _crypto.Decrypt(data);
                    var decryptedReader = new BigEndianReader(decryptedBody);
                    if (rawMessage.Frame.Head.Base.EncHeadLen > 0)
                    {
                        var encHead = new TPDUEncHead();
                        encHead.Deserialize(decryptedReader);
                    }

                    await OnMessageReceived(rawMessage.Frame.Head.Ext, decryptedReader);
                }
            }

        }

        protected abstract Task OnMessageReceived(TPDUExt message, BigEndianReader bodyReader);
    }
}
