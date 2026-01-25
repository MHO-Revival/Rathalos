using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
    public sealed record Message
    {
        private TPDUFrame _frame = new();

        public Message(TPDUExt extension)
        {

        }

        public void Unpack(IDataReader reader)
        {
            _frame.Deserialize(reader);
        }

        public void Pack(IDataWriter writer)
        {
           _frame.Serialize(writer);
        }
    }
}