using System.Reflection;

namespace Rathalos.Core.Protocol.Tools
{
    [AttributeUsage(AttributeTargets.Property)]
    public sealed class TsvColumnAttribute : Attribute
    {
        public string ColumnName { get; }

        public TsvColumnAttribute(string columnName)
        {
            ColumnName = columnName;
        }
    }

    public sealed class TsvSheet
    {
        public string Name { get; set; } = string.Empty;

        public string[] Headers { get; set; } = [];

        public List<string[]> Rows { get; set; } = [];

        public List<Dictionary<string, string>> Records { get; set; } = [];

        public string? GetValue(int rowIndex, string columnName)
        {
            if (rowIndex < 0 || rowIndex >= Records.Count)
                return null;

            return Records[rowIndex].TryGetValue(columnName, out var value) ? value : null;
        }

        public string? GetValue(int rowIndex, int columnIndex)
        {
            if (rowIndex < 0 || rowIndex >= Rows.Count)
                return null;

            if (columnIndex < 0 || columnIndex >= Rows[rowIndex].Length)
                return null;

            return Rows[rowIndex][columnIndex];
        }

        public int GetColumnIndex(string columnName)
        {
            for (int i = 0; i < Headers.Length; i++)
            {
                if (Headers[i] == columnName)
                    return i;
            }
            return -1;
        }

        public IEnumerable<Dictionary<string, string>> Where(Func<Dictionary<string, string>, bool> predicate)
        {
            return Records.Where(predicate);
        }

        public List<T> ReadAs<T>() where T : new()
        {
            var result = new List<T>();
            var properties = GetMappedProperties<T>();

            foreach (var record in Records)
            {
                var obj = new T();
                foreach (var (property, columnName) in properties)
                {
                    if (record.TryGetValue(columnName, out var value) && !string.IsNullOrEmpty(value))
                    {
                        var convertedValue = ConvertValue(value, property.PropertyType);
                        if (convertedValue != null)
                        {
                            property.SetValue(obj, convertedValue);
                        }
                    }
                }
                result.Add(obj);
            }

            return result;
        }

        public T? ReadFirstAs<T>() where T : new()
        {
            var items = ReadAs<T>();
            return items.Count > 0 ? items[0] : default;
        }

        public IEnumerable<T> ReadAs<T>(Func<Dictionary<string, string>, bool> predicate) where T : new()
        {
            var properties = GetMappedProperties<T>();

            foreach (var record in Records.Where(predicate))
            {
                var obj = new T();
                foreach (var (property, columnName) in properties)
                {
                    if (record.TryGetValue(columnName, out var value) && !string.IsNullOrEmpty(value))
                    {
                        var convertedValue = ConvertValue(value, property.PropertyType);
                        if (convertedValue != null)
                        {
                            property.SetValue(obj, convertedValue);
                        }
                    }
                }
                yield return obj;
            }
        }

        private static List<(PropertyInfo Property, string ColumnName)> GetMappedProperties<T>()
        {
            var properties = new List<(PropertyInfo, string)>();

            foreach (var property in typeof(T).GetProperties(BindingFlags.Public | BindingFlags.Instance))
            {
                if (!property.CanWrite)
                    continue;

                var attribute = property.GetCustomAttribute<TsvColumnAttribute>();
                var columnName = attribute?.ColumnName ?? property.Name;
                properties.Add((property, columnName));
            }

            return properties;
        }

        private static object? ConvertValue(string value, Type targetType)
        {
            var underlyingType = Nullable.GetUnderlyingType(targetType);
            var isNullable = underlyingType != null;
            var actualType = underlyingType ?? targetType;

            if (string.IsNullOrEmpty(value))
                return isNullable ? null : GetDefaultValue(actualType);

            try
            {
                if (actualType == typeof(string))
                    return value;

                if (actualType == typeof(int))
                    return int.Parse(value);

                if (actualType == typeof(uint))
                    return uint.Parse(value);

                if (actualType == typeof(long))
                    return long.Parse(value);

                if (actualType == typeof(ulong))
                    return ulong.Parse(value);

                if (actualType == typeof(short))
                    return short.Parse(value);

                if (actualType == typeof(ushort))
                    return ushort.Parse(value);

                if (actualType == typeof(byte))
                    return byte.Parse(value);

                if (actualType == typeof(sbyte))
                    return sbyte.Parse(value);

                if (actualType == typeof(float))
                    return float.Parse(value);

                if (actualType == typeof(double))
                    return double.Parse(value);

                if (actualType == typeof(decimal))
                    return decimal.Parse(value);

                if (actualType == typeof(bool))
                    return value == "1" || value.Equals("true", StringComparison.OrdinalIgnoreCase);

                if (actualType == typeof(DateTime))
                    return DateTime.Parse(value);

                if (actualType.IsEnum)
                    return Enum.Parse(actualType, value);

                return Convert.ChangeType(value, actualType);
            }
            catch
            {
                return isNullable ? null : GetDefaultValue(actualType);
            }
        }

        private static object? GetDefaultValue(Type type)
        {
            return type.IsValueType ? Activator.CreateInstance(type) : null;
        }
    }

    public sealed class TsvReader
    {
        private const string SheetBeginMarker = "#============Begin of sheet============";
        private const string SheetEndMarker = "#============End of sheet============";
        private const string SheetNamePrefix = "@Sheet=";

        private readonly string _content;

        public TsvReader(byte[] content)
        {
            _content = System.Text.Encoding.UTF8.GetString(content);
        }

        public TsvReader(string content)
        {
            _content = content;
        }

        public Dictionary<string, TsvSheet> Sheets { get; private set; } = [];

        public static TsvReader Create(byte[] content)
        {
            var reader = new TsvReader(content);
            reader.Read();
            return reader;
        }

        public static TsvReader Create(string content)
        {
            var reader = new TsvReader(content);
            reader.Read();
            return reader;
        }

        public static TsvReader CreateFromFile(string filePath)
        {
            if (!File.Exists(filePath))
                throw new FileNotFoundException($"TSV file not found: {filePath}");

            var content = File.ReadAllBytes(filePath);
            return Create(content);
        }

        public static List<T> Parse<T>(string filePath, string sheet)
            where T : new()
        {
            var reader = CreateFromFile(filePath);
            var tsvSheet = reader.GetSheet(sheet);
            if (tsvSheet == null)
                throw new InvalidOperationException($"Sheet '{sheet}' not found in TSV file: {filePath}");
            return tsvSheet.ReadAs<T>();
        }

        public TsvSheet? GetSheet(string sheetName)
        {
            return Sheets.TryGetValue(sheetName, out var sheet) ? sheet : null;
        }

        private void Read()
        {
            var lines = _content
                .Split(["\r\n", "\n"], StringSplitOptions.None)
                .ToList();

            if (lines.Count == 0)
                return;

            TsvSheet? currentSheet = null;
            bool inSheet = false;
            bool headersRead = false;

            foreach (var line in lines)
            {
                if (string.IsNullOrWhiteSpace(line))
                    continue;

                if (line == SheetBeginMarker)
                {
                    inSheet = true;
                    headersRead = false;
                    currentSheet = new TsvSheet();
                    continue;
                }

                if (line == SheetEndMarker)
                {
                    if (currentSheet != null && !string.IsNullOrEmpty(currentSheet.Name))
                    {
                        Sheets[currentSheet.Name] = currentSheet;
                    }
                    inSheet = false;
                    currentSheet = null;
                    continue;
                }

                if (!inSheet || currentSheet == null)
                    continue;

                if (line.StartsWith(SheetNamePrefix))
                {
                    currentSheet.Name = line[SheetNamePrefix.Length..];
                    continue;
                }

                if (line.StartsWith('#'))
                    continue;

                var values = ParseLine(line);

                if (!headersRead)
                {
                    currentSheet.Headers = values;
                    headersRead = true;
                    continue;
                }

                currentSheet.Rows.Add(values);

                var record = new Dictionary<string, string>();
                for (int j = 0; j < currentSheet.Headers.Length && j < values.Length; j++)
                {
                    record[currentSheet.Headers[j]] = values[j];
                }
                currentSheet.Records.Add(record);
            }
        }

        private static string[] ParseLine(string line)
        {
            return line.Split('\t');
        }
    }
}
