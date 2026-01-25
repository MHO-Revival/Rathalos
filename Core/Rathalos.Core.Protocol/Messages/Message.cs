using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Cryptography;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
    public sealed record Message
    {
        private static uint _seq = 0;

        private TPDUFrame _frame = new();
        private TPDUExt _headerExtension;
        private CSPkgBody _csPacketBody;
        private readonly byte[] _key;

        public Message() { }

        public Message(TPDUExt headExtension, CSPkgBody csPacket, byte[] key)
        {
            _headerExtension = headExtension;
            _csPacketBody = csPacket;
            _key = key;
        }

        public Message(TPDUExt headExtension, byte[] key) : this(headExtension, null, key)
        {
        }

        public Message(CSPkgBody csPacket, byte[] key) : this(null, csPacket, key)
        {
        }

        public void Unpack(IDataReader reader)
        {
            _frame.Deserialize(reader);
        }

        public void Pack(IDataWriter writer)
        {
            var packetBodyWriter = new BigEndianWriter();
            _csPacketBody?.Serialize(packetBodyWriter);
            if (_csPacketBody != null)
            {
                var packet = new CSPkg
                {
                    Head = new CSPkgHead()
                    {
                        BodyLen = (uint)packetBodyWriter.Data.Length,
                        CmdID = (CS_CMD_ID)_csPacketBody.ProtocolId,
                        HeadLen = (ushort)RawMessage.HEADER_SIZE,
                        NoUse = 0,
                        SeqID = _seq++
                    },
                    Body = _csPacketBody
                };
                var bodyWriter = new BigEndianWriter();
                packet.Serialize(bodyWriter);
                var bodyBytes = new TpduCryptoAes128(_key).Encrypt(bodyWriter.Data);
                _frame.Body = bodyBytes;
            }
            else
            {
                _frame.Body = [];
            }

            var headerExtensionWriter = new BigEndianWriter();
            _headerExtension?.Serialize(headerExtensionWriter);

            _frame.Head = new TPDUHead
            {
                Base = new TPDUBase
                {
                    Cmd = (TPDU_CMD)_headerExtension.ProtocolId,
                    HeadLen = headerExtensionWriter.Data.Length + RawMessage.TPDU_HEADER_LENGTH,
                    BodyLen = packetBodyWriter.Data.Length,
                    EncHeadLen = 0,
                    Magic = TqqapiConstants.TPDU_MAGIC,
                    Version = TqqapiConstants.TPDU_VERSION,
                },
                Ext = _headerExtension,
            };

           _frame.Serialize(writer);
        }
    }
}