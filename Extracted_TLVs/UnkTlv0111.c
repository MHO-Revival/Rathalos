// ============================================================
// Name: TLV::UnkTlv0111::Read
// Address Name: SUB_1016AB20
// ============================================================
//----- (1016AB20) --------------------------------------------------------
int __thiscall sub_1016AB20(void *this, size_t a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1016ABF0((int)this, &Size, v8);
  else
    result = sub_1016ADD0((int)this, &Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0111::Read_0xAA
// Address Name: SUB_1016ABF0
// ============================================================
//----- (1016ABF0) --------------------------------------------------------
int __thiscall sub_1016ABF0(int this, _DWORD *Size, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 634) = 0;
  v5 = Size[1] + a3;
  v10 = v5;
  if ( Size[1] >= v5 )
  {
LABEL_27:
    if ( Size[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(Size, &v8);
      if ( result )
        break;
      switch ( v8 >> 4 )
      {
        case 2u:
          if ( (*(_BYTE *)(this + 634) & 1) == 0 )
            *(_DWORD *)(this + 634) |= 1u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10167BB0(this, Size, v9);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 634) & 2) == 0 )
            *(_DWORD *)(this + 634) |= 2u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_101684B0((_DWORD *)(this + 585), Size, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 634) & 4) == 0 )
            *(_DWORD *)(this + 634) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_101691E0(this + 597, Size, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 634) & 8) == 0 )
            *(_DWORD *)(this + 634) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_1016A260((char *)(this + 625), Size, v9);
          break;
        default:
          v7 = TdrBuf::SkipField(Size, v8 & 0xF);
          break;
      }
      v4 = v7;
      if ( v7 )
        return v4;
LABEL_26:
      v5 = v10;
      if ( Size[1] >= v10 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0111::Read_0x99
// Address Name: SUB_1016ADD0
// ============================================================
//----- (1016ADD0) --------------------------------------------------------
int __thiscall sub_1016ADD0(int this, _DWORD *Size, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 634) = 0;
  v5 = Size[1] + a3;
  v10 = v5;
  if ( Size[1] >= v5 )
  {
LABEL_27:
    if ( Size[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(Size, &v8);
      if ( result )
        break;
      switch ( v8 >> 4 )
      {
        case 2u:
          if ( (*(_BYTE *)(this + 634) & 1) == 0 )
            *(_DWORD *)(this + 634) |= 1u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10167D60(this, Size, v9);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 634) & 2) == 0 )
            *(_DWORD *)(this + 634) |= 2u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10168550(this + 585, Size, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 634) & 4) == 0 )
            *(_DWORD *)(this + 634) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10169610(this + 597, Size, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 634) & 8) == 0 )
            *(_DWORD *)(this + 634) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_1016A350((char *)(this + 625), Size, v9);
          break;
        default:
          v7 = TdrBuf::SkipField(Size, v8 & 0xF);
          break;
      }
      v4 = v7;
      if ( v7 )
        return v4;
LABEL_26:
      v5 = v10;
      if ( Size[1] >= v10 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0111::DoDebugFormat
// Address Name: SUB_1016AFD0
// ============================================================
//----- (1016AFD0) --------------------------------------------------------
int __thiscall sub_1016AFD0(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1016B080(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0111::DebugFormat
// Address Name: SUB_1016B080
// ============================================================
//----- (1016B080) --------------------------------------------------------
int __thiscall sub_1016B080(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // ecx

  if ( !"[stChatTabs]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[stChatTabs]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_10167FE0(this, a2, a3 + 1, a4) : sub_10167FE0(this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[stHunterStar]");
        if ( !result )
        {
          v5 = this + 585;
          result = a3 >= 0 ? sub_101686F0(v5, a2, a3 + 1, a4) : sub_101686F0(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[stGamePadCustom]");
            if ( !result )
            {
              v6 = this + 597;
              if ( a3 >= 0 )
                result = sub_10169B10(v6, a2, a3 + 1, a4);
              else
                result = sub_10169B10(v6, a2, a3, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[stSilverTips]");
                if ( !result )
                {
                  v7 = this + 625;
                  if ( a3 >= 0 )
                    return sub_1016A540(v7, a2, a3 + 1, a4);
                  else
                    return sub_1016A540(v7, a2, a3, a4);
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
// Address Name: SUB_10167BB0
// ============================================================
//----- (10167BB0) --------------------------------------------------------
int __thiscall sub_10167BB0(int this, _DWORD *Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = Size;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 581) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
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
        if ( (v5[581] & 1) == 0 )
          *(_DWORD *)(v5 + 581) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 581) & 2) == 0 )
            *(_DWORD *)(v5 + 581) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10167210(&v16[29 * v9 + 1], (size_t)v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = (_DWORD *)v4[1];
            if ( v10 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v10 == (_DWORD *)((char *)Size + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x14u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101684B0
// ============================================================
//----- (101684B0) --------------------------------------------------------
int __thiscall sub_101684B0(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
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
        VarUInt = TdrBuf::ReadVarUInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
      }
      else
      {
        VarUInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUInt;
      if ( VarUInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101691E0
// ============================================================
//----- (101691E0) --------------------------------------------------------
int __thiscall sub_101691E0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016A260
// ============================================================
//----- (1016A260) --------------------------------------------------------
int __thiscall sub_1016A260(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
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
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadVarUInt(a2, this + 1);
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
// Address Name: SUB_10167D60
// ============================================================
//----- (10167D60) --------------------------------------------------------
int __thiscall sub_10167D60(int this, _DWORD *Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = Size;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 581) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
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
        if ( (v5[581] & 1) == 0 )
          *(_DWORD *)(v5 + 581) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 581) & 2) == 0 )
            *(_DWORD *)(v5 + 581) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10167350(&v16[29 * v9 + 1], (size_t)v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = (_DWORD *)v4[1];
            if ( v10 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v10 == (_DWORD *)((char *)Size + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x14u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016A350
// ============================================================
//----- (1016A350) --------------------------------------------------------
int __thiscall sub_1016A350(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
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
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 1);
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
// Address Name: SUB_10169610
// ============================================================
//----- (10169610) --------------------------------------------------------
int __thiscall sub_10169610(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10168550
// ============================================================
//----- (10168550) --------------------------------------------------------
int __thiscall sub_10168550(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10167FE0
// ============================================================
//----- (10167FE0) --------------------------------------------------------
int __thiscall sub_10167FE0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v10; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[nNumTabs]", "0x%02x", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this <= 0x14u )
    {
      v8 = 0;
      if ( v7 )
      {
        while ( 1 )
        {
          if ( !"[astTabs]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[astTabs]", v8, a4);
          if ( result )
            break;
          v10 = (int)(this + 29 * v8 + 1);
          if ( a3 >= 0 )
          {
            result = sub_1024A410(a2, a3 + 1, a4, "[strName]", (const char *)v10);
            if ( result )
              return result;
            result = print_field(a2, a3 + 1, a4, "[nChannelFlags]", "%u", *(_DWORD *)(v10 + 21));
          }
          else
          {
            result = sub_1024A410(a2, a3, a4, "[strName]", (const char *)v10);
            if ( result )
              return result;
            result = print_field(a2, a3, a4, "[nChannelFlags]", "%u", *(_DWORD *)(v10 + 21));
          }
          if ( result )
            break;
          if ( ++v8 >= *this )
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
// Address Name: SUB_1016A540
// ============================================================
//----- (1016A540) --------------------------------------------------------
int __thiscall sub_1016A540(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[tipsCheck]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101686F0
// ============================================================
//----- (101686F0) --------------------------------------------------------
int __thiscall sub_101686F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nFirstSettingData]", "%u", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[nSecondSettingData]", "%u", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10169B10
// ============================================================
//----- (10169B10) --------------------------------------------------------
int __thiscall sub_10169B10(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nBUTTON_UP]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[nBUTTON_LEFT]", "0x%02x", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[nBUTTON_DOWN]", "0x%02x", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[nBUTTON_RIGHT]", "0x%02x", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[nSTICK_LEFT_LEFT]", "0x%02x", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[nSTICK_LEFT_RIGHT]", "0x%02x", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[nSTICK_LEFT_UP]", "0x%02x", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[nSTICK_LEFT_DOWN]", "0x%02x", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[nSTICK_RIGHT_LEFT]", "0x%02x", *(this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[nSTICK_RIGHT_RIGHT]", "0x%02x", *(this + 9));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[nSTICK_RIGHT_UP]", "0x%02x", *(this + 10));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[nSTICK_RIGHT_DOWN]", "0x%02x", *(this + 11));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[nBUTTON_L2]", "0x%02x", *(this + 12));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[nBUTTON_R2]", "0x%02x", *(this + 13));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[nBUTTON_L1]", "0x%02x", *(this + 14));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[nBUTTON_R1]", "0x%02x", *(this + 15));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[nBUTTON_TRIANGLE]", "0x%02x", *(this + 16));
                                  if ( !result )
                                  {
                                    result = print_field(a2, a3, a4, "[nBUTTON_CIRCLE]", "0x%02x", *(this + 17));
                                    if ( !result )
                                    {
                                      result = print_field(a2, a3, a4, "[nBUTTON_CROSS]", "0x%02x", *(this + 18));
                                      if ( !result )
                                      {
                                        result = print_field(a2, a3, a4, "[nBUTTON_SQUARE]", "0x%02x", *(this + 19));
                                        if ( !result )
                                        {
                                          result = print_field(a2, a3, a4, "[nBUTTON_SELECT]", "0x%02x", *(this + 20));
                                          if ( !result )
                                          {
                                            result = print_field(a2, a3, a4, "[nBUTTON_START]", "0x%02x", *(this + 21));
                                            if ( !result )
                                            {
                                              result = print_field(a2, a3, a4, "[nBUTTON_L3]", "0x%02x", *(this + 22));
                                              if ( !result )
                                                return print_field(a2, a3, a4, "[nBUTTON_R3]", "0x%02x", *(this + 23));
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
// Address Name: SUB_10167210
// ============================================================
//----- (10167210) --------------------------------------------------------
int __thiscall sub_10167210(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 25) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 25) & 1) == 0 )
        *(_DWORD *)(this + 25) |= 1u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x15 )
        return -3;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9) = 0;
      v6 = a3;
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 25) & 2) == 0 )
        *(_DWORD *)(this + 25) |= 2u;
      result = TdrBuf::ReadVarUInt(v4, this + 21);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10167350
// ============================================================
//----- (10167350) --------------------------------------------------------
int __thiscall sub_10167350(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 25) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 25) & 1) == 0 )
        *(_DWORD *)(this + 25) |= 1u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x15 )
        return -3;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9) = 0;
      v6 = a3;
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 25) & 2) == 0 )
        *(_DWORD *)(this + 25) |= 2u;
      result = TdrBuf::ReadInt32(v4, this + 21);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
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



