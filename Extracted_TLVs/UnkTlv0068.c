// ============================================================
// Name: TLV::UnkTlv0068::Read_0xAA
// Address Name: SUB_10145430
// ============================================================
//----- (10145430) --------------------------------------------------------
int __thiscall sub_10145430(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarShort; // eax
  __int16 v10; // di
  int VarUInt; // edx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+10h] [ebp-8h]
  unsigned int v20; // [esp+14h] [ebp-4h] BYREF
  int v21; // [esp+20h] [ebp+8h]

  v3 = a3;
  v6 = 0;
  v20 = 0;
  *(_DWORD *)(this + 52) = 0;
  v7 = a2[1] + v3;
  v17 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_36:
    if ( a2[1] > v7 )
      return -34;
    return v6;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v20);
    if ( result )
      return result;
    if ( v20 >> 4 != 1 )
      break;
    if ( (*(_BYTE *)(this + 52) & 1) == 0 )
      *(_DWORD *)(this + 52) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_33:
    VarUInt = VarShort;
    v21 = VarShort;
    if ( VarShort )
      return VarUInt;
LABEL_34:
    v7 = v17;
    if ( a2[1] >= v17 )
    {
      v6 = v21;
      goto LABEL_36;
    }
  }
  if ( v20 >> 4 == 2 )
  {
    if ( (*(_DWORD *)(this + 52) & 2) == 0 )
      *(_DWORD *)(this + 52) |= 2u;
    a3 = 0;
    result = TdrBuf::ReadInt32(a2, &a3);
    if ( result )
      return result;
    if ( a3 )
    {
      v10 = 0;
      v19 = a2[1];
      v21 = 0;
      while ( 1 )
      {
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v13 = a2[1];
        if ( a2[2] == v13 )
          return -2;
        *(_BYTE *)(v10 + this + 2) = *(_BYTE *)(v13 + *a2);
        v14 = a3;
        ++a2[1];
        v15 = v19 + v14;
        v16 = a2[1];
        if ( v16 > v15 )
          return -34;
        if ( v16 == v15 )
        {
LABEL_29:
          *(_WORD *)this = v10 + 1;
          goto LABEL_34;
        }
        if ( ++v10 >= 10 )
          goto LABEL_34;
      }
    }
    return -37;
  }
  if ( v20 >> 4 != 3 )
  {
    VarShort = TdrBuf::SkipField(a2, v20 & 0xF);
    goto LABEL_33;
  }
  if ( (*(_DWORD *)(this + 52) & 4) == 0 )
    *(_DWORD *)(this + 52) |= 4u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v10 = 0;
  v18 = a2[1];
  while ( 1 )
  {
    VarUInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 4 * (v10 + 3)));
    v21 = VarUInt;
    if ( VarUInt )
      return VarUInt;
    v12 = a2[1];
    if ( v12 > v18 + a3 )
      return -34;
    if ( v12 == v18 + a3 )
      goto LABEL_29;
    if ( ++v10 >= 10 )
      goto LABEL_34;
  }
}



// ============================================================
// Name: TLV::UnkTlv0068::Read_0x99
// Address Name: SUB_10145630
// ============================================================
//----- (10145630) --------------------------------------------------------
int __thiscall sub_10145630(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  __int16 v10; // di
  int Int32; // edx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+10h] [ebp-8h]
  unsigned int v20; // [esp+14h] [ebp-4h] BYREF
  int v21; // [esp+20h] [ebp+8h]

  v3 = a3;
  v6 = 0;
  v20 = 0;
  *(_DWORD *)(this + 52) = 0;
  v7 = a2[1] + v3;
  v17 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_36:
    if ( a2[1] > v7 )
      return -34;
    return v6;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v20);
    if ( result )
      return result;
    if ( v20 >> 4 != 1 )
      break;
    if ( (*(_BYTE *)(this + 52) & 1) == 0 )
      *(_DWORD *)(this + 52) |= 1u;
    Int16 = TdrBuf::ReadInt16(a2, (_BYTE *)this);
LABEL_33:
    Int32 = Int16;
    v21 = Int16;
    if ( Int16 )
      return Int32;
LABEL_34:
    v7 = v17;
    if ( a2[1] >= v17 )
    {
      v6 = v21;
      goto LABEL_36;
    }
  }
  if ( v20 >> 4 == 2 )
  {
    if ( (*(_DWORD *)(this + 52) & 2) == 0 )
      *(_DWORD *)(this + 52) |= 2u;
    a3 = 0;
    result = TdrBuf::ReadInt32(a2, &a3);
    if ( result )
      return result;
    if ( a3 )
    {
      v10 = 0;
      v19 = a2[1];
      v21 = 0;
      while ( 1 )
      {
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v13 = a2[1];
        if ( a2[2] == v13 )
          return -2;
        *(_BYTE *)(v10 + this + 2) = *(_BYTE *)(v13 + *a2);
        v14 = a3;
        ++a2[1];
        v15 = v19 + v14;
        v16 = a2[1];
        if ( v16 > v15 )
          return -34;
        if ( v16 == v15 )
        {
LABEL_29:
          *(_WORD *)this = v10 + 1;
          goto LABEL_34;
        }
        if ( ++v10 >= 10 )
          goto LABEL_34;
      }
    }
    return -37;
  }
  if ( v20 >> 4 != 3 )
  {
    Int16 = TdrBuf::SkipField(a2, v20 & 0xF);
    goto LABEL_33;
  }
  if ( (*(_DWORD *)(this + 52) & 4) == 0 )
    *(_DWORD *)(this + 52) |= 4u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v10 = 0;
  v18 = a2[1];
  while ( 1 )
  {
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4 * (v10 + 3)));
    v21 = Int32;
    if ( Int32 )
      return Int32;
    v12 = a2[1];
    if ( v12 > v18 + a3 )
      return -34;
    if ( v12 == v18 + a3 )
      goto LABEL_29;
    if ( ++v10 >= 10 )
      goto LABEL_34;
  }
}



// ============================================================
// Name: TLV::UnkTlv0068::DoDebugFormat
// Address Name: SUB_10145850
// ============================================================
//----- (10145850) --------------------------------------------------------
int __thiscall sub_10145850(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10145900(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0068::DebugFormat
// Address Name: SUB_10145900
// ============================================================
//----- (10145900) --------------------------------------------------------
int __thiscall sub_10145900(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  __int16 v9; // di

  result = print_field(a2, a3, a4, "[levelStatCnt]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this < 0 )
      return -6;
    if ( v6 > 10 )
      return -7;
    result = sub_1024A3B0(a2, a3, 10, "[levelStatType]", v6);
    if ( !result )
    {
      v7 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          v8 = *this;
          if ( *this < 0 )
            return -6;
          if ( v8 > 10 )
            return -7;
          result = sub_1024A3B0(a2, a3, 10, "[levelStatValue]", v8);
          if ( !result )
          {
            v9 = 0;
            if ( *this <= 0 )
            {
              return TdrBuf::WriteChar(a2, a4);
            }
            else
            {
              while ( 1 )
              {
                result = Printf(a2, " %u", *((_DWORD *)this + v9 + 3));
                if ( result )
                  break;
                if ( ++v9 >= *this )
                  return TdrBuf::WriteChar(a2, a4);
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v7 + 2));
          if ( result )
            break;
          if ( ++v7 >= *this )
            goto LABEL_10;
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



