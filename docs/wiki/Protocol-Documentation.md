# Protocol Documentation

This document describes the network protocol used by the Rathalos server for communication with Monster Hunter Online clients.

## Overview

The Rathalos server uses two main protocols:

1. **Tqqapi** - Authentication and connection management
2. **Csproto** - Game logic and commands

Both protocols use **TLV (Type-Length-Value)** encoding for efficient binary serialization.

---

## Protocol Architecture

```
┌─────────────┐          ┌──────────────┐          ┌──────────────┐
│   Client    │◄────────►│ Tqqapi Layer │◄────────►│  Auth Server │
│             │          └──────────────┘          └──────────────┘
│             │                   │
│             │                   ▼
│             │          ┌──────────────┐          ┌──────────────┐
│             │◄────────►│ Csproto Layer│◄────────►│ World Server │
└─────────────┘          └──────────────┘          └──────────────┘
```

---

## TLV Structure

### What is TLV?

TLV (Type-Length-Value) is a binary encoding format where each data field consists of:

- **Type**: Field identifier (varies)
- **Length**: Size of the value (varies)
- **Value**: The actual data

### TLV Format

```
┌──────┬────────┬─────────────┐
│ Tag  │ Length │    Value    │
├──────┼────────┼─────────────┤
│VarInt│VarInt  │ Raw Bytes   │
└──────┴────────┴─────────────┘
```

### Variable-Length Integers (VarInt)

The protocol uses variable-length encoding for integers:

```csharp
// Reading VarInt
public uint ReadVarUInt()
{
    uint result = 0;
    int shift = 0;
    byte b;
    do
    {
        b = ReadByte();
        result |= (uint)(b & 0x7F) << shift;
        shift += 7;
    } while ((b & 0x80) != 0);
    return result;
}
```

### TLV Tag Format

Each TLV tag encodes both the field ID and wire type:

```
Tag = (FieldID << 4) | WireType
```

- **Field ID**: Unique identifier for the field (high 28 bits)
- **Wire Type**: Encoding type (low 4 bits)

### Wire Types

| Wire Type | Value | Description | Example |
|-----------|-------|-------------|---------|
| VarInt | 0 | Variable-length integer | Player level |
| Fixed64 | 1 | 64-bit value | Timestamp |
| LengthDelimited | 2 | Length-prefixed data | Strings, bytes |
| StartGroup | 3 | Deprecated | - |
| EndGroup | 4 | Deprecated | - |
| Fixed32 | 5 | 32-bit value | Float |

---

## TLV Structure Classes

### Base TlvStructure

All TLV messages inherit from `TlvStructure`:

```csharp
public abstract class TlvStructure
{
    public abstract TlvMagic Magic { get; }

    protected abstract void DeserializeContent(IDataReader reader);
    protected abstract void SerializeContent(IDataWriter writer);

    // Helper methods
    protected void ReadTlvObject<T>(IDataReader reader, out T obj) where T : TlvStructure, new();
    protected void WriteTlvObject<T>(IDataWriter writer, uint fieldId, T obj) where T : TlvStructure;
}
```

### Example: TlvRoleNames

From the file you provided:

```csharp
public class TlvRoleNames : TlvStructure
{
    public override TlvMagic Magic => TlvMagic.Fixed;
    public const int MaxNameLength = 32;

    public string Name { get; set; } = string.Empty;  // Field ID: 1
    public string Guild { get; set; } = string.Empty; // Field ID: 2
    public string Clan { get; set; } = string.Empty;  // Field ID: 3

    protected override void DeserializeContent(IDataReader reader)
    {
        while (reader.BytesAvailable > 0)
        {
            uint tag = reader.ReadVarUInt();
            uint fieldId = tag >> 4;
            uint wireType = tag & 0xF;

            switch (fieldId)
            {
                case 1: Name = ReadTlvString(reader); break;
                case 2: Guild = ReadTlvString(reader); break;
                case 3: Clan = ReadTlvString(reader); break;
                default: SkipTlvField(reader, wireType); break;
            }
        }
    }

    protected override void SerializeContent(IDataWriter writer)
    {
        WriteTlvString(writer, 1, Name);
        WriteTlvString(writer, 2, Guild);
        WriteTlvString(writer, 3, Clan);
    }
}
```

### Binary Wire Format Example

For a `TlvRoleNames` with:
- Name: "Hunter"
- Guild: "MHO Revival"
- Clan: ""

```
┌──────────────────────────────────────────────────┐
│ Field 1 (Name)                                   │
├────────┬────────┬──────────────────────────────┤
│ Tag    │ Length │ Value                        │
│ 0x12   │ 0x06   │ "Hunter" (UTF-8)             │
├────────┼────────┼──────────────────────────────┤
│ Field 2 (Guild)                                  │
├────────┬────────┬──────────────────────────────┤
│ Tag    │ Length │ Value                        │
│ 0x22   │ 0x0B   │ "MHO Revival" (UTF-8)        │
└────────┴────────┴──────────────────────────────┘
```

Where:
- `0x12` = `(1 << 4) | 2` = Field ID 1, Wire Type 2 (LengthDelimited)
- `0x22` = `(2 << 4) | 2` = Field ID 2, Wire Type 2

---

## Csproto Protocol

### Command Structure

Csproto messages follow this pattern:

```csharp
public class CSPkg
{
    public CSPkgHead Head { get; set; }
    public CSPkgBody Body { get; set; }
}
```

### Command IDs

Commands are identified by `CS_CMD_ID` enum:

```csharp
public enum CS_CMD_ID : uint
{
    // Character Commands
    CS_CREATE_ROLE_REQ = 0x1001,
    CS_CREATE_ROLE_RSP = 0x1002,
    CS_SELECT_ROLE_REQ = 0x1003,
    CS_SELECT_ROLE_RSP = 0x1004,

    // Chat Commands
    CS_CHAT_REQ = 0x2001,
    CS_CHAT_RSP = 0x2002,
    CS_CHAT_NTF = 0x2003,

    // ... hundreds more
}
```

### Packet Flow

```
Client ──[REQUEST]──►  Server
       ◄──[RESPONSE]── Server
       ◄──[NOTIFY]──── Server
```

### Example Messages

#### Character Creation Request
```csharp
public class CSPkgBodyCreateRoleReq
{
    public string Name { get; set; }
    public CS_GENDER Gender { get; set; }
    public uint FaceId { get; set; }
    public uint HairId { get; set; }
    public uint ClothesId { get; set; }
}
```

#### Character Creation Response
```csharp
public class CSPkgBodyCreateRoleRsp
{
    public bool Success { get; set; }
    public uint ErrorCode { get; set; }
    public CRole Role { get; set; }  // Contains full character data
}
```

---

## Tqqapi Protocol

### Purpose

Tqqapi handles:
- Client authentication
- Connection management
- Session establishment
- Heartbeat/keepalive

### TPDU Structure

```csharp
public class TPDUBase
{
    public TPDUHead Head { get; set; }
    public TPDUExt Extension { get; set; }
    public byte[] Body { get; set; }
}
```

### TPDU Commands

```csharp
public enum TPDU_CMD : byte
{
    TPDU_NONE = 0,
    TPDU_SYN = 1,        // Connection request
    TPDU_SYN_ACK = 2,    // Connection acknowledgment
    TPDU_AUTH = 3,       // Authentication
    TPDU_AUTH_ACK = 4,   // Authentication response
    TPDU_RELAY = 5,      // Relay data
    TPDU_STOP = 6,       // Disconnect
}
```

### Authentication Flow

```
Client                        Server
  │                             │
  ├────── TPDU_SYN ──────────►  │
  │                             │
  │ ◄───── TPDU_SYN_ACK ───────┤
  │                             │
  ├────── TPDU_AUTH ──────────►  │
  │      (TQQUnifiedAuthInfo)   │
  │                             │
  │ ◄───── TPDU_AUTH_ACK ──────┤
  │      (Session Token)        │
  │                             │
  ├────── TPDU_RELAY ─────────►  │
  │      (Game Data)            │
  │                             │
```

---

## Data Types

### Primitive Types

| Type | Size | Description |
|------|------|-------------|
| `byte` | 1 byte | Unsigned 8-bit |
| `short` | 2 bytes | Signed 16-bit |
| `ushort` | 2 bytes | Unsigned 16-bit |
| `int` | 4 bytes | Signed 32-bit |
| `uint` | 4 bytes | Unsigned 32-bit |
| `long` | 8 bytes | Signed 64-bit |
| `ulong` | 8 bytes | Unsigned 64-bit |
| `float` | 4 bytes | IEEE 754 float |
| `double` | 8 bytes | IEEE 754 double |

### Complex Types

#### Strings
```csharp
// UTF-8 encoded, length-prefixed
int length = reader.ReadInt();
byte[] bytes = reader.ReadBytes(length);
string text = Encoding.UTF8.GetString(bytes);
```

#### Arrays
```csharp
// Count-prefixed
int count = reader.ReadInt();
for (int i = 0; i < count; i++)
{
    // Read elements
}
```

#### Nested TLV Objects
```csharp
// Use ReadTlvObject helper
ReadTlvObject(reader, out TlvAttributeItem attr);
```

---

## Protocol Helpers

### IDataReader Interface

```csharp
public interface IDataReader
{
    int BytesAvailable { get; }
    byte ReadByte();
    byte[] ReadBytes(int count);
    short ReadShort();
    int ReadInt();
    long ReadLong();
    float ReadFloat();
    uint ReadVarUInt();
}
```

### IDataWriter Interface

```csharp
public interface IDataWriter
{
    void WriteByte(byte value);
    void WriteBytes(byte[] value);
    void WriteShort(short value);
    void WriteInt(int value);
    void WriteLong(long value);
    void WriteFloat(float value);
    void WriteVarUInt(uint value);
}
```

---

## Best Practices

### For TLV Nested Sub-Structures

**From `.github/copilot-instructions.md`:**

> For TLV nested sub-structures, use the existing `ReadTlvObject`/`WriteTlvObject` helpers. Do not create separate `ReadTlvInlineObject`/`WriteTlvInlineObject` methods — `ReadTlvObject` already handles nested TLV content.

### Reading Nested TLV

```csharp
case FieldId.NestedObject:
{
    ReadTlvObject(reader, out TlvNestedType nested);
    MyNestedProperty = nested;
    break;
}
```

### Writing Nested TLV

```csharp
if (MyNestedProperty != null)
{
    WriteTlvObject(writer, FieldId.NestedObject, MyNestedProperty);
}
```

### Error Handling

Always handle unknown fields gracefully:

```csharp
default:
    SkipTlvField(reader, wireType);
    break;
```

---

## Message Categories

### Character Management
- Character creation/deletion
- Character selection
- Character attributes sync

### Inventory & Items
- Item management (add/remove/move)
- Equipment changes
- Item box operations

### Combat & Skills
- Skill usage
- Damage calculation
- Buff/debuff application

### Social Systems
- Guild/clan operations
- Friends list
- Chat messages
- Trading

### World Events
- Monster spawning
- NPC interactions
- Quest management

---

## Debugging Protocol Messages

### Enable Protocol Logging

```json
"Logging": {
  "LogLevel": {
    "Rathalos.Core.Protocol": "Trace"
  }
}
```

### Hex Dump Format

```
00000000  12 06 48 75 6e 74 65 72  22 0B 4D 48 4F 20 52 65  |..Hunter"..MHO Re|
00000010  76 69 76 61 6c                                    |vival|
```

---

## References

- [TLV Structure Implementation](../Core/Rathalos.Core.Protocol/Messages/Custom/Csproto/Classes/TlvStructure.cs)
- [Csproto Command IDs](../Core/Rathalos.Core.Protocol/Messages/Csproto/Enums/CS_CMD_ID.cs)
- [Tqqapi Commands](../Core/Rathalos.Core.Protocol/Messages/Tqqapi/Enums/TPDU_CMD.cs)

---

## Next Steps

- [Development Guide](Development-Guide)
- [Architecture Overview](Architecture)
- [API Reference](API-Reference)
