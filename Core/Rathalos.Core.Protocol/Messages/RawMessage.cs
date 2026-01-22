using Rathalos.Core.Utils.IO;

namespace Rathalos.Core.Protocol.Messages
{
	public class RawMessage
	{
		public const ushort HEADER_SIZE = 16;
		public const ushort TDPU_HEADER_LENGTH = 12;
		public ushort HeaderLength { get; set; }
        public ushort MessageId { get; set; }

		public uint InstanceId { get; set; }
		public uint NoUse { get; set; }
        public byte[] RawBody { get; set; }
		public virtual bool Parse(IDataReader reader)
		{
			var position = reader.Position;
			if (reader.BytesAvailable < HEADER_SIZE)
				return false;

			MessageId = reader.ReadUShort();
			HeaderLength = reader.ReadUShort();
			var messageLength = reader.ReadUInt();
            InstanceId = reader.ReadUInt();
			NoUse = reader.ReadUInt();

			if (reader.BytesAvailable < messageLength)
			{
				reader.Seek(position, SeekOrigin.Begin);
				return false;
			}

			if (messageLength > 0)
				RawBody = reader.ReadBytes(messageLength);
			else
				RawBody = [];

			return true;
		}
	}
}
