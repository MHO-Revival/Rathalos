namespace Rathalos.Servers.Base.Services
{
	public interface IWarmupService
	{
		Task Initialize();
	}
	public abstract class WarmupService<T> : IWarmupService
		where T : WarmupService<T>
	{
		public static T Instance { get; private set; }

		public virtual Task Initialize() => Task.CompletedTask;

		public void SetInstance(T instance)
		{
			Instance = instance;
		}
	}
}
