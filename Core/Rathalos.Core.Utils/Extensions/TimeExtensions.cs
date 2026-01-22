using System.Text;

namespace Rathalos.Core.Utils.Extensions
{
	public static class TimeExtensions
	{
		public static long GetUnixTimeStampLong(this DateTime date)
		{
			return (long)(date - TimeZoneInfo.Local.GetUtcOffset(date) - new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;
		}

		public static double GetUnixTimeStampDouble(this DateTime date)
		{
			return (date - TimeZoneInfo.Local.GetUtcOffset(date) - new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc)).TotalMilliseconds;
		}

		public static uint GetUnixTimeStamp(this DateTime date)
		{
			return (uint)(date - TimeZoneInfo.Local.GetUtcOffset(date) - new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc)).TotalSeconds;
		}

		public static DateTime FromUnixTimestamp(this double timestamp)
		{
			DateTimeOffset dateTimeOffset = DateTimeOffset.FromUnixTimeSeconds((long)timestamp);
			return dateTimeOffset.UtcDateTime;
		}

		public static DateTime FromUnixTimeStamp(this long unixTimeStamp)
		{
			return (new DateTime(1970, 1, 1, 0, 0, 0, 0, DateTimeKind.Utc)).AddMilliseconds(unixTimeStamp);
		}

		public static string ToPrettyFormat(this TimeSpan span)
		{
			if (span == TimeSpan.Zero) return "0 seconds ";

			var sb = new StringBuilder();
			if (span.Hours > 0)
				sb.AppendFormat("{0} hour{1} ", span.Hours, span.Hours > 1 ? "s" : String.Empty);
			if (span.Minutes > 0)
				sb.AppendFormat("{0} minute{1} ", span.Minutes, span.Minutes > 1 ? "s" : String.Empty);
			if (span.Seconds > 0)
				sb.AppendFormat("{0} second{1} ", span.Seconds, span.Seconds > 1 ? "s" : String.Empty);
			return sb.ToString();
		}
	}
}