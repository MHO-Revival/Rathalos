// ============================================================
// Name: TLV::UnkTlv0207::Read_0xAA
// Address Name: SUB_101FC550
// ============================================================
//----- (101FC550) --------------------------------------------------------
int __thiscall sub_101FC550(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  __int16 v10; // bx
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 67) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_47;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[67] & 1) == 0 )
          v4[67] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_45;
      case 2u:
        if ( (v4[67] & 2) == 0 )
          v4[67] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_45;
      case 3u:
        if ( (v4[67] & 4) == 0 )
          v4[67] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_45;
      case 4u:
        if ( (v4[67] & 8) == 0 )
          v4[67] |= 8u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 3);
        goto LABEL_45;
      case 5u:
        if ( (v4[67] & 0x10) == 0 )
          v4[67] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 4);
        goto LABEL_45;
      case 6u:
        if ( (v4[67] & 0x20) == 0 )
          v4[67] |= 0x20u;
        VarInt = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 10);
        goto LABEL_45;
      case 7u:
        if ( (v4[67] & 0x40) == 0 )
          v4[67] |= 0x40u;
        VarInt = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 11);
        goto LABEL_45;
      case 8u:
        if ( (v4[67] & 0x80) == 0 )
          v4[67] |= 0x80u;
        VarInt = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 12);
        goto LABEL_45;
      case 9u:
        if ( (v4[67] & 0x100) == 0 )
          v4[67] |= 0x100u;
        VarInt = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 13);
        goto LABEL_45;
      case 0xAu:
        if ( (v4[67] & 0x200) == 0 )
          v4[67] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          v5 = TdrBuf::ReadInt32(v6, &a3);
          if ( v5 )
            return v5;
          if ( a3 )
          {
            v5 = sub_101FB9F0(&v16[6 * v10 + 7], v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 10 )
          {
            v4 = v16;
            goto LABEL_46;
          }
        }
        v12 = v10 + 1;
        v4 = v16;
        *((_WORD *)v16 + 13) = v12;
LABEL_46:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_47:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_45:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_46;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0207::Read_0x99
// Address Name: SUB_101FC830
// ============================================================
//----- (101FC830) --------------------------------------------------------
int __thiscall sub_101FC830(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  __int16 v10; // bx
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 67) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_47;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[67] & 1) == 0 )
          v4[67] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_45;
      case 2u:
        if ( (v4[67] & 2) == 0 )
          v4[67] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_45;
      case 3u:
        if ( (v4[67] & 4) == 0 )
          v4[67] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_45;
      case 4u:
        if ( (v4[67] & 8) == 0 )
          v4[67] |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 12);
        goto LABEL_45;
      case 5u:
        if ( (v4[67] & 0x10) == 0 )
          v4[67] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 16);
        goto LABEL_45;
      case 6u:
        if ( (v4[67] & 0x20) == 0 )
          v4[67] |= 0x20u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)v4 + 20);
        goto LABEL_45;
      case 7u:
        if ( (v4[67] & 0x40) == 0 )
          v4[67] |= 0x40u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)v4 + 22);
        goto LABEL_45;
      case 8u:
        if ( (v4[67] & 0x80) == 0 )
          v4[67] |= 0x80u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)v4 + 24);
        goto LABEL_45;
      case 9u:
        if ( (v4[67] & 0x100) == 0 )
          v4[67] |= 0x100u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)v4 + 26);
        goto LABEL_45;
      case 0xAu:
        if ( (v4[67] & 0x200) == 0 )
          v4[67] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          v5 = TdrBuf::ReadInt32(v6, &a3);
          if ( v5 )
            return v5;
          if ( a3 )
          {
            v5 = sub_101FBB20((int)&v16[6 * v10 + 7], v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 10 )
          {
            v4 = v16;
            goto LABEL_46;
          }
        }
        v12 = v10 + 1;
        v4 = v16;
        *((_WORD *)v16 + 13) = v12;
LABEL_46:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_47:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_45:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_46;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0207::DoDebugFormat
// Address Name: SUB_101FCB30
// ============================================================
//----- (101FCB30) --------------------------------------------------------
int __thiscall sub_101FCB30(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101FCBE0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0207::DebugFormat
// Address Name: SUB_101FCBE0
// ============================================================
//----- (101FCBE0) --------------------------------------------------------
int __thiscall sub_101FCBE0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx

  result = print_field(a2, a3, a4, "[buffId]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[uID]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[ownerId]", "%d", *((_DWORD *)this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[retainTime]", "%d", *((_DWORD *)this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[expireTime]", "%d", *((_DWORD *)this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[count]", "%d", *(this + 10));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[stack]", "%d", *(this + 11));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[from]", "%d", *(this + 12));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[effectNum]", "%d", *(this + 13));
                  if ( !result )
                  {
                    v6 = *(this + 13);
                    if ( v6 >= 0 )
                    {
                      if ( v6 <= 10 )
                      {
                        v7 = 0;
                        if ( v6 <= 0 )
                        {
                          return 0;
                        }
                        else
                        {
                          while ( 1 )
                          {
                            result = sub_1024A230(a2, a3, a4, "[effectData]", v7);
                            if ( result )
                              break;
                            result = a3 >= 0
                                   ? sub_101FBD20((_DWORD *)this + 6 * v7 + 7, a2, a3 + 1, a4)
                                   : sub_101FBD20((_DWORD *)this + 6 * v7 + 7, a2, a3, a4);
                            if ( result )
                              break;
                            if ( ++v7 >= *(this + 13) )
                              return 0;
                          }
                        }
                      }
                      else
                      {
                        return -7;
                      }
                    }
                    else
                    {
                      return -6;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FB9F0
// ============================================================
//----- (101FB9F0) --------------------------------------------------------
int __thiscall sub_101FB9F0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 5) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_22:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 5) & 1) == 0 )
            *(this + 5) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 5) & 2) == 0 )
            *(this + 5) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 5) & 4) == 0 )
            *(this + 5) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 5) & 8) == 0 )
            *(this + 5) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 5) & 0x10) == 0 )
            *(this + 5) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_22;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FBB20
// ============================================================
//----- (101FBB20) --------------------------------------------------------
int __thiscall sub_101FBB20(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 20) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_22:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 20) & 1) == 0 )
            *(_DWORD *)(this + 20) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 20) & 2) == 0 )
            *(_DWORD *)(this + 20) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 20) & 4) == 0 )
            *(_DWORD *)(this + 20) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 20) & 8) == 0 )
            *(_DWORD *)(this + 20) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 20) & 0x10) == 0 )
            *(_DWORD *)(this + 20) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_22;
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
// Address Name: SUB_1024A230
// ============================================================
//----- (1024A230) --------------------------------------------------------
int __fastcall sub_1024A230(_DWORD *a1, int a2, char a3, const char *ArgList, int a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
  result = sub_1024A140(a2);
  if ( !result )
    return Printf(a1, "%s[%u]%c", ArgList, a5, a3);
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FBD20
// ============================================================
//----- (101FBD20) --------------------------------------------------------
int __thiscall sub_101FBD20(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[effectType]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[param1]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[param2]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[param3]", "%d", *(this + 3));
        if ( !result )
          return print_field(a2, a3, a4, "[param4]", "%d", *(this + 4));
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



