using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
    public class RawMessage
    {
        public const ushort HEADER_SIZE = 16;
        public const ushort TPDU_HEADER_LENGTH = 12;
        
        public TPDUFrame Frame { get; set; }
        public virtual bool Parse(IDataReader reader)
        {
            var position = reader.Position;
            if (reader.BytesAvailable < HEADER_SIZE)
                return false;
            try
            {
                TPDUFrame frame = new TPDUFrame();
                frame.Deserialize(reader);

                if (frame.Head.Base.Magic != TqqapiConstants.TPDU_MAGIC)
                    throw new Exception($"Invalid TPDU Magic {frame.Head.Base.Magic} should be {TqqapiConstants.TPDU_MAGIC}");
                if (frame.Head.Base.Version != TqqapiConstants.TPDU_VERSION)
                    throw new Exception($"Invalid TPDU Version {frame.Head.Base.Version} should be {TqqapiConstants.TPDU_VERSION}");

                Frame = frame;

                return true;
            }
            catch
            {
                reader.Seek(position, System.IO.SeekOrigin.Begin);
                return false;
            }
        }
    }
}
