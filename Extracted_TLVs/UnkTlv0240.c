// ============================================================
// Name: TLV::UnkTlv0240::Read_0xAA
// Address Name: SUB_10219D20
// ============================================================
//----- (10219D20) --------------------------------------------------------
int __thiscall sub_10219D20(int this, _DWORD *a2, unsigned int a3)
{
  unsigned int v3; // eax
  int VarUInt; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  _DWORD *v10; // ebx
  int v11; // edi
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  int v14; // edi
  unsigned int v15; // edx
  _DWORD *v16; // ebx
  unsigned __int16 v17; // di
  unsigned int v18; // edx
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarUInt = 0;
  v6 = a2;
  *(_DWORD *)(this + 5050) = 0;
  v20 = this;
  v7 = v6[1] + v3;
  v19 = 0;
  a3 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_49;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5050) & 1) == 0 )
          *(_DWORD *)(this + 5050) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)this);
        goto LABEL_47;
      case 2u:
        if ( (*(_DWORD *)(this + 5050) & 2) == 0 )
          *(_DWORD *)(this + 5050) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v10 = a2;
        if ( !a2 )
          return -37;
        v11 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = sub_10115A30(v6, (_BYTE *)(v11 + v20 + 4));
          if ( VarUInt )
            return VarUInt;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)v20 = v11 + 1;
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 5050) & 4) == 0 )
          *(_DWORD *)(this + 5050) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(this + 2504));
        goto LABEL_47;
      case 4u:
        if ( (*(_DWORD *)(this + 5050) & 8) == 0 )
          *(_DWORD *)(this + 5050) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v14 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = sub_10115A30(v6, (_BYTE *)(v14 + v20 + 2508));
          if ( VarUInt )
            return VarUInt;
          v15 = v6[1];
          if ( (_DWORD *)v15 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
            break;
          if ( ++v14 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)(v20 + 2504) = v14 + 1;
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(this + 5050) & 0x10) == 0 )
          *(_DWORD *)(this + 5050) |= 0x10u;
        VarInt = TdrBuf::ReadVarUShort(v6, (_WORD *)(this + 5008));
        goto LABEL_47;
      case 6u:
        if ( (*(_DWORD *)(this + 5050) & 0x20) == 0 )
          *(_DWORD *)(this + 5050) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v16 = a2;
        if ( !a2 )
          return -37;
        v17 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v20 + 4 * v17 + 5010));
          if ( VarUInt )
            return VarUInt;
          v18 = v6[1];
          if ( (_DWORD *)v18 > (_DWORD *)((char *)a2 + (int)v16) )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + (_DWORD)v16) )
            break;
          if ( ++v17 >= 0xAu )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_WORD *)(v20 + 5008) = v17 + 1;
LABEL_48:
        v7 = a3;
        if ( v6[1] < a3 )
          continue;
LABEL_49:
        if ( v6[1] > v7 )
          return -34;
        return VarUInt;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_47:
        VarUInt = VarInt;
        if ( !VarInt )
          goto LABEL_48;
        return VarUInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0240::Read_0x99
// Address Name: SUB_1021A010
// ============================================================
//----- (1021A010) --------------------------------------------------------
int __thiscall sub_1021A010(int this, _DWORD *a2, unsigned int a3)
{
  unsigned int v3; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // ebx
  int v11; // edi
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  int v14; // edi
  unsigned int v15; // edx
  _DWORD *v16; // ebx
  unsigned __int16 v17; // di
  unsigned int v18; // edx
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  v5 = 0;
  v6 = a2;
  *(_DWORD *)(this + 5050) = 0;
  v20 = this;
  v7 = v6[1] + v3;
  v19 = 0;
  a3 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_49;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5050) & 1) == 0 )
          *(_DWORD *)(this + 5050) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this);
        goto LABEL_47;
      case 2u:
        if ( (*(_DWORD *)(this + 5050) & 2) == 0 )
          *(_DWORD *)(this + 5050) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v10 = a2;
        if ( !a2 )
          return -37;
        v11 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)(v11 + v20 + 4));
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)v20 = v11 + 1;
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 5050) & 4) == 0 )
          *(_DWORD *)(this + 5050) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 2504));
        goto LABEL_47;
      case 4u:
        if ( (*(_DWORD *)(this + 5050) & 8) == 0 )
          *(_DWORD *)(this + 5050) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v14 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)(v14 + v20 + 2508));
          if ( v5 )
            return v5;
          v15 = v6[1];
          if ( (_DWORD *)v15 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
            break;
          if ( ++v14 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)(v20 + 2504) = v14 + 1;
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(this + 5050) & 0x10) == 0 )
          *(_DWORD *)(this + 5050) |= 0x10u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 5008));
        goto LABEL_47;
      case 6u:
        if ( (*(_DWORD *)(this + 5050) & 0x20) == 0 )
          *(_DWORD *)(this + 5050) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v16 = a2;
        if ( !a2 )
          return -37;
        v17 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, (_BYTE *)(v20 + 4 * v17 + 5010));
          if ( v5 )
            return v5;
          v18 = v6[1];
          if ( (_DWORD *)v18 > (_DWORD *)((char *)a2 + (int)v16) )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + (_DWORD)v16) )
            break;
          if ( ++v17 >= 0xAu )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_WORD *)(v20 + 5008) = v17 + 1;
LABEL_48:
        v7 = a3;
        if ( v6[1] < a3 )
          continue;
LABEL_49:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_47:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_48;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0240::DoDebugFormat
// Address Name: SUB_1021A320
// ============================================================
//----- (1021A320) --------------------------------------------------------
int __thiscall sub_1021A320(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1021A3D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0240::DebugFormat
// Address Name: SUB_1021A3D0
// ============================================================
//----- (1021A3D0) --------------------------------------------------------
int __thiscall sub_1021A3D0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // di

  result = print_field(a2, a3, a4, "[unlockBitCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 2500 )
      return -7;
    result = sub_1024A3B0(a2, a3, v6, "[unlockBit]", v7);
    if ( !result )
    {
      v8 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *(this + 626));
        if ( result )
          return result;
        v10 = *(this + 626);
        if ( v10 < 0 )
          return -6;
        if ( v10 <= 2500 )
        {
          result = sub_1024A3B0(a2, a3, v9, "[completeBit]", v10);
          if ( result )
            return result;
          v11 = 0;
          if ( *(this + 626) > 0 )
          {
            do
            {
              result = Printf(a2, " 0x%02x", *((char *)this + v11 + 2508));
              if ( result )
                return result;
            }
            while ( ++v11 < *(this + 626) );
          }
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[newFinishCardNum]", "%d", *((unsigned __int16 *)this + 2504));
          if ( result )
            return result;
          if ( *((_WORD *)this + 2504) <= 0xAu )
          {
            result = sub_1024A3B0(a2, a3, 10, "[newFinishCardList]", *((unsigned __int16 *)this + 2504));
            if ( !result )
            {
              v12 = 0;
              if ( *((_WORD *)this + 2504) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %u", *(int *)((char *)this + 4 * v12 + 5010));
                  if ( result )
                    break;
                  if ( ++v12 >= *((_WORD *)this + 2504) )
                    return TdrBuf::WriteChar(a2, a4);
                }
              }
              else
              {
                return TdrBuf::WriteChar(a2, a4);
              }
            }
            return result;
          }
        }
        return -7;
      }
      while ( 1 )
      {
        result = Printf(a2, " 0x%02x", *((char *)this + v8 + 4));
        if ( result )
          break;
        if ( ++v8 >= *this )
          goto LABEL_10;
      }
    }
  }
  return result;
}
// 1021A431: variable 'v6' is possibly undefined
// 1021A4D0: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10115A30
// ============================================================
//----- (10115A30) --------------------------------------------------------
int __thiscall sub_10115A30(_DWORD *this, _BYTE *a2)
{
  int v3; // ecx

  if ( *(this + 1) > *(this + 2) )
    _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
  v3 = *(this + 1);
  if ( *(this + 2) == v3 )
    return -2;
  *a2 = *(_BYTE *)(v3 + *this);
  ++*(this + 1);
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



