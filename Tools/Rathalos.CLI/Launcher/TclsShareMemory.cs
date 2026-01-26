using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;

namespace Rathalos.CLI.Launcher
{
    public unsafe class TenProxyTclsSharedMemory : IDisposable
    {
        private const int OffsetTableSize = 64;
        private const int Var20OffsetTableSize = 17;
        // --- Data Fields ---
        public uint Uin { get; set; }
        public uint GameServiceId { get; set; }
        public string ClientExePath { get; set; }
        public string WindowTitle { get; set; }
        public string InstallDir { get; set; } // var_19
        public string Password { get; set; }   // var_16
        public byte[] AesKey { get; set; }
        public byte[] LoginSignature { get; set; }
        public byte[] JumpSignature { get; set; }

        // Sub-config (Var 20) - Not fully read in the disassembly provided, 
        // but required for the game connection logic elsewhere.
        public string ConnectionIP { get; set; }
        public string ConnectionPorts { get; set; }
        public string ServerName { get; set; } // var_20_v5
        private byte[] _var25;
        private byte[] _var60;
        private string _var33;
        private string _var20v9;

        public TenProxyTclsSharedMemory()
        {
            GameServiceId = 0x300A01;
            // Defaults matching the game requirements
            Uin = 1235;

            // This title is often checked by the game to verify it was launched by TCLS
            WindowTitle = "QQ仙侠传登录程序6";

            ClientExePath = ""; // Can be empty if we hook the path check
            InstallDir = "dir_root;双线三区;283缘聚仙侠;"; // var_19 format

            // "PASS:" prefix is required for the game to parse var_16
            Password = ""; // e.g. "PASS:123456"

            // 16-byte AES Key (The game reads this from ID 5)
            // We use all 1s for simplicity, or generate a random one.
            AesKey = new byte[] {
                0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
            };

            // Signatures (Empty for emulated/cracked mode, or real tickets if valid)
            LoginSignature = new byte[96];
            JumpSignature = new byte[72];

            // Connection Info (Var 20 sub-struct)
            ConnectionIP = "127.0.0.1";
            ConnectionPorts = "127.0.0.1:8142";
            ServerName = "283缘聚仙侠";
            // Var25 (16 bytes of 0x00)
            _var25 = new byte[16];
            _var33 = "1:双线一区;2:双线二区;3:双线三区;";
            _var20v9 = "-s:3";
            // Var60 (16 bytes of 0x00)
            _var60 = new byte[16];
        }
        public byte[] Serialize()
        {
            using (AgBuffer buf = new AgBuffer())
            {
                // 1. Reserve Offset Table (Start at 0, Length 64 ints)
                int varOffsetTablePos = buf.Position;
                buf.WriteU32(0);
                buf.WriteRepeat(0, OffsetTableSize * 4);

                // ==========================================================
                // 2. Write Variables Data (Content)
                // ==========================================================
                int gameServiceIdOffset = buf.Position; buf.WriteU32(4); buf.WriteU32(GameServiceId);
                int uinOffset = buf.Position; buf.WriteU32(4); buf.WriteU32(Uin);
                int var6Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(0);
                int var3Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x60);
                int var4Offset = buf.Position; buf.WriteU32((uint)LoginSignature.Length); buf.WriteData(LoginSignature);
                int var5Offset = buf.Position; buf.WriteU32((uint)AesKey.Length); buf.WriteData(AesKey);
                int var21Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x0);
                int var22Offset = buf.Position; buf.WriteU32(0x0);
                int var23Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x0);
                int var24Offset = buf.Position; buf.WriteU32(0x0);
                int var25Offset = buf.Position; buf.WriteU32((uint)_var25.Length); buf.WriteData(_var25);
                int var26Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x48);
                int var27Offset = buf.Position; buf.WriteU32((uint)JumpSignature.Length); buf.WriteData(JumpSignature);

                int var32Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x3);
                int var33Offset = buf.Position; string val33 = _var33 + "\0"; buf.WriteU32((uint)(val33.Length * 2)); buf.WriteWString(val33);

                int var17Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);
                int var18Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);

                int var19Offset = buf.Position; string val19 = InstallDir + "\0"; buf.WriteU32((uint)(val19.Length * 2)); buf.WriteWString(val19);

                int var36Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);
                int var37Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var40Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var42Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);

                // Var 20 Sub-structure
                int var20Offset = buf.Position;
                int var20OffsetTablePos = buf.Position;
                buf.WriteRepeat(0x00, Var20OffsetTableSize * 4);
                int var20v2Offset = buf.Position; string val20v2 = ConnectionPorts + "\0"; buf.WriteU32((uint)(val20v2.Length * 2)); buf.WriteWString(val20v2);
                int var20v3Offset = buf.Position; string val20v3 = ConnectionIP + "\0"; buf.WriteU32((uint)(val20v3.Length * 2)); buf.WriteWString(val20v3);
                int var20v4Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x2B0A);
                int var20v5Offset = buf.Position; string val20v5 = ServerName + "\0"; buf.WriteU32((uint)(val20v5.Length * 2)); buf.WriteWString(val20v5);
                int var20v6Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0);
                int var20v7Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0);
                int var20v8Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x5);
                int var20v9Offset = buf.Position; buf.WriteU32((uint)(Encoding.UTF8.GetByteCount(_var20v9) + 1)); buf.WriteString(_var20v9);
                int var20v10Offset = buf.Position; buf.WriteU32(0x2); buf.WriteU16(0x0);
                int var7Offset = buf.Position; buf.WriteU32(0x0);
                int var60Offset = buf.Position; buf.WriteU32((uint)_var60.Length); buf.WriteData(_var60);

                int var14Offset = buf.Position;
                if (string.IsNullOrEmpty(ClientExePath)) { buf.WriteU32(0); }
                else { string val14 = ClientExePath + "\0"; buf.WriteU32((uint)(val14.Length * 2)); buf.WriteWString(val14); }

                int var41Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var15Offset = buf.Position; string val15 = WindowTitle + "\0"; buf.WriteU32((uint)(val15.Length * 2)); buf.WriteWString(val15);
                // [FIX] var_16 (Password)
                int var16Offset = buf.Position;

                if (string.IsNullOrEmpty(Password))
                {
                    // Empty Password: Write just a null terminator (Length 2 bytes)
                    // Matches C++: buf->write_u32(2); buf->write_u16(0);
                    buf.WriteU32(2);
                    buf.WriteU16(0);
                }
                else
                {
                    // Set Password: Must prepend "PASS:" so the game can strip it
                    string fullPassword = "PASS:" + Password + "\0";

                    buf.WriteU32((uint)(fullPassword.Length * 2));
                    buf.WriteWString(fullPassword);
                }

                // ==========================================================
                // 3. Fill Offset Tables (EXACT ALIGNMENT)
                // ==========================================================

                // --- Var 20 Table ---
                buf.Seek(var20OffsetTablePos);
                buf.WriteU32((uint)(var20Offset + 4));
                buf.WriteU32((uint)var20v2Offset); buf.WriteU32((uint)var20v3Offset); buf.WriteU32((uint)var20v4Offset);
                buf.WriteU32((uint)var20v5Offset); buf.WriteU32((uint)var20v6Offset); buf.WriteU32((uint)var20v7Offset);
                buf.WriteU32((uint)var20v8Offset); buf.WriteU32((uint)var20v9Offset); buf.WriteU32((uint)var20v10Offset);

                // --- MAIN OFFSET TABLE (Fixing the 8-integer misalignment) ---
                buf.Seek(varOffsetTablePos);
                buf.WriteU32(OffsetTableSize);

                // Block 1: Vars 1-7
                buf.WriteU32((uint)gameServiceIdOffset);
                buf.WriteU32((uint)uinOffset);
                buf.WriteU32((uint)var3Offset);
                buf.WriteU32((uint)var4Offset);
                buf.WriteU32((uint)var5Offset);
                buf.WriteU32((uint)var6Offset);
                buf.WriteU32((uint)var7Offset); // Index 7 (0x1C)

                // Block 2: 6 Zeros
                for (int i = 0; i < 6; i++) buf.WriteU32(0);

                // Block 3: Vars 14-27
                buf.WriteU32((uint)var14Offset); // Index 14 (0x38)
                buf.WriteU32((uint)var15Offset);
                buf.WriteU32((uint)var16Offset);
                buf.WriteU32((uint)var17Offset);
                buf.WriteU32((uint)var18Offset);
                buf.WriteU32((uint)var19Offset);
                buf.WriteU32((uint)var20Offset);
                buf.WriteU32((uint)var21Offset);
                buf.WriteU32((uint)var22Offset);
                buf.WriteU32((uint)var23Offset);
                buf.WriteU32((uint)var24Offset);
                buf.WriteU32((uint)var25Offset);
                buf.WriteU32((uint)var26Offset);
                buf.WriteU32((uint)var27Offset); // Index 27 (0x6C)

                // Block 4: 4 Zeros
                for (int i = 0; i < 4; i++) buf.WriteU32(0);

                // Block 5: Vars 32-33
                buf.WriteU32((uint)var32Offset); // Index 32 (0x80) - Matches C++ dump 0x1002
                buf.WriteU32((uint)var33Offset);

                // Block 6: 2 Zeros
                buf.WriteU32(0); buf.WriteU32(0);

                // Block 7: Vars 36-37
                buf.WriteU32((uint)var36Offset); // Index 36 (0x90) - Matches C++ dump 0x8A02
                buf.WriteU32((uint)var37Offset);

                // Block 8: 2 Zeros
                buf.WriteU32(0); buf.WriteU32(0);

                // Block 9: Vars 40-42
                buf.WriteU32((uint)var40Offset);
                buf.WriteU32((uint)var41Offset);
                buf.WriteU32((uint)var42Offset); // Index 42 (0xA8)

                // Block 10: 9 Zeros
                for (int i = 0; i < 9; i++) buf.WriteU32(0);

                // Block 11: Var 60
                buf.WriteU32((uint)var60Offset); // Index 52 (0xD0) - Matches C++ dump 6F03

                return buf.GetAllData();
            }
        }
        // Keep handles alive
        private IntPtr _hMapFile = IntPtr.Zero;
        private IntPtr _pMapView = IntPtr.Zero;

        // --- Native Constants ---
        private const uint PAGE_EXECUTE_READWRITE = 0x40; // Allow Game to "Execute" if needed
        private const uint FILE_MAP_WRITE = 0x0002;
        private const int INVALID_HANDLE_VALUE = -1;
        private const uint SDDL_REVISION_1 = 1;

        // --- Native Imports ---
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern IntPtr CreateFileMappingW(
            IntPtr hFile,
            ref SECURITY_ATTRIBUTES lpFileMappingAttributes, // We use ref struct here
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

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool UnmapViewOfFile(IntPtr lpBaseAddress);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool CloseHandle(IntPtr hObject);

        [DllImport("advapi32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool ConvertStringSecurityDescriptorToSecurityDescriptor(
            string StringSecurityDescriptor,
            uint StringSDRevision,
            out IntPtr SecurityDescriptor,
            out uint SecurityDescriptorSize);

        [StructLayout(LayoutKind.Sequential)]
        public struct SECURITY_ATTRIBUTES
        {
            public int nLength;
            public IntPtr lpSecurityDescriptor;
            public bool bInheritHandle;
        }

        // ... [Insert your Properties and Serialize() method here] ...

        public void Map(uint processId)
        {
            if (processId == 0) processId = (uint)Process.GetCurrentProcess().Id;

            // 1. EXACT NAME
            string mapName = "TCLS_SHAREDMEMEMORY" + processId;
            uint size = 0xF001F;

            Console.WriteLine($"[Map] Creating Map: {mapName}");

            // 2. CREATE SECURITY DESCRIPTOR (Everyone - Full Control)
            // This fixes the "Access Denied" issue by explicitly allowing everyone.
            // D: = DACL, (A; = Allow, ;GA; = Generic All, ;;;WD) = World/Everyone
            string sddl = "D:(A;;GA;;;WD)";
            IntPtr pSecurityDescriptor = IntPtr.Zero;

            if (!ConvertStringSecurityDescriptorToSecurityDescriptor(sddl, SDDL_REVISION_1, out pSecurityDescriptor, out _))
            {
                Console.WriteLine($"[Error] Security Descriptor failed: {Marshal.GetLastWin32Error()}");
                return;
            }

            SECURITY_ATTRIBUTES sa = new SECURITY_ATTRIBUTES();
            sa.nLength = Marshal.SizeOf(sa);
            sa.lpSecurityDescriptor = pSecurityDescriptor;
            sa.bInheritHandle = false;

            try
            {
                // 3. Create Map with PERMISSIONS
                _hMapFile = CreateFileMappingW(
                    new IntPtr(INVALID_HANDLE_VALUE),
                    ref sa,                    // Pass our "Everyone" security
                    PAGE_EXECUTE_READWRITE,    // 0x40 (Stronger permission)
                    0,
                    size,
                    mapName
                );

                if (_hMapFile == IntPtr.Zero)
                {
                    Console.WriteLine($"[Error] CreateFileMappingW failed: {Marshal.GetLastWin32Error()}");
                    return;
                }

                // 4. Map View
                _pMapView = MapViewOfFile(
                    _hMapFile,
                    FILE_MAP_WRITE,
                    0,
                    0,
                    UIntPtr.Zero
                );

                if (_pMapView == IntPtr.Zero)
                {
                    Console.WriteLine($"[Error] MapViewOfFile failed: {Marshal.GetLastWin32Error()}");
                    CloseHandle(_hMapFile);
                    _hMapFile = IntPtr.Zero;
                    return;
                }

                Console.WriteLine($"[Map] Native Handle: 0x{_hMapFile:X}");

                // 5. Write Data
                byte[] data = Serialize();
                fixed (byte* ptr = data)
                {
                    MemoryMapper.Show(ptr, data.Length);
                }
                Marshal.Copy(data, 0, _pMapView, data.Length);
                Console.WriteLine($"[Map] Data written ({data.Length} bytes).");
            }
            finally
            {
                // Free the temporary security descriptor memory
                if (pSecurityDescriptor != IntPtr.Zero)
                    Marshal.FreeHGlobal(pSecurityDescriptor);
            }
        }

        public void Dispose()
        {
            if (_pMapView != IntPtr.Zero) { UnmapViewOfFile(_pMapView); _pMapView = IntPtr.Zero; }
            if (_hMapFile != IntPtr.Zero) { CloseHandle(_hMapFile); _hMapFile = IntPtr.Zero; }
        }
    }
}