using System;
using System.Text;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace Rathalos.CLI.Launcher
{
    public class AgBuffer : IDisposable
    {
        public enum Endianness
        {
            Big,
            Small
        }

        // --- Static Helper for System Endianness ---
        private static readonly Endianness SystemEndianness = BitConverter.IsLittleEndian ? Endianness.Small : Endianness.Big;

        // --- Constants ---
        private const int GrowSize = 1024;

        // --- Fields ---
        private byte[] _data;
        private int _position;
        private int _virtualLength; // The "used" length
        private Endianness _endianness;

        // --- Properties ---
        public int Position => _position;
        public int Length => _virtualLength;
        public int Available => _virtualLength - _position;
        public Endianness CurrentEndianness
        {
            get => _endianness;
            set => _endianness = value;
        }

        // --- Constructors ---
        public AgBuffer()
        {
            _data = new byte[GrowSize];
            _position = 0;
            _virtualLength = 0;
            _endianness = Endianness.Small; // Default as per C++ code
        }

        public AgBuffer(byte[] initialData)
        {
            _data = new byte[initialData.Length];
            Buffer.BlockCopy(initialData, 0, _data, 0, initialData.Length);
            _position = initialData.Length;
            _virtualLength = initialData.Length;
            _endianness = Endianness.Small;
        }

        // Private constructor for slicing
        private AgBuffer(byte[] sourceData, int offset, int length)
        {
            _data = new byte[length];
            Buffer.BlockCopy(sourceData, offset, _data, 0, length);
            _position = length; // Mimic write behavior (cursor at end) or 0? 
                                // C++: write_data moves pos. C++ slice does: new AgBuffer(&data[pos], len).
                                // The C++ ctor writes data then leaves pos at end.
            _virtualLength = length;
            _endianness = Endianness.Small;
        }

        // --- Endianness Logic ---
        public static ushort SwapEndianness(ushort x, Endianness targetEndianness)
        {
            if (targetEndianness != SystemEndianness)
            {
                return (ushort)((x >> 8) | (x << 8));
            }
            return x;
        }

        public static uint SwapEndianness(uint x, Endianness targetEndianness)
        {
            if (targetEndianness != SystemEndianness)
            {
                return ((x & 0x000000FF) << 24) |
                       ((x & 0x0000FF00) << 8) |
                       ((x & 0x00FF0000) >> 8) |
                       ((x & 0xFF000000) >> 24);
            }
            return x;
        }

        public static ulong SwapEndianness(ulong x, Endianness targetEndianness)
        {
            if (targetEndianness != SystemEndianness)
            {
                return ((x & 0x00000000000000FF) << 56) |
                       ((x & 0x000000000000FF00) << 40) |
                       ((x & 0x0000000000FF0000) << 24) |
                       ((x & 0x00000000FF000000) << 8) |
                       ((x & 0x000000FF00000000) >> 8) |
                       ((x & 0x0000FF0000000000) >> 24) |
                       ((x & 0x00FF000000000000) >> 40) |
                       ((x & 0xFF00000000000000) >> 56);
            }
            return x;
        }

        // --- Internal Memory Management ---
        private void EnsureCapacity(int bytesToAdd)
        {
            if (_position + bytesToAdd > _data.Length)
            {
                int newSize = _data.Length + bytesToAdd + GrowSize;
                Array.Resize(ref _data, newSize);
            }
        }

        // --- Write Methods ---
        public void WriteRepeat(byte repeatValue, int length)
        {
            EnsureCapacity(length);
            for (int i = 0; i < length; i++)
            {
                _data[_position++] = repeatValue;
            }
            UpdateVirtualLength();
        }

        public void WriteData(byte[] src, int length)
        {
            if (length <= 0) return;
            EnsureCapacity(length);
            Buffer.BlockCopy(src, 0, _data, _position, length);
            _position += length;
            UpdateVirtualLength();
        }

        // Overload for convenience in C#
        public void WriteData(byte[] src) => WriteData(src, src.Length);

        public void WriteWString(string val)
        {
            // Write characters exactly as given. 
            // We will handle the Null Terminator in the Serialize method.
            foreach (char c in val)
            {
                WriteWChar(c);
            }
        }

        public void WriteString(string val)
        {
            // For ASCII strings, C++ AgBuffer::write_string ADDS a null terminator manually
            byte[] bytes = Encoding.UTF8.GetBytes(val);
            foreach (byte b in bytes) WriteU8(b);
            WriteU8(0); // Explicit \0 matching C++
        }

        public void WriteWChar(char c)
        {
            ushort val = (ushort)c;
            val = SwapEndianness(val, _endianness);
            WriteU16(val);
        }

        public void WriteU8(byte val)
        {
            EnsureCapacity(1);
            _data[_position++] = val;
            UpdateVirtualLength();
        }

        public void WriteU16(ushort val)
        {
            val = SwapEndianness(val, _endianness);
            EnsureCapacity(2);
            _data[_position++] = (byte)(val & 0xFF);
            _data[_position++] = (byte)((val >> 8) & 0xFF);
            UpdateVirtualLength();
        }

        public void WriteU32(uint val)
        {
            val = SwapEndianness(val, _endianness);
            EnsureCapacity(4);
            _data[_position++] = (byte)(val & 0xFF);
            _data[_position++] = (byte)((val >> 8) & 0xFF);
            _data[_position++] = (byte)((val >> 16) & 0xFF);
            _data[_position++] = (byte)((val >> 24) & 0xFF);
            UpdateVirtualLength();
        }

        // --- Read Methods ---
        public byte ReadU8()
        {
            if (_position >= _virtualLength) return 0;
            return _data[_position++];
        }

        public ushort ReadU16()
        {
            // C++ reads byte by byte then ORs them.
            if (_position + 2 > _virtualLength) return 0; // Simple boundary check

            ushort val = (ushort)(_data[_position++] | (_data[_position++] << 8));
            return SwapEndianness(val, _endianness);
        }

        public uint ReadU32()
        {
            if (_position + 4 > _virtualLength) return 0;

            uint val = (uint)(_data[_position++] |
                             (_data[_position++] << 8) |
                             (_data[_position++] << 16) |
                             (_data[_position++] << 24));
            return SwapEndianness(val, _endianness);
        }

        public string ReadString()
        {
            List<byte> buf = new List<byte>();
            while (true)
            {
                byte c = ReadU8();
                if (c == 0) break;
                buf.Add(c);
            }
            return Encoding.UTF8.GetString(buf.ToArray());
        }

        public void ReadData(byte[] dst, int length)
        {
            if (dst == null) return;
            if (_position + length > _virtualLength) return; // Not enough data

            Buffer.BlockCopy(_data, _position, dst, 0, length);
            _position += length;
        }

        // --- Utility Methods ---
        public void GetData(int srcOffset, int srcCount, byte[] dst)
        {
            if (dst == null) return;
            if (srcOffset + srcCount > _virtualLength) return;
            if (dst.Length < srcCount) return;

            Buffer.BlockCopy(_data, srcOffset, dst, 0, srcCount);
        }

        public byte[] GetAllData()
        {
            byte[] result = new byte[_virtualLength];
            Buffer.BlockCopy(_data, 0, result, 0, _virtualLength);
            return result;
        }

        public void Seek(int newPosition)
        {
            if (newPosition > _virtualLength)
                _position = _virtualLength;
            else
                _position = newPosition;
        }

        public void SetLength(int length)
        {
            EnsureCapacity(length - _position); // Just ensure array is big enough
            _virtualLength = length;
        }

        public AgBuffer Slice(int length)
        {
            // C++: new AgBuffer(&data[position], length)
            // It copies data from current pos for 'length' bytes into a new buffer.
            if (_position + length > _virtualLength) length = _virtualLength - _position;

            return new AgBuffer(_data, _position, length);
        }

        // Allows direct access to the internal array (unsafe-ish but performant)
        public byte[] GetRawBuffer()
        {
            return _data;
        }

        private void UpdateVirtualLength()
        {
            if (_position > _virtualLength)
            {
                _virtualLength = _position;
            }
        }

        // --- IDisposable ---
        // C++ had a destructor to free(data). C# GC handles memory, 
        // but if you are pooling buffers or strictly want to nullify, you can use this.
        public void Dispose()
        {
            _data = null;
        }
    }
}