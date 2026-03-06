// ============================================================
// Name: TLV::UnkTlv0035::Read
// Address Name: SUB_10129680
// ============================================================
//----- (10129680) --------------------------------------------------------
int __thiscall sub_10129680(void *this, size_t a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10129750((int)this, &Size, v8);
  else
    result = sub_101299D0((int)this, &Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0035::Read_0xAA
// Address Name: SUB_10129750
// ============================================================
//----- (10129750) --------------------------------------------------------
int __thiscall sub_10129750(int this, _DWORD *Size, int a3)
{
  int result; // eax
  int v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // [esp+10h] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-14h]
  unsigned int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h]
  unsigned int v18; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v15 = 0;
  v14 = this;
  *(_DWORD *)(this + 200110) = 0;
  v5 = Size[1] + a3;
  v18 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 200110) & 1) == 0 )
          *(_DWORD *)(v4 + 200110) |= 1u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 200110) & 2) == 0 )
          *(_DWORD *)(v4 + 200110) |= 2u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)(v4 + 1));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 200110) & 4) == 0 )
          *(_DWORD *)(v4 + 200110) |= 4u;
        v13 = 0;
        result = TdrBuf::ReadInt32(Size, &v13);
        if ( result )
          return result;
        if ( !v13 )
          return -37;
        v6 = 0;
        v17 = Size[1];
        while ( 2 )
        {
          v16 = 0;
          result = TdrBuf::ReadInt32(Size, &v16);
          if ( result )
            return result;
          if ( v16 )
          {
            result = sub_10128BA0((char *)(v4 + 13 * v6 + 2), (size_t)Size, v16);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v17 + v13 )
            return -34;
          if ( v7 != v17 + v13 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)(v4 + 1) = v6 + 1;
        goto LABEL_39;
      case 4u:
        if ( (*(_DWORD *)(v4 + 200110) & 8) == 0 )
          *(_DWORD *)(v4 + 200110) |= 8u;
        result = TdrBuf::ReadVarUInt(Size, (_DWORD *)(v4 + 106));
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(v4 + 200110) & 0x10) == 0 )
          *(_DWORD *)(v4 + 200110) |= 0x10u;
        v16 = 0;
        result = TdrBuf::ReadInt32(Size, &v16);
        if ( result )
          return result;
        v8 = v16;
        if ( !v16 )
          return -37;
        v9 = 0;
        v10 = v14 + 110;
        v17 = Size[1];
        v16 = v14 + 110;
        while ( 1 )
        {
          result = TdrBuf::ReadByte(Size, (_BYTE *)(v10 + v9));
          if ( result )
            return result;
          v11 = Size[1];
          if ( v11 > v8 + v17 )
            return -34;
          if ( v11 == v8 + v17 )
            break;
          v10 = v16;
          if ( (unsigned int)++v9 >= 0x30D40 )
          {
            v4 = v14;
            goto LABEL_39;
          }
        }
        v12 = v9 + 1;
        v4 = v14;
        *(_DWORD *)(v14 + 106) = v12;
LABEL_39:
        v5 = v18;
        if ( Size[1] < v18 )
          continue;
LABEL_40:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v15 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0035::Read_0x99
// Address Name: SUB_101299D0
// ============================================================
//----- (101299D0) --------------------------------------------------------
int __thiscall sub_101299D0(int this, _DWORD *Size, int a3)
{
  int result; // eax
  int v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // [esp+10h] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-14h]
  unsigned int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h]
  unsigned int v18; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v15 = 0;
  v14 = this;
  *(_DWORD *)(this + 200110) = 0;
  v5 = Size[1] + a3;
  v18 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 200110) & 1) == 0 )
          *(_DWORD *)(v4 + 200110) |= 1u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 200110) & 2) == 0 )
          *(_DWORD *)(v4 + 200110) |= 2u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)(v4 + 1));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 200110) & 4) == 0 )
          *(_DWORD *)(v4 + 200110) |= 4u;
        v13 = 0;
        result = TdrBuf::ReadInt32(Size, &v13);
        if ( result )
          return result;
        if ( !v13 )
          return -37;
        v6 = 0;
        v17 = Size[1];
        while ( 2 )
        {
          v16 = 0;
          result = TdrBuf::ReadInt32(Size, &v16);
          if ( result )
            return result;
          if ( v16 )
          {
            result = sub_10128D30((char *)(v4 + 13 * v6 + 2), (size_t)Size, v16);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v17 + v13 )
            return -34;
          if ( v7 != v17 + v13 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)(v4 + 1) = v6 + 1;
        goto LABEL_39;
      case 4u:
        if ( (*(_DWORD *)(v4 + 200110) & 8) == 0 )
          *(_DWORD *)(v4 + 200110) |= 8u;
        result = TdrBuf::ReadInt32(Size, (_BYTE *)(v4 + 106));
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(v4 + 200110) & 0x10) == 0 )
          *(_DWORD *)(v4 + 200110) |= 0x10u;
        v16 = 0;
        result = TdrBuf::ReadInt32(Size, &v16);
        if ( result )
          return result;
        v8 = v16;
        if ( !v16 )
          return -37;
        v9 = 0;
        v10 = v14 + 110;
        v17 = Size[1];
        v16 = v14 + 110;
        while ( 1 )
        {
          result = TdrBuf::ReadByte(Size, (_BYTE *)(v10 + v9));
          if ( result )
            return result;
          v11 = Size[1];
          if ( v11 > v8 + v17 )
            return -34;
          if ( v11 == v8 + v17 )
            break;
          v10 = v16;
          if ( (unsigned int)++v9 >= 0x30D40 )
          {
            v4 = v14;
            goto LABEL_39;
          }
        }
        v12 = v9 + 1;
        v4 = v14;
        *(_DWORD *)(v14 + 106) = v12;
LABEL_39:
        v5 = v18;
        if ( Size[1] < v18 )
          continue;
LABEL_40:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v15 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0035::DoDebugFormat
// Address Name: SUB_10129C70
// ============================================================
//----- (10129C70) --------------------------------------------------------
int __thiscall sub_10129C70(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10129D20(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0035::DebugFormat
// Address Name: SUB_10129D20
// ============================================================
//----- (10129D20) --------------------------------------------------------
int __thiscall sub_10129D20(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // al
  const char *v10; // ecx
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // esi
  int v14; // [esp+14h] [ebp+8h]
  unsigned __int8 v15; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[curNum]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 > 8u )
        return -7;
      v9 = 0;
      v15 = 0;
      if ( v8 )
      {
        while ( 1 )
        {
          v14 = v9;
          if ( !"[stores]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[stores]", v14, a4);
          if ( result )
            break;
          v10 = (const char *)(this + 13 * v14 + 2);
          result = a3 >= 0 ? sub_10128FC0(v10, a2, a3 + 1, a4) : sub_10128FC0(v10, a2, a3, a4);
          if ( result )
            break;
          v9 = v15 + 1;
          v15 = v9;
          if ( v9 >= *(this + 1) )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        result = print_field(a2, a3, a4, "[storeSize]", "%u", *(_DWORD *)(this + 106));
        if ( !result )
        {
          v12 = *(_DWORD *)(this + 106);
          if ( v12 > 0x30D40 )
            return -7;
          result = sub_1024A3B0(a2, a3, v11, "[storeData]", v12);
          if ( !result )
          {
            v13 = 0;
            if ( *(_DWORD *)(this + 106) )
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *(this + v13 + 110));
                if ( result )
                  break;
                if ( (unsigned int)++v13 >= *(_DWORD *)(this + 106) )
                  return TdrBuf::WriteChar(a2, a4);
              }
            }
            else
            {
              return TdrBuf::WriteChar(a2, a4);
            }
          }
        }
      }
    }
  }
  return result;
}
// 10129E61: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10128BA0
// ============================================================
//----- (10128BA0) --------------------------------------------------------
int __thiscall sub_10128BA0(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v12 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      break;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v11 = v4[1];
      if ( v4[2] == v11 )
        return -2;
      *this = *(_BYTE *)(v11 + *v4);
      ++v4[1];
    }
    else if ( v12 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 8 )
        return -3;
      if ( this == (char *)-1 )
        return -8;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this + 1, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9 + 1) = 0;
      v6 = a3;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v12 & 0xF);
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
// Address Name: SUB_10128D30
// ============================================================
//----- (10128D30) --------------------------------------------------------
int __thiscall sub_10128D30(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v12 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      break;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v11 = v4[1];
      if ( v4[2] == v11 )
        return -2;
      *this = *(_BYTE *)(v11 + *v4);
      ++v4[1];
    }
    else if ( v12 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 8 )
        return -3;
      if ( this == (char *)-1 )
        return -8;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this + 1, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9 + 1) = 0;
      v6 = a3;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v12 & 0xF);
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
// Address Name: SUB_10128FC0
// ============================================================
//----- (10128FC0) --------------------------------------------------------
int __thiscall sub_10128FC0(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[idx]", "0x%02x", *(unsigned __int8 *)this);
  if ( !result )
    return sub_1024A410(a2, a3, a4, "[name]", this + 1);
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



