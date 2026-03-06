// ============================================================
// Name: TLV::UnkTlv0155::Read
// Address Name: SUB_10189D00
// ============================================================
//----- (10189D00) --------------------------------------------------------
int __thiscall sub_10189D00(char *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10189DD0(this, &v9, v8);
  else
    result = sub_10189FA0(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0155::Read_0xAA
// Address Name: SUB_10189DD0
// ============================================================
//----- (10189DD0) --------------------------------------------------------
int __thiscall sub_10189DD0(char *this, _DWORD *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+14h] [ebp-14h] BYREF
  unsigned int v12; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp-8h]
  unsigned int v15; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v12 = 0;
  *(_DWORD *)(this + 36521) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_27:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v12);
      if ( result )
        break;
      if ( v12 >> 4 == 1 )
      {
        if ( (v3[36521] & 1) == 0 )
          *(_DWORD *)(v3 + 36521) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v4 = 0;
      }
      else
      {
        if ( v12 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 36521) & 2) == 0 )
            *(_DWORD *)(v3 + 36521) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v14 = a2[1];
          while ( 1 )
          {
            v13 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v13);
            if ( v4 )
              return v4;
            if ( v13 )
            {
              v4 = sub_101891C0((int)(this + 913 * v7 + 1), a2, v13);
              if ( v4 )
                return v4;
            }
            v8 = a2[1];
            if ( v8 > v14 + v11 )
              return -34;
            if ( v8 == v14 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            if ( ++v7 >= 0x28u )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v12 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v15;
      if ( a2[1] >= v15 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0155::Read_0x99
// Address Name: SUB_10189FA0
// ============================================================
//----- (10189FA0) --------------------------------------------------------
int __thiscall sub_10189FA0(char *this, _DWORD *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+14h] [ebp-14h] BYREF
  unsigned int v12; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp-8h]
  unsigned int v15; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v12 = 0;
  *(_DWORD *)(this + 36521) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_27:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v12);
      if ( result )
        break;
      if ( v12 >> 4 == 1 )
      {
        if ( (v3[36521] & 1) == 0 )
          *(_DWORD *)(v3 + 36521) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v4 = 0;
      }
      else
      {
        if ( v12 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 36521) & 2) == 0 )
            *(_DWORD *)(v3 + 36521) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v14 = a2[1];
          while ( 1 )
          {
            v13 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v13);
            if ( v4 )
              return v4;
            if ( v13 )
            {
              v4 = sub_10189400((int)(this + 913 * v7 + 1), a2, v13);
              if ( v4 )
                return v4;
            }
            v8 = a2[1];
            if ( v8 > v14 + v11 )
              return -34;
            if ( v8 == v14 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            if ( ++v7 >= 0x28u )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v12 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v15;
      if ( a2[1] >= v15 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0155::DoDebugFormat
// Address Name: SUB_1018A190
// ============================================================
//----- (1018A190) --------------------------------------------------------
int __thiscall sub_1018A190(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1018A240(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0155::DebugFormat
// Address Name: SUB_1018A240
// ============================================================
//----- (1018A240) --------------------------------------------------------
int __thiscall sub_1018A240(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // bl
  unsigned __int8 *v7; // ecx

  result = print_field(a2, a3, a4, "[groupCnt]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this <= 0x28u )
    {
      v6 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          if ( !"[suitSkillGroupData]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[suitSkillGroupData]", v6, a4);
          if ( result )
            break;
          v7 = this + 913 * v6 + 1;
          result = a3 >= 0 ? sub_10189710(v7, a2, a3 + 1, a4) : sub_10189710(v7, a2, a3, a4);
          if ( result )
            break;
          if ( ++v6 >= *this )
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101891C0
// ============================================================
//----- (101891C0) --------------------------------------------------------
int __thiscall sub_101891C0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 909) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 909) & 1) == 0 )
          *(_DWORD *)(v5 + 909) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v5 + 909) & 2) == 0 )
          *(_DWORD *)(v5 + 909) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_35;
      case 3u:
        if ( (*(_DWORD *)(v5 + 909) & 4) == 0 )
          *(_DWORD *)(v5 + 909) |= 4u;
        VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_35;
      case 4u:
        if ( (*(_DWORD *)(v5 + 909) & 8) == 0 )
          *(_DWORD *)(v5 + 909) |= 8u;
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
          Byte = TdrBuf::ReadVarInt(v4, (int *)(v16 + 4 * v10 + 9));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v5 + 909) & 0x10) == 0 )
          *(_DWORD *)(v5 + 909) |= 0x10u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 729 + v10));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v16;
            *(_BYTE *)(v16 + 8) = v10 + 1;
            v5 = v12;
            goto LABEL_36;
          }
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
LABEL_36:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_37:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        VarInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_35:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_36;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10189400
// ============================================================
//----- (10189400) --------------------------------------------------------
int __thiscall sub_10189400(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 909) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 909) & 1) == 0 )
          *(_DWORD *)(v5 + 909) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v5 + 909) & 2) == 0 )
          *(_DWORD *)(v5 + 909) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_35;
      case 3u:
        if ( (*(_DWORD *)(v5 + 909) & 4) == 0 )
          *(_DWORD *)(v5 + 909) |= 4u;
        Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_35;
      case 4u:
        if ( (*(_DWORD *)(v5 + 909) & 8) == 0 )
          *(_DWORD *)(v5 + 909) |= 8u;
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
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 9));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v5 + 909) & 0x10) == 0 )
          *(_DWORD *)(v5 + 909) |= 0x10u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 729 + v10));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v16;
            *(_BYTE *)(v16 + 8) = v10 + 1;
            v5 = v12;
            goto LABEL_36;
          }
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
LABEL_36:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_37:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_35:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_36;
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
// Address Name: SUB_10189710
// ============================================================
//----- (10189710) --------------------------------------------------------
int __thiscall sub_10189710(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  result = print_field(a2, a3, a4, "[skillGroup]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[leftEditCnt]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[skillCnt]", "0x%02x", *((unsigned __int8 *)this + 8));
      if ( !result )
      {
        v7 = *((_BYTE *)this + 8);
        if ( v7 > 0xB4u )
          return -7;
        result = sub_1024A3B0(a2, a3, v6, "[skillID]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *((_BYTE *)this + 8) )
          {
            while ( 1 )
            {
              result = Printf(a2, " %d", *(_DWORD *)((char *)this + 4 * v8 + 9));
              if ( result )
                break;
              if ( ++v8 >= *((_BYTE *)this + 8) )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              v10 = *((_BYTE *)this + 8);
              if ( v10 > 0xB4u )
                return -7;
              result = sub_1024A3B0(a2, a3, v9, "[actFlag]", v10);
              if ( !result )
              {
                v11 = 0;
                if ( *((_BYTE *)this + 8) )
                {
                  while ( 1 )
                  {
                    result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v11 + 729));
                    if ( result )
                      break;
                    if ( ++v11 >= *((_BYTE *)this + 8) )
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
  return result;
}
// 101897AA: variable 'v6' is possibly undefined
// 10189807: variable 'v9' is possibly undefined



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



