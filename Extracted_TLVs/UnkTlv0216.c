// ============================================================
// Name: TLV::UnkTlv0216::Read_0xAA
// Address Name: SUB_10202EE0
// ============================================================
//----- (10202EE0) --------------------------------------------------------
int __thiscall sub_10202EE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarShort; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // esi
  int *v10; // ebx
  unsigned int v11; // edx
  _DWORD *v12; // ebx
  int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarShort = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 5030) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_19;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5030) & 1) == 0 )
          *(_DWORD *)(this + 5030) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)this);
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
      case 2u:
        if ( (*(_DWORD *)(this + 5030) & 2) == 0 )
          *(_DWORD *)(this + 5030) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        a3 = v6[1];
        v10 = (int *)(this + 2);
        while ( 1 )
        {
          VarShort = TdrBuf::ReadVarInt(v6, v10);
          if ( VarShort )
            return VarShort;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v9;
            ++v10;
            if ( v9 < 6 )
              continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (*(_DWORD *)(this + 5030) & 4) == 0 )
          *(_DWORD *)(this + 5030) |= 4u;
        VarShort = TdrBuf::ReadVarInt(v6, (int *)(this + 26));
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
      case 4u:
        if ( (*(_DWORD *)(this + 5030) & 8) == 0 )
          *(_DWORD *)(this + 5030) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v12 = a2;
        if ( !a2 )
          return -37;
        v13 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarShort = TdrBuf::ReadByte(v6, (_BYTE *)(v13 + v17 + 30));
          if ( VarShort )
            return VarShort;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v12) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v12) )
            break;
          if ( ++v13 >= 5000 )
          {
LABEL_17:
            this = v17;
            goto LABEL_18;
          }
        }
        this = v17;
        *(_DWORD *)(v17 + 26) = v13 + 1;
LABEL_18:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_19:
        if ( v6[1] > v7 )
          return -34;
        return VarShort;
      default:
        VarShort = TdrBuf::SkipField(v6, v16 & 0xF);
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0216::Read_0x99
// Address Name: SUB_102030F0
// ============================================================
//----- (102030F0) --------------------------------------------------------
int __thiscall sub_102030F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int Int16; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // esi
  _BYTE *v10; // ebx
  unsigned int v11; // edx
  _DWORD *v12; // ebx
  int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  Int16 = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 5030) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_19;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5030) & 1) == 0 )
          *(_DWORD *)(this + 5030) |= 1u;
        Int16 = TdrBuf::ReadInt16(v6, (_BYTE *)this);
        if ( Int16 )
          return Int16;
        goto LABEL_18;
      case 2u:
        if ( (*(_DWORD *)(this + 5030) & 2) == 0 )
          *(_DWORD *)(this + 5030) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        a3 = v6[1];
        v10 = (_BYTE *)(this + 2);
        while ( 1 )
        {
          Int16 = TdrBuf::ReadInt32(v6, v10);
          if ( Int16 )
            return Int16;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v9;
            v10 += 4;
            if ( v9 < 6 )
              continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (*(_DWORD *)(this + 5030) & 4) == 0 )
          *(_DWORD *)(this + 5030) |= 4u;
        Int16 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 26));
        if ( Int16 )
          return Int16;
        goto LABEL_18;
      case 4u:
        if ( (*(_DWORD *)(this + 5030) & 8) == 0 )
          *(_DWORD *)(this + 5030) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v12 = a2;
        if ( !a2 )
          return -37;
        v13 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          Int16 = TdrBuf::ReadByte(v6, (_BYTE *)(v13 + v17 + 30));
          if ( Int16 )
            return Int16;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v12) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v12) )
            break;
          if ( ++v13 >= 5000 )
          {
LABEL_17:
            this = v17;
            goto LABEL_18;
          }
        }
        this = v17;
        *(_DWORD *)(v17 + 26) = v13 + 1;
LABEL_18:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_19:
        if ( v6[1] > v7 )
          return -34;
        return Int16;
      default:
        Int16 = TdrBuf::SkipField(v6, v16 & 0xF);
        if ( Int16 )
          return Int16;
        goto LABEL_18;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0216::DoDebugFormat
// Address Name: SUB_10203320
// ============================================================
//----- (10203320) --------------------------------------------------------
int __thiscall sub_10203320(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_102033D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0216::DebugFormat
// Address Name: SUB_102033D0
// ============================================================
//----- (102033D0) --------------------------------------------------------
int __thiscall sub_102033D0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned int v6; // esi
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // esi

  result = print_field(a2, a3, a4, "[index]", "%d", *this);
  if ( !result )
  {
    if ( !"[equipID]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s[0 : %I64i]:", "[equipID]", 5LL);
      if ( !result )
      {
        v6 = 0;
        v7 = this + 1;
        while ( 1 )
        {
          result = Printf(a2, " %d", *v7);
          if ( result )
            break;
          ++v6;
          ++v7;
          if ( v6 >= 6 )
          {
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0xC4u);
            v8 = a2[1];
            if ( (unsigned int)(a2[2] - v8) < 2 )
              return -1;
            *(_BYTE *)(v8 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            result = print_field(a2, a3, a4, "[dataLen]", "%d", *(_DWORD *)(this + 13));
            if ( !result )
            {
              v10 = *(_DWORD *)(this + 13);
              if ( v10 >= 0 )
              {
                if ( v10 <= 5000 )
                {
                  result = sub_1024A3B0(a2, a3, v9, "[equipData]", v10);
                  if ( !result )
                  {
                    v11 = 0;
                    if ( *(int *)(this + 13) <= 0 )
                    {
                      return TdrBuf::WriteChar(a2, a4);
                    }
                    else
                    {
                      while ( 1 )
                      {
                        result = Printf(a2, " %d", *((unsigned __int8 *)this + v11 + 30));
                        if ( result )
                          break;
                        if ( ++v11 >= *(_DWORD *)(this + 13) )
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
            return result;
          }
        }
      }
    }
  }
  return result;
}
// 10203523: variable 'v9' is possibly undefined



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



