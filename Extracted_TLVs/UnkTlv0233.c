// ============================================================
// Name: TLV::UnkTlv0233::Read_0xAA
// Address Name: SUB_10215740
// ============================================================
//----- (10215740) --------------------------------------------------------
int __thiscall sub_10215740(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned __int8 v8; // bl
  unsigned int v9; // edx
  unsigned __int8 v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  unsigned int v14; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v14 = 0;
  v6 = a3;
  *(_DWORD *)(this + 126) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v3[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + v8 + 1));
          if ( result )
            return result;
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 0x14u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)this = v8 + 1;
        goto LABEL_39;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 21));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v13 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10214DC0(this + 2 * (5 * v10 + 11), v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v13) )
            break;
          if ( ++v10 >= 0xAu )
            goto LABEL_39;
        }
        *(_BYTE *)(this + 21) = v10 + 1;
LABEL_39:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_40:
        if ( v3[1] > v7 )
          return -34;
        return result;
      case 5u:
        if ( (*(_DWORD *)(this + 126) & 0x10) == 0 )
          *(_DWORD *)(this + 126) |= 0x10u;
        result = TdrBuf::ReadVarUInt(v3, (_DWORD *)(this + 122));
        goto LABEL_38;
      default:
        result = TdrBuf::SkipField(v3, v14 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0233::Read_0x99
// Address Name: SUB_10215960
// ============================================================
//----- (10215960) --------------------------------------------------------
int __thiscall sub_10215960(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned __int8 v8; // bl
  unsigned int v9; // edx
  unsigned __int8 v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  unsigned int v14; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v14 = 0;
  v6 = a3;
  *(_DWORD *)(this + 126) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v3[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + v8 + 1));
          if ( result )
            return result;
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 0x14u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)this = v8 + 1;
        goto LABEL_39;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 21));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v13 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10214E60((char *)(this + 2 * (5 * v10 + 11)), v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v13) )
            break;
          if ( ++v10 >= 0xAu )
            goto LABEL_39;
        }
        *(_BYTE *)(this + 21) = v10 + 1;
LABEL_39:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_40:
        if ( v3[1] > v7 )
          return -34;
        return result;
      case 5u:
        if ( (*(_DWORD *)(this + 126) & 0x10) == 0 )
          *(_DWORD *)(this + 126) |= 0x10u;
        result = TdrBuf::ReadInt32(v3, (_BYTE *)(this + 122));
        goto LABEL_38;
      default:
        result = TdrBuf::SkipField(v3, v14 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0233::DoDebugFormat
// Address Name: SUB_10215BA0
// ============================================================
//----- (10215BA0) --------------------------------------------------------
int __thiscall sub_10215BA0(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10215C50(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0233::DebugFormat
// Address Name: SUB_10215C50
// ============================================================
//----- (10215C50) --------------------------------------------------------
int __thiscall sub_10215C50(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // bl
  unsigned __int8 v8; // al
  unsigned __int8 v9; // bl
  int v10; // eax

  result = print_field(a2, a3, a4, "[starNum]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this > 0x14u )
      return -7;
    result = sub_1024A3B0(a2, a3, v6, "[starList]", *this);
    if ( !result )
    {
      v7 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *(this + v7 + 1));
          if ( result )
            break;
          if ( ++v7 >= *this )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[statNum]", "0x%02x", *(this + 21));
          if ( !result )
          {
            v8 = *(this + 21);
            if ( v8 > 0xAu )
              return -7;
            v9 = 0;
            if ( v8 )
            {
              while ( 1 )
              {
                if ( !"[statList]" )
                  _wassert(
                    L"NULL != variable",
                    L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                    0x43u);
                result = sub_1024A140(a3);
                if ( result )
                  break;
                result = Printf(a2, "%s[%u]%c", "[statList]", v9, a4);
                if ( result )
                  break;
                v10 = a3;
                if ( a3 >= 0 )
                  v10 = a3 + 1;
                result = sub_10215060((unsigned __int16 *)this + 5 * v9 + 11, a2, v10, a4);
                if ( result )
                  break;
                if ( ++v9 >= *(this + 21) )
                  return print_field(a2, a3, a4, "[starPoints]", "%u", *(_DWORD *)(this + 122));
              }
            }
            else
            {
              return print_field(a2, a3, a4, "[starPoints]", "%u", *(_DWORD *)(this + 122));
            }
          }
        }
      }
    }
  }
  return result;
}
// 10215CA3: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10214DC0
// ============================================================
//----- (10214DC0) --------------------------------------------------------
int __thiscall sub_10214DC0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
        if ( (*(_BYTE *)(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        VarUShort = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 2));
      }
      else
      {
        VarUShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUShort;
      if ( VarUShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10214E60
// ============================================================
//----- (10214E60) --------------------------------------------------------
int __thiscall sub_10214E60(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 6) & 1) == 0 )
        *(_DWORD *)(this + 6) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v7 = a2[1];
      if ( (unsigned int)(a2[2] - v7) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v7 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 6) & 2) == 0 )
        *(_DWORD *)(this + 6) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 2);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
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
// Address Name: SUB_10215060
// ============================================================
//----- (10215060) --------------------------------------------------------
int __thiscall sub_10215060(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[statType]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[statValue]", "%u", *(_DWORD *)(this + 1));
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



