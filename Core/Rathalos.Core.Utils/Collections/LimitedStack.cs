namespace Rathalos.Core.Utils.Collections
{
	[Serializable]
	public class LimitedStack<T> : LinkedList<T>
	{
		private int _maxItems;

		public LimitedStack(int max)
		{
			_maxItems = max;
		}

		public LimitedStack(int max, IEnumerable<T> items)
			: base(items)
		{
			_maxItems = max;
		}

		public T[] this[Range range] => this.ToArray()[range];

		public int MaxItems
		{
			get { return _maxItems; }
			set
			{
				while (Count > value)
				{
					RemoveFirst();
				}
				_maxItems = value;
			}
		}

		public bool IsFull => _maxItems <= this.Count;

		public T Get(int fromLast)
		{
			var pointer = Last;
			while(fromLast > 0)
			{
				pointer = Last.Previous;
				fromLast--;
			}

			return pointer.Value;
		}

		public T Peek()
		{
			return Last.Value;
		}

		public T Pop()
		{
			var node = Last;
			RemoveLast();
			return node.Value;
		}

		public void Push(T value)
		{
			var node = new LinkedListNode<T>(value);
			AddLast(node);

			if (Count > _maxItems)
			{
				RemoveFirst();
			}
		}
	}
}