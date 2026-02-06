using System.Security.Cryptography;

namespace Rathalos.Core.Utils.Cryptography
{
    public static class DatCrypto
    {
        private static byte[] DatKey = new byte[16]
        {
            0x01, 0x09, 0x08, 0x00, 0x00, 0x02, 0x01, 0x06, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11
        };
        public static byte[] Decrypt(byte[] data)
        {
            Aes aes = Aes.Create();
            aes.Mode = CipherMode.ECB;
            aes.Padding = PaddingMode.None;
            aes.Key = DatKey;
            ICryptoTransform encryptor = aes.CreateEncryptor();
            return encryptor.TransformFinalBlock(data, 0, data.Length);
        }
    }
}
