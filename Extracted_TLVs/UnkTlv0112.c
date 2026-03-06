// ============================================================
// Name: TLV::UnkTlv0112::Read_0xAA
// Address Name: SUB_1016B8A0
// ============================================================
//----- (1016B8A0) --------------------------------------------------------
int __thiscall sub_1016B8A0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 69) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 69) & 1) == 0 )
            *(_DWORD *)(this + 69) |= 1u;
          VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)this);
          goto LABEL_38;
        case 2u:
          if ( (*(_DWORD *)(this + 69) & 2) == 0 )
            *(_DWORD *)(this + 69) |= 2u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 8));
          goto LABEL_38;
        case 3u:
          if ( (*(_DWORD *)(this + 69) & 4) == 0 )
            *(_DWORD *)(this + 69) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_39:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_40;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 69) & 8) == 0 )
            *(_DWORD *)(this + 69) |= 8u;
          VarULong = TdrBuf::ReadByte(v4, (_BYTE *)(this + 44));
          goto LABEL_38;
        case 5u:
          if ( (*(_DWORD *)(this + 69) & 0x10) == 0 )
            *(_DWORD *)(this + 69) |= 0x10u;
          VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 45));
          goto LABEL_38;
        case 6u:
          if ( (*(_DWORD *)(this + 69) & 0x20) == 0 )
            *(_DWORD *)(this + 69) |= 0x20u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 49));
          goto LABEL_38;
        case 7u:
          if ( (*(_DWORD *)(this + 69) & 0x40) == 0 )
            *(_DWORD *)(this + 69) |= 0x40u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 53));
          goto LABEL_38;
        case 8u:
          if ( (*(_DWORD *)(this + 69) & 0x80) == 0 )
            *(_DWORD *)(this + 69) |= 0x80u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 57));
          goto LABEL_38;
        case 9u:
          if ( (*(_DWORD *)(this + 69) & 0x100) == 0 )
            *(_DWORD *)(this + 69) |= 0x100u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 61));
          goto LABEL_38;
        case 0xAu:
          if ( (*(_DWORD *)(this + 69) & 0x200) == 0 )
            *(_DWORD *)(this + 69) |= 0x200u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 65));
          goto LABEL_38;
        default:
          VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_38:
          Bytes = VarULong;
          if ( !VarULong )
            goto LABEL_39;
          return Bytes;
      }
    }
  }
LABEL_40:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0112::Read_0x99
// Address Name: SUB_1016BAE0
// ============================================================
//----- (1016BAE0) --------------------------------------------------------
int __thiscall sub_1016BAE0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 69) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 69) & 1) == 0 )
            *(_DWORD *)(this + 69) |= 1u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
          goto LABEL_38;
        case 2u:
          if ( (*(_DWORD *)(this + 69) & 2) == 0 )
            *(_DWORD *)(this + 69) |= 2u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
          goto LABEL_38;
        case 3u:
          if ( (*(_DWORD *)(this + 69) & 4) == 0 )
            *(_DWORD *)(this + 69) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_39:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_40;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 69) & 8) == 0 )
            *(_DWORD *)(this + 69) |= 8u;
          Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 44));
          goto LABEL_38;
        case 5u:
          if ( (*(_DWORD *)(this + 69) & 0x10) == 0 )
            *(_DWORD *)(this + 69) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 45));
          goto LABEL_38;
        case 6u:
          if ( (*(_DWORD *)(this + 69) & 0x20) == 0 )
            *(_DWORD *)(this + 69) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 49));
          goto LABEL_38;
        case 7u:
          if ( (*(_DWORD *)(this + 69) & 0x40) == 0 )
            *(_DWORD *)(this + 69) |= 0x40u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 53));
          goto LABEL_38;
        case 8u:
          if ( (*(_DWORD *)(this + 69) & 0x80) == 0 )
            *(_DWORD *)(this + 69) |= 0x80u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 57));
          goto LABEL_38;
        case 9u:
          if ( (*(_DWORD *)(this + 69) & 0x100) == 0 )
            *(_DWORD *)(this + 69) |= 0x100u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 61));
          goto LABEL_38;
        case 0xAu:
          if ( (*(_DWORD *)(this + 69) & 0x200) == 0 )
            *(_DWORD *)(this + 69) |= 0x200u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 65));
          goto LABEL_38;
        default:
          Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_38:
          Bytes = Int64;
          if ( !Int64 )
            goto LABEL_39;
          return Bytes;
      }
    }
  }
LABEL_40:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0112::DoDebugFormat
// Address Name: SUB_1016BD40
// ============================================================
//----- (1016BD40) --------------------------------------------------------
int __thiscall sub_1016BD40(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1016BDF0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0112::DebugFormat
// Address Name: SUB_1016BDF0
// ============================================================
//----- (1016BDF0) --------------------------------------------------------
int __thiscall sub_1016BDF0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[ullRoleDBID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iLevel]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[szRoleName]", (const char *)this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[bGroupID]", "0x%02x", *(this + 44));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[dwFriendly]", "%u", *(_DWORD *)(this + 45));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[iFarmPoint]", "%d", *(_DWORD *)(this + 49));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[iFarmCanBeGatheredCount]", "%d", *(_DWORD *)(this + 53));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[iHRLevel]", "%d", *(_DWORD *)(this + 57));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[iAddTime]", "%d", *(_DWORD *)(this + 61));
                  if ( !result )
                    return print_field(a2, a3, a4, "[dwSvrId]", "%d", *(_DWORD *)(this + 65));
                }
              }
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
// Address Name: SUB_1024A410
// ============================================================
//----- (1024A410) --------------------------------------------------------
int __fastcall sub_1024A410(_DWORD *a1, int a2, char a3, const char *ArgList, const char *a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xAFu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s: ", ArgList);
    if ( !result )
    {
      result = Printf(a1, "%s", a5);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
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



