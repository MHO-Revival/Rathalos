// ============================================================
// Name: TLV::UnkTlv0089::Read_0xAA
// Address Name: SUB_10157930
// ============================================================
//----- (10157930) --------------------------------------------------------
int __thiscall sub_10157930(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = (_DWORD *)a2;
  v16 = this;
  *(_DWORD *)(this + 417) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 417) & 1) == 0 )
          *(_DWORD *)(v4 + 417) |= 1u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)v4, v6, a2);
        goto LABEL_36;
      case 2u:
        if ( (*(_DWORD *)(v4 + 417) & 2) == 0 )
          *(_DWORD *)(v4 + 417) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)(v4 + 32), v6, a2);
        goto LABEL_36;
      case 3u:
        if ( (*(_DWORD *)(v4 + 417) & 4) == 0 )
          *(_DWORD *)(v4 + 417) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)(v4 + 64), v6, a2);
LABEL_36:
        v5 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_37;
        return v5;
      case 4u:
        if ( (*(_DWORD *)(v4 + 417) & 8) == 0 )
          *(_DWORD *)(v4 + 417) |= 8u;
        Byte_2 = TdrBuf::ReadByte_2(v6, (_BYTE *)(v4 + 96));
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v4 + 417) & 0x10) == 0 )
          *(_DWORD *)(v4 + 417) |= 0x10u;
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
            v5 = sub_10156CC0((_DWORD *)(32 * v10 + v16 + 97), v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > v14 + a2 )
            return -34;
          if ( v11 == v14 + a2 )
            break;
          if ( ++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_37;
          }
        }
        v12 = v16;
        *(_BYTE *)(v16 + 96) = v10 + 1;
        v4 = v12;
LABEL_37:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Byte_2 = TdrBuf::SkipField(v6, v15 & 0xF);
        goto LABEL_36;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0089::Read_0x99
// Address Name: SUB_10157BB0
// ============================================================
//----- (10157BB0) --------------------------------------------------------
int __thiscall sub_10157BB0(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = (_DWORD *)a2;
  v16 = this;
  *(_DWORD *)(this + 417) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 417) & 1) == 0 )
          *(_DWORD *)(v4 + 417) |= 1u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4, v6, a2);
        goto LABEL_36;
      case 2u:
        if ( (*(_DWORD *)(v4 + 417) & 2) == 0 )
          *(_DWORD *)(v4 + 417) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4 + 32, v6, a2);
        goto LABEL_36;
      case 3u:
        if ( (*(_DWORD *)(v4 + 417) & 4) == 0 )
          *(_DWORD *)(v4 + 417) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4 + 64, v6, a2);
LABEL_36:
        v5 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_37;
        return v5;
      case 4u:
        if ( (*(_DWORD *)(v4 + 417) & 8) == 0 )
          *(_DWORD *)(v4 + 417) |= 8u;
        Byte_2 = TdrBuf::ReadByte_2(v6, (_BYTE *)(v4 + 96));
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v4 + 417) & 0x10) == 0 )
          *(_DWORD *)(v4 + 417) |= 0x10u;
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
            v5 = sub_10156E40(32 * v10 + v16 + 97, v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > v14 + a2 )
            return -34;
          if ( v11 == v14 + a2 )
            break;
          if ( ++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_37;
          }
        }
        v12 = v16;
        *(_BYTE *)(v16 + 96) = v10 + 1;
        v4 = v12;
LABEL_37:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Byte_2 = TdrBuf::SkipField(v6, v15 & 0xF);
        goto LABEL_36;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0089::DoDebugFormat
// Address Name: SUB_10157E50
// ============================================================
//----- (10157E50) --------------------------------------------------------
int __thiscall sub_10157E50(void *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10157F00((int)this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0089::DebugFormat
// Address Name: SUB_10157F00
// ============================================================
//----- (10157F00) --------------------------------------------------------
int __thiscall sub_10157F00(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v7; // ecx
  _DWORD *v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 v10; // cl
  int v11; // ebx
  _DWORD *v12; // ecx
  unsigned __int8 v14; // [esp+1Fh] [ebp+Fh]

  if ( !"[daily]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[daily]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_10157090((_DWORD *)this, a2, a3 + 1, a4) : sub_10157090((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[weekly]");
        if ( !result )
        {
          v7 = (_DWORD *)(this + 32);
          result = a3 >= 0 ? sub_10157090(v7, a2, a3 + 1, a4) : sub_10157090(v7, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[monthly]");
            if ( !result )
            {
              v8 = (_DWORD *)(this + 64);
              result = a3 >= 0 ? sub_10157090(v8, a2, a3 + 1, a4) : sub_10157090(v8, a2, a3, a4);
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[count]", "0x%02x", *(unsigned __int8 *)(this + 96));
                if ( !result )
                {
                  v9 = *(_BYTE *)(this + 96);
                  if ( v9 <= 0xAu )
                  {
                    v10 = 0;
                    v14 = 0;
                    if ( v9 )
                    {
                      while ( 1 )
                      {
                        v11 = v10;
                        result = sub_1024A230(a2, a3, a4, "[selfDefs]", v10);
                        if ( result )
                          break;
                        v12 = (_DWORD *)(32 * v11 + this + 97);
                        result = a3 >= 0 ? sub_10157090(v12, a2, a3 + 1, a4) : sub_10157090(v12, a2, a3, a4);
                        if ( result )
                          break;
                        v10 = v14 + 1;
                        v14 = v10;
                        if ( v10 >= *(_BYTE *)(this + 96) )
                          return 0;
                      }
                    }
                    else
                    {
                      return 0;
                    }
                  }
                  else
                  {
                    return -7;
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
// Address Name: SUB_10156CC0
// ============================================================
//----- (10156CC0) --------------------------------------------------------
int __thiscall sub_10156CC0(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 7) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 7) & 1) == 0 )
            *(this + 7) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 7) & 2) == 0 )
            *(this + 7) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 7) & 4) == 0 )
            *(this + 7) |= 4u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 7) & 8) == 0 )
            *(this + 7) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 7) & 0x10) == 0 )
            *(this + 7) |= 0x10u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 7) & 0x20) == 0 )
            *(this + 7) |= 0x20u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 7) & 0x40) == 0 )
            *(this + 7) |= 0x40u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 6);
          break;
        default:
          VarUInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarUInt;
      if ( VarUInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10156E40
// ============================================================
//----- (10156E40) --------------------------------------------------------
int __thiscall sub_10156E40(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 28) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 28) & 1) == 0 )
            *(_DWORD *)(this + 28) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 28) & 2) == 0 )
            *(_DWORD *)(this + 28) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 28) & 4) == 0 )
            *(_DWORD *)(this + 28) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 28) & 8) == 0 )
            *(_DWORD *)(this + 28) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 28) & 0x10) == 0 )
            *(_DWORD *)(this + 28) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 28) & 0x20) == 0 )
            *(_DWORD *)(this + 28) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 28) & 0x40) == 0 )
            *(_DWORD *)(this + 28) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
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
        goto LABEL_28;
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
// Address Name: SUB_10157090
// ============================================================
//----- (10157090) --------------------------------------------------------
int __thiscall sub_10157090(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[onlineTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lastUpdateTime]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[activityID]", "%u", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[hour]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[min]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[second]", "%d", *(this + 5));
            if ( !result )
              return print_field(a2, a3, a4, "[offset]", "%d", *(this + 6));
          }
        }
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



