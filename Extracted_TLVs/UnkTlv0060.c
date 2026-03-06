// ============================================================
// Name: TLV::UnkTlv0060::Read_0xAA
// Address Name: SUB_10140CF0
// ============================================================
//----- (10140CF0) --------------------------------------------------------
int __thiscall sub_10140CF0(int *this, int *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  int *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // ebx
  _DWORD *v14; // ecx
  int v15; // eax
  char *v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v20; // [esp+18h] [ebp-8h] BYREF
  int *v21; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v21 = this;
  *(this + 22333) = 0;
  v20 = 0;
  v7 = (char *)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (v4[22333] & 1) == 0 )
          v4[22333] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_37;
      case 2u:
        if ( (v4[22333] & 2) == 0 )
          v4[22333] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v17 = v6[1];
        a3 = v21 + 1;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1013FFC0(a3, v6, (int *)v19);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (int *)((char *)Size + v17) )
            return -34;
          if ( v11 == (int *)((char *)Size + v17) )
            break;
          a3 += 5439;
          if ( ++v10 >= 4 )
          {
            v4 = v21;
            goto LABEL_38;
          }
        }
        v12 = v10 + 1;
        v4 = v21;
        *v21 = v12;
        goto LABEL_38;
      case 3u:
        if ( (v4[22333] & 4) == 0 )
          v4[22333] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 21757);
        goto LABEL_37;
      case 4u:
        if ( (v4[22333] & 8) == 0 )
          v4[22333] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v13 = 0;
        v18 = v6[1];
        a3 = v21 + 21758;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1013ED00((int)a3, (size_t)v6, v19);
            if ( v5 )
              return v5;
          }
          v14 = (_DWORD *)v6[1];
          if ( v14 > (int *)((char *)Size + v18) )
            return -34;
          if ( v14 == (int *)((char *)Size + v18) )
            break;
          a3 = (int *)((char *)a3 + 230);
          if ( ++v13 >= 10 )
          {
            v4 = v21;
            goto LABEL_38;
          }
        }
        v15 = v13 + 1;
        v4 = v21;
        v21[21757] = v15;
LABEL_38:
        v7 = v16;
        if ( v6[1] < (unsigned int)v16 )
          continue;
LABEL_39:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v20 & 0xF);
LABEL_37:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_38;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0060::Read_0x99
// Address Name: SUB_10140F60
// ============================================================
//----- (10140F60) --------------------------------------------------------
int __thiscall sub_10140F60(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // ebx
  _DWORD *v14; // ecx
  int v15; // eax
  char *v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v20; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v21; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v21 = this;
  *(this + 22333) = 0;
  v20 = 0;
  v7 = (char *)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (v4[22333] & 1) == 0 )
          v4[22333] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_37;
      case 2u:
        if ( (v4[22333] & 2) == 0 )
          v4[22333] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v17 = v6[1];
        a3 = v21 + 1;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_10140190(a3, v6, (_DWORD *)v19);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (_DWORD *)((char *)Size + v17) )
            return -34;
          if ( v11 == (_DWORD *)((char *)Size + v17) )
            break;
          a3 += 5439;
          if ( ++v10 >= 4 )
          {
            v4 = v21;
            goto LABEL_38;
          }
        }
        v12 = v10 + 1;
        v4 = v21;
        *v21 = v12;
        goto LABEL_38;
      case 3u:
        if ( (v4[22333] & 4) == 0 )
          v4[22333] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 87028);
        goto LABEL_37;
      case 4u:
        if ( (v4[22333] & 8) == 0 )
          v4[22333] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v13 = 0;
        v18 = v6[1];
        a3 = v21 + 21758;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1013F1D0((int)a3, (size_t)v6, v19);
            if ( v5 )
              return v5;
          }
          v14 = (_DWORD *)v6[1];
          if ( v14 > (_DWORD *)((char *)Size + v18) )
            return -34;
          if ( v14 == (_DWORD *)((char *)Size + v18) )
            break;
          a3 = (_DWORD *)((char *)a3 + 230);
          if ( ++v13 >= 10 )
          {
            v4 = v21;
            goto LABEL_38;
          }
        }
        v15 = v13 + 1;
        v4 = v21;
        v21[21757] = v15;
LABEL_38:
        v7 = v16;
        if ( v6[1] < (unsigned int)v16 )
          continue;
LABEL_39:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v20 & 0xF);
LABEL_37:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_38;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0060::DoDebugFormat
// Address Name: SUB_101411F0
// ============================================================
//----- (101411F0) --------------------------------------------------------
int __thiscall sub_101411F0(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_101412A0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0060::DebugFormat
// Address Name: SUB_101412A0
// ============================================================
//----- (101412A0) --------------------------------------------------------
int __thiscall sub_101412A0(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v7; // eax
  int v8; // ebx
  bool v9; // cc
  int *v10; // eax
  int v11; // ecx
  int v12; // ebx
  _DWORD *v14; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *i; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 4 )
      return -7;
    v8 = 0;
    v9 = v7 <= 0;
    v10 = this;
    if ( v9 )
    {
LABEL_17:
      result = print_field(a2, a3, a4, "[cfgCount]", "%d", v10[21757]);
      if ( !result )
      {
        v11 = *(this + 21757);
        if ( v11 < 0 )
          return -6;
        if ( v11 > 10 )
          return -7;
        v12 = 0;
        if ( v11 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (unsigned __int8 *)(this + 21758); ; i += 230 )
          {
            if ( !"[cfgs]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[cfgs]", v12, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1013F770(i, a2, a3 + 1, a4) : sub_1013F770(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v12 >= *(this + 21757) )
              return 0;
          }
        }
      }
    }
    else
    {
      v14 = this + 1;
      while ( 1 )
      {
        if ( !"[libs]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[libs]", v8, (char)a4);
        if ( result )
          break;
        result = a3 >= 0 ? sub_10140430(v14, a2, a3 + 1, a4) : sub_10140430(v14, a2, a3, a4);
        if ( result )
          break;
        v10 = this;
        ++v8;
        v14 += 5439;
        if ( v8 >= *this )
          goto LABEL_17;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013ED00
// ============================================================
//----- (1013ED00) --------------------------------------------------------
int __thiscall sub_1013ED00(int this, size_t Size, unsigned int a3)
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
  *(_DWORD *)(this + 226) = 0;
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
          if ( (*(_BYTE *)(this + 226) & 1) == 0 )
            *(_DWORD *)(this + 226) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)this);
          goto LABEL_71;
        case 2u:
          if ( (*(_DWORD *)(this + 226) & 2) == 0 )
            *(_DWORD *)(this + 226) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 4));
          goto LABEL_71;
        case 3u:
          if ( (*(_DWORD *)(this + 226) & 4) == 0 )
            *(_DWORD *)(this + 226) |= 4u;
          VarInt = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 8));
          goto LABEL_71;
        case 4u:
          if ( (*(_DWORD *)(this + 226) & 8) == 0 )
            *(_DWORD *)(this + 226) |= 8u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 9));
          goto LABEL_71;
        case 5u:
          if ( (*(_DWORD *)(this + 226) & 0x10) == 0 )
            *(_DWORD *)(this + 226) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 13));
          goto LABEL_71;
        case 6u:
          if ( (*(_DWORD *)(this + 226) & 0x20) == 0 )
            *(_DWORD *)(this + 226) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 17));
          goto LABEL_71;
        case 7u:
          if ( (*(_DWORD *)(this + 226) & 0x40) == 0 )
            *(_DWORD *)(this + 226) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 21));
          goto LABEL_71;
        case 8u:
          if ( (*(_DWORD *)(this + 226) & 0x80) == 0 )
            *(_DWORD *)(this + 226) |= 0x80u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 25), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 25) = 0;
          goto LABEL_72;
        case 9u:
          if ( (*(_DWORD *)(this + 226) & 0x100) == 0 )
            *(_DWORD *)(this + 226) |= 0x100u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 57), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 57) = 0;
          goto LABEL_72;
        case 0xAu:
          if ( (*(_DWORD *)(this + 226) & 0x200) == 0 )
            *(_DWORD *)(this + 226) |= 0x200u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 89), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 89) = 0;
          goto LABEL_72;
        case 0xBu:
          if ( (*(_DWORD *)(this + 226) & 0x400) == 0 )
            *(_DWORD *)(this + 226) |= 0x400u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 121), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 121) = 0;
          goto LABEL_72;
        case 0xCu:
          if ( (*(_DWORD *)(this + 226) & 0x800) == 0 )
            *(_DWORD *)(this + 226) |= 0x800u;
          VarInt = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 153));
          goto LABEL_71;
        case 0xDu:
          if ( (*(_DWORD *)(this + 226) & 0x1000) == 0 )
            *(_DWORD *)(this + 226) |= 0x1000u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 154));
          goto LABEL_71;
        case 0xEu:
          if ( (*(_DWORD *)(this + 226) & 0x2000) == 0 )
            *(_DWORD *)(this + 226) |= 0x2000u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 158), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 158) = 0;
          goto LABEL_72;
        case 0xFu:
          if ( (*(_DWORD *)(this + 226) & 0x4000) == 0 )
            *(_DWORD *)(this + 226) |= 0x4000u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 190), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 190) = 0;
LABEL_72:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_73;
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 226) & 0x8000) == 0 )
            *(_DWORD *)(this + 226) |= 0x8000u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 222));
          goto LABEL_71;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_71:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_72;
          return Bytes;
      }
    }
  }
LABEL_73:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013FFC0
// ============================================================
//----- (1013FFC0) --------------------------------------------------------
int __thiscall sub_1013FFC0(int *this, int *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  int *v6; // edi
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
  *(this + 5438) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (v4[5438] & 1) == 0 )
          v4[5438] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_27;
      case 2u:
        if ( (v4[5438] & 2) == 0 )
          v4[5438] |= 2u;
        VarInt = TdrBuf::ReadVarUInt(v6, v4 + 1);
        goto LABEL_27;
      case 3u:
        if ( (v4[5438] & 4) == 0 )
          v4[5438] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_27;
      case 4u:
        if ( (v4[5438] & 8) == 0 )
          v4[5438] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = v17 + 3;
        while ( 1 )
        {
          v15 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v15);
          if ( v5 )
            return v5;
          if ( v15 )
          {
            v5 = sub_1013DA50(a3, v6, v15);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (int *)((char *)Size + v14) )
            return -34;
          if ( v11 == (int *)((char *)Size + v14) )
            break;
          a3 = (int *)((char *)a3 + 2174);
          if ( ++v10 >= 10 )
          {
            v4 = v17;
            goto LABEL_28;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        v17[2] = v12;
LABEL_28:
        v7 = v13;
        if ( v6[1] < (unsigned int)v13 )
          continue;
LABEL_29:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_27:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_28;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10140190
// ============================================================
//----- (10140190) --------------------------------------------------------
int __thiscall sub_10140190(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 5438) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (v4[5438] & 1) == 0 )
          v4[5438] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_27;
      case 2u:
        if ( (v4[5438] & 2) == 0 )
          v4[5438] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_27;
      case 3u:
        if ( (v4[5438] & 4) == 0 )
          v4[5438] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_27;
      case 4u:
        if ( (v4[5438] & 8) == 0 )
          v4[5438] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = v17 + 3;
        while ( 1 )
        {
          v15 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v15);
          if ( v5 )
            return v5;
          if ( v15 )
          {
            v5 = sub_1013DC70((int)a3, v6, v15);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (_DWORD *)((char *)Size + v14) )
            return -34;
          if ( v11 == (_DWORD *)((char *)Size + v14) )
            break;
          a3 = (_DWORD *)((char *)a3 + 2174);
          if ( ++v10 >= 10 )
          {
            v4 = v17;
            goto LABEL_28;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        v17[2] = v12;
LABEL_28:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_29:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_27:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_28;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013F1D0
// ============================================================
//----- (1013F1D0) --------------------------------------------------------
int __thiscall sub_1013F1D0(int this, size_t Size, unsigned int a3)
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
  *(_DWORD *)(this + 226) = 0;
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
          if ( (*(_BYTE *)(this + 226) & 1) == 0 )
            *(_DWORD *)(this + 226) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_71;
        case 2u:
          if ( (*(_DWORD *)(this + 226) & 2) == 0 )
            *(_DWORD *)(this + 226) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          goto LABEL_71;
        case 3u:
          if ( (*(_DWORD *)(this + 226) & 4) == 0 )
            *(_DWORD *)(this + 226) |= 4u;
          Int32 = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 8));
          goto LABEL_71;
        case 4u:
          if ( (*(_DWORD *)(this + 226) & 8) == 0 )
            *(_DWORD *)(this + 226) |= 8u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 9));
          goto LABEL_71;
        case 5u:
          if ( (*(_DWORD *)(this + 226) & 0x10) == 0 )
            *(_DWORD *)(this + 226) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 13));
          goto LABEL_71;
        case 6u:
          if ( (*(_DWORD *)(this + 226) & 0x20) == 0 )
            *(_DWORD *)(this + 226) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 17));
          goto LABEL_71;
        case 7u:
          if ( (*(_DWORD *)(this + 226) & 0x40) == 0 )
            *(_DWORD *)(this + 226) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 21));
          goto LABEL_71;
        case 8u:
          if ( (*(_DWORD *)(this + 226) & 0x80) == 0 )
            *(_DWORD *)(this + 226) |= 0x80u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 25), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 25) = 0;
          goto LABEL_72;
        case 9u:
          if ( (*(_DWORD *)(this + 226) & 0x100) == 0 )
            *(_DWORD *)(this + 226) |= 0x100u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 57), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 57) = 0;
          goto LABEL_72;
        case 0xAu:
          if ( (*(_DWORD *)(this + 226) & 0x200) == 0 )
            *(_DWORD *)(this + 226) |= 0x200u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 89), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 89) = 0;
          goto LABEL_72;
        case 0xBu:
          if ( (*(_DWORD *)(this + 226) & 0x400) == 0 )
            *(_DWORD *)(this + 226) |= 0x400u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 121), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 121) = 0;
          goto LABEL_72;
        case 0xCu:
          if ( (*(_DWORD *)(this + 226) & 0x800) == 0 )
            *(_DWORD *)(this + 226) |= 0x800u;
          Int32 = TdrBuf::ReadByte_2(v4, (_BYTE *)(this + 153));
          goto LABEL_71;
        case 0xDu:
          if ( (*(_DWORD *)(this + 226) & 0x1000) == 0 )
            *(_DWORD *)(this + 226) |= 0x1000u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 154));
          goto LABEL_71;
        case 0xEu:
          if ( (*(_DWORD *)(this + 226) & 0x2000) == 0 )
            *(_DWORD *)(this + 226) |= 0x2000u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 158), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 158) = 0;
          goto LABEL_72;
        case 0xFu:
          if ( (*(_DWORD *)(this + 226) & 0x4000) == 0 )
            *(_DWORD *)(this + 226) |= 0x4000u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 190), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 190) = 0;
LABEL_72:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_73;
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 226) & 0x8000) == 0 )
            *(_DWORD *)(this + 226) |= 0x8000u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 222));
          goto LABEL_71;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_71:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_72;
          return Bytes;
      }
    }
  }
LABEL_73:
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
// Address Name: SUB_1013F770
// ============================================================
//----- (1013F770) --------------------------------------------------------
int __thiscall sub_1013F770(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lib]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[content]", "0x%02x", *(this + 8));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[arg1]", "%d", *(_DWORD *)(this + 9));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[arg2]", "%d", *(_DWORD *)(this + 13));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[arg3]", "%d", *(_DWORD *)(this + 17));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[npc]", "%d", *(_DWORD *)(this + 21));
              if ( !result )
              {
                result = sub_1024A410(a2, a3, a4, "[name]", (const char *)this + 25);
                if ( !result )
                {
                  result = sub_1024A410(a2, a3, a4, "[note]", (const char *)this + 57);
                  if ( !result )
                  {
                    result = sub_1024A410(a2, a3, a4, "[icon]", (const char *)this + 89);
                    if ( !result )
                    {
                      result = sub_1024A410(a2, a3, a4, "[best]", (const char *)this + 121);
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[statisticsType]", "0x%02x", *(this + 153));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[itemPrize]", "%d", *(_DWORD *)(this + 154));
                          if ( !result )
                          {
                            result = sub_1024A410(a2, a3, a4, "[note1]", (const char *)this + 158);
                            if ( !result )
                            {
                              result = sub_1024A410(a2, a3, a4, "[note2]", (const char *)this + 190);
                              if ( !result )
                                return print_field(a2, a3, a4, "[objType]", "%d", *(_DWORD *)(this + 222));
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
// Address Name: SUB_10140430
// ============================================================
//----- (10140430) --------------------------------------------------------
int __thiscall sub_10140430(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx
  int v6; // esi
  _DWORD *i; // ebx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[count]", "%d", *(this + 2));
      if ( !result )
      {
        v5 = *(this + 2);
        if ( v5 >= 0 )
        {
          if ( v5 <= 10 )
          {
            v6 = 0;
            if ( v5 <= 0 )
            {
              return 0;
            }
            else
            {
              for ( i = this + 3; ; i = (_DWORD *)((char *)i + 2174) )
              {
                result = sub_1024A230(a2, a3, a4, "[sculptures]", v6);
                if ( result )
                  break;
                result = a3 >= 0 ? sub_1013DF60(i, a2, a3 + 1, a4) : sub_1013DF60(i, a2, a3, a4);
                if ( result )
                  break;
                if ( ++v6 >= *(this + 2) )
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
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013DA50
// ============================================================
//----- (1013DA50) --------------------------------------------------------
int __thiscall sub_1013DA50(int *this, int *Size, unsigned int a3)
{
  unsigned int v3; // eax
  int *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = Size;
  v6 = 0;
  v10 = 0;
  *(int *)((char *)this + 2170) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*((_BYTE *)this + 2170) & 1) == 0 )
            *(int *)((char *)this + 2170) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          break;
        case 2u:
          if ( (*(int *)((char *)this + 2170) & 2) == 0 )
            *(int *)((char *)this + 2170) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 1);
          break;
        case 3u:
          if ( (*(int *)((char *)this + 2170) & 4) == 0 )
            *(int *)((char *)this + 2170) |= 4u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          VarInt = sub_10138FC0(this + 2, (size_t)v4, (int)Size);
          break;
        case 4u:
          if ( (*(int *)((char *)this + 2170) & 8) == 0 )
            *(int *)((char *)this + 2170) |= 8u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          VarInt = sub_10139810(this + 13, v4, Size);
          break;
        case 5u:
          if ( (*(int *)((char *)this + 2170) & 0x10) == 0 )
            *(int *)((char *)this + 2170) |= 0x10u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          VarInt = sub_1013ABB0(this + 48, v4, Size);
          break;
        case 6u:
          if ( (*(int *)((char *)this + 2170) & 0x20) == 0 )
            *(int *)((char *)this + 2170) |= 0x20u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          VarInt = sub_1013CE50(this + 125, v4, (int)Size);
          break;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_32:
      v7 = a3;
      if ( v4[1] >= a3 )
        goto LABEL_33;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013DC70
// ============================================================
//----- (1013DC70) --------------------------------------------------------
int __thiscall sub_1013DC70(int this, _DWORD *Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = Size;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 2170) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 2170) & 1) == 0 )
            *(_DWORD *)(this + 2170) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 2170) & 2) == 0 )
            *(_DWORD *)(this + 2170) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 2170) & 4) == 0 )
            *(_DWORD *)(this + 2170) |= 4u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          Int32 = sub_101390C0(this + 8, (size_t)v4, (int)Size);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 2170) & 8) == 0 )
            *(_DWORD *)(this + 2170) |= 8u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          Int32 = sub_10139980((_DWORD *)(this + 52), v4, Size);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 2170) & 0x10) == 0 )
            *(_DWORD *)(this + 2170) |= 0x10u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          Int32 = sub_1013AD20((_DWORD *)(this + 192), v4, Size);
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 2170) & 0x20) == 0 )
            *(_DWORD *)(this + 2170) |= 0x20u;
          Size = 0;
          v6 = TdrBuf::ReadInt32(v4, &Size);
          if ( v6 )
            return v6;
          if ( !Size )
            goto LABEL_32;
          Int32 = sub_1013D040(this + 500, v4, (int)Size);
          break;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_32:
      v7 = a3;
      if ( v4[1] >= a3 )
        goto LABEL_33;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013DF60
// ============================================================
//----- (1013DF60) --------------------------------------------------------
int __thiscall sub_1013DF60(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  const char *v5; // ecx
  _DWORD *v6; // ecx
  _DWORD *v7; // ecx
  char *v8; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[round]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_structure((int)a2, a3, a4, (int)"[best]");
      if ( !result )
      {
        v5 = (const char *)(this + 2);
        result = a3 >= 0 ? sub_10139290(v5, a2, a3 + 1, a4) : sub_10139290(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[histories]");
          if ( !result )
          {
            v6 = this + 13;
            result = a3 >= 0 ? sub_10139BC0(v6, a2, a3 + 1, a4) : sub_10139BC0(v6, a2, a3, a4);
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[currents]");
              if ( !result )
              {
                v7 = this + 48;
                if ( a3 >= 0 )
                  result = sub_1013AF60(v7, a2, a3 + 1, a4);
                else
                  result = sub_1013AF60(v7, a2, a3, a4);
                if ( !result )
                {
                  result = print_structure((int)a2, a3, a4, (int)"[avatar]");
                  if ( !result )
                  {
                    v8 = (char *)(this + 125);
                    if ( a3 >= 0 )
                      return sub_1013D300(v8, a2, a3 + 1, a4);
                    else
                      return sub_1013D300(v8, a2, a3, a4);
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
// Address Name: SUB_10139810
// ============================================================
//----- (10139810) --------------------------------------------------------
int __thiscall sub_10139810(int *this, _DWORD *Size, int *a3)
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
  *(this + 34) = 0;
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
        if ( (v4[34] & 1) == 0 )
          v4[34] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[34] & 2) == 0 )
            v4[34] |= 2u;
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
              v5 = sub_10138FC0(a3, (size_t)v6, v15);
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
            a3 += 11;
            if ( ++v10 >= 3 )
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
// Name: Internal Helper Function
// Address Name: SUB_1013CE50
// ============================================================
//----- (1013CE50) --------------------------------------------------------
int __thiscall sub_1013CE50(int *this, _DWORD *a2, int a3)
{
  int Bytes; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  size_t Size; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  Bytes = 0;
  v9 = 0;
  *(int *)((char *)this + 1666) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*((_BYTE *)this + 1666) & 1) == 0 )
            *(int *)((char *)this + 1666) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          goto LABEL_27;
        case 2u:
          if ( (*(int *)((char *)this + 1666) & 2) == 0 )
            *(int *)((char *)this + 1666) |= 2u;
          VarInt = TdrBuf::ReadVarULong(a2, this + 1);
          goto LABEL_27;
        case 3u:
          if ( (*(int *)((char *)this + 1666) & 4) == 0 )
            *(int *)((char *)this + 1666) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(a2, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(a2, this + 3, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 12) = 0;
LABEL_28:
          v5 = v10;
          if ( a2[1] >= v10 )
            goto LABEL_29;
          break;
        case 4u:
          if ( (*(int *)((char *)this + 1666) & 8) == 0 )
            *(int *)((char *)this + 1666) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          VarInt = sub_1013BAB0(this + 11, a2, (int *)Size);
          goto LABEL_27;
        case 5u:
          if ( (*(int *)((char *)this + 1666) & 0x10) == 0 )
            *(int *)((char *)this + 1666) |= 0x10u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          VarInt = sub_1013C390(this + 93, a2, Size);
LABEL_27:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_28;
          return Bytes;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          goto LABEL_27;
      }
    }
  }
LABEL_29:
  if ( a2[1] > v5 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10138FC0
// ============================================================
//----- (10138FC0) --------------------------------------------------------
int __thiscall sub_10138FC0(int *this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int VarInt; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(this + 10) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(this + 10) & 2) == 0 )
          *(this + 10) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, this + 1);
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        VarInt = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(this + 10) & 4) == 0 )
        *(this + 10) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, this + 2, Size);
      if ( Bytes )
        return Bytes;
      *((_BYTE *)this + v10 + 8) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 10) & 1) == 0 )
      *(this + 10) |= 1u;
    VarInt = TdrBuf::ReadVarInt(v6, this);
LABEL_19:
    Bytes = VarInt;
    if ( VarInt )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013ABB0
// ============================================================
//----- (1013ABB0) --------------------------------------------------------
int __thiscall sub_1013ABB0(int *this, _DWORD *Size, int *a3)
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
  *(this + 76) = 0;
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
        if ( (v4[76] & 1) == 0 )
          v4[76] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[76] & 2) == 0 )
            v4[76] |= 2u;
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
              v5 = sub_1013A220(a3, (size_t)v6, v15);
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
            a3 += 15;
            if ( ++v10 >= 5 )
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
// Name: Internal Helper Function
// Address Name: SUB_10139980
// ============================================================
//----- (10139980) --------------------------------------------------------
int __thiscall sub_10139980(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 34) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
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
        if ( (v4[34] & 1) == 0 )
          v4[34] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[34] & 2) == 0 )
            v4[34] |= 2u;
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
              v5 = sub_101390C0((int)a3, (size_t)v6, v15);
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
            a3 += 11;
            if ( ++v10 >= 3 )
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
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101390C0
// ============================================================
//----- (101390C0) --------------------------------------------------------
int __thiscall sub_101390C0(int this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int Int32; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 40) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 40) & 2) == 0 )
          *(_DWORD *)(this + 40) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 4));
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 40) & 4) == 0 )
        *(_DWORD *)(this + 40) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 8), Size);
      if ( Bytes )
        return Bytes;
      *(_BYTE *)(this + v10 + 8) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 40) & 1) == 0 )
      *(_DWORD *)(this + 40) |= 1u;
    Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this);
LABEL_19:
    Bytes = Int32;
    if ( Int32 )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013AD20
// ============================================================
//----- (1013AD20) --------------------------------------------------------
int __thiscall sub_1013AD20(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 76) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
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
        if ( (v4[76] & 1) == 0 )
          v4[76] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[76] & 2) == 0 )
            v4[76] |= 2u;
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
              v5 = sub_1013A390((int)a3, (size_t)v6, v15);
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
            a3 += 15;
            if ( ++v10 >= 5 )
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
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013D040
// ============================================================
//----- (1013D040) --------------------------------------------------------
int __thiscall sub_1013D040(int this, _DWORD *a2, int a3)
{
  int Bytes; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  size_t Size; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  Bytes = 0;
  v9 = 0;
  *(_DWORD *)(this + 1666) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 1666) & 1) == 0 )
            *(_DWORD *)(this + 1666) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          goto LABEL_27;
        case 2u:
          if ( (*(_DWORD *)(this + 1666) & 2) == 0 )
            *(_DWORD *)(this + 1666) |= 2u;
          Int32 = TdrBuf::ReadInt64(a2, (_BYTE *)(this + 4));
          goto LABEL_27;
        case 3u:
          if ( (*(_DWORD *)(this + 1666) & 4) == 0 )
            *(_DWORD *)(this + 1666) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(a2, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(a2, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_28:
          v5 = v10;
          if ( a2[1] >= v10 )
            goto LABEL_29;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 1666) & 8) == 0 )
            *(_DWORD *)(this + 1666) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          Int32 = sub_1013BC20((_DWORD *)(this + 44), a2, Size);
          goto LABEL_27;
        case 5u:
          if ( (*(_DWORD *)(this + 1666) & 0x10) == 0 )
            *(_DWORD *)(this + 1666) |= 0x10u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          Int32 = sub_1013C510(this + 372, a2, Size);
LABEL_27:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_28;
          return Bytes;
        default:
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
          goto LABEL_27;
      }
    }
  }
LABEL_29:
  if ( a2[1] > v5 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013D300
// ============================================================
//----- (1013D300) --------------------------------------------------------
int __thiscall sub_1013D300(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx
  unsigned int *v6; // ecx

  result = print_field(a2, a3, a4, "[sex]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 4));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[name]", this + 12);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[equips]");
        if ( !result )
        {
          v5 = this + 44;
          if ( a3 >= 0 )
            result = sub_1013BE60(v5, a2, a3 + 1, a4);
          else
            result = sub_1013BE60(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[attrs]");
            if ( !result )
            {
              v6 = (unsigned int *)(this + 372);
              if ( a3 >= 0 )
                return sub_1013C760(v6, a2, a3 + 1, a4);
              else
                return sub_1013C760(v6, a2, a3, a4);
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
// Address Name: SUB_10139BC0
// ============================================================
//----- (10139BC0) --------------------------------------------------------
int __thiscall sub_10139BC0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  const char *i; // edi

  result = print_field(a2, a3, a4, "[hisCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 3 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (const char *)(this + 1); ; i += 44 )
          {
            if ( !"[sculptures]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[sculptures]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10139290(i, a2, a3 + 1, a4) : sub_10139290(i, a2, a3, a4);
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
// Address Name: SUB_10139290
// ============================================================
//----- (10139290) --------------------------------------------------------
int __thiscall sub_10139290(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[round]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[score]", "%d", *((_DWORD *)this + 1));
    if ( !result )
      return sub_1024A410(a2, a3, a4, "[name]", this + 8);
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013AF60
// ============================================================
//----- (1013AF60) --------------------------------------------------------
int __thiscall sub_1013AF60(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  char *i; // edi

  result = print_field(a2, a3, a4, "[curCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 5 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (char *)(this + 1); ; i += 60 )
          {
            if ( !"[sculptures]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[sculptures]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1013A5D0(i, a2, a3 + 1, a4) : sub_1013A5D0(i, a2, a3, a4);
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
// Address Name: SUB_1013C390
// ============================================================
//----- (1013C390) --------------------------------------------------------
int __thiscall sub_1013C390(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)((char *)this + 1290) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
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
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (*((_BYTE *)this + 1290) & 1) == 0 )
          *(_DWORD *)((char *)this + 1290) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, this);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)((char *)this + 1290) & 2) == 0 )
            *(_DWORD *)((char *)this + 1290) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *((_BYTE *)this + v11 + 4) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *this = v11 + 1;
                  goto LABEL_23;
                }
                if ( (unsigned int)++v11 >= 0x506 )
                {
                  v6 = a3;
                  goto LABEL_23;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        VarUInt = TdrBuf::SkipField(v4, v16 & 0xF);
      }
      v6 = VarUInt;
      if ( VarUInt )
        return v6;
LABEL_23:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BAB0
// ============================================================
//----- (1013BAB0) --------------------------------------------------------
int __thiscall sub_1013BAB0(_DWORD *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 81) = 0;
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
        if ( (v4[81] & 1) == 0 )
          v4[81] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[81] & 2) == 0 )
            v4[81] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
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
              v5 = sub_1013B3B0(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 2;
            if ( (unsigned int)++v10 >= 0x28 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarUInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarUInt;
      if ( VarUInt )
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
// Name: Internal Helper Function
// Address Name: SUB_1013A220
// ============================================================
//----- (1013A220) --------------------------------------------------------
int __thiscall sub_1013A220(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 14) = 0;
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
          if ( (*(_BYTE *)(this + 14) & 1) == 0 )
            *(this + 14) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_23;
        case 2u:
          if ( (*(this + 14) & 2) == 0 )
            *(this + 14) |= 2u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 1);
          goto LABEL_23;
        case 3u:
          if ( (*(this + 14) & 4) == 0 )
            *(this + 14) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 3, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 12) = 0;
LABEL_24:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_25;
          break;
        case 4u:
          if ( (*(this + 14) & 8) == 0 )
            *(this + 14) |= 8u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 11);
          goto LABEL_23;
        case 5u:
          if ( (*(this + 14) & 0x10) == 0 )
            *(this + 14) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 13);
          goto LABEL_23;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_23:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_24;
          return Bytes;
      }
    }
  }
LABEL_25:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013A390
// ============================================================
//----- (1013A390) --------------------------------------------------------
int __thiscall sub_1013A390(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 56) = 0;
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
          if ( (*(_BYTE *)(this + 56) & 1) == 0 )
            *(_DWORD *)(this + 56) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_23;
        case 2u:
          if ( (*(_DWORD *)(this + 56) & 2) == 0 )
            *(_DWORD *)(this + 56) |= 2u;
          Int32 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 4));
          goto LABEL_23;
        case 3u:
          if ( (*(_DWORD *)(this + 56) & 4) == 0 )
            *(_DWORD *)(this + 56) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_24:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_25;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 56) & 8) == 0 )
            *(_DWORD *)(this + 56) |= 8u;
          Int32 = TdrBuf::ReadInt64(v4, (_BYTE *)(this + 44));
          goto LABEL_23;
        case 5u:
          if ( (*(_DWORD *)(this + 56) & 0x10) == 0 )
            *(_DWORD *)(this + 56) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 52));
          goto LABEL_23;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_23:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_24;
          return Bytes;
      }
    }
  }
LABEL_25:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BC20
// ============================================================
//----- (1013BC20) --------------------------------------------------------
int __thiscall sub_1013BC20(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 81) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
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
        if ( (v4[81] & 1) == 0 )
          v4[81] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[81] & 2) == 0 )
            v4[81] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1013B430(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 8;
            if ( (unsigned int)++v10 >= 0x28 )
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
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013C510
// ============================================================
//----- (1013C510) --------------------------------------------------------
int __thiscall sub_1013C510(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)(this + 1290) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
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
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1290) & 1) == 0 )
          *(_DWORD *)(this + 1290) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 1290) & 2) == 0 )
            *(_DWORD *)(this + 1290) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *(_BYTE *)(v11 + this + 4) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *(_DWORD *)this = v11 + 1;
                  goto LABEL_23;
                }
                if ( (unsigned int)++v11 >= 0x506 )
                {
                  v6 = a3;
                  goto LABEL_23;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_23:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BE60
// ============================================================
//----- (1013BE60) --------------------------------------------------------
int __thiscall sub_1013BE60(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int *i; // edi
  int v8; // [esp-8h] [ebp-14h]

  result = print_field(a2, a3, a4, "[count]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 0x28u )
    {
      v6 = 0;
      if ( *this )
      {
        for ( i = this + 1; ; i += 2 )
        {
          if ( !"[equips]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[equips]", v6, a4);
          if ( result )
            break;
          v8 = *i;
          result = a3 >= 0
                 ? print_field(a2, a3 + 1, a4, "[itemType]", "%d", v8)
                 : print_field(a2, a3, a4, "[itemType]", "%d", v8);
          if ( result )
            break;
          if ( (unsigned int)++v6 >= *this )
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
// Address Name: SUB_1013C760
// ============================================================
//----- (1013C760) --------------------------------------------------------
int __thiscall sub_1013C760(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // esi

  result = print_field(a2, a3, a4, "[attrSize]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 0x506 )
    {
      result = sub_1024A3B0(a2, a3, v6, "[attrs]", *this);
      if ( !result )
      {
        v7 = 0;
        if ( *this )
        {
          while ( 1 )
          {
            result = Printf(a2, " %d", *((unsigned __int8 *)this + v7 + 4));
            if ( result )
              break;
            if ( ++v7 >= *this )
              return TdrBuf::WriteChar(a2, a4);
          }
        }
        else
        {
          return TdrBuf::WriteChar(a2, a4);
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
// 1013C7AD: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013A5D0
// ============================================================
//----- (1013A5D0) --------------------------------------------------------
int __thiscall sub_1013A5D0(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[score]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 4));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[name]", this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[uin]", "%I64u", *(_QWORD *)(this + 44));
        if ( !result )
          return print_field(a2, a3, a4, "[time]", "%d", *((_DWORD *)this + 13));
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013B3B0
// ============================================================
//----- (1013B3B0) --------------------------------------------------------
int __thiscall sub_1013B3B0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 1) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
    if ( a2[1] > v6 )
      return -34;
    return v5;
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
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013B430
// ============================================================
//----- (1013B430) --------------------------------------------------------
int __thiscall sub_1013B430(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
    if ( a2[1] > v6 )
      return -34;
    return v5;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
    }
  }
  return result;
}



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



