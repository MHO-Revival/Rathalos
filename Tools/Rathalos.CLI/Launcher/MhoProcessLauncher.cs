using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Text;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Rathalos.CLI.Launcher
{
    /// <summary>
    /// Service for launching and injecting into MHO Client processes.
    /// Translated from the C++ mho_launcher implementation.
    /// </summary>
    public class MhoProcessLauncher
    {
        // Error codes
        private const int ERROR_ELEVATION_REQUIRED = 740;
        private const int ERROR_ACCESS_DENIED = 5;
        // =============================================================
        // 1. Native WinAPI Imports
        // =============================================================
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        static extern bool CreateProcess(
            string lpApplicationName,
            string lpCommandLine,
            IntPtr lpProcessAttributes,
            IntPtr lpThreadAttributes,
            bool bInheritHandles,
            uint dwCreationFlags,
            IntPtr lpEnvironment,
            string lpCurrentDirectory,
            ref STARTUPINFO lpStartupInfo,
            out PROCESS_INFORMATION lpProcessInformation);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern IntPtr VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress, uint dwSize, uint flAllocationType, uint flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool WriteProcessMemory(IntPtr hProcess, IntPtr lpBaseAddress, byte[] lpBuffer, uint nSize, out int lpNumberOfBytesWritten);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern IntPtr CreateRemoteThread(IntPtr hProcess, IntPtr lpThreadAttributes, uint dwStackSize, IntPtr lpStartAddress, IntPtr lpParameter, uint dwCreationFlags, IntPtr lpThreadId);

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
        static extern IntPtr GetProcAddress(IntPtr hModule, string lpProcName);

        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto)]
        static extern IntPtr GetModuleHandle(string lpModuleName);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern uint ResumeThread(IntPtr hThread);

        [DllImport("kernel32.dll", SetLastError = true)]
        static extern bool CloseHandle(IntPtr hObject);

        // Constants
        const uint CREATE_SUSPENDED = 0x00000004;
        const uint CREATE_UNICODE_ENVIRONMENT = 0x00000400;
        const uint CREATE_NEW_PROCESS_GROUP = 0x00000200;
        const uint DETACHED_PROCESS = 0x00000008;
        const uint MEM_COMMIT = 0x00001000;
        const uint MEM_RESERVE = 0x00002000;
        const uint PAGE_EXECUTE_READWRITE = 0x40;

        // Structs
        [StructLayout(LayoutKind.Sequential)]
        struct STARTUPINFO
        {
            public uint cb;
            public string lpReserved;
            public string lpDesktop;
            public string lpTitle;
            public uint dwX;
            public uint dwY;
            public uint dwXSize;
            public uint dwYSize;
            public uint dwXCountChars;
            public uint dwYCountChars;
            public uint dwFillAttribute;
            public uint dwFlags;
            public short wShowWindow;
            public short cbReserved2;
            public IntPtr lpReserved2;
            public IntPtr hStdInput;
            public IntPtr hStdOutput;
            public IntPtr hStdError;
        }

        [StructLayout(LayoutKind.Sequential)]
        struct PROCESS_INFORMATION
        {
            public IntPtr hProcess;
            public IntPtr hThread;
            public uint dwProcessId;
            public uint dwThreadId;
        }

        // =============================================================
        // 2. Helper Functions
        // =============================================================


        /// <summary>
        /// Result of a process launch operation
        /// </summary>
        public class LaunchResult
        {
            public bool Success { get; set; }
            public uint ProcessId { get; set; }
            public IntPtr ProcessHandle { get; set; }
            public IntPtr ThreadHandle { get; set; }
            public string? ErrorMessage { get; set; }
        }

        /// <summary>
        /// Configuration for launching MHO Client
        /// </summary>
        public class LaunchConfiguration
        {
            public string MhoDirectory { get; set; } = string.Empty;
            public string MhoExecutable { get; set; } = "MHOClient.exe";
            public string Arguments { get; set; } = "-q 123456789 -src=tgp -game_id 45 -area 1 -zone_id 17306122 -nosplash";
            public string WorkingDirectory { get; set; } = string.Empty;
            public bool InjectDll { get; set; } = false;
            public string? DllPath { get; set; }
        }


        private const uint STARTF_USESHOWWINDOW = 0x00000001;
        private const ushort SW_NORMAL = 1;

        // =============================================================
        // 2. Native Imports
        // =============================================================
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool CreateProcessW(
            string lpApplicationName,
            string lpCommandLine,
            IntPtr lpProcessAttributes,
            IntPtr lpThreadAttributes,
            bool bInheritHandles,
            uint dwCreationFlags,
            IntPtr lpEnvironment,
            string lpCurrentDirectory,
            ref STARTUPINFO lpStartupInfo,
            out PROCESS_INFORMATION lpProcessInformation
        );

        [DllImport("kernel32.dll")]
        private static extern uint GetLastError();

        // =============================================================
        // 3. The Function Translation
        // =============================================================
        public LaunchResult CreateMhoProcessOrg(LaunchConfiguration config)
        {
            var result = new LaunchResult();

            // 1. Prepare Startup Info
            STARTUPINFO si = new STARTUPINFO();
            si.cb = (uint)Marshal.SizeOf(si);

            // This is important: The C++ code explicitly sets the console/window title
            si.lpTitle = "IIPSMsgWnd";
            si.wShowWindow = (short)SW_NORMAL;
            si.dwFlags = STARTF_USESHOWWINDOW;

            PROCESS_INFORMATION pi = new PROCESS_INFORMATION();

            // 2. Build Command Line
            // C++: mho_dir + mho_exe + L" " + mho_arg;
            // We replicate that string concatenation logic exactly.
            string cmdStr = $"\"{Path.Combine(config.MhoDirectory, config.MhoExecutable)}\" {config.Arguments}";

            Console.WriteLine($"Creating process: {cmdStr}");

            // 3. Call CreateProcess
            bool ret = CreateProcessW(
                null,               // lpApplicationName (NULL in C++ code)
                cmdStr,             // lpCommandLine
                IntPtr.Zero,        // lpProcessAttributes
                IntPtr.Zero,        // lpThreadAttributes
                false,              // bInheritHandles
                CREATE_UNICODE_ENVIRONMENT, // dwCreationFlags
                IntPtr.Zero,        // lpEnvironment
                config.WorkingDirectory,            // lpCurrentDirectory
                ref si,
                out pi
            );

            if (!ret)
            {
                uint err = GetLastError();
                Console.WriteLine($"CreateProcess failed ({err})");
                // Return empty struct (equivalent to C++ returning the memset 0 struct)
                result.ErrorMessage = GetErrorMessage((int)err);
                return result;
            }

            result.Success = true;
            result.ProcessId = pi.dwProcessId;
            result.ProcessHandle = pi.hProcess;
            result.ThreadHandle = pi.hThread;

            Console.WriteLine($"Created Process Success ({pi.dwProcessId})");
            return result;
        }

        /// <summary>
        /// Creates an MHO process in suspended state for injection
        /// </summary>
        public LaunchResult CreateSuspendedProcess(LaunchConfiguration config)
        {
            var result = new LaunchResult();

            try
            {
                STARTUPINFO si = new STARTUPINFO();
                si.cb = (uint)Marshal.SizeOf(si);
                si.lpTitle = "IIPSMsgWnd";
                si.wShowWindow = 1; // SW_NORMAL
                si.dwFlags = 1;     // STARTF_USESHOWWINDOW

                PROCESS_INFORMATION pi;

                string cmdLine = $"\"{Path.Combine(config.MhoDirectory, config.MhoExecutable)}\" {config.Arguments}";
                Console.WriteLine($"Creating process: {cmdLine}");

                // Flags: Suspended | Unicode | New Group | Detached
                uint flags = CREATE_SUSPENDED | CREATE_UNICODE_ENVIRONMENT | CREATE_NEW_PROCESS_GROUP | DETACHED_PROCESS;

                bool success = CreateProcess(
                    null,
                    cmdLine,
                    IntPtr.Zero,
                    IntPtr.Zero,
                    false,
                    flags,
                    IntPtr.Zero,
                    config.WorkingDirectory,
                    ref si,
                    out pi
                );

                if (!success)
                {
                    int err = Marshal.GetLastWin32Error();
                    Console.WriteLine($"CreateProcess failed ({err})");
                    return new () { ProcessHandle = IntPtr.Zero };
                }

                Console.WriteLine($"Created Process Success (PID: {pi.dwProcessId})");
               

                if (!success)
                {
                    int error = Marshal.GetLastWin32Error();
                    result.ErrorMessage = GetErrorMessage(error);
                    return result;
                }

                result.Success = true;
                result.ProcessId = pi.dwProcessId;
                result.ProcessHandle = pi.hProcess;
                result.ThreadHandle = pi.hThread;

                Console.WriteLine($"Created Process Successfully (PID: {result.ProcessId})");
                return result;
            }
            catch (Exception ex)
            {
                result.ErrorMessage = $"Exception during process creation: {ex.Message}";
                return result;
            }
        }

        /// <summary>
        /// Injects a DLL into a suspended process and resumes it
        /// </summary>
        public bool InjectDllAndResume(LaunchResult pi, string dllPath)
        {
            if (!pi.Success || pi.ProcessHandle == IntPtr.Zero)
            {
                Console.WriteLine("Invalid process handle for injection");
                return false;
            }

            try
            {
                if (pi.ProcessHandle == IntPtr.Zero) return false;

                string dllName = "mho_launcher_lib.dll"; // Name of your C# DLL or Native DLL
                                                         // Note: If using the C# DLL we made previously, ensure it's compiled as x86/x64 correctly.

                if (!File.Exists(dllPath))
                {
                    Console.Error.WriteLine($"Error: DLL not found at {dllPath}");
                    return false;
                }

                // 1. Allocate Memory
                // Need space for the string (path) + null terminator. Unicode = 2 bytes per char.
                uint size = (uint)((dllPath.Length + 1) * 2);
                IntPtr allocMem = VirtualAllocEx(pi.ProcessHandle, IntPtr.Zero, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

                if (allocMem == IntPtr.Zero)
                {
                    Console.Error.WriteLine("VirtualAllocEx failed.");
                    return false;
                }

                // 2. Write DLL Path to Memory
                byte[] bytes = Encoding.Unicode.GetBytes(dllPath);
                WriteProcessMemory(pi.ProcessHandle, allocMem, bytes, (uint)bytes.Length, out _);

                // 3. Get LoadLibraryW Address
                IntPtr kernel32 = GetModuleHandle("kernel32.dll");
                IntPtr loadLibraryAddr = GetProcAddress(kernel32, "LoadLibraryW");

                if (loadLibraryAddr == IntPtr.Zero)
                {
                    Console.Error.WriteLine("Failed to find LoadLibraryW.");
                    return false;
                }

                // 4. Create Remote Thread
                IntPtr remoteThread = CreateRemoteThread(pi.ProcessHandle, IntPtr.Zero, 0, loadLibraryAddr, allocMem, 0, IntPtr.Zero);

                if (remoteThread == IntPtr.Zero)
                {
                    Console.Error.WriteLine("CreateRemoteThread failed.");
                }
                else
                {
                    Console.WriteLine("Injection thread created successfully.");
                    // Optional: Wait for thread to finish (WaitForSingleObject) to ensure DLL is loaded before resuming
                    // WaitForSingleObject(remoteThread, 5000); 
                    CloseHandle(remoteThread);
                }

                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Exception during DLL injection: {ex.Message}");
                return false;
            }
        }

        /// <summary>
        /// Resumes a suspended process thread
        /// </summary>
        public bool ResumeProcess(LaunchResult processInfo)
        {
            if (processInfo.ThreadHandle == IntPtr.Zero)
            {
                Console.WriteLine("Invalid thread handle");
                return false;
            }

            uint result = ResumeThread(processInfo.ThreadHandle);
            if (result == uint.MaxValue)
            {
                int error = Marshal.GetLastWin32Error();
                Console.WriteLine($"ResumeThread failed with error code {error}");
                return false;
            }

            Console.WriteLine("Process resumed successfully");
            return true;
        }

        /// <summary>
        /// Cleans up process handles
        /// </summary>
        public void CleanupHandles(LaunchResult processInfo)
        {
            if (processInfo.ProcessHandle != IntPtr.Zero)
            {
                CloseHandle(processInfo.ProcessHandle);
            }
            if (processInfo.ThreadHandle != IntPtr.Zero)
            {
                CloseHandle(processInfo.ThreadHandle);
            }
        }

        /// <summary>
        /// Gets the directory where the current executable is located
        /// </summary>
        public static string GetExecutableDirectory()
        {
            string? exePath = Process.GetCurrentProcess().MainModule?.FileName;
            if (string.IsNullOrEmpty(exePath))
            {
                return Directory.GetCurrentDirectory();
            }
            return Path.GetDirectoryName(exePath) ?? Directory.GetCurrentDirectory();
        }

        /// <summary>
        /// Gets the default DLL path for injection (Rathalos.Hook.dll in executable directory)
        /// </summary>
        public static string GetDefaultDllPath()
        {
            return Path.Combine(GetExecutableDirectory(), "libs", "mho_launcher_lib.dll");
            //return Path.Combine(GetExecutableDirectory(), "Rathalos.Hook.dll");
        }

        /// <summary>
        /// Checks if the current process is running with Administrator privileges
        /// </summary>
        public static bool IsRunningAsAdmin()
        {
            try
            {
                using var identity = WindowsIdentity.GetCurrent();
                var principal = new WindowsPrincipal(identity);
                return principal.IsInRole(WindowsBuiltInRole.Administrator);
            }
            catch
            {
                return false;
            }
        }

        /// <summary>
        /// Gets a descriptive error message for common Win32 error codes
        /// </summary>
        private static string GetErrorMessage(int errorCode)
        {
            return errorCode switch
            {
                ERROR_ELEVATION_REQUIRED => 
                    $"CreateProcess failed with error code {errorCode} (ERROR_ELEVATION_REQUIRED).\n" +
                    "This operation requires Administrator privileges.\n" +
                    "Please restart the application as Administrator (Right-click -> Run as administrator).",
                ERROR_ACCESS_DENIED => 
                    $"CreateProcess failed with error code {errorCode} (ERROR_ACCESS_DENIED).\n" +
                    "Access was denied. Try running as Administrator.",
                2 => // ERROR_FILE_NOT_FOUND
                    $"CreateProcess failed with error code {errorCode} (ERROR_FILE_NOT_FOUND).\n" +
                    "The executable file was not found. Check the path.",
                3 => // ERROR_PATH_NOT_FOUND
                    $"CreateProcess failed with error code {errorCode} (ERROR_PATH_NOT_FOUND).\n" +
                    "The directory path was not found. Check the path.",
                _ => $"CreateProcess failed with error code {errorCode}"
            };
        }
    }
}
