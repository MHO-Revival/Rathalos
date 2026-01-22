namespace Rathalos.Servers.Base.Services.Threads
{
	public sealed class ScheduledTask : IDisposable
	{
		private DateTime executionTime;

		public ScheduledTask(double secondsInterval, Action action, bool isInfinite)
		{
			SecondsInterval = secondsInterval;
			Action = action;
			IsInfinite = isInfinite;

			Postpone();
		}

		internal double SecondsInterval { get; set; }
		internal Action Action { get; set; }
		internal bool IsInfinite { get; set; }

		internal bool IsPaused { get; private set; }
		internal bool IsDisposed { get; private set; }

		public bool CanTrigger => DateTime.Now > executionTime;

		public void Postpone()
		{
			executionTime = DateTime.Now.AddSeconds(SecondsInterval);
		}

		public void Trigger()
		{
			if (IsDisposed)
				return;

			try
			{
				if (Action is not null)
					Task.Run(Action);
			}
			catch (Exception e)
			{
				LoggingService.Instance.LogError($"{e.Message}\nStackTrace: {e.StackTrace}");
			}

			if (IsInfinite)
				Postpone();
			else
				Dispose();
		}

		public void Resume()
		{
			IsPaused = false;
		}

		public void Pause()
		{
			IsPaused = true;
		}

		public void Dispose()
		{
			Pause();
			IsDisposed = true;
		}

	}
}
