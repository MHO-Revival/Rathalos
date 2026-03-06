// ============================================================
// Name: TLV::UnkTlv0224::Read_0xAA
// Address Name: SUB_1020EB80
// ============================================================
//----- (1020EB80) --------------------------------------------------------
int __thiscall sub_1020EB80(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int i; // eax
  unsigned int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-Ch]
  unsigned int v21; // [esp+10h] [ebp-8h] BYREF
  int v22; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v22 = this;
  v21 = 0;
  *(_DWORD *)(this + 2825) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_50:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 2825) & 1) == 0 )
          *(_DWORD *)(v5 + 2825) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)v5);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v5 + 2825) & 2) == 0 )
          *(_DWORD *)(v5 + 2825) |= 2u;
        VarULong = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v5 + 2825) & 4) == 0 )
          *(_DWORD *)(v5 + 2825) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v11 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v22 + 9 + v11));
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
          {
            v11 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 6u:
        if ( (*(_DWORD *)(v5 + 2825) & 8) == 0 )
          *(_DWORD *)(v5 + 2825) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v14 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v22 + 4 * v14 + 265));
          if ( Byte )
            return Byte;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + a3) )
          {
            v14 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 7u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x10) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v16 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v22 + 4 * v16 + 1289));
          if ( Byte )
            return Byte;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + a3) )
          {
            v16 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 8u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x20) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          for ( i = 0; ; i = v10 )
          {
            Byte = TdrBuf::ReadVarUShort(v4, (_WORD *)(v22 + 2 * i + 2313));
            if ( Byte )
              return Byte;
            v19 = v4[1];
            if ( v19 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + a3) )
            {
LABEL_19:
              v13 = v22;
              *(_BYTE *)(v22 + 8) = v10 + 1;
              v5 = v13;
LABEL_49:
              v7 = v20;
              if ( v4[1] >= v20 )
                goto LABEL_50;
              goto LABEL_2;
            }
            ++v10;
          }
LABEL_54:
          result = -34;
        }
        else
        {
LABEL_55:
          result = -37;
        }
        break;
      default:
        VarULong = TdrBuf::SkipField(v4, v21 & 0xF);
LABEL_48:
        Byte = VarULong;
        if ( !VarULong )
          goto LABEL_49;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0224::Read_0x99
// Address Name: SUB_1020EED0
// ============================================================
//----- (1020EED0) --------------------------------------------------------
int __thiscall sub_1020EED0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int i; // eax
  unsigned int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-Ch]
  unsigned int v21; // [esp+10h] [ebp-8h] BYREF
  int v22; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v22 = this;
  v21 = 0;
  *(_DWORD *)(this + 2825) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_50:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 2825) & 1) == 0 )
          *(_DWORD *)(v5 + 2825) |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)v5);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v5 + 2825) & 2) == 0 )
          *(_DWORD *)(v5 + 2825) |= 2u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v5 + 2825) & 4) == 0 )
          *(_DWORD *)(v5 + 2825) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v11 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v22 + 9 + v11));
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
          {
            v11 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 6u:
        if ( (*(_DWORD *)(v5 + 2825) & 8) == 0 )
          *(_DWORD *)(v5 + 2825) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v14 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v22 + 4 * v14 + 265));
          if ( Byte )
            return Byte;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + a3) )
          {
            v14 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 7u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x10) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v16 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v22 + 4 * v16 + 1289));
          if ( Byte )
            return Byte;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + a3) )
          {
            v16 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 8u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x20) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          for ( i = 0; ; i = v10 )
          {
            Byte = TdrBuf::ReadInt16(v4, (_BYTE *)(v22 + 2 * i + 2313));
            if ( Byte )
              return Byte;
            v19 = v4[1];
            if ( v19 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + a3) )
            {
LABEL_19:
              v13 = v22;
              *(_BYTE *)(v22 + 8) = v10 + 1;
              v5 = v13;
LABEL_49:
              v7 = v20;
              if ( v4[1] >= v20 )
                goto LABEL_50;
              goto LABEL_2;
            }
            ++v10;
          }
LABEL_54:
          result = -34;
        }
        else
        {
LABEL_55:
          result = -37;
        }
        break;
      default:
        Int64 = TdrBuf::SkipField(v4, v21 & 0xF);
LABEL_48:
        Byte = Int64;
        if ( !Int64 )
          goto LABEL_49;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0224::DoDebugFormat
// Address Name: SUB_1020F240
// ============================================================
//----- (1020F240) --------------------------------------------------------
int __thiscall sub_1020F240(_BYTE *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1020F2F0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0224::DebugFormat
// Address Name: SUB_1020F2F0
// ============================================================
//----- (1020F2F0) --------------------------------------------------------
int __thiscall sub_1020F2F0(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // bl
  int v11; // ecx
  unsigned __int8 v12; // bl
  int v13; // edx
  unsigned __int8 v14; // bl
  int v15; // ecx
  int v16; // [esp+18h] [ebp+8h]

  result = print_field(a2, a3, a4, "[lastResetTm]", "%I64u", *(_QWORD *)this);
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[limitDataCnt]", "0x%02x", (unsigned __int8)*(this + 8));
  if ( result )
    return result;
  result = sub_1024A3B0(a2, a3, v7, "[shopType]", (unsigned __int8)*(this + 8));
  if ( result )
    return result;
  v8 = 0;
  if ( *(this + 8) )
  {
    while ( 1 )
    {
      result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v8 + 9));
      if ( result )
        break;
      if ( ++v8 >= *(this + 8) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    result = TdrBuf::WriteChar(a2, a4);
    if ( result )
      return result;
    result = sub_1024A3B0(a2, a3, v9, "[shopID]", (unsigned __int8)*(this + 8));
    if ( result )
      return result;
    v10 = 0;
    if ( *(this + 8) )
    {
      while ( 1 )
      {
        result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v10 + 265));
        if ( result )
          break;
        if ( ++v10 >= *(this + 8) )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      result = TdrBuf::WriteChar(a2, a4);
      if ( result )
        return result;
      result = sub_1024A3B0(a2, a3, v11, "[saleID]", (unsigned __int8)*(this + 8));
      if ( result )
        return result;
      v12 = 0;
      if ( !*(this + 8) )
      {
LABEL_17:
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0xC4u);
        v13 = a2[1];
        if ( (unsigned int)(a2[2] - v13) >= 2 )
        {
          *(_BYTE *)(v13 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          v16 = (unsigned __int8)*(this + 8);
          if ( !"[buyCount]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x9Du);
          result = sub_1024A140(a3);
          if ( result )
            return result;
          result = Printf(a2, "%s[0 : %I64i]:", "[buyCount]", (unsigned int)v16 - 1LL);
          if ( result )
            return result;
          v14 = 0;
          if ( *(this + 8) )
          {
            do
            {
              result = Printf(a2, " %d", *(unsigned __int16 *)(this + 2 * v14 + 2313));
              if ( result )
                return result;
            }
            while ( ++v14 < *(this + 8) );
          }
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v15 = a2[1];
          if ( (unsigned int)(a2[2] - v15) >= 2 )
          {
            *(_BYTE *)(v15 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            return 0;
          }
        }
        return -1;
      }
      while ( 1 )
      {
        result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v12 + 1289));
        if ( result )
          break;
        if ( ++v12 >= *(this + 8) )
          goto LABEL_17;
      }
    }
  }
  return result;
}
// 1020F358: variable 'v7' is possibly undefined
// 1020F3BA: variable 'v9' is possibly undefined
// 1020F41C: variable 'v11' is possibly undefined



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



