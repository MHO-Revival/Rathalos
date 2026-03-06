// ============================================================
// Name: TLV::UnkTlv0238::Read_0xAA
// Address Name: SUB_10218990
// ============================================================
//----- (10218990) --------------------------------------------------------
int __thiscall sub_10218990(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUShort; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  unsigned int v16; // [esp+14h] [ebp-8h] BYREF
  int v17; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 93) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        return result;
      if ( v16 >> 4 == 1 )
        break;
      if ( v16 >> 4 != 2 )
      {
        if ( v16 >> 4 == 3 )
        {
          if ( (*(_DWORD *)(v5 + 93) & 4) == 0 )
            *(_DWORD *)(v5 + 93) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v15 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10218160((char *)(v17 + 8 * v10 + 3 + v10), v4, a3);
              if ( v6 )
                return v6;
            }
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v15 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v15) )
            {
              v12 = v17;
              *(_BYTE *)(v17 + 2) = v10 + 1;
              v5 = v12;
              goto LABEL_30;
            }
            if ( ++v10 >= 0xAu )
            {
              v5 = v17;
              goto LABEL_30;
            }
          }
        }
        VarUShort = TdrBuf::SkipField(v4, v16 & 0xF);
        goto LABEL_29;
      }
      if ( (*(_DWORD *)(v5 + 93) & 2) == 0 )
        *(_DWORD *)(v5 + 93) |= 2u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v13 = v4[1];
      if ( v4[2] == v13 )
        return -2;
      *(_BYTE *)(v5 + 2) = *(_BYTE *)(v13 + *v4);
      ++v4[1];
      v6 = 0;
LABEL_30:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_31;
    }
    if ( (*(_BYTE *)(v5 + 93) & 1) == 0 )
      *(_DWORD *)(v5 + 93) |= 1u;
    VarUShort = TdrBuf::ReadVarUShort(v4, (_WORD *)v5);
LABEL_29:
    v6 = VarUShort;
    if ( VarUShort )
      return v6;
    goto LABEL_30;
  }
LABEL_31:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: TLV::UnkTlv0238::Read_0x99
// Address Name: SUB_10218B60
// ============================================================
//----- (10218B60) --------------------------------------------------------
int __thiscall sub_10218B60(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  unsigned int v16; // [esp+14h] [ebp-8h] BYREF
  int v17; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 93) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        return result;
      if ( v16 >> 4 == 1 )
        break;
      if ( v16 >> 4 != 2 )
      {
        if ( v16 >> 4 == 3 )
        {
          if ( (*(_DWORD *)(v5 + 93) & 4) == 0 )
            *(_DWORD *)(v5 + 93) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v15 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10218250((char *)(v17 + 8 * v10 + 3 + v10), v4, a3);
              if ( v6 )
                return v6;
            }
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v15 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v15) )
            {
              v12 = v17;
              *(_BYTE *)(v17 + 2) = v10 + 1;
              v5 = v12;
              goto LABEL_30;
            }
            if ( ++v10 >= 0xAu )
            {
              v5 = v17;
              goto LABEL_30;
            }
          }
        }
        Int16 = TdrBuf::SkipField(v4, v16 & 0xF);
        goto LABEL_29;
      }
      if ( (*(_DWORD *)(v5 + 93) & 2) == 0 )
        *(_DWORD *)(v5 + 93) |= 2u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v13 = v4[1];
      if ( v4[2] == v13 )
        return -2;
      *(_BYTE *)(v5 + 2) = *(_BYTE *)(v13 + *v4);
      ++v4[1];
      v6 = 0;
LABEL_30:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_31;
    }
    if ( (*(_BYTE *)(v5 + 93) & 1) == 0 )
      *(_DWORD *)(v5 + 93) |= 1u;
    Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)v5);
LABEL_29:
    v6 = Int16;
    if ( Int16 )
      return v6;
    goto LABEL_30;
  }
LABEL_31:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: TLV::UnkTlv0238::DoDebugFormat
// Address Name: SUB_10218D50
// ============================================================
//----- (10218D50) --------------------------------------------------------
int __thiscall sub_10218D50(unsigned __int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10218E00(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0238::DebugFormat
// Address Name: SUB_10218E00
// ============================================================
//----- (10218E00) --------------------------------------------------------
int __thiscall sub_10218E00(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  unsigned __int8 *v8; // ecx

  result = print_field(a2, a3, a4, "[cardId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[targetNum]", "0x%02x", *((unsigned __int8 *)this + 2));
    if ( !result )
    {
      v6 = *((_BYTE *)this + 2);
      if ( v6 <= 0xAu )
      {
        v7 = 0;
        if ( v6 )
        {
          while ( 1 )
          {
            if ( !"[targetList]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[targetList]", v7, a4);
            if ( result )
              break;
            v8 = (unsigned __int8 *)this + 8 * v7 + v7 + 3;
            result = a3 >= 0 ? sub_10218440(v8, a2, a3 + 1, a4) : sub_10218440(v8, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *((_BYTE *)this + 2) )
              return 0;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return -7;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10218160
// ============================================================
//----- (10218160) --------------------------------------------------------
int __thiscall sub_10218160(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadVarUInt(a2, this + 1);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10218250
// ============================================================
//----- (10218250) --------------------------------------------------------
int __thiscall sub_10218250(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 1);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
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
// Address Name: SUB_10218440
// ============================================================
//----- (10218440) --------------------------------------------------------
int __thiscall sub_10218440(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[targetIdx]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[targetData]", "%u", *(_DWORD *)(this + 1));
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



