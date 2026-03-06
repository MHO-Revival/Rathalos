// ============================================================
// Name: TLV::UnkTlv0076::Read_0xAA
// Address Name: SUB_1014BA90
// ============================================================
//----- (1014BA90) --------------------------------------------------------
int __thiscall sub_1014BA90(unsigned int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  unsigned int *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // eax
  _DWORD *v19; // edx
  char *v20; // eax
  char *v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  char *v24; // [esp+Ch] [ebp-18h]
  int v25; // [esp+10h] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-10h] BYREF
  int v27; // [esp+18h] [ebp-Ch]
  unsigned int v28; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int *v29; // [esp+20h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v29 = this;
  *(this + 1793) = 0;
  v28 = 0;
  v7 = (char *)v3 + v6[1];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_61;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (v4[1793] & 1) == 0 )
          v4[1793] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
        goto LABEL_59;
      case 3u:
        if ( (v4[1793] & 2) == 0 )
          v4[1793] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        do
        {
          Byte = TdrBuf::ReadVarUInt(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v27) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 4u:
        if ( (v4[1793] & 4) == 0 )
          v4[1793] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 513;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v26);
          v15 = a3;
          Byte = v14;
          if ( v14 )
            return Byte;
          v16 = (char *)a2 + v27;
          *a3 = v26;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
            goto LABEL_17;
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 5u:
        if ( (v4[1793] & 8) == 0 )
          v4[1793] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 1025;
        do
        {
          v18 = TdrBuf::ReadInt32(v6, &v25);
          v19 = a3;
          Byte = v18;
          if ( v18 )
            return Byte;
          v20 = (char *)a2 + v27;
          *a3 = v25;
          v21 = (char *)v6[1];
          if ( v21 > v20 )
            return -34;
          if ( v21 == v20 )
            goto LABEL_17;
          ++v10;
          a3 = v19 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 6u:
        if ( (v4[1793] & 0x10) == 0 )
          v4[1793] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6148);
          if ( Byte )
            return Byte;
          v22 = v6[1];
          if ( (_DWORD *)v22 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 7u:
        if ( (v4[1793] & 0x20) == 0 )
          v4[1793] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6660);
          if ( Byte )
            return Byte;
          v23 = v6[1];
          if ( (_DWORD *)v23 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_17:
            v13 = v10 + 1;
            v4 = v29;
            *v29 = v13;
            goto LABEL_60;
          }
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
LABEL_60:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_61:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Byte;
      default:
        VarUInt = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_59:
        Byte = VarUInt;
        if ( !VarUInt )
          goto LABEL_60;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0076::Read_0x99
// Address Name: SUB_1014BE50
// ============================================================
//----- (1014BE50) --------------------------------------------------------
int __thiscall sub_1014BE50(unsigned int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  unsigned int *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // eax
  _DWORD *v19; // edx
  char *v20; // eax
  char *v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  char *v24; // [esp+Ch] [ebp-18h]
  int v25; // [esp+10h] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-10h] BYREF
  int v27; // [esp+18h] [ebp-Ch]
  unsigned int v28; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int *v29; // [esp+20h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v29 = this;
  *(this + 1793) = 0;
  v28 = 0;
  v7 = (char *)v3 + v6[1];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_61;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (v4[1793] & 1) == 0 )
          v4[1793] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_59;
      case 3u:
        if ( (v4[1793] & 2) == 0 )
          v4[1793] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        do
        {
          Byte = TdrBuf::ReadInt32(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v27) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 4u:
        if ( (v4[1793] & 4) == 0 )
          v4[1793] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 513;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v26);
          v15 = a3;
          Byte = v14;
          if ( v14 )
            return Byte;
          v16 = (char *)a2 + v27;
          *a3 = v26;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
            goto LABEL_17;
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 5u:
        if ( (v4[1793] & 8) == 0 )
          v4[1793] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 1025;
        do
        {
          v18 = TdrBuf::ReadInt32(v6, &v25);
          v19 = a3;
          Byte = v18;
          if ( v18 )
            return Byte;
          v20 = (char *)a2 + v27;
          *a3 = v25;
          v21 = (char *)v6[1];
          if ( v21 > v20 )
            return -34;
          if ( v21 == v20 )
            goto LABEL_17;
          ++v10;
          a3 = v19 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 6u:
        if ( (v4[1793] & 0x10) == 0 )
          v4[1793] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6148);
          if ( Byte )
            return Byte;
          v22 = v6[1];
          if ( (_DWORD *)v22 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 7u:
        if ( (v4[1793] & 0x20) == 0 )
          v4[1793] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6660);
          if ( Byte )
            return Byte;
          v23 = v6[1];
          if ( (_DWORD *)v23 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_17:
            v13 = v10 + 1;
            v4 = v29;
            *v29 = v13;
            goto LABEL_60;
          }
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
LABEL_60:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_61:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_59:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_60;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0076::DoDebugFormat
// Address Name: SUB_1014C230
// ============================================================
//----- (1014C230) --------------------------------------------------------
int __thiscall sub_1014C230(unsigned int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1014C2E0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0076::DebugFormat
// Address Name: SUB_1014C2E0
// ============================================================
//----- (1014C2E0) --------------------------------------------------------
int __thiscall sub_1014C2E0(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  unsigned int v8; // ebx
  _DWORD *v9; // eax
  int v10; // ecx
  unsigned int v11; // ebx
  float *v12; // eax
  int v13; // ecx
  unsigned int v14; // ebx
  float *v15; // eax
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  int v20; // [esp+1Ch] [ebp+8h]
  int v21; // [esp+1Ch] [ebp+8h]
  int v22; // [esp+1Ch] [ebp+8h]

  result = print_field(a2, a3, a4, "[monsterCnt]", "%u", *this);
  if ( !result )
  {
    if ( *this > 0x200 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[monsterId]", *this);
    if ( !result )
    {
      v8 = 0;
      if ( *this )
      {
        v9 = this + 1;
        v20 = (int)(this + 1);
        while ( 1 )
        {
          result = Printf(a2, " %u", *v9);
          if ( result )
            break;
          ++v8;
          v9 = (_DWORD *)(v20 + 4);
          v20 += 4;
          if ( v8 >= *this )
            goto LABEL_9;
        }
      }
      else
      {
LABEL_9:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          if ( *this > 0x200 )
            return -7;
          result = sub_1024A3B0(a2, a3, v10, "[maxSize]", *this);
          if ( !result )
          {
            v11 = 0;
            if ( *this )
            {
              v12 = (float *)(this + 513);
              v21 = (int)(this + 513);
              while ( 1 )
              {
                result = Printf(a2, " %f", *v12);
                if ( result )
                  break;
                ++v11;
                v12 = (float *)(v21 + 4);
                v21 += 4;
                if ( v11 >= *this )
                  goto LABEL_16;
              }
            }
            else
            {
LABEL_16:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                if ( *this > 0x200 )
                  return -7;
                result = sub_1024A3B0(a2, a3, v13, "[minSize]", *this);
                if ( !result )
                {
                  v14 = 0;
                  if ( *this )
                  {
                    v15 = (float *)(this + 1025);
                    v22 = (int)(this + 1025);
                    while ( 1 )
                    {
                      result = Printf(a2, " %f", *v15);
                      if ( result )
                        break;
                      ++v14;
                      v15 = (float *)(v22 + 4);
                      v22 += 4;
                      if ( v14 >= *this )
                        goto LABEL_23;
                    }
                  }
                  else
                  {
LABEL_23:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( !result )
                    {
                      if ( *this > 0x200 )
                        return -7;
                      result = sub_1024A3B0(a2, a3, v16, "[maxFlag]", *this);
                      if ( !result )
                      {
                        v17 = 0;
                        if ( *this )
                        {
                          while ( 1 )
                          {
                            result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v17 + 6148));
                            if ( result )
                              break;
                            if ( ++v17 >= *this )
                              goto LABEL_29;
                          }
                        }
                        else
                        {
LABEL_29:
                          result = TdrBuf::WriteChar(a2, a4);
                          if ( !result )
                          {
                            if ( *this > 0x200 )
                              return -7;
                            result = sub_1024A3B0(a2, a3, v18, "[minFlag]", *this);
                            if ( !result )
                            {
                              v19 = 0;
                              if ( *this )
                              {
                                while ( 1 )
                                {
                                  result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v19 + 6660));
                                  if ( result )
                                    break;
                                  if ( ++v19 >= *this )
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
            }
          }
        }
      }
    }
  }
  return result;
}
// 1014C331: variable 'v7' is possibly undefined
// 1014C39F: variable 'v10' is possibly undefined
// 1014C420: variable 'v13' is possibly undefined
// 1014C4A0: variable 'v16' is possibly undefined
// 1014C509: variable 'v18' is possibly undefined



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



