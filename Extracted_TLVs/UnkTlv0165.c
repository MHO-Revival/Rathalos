// ============================================================
// Name: TLV::UnkTlv0165::Read_0xAA
// Address Name: SUB_10190A80
// ============================================================
//----- (10190A80) --------------------------------------------------------
int __thiscall sub_10190A80(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  char *v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 44) = 0;
  v15 = 0;
  v7 = (char *)v3 + v6[1];
  v12 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_28:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[44] & 1) == 0 )
          v4[44] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[44] & 2) == 0 )
          v4[44] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_7;
      case 3u:
        if ( (v4[44] & 4) == 0 )
          v4[44] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_7;
      case 4u:
        if ( (v4[44] & 8) == 0 )
          v4[44] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = v16 + 3;
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_101901B0(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 5;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= (unsigned int)v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[44] & 0x10) == 0 )
          v4[44] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 43);
        goto LABEL_7;
      default:
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0165::Read_0x99
// Address Name: SUB_10190C60
// ============================================================
//----- (10190C60) --------------------------------------------------------
int __thiscall sub_10190C60(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 44) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_28:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[44] & 1) == 0 )
          v4[44] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[44] & 2) == 0 )
          v4[44] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_7;
      case 3u:
        if ( (v4[44] & 4) == 0 )
          v4[44] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_7;
      case 4u:
        if ( (v4[44] & 8) == 0 )
          v4[44] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = (int)(v16 + 3);
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_101902B0(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 20;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[44] & 0x10) == 0 )
          v4[44] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 172);
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0165::DoDebugFormat
// Address Name: SUB_10190E60
// ============================================================
//----- (10190E60) --------------------------------------------------------
int __thiscall sub_10190E60(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10190F10(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0165::DebugFormat
// Address Name: SUB_10190F10
// ============================================================
//----- (10190F10) --------------------------------------------------------
int __thiscall sub_10190F10(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ebx
  _DWORD *i; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[iSearchCount]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iRrefreshCount]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iVipRefreshCount]", "%d", *(this + 2));
      if ( !result )
      {
        v6 = 0;
        for ( i = this + 3; ; i += 5 )
        {
          if ( !"[vItemPoolList]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[vItemPoolList]", v6, a4);
          if ( result )
            break;
          result = a3 >= 0 ? sub_10190480(i, a2, a3 + 1, a4) : sub_10190480(i, a2, a3, a4);
          if ( result )
            break;
          if ( (unsigned int)++v6 >= 8 )
            return print_field(a2, a3, a4, "[iLastUpdateTime]", "%d", *(this + 43));
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101901B0
// ============================================================
//----- (101901B0) --------------------------------------------------------
int __thiscall sub_101901B0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
          if ( (*(_BYTE *)(this + 4) & 1) == 0 )
            *(this + 4) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101902B0
// ============================================================
//----- (101902B0) --------------------------------------------------------
int __thiscall sub_101902B0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 16) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(_DWORD *)(this + 16) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 16) & 2) == 0 )
            *(_DWORD *)(this + 16) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 16) & 4) == 0 )
            *(_DWORD *)(this + 16) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 16) & 8) == 0 )
            *(_DWORD *)(this + 16) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_19;
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
// Address Name: SUB_10190480
// ============================================================
//----- (10190480) --------------------------------------------------------
int __thiscall sub_10190480(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iPosition]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iItemId]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iItemNum]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[iQuality]", "%d", *(this + 3));
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



