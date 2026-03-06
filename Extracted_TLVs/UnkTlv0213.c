// ============================================================
// Name: TLV::UnkTlv0213::Read_0xAA
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
// Name: TLV::UnkTlv0213::Read_0x99
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
// Name: TLV::UnkTlv0213::DoDebugFormat
// Address Name: SUB_10200D40
// ============================================================
//----- (10200D40) --------------------------------------------------------
int __thiscall sub_10200D40(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10200DF0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0213::DebugFormat
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



