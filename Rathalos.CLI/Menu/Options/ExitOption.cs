using Rathalos.CLI.Utils;

namespace Rathalos.CLI.Menu.Options
{
    /// <summary>
    /// Menu option handler for exiting the application
    /// </summary>
    public class ExitOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Exit Application";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine("Are you sure you want to exit? (y/N): ");
            var response = Console.ReadLine()?.Trim().ToLowerInvariant();
            
            if (response == "y" || response == "yes")
            {
                Console.WriteLine("Shutting down Rathalos CLI...");
                await Task.Delay(1000);
                Console.WriteLine("Thank you for using Rathalos!");
                return false; // Exit the application
            }
            
            Console.WriteLine("Operation cancelled.");
            return true; // Continue menu
        }
    }
}