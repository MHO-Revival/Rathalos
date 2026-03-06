// ============================================================
// Name: TLV::UnkTlv0189::Read_0xAA
// Address Name: SUB_101AF510
// ============================================================
//----- (101AF510) --------------------------------------------------------
int __thiscall sub_101AF510(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  char *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  char *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (char *)this;
  v6 = 0;
  v15 = (char *)this;
  v14 = 0;
  *(_DWORD *)(this + 91) = 0;
  v7 = &v3[v4[1]];
  v11 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_19:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v5[91] & 1) == 0 )
          *(_DWORD *)(v5 + 91) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v4[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          v6 = TdrBuf::ReadInt32(v4, &v13);
          if ( v6 )
            return v6;
          if ( v13 )
          {
            v6 = sub_101AEBA0(a3, (int)v4, v13);
            if ( v6 )
              return v6;
          }
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 13;
            if ( (unsigned int)++v9 < 7 )
              continue;
          }
          v5 = v15;
          goto LABEL_18;
        }
      }
      v6 = TdrBuf::SkipField(v4, v14 & 0xF);
      if ( v6 )
        return v6;
LABEL_18:
      v7 = v11;
      if ( v4[1] >= (unsigned int)v11 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0189::Read_0x99
// Address Name: SUB_101AF640
// ============================================================
//----- (101AF640) --------------------------------------------------------
int __thiscall sub_101AF640(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  char *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  char *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (char *)this;
  v6 = 0;
  v15 = (char *)this;
  v14 = 0;
  *(_DWORD *)(this + 91) = 0;
  v7 = &v3[v4[1]];
  v11 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_19:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v5[91] & 1) == 0 )
          *(_DWORD *)(v5 + 91) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v4[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          v6 = TdrBuf::ReadInt32(v4, &v13);
          if ( v6 )
            return v6;
          if ( v13 )
          {
            v6 = sub_101AECC0(a3, (int)v4, v13);
            if ( v6 )
              return v6;
          }
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 13;
            if ( (unsigned int)++v9 < 7 )
              continue;
          }
          v5 = v15;
          goto LABEL_18;
        }
      }
      v6 = TdrBuf::SkipField(v4, v14 & 0xF);
      if ( v6 )
        return v6;
LABEL_18:
      v7 = v11;
      if ( v4[1] >= (unsigned int)v11 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0189::DoDebugFormat
// Address Name: SUB_101AF790
// ============================================================
//----- (101AF790) --------------------------------------------------------
int __thiscall sub_101AF790(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101AF840(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0189::DebugFormat
// Address Name: SUB_101AF840
// ============================================================
//----- (101AF840) --------------------------------------------------------
int __thiscall sub_101AF840(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  unsigned int i; // esi
  int result; // eax

  for ( i = 0; i < 7; ++i )
  {
    if ( !"[value]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      break;
    result = Printf(a2, "%s[%u]%c", "[value]", i, a4);
    if ( result )
      break;
    result = a3 >= 0 ? sub_101AEEB0(this, a2, a3 + 1, a4) : sub_101AEEB0(this, a2, a3, a4);
    if ( result )
      break;
    this += 13;
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AEBA0
// ============================================================
//----- (101AEBA0) --------------------------------------------------------
int __thiscall sub_101AEBA0(char *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
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
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AE4E0((int *)(this + 1), &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *this = v10;
      }
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
// Address Name: SUB_101AECC0
// ============================================================
//----- (101AECC0) --------------------------------------------------------
int __thiscall sub_101AECC0(char *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
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
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AE5F0(this + 1, &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *this = v10;
      }
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
// Address Name: SUB_101AEEB0
// ============================================================
//----- (101AEEB0) --------------------------------------------------------
int __thiscall sub_101AEEB0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  float *v5; // ecx

  result = print_field(a2, a3, a4, "[wType]", "%d", *this);
  if ( !result )
  {
    if ( !"[stValue]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[stValue]", a4);
      if ( !result )
      {
        v5 = (float *)(this + 1);
        if ( a3 >= 0 )
          return sub_101AE7B0(v5, *this, 0, a2, a3 + 1, a4);
        else
          return sub_101AE7B0(v5, *this, 0, a2, a3, a4);
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
// Address Name: SUB_101AE4E0
// ============================================================
//----- (101AE4E0) --------------------------------------------------------
int __thiscall sub_101AE4E0(int *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  if ( !a4 )
    return 0;
  v6 = (_DWORD *)a3;
  v7 = (_DWORD *)a3;
  a3 = 0;
  v10 = v7[1];
  result = TdrBuf::ReadVarUInt(v7, &a3);
  if ( !result )
  {
    v9 = a3 >> 4;
    switch ( a3 >> 4 )
    {
      case 1u:
        result = TdrBuf::ReadVarInt(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 2u:
        result = TdrBuf::ReadInt32(v6, &a3);
        v8 = result;
        if ( !result )
        {
          *this = a3;
          goto LABEL_14;
        }
        break;
      case 4u:
        result = TdrBuf::ReadVarShort(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 6u:
        result = TdrBuf::ReadVarULong(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      default:
        result = TdrBuf::SkipField(v6, a3 & 0xF);
        v8 = result;
        if ( !result )
        {
LABEL_14:
          if ( v6[1] <= (unsigned int)(v10 + a4) )
          {
            *a2 = v9;
            result = v8;
          }
          else
          {
            result = -34;
          }
        }
        break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AE5F0
// ============================================================
//----- (101AE5F0) --------------------------------------------------------
int __thiscall sub_101AE5F0(_BYTE *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  if ( !a4 )
    return 0;
  v6 = (_DWORD *)a3;
  v7 = (_DWORD *)a3;
  a3 = 0;
  v10 = v7[1];
  result = TdrBuf::ReadVarUInt(v7, &a3);
  if ( !result )
  {
    v9 = a3 >> 4;
    switch ( a3 >> 4 )
    {
      case 1u:
        result = TdrBuf::ReadInt32(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 2u:
        result = TdrBuf::ReadInt32(v6, &a3);
        v8 = result;
        if ( !result )
        {
          *(_DWORD *)this = a3;
          goto LABEL_14;
        }
        break;
      case 4u:
        result = TdrBuf::ReadInt16(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 6u:
        result = TdrBuf::ReadInt64(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      default:
        result = TdrBuf::SkipField(v6, a3 & 0xF);
        v8 = result;
        if ( !result )
        {
LABEL_14:
          if ( v6[1] <= (unsigned int)(v10 + a4) )
          {
            *a2 = v9;
            result = v8;
          }
          else
          {
            result = -34;
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
// Address Name: SUB_101AE7B0
// ============================================================
//----- (101AE7B0) --------------------------------------------------------
int __thiscall sub_101AE7B0(float *this, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int result; // eax

  result = 0;
  if ( a2 == 1 && !a3 )
    return print_field(a4, a5, a6, "[iInt]", "%d", *(_DWORD *)this);
  if ( a2 == 2 && !a3 )
    return print_field(a4, a5, a6, "[fFloat]", "%f", *this);
  if ( a2 == 4 && !a3 )
    return print_field(a4, a5, a6, "[nBool]", "%d", *(__int16 *)this);
  if ( a2 == 6 && !a3 )
    return print_field(a4, a5, a6, "[ullUint64]", "%I64u", *(_QWORD *)this);
  return result;
}



