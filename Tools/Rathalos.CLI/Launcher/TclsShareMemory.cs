using System.Collections;
using System.Data.Common;
using System.Diagnostics;
using System.IO.MemoryMappedFiles;
using System.Reflection.Metadata;
using System.Runtime.InteropServices;
using System.Text;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Rathalos.CLI.Launcher
{
    public unsafe class TenProxyTclsSharedMemory : IDisposable
    {
        private const int OffsetTableSize = 64;
        private const int Var20OffsetTableSize = 17;
        // --- Data Fields ---
        public uint Uin { get; set; }
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
        private string _var20v5;
        private string _var20v9;

        public TenProxyTclsSharedMemory()
        {
            // Defaults matching the game requirements
            Uin = 123456789;

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
            _var20v5 = "283缘聚仙侠";
            _var20v9 = "-s:3";
            // Var60 (16 bytes of 0x00)
            _var60 = new byte[16];
        }
        public byte[] Serialize()
        {
            using (AgBuffer buf = new AgBuffer())
            {
                // 1. Reserve Offset Table
                int varOffsetTablePos = buf.Position;
                buf.WriteU32(0);
                buf.WriteRepeat(0, OffsetTableSize * 4);

                // --- Variables ---
                // (Variables writing section remains EXACTLY the same as before)
                // ... [Paste the variables writing code from the previous step here] ...

                // For completeness, here is the variables block again to ensure no context is lost:
                int var1Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(0x300A01);
                int var2Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(1235);
                int var6Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(1235);
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

                int var33Offset = buf.Position;
                string val33 = _var33 + "\0"; buf.WriteU32((uint)(val33.Length * 2)); buf.WriteWString(val33);

                int var17Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);
                int var18Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);

                int var19Offset = buf.Position;
                string val19 = InstallDir + "\0"; buf.WriteU32((uint)(val19.Length * 2)); buf.WriteWString(val19);

                int var36Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);
                int var37Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var40Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var42Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);

                // Sub-Structure Var 20
                int var20Offset = buf.Position;
                int var20OffsetTablePos = buf.Position;
                buf.WriteRepeat(0x00, Var20OffsetTableSize * 4);
                int var20v2Offset = buf.Position; string val20v2 = ConnectionPorts + "\0"; buf.WriteU32((uint)(val20v2.Length * 2)); buf.WriteWString(val20v2);
                int var20v3Offset = buf.Position; string val20v3 = ConnectionIP + "\0"; buf.WriteU32((uint)(val20v3.Length * 2)); buf.WriteWString(val20v3);
                int var20v4Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x2B0A);
                int var20v5Offset = buf.Position; string val20v5 = ServerName + "\0"; buf.WriteU32((uint)(val20v5.Length * 2)); buf.WriteWString(val20v5);
                int var20v6Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(1235);
                int var20v7Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(1235);
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
                int var16Offset = buf.Position; buf.WriteU32(2); buf.WriteU16(0);

                // --- Fill Offset Tables ---
                // Var 20 Table (Unchanged)
                buf.Seek(var20OffsetTablePos);
                buf.WriteU32((uint)(var20Offset + 4));
                buf.WriteU32((uint)var20v2Offset); buf.WriteU32((uint)var20v3Offset); buf.WriteU32((uint)var20v4Offset);
                buf.WriteU32((uint)var20v5Offset); buf.WriteU32((uint)var20v6Offset); buf.WriteU32((uint)var20v7Offset);
                buf.WriteU32((uint)var20v8Offset); buf.WriteU32((uint)var20v9Offset); buf.WriteU32((uint)var20v10Offset);
                for (int i = 0; i < 6; i++) buf.WriteU32(0);

                // MAIN OFFSET TABLE (FIXED HERE)
                buf.Seek(varOffsetTablePos);
                buf.WriteU32(OffsetTableSize);
                buf.WriteU32((uint)var1Offset);
                buf.WriteU32((uint)var2Offset);
                buf.WriteU32((uint)var3Offset);
                buf.WriteU32((uint)var4Offset);
                buf.WriteU32((uint)var5Offset);
                buf.WriteU32((uint)var6Offset);
                buf.WriteU32((uint)var7Offset);

                // [FIXED BLOCK] - There must be 6 zeros total here, not 3.
                buf.WriteU32(0); buf.WriteU32(0); buf.WriteU32(0); // Set 1
                buf.WriteU32(0); buf.WriteU32(0); buf.WriteU32(0); // Set 2 (Was missing!)

                buf.WriteU32((uint)var14Offset);
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
                buf.WriteU32((uint)var27Offset);
                buf.WriteU32(0); buf.WriteU32(0); buf.WriteU32(0);
                buf.WriteU32(0);
                buf.WriteU32((uint)var32Offset);
                buf.WriteU32((uint)var33Offset);
                buf.WriteU32(0); buf.WriteU32(0);
                buf.WriteU32((uint)var36Offset);
                buf.WriteU32((uint)var37Offset);
                buf.WriteU32(0); buf.WriteU32(0);
                buf.WriteU32((uint)var40Offset);
                buf.WriteU32((uint)var41Offset);
                buf.WriteU32((uint)var42Offset);
                for (int i = 0; i < 9; i++) buf.WriteU32(0);
                buf.WriteU32((uint)var60Offset);
                for (int i = 0; i < 4; i++) buf.WriteU32(0);

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