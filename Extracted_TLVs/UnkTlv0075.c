// ============================================================
// Name: TLV::UnkTlv0075::Read
// Address Name: SUB_1014AB70
// ============================================================
//----- (1014AB70) --------------------------------------------------------
int __thiscall sub_1014AB70(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1014AC40((int)this, &v9, v8);
  else
    result = sub_1014AE00((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0075::Read_0xAA
// Address Name: SUB_1014AC40
// ============================================================
//----- (1014AC40) --------------------------------------------------------
int __thiscall sub_1014AC40(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  v9 = 0;
  *(_DWORD *)(this + 126) = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      return result;
    switch ( v9 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadVarUInt(a2, (_DWORD *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        v8 = 0;
        result = TdrBuf::ReadInt32(a2, &v8);
        if ( result )
          return result;
        if ( !v8 )
          return -37;
        v6 = 0;
        v11 = a2[1];
        while ( 1 )
        {
          v10 = 0;
          result = TdrBuf::ReadInt32(a2, &v10);
          if ( result )
            return result;
          if ( v10 )
          {
            result = sub_1014A460((int *)(this + 6 + 12 * v6), a2, v10);
            if ( result )
              return result;
          }
          v7 = a2[1];
          if ( v7 > v11 + v8 )
            return -34;
          if ( v7 == v11 + v8 )
            break;
          if ( ++v6 >= 0xAu )
            goto LABEL_28;
        }
        *(_BYTE *)(this + 5) = v6 + 1;
LABEL_28:
        v5 = v12;
        if ( a2[1] < v12 )
          continue;
LABEL_29:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v9 & 0xF);
LABEL_27:
        if ( !result )
          goto LABEL_28;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0075::Read_0x99
// Address Name: SUB_1014AE00
// ============================================================
//----- (1014AE00) --------------------------------------------------------
int __thiscall sub_1014AE00(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  v9 = 0;
  *(_DWORD *)(this + 126) = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      return result;
    switch ( v9 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadInt32(a2, (_BYTE *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        v8 = 0;
        result = TdrBuf::ReadInt32(a2, &v8);
        if ( result )
          return result;
        if ( !v8 )
          return -37;
        v6 = 0;
        v11 = a2[1];
        while ( 1 )
        {
          v10 = 0;
          result = TdrBuf::ReadInt32(a2, &v10);
          if ( result )
            return result;
          if ( v10 )
          {
            result = sub_1014A500(this + 6 + 12 * v6, a2, v10);
            if ( result )
              return result;
          }
          v7 = a2[1];
          if ( v7 > v11 + v8 )
            return -34;
          if ( v7 == v11 + v8 )
            break;
          if ( ++v6 >= 0xAu )
            goto LABEL_28;
        }
        *(_BYTE *)(this + 5) = v6 + 1;
LABEL_28:
        v5 = v12;
        if ( a2[1] < v12 )
          continue;
LABEL_29:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v9 & 0xF);
LABEL_27:
        if ( !result )
          goto LABEL_28;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0075::DoDebugFormat
// Address Name: SUB_1014AFE0
// ============================================================
//----- (1014AFE0) --------------------------------------------------------
int __thiscall sub_1014AFE0(_BYTE *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1014B090(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0075::DebugFormat
// Address Name: SUB_1014B090
// ============================================================
//----- (1014B090) --------------------------------------------------------
int __thiscall sub_1014B090(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  int v8; // [esp-8h] [ebp-18h]

  result = print_field(a2, a3, a4, "[lastRefreshTm]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[rewardCnt]", "0x%02x", (unsigned __int8)*(this + 4));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[levelCnt]", "0x%02x", (unsigned __int8)*(this + 5));
      if ( !result )
      {
        v6 = *(this + 5);
        if ( v6 <= 0xAu )
        {
          v7 = 0;
          if ( v6 )
          {
            while ( 1 )
            {
              if ( !"[warningData]" )
                _wassert(
                  L"NULL != variable",
                  L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                  0x43u);
              result = sub_1024A140(a3);
              if ( result )
                break;
              result = Printf(a2, "%s[%u]%c", "[warningData]", v7, a4);
              if ( result )
                break;
              v8 = a3 >= 0 ? a3 + 1 : a3;
              result = sub_1014A6A0(this + 12 * v7 + 6, a2, v8, a4);
              if ( result )
                break;
              if ( ++v7 >= *(this + 5) )
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
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014A460
// ============================================================
//----- (1014A460) --------------------------------------------------------
int __thiscall sub_1014A460(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarUInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014A500
// ============================================================
//----- (1014A500) --------------------------------------------------------
int __thiscall sub_1014A500(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        break;
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
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
// Address Name: SUB_1014A6A0
// ============================================================
//----- (1014A6A0) --------------------------------------------------------
int __thiscall sub_1014A6A0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[levelId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[warningTime]", "%u", *(this + 1));
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



