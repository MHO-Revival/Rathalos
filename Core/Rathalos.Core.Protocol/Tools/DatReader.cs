using Rathalos.Core.Utils.Cryptography;
using Rathalos.Core.Utils.IO;
using System.Text;

namespace Rathalos.Core.Protocol.Tools
{
    public sealed class DatReader
    {
        private const uint DatHeaderLength = 0x10;
        private const uint DatMagic = 0x43;

        private readonly byte[] _encContent;

        public DatReader(byte[] encContent)
        {
            this._encContent = encContent;
        }

        public string Content { get; private set; }

        public static DatReader Create(byte[] encContent)
        {
            var datFile = new DatReader(encContent);
            datFile.Read();
            return datFile;
        }

        private void Read()
        {
            var reader = new FastLittleEndianReader(_encContent);
            var headLen = reader.ReadUInt();
            if (headLen != DatHeaderLength)
                throw new Exception($"Invalid dat file : Header length mismatch {headLen} != {DatHeaderLength}");
            
            var magic = reader.ReadUInt();
            if (magic != DatMagic)
                throw new Exception($"Invalid dat file : Magic mismatch {magic} != {DatMagic}");

            var totalCountSize = reader.ReadUInt();
            var unk = reader.ReadUInt();

            if (totalCountSize - 16 != reader.BytesAvailable)
                throw new Exception($"Invalid dat file : Total content len mismatch {totalCountSize - 16} != {reader.BytesAvailable}");

            var fileContent = reader.ReadBytes((int)reader.BytesAvailable);
            Content = Encoding.UTF8.GetString(DatCrypto.Decrypt(fileContent));
        }
    }
}
