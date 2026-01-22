#region License GNU GPL
// BigEndianWriter.cs
// 
// Copyright (C) 2012 - BehaviorIsManaged
// 
// This program is free software; you can redistribute it and/or modify it 
// under the terms of the GNU General Public License as published by the Free Software Foundation;
// either version 2 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
// without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License for more details. 
// You should have received a copy of the GNU General Public License along with this program; 
// if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#endregion
using System.Text;

namespace Rathalos.Core.Utils.IO
{
	public class BigEndianWriter : IDataWriter, IDisposable
	{
		public const int INT_SIZE = 32;
		public const int SHORT_SIZE = 16;
		public const int SHORT_MIN_VALUE = -0x8000;
		public const int SHORT_MAX_VALUE = 0x7FFF;
		public const int USHORT_MAX_VALUE = 0xFFFF;
		public const int CHUNCK_BIT_SIZE = 7;
		public static readonly int MAX_ENCODING_LENGHT = (int)Math.Ceiling((double)INT_SIZE / CHUNCK_BIT_SIZE);
		public const int MASK_10000000 = 0x80;
		public const int MASK_01111111 = 0x7F;

		#region Properties

		private BinaryWriter _writer;

		public Stream BaseStream
		{
			get { return _writer.BaseStream; }
		}

		/// <summary>
		///   Gets available bytes number in the buffer
		/// </summary>
		public long BytesAvailable
		{
			get { return _writer.BaseStream.Length - _writer.BaseStream.Position; }
		}

		public long Position
		{
			get { return _writer.BaseStream.Position; }
			set
			{
				_writer.BaseStream.Position = value;
			}
		}

		public byte[] Data
		{
			get
			{
				var pos = _writer.BaseStream.Position;

				var data = new byte[_writer.BaseStream.Length];
				_writer.BaseStream.Position = 0;
				_writer.BaseStream.Read(data, 0, (int)_writer.BaseStream.Length);

				_writer.BaseStream.Position = pos;

				return data;
			}
		}

		#endregion

		#region Initialisation

		/// <summary>
		/// Initializes a new instance of the <see cref="BigEndianWriter"/> class.
		/// </summary>
		public BigEndianWriter()
		{
			_writer = new BinaryWriter(new MemoryStream(), Encoding.UTF8);
		}

		/// <summary>
		/// Initializes a new instance of the <see cref="BigEndianWriter"/> class.
		/// </summary>
		/// <param name="stream">The stream.</param>
		public BigEndianWriter(Stream stream)
		{
			_writer = new BinaryWriter(stream, Encoding.UTF8);
		}

		#endregion

		#region Private Methods

		/// <summary>
		///   Reverse bytes and write them into the buffer
		/// </summary>
		private void WriteBigEndianBytes(byte[] endianBytes)
		{
			for (int i = endianBytes.Length - 1; i >= 0; i--)
			{
				_writer.Write(endianBytes[i]);
			}
		}

		#endregion

		#region Public Methods

		public void WriteVarInt(int @int)
		{
			var value = unchecked((uint)@int);

			if (value <= MASK_01111111)
			{
				_writer.Write((byte)value);
				return;
			}

			int i = 0;
			while (value != 0)
			{
				var b = (byte)(value & MASK_01111111);
				i++;
				value >>= CHUNCK_BIT_SIZE;
				if (value > 0)
					b |= MASK_10000000;
				_writer.Write(b);
			}
		}

		public void WriteVarUInt(uint @uint)
		{
			WriteVarInt(unchecked((int)@uint));
		}

		public void WriteVarShort(short @short)
		{
			var value = unchecked((ushort)@short);

			if (value <= MASK_01111111)
			{
				_writer.Write((byte)value);
				return;
			}

			int i = 0;
			while (value != 0)
			{
				var b = (byte)(value & MASK_01111111);
				i++;
				value >>= CHUNCK_BIT_SIZE;
				if (value > 0)
					b |= MASK_10000000;
				_writer.Write(b);
			}
		}

		public void WriteVarUShort(ushort @ushort)
		{
			WriteVarShort(unchecked((short)@ushort));
		}

		public void WriteVarLong(long @long)
		{
			var value = unchecked((ulong)@long);

			if (value >> 32 == 0)
			{
				WriteVarInt((int)value);
				return;
			}

			var low = value & 0xFFFFFFFF;
			var high = value >> 32;
			for (int i = 0; i < 4; i++)
			{
				_writer.Write((byte)(low & MASK_01111111 | MASK_10000000));
				low >>= 7;
			}
			if ((high & 0xFFFFFFF8) == 0) // only 3 first bits are non zeros
			{
				_writer.Write((byte)(high << 4 | low));
			}
			else
			{
				_writer.Write((byte)((high << 4 | low) & MASK_01111111 | MASK_10000000));
				high >>= 3;
				while (high >= 0x80)
				{
					_writer.Write((byte)(high & MASK_01111111 | MASK_10000000));
					high >>= 7;
				}
				_writer.Write((byte)high);
			}
		}

		public void WriteVarULong(ulong @ulong)
		{
			WriteVarLong(unchecked((long)@ulong));
		}

		/// <summary>
		///   Write a Short into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteShort(short @short)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@short));
		}

		/// <summary>
		///   Write a int into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteInt(int @int)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@int));
		}

		/// <summary>
		///   Write a long into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteLong(Int64 @long)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@long));
		}

		/// <summary>
		///   Write a UShort into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteUShort(ushort @ushort)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@ushort));
		}

		/// <summary>
		///   Write a int into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteUInt(UInt32 @uint)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@uint));
		}

		/// <summary>
		///   Write a long into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteULong(UInt64 @ulong)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@ulong));
		}

		/// <summary>
		///   Write a byte into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteByte(byte @byte)
		{
			_writer.Write(@byte);
		}

		public void WriteSByte(sbyte @byte)
		{
			_writer.Write(@byte);
		}
		/// <summary>
		///   Write a Float into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteFloat(float @float)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@float));
		}

		/// <summary>
		///   Write a Boolean into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteBoolean(Boolean @bool)
		{
			if (@bool)
			{
				_writer.Write((byte)1);
			}
			else
			{
				_writer.Write((byte)0);
			}
		}

		/// <summary>
		///   Write a Char into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteChar(Char @char)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@char));
		}

		/// <summary>
		///   Write a Double into the buffer
		/// </summary>
		public void WriteDouble(Double @double)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@double));
		}

		/// <summary>
		///   Write a Single into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteSingle(Single @single)
		{
			WriteBigEndianBytes(BitConverter.GetBytes(@single));
		}

		/// <summary>
		///   Write a string into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteUTF(string str)
		{
			var bytes = Encoding.UTF8.GetBytes(str);
			var len = bytes.Length;
			WriteInt(len);

			int i;
			for (i = 0; i < len; i++)
				_writer.Write(bytes[i]);
		}

		/// <summary>
		///   Write a string into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteUTFBytes(string str)
		{
			var bytes = Encoding.UTF8.GetBytes(str);
			var len = bytes.Length;
			int i;
			for (i = 0; i < len; i++)
				_writer.Write(bytes[i]);
		}

		/// <summary>
		///   Write a bytes array into the buffer
		/// </summary>
		/// <returns></returns>
		public void WriteBytes(byte[] data)
		{
			_writer.Write(data);
		}


		public void Seek(int offset)
		{
			Seek(offset, SeekOrigin.Begin);
		}

		public void Seek(int offset, SeekOrigin seekOrigin)
		{
			_writer.BaseStream.Seek(offset, seekOrigin);
		}


		public void Clear()
		{
			_writer = new BinaryWriter(new MemoryStream(), Encoding.UTF8);
		}

		#endregion

		#region Dispose

		public void Dispose()
		{
			_writer.Flush();
			_writer.Dispose();
			_writer = null;
		}

		#endregion
	}
}