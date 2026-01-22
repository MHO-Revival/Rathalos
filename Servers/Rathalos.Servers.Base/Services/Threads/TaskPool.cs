using System.Collections.Concurrent;

namespace Rathalos.Servers.Base.Services.Threads
{
	public sealed class TaskPool
	{
		private ConcurrentQueue<ScheduledTask> _scheduledTasks = new();
		private readonly ConcurrentQueue<Func<Task>> _synchronizedActions = new();
		private readonly Guid _id;
		private readonly string _name;
		private CancellationTokenSource _tokenSource;

		public TaskPool(string name)
		{
			this._id = Guid.NewGuid();
			this._name = name;
		}

		public Guid Id => this._id;
		public string Name => _name;
		public bool IsRunning => _tokenSource is not null && !_tokenSource.IsCancellationRequested;

		public void Start(CancellationTokenSource tokenSource = null)
		{
			if (IsRunning)
				return;
			
			_tokenSource = tokenSource ?? new CancellationTokenSource();
			Task.Run(() => ExecuteAsync(_tokenSource.Token));
		}

		public void Stop()
		{
			if(!IsRunning)
				return;
			
			_tokenSource.Cancel();
			foreach(var scheduledTask in _scheduledTasks)
				scheduledTask.Dispose();
		}

		private async Task ExecuteAsync(CancellationToken stoppingToken)
		{
			await Task.Delay(10, stoppingToken);
			_ = Tick(stoppingToken);
		}

		private void Schedule(ScheduledTask task)
		{
			task.Resume();
			_scheduledTasks.Enqueue(task);
		}

		public void Synchronize(Func<Task> action)
		{
			_synchronizedActions.Enqueue(action);
		}

		public void Synchronize(Action action)
		{
			_synchronizedActions.Enqueue(() =>
			{
				action();
				return Task.CompletedTask;
			});
		}
		
		public ScheduledTask ScheduleDelayed(double secondsDelay, Action action)
		{
			var task = new ScheduledTask(secondsDelay, action, false);
			Schedule(task);

			return task;
		}

		public ScheduledTask SchedulePeriodically(double secondsInterval, Action action)
		{
			var task = new ScheduledTask(secondsInterval, action, true);
			Schedule(task);

			return task;
		}

		private async Task Tick(CancellationToken stoppingToken)
		{
			while (!stoppingToken.IsCancellationRequested)
			{
				_ =  TickSynchronized(stoppingToken);

				ConcurrentQueue<ScheduledTask> nextTasks = new();

				while (!stoppingToken.IsCancellationRequested && _scheduledTasks.TryDequeue(out var task))
				{
					if (task.IsDisposed)
						continue;

					else if (task.IsPaused && task.CanTrigger)
					{
						task.Postpone();
						nextTasks.Enqueue(task);
						continue;
					}
					else if (!task.CanTrigger)
					{
						nextTasks.Enqueue(task);
						continue;
					}

					task.Trigger();

					if (task.IsDisposed)
						continue;

					nextTasks.Enqueue(task);
				}

				_scheduledTasks = nextTasks;

				if (stoppingToken.IsCancellationRequested)
					return;

				await Task.Delay(10, stoppingToken);
			}
		}

		private async Task TickSynchronized(CancellationToken stoppingToken)
		{
			while (!stoppingToken.IsCancellationRequested && _synchronizedActions.TryDequeue(out var action))
			{
				await action();
			}
		}
	}
}
