// ============================================================
// Name: TLV::UnkTlv0091::Read
// Address Name: SUB_10159150
// ============================================================
//----- (10159150) --------------------------------------------------------
int __thiscall sub_10159150(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  int v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = a2 - 5;
  if ( v7 == -86 )
    result = sub_10159220(this, &v9, v8);
  else
    result = sub_10159560(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0091::Read_0xAA
// Address Name: SUB_10159220
// ============================================================
//----- (10159220) --------------------------------------------------------
int __thiscall sub_10159220(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v17 = this;
  v16 = 0;
  *(this + 39) = 0;
  v7 = v4[1] + v3;
  v15 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_53;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (v5[39] & 1) == 0 )
          v5[39] |= 1u;
        VarULong = TdrBuf::ReadVarULong(v4, v5);
        goto LABEL_51;
      case 2u:
        if ( (v5[39] & 2) == 0 )
          v5[39] |= 2u;
        VarULong = TdrBuf::ReadVarInt(v4, v5 + 2);
        goto LABEL_51;
      case 3u:
        if ( (v5[39] & 4) == 0 )
          v5[39] |= 4u;
        VarULong = TdrBuf::ReadByte(v4, (_BYTE *)v5 + 12);
        goto LABEL_51;
      case 4u:
        if ( (v5[39] & 8) == 0 )
          v5[39] |= 8u;
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
          VarInt = TdrBuf::ReadVarInt(v4, (_DWORD *)((char *)&v17[v10 + 3] + 1));
          if ( VarInt )
            return VarInt;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
        goto LABEL_52;
      case 5u:
        if ( (v5[39] & 0x10) == 0 )
          v5[39] |= 0x10u;
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
          VarInt = TdrBuf::ReadVarUShort(v4, (_DWORD *)((char *)v17 + 2 * v10 + 93));
          if ( VarInt )
            return VarInt;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
        goto LABEL_52;
      case 6u:
        if ( (v5[39] & 0x20) == 0 )
          v5[39] |= 0x20u;
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
          VarInt = TdrBuf::ReadByte(v4, (_BYTE *)v17 + v10 + 133);
          if ( VarInt )
            return VarInt;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v17;
            *((_BYTE *)v17 + 12) = v10 + 1;
            v5 = v12;
            goto LABEL_52;
          }
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
LABEL_52:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_53:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      case 7u:
        if ( (v5[39] & 0x40) == 0 )
          v5[39] |= 0x40u;
        VarULong = sub_10151B00(v4, (_BYTE *)v5 + 153);
        goto LABEL_51;
      case 8u:
        if ( (v5[39] & 0x80) == 0 )
          v5[39] |= 0x80u;
        VarULong = TdrBuf::ReadVarUShort(v4, (_WORD *)v5 + 77);
        goto LABEL_51;
      default:
        VarULong = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_51:
        VarInt = VarULong;
        if ( !VarULong )
          goto LABEL_52;
        return VarInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0091::Read_0x99
// Address Name: SUB_10159560
// ============================================================
//----- (10159560) --------------------------------------------------------
int __thiscall sub_10159560(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v17 = this;
  v16 = 0;
  *(this + 39) = 0;
  v7 = v4[1] + v3;
  v15 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_53;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (v5[39] & 1) == 0 )
          v5[39] |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, v5);
        goto LABEL_51;
      case 2u:
        if ( (v5[39] & 2) == 0 )
          v5[39] |= 2u;
        Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 8);
        goto LABEL_51;
      case 3u:
        if ( (v5[39] & 4) == 0 )
          v5[39] |= 4u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)v5 + 12);
        goto LABEL_51;
      case 4u:
        if ( (v5[39] & 8) == 0 )
          v5[39] |= 8u;
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
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)&v17[v10 + 3] + 1);
          if ( Int32 )
            return Int32;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
        goto LABEL_52;
      case 5u:
        if ( (v5[39] & 0x10) == 0 )
          v5[39] |= 0x10u;
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
          Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)v17 + 2 * v10 + 93);
          if ( Int32 )
            return Int32;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
        goto LABEL_52;
      case 6u:
        if ( (v5[39] & 0x20) == 0 )
          v5[39] |= 0x20u;
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
          Int32 = TdrBuf::ReadByte(v4, (_BYTE *)v17 + v10 + 133);
          if ( Int32 )
            return Int32;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v17;
            *((_BYTE *)v17 + 12) = v10 + 1;
            v5 = v12;
            goto LABEL_52;
          }
          ++v10;
        }
        while ( v10 < 0x14u );
        v5 = v17;
LABEL_52:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_53:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      case 7u:
        if ( (v5[39] & 0x40) == 0 )
          v5[39] |= 0x40u;
        Int64 = sub_10151B00(v4, (_BYTE *)v5 + 153);
        goto LABEL_51;
      case 8u:
        if ( (v5[39] & 0x80) == 0 )
          v5[39] |= 0x80u;
        Int64 = TdrBuf::ReadInt16(v4, (_BYTE *)v5 + 154);
        goto LABEL_51;
      default:
        Int64 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_51:
        Int32 = Int64;
        if ( !Int64 )
          goto LABEL_52;
        return Int32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0091::DoDebugFormat
// Address Name: SUB_101598C0
// ============================================================
//----- (101598C0) --------------------------------------------------------
int __thiscall sub_101598C0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10159970(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0091::DebugFormat
// Address Name: SUB_10159970
// ============================================================
//----- (10159970) --------------------------------------------------------
int __thiscall sub_10159970(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl
  int v12; // ecx
  unsigned __int8 v13; // al
  unsigned __int8 v14; // bl

  result = print_field(a2, a3, a4, "[lastTime]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[awardCnt]", "%d", *(this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[itemTypeCnt]", "0x%02x", *((unsigned __int8 *)this + 12));
      if ( !result )
      {
        v7 = *((_BYTE *)this + 12);
        if ( v7 > 0x14u )
          return -7;
        result = sub_1024A3B0(a2, a3, v6, "[itemType]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *((_BYTE *)this + 12) )
          {
            while ( 1 )
            {
              result = Printf(a2, " %d", *(_DWORD *)((char *)this + 4 * v8 + 13));
              if ( result )
                break;
              if ( ++v8 >= *((_BYTE *)this + 12) )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              v10 = *((_BYTE *)this + 12);
              if ( v10 > 0x14u )
                return -7;
              result = sub_1024A3B0(a2, a3, v9, "[itemCnt]", v10);
              if ( !result )
              {
                v11 = 0;
                if ( *((_BYTE *)this + 12) )
                {
                  while ( 1 )
                  {
                    result = Printf(a2, " %d", *(unsigned __int16 *)((char *)this + 2 * v11 + 93));
                    if ( result )
                      break;
                    if ( ++v11 >= *((_BYTE *)this + 12) )
                      goto LABEL_16;
                  }
                }
                else
                {
LABEL_16:
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( !result )
                  {
                    v13 = *((_BYTE *)this + 12);
                    if ( v13 > 0x14u )
                      return -7;
                    result = sub_1024A3B0(a2, a3, v12, "[itemBindType]", v13);
                    if ( !result )
                    {
                      v14 = 0;
                      if ( *((_BYTE *)this + 12) )
                      {
                        while ( 1 )
                        {
                          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v14 + 133));
                          if ( result )
                            break;
                          if ( ++v14 >= *((_BYTE *)this + 12) )
                            goto LABEL_22;
                        }
                      }
                      else
                      {
LABEL_22:
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[vipFlag]", "0x%02x", *((char *)this + 153));
                          if ( !result )
                            return print_field(a2, a3, a4, "[farmLevel]", "%d", *((unsigned __int16 *)this + 77));
                        }
                      }
                    }
                  }
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
// 10159A0D: variable 'v6' is possibly undefined
// 10159A72: variable 'v9' is possibly undefined
// 10159AE4: variable 'v12' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10151B00
// ============================================================
//----- (10151B00) --------------------------------------------------------
int __thiscall sub_10151B00(_DWORD *this, _BYTE *a2)
{
  int v3; // ecx

  if ( *(this + 1) > *(this + 2) )
    _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
  v3 = *(this + 1);
  if ( *(this + 2) == v3 )
    return -2;
  *a2 = *(_BYTE *)(v3 + *this);
  ++*(this + 1);
  return 0;
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



