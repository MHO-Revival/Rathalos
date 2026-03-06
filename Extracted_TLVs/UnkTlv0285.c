// ============================================================
// Name: TLV::UnkTlv0285::Read_0xAA
// Address Name: SUB_1023B8F0
// ============================================================
//----- (1023B8F0) --------------------------------------------------------
int __thiscall sub_1023B8F0(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ecx
  unsigned __int16 v8; // si
  unsigned int v9; // edx
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 164) = 0;
  v12 = 0;
  v7 = v6[1] + v5;
  v10 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_28:
    if ( v6[1] > v7 )
      return -34;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v12);
      if ( result )
        break;
      switch ( v12 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 164) & 1) == 0 )
            *(_DWORD *)(this + 164) |= 1u;
          result = TdrBuf::ReadVarUShort(v6, (_WORD *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 164) & 2) == 0 )
            *(_DWORD *)(this + 164) |= 2u;
          result = TdrBuf::ReadVarUShort(v6, (_WORD *)(this + 2));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 164) & 4) == 0 )
            *(_DWORD *)(this + 164) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( !result )
          {
            if ( a2 )
            {
              v8 = 0;
              v11 = v6[1];
              while ( 1 )
              {
                a3 = 0;
                result = TdrBuf::ReadInt32(v6, &a3);
                if ( result )
                  break;
                if ( a3 )
                {
                  result = sub_1023B120((_DWORD *)(16 * v8 + this + 4), v6, a3);
                  if ( result )
                    break;
                }
                v9 = v6[1];
                if ( v9 > (unsigned int)a2 + v11 )
                  return -34;
                if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + v11) )
                {
                  *(_WORD *)(this + 2) = v8 + 1;
                  goto LABEL_27;
                }
                if ( ++v8 >= 0xAu )
                  goto LABEL_27;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        default:
          result = TdrBuf::SkipField(v6, v12 & 0xF);
          break;
      }
      if ( result )
        return result;
LABEL_27:
      v7 = v10;
      if ( v6[1] >= v10 )
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0285::Read_0x99
// Address Name: SUB_1023BA70
// ============================================================
//----- (1023BA70) --------------------------------------------------------
int __thiscall sub_1023BA70(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ecx
  unsigned __int16 v8; // si
  unsigned int v9; // edx
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 164) = 0;
  v12 = 0;
  v7 = v6[1] + v5;
  v10 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_28:
    if ( v6[1] > v7 )
      return -34;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v12);
      if ( result )
        break;
      switch ( v12 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 164) & 1) == 0 )
            *(_DWORD *)(this + 164) |= 1u;
          result = TdrBuf::ReadInt16(v6, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 164) & 2) == 0 )
            *(_DWORD *)(this + 164) |= 2u;
          result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 2));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 164) & 4) == 0 )
            *(_DWORD *)(this + 164) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( !result )
          {
            if ( a2 )
            {
              v8 = 0;
              v11 = v6[1];
              while ( 1 )
              {
                a3 = 0;
                result = TdrBuf::ReadInt32(v6, &a3);
                if ( result )
                  break;
                if ( a3 )
                {
                  result = sub_1023B1D0(16 * v8 + this + 4, v6, a3);
                  if ( result )
                    break;
                }
                v9 = v6[1];
                if ( v9 > (unsigned int)a2 + v11 )
                  return -34;
                if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + v11) )
                {
                  *(_WORD *)(this + 2) = v8 + 1;
                  goto LABEL_27;
                }
                if ( ++v8 >= 0xAu )
                  goto LABEL_27;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        default:
          result = TdrBuf::SkipField(v6, v12 & 0xF);
          break;
      }
      if ( result )
        return result;
LABEL_27:
      v7 = v10;
      if ( v6[1] >= v10 )
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0285::DoDebugFormat
// Address Name: SUB_1023BC10
// ============================================================
//----- (1023BC10) --------------------------------------------------------
int __thiscall sub_1023BC10(unsigned __int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1023BCC0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0285::DebugFormat
// Address Name: SUB_1023BCC0
// ============================================================
//----- (1023BCC0) --------------------------------------------------------
int __thiscall sub_1023BCC0(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // di
  unsigned __int16 *v8; // ecx

  result = print_field(a2, a3, a4, "[rate]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[historyCount]", "%d", *(this + 1));
    if ( !result )
    {
      v6 = *(this + 1);
      if ( v6 <= 0xAu )
      {
        v7 = 0;
        if ( v6 )
        {
          while ( 1 )
          {
            if ( !"[history]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[history]", v7, a4);
            if ( result )
              break;
            v8 = this + 8 * v7 + 2;
            result = a3 >= 0 ? sub_1023B350(v8, a2, a3 + 1, a4) : sub_1023B350(v8, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *(this + 1) )
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1023B120
// ============================================================
//----- (1023B120) --------------------------------------------------------
int __thiscall sub_1023B120(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_18:
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
      switch ( v8 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 2);
          break;
        default:
          VarUInt = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarUInt;
      if ( VarUInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1023B1D0
// ============================================================
//----- (1023B1D0) --------------------------------------------------------
int __thiscall sub_1023B1D0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 12) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_18:
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
      switch ( v8 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
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
// Address Name: SUB_1023B350
// ============================================================
//----- (1023B350) --------------------------------------------------------
int __thiscall sub_1023B350(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[totalCredit]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[totalMoney]", "%u", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[lastTime]", "%u", *(this + 2));
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



