using Rathalos.Core.Utils.Consoles;
using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
    public abstract record Message
    {
        private static uint _seqId;
        public virtual bool IsTdpu => false;
        public abstract ushort ProtocolMessageId
        {
            get;
        }

        public void Unpack(IDataReader reader)
        {
            Deserialize(reader);
        }

        public void Pack(IDataWriter writer)
        {
            BigEndianWriter bodyWriter = new BigEndianWriter();
            Serialize(bodyWriter);

            WriteHeader(writer, (uint)bodyWriter.BaseStream.Length);
            writer.WriteBytes(bodyWriter.Data);
        }

        protected virtual void WriteHeader(IDataWriter writer, uint bodyLen)
        {
            writer.WriteUShort(ProtocolMessageId);
            writer.WriteUShort(RawMessage.HEADER_SIZE);
            writer.WriteUInt(bodyLen);
            writer.WriteUInt(_seqId++);
            writer.WriteUInt(0); // NoUse
        }

        public abstract void Serialize(IDataWriter writer);

        public abstract void Deserialize(IDataReader reader);



        public override string ToString()
        {
            var messageName = GetType().Name;

            return ProtocolMessageId switch
            {
                _ => new ConsoleFormat(messageName, ConsoleAttributes.Bold)
            };
        }
    }
}