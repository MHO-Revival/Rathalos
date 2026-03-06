// ============================================================
// Name: TLV::UnkTlv0156::Read
// Address Name: SUB_1018A670
// ============================================================
//----- (1018A670) --------------------------------------------------------
int __thiscall sub_1018A670(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1018A740(this, &v9, v8);
  else
    result = sub_1018A820((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0156::Read_0xAA
// Address Name: SUB_1018A740
// ============================================================
//----- (1018A740) --------------------------------------------------------
int __thiscall sub_1018A740(int *this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(this + 11) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        return result;
      if ( v8 >> 4 == 1 )
        break;
      if ( v8 >> 4 != 2 )
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_14;
      }
      if ( (*(this + 11) & 2) == 0 )
        *(this + 11) |= 2u;
      v9 = 0;
      v4 = TdrBuf::ReadInt32(a2, &v9);
      if ( v4 )
        return v4;
      if ( v9 )
      {
        VarInt = sub_102070B0(this + 1, a2, v9);
        goto LABEL_14;
      }
LABEL_15:
      v5 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_16;
    }
    if ( (*(_BYTE *)(this + 11) & 1) == 0 )
      *(this + 11) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, this);
LABEL_14:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_15;
  }
LABEL_16:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: TLV::UnkTlv0156::Read_0x99
// Address Name: SUB_1018A820
// ============================================================
//----- (1018A820) --------------------------------------------------------
int __thiscall sub_1018A820(int this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 44) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        return result;
      if ( v8 >> 4 == 1 )
        break;
      if ( v8 >> 4 != 2 )
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_14;
      }
      if ( (*(_DWORD *)(this + 44) & 2) == 0 )
        *(_DWORD *)(this + 44) |= 2u;
      v9 = 0;
      v4 = TdrBuf::ReadInt32(a2, &v9);
      if ( v4 )
        return v4;
      if ( v9 )
      {
        Int32 = sub_10207260(this + 4, a2, v9);
        goto LABEL_14;
      }
LABEL_15:
      v5 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_16;
    }
    if ( (*(_BYTE *)(this + 44) & 1) == 0 )
      *(_DWORD *)(this + 44) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_14:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_15;
  }
LABEL_16:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: TLV::UnkTlv0156::DoDebugFormat
// Address Name: SUB_1018A920
// ============================================================
//----- (1018A920) --------------------------------------------------------
int __thiscall sub_1018A920(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1018A9D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0156::DebugFormat
// Address Name: SUB_1018A9D0
// ============================================================
//----- (1018A9D0) --------------------------------------------------------
int __thiscall sub_1018A9D0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  _DWORD *v5; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    if ( !"[attrs]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[attrs]", a4);
      if ( !result )
      {
        v5 = this + 1;
        if ( a3 >= 0 )
          return sub_102074E0(v5, a2, a3 + 1, a4);
        else
          return sub_102074E0(v5, a2, a3, a4);
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102070B0
// ============================================================
//----- (102070B0) --------------------------------------------------------
int __thiscall sub_102070B0(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 9) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_31:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 9) & 1) == 0 )
            *(this + 9) |= 1u;
          VarULong = TdrBuf::ReadVarULong(a2, this);
          break;
        case 2u:
          if ( (*(this + 9) & 2) == 0 )
            *(this + 9) |= 2u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 9) & 4) == 0 )
            *(this + 9) |= 4u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 9) & 8) == 0 )
            *(this + 9) |= 8u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 9) & 0x10) == 0 )
            *(this + 9) |= 0x10u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 9) & 0x20) == 0 )
            *(this + 9) |= 0x20u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 6);
          break;
        case 8u:
          if ( (*(this + 9) & 0x40) == 0 )
            *(this + 9) |= 0x40u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 7);
          break;
        case 9u:
          if ( (*(this + 9) & 0x80) == 0 )
            *(this + 9) |= 0x80u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 8);
          break;
        default:
          VarULong = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarULong;
      if ( VarULong )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_31;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10207260
// ============================================================
//----- (10207260) --------------------------------------------------------
int __thiscall sub_10207260(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 36) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_31:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 36) & 1) == 0 )
            *(_DWORD *)(this + 36) |= 1u;
          Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 36) & 2) == 0 )
            *(_DWORD *)(this + 36) |= 2u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 36) & 4) == 0 )
            *(_DWORD *)(this + 36) |= 4u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 36) & 8) == 0 )
            *(_DWORD *)(this + 36) |= 8u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 36) & 0x10) == 0 )
            *(_DWORD *)(this + 36) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 36) & 0x20) == 0 )
            *(_DWORD *)(this + 36) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 36) & 0x40) == 0 )
            *(_DWORD *)(this + 36) |= 0x40u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 28));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 36) & 0x80) == 0 )
            *(_DWORD *)(this + 36) |= 0x80u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 32));
          break;
        default:
          Int64 = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Int64;
      if ( Int64 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_31;
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
// Address Name: SUB_102074E0
// ============================================================
//----- (102074E0) --------------------------------------------------------
int __thiscall sub_102074E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[soulBeastGID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[oCharLevel]", "%d", *(this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[oCharExp]", "%d", *(this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[oCharGlut]", "%d", *(this + 4));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[oEvloveStage]", "%d", *(this + 5));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[oImage]", "%d", *(this + 6));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[oFollow]", "%d", *(this + 7));
              if ( !result )
                return print_field(a2, a3, a4, "[oFeedTime]", "%d", *(this + 8));
            }
          }
        }
      }
    }
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



