// ============================================================
// Name: TLV::UnkTlv0185::Read_0xAA
// Address Name: SUB_101A4CC0
// ============================================================
//----- (101A4CC0) --------------------------------------------------------
int __thiscall sub_101A4CC0(int this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h] BYREF
  unsigned int v16; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v16 = 0;
  *(_DWORD *)(this + 1272) = 0;
  v7 = v4[1] + v3;
  v12 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_125:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 1272) & 1) == 0 )
          *(_DWORD *)(this + 1272) |= 1u;
        VarInt = sub_10115A30(v4, (_BYTE *)this);
        goto LABEL_123;
      case 3u:
        if ( (*(_DWORD *)(this + 1272) & 2) == 0 )
          *(_DWORD *)(this + 1272) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 1));
        goto LABEL_123;
      case 4u:
        if ( (*(_DWORD *)(this + 1272) & 4) == 0 )
          *(_DWORD *)(this + 1272) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 5));
        goto LABEL_123;
      case 5u:
        if ( (*(_DWORD *)(this + 1272) & 8) == 0 )
          *(_DWORD *)(this + 1272) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 9), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + Size + 9) = 0;
        goto LABEL_124;
      case 6u:
        if ( (*(_DWORD *)(this + 1272) & 0x10) == 0 )
          *(_DWORD *)(this + 1272) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 41), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + Size + 41) = 0;
          goto LABEL_124;
        }
        return Bytes;
      case 7u:
        if ( (*(_DWORD *)(this + 1272) & 0x20) == 0 )
          *(_DWORD *)(this + 1272) |= 0x20u;
        VarInt = sub_10115A30(v4, (_BYTE *)(this + 73));
        goto LABEL_123;
      case 8u:
        if ( (*(_DWORD *)(this + 1272) & 0x40) == 0 )
          *(_DWORD *)(this + 1272) |= 0x40u;
        VarInt = sub_10115A30(v4, (_BYTE *)(this + 74));
        goto LABEL_123;
      case 9u:
        if ( (*(_DWORD *)(this + 1272) & 0x80) == 0 )
          *(_DWORD *)(this + 1272) |= 0x80u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 75));
        goto LABEL_123;
      case 0xAu:
        if ( (*(_DWORD *)(this + 1272) & 0x100) == 0 )
          *(_DWORD *)(this + 1272) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 79));
        goto LABEL_123;
      case 0xBu:
        if ( (*(_DWORD *)(this + 1272) & 0x200) == 0 )
          *(_DWORD *)(this + 1272) |= 0x200u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 83));
        goto LABEL_123;
      case 0xCu:
        if ( (*(_DWORD *)(this + 1272) & 0x400) == 0 )
          *(_DWORD *)(this + 1272) |= 0x400u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 85));
        goto LABEL_123;
      case 0xEu:
        if ( (*(_DWORD *)(this + 1272) & 0x800) == 0 )
          *(_DWORD *)(this + 1272) |= 0x800u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 87));
        goto LABEL_123;
      case 0xFu:
        if ( (*(_DWORD *)(this + 1272) & 0x1000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x1000u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 89));
        goto LABEL_123;
      case 0x10u:
        if ( (*(_DWORD *)(this + 1272) & 0x2000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x2000u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 91));
        goto LABEL_123;
      case 0x11u:
        if ( (*(_DWORD *)(this + 1272) & 0x4000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x4000u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 95));
        goto LABEL_123;
      case 0x12u:
        if ( (*(_DWORD *)(this + 1272) & 0x8000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x8000u;
        VarInt = sub_10115A30(v4, (_BYTE *)(this + 99));
        goto LABEL_123;
      case 0x15u:
        if ( (*(_DWORD *)(this + 1272) & 0x10000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x10000u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 100));
        goto LABEL_123;
      case 0x16u:
        if ( (*(_DWORD *)(this + 1272) & 0x20000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x20000u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          goto LABEL_131;
        v14 = v4[1];
        Size = 0;
        while ( 2 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v4, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1019E250(this + 8 * (__int16)Size + (__int16)Size + 102, v4, v15);
            if ( Bytes )
              return Bytes;
          }
          v10 = v4[1];
          if ( v10 > v14 + a3 )
            goto LABEL_130;
          if ( v10 != v14 + a3 )
          {
            if ( (__int16)++Size >= 70 )
              goto LABEL_124;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 100) = Size + 1;
        goto LABEL_124;
      case 0x17u:
        if ( (*(_DWORD *)(this + 1272) & 0x40000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x40000u;
        VarInt = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 732));
        goto LABEL_123;
      case 0x18u:
        if ( (*(_DWORD *)(this + 1272) & 0x80000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x80000u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v14 = v4[1];
          Size = 0;
          while ( 1 )
          {
            v15 = 0;
            Bytes = TdrBuf::ReadInt32(v4, &v15);
            if ( Bytes )
              return Bytes;
            if ( v15 )
            {
              Bytes = sub_1019E900(this + 2 * (5 * (__int16)Size + 367), v4, v15);
              if ( Bytes )
                return Bytes;
            }
            v11 = v4[1];
            if ( v11 > v14 + a3 )
              break;
            if ( v11 == v14 + a3 )
            {
              *(_WORD *)(this + 732) = Size + 1;
LABEL_124:
              v7 = v12;
              if ( v4[1] >= v12 )
                goto LABEL_125;
              goto LABEL_2;
            }
            if ( (__int16)++Size >= 10 )
              goto LABEL_124;
          }
LABEL_130:
          result = -34;
        }
        else
        {
LABEL_131:
          result = -37;
        }
        break;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 1272) & 0x100000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x100000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        VarInt = sub_1019EF80(this + 834, v4, Size);
        goto LABEL_123;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 1272) & 0x200000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x200000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        VarInt = sub_1019F930((int *)(this + 843), (size_t)v4, Size);
        goto LABEL_123;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 1272) & 0x400000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x400000u;
        VarInt = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 911));
        goto LABEL_123;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 1272) & 0x800000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x800000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        VarInt = sub_101A2350(this + 912, v4, Size);
        goto LABEL_123;
      case 0x20u:
        if ( (*(_DWORD *)(this + 1272) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x1000000u;
        Bytes = TdrBuf::ReadInt32(v4, &v13);
        if ( Bytes )
          return Bytes;
        *(_DWORD *)(this + 1160) = v13;
        goto LABEL_124;
      case 0x21u:
        if ( (*(_DWORD *)(this + 1272) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x2000000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        VarInt = sub_101A2F70((_DWORD *)(this + 1164), v4, Size);
        goto LABEL_123;
      case 0x22u:
        if ( (*(_DWORD *)(this + 1272) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x4000000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        VarInt = sub_101A3790((int *)(this + 1260), v4, Size);
LABEL_123:
        Bytes = VarInt;
        if ( !VarInt )
          goto LABEL_124;
        return Bytes;
      default:
        VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
        goto LABEL_123;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0185::Read_0x99
// Address Name: SUB_101A54E0
// ============================================================
//----- (101A54E0) --------------------------------------------------------
int __thiscall sub_101A54E0(int this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h] BYREF
  unsigned int v16; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v16 = 0;
  *(_DWORD *)(this + 1272) = 0;
  v7 = v4[1] + v3;
  v12 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_125:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 1272) & 1) == 0 )
          *(_DWORD *)(this + 1272) |= 1u;
        Int32 = sub_10115A30(v4, (_BYTE *)this);
        goto LABEL_123;
      case 3u:
        if ( (*(_DWORD *)(this + 1272) & 2) == 0 )
          *(_DWORD *)(this + 1272) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1));
        goto LABEL_123;
      case 4u:
        if ( (*(_DWORD *)(this + 1272) & 4) == 0 )
          *(_DWORD *)(this + 1272) |= 4u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 5));
        goto LABEL_123;
      case 5u:
        if ( (*(_DWORD *)(this + 1272) & 8) == 0 )
          *(_DWORD *)(this + 1272) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 9), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + Size + 9) = 0;
        goto LABEL_124;
      case 6u:
        if ( (*(_DWORD *)(this + 1272) & 0x10) == 0 )
          *(_DWORD *)(this + 1272) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 41), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + Size + 41) = 0;
          goto LABEL_124;
        }
        return Bytes;
      case 7u:
        if ( (*(_DWORD *)(this + 1272) & 0x20) == 0 )
          *(_DWORD *)(this + 1272) |= 0x20u;
        Int32 = sub_10115A30(v4, (_BYTE *)(this + 73));
        goto LABEL_123;
      case 8u:
        if ( (*(_DWORD *)(this + 1272) & 0x40) == 0 )
          *(_DWORD *)(this + 1272) |= 0x40u;
        Int32 = sub_10115A30(v4, (_BYTE *)(this + 74));
        goto LABEL_123;
      case 9u:
        if ( (*(_DWORD *)(this + 1272) & 0x80) == 0 )
          *(_DWORD *)(this + 1272) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 75));
        goto LABEL_123;
      case 0xAu:
        if ( (*(_DWORD *)(this + 1272) & 0x100) == 0 )
          *(_DWORD *)(this + 1272) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 79));
        goto LABEL_123;
      case 0xBu:
        if ( (*(_DWORD *)(this + 1272) & 0x200) == 0 )
          *(_DWORD *)(this + 1272) |= 0x200u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 83));
        goto LABEL_123;
      case 0xCu:
        if ( (*(_DWORD *)(this + 1272) & 0x400) == 0 )
          *(_DWORD *)(this + 1272) |= 0x400u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 85));
        goto LABEL_123;
      case 0xEu:
        if ( (*(_DWORD *)(this + 1272) & 0x800) == 0 )
          *(_DWORD *)(this + 1272) |= 0x800u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 87));
        goto LABEL_123;
      case 0xFu:
        if ( (*(_DWORD *)(this + 1272) & 0x1000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x1000u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 89));
        goto LABEL_123;
      case 0x10u:
        if ( (*(_DWORD *)(this + 1272) & 0x2000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 91));
        goto LABEL_123;
      case 0x11u:
        if ( (*(_DWORD *)(this + 1272) & 0x4000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 95));
        goto LABEL_123;
      case 0x12u:
        if ( (*(_DWORD *)(this + 1272) & 0x8000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x8000u;
        Int32 = sub_10115A30(v4, (_BYTE *)(this + 99));
        goto LABEL_123;
      case 0x15u:
        if ( (*(_DWORD *)(this + 1272) & 0x10000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x10000u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 100));
        goto LABEL_123;
      case 0x16u:
        if ( (*(_DWORD *)(this + 1272) & 0x20000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x20000u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          goto LABEL_131;
        v14 = v4[1];
        Size = 0;
        while ( 2 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v4, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1019E340(this + 8 * (__int16)Size + (__int16)Size + 102, v4, v15);
            if ( Bytes )
              return Bytes;
          }
          v10 = v4[1];
          if ( v10 > v14 + a3 )
            goto LABEL_130;
          if ( v10 != v14 + a3 )
          {
            if ( (__int16)++Size >= 70 )
              goto LABEL_124;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 100) = Size + 1;
        goto LABEL_124;
      case 0x17u:
        if ( (*(_DWORD *)(this + 1272) & 0x40000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x40000u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 732));
        goto LABEL_123;
      case 0x18u:
        if ( (*(_DWORD *)(this + 1272) & 0x80000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x80000u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v14 = v4[1];
          Size = 0;
          while ( 1 )
          {
            v15 = 0;
            Bytes = TdrBuf::ReadInt32(v4, &v15);
            if ( Bytes )
              return Bytes;
            if ( v15 )
            {
              Bytes = sub_1019E9A0((char *)(this + 2 * (5 * (__int16)Size + 367)), v4, v15);
              if ( Bytes )
                return Bytes;
            }
            v11 = v4[1];
            if ( v11 > v14 + a3 )
              break;
            if ( v11 == v14 + a3 )
            {
              *(_WORD *)(this + 732) = Size + 1;
LABEL_124:
              v7 = v12;
              if ( v4[1] >= v12 )
                goto LABEL_125;
              goto LABEL_2;
            }
            if ( (__int16)++Size >= 10 )
              goto LABEL_124;
          }
LABEL_130:
          result = -34;
        }
        else
        {
LABEL_131:
          result = -37;
        }
        break;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 1272) & 0x100000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x100000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        Int32 = sub_1019F070(this + 834, v4, Size);
        goto LABEL_123;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 1272) & 0x200000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x200000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        Int32 = sub_1019FB40(this + 843, (size_t)v4, Size);
        goto LABEL_123;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 1272) & 0x400000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x400000u;
        Int32 = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 911));
        goto LABEL_123;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 1272) & 0x800000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x800000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        Int32 = sub_101A2590(this + 912, v4, Size);
        goto LABEL_123;
      case 0x20u:
        if ( (*(_DWORD *)(this + 1272) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x1000000u;
        Bytes = TdrBuf::ReadInt32(v4, &v13);
        if ( Bytes )
          return Bytes;
        *(_DWORD *)(this + 1160) = v13;
        goto LABEL_124;
      case 0x21u:
        if ( (*(_DWORD *)(this + 1272) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x2000000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        Int32 = sub_101A30D0((_DWORD *)(this + 1164), v4, Size);
        goto LABEL_123;
      case 0x22u:
        if ( (*(_DWORD *)(this + 1272) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1272) |= 0x4000000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v4, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_124;
        Int32 = sub_101A3830(this + 1260, v4, Size);
LABEL_123:
        Bytes = Int32;
        if ( !Int32 )
          goto LABEL_124;
        return Bytes;
      default:
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
        goto LABEL_123;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0185::DoDebugFormat
// Address Name: SUB_101A5D20
// ============================================================
//----- (101A5D20) --------------------------------------------------------
int __thiscall sub_101A5D20(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
{
  int v7; // esi
  signed __int32 v8; // [esp+8h] [ebp-1Ch] BYREF
  int v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  char v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+20h] [ebp-4h]

  if ( !a2 )
    return -19;
  v8 = a2;
  v11 = 0;
  v9 = 0;
  v10 = a3;
  v12 = 0;
  v7 = sub_101A5DD0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0185::DebugFormat
// Address Name: SUB_101A5DD0
// ============================================================
//----- (101A5DD0) --------------------------------------------------------
int __thiscall sub_101A5DD0(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  __int16 v8; // cx
  int v9; // eax
  __int16 v10; // cx
  int v11; // eax
  char *v12; // ecx
  const char *v13; // ecx
  __int16 *v14; // ecx
  __int16 *v15; // ecx
  _DWORD *v16; // ecx
  int v17; // [esp+20h] [ebp+Ch]
  int v18; // [esp+20h] [ebp+Ch]
  int v19; // [esp+24h] [ebp+10h]
  int v20; // [esp+24h] [ebp+10h]

  result = print_field(a2, a3, a4, "[idx]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[uId]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)(this + 5));
      if ( !result )
      {
        result = sub_1024A410(a2, a3, a4, "[name]", this + 9);
        if ( !result )
        {
          result = sub_1024A410(a2, a3, a4, "[desc]", this + 41);
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[sex]", "0x%02x", *(this + 73));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[state]", "0x%02x", *(this + 74));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[level]", "%d", *(_DWORD *)(this + 75));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[exp]", "%d", *(_DWORD *)(this + 79));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[loyal]", "%d", *(__int16 *)(this + 83));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[potential]", "%d", *(__int16 *)(this + 85));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[spirit]", "%d", *(__int16 *)(this + 87));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[vigour]", "%d", *(__int16 *)(this + 89));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[supportSkill]", "%d", *(_DWORD *)(this + 91));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[giftSkill]", "%d", *(_DWORD *)(this + 95));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[rename]", "0x%02x", *(this + 99));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[groupNum]", "%d", *((__int16 *)this + 50));
                                  if ( !result )
                                  {
                                    v8 = *((_WORD *)this + 50);
                                    if ( v8 < 0 )
                                      return -6;
                                    if ( v8 > 70 )
                                      return -7;
                                    LOWORD(v9) = 0;
                                    v17 = 0;
                                    if ( v8 <= 0 )
                                    {
LABEL_29:
                                      result = print_field(a2, a3, a4, "[potentialNum]", "%d", *((__int16 *)this + 366));
                                      if ( !result )
                                      {
                                        v10 = *((_WORD *)this + 366);
                                        if ( v10 < 0 )
                                          return -6;
                                        if ( v10 > 10 )
                                          return -7;
                                        LOWORD(v11) = 0;
                                        v18 = 0;
                                        if ( v10 <= 0 )
                                        {
LABEL_39:
                                          result = print_structure((int)a2, a3, a4, (int)"[train]");
                                          if ( !result )
                                          {
                                            v12 = this + 834;
                                            result = a3 >= 0
                                                   ? sub_1019F260(v12, a2, a3 + 1, a4)
                                                   : sub_1019F260(v12, a2, a3, a4);
                                            if ( !result )
                                            {
                                              result = print_structure((int)a2, a3, a4, (int)"[rngAttrs]");
                                              if ( !result )
                                              {
                                                v13 = this + 843;
                                                result = a3 >= 0
                                                       ? sub_1019FE20(v13, a2, a3 + 1, a4)
                                                       : sub_1019FE20(v13, a2, a3, a4);
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[talkStyle]",
                                                             "0x%02x",
                                                             (unsigned __int8)*(this + 911));
                                                  if ( !result )
                                                  {
                                                    result = print_structure((int)a2, a3, a4, (int)"[equipSkills]");
                                                    if ( !result )
                                                    {
                                                      v14 = (__int16 *)(this + 912);
                                                      result = a3 >= 0
                                                             ? sub_101A28A0(v14, a2, a3 + 1, a4)
                                                             : sub_101A28A0(v14, a2, a3, a4);
                                                      if ( !result )
                                                      {
                                                        result = print_field(
                                                                   a2,
                                                                   a3,
                                                                   a4,
                                                                   "[sp]",
                                                                   "%f",
                                                                   *((float *)this + 290));
                                                        if ( !result )
                                                        {
                                                          result = print_structure((int)a2, a3, a4, (int)"[waitSkills]");
                                                          if ( !result )
                                                          {
                                                            v15 = (__int16 *)(this + 1164);
                                                            if ( a3 >= 0 )
                                                              result = sub_101A3300(v15, a2, a3 + 1, a4);
                                                            else
                                                              result = sub_101A3300(v15, a2, a3, a4);
                                                            if ( !result )
                                                            {
                                                              result = print_structure(
                                                                         (int)a2,
                                                                         a3,
                                                                         a4,
                                                                         (int)"[growHigherCat]");
                                                              if ( !result )
                                                              {
                                                                v16 = this + 1260;
                                                                if ( a3 >= 0 )
                                                                  return sub_101A39D0(v16, a2, a3 + 1, a4);
                                                                else
                                                                  return sub_101A39D0(v16, a2, a3, a4);
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                        else
                                        {
                                          while ( 1 )
                                          {
                                            v20 = (__int16)v11;
                                            result = sub_1024A230(a2, a3, a4, "[potentialValue]", (__int16)v11);
                                            if ( result )
                                              break;
                                            result = a3 >= 0
                                                   ? sub_1019EBA0((__int16 *)this + 5 * v20 + 367, a2, a3 + 1, a4)
                                                   : sub_1019EBA0((__int16 *)this + 5 * v20 + 367, a2, a3, a4);
                                            if ( result )
                                              break;
                                            v11 = v18 + 1;
                                            v18 = v11;
                                            if ( (__int16)v11 >= *((__int16 *)this + 366) )
                                              goto LABEL_39;
                                          }
                                        }
                                      }
                                    }
                                    else
                                    {
                                      while ( 1 )
                                      {
                                        v19 = (__int16)v9;
                                        result = sub_1024A230(a2, a3, a4, "[groupExp]", (__int16)v9);
                                        if ( result )
                                          break;
                                        result = a3 >= 0
                                               ? sub_1019E530(this + 8 * v19 + v19 + 102, a2, a3 + 1, a4)
                                               : sub_1019E530(this + 8 * v19 + v19 + 102, a2, a3, a4);
                                        if ( result )
                                          break;
                                        v9 = v17 + 1;
                                        v17 = v9;
                                        if ( (__int16)v9 >= *((__int16 *)this + 50) )
                                          goto LABEL_29;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019E250
// ============================================================
//----- (1019E250) --------------------------------------------------------
int __thiscall sub_1019E250(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
LABEL_15:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A2F70
// ============================================================
//----- (101A2F70) --------------------------------------------------------
int __thiscall sub_101A2F70(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _WORD *v5; // esi
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarShort; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  _WORD *v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _WORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(this + 23) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[46] & 1) == 0 )
          *((_DWORD *)v5 + 23) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v4, v5);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*((_DWORD *)v5 + 23) & 2) == 0 )
            *((_DWORD *)v5 + 23) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_101A1300((int)&v16[4 * v10 + 1] + v10, v4, a3);
              if ( v6 )
                return v6;
            }
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v16;
              *v16 = v10 + 1;
              v5 = v12;
              goto LABEL_23;
            }
            if ( ++v10 >= 10 )
            {
              v5 = v16;
              goto LABEL_23;
            }
          }
        }
        VarShort = TdrBuf::SkipField(v4, v15 & 0xF);
      }
      v6 = VarShort;
      if ( VarShort )
        return v6;
LABEL_23:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A3790
// ============================================================
//----- (101A3790) --------------------------------------------------------
int __thiscall sub_101A3790(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019EF80
// ============================================================
//----- (1019EF80) --------------------------------------------------------
int __thiscall sub_1019EF80(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 3 )
      {
        VarUInt = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    VarUInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)this);
LABEL_15:
    v4 = VarUInt;
    if ( VarUInt )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A2350
// ============================================================
//----- (101A2350) --------------------------------------------------------
int __thiscall sub_101A2350(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 244) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 244) & 1) == 0 )
          *(_DWORD *)(this + 244) |= 1u;
        result = TdrBuf::ReadVarShort(v6, (_WORD *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 244) & 2) == 0 )
          *(_DWORD *)(this + 244) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101A0CE0((int *)(this + 2 + 12 * v8), v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 244) & 4) == 0 )
          *(_DWORD *)(this + 244) |= 4u;
        result = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 122));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 244) & 8) == 0 )
          *(_DWORD *)(this + 244) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101A19C0((int *)(this + 4 * (3 * v10 + 31)), v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 10 )
            goto LABEL_38;
        }
        *(_WORD *)(this + 122) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10115A30
// ============================================================
//----- (10115A30) --------------------------------------------------------
int __thiscall sub_10115A30(_DWORD *this, _BYTE *a2)
{
  int v3; // ecx

  if ( *(this + 1) > *(this + 2) )
    _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
  v3 = *(this + 1);
  if ( *(this + 2) == v3 )
    return -2;
  *a2 = *(_BYTE *)(v3 + *this);
  ++*(this + 1);
  return 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019F930
// ============================================================
//----- (1019F930) --------------------------------------------------------
int __thiscall sub_1019F930(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 16) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(this + 16) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_35;
        case 2u:
          if ( (*(this + 16) & 2) == 0 )
            *(this + 16) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 1);
          goto LABEL_35;
        case 3u:
          if ( (*(this + 16) & 4) == 0 )
            *(this + 16) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 2);
          goto LABEL_35;
        case 4u:
          if ( (*(this + 16) & 8) == 0 )
            *(this + 16) |= 8u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 3);
          goto LABEL_35;
        case 5u:
          if ( (*(this + 16) & 0x10) == 0 )
            *(this + 16) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 4);
          goto LABEL_35;
        case 6u:
          if ( (*(this + 16) & 0x20) == 0 )
            *(this + 16) |= 0x20u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 5, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 20) = 0;
LABEL_36:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_37;
          break;
        case 7u:
          if ( (*(this + 16) & 0x40) == 0 )
            *(this + 16) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 13);
          goto LABEL_35;
        case 8u:
          if ( (*(this + 16) & 0x80) == 0 )
            *(this + 16) |= 0x80u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 14);
          goto LABEL_35;
        case 9u:
          if ( (*(this + 16) & 0x100) == 0 )
            *(this + 16) |= 0x100u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 15);
          goto LABEL_35;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_35:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_36;
          return Bytes;
      }
    }
  }
LABEL_37:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019E900
// ============================================================
//----- (1019E900) --------------------------------------------------------
int __thiscall sub_1019E900(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        VarShort = TdrBuf::ReadVarInt(a2, (int *)(this + 2));
      }
      else
      {
        VarShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarShort;
      if ( VarShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A30D0
// ============================================================
//----- (101A30D0) --------------------------------------------------------
int __thiscall sub_101A30D0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _WORD *v5; // esi
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  _WORD *v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _WORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(this + 23) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[46] & 1) == 0 )
          *((_DWORD *)v5 + 23) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, v5);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*((_DWORD *)v5 + 23) & 2) == 0 )
            *((_DWORD *)v5 + 23) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_101A13F0((int)&v16[4 * v10 + 1] + v10, v4, a3);
              if ( v6 )
                return v6;
            }
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v16;
              *v16 = v10 + 1;
              v5 = v12;
              goto LABEL_23;
            }
            if ( ++v10 >= 10 )
            {
              v5 = v16;
              goto LABEL_23;
            }
          }
        }
        Int16 = TdrBuf::SkipField(v4, v15 & 0xF);
      }
      v6 = Int16;
      if ( Int16 )
        return v6;
LABEL_23:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A3830
// ============================================================
//----- (101A3830) --------------------------------------------------------
int __thiscall sub_101A3830(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019E340
// ============================================================
//----- (1019E340) --------------------------------------------------------
int __thiscall sub_1019E340(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_15:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019E9A0
// ============================================================
//----- (1019E9A0) --------------------------------------------------------
int __thiscall sub_1019E9A0(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 6) & 1) == 0 )
        *(_DWORD *)(this + 6) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v7 = a2[1];
      if ( (unsigned int)(a2[2] - v7) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v7 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 6) & 2) == 0 )
        *(_DWORD *)(this + 6) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 2);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019F070
// ============================================================
//----- (1019F070) --------------------------------------------------------
int __thiscall sub_1019F070(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_15:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019FB40
// ============================================================
//----- (1019FB40) --------------------------------------------------------
int __thiscall sub_1019FB40(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 64) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 64) & 1) == 0 )
            *(_DWORD *)(this + 64) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_35;
        case 2u:
          if ( (*(_DWORD *)(this + 64) & 2) == 0 )
            *(_DWORD *)(this + 64) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          goto LABEL_35;
        case 3u:
          if ( (*(_DWORD *)(this + 64) & 4) == 0 )
            *(_DWORD *)(this + 64) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
          goto LABEL_35;
        case 4u:
          if ( (*(_DWORD *)(this + 64) & 8) == 0 )
            *(_DWORD *)(this + 64) |= 8u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 12));
          goto LABEL_35;
        case 5u:
          if ( (*(_DWORD *)(this + 64) & 0x10) == 0 )
            *(_DWORD *)(this + 64) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 16));
          goto LABEL_35;
        case 6u:
          if ( (*(_DWORD *)(this + 64) & 0x20) == 0 )
            *(_DWORD *)(this + 64) |= 0x20u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 20), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 20) = 0;
LABEL_36:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_37;
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 64) & 0x40) == 0 )
            *(_DWORD *)(this + 64) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 52));
          goto LABEL_35;
        case 8u:
          if ( (*(_DWORD *)(this + 64) & 0x80) == 0 )
            *(_DWORD *)(this + 64) |= 0x80u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 56));
          goto LABEL_35;
        case 9u:
          if ( (*(_DWORD *)(this + 64) & 0x100) == 0 )
            *(_DWORD *)(this + 64) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
          goto LABEL_35;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_35:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_36;
          return Bytes;
      }
    }
  }
LABEL_37:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A2590
// ============================================================
//----- (101A2590) --------------------------------------------------------
int __thiscall sub_101A2590(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 244) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 244) & 1) == 0 )
          *(_DWORD *)(this + 244) |= 1u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 244) & 2) == 0 )
          *(_DWORD *)(this + 244) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101A0D80(this + 2 + 12 * v8, v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 244) & 4) == 0 )
          *(_DWORD *)(this + 244) |= 4u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 122));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 244) & 8) == 0 )
          *(_DWORD *)(this + 244) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101A1A60(this + 4 * (3 * v10 + 31), v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 10 )
            goto LABEL_38;
        }
        *(_WORD *)(this + 122) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10C3DA30
// ============================================================
//----- (10C3DA30) --------------------------------------------------------
signed __int32 __cdecl sub_10C3DA30(signed __int32 a1)
{
  signed __int32 result; // eax

  if ( !dword_1202E864 )
    sub_10C495F0();
  result = a1;
  if ( a1 )
    return _InterlockedExchangeAdd(&dword_1202E828, dword_1202E83C(a1));
  return result;
}
// 1202E828: using guessed type int dword_1202E828;
// 1202E83C: using guessed type int (__cdecl *dword_1202E83C)(_DWORD);
// 1202E864: using guessed type int dword_1202E864;



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019F260
// ============================================================
//----- (1019F260) --------------------------------------------------------
int __thiscall sub_1019F260(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[trainTime]", "%u", *(_DWORD *)this);
  if ( !result )
    return print_field(a2, a3, a4, "[trainSlot]", "0x%02x", *(this + 4));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A3300
// ============================================================
//----- (101A3300) --------------------------------------------------------
int __thiscall sub_101A3300(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // si
  char *v8; // ecx

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 10 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          while ( 1 )
          {
            if ( !"[skill]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[skill]", v7, a4);
            if ( result )
              break;
            v8 = (char *)this + 8 * v7 + v7 + 2;
            result = a3 >= 0 ? sub_101A15E0(v8, a2, a3 + 1, a4) : sub_101A15E0(v8, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
          }
        }
      }
      else
      {
        return -7;
      }
    }
    else
    {
      return -6;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019E530
// ============================================================
//----- (1019E530) --------------------------------------------------------
int __thiscall sub_1019E530(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
    return print_field(a2, a3, a4, "[exp]", "0x%02x", *(this + 4));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019FE20
// ============================================================
//----- (1019FE20) --------------------------------------------------------
int __thiscall sub_1019FE20(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[quality]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[character]", "%d", *((_DWORD *)this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[atkTarget]", "%d", *((_DWORD *)this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[atkMode]", "%d", *((_DWORD *)this + 4));
          if ( !result )
          {
            result = sub_1024A410(a2, a3, a4, "[name]", this + 20);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[skin]", "%d", *((_DWORD *)this + 13));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[supportSkill]", "%d", *((_DWORD *)this + 14));
                if ( !result )
                  return print_field(a2, a3, a4, "[randType]", "%d", *((_DWORD *)this + 15));
              }
            }
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A230
// ============================================================
//----- (1024A230) --------------------------------------------------------
int __fastcall sub_1024A230(_DWORD *a1, int a2, char a3, const char *ArgList, int a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
  result = sub_1024A140(a2);
  if ( !result )
    return Printf(a1, "%s[%u]%c", ArgList, a5, a3);
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A39D0
// ============================================================
//----- (101A39D0) --------------------------------------------------------
int __thiscall sub_101A39D0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[dateDay]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[curHigher]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A410
// ============================================================
//----- (1024A410) --------------------------------------------------------
int __fastcall sub_1024A410(_DWORD *a1, int a2, char a3, const char *ArgList, const char *a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xAFu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s: ", ArgList);
    if ( !result )
    {
      result = Printf(a1, "%s", a5);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019EBA0
// ============================================================
//----- (1019EBA0) --------------------------------------------------------
int __thiscall sub_1019EBA0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[value]", "%d", *(_DWORD *)(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A28A0
// ============================================================
//----- (101A28A0) --------------------------------------------------------
int __thiscall sub_101A28A0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v8; // cx
  int v9; // eax
  __int16 v10; // cx
  int v11; // eax
  int v12; // [esp+14h] [ebp+8h]
  int v13; // [esp+14h] [ebp+8h]
  int v14; // [esp+18h] [ebp+Ch]
  int v15; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( *this < 0 )
      return -6;
    if ( v8 > 10 )
      return -7;
    LOWORD(v9) = 0;
    v12 = 0;
    if ( v8 <= 0 )
    {
LABEL_16:
      result = print_field(a2, a3, a4, "[slotCount]", "%d", *(this + 61));
      if ( !result )
      {
        v10 = *(this + 61);
        if ( v10 < 0 )
          return -6;
        if ( v10 > 10 )
          return -7;
        LOWORD(v11) = 0;
        v13 = 0;
        if ( v10 <= 0 )
        {
          return 0;
        }
        else
        {
          while ( 1 )
          {
            v15 = (__int16)v11;
            if ( !"[slotLock]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[slotLock]", v15, a4);
            if ( result )
              break;
            result = a3 >= 0
                   ? sub_101A1C00((_DWORD *)this + 3 * v15 + 31, a2, a3 + 1, a4)
                   : sub_101A1C00((_DWORD *)this + 3 * v15 + 31, a2, a3, a4);
            if ( result )
              break;
            v11 = v13 + 1;
            v13 = v11;
            if ( (__int16)v11 >= *(this + 61) )
              return 0;
          }
        }
      }
    }
    else
    {
      while ( 1 )
      {
        v14 = (__int16)v9;
        if ( !"[skill]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[skill]", v14, a4);
        if ( result )
          break;
        result = a3 >= 0
               ? sub_101A0F20(this + 6 * v14 + 1, a2, a3 + 1, a4)
               : sub_101A0F20(this + 6 * v14 + 1, a2, a3, a4);
        if ( result )
          break;
        v9 = v12 + 1;
        v12 = v9;
        if ( (__int16)v9 >= *this )
          goto LABEL_16;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A1300
// ============================================================
//----- (101A1300) --------------------------------------------------------
int __thiscall sub_101A1300(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
LABEL_15:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A0CE0
// ============================================================
//----- (101A0CE0) --------------------------------------------------------
int __thiscall sub_101A0CE0(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A19C0
// ============================================================
//----- (101A19C0) --------------------------------------------------------
int __thiscall sub_101A19C0(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A13F0
// ============================================================
//----- (101A13F0) --------------------------------------------------------
int __thiscall sub_101A13F0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 5) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 5) & 1) == 0 )
      *(_DWORD *)(this + 5) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_15:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A0D80
// ============================================================
//----- (101A0D80) --------------------------------------------------------
int __thiscall sub_101A0D80(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A1A60
// ============================================================
//----- (101A1A60) --------------------------------------------------------
int __thiscall sub_101A1A60(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10C495F0
// ============================================================
//----- (10C495F0) --------------------------------------------------------
HMODULE sub_10C495F0()
{
  int v0; // ebx
  HMODULE ModuleHandleA; // esi
  FARPROC ProcAddress; // eax
  HMODULE result; // eax
  int (*v4)(void); // eax

  dword_1202E864 = 1;
  v0 = 0;
  dword_1202E824 = 0;
  dword_1202E828 = 0;
  dword_1202E82C = 0;
  dword_1202E830 = 0;
  ModuleHandleA = GetModuleHandleA(0);
  if ( !ModuleHandleA )
    goto LABEL_12;
  while ( 1 )
  {
    dword_1202E834 = (int)GetProcAddress(ModuleHandleA, "CryMalloc");
    dword_1202E838 = (int)GetProcAddress(ModuleHandleA, "CryRealloc");
    dword_1202E83C = (int (__cdecl *)(_DWORD))GetProcAddress(ModuleHandleA, "CryFree");
    dword_1202E840 = (int)GetProcAddress(ModuleHandleA, "CryGetMemSize");
    dword_1202E844 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtMalloc");
    dword_1202E850 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtSize");
    dword_1202E848 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtFree");
    dword_1202E854 = (int)GetProcAddress(ModuleHandleA, "CryGetIMemoryManagerInterface");
    dword_1202E860 = (int)GetProcAddress(ModuleHandleA, "CryCleanup");
    ProcAddress = GetProcAddress(ModuleHandleA, "EnableMemCheck");
    dword_1202E858 = (int)ProcAddress;
    if ( dword_1202E834 )
    {
      if ( dword_1202E838
        && dword_1202E83C
        && dword_1202E840
        && dword_1202E844
        && dword_1202E848
        && dword_1202E850
        && dword_1202E854 )
      {
        break;
      }
    }
    if ( v0 == 1 )
      break;
    ModuleHandleA = LoadLibraryA("CrySystem.dll");
    ++v0;
    if ( !ModuleHandleA )
      goto LABEL_12;
  }
  if ( !dword_1202E834
    || !dword_1202E838
    || !dword_1202E83C
    || !dword_1202E840
    || !dword_1202E844
    || !dword_1202E848
    || !dword_1202E850
    || !dword_1202E854
    || !ProcAddress )
  {
LABEL_12:
    MessageBoxA(0, "Could not access CrySystem.dll (check working directory)", "Memory Manager", 0);
    exit(1);
  }
  if ( ((unsigned __int8 (__cdecl *)(_DWORD))ProcAddress)(0) )
  {
    dword_1202E834 = (int)GetProcAddress(ModuleHandleA, "CryMalloc_MemCheck");
    dword_1202E838 = (int)GetProcAddress(ModuleHandleA, "CryRealloc_MemCheck");
    dword_1202E83C = (int (__cdecl *)(_DWORD))GetProcAddress(ModuleHandleA, "CryFree_MemCheck");
    dword_1202E844 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtMalloc_MemCheck");
    dword_1202E84C = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtRealloc_MemCheck");
    dword_1202E848 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtFree_MemCheck");
    dword_1202E840 = (int)GetProcAddress(ModuleHandleA, "CryGetMemSize_MemCheck");
    dword_1202E850 = (int)GetProcAddress(ModuleHandleA, "CrySystemCrtSize_MemCheck");
  }
  result = LoadLibraryA("MemoryProfiler.dll");
  dword_1202E85C = result;
  if ( result )
  {
    dword_1202E834 = (int)GetProcAddress(result, "UnrealMalloc");
    dword_1202E838 = (int)GetProcAddress(dword_1202E85C, "UnrealRealloc");
    dword_1202E83C = (int (__cdecl *)(_DWORD))GetProcAddress(dword_1202E85C, "UnrealFree");
    dword_1202E844 = (int)GetProcAddress(dword_1202E85C, "UnrealCrtMalloc");
    dword_1202E84C = (int)GetProcAddress(dword_1202E85C, "UnrealCrtRealloc");
    dword_1202E848 = (int)GetProcAddress(dword_1202E85C, "UnrealCrtFree");
    dword_1202E850 = (int)GetProcAddress(dword_1202E85C, "UnrealSystemCrtSize");
    dword_1202E840 = (int)GetProcAddress(dword_1202E85C, "UnrealGetMemSize");
    v4 = GetProcAddress(dword_1202E85C, "Init");
    return (HMODULE)v4();
  }
  return result;
}
// 10C4974A: conditional instruction was optimized away because esi.4!=0
// 1202E824: using guessed type int dword_1202E824;
// 1202E828: using guessed type int dword_1202E828;
// 1202E82C: using guessed type int dword_1202E82C;
// 1202E830: using guessed type int dword_1202E830;
// 1202E834: using guessed type int dword_1202E834;
// 1202E838: using guessed type int dword_1202E838;
// 1202E83C: using guessed type int (__cdecl *dword_1202E83C)(_DWORD);
// 1202E840: using guessed type int dword_1202E840;
// 1202E844: using guessed type int dword_1202E844;
// 1202E848: using guessed type int dword_1202E848;
// 1202E84C: using guessed type int dword_1202E84C;
// 1202E850: using guessed type int dword_1202E850;
// 1202E854: using guessed type int dword_1202E854;
// 1202E858: using guessed type int dword_1202E858;
// 1202E860: using guessed type int dword_1202E860;
// 1202E864: using guessed type int dword_1202E864;



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A15E0
// ============================================================
//----- (101A15E0) --------------------------------------------------------
int __thiscall sub_101A15E0(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
    return print_field(a2, a3, a4, "[newFlag]", "0x%02x", *(this + 4));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A140
// ============================================================
//----- (1024A290) --------------------------------------------------------
int print_field(_DWORD *a1, int a2, char a3, const char *a4, char *Format, ...)
{
  int result; // eax
  int v6; // eax
  int v7; // ecx
  va_list va; // [esp+1Ch] [ebp+1Ch] BYREF

  va_start(va, Format);
  if ( !a4 )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x5Bu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s: ", a4);
    if ( !result )
    {
      v6 = _vsnprintf((char *const)(a1[1] + *a1), a1[2] - a1[1], Format, va);
      if ( v6 < 0 )
        return -1;
      v7 = a1[1];
      if ( v6 >= (unsigned int)(a1[2] - v7) )
      {
        return -1;
      }
      else
      {
        a1[1] = v7 + v6;
        return TdrBuf::WriteChar(a1, a3);
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A1C00
// ============================================================
//----- (101A1C00) --------------------------------------------------------
int __thiscall sub_101A1C00(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[type]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[lockInfo]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101A0F20
// ============================================================
//----- (101A0F20) --------------------------------------------------------
int __thiscall sub_101A0F20(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[slot]", "%d", *(this + 1));
  return result;
}



