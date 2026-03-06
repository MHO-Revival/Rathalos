// ============================================================
// Name: TLV::UnkTlv0106::Read_0xAA
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
// Name: TLV::UnkTlv0106::Read_0x99
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
// Name: TLV::UnkTlv0106::DoDebugFormat
// Address Name: SUB_101674B0
// ============================================================
//----- (101674B0) --------------------------------------------------------
int __thiscall sub_101674B0(int this, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int v8; // esi
  int v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int v11; // [esp+14h] [ebp-14h]
  char v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+24h] [ebp-4h]

  if ( !a2 )
    return -19;
  v9 = a2;
  v12 = 0;
  v10 = 0;
  v11 = a3;
  v13 = 0;
  v8 = sub_1024A410(&v9, a5, a6, "[strName]", (const char *)this);
  if ( !v8 )
    v8 = print_field(&v9, a5, a6, "[nChannelFlags]", "%u", *(_DWORD *)(this + 21));
  if ( a4 )
    *a4 = v10;
  if ( v12 )
    sub_10C3DA30(v9);
  return v8;
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



