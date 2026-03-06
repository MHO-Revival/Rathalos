// ============================================================
// Name: TLV::UnkTlv0118::Read
// Address Name: SUB_1016EE00
// ============================================================
//----- (1016EE00) --------------------------------------------------------
int __thiscall sub_1016EE00(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  int v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = a2 - 5;
  if ( v7 == -86 )
    result = sub_1016EED0(this, &v9, v8);
  else
    result = sub_1016F050(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0118::Read_0xAA
// Address Name: SUB_1016EED0
// ============================================================
//----- (1016EED0) --------------------------------------------------------
int __thiscall sub_1016EED0(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  int *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(int *)((char *)this + 654) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (*((_BYTE *)v3 + 654) & 1) == 0 )
          *(int *)((char *)v3 + 654) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(int *)((char *)v3 + 654) & 2) == 0 )
            *(int *)((char *)v3 + 654) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v8 = 0;
          v16 = a2[1];
          v12 = v13 + 1;
          while ( 1 )
          {
            v15 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v15);
            if ( v4 )
              return v4;
            if ( v15 )
            {
              v4 = sub_1016E6A0((int)v12, a2, v15);
              if ( v4 )
                return v4;
            }
            v9 = a2[1];
            if ( v9 > v16 + v11 )
              return -34;
            if ( v9 == v16 + v11 )
            {
              v10 = v8 + 1;
              v3 = v13;
              *v13 = v10;
              goto LABEL_23;
            }
            v12 = (_DWORD *)((char *)v12 + 13);
            if ( ++v8 >= 50 )
            {
              v3 = v13;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(a2, v14 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
LABEL_23:
      v5 = v17;
      if ( a2[1] >= v17 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0118::Read_0x99
// Address Name: SUB_1016F050
// ============================================================
//----- (1016F050) --------------------------------------------------------
int __thiscall sub_1016F050(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 654) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (*((_BYTE *)v3 + 654) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 654) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(_DWORD *)((char *)v3 + 654) & 2) == 0 )
            *(_DWORD *)((char *)v3 + 654) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v8 = 0;
          v16 = a2[1];
          v12 = v13 + 1;
          while ( 1 )
          {
            v15 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v15);
            if ( v4 )
              return v4;
            if ( v15 )
            {
              v4 = sub_1016E7B0((int)v12, a2, v15);
              if ( v4 )
                return v4;
            }
            v9 = a2[1];
            if ( v9 > v16 + v11 )
              return -34;
            if ( v9 == v16 + v11 )
            {
              v10 = v8 + 1;
              v3 = v13;
              *v13 = v10;
              goto LABEL_23;
            }
            v12 = (_DWORD *)((char *)v12 + 13);
            if ( ++v8 >= 50 )
            {
              v3 = v13;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(a2, v14 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
LABEL_23:
      v5 = v17;
      if ( a2[1] >= v17 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0118::DoDebugFormat
// Address Name: SUB_1016F1F0
// ============================================================
//----- (1016F1F0) --------------------------------------------------------
int __thiscall sub_1016F1F0(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1016F2A0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0118::DebugFormat
// Address Name: SUB_1016F2A0
// ============================================================
//----- (1016F2A0) --------------------------------------------------------
int __thiscall sub_1016F2A0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 50 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i = (_DWORD *)((char *)i + 13) )
          {
            if ( !"[data]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[data]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1016E980(i, a2, a3 + 1, a4) : sub_1016E980(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016E6A0
// ============================================================
//----- (1016E6A0) --------------------------------------------------------
int __thiscall sub_1016E6A0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        if ( v9 >> 4 == 3 )
        {
          if ( (*(_DWORD *)(this + 9) & 4) == 0 )
            *(_DWORD *)(this + 9) |= 4u;
          VarUInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 5));
        }
        else
        {
          VarUInt = TdrBuf::SkipField(a2, v9 & 0xF);
        }
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    VarUInt = TdrBuf::ReadVarInt(a2, (int *)this);
LABEL_19:
    v4 = VarUInt;
    if ( VarUInt )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016E7B0
// ============================================================
//----- (1016E7B0) --------------------------------------------------------
int __thiscall sub_1016E7B0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        if ( v9 >> 4 == 3 )
        {
          if ( (*(_DWORD *)(this + 9) & 4) == 0 )
            *(_DWORD *)(this + 9) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 5));
        }
        else
        {
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        }
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 4) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_19:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
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
// Address Name: SUB_1016E980
// ============================================================
//----- (1016E980) --------------------------------------------------------
int __thiscall sub_1016E980(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nGroupID]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[bType]", "0x%02x", *((unsigned __int8 *)this + 4));
    if ( !result )
      return print_field(a2, a3, a4, "[nTime]", "%u", *(_DWORD *)((char *)this + 5));
  }
  return result;
}



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



