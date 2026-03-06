// ============================================================
// Name: TLV::UnkTlv0187::Read_0xAA
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
// Name: TLV::UnkTlv0187::Read_0x99
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
// Name: TLV::UnkTlv0187::DoDebugFormat
// Address Name: SUB_101AE700
// ============================================================
//----- (101AE700) --------------------------------------------------------
int __thiscall sub_101AE700(float *this, int a2, int a3, signed __int32 a4, int a5, _DWORD *a6, int a7, char a8)
{
  int v9; // esi
  signed __int32 v10; // [esp+8h] [ebp-1Ch] BYREF
  int v11; // [esp+Ch] [ebp-18h]
  int v12; // [esp+10h] [ebp-14h]
  char v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  if ( !a4 )
    return -19;
  v10 = a4;
  v13 = 0;
  v11 = 0;
  v12 = a5;
  v14 = 0;
  v9 = sub_101AE7B0(this, a2, a3, &v10, a7, a8);
  if ( a6 )
    *a6 = v11;
  if ( v13 )
    sub_10C3DA30(v10);
  return v9;
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



