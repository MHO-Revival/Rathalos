// ============================================================
// Name: TLV::UnkTlv0159::Read
// Address Name: SUB_1018CF60
// ============================================================
//----- (1018CF60) --------------------------------------------------------
int __thiscall sub_1018CF60(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1018D030(this, &v9, v8);
  else
    result = sub_1018D250(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0159::Read_0xAA
// Address Name: SUB_1018D030
// ============================================================
//----- (1018D030) --------------------------------------------------------
int __thiscall sub_1018D030(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarUInt; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  _DWORD *v10; // ebx
  int v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // esi
  _DWORD *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h] BYREF
  int *v18; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarUInt = 0;
  v6 = a2;
  v18 = this;
  *(this + 1106) = 0;
  v17 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_35;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 1106) & 1) == 0 )
          *(this + 1106) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, this);
        goto LABEL_33;
      case 2u:
        if ( (*(this + 1106) & 2) == 0 )
          *(this + 1106) |= 2u;
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
          VarUInt = sub_10115A30(v6, (_BYTE *)v18 + v11 + 4);
          if ( VarUInt )
            return VarUInt;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 320 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        *v18 = v11 + 1;
        goto LABEL_34;
      case 3u:
        if ( (*(this + 1106) & 4) == 0 )
          *(this + 1106) |= 4u;
        VarInt = TdrBuf::ReadVarUInt(v6, this + 81);
        goto LABEL_33;
      case 4u:
        if ( (*(this + 1106) & 8) == 0 )
          *(this + 1106) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = v6[1];
        v14 = this + 82;
        while ( 1 )
        {
          VarUInt = TdrBuf::ReadVarUInt(v6, v14);
          if ( VarUInt )
            return VarUInt;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v13;
          ++v14;
          if ( v13 >= 0x400 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        v18[81] = v13 + 1;
LABEL_34:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_35:
        if ( v6[1] > v7 )
          return -34;
        return VarUInt;
      default:
        VarInt = TdrBuf::SkipField(v6, v17 & 0xF);
LABEL_33:
        VarUInt = VarInt;
        if ( !VarInt )
          goto LABEL_34;
        return VarUInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0159::Read_0x99
// Address Name: SUB_1018D250
// ============================================================
//----- (1018D250) --------------------------------------------------------
int __thiscall sub_1018D250(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // ebx
  int v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // esi
  _BYTE *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v18; // [esp+14h] [ebp-4h]

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v18 = this;
  *(this + 1106) = 0;
  v17 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_35;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 1106) & 1) == 0 )
          *(this + 1106) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, this);
        goto LABEL_33;
      case 2u:
        if ( (*(this + 1106) & 2) == 0 )
          *(this + 1106) |= 2u;
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
          v5 = sub_10115A30(v6, (_BYTE *)v18 + v11 + 4);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 320 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        *v18 = v11 + 1;
        goto LABEL_34;
      case 3u:
        if ( (*(this + 1106) & 4) == 0 )
          *(this + 1106) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this + 324);
        goto LABEL_33;
      case 4u:
        if ( (*(this + 1106) & 8) == 0 )
          *(this + 1106) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = v6[1];
        v14 = this + 82;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v14);
          if ( v5 )
            return v5;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v13;
          v14 += 4;
          if ( v13 >= 0x400 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        v18[81] = v13 + 1;
LABEL_34:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_35:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v17 & 0xF);
LABEL_33:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_34;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0159::DoDebugFormat
// Address Name: SUB_1018D490
// ============================================================
//----- (1018D490) --------------------------------------------------------
int __thiscall sub_1018D490(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1018D540(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0159::DebugFormat
// Address Name: SUB_1018D540
// ============================================================
//----- (1018D540) --------------------------------------------------------
int __thiscall sub_1018D540(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // esi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 320 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[completeBit]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[illustrateCardCount]", "%u", *(this + 81));
          if ( !result )
          {
            v11 = *(this + 81);
            if ( v11 > 0x400 )
              return -7;
            result = sub_1024A3B0(a2, a3, v10, "[illustrateCardInfo]", v11);
            if ( !result )
            {
              v12 = 0;
              if ( *(this + 81) )
              {
                for ( i = this + 82; ; ++i )
                {
                  result = Printf(a2, " %u", *i);
                  if ( result )
                    break;
                  if ( (unsigned int)++v12 >= *(this + 81) )
                  {
                    v4 = a2;
                    return TdrBuf::WriteChar(v4, a4);
                  }
                }
              }
              else
              {
                return TdrBuf::WriteChar(v4, a4);
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((char *)this + v9 + 4));
          if ( result )
            break;
          if ( ++v9 >= *this )
            goto LABEL_10;
        }
      }
    }
  }
  return result;
}
// 1018D5A1: variable 'v7' is possibly undefined
// 1018D634: variable 'v10' is possibly undefined



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



