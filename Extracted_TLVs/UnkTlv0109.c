// ============================================================
// Name: TLV::UnkTlv0109::Read_0xAA
// Address Name: SUB_101691E0
// ============================================================
//----- (101691E0) --------------------------------------------------------
int __thiscall sub_101691E0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0109::Read_0x99
// Address Name: SUB_10169610
// ============================================================
//----- (10169610) --------------------------------------------------------
int __thiscall sub_10169610(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0109::DoDebugFormat
// Address Name: SUB_10169A60
// ============================================================
//----- (10169A60) --------------------------------------------------------
int __thiscall sub_10169A60(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10169B10(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0109::DebugFormat
// Address Name: SUB_10169B10
// ============================================================
//----- (10169B10) --------------------------------------------------------
int __thiscall sub_10169B10(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nBUTTON_UP]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[nBUTTON_LEFT]", "0x%02x", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[nBUTTON_DOWN]", "0x%02x", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[nBUTTON_RIGHT]", "0x%02x", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[nSTICK_LEFT_LEFT]", "0x%02x", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[nSTICK_LEFT_RIGHT]", "0x%02x", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[nSTICK_LEFT_UP]", "0x%02x", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[nSTICK_LEFT_DOWN]", "0x%02x", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[nSTICK_RIGHT_LEFT]", "0x%02x", *(this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[nSTICK_RIGHT_RIGHT]", "0x%02x", *(this + 9));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[nSTICK_RIGHT_UP]", "0x%02x", *(this + 10));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[nSTICK_RIGHT_DOWN]", "0x%02x", *(this + 11));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[nBUTTON_L2]", "0x%02x", *(this + 12));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[nBUTTON_R2]", "0x%02x", *(this + 13));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[nBUTTON_L1]", "0x%02x", *(this + 14));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[nBUTTON_R1]", "0x%02x", *(this + 15));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[nBUTTON_TRIANGLE]", "0x%02x", *(this + 16));
                                  if ( !result )
                                  {
                                    result = print_field(a2, a3, a4, "[nBUTTON_CIRCLE]", "0x%02x", *(this + 17));
                                    if ( !result )
                                    {
                                      result = print_field(a2, a3, a4, "[nBUTTON_CROSS]", "0x%02x", *(this + 18));
                                      if ( !result )
                                      {
                                        result = print_field(a2, a3, a4, "[nBUTTON_SQUARE]", "0x%02x", *(this + 19));
                                        if ( !result )
                                        {
                                          result = print_field(a2, a3, a4, "[nBUTTON_SELECT]", "0x%02x", *(this + 20));
                                          if ( !result )
                                          {
                                            result = print_field(a2, a3, a4, "[nBUTTON_START]", "0x%02x", *(this + 21));
                                            if ( !result )
                                            {
                                              result = print_field(a2, a3, a4, "[nBUTTON_L3]", "0x%02x", *(this + 22));
                                              if ( !result )
                                                return print_field(a2, a3, a4, "[nBUTTON_R3]", "0x%02x", *(this + 23));
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



