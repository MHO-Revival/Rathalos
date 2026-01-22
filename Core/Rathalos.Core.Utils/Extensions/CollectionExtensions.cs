using Rathalos.Core.Utils.Collections;
using Rathalos.Core.Utils.IO;
using Org.BouncyCastle.Crypto.Tls;
using System.Collections;
using System.Collections.Concurrent;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Xml.Linq;

namespace Rathalos.Core.Utils.Extensions
{
	public static class CollectionExtensions
	{
        
        public static string ByteArrayToString(this byte[] bytes)
		{
			var output = new StringBuilder(bytes.Length);

			foreach (var t in bytes)
			{
				output.Append(t.ToString("X2"));
			}

			return output.ToString().ToLower();
		}

		public static string EncodeByteArray(this byte[] bytes)
		{
			var output = new StringBuilder(bytes.Length);

			foreach (var t in bytes)
			{
				output.Append((char)t);
			}

			return output.ToString();
		}

		public static List<T> Clone<T>(this List<T> listToClone) where T : ICloneable => listToClone.Select(item => (T)item.Clone()).ToList();

		public static void Move<T>(this List<T> list, T item, int newIndex) where T : ICloneable
		{
			list.Remove(item);
			list.Insert(newIndex, item);
		}

		public static bool CompareEnumerable<T>(this IEnumerable<T> ie1, IEnumerable<T> ie2)
		{
			if (ie1.GetType() != ie2.GetType())
				return false;

			var a1 = ie1.ToArray();
			var a2 = ie2.ToArray();

			if (a1.Length != a2.Length)
				return false;

			return !a1.Except(a2).Any() && !a2.Except(a1).Any();
		}

		public static T MaxOf<T, T1>(this IList<T> collection, Func<T, T1> selector) where T1 : IComparable<T1>
		{
			if (collection.Count == 0) return default(T);

			var maxT = collection[0];
			var maxT1 = selector(maxT);

			for (var i = 1; i < collection.Count; i++)
			{
				var currentT1 = selector(collection[i]);
				if (currentT1.CompareTo(maxT1) <= 0)
					continue;

				maxT = collection[i];
				maxT1 = currentT1;
			}
			return maxT;
		}

		public static T MinOf<T, T1>(this IList<T> collection, Func<T, T1> selector) where T1 : IComparable<T1>
		{
			if (collection.Count == 0) return default(T);

			var maxT = collection[0];
			var maxT1 = selector(maxT);

			for (var i = 1; i < collection.Count; i++)
			{
				var currentT1 = selector(collection[i]);
				if (currentT1.CompareTo(maxT1) >= 0)
					continue;

				maxT = collection[i];
				maxT1 = currentT1;
			}
			return maxT;
		}

		public static int IndexOf<T>(this IEnumerable<T> collection, T comparer)
			where T : class
		{
			int iterator = 0;
			foreach(var item in collection)
			{
                if (item == comparer)
                {
                    return iterator;
                }
                iterator++;
			}

			return -1;
		}

		public static int FindIndex<T>(this IEnumerable<T> collection, Predicate<T> comparer)
					where T : class
		{
			int iterator = 0;
			foreach (var item in collection)
			{
				if (comparer(item))
				{
					return iterator;
				}
				iterator++;
			}

			return -1;
		}
		public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> enumerable)
		{
			var elements = enumerable.ToArray();
			// Note i > 0 to avoid final pointless iteration
			for (var i = elements.Length - 1; i > 0; i--)
			{
				// Swap element "i" with a random earlier element it (or itself)
				var swapIndex = Random.Shared.Next(i + 1);
				(elements[i], elements[swapIndex]) = (elements[swapIndex], elements[i]);
			}
			// Lazily yield (avoiding aliasing issues etc)
			return elements;
		}

		public static IEnumerable<T> ShuffleLinq<T>(this IEnumerable<T> enumerable)
		{
			return enumerable.OrderBy(x => Random.Shared.NextDouble());
		}
		

		public static T RandomElementOrDefault<T>(this IEnumerable<T> enumerable)
		{
			var rand = new Random();
			var count = enumerable.Count();

			if (count <= 0)
				return default(T);

			return enumerable.ElementAt(rand.Next(count));
		}

		/// <summary>
		/// Returns the string representation of an IEnumerable (all elements, joined by comma)
		/// </summary>
		/// <param name="conj">The conjunction to be used between each elements of the collection</param>
		public static string ToStringCol(this ICollection collection, string conj) => collection != null ? string.Join(conj, ToStringArr(collection)) : "(null)";

		public static string ToString(this IEnumerable collection, string conj) => collection != null ? string.Join(conj, ToStringArr(collection)) : "(null)";

		public static string[] ToStringArr(this IEnumerable collection)
		{
			var strs = new List<string>();
			var colEnum = collection.GetEnumerator();
			while (colEnum.MoveNext())
			{
				var cur = colEnum.Current;
				if (cur != null)
				{
					strs.Add(cur.ToString());
				}
			}
			return strs.ToArray();
		}

		public static T GetOrDefault<T>(this IList<T> list, int index) => index >= list.Count ? default(T) : list[index];

		public static TValue GetOrDefault<TKey, TValue>(this IDictionary<TKey, TValue> dict, TKey key)
		{
			TValue val;
			return dict.TryGetValue(key, out val) ? val : default(TValue);
		}

		public static void AddRange<T, S>(this Dictionary<T, S> source, Dictionary<T, S> collection)
		{
			if (collection == null)
			{
				throw new ArgumentNullException("Collection is null");
			}

			foreach (var item in collection.Where(item => !source.ContainsKey(item.Key)))
			{
				source.Add(item.Key, item.Value);
			}
		}

		public static T[] Concat<T>(this T[] x, T[] y)
		{
			if (x == null)
				throw new ArgumentNullException("x");
			if (y == null)
				throw new ArgumentNullException("y");

			var oldLen = x.Length;
			Array.Resize(ref x, x.Length + y.Length);
			Array.Copy(y, 0, x, oldLen, y.Length);

			return x;
		}

		public static T[] Add<T>(this T[] array, T item)
		{
			return array.Concat(new T[] { item });
		}
		public static List<T> Splice<T>(this List<T> Source, int Start, int Size)
		{
			var retVal = Source.Skip(Start).Take(Size).ToList();
			Source.RemoveRange(Start, Size);
			return retVal;
		}

		public static void FastForEach<T>(this IEnumerable<T> source, Action<T> action)
		{
			Span<T> items;
			if (source is T[] sourceArray)
				items = sourceArray;
			else if (source is ConcurrentList<T> sourceConcurrentList)
				items = CollectionsMarshal.AsSpan(sourceConcurrentList.ToList());
			else if (source is List<T> sourceList)
				items = CollectionsMarshal.AsSpan(sourceList);
			else
			{
				throw new NotSupportedException("Collections types other than Lists or Arrays are not supported");
			}

			ref var itemRef = ref MemoryMarshal.GetReference(items);
			for (int i = 0; i < items.Length; i++)
			{
				var item = Unsafe.Add(ref itemRef, i);
				action(item);
			}
		}

		public static void TreatCollectionParallelWithConsole<T>(this IEnumerable<T> source, string messageOnPercentage, Action<T> action)
		{
			ParallelOptions options = new ParallelOptions(){
				MaxDegreeOfParallelism = Environment.ProcessorCount,
			};
			var console = new ConsoleProgress();
			var counter = 0;
			Parallel.ForEach(source, options, item =>
			{
				action(item);

				lock (console)
					console.Update($"{messageOnPercentage} => {(int)(++counter / (double)source.Count() * 100.0)}%");

			});
			console.End();
		}

		public static void ParallelForEach<T>(this IEnumerable<T> source, Action<T> action)
		{
            ParallelOptions options = new ParallelOptions()
            {
                MaxDegreeOfParallelism = Environment.ProcessorCount,
            };
            Parallel.ForEach(source, options, item =>
			{
				action(item);
			});
		}

		public static ConcurrentDictionary<TKey, TElement> ToConcurrentDictionary<TSource, TKey, TElement>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector, Func<TSource, TElement> elementSelector)
		{
			return new ConcurrentDictionary<TKey, TElement>(source.ToDictionary(keySelector, elementSelector));
		}
	}
}