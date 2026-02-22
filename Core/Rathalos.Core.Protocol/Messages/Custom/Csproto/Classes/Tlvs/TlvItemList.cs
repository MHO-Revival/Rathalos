using Rathalos.Core.Utils.IO;
using System.Collections.Generic;
using System.IO;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Classes.Tlvs
{
    /// <summary>
    /// Reconstructed TLV Structure (Inventory/Item Container).
    /// C++ Writer: crygame.dll+sub_1010EF10
    /// C++ Printer: crygame.dll+sub_1010F4E0
    /// </summary>
    public class TlvItemList : TlvStructure
    {
        public override TlvMagic Magic => TlvMagic.Fixed;

        // --- Hardcoded Boundary ---
        public const int MaxItems = 2500; // 0x9C4u

        // Field 1 is the item count, but we will rely on Items.Count dynamically.
        public List<TlvItem> Items { get; set; } = new List<TlvItem>();

        public short SafeDataFlag { get; set; }

        protected override void DeserializeContent(IDataReader reader)
        {
            while (reader.BytesAvailable > 0)
            {
                uint tag = reader.ReadVarUInt();
                uint fieldId = tag >> 4;
                uint wireType = tag & 0xF;

                switch (fieldId)
                {
                    case 1:
                        // Read and discard the explicit count (we use Items.Count instead)
                        reader.ReadShort();
                        break;

                    case 2:
                        // Uses the ReadTlvList helper we created earlier!
                        Items = ReadTlvList<TlvItem>(reader);
                        break;

                    case 3:
                        SafeDataFlag = reader.ReadShort();
                        break;

                    default:
                        SkipTlvField(reader, wireType);
                        break;
                }
            }
        }

        protected override void SerializeContent(IDataWriter writer)
        {
            // --- BOUNDARY CHECKS ---
            if (Items.Count > MaxItems)
                throw new InvalidDataException($"[TlvItemList] Items count ({Items.Count}) exceeds maximum of {MaxItems}.");

            // --- SERIALIZATION ---

            // Field 1: Always write the count explicitly as a Short (WireType 2)
            // Note: If you want to force write 0 when empty, use: writer.WriteVarUInt((1 << 4) | 2); writer.WriteShort(0);
            WriteTlvShort(writer, 1, (short)Items.Count);

            // Field 2: Write the Length-Delimited List of TlvItems (WireType 5)
            WriteTlvList(writer, 2, Items);

            // Field 3: Write SafeDataFlag (WireType 2)
            WriteTlvShort(writer, 3, SafeDataFlag);
        }
    }
}