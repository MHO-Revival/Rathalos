// ============================================================
// Name: TLV::UnkTlv0041::Read_0xAA
// Address Name: SUB_1012ED80
// ============================================================
//----- (1012ED80) --------------------------------------------------------
int __thiscall sub_1012ED80(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 13) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 13) & 1) == 0 )
            *(_DWORD *)(this + 13) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 13) & 2) == 0 )
            *(_DWORD *)(this + 13) |= 2u;
          VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 4));
          goto LABEL_20;
        case 3u:
          if ( (*(_DWORD *)(this + 13) & 4) == 0 )
            *(_DWORD *)(this + 13) |= 4u;
          VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 8));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 13) & 8) == 0 )
            *(_DWORD *)(this + 13) |= 8u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 12) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = VarInt;
          if ( !VarInt )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: TLV::UnkTlv0041::Read_0x99
// Address Name: SUB_1012EED0
// ============================================================
//----- (1012EED0) --------------------------------------------------------
int __thiscall sub_1012EED0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 13) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 13) & 1) == 0 )
            *(_DWORD *)(this + 13) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 13) & 2) == 0 )
            *(_DWORD *)(this + 13) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          goto LABEL_20;
        case 3u:
          if ( (*(_DWORD *)(this + 13) & 4) == 0 )
            *(_DWORD *)(this + 13) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 13) & 8) == 0 )
            *(_DWORD *)(this + 13) |= 8u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 12) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = Int32;
          if ( !Int32 )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: TLV::UnkTlv0041::DoDebugFormat
// Address Name: SUB_1012F040
// ============================================================
//----- (1012F040) --------------------------------------------------------
int __thiscall sub_1012F040(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1012F0F0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0041::DebugFormat
// Address Name: SUB_1012F0F0
// ============================================================
//----- (1012F0F0) --------------------------------------------------------
int __thiscall sub_1012F0F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[goodsNumber]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[lastChangeTime]", "%u", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[isOwned]", "0x%02x", *((char *)this + 12));
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



