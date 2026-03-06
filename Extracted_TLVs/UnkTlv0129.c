// ============================================================
// Name: TLV::UnkTlv0129::Read
// Address Name: SUB_10176160
// ============================================================
//----- (10176160) --------------------------------------------------------
int __thiscall sub_10176160(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  int *v8; // [esp-Ch] [ebp-1Ch]
  unsigned int v9; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  v9 = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&v9, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&v9, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = (int *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_10176230(this, &v9, v8);
  else
    result = sub_101764A0(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0129::Read_0xAA
// Address Name: SUB_10176230
// ============================================================
//----- (10176230) --------------------------------------------------------
int __thiscall sub_10176230(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  unsigned int v21; // [esp+14h] [ebp-8h] BYREF
  int *v22; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(this + 303) = 0;
  v21 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (v4[303] & 1) == 0 )
          v4[303] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_36;
      case 6u:
        if ( (v4[303] & 2) == 0 )
          v4[303] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_36;
      case 7u:
        if ( (v4[303] & 4) == 0 )
          v4[303] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v22 + 2;
        a3 = v22 + 2;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 200 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        v22[1] = v13;
        goto LABEL_37;
      case 8u:
        if ( (v4[303] & 8) == 0 )
          v4[303] |= 8u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 202);
        goto LABEL_36;
      case 9u:
        if ( (v4[303] & 0x10) == 0 )
          v4[303] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = v6[1];
        v15 = v22 + 203;
        a3 = v22 + 203;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v20) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 100 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        v22[202] = v17;
LABEL_37:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v21 & 0xF);
LABEL_36:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_37;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0129::Read_0x99
// Address Name: SUB_101764A0
// ============================================================
//----- (101764A0) --------------------------------------------------------
int __thiscall sub_101764A0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  unsigned int v21; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v22; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(this + 303) = 0;
  v21 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (v4[303] & 1) == 0 )
          v4[303] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_36;
      case 6u:
        if ( (v4[303] & 2) == 0 )
          v4[303] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_36;
      case 7u:
        if ( (v4[303] & 4) == 0 )
          v4[303] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v22 + 2;
        a3 = v22 + 2;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 200 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        v22[1] = v13;
        goto LABEL_37;
      case 8u:
        if ( (v4[303] & 8) == 0 )
          v4[303] |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 808);
        goto LABEL_36;
      case 9u:
        if ( (v4[303] & 0x10) == 0 )
          v4[303] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = v6[1];
        v15 = v22 + 203;
        a3 = v22 + 203;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v20) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 100 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        v22[202] = v17;
LABEL_37:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v21 & 0xF);
LABEL_36:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_37;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0129::DoDebugFormat
// Address Name: SUB_10176730
// ============================================================
//----- (10176730) --------------------------------------------------------
int __thiscall sub_10176730(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101767E0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0129::DebugFormat
// Address Name: SUB_101767E0
// ============================================================
//----- (101767E0) --------------------------------------------------------
int __thiscall sub_101767E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[points]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[ctxCount]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 200 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[ctxInfo]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_13:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            result = print_field(v4, a3, a4, "[prizesCount]", "%d", *(this + 202));
            if ( !result )
            {
              v12 = *(this + 202);
              if ( v12 < 0 )
                return -6;
              if ( v12 > 100 )
                return -7;
              result = sub_1024A3B0(v4, a3, v11, "[prizesID]", v12);
              if ( !result )
              {
                v13 = 0;
                if ( (int)*(this + 202) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = this + 203; ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v13 >= *(this + 202) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v10 = this + 2;
          while ( 1 )
          {
            result = Printf(a2, " %d", *v10);
            if ( result )
              break;
            ++v9;
            ++v10;
            if ( v9 >= *(this + 1) )
            {
              v4 = a2;
              goto LABEL_13;
            }
          }
        }
      }
    }
  }
  return result;
}
// 10176865: variable 'v7' is possibly undefined
// 101768FF: variable 'v11' is possibly undefined



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



