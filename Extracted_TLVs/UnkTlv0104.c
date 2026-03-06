// ============================================================
// Name: TLV::UnkTlv0104::Read_0xAA
// Address Name: SUB_10166180
// ============================================================
//----- (10166180) --------------------------------------------------------
int __thiscall sub_10166180(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  _DWORD *v5; // edi
  bool v6; // cf
  int result; // eax
  unsigned int v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = this;
  v12 = 0;
  v5 = a2;
  *(this + 4) = 0;
  v10 = v5[1] + v3;
  v6 = v10 < v5[1];
  if ( v10 <= v5[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v5, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 2u:
        if ( (v4[4] & 1) == 0 )
          v4[4] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v5, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v8 = 0;
            a3 = v5[1];
            while ( 1 )
            {
              result = TdrBuf::ReadVarInt(v5, v4);
              if ( result )
                break;
              v9 = v5[1];
              if ( v9 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
              {
                ++v8;
                ++v4;
                if ( v8 < 2 )
                  continue;
              }
              v4 = this;
              goto LABEL_26;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      case 3u:
        if ( (v4[4] & 2) == 0 )
          v4[4] |= 2u;
        result = TdrBuf::ReadVarInt(v5, v4 + 2);
        if ( result )
          return result;
        break;
      case 4u:
        if ( (v4[4] & 4) == 0 )
          v4[4] |= 4u;
        result = TdrBuf::ReadVarUInt(v5, v4 + 3);
        if ( result )
          return result;
        break;
      default:
        result = TdrBuf::SkipField(v5, v12 & 0xF);
        if ( result )
          return result;
        break;
    }
LABEL_26:
    if ( v5[1] >= v10 )
    {
      v6 = v10 < v5[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0104::Read_0x99
// Address Name: SUB_101662D0
// ============================================================
//----- (101662D0) --------------------------------------------------------
int __thiscall sub_101662D0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // edi
  bool v6; // cf
  int result; // eax
  _BYTE *v8; // eax
  unsigned int v9; // esi
  unsigned int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-Ch]
  unsigned int v13; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = this;
  v13 = 0;
  v5 = a2;
  *(this + 4) = 0;
  v11 = v5[1] + v3;
  v6 = v11 < v5[1];
  if ( v11 > v5[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v5, &v13);
      if ( result )
        return result;
      if ( v13 >> 4 == 2 )
      {
        if ( (v4[4] & 1) == 0 )
          v4[4] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v5, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v9 = 0;
            a3 = v5[1];
            while ( 1 )
            {
              result = TdrBuf::ReadInt32(v5, v4);
              if ( result )
                break;
              v10 = v5[1];
              if ( v10 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
              {
                ++v9;
                ++v4;
                if ( v9 < 2 )
                  continue;
              }
              v4 = this;
              goto LABEL_26;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      }
      if ( v13 >> 4 == 3 )
        break;
      if ( v13 >> 4 == 4 )
      {
        if ( (v4[4] & 4) == 0 )
          v4[4] |= 4u;
        v8 = v4 + 3;
LABEL_13:
        result = TdrBuf::ReadInt32(v5, v8);
        goto LABEL_14;
      }
      result = TdrBuf::SkipField(v5, v13 & 0xF);
LABEL_14:
      if ( result )
        return result;
LABEL_26:
      if ( v5[1] >= v11 )
      {
        v6 = v11 < v5[1];
        return v6 ? 0xFFFFFFDE : 0;
      }
    }
    if ( (v4[4] & 2) == 0 )
      v4[4] |= 2u;
    v8 = v4 + 2;
    goto LABEL_13;
  }
  return v6 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: TLV::UnkTlv0104::DoDebugFormat
// Address Name: SUB_10166420
// ============================================================
//----- (10166420) --------------------------------------------------------
int __thiscall sub_10166420(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101664D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0104::DebugFormat
// Address Name: SUB_101664D0
// ============================================================
//----- (101664D0) --------------------------------------------------------
int __thiscall sub_101664D0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx

  if ( !"[actionPoint]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[actionPoint]", 1LL);
    if ( !result )
    {
      v6 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(this + v6));
        if ( result )
          break;
        if ( (unsigned int)++v6 >= 2 )
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
          result = print_field(a2, a3, a4, "[nextResetTime]", "%d", *(this + 2));
          if ( !result )
            return print_field(a2, a3, a4, "[actionPointFlags]", "%u", *(this + 3));
          return result;
        }
      }
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



