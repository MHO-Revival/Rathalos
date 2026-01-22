using System.Numerics;

namespace Rathalos.Core.Utils.Consoles;

public sealed class ConsoleFormat
{
	public static readonly ConsoleFormat SendPacket = new("[SND]", ConsoleAttributes.Cyan, ConsoleAttributes.Bold);
	public static readonly ConsoleFormat ReceivePacket = new("[RCV]", ConsoleAttributes.Magenta, ConsoleAttributes.Bold);

	public ConsoleFormat(string text, params string[] attributes)
	{
		Text = text;
		Attributes = attributes;
	}

	public string Text { get; set; }
	public string[] Attributes { get; set; }

	public static implicit operator string(ConsoleFormat format)
	{
		return format.ToString();
	}

	public override string ToString()
	{
		return $"{string.Join(string.Empty, Attributes.Select(_ => $"\u001b{_}"))}{Text}\u001b[0m";
	}
}

public static class ConsoleAttributes
{
	public const string Black = "[30m";
	public const string Red = "[31m";
	public const string Green = "[32m";
	public const string Yellow = "[33m";
	public const string Blue = "[34m";
	public const string Magenta = "[35m";
	public const string Cyan = "[36m";
	public const string Gray = "[90m";
	public const string LightGray = "[37m";
	public const string LightRed = "[91m";
	public const string LightGreen = "[92m";
	public const string LightYellow = "[93m";
	public const string LightBlue = "[94m";
	public const string LightMagenta = "[95m";
	public const string LightCyan = "[96m";
	public const string White = "[97m";
	public const string Bold = "[1m";
	public const string Underline = "[4m";
}
