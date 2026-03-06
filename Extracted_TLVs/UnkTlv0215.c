// ============================================================
// Name: TLV::UnkTlv0215::Read_0xAA
// Address Name: SUB_10202280
// ============================================================
//----- (10202280) --------------------------------------------------------
int __thiscall sub_10202280(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  unsigned int v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  unsigned int v16; // [esp+18h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 1448) = 0;
  v15 = this;
  v7 = v6[1] + v5;
  v16 = 0;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_38:
    if ( v6[1] > v7 )
      return -34;
    return result;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    if ( v16 >> 4 == 1 )
      break;
    if ( v16 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 1448) & 2) == 0 )
        *(_DWORD *)(this + 1448) |= 2u;
      result = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 216));
      if ( result )
        return result;
    }
    else
    {
      if ( v16 >> 4 == 3 )
      {
        if ( (*(_DWORD *)(this + 1448) & 4) == 0 )
          *(_DWORD *)(this + 1448) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v8 = 0;
          v13 = v6[1];
          while ( 1 )
          {
            a3 = 0;
            result = TdrBuf::ReadInt32(v6, &a3);
            if ( result )
              return result;
            if ( a3 )
            {
              result = sub_102009C0(this + 41 * v8 + 218, v6, a3);
              if ( result )
                return result;
            }
            v9 = v6[1];
            if ( v9 > (unsigned int)a2 + v13 )
              return -34;
            if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + v13) )
            {
              *(_WORD *)(this + 216) = v8 + 1;
              goto LABEL_37;
            }
            if ( ++v8 >= 30 )
              goto LABEL_37;
          }
        }
        return -37;
      }
      result = TdrBuf::SkipField(v6, v16 & 0xF);
      if ( result )
        return result;
    }
LABEL_37:
    v7 = v12;
    if ( v6[1] >= v12 )
      goto LABEL_38;
  }
  if ( (*(_BYTE *)(this + 1448) & 1) == 0 )
    *(_DWORD *)(this + 1448) |= 1u;
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
      result = sub_10201550((int *)this, v6, a3);
      if ( result )
        return result;
    }
    v11 = v6[1];
    if ( v11 > (unsigned int)a2 + v14 )
      return -34;
    if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v14) )
    {
      ++v10;
      this += 36;
      if ( v10 < 6 )
        continue;
    }
    this = v15;
    goto LABEL_37;
  }
}



// ============================================================
// Name: TLV::UnkTlv0215::Read_0x99
// Address Name: SUB_102024A0
// ============================================================
//----- (102024A0) --------------------------------------------------------
int __thiscall sub_102024A0(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  unsigned int v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+14h] [ebp-8h]
  unsigned int v16; // [esp+18h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 1448) = 0;
  v15 = this;
  v7 = v6[1] + v5;
  v16 = 0;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_38:
    if ( v6[1] > v7 )
      return -34;
    return result;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    if ( v16 >> 4 == 1 )
      break;
    if ( v16 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 1448) & 2) == 0 )
        *(_DWORD *)(this + 1448) |= 2u;
      result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 216));
      if ( result )
        return result;
    }
    else
    {
      if ( v16 >> 4 == 3 )
      {
        if ( (*(_DWORD *)(this + 1448) & 4) == 0 )
          *(_DWORD *)(this + 1448) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v8 = 0;
          v13 = v6[1];
          while ( 1 )
          {
            a3 = 0;
            result = TdrBuf::ReadInt32(v6, &a3);
            if ( result )
              return result;
            if ( a3 )
            {
              result = sub_10200B70(this + 41 * v8 + 218, v6, a3);
              if ( result )
                return result;
            }
            v9 = v6[1];
            if ( v9 > (unsigned int)a2 + v13 )
              return -34;
            if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + v13) )
            {
              *(_WORD *)(this + 216) = v8 + 1;
              goto LABEL_37;
            }
            if ( ++v8 >= 30 )
              goto LABEL_37;
          }
        }
        return -37;
      }
      result = TdrBuf::SkipField(v6, v16 & 0xF);
      if ( result )
        return result;
    }
LABEL_37:
    v7 = v12;
    if ( v6[1] >= v12 )
      goto LABEL_38;
  }
  if ( (*(_BYTE *)(this + 1448) & 1) == 0 )
    *(_DWORD *)(this + 1448) |= 1u;
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
      result = sub_102016C0((_DWORD *)this, v6, a3);
      if ( result )
        return result;
    }
    v11 = v6[1];
    if ( v11 > (unsigned int)a2 + v14 )
      return -34;
    if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v14) )
    {
      ++v10;
      this += 36;
      if ( v10 < 6 )
        continue;
    }
    this = v15;
    goto LABEL_37;
  }
}



// ============================================================
// Name: TLV::UnkTlv0215::DoDebugFormat
// Address Name: SUB_102026E0
// ============================================================
//----- (102026E0) --------------------------------------------------------
int __thiscall sub_102026E0(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10202790(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0215::DebugFormat
// Address Name: SUB_10202790
// ============================================================
//----- (10202790) --------------------------------------------------------
int __thiscall sub_10202790(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int v4; // ebx
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  __int16 *v9; // [esp+10h] [ebp-4h]

  v4 = 0;
  v9 = this;
  while ( 1 )
  {
    if ( !"[sPFData]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      break;
    result = Printf(a2, "%s[%u]%c", "[sPFData]", v4, a4);
    if ( result )
      break;
    result = a3 >= 0 ? sub_10201900(v9, a2, a3 + 1, a4) : sub_10201900(v9, a2, a3, a4);
    if ( result )
      break;
    v9 += 18;
    if ( (unsigned int)++v4 >= 6 )
    {
      result = print_field(a2, a3, a4, "[petAvatarCount]", "%d", *(this + 108));
      if ( !result )
      {
        v6 = *(this + 108);
        if ( v6 >= 0 )
        {
          if ( v6 <= 30 )
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
                if ( !"[petAvatarInfo]" )
                  _wassert(
                    L"NULL != variable",
                    L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                    0x43u);
                result = sub_1024A140(a3);
                if ( result )
                  break;
                result = Printf(a2, "%s[%u]%c", "[petAvatarInfo]", v7, a4);
                if ( result )
                  break;
                result = a3 >= 0
                       ? sub_10200DF0((__int16 *)((char *)this + 41 * v7 + 218), a2, a3 + 1, a4)
                       : sub_10200DF0((__int16 *)((char *)this + 41 * v7 + 218), a2, a3, a4);
                if ( result )
                  break;
                if ( ++v7 >= *(this + 108) )
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
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10201550
// ============================================================
//----- (10201550) --------------------------------------------------------
int __thiscall sub_10201550(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  bool v6; // cf
  int result; // eax
  unsigned int v8; // edi
  int *v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  int *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v15 = this;
  v14 = 0;
  *(this + 8) = 0;
  v13 = v4[1] + v3;
  v6 = v13 < v4[1];
  if ( v13 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    if ( v14 >> 4 == 1 )
      break;
    if ( v14 >> 4 == 2 )
    {
      if ( (v5[8] & 2) == 0 )
        v5[8] |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v8 = 0;
        a3 = v4[1];
        v9 = v5 + 4;
        while ( 1 )
        {
          result = TdrBuf::ReadVarInt(v4, v9);
          if ( result )
            return result;
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v8;
            ++v9;
            if ( v8 < 4 )
              continue;
          }
          goto LABEL_26;
        }
      }
      return -37;
    }
    result = TdrBuf::SkipField(v4, v14 & 0xF);
    if ( result )
      return result;
LABEL_27:
    if ( v4[1] >= v13 )
    {
      v6 = v13 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  if ( (v5[8] & 1) == 0 )
    v5[8] |= 1u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( result )
    return result;
  if ( !a2 )
    return -37;
  v11 = 0;
  a3 = v4[1];
  while ( 1 )
  {
    result = TdrBuf::ReadVarInt(v4, v5);
    if ( result )
      return result;
    v12 = v4[1];
    if ( v12 > (unsigned int)a2 + a3 )
      return -34;
    if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
    {
      ++v11;
      ++v5;
      if ( v11 < 4 )
        continue;
    }
LABEL_26:
    v5 = v15;
    goto LABEL_27;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102009C0
// ============================================================
//----- (102009C0) --------------------------------------------------------
int __thiscall sub_102009C0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // edi
  int *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 37) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 37) & 1) == 0 )
          *(_DWORD *)(v5 + 37) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 37) & 2) == 0 )
          *(_DWORD *)(v5 + 37) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_7;
      case 3u:
        if ( (*(_DWORD *)(v5 + 37) & 4) == 0 )
          *(_DWORD *)(v5 + 37) |= 4u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v10 = 0;
          v15 = v4[1];
          v11 = (int *)(v17 + 8);
          v12 = a2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadVarInt(v12, v11);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v15 )
              break;
            if ( v13 != a3 + v15 )
            {
              ++v10;
              ++v11;
              if ( v10 < 6 )
                continue;
            }
            v5 = v17;
            v4 = a2;
LABEL_22:
            v7 = v14;
            if ( v4[1] >= v14 )
              goto LABEL_23;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 4u:
        if ( (*(_DWORD *)(v5 + 37) & 8) == 0 )
          *(_DWORD *)(v5 + 37) |= 8u;
        VarInt = sub_10115A30(v4, (_BYTE *)(v5 + 32));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 37) & 0x10) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 33));
        goto LABEL_7;
      default:
        VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_7:
        v6 = VarInt;
        if ( !VarInt )
          goto LABEL_22;
        return v6;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102016C0
// ============================================================
//----- (102016C0) --------------------------------------------------------
int __thiscall sub_102016C0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  bool v6; // cf
  int result; // eax
  unsigned int v8; // edi
  _BYTE *v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v15 = this;
  v14 = 0;
  *(this + 8) = 0;
  v13 = v4[1] + v3;
  v6 = v13 < v4[1];
  if ( v13 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    if ( v14 >> 4 == 1 )
      break;
    if ( v14 >> 4 == 2 )
    {
      if ( (v5[8] & 2) == 0 )
        v5[8] |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v8 = 0;
        a3 = v4[1];
        v9 = v5 + 4;
        while ( 1 )
        {
          result = TdrBuf::ReadInt32(v4, v9);
          if ( result )
            return result;
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v8;
            v9 += 4;
            if ( v8 < 4 )
              continue;
          }
          goto LABEL_26;
        }
      }
      return -37;
    }
    result = TdrBuf::SkipField(v4, v14 & 0xF);
    if ( result )
      return result;
LABEL_27:
    if ( v4[1] >= v13 )
    {
      v6 = v13 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  if ( (v5[8] & 1) == 0 )
    v5[8] |= 1u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( result )
    return result;
  if ( !a2 )
    return -37;
  v11 = 0;
  a3 = v4[1];
  while ( 1 )
  {
    result = TdrBuf::ReadInt32(v4, v5);
    if ( result )
      return result;
    v12 = v4[1];
    if ( v12 > (unsigned int)a2 + a3 )
      return -34;
    if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
    {
      ++v11;
      ++v5;
      if ( v11 < 4 )
        continue;
    }
LABEL_26:
    v5 = v15;
    goto LABEL_27;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10200B70
// ============================================================
//----- (10200B70) --------------------------------------------------------
int __thiscall sub_10200B70(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // edi
  _BYTE *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 37) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 37) & 1) == 0 )
          *(_DWORD *)(v5 + 37) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 37) & 2) == 0 )
          *(_DWORD *)(v5 + 37) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_7;
      case 3u:
        if ( (*(_DWORD *)(v5 + 37) & 4) == 0 )
          *(_DWORD *)(v5 + 37) |= 4u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v10 = 0;
          v15 = v4[1];
          v11 = (_BYTE *)(v17 + 8);
          v12 = a2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadInt32(v12, v11);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v15 )
              break;
            if ( v13 != a3 + v15 )
            {
              ++v10;
              v11 += 4;
              if ( v10 < 6 )
                continue;
            }
            v5 = v17;
            v4 = a2;
LABEL_22:
            v7 = v14;
            if ( v4[1] >= v14 )
              goto LABEL_23;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 4u:
        if ( (*(_DWORD *)(v5 + 37) & 8) == 0 )
          *(_DWORD *)(v5 + 37) |= 8u;
        Int32 = sub_10115A30(v4, (_BYTE *)(v5 + 32));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 37) & 0x10) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 33));
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_7:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_22;
        return v6;
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
// Address Name: SUB_10200DF0
// ============================================================
//----- (10200DF0) --------------------------------------------------------
int __thiscall sub_10200DF0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[petID]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[skinID]", "%d", *(this + 1));
    if ( !result )
    {
      result = sub_1024A3B0(a2, a3, v6, "[avatarInfo]", 6);
      if ( !result )
      {
        v7 = 0;
        for ( i = this + 2; ; ++i )
        {
          result = Printf(a2, " %d", *i);
          if ( result )
            break;
          if ( (unsigned int)++v7 >= 6 )
          {
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[sex]", "0x%02x", *((char *)this + 32));
              if ( !result )
                return print_field(a2, a3, a4, "[slot]", "%d", *(_DWORD *)((char *)this + 33));
            }
            return result;
          }
        }
      }
    }
  }
  return result;
}
// 10200E53: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10201900
// ============================================================
//----- (10201900) --------------------------------------------------------
int __thiscall sub_10201900(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edi
  _DWORD *i; // ebx
  int v10; // ecx

  if ( !"[petID]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[petID]", 3LL);
    if ( !result )
    {
      v6 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(this + v6));
        if ( result )
          break;
        if ( (unsigned int)++v6 >= 4 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v7 = a2[1];
          if ( (unsigned int)(a2[2] - v7) < 2 )
            return -1;
          *(_BYTE *)(v7 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          if ( !"[startTime]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x9Du);
          result = sub_1024A140(a3);
          if ( !result )
          {
            result = Printf(a2, "%s[0 : %I64i]:", "[startTime]", 3LL);
            if ( !result )
            {
              v8 = 0;
              for ( i = this + 4; ; ++i )
              {
                result = Printf(a2, " %d", *i);
                if ( result )
                  break;
                if ( (unsigned int)++v8 >= 4 )
                {
                  if ( a2[1] > a2[2] )
                    _wassert(
                      L"position <= length",
                      L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                      0xC4u);
                  v10 = a2[1];
                  if ( (unsigned int)(a2[2] - v10) >= 2 )
                  {
                    *(_BYTE *)(v10 + *a2) = a4;
                    *(_BYTE *)(++a2[1] + *a2) = 0;
                    return 0;
                  }
                  return -1;
                }
              }
            }
          }
          return result;
        }
      }
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



