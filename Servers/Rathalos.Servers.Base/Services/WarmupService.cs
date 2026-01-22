namespace Rathalos.Servers.Base.Services
{
	public interface IWarmupService
	{
		void Initialize();
	}
	public abstract class WarmupService<T> : IWarmupService
		where T : WarmupService<T>
	{
		public static T Instance { get; private set; }

		public virtual void Initialize() { }

		public void SetInstance(T instance)
		{
			Instance = instance;
		}
	}
}
