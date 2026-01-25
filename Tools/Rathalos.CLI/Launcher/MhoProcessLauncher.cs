using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Text;

namespace Rathalos.CLI.Launcher
{
    /// <summary>
    /// Service for launching and injecting into MHO Client processes.
    /// Translated from the C++ mho_launcher implementation.
    /// </summary>
    public class MhoProcessLauncher
    {
        #region Win32 Constants
        private const uint CREATE_SUSPENDED = 0x00000004;
        private const uint CREATE_UNICODE_ENVIRONMENT = 0x00000400;
        private const uint CREATE_NEW_PROCESS_GROUP = 0x00000200;
        private const uint DETACHED_PROCESS = 0x00000008;
        private const int STARTF_USESHOWWINDOW = 0x00000001;
        private const int SW_NORMAL = 1;
        private const uint MEM_COMMIT = 0x1000;
        private const uint MEM_RESERVE = 0x2000;
        private const uint PAGE_EXECUTE_READWRITE = 0x40;
        
        // Error codes
        private const int ERROR_ELEVATION_REQUIRED = 740;
        private const int ERROR_ACCESS_DENIED = 5;
        #endregion

        #region Win32 Structures
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
        private struct STARTUPINFO
        {
            public int cb;
            public string lpReserved;
            public string lpDesktop;
            public string lpTitle;
            public int dwX;
            public int dwY;
            public int dwXSize;
            public int dwYSize;
            public int dwXCountChars;
            public int dwYCountChars;
            public int dwFillAttribute;
            public int dwFlags;
            public short wShowWindow;
            public short cbReserved2;
            public IntPtr lpReserved2;
            public IntPtr hStdInput;
            public IntPtr hStdOutput;
            public IntPtr hStdError;
        }

        [StructLayout(LayoutKind.Sequential)]
        private struct PROCESS_INFORMATION
        {
            public IntPtr hProcess;
            public IntPtr hThread;
            public int dwProcessId;
            public int dwThreadId;
        }
        #endregion

        #region Win32 Imports
        [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Unicode)]
        private static extern bool CreateProcessW(
            string? lpApplicationName,
            StringBuilder lpCommandLine,
            IntPtr lpProcessAttributes,
            IntPtr lpThreadAttributes,
            bool bInheritHandles,
            uint dwCreationFlags,
            IntPtr lpEnvironment,
            string lpCurrentDirectory,
            ref STARTUPINFO lpStartupInfo,
            out PROCESS_INFORMATION lpProcessInformation);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern IntPtr VirtualAllocEx(
            IntPtr hProcess,
            IntPtr lpAddress,
            uint dwSize,
            uint flAllocationType,
            uint flProtect);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool WriteProcessMemory(
            IntPtr hProcess,
            IntPtr lpBaseAddress,
            byte[] lpBuffer,
            uint nSize,
            out IntPtr lpNumberOfBytesWritten);

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, SetLastError = true)]
        private static extern IntPtr GetProcAddress(IntPtr hModule, string procName);

        [DllImport("kernel32.dll", CharSet = CharSet.Ansi, SetLastError = true)]
        private static extern IntPtr GetModuleHandleA(string lpModuleName);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern IntPtr CreateRemoteThread(
            IntPtr hProcess,
            IntPtr lpThreadAttributes,
            uint dwStackSize,
            IntPtr lpStartAddress,
            IntPtr lpParameter,
            uint dwCreationFlags,
            out IntPtr lpThreadId);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern uint ResumeThread(IntPtr hThread);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern bool CloseHandle(IntPtr hObject);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern uint WaitForSingleObject(IntPtr hHandle, uint dwMilliseconds);
        #endregion

        /// <summary>
        /// Result of a process launch operation
        /// </summary>
        public class LaunchResult
        {
            public bool Success { get; set; }
            public int ProcessId { get; set; }
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

        /// <summary>
        /// Creates an MHO process in suspended state for injection
        /// </summary>
        public LaunchResult CreateSuspendedProcess(LaunchConfiguration config)
        {
            var result = new LaunchResult();

            try
            {
                var startupInfo = new STARTUPINFO
                {
                    cb = Marshal.SizeOf<STARTUPINFO>(),
                    lpTitle = "IIPSMsgWnd",
                    wShowWindow = SW_NORMAL,
                    dwFlags = STARTF_USESHOWWINDOW
                };

                var commandLine = new StringBuilder($"{config.MhoDirectory}{config.MhoExecutable} {config.Arguments}");
                var workDir = string.IsNullOrEmpty(config.WorkingDirectory) ? config.MhoDirectory : config.WorkingDirectory;

                Console.WriteLine($"Creating process: \"{config.MhoDirectory}{config.MhoExecutable} {config.Arguments}\"");

                bool success = CreateProcessW(
                    null,
                    commandLine,
                    IntPtr.Zero,
                    IntPtr.Zero,
                    false,
                    CREATE_SUSPENDED | CREATE_UNICODE_ENVIRONMENT | CREATE_NEW_PROCESS_GROUP | DETACHED_PROCESS,
                    IntPtr.Zero,
                    workDir,
                    ref startupInfo,
                    out PROCESS_INFORMATION processInfo);

                if (!success)
                {
                    int error = Marshal.GetLastWin32Error();
                    result.ErrorMessage = GetErrorMessage(error);
                    return result;
                }

                result.Success = true;
                result.ProcessId = processInfo.dwProcessId;
                result.ProcessHandle = processInfo.hProcess;
                result.ThreadHandle = processInfo.hThread;

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
        /// Creates an MHO process normally (not suspended)
        /// </summary>
        public LaunchResult CreateNormalProcess(LaunchConfiguration config)
        {
            var result = new LaunchResult();

            try
            {
                var startupInfo = new STARTUPINFO
                {
                    cb = Marshal.SizeOf<STARTUPINFO>(),
                    lpTitle = "IIPSMsgWnd",
                    wShowWindow = SW_NORMAL,
                    dwFlags = STARTF_USESHOWWINDOW
                };

                var commandLine = new StringBuilder($"{config.MhoDirectory}{config.MhoExecutable} {config.Arguments}");
                var workDir = string.IsNullOrEmpty(config.WorkingDirectory) ? config.MhoDirectory : config.WorkingDirectory;

                Console.WriteLine($"Creating process: \"{config.MhoDirectory}{config.MhoExecutable} {config.Arguments}\"");

                bool success = CreateProcessW(
                    null,
                    commandLine,
                    IntPtr.Zero,
                    IntPtr.Zero,
                    false,
                    CREATE_UNICODE_ENVIRONMENT,
                    IntPtr.Zero,
                    workDir,
                    ref startupInfo,
                    out PROCESS_INFORMATION processInfo);

                if (!success)
                {
                    int error = Marshal.GetLastWin32Error();
                    result.ErrorMessage = GetErrorMessage(error);
                    return result;
                }

                result.Success = true;
                result.ProcessId = processInfo.dwProcessId;
                result.ProcessHandle = processInfo.hProcess;
                result.ThreadHandle = processInfo.hThread;

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
        public bool InjectDllAndResume(LaunchResult processInfo, string dllPath)
        {
            if (!processInfo.Success || processInfo.ProcessHandle == IntPtr.Zero)
            {
                Console.WriteLine("Invalid process handle for injection");
                return false;
            }

            try
            {
                // Convert DLL path to Unicode bytes
                byte[] dllPathBytes = Encoding.Unicode.GetBytes(dllPath + "\0");
                uint dllPathSize = (uint)dllPathBytes.Length;

                // Allocate memory in the target process for the DLL path
                IntPtr remoteMemory = VirtualAllocEx(
                    processInfo.ProcessHandle,
                    IntPtr.Zero,
                    dllPathSize,
                    MEM_COMMIT | MEM_RESERVE,
                    PAGE_EXECUTE_READWRITE);

                if (remoteMemory == IntPtr.Zero)
                {
                    int error = Marshal.GetLastWin32Error();
                    Console.WriteLine($"VirtualAllocEx failed with error code {error}");
                    return false;
                }

                // Write the DLL path into the allocated memory
                bool writeSuccess = WriteProcessMemory(
                    processInfo.ProcessHandle,
                    remoteMemory,
                    dllPathBytes,
                    dllPathSize,
                    out _);

                if (!writeSuccess)
                {
                    int error = Marshal.GetLastWin32Error();
                    Console.WriteLine($"WriteProcessMemory failed with error code {error}");
                    return false;
                }

                // Get the address of LoadLibraryW from kernel32.dll
                IntPtr kernel32Handle = GetModuleHandleA("Kernel32");
                IntPtr loadLibraryAddr = GetProcAddress(kernel32Handle, "LoadLibraryW");

                if (loadLibraryAddr == IntPtr.Zero)
                {
                    Console.WriteLine("Failed to get LoadLibraryW address");
                    return false;
                }

                // Create a remote thread that calls LoadLibraryW with the DLL path
                IntPtr remoteThread = CreateRemoteThread(
                    processInfo.ProcessHandle,
                    IntPtr.Zero,
                    0,
                    loadLibraryAddr,
                    remoteMemory,
                    0,
                    out _);

                if (remoteThread == IntPtr.Zero)
                {
                    int error = Marshal.GetLastWin32Error();
                    Console.WriteLine($"CreateRemoteThread failed with error code {error}");
                    return false;
                }

                Console.WriteLine($"DLL injection initiated for: {dllPath}");

                // Wait for the injection thread to complete (optional, with timeout)
                WaitForSingleObject(remoteThread, 5000);
                CloseHandle(remoteThread);

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
            return Path.Combine(GetExecutableDirectory(), "Rathalos.Hook.dll");
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
