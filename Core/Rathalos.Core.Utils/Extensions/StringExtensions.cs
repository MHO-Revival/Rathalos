using System.Collections;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.RegularExpressions;

namespace Rathalos.Core.Utils.Extensions
{
	public static class StringExtensions
	{
		public static string RemoveAccents(this string source)
		{
			return string.Concat(
				source.Normalize(NormalizationForm.FormD)
					  .Where(ch => CharUnicodeInfo.GetUnicodeCategory(ch) !=
								   UnicodeCategory.NonSpacingMark)
				).Normalize(NormalizationForm.FormC);
		}

		public static bool HasAccents(this string source)
		{
			return
				source.Normalize(NormalizationForm.FormD)
					  .Any(x => CharUnicodeInfo.GetUnicodeCategory(x) == UnicodeCategory.NonSpacingMark);
		}

		public static string FirstLetterUpper(this string source)
		{
			if (string.IsNullOrEmpty(source))
				return string.Empty;

			var letters = source.ToCharArray();
			letters[0] = char.ToUpper(letters[0]);

			return new string(letters);
		}

		public static string ConcatCopy(this string str, int times)
		{
			var builder = new StringBuilder(str.Length * times);

			for (int i = 0; i < times; i++)
			{
				builder.Append(str);
			}

			return builder.ToString();
		}

		public static string RandomString(this Random random, int size, bool onlyAlphanumeric = true, bool withMinus = false)
		{
			string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

			if (withMinus)
				chars += "abcdefghijklmnopqrstuvwxyz";

			if (!onlyAlphanumeric)
				chars += "_-?!";

			return new string(Enumerable.Repeat(chars, size)
				.Select(s => s[random.Next(s.Length)]).ToArray());

		}

		public static string[] SplitAdvanced(this string expression, string delimiter)
		{
			return SplitAdvanced(expression, delimiter, "", false);
		}

		public static string[] SplitAdvanced(this string expression, string delimiter,
									 string qualifier)
		{
			return SplitAdvanced(expression, delimiter, qualifier, false);
		}


		public static string[] SplitAdvanced(this string expression, string delimiter,
			string qualifier, bool ignoreCase)
		{
			return SplitAdvanced(expression, new[] { delimiter }, qualifier, ignoreCase);
		}

		public static string[] SplitAdvanced(this string expression, string[] delimiters,
									 string qualifier, bool ignoreCase)
		{
			bool qualifierState = false;
			var startIndex = 0;
			var values = new ArrayList();

			for (int charIndex = 0; charIndex < expression.Length - 1; charIndex++)
			{
				if (qualifier != null)
					if (string.Compare(expression.Substring
										   (charIndex, qualifier.Length), qualifier, ignoreCase) == 0)
					{
						qualifierState = !(qualifierState);
					}
					else if (!(qualifierState)
							 && (delimiters.Any(x => string.Compare(expression.Substring
												   (charIndex, x.Length), x, ignoreCase) == 0)))
					{
						values.Add(expression[startIndex..charIndex]);
						startIndex = charIndex + 1;
					}
			}

			if (startIndex < expression.Length)
				values.Add(expression[startIndex..]);

			var returnValues = new string[values.Count];
			values.CopyTo(returnValues);
			return returnValues;
		}

		public static List<string> GetDelimitedText(this string text, string firstDelimiter, string secondDelimiter, bool includeDelimiter = false)
		{
			var returnedList = new List<string>();
			bool exit = false;
			string delimitedText;
			string firstPart;
			string secondPart;

			while (!exit)
			{
				delimitedText = GetSingleDelimitedText(text, firstDelimiter, secondDelimiter, includeDelimiter);
				if (string.IsNullOrEmpty(delimitedText))
				{
					exit = true;
				}
				else
				{
					returnedList.Add(delimitedText);
					if (!includeDelimiter)
					{
						delimitedText = firstDelimiter + delimitedText + secondDelimiter;
					}
					firstPart = text.Substring(0, text.IndexOf(delimitedText));
					while (firstPart.Contains(firstDelimiter))
					{
						firstPart = firstPart.Replace(firstDelimiter, "");
					}
					secondPart = text.Substring(text.IndexOf(delimitedText) + delimitedText.Length);
					text = firstPart + secondPart;
				}
			}
			return returnedList;
		}

		private static string GetSingleDelimitedText(this string text, string firstDelimiter, string secondDelimiter, bool includeDelimiter)
		{
			// This method should be implemented to extract a single delimited text segment.
			// Placeholder implementation:
			int startIndex = text.IndexOf(firstDelimiter);
			if (startIndex == -1)
			{
				return string.Empty;
			}
			startIndex += firstDelimiter.Length;
			int endIndex = text.IndexOf(secondDelimiter, startIndex);
			if (endIndex == -1)
			{
				return string.Empty;
			}
			string result = text.Substring(startIndex, endIndex - startIndex);
			if (includeDelimiter)
			{
				result = firstDelimiter + result + secondDelimiter;
			}
			return result;
		}

		public static string EscapeString(this string str)
		{
			return str == null ? null : Regex.Replace(str, @"[\r\n\x00\x1a\\'""]", @"\$0");
		}

		/// <summary>
		///   Convert html chars to HTML entities
		/// </summary>
		/// <param name = "str"></param>
		/// <returns></returns>
		public static string SanitizeHtml(this string str)
		{
			return str.Replace("&", "&amp;")
					  .Replace("<", "&lt;")
					  .Replace(">", "&gt;");
		}

		public static int CountOccurences(this string str, char chr, int startIndex, int count)
		{
			int occurences = 0;

			for (int i = startIndex; i < startIndex + count; i++)
			{
				if (str[i] == chr)
					occurences++;
			}

			return occurences;
		}

		public static int CountOccurences(this string str, char chr)
		{
			return CountOccurences(str, chr, 0, str.Length);
		}

		public static string RemoveWhitespace(this string input)
		{
			return new string(input.ToCharArray()
				.Where(c => !Char.IsWhiteSpace(c))
				.ToArray());
		}

		public static IEnumerable<string> Split(this string str, int chunkSize)
		{
			double length = str.Length;
			double size = chunkSize;
			var count = (int)Math.Ceiling(length / size);

			return Enumerable.Range(0, count)
				.Select(i => str.Substring(i * chunkSize, (int)(length - (i * chunkSize))));
		}

		public static IEnumerable<int> FindIndexes(this string str, string strToSearch)
		{
			IList<int> indeces = new List<int>();
			int index = -1;
			while (-1 != (index = str.IndexOf(strToSearch, index + 1)))
			{
				indeces.Add(index);
			}

			return indeces;
		}

		public static string TrimStart(this string target, string trimString)
		{
			if (string.IsNullOrEmpty(trimString)) return target;

			string result = target;
			while (result.StartsWith(trimString))
			{
				result = result.Substring(trimString.Length);
			}

			return result;
		}

		public static string TrimEnd(this string target, string trimString)
		{
			if (string.IsNullOrEmpty(trimString)) return target;

			string result = target;
			while (result.EndsWith(trimString))
			{
				result = result.Substring(0, result.Length - trimString.Length);
			}

			return result;
		}

		public static string Trim(this string target, string trimString)
		{
			if (string.IsNullOrEmpty(trimString)) return target;

			return target.TrimStart(trimString).TrimEnd(trimString);
		}

        public static byte[] FromHexString(this string hexString)
        {
            if ((hexString.Length & 1) != 0)
            {
                throw new ArgumentException("Input must have even number of characters");
            }

            byte[] ret = new byte[hexString.Length / 2];
            for (int i = 0; i < ret.Length; i++)
            {
                int high = hexString[i * 2];
                int low = hexString[i * 2 + 1];
                high = (high & 0xf) + ((high & 0x40) >> 6) * 9;
                low = (low & 0xf) + ((low & 0x40) >> 6) * 9;

                ret[i] = (byte)((high << 4) | low);
            }

            return ret;
        }

        public static string ToHexString(this byte[] data, char? seperator = null)
        {
            StringBuilder sb = new StringBuilder();
            int len = data.Length;
            for (int i = 0; i < len; i++)
            {
                sb.Append(data[i].ToString("X2"));
                if (seperator != null && i < len - 1)
                {
                    sb.Append(seperator);
                }
            }

            return sb.ToString();
        }

        public static string HexDump(this byte[] bytes, int bytesPerLine = 16)
        {
            if (bytes == null) return "<null>";
            int bytesLength = bytes.Length;

            char[] HexChars = "0123456789ABCDEF".ToCharArray();

            int firstHexColumn =
                8 // 8 characters for the address
                + 3; // 3 spaces

            int firstCharColumn = firstHexColumn
                                  + bytesPerLine * 3 // - 2 digit for the hexadecimal value and 1 space
                                  + (bytesPerLine - 1) / 8 // - 1 extra space every 8 characters from the 9th
                                  + 2; // 2 spaces 

            int lineLength = firstCharColumn
                             + bytesPerLine // - characters to show the ascii value
                             + Environment.NewLine.Length; // Carriage return and line feed (should normally be 2)

            char[] line = (new String(' ', lineLength - Environment.NewLine.Length) + Environment.NewLine)
                .ToCharArray();
            int expectedLines = (bytesLength + bytesPerLine - 1) / bytesPerLine;
            StringBuilder result = new StringBuilder(expectedLines * lineLength);

            for (int i = 0; i < bytesLength; i += bytesPerLine)
            {
                line[0] = HexChars[(i >> 28) & 0xF];
                line[1] = HexChars[(i >> 24) & 0xF];
                line[2] = HexChars[(i >> 20) & 0xF];
                line[3] = HexChars[(i >> 16) & 0xF];
                line[4] = HexChars[(i >> 12) & 0xF];
                line[5] = HexChars[(i >> 8) & 0xF];
                line[6] = HexChars[(i >> 4) & 0xF];
                line[7] = HexChars[(i >> 0) & 0xF];

                int hexColumn = firstHexColumn;
                int charColumn = firstCharColumn;

                for (int j = 0; j < bytesPerLine; j++)
                {
                    if (j > 0 && (j & 7) == 0) hexColumn++;
                    if (i + j >= bytesLength)
                    {
                        line[hexColumn] = ' ';
                        line[hexColumn + 1] = ' ';
                        line[charColumn] = ' ';
                    }
                    else
                    {
                        byte b = bytes[i + j];
                        line[hexColumn] = HexChars[(b >> 4) & 0xF];
                        line[hexColumn + 1] = HexChars[b & 0xF];
                        line[charColumn] = (b < 32 ? '·' : (char)b);
                    }

                    hexColumn += 3;
                    charColumn++;
                }

                result.Append(line);
            }

            string ret = result.ToString();
            ret = ret.TrimEnd(Environment.NewLine.ToCharArray());
            ret = ret += Environment.NewLine;
            return ret;
        }
    }
}