// ============================================================
// Name: TLV::UnkTlv0299::Read_0xAA
// Address Name: SUB_1024C9D0
// ============================================================
//----- (1024C9D0) --------------------------------------------------------
int __thiscall sub_1024C9D0(int this, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = (_DWORD *)a2;
  v5 = this;
  VarInt = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 517) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_36;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v5 + 517) & 1) == 0 )
          *(_DWORD *)(v5 + 517) |= 1u;
        a2 = 0;
        VarInt = TdrBuf::ReadInt32(v4, &a2);
        if ( VarInt )
          return VarInt;
        if ( !a2 )
          goto LABEL_35;
        Byte_2 = sub_1024C0C0((_DWORD *)v5, v4, a2);
        goto LABEL_34;
      case 3u:
        if ( (*(_DWORD *)(v5 + 517) & 2) == 0 )
          *(_DWORD *)(v5 + 517) |= 2u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v5 + 16));
        goto LABEL_34;
      case 4u:
        if ( (*(_DWORD *)(v5 + 517) & 4) == 0 )
          *(_DWORD *)(v5 + 517) |= 4u;
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
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(v16 + 4 * v10 + 17));
          if ( VarInt )
            return VarInt;
          v11 = v4[1];
          if ( v11 > a3 + a2 )
            return -34;
          if ( v11 == a3 + a2 )
            goto LABEL_22;
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
        goto LABEL_35;
      case 5u:
        if ( (*(_DWORD *)(v5 + 517) & 8) == 0 )
          *(_DWORD *)(v5 + 517) |= 8u;
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
          VarInt = TdrBuf::ReadByte_2(v4, (_BYTE *)(v16 + 417 + v10));
          if ( VarInt )
            return VarInt;
          v13 = v4[1];
          if ( v13 > a3 + a2 )
            return -34;
          if ( v13 == a3 + a2 )
          {
LABEL_22:
            v12 = v16;
            *(_BYTE *)(v16 + 16) = v10 + 1;
            v5 = v12;
            goto LABEL_35;
          }
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
LABEL_35:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_36:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_34:
        VarInt = Byte_2;
        if ( !Byte_2 )
          goto LABEL_35;
        return VarInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0299::Read_0x99
// Address Name: SUB_1024CC10
// ============================================================
//----- (1024CC10) --------------------------------------------------------
int __thiscall sub_1024CC10(int this, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = (_DWORD *)a2;
  v5 = this;
  Int32 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 517) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_36;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v5 + 517) & 1) == 0 )
          *(_DWORD *)(v5 + 517) |= 1u;
        a2 = 0;
        Int32 = TdrBuf::ReadInt32(v4, &a2);
        if ( Int32 )
          return Int32;
        if ( !a2 )
          goto LABEL_35;
        Byte_2 = sub_1024C170(v5, v4, a2);
        goto LABEL_34;
      case 3u:
        if ( (*(_DWORD *)(v5 + 517) & 2) == 0 )
          *(_DWORD *)(v5 + 517) |= 2u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v5 + 16));
        goto LABEL_34;
      case 4u:
        if ( (*(_DWORD *)(v5 + 517) & 4) == 0 )
          *(_DWORD *)(v5 + 517) |= 4u;
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
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 17));
          if ( Int32 )
            return Int32;
          v11 = v4[1];
          if ( v11 > a3 + a2 )
            return -34;
          if ( v11 == a3 + a2 )
            goto LABEL_22;
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
        goto LABEL_35;
      case 5u:
        if ( (*(_DWORD *)(v5 + 517) & 8) == 0 )
          *(_DWORD *)(v5 + 517) |= 8u;
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
          Int32 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v16 + 417 + v10));
          if ( Int32 )
            return Int32;
          v13 = v4[1];
          if ( v13 > a3 + a2 )
            return -34;
          if ( v13 == a3 + a2 )
          {
LABEL_22:
            v12 = v16;
            *(_BYTE *)(v16 + 16) = v10 + 1;
            v5 = v12;
            goto LABEL_35;
          }
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
LABEL_35:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_36:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_34:
        Int32 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_35;
        return Int32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0299::DoDebugFormat
// Address Name: SUB_1024CE70
// ============================================================
//----- (1024CE70) --------------------------------------------------------
int __thiscall sub_1024CE70(void *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1024CF20((int)this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0299::DebugFormat
// Address Name: SUB_1024CF20
// ============================================================
//----- (1024CF20) --------------------------------------------------------
int __thiscall sub_1024CF20(int this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  if ( !"[giftAttr]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[giftAttr]", a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_1024C2F0((_DWORD *)this, a2, a3 + 1, a4) : sub_1024C2F0((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[giftNum]", "0x%02x", *(unsigned __int8 *)(this + 16));
        if ( !result )
        {
          v7 = *(_BYTE *)(this + 16);
          if ( v7 > 0x64u )
            return -7;
          result = sub_1024A3B0(a2, a3, v6, "[giftId]", v7);
          if ( !result )
          {
            v8 = 0;
            if ( *(_BYTE *)(this + 16) )
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v8 + 17));
                if ( result )
                  break;
                if ( ++v8 >= *(_BYTE *)(this + 16) )
                  goto LABEL_16;
              }
            }
            else
            {
LABEL_16:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                v10 = *(_BYTE *)(this + 16);
                if ( v10 > 0x64u )
                  return -7;
                result = sub_1024A3B0(a2, a3, v9, "[giftState]", v10);
                if ( !result )
                {
                  v11 = 0;
                  if ( *(_BYTE *)(this + 16) )
                  {
                    while ( 1 )
                    {
                      result = Printf(a2, " 0x%02x", *(unsigned __int8 *)(v11 + this + 417));
                      if ( result )
                        break;
                      if ( ++v11 >= *(_BYTE *)(this + 16) )
                        return TdrBuf::WriteChar(a2, a4);
                    }
                  }
                  else
                  {
                    return TdrBuf::WriteChar(a2, a4);
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
// 1024CFE6: variable 'v6' is possibly undefined
// 1024D046: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024C0C0
// ============================================================
//----- (1024C0C0) --------------------------------------------------------
int __thiscall sub_1024C0C0(_DWORD *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1024C170
// ============================================================
//----- (1024C170) --------------------------------------------------------
int __thiscall sub_1024C170(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1024C2F0
// ============================================================
//----- (1024C2F0) --------------------------------------------------------
int __thiscall sub_1024C2F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[onlineTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[consecDays]", "%u", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 2));
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



