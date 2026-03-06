// ============================================================
// Name: TLV::UnkTlv0291::Read_0xAA
// Address Name: SUB_10246390
// ============================================================
//----- (10246390) --------------------------------------------------------
int __thiscall sub_10246390(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  _DWORD *v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 17665) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[17665] & 1) == 0 )
          v4[17665] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[17665] & 2) == 0 )
            v4[17665] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10245770(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 276;
            if ( ++v10 >= 64 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0291::Read_0x99
// Address Name: SUB_10246500
// ============================================================
//----- (10246500) --------------------------------------------------------
int __thiscall sub_10246500(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  _DWORD *v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 17665) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[17665] & 1) == 0 )
          v4[17665] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[17665] & 2) == 0 )
            v4[17665] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_102459A0(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 276;
            if ( ++v10 >= 64 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0291::DoDebugFormat
// Address Name: SUB_10246690
// ============================================================
//----- (10246690) --------------------------------------------------------
int __thiscall sub_10246690(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10246740(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0291::DebugFormat
// Address Name: SUB_10246740
// ============================================================
//----- (10246740) --------------------------------------------------------
int __thiscall sub_10246740(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 64 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 276 )
          {
            if ( !"[data]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[data]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10245CA0(i, a2, a3 + 1, a4) : sub_10245CA0(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10245770
// ============================================================
//----- (10245770) --------------------------------------------------------
int __thiscall sub_10245770(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int VarInt; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  VarInt = 0;
  v6 = a2;
  v19 = this;
  *(this + 275) = 0;
  v18 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_20;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (v4[275] & 1) == 0 )
          v4[275] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[275] & 2) == 0 )
          v4[275] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = v19 + 1;
        a3 = v19 + 1;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v11);
          if ( VarInt )
            return VarInt;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + v17) )
          {
            ++v10;
            v11 = ++a3;
            if ( v10 < 0x10 )
              continue;
          }
          goto LABEL_18;
        }
      case 3u:
        if ( (v4[275] & 4) == 0 )
          v4[275] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 17);
        if ( VarInt )
          return VarInt;
        goto LABEL_19;
      case 4u:
        if ( (v4[275] & 8) == 0 )
          v4[275] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadByte(v6, (_BYTE *)v19 + v13 + 72);
          if ( VarInt )
            return VarInt;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          if ( ++v13 >= 1024 )
          {
LABEL_18:
            v4 = v19;
            goto LABEL_19;
          }
        }
        v15 = v13 + 1;
        v4 = v19;
        v19[17] = v15;
LABEL_19:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_20:
        if ( v6[1] > v7 )
          return -34;
        return VarInt;
      case 5u:
        if ( (v4[275] & 0x10) == 0 )
          v4[275] |= 0x10u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4 + 274);
        goto LABEL_7;
      default:
        VarUInt = TdrBuf::SkipField(v6, v18 & 0xF);
LABEL_7:
        VarInt = VarUInt;
        if ( !VarUInt )
          goto LABEL_19;
        return VarInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102459A0
// ============================================================
//----- (102459A0) --------------------------------------------------------
int __thiscall sub_102459A0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v19 = this;
  *(this + 275) = 0;
  v18 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_20;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (v4[275] & 1) == 0 )
          v4[275] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[275] & 2) == 0 )
          v4[275] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = v19 + 1;
        a3 = v19 + 1;
        while ( 1 )
        {
          Byte = TdrBuf::ReadInt32(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + v17) )
          {
            ++v10;
            v11 = ++a3;
            if ( v10 < 0x10 )
              continue;
          }
          goto LABEL_18;
        }
      case 3u:
        if ( (v4[275] & 4) == 0 )
          v4[275] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 68);
        goto LABEL_7;
      case 4u:
        if ( (v4[275] & 8) == 0 )
          v4[275] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = (_DWORD *)v6[1];
        while ( 1 )
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v19 + v13 + 72);
          if ( Byte )
            return Byte;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          if ( ++v13 >= 1024 )
          {
LABEL_18:
            v4 = v19;
            goto LABEL_19;
          }
        }
        v15 = v13 + 1;
        v4 = v19;
        v19[17] = v15;
LABEL_19:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_20:
        if ( v6[1] > v7 )
          return -34;
        return Byte;
      case 5u:
        if ( (v4[275] & 0x10) == 0 )
          v4[275] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 1096);
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v6, v18 & 0xF);
LABEL_7:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_19;
        return Byte;
    }
  }
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
// Address Name: SUB_10245CA0
// ============================================================
//----- (10245CA0) --------------------------------------------------------
int __thiscall sub_10245CA0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned int v6; // edi
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // edi

  result = print_field(a2, a3, a4, "[iD]", "%u", *this);
  if ( !result )
  {
    if ( !"[vars]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s[0 : %I64i]:", "[vars]", 15LL);
      if ( !result )
      {
        v6 = 0;
        v7 = this + 1;
        while ( 1 )
        {
          result = Printf(a2, " %d", *v7);
          if ( result )
            break;
          ++v6;
          ++v7;
          if ( v6 >= 0x10 )
          {
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0xC4u);
            v8 = a2[1];
            if ( (unsigned int)(a2[2] - v8) < 2 )
              return -1;
            *(_BYTE *)(v8 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            result = print_field(a2, a3, a4, "[length]", "%d", *(this + 17));
            if ( !result )
            {
              v10 = *(this + 17);
              if ( v10 >= 0 )
              {
                if ( v10 <= 1024 )
                {
                  result = sub_1024A3B0(a2, a3, v9, "[data]", v10);
                  if ( !result )
                  {
                    v11 = 0;
                    if ( (int)*(this + 17) <= 0 )
                    {
LABEL_21:
                      result = TdrBuf::WriteChar(a2, a4);
                      if ( !result )
                        return print_field(a2, a3, a4, "[lastUpdate]", "%u", *(this + 274));
                    }
                    else
                    {
                      while ( 1 )
                      {
                        result = Printf(a2, " %d", *((unsigned __int8 *)this + v11 + 72));
                        if ( result )
                          break;
                        if ( ++v11 >= *(this + 17) )
                          goto LABEL_21;
                      }
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
            return result;
          }
        }
      }
    }
  }
  return result;
}
// 10245DF3: variable 'v9' is possibly undefined



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



