// ============================================================
// Name: TLV::UnkTlv0124::Read
// Address Name: SUB_10172510
// ============================================================
//----- (10172510) --------------------------------------------------------
int __thiscall sub_10172510(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_101725E0(this, &v9, v8);
  else
    result = sub_101727D0((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0124::Read_0xAA
// Address Name: SUB_101725E0
// ============================================================
//----- (101725E0) --------------------------------------------------------
int __thiscall sub_101725E0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarInt; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // esi
  int *v11; // ebx
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarInt = 0;
  v6 = a2;
  v17 = this;
  *(this + 27) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 27) & 1) == 0 )
          *(this + 27) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, this);
        goto LABEL_32;
      case 4u:
        if ( (*(this + 27) & 2) == 0 )
          *(this + 27) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v6, this + 1);
        goto LABEL_32;
      case 5u:
        if ( (*(this + 27) & 4) == 0 )
          *(this + 27) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        v11 = this + 2;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v6, v11);
          if ( VarInt )
            return VarInt;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
          ++v11;
        }
        while ( v10 < 20 );
        this = v17;
        goto LABEL_33;
      case 6u:
        if ( (*(this + 27) & 8) == 0 )
          *(this + 27) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v10 = 0;
        a2 = (_DWORD *)v6[1];
        do
        {
          VarInt = TdrBuf::ReadByte(v6, (_BYTE *)v17 + v10 + 88);
          if ( VarInt )
            return VarInt;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
          {
LABEL_20:
            this = v17;
            v17[1] = v10 + 1;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 20 );
        this = v17;
LABEL_33:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_34:
        if ( v6[1] > v7 )
          return -34;
        return VarInt;
      default:
        VarUInt = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_32:
        VarInt = VarUInt;
        if ( !VarUInt )
          goto LABEL_33;
        return VarInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0124::Read_0x99
// Address Name: SUB_101727D0
// ============================================================
//----- (101727D0) --------------------------------------------------------
int __thiscall sub_101727D0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int Byte; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // esi
  _BYTE *v11; // ebx
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  Byte = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 108) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 108) & 1) == 0 )
          *(_DWORD *)(this + 108) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)(this + 108) & 2) == 0 )
          *(_DWORD *)(this + 108) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 4));
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)(this + 108) & 4) == 0 )
          *(_DWORD *)(this + 108) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        v11 = (_BYTE *)(this + 8);
        do
        {
          Byte = TdrBuf::ReadInt32(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
          v11 += 4;
        }
        while ( v10 < 20 );
        this = v17;
        goto LABEL_33;
      case 6u:
        if ( (*(_DWORD *)(this + 108) & 8) == 0 )
          *(_DWORD *)(this + 108) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v10 = 0;
        a2 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)(v10 + v17 + 88));
          if ( Byte )
            return Byte;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
          {
LABEL_20:
            this = v17;
            *(_DWORD *)(v17 + 4) = v10 + 1;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 20 );
        this = v17;
LABEL_33:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_34:
        if ( v6[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_32:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0124::DoDebugFormat
// Address Name: SUB_101729E0
// ============================================================
//----- (101729E0) --------------------------------------------------------
int __thiscall sub_101729E0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10172A90(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0124::DebugFormat
// Address Name: SUB_10172A90
// ============================================================
//----- (10172A90) --------------------------------------------------------
int __thiscall sub_10172A90(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 20 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[prizeId]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_13:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            v12 = *(this + 1);
            if ( v12 < 0 )
              return -6;
            if ( v12 > 20 )
              return -7;
            result = sub_1024A3B0(v4, a3, v11, "[state]", v12);
            if ( !result )
            {
              v13 = 0;
              if ( (int)*(this + 1) <= 0 )
              {
                return TdrBuf::WriteChar(v4, a4);
              }
              else
              {
                while ( 1 )
                {
                  result = Printf(v4, " 0x%02x", *((unsigned __int8 *)this + v13 + 88));
                  if ( result )
                    break;
                  if ( ++v13 >= *(this + 1) )
                    return TdrBuf::WriteChar(v4, a4);
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
// 10172B13: variable 'v7' is possibly undefined
// 10172B7A: variable 'v11' is possibly undefined



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



