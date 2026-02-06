using System.Security.Cryptography;

namespace Rathalos.Core.Utils.Cryptography
{
    public class CryXmlCrypto
    {
        // Constants defining the encryption structure
        private const int BLOCK_SIZE = 129;
        private const int PART1_SIZE = 64;  // First 64 bytes of input
        private const int PART2_SIZE = 65;  // Remaining 65 bytes of input
        private const int SWAP_OFFSET = 65; // Where Part 1 gets moved to

        private static readonly byte[] KEY_TABLE_0 = new byte[65]
        {
        0x09, 0x40, 0x48, 0x19, 0xC1, 0x8F, 0x83, 0xF5, 0x60, 0x09, 0x6F, 0x14, 0x0F, 0xBE, 0x51, 0xEA,
        0x7A, 0x81, 0x08, 0xB4, 0x76, 0xB6, 0x1A, 0x91, 0x5A, 0x74, 0x70, 0xC9, 0xDD, 0x83, 0xE5, 0x04,
        0x9F, 0x48, 0xC8, 0x48, 0xA0, 0x9E, 0x9B, 0x8F, 0x8B, 0x0F, 0x9C, 0x01, 0x94, 0x34, 0x62, 0x29,
        0x99, 0xB7, 0xDC, 0x77, 0xFC, 0x87, 0xB2, 0x39, 0xFB, 0x8F, 0x6D, 0xD6, 0x51, 0x97, 0x6C, 0xD8,
        0x91
        };

        private static readonly byte[] KEY_TABLE_1 = new byte[65]
        {
        0xC7, 0xAB, 0x19, 0x5A, 0x77, 0x88, 0xFA, 0x21, 0xAB, 0x5D, 0x7D, 0x33, 0xAA, 0x3A, 0x75, 0x0A,
        0xF9, 0x7C, 0x76, 0xB6, 0x6A, 0xE3, 0x05, 0xD5, 0x77, 0xCF, 0xF2, 0xFB, 0x2D, 0xB2, 0x1B, 0x29,
        0x17, 0x50, 0x04, 0xDA, 0x4A, 0xC7, 0x8C, 0x31, 0x4A, 0x51, 0xA8, 0x3B, 0x9E, 0xE5, 0xDE, 0x4B,
        0x75, 0x7C, 0x47, 0x54, 0xFB, 0x03, 0x24, 0xA6, 0x13, 0x4A, 0xCB, 0xE9, 0x5E, 0x34, 0xE1, 0xA1,
        0x80
        };

        /// <summary>
        /// Returns a new byte array containing the decrypted data. 
        /// The original input buffer is not modified.
        /// </summary>
        public static byte[] Decrypt(byte[] inputBuffer)
        {
            // Safety checks
            if (inputBuffer == null) return null;
            if (inputBuffer.Length == 0) return new byte[0];

            // Create the copy we will modify and return
            byte[] outputBuffer = new byte[inputBuffer.Length];

            int totalBytes = inputBuffer.Length;
            int currentOffset = 0;

            // ---------------------------------------------------------
            // PHASE 1: Process Full Blocks (129 bytes)
            // ---------------------------------------------------------
            while (totalBytes >= BLOCK_SIZE)
            {
                // SWAP LOGIC:
                // Input [0..63]   -> XOR Table0 -> Output [65..128] (Tail)
                // Input [64..128] -> XOR Table1 -> Output [0..64]   (Head)

                // 1. Process the "Head" (Input Part 1 -> Output Tail)
                for (int i = 0; i < PART1_SIZE; i++)
                {
                    byte inputByte = inputBuffer[currentOffset + i];
                    outputBuffer[currentOffset + SWAP_OFFSET + i] = (byte)(inputByte ^ KEY_TABLE_0[i]);
                }

                // 2. Process the "Tail" (Input Part 2 -> Output Head)
                for (int i = 0; i < PART2_SIZE; i++)
                {
                    byte inputByte = inputBuffer[currentOffset + PART1_SIZE + i];
                    outputBuffer[currentOffset + i] = (byte)(inputByte ^ KEY_TABLE_1[i]);
                }

                currentOffset += BLOCK_SIZE;
                totalBytes -= BLOCK_SIZE;
            }

            // ---------------------------------------------------------
            // PHASE 2: Process Remainder (If any bytes left)
            // ---------------------------------------------------------
            if (totalBytes > 0)
            {
                // CASE A: Small Remainder (<= 65 bytes)
                // We only have enough data to fill the "Head" of the output (using Table 1).
                // The "Tail" is skipped because the input file ends abruptly.
                if (totalBytes <= PART2_SIZE)
                {
                    for (int i = 0; i < totalBytes; i++)
                    {
                        byte inputByte = inputBuffer[currentOffset + i];
                        outputBuffer[currentOffset + i] = (byte)(inputByte ^ KEY_TABLE_1[i]);
                    }
                }
                // CASE B: Large Remainder (> 65 bytes)
                // We have enough data to fill the "Head" AND start filling the "Tail".
                else
                {
                    // In the remainder logic, the data is laid out sequentially in the input,
                    // but we map it to the "swapped" positions in the output.

                    // Calculate how many bytes go into the "Tail" (Table 0 logic)
                    int tailBytesCount = totalBytes - PART2_SIZE;

                    // 1. Decrypt the "Tail" bytes (Input starts at 0 -> Output at 65)
                    for (int i = 0; i < tailBytesCount; i++)
                    {
                        byte inputByte = inputBuffer[currentOffset + i];
                        outputBuffer[currentOffset + SWAP_OFFSET + i] = (byte)(inputByte ^ KEY_TABLE_0[i]);
                    }

                    // 2. Decrypt the "Head" bytes (Input continues after Tail -> Output at 0)
                    for (int i = 0; i < PART2_SIZE; i++)
                    {
                        byte inputByte = inputBuffer[currentOffset + tailBytesCount + i];
                        outputBuffer[currentOffset + i] = (byte)(inputByte ^ KEY_TABLE_1[i]);
                    }
                }
            }

            return outputBuffer;
        }
    }
}
