// ============================================================
// Name: TLV::UnkTlv0236::Read_0xAA
// Address Name: SUB_102175D0
// ============================================================
//----- (102175D0) --------------------------------------------------------
int __thiscall sub_102175D0(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned __int8 v8; // bl
  unsigned int v9; // edx
  unsigned __int8 v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v15 = 0;
  v6 = a3;
  *(_DWORD *)(this + 412) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 412) & 1) == 0 )
          *(_DWORD *)(this + 412) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_37;
      case 3u:
        if ( (*(_DWORD *)(this + 412) & 2) == 0 )
          *(_DWORD *)(this + 412) |= 2u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 1));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 412) & 4) == 0 )
          *(_DWORD *)(this + 412) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_102162D0((char *)(23 * v8 + this + 2), v3, a3);
            if ( result )
              return result;
          }
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xAu )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_BYTE *)(this + 1) = v8 + 1;
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(this + 412) & 8) == 0 )
          *(_DWORD *)(this + 412) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216BA0((char *)(this + 232 + 8 * v10 + v10), v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0x14u )
            goto LABEL_38;
        }
        *(_BYTE *)this = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_39:
        if ( v3[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0236::Read_0x99
// Address Name: SUB_10217820
// ============================================================
//----- (10217820) --------------------------------------------------------
int __thiscall sub_10217820(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  char v8; // bl
  unsigned int v9; // edx
  char v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v15 = 0;
  v6 = a3;
  *(_DWORD *)(this + 412) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(&v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 412) & 1) == 0 )
          *(_DWORD *)(this + 412) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_37;
      case 3u:
        if ( (*(_DWORD *)(this + 412) & 2) == 0 )
          *(_DWORD *)(this + 412) |= 2u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 1));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 412) & 4) == 0 )
          *(_DWORD *)(this + 412) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216470(v3, a3);
            if ( result )
              return result;
          }
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( (unsigned __int8)++v8 >= 0xAu )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_BYTE *)(this + 1) = v8 + 1;
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(this + 412) & 8) == 0 )
          *(_DWORD *)(this + 412) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216C90(v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( (unsigned __int8)++v10 >= 0x14u )
            goto LABEL_38;
        }
        *(_BYTE *)this = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_39:
        if ( v3[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}
// 1010CCB0: using guessed type _DWORD __stdcall sub_1010CCB0(_DWORD);
// 1010D4F0: using guessed type int __fastcall sub_1010D4F0(_DWORD, _DWORD);
// 10216470: using guessed type _DWORD __stdcall sub_10216470(_DWORD, _DWORD);
// 10216C90: using guessed type _DWORD __stdcall sub_10216C90(_DWORD, _DWORD);



// ============================================================
// Name: TLV::UnkTlv0236::DoDebugFormat
// Address Name: SUB_10217A90
// ============================================================
//----- (10217A90) --------------------------------------------------------
int __thiscall sub_10217A90(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10217B40(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0236::DebugFormat
// Address Name: SUB_10217B40
// ============================================================
//----- (10217B40) --------------------------------------------------------
int __thiscall sub_10217B40(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  bool v9; // zf
  void (__cdecl *v10)(const wchar_t *, const wchar_t *, unsigned int); // edx
  unsigned __int8 v11; // al
  unsigned __int8 v12; // cl
  int v13; // [esp-4h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp+Ch]
  int v16; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *v17; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 v18; // [esp+23h] [ebp+13h]
  unsigned __int8 v19; // [esp+23h] [ebp+13h]

  result = print_field(a2, a3, a4, "[starNum]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[branchNum]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v6 = this;
      v7 = *(this + 1);
      if ( v7 > 0xAu )
        return -7;
      v8 = 0;
      v9 = v7 == 0;
      v10 = _wassert;
      v18 = 0;
      if ( v9 )
      {
LABEL_15:
        v11 = *v6;
        if ( v11 > 0x14u )
          return -7;
        v12 = 0;
        v19 = 0;
        if ( v11 )
        {
          while ( 1 )
          {
            v16 = v12;
            if ( !"[starList]" )
              v10(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[starList]", v16, a4);
            if ( result )
              break;
            v17 = this + 8 * v16 + v16 + 232;
            v13 = *v17;
            if ( a3 >= 0 )
            {
              result = print_field(a2, a3 + 1, a4, "[quality]", "0x%02x", v13);
              if ( result )
                return result;
              result = print_field(a2, a3 + 1, a4, "[finishTime]", "%u", *(_DWORD *)(v17 + 1));
            }
            else
            {
              result = print_field(a2, a3, a4, "[quality]", "0x%02x", v13);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[finishTime]", "%u", *(_DWORD *)(v17 + 1));
            }
            if ( result )
              break;
            v12 = v19 + 1;
            v19 = v12;
            if ( v12 >= *this )
              return 0;
            v10 = _wassert;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        while ( 1 )
        {
          v15 = v8;
          if ( !"[branchList]" )
            v10(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[branchList]", v15, a4);
          if ( result )
            break;
          result = a3 >= 0
                 ? sub_102166E0(this + 23 * v15 + 2, a2, a3 + 1, a4)
                 : sub_102166E0(this + 23 * v15 + 2, a2, a3, a4);
          if ( result )
            break;
          v6 = this;
          v8 = v18 + 1;
          v10 = _wassert;
          v18 = v8;
          if ( v8 >= *(this + 1) )
            goto LABEL_15;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102162D0
// ============================================================
//----- (102162D0) --------------------------------------------------------
int __thiscall sub_102162D0(char *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int v8; // ecx
  int VarUShort; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 19) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(this + 19) & 1) == 0 )
              *(_DWORD *)(this + 19) |= 1u;
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0x290u);
            v8 = a2[1];
            if ( a2[2] != v8 )
            {
              *this = *(_BYTE *)(v8 + *a2);
              ++a2[1];
              v5 = 0;
              goto LABEL_27;
            }
            return -2;
          case 2u:
            if ( (*(_DWORD *)(this + 19) & 2) == 0 )
              *(_DWORD *)(this + 19) |= 2u;
            VarUShort = TdrBuf::ReadVarUShort(a2, this + 1);
            goto LABEL_26;
          case 3u:
            if ( (*(_DWORD *)(this + 19) & 4) == 0 )
              *(_DWORD *)(this + 19) |= 4u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 3);
            goto LABEL_26;
          case 4u:
            if ( (*(_DWORD *)(this + 19) & 8) == 0 )
              *(_DWORD *)(this + 19) |= 8u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 7);
            goto LABEL_26;
          case 5u:
            if ( (*(_DWORD *)(this + 19) & 0x10) == 0 )
              *(_DWORD *)(this + 19) |= 0x10u;
            VarUShort = TdrBuf::ReadVarInt(a2, (int *)(this + 11));
            goto LABEL_26;
          case 6u:
            if ( (*(_DWORD *)(this + 19) & 0x20) == 0 )
              *(_DWORD *)(this + 19) |= 0x20u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 15);
            goto LABEL_26;
          default:
            VarUShort = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_26:
            v5 = VarUShort;
            if ( VarUShort )
              return v5;
LABEL_27:
            v6 = v11;
            if ( a2[1] >= v11 )
              goto LABEL_28;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10216BA0
// ============================================================
//----- (10216BA0) --------------------------------------------------------
int __thiscall sub_10216BA0(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadVarUInt(a2, this + 1);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10216C90
// ============================================================
//----- (10216C90) --------------------------------------------------------
int __thiscall sub_10216C90(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      break;
    if ( v8 >> 4 == 1 )
    {
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 1);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(a2, v8 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v4 )
    {
      v5 = v4 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10216470
// ============================================================
//----- (10216470) --------------------------------------------------------
int __thiscall sub_10216470(char *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int v8; // ecx
  int Int16; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 19) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(this + 19) & 1) == 0 )
              *(_DWORD *)(this + 19) |= 1u;
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0x290u);
            v8 = a2[1];
            if ( a2[2] != v8 )
            {
              *this = *(_BYTE *)(v8 + *a2);
              ++a2[1];
              v5 = 0;
              goto LABEL_27;
            }
            return -2;
          case 2u:
            if ( (*(_DWORD *)(this + 19) & 2) == 0 )
              *(_DWORD *)(this + 19) |= 2u;
            Int16 = TdrBuf::ReadInt16(a2, this + 1);
            goto LABEL_26;
          case 3u:
            if ( (*(_DWORD *)(this + 19) & 4) == 0 )
              *(_DWORD *)(this + 19) |= 4u;
            Int16 = TdrBuf::ReadInt32(a2, this + 3);
            goto LABEL_26;
          case 4u:
            if ( (*(_DWORD *)(this + 19) & 8) == 0 )
              *(_DWORD *)(this + 19) |= 8u;
            Int16 = TdrBuf::ReadInt32(a2, this + 7);
            goto LABEL_26;
          case 5u:
            if ( (*(_DWORD *)(this + 19) & 0x10) == 0 )
              *(_DWORD *)(this + 19) |= 0x10u;
            Int16 = TdrBuf::ReadInt32(a2, this + 11);
            goto LABEL_26;
          case 6u:
            if ( (*(_DWORD *)(this + 19) & 0x20) == 0 )
              *(_DWORD *)(this + 19) |= 0x20u;
            Int16 = TdrBuf::ReadInt32(a2, this + 15);
            goto LABEL_26;
          default:
            Int16 = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_26:
            v5 = Int16;
            if ( Int16 )
              return v5;
LABEL_27:
            v6 = v11;
            if ( a2[1] >= v11 )
              goto LABEL_28;
            continue;
        }
      }
      break;
    }
  }
  return result;
}
// 1010D4F0: using guessed type int __fastcall sub_1010D4F0(_DWORD, _DWORD);



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
// Address Name: SUB_102166E0
// ============================================================
//----- (102166E0) --------------------------------------------------------
int __thiscall sub_102166E0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[branchType]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[branchLevel]", "%d", *(unsigned __int16 *)(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[branchAllScore]", "%u", *(_DWORD *)(this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[branchDayScore]", "%u", *(_DWORD *)(this + 7));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[branchRecordCardLevelUpTimes]", "%d", *(_DWORD *)(this + 11));
          if ( !result )
            return print_field(a2, a3, a4, "[branchChallengeScore]", "%u", *(_DWORD *)(this + 15));
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



