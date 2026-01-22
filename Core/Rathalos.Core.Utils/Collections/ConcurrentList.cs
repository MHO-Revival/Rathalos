using Org.BouncyCastle.Crypto.Tls;
using System.Collections;

namespace Rathalos.Core.Utils.Collections
{
	public class ConcurrentList<T> : ICollection<T>, IList<T>
	{
		private List<T> _internalList = new List<T>();
		public T this[int index]
		{
			get => _internalList[index];
			set => _internalList[index] = value;
		}

		public ConcurrentList(int capacity) => _internalList = new List<T>(capacity);
		public ConcurrentList() => _internalList = new List<T>();
		public ConcurrentList(IEnumerable<T> list) => _internalList = list.ToList();

		public int Count
		{
			get
			{
				lock (_internalList)
					return _internalList.Count;
			}
		}

		public bool IsReadOnly => false;

		public void Add(T item)
		{
			lock (_internalList)
				_internalList.Add(item);
		}

		public void AddRange(IEnumerable<T> item)
		{
			lock (_internalList)
				_internalList.AddRange(item);
		}

		public void Clear()
		{
			lock (_internalList)
				_internalList.Clear();
		}

		public bool Contains(T item)
		{
			lock (_internalList)
				return _internalList.Contains(item);
		}

		public void CopyTo(T[] array, int arrayIndex)
		{
			lock (_internalList)
				_internalList.CopyTo(array, arrayIndex);
		}

		public IEnumerator<T> GetEnumerator()
		{
			lock (_internalList)
				return _internalList.GetEnumerator();
		}

		public int IndexOf(T item)
		{
			lock (_internalList)
				return _internalList.IndexOf(item);
		}

		public void Insert(int index, T item)
		{
			lock (_internalList)
				_internalList.Insert(index, item);
		}

		public bool Remove(T item)
		{
			lock (_internalList)
				return _internalList.Remove(item);
		}

		public void RemoveAt(int index)
		{
			lock (_internalList)
				_internalList.RemoveAt(index);
		}

		public IEnumerable<T> Where(Func<T, bool> match)
		{
			lock (_internalList)
				return _internalList.Where(match);
		}

		public T FirstOrDefault(Func<T, bool> match)
		{
			lock (_internalList)
				return _internalList.FirstOrDefault(match);
		}

		public IEnumerable<TResult> Select<TResult>(Func<T, TResult> match)
		{
			lock (_internalList)
				return _internalList.Select(match);
		}

		IEnumerator IEnumerable.GetEnumerator()
		{
			lock (_internalList)
				return _internalList.GetEnumerator();
		}

		public List<T> ToList()
		{
			lock (_internalList)
				return _internalList.ToList();
		}

		public T[] ToArray()
		{
			lock (_internalList)
				return _internalList.ToArray();
		}

		public Dictionary<TKey, T> ToDictionary<TKey>(Func<T, TKey> keySelector)
		{
			lock(_internalList)
				return _internalList.ToDictionary(keySelector);
		}
	}
}
