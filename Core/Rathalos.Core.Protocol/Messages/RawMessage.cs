using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
    public class RawMessage
    {
        public const ushort HEADER_SIZE = 16;
        public const ushort TPDU_HEADER_LENGTH = 12;
        public byte Magic { get; set; }
        public byte Version { get; set; }
        public TPDU_CMD Id { get; set; }
        public byte EncryptedHeaderLen { get; set; }
        public int HeaderExtensionLength { get; set; }
        public int BodyLength { get; set; }
        public virtual bool Parse(IDataReader reader)
        {
            var position = reader.Position;
            if (reader.BytesAvailable < HEADER_SIZE)
                return false;

            Magic = reader.ReadByte();
            Version = reader.ReadByte();
            Id = (TPDU_CMD)reader.ReadByte();
            EncryptedHeaderLen = reader.ReadByte();
            HeaderExtensionLength = reader.ReadInt() - TPDU_HEADER_LENGTH;
            BodyLength = reader.ReadInt();

            if (Magic != TqqapiConstants.TPDU_MAGIC)
                throw new Exception($"Invalid TPDU Magic {Magic} should be {TqqapiConstants.TPDU_MAGIC}");
            if (Version != TqqapiConstants.TPDU_VERSION)
                throw new Exception($"Invalid TPDU Version {Version} should be {TqqapiConstants.TPDU_VERSION}");
            
            if (HeaderExtensionLength + BodyLength > reader.BytesAvailable)
            {
                reader.Seek(position, System.IO.SeekOrigin.Begin);
                return false;
            }

            return true;
        }
    }
}
