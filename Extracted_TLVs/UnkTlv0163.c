// ============================================================
// Name: TLV::UnkTlv0163::Read
// Address Name: SUB_1018F610
// ============================================================
//----- (1018F610) --------------------------------------------------------
int __thiscall sub_1018F610(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1018F6E0(this, &v9, v8);
  else
    result = sub_1018F920(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0163::Read_0xAA
// Address Name: SUB_1018F6E0
// ============================================================
//----- (1018F6E0) --------------------------------------------------------
int __thiscall sub_1018F6E0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int *v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 378) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 378) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 2) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 2u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = v13 + 1;
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1018ED90((int)v12, a2, (int)v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 = (_DWORD *)((char *)v12 + 13);
          if ( ++v8 >= 8 )
          {
            v3 = v13;
            goto LABEL_33;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *v13 = v10;
LABEL_33:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_34:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 3u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 4) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 4u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3 + 108);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 8) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 8u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3 + 109);
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 0x10) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 0x10u;
        v15 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v15);
        if ( v4 )
          return v4;
        if ( !v15 )
          goto LABEL_33;
        VarInt = sub_1018E340((_DWORD *)((char *)v3 + 110), a2, v15);
LABEL_32:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_33;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v14 & 0xF);
        goto LABEL_32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0163::Read_0x99
// Address Name: SUB_1018F920
// ============================================================
//----- (1018F920) --------------------------------------------------------
int __thiscall sub_1018F920(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 378) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 378) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 2) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 2u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = v13 + 1;
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1018EE90((int)v12, a2, v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 = (_DWORD *)((char *)v12 + 13);
          if ( ++v8 >= 8 )
          {
            v3 = v13;
            goto LABEL_33;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *v13 = v10;
LABEL_33:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_34:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 3u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 4) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 4u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3 + 108);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 8) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 8u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3 + 109);
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 0x10) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 0x10u;
        v15 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v15);
        if ( v4 )
          return v4;
        if ( !v15 )
          goto LABEL_33;
        Int32 = sub_1018E580((_DWORD *)((char *)v3 + 110), a2, v15);
LABEL_32:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_33;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v14 & 0xF);
        goto LABEL_32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0163::DoDebugFormat
// Address Name: SUB_1018FB80
// ============================================================
//----- (1018FB80) --------------------------------------------------------
int __thiscall sub_1018FB80(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1018FC30(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0163::DebugFormat
// Address Name: SUB_1018FC30
// ============================================================
//----- (1018FC30) --------------------------------------------------------
int __thiscall sub_1018FC30(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v7; // eax
  int v8; // ebx
  bool v9; // cc
  int *v10; // eax
  int *v11; // ecx
  _DWORD *v13; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[guideBookChapterCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 8 )
      {
        v8 = 0;
        v9 = v7 <= 0;
        v10 = this;
        if ( v9 )
        {
LABEL_17:
          result = print_field(a2, a3, a4, "[isFisrtAutoOpenGuideBook]", "0x%02x", *((char *)v10 + 108));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[weaopnId]", "0x%02x", *((char *)this + 109));
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[guideActionInfos]");
              if ( !result )
              {
                v11 = (int *)((char *)this + 110);
                if ( a3 >= 0 )
                  return sub_1018E890(v11, a2, a3 + 1, a4);
                else
                  return sub_1018E890(v11, a2, a3, a4);
              }
            }
          }
        }
        else
        {
          v13 = this + 1;
          while ( 1 )
          {
            if ( !"[guideBookChapterInfos]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guideBookChapterInfos]", v8, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1018F060(v13, a2, a3 + 1, a4) : sub_1018F060(v13, a2, a3, a4);
            if ( result )
              break;
            v10 = this;
            ++v8;
            v13 = (_DWORD *)((char *)v13 + 13);
            if ( v8 >= *this )
              goto LABEL_17;
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
// Address Name: SUB_1018E340
// ============================================================
//----- (1018E340) --------------------------------------------------------
int __thiscall sub_1018E340(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  char *v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v20 = this;
  *(this + 66) = 0;
  v19 = 0;
  v7 = (char *)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v4[66] & 1) == 0 )
          v4[66] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_35;
      case 2u:
        if ( (v4[66] & 2) == 0 )
          v4[66] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (int *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v20 + v10 + 4);
          if ( v5 )
            return v5;
          v11 = v6[1];
          if ( (_DWORD *)v11 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          if ( ++v10 >= 160 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v12 = v10 + 1;
        v4 = v20;
        *v20 = v12;
        goto LABEL_36;
      case 3u:
        if ( (v4[66] & 4) == 0 )
          v4[66] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 41);
        goto LABEL_35;
      case 4u:
        if ( (v4[66] & 8) == 0 )
          v4[66] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v17 = v6[1];
        a3 = v20 + 42;
        while ( 1 )
        {
          v18 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v18);
          if ( v5 )
            return v5;
          if ( v18 )
          {
            v5 = sub_1018DA20(a3, v6, v18);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 += 3;
          if ( ++v13 >= 8 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v15 = v13 + 1;
        v4 = v20;
        v20[41] = v15;
LABEL_36:
        v7 = v16;
        if ( v6[1] < (unsigned int)v16 )
          continue;
LABEL_37:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_35:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_36;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018ED90
// ============================================================
//----- (1018ED90) --------------------------------------------------------
int __thiscall sub_1018ED90(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
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
      if ( v9 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 9) & 2) == 0 )
          *(_DWORD *)(this + 9) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(this + 4));
        goto LABEL_19;
      }
      if ( v9 >> 4 != 3 )
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 8) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
LABEL_19:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018EE90
// ============================================================
//----- (1018EE90) --------------------------------------------------------
int __thiscall sub_1018EE90(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
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
      if ( v9 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 9) & 2) == 0 )
          *(_DWORD *)(this + 9) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
        goto LABEL_19;
      }
      if ( v9 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 8) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_19:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018E580
// ============================================================
//----- (1018E580) --------------------------------------------------------
int __thiscall sub_1018E580(_DWORD *this, _DWORD *a2, int a3)
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
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v20 = this;
  *(this + 66) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v4[66] & 1) == 0 )
          v4[66] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_35;
      case 2u:
        if ( (v4[66] & 2) == 0 )
          v4[66] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v20 + v10 + 4);
          if ( v5 )
            return v5;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 160 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v12 = v10 + 1;
        v4 = v20;
        *v20 = v12;
        goto LABEL_36;
      case 3u:
        if ( (v4[66] & 4) == 0 )
          v4[66] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 164);
        goto LABEL_35;
      case 4u:
        if ( (v4[66] & 8) == 0 )
          v4[66] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v17 = v6[1];
        a3 = (int)(v20 + 42);
        while ( 1 )
        {
          v18 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v18);
          if ( v5 )
            return v5;
          if ( v18 )
          {
            v5 = sub_1018DAC0(a3, v6, v18);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 += 12;
          if ( ++v13 >= 8 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v15 = v13 + 1;
        v4 = v20;
        v20[41] = v15;
LABEL_36:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_37:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_35:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_36;
        return v5;
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
// Address Name: SUB_1018E890
// ============================================================
//----- (1018E890) --------------------------------------------------------
int __thiscall sub_1018E890(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  _DWORD *i; // edi
  int v12; // eax

  result = print_field(a2, a3, a4, "[finishActionBitTagCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 160 )
      return -7;
    result = sub_1024A3B0(a2, a3, v6, "[finishActionBitTag]", v7);
    if ( !result )
    {
      v8 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[actionStepInfoCount]", "%d", *(this + 41));
          if ( !result )
          {
            v9 = *(this + 41);
            if ( v9 < 0 )
              return -6;
            if ( v9 > 8 )
              return -7;
            v10 = 0;
            if ( v9 <= 0 )
            {
              return 0;
            }
            else
            {
              for ( i = this + 42; ; i += 3 )
              {
                result = sub_1024A230(a2, a3, a4, "[actionStepInfos]", v10);
                if ( result )
                  break;
                v12 = a3;
                if ( a3 >= 0 )
                  v12 = a3 + 1;
                result = sub_1018DC60(i, a2, v12, a4);
                if ( result )
                  break;
                if ( ++v10 >= *(this + 41) )
                  return 0;
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((char *)this + v8 + 4));
          if ( result )
            break;
          if ( ++v8 >= *this )
            goto LABEL_10;
        }
      }
    }
  }
  return result;
}
// 1018E8F1: variable 'v6' is possibly undefined



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
// Address Name: SUB_1018F060
// ============================================================
//----- (1018F060) --------------------------------------------------------
int __thiscall sub_1018F060(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[chapterId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[getRewardCount]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[isNotNew]", "0x%02x", *((char *)this + 8));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018DA20
// ============================================================
//----- (1018DA20) --------------------------------------------------------
int __thiscall sub_1018DA20(int *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1018DAC0
// ============================================================
//----- (1018DAC0) --------------------------------------------------------
int __thiscall sub_1018DAC0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1018DC60
// ============================================================
//----- (1018DC60) --------------------------------------------------------
int __thiscall sub_1018DC60(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[actionId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[steps]", "%d", *(this + 1));
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



