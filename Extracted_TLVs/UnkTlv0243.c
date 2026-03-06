// ============================================================
// Name: TLV::UnkTlv0243::Read_0xAA
// Address Name: SUB_1021B9B0
// ============================================================
//----- (1021B9B0) --------------------------------------------------------
int __thiscall sub_1021B9B0(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 31604) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 31604) & 1) == 0 )
          *(_DWORD *)(this + 31604) |= 1u;
        result = TdrBuf::ReadVarUShort(v6, (_WORD *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 31604) & 2) == 0 )
          *(_DWORD *)(this + 31604) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021B000(this + 2 * (5 * v8 + 1), v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xC8u )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 31604) & 4) == 0 )
          *(_DWORD *)(this + 31604) |= 4u;
        result = TdrBuf::ReadVarUShort(v6, (_WORD *)(this + 2002));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 31604) & 8) == 0 )
          *(_DWORD *)(this + 31604) |= 8u;
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
            result = sub_1021A950(this + 2004 + 8 * v10, v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0xE74u )
            goto LABEL_38;
        }
        *(_WORD *)(this + 2002) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0243::Read_0x99
// Address Name: SUB_1021BC10
// ============================================================
//----- (1021BC10) --------------------------------------------------------
int __thiscall sub_1021BC10(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 31604) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 31604) & 1) == 0 )
          *(_DWORD *)(this + 31604) |= 1u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 31604) & 2) == 0 )
          *(_DWORD *)(this + 31604) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021B0A0((char *)(this + 2 * (5 * v8 + 1)), v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xC8u )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 31604) & 4) == 0 )
          *(_DWORD *)(this + 31604) |= 4u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 2002));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 31604) & 8) == 0 )
          *(_DWORD *)(this + 31604) |= 8u;
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
            result = sub_1021A9F0((_DWORD *)(this + 2004 + 8 * v10), v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0xE74u )
            goto LABEL_38;
        }
        *(_WORD *)(this + 2002) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0243::DoDebugFormat
// Address Name: SUB_1021BE90
// ============================================================
//----- (1021BE90) --------------------------------------------------------
int __thiscall sub_1021BE90(unsigned __int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1021BF40(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0243::DebugFormat
// Address Name: SUB_1021BF40
// ============================================================
//----- (1021BF40) --------------------------------------------------------
int __thiscall sub_1021BF40(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // eax
  unsigned __int16 v9; // cx
  int v10; // eax
  int v11; // [esp+14h] [ebp+8h]
  int v12; // [esp+14h] [ebp+8h]
  int v13; // [esp+18h] [ebp+Ch]
  int v14; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[statNumInt]", "%d", *this);
  if ( !result )
  {
    if ( *this > 0xC8u )
      return -7;
    LOWORD(v8) = 0;
    v11 = 0;
    if ( *this )
    {
      while ( 1 )
      {
        v13 = (unsigned __int16)v8;
        if ( !"[statListInt]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[statListInt]", v13, a4);
        if ( result )
          break;
        result = a3 >= 0
               ? sub_1021B2A0(this + 5 * v13 + 1, a2, a3 + 1, a4)
               : sub_1021B2A0(this + 5 * v13 + 1, a2, a3, a4);
        if ( result )
          break;
        v8 = v11 + 1;
        v11 = v8;
        if ( (unsigned __int16)v8 >= *this )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      result = print_field(a2, a3, a4, "[statNum]", "%d", *(this + 1001));
      if ( !result )
      {
        v9 = *(this + 1001);
        if ( v9 > 0xE74u )
          return -7;
        LOWORD(v10) = 0;
        v12 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v14 = (unsigned __int16)v10;
            if ( !"[statList]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[statList]", v14, a4);
            if ( result )
              break;
            result = a3 >= 0
                   ? sub_1021AC30(this + 4 * v14 + 1002, a2, a3 + 1, a4)
                   : sub_1021AC30(this + 4 * v14 + 1002, a2, a3, a4);
            if ( result )
              break;
            v10 = v12 + 1;
            v12 = v10;
            if ( (unsigned __int16)v10 >= *(this + 1001) )
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021B000
// ============================================================
//----- (1021B000) --------------------------------------------------------
int __thiscall sub_1021B000(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
        if ( (*(_BYTE *)(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        VarUShort = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 2));
      }
      else
      {
        VarUShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUShort;
      if ( VarUShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021A950
// ============================================================
//----- (1021A950) --------------------------------------------------------
int __thiscall sub_1021A950(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 4) = 0;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 4) & 2) == 0 )
          *(_DWORD *)(this + 4) |= 2u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)(this + 2));
      }
      else
      {
        VarUShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUShort;
      if ( VarUShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021B0A0
// ============================================================
//----- (1021B0A0) --------------------------------------------------------
int __thiscall sub_1021B0A0(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
      if ( (*(this + 6) & 1) == 0 )
        *(_DWORD *)(this + 6) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v7 = a2[1];
      if ( (unsigned int)(a2[2] - v7) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v7 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 6) & 2) == 0 )
        *(_DWORD *)(this + 6) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 2);
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
// Address Name: SUB_1021A9F0
// ============================================================
//----- (1021A9F0) --------------------------------------------------------
int __thiscall sub_1021A9F0(_DWORD *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(this + 1) = 0;
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
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v8 = a2[1];
        if ( (unsigned int)(a2[2] - v8) < 2 )
          return -2;
        *(_BYTE *)this = *(_BYTE *)(*a2 + v8 + 1);
        *((_BYTE *)this + 1) = *(_BYTE *)(*a2 + a2[1]);
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
        if ( (*(this + 1) & 2) == 0 )
          *(this + 1) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v7 = a2[1];
        if ( (unsigned int)(a2[2] - v7) < 2 )
          return -2;
        *((_BYTE *)this + 2) = *(_BYTE *)(*a2 + v7 + 1);
        *((_BYTE *)this + 3) = *(_BYTE *)(*a2 + a2[1]);
      }
      a2[1] += 2;
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
// Address Name: SUB_1021B2A0
// ============================================================
//----- (1021B2A0) --------------------------------------------------------
int __thiscall sub_1021B2A0(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[statIdx]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[statValue]", "%u", *(_DWORD *)(this + 1));
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
// Address Name: SUB_1021AC30
// ============================================================
//----- (1021AC30) --------------------------------------------------------
int __thiscall sub_1021AC30(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[statIdx]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[statValue]", "%d", *(this + 1));
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



