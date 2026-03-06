// ============================================================
// Name: TLV::UnkTlv0264::Read_0xAA
// Address Name: SUB_10229EF0
// ============================================================
//----- (10229EF0) --------------------------------------------------------
int __thiscall sub_10229EF0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int *v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int *v17; // [esp+18h] [ebp-8h]
  unsigned int v18; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(this + 32) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_26:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      switch ( v18 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 32) & 1) == 0 )
            *(this + 32) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          break;
        case 2u:
          if ( (*(this + 32) & 2) == 0 )
            *(this + 32) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 1);
          break;
        case 3u:
          if ( (*(this + 32) & 4) == 0 )
            *(this + 32) |= 4u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( result )
            return result;
          if ( !a3 )
            return -37;
          v10 = this + 2;
          v16 = v4[1];
          v11 = 0;
          v12 = a2;
          v17 = this + 2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadVarInt(v12, v10);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v16 )
              return -34;
            if ( v13 == a3 + v16 )
            {
              v14 = v11 + 1;
              v4 = a2;
              *(this + 1) = v14;
              goto LABEL_25;
            }
            ++v11;
            v10 = ++v17;
            if ( v11 >= 30 )
            {
              v4 = a2;
              goto LABEL_25;
            }
          }
        default:
          VarInt = TdrBuf::SkipField(v4, v18 & 0xF);
          break;
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_25:
      v7 = v15;
      if ( v4[1] >= v15 )
        goto LABEL_26;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0264::Read_0x99
// Address Name: SUB_1022A070
// ============================================================
//----- (1022A070) --------------------------------------------------------
int __thiscall sub_1022A070(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _BYTE *v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  unsigned int v18; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(_DWORD *)(this + 128) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_26:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      switch ( v18 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 128) & 1) == 0 )
            *(_DWORD *)(this + 128) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 128) & 2) == 0 )
            *(_DWORD *)(this + 128) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 128) & 4) == 0 )
            *(_DWORD *)(this + 128) |= 4u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( result )
            return result;
          if ( !a3 )
            return -37;
          v10 = (_BYTE *)(this + 8);
          v16 = v4[1];
          v11 = 0;
          v12 = a2;
          v17 = this + 8;
          while ( 1 )
          {
            v6 = TdrBuf::ReadInt32(v12, v10);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v16 )
              return -34;
            if ( v13 == a3 + v16 )
            {
              v14 = v11 + 1;
              v4 = a2;
              *(_DWORD *)(this + 4) = v14;
              goto LABEL_25;
            }
            ++v11;
            v10 = (_BYTE *)(v17 + 4);
            v17 += 4;
            if ( v11 >= 30 )
            {
              v4 = a2;
              goto LABEL_25;
            }
          }
        default:
          Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
          break;
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_25:
      v7 = v15;
      if ( v4[1] >= v15 )
        goto LABEL_26;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0264::DoDebugFormat
// Address Name: SUB_1022A210
// ============================================================
//----- (1022A210) --------------------------------------------------------
int __thiscall sub_1022A210(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1022A2C0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0264::DebugFormat
// Address Name: SUB_1022A2C0
// ============================================================
//----- (1022A2C0) --------------------------------------------------------
int __thiscall sub_1022A2C0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[groupId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[preferNum]", "%d", *(this + 1));
    if ( !result )
    {
      v7 = *(this + 1);
      if ( v7 >= 0 )
      {
        if ( v7 <= 30 )
        {
          result = sub_1024A3B0(a2, a3, v6, "[preferIds]", v7);
          if ( !result )
          {
            v8 = 0;
            if ( (int)*(this + 1) <= 0 )
            {
              return TdrBuf::WriteChar(a2, a4);
            }
            else
            {
              for ( i = this + 2; ; ++i )
              {
                result = Printf(a2, " %d", *i);
                if ( result )
                  break;
                if ( ++v8 >= *(this + 1) )
                  return TdrBuf::WriteChar(a2, a4);
              }
            }
          }
        }
        else
        {
          return -7;
        }
      }
      else
      {
        return -6;
      }
    }
  }
  return result;
}
// 1022A33E: variable 'v6' is possibly undefined



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



