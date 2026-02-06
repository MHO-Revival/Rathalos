namespace Rathalos.CLI.Menu
{
    /// <summary>
    /// Console menu system with arrow key navigation and scrolling support
    /// </summary>
    public class ConsoleMenuSystem
    {
        private readonly List<IMenuOption> _menuOptions;
        private int _currentSelection;
        private int _scrollOffset;
        private readonly string _customTitle;
        private const int HeaderLines = 3; // Title + instructions + empty line
        private const int FooterLines = 2; // Empty line + footer text

        public ConsoleMenuSystem(List<IMenuOption> menuOptions)
        {
            _menuOptions = menuOptions ?? throw new ArgumentNullException(nameof(menuOptions));
            _currentSelection = 0;
            _scrollOffset = 0;
            _customTitle = "=== Rathalos CLI Menu ===";
        }

        public ConsoleMenuSystem(List<IMenuOption> menuOptions, string customTitle)
        {
            _menuOptions = menuOptions ?? throw new ArgumentNullException(nameof(menuOptions));
            _currentSelection = 0;
            _scrollOffset = 0;
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
                    case ConsoleKey.PageUp:
                        PageUp();
                        break;
                    case ConsoleKey.PageDown:
                        PageDown();
                        break;
                    case ConsoleKey.Home:
                        MoveToStart();
                        break;
                    case ConsoleKey.End:
                        MoveToEnd();
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

            int consoleHeight = Console.WindowHeight;
            int totalItems = _menuOptions.Count;

            // Calculate base available lines for items
            int baseAvailableLines = consoleHeight - HeaderLines - FooterLines;

            // Determine if we need scrolling at all
            bool needsScrolling = totalItems > baseAvailableLines;

            // If scrolling is needed, reserve space for scroll indicators (up to 2 lines)
            int scrollIndicatorLines = 0;
            if (needsScrolling)
            {
                scrollIndicatorLines = 2; // Reserve space for both indicators
            }

            int visibleCount = Math.Max(1, baseAvailableLines - scrollIndicatorLines - 1);

            // Adjust scroll offset to keep selection visible
            if (_currentSelection < _scrollOffset)
            {
                _scrollOffset = _currentSelection;
            }
            else if (_currentSelection >= _scrollOffset + visibleCount)
            {
                _scrollOffset = _currentSelection - visibleCount + 1;
            }

            // Ensure scroll offset is valid
            int maxScrollOffset = Math.Max(0, totalItems - visibleCount);
            _scrollOffset = Math.Max(0, Math.Min(_scrollOffset, maxScrollOffset));

            // Determine which indicators are actually needed
            bool showTopIndicator = _scrollOffset > 0;
            bool showBottomIndicator = (_scrollOffset + visibleCount) < totalItems;

            // Write header
            Console.WriteLine(_customTitle);
            Console.WriteLine("Use ↑/↓ to navigate, Enter to select, Esc to go back");
            Console.WriteLine();

            // Show scroll indicator at top if needed
            if (showTopIndicator)
            {
                Console.ForegroundColor = ConsoleColor.DarkGray;
                Console.WriteLine($"  ▲ {_scrollOffset} more item(s) above");
                Console.ResetColor();
            }

            // Display visible items
            int endIndex = Math.Min(_scrollOffset + visibleCount, totalItems);
            for (int i = _scrollOffset; i < endIndex; i++)
            {
                if (i == _currentSelection)
                {
                    Console.BackgroundColor = ConsoleColor.DarkGray;
                    Console.ForegroundColor = ConsoleColor.White;
                    Console.WriteLine($"> {_menuOptions[i].DisplayName}");
                    Console.ResetColor();
                }
                else
                {
                    Console.WriteLine($"  {_menuOptions[i].DisplayName}");
                }
            }

            // Show scroll indicator at bottom if needed
            if (showBottomIndicator)
            {
                int remainingBelow = totalItems - endIndex;
                Console.ForegroundColor = ConsoleColor.DarkGray;
                Console.WriteLine($"  ▼ {remainingBelow} more item(s) below");
                Console.ResetColor();
            }

            // Footer
            Console.WriteLine();
            if (needsScrolling)
            {
                Console.WriteLine($"[{_currentSelection + 1}/{totalItems}] PgUp/PgDn for fast scroll, Home/End to jump");
            }
            else
            {
                Console.WriteLine("Press Esc to go back.");
            }
        }

        private int GetVisibleItemCount()
        {
            int consoleHeight = Console.WindowHeight;
            int baseAvailableLines = consoleHeight - HeaderLines - FooterLines;
            bool needsScrolling = _menuOptions.Count > baseAvailableLines;
            int scrollIndicatorLines = needsScrolling ? 2 : 0;
            return Math.Max(1, baseAvailableLines - scrollIndicatorLines - 1);
        }

        private void MoveUp()
        {
            _currentSelection = _currentSelection == 0 ? _menuOptions.Count - 1 : _currentSelection - 1;
        }

        private void MoveDown()
        {
            _currentSelection = _currentSelection == _menuOptions.Count - 1 ? 0 : _currentSelection + 1;
        }

        private void PageUp()
        {
            int visibleCount = GetVisibleItemCount();
            _currentSelection = Math.Max(0, _currentSelection - visibleCount);
        }

        private void PageDown()
        {
            int visibleCount = GetVisibleItemCount();
            _currentSelection = Math.Min(_menuOptions.Count - 1, _currentSelection + visibleCount);
        }

        private void MoveToStart()
        {
            _currentSelection = 0;
            _scrollOffset = 0;
        }

        private void MoveToEnd()
        {
            _currentSelection = _menuOptions.Count - 1;
        }

        private async Task<bool> ExecuteSelectedOptionAsync()
        {
            try
            {
                var selectedOption = _menuOptions[_currentSelection];

                // Let the option handle its own display
                bool shouldContinue = await selectedOption.ExecuteAsync();

                return shouldContinue;
            }
            catch (Exception ex)
            {
                Console.Clear();
                Console.WriteLine($"Error executing option: {ex.Message}");
                Console.WriteLine("Press any key to return to the menu...");
                Console.ReadKey(true);
                return true; // Continue menu on error
            }
        }
    }
}