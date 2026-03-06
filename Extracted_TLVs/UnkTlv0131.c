// ============================================================
// Name: TLV::UnkTlv0131::Read
// Address Name: SUB_101777A0
// ============================================================
//----- (101777A0) --------------------------------------------------------
int __thiscall sub_101777A0(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  char *v8; // [esp-Ch] [ebp-1Ch]
  unsigned int v9; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  v9 = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&v9, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&v9, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = (char *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_10177870(this, &v9, v8);
  else
    result = sub_10177AE0((int)this, &v9, (int)v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0131::Read_0xAA
// Address Name: SUB_10177870
// ============================================================
//----- (10177870) --------------------------------------------------------
int __thiscall sub_10177870(_DWORD *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int Byte_2; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte_2 = 0;
  v19 = this;
  v18 = 0;
  *(_DWORD *)((char *)this + 38) = 0;
  v7 = (unsigned int)&v3[v4[1]];
  v16 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 38) & 1) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 2) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v4, v5 + 1);
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 4) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v19 + v10 + 8);
          if ( Byte_2 )
            return Byte_2;
          v11 = v4[1];
          if ( (_DWORD *)v11 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 8) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v19 + v10 + 13);
          if ( Byte_2 )
            return Byte_2;
          v13 = v4[1];
          if ( (_DWORD *)v13 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 0x10) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v4[1];
        v14 = (_DWORD *)((char *)v19 + 18);
        a3 = (char *)v19 + 18;
        do
        {
          Byte_2 = TdrBuf::ReadVarInt(v4, v14);
          if ( Byte_2 )
            return Byte_2;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v17) )
          {
LABEL_20:
            v12 = v10 + 1;
            v5 = v19;
            v19[1] = v12;
            goto LABEL_43;
          }
          ++v10;
          v14 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v19;
LABEL_43:
        v7 = v16;
        if ( v4[1] < v16 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Byte_2;
      default:
        VarUInt = TdrBuf::SkipField(v4, v18 & 0xF);
LABEL_42:
        Byte_2 = VarUInt;
        if ( !VarUInt )
          goto LABEL_43;
        return Byte_2;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0131::Read_0x99
// Address Name: SUB_10177AE0
// ============================================================
//----- (10177AE0) --------------------------------------------------------
int __thiscall sub_10177AE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte_2; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  int v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte_2 = 0;
  v19 = this;
  v18 = 0;
  *(_DWORD *)(this + 38) = 0;
  v7 = v4[1] + v3;
  v16 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 38) & 1) == 0 )
          *(_DWORD *)(v5 + 38) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 38) & 2) == 0 )
          *(_DWORD *)(v5 + 38) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)(v5 + 38) & 4) == 0 )
          *(_DWORD *)(v5 + 38) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v10 + v19 + 8));
          if ( Byte_2 )
            return Byte_2;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)(v5 + 38) & 8) == 0 )
          *(_DWORD *)(v5 + 38) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v10 + v19 + 13));
          if ( Byte_2 )
            return Byte_2;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 38) & 0x10) == 0 )
          *(_DWORD *)(v5 + 38) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v4[1];
        v14 = (_BYTE *)(v19 + 18);
        a3 = v19 + 18;
        do
        {
          Byte_2 = TdrBuf::ReadInt32(v4, v14);
          if ( Byte_2 )
            return Byte_2;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v17) )
          {
LABEL_20:
            v12 = v10 + 1;
            v5 = v19;
            *(_DWORD *)(v19 + 4) = v12;
            goto LABEL_43;
          }
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v19;
LABEL_43:
        v7 = v16;
        if ( v4[1] < v16 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Byte_2;
      default:
        Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
LABEL_42:
        Byte_2 = Int32;
        if ( !Int32 )
          goto LABEL_43;
        return Byte_2;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0131::DoDebugFormat
// Address Name: SUB_10177D70
// ============================================================
//----- (10177D70) --------------------------------------------------------
int __thiscall sub_10177D70(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10177E20(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0131::DebugFormat
// Address Name: SUB_10177E20
// ============================================================
//----- (10177E20) --------------------------------------------------------
int __thiscall sub_10177E20(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 5 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[awardsType]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_11:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v11 = *(this + 1);
          if ( v11 < 0 )
            return -6;
          if ( v11 <= 5 )
          {
            result = sub_1024A3B0(a2, a3, v10, "[awardsState]", v11);
            if ( result )
              return result;
            v12 = 0;
            if ( (int)*(this + 1) > 0 )
            {
              do
              {
                result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v12 + 13));
                if ( result )
                  return result;
              }
              while ( ++v12 < *(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v14 = *(this + 1);
            if ( v14 < 0 )
              return -6;
            if ( v14 <= 5 )
            {
              result = sub_1024A3B0(a2, a3, v13, "[awardsId]", v14);
              if ( !result )
              {
                v15 = 0;
                if ( (int)*(this + 1) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = (_DWORD *)((char *)this + 18); ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v15 >= *(this + 1) )
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
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v9 + 8));
          if ( result )
            break;
          if ( ++v9 >= *(this + 1) )
            goto LABEL_11;
        }
      }
    }
  }
  return result;
}
// 10177EA3: variable 'v7' is possibly undefined
// 10177F12: variable 'v10' is possibly undefined
// 10177F7E: variable 'v13' is possibly undefined



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



