namespace Rathalos.Core.Utils.IO
{
	public class ConsoleProgress
	{
		private object _lastValue;

		public ConsoleProgress()
		{
			PositionX = Console.CursorLeft;
			PositionY = Console.CursorTop;
		}

		public ConsoleProgress(int positionX, int positionY)
		{
			PositionX = positionX;
			PositionY = positionY;
		}

		public int PositionX
		{
			get;
			set;
		}

		public int PositionY
		{
			get;
			set;
		}

		public void Update(int value)
		{
			if (value.Equals(_lastValue))
				return;

			_lastValue = value;

			int oldX = Console.CursorLeft;
			int oldY = Console.CursorTop;

			Console.SetCursorPosition(PositionX, PositionY);
			Console.Write(value + "%");
			Console.SetCursorPosition(oldX, oldY);
		}

		public void Update(string value)
		{
			if (value.Equals(_lastValue))
				return;

			int oldX = Console.CursorLeft;
			int oldY = Console.CursorTop;

			Console.SetCursorPosition(PositionX, PositionY);
			Console.Write(value);
			Console.SetCursorPosition(oldX, oldY);
		}

		public void End()
		{
			string cleaner = string.Empty;

			for (int i = 0; i < Console.BufferWidth - PositionX; i++)
			{
				cleaner += " ";
			}


			int oldX = Console.CursorLeft;
			int oldY = Console.CursorTop;

			Console.SetCursorPosition(PositionX, PositionY);
			Console.Write(cleaner);
			Console.SetCursorPosition(oldX, oldY);
		}
	}
}