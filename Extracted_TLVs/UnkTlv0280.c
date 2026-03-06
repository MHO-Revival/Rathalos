// ============================================================
// Name: TLV::UnkTlv0280::Read
// Address Name: SUB_10237520
// ============================================================
//----- (10237520) --------------------------------------------------------
int __thiscall sub_10237520(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  int v8; // [esp-Ch] [ebp-1Ch]
  unsigned int v9; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  v9 = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&v9, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&v9, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = a2 - 5;
  if ( v7 == -86 )
    result = sub_102375F0((int)this, &v9, v8);
  else
    result = sub_10237760((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0280::Read_0xAA
// Address Name: SUB_102375F0
// ============================================================
//----- (102375F0) --------------------------------------------------------
int __thiscall sub_102375F0(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int16 v6; // si
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  size_t Size; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  *(_DWORD *)(this + 94502) = 0;
  v9 = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 94502) & 1) == 0 )
          *(_DWORD *)(this + 94502) |= 1u;
        result = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else
      {
        if ( v9 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 94502) & 2) == 0 )
            *(_DWORD *)(this + 94502) |= 2u;
          v8 = 0;
          result = TdrBuf::ReadInt32(a2, &v8);
          if ( !result )
          {
            if ( v8 )
            {
              v6 = 0;
              v11 = a2[1];
              while ( 1 )
              {
                Size = 0;
                result = TdrBuf::ReadInt32(a2, &Size);
                if ( result )
                  break;
                if ( Size )
                {
                  result = sub_10236580(315 * v6 + this + 2, a2, Size);
                  if ( result )
                    break;
                }
                v7 = a2[1];
                if ( v7 > v11 + v8 )
                  return -34;
                if ( v7 == v11 + v8 )
                {
                  *(_WORD *)this = v6 + 1;
                  goto LABEL_23;
                }
                if ( ++v6 >= 0x12Cu )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        result = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      if ( result )
        return result;
LABEL_23:
      v5 = v12;
      if ( a2[1] >= v12 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0280::Read_0x99
// Address Name: SUB_10237760
// ============================================================
//----- (10237760) --------------------------------------------------------
int __thiscall sub_10237760(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int16 v6; // si
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  size_t Size; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  *(_DWORD *)(this + 94502) = 0;
  v9 = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 94502) & 1) == 0 )
          *(_DWORD *)(this + 94502) |= 1u;
        result = TdrBuf::ReadInt16(a2, (_BYTE *)this);
      }
      else
      {
        if ( v9 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 94502) & 2) == 0 )
            *(_DWORD *)(this + 94502) |= 2u;
          v8 = 0;
          result = TdrBuf::ReadInt32(a2, &v8);
          if ( !result )
          {
            if ( v8 )
            {
              v6 = 0;
              v11 = a2[1];
              while ( 1 )
              {
                Size = 0;
                result = TdrBuf::ReadInt32(a2, &Size);
                if ( result )
                  break;
                if ( Size )
                {
                  result = sub_10236960(315 * v6 + this + 2, a2, Size);
                  if ( result )
                    break;
                }
                v7 = a2[1];
                if ( v7 > v11 + v8 )
                  return -34;
                if ( v7 == v11 + v8 )
                {
                  *(_WORD *)this = v6 + 1;
                  goto LABEL_23;
                }
                if ( ++v6 >= 0x12Cu )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        result = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      if ( result )
        return result;
LABEL_23:
      v5 = v12;
      if ( a2[1] >= v12 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0280::DoDebugFormat
// Address Name: SUB_102378F0
// ============================================================
//----- (102378F0) --------------------------------------------------------
int __thiscall sub_102378F0(unsigned __int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_102379A0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0280::DebugFormat
// Address Name: SUB_102379A0
// ============================================================
//----- (102379A0) --------------------------------------------------------
int __thiscall sub_102379A0(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // si

  result = print_field(a2, a3, a4, "[recordCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this <= 0x12Cu )
    {
      v7 = 0;
      if ( v6 )
      {
        while ( 1 )
        {
          if ( !"[records]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[records]", v7, a4);
          if ( result )
            break;
          result = a3 >= 0
                 ? sub_10236E10((unsigned __int8 *)this + 315 * v7 + 2, a2, a3 + 1, a4)
                 : sub_10236E10((unsigned __int8 *)this + 315 * v7 + 2, a2, a3, a4);
          if ( result )
            break;
          if ( ++v7 >= *this )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10236580
// ============================================================
//----- (10236580) --------------------------------------------------------
int __thiscall sub_10236580(int this, _DWORD *a2, size_t Size)
{
  size_t v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  size_t v7; // eax
  int result; // eax
  int VarULong; // eax
  int v10; // eax
  unsigned __int16 v11; // di
  size_t v12; // eax
  __int16 v13; // ax
  size_t v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = Size;
  v4 = a2;
  Bytes = 0;
  v16 = 0;
  *(_DWORD *)(this + 311) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_60;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 311) & 1) == 0 )
          *(_DWORD *)(this + 311) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)this);
        goto LABEL_58;
      case 2u:
        if ( (*(_DWORD *)(this + 311) & 2) == 0 )
          *(_DWORD *)(this + 311) |= 2u;
        VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)(this + 8));
        goto LABEL_58;
      case 3u:
        if ( (*(_DWORD *)(this + 311) & 4) == 0 )
          *(_DWORD *)(this + 311) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 16), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + Size + 16) = 0;
        goto LABEL_59;
      case 4u:
        if ( (*(_DWORD *)(this + 311) & 8) == 0 )
          *(_DWORD *)(this + 311) |= 8u;
        VarULong = TdrBuf::ReadByte(v4, (_BYTE *)(this + 48));
        goto LABEL_58;
      case 5u:
        if ( (*(_DWORD *)(this + 311) & 0x10) == 0 )
          *(_DWORD *)(this + 311) |= 0x10u;
        VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 49));
        goto LABEL_58;
      case 6u:
        if ( (*(_DWORD *)(this + 311) & 0x20) == 0 )
          *(_DWORD *)(this + 311) |= 0x20u;
        VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 53));
        goto LABEL_58;
      case 7u:
        if ( (*(_DWORD *)(this + 311) & 0x40) == 0 )
          *(_DWORD *)(this + 311) |= 0x40u;
        VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 57));
        goto LABEL_58;
      case 8u:
        if ( (*(_DWORD *)(this + 311) & 0x80) == 0 )
          *(_DWORD *)(this + 311) |= 0x80u;
        VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 61));
        goto LABEL_58;
      case 9u:
        if ( (*(_DWORD *)(this + 311) & 0x100) == 0 )
          *(_DWORD *)(this + 311) |= 0x100u;
        VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)(this + 65));
        goto LABEL_58;
      case 0xAu:
        if ( (*(_DWORD *)(this + 311) & 0x200) == 0 )
          *(_DWORD *)(this + 311) |= 0x200u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 73), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + Size + 73) = 0;
          goto LABEL_59;
        }
        return Bytes;
      case 0xBu:
        if ( (*(_DWORD *)(this + 311) & 0x400) == 0 )
          *(_DWORD *)(this + 311) |= 0x400u;
        VarULong = TdrBuf::ReadVarUShort(v4, (_WORD *)(this + 105));
        goto LABEL_58;
      case 0xCu:
        if ( (*(_DWORD *)(this + 311) & 0x800) == 0 )
          *(_DWORD *)(this + 311) |= 0x800u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = v4[1];
        v11 = 0;
        v15 = v10;
        while ( 1 )
        {
          Bytes = TdrBuf::ReadByte(a2, (_BYTE *)(this + v11 + 107));
          if ( Bytes )
            return Bytes;
          v12 = a2[1];
          if ( v12 > Size + v15 )
            return -34;
          if ( v12 == Size + v15 )
            break;
          if ( ++v11 >= 0xC8u )
          {
            v4 = a2;
            goto LABEL_59;
          }
        }
        v13 = v11 + 1;
        v4 = a2;
        *(_WORD *)(this + 105) = v13;
LABEL_59:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_60:
        if ( v4[1] > v7 )
          return -34;
        return Bytes;
      case 0xDu:
        if ( (*(_DWORD *)(this + 311) & 0x1000) == 0 )
          *(_DWORD *)(this + 311) |= 0x1000u;
        VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 307));
        goto LABEL_58;
      default:
        VarULong = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_58:
        Bytes = VarULong;
        if ( !VarULong )
          goto LABEL_59;
        return Bytes;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10236960
// ============================================================
//----- (10236960) --------------------------------------------------------
int __thiscall sub_10236960(int this, _DWORD *a2, size_t Size)
{
  size_t v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  size_t v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // eax
  unsigned __int16 v11; // di
  size_t v12; // eax
  __int16 v13; // ax
  size_t v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = Size;
  v4 = a2;
  Bytes = 0;
  v16 = 0;
  *(_DWORD *)(this + 311) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_60;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 311) & 1) == 0 )
          *(_DWORD *)(this + 311) |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
        goto LABEL_58;
      case 2u:
        if ( (*(_DWORD *)(this + 311) & 2) == 0 )
          *(_DWORD *)(this + 311) |= 2u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 8));
        goto LABEL_58;
      case 3u:
        if ( (*(_DWORD *)(this + 311) & 4) == 0 )
          *(_DWORD *)(this + 311) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 16), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + Size + 16) = 0;
        goto LABEL_59;
      case 4u:
        if ( (*(_DWORD *)(this + 311) & 8) == 0 )
          *(_DWORD *)(this + 311) |= 8u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 48));
        goto LABEL_58;
      case 5u:
        if ( (*(_DWORD *)(this + 311) & 0x10) == 0 )
          *(_DWORD *)(this + 311) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 49));
        goto LABEL_58;
      case 6u:
        if ( (*(_DWORD *)(this + 311) & 0x20) == 0 )
          *(_DWORD *)(this + 311) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 53));
        goto LABEL_58;
      case 7u:
        if ( (*(_DWORD *)(this + 311) & 0x40) == 0 )
          *(_DWORD *)(this + 311) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 57));
        goto LABEL_58;
      case 8u:
        if ( (*(_DWORD *)(this + 311) & 0x80) == 0 )
          *(_DWORD *)(this + 311) |= 0x80u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 61));
        goto LABEL_58;
      case 9u:
        if ( (*(_DWORD *)(this + 311) & 0x100) == 0 )
          *(_DWORD *)(this + 311) |= 0x100u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 65));
        goto LABEL_58;
      case 0xAu:
        if ( (*(_DWORD *)(this + 311) & 0x200) == 0 )
          *(_DWORD *)(this + 311) |= 0x200u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 73), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + Size + 73) = 0;
          goto LABEL_59;
        }
        return Bytes;
      case 0xBu:
        if ( (*(_DWORD *)(this + 311) & 0x400) == 0 )
          *(_DWORD *)(this + 311) |= 0x400u;
        Int64 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 105));
        goto LABEL_58;
      case 0xCu:
        if ( (*(_DWORD *)(this + 311) & 0x800) == 0 )
          *(_DWORD *)(this + 311) |= 0x800u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = v4[1];
        v11 = 0;
        v15 = v10;
        while ( 1 )
        {
          Bytes = TdrBuf::ReadByte(a2, (_BYTE *)(this + v11 + 107));
          if ( Bytes )
            return Bytes;
          v12 = a2[1];
          if ( v12 > Size + v15 )
            return -34;
          if ( v12 == Size + v15 )
            break;
          if ( ++v11 >= 0xC8u )
          {
            v4 = a2;
            goto LABEL_59;
          }
        }
        v13 = v11 + 1;
        v4 = a2;
        *(_WORD *)(this + 105) = v13;
LABEL_59:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_60:
        if ( v4[1] > v7 )
          return -34;
        return Bytes;
      case 0xDu:
        if ( (*(_DWORD *)(this + 311) & 0x1000) == 0 )
          *(_DWORD *)(this + 311) |= 0x1000u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 307));
        goto LABEL_58;
      default:
        Int64 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_58:
        Bytes = Int64;
        if ( !Int64 )
          goto LABEL_59;
        return Bytes;
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
// Address Name: SUB_10236E10
// ============================================================
//----- (10236E10) --------------------------------------------------------
int __thiscall sub_10236E10(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int16 v6; // di

  result = print_field(a2, a3, a4, "[recordId]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dBId]", "%I64u", *((_QWORD *)this + 1));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[roleName]", (const char *)this + 16);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[saleTime]", "0x%02x", *(this + 48));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[expireTime]", "%u", *(_DWORD *)(this + 49));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[initPrice]", "%u", *(_DWORD *)(this + 53));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[maxPrice]", "%u", *(_DWORD *)(this + 57));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[curPrice]", "%u", *(_DWORD *)(this + 61));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[bidDBId]", "%I64u", *(_QWORD *)(this + 65));
                  if ( !result )
                  {
                    result = sub_1024A410(a2, a3, a4, "[bidRoleName]", (const char *)this + 73);
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[itemDataSize]", "%d", *(unsigned __int16 *)(this + 105));
                      if ( !result )
                      {
                        if ( *(_WORD *)(this + 105) <= 0xC8u )
                        {
                          result = sub_1024A3B0(a2, a3, 200, "[itemData]", *(unsigned __int16 *)(this + 105));
                          if ( !result )
                          {
                            v6 = 0;
                            if ( *(_WORD *)(this + 105) )
                            {
                              while ( 1 )
                              {
                                result = Printf(a2, " %d", *(this + v6 + 107));
                                if ( result )
                                  break;
                                if ( ++v6 >= *(_WORD *)(this + 105) )
                                  goto LABEL_18;
                              }
                            }
                            else
                            {
LABEL_18:
                              result = TdrBuf::WriteChar(a2, a4);
                              if ( !result )
                                return print_field(a2, a3, a4, "[bidLevel]", "%u", *(_DWORD *)(this + 307));
                            }
                          }
                        }
                        else
                        {
                          return -7;
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
// Address Name: SUB_1024A3B0
// ============================================================
//----- (1024A3B0) --------------------------------------------------------
int __fastcall sub_1024A3B0(_DWORD *a1, int a2, int a3, const char *ArgList, __int64 a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a2);
  if ( !result )
    return Printf(a1, "%s[0 : %I64i]:", ArgList, a5 - 1);
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



