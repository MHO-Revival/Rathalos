using Rathalos.CLI.Launcher;
using Rathalos.CLI.Utils;

namespace Rathalos.CLI.Menu.Options
{
    /// <summary>
    /// Menu option for configuring the Windows hosts file with MHO-required entries.
    /// </summary>
    public class HostsFileOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Gear} Configure Hosts File";

        private static readonly string HostsFilePath = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.System),
            "drivers", "etc", "hosts");

        private static readonly Dictionary<string, string> RequiredEntries = new()
        {
            { "tqos.gamesafe.qq.com", "127.0.0.1" },
            { "down.qq.com", "127.0.0.1" },
            { "stat.iips.qq.com", "127.0.0.1" },
            { "ied-tqos.qq.com", "127.0.0.1" },
            { "apps.game.qq.com", "127.0.0.1" }
        };

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Gear} Configure Hosts File");
            Console.WriteLine("Add required host entries for MHO to redirect traffic to localhost");
            Console.WriteLine(new string('=', 70));
            Console.WriteLine();

            // Check for admin rights
            if (!MhoProcessLauncher.IsRunningAsAdmin())
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} This operation requires Administrator privileges!");
                Console.WriteLine("   Please restart the CLI as Administrator.");
                Console.ResetColor();
                return true;
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Running as Administrator");
            Console.ResetColor();
            Console.WriteLine();

            // Create sub-menu options
            var subMenuOptions = new List<IMenuOption>
            {
                new ViewHostsStatusSubOption(),
                new AddHostsEntriesSubOption(),
                new RemoveHostsEntriesSubOption(),
                new ReturnToMainMenuHostsSubOption()
            };

            var subMenuSystem = new ConsoleMenuSystem(subMenuOptions, "=== Hosts File Configuration ===");
            await subMenuSystem.RunAsync();

            return true;
        }

        /// <summary>
        /// Gets the current status of required host entries
        /// </summary>
        internal static Dictionary<string, bool> GetEntriesStatus()
        {
            var status = new Dictionary<string, bool>();
            
            foreach (var entry in RequiredEntries)
            {
                status[entry.Key] = false;
            }

            try
            {
                if (!File.Exists(HostsFilePath))
                {
                    return status;
                }

                var lines = File.ReadAllLines(HostsFilePath);
                foreach (var line in lines)
                {
                    var trimmedLine = line.Trim();
                    
                    // Skip comments and empty lines
                    if (string.IsNullOrEmpty(trimmedLine) || trimmedLine.StartsWith('#'))
                    {
                        continue;
                    }

                    // Parse the line (format: IP hostname)
                    var parts = trimmedLine.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                    if (parts.Length >= 2)
                    {
                        var hostname = parts[1].ToLowerInvariant();
                        if (status.ContainsKey(hostname) && parts[0] == "127.0.0.1")
                        {
                            status[hostname] = true;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Error reading hosts file: {ex.Message}");
            }

            return status;
        }

        /// <summary>
        /// Adds missing host entries to the hosts file
        /// </summary>
        internal static bool AddMissingEntries()
        {
            try
            {
                var status = GetEntriesStatus();
                var missingEntries = status.Where(s => !s.Value).Select(s => s.Key).ToList();

                if (missingEntries.Count == 0)
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} All required entries already exist!");
                    return true;
                }

                // Read existing content
                var existingContent = File.Exists(HostsFilePath) 
                    ? File.ReadAllText(HostsFilePath) 
                    : string.Empty;

                // Ensure we end with a newline before adding entries
                if (!existingContent.EndsWith(Environment.NewLine) && !string.IsNullOrEmpty(existingContent))
                {
                    existingContent += Environment.NewLine;
                }

                // Add MHO section header if not present
                if (!existingContent.Contains("# MHO Revival"))
                {
                    existingContent += Environment.NewLine + "# MHO Revival - Monster Hunter Online" + Environment.NewLine;
                }

                // Add missing entries
                foreach (var hostname in missingEntries)
                {
                    existingContent += $"127.0.0.1 {hostname}" + Environment.NewLine;
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Added: 127.0.0.1 {hostname}");
                }

                File.WriteAllText(HostsFilePath, existingContent);
                Console.WriteLine();
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Party} Successfully added {missingEntries.Count} entries!");
                return true;
            }
            catch (UnauthorizedAccessException)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Access denied. Please run as Administrator.");
                return false;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Error modifying hosts file: {ex.Message}");
                return false;
            }
        }

        /// <summary>
        /// Removes MHO-related entries from the hosts file
        /// </summary>
        internal static bool RemoveEntries()
        {
            try
            {
                if (!File.Exists(HostsFilePath))
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Hosts file not found.");
                    return false;
                }

                var lines = File.ReadAllLines(HostsFilePath).ToList();
                var removedCount = 0;

                for (int i = lines.Count - 1; i >= 0; i--)
                {
                    var trimmedLine = lines[i].Trim();
                    
                    // Remove MHO section header
                    if (trimmedLine.Contains("# MHO Revival"))
                    {
                        lines.RemoveAt(i);
                        continue;
                    }

                    // Skip comments and empty lines
                    if (string.IsNullOrEmpty(trimmedLine) || trimmedLine.StartsWith('#'))
                    {
                        continue;
                    }

                    // Check if this line contains one of our entries
                    var parts = trimmedLine.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                    if (parts.Length >= 2)
                    {
                        var hostname = parts[1].ToLowerInvariant();
                        if (RequiredEntries.ContainsKey(hostname))
                        {
                            Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Removed: {trimmedLine}");
                            lines.RemoveAt(i);
                            removedCount++;
                        }
                    }
                }

                if (removedCount == 0)
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} No MHO entries found to remove.");
                    return true;
                }

                File.WriteAllLines(HostsFilePath, lines);
                Console.WriteLine();
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Party} Successfully removed {removedCount} entries!");
                return true;
            }
            catch (UnauthorizedAccessException)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Access denied. Please run as Administrator.");
                return false;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Error modifying hosts file: {ex.Message}");
                return false;
            }
        }
    }

    #region Sub-menu Options

    /// <summary>
    /// Sub-menu option for viewing current hosts file status
    /// </summary>
    internal class ViewHostsStatusSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Search} View current status";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Search} Hosts File Status");
            Console.WriteLine(new string('-', 50));
            Console.WriteLine();

            var status = HostsFileOption.GetEntriesStatus();
            var allPresent = true;

            Console.WriteLine("Required entries:");
            Console.WriteLine();
            
            foreach (var entry in status)
            {
                if (entry.Value)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine($"  {ConsoleDisplayHelper.Icons.CheckMark} 127.0.0.1 {entry.Key}");
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine($"  {ConsoleDisplayHelper.Icons.Error} 127.0.0.1 {entry.Key} (MISSING)");
                    allPresent = false;
                }
                Console.ResetColor();
            }

            Console.WriteLine();
            if (allPresent)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Party} All required entries are configured!");
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} Some entries are missing. Use 'Add missing entries' to configure them.");
            }
            Console.ResetColor();

            Console.WriteLine();
            Console.WriteLine("Press any key to return...");
            Console.ReadKey(true);
            
            return true;
        }
    }

    /// <summary>
    /// Sub-menu option for adding missing hosts entries
    /// </summary>
    internal class AddHostsEntriesSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Floppy} Add missing entries";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Floppy} Add Missing Hosts Entries");
            Console.WriteLine(new string('-', 50));
            Console.WriteLine();

            Console.WriteLine("This will add the following entries to your hosts file:");
            Console.WriteLine("  127.0.0.1 tqos.gamesafe.qq.com");
            Console.WriteLine("  127.0.0.1 down.qq.com");
            Console.WriteLine("  127.0.0.1 stat.iips.qq.com");
            Console.WriteLine("  127.0.0.1 ied-tqos.qq.com");
            Console.WriteLine("  127.0.0.1 apps.game.qq.com");
            Console.WriteLine();
            Console.Write("Continue? (Y/n): ");
            
            var response = Console.ReadLine()?.Trim().ToLowerInvariant();
            if (response == "n" || response == "no")
            {
                Console.WriteLine("Operation cancelled.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return...");
                Console.ReadKey(true);
                return true;
            }

            Console.WriteLine();
            HostsFileOption.AddMissingEntries();

            Console.WriteLine();
            Console.WriteLine("Press any key to return...");
            Console.ReadKey(true);
            
            return true;
        }
    }

    /// <summary>
    /// Sub-menu option for removing MHO hosts entries
    /// </summary>
    internal class RemoveHostsEntriesSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Error} Remove MHO entries";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Error} Remove MHO Hosts Entries");
            Console.WriteLine(new string('-', 50));
            Console.WriteLine();

            Console.WriteLine("This will remove all MHO-related entries from your hosts file.");
            Console.Write("Are you sure? (y/N): ");
            
            var response = Console.ReadLine()?.Trim().ToLowerInvariant();
            if (response != "y" && response != "yes")
            {
                Console.WriteLine("Operation cancelled.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return...");
                Console.ReadKey(true);
                return true;
            }

            Console.WriteLine();
            HostsFileOption.RemoveEntries();

            Console.WriteLine();
            Console.WriteLine("Press any key to return...");
            Console.ReadKey(true);
            
            return true;
        }
    }

    /// <summary>
    /// Sub-menu option for returning to main menu
    /// </summary>
    internal class ReturnToMainMenuHostsSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Return to main menu";

        public async Task<bool> ExecuteAsync()
        {
            return false;
        }
    }

    #endregion
}
