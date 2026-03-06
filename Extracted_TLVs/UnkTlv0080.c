// ============================================================
// Name: TLV::UnkTlv0080::Read
// Address Name: SUB_101514C0
// ============================================================
//----- (101514C0) --------------------------------------------------------
int __thiscall sub_101514C0(_DWORD *this, size_t a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  unsigned int v8; // [esp-Ch] [ebp-1Ch]
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
    result = sub_10151590(this, (size_t)&Size, v8);
  else
    result = sub_10151700(this, (size_t)&Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0080::Read_0xAA
// Address Name: SUB_10151590
// ============================================================
//----- (10151590) --------------------------------------------------------
int __thiscall sub_10151590(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  bool v6; // cf
  int result; // eax
  size_t v8; // ebx
  size_t v9; // ebx
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(this + 24) = 0;
  a3 = v4[1] + v3;
  v6 = a3 < v4[1];
  if ( a3 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    switch ( v11 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 24) & 1) == 0 )
          *(this + 24) |= 1u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v10) = 0;
        break;
      case 2u:
        if ( (*(this + 24) & 2) == 0 )
          *(this + 24) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v9 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this + 8, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v9 + 32) = 0;
        break;
      case 3u:
        if ( (*(this + 24) & 4) == 0 )
          *(this + 24) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v8 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this + 16, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v8 + 64) = 0;
        break;
      default:
        result = TdrBuf::SkipField(v4, v11 & 0xF);
        if ( result )
          return result;
        break;
    }
    if ( v4[1] >= a3 )
    {
      v6 = a3 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0080::Read_0x99
// Address Name: SUB_10151700
// ============================================================
//----- (10151700) --------------------------------------------------------
int __thiscall sub_10151700(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  bool v6; // cf
  int result; // eax
  size_t v8; // ebx
  size_t v9; // ebx
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(this + 24) = 0;
  a3 = v4[1] + v3;
  v6 = a3 < v4[1];
  if ( a3 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    switch ( v11 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 24) & 1) == 0 )
          *(this + 24) |= 1u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v10) = 0;
        break;
      case 2u:
        if ( (*(this + 24) & 2) == 0 )
          *(this + 24) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v9 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this + 8, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v9 + 32) = 0;
        break;
      case 3u:
        if ( (*(this + 24) & 4) == 0 )
          *(this + 24) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v8 = Size;
        if ( Size >= 0x20 )
          return -3;
        result = TdrBuf::ReadBytes(v4, this + 16, Size);
        if ( result )
          return result;
        *((_BYTE *)this + v8 + 64) = 0;
        break;
      default:
        result = TdrBuf::SkipField(v4, v11 & 0xF);
        if ( result )
          return result;
        break;
    }
    if ( v4[1] >= a3 )
    {
      v6 = a3 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0080::DoDebugFormat
// Address Name: SUB_10151890
// ============================================================
//----- (10151890) --------------------------------------------------------
int __thiscall sub_10151890(const char *this, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int v7; // esi
  int v8; // [esp+8h] [ebp-1Ch] BYREF
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
  v7 = sub_10151940(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0080::DebugFormat
// Address Name: SUB_10151940
// ============================================================
//----- (10151940) --------------------------------------------------------
int __thiscall sub_10151940(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = sub_1024A410(a2, a3, a4, "[name]", this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[guild]", this + 32);
    if ( !result )
      return sub_1024A410(a2, a3, a4, "[clan]", this + 64);
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



