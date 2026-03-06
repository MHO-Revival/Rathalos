// ============================================================
// Name: TLV::UnkTlv0158::Read
// Address Name: SUB_1018C4E0
// ============================================================
//----- (1018C4E0) --------------------------------------------------------
int __thiscall sub_1018C4E0(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1018C5B0(this, &v9, v8);
  else
    result = sub_1018C730((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0158::Read_0xAA
// Address Name: SUB_1018C5B0
// ============================================================
//----- (1018C5B0) --------------------------------------------------------
int __thiscall sub_1018C5B0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // ecx
  unsigned int v14; // edx
  char v15; // al
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(this + 33) = 0;
  v7 = a2[1] + v3;
  v16 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_24:
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
      if ( v18 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 33) & 1) == 0 )
          *(this + 33) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, this);
      }
      else
      {
        if ( v18 >> 4 == 2 )
        {
          if ( (*(this + 33) & 2) == 0 )
            *(this + 33) |= 2u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( !result )
          {
            v10 = a3;
            if ( a3 )
            {
              v11 = v4[1];
              v12 = 0;
              v17 = v11;
              while ( 1 )
              {
                if ( v11 > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v13 = v4[1];
                if ( v4[2] == v13 )
                  return -2;
                v14 = v17 + v10;
                v15 = *(_BYTE *)(v13 + *v4);
                v6 = 0;
                *((_BYTE *)this + v12 + 4) = v15;
                v11 = ++v4[1];
                v4 = a2;
                if ( v11 > v14 )
                  return -34;
                if ( v11 == v14 )
                {
                  *this = v12 + 1;
                  goto LABEL_23;
                }
                v10 = a3;
                if ( ++v12 >= 128 )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        VarInt = TdrBuf::SkipField(v4, v18 & 0xF);
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_23:
      v7 = v16;
      if ( v4[1] >= v16 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0158::Read_0x99
// Address Name: SUB_1018C730
// ============================================================
//----- (1018C730) --------------------------------------------------------
int __thiscall sub_1018C730(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // ecx
  unsigned int v14; // edx
  char v15; // al
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(_DWORD *)(this + 132) = 0;
  v7 = a2[1] + v3;
  v16 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_24:
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
      if ( v18 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 132) & 1) == 0 )
          *(_DWORD *)(this + 132) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
      }
      else
      {
        if ( v18 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 132) & 2) == 0 )
            *(_DWORD *)(this + 132) |= 2u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( !result )
          {
            v10 = a3;
            if ( a3 )
            {
              v11 = v4[1];
              v12 = 0;
              v17 = v11;
              while ( 1 )
              {
                if ( v11 > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v13 = v4[1];
                if ( v4[2] == v13 )
                  return -2;
                v14 = v17 + v10;
                v15 = *(_BYTE *)(v13 + *v4);
                v6 = 0;
                *(_BYTE *)(v12 + this + 4) = v15;
                v11 = ++v4[1];
                v4 = a2;
                if ( v11 > v14 )
                  return -34;
                if ( v11 == v14 )
                {
                  *(_DWORD *)this = v12 + 1;
                  goto LABEL_23;
                }
                v10 = a3;
                if ( ++v12 >= 128 )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_23:
      v7 = v16;
      if ( v4[1] >= v16 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0158::DoDebugFormat
// Address Name: SUB_1018C8D0
// ============================================================
//----- (1018C8D0) --------------------------------------------------------
int __thiscall sub_1018C8D0(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1018C980(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0158::DebugFormat
// Address Name: SUB_1018C980
// ============================================================
//----- (1018C980) --------------------------------------------------------
int __thiscall sub_1018C980(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 128 )
      {
        result = sub_1024A3B0(a2, a3, v6, "[completeBit]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *this <= 0 )
          {
            return TdrBuf::WriteChar(a2, a4);
          }
          else
          {
            while ( 1 )
            {
              result = Printf(a2, " 0x%02x", *((char *)this + v8 + 4));
              if ( result )
                break;
              if ( ++v8 >= *this )
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
// 1018C9DD: variable 'v6' is possibly undefined



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



