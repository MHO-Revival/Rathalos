// ============================================================
// Name: TLV::UnkTlv0261::Read_0xAA
// Address Name: SUB_102287C0
// ============================================================
//----- (102287C0) --------------------------------------------------------
int __thiscall sub_102287C0(_DWORD *this, int a2, unsigned int i)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int v9; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = i;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(this + 4213) = 0;
  v7 = v4[1] + v3;
  for ( i = v7; v4[1] < i; v7 = i )
  {
    result = TdrBuf::ReadVarUInt(v4, &v10);
    if ( result )
      return result;
    if ( v10 >> 4 == 1 )
    {
      if ( (*(_BYTE *)(this + 4213) & 1) == 0 )
        *(this + 4213) |= 1u;
      a2 = 0;
      v6 = TdrBuf::ReadInt32(v4, &a2);
      if ( v6 )
        return v6;
      if ( a2 )
      {
        v9 = sub_10226C30(this, v4, a2);
LABEL_16:
        v6 = v9;
        if ( v9 )
          return v6;
      }
    }
    else
    {
      if ( v10 >> 4 != 2 )
      {
        v9 = TdrBuf::SkipField(v4, v10 & 0xF);
        goto LABEL_16;
      }
      if ( (*(this + 4213) & 2) == 0 )
        *(this + 4213) |= 2u;
      a2 = 0;
      v6 = TdrBuf::ReadInt32(v4, &a2);
      if ( v6 )
        return v6;
      if ( a2 )
      {
        v9 = sub_10227E40(this + 3, v4, a2);
        goto LABEL_16;
      }
    }
  }
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: TLV::UnkTlv0261::Read_0x99
// Address Name: SUB_102288C0
// ============================================================
//----- (102288C0) --------------------------------------------------------
int __thiscall sub_102288C0(_DWORD *this, int a2, unsigned int i)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int v9; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = i;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(this + 4213) = 0;
  v7 = v4[1] + v3;
  for ( i = v7; v4[1] < i; v7 = i )
  {
    result = TdrBuf::ReadVarUInt(v4, &v10);
    if ( result )
      return result;
    if ( v10 >> 4 == 1 )
    {
      if ( (*(_BYTE *)(this + 4213) & 1) == 0 )
        *(this + 4213) |= 1u;
      a2 = 0;
      v6 = TdrBuf::ReadInt32(v4, &a2);
      if ( v6 )
        return v6;
      if ( a2 )
      {
        v9 = sub_10226CD0((int)this, v4, a2);
LABEL_16:
        v6 = v9;
        if ( v9 )
          return v6;
      }
    }
    else
    {
      if ( v10 >> 4 != 2 )
      {
        v9 = TdrBuf::SkipField(v4, v10 & 0xF);
        goto LABEL_16;
      }
      if ( (*(this + 4213) & 2) == 0 )
        *(this + 4213) |= 2u;
      a2 = 0;
      v6 = TdrBuf::ReadInt32(v4, &a2);
      if ( v6 )
        return v6;
      if ( a2 )
      {
        v9 = sub_10227FB0(this + 3, v4, a2);
        goto LABEL_16;
      }
    }
  }
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: TLV::UnkTlv0261::DoDebugFormat
// Address Name: SUB_102289E0
// ============================================================
//----- (102289E0) --------------------------------------------------------
int __thiscall sub_102289E0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10228A90(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0261::DebugFormat
// Address Name: SUB_10228A90
// ============================================================
//----- (10228A90) --------------------------------------------------------
int __thiscall sub_10228A90(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx

  if ( !"[schedule]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[schedule]", (char)a4);
    if ( !result )
    {
      if ( a3 >= 0 )
        result = sub_10226E70(this, a2, a3 + 1, a4);
      else
        result = sub_10226E70(this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[dailys]");
        if ( !result )
        {
          v5 = this + 3;
          if ( a3 >= 0 )
            return sub_102281F0(v5, a2, a3 + 1, a4);
          else
            return sub_102281F0(v5, a2, a3, a4);
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10227E40
// ============================================================
//----- (10227E40) --------------------------------------------------------
int __thiscall sub_10227E40(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 4209) = 0;
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
        if ( (v4[4209] & 1) == 0 )
          v4[4209] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[4209] & 2) == 0 )
            v4[4209] |= 2u;
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
              v5 = sub_102273F0(a3, v6, v15);
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
            a3 += 526;
            if ( ++v10 >= 32 )
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
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10226C30
// ============================================================
//----- (10226C30) --------------------------------------------------------
int __thiscall sub_10226C30(_DWORD *this, _DWORD *a2, int a3)
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
        VarUInt = TdrBuf::ReadVarInt(a2, this + 1);
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
// Address Name: SUB_10227FB0
// ============================================================
//----- (10227FB0) --------------------------------------------------------
int __thiscall sub_10227FB0(_DWORD *this, _DWORD *a2, int a3)
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
  *(this + 4209) = 0;
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
        if ( (v4[4209] & 1) == 0 )
          v4[4209] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[4209] & 2) == 0 )
            v4[4209] |= 2u;
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
              v5 = sub_102275A0(a3, v6, v15);
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
            a3 += 526;
            if ( ++v10 >= 32 )
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
// Address Name: SUB_10226CD0
// ============================================================
//----- (10226CD0) --------------------------------------------------------
int __thiscall sub_10226CD0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10226E70
// ============================================================
//----- (10226E70) --------------------------------------------------------
int __thiscall sub_10226E70(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[group]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102281F0
// ============================================================
//----- (102281F0) --------------------------------------------------------
int __thiscall sub_102281F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  __int16 *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 32 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (__int16 *)(this + 1); ; i += 263 )
          {
            if ( !"[dailys]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[dailys]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10227820(i, a2, a3 + 1, a4) : sub_10227820(i, a2, a3, a4);
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
// Address Name: SUB_102273F0
// ============================================================
//----- (102273F0) --------------------------------------------------------
int __thiscall sub_102273F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int VarShort; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarShort = 0;
  v15 = this;
  v14 = 0;
  *(_DWORD *)(this + 522) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 522) & 1) == 0 )
          *(_DWORD *)(v5 + 522) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)v5);
        goto LABEL_25;
      case 2u:
        if ( (*(_DWORD *)(v5 + 522) & 2) == 0 )
          *(_DWORD *)(v5 + 522) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_25;
      case 3u:
        if ( (*(_DWORD *)(v5 + 522) & 4) == 0 )
          *(_DWORD *)(v5 + 522) |= 4u;
        VarUInt = TdrBuf::ReadVarShort(v4, (_WORD *)(v5 + 8));
        goto LABEL_25;
      case 4u:
        if ( (*(_DWORD *)(v5 + 522) & 8) == 0 )
          *(_DWORD *)(v5 + 522) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        while ( 1 )
        {
          VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(v15 + 10 + 2 * v10));
          if ( VarShort )
            return VarShort;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 256 )
          {
            v5 = v15;
            goto LABEL_26;
          }
        }
        v12 = v10 + 1;
        v5 = v15;
        *(_WORD *)(v15 + 8) = v12;
LABEL_26:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return VarShort;
      default:
        VarUInt = TdrBuf::SkipField(v4, v14 & 0xF);
LABEL_25:
        VarShort = VarUInt;
        if ( !VarUInt )
          goto LABEL_26;
        return VarShort;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102275A0
// ============================================================
//----- (102275A0) --------------------------------------------------------
int __thiscall sub_102275A0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int Int16; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  int v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int16 = 0;
  v15 = this;
  v14 = 0;
  *(_DWORD *)(this + 522) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 522) & 1) == 0 )
          *(_DWORD *)(v5 + 522) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_25;
      case 2u:
        if ( (*(_DWORD *)(v5 + 522) & 2) == 0 )
          *(_DWORD *)(v5 + 522) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_25;
      case 3u:
        if ( (*(_DWORD *)(v5 + 522) & 4) == 0 )
          *(_DWORD *)(v5 + 522) |= 4u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(v5 + 8));
        goto LABEL_25;
      case 4u:
        if ( (*(_DWORD *)(v5 + 522) & 8) == 0 )
          *(_DWORD *)(v5 + 522) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        while ( 1 )
        {
          Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(v15 + 10 + 2 * v10));
          if ( Int16 )
            return Int16;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 256 )
          {
            v5 = v15;
            goto LABEL_26;
          }
        }
        v12 = v10 + 1;
        v5 = v15;
        *(_WORD *)(v15 + 8) = v12;
LABEL_26:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return Int16;
      default:
        Int32 = TdrBuf::SkipField(v4, v14 & 0xF);
LABEL_25:
        Int16 = Int32;
        if ( !Int32 )
          goto LABEL_26;
        return Int16;
    }
  }
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
// Address Name: SUB_10227820
// ============================================================
//----- (10227820) --------------------------------------------------------
int __thiscall sub_10227820(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // si

  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lib]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[taskCount]", "%d", *(this + 4));
      if ( !result )
      {
        v6 = *(this + 4);
        if ( v6 >= 0 )
        {
          if ( v6 <= 256 )
          {
            result = sub_1024A3B0(a2, a3, 256, "[task]", v6);
            if ( !result )
            {
              v7 = 0;
              if ( *(this + 4) <= 0 )
              {
                return TdrBuf::WriteChar(a2, a4);
              }
              else
              {
                while ( 1 )
                {
                  result = Printf(a2, " %d", *(this + v7 + 5));
                  if ( result )
                    break;
                  if ( ++v7 >= *(this + 4) )
                    return TdrBuf::WriteChar(a2, a4);
                }
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



