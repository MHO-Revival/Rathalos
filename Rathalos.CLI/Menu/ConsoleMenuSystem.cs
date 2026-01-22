namespace Rathalos.CLI.Menu
{
    /// <summary>
    /// Console menu system with arrow key navigation
    /// </summary>
    public class ConsoleMenuSystem
    {
        private readonly List<IMenuOption> _menuOptions;
        private int _currentSelection;
        private readonly string _customTitle;

        public ConsoleMenuSystem(List<IMenuOption> menuOptions)
        {
            _menuOptions = menuOptions ?? throw new ArgumentNullException(nameof(menuOptions));
            _currentSelection = 0;
            _customTitle = "=== Rathalos CLI Menu ===";
        }

        public ConsoleMenuSystem(List<IMenuOption> menuOptions, string customTitle)
        {
            _menuOptions = menuOptions ?? throw new ArgumentNullException(nameof(menuOptions));
            _currentSelection = 0;
            _customTitle = customTitle ?? "=== Rathalos CLI Menu ===";
        }

        /// <summary>
        /// Display the menu and handle user input
        /// </summary>
        public async Task RunAsync()
        {
            bool shouldContinue = true;

            while (shouldContinue)
            {
                DisplayMenu();
                var keyInfo = Console.ReadKey(true);

                switch (keyInfo.Key)
                {
                    case ConsoleKey.UpArrow:
                        MoveUp();
                        break;
                    case ConsoleKey.DownArrow:
                        MoveDown();
                        break;
                    case ConsoleKey.Enter:
                        shouldContinue = await ExecuteSelectedOptionAsync();
                        break;
                    case ConsoleKey.Escape:
                        shouldContinue = false;
                        break;
                }
            }
        }

        private void DisplayMenu()
        {
            Console.Clear();
            Console.WriteLine(_customTitle);
            Console.WriteLine("Use ↑/↓ arrows to navigate, Enter to select, Esc to exit");
            Console.WriteLine();

            for (int i = 0; i < _menuOptions.Count; i++)
            {
                if (i == _currentSelection)
                {
                    Console.BackgroundColor = ConsoleColor.DarkGray;
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine($"> {_menuOptions[i].DisplayName}");
                }
                else
                {
                    Console.WriteLine($"  {_menuOptions[i].DisplayName}");
                }
                Console.ResetColor();
            }

            Console.WriteLine();
            Console.WriteLine("Press Esc to exit the application.");
        }

        private void MoveUp()
        {
            _currentSelection = _currentSelection == 0 ? _menuOptions.Count - 1 : _currentSelection - 1;
        }

        private void MoveDown()
        {
            _currentSelection = _currentSelection == _menuOptions.Count - 1 ? 0 : _currentSelection + 1;
        }

        private async Task<bool> ExecuteSelectedOptionAsync()
        {
            try
            {
                var selectedOption = _menuOptions[_currentSelection];
                Console.Clear();
                Console.WriteLine($"Executing: {selectedOption.DisplayName}");
                Console.WriteLine(new string('=', 50));
                Console.WriteLine();

                bool shouldContinue = await selectedOption.ExecuteAsync();

                if (shouldContinue)
                {
                    Console.WriteLine();
                    Console.WriteLine("Press any key to return to the menu...");
                    Console.ReadKey(true);
                }

                return shouldContinue;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error executing option: {ex.Message}");
                Console.WriteLine("Press any key to return to the menu...");
                Console.ReadKey(true);
                return true; // Continue menu on error
            }
        }
    }
}