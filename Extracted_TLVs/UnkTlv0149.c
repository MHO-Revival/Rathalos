// ============================================================
// Name: TLV::UnkTlv0149::Read_0xAA
// Address Name: SUB_10184830
// ============================================================
//----- (10184830) --------------------------------------------------------
int __thiscall sub_10184830(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int VarULong; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  VarULong = 0;
  v6 = a2;
  v20 = this;
  *(_DWORD *)(this + 130) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 130) & 1) == 0 )
          *(_DWORD *)(v4 + 130) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 130) & 2) == 0 )
          *(_DWORD *)(v4 + 130) |= 2u;
        VarInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 4));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 130) & 4) == 0 )
          *(_DWORD *)(v4 + 130) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 5));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(v4 + 130) & 8) == 0 )
          *(_DWORD *)(v4 + 130) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = (_DWORD *)(v20 + 9);
        a3 = v20 + 9;
        do
        {
          VarULong = TdrBuf::ReadVarULong(v6, v11);
          if ( VarULong )
            return VarULong;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
            goto LABEL_23;
          ++v10;
          v11 = (_DWORD *)(a3 + 8);
          a3 += 8;
        }
        while ( v10 < 10 );
        v4 = v20;
        goto LABEL_39;
      case 5u:
        if ( (*(_DWORD *)(v4 + 130) & 0x10) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v6[1];
        v14 = (_DWORD *)(v20 + 89);
        a3 = v20 + 89;
        do
        {
          VarULong = TdrBuf::ReadVarUInt(v6, v14);
          if ( VarULong )
            return VarULong;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v18) )
          {
LABEL_23:
            v13 = v10 + 1;
            v4 = v20;
            *(_DWORD *)(v20 + 5) = v13;
            goto LABEL_39;
          }
          ++v10;
          v14 = (_DWORD *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 10 );
        v4 = v20;
LABEL_39:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_40:
        if ( v6[1] > v7 )
          return -34;
        return VarULong;
      case 6u:
        if ( (*(_DWORD *)(v4 + 130) & 0x20) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x20u;
        VarInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 129));
        goto LABEL_38;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_38:
        VarULong = VarInt;
        if ( !VarInt )
          goto LABEL_39;
        return VarULong;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0149::Read_0x99
// Address Name: SUB_10184AA0
// ============================================================
//----- (10184AA0) --------------------------------------------------------
int __thiscall sub_10184AA0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Int64; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Int64 = 0;
  v6 = a2;
  v20 = this;
  *(_DWORD *)(this + 130) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 130) & 1) == 0 )
          *(_DWORD *)(v4 + 130) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 130) & 2) == 0 )
          *(_DWORD *)(v4 + 130) |= 2u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 4));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 130) & 4) == 0 )
          *(_DWORD *)(v4 + 130) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 5));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(v4 + 130) & 8) == 0 )
          *(_DWORD *)(v4 + 130) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = (_BYTE *)(v20 + 9);
        a3 = v20 + 9;
        do
        {
          Int64 = TdrBuf::ReadInt64(v6, v11);
          if ( Int64 )
            return Int64;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
            goto LABEL_23;
          ++v10;
          v11 = (_BYTE *)(a3 + 8);
          a3 += 8;
        }
        while ( v10 < 10 );
        v4 = v20;
        goto LABEL_39;
      case 5u:
        if ( (*(_DWORD *)(v4 + 130) & 0x10) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v6[1];
        v14 = (_BYTE *)(v20 + 89);
        a3 = v20 + 89;
        do
        {
          Int64 = TdrBuf::ReadInt32(v6, v14);
          if ( Int64 )
            return Int64;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v18) )
          {
LABEL_23:
            v13 = v10 + 1;
            v4 = v20;
            *(_DWORD *)(v20 + 5) = v13;
            goto LABEL_39;
          }
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 10 );
        v4 = v20;
LABEL_39:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_40:
        if ( v6[1] > v7 )
          return -34;
        return Int64;
      case 6u:
        if ( (*(_DWORD *)(v4 + 130) & 0x20) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x20u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 129));
        goto LABEL_38;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_38:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_39;
        return Int64;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0149::DoDebugFormat
// Address Name: SUB_10184D30
// ============================================================
//----- (10184D30) --------------------------------------------------------
int __thiscall sub_10184D30(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10184DE0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0149::DebugFormat
// Address Name: SUB_10184DE0
// ============================================================
//----- (10184DE0) --------------------------------------------------------
int __thiscall sub_10184DE0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // edi
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _QWORD *v10; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[lastReportTime]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[todayReportTimes]", "0x%02x", *(this + 4));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[reportOtherPlayerNum]", "%d", *(_DWORD *)(this + 5));
      if ( !result )
      {
        v8 = *(_DWORD *)(this + 5);
        if ( v8 < 0 )
          return -6;
        if ( v8 > 10 )
          return -7;
        result = sub_1024A3B0(a2, a3, v7, "[otherPlayerDBID]", v8);
        if ( !result )
        {
          v9 = 0;
          if ( *(int *)(this + 5) <= 0 )
          {
LABEL_14:
            result = TdrBuf::WriteChar(v4, a4);
            if ( !result )
            {
              v12 = *(_DWORD *)(this + 5);
              if ( v12 < 0 )
                return -6;
              if ( v12 > 10 )
                return -7;
              result = sub_1024A3B0(v4, a3, v11, "[reportOtherPlayerTime]", v12);
              if ( !result )
              {
                v13 = 0;
                if ( *(int *)(this + 5) <= 0 )
                {
LABEL_22:
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( !result )
                    return print_field(a2, a3, a4, "[todayHangUpTimes]", "0x%02x", *(this + 129));
                }
                else
                {
                  v14 = this + 89;
                  while ( 1 )
                  {
                    result = Printf(a2, " %u", *v14);
                    if ( result )
                      break;
                    ++v13;
                    ++v14;
                    if ( v13 >= *(_DWORD *)(this + 5) )
                      goto LABEL_22;
                  }
                }
              }
            }
          }
          else
          {
            v10 = this + 9;
            while ( 1 )
            {
              result = Printf(a2, " %I64u", *v10);
              if ( result )
                break;
              ++v9;
              ++v10;
              if ( v9 >= *(_DWORD *)(this + 5) )
              {
                v4 = a2;
                goto LABEL_14;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 10184E88: variable 'v7' is possibly undefined
// 10184EFB: variable 'v11' is possibly undefined



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



