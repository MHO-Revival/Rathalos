///
/// TdpuCrypto.cs - Abstract base class for TDP-U encryption/decryption with TSF4G padding.
/// has been designed on https://github.com/sebastian-heinz/Arrowgene.MonsterHunterOnline
///
using NLog;
using Rathalos.Core.Utils.Extensions;
using System;
using System.Security.Cryptography;

namespace Rathalos.Core.Utils.Cryptography;

public abstract class TdpuCrypto
{
    protected static readonly Logger Logger = LogManager.GetCurrentClassLogger();
    public abstract ConnectionSecureEncodingType EncodingType { get; }

    private const int Tsf4gPaddingLen = 6;

    public abstract TdpuCrypto GetSafeInstance();
    public abstract byte[] Encrypt(byte[] plain);
    public abstract byte[] Decrypt(byte[] cipher);

    protected byte[] Tsf4gPad(byte[] payload, int blockSize = 16)
    {
        int rem = payload.Length % blockSize;
        int req = blockSize - rem;
        if (req < Tsf4gPaddingLen)
        {
            // require additional block to fit tsf4g
            req += blockSize;
        }

        if (req > byte.MaxValue || req < byte.MinValue)
        {
            Logger.Error(
                $"required padding of:{req} is out of range for payload:{Environment.NewLine + payload.HexDump()}");
            return payload;
        }

        byte padding = (byte)req;
        int zeroBytesLength = padding - Tsf4gPaddingLen;
        int paddedLength = payload.Length + zeroBytesLength + Tsf4gPaddingLen;
        byte[] padded = new byte[paddedLength];

        Buffer.BlockCopy(payload, 0, padded, 0, payload.Length);
        int paddedOffset = padded.Length - Tsf4gPaddingLen;
        padded[paddedOffset++] = 0x74;
        padded[paddedOffset++] = 0x73;
        padded[paddedOffset++] = 0x66;
        padded[paddedOffset++] = 0x34;
        padded[paddedOffset++] = 0x67;
        padded[paddedOffset] = padding;

        return padded;
    }

    protected byte[] Tsf4gUnPad(byte[] payload)
    {
        // todo sanity check block size
        // todo sanity check tsf4g string exists

        byte padding = payload[^1];
        if (padding > payload.Length)
        {
            Logger.Error(
                $"padding of:{padding} is larger than payload size:{payload.Length} for payload: {Environment.NewLine + payload.HexDump()}");
            return payload;
        }

        int unPaddedLength = payload.Length - padding;
        byte[] unPadded = new byte[unPaddedLength];
        Buffer.BlockCopy(payload, 0, unPadded, 0, unPadded.Length);
        return unPadded;
    }
}