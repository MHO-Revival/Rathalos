using Rathalos.Core.Utils.IO;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes
{
    public enum TlvMagic
    {
        Debug = 0xAF,
        Dynamic = 0xAA,
        Fixed = 0x99,
    }

    public abstract class TlvStructure
    {
        public virtual TlvMagic Magic { get; private set; } = TlvMagic.Fixed;

        public byte[] Pack()
        {
            var writer = new BufferWriter();
            Serialize(writer);
            return writer.Data;
        }

        public void Unpack(byte[] data)
        {
            var reader = new BufferReader(data);
            Deserialize(reader);
        }

        private void Deserialize(IDataReader reader)
        {
            Magic = (TlvMagic)reader.ReadByte();
            if (Magic != TlvMagic.Fixed && Magic != TlvMagic.Dynamic)
                return;

            var contentLength = reader.ReadInt();
            var contentData = reader.ReadBytes(contentLength);
            var contentReader = new BufferReader(contentData);
            DeserializeContent(contentReader);
        }

        protected abstract void DeserializeContent(IDataReader reader);

        private void Serialize(IDataWriter writer)
        {
            writer.WriteByte((byte)Magic);
            if (Magic != TlvMagic.Fixed && Magic != TlvMagic.Dynamic)
                return;

            var bufferContent = new BufferWriter();
            SerializeContent(bufferContent);

            writer.WriteInt((int)bufferContent.Data.Length + 5);
            writer.WriteBytes(bufferContent.Data);
        }

        protected abstract void SerializeContent(IDataWriter writer);

        #region Helpers to perfectly match C++ `TdrBuf` logic

        protected void WriteTlvByte(IDataWriter writer, uint fieldId, byte value)
        {
            // Skip default/0 values to save network bandwidth (standard Protobuf/TDR behavior)
            if (value == 0) return;

            // FieldID shifted left by 4, combined with WireType 1 (which the C++ uses for raw bytes)
            writer.WriteVarUInt((fieldId << 4) | 1);
            writer.WriteByte(value);
        }

        protected void WriteTlvShort(IDataWriter writer, uint fieldId, short value)
        {
            if (value == 0) return; // Skip default values to save bandwidth
            writer.WriteVarUInt((fieldId << 4) | 2); // WireType 2
            writer.WriteShort(value);
        }

        protected void WriteTlvInt(IDataWriter writer, uint fieldId, int value)
        {
            if (value == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 3); // WireType 3
            writer.WriteInt(value);
        }

        protected void WriteTlvFloat(IDataWriter writer, uint fieldId, float value)
        {
            if (value == 0f) return;
            writer.WriteVarUInt((fieldId << 4) | 3); // WireType 3
            writer.WriteFloat(value);
        }

        protected void WriteTlvLong(IDataWriter writer, uint fieldId, long value)
        {
            if (value == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 4); // WireType 4
            writer.WriteLong(value);
        }

        protected void WriteTlvVarInt(IDataWriter writer, uint fieldId, int value)
        {
            if (value == 0) return; // Skip defaults
            writer.WriteVarUInt((fieldId << 4) | 0); // WireType 0
            writer.WriteVarInt(value);
        }

        protected void WriteStrictIntArray(IDataWriter writer, uint fieldId, int[] arr, int fixedLength)
        {
            if (arr == null) return;

            if (arr.Length != fixedLength)
                throw new InvalidDataException($"[CharTlvAttributes] Field {fieldId} array length is {arr.Length}. It MUST be exactly {fixedLength}.");

            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5 (Length Delimited)

            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            for (int i = 0; i < fixedLength; i++)
            {
                writer.WriteInt(arr[i]);
            }

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }

        protected void WriteStrictFloatArray(IDataWriter writer, uint fieldId, float[] arr, int fixedLength)
        {
            if (arr == null) return;

            if (arr.Length != fixedLength)
                throw new InvalidDataException($"[CharTlvAttributes] Field {fieldId} float array length is {arr.Length}. It MUST be exactly {fixedLength}.");

            writer.WriteVarUInt((fieldId << 4) | 5);

            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            for (int i = 0; i < fixedLength; i++)
            {
                writer.WriteFloat(arr[i]);
            }

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }
        
        protected short[] ReadTlvVarShortArray(IDataReader reader)
        {
            // 1. Read the Total Byte Length of the array wrapper
            int byteLen = reader.ReadInt();

            // 2. Calculate exactly where this array ends in the stream
            long endPosition = reader.Position + byteLen;
            var list = new List<short>();

            // 3. Keep reading VarShorts until we hit the end position
            while (reader.Position < endPosition)
            {
                list.Add(reader.ReadVarShort());
            }

            return list.ToArray();
        }
        // Helper for VarShort Arrays that respects a specific count
        protected void WriteTlvVarShortArray(IDataWriter writer, uint fieldId, short[] arr)
        {
            if (arr == null || arr.Length == 0) return;

            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5
            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            // Safely loop up to 'count' (ensuring we don't go out of bounds of the actual array)
            for (int i = 0; i < arr.Length; i++)
            {
                writer.WriteVarShort(arr[i]);
            }

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }

        protected void WriteTlvIntArray(IDataWriter writer, uint fieldId, int[] arr)
        {
            if (arr == null || arr.Length == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5

            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            for (int i = 0; i < arr.Length; i++)
                writer.WriteInt(arr[i]);

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }

        protected void WriteTlvFloatArray(IDataWriter writer, uint fieldId, float[] arr)
        {
            if (arr == null || arr.Length == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5

            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            for (int i = 0; i < arr.Length; i++)
                writer.WriteFloat(arr[i]);

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }

        // And the readers for the Length-Delimited arrays
        protected int[] ReadTlvIntArray(IDataReader reader)
        {
            int byteLen = reader.ReadInt();
            int count = byteLen / 4;
            int[] arr = new int[count];
            for (int i = 0; i < count; i++) arr[i] = reader.ReadInt();
            return arr;
        }

        protected float[] ReadTlvFloatArray(IDataReader reader)
        {
            int byteLen = reader.ReadInt();
            int count = byteLen / 4;
            float[] arr = new float[count];
            for (int i = 0; i < count; i++) arr[i] = reader.ReadFloat();
            return arr;
        }

        protected void WriteTlvByteArray(IDataWriter writer, uint fieldId, byte[] data)
        {
            if (data == null || data.Length == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5

            writer.WriteInt(data.Length); // Raw byte arrays often just write length directly
            writer.WriteBytes(data);
        }

        protected int[] ReadTlvVarIntArray(IDataReader reader)
        {
            // A Length-Delimited VarInt array
            int byteLen = reader.ReadInt();

            // Create a temporary sub-reader or track start position
            long endPosition = reader.Position + byteLen;
            var list = new List<int>();

            while (reader.Position < endPosition)
            {
                list.Add(reader.ReadVarInt());
            }

            return list.ToArray();
        }

        protected void WriteTlvVarIntArray(IDataWriter writer, uint fieldId, int[] arr)
        {
            if (arr == null || arr.Length == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5 (Length-delimited)

            long lenPos = writer.ReserveInt();
            long startPos = writer.Position;

            for (int i = 0; i < arr.Length; i++)
            {
                writer.WriteVarInt(arr[i]);
            }

            writer.WriteIntAtPosition((int)(writer.Position - startPos), lenPos);
        }

        protected void WriteTlvList<T>(IDataWriter writer, uint fieldId, List<T> items) where T : TlvStructure
        {
            if (items == null || items.Count == 0) return;
            writer.WriteVarUInt((fieldId << 4) | 5); // WireType 5

            long listLenPos = writer.ReserveInt();
            long listStartPos = writer.Position;

            foreach (var item in items)
            {
                long itemLenPos = writer.ReserveInt();
                long itemStartPos = writer.Position;

                // Let the nested TLV serialize its own content
                item.SerializeContent(writer);

                writer.WriteIntAtPosition((int)(writer.Position - itemStartPos), itemLenPos);
            }

            writer.WriteIntAtPosition((int)(writer.Position - listStartPos), listLenPos);
        }

        protected List<T> ReadTlvList<T>(IDataReader reader) where T : TlvStructure, new()
        {
            var list = new List<T>();

            // 1. Read the total length of the entire list (in bytes)
            int listByteLen = reader.ReadInt();
            long listEndPos = reader.Position + listByteLen;

            // 2. Loop until we've consumed all the bytes for this list
            while (reader.Position < listEndPos)
            {
                // 3. Read the specific length of THIS single item
                int itemByteLen = reader.ReadInt();

                // 4. Extract only this item's bytes and create a temporary reader for it
                byte[] itemData = reader.ReadBytes(itemByteLen);
                var itemReader = new Rathalos.Core.Utils.IO.BufferReader(itemData);

                // 5. Instantiate the TLV object and deserialize it safely
                var item = new T();
                item.DeserializeContent(itemReader);
                list.Add(item);
            }

            return list;
        }

        protected void SkipTlvField(IDataReader reader, uint wireType)
        {
            switch (wireType)
            {
                case 0:
                    // WireType 0: VarInt / VarLong
                    reader.ReadVarULong(); // (Or ReadVarUInt(), they consume the exact same bytes)
                    break;

                case 1:
                    // WireType 1: Fixed 8-bit (1 byte)
                    reader.ReadByte();
                    break;

                case 2:
                    // WireType 2: Fixed 16-bit (2 bytes)
                    reader.ReadShort();
                    break;

                case 3:
                    // WireType 3: Fixed 32-bit (4 bytes)
                    reader.ReadInt();
                    break;

                case 4:
                    // WireType 4: Fixed 64-bit (8 bytes)
                    reader.ReadLong();
                    break;

                case 5:
                    // WireType 5: Length-Delimited
                    // Reads a 4-byte Int32 to get the length, then skips that many bytes
                    int byteLength = reader.ReadInt();

                    // If your reader supports it, use: reader.BaseStream.Position += byteLength;
                    // Otherwise, just read and discard the bytes:
                    reader.ReadBytes(byteLength);
                    break;

                default:
                    throw new InvalidDataException($"[SkipTlvField] Unrecognized WireType: {wireType}. Possible corrupted packet!");
            }
        }
        #endregion
    }
}
