// ============================================================
// Name: TLV::UnkTlv0273::Read
// Address Name: SUB_10230D10
// ============================================================
//----- (10230D10) --------------------------------------------------------
int __thiscall sub_10230D10(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10230DE0(this, (char *)&v9, v8);
  else
    result = sub_10230FC0((int)this, (char *)&v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0273::Read_0xAA
// Address Name: SUB_10230DE0
// ============================================================
//----- (10230DE0) --------------------------------------------------------
int __thiscall sub_10230DE0(int *this, char *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(this + 128) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v10 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_29:
    if ( *((_DWORD *)a2 + 1) > v5 )
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
      switch ( v8 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 128) & 1) == 0 )
            *(this + 128) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 128) & 2) == 0 )
            *(this + 128) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 128) & 4) == 0 )
            *(this + 128) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          VarInt = sub_1022D150((int)(this + 2), a2, v9);
          break;
        case 4u:
          if ( (*(this + 128) & 8) == 0 )
            *(this + 128) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          VarInt = sub_1022FA50((int)this + 15, a2, v9);
          break;
        case 5u:
          if ( (*(this + 128) & 0x10) == 0 )
            *(this + 128) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 126);
          break;
        case 6u:
          if ( (*(this + 128) & 0x20) == 0 )
            *(this + 128) |= 0x20u;
          VarInt = TdrBuf::ReadVarUInt(a2, this + 127);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
LABEL_28:
      v5 = v10;
      if ( *((_DWORD *)a2 + 1) >= v10 )
        goto LABEL_29;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0273::Read_0x99
// Address Name: SUB_10230FC0
// ============================================================
//----- (10230FC0) --------------------------------------------------------
int __thiscall sub_10230FC0(int this, char *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 512) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v10 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_29:
    if ( *((_DWORD *)a2 + 1) > v5 )
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
      switch ( v8 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 512) & 1) == 0 )
            *(_DWORD *)(this + 512) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 512) & 2) == 0 )
            *(_DWORD *)(this + 512) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 512) & 4) == 0 )
            *(_DWORD *)(this + 512) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          Int32 = sub_1022D240((char *)(this + 8), a2, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 512) & 8) == 0 )
            *(_DWORD *)(this + 512) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          Int32 = sub_1022FF30(this + 15, a2, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 512) & 0x10) == 0 )
            *(_DWORD *)(this + 512) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 504));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 512) & 0x20) == 0 )
            *(_DWORD *)(this + 512) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 508));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
LABEL_28:
      v5 = v10;
      if ( *((_DWORD *)a2 + 1) >= v10 )
        goto LABEL_29;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0273::DoDebugFormat
// Address Name: SUB_102311C0
// ============================================================
//----- (102311C0) --------------------------------------------------------
int __thiscall sub_102311C0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10231270(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0273::DebugFormat
// Address Name: SUB_10231270
// ============================================================
//----- (10231270) --------------------------------------------------------
int __thiscall sub_10231270(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  __int16 *v5; // ecx
  char *v6; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[relicPoint]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_structure((int)a2, a3, a4, (int)"[relicPrize]");
      if ( !result )
      {
        v5 = (__int16 *)(this + 2);
        result = a3 >= 0 ? sub_1022D470(v5, a2, a3 + 1, a4) : sub_1022D470(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[chess]");
          if ( !result )
          {
            v6 = (char *)this + 15;
            if ( a3 >= 0 )
              result = sub_102304E0(v6, a2, a3 + 1, a4);
            else
              result = sub_102304E0(v6, a2, a3, a4);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[activity]", "%d", *(this + 126));
              if ( !result )
                return print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 127));
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
// Address Name: SUB_1022D150
// ============================================================
//----- (1022D150) --------------------------------------------------------
int __thiscall sub_1022D150(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
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
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
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
// Address Name: SUB_1022FA50
// ============================================================
//----- (1022FA50) --------------------------------------------------------
int __thiscall sub_1022FA50(int this, char *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  char *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  unsigned int v21; // [esp+18h] [ebp-8h] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(_DWORD *)(this + 485) = 0;
  v21 = 0;
  v7 = *((_DWORD *)v6 + 1) + v3;
  v18 = v7;
  if ( *((_DWORD *)v6 + 1) >= v7 )
    goto LABEL_76;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 485) & 1) == 0 )
          *(_DWORD *)(v4 + 485) |= 1u;
        VarInt = sub_10115A30(v6, (_BYTE *)v4);
        goto LABEL_74;
      case 2u:
        if ( (*(_DWORD *)(v4 + 485) & 2) == 0 )
          *(_DWORD *)(v4 + 485) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022C890(v4 + 1, v6, a2);
        goto LABEL_74;
      case 3u:
        if ( (*(_DWORD *)(v4 + 485) & 4) == 0 )
          *(_DWORD *)(v4 + 485) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022D150(v4 + 156, v6, (int)a2);
        goto LABEL_74;
      case 4u:
        if ( (*(_DWORD *)(v4 + 485) & 8) == 0 )
          *(_DWORD *)(v4 + 485) |= 8u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022DA00(v4 + 163, v6, (int)a2);
        goto LABEL_74;
      case 5u:
        if ( (*(_DWORD *)(v4 + 485) & 0x10) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 245));
        goto LABEL_74;
      case 6u:
        if ( (*(_DWORD *)(v4 + 485) & 0x20) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 249));
        goto LABEL_74;
      case 7u:
        if ( (*(_DWORD *)(v4 + 485) & 0x40) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 253));
        goto LABEL_74;
      case 8u:
        if ( (*(_DWORD *)(v4 + 485) & 0x80) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x80u;
        VarInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 257));
        goto LABEL_74;
      case 9u:
        if ( (*(_DWORD *)(v4 + 485) & 0x100) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 261));
        goto LABEL_74;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 485) & 0x200) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = *((_DWORD *)v6 + 1);
        v11 = (int *)(v22 + 265);
        a3 = v22 + 265;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = *((_DWORD *)v6 + 1);
          if ( v12 > (unsigned int)&a2[v19] )
            return -34;
          if ( (char *)v12 == &a2[v19] )
            break;
          ++v10;
          v11 = (int *)(a3 + 4);
          a3 += 4;
          if ( v10 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 261) = v13;
        goto LABEL_75;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 485) & 0x400) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x400u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 305));
        goto LABEL_74;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 485) & 0x800) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = *((_DWORD *)v6 + 1);
        v15 = (int *)(v22 + 309);
        a3 = v22 + 309;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = *((_DWORD *)v6 + 1);
          if ( v16 > (unsigned int)&a2[v20] )
            return -34;
          if ( (char *)v16 == &a2[v20] )
            break;
          ++v14;
          v15 = (int *)(a3 + 4);
          a3 += 4;
          if ( v14 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 305) = v17;
LABEL_75:
        v7 = v18;
        if ( *((_DWORD *)v6 + 1) < v18 )
          continue;
LABEL_76:
        if ( *((_DWORD *)v6 + 1) > v7 )
          return -34;
        return v5;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 485) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x1000u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022EA10((int *)(v4 + 349), v6, (int *)a2);
LABEL_74:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_75;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 485) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x2000u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 477));
        goto LABEL_74;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 485) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x4000u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 481));
        goto LABEL_74;
      default:
        VarInt = TdrBuf::SkipField(v6, v21 & 0xF);
        goto LABEL_74;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022D240
// ============================================================
//----- (1022D240) --------------------------------------------------------
int __thiscall sub_1022D240(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022FF30
// ============================================================
//----- (1022FF30) --------------------------------------------------------
int __thiscall sub_1022FF30(int this, char *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  char *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  unsigned int v21; // [esp+18h] [ebp-8h] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(_DWORD *)(this + 485) = 0;
  v21 = 0;
  v7 = *((_DWORD *)v6 + 1) + v3;
  v18 = v7;
  if ( *((_DWORD *)v6 + 1) >= v7 )
    goto LABEL_76;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 485) & 1) == 0 )
          *(_DWORD *)(v4 + 485) |= 1u;
        Int32 = sub_10115A30(v6, (_BYTE *)v4);
        goto LABEL_74;
      case 2u:
        if ( (*(_DWORD *)(v4 + 485) & 2) == 0 )
          *(_DWORD *)(v4 + 485) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022CA50(v4 + 1, v6, a2);
        goto LABEL_74;
      case 3u:
        if ( (*(_DWORD *)(v4 + 485) & 4) == 0 )
          *(_DWORD *)(v4 + 485) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022D240((char *)(v4 + 156), v6, (int)a2);
        goto LABEL_74;
      case 4u:
        if ( (*(_DWORD *)(v4 + 485) & 8) == 0 )
          *(_DWORD *)(v4 + 485) |= 8u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022DBB0(v4 + 163, v6, a2);
        goto LABEL_74;
      case 5u:
        if ( (*(_DWORD *)(v4 + 485) & 0x10) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 245));
        goto LABEL_74;
      case 6u:
        if ( (*(_DWORD *)(v4 + 485) & 0x20) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 249));
        goto LABEL_74;
      case 7u:
        if ( (*(_DWORD *)(v4 + 485) & 0x40) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 253));
        goto LABEL_74;
      case 8u:
        if ( (*(_DWORD *)(v4 + 485) & 0x80) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 257));
        goto LABEL_74;
      case 9u:
        if ( (*(_DWORD *)(v4 + 485) & 0x100) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 261));
        goto LABEL_74;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 485) & 0x200) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = *((_DWORD *)v6 + 1);
        v11 = (_BYTE *)(v22 + 265);
        a3 = v22 + 265;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = *((_DWORD *)v6 + 1);
          if ( v12 > (unsigned int)&a2[v19] )
            return -34;
          if ( (char *)v12 == &a2[v19] )
            break;
          ++v10;
          v11 = (_BYTE *)(a3 + 4);
          a3 += 4;
          if ( v10 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 261) = v13;
        goto LABEL_75;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 485) & 0x400) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x400u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 305));
        goto LABEL_74;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 485) & 0x800) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = *((_DWORD *)v6 + 1);
        v15 = (_BYTE *)(v22 + 309);
        a3 = v22 + 309;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = *((_DWORD *)v6 + 1);
          if ( v16 > (unsigned int)&a2[v20] )
            return -34;
          if ( (char *)v16 == &a2[v20] )
            break;
          ++v14;
          v15 = (_BYTE *)(a3 + 4);
          a3 += 4;
          if ( v14 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 305) = v17;
LABEL_75:
        v7 = v18;
        if ( *((_DWORD *)v6 + 1) < v18 )
          continue;
LABEL_76:
        if ( *((_DWORD *)v6 + 1) > v7 )
          return -34;
        return v5;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 485) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x1000u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022EB70((_DWORD *)(v4 + 349), v6, (int)a2);
LABEL_74:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_75;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 485) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 477));
        goto LABEL_74;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 485) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 481));
        goto LABEL_74;
      default:
        Int32 = TdrBuf::SkipField(v6, v21 & 0xF);
        goto LABEL_74;
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
// Address Name: SUB_102304E0
// ============================================================
//----- (102304E0) --------------------------------------------------------
int __thiscall sub_102304E0(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  char *v8; // ecx
  __int16 *v9; // ecx
  char *v10; // ecx
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // eax
  _DWORD *v16; // ecx
  int *v17; // ecx
  int v18; // [esp+14h] [ebp+8h]
  int v19; // [esp+14h] [ebp+8h]
  int v20; // [esp+18h] [ebp+Ch]
  int v21; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[hitCount]", "0x%02x", *this);
  if ( !result )
  {
    if ( !"[pieces]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[pieces]", (char)a4);
      if ( !result )
      {
        v8 = this + 1;
        result = a3 >= 0 ? sub_1022CCE0(v8, a2, a3 + 1, a4) : sub_1022CCE0(v8, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[ultimatePrize]");
          if ( !result )
          {
            v9 = (__int16 *)(this + 156);
            result = a3 >= 0 ? sub_1022D470(v9, a2, a3 + 1, a4) : sub_1022D470(v9, a2, a3, a4);
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[piecePrizes]");
              if ( !result )
              {
                v10 = this + 163;
                result = a3 >= 0 ? sub_1022DE30(v10, a2, a3 + 1, a4) : sub_1022DE30(v10, a2, a3, a4);
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[blackFaceCount]", "%d", *(_DWORD *)(this + 245));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[iFHasSSR]", "%d", *(_DWORD *)(this + 249));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[dragonShopID]", "%d", *(_DWORD *)(this + 253));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[dragonShopEndTime]", "%u", *(_DWORD *)(this + 257));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[freshNumBitCount]", "%d", *(_DWORD *)(this + 261));
                          if ( !result )
                          {
                            v12 = *(_DWORD *)(this + 261);
                            if ( v12 < 0 )
                              return -6;
                            if ( v12 > 10 )
                              return -7;
                            result = sub_1024A3B0(a2, a3, v11, "[freshNumBit]", v12);
                            if ( !result )
                            {
                              v20 = 0;
                              if ( *(int *)(this + 261) <= 0 )
                              {
LABEL_34:
                                result = TdrBuf::WriteChar(a2, a4);
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[freshNumTenCount]", "%d", *(_DWORD *)(this + 305));
                                  if ( !result )
                                  {
                                    v15 = *(_DWORD *)(this + 305);
                                    if ( v15 < 0 )
                                      return -6;
                                    if ( v15 > 10 )
                                      return -7;
                                    result = sub_1024A3B0(a2, a3, v14, "[freshNumTen]", v15);
                                    if ( !result )
                                    {
                                      v21 = 0;
                                      if ( *(int *)(this + 305) <= 0 )
                                      {
LABEL_43:
                                        result = TdrBuf::WriteChar(a2, a4);
                                        if ( !result )
                                        {
                                          result = print_structure((int)a2, a3, a4, (int)"[dragonBoxShopItems]");
                                          if ( !result )
                                          {
                                            v17 = (int *)(this + 349);
                                            if ( a3 >= 0 )
                                              result = sub_1022EDA0(v17, a2, a3 + 1, a4);
                                            else
                                              result = sub_1022EDA0(v17, a2, a3, a4);
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[freshNumCnt]",
                                                         "%d",
                                                         *(_DWORD *)(this + 477));
                                              if ( !result )
                                                return print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[fetchState]",
                                                         "%d",
                                                         *(_DWORD *)(this + 481));
                                            }
                                          }
                                        }
                                      }
                                      else
                                      {
                                        v16 = this + 309;
                                        v19 = (int)(this + 309);
                                        while ( 1 )
                                        {
                                          result = Printf(a2, " %d", *v16);
                                          if ( result )
                                            break;
                                          v16 = (_DWORD *)(v19 + 4);
                                          ++v21;
                                          v19 += 4;
                                          if ( v21 >= *(_DWORD *)(this + 305) )
                                            goto LABEL_43;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else
                              {
                                v13 = this + 265;
                                v18 = (int)(this + 265);
                                while ( 1 )
                                {
                                  result = Printf(a2, " %d", *v13);
                                  if ( result )
                                    break;
                                  v13 = (_DWORD *)(v18 + 4);
                                  ++v20;
                                  v18 += 4;
                                  if ( v20 >= *(_DWORD *)(this + 261) )
                                    goto LABEL_34;
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
// 102306EC: variable 'v11' is possibly undefined
// 1023079B: variable 'v14' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022D470
// ============================================================
//----- (1022D470) --------------------------------------------------------
int __thiscall sub_1022D470(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[state]", "0x%02x", *((char *)this + 2));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022DA00
// ============================================================
//----- (1022DA00) --------------------------------------------------------
int __thiscall sub_1022DA00(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 78) = 0;
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
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v5[78] & 1) == 0 )
          *(_DWORD *)(v5 + 78) |= 1u;
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
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 78) & 2) == 0 )
            *(_DWORD *)(v5 + 78) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022D150(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 7;
            if ( ++v9 >= 11 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
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
// Address Name: SUB_1022EA10
// ============================================================
//----- (1022EA10) --------------------------------------------------------
int __thiscall sub_1022EA10(int *this, _DWORD *a2, int *a3)
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
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 31) = 0;
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
        if ( (v4[31] & 1) == 0 )
          v4[31] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[31] & 2) == 0 )
            v4[31] |= 2u;
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
              v5 = sub_1022E2B0(a3, v6, v15);
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
            a3 += 3;
            if ( ++v10 >= 10 )
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
// Address Name: SUB_1022C890
// ============================================================
//----- (1022C890) --------------------------------------------------------
int __thiscall sub_1022C890(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 151) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
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
        if ( (v5[151] & 1) == 0 )
          *(_DWORD *)(v5 + 151) |= 1u;
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
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 151) & 2) == 0 )
            *(_DWORD *)(v5 + 151) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022BFD0(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 6;
            if ( ++v9 >= 25 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
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
// Address Name: SUB_1022DBB0
// ============================================================
//----- (1022DBB0) --------------------------------------------------------
int __thiscall sub_1022DBB0(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 78) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
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
        if ( (v5[78] & 1) == 0 )
          *(_DWORD *)(v5 + 78) |= 1u;
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
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 78) & 2) == 0 )
            *(_DWORD *)(v5 + 78) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022D240(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 7;
            if ( ++v9 >= 11 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022CA50
// ============================================================
//----- (1022CA50) --------------------------------------------------------
int __thiscall sub_1022CA50(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 151) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
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
        if ( (v5[151] & 1) == 0 )
          *(_DWORD *)(v5 + 151) |= 1u;
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
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 151) & 2) == 0 )
            *(_DWORD *)(v5 + 151) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022C0F0(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 6;
            if ( ++v9 >= 25 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022EB70
// ============================================================
//----- (1022EB70) --------------------------------------------------------
int __thiscall sub_1022EB70(_DWORD *this, _DWORD *a2, int a3)
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
  *(this + 31) = 0;
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
        if ( (v4[31] & 1) == 0 )
          v4[31] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[31] & 2) == 0 )
            v4[31] |= 2u;
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
              v5 = sub_1022E350(a3, v6, v15);
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
            a3 += 12;
            if ( ++v10 >= 10 )
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
// Address Name: SUB_1022CCE0
// ============================================================
//----- (1022CCE0) --------------------------------------------------------
int __thiscall sub_1022CCE0(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char v6; // al
  int v7; // esi
  char *i; // ebx

  result = print_field(a2, a3, a4, "[count]", "0x%02x", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 25 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 6 )
          {
            if ( !"[pieces]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[pieces]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022C310(i, a2, a3 + 1, a4) : sub_1022C310(i, a2, a3, a4);
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
// Address Name: SUB_1022EDA0
// ============================================================
//----- (1022EDA0) --------------------------------------------------------
int __thiscall sub_1022EDA0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

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
          for ( i = this + 1; ; i += 3 )
          {
            if ( !"[dragonBoxShopItems]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[dragonBoxShopItems]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022E4F0(i, a2, a3 + 1, a4) : sub_1022E4F0(i, a2, a3, a4);
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
// Address Name: SUB_1022DE30
// ============================================================
//----- (1022DE30) --------------------------------------------------------
int __thiscall sub_1022DE30(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char v6; // al
  int v7; // esi
  __int16 *i; // ebx

  result = print_field(a2, a3, a4, "[count]", "0x%02x", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 11 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (__int16 *)(this + 1); ; i = (__int16 *)((char *)i + 7) )
          {
            if ( !"[piecePrizes]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[piecePrizes]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022D470(i, a2, a3 + 1, a4) : sub_1022D470(i, a2, a3, a4);
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
// Address Name: SUB_1022E2B0
// ============================================================
//----- (1022E2B0) --------------------------------------------------------
int __thiscall sub_1022E2B0(int *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1022BFD0
// ============================================================
//----- (1022BFD0) --------------------------------------------------------
int __thiscall sub_1022BFD0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022C0F0
// ============================================================
//----- (1022C0F0) --------------------------------------------------------
int __thiscall sub_1022C0F0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022E350
// ============================================================
//----- (1022E350) --------------------------------------------------------
int __thiscall sub_1022E350(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1022C310
// ============================================================
//----- (1022C310) --------------------------------------------------------
int __thiscall sub_1022C310(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[val]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[hit]", "0x%02x", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022E4F0
// ============================================================
//----- (1022E4F0) --------------------------------------------------------
int __thiscall sub_1022E4F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[thisID]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[buyTimes]", "%d", *(this + 1));
  return result;
}



