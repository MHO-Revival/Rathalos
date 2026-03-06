// ============================================================
// Name: TLV::UnkTlv0282::Read
// Address Name: SUB_10239800
// ============================================================
//----- (10239800) --------------------------------------------------------
int __thiscall sub_10239800(void *this, size_t a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  size_t v6; // esi
  char v7; // bl
  int v8; // [esp-Ch] [ebp-1Ch]
  size_t Size; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  Size = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&Size, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&Size, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = a2 - 5;
  if ( v7 == -86 )
    result = sub_102398D0((int)this, &Size, v8);
  else
    result = sub_10239C30((int)this, &Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0282::Read_0xAA
// Address Name: SUB_102398D0
// ============================================================
//----- (102398D0) --------------------------------------------------------
int __thiscall sub_102398D0(int this, _DWORD *Size, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int16 v6; // di
  unsigned int v7; // edx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  int v12; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  int v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  result = 0;
  *(_DWORD *)(this + 108006) = 0;
  v13 = 0;
  v5 = Size[1] + a3;
  v16 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_55;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v13);
    if ( result )
      return result;
    switch ( v13 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 108006) & 1) == 0 )
          *(_DWORD *)(this + 108006) |= 1u;
        result = TdrBuf::ReadVarUShort(Size, (_WORD *)this);
        goto LABEL_53;
      case 2u:
        if ( (*(_DWORD *)(this + 108006) & 2) == 0 )
          *(_DWORD *)(this + 108006) |= 2u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v6 = 0;
        v15 = Size[1];
        while ( 2 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238670((_DWORD *)(this + 2 + 120 * v6), (size_t)Size, v14);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v15 + v12 )
            return -34;
          if ( v7 != v15 + v12 )
          {
            if ( ++v6 >= 0x64u )
              goto LABEL_54;
            continue;
          }
          break;
        }
        *(_WORD *)this = v6 + 1;
        goto LABEL_54;
      case 3u:
        if ( (*(_DWORD *)(this + 108006) & 4) == 0 )
          *(_DWORD *)(this + 108006) |= 4u;
        result = TdrBuf::ReadVarUShort(Size, (_WORD *)(this + 12002));
        goto LABEL_53;
      case 4u:
        if ( (*(_DWORD *)(this + 108006) & 8) == 0 )
          *(_DWORD *)(this + 108006) |= 8u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v8 = 0;
        v15 = Size[1];
        while ( 2 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238670((_DWORD *)(this + 12004 + 120 * v8), (size_t)Size, v14);
            if ( result )
              return result;
          }
          v9 = Size[1];
          if ( v9 > v15 + v12 )
            return -34;
          if ( v9 != v15 + v12 )
          {
            if ( ++v8 >= 0x190u )
              goto LABEL_54;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 12002) = v8 + 1;
        goto LABEL_54;
      case 5u:
        if ( (*(_DWORD *)(this + 108006) & 0x10) == 0 )
          *(_DWORD *)(this + 108006) |= 0x10u;
        result = TdrBuf::ReadVarUShort(Size, (_WORD *)(this + 60004));
        goto LABEL_53;
      case 6u:
        if ( (*(_DWORD *)(this + 108006) & 0x20) == 0 )
          *(_DWORD *)(this + 108006) |= 0x20u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v10 = 0;
        v15 = Size[1];
        while ( 1 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238670((_DWORD *)(this + 60006 + 120 * v10), (size_t)Size, v14);
            if ( result )
              return result;
          }
          v11 = Size[1];
          if ( v11 > v15 + v12 )
            return -34;
          if ( v11 == v15 + v12 )
            break;
          if ( ++v10 >= 0x190u )
            goto LABEL_54;
        }
        *(_WORD *)(this + 60004) = v10 + 1;
LABEL_54:
        v5 = v16;
        if ( Size[1] < v16 )
          continue;
LABEL_55:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v13 & 0xF);
LABEL_53:
        if ( !result )
          goto LABEL_54;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0282::Read_0x99
// Address Name: SUB_10239C30
// ============================================================
//----- (10239C30) --------------------------------------------------------
int __thiscall sub_10239C30(int this, _DWORD *Size, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int16 v6; // di
  unsigned int v7; // edx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  int v12; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v13; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch] BYREF
  int v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  result = 0;
  *(_DWORD *)(this + 108006) = 0;
  v13 = 0;
  v5 = Size[1] + a3;
  v16 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_55;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v13);
    if ( result )
      return result;
    switch ( v13 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 108006) & 1) == 0 )
          *(_DWORD *)(this + 108006) |= 1u;
        result = TdrBuf::ReadInt16(Size, (_BYTE *)this);
        goto LABEL_53;
      case 2u:
        if ( (*(_DWORD *)(this + 108006) & 2) == 0 )
          *(_DWORD *)(this + 108006) |= 2u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v6 = 0;
        v15 = Size[1];
        while ( 2 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238940(this + 2 + 120 * v6, (size_t)Size, v14);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v15 + v12 )
            return -34;
          if ( v7 != v15 + v12 )
          {
            if ( ++v6 >= 0x64u )
              goto LABEL_54;
            continue;
          }
          break;
        }
        *(_WORD *)this = v6 + 1;
        goto LABEL_54;
      case 3u:
        if ( (*(_DWORD *)(this + 108006) & 4) == 0 )
          *(_DWORD *)(this + 108006) |= 4u;
        result = TdrBuf::ReadInt16(Size, (_BYTE *)(this + 12002));
        goto LABEL_53;
      case 4u:
        if ( (*(_DWORD *)(this + 108006) & 8) == 0 )
          *(_DWORD *)(this + 108006) |= 8u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v8 = 0;
        v15 = Size[1];
        while ( 2 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238940(this + 12004 + 120 * v8, (size_t)Size, v14);
            if ( result )
              return result;
          }
          v9 = Size[1];
          if ( v9 > v15 + v12 )
            return -34;
          if ( v9 != v15 + v12 )
          {
            if ( ++v8 >= 0x190u )
              goto LABEL_54;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 12002) = v8 + 1;
        goto LABEL_54;
      case 5u:
        if ( (*(_DWORD *)(this + 108006) & 0x10) == 0 )
          *(_DWORD *)(this + 108006) |= 0x10u;
        result = TdrBuf::ReadInt16(Size, (_BYTE *)(this + 60004));
        goto LABEL_53;
      case 6u:
        if ( (*(_DWORD *)(this + 108006) & 0x20) == 0 )
          *(_DWORD *)(this + 108006) |= 0x20u;
        v12 = 0;
        result = TdrBuf::ReadInt32(Size, &v12);
        if ( result )
          return result;
        if ( !v12 )
          return -37;
        v10 = 0;
        v15 = Size[1];
        while ( 1 )
        {
          v14 = 0;
          result = TdrBuf::ReadInt32(Size, &v14);
          if ( result )
            return result;
          if ( v14 )
          {
            result = sub_10238940(this + 60006 + 120 * v10, (size_t)Size, v14);
            if ( result )
              return result;
          }
          v11 = Size[1];
          if ( v11 > v15 + v12 )
            return -34;
          if ( v11 == v15 + v12 )
            break;
          if ( ++v10 >= 0x190u )
            goto LABEL_54;
        }
        *(_WORD *)(this + 60004) = v10 + 1;
LABEL_54:
        v5 = v16;
        if ( Size[1] < v16 )
          continue;
LABEL_55:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v13 & 0xF);
LABEL_53:
        if ( !result )
          goto LABEL_54;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0282::DoDebugFormat
// Address Name: SUB_10239FB0
// ============================================================
//----- (10239FB0) --------------------------------------------------------
int __thiscall sub_10239FB0(unsigned __int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1023A060(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0282::DebugFormat
// Address Name: SUB_1023A060
// ============================================================
//----- (1023A060) --------------------------------------------------------
int __thiscall sub_1023A060(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // eax
  unsigned __int16 v9; // cx
  int v10; // eax
  unsigned __int16 v11; // cx
  int v12; // eax
  int v13; // [esp+14h] [ebp+8h]
  int v14; // [esp+14h] [ebp+8h]
  int v15; // [esp+14h] [ebp+8h]
  int v16; // [esp+18h] [ebp+Ch]
  int v17; // [esp+18h] [ebp+Ch]
  int v18; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[saleCount]", "%d", *this);
  if ( !result )
  {
    if ( *this > 0x64u )
      return -7;
    LOWORD(v8) = 0;
    v13 = 0;
    if ( *this )
    {
      while ( 1 )
      {
        v16 = (unsigned __int16)v8;
        if ( !"[sales]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[sales]", v16, a4);
        if ( result )
          break;
        result = a3 >= 0
               ? sub_10238CE0((const char *)this + 120 * v16 + 2, a2, a3 + 1, a4)
               : sub_10238CE0((const char *)this + 120 * v16 + 2, a2, a3, a4);
        if ( result )
          break;
        v8 = v13 + 1;
        v13 = v8;
        if ( (unsigned __int16)v8 >= *this )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      result = print_field(a2, a3, a4, "[recordSaleCount]", "%d", *(this + 6001));
      if ( !result )
      {
        v9 = *(this + 6001);
        if ( v9 > 0x190u )
          return -7;
        LOWORD(v10) = 0;
        v14 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v17 = (unsigned __int16)v10;
            if ( !"[recordSale]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[recordSale]", v17, a4);
            if ( result )
              break;
            result = a3 >= 0
                   ? sub_10238CE0((const char *)this + 120 * v17 + 12004, a2, a3 + 1, a4)
                   : sub_10238CE0((const char *)this + 120 * v17 + 12004, a2, a3, a4);
            if ( result )
              break;
            v10 = v14 + 1;
            v14 = v10;
            if ( (unsigned __int16)v10 >= *(this + 6001) )
              goto LABEL_26;
          }
        }
        else
        {
LABEL_26:
          result = print_field(a2, a3, a4, "[recordBuyCount]", "%d", *(this + 30002));
          if ( !result )
          {
            v11 = *(this + 30002);
            if ( v11 > 0x190u )
              return -7;
            LOWORD(v12) = 0;
            v15 = 0;
            if ( v11 )
            {
              while ( 1 )
              {
                v18 = (unsigned __int16)v12;
                if ( !"[recordBuy]" )
                  _wassert(
                    L"NULL != variable",
                    L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                    0x43u);
                result = sub_1024A140(a3);
                if ( result )
                  break;
                result = Printf(a2, "%s[%u]%c", "[recordBuy]", v18, a4);
                if ( result )
                  break;
                result = a3 >= 0
                       ? sub_10238CE0((const char *)this + 120 * v18 + 60006, a2, a3 + 1, a4)
                       : sub_10238CE0((const char *)this + 120 * v18 + 60006, a2, a3, a4);
                if ( result )
                  break;
                v12 = v15 + 1;
                v15 = v12;
                if ( (unsigned __int16)v12 >= *(this + 30002) )
                  return 0;
              }
            }
            else
            {
              return 0;
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
// Address Name: SUB_10238670
// ============================================================
//----- (10238670) --------------------------------------------------------
int __thiscall sub_10238670(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 29) = 0;
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
          if ( (*(_BYTE *)(this + 29) & 1) == 0 )
            *(this + 29) |= 1u;
          VarULong = TdrBuf::ReadVarULong(v4, this);
          goto LABEL_47;
        case 2u:
          if ( (*(this + 29) & 2) == 0 )
            *(this + 29) |= 2u;
          VarULong = TdrBuf::ReadVarULong(v4, this + 2);
          goto LABEL_47;
        case 3u:
          if ( (*(this + 29) & 4) == 0 )
            *(this + 29) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 4, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 16) = 0;
          goto LABEL_48;
        case 4u:
          if ( (*(this + 29) & 8) == 0 )
            *(this + 29) |= 8u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 12);
          goto LABEL_47;
        case 5u:
          if ( (*(this + 29) & 0x10) == 0 )
            *(this + 29) |= 0x10u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 13);
          goto LABEL_47;
        case 6u:
          if ( (*(this + 29) & 0x20) == 0 )
            *(this + 29) |= 0x20u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 14);
          goto LABEL_47;
        case 7u:
          if ( (*(this + 29) & 0x40) == 0 )
            *(this + 29) |= 0x40u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 15);
          goto LABEL_47;
        case 8u:
          if ( (*(this + 29) & 0x80) == 0 )
            *(this + 29) |= 0x80u;
          VarULong = TdrBuf::ReadVarULong(v4, this + 16);
          goto LABEL_47;
        case 9u:
          if ( (*(this + 29) & 0x100) == 0 )
            *(this + 29) |= 0x100u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 18, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 72) = 0;
LABEL_48:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_49;
          break;
        case 0xAu:
          if ( (*(this + 29) & 0x200) == 0 )
            *(this + 29) |= 0x200u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 26);
          goto LABEL_47;
        case 0xBu:
          if ( (*(this + 29) & 0x400) == 0 )
            *(this + 29) |= 0x400u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 27);
          goto LABEL_47;
        case 0xCu:
          if ( (*(this + 29) & 0x800) == 0 )
            *(this + 29) |= 0x800u;
          VarULong = TdrBuf::ReadVarUInt(v4, this + 28);
          goto LABEL_47;
        default:
          VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_47:
          Bytes = VarULong;
          if ( !VarULong )
            goto LABEL_48;
          return Bytes;
      }
    }
  }
LABEL_49:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10238940
// ============================================================
//----- (10238940) --------------------------------------------------------
int __thiscall sub_10238940(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 116) = 0;
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
          if ( (*(_BYTE *)(this + 116) & 1) == 0 )
            *(_DWORD *)(this + 116) |= 1u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
          goto LABEL_47;
        case 2u:
          if ( (*(_DWORD *)(this + 116) & 2) == 0 )
            *(_DWORD *)(this + 116) |= 2u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 8));
          goto LABEL_47;
        case 3u:
          if ( (*(_DWORD *)(this + 116) & 4) == 0 )
            *(_DWORD *)(this + 116) |= 4u;
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
          goto LABEL_48;
        case 4u:
          if ( (*(_DWORD *)(this + 116) & 8) == 0 )
            *(_DWORD *)(this + 116) |= 8u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 48));
          goto LABEL_47;
        case 5u:
          if ( (*(_DWORD *)(this + 116) & 0x10) == 0 )
            *(_DWORD *)(this + 116) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 52));
          goto LABEL_47;
        case 6u:
          if ( (*(_DWORD *)(this + 116) & 0x20) == 0 )
            *(_DWORD *)(this + 116) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 56));
          goto LABEL_47;
        case 7u:
          if ( (*(_DWORD *)(this + 116) & 0x40) == 0 )
            *(_DWORD *)(this + 116) |= 0x40u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
          goto LABEL_47;
        case 8u:
          if ( (*(_DWORD *)(this + 116) & 0x80) == 0 )
            *(_DWORD *)(this + 116) |= 0x80u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 64));
          goto LABEL_47;
        case 9u:
          if ( (*(_DWORD *)(this + 116) & 0x100) == 0 )
            *(_DWORD *)(this + 116) |= 0x100u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 72), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 72) = 0;
LABEL_48:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_49;
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 116) & 0x200) == 0 )
            *(_DWORD *)(this + 116) |= 0x200u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 104));
          goto LABEL_47;
        case 0xBu:
          if ( (*(_DWORD *)(this + 116) & 0x400) == 0 )
            *(_DWORD *)(this + 116) |= 0x400u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 108));
          goto LABEL_47;
        case 0xCu:
          if ( (*(_DWORD *)(this + 116) & 0x800) == 0 )
            *(_DWORD *)(this + 116) |= 0x800u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 112));
          goto LABEL_47;
        default:
          Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_47:
          Bytes = Int64;
          if ( !Int64 )
            goto LABEL_48;
          return Bytes;
      }
    }
  }
LABEL_49:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
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
// Address Name: SUB_10238CE0
// ============================================================
//----- (10238CE0) --------------------------------------------------------
int __thiscall sub_10238CE0(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[recordId]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dBId]", "%I64u", *((_QWORD *)this + 1));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[roleName]", this + 16);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[expireTime]", "%u", *((_DWORD *)this + 12));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[money]", "%u", *((_DWORD *)this + 13));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[credit]", "%u", *((_DWORD *)this + 14));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[recordTime]", "%u", *((_DWORD *)this + 15));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[bidDBId]", "%I64u", *((_QWORD *)this + 8));
                if ( !result )
                {
                  result = sub_1024A410(a2, a3, a4, "[bidRoleName]", this + 72);
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[bidLevel]", "%u", *((_DWORD *)this + 26));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[uin]", "%u", *((_DWORD *)this + 27));
                      if ( !result )
                        return print_field(a2, a3, a4, "[biduin]", "%u", *((_DWORD *)this + 28));
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



