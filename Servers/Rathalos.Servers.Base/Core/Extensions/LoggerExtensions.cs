using Rathalos.Core.Utils.Consoles;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Logging.Abstractions;
using Microsoft.Extensions.Logging.Console;
using Microsoft.Extensions.Options;

namespace Rathalos.Servers.Base.Core.Extensions
{

	public static class ConsoleLoggerExtensions
	{
		public static ILoggingBuilder AddCustomFormatter(this ILoggingBuilder builder) =>
			builder.AddConsole(options => options.FormatterName = nameof(CustomLoggingFormatter))
				.AddConsoleFormatter<CustomLoggingFormatter, ConsoleFormatterOptions>();
	}
	public sealed class CustomLoggingFormatter : ConsoleFormatter, IDisposable
	{
		private readonly IDisposable _optionsReloadToken;
		private ConsoleFormatterOptions _formatterOptions;

		public CustomLoggingFormatter(IOptionsMonitor<ConsoleFormatterOptions> options) : base(nameof(CustomLoggingFormatter)) =>
			(_optionsReloadToken, _formatterOptions) = (options.OnChange(ReloadLoggerOptions), options.CurrentValue);

		private void ReloadLoggerOptions(ConsoleFormatterOptions options) =>
			_formatterOptions = options;

		public override void Write<TState>(in LogEntry<TState> logEntry, IExternalScopeProvider scopeProvider, TextWriter textWriter)
		{
			string message = logEntry.Formatter?.Invoke(logEntry.State, logEntry.Exception);

			if (message is null)
			{
				return;
			}

			if (logEntry.Category.Contains("Microsoft."))
				return;

			string color = logEntry.LogLevel switch
			{
				LogLevel.Trace => ConsoleAttributes.LightMagenta,
				LogLevel.Debug => ConsoleAttributes.Magenta,
				LogLevel.Information => ConsoleAttributes.Green,
				LogLevel.Warning => ConsoleAttributes.Yellow,
				LogLevel.Error => ConsoleAttributes.LightRed,
				LogLevel.Critical => ConsoleAttributes.Red,
				LogLevel.None => "",
				_ => ConsoleAttributes.Cyan,
			};

			var logCategoryName = logEntry.Category.Split(".").LastOrDefault();
			string logName = new ConsoleFormat(GetShortNameLogLevel(logEntry.LogLevel), ConsoleAttributes.Bold, ConsoleAttributes.Underline, color);
			string category = new ConsoleFormat(logCategoryName, ConsoleAttributes.White);

            if (logCategoryName.EndsWith("Handler"))
                category = new ConsoleFormat(logCategoryName, ConsoleAttributes.LightYellow);
			else if (logCategoryName.EndsWith("Client") || logCategoryName.EndsWith("Server"))
				category = new ConsoleFormat(logCategoryName, ConsoleAttributes.LightCyan);

			textWriter.WriteLine($"{logName}: ({category}) => {message}");
		}

		public static string GetShortNameLogLevel(LogLevel level)
		{
			return level switch
			{
				LogLevel.Information => "info",
				LogLevel.Warning => "warn",
				LogLevel.Critical => "crit",
				_ => level.ToString().ToLowerInvariant(),
			};
		}

		public void Dispose() => _optionsReloadToken?.Dispose();
	}
}
