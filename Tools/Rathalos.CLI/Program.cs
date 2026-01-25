using Rathalos.CLI.Menu;
using Rathalos.CLI.Menu.Options;
using Rathalos.CLI.Utils;

namespace Rathalos.CLI
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            // Initialize console for best Unicode/emoji support
            ConsoleDisplayHelper.InitializeConsole();
            
            Console.Title = "Rathalos CLI - Monster Hunter Online Server";
            
            try
            {
                // Initialize menu options
                var menuOptions = new List<IMenuOption>
                {
                    new XmlCodeGeneratorOption(),
                    new MhoLauncherOption(),
                    new HostsFileOption(),
                    new ExitOption()
                };

                // Create and run the menu system
                var menuSystem = new ConsoleMenuSystem(menuOptions);
                await menuSystem.RunAsync();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Critical error: {ex.Message}");
                Console.WriteLine("Press any key to exit...");
                Console.ReadKey();
            }
        }
    }
}
