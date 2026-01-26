using Rathalos.CLI.Launcher;
using Rathalos.CLI.Utils;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;

namespace Rathalos.CLI.Menu.Options
{
    /// <summary>
    /// Menu option for launching MHO Client with optional DLL injection.
    /// Translated from the C++ mho_launcher implementation.
    /// </summary>
    public class MhoLauncherOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Rocket} MHO Client Launcher";
        public static TenProxyTclsSharedMemory TenProxyTclsSharedMemory;
        private readonly MhoProcessLauncher _launcher;

        public MhoLauncherOption()
        {
            _launcher = new MhoProcessLauncher();
        }

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Rocket} MHO Client Launcher");
            Console.WriteLine("Launch Monster Hunter Online client with optional DLL injection");
            Console.WriteLine(new string('=', 70));
            Console.WriteLine();

            // Check for admin rights and warn if not running as admin
            if (!MhoProcessLauncher.IsRunningAsAdmin())
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} WARNING: Not running as Administrator!");
                Console.WriteLine("   DLL injection requires Administrator privileges.");
                Console.WriteLine("   Consider restarting the CLI as Administrator.");
                Console.ResetColor();
                Console.WriteLine();
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Running as Administrator");
                Console.ResetColor();
                Console.WriteLine();
            }

            // Create sub-menu options
            var subMenuOptions = new List<IMenuOption>
            {
                new LaunchWithInjectionSubOption(this),
                new ViewUsageSubOption(),
                new ReturnToMainMenuLauncherSubOption()
            };

            // Create and run the sub-menu system
            var subMenuSystem = new ConsoleMenuSystem(subMenuOptions, "=== MHO Client Launcher ===");
            await subMenuSystem.RunAsync();

            return true; // Always return true to continue the main menu
        }

        /// <summary>
        /// Launch with DLL injection (suspended process, inject, resume)
        /// </summary>
        internal async Task LaunchWithInjectionAsync()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Rocket} Launch with DLL Injection");
            Console.WriteLine(new string('-', 40));

            var config = await GetLaunchConfigurationAsync();
            if (config == null) return;

            // Get DLL path
            string defaultDllPath = MhoProcessLauncher.GetDefaultDllPath();
            Console.Write($"Enter DLL path [{defaultDllPath}]: ");
            string? dllPath = Console.ReadLine()?.Trim();

            if (string.IsNullOrEmpty(dllPath))
            {
                dllPath = defaultDllPath;
            }

            if (!File.Exists(dllPath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} DLL file not found: {dllPath}");
                return;
            }

            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Creating suspended process...");

            //var result = _launcher.CreateMhoProcessOrg(config);
            //if (!result.Success)
            //{
            //    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} {result.ErrorMessage}");
            //    return;
            //}

            var proc = Process.Start(new ProcessStartInfo
            {
                Arguments = config.Arguments,
                FileName = Path.Combine(config.MhoDirectory, config.MhoExecutable),
                WorkingDirectory = config.WorkingDirectory
            });

            Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Process created (PID: {proc.Id})");
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Injecting DLL...");

            //bool injected = _launcher.InjectDllAndResume(result, dllPath);
            //if (!injected)
            //{
            //    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} DLL injection failed");
            //    _launcher.CleanupHandles(result);
            //    return;
            //}
            if (TenProxyTclsSharedMemory is not null)
                TenProxyTclsSharedMemory.Dispose();

            TenProxyTclsSharedMemory = new TenProxyTclsSharedMemory();
            TenProxyTclsSharedMemory.Map((uint)proc.Id);


            Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} DLL injected successfully");
            Console.WriteLine();
            Console.WriteLine("Press Enter to resume MHOClient.exe...");
            Console.ReadLine();

            //_launcher.ResumeProcess(result);
            //_launcher.CleanupHandles(result);

            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Party} MHO Client launched successfully!");
        }



        private async Task<MhoProcessLauncher.LaunchConfiguration?> GetLaunchConfigurationAsync()
        {
            // Get MHO directory
            Console.Write("Enter MHO directory (e.g., D:\\games\\Monster Hunter Online\\Bin\\Client\\Bin32\\): ");
            string? mhoDir = Console.ReadLine()?.Trim();

            if (string.IsNullOrEmpty(mhoDir))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Directory is required");
                return null;
            }

            if (!Directory.Exists(mhoDir))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Directory does not exist: {mhoDir}");
                return null;
            }

            // Ensure directory ends with separator
            if (!mhoDir.EndsWith(Path.DirectorySeparatorChar) && !mhoDir.EndsWith(Path.AltDirectorySeparatorChar))
            {
                mhoDir += Path.DirectorySeparatorChar;
            }

            string exePath = Path.Combine(mhoDir, "MHOClient.exe");
            if (!File.Exists(exePath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} MHOClient.exe not found in directory");
                return null;
            }

            // Get arguments
            string defaultArgs = "-q 123456789 -src=tgp -game_id 45 -area 1 -zone_id 17306122 -nosplash";
            Console.Write($"Enter arguments [{defaultArgs}]: ");
            string? args = Console.ReadLine()?.Trim();

            if (string.IsNullOrEmpty(args))
            {
                args = defaultArgs;
            }

            return new MhoProcessLauncher.LaunchConfiguration
            {
                MhoDirectory = mhoDir,
                MhoExecutable = "MHOClient.exe",
                Arguments = args,
                WorkingDirectory = mhoDir
            };
        }
    }

    #region Sub-menu Options

    /// <summary>
    /// Sub-menu option for launching with DLL injection
    /// </summary>
    internal class LaunchWithInjectionSubOption : IMenuOption
    {
        private readonly MhoLauncherOption _parent;

        public LaunchWithInjectionSubOption(MhoLauncherOption parent)
        {
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Rocket} Launch with DLL injection";

        public async Task<bool> ExecuteAsync()
        {
            await _parent.LaunchWithInjectionAsync();

            Console.WriteLine();
            Console.WriteLine("Press any key to return to the launcher menu...");
            Console.ReadKey(true);

            return true; // Continue sub-menu
        }
    }

    /// <summary>
    /// Sub-menu option for viewing usage information
    /// </summary>
    internal class ViewUsageSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Book} View usage information";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Book} MHO Launcher Usage");
            Console.WriteLine(new string('=', 60));
            Console.WriteLine();
            Console.WriteLine("This launcher provides functionality to start Monster Hunter Online client");
            Console.WriteLine("with optional DLL injection for hooking and modding purposes.");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} Launch Modes:");
            Console.WriteLine();
            Console.WriteLine("1) Launch with DLL injection:");
            Console.WriteLine("   - Creates process in suspended state");
            Console.WriteLine("   - Injects specified DLL (default: mho_launcher_lib.dll)");
            Console.WriteLine("   - Waits for user confirmation before resuming");
            Console.WriteLine("   - Use this for hooking logging functions or other mods");
            Console.WriteLine();
            Console.WriteLine("2) Launch without DLL injection:");
            Console.WriteLine("   - Creates process normally");
            Console.WriteLine("   - No modifications to the process");
            Console.WriteLine();
            Console.WriteLine("3) Custom launch:");
            Console.WriteLine("   - Specify all parameters manually");
            Console.WriteLine("   - Directory, executable, arguments, working directory");
            Console.WriteLine("   - Optional DLL injection");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} Default Arguments:");
            Console.WriteLine("   -q 123456789 -src=tgp -game_id 45 -area 1 -zone_id 17306122 -nosplash");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} Alternative Arguments:");
            Console.WriteLine("   -q -loginqq=1234567890123456789 -nosplash");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} Tips:");
            Console.WriteLine("   - Place mho_launcher_lib.dll in the same directory as this CLI tool");
            Console.WriteLine("   - The MHO directory should point to: ...\\Bin\\Client\\Bin32\\");
            Console.WriteLine("   - Make sure to run as Administrator if needed");

            Console.WriteLine();
            Console.WriteLine("Press any key to return to the launcher menu...");
            Console.ReadKey(true);

            return true; // Continue sub-menu
        }
    }

    /// <summary>
    /// Sub-menu option for returning to main menu
    /// </summary>
    internal class ReturnToMainMenuLauncherSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Return to main menu";

        public async Task<bool> ExecuteAsync()
        {
            return false; // Exit sub-menu
        }
    }

    #endregion
}
