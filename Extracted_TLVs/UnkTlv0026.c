// ============================================================
// Name: TLV::UnkTlv0026::Read_0xAA
// Address Name: SUB_10123390
// ============================================================
//----- (10123390) --------------------------------------------------------
int __thiscall sub_10123390(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 114) = 0;
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
          if ( (*(_BYTE *)(this + 114) & 1) == 0 )
            *(this + 114) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_34;
        case 2u:
          if ( (*(this + 114) & 2) == 0 )
            *(this + 114) |= 2u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_35;
          VarInt = sub_10118210(this + 1, (size_t)v4, Size);
LABEL_34:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_35;
          return Bytes;
        case 3u:
          if ( (*(this + 114) & 4) == 0 )
            *(this + 114) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 15);
          goto LABEL_34;
        case 4u:
          if ( (*(this + 114) & 8) == 0 )
            *(this + 114) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 16, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 64) = 0;
          goto LABEL_35;
        case 5u:
          if ( (*(this + 114) & 0x10) == 0 )
            *(this + 114) |= 0x10u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 48, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 192) = 0;
LABEL_35:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_36;
          break;
        case 6u:
          if ( (*(this + 114) & 0x20) == 0 )
            *(this + 114) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 112);
          goto LABEL_34;
        case 7u:
          if ( (*(this + 114) & 0x40) == 0 )
            *(this + 114) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 113);
          goto LABEL_34;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_34;
      }
    }
  }
LABEL_36:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0026::Read_0x99
// Address Name: SUB_10123600
// ============================================================
//----- (10123600) --------------------------------------------------------
int __thiscall sub_10123600(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 456) = 0;
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
          if ( (*(_BYTE *)(this + 456) & 1) == 0 )
            *(_DWORD *)(this + 456) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_34;
        case 2u:
          if ( (*(_DWORD *)(this + 456) & 2) == 0 )
            *(_DWORD *)(this + 456) |= 2u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_35;
          Int32 = sub_10118360((_DWORD *)(this + 4), (size_t)v4, Size);
LABEL_34:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_35;
          return Bytes;
        case 3u:
          if ( (*(_DWORD *)(this + 456) & 4) == 0 )
            *(_DWORD *)(this + 456) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
          goto LABEL_34;
        case 4u:
          if ( (*(_DWORD *)(this + 456) & 8) == 0 )
            *(_DWORD *)(this + 456) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 64), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 64) = 0;
          goto LABEL_35;
        case 5u:
          if ( (*(_DWORD *)(this + 456) & 0x10) == 0 )
            *(_DWORD *)(this + 456) |= 0x10u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 192), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 192) = 0;
LABEL_35:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_36;
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 456) & 0x20) == 0 )
            *(_DWORD *)(this + 456) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 448));
          goto LABEL_34;
        case 7u:
          if ( (*(_DWORD *)(this + 456) & 0x40) == 0 )
            *(_DWORD *)(this + 456) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 452));
          goto LABEL_34;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_34;
      }
    }
  }
LABEL_36:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0026::DoDebugFormat
// Address Name: SUB_10123890
// ============================================================
//----- (10123890) --------------------------------------------------------
int __thiscall sub_10123890(const char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10123940(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0026::DebugFormat
// Address Name: SUB_10123940
// ============================================================
//----- (10123940) --------------------------------------------------------
int __thiscall sub_10123940(const char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    if ( !"[role]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[role]", (char)a4);
      if ( !result )
      {
        v5 = (int)(this + 4);
        if ( a3 >= 0 )
          result = sub_10118580(v5, a2, a3 + 1, a4);
        else
          result = sub_10118580(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[level]", "%d", *((_DWORD *)this + 15));
          if ( !result )
          {
            result = sub_1024A410(a2, a3, a4, "[hunterStar]", this + 64);
            if ( !result )
            {
              result = sub_1024A410(a2, a3, a4, "[note]", this + 192);
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[time]", "%d", *((_DWORD *)this + 112));
                if ( !result )
                  return print_field(a2, a3, a4, "[hRLevel]", "%d", *((_DWORD *)this + 113));
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
// Address Name: SUB_10118210
// ============================================================
//----- (10118210) --------------------------------------------------------
int __thiscall sub_10118210(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 8);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            VarULong = TdrBuf::ReadVarUInt(v4, this + 10);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 11);
            goto LABEL_20;
          default:
            VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = VarULong;
            if ( VarULong )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10118360
// ============================================================
//----- (10118360) --------------------------------------------------------
int __thiscall sub_10118360(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 32);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)this + 40);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 44);
            goto LABEL_20;
          default:
            Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = Int64;
            if ( Int64 )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
            continue;
        }
      }
      break;
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
// Address Name: SUB_10118580
// ============================================================
//----- (10118580) --------------------------------------------------------
int __thiscall sub_10118580(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = sub_1024A410((int)a2, a4, (char)"[name]", this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 32));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[rtid]", "%u", *(_DWORD *)(this + 40));
      if ( !result )
        return print_field(a2, a3, a4, "[uin]", "%I64u", *(_QWORD *)(this + 44));
    }
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



