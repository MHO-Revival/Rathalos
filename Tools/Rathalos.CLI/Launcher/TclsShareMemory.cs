using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;

namespace Rathalos.CLI.Launcher
{
    public class GameServerInfo
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Ip { get; set; }
        public int Port { get; set; } = 8142;
        public uint Unk0 { get; set; } = 0x2B0A;
        public string Unk3 { get; set; } = "-s:3";
        // Each server can have its own Auth Type (usually 5)
        public uint Unk5 { get; set; } = 5;
        public ushort Unk4 { get; set; } = 0;
        public uint Unk1 { get; internal set; }
        public uint Unk2 { get; internal set; }
    }

    public unsafe class TenProxyTclsSharedMemory : IDisposable
    {
        private const int OffsetTableSize = 64;
        private const int Var20OffsetTableSize = 17;

        // --- Global Config ---
        public uint GlobalServiceId { get; set; } = 0x300A01;
        public uint Uin { get; set; } = 1235;
        public string ClientExePath { get; set; } = "";
        public string WindowTitle { get; set; } = "MHO Game Client";
        public string Unk2 { get; set; } = "dir_root;双线三区;283缘聚仙侠;";
        public string Password { get; set; } = "";

        public byte[] AesKey { get; set; }
        public byte[] LoginSignature { get; set; }
        public byte[] JumpSignature { get; set; }

        // --- Server Management ---
        public List<GameServerInfo> ServerList { get; set; }
        public int Unk1 { get; set; }
        public int Unk3 { get; set; }

        private byte[] _reservedVar25 = new byte[16];
        private byte[] _reservedVar60 = new byte[16];

        public TenProxyTclsSharedMemory()
        {
            AesKey = Enumerable.Repeat((byte)0x01, 16).ToArray();
            LoginSignature = new byte[96]; //is mandatory can't be empty it's for the siginfo in TqqUnifiedAuthInfo
            JumpSignature = []; // dunno what is this ??? whats its utility ??? base+6727

            // It takes in account only the first one even if you put multiple so idk why having multiple entries
            ServerList = new List<GameServerInfo>
            {
                new GameServerInfo { Id=1, Name="SRV1", Ip="127.0.0.1", Port=8144, Unk0=4, Unk3="-s:7", Unk5 = 10, Unk4 = 13 },
                new GameServerInfo { Id=2, Name="SRV2", Ip="127.0.0.1", Port=8142, Unk0=5, Unk3="-s:8", Unk5 = 11, Unk4 = 14 },
                new GameServerInfo { Id=3, Name="SRV3", Ip="127.0.0.1", Port=8143, Unk0=6, Unk3="-s:9", Unk5 = 12, Unk4 = 15 },
            };

            Unk1 = 3;
        }

        public byte[] Serialize()
        {
            if (ServerList == null || ServerList.Count == 0) throw new Exception("ServerList empty");

            // 2. Build Server List String (var_33)
            StringBuilder sbVar33 = new StringBuilder();
            foreach (var s in ServerList) sbVar33.Append($"{s.Id}:{s.Name};");
            string connectionString = sbVar33.ToString();

            using (AgBuffer buf = new AgBuffer())
            {
                // --- Reserve Offset Table ---
                int varOffsetTablePos = buf.Position;
                buf.WriteU32(0);
                buf.WriteRepeat(0, OffsetTableSize * 4);

                // --- Global Variables ---
                int var1Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(GlobalServiceId);
                int var2Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(Uin);
                int var6Offset = buf.Position; buf.WriteU32(4); buf.WriteU32(Uin);
                int var3Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8((byte)LoginSignature.Length);//it's mandatory and can't be 0 otherwise it put random bytes in the TqqUnifiedAuthInfo for siginfo
                int var4Offset = buf.Position; buf.WriteU32((uint)LoginSignature.Length); buf.WriteData(LoginSignature);
                int var5Offset = buf.Position; buf.WriteU32((uint)AesKey.Length); buf.WriteData(AesKey);

                int var21Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x0);
                int var22Offset = buf.Position; buf.WriteU32(0x0);
                int var23Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0x0);
                int var24Offset = buf.Position; buf.WriteU32(0x0);
                int var25Offset = buf.Position; buf.WriteU32((uint)_reservedVar25.Length); buf.WriteData(_reservedVar25);
                int var26Offset = buf.Position; buf.WriteU32(0x1); buf.WriteU8(0);
                int var27Offset = buf.Position; buf.WriteU32((uint)JumpSignature.Length); buf.WriteData(JumpSignature);

                int var32Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32((uint)Unk1);
                int var33Offset = buf.Position; string val33 = connectionString + "\0"; buf.WriteU32((uint)(val33.Length * 2)); buf.WriteWString(val33);

                // [UPDATED] var_17 (Count) and var_18 (Selected Index)
                int var17Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32((uint)ServerList.Count);
                int var18Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32((uint)Unk3);

                int var19Offset = buf.Position; string val19 = Unk2 + "\0"; buf.WriteU32((uint)(val19.Length * 2)); buf.WriteWString(val19);

                int var36Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x1);
                int var37Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var40Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var42Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);

                // ==========================================================
                // var_20 (Server Arrays)
                // ==========================================================
                int var20Offset = buf.Position;
                int var20OffsetTablePos = buf.Position;
                buf.WriteRepeat(0x00, Var20OffsetTableSize * 4);

                // 1. Connection Ports (Array of Strings)
                int var20v2Offset = buf.Position;
                foreach (var s in ServerList)
                {
                    string val = $"{s.Ip}:{s.Port}\0";
                    buf.WriteU32((uint)(val.Length * 2)); buf.WriteWString(val);
                }

                // 2. Connection IP (Array of Strings)
                int var20v3Offset = buf.Position;
                foreach (var s in ServerList)
                {
                    string val = s.Ip + "\0";
                    buf.WriteU32((uint)(val.Length * 2)); buf.WriteWString(val);
                }

                // 3. Zone ID maybe ? (Array of Integers)
                int var20v4Offset = buf.Position;
                buf.WriteU32((uint)(ServerList.Count * 4)); // Total Length of array block
                foreach (var s in ServerList) buf.WriteU32(s.Unk0);

                // 4. Server Name (Array of Strings)
                int var20v5Offset = buf.Position;
                foreach (var s in ServerList)
                {
                    string val = s.Name + "\0";
                    buf.WriteU32((uint)(val.Length * 2)); buf.WriteWString(val);
                }

                // 5. Server UIN maybe ? (Array of Integers)
                int var20v6Offset = buf.Position;
                buf.WriteU32((uint)(ServerList.Count * 4));
                foreach (var s in ServerList) buf.WriteU32(s.Unk1); // Use same UIN for all

                // 6. UIN Backup maybe ? (Array of Integers)
                int var20v7Offset = buf.Position;
                buf.WriteU32((uint)(ServerList.Count * 4));
                foreach (var s in ServerList) buf.WriteU32(s.Unk2);

                // 7. Auth Type maybe ? (Array of Integers)
                int var20v8Offset = buf.Position;
                buf.WriteU32((uint)(ServerList.Count * 4));
                foreach (var s in ServerList) buf.WriteU32(s.Unk5);

                // 8. Startup Args (Array of ANSI Strings)
                int var20v9Offset = buf.Position;
                foreach (var s in ServerList)
                {
                    // String arrays (esp ANSI) often need exact length logic. 
                    // TCLS strings are typically: [Len u32][Data...]
                    buf.WriteU32((uint)(Encoding.UTF8.GetByteCount(s.Unk3) + 1));
                    buf.WriteString(s.Unk3);
                }

                // 9. Unknown Short (Array) - Writes 0x0000 for each server
                int var20v10Offset = buf.Position;
                buf.WriteU32((uint)(ServerList.Count * 2));
                foreach (var s in ServerList) buf.WriteU16(s.Unk4);

                // End var_20

                int var7Offset = buf.Position; buf.WriteU32(0x0);
                int var60Offset = buf.Position; buf.WriteU32((uint)_reservedVar60.Length); buf.WriteData(_reservedVar60);

                int var14Offset = buf.Position;
                if (string.IsNullOrEmpty(ClientExePath)) { buf.WriteU32(0); }
                else { string val14 = ClientExePath + "\0"; buf.WriteU32((uint)(val14.Length * 2)); buf.WriteWString(val14); }

                int var41Offset = buf.Position; buf.WriteU32(0x4); buf.WriteU32(0x0);
                int var15Offset = buf.Position; string val15 = WindowTitle + "\0"; buf.WriteU32((uint)(val15.Length * 2)); buf.WriteWString(val15);

                int var16Offset = buf.Position;
                if (string.IsNullOrEmpty(Password)) { buf.WriteU32(2); buf.WriteU16(0); }
                else { string p = "PASS:" + Password + "\0"; buf.WriteU32((uint)(p.Length * 2)); buf.WriteWString(p); }

                // --- Fill Offset Tables ---

                // Var 20 Table (Points to the START of the arrays)
                buf.Seek(var20OffsetTablePos);
                buf.WriteU32((uint)(var20Offset + 4));
                buf.WriteU32((uint)var20v2Offset); buf.WriteU32((uint)var20v3Offset); buf.WriteU32((uint)var20v4Offset);
                buf.WriteU32((uint)var20v5Offset); buf.WriteU32((uint)var20v6Offset); buf.WriteU32((uint)var20v7Offset);
                buf.WriteU32((uint)var20v8Offset); buf.WriteU32((uint)var20v9Offset); buf.WriteU32((uint)var20v10Offset);
                for (int i = 0; i < 6; i++) buf.WriteU32(0);

                // Main Table
                buf.Seek(varOffsetTablePos);
                buf.WriteU32(OffsetTableSize);

                buf.WriteU32((uint)var1Offset);
                buf.WriteU32((uint)var2Offset);
                buf.WriteU32((uint)var3Offset);
                buf.WriteU32((uint)var4Offset);
                buf.WriteU32((uint)var5Offset);
                buf.WriteU32((uint)var6Offset);
                buf.WriteU32((uint)var7Offset);
                for (int i = 0; i < 6; i++) buf.WriteU32(0);
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
                for (int i = 0; i < 4; i++) buf.WriteU32(0);
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