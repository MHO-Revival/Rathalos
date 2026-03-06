// ============================================================
// Name: TLV::UnkTlv0085::Read_0xAA
// Address Name: SUB_10155090
// ============================================================
//----- (10155090) --------------------------------------------------------
int __thiscall sub_10155090(char *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  bool v6; // cf
  int result; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v12 = 0;
  *(_DWORD *)(this + 65) = 0;
  v11 = v4[1] + v3;
  v6 = v11 < v4[1];
  if ( v11 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 65) & 1) == 0 )
        *(_DWORD *)(this + 65) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v10 = v4[1];
      if ( v4[2] == v10 )
        return -2;
      *this = *(_BYTE *)(v10 + *v4);
      ++v4[1];
    }
    else
    {
      if ( v12 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 65) & 2) == 0 )
          *(_DWORD *)(this + 65) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v8 = 0;
            a3 = v4[1];
            while ( 1 )
            {
              result = TdrBuf::ReadVarInt(v4, (int *)(this + 4 * v8 + 1));
              if ( result )
                break;
              v9 = v4[1];
              if ( v9 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + a3) )
              {
                *this = v8 + 1;
                goto LABEL_24;
              }
              if ( ++v8 >= 0x10u )
                goto LABEL_24;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      }
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
LABEL_24:
    if ( v4[1] >= v11 )
    {
      v6 = v11 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0085::Read_0x99
// Address Name: SUB_10155200
// ============================================================
//----- (10155200) --------------------------------------------------------
int __thiscall sub_10155200(char *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  bool v6; // cf
  int result; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v12 = 0;
  *(_DWORD *)(this + 65) = 0;
  v11 = v4[1] + v3;
  v6 = v11 < v4[1];
  if ( v11 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 65) & 1) == 0 )
        *(_DWORD *)(this + 65) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v10 = v4[1];
      if ( v4[2] == v10 )
        return -2;
      *this = *(_BYTE *)(v10 + *v4);
      ++v4[1];
    }
    else
    {
      if ( v12 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 65) & 2) == 0 )
          *(_DWORD *)(this + 65) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v8 = 0;
            a3 = v4[1];
            while ( 1 )
            {
              result = TdrBuf::ReadInt32(v4, this + 4 * v8 + 1);
              if ( result )
                break;
              v9 = v4[1];
              if ( v9 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + a3) )
              {
                *this = v8 + 1;
                goto LABEL_24;
              }
              if ( ++v8 >= 0x10u )
                goto LABEL_24;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      }
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
LABEL_24:
    if ( v4[1] >= v11 )
    {
      v6 = v11 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0085::DoDebugFormat
// Address Name: SUB_10155390
// ============================================================
//----- (10155390) --------------------------------------------------------
int __thiscall sub_10155390(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10155440(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0085::DebugFormat
// Address Name: SUB_10155440
// ============================================================
//----- (10155440) --------------------------------------------------------
int __thiscall sub_10155440(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // bl

  result = print_field(a2, a3, a4, "[varNum]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this <= 0x10u )
    {
      result = sub_1024A3B0(a2, a3, v6, "[varData]", *this);
      if ( !result )
      {
        v7 = 0;
        if ( *this )
        {
          while ( 1 )
          {
            result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v7 + 1));
            if ( result )
              break;
            if ( ++v7 >= *this )
              return TdrBuf::WriteChar(a2, a4);
          }
        }
        else
        {
          return TdrBuf::WriteChar(a2, a4);
        }
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}
// 1015548F: variable 'v6' is possibly undefined



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



