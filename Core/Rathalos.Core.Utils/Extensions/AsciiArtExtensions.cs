using System.Text;

namespace Rathalos.Core.Utils.Extensions
{
	public static class AsciiArtExtensions
	{
		public static string[] RathalosArt()
		{
			return new[]
            {
				"██████╗  █████╗ ████████╗██╗  ██╗ █████╗ ██╗      ██████╗ ███████╗",
				"██╔══██╗██╔══██╗╚══██╔══╝██║  ██║██╔══██╗██║     ██╔═══██╗██╔════╝",
				"██████╔╝███████║   ██║   ███████║███████║██║     ██║   ██║███████╗",
				"██╔══██╗██╔══██║   ██║   ██╔══██║██╔══██║██║     ██║   ██║╚════██║",
				"██║  ██║██║  ██║   ██║   ██║  ██║██║  ██║███████╗╚██████╔╝███████║",
				"╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝",
                "                                                  				   ",
			};
		}

		private static readonly ConsoleColor[] _colors;

		public static int BufferWidth => Console.IsOutputRedirected ? 0 : Console.BufferWidth;

		static AsciiArtExtensions()
		{
			_colors = Enum.GetValues<ConsoleColor>().Except(new[] {ConsoleColor.Black}).ToArray();
		}

		public static void PrintCenteredAsciiArt(this string[] asciiArt)
		{
			Console.OutputEncoding = Encoding.UTF8;
			Console.ForegroundColor = GetRandomConsoleColor();
			foreach (string line in asciiArt)
			{
				int pad = (BufferWidth + line.Length) / 2;

				Console.WriteLine(line.PadLeft(pad));
			}
			Console.ResetColor();
		}

		private static ConsoleColor GetRandomConsoleColor()
		{
			return _colors[Random.Shared.Next(_colors.Length)];
		}
	}
}
