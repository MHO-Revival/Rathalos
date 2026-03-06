// ============================================================
// Name: TLV::UnkTlv0209::Read
// Address Name: SUB_101FDF20
// ============================================================
//----- (101FDF20) --------------------------------------------------------
int __thiscall sub_101FDF20(int *this, size_t a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  size_t v6; // esi
  char v7; // bl
  int v8; // [esp-Ch] [ebp-1Ch]
  size_t Size; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  Size = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&Size, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&Size, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = a2 - 5;
  if ( v7 == -86 )
    result = sub_101FDFF0(this, (size_t)&Size, v8);
  else
    result = sub_101FE280((int)this, (size_t)&Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0209::Read_0xAA
// Address Name: SUB_101FDFF0
// ============================================================
//----- (101FDFF0) --------------------------------------------------------
int __thiscall sub_101FDFF0(int *this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h] BYREF
  unsigned int v16; // [esp+24h] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v16 = 0;
  *(this + 16) = 0;
  v7 = v4[1] + v3;
  v10 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        return result;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(this + 16) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_41;
        case 2u:
          if ( (*(this + 16) & 2) == 0 )
            *(this + 16) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 1, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 4) = 0;
LABEL_42:
          v7 = v10;
          if ( v4[1] >= v10 )
            goto LABEL_43;
          break;
        case 3u:
          if ( (*(this + 16) & 4) == 0 )
            *(this + 16) |= 4u;
          Bytes = TdrBuf::ReadInt32(v4, &a3);
          if ( Bytes )
            return Bytes;
          *(this + 9) = a3;
          goto LABEL_42;
        case 4u:
          if ( (*(this + 16) & 8) == 0 )
            *(this + 16) |= 8u;
          Bytes = TdrBuf::ReadInt32(v4, &v15);
          if ( Bytes )
            return Bytes;
          *(this + 10) = v15;
          goto LABEL_42;
        case 5u:
          if ( (*(this + 16) & 0x10) == 0 )
            *(this + 16) |= 0x10u;
          Bytes = TdrBuf::ReadInt32(v4, &v14);
          if ( Bytes )
            return Bytes;
          *(this + 11) = v14;
          goto LABEL_42;
        case 6u:
          if ( (*(this + 16) & 0x20) == 0 )
            *(this + 16) |= 0x20u;
          Bytes = TdrBuf::ReadInt32(v4, &v13);
          if ( Bytes )
            return Bytes;
          *(this + 12) = v13;
          goto LABEL_42;
        case 7u:
          if ( (*(this + 16) & 0x40) == 0 )
            *(this + 16) |= 0x40u;
          Bytes = TdrBuf::ReadInt32(v4, &v12);
          if ( Bytes )
            return Bytes;
          *(this + 13) = v12;
          goto LABEL_42;
        case 8u:
          if ( (*(this + 16) & 0x80) == 0 )
            *(this + 16) |= 0x80u;
          Bytes = TdrBuf::ReadInt32(v4, &v11);
          if ( Bytes )
            return Bytes;
          *(this + 14) = v11;
          goto LABEL_42;
        case 9u:
          if ( (*(this + 16) & 0x100) == 0 )
            *(this + 16) |= 0x100u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 15);
          goto LABEL_41;
        default:
          VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_41:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_42;
          return Bytes;
      }
    }
  }
LABEL_43:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0209::Read_0x99
// Address Name: SUB_101FE280
// ============================================================
//----- (101FE280) --------------------------------------------------------
int __thiscall sub_101FE280(int this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h] BYREF
  unsigned int v16; // [esp+24h] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v16 = 0;
  *(_DWORD *)(this + 64) = 0;
  v7 = v4[1] + v3;
  v10 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        return result;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 64) & 1) == 0 )
            *(_DWORD *)(this + 64) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_41;
        case 2u:
          if ( (*(_DWORD *)(this + 64) & 2) == 0 )
            *(_DWORD *)(this + 64) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 4), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 4) = 0;
LABEL_42:
          v7 = v10;
          if ( v4[1] >= v10 )
            goto LABEL_43;
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 64) & 4) == 0 )
            *(_DWORD *)(this + 64) |= 4u;
          Bytes = TdrBuf::ReadInt32(v4, &a3);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 36) = a3;
          goto LABEL_42;
        case 4u:
          if ( (*(_DWORD *)(this + 64) & 8) == 0 )
            *(_DWORD *)(this + 64) |= 8u;
          Bytes = TdrBuf::ReadInt32(v4, &v15);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 40) = v15;
          goto LABEL_42;
        case 5u:
          if ( (*(_DWORD *)(this + 64) & 0x10) == 0 )
            *(_DWORD *)(this + 64) |= 0x10u;
          Bytes = TdrBuf::ReadInt32(v4, &v14);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 44) = v14;
          goto LABEL_42;
        case 6u:
          if ( (*(_DWORD *)(this + 64) & 0x20) == 0 )
            *(_DWORD *)(this + 64) |= 0x20u;
          Bytes = TdrBuf::ReadInt32(v4, &v13);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 48) = v13;
          goto LABEL_42;
        case 7u:
          if ( (*(_DWORD *)(this + 64) & 0x40) == 0 )
            *(_DWORD *)(this + 64) |= 0x40u;
          Bytes = TdrBuf::ReadInt32(v4, &v12);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 52) = v12;
          goto LABEL_42;
        case 8u:
          if ( (*(_DWORD *)(this + 64) & 0x80) == 0 )
            *(_DWORD *)(this + 64) |= 0x80u;
          Bytes = TdrBuf::ReadInt32(v4, &v11);
          if ( Bytes )
            return Bytes;
          *(_DWORD *)(this + 56) = v11;
          goto LABEL_42;
        case 9u:
          if ( (*(_DWORD *)(this + 64) & 0x100) == 0 )
            *(_DWORD *)(this + 64) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
          goto LABEL_41;
        default:
          Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_41:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_42;
          return Bytes;
      }
    }
  }
LABEL_43:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0209::DoDebugFormat
// Address Name: SUB_101FE530
// ============================================================
//----- (101FE530) --------------------------------------------------------
int __thiscall sub_101FE530(const char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101FE5E0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0209::DebugFormat
// Address Name: SUB_101FE5E0
// ============================================================
//----- (101FE5E0) --------------------------------------------------------
int __thiscall sub_101FE5E0(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[boneId]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[part]", this + 4);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[posX]", "%f", *((float *)this + 9));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[posY]", "%f", *((float *)this + 10));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[posZ]", "%f", *((float *)this + 11));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[dirX]", "%f", *((float *)this + 12));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[dirY]", "%f", *((float *)this + 13));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[dirZ]", "%f", *((float *)this + 14));
                if ( !result )
                  return print_field(a2, a3, a4, "[logicVehicleId]", "%u", *((_DWORD *)this + 15));
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



