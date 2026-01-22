using MemoryPack;
using System.Collections;
using System.Text;

namespace Rathalos.Core.Utils.IO
{
	public static class FormatterExtensions
	{
		public static byte[] ToBinary<T>(this T obj)
		{
			if (obj is IList { Count: 0 })
				return Array.Empty<byte>();

			return MemoryPackSerializer.Serialize(obj);
		}
		public static T ToObject<T>(this byte[] bytes)
		{
			if (bytes.Length == 0)
				return default;

			try
			{
				return MemoryPackSerializer.Deserialize<T>(bytes);
			}
			catch (Exception)
			{
				return default;
			}
		}

		public static string ToCSV(this IEnumerable enumerable, string separator)
		{
			var builder = new StringBuilder();
			var count = 0;
			foreach (var entity in enumerable)
			{
				builder.Append(entity);
				builder.Append(separator);
				count++;
			}
			if (count > 0)
				builder.Remove(builder.Length - separator.Length, separator.Length);
			return builder.ToString();
		}

		public static string ToCSV<T>(this IEnumerable<T> enumerable, string separator, Func<T, string> formatter)
		{
			var builder = new StringBuilder();
			int count = 0;
			foreach (var entity in enumerable)
			{
				builder.Append(formatter(entity));
				builder.Append(separator);
				count++;
			}
			if (count > 0)
				builder.Remove(builder.Length - separator.Length, separator.Length);

			return builder.ToString();
		}

		public static T[] FromCSV<T>(this string csvValue, string separator)
			where T : IConvertible
		{
			var result = new List<T>();
			int lastIndex = 0;
			int i = csvValue.IndexOf(separator, StringComparison.Ordinal);
			while (i >= 0 && i < csvValue.Length)
			{
				result.Add((T)Convert.ChangeType(csvValue.Substring(lastIndex, i - lastIndex), typeof(T)));
				lastIndex = i + separator.Length;
				i = csvValue.IndexOf(separator, lastIndex, StringComparison.Ordinal);
			}

			if (!string.IsNullOrEmpty(csvValue))
				result.Add(
					(T)Convert.ChangeType(csvValue.Substring(lastIndex, csvValue.Length - lastIndex), typeof(T)));

			return result.ToArray();
		}

		public static T[] FromCSV<T>(this string csvValue, string separator, Func<string, T> converter)
		{
			var result = new List<T>();
			int lastIndex = 0;
			int i = csvValue.IndexOf(separator, StringComparison.Ordinal);
			while (i >= 0 && i < csvValue.Length)
			{
				result.Add(converter(csvValue.Substring(lastIndex, i - lastIndex)));
				lastIndex = i + separator.Length;
				i = csvValue.IndexOf(separator, lastIndex, StringComparison.Ordinal);
			}
			if (!string.IsNullOrEmpty(csvValue))
				result.Add(converter(csvValue.Substring(lastIndex, csvValue.Length - lastIndex)));
			return result.ToArray();
		}
	}
}