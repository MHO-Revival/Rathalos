// ============================================================
// Name: TLV::UnkTlv0070::Read_0xAA
// Address Name: SUB_10147090
// ============================================================
//----- (10147090) --------------------------------------------------------
int __thiscall sub_10147090(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        VarInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_32:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0070::Read_0x99
// Address Name: SUB_10147280
// ============================================================
//----- (10147280) --------------------------------------------------------
int __thiscall sub_10147280(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_32:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0070::DoDebugFormat
// Address Name: SUB_10147490
// ============================================================
//----- (10147490) --------------------------------------------------------
int __thiscall sub_10147490(_BYTE *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10147540(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0070::DebugFormat
// Address Name: SUB_10147540
// ============================================================
//----- (10147540) --------------------------------------------------------
int __thiscall sub_10147540(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  result = print_field(a2, a3, a4, "[levelID]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dataCnt]", "0x%02x", (unsigned __int8)*(this + 4));
    if ( !result )
    {
      v7 = *(this + 4);
      if ( v7 > 0xAu )
        return -7;
      result = sub_1024A3B0(a2, a3, v6, "[dataType]", v7);
      if ( !result )
      {
        v8 = 0;
        if ( *(this + 4) )
        {
          while ( 1 )
          {
            result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v8 + 5));
            if ( result )
              break;
            if ( ++v8 >= *(this + 4) )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          result = TdrBuf::WriteChar(a2, a4);
          if ( !result )
          {
            v10 = *(this + 4);
            if ( v10 > 0xAu )
              return -7;
            result = sub_1024A3B0(a2, a3, v9, "[dataVal]", v10);
            if ( !result )
            {
              v11 = 0;
              if ( *(this + 4) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v11 + 15));
                  if ( result )
                    break;
                  if ( ++v11 >= *(this + 4) )
                    return TdrBuf::WriteChar(a2, a4);
                }
              }
              else
              {
                return TdrBuf::WriteChar(a2, a4);
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 101475B7: variable 'v6' is possibly undefined
// 10147618: variable 'v9' is possibly undefined



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



