using System.Runtime.InteropServices;

namespace Rathalos.CLI.Utils
{
    /// <summary>
    /// Utility class for handling console display with emoji support detection
    /// </summary>
    public static class ConsoleDisplayHelper
    {
        private static bool? _supportsEmojis = null;
        
        /// <summary>
        /// Checks if the current console supports emoji display
        /// </summary>
        public static bool SupportsEmojis
        {
            get
            {
                if (_supportsEmojis == null)
                {
                    _supportsEmojis = DetectEmojiSupport();
                }
                return _supportsEmojis.Value;
            }
        }

        /// <summary>
        /// Display icons with fallback support
        /// </summary>
        public static class Icons
        {
            public static string Wrench => SupportsEmojis ? "🔧" : "[TOOL]";
            public static string Folder => SupportsEmojis ? "📁" : "[DIR]";
            public static string File => SupportsEmojis ? "📂" : "[FILE]";
            public static string Document => SupportsEmojis ? "📋" : "[DOC]";
            public static string Book => SupportsEmojis ? "📖" : "[INFO]";
            public static string Back => SupportsEmojis ? "🔙" : "[BACK]";
            public static string CheckMark => SupportsEmojis ? "✅" : "[OK]";
            public static string Error => SupportsEmojis ? "❌" : "[ERROR]";
            public static string Search => SupportsEmojis ? "🔍" : "[SEARCH]";
            public static string Gear => SupportsEmojis ? "⚙️" : "[CONFIG]";
            public static string Rocket => SupportsEmojis ? "🚀" : "[LAUNCH]";
            public static string Floppy => SupportsEmojis ? "💾" : "[SAVE]";
            public static string Chart => SupportsEmojis ? "📊" : "[STATS]";
            public static string Lightbulb => SupportsEmojis ? "💡" : "[TIP]";
            public static string Party => SupportsEmojis ? "🎉" : "[SUCCESS]";
            public static string Cycle => SupportsEmojis ? "🔄" : "[PROCESS]";
            public static string Diamond => SupportsEmojis ? "🔹" : " - ";
        }

        /// <summary>
        /// Initialize console for best emoji/Unicode support
        /// </summary>
        public static void InitializeConsole()
        {
            try
            {
                // Set UTF-8 encoding for better Unicode support
                Console.OutputEncoding = System.Text.Encoding.UTF8;
                Console.InputEncoding = System.Text.Encoding.UTF8;
                
                // On Windows, try to enable virtual terminal processing for better Unicode support
                if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
                {
                    EnableWindowsUnicodeSupport();
                }
            }
            catch
            {
                // If encoding setup fails, continue without it
                _supportsEmojis = false;
            }
        }

        private static bool DetectEmojiSupport()
        {
            try
            {
                // Test by trying to write an emoji and checking if console encoding supports it
                var originalPosition = Console.CursorTop;
                Console.Write("🔧");
                Console.SetCursorPosition(0, originalPosition);
                Console.Write(" "); // Clear the test character
                Console.SetCursorPosition(0, originalPosition);
                
                // If we got here without exception, assume emoji support
                return Console.OutputEncoding.EncodingName.Contains("UTF-8") || 
                       Console.OutputEncoding.CodePage == 65001; // UTF-8 code page
            }
            catch
            {
                return false;
            }
        }

        private static void EnableWindowsUnicodeSupport()
        {
            if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows))
            {
                try
                {
                    // Try to enable virtual terminal processing on Windows 10+
                    // This improves Unicode and ANSI support
                    const uint ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004;
                    var handle = GetStdHandle(-11); // STD_OUTPUT_HANDLE
                    
                    if (GetConsoleMode(handle, out uint mode))
                    {
                        SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
                    }
                }
                catch
                {
                    // If Windows API calls fail, continue without virtual terminal support
                }
            }
        }

        #region Windows API Imports
        [DllImport("kernel32.dll")]
        private static extern bool GetConsoleMode(IntPtr hConsoleHandle, out uint lpMode);

        [DllImport("kernel32.dll")]
        private static extern bool SetConsoleMode(IntPtr hConsoleHandle, uint dwMode);

        [DllImport("kernel32.dll", SetLastError = true)]
        private static extern IntPtr GetStdHandle(int nStdHandle);
        #endregion
    }
}