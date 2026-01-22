namespace Rathalos.Core.Utils.Cache
{
	public sealed class ObjectValidator<T>
	{

		public event Action<ObjectValidator<T>> ObjectInvalidated;

		private void NotifyObjectInvalidated()
		{
			var handler = ObjectInvalidated;
			if (handler != null)
				handler(this);
		}


		private readonly Lock _sync = new Lock();
		private bool _isValid;
		private T _instance;
		private DateTime _lastCreationDate;
		private readonly Func<T> _creator;

		public ObjectValidator(Func<T> creator, TimeSpan? lifeTime = null)
		{
			LifeTime = lifeTime;
			_creator = creator;
		}

		private bool IsValid => _isValid && (LifeTime == null || DateTime.Now - _lastCreationDate < LifeTime.Value);

		public TimeSpan? LifeTime
		{
			get;
			set;
		}

		public void Invalidate()
		{
			_isValid = false;

			NotifyObjectInvalidated();
		}

		public T Instance
		{
			get
			{
				if (this.IsValid)
					return this._instance;

				lock (this._sync)
				{
					if (this.IsValid)
						return this._instance;

					this._instance = this._creator();
					this._lastCreationDate = DateTime.Now;
					this._isValid = true;
				}

				return this._instance;
			}
		}

		public static implicit operator T(ObjectValidator<T> validator)
		{
			return validator.Instance;
		}
	}

	public class ObjectValidator<T, TContext>
	{
		public event Action<ObjectValidator<T, TContext>> ObjectInvalidated;

		private void NotifyObjectInvalidated()
		{
			var handler = ObjectInvalidated;
			if (handler != null)
				handler(this);
		}

		private readonly object _sync = new object();

		private bool _isValid;

		private T _instance;

		private readonly TContext _context;
		private readonly Func<TContext, T> _creator;

		public ObjectValidator(TContext context, Func<TContext, T> creator)
		{
			_context = context;
			_creator = creator;
		}

		public void Invalidate()
		{
			_isValid = false;

			NotifyObjectInvalidated();
		}

		public static implicit operator T(ObjectValidator<T, TContext> validator)
		{
			if (validator._isValid)
				return validator._instance;

			lock (validator._sync)
			{
				if (validator._isValid)
					return validator._instance;

				validator._instance = validator._creator(validator._context);
				validator._isValid = true;
			}

			return validator._instance;
		}
	}
}
