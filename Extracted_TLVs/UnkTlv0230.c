// ============================================================
// Name: TLV::UnkTlv0230::Read_0xAA
// Address Name: SUB_10213100
// ============================================================
//----- (10213100) --------------------------------------------------------
int __thiscall sub_10213100(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  __int16 v10; // di
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 522) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 522) & 1) == 0 )
          *(_DWORD *)(v5 + 522) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)v5);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(v5 + 522) & 2) == 0 )
          *(_DWORD *)(v5 + 522) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(v5 + 522) & 4) == 0 )
          *(_DWORD *)(v5 + 522) |= 4u;
        VarUInt = TdrBuf::ReadVarShort(v4, (_WORD *)(v5 + 8));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(v5 + 522) & 8) == 0 )
          *(_DWORD *)(v5 + 522) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v4[1];
        while ( 1 )
        {
          a3 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a3);
          if ( v6 )
            return v6;
          if ( a3 )
          {
            v6 = sub_10212840(v16 + 8 * v10 + 10, v4, a3);
            if ( v6 )
              return v6;
          }
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v16;
            goto LABEL_28;
          }
        }
        v12 = v10 + 1;
        v5 = v16;
        *(_WORD *)(v16 + 8) = v12;
LABEL_28:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_29:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      default:
        VarUInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_27:
        v6 = VarUInt;
        if ( !VarUInt )
          goto LABEL_28;
        return v6;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0230::Read_0x99
// Address Name: SUB_102132D0
// ============================================================
//----- (102132D0) --------------------------------------------------------
int __thiscall sub_102132D0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  __int16 v10; // di
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 522) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 522) & 1) == 0 )
          *(_DWORD *)(v5 + 522) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(v5 + 522) & 2) == 0 )
          *(_DWORD *)(v5 + 522) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(v5 + 522) & 4) == 0 )
          *(_DWORD *)(v5 + 522) |= 4u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(v5 + 8));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(v5 + 522) & 8) == 0 )
          *(_DWORD *)(v5 + 522) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v4[1];
        while ( 1 )
        {
          a3 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a3);
          if ( v6 )
            return v6;
          if ( a3 )
          {
            v6 = sub_102128E0((_DWORD *)(v16 + 8 * v10 + 10), v4, a3);
            if ( v6 )
              return v6;
          }
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v16;
            goto LABEL_28;
          }
        }
        v12 = v10 + 1;
        v5 = v16;
        *(_WORD *)(v16 + 8) = v12;
LABEL_28:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_29:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_27:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_28;
        return v6;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0230::DoDebugFormat
// Address Name: SUB_102134C0
// ============================================================
//----- (102134C0) --------------------------------------------------------
int __thiscall sub_102134C0(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10213570(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0230::DebugFormat
// Address Name: SUB_10213570
// ============================================================
//----- (10213570) --------------------------------------------------------
int __thiscall sub_10213570(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // si

  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lib]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[commodityCount]", "%d", *(this + 4));
      if ( !result )
      {
        v6 = *(this + 4);
        if ( v6 >= 0 )
        {
          if ( v6 <= 64 )
          {
            v7 = 0;
            if ( v6 <= 0 )
            {
              return 0;
            }
            else
            {
              while ( 1 )
              {
                result = sub_1024A230(a2, a3, a4, "[commodity]", v7);
                if ( result )
                  break;
                result = a3 >= 0
                       ? sub_10212B20(this + 4 * v7 + 5, a2, a3 + 1, a4)
                       : sub_10212B20(this + 4 * v7 + 5, a2, a3, a4);
                if ( result )
                  break;
                if ( ++v7 >= *(this + 4) )
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
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10212840
// ============================================================
//----- (10212840) --------------------------------------------------------
int __thiscall sub_10212840(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 4) = 0;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 4) & 2) == 0 )
          *(_DWORD *)(this + 4) |= 2u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 2));
      }
      else
      {
        VarShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarShort;
      if ( VarShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102128E0
// ============================================================
//----- (102128E0) --------------------------------------------------------
int __thiscall sub_102128E0(_DWORD *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(this + 1) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v8 = a2[1];
        if ( (unsigned int)(a2[2] - v8) < 2 )
          return -2;
        *(_BYTE *)this = *(_BYTE *)(*a2 + v8 + 1);
        *((_BYTE *)this + 1) = *(_BYTE *)(*a2 + a2[1]);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(this + 1) & 2) == 0 )
          *(this + 1) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v7 = a2[1];
        if ( (unsigned int)(a2[2] - v7) < 2 )
          return -2;
        *((_BYTE *)this + 2) = *(_BYTE *)(*a2 + v7 + 1);
        *((_BYTE *)this + 3) = *(_BYTE *)(*a2 + a2[1]);
      }
      a2[1] += 2;
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
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
// Address Name: SUB_10212B20
// ============================================================
//----- (10212B20) --------------------------------------------------------
int __thiscall sub_10212B20(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commodity]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[saledCount]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A230
// ============================================================
//----- (1024A230) --------------------------------------------------------
int __fastcall sub_1024A230(_DWORD *a1, int a2, char a3, const char *ArgList, int a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
  result = sub_1024A140(a2);
  if ( !result )
    return Printf(a1, "%s[%u]%c", ArgList, a5, a3);
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



