
using Microsoft.Extensions.Logging;

namespace Rathalos.Servers.Base.Services
{
	public sealed class LoggingService : WarmupService<LoggingService>
	{
		private readonly ILoggerFactory _loggerFactory;
		private readonly ILogger _logger;

		public LoggingService(ILoggerFactory loggerFactory)
		{
			_loggerFactory = loggerFactory;
			_logger = _loggerFactory.CreateLogger("Logs");
		}

		public ILogger CreateLogger<T>()
		{
			return _loggerFactory.CreateLogger(typeof(T).Name);
		}

		public void LogInformation(string message)
		{
			_logger.LogInformation(message);
		}

		public void LogError(string message)
		{
			_logger.LogError(message);
		}

		public void LogWarning(string message)
		{
			_logger.LogWarning(message);
		}

		public void LogDebug(string message)
		{
			_logger.LogDebug(message);
		}

		public void LogCritical(string message)
		{
			_logger.LogCritical(message);
		}

		public void LogTrace(string message)
		{
			_logger.LogTrace(message);
		}
	}
}
