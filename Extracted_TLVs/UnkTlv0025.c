// ============================================================
// Name: TLV::UnkTlv0025::Read_0xAA
// Address Name: SUB_101227B0
// ============================================================
//----- (101227B0) --------------------------------------------------------
int __thiscall sub_101227B0(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 39745) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[39745] & 1) == 0 )
          v4[39745] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[39745] & 2) == 0 )
            v4[39745] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10121050(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 = (int *)((char *)a3 + 621);
            if ( ++v10 >= 256 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0025::Read_0x99
// Address Name: SUB_10122920
// ============================================================
//----- (10122920) --------------------------------------------------------
int __thiscall sub_10122920(_DWORD *this, _DWORD *Size, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 39745) = 0;
  v16 = 0;
  v7 = &v3[v6[1]];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[39745] & 1) == 0 )
          v4[39745] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[39745] & 2) == 0 )
            v4[39745] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (char *)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10121660(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 621;
            if ( ++v10 >= 256 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0025::DoDebugFormat
// Address Name: SUB_10122AB0
// ============================================================
//----- (10122AB0) --------------------------------------------------------
int __thiscall sub_10122AB0(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10122B60(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0025::DebugFormat
// Address Name: SUB_10122B60
// ============================================================
//----- (10122B60) --------------------------------------------------------
int __thiscall sub_10122B60(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  int i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 256 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (int)(this + 1); ; i += 621 )
          {
            if ( !"[guilders]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guilders]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10121D40(i, a2, a3 + 1, a4) : sub_10121D40(i, a2, a3, a4);
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
// Address Name: SUB_10121050
// ============================================================
//----- (10121050) --------------------------------------------------------
int __thiscall sub_10121050(int *this, size_t Size, unsigned int a3)
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
  *(int *)((char *)this + 617) = 0;
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
          if ( (*((_BYTE *)this + 617) & 1) == 0 )
            *(int *)((char *)this + 617) |= 1u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          VarInt = sub_10118210(this, (size_t)v4, Size);
          goto LABEL_90;
        case 2u:
          if ( (*(int *)((char *)this + 617) & 2) == 0 )
            *(int *)((char *)this + 617) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 14, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 56) = 0;
          goto LABEL_91;
        case 3u:
          if ( (*(int *)((char *)this + 617) & 4) == 0 )
            *(int *)((char *)this + 617) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 78);
          goto LABEL_90;
        case 4u:
          if ( (*(int *)((char *)this + 617) & 8) == 0 )
            *(int *)((char *)this + 617) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 79, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 316) = 0;
LABEL_91:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_92;
          break;
        case 5u:
          if ( (*(int *)((char *)this + 617) & 0x10) == 0 )
            *(int *)((char *)this + 617) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 111);
          goto LABEL_90;
        case 6u:
          if ( (*(int *)((char *)this + 617) & 0x20) == 0 )
            *(int *)((char *)this + 617) |= 0x20u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 112);
          goto LABEL_90;
        case 7u:
          if ( (*(int *)((char *)this + 617) & 0x40) == 0 )
            *(int *)((char *)this + 617) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 114);
          goto LABEL_90;
        case 8u:
          if ( (*(int *)((char *)this + 617) & 0x80) == 0 )
            *(int *)((char *)this + 617) |= 0x80u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 115);
          goto LABEL_90;
        case 9u:
          if ( (*(int *)((char *)this + 617) & 0x100) == 0 )
            *(int *)((char *)this + 617) |= 0x100u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 116);
          goto LABEL_90;
        case 0xAu:
          if ( (*(int *)((char *)this + 617) & 0x200) == 0 )
            *(int *)((char *)this + 617) |= 0x200u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 117);
          goto LABEL_90;
        case 0xBu:
          if ( (*(int *)((char *)this + 617) & 0x400) == 0 )
            *(int *)((char *)this + 617) |= 0x400u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 118);
          goto LABEL_90;
        case 0xCu:
          if ( (*(int *)((char *)this + 617) & 0x800) == 0 )
            *(int *)((char *)this + 617) |= 0x800u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 119);
          goto LABEL_90;
        case 0xDu:
          if ( (*(int *)((char *)this + 617) & 0x1000) == 0 )
            *(int *)((char *)this + 617) |= 0x1000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 120);
          goto LABEL_90;
        case 0xEu:
          if ( (*(int *)((char *)this + 617) & 0x2000) == 0 )
            *(int *)((char *)this + 617) |= 0x2000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 121);
          goto LABEL_90;
        case 0xFu:
          if ( (*(int *)((char *)this + 617) & 0x4000) == 0 )
            *(int *)((char *)this + 617) |= 0x4000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 122);
          goto LABEL_90;
        case 0x10u:
          if ( (*(int *)((char *)this + 617) & 0x8000) == 0 )
            *(int *)((char *)this + 617) |= 0x8000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 123);
          goto LABEL_90;
        case 0x11u:
          if ( (*(int *)((char *)this + 617) & 0x10000) == 0 )
            *(int *)((char *)this + 617) |= 0x10000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 124);
          goto LABEL_90;
        case 0x12u:
          if ( (*(int *)((char *)this + 617) & 0x20000) == 0 )
            *(int *)((char *)this + 617) |= 0x20000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 125);
          goto LABEL_90;
        case 0x13u:
          if ( (*(int *)((char *)this + 617) & 0x40000) == 0 )
            *(int *)((char *)this + 617) |= 0x40000u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 126);
          goto LABEL_90;
        case 0x14u:
          if ( (*(int *)((char *)this + 617) & 0x80000) == 0 )
            *(int *)((char *)this + 617) |= 0x80000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 128);
          goto LABEL_90;
        case 0x15u:
          if ( (*(int *)((char *)this + 617) & 0x100000) == 0 )
            *(int *)((char *)this + 617) |= 0x100000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 129);
          goto LABEL_90;
        case 0x16u:
          if ( (*(int *)((char *)this + 617) & 0x200000) == 0 )
            *(int *)((char *)this + 617) |= 0x200000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 130);
          goto LABEL_90;
        case 0x17u:
          if ( (*(int *)((char *)this + 617) & 0x400000) == 0 )
            *(int *)((char *)this + 617) |= 0x400000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 131);
          goto LABEL_90;
        case 0x18u:
          if ( (*(int *)((char *)this + 617) & 0x800000) == 0 )
            *(int *)((char *)this + 617) |= 0x800000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 132);
          goto LABEL_90;
        case 0x19u:
          if ( (*(int *)((char *)this + 617) & 0x1000000) == 0 )
            *(int *)((char *)this + 617) |= 0x1000000u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          VarInt = sub_1011FD30((int)(this + 133), (unsigned int)v4, Size);
LABEL_90:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_91;
          return Bytes;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_90;
      }
    }
  }
LABEL_92:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10121660
// ============================================================
//----- (10121660) --------------------------------------------------------
int __thiscall sub_10121660(char *this, size_t Size, unsigned int a3)
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
  *(_DWORD *)(this + 617) = 0;
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
          if ( (*(this + 617) & 1) == 0 )
            *(_DWORD *)(this + 617) |= 1u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          Int32 = sub_10118360(this, (size_t)v4, Size);
          goto LABEL_90;
        case 2u:
          if ( (*(_DWORD *)(this + 617) & 2) == 0 )
            *(_DWORD *)(this + 617) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 56, Size);
          if ( Bytes )
            return Bytes;
          *(this + Size + 56) = 0;
          goto LABEL_91;
        case 3u:
          if ( (*(_DWORD *)(this + 617) & 4) == 0 )
            *(_DWORD *)(this + 617) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, this + 312);
          goto LABEL_90;
        case 4u:
          if ( (*(_DWORD *)(this + 617) & 8) == 0 )
            *(_DWORD *)(this + 617) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 316, Size);
          if ( Bytes )
            return Bytes;
          *(this + Size + 316) = 0;
LABEL_91:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_92;
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 617) & 0x10) == 0 )
            *(_DWORD *)(this + 617) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, this + 444);
          goto LABEL_90;
        case 6u:
          if ( (*(_DWORD *)(this + 617) & 0x20) == 0 )
            *(_DWORD *)(this + 617) |= 0x20u;
          Int32 = TdrBuf::ReadInt64(v4, this + 448);
          goto LABEL_90;
        case 7u:
          if ( (*(_DWORD *)(this + 617) & 0x40) == 0 )
            *(_DWORD *)(this + 617) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, this + 456);
          goto LABEL_90;
        case 8u:
          if ( (*(_DWORD *)(this + 617) & 0x80) == 0 )
            *(_DWORD *)(this + 617) |= 0x80u;
          Int32 = TdrBuf::ReadInt32(v4, this + 460);
          goto LABEL_90;
        case 9u:
          if ( (*(_DWORD *)(this + 617) & 0x100) == 0 )
            *(_DWORD *)(this + 617) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(v4, this + 464);
          goto LABEL_90;
        case 0xAu:
          if ( (*(_DWORD *)(this + 617) & 0x200) == 0 )
            *(_DWORD *)(this + 617) |= 0x200u;
          Int32 = TdrBuf::ReadInt32(v4, this + 468);
          goto LABEL_90;
        case 0xBu:
          if ( (*(_DWORD *)(this + 617) & 0x400) == 0 )
            *(_DWORD *)(this + 617) |= 0x400u;
          Int32 = TdrBuf::ReadInt32(v4, this + 472);
          goto LABEL_90;
        case 0xCu:
          if ( (*(_DWORD *)(this + 617) & 0x800) == 0 )
            *(_DWORD *)(this + 617) |= 0x800u;
          Int32 = TdrBuf::ReadInt32(v4, this + 476);
          goto LABEL_90;
        case 0xDu:
          if ( (*(_DWORD *)(this + 617) & 0x1000) == 0 )
            *(_DWORD *)(this + 617) |= 0x1000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 480);
          goto LABEL_90;
        case 0xEu:
          if ( (*(_DWORD *)(this + 617) & 0x2000) == 0 )
            *(_DWORD *)(this + 617) |= 0x2000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 484);
          goto LABEL_90;
        case 0xFu:
          if ( (*(_DWORD *)(this + 617) & 0x4000) == 0 )
            *(_DWORD *)(this + 617) |= 0x4000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 488);
          goto LABEL_90;
        case 0x10u:
          if ( (*(_DWORD *)(this + 617) & 0x8000) == 0 )
            *(_DWORD *)(this + 617) |= 0x8000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 492);
          goto LABEL_90;
        case 0x11u:
          if ( (*(_DWORD *)(this + 617) & 0x10000) == 0 )
            *(_DWORD *)(this + 617) |= 0x10000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 496);
          goto LABEL_90;
        case 0x12u:
          if ( (*(_DWORD *)(this + 617) & 0x20000) == 0 )
            *(_DWORD *)(this + 617) |= 0x20000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 500);
          goto LABEL_90;
        case 0x13u:
          if ( (*(_DWORD *)(this + 617) & 0x40000) == 0 )
            *(_DWORD *)(this + 617) |= 0x40000u;
          Int32 = TdrBuf::ReadInt64(v4, this + 504);
          goto LABEL_90;
        case 0x14u:
          if ( (*(_DWORD *)(this + 617) & 0x80000) == 0 )
            *(_DWORD *)(this + 617) |= 0x80000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 512);
          goto LABEL_90;
        case 0x15u:
          if ( (*(_DWORD *)(this + 617) & 0x100000) == 0 )
            *(_DWORD *)(this + 617) |= 0x100000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 516);
          goto LABEL_90;
        case 0x16u:
          if ( (*(_DWORD *)(this + 617) & 0x200000) == 0 )
            *(_DWORD *)(this + 617) |= 0x200000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 520);
          goto LABEL_90;
        case 0x17u:
          if ( (*(_DWORD *)(this + 617) & 0x400000) == 0 )
            *(_DWORD *)(this + 617) |= 0x400000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 524);
          goto LABEL_90;
        case 0x18u:
          if ( (*(_DWORD *)(this + 617) & 0x800000) == 0 )
            *(_DWORD *)(this + 617) |= 0x800000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 528);
          goto LABEL_90;
        case 0x19u:
          if ( (*(_DWORD *)(this + 617) & 0x1000000) == 0 )
            *(_DWORD *)(this + 617) |= 0x1000000u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          Int32 = sub_1011FEA0((int)(this + 532), (unsigned int)v4, Size);
LABEL_90:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_91;
          return Bytes;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_90;
      }
    }
  }
LABEL_92:
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
// Address Name: SUB_10121D40
// ============================================================
//----- (10121D40) --------------------------------------------------------
int __thiscall sub_10121D40(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // ecx

  if ( !"[id]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[id]", (char)a4);
    if ( !result )
    {
      if ( a3 >= 0 )
        result = sub_10118580(this, a2, a3 + 1, a4);
      else
        result = sub_10118580(this, a2, a3, a4);
      if ( !result )
      {
        result = sub_1024A410(a2, a3, a4, "[note]", (const char *)(this + 56));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[level]", "%d", *(_DWORD *)(this + 312));
          if ( !result )
          {
            result = sub_1024A410(a2, a3, a4, "[hunterStar]", (const char *)(this + 316));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[contribution]", "%d", *(_DWORD *)(this + 444));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[contributionAcc]", "%I64u", *(_QWORD *)(this + 448));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[wage]", "%d", *(_DWORD *)(this + 456));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[title]", "%d", *(_DWORD *)(this + 460));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[offlineTime]", "%u", *(_DWORD *)(this + 464));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[depotOpCount]", "%d", *(_DWORD *)(this + 468));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[hRLevel]", "%d", *(_DWORD *)(this + 472));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[joinTime]", "%u", *(_DWORD *)(this + 476));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[wildHuntSoul]", "%d", *(_DWORD *)(this + 480));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[wildHuntPhase]", "%d", *(_DWORD *)(this + 484));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[celebrationTask]", "%d", *(_DWORD *)(this + 488));
                                  if ( !result )
                                  {
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[preCelebrationTask]",
                                               "%d",
                                               *(_DWORD *)(this + 492));
                                    if ( !result )
                                    {
                                      result = print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[celebrationScore]",
                                                 "%d",
                                                 *(_DWORD *)(this + 496));
                                      if ( !result )
                                      {
                                        result = print_field(
                                                   a2,
                                                   a3,
                                                   a4,
                                                   "[celebrationReward]",
                                                   "%d",
                                                   *(_DWORD *)(this + 500));
                                        if ( !result )
                                        {
                                          result = print_field(
                                                     a2,
                                                     a3,
                                                     a4,
                                                     "[contributionWeekAcc]",
                                                     "%I64u",
                                                     *(_QWORD *)(this + 504));
                                          if ( !result )
                                          {
                                            result = print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[levelupAll]",
                                                       "%d",
                                                       *(_DWORD *)(this + 512));
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[hunterCount]",
                                                         "%d",
                                                         *(_DWORD *)(this + 516));
                                              if ( !result )
                                              {
                                                result = print_field(
                                                           a2,
                                                           a3,
                                                           a4,
                                                           "[taskCount]",
                                                           "%d",
                                                           *(_DWORD *)(this + 520));
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[isBaned]",
                                                             "%d",
                                                             *(_DWORD *)(this + 524));
                                                  if ( !result )
                                                  {
                                                    result = print_field(
                                                               a2,
                                                               a3,
                                                               a4,
                                                               "[banedTime]",
                                                               "%d",
                                                               *(_DWORD *)(this + 528));
                                                    if ( !result )
                                                    {
                                                      result = print_structure((int)a2, a3, a4, (int)"[guildWar]");
                                                      if ( !result )
                                                      {
                                                        v6 = this + 532;
                                                        if ( a3 >= 0 )
                                                          return sub_101200E0(v6, a2, a3 + 1, a4);
                                                        else
                                                          return sub_101200E0(v6, a2, a3, a4);
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
// Address Name: SUB_10118210
// ============================================================
//----- (10118210) --------------------------------------------------------
int __thiscall sub_10118210(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 8);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            VarULong = TdrBuf::ReadVarUInt(v4, this + 10);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 11);
            goto LABEL_20;
          default:
            VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = VarULong;
            if ( VarULong )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011FD30
// ============================================================
//----- (1011FD30) --------------------------------------------------------
int __thiscall sub_1011FD30(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v11 = 0;
  *(_DWORD *)(this + 81) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v11);
      if ( result )
        return result;
      switch ( v11 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 81) & 1) == 0 )
            *(_DWORD *)(this + 81) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_23;
          VarUInt = sub_1011B300((_DWORD *)this, (int)v4, a2);
          goto LABEL_22;
        case 2u:
          if ( (*(_DWORD *)(this + 81) & 2) == 0 )
            *(_DWORD *)(this + 81) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 72));
          goto LABEL_22;
        case 3u:
          if ( (*(_DWORD *)(this + 81) & 4) == 0 )
            *(_DWORD *)(this + 81) |= 4u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 76) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          v6 = 0;
LABEL_23:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_24;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 81) & 8) == 0 )
            *(_DWORD *)(this + 81) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(v4, (int *)(this + 77));
          goto LABEL_22;
        default:
          VarUInt = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_22:
          v6 = VarUInt;
          if ( !VarUInt )
            goto LABEL_23;
          return v6;
      }
    }
  }
LABEL_24:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011FEA0
// ============================================================
//----- (1011FEA0) --------------------------------------------------------
int __thiscall sub_1011FEA0(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v11 = 0;
  *(_DWORD *)(this + 81) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v11);
      if ( result )
        return result;
      switch ( v11 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 81) & 1) == 0 )
            *(_DWORD *)(this + 81) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_23;
          Int32 = sub_1011B450(this, (int)v4, a2);
          goto LABEL_22;
        case 2u:
          if ( (*(_DWORD *)(this + 81) & 2) == 0 )
            *(_DWORD *)(this + 81) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 72));
          goto LABEL_22;
        case 3u:
          if ( (*(_DWORD *)(this + 81) & 4) == 0 )
            *(_DWORD *)(this + 81) |= 4u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 76) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          v6 = 0;
LABEL_23:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_24;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 81) & 8) == 0 )
            *(_DWORD *)(this + 81) |= 8u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 77));
          goto LABEL_22;
        default:
          Int32 = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_22:
          v6 = Int32;
          if ( !Int32 )
            goto LABEL_23;
          return v6;
      }
    }
  }
LABEL_24:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10118360
// ============================================================
//----- (10118360) --------------------------------------------------------
int __thiscall sub_10118360(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 32);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)this + 40);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 44);
            goto LABEL_20;
          default:
            Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = Int64;
            if ( Int64 )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
            continue;
        }
      }
      break;
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
// Address Name: SUB_101200E0
// ============================================================
//----- (101200E0) --------------------------------------------------------
int __thiscall sub_101200E0(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  if ( !"[commerceBoatInfo]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[commerceBoatInfo]", (char)a4);
    if ( !result )
    {
      if ( a3 >= 0 )
        result = sub_1011B670((_DWORD *)this, a2, a3 + 1, a4);
      else
        result = sub_1011B670((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[contributeResPoint]", "%u", *(_DWORD *)(this + 72));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[challengeTimes]", "0x%02x", *(char *)(this + 76));
          if ( !result )
            return print_field(a2, a3, a4, "[refreshTimestamp]", "%d", *(_DWORD *)(this + 77));
        }
      }
    }
  }
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
// Address Name: SUB_10118580
// ============================================================
//----- (10118580) --------------------------------------------------------
int __thiscall sub_10118580(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = sub_1024A410((int)a2, a4, (char)"[name]", this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 32));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[rtid]", "%u", *(_DWORD *)(this + 40));
      if ( !result )
        return print_field(a2, a3, a4, "[uin]", "%I64u", *(_QWORD *)(this + 44));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B300
// ============================================================
//----- (1011B300) --------------------------------------------------------
int __thiscall sub_1011B300(_DWORD *this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(this + 17) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 17) & 1) == 0 )
              *(this + 17) |= 1u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this);
            goto LABEL_22;
          case 2u:
            if ( (*(this + 17) & 2) == 0 )
              *(this + 17) |= 2u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 1);
            goto LABEL_22;
          case 3u:
            if ( (*(this + 17) & 4) == 0 )
              *(this + 17) |= 4u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 2);
            goto LABEL_22;
          case 4u:
            if ( (*(this + 17) & 8) == 0 )
              *(this + 17) |= 8u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 3);
            goto LABEL_22;
          case 5u:
            if ( (*(this + 17) & 0x10) == 0 )
              *(this + 17) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            VarUInt = sub_1011A940(this + 4, v4, a2);
LABEL_22:
            v6 = VarUInt;
            if ( VarUInt )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            VarUInt = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B450
// ============================================================
//----- (1011B450) --------------------------------------------------------
int __thiscall sub_1011B450(int this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 68) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 68) & 1) == 0 )
              *(_DWORD *)(this + 68) |= 1u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
            goto LABEL_22;
          case 2u:
            if ( (*(_DWORD *)(this + 68) & 2) == 0 )
              *(_DWORD *)(this + 68) |= 2u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
            goto LABEL_22;
          case 3u:
            if ( (*(_DWORD *)(this + 68) & 4) == 0 )
              *(_DWORD *)(this + 68) |= 4u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
            goto LABEL_22;
          case 4u:
            if ( (*(_DWORD *)(this + 68) & 8) == 0 )
              *(_DWORD *)(this + 68) |= 8u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 12));
            goto LABEL_22;
          case 5u:
            if ( (*(_DWORD *)(this + 68) & 0x10) == 0 )
              *(_DWORD *)(this + 68) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            Int32 = sub_1011AAE0((unsigned int *)(this + 16), v4, a2);
LABEL_22:
            v6 = Int32;
            if ( Int32 )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B670
// ============================================================
//----- (1011B670) --------------------------------------------------------
int __thiscall sub_1011B670(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commerceBoatId]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[commerceBoatStartTime]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[commerceBoatStatus]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[levelId]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[grabInfo]");
          if ( !result )
          {
            if ( a3 >= 0 )
              return sub_1011AD50(a2, a3 + 1, a4);
            else
              return sub_1011AD50(a2, a3, a4);
          }
        }
      }
    }
  }
  return result;
}
// 1011AD50: using guessed type _DWORD __stdcall sub_1011AD50(_DWORD, _DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011A940
// ============================================================
//----- (1011A940) --------------------------------------------------------
int __thiscall sub_1011A940(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int VarULong; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarULong = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          VarULong = TdrBuf::ReadVarULong(v12, v11);
          if ( VarULong )
            return VarULong;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 2;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return VarULong;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        VarUInt = TdrBuf::ReadVarULong(v4, v5 + 9);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5 + 11);
        goto LABEL_25;
      default:
        VarUInt = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        VarULong = VarUInt;
        if ( !VarUInt )
          goto LABEL_26;
        return VarULong;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011AAE0
// ============================================================
//----- (1011AAE0) --------------------------------------------------------
int __thiscall sub_1011AAE0(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int Int64; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // edi
  _BYTE *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int64 = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          Int64 = TdrBuf::ReadInt64(v12, v11);
          if ( Int64 )
            return Int64;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 8;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return Int64;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        Int32 = TdrBuf::ReadInt64(v4, (_BYTE *)v5 + 36);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 44);
        goto LABEL_25;
      default:
        Int32 = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_26;
        return Int64;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011AD50
// ============================================================
//----- (1011AD50) --------------------------------------------------------
int __thiscall sub_1011AD50(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // esi
  int result; // eax
  int v7; // ecx
  unsigned int v8; // edi
  _QWORD *v9; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[playerCount]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 4 )
    {
      result = sub_1024A3B0(a2, a3, v7, "[playerId]", *this);
      if ( !result )
      {
        v8 = 0;
        if ( *this )
        {
          v9 = this + 1;
          while ( 1 )
          {
            result = Printf(a2, " %I64u", *v9);
            if ( result )
              break;
            ++v8;
            ++v9;
            if ( v8 >= *this )
            {
              v4 = a2;
              goto LABEL_10;
            }
          }
        }
        else
        {
LABEL_10:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            result = print_field(v4, a3, a4, "[ownGuildId]", "%I64u", *(_QWORD *)(this + 9));
            if ( !result )
              return print_field(v4, a3, a4, "[minTime]", "%u", *(this + 11));
          }
        }
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}
// 1011AD9F: variable 'v7' is possibly undefined



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



