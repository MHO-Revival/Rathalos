using System;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;

namespace Rathalos.CLI.Launcher
{


    public unsafe class MemoryMapper
    {
        // =============================================================
        // 1. Native Constants & Imports
        // =============================================================
        private const uint PAGE_READWRITE = 0x04;
        private const uint FILE_MAP_WRITE = 0x0002;
        private const int INVALID_HANDLE_VALUE = -1;
        private const uint SDDL_REVISION_1 = 1;

        // Using CreateFileMappingA (ANSI) to match C++ code exactly
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
        private static extern IntPtr CreateFileMappingA(
            IntPtr hFile,
            IntPtr lpFileMappingAttributes, // Passed as NULL in C++
            uint flProtect,
            uint dwMaximumSizeHigh,
            uint dwMaximumSizeLow,
            string lpName);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern IntPtr MapViewOfFile(
            IntPtr hFileMappingObject,
            uint dwDesiredAccess,
            uint dwFileOffsetHigh,
            uint dwFileOffsetLow,
            UIntPtr dwNumberOfBytesToMap);

        [DllImport("advapi32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool ConvertStringSecurityDescriptorToSecurityDescriptor(
            string StringSecurityDescriptor,
            uint StringSDRevision,
            out IntPtr SecurityDescriptor,
            out uint SecurityDescriptorSize);

        [DllImport("kernel32.dll")]
        private static extern uint GetLastError();
        // =============================================================
        // 2. The MapMemory Function
        // =============================================================
        public static nint MapMemory(string pMapName, uint pMapSize)
        {
            // 1. CreateFileMappingA
            IntPtr sharedMemHandle = CreateFileMappingA(
                new IntPtr(INVALID_HANDLE_VALUE),
                IntPtr.Zero, // NULL
                PAGE_READWRITE,
                0,
                pMapSize,
                pMapName
            );

            if (sharedMemHandle == IntPtr.Zero)
            {
                uint err = GetLastError();
                // Note: GetLastErrorAsString() helper is omitted as it wasn't provided, 
                // but the error code logic is preserved.
                Console.WriteLine($"CreateFileMappingA failed ({err})");
                return IntPtr.Zero;
            }

            // 2. MapViewOfFile
            IntPtr sharedMem = MapViewOfFile(
                sharedMemHandle,
                FILE_MAP_WRITE,
                0,
                0,
                UIntPtr.Zero // 0 maps the entire view
            );

            if (sharedMem == IntPtr.Zero)
            {
                uint err = GetLastError();
                Console.WriteLine($"MapViewOfFile failed ({err})");
                // In C++, the handle is leaked here (not closed), so we do the same.
                return IntPtr.Zero;
            }

            Console.WriteLine($"MapViewOfFile:{pMapName}");

            return sharedMem;
        }

        // Optional: Helper to free the memory later
        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool UnmapViewOfFile(IntPtr lpBaseAddress);

        public static void Unmap(nint ptr)
        {
            UnmapViewOfFile((IntPtr)ptr);
        }

        // =============================================================
        // 3. Hex Dump / Logging Helpers (Ported from C++)
        // =============================================================

        private static readonly char[] HexLookup = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

        public static string ToHex(byte* bytes, int size)
        {
            StringBuilder sb = new StringBuilder(size * 3);
            for (int i = 0; i < size; ++i)
            {
                byte ch = bytes[i];
                // Mimic C++: hex[(ch & 0xF0) >> 4]
                sb.Append(HexLookup[(ch & 0xF0) >> 4]);
                // Mimic C++: hex[ch & 0xF]
                sb.Append(HexLookup[ch & 0xF]);
                // Mimic C++: append(" ")
                sb.Append(' ');
            }
            return sb.ToString();
        }

        public static string ToAscii(byte* bytes, int size)
        {
            StringBuilder sb = new StringBuilder(size);
            for (int i = 0; i < size; ++i)
            {
                byte ch = bytes[i];
                if (ch >= 32 && ch <= 127)
                {
                    sb.Append((char)ch);
                }
                else
                {
                    sb.Append('.');
                }
            }
            return sb.ToString();
        }

        public static void Show(byte* bytes, int size)
        {
            Console.WriteLine();
            Console.WriteLine("---------");
            // Print Pointer Address and Size
            Console.WriteLine($"Ptr:0x{(IntPtr)bytes:X} Size:{size}");

            int chunkSize = 16;
            int chunks = size / chunkSize;
            int rem = size % chunkSize;

            int offset = 0;

            // Loop full chunks
            for (int i = 0; i < chunks; i++)
            {
                offset = i * chunkSize;
                string hex = ToHex(bytes + offset, chunkSize);
                string ascii = ToAscii(bytes + offset, chunkSize);

                // Format: 0xOFFSET | HEX | ASCII
                Console.WriteLine($"0x{offset:X8} | {hex}| {ascii}");
            }

            // Handle remainder (Last line)
            if (rem > 0)
            {
                offset = chunks * chunkSize;
                string hex = ToHex(bytes + offset, rem);
                string ascii = ToAscii(bytes + offset, rem);

                // Note: This mimics C++ exactly. 
                // If you want the ASCII column aligned, you would pad the 'hex' string here.
                Console.WriteLine($"0x{offset:X8} | {hex}| {ascii}");
            }

            Console.WriteLine("---------");
            Console.WriteLine();
        }
    }
}
