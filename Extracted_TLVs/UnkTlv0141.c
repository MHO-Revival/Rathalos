// ============================================================
// Name: TLV::UnkTlv0141::Read_0xAA
// Address Name: SUB_1017E050
// ============================================================
//----- (1017E050) --------------------------------------------------------
int __thiscall sub_1017E050(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 25) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_20:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 25) & 1) == 0 )
          *(_DWORD *)(v5 + 25) |= 1u;
        v9 = sub_101600D0(v4, (int *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 25) & 2) == 0 )
          *(_DWORD *)(v5 + 25) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          v11 = v16 + 8;
          v14 = v16 + 8;
          while ( 1 )
          {
            Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v11));
            if ( Byte )
              return Byte;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
            {
              v11 = v14;
              if ( (unsigned int)++v10 < 7 )
                continue;
            }
            v5 = v16;
LABEL_19:
            v7 = v13;
            if ( v4[1] >= v13 )
              goto LABEL_20;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 3u:
        if ( (*(_DWORD *)(v5 + 25) & 4) == 0 )
          *(_DWORD *)(v5 + 25) |= 4u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 15));
        if ( Byte )
          return Byte;
        goto LABEL_19;
      case 4u:
        if ( (*(_DWORD *)(v5 + 25) & 8) == 0 )
          *(_DWORD *)(v5 + 25) |= 8u;
        v9 = sub_101600D0(v4, (int *)(v5 + 16));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 25) & 0x10) == 0 )
          *(_DWORD *)(v5 + 25) |= 0x10u;
        v9 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 24));
        goto LABEL_7;
      default:
        v9 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_7:
        Byte = v9;
        if ( !v9 )
          goto LABEL_19;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0141::Read_0x99
// Address Name: SUB_1017E210
// ============================================================
//----- (1017E210) --------------------------------------------------------
int __thiscall sub_1017E210(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 25) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_20:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 25) & 1) == 0 )
          *(_DWORD *)(v5 + 25) |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 25) & 2) == 0 )
          *(_DWORD *)(v5 + 25) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          v11 = v16 + 8;
          v14 = v16 + 8;
          while ( 1 )
          {
            Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v11));
            if ( Byte )
              return Byte;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
            {
              v11 = v14;
              if ( (unsigned int)++v10 < 7 )
                continue;
            }
            v5 = v16;
LABEL_19:
            v7 = v13;
            if ( v4[1] >= v13 )
              goto LABEL_20;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 3u:
        if ( (*(_DWORD *)(v5 + 25) & 4) == 0 )
          *(_DWORD *)(v5 + 25) |= 4u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 15));
        if ( Byte )
          return Byte;
        goto LABEL_19;
      case 4u:
        if ( (*(_DWORD *)(v5 + 25) & 8) == 0 )
          *(_DWORD *)(v5 + 25) |= 8u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(v5 + 16));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 25) & 0x10) == 0 )
          *(_DWORD *)(v5 + 25) |= 0x10u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 24));
        goto LABEL_7;
      default:
        Int64 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_7:
        Byte = Int64;
        if ( !Int64 )
          goto LABEL_19;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0141::DoDebugFormat
// Address Name: SUB_1017E3F0
// ============================================================
//----- (1017E3F0) --------------------------------------------------------
int __thiscall sub_1017E3F0(_QWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1017E4A0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0141::DebugFormat
// Address Name: SUB_1017E4A0
// ============================================================
//----- (1017E4A0) --------------------------------------------------------
int __thiscall sub_1017E4A0(_QWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx

  result = print_field(a2, a3, a4, "[tCatTime]", "%I64i", *this);
  if ( !result )
  {
    if ( !"[vCatSeq]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s[0 : %I64i]:", "[vCatSeq]", 6LL);
      if ( !result )
      {
        v6 = 0;
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v6 + 8));
          if ( result )
            break;
          if ( (unsigned int)++v6 >= 7 )
          {
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0xC4u);
            v7 = a2[1];
            if ( (unsigned int)(a2[2] - v7) < 2 )
              return -1;
            *(_BYTE *)(v7 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            result = print_field(a2, a3, a4, "[iOpen]", "0x%02x", *((unsigned __int8 *)this + 15));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[tOpenTime]", "%I64i", *(this + 2));
              if ( !result )
                return print_field(a2, a3, a4, "[iTools]", "0x%02x", *((unsigned __int8 *)this + 24));
            }
            return result;
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101600D0
// ============================================================
//----- (101600D0) --------------------------------------------------------
int __thiscall sub_101600D0(_DWORD *this, int *a2)
{
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // edx
  int v6; // eax
  char v7; // al
  int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  unsigned int v15; // [esp+8h] [ebp-Ch]
  char v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  if ( *(this + 1) > *(this + 2) )
    _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x3DDu);
  v3 = 0;
  v4 = 0;
  v17 = 0;
  v15 = 0;
  *a2 = 0;
  a2[1] = 0;
  v5 = *(this + 1);
  if ( *(this + 2) != v5 )
  {
    v6 = v5 + *this;
    v16 = 0;
    while ( 1 )
    {
      v7 = *(_BYTE *)(v6 + v4);
      if ( (v7 & 0x7Fu) > 0xFFFFFFFFFFFFFFFFuLL >> v3 )
        break;
      *(_QWORD *)a2 |= (__int64)(v7 & 0x7F) << v16;
      v8 = *(this + 1);
      if ( *(char *)(v8 + *this + v4) < 0 )
      {
        ++v4;
        LOBYTE(v3) = v16 + 7;
        v16 += 7;
        v6 = v8 + *this;
        if ( v4 < *(this + 2) - v8 )
          continue;
      }
      v3 = 0;
      goto LABEL_9;
    }
    v3 = -1;
    v17 = -1;
  }
LABEL_9:
  v9 = *(this + 2) - *(this + 1);
  if ( v4 == v9 )
  {
    v10 = -1;
  }
  else
  {
    if ( !v3 && v9 )
      v15 = v4 + 1;
    v10 = v17;
  }
  v11 = a2[1];
  v12 = *a2;
  if ( (*a2 & 1) != 0 )
  {
    v12 = ~v12;
    v11 = ~v11;
  }
  v13 = *a2 << 31;
  *a2 = __PAIR64__(v11, v12) >> 1;
  a2[1] = v13 | (v11 >> 1) & 0x7FFFFFFF;
  if ( v10 )
    return -2;
  *(this + 1) += v15;
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



