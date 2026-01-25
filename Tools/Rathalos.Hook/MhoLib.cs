using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.CLI.Launcher
{
    using System;
    using System.Collections.Concurrent;
    using System.Diagnostics;
    using System.IO;
    using System.Runtime.InteropServices;
    using System.Text;
    using System.Threading;
    using System.Threading.Tasks;
    using MinHook; // Requires MinHook.NET Nuget Package

    namespace MhoLauncher
    {
        public unsafe class MhoMod
        {
            // =============================================================
            // 1. Native API Helpers
            // =============================================================
            private static class Native
            {
                [DllImport("kernel32.dll", SetLastError = true)]
                public static extern bool AllocConsole();

                [DllImport("kernel32.dll", CharSet = CharSet.Auto)]
                public static extern IntPtr GetModuleHandle(string lpModuleName);

                [DllImport("kernel32.dll", SetLastError = true)]
                public static extern bool WriteProcessMemory(IntPtr hProcess, IntPtr lpBaseAddress, byte[] lpBuffer, int nSize, out int lpNumberOfBytesWritten);

                [DllImport("kernel32.dll", SetLastError = true)]
                public static extern bool VirtualProtect(IntPtr lpAddress, uint dwSize, uint flNewProtect, out uint lpflOldProtect);

                [DllImport("kernel32.dll")]
                public static extern IntPtr GetCurrentProcess();

                // Helper to write generic types to memory
                public static void WriteMemory(IntPtr address, byte[] data)
                {
                    // Unprotect memory
                    VirtualProtect(address, (uint)data.Length, 0x40, out uint oldProtect); // 0x40 = PAGE_EXECUTE_READWRITE

                    WriteProcessMemory(GetCurrentProcess(), address, data, data.Length, out _);

                    // Reprotect (Optional, but good practice)
                    VirtualProtect(address, (uint)data.Length, oldProtect, out _);
                }

                public static void PatchNop(IntPtr address, int count)
                {
                    byte[] nops = new byte[count];
                    for (int i = 0; i < count; i++) nops[i] = 0x90; // NOP opcode
                    WriteMemory(address, nops);
                }
            }

            // =============================================================
            // 2. State & Configuration
            // =============================================================
            private static HookEngine _hookEngine = new HookEngine();
            private static IntPtr _serverUrlAddress = IntPtr.Zero;
            private static bool _logCrypto = false;
            private static BlockingCollection<string> _eventQueue = new BlockingCollection<string>(100);

            // =============================================================
            // 3. Delegate Definitions (Function Signatures)
            // =============================================================

            // CryGame
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            private delegate void D_CryGameConnection();

            // ProtocolHandler
            [UnmanagedFunctionPointer(CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
            private delegate void D_ProtocolLog(int pUnk, IntPtr pBufferSize, string pStr, IntPtr pStrFmtArgs);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            private delegate int D_TpduDecryption(IntPtr apiHandle, IntPtr inputBuffer, int inputLen, IntPtr* outputBuffer, int* outputLen, int isPlain, int allowUnencrypted);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            private delegate int D_TpduEncryption(IntPtr apiHandle, IntPtr inputBuffer, int inputLen, IntPtr* outputBuffer, int* outputLen, int allowUnencrypted);

            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            private delegate int D_AesKeyExpansion(IntPtr key, uint keyLenBits, IntPtr expandedKey);

            // TenProxy & Client Log (Approximated signatures based on usage)
            [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
            private delegate void D_TenProxyLog(IntPtr logStr);

            // =============================================================
            // 4. Hook Storage (To keep delegates alive)
            // =============================================================
            // We must store the original delegates to call them later
            private static D_CryGameConnection _origCryGameConnection;
            private static D_ProtocolLog _origProtocolLog;
            private static D_TpduDecryption _origTpduDecryption;
            private static D_TpduEncryption _origTpduEncryption;
            private static D_AesKeyExpansion _origAesKeyExpansion;
            private static D_TenProxyLog _origTenProxyLog;

            // =============================================================
            // 5. Hook Implementations (The Logic)
            // =============================================================

            // --- CryGame Connection Logic ---
            private static void Hk_CryGameConnection()
            {
                Log("crygame_13F3640 (Hook Triggered)\n");

                // Overwrite the Server URL in memory right before the connection happens
                if (_serverUrlAddress != IntPtr.Zero)
                {
                    string url = "127.0.0.1:8142";
                    byte[] urlBytes = Encoding.ASCII.GetBytes(url + "\0");
                    Native.WriteMemory(_serverUrlAddress, urlBytes);
                    Log($"Replaced URL at 0x{_serverUrlAddress.ToString("X")} with {url}");
                }

                // Call Original
                _origCryGameConnection();
            }

            // --- Protocol Handler Decryption ---
            private static int Hk_TpduDecryption(IntPtr apiHandle, IntPtr inputBuffer, int inputLen, IntPtr* outputBuffer, int* outputLen, int isPlain, int allowUnencrypted)
            {
                // Access encryption_mode_addr (apiHandle + 0x84)
                byte* encryptionModeAddr = (byte*)(apiHandle + 0x84);

                if (_logCrypto)
                {
                    Log("DECRYPT - START | ModeAddr Val: {0}\n", *encryptionModeAddr);
                    // (Hex dump logic omitted for brevity)
                }

                // Call Original
                int ret = _origTpduDecryption(apiHandle, inputBuffer, inputLen, outputBuffer, outputLen, isPlain, allowUnencrypted);

                if (_logCrypto)
                {
                    Log("DECRYPT - End | Ret: {0}\n", ret);
                }
                return ret;
            }

            // --- Protocol Handler Encryption ---
            private static int Hk_TpduEncryption(IntPtr apiHandle, IntPtr inputBuffer, int inputLen, IntPtr* outputBuffer, int* outputLen, int allowUnencrypted)
            {
                byte* encryptionModeAddr = (byte*)(apiHandle + 0x84);

                if (_logCrypto) Log("ENCRYPT - START | ModeAddr Val: {0}\n", *encryptionModeAddr);

                int ret = _origTpduEncryption(apiHandle, inputBuffer, inputLen, outputBuffer, outputLen, allowUnencrypted);

                if (_logCrypto) Log("ENCRYPT - End | Ret: {0}\n", ret);
                return ret;
            }

            // --- Protocol Log ---
            private static void Hk_ProtocolLog(int pUnk, IntPtr pBufferSize, string pStr, IntPtr pStrFmtArgs)
            {
                // We intercept the log, print it to our console, then let the game do its thing
                if (!string.IsNullOrEmpty(pStr))
                {
                    Log("ProtoLog: {0}\n", pStr);
                }
                _origProtocolLog(pUnk, pBufferSize, pStr, pStrFmtArgs);
            }

            // --- TenProxy Log ---
            private static void Hk_TenProxyLog(IntPtr logPtr)
            {
                string logText = Marshal.PtrToStringUni(logPtr);
                Log("TenProxyLog: {0}\n", logText);

                // Note: The C++ version replaced this function entirely (no original call).
                // If you need to call original, use _origTenProxyLog(logPtr);
            }

            // =============================================================
            // 6. Initialization Logic (Threading & Hooking)
            // =============================================================
            public static void Run()
            {
                CreateConsole();
                Task.Run(() => LogLoop());
                Log("MhoMod C# Started.\n");

                // 1. Setup Client Base
                string exeName = Process.GetCurrentProcess().MainModule.ModuleName;
                IntPtr mhoBase = Native.GetModuleHandle(exeName);

                // RVA for Server URL
                _serverUrlAddress = mhoBase + 0x157AAA0;

                // Disable Client Conditional Logging (NOP 6 bytes at 0x3E0C82)
                Native.PatchNop(mhoBase + 0x3E0C82, 6);

                // 2. Spin up threads to wait for DLLs
                new Thread(SetupCryGame).Start();
                new Thread(SetupProtocolHandler).Start();
                new Thread(SetupTenProxy).Start();
            }

            private static void SetupCryGame()
            {
                IntPtr handle = WaitForModule("crygame");

                // The C++ code hooks the function at crygame + 0x13F3640
                // But usually hooks work by targeting the *Start* of the function.
                // Ensure 0x13F3640 is the start of a function.
                IntPtr target = handle + 0x13F3640; // The C++ 'org_fn_crygame_13EC290' assignment suggest this is the target

                try
                {
                    _origCryGameConnection = _hookEngine.CreateHook<D_CryGameConnection>(target, Hk_CryGameConnection);
                    _hookEngine.EnableHook(_origCryGameConnection);
                    Log("CryGame Hooks Enabled.");
                }
                catch (Exception ex) { Log($"CryGame Hook Error: {ex.Message}"); }
            }

            private static void SetupProtocolHandler()
            {
                IntPtr handle = WaitForModule("protocalhandler"); // Sic: Spelling matches C++ code

                try
                {
                    // Addresses from C++ "org_..." assignments
                    IntPtr addrLog = handle + 0x1703;
                    IntPtr addrDecrypt = handle + 0x73DC0;
                    IntPtr addrEncrypt = handle + 0x73BB0;

                    // Create Hooks
                    _origProtocolLog = _hookEngine.CreateHook<D_ProtocolLog>(addrLog, Hk_ProtocolLog);
                    _origTpduDecryption = _hookEngine.CreateHook<D_TpduDecryption>(addrDecrypt, Hk_TpduDecryption);
                    _origTpduEncryption = _hookEngine.CreateHook<D_TpduEncryption>(addrEncrypt, Hk_TpduEncryption);

                    // Enable all
                    _hookEngine.EnableHook(_origProtocolLog);
                    _hookEngine.EnableHook(_origTpduDecryption);
                    _hookEngine.EnableHook(_origTpduEncryption);

                    Log("ProtocolHandler Hooks Enabled.");
                }
                catch (Exception ex) { Log($"ProtocolHandler Hook Error: {ex.Message}"); }
            }

            private static void SetupTenProxy()
            {
                IntPtr handle = WaitForModule("tenproxy.dll");

                // NOP conditional logging (0xA0D3, 8 bytes)
                Native.PatchNop(handle + 0xA0D3, 8);

                // Hook Logging (0xA143)
                // Note: In C++ this was a patch_jmp. In MinHook we hook the function containing this address 
                // OR if 0xA143 is the start of the log function, we hook it directly.
                IntPtr addrLog = handle + 0xA143;
                try
                {
                    _origTenProxyLog = _hookEngine.CreateHook<D_TenProxyLog>(addrLog, Hk_TenProxyLog);
                    _hookEngine.EnableHook(_origTenProxyLog);
                    Log("TenProxy Hooks Enabled.");
                }
                catch (Exception ex) { Log($"TenProxy Hook Error: {ex.Message}"); }
            }

            // =============================================================
            // 7. Utilities
            // =============================================================
            private static IntPtr WaitForModule(string name)
            {
                IntPtr handle = IntPtr.Zero;
                while ((handle = Native.GetModuleHandle(name)) == IntPtr.Zero)
                {
                    Thread.Sleep(50);
                }
                Log($"Module found: {name} at 0x{handle.ToString("X")}\n");
                return handle;
            }

            private static void LogLoop()
            {
                foreach (var msg in _eventQueue.GetConsumingEnumerable())
                {
                    Console.Write(msg);
                }
            }

            private static void Log(string fmt, params object[] args)
            {
                _eventQueue.Add(string.Format(fmt, args));
            }

            private static void CreateConsole()
            {
                Native.AllocConsole();
                var writer = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = true };
                Console.SetOut(writer);
            }
        }
    }
}
