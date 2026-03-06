// ============================================================
// Name: TLV::UnkTlv0135::Read_0xAA
// Address Name: SUB_10179DE0
// ============================================================
//----- (10179DE0) --------------------------------------------------------
int __thiscall sub_10179DE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int *v14; // eax
  unsigned int v15; // ecx
  int *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-Ch]
  unsigned int v22; // [esp+18h] [ebp-8h] BYREF
  int v23; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v23 = this;
  v22 = 0;
  *(_DWORD *)(this + 65) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 65) & 1) == 0 )
          *(_DWORD *)(v5 + 65) |= 1u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 65) & 2) == 0 )
          *(_DWORD *)(v5 + 65) |= 2u;
        Byte_2 = TdrBuf::ReadVarInt(v4, (int *)(v5 + 1));
        goto LABEL_42;
      case 4u:
        if ( (*(_DWORD *)(v5 + 65) & 4) == 0 )
          *(_DWORD *)(v5 + 65) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v11 = (int *)(v23 + 5);
        a3 = v23 + 5;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v11);
          if ( VarInt )
            return VarInt;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_20;
          ++v10;
          v11 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 65) & 8) == 0 )
          *(_DWORD *)(v5 + 65) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v4[1];
        v14 = (int *)(v23 + 25);
        a3 = v23 + 25;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v14);
          if ( VarInt )
            return VarInt;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_20;
          ++v10;
          v14 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 6u:
        if ( (*(_DWORD *)(v5 + 65) & 0x10) == 0 )
          *(_DWORD *)(v5 + 65) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v21 = v4[1];
        v16 = (int *)(v23 + 45);
        a3 = v23 + 45;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v16);
          if ( VarInt )
            return VarInt;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + v21 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + v21) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v23;
            *(_DWORD *)(v23 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v16 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
LABEL_43:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v22 & 0xF);
LABEL_42:
        VarInt = Byte_2;
        if ( !Byte_2 )
          goto LABEL_43;
        return VarInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0135::Read_0x99
// Address Name: SUB_1017A070
// ============================================================
//----- (1017A070) --------------------------------------------------------
int __thiscall sub_1017A070(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  _BYTE *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-Ch]
  unsigned int v22; // [esp+18h] [ebp-8h] BYREF
  int v23; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v23 = this;
  v22 = 0;
  *(_DWORD *)(this + 65) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 65) & 1) == 0 )
          *(_DWORD *)(v5 + 65) |= 1u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 65) & 2) == 0 )
          *(_DWORD *)(v5 + 65) |= 2u;
        Byte_2 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 1));
        goto LABEL_42;
      case 4u:
        if ( (*(_DWORD *)(v5 + 65) & 4) == 0 )
          *(_DWORD *)(v5 + 65) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v11 = (_BYTE *)(v23 + 5);
        a3 = v23 + 5;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v11);
          if ( Int32 )
            return Int32;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_20;
          ++v10;
          v11 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 65) & 8) == 0 )
          *(_DWORD *)(v5 + 65) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v4[1];
        v14 = (_BYTE *)(v23 + 25);
        a3 = v23 + 25;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v14);
          if ( Int32 )
            return Int32;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_20;
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 6u:
        if ( (*(_DWORD *)(v5 + 65) & 0x10) == 0 )
          *(_DWORD *)(v5 + 65) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v21 = v4[1];
        v16 = (_BYTE *)(v23 + 45);
        a3 = v23 + 45;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v16);
          if ( Int32 )
            return Int32;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + v21 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + v21) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v23;
            *(_DWORD *)(v23 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v16 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
LABEL_43:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v22 & 0xF);
LABEL_42:
        Int32 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_43;
        return Int32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0135::DoDebugFormat
// Address Name: SUB_1017A320
// ============================================================
//----- (1017A320) --------------------------------------------------------
int __thiscall sub_1017A320(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1017A3D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0135::DebugFormat
// Address Name: SUB_1017A3D0
// ============================================================
//----- (1017A3D0) --------------------------------------------------------
int __thiscall sub_1017A3D0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  _DWORD *i; // ebx
  unsigned __int8 *v19; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v20; // [esp+Ch] [ebp-4h]

  v4 = a2;
  result = print_field(a2, a3, a4, "[type]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
    {
      v8 = *(_DWORD *)(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 5 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[arg1]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( *(int *)(this + 1) <= 0 )
        {
LABEL_12:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v12 = *(_DWORD *)(this + 1);
          if ( v12 < 0 )
            return -6;
          if ( v12 <= 5 )
          {
            result = sub_1024A3B0(a2, a3, v11, "[arg2]", v12);
            if ( result )
              return result;
            v13 = 0;
            if ( *(int *)(this + 1) > 0 )
            {
              v14 = this + 25;
              v20 = this + 25;
              do
              {
                result = Printf(a2, " %d", *v14);
                if ( result )
                  return result;
                ++v13;
                v14 = v20 + 4;
                v20 += 4;
              }
              while ( v13 < *(_DWORD *)(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v16 = *(_DWORD *)(this + 1);
            if ( v16 < 0 )
              return -6;
            if ( v16 <= 5 )
            {
              result = sub_1024A3B0(a2, a3, v15, "[arg3]", v16);
              if ( !result )
              {
                v17 = 0;
                if ( *(int *)(this + 1) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = this + 45; ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v17 >= *(_DWORD *)(this + 1) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
              return result;
            }
          }
          return -7;
        }
        v10 = this + 5;
        v19 = this + 5;
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          v10 = v19 + 4;
          v19 += 4;
          if ( v9 >= *(_DWORD *)(this + 1) )
            goto LABEL_12;
        }
      }
    }
  }
  return result;
}
// 1017A45A: variable 'v7' is possibly undefined
// 1017A4D2: variable 'v11' is possibly undefined
// 1017A547: variable 'v15' is possibly undefined



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



