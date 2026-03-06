// ============================================================
// Name: TLV::UnkTlv0039::Read_0xAA
// Address Name: SUB_1012BFD0
// ============================================================
//----- (1012BFD0) --------------------------------------------------------
int __thiscall sub_1012BFD0(int this, size_t Size, _DWORD *a3)
{
  _DWORD *v3; // eax
  int v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarULong; // eax
  int v10; // ebx
  size_t v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v17 = this;
  *(_DWORD *)(this + 265) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 265) & 1) == 0 )
          *(_DWORD *)(v4 + 265) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)v4);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v4 + 265) & 2) == 0 )
          *(_DWORD *)(v4 + 265) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x28 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(v4 + 8), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(v4 + Size + 8) = 0;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (*(_DWORD *)(v4 + 265) & 4) == 0 )
          *(_DWORD *)(v4 + 265) |= 4u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 48));
        goto LABEL_48;
      case 4u:
        if ( (*(_DWORD *)(v4 + 265) & 8) == 0 )
          *(_DWORD *)(v4 + 265) |= 8u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 52));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v4 + 265) & 0x10) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x10u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(v4 + 265) & 0x20) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 60));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(v4 + 265) & 0x40) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 64));
        goto LABEL_48;
      case 8u:
        if ( (*(_DWORD *)(v4 + 265) & 0x80) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x80u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 68));
        goto LABEL_48;
      case 9u:
        if ( (*(_DWORD *)(v4 + 265) & 0x100) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x100u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = (_DWORD *)(v17 + 72);
        while ( 1 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1012B400(a3, (size_t)v6, v15);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          a3 += 12;
          if ( ++v10 >= 4 )
          {
            v4 = v17;
            goto LABEL_49;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        *(_DWORD *)(v17 + 68) = v12;
LABEL_49:
        v7 = v13;
        if ( v6[1] < (unsigned int)v13 )
          continue;
LABEL_50:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Bytes;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 265) & 0x200) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x200u;
        VarULong = sub_10115A30(v6, (_BYTE *)(v4 + 264));
        goto LABEL_48;
      default:
        VarULong = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_48:
        Bytes = VarULong;
        if ( !VarULong )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0039::Read_0x99
// Address Name: SUB_1012C300
// ============================================================
//----- (1012C300) --------------------------------------------------------
int __thiscall sub_1012C300(int this, size_t Size, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // ebx
  size_t v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v17 = this;
  *(_DWORD *)(this + 265) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 265) & 1) == 0 )
          *(_DWORD *)(v4 + 265) |= 1u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v4 + 265) & 2) == 0 )
          *(_DWORD *)(v4 + 265) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x28 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(v4 + 8), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(v4 + Size + 8) = 0;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (*(_DWORD *)(v4 + 265) & 4) == 0 )
          *(_DWORD *)(v4 + 265) |= 4u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 48));
        goto LABEL_48;
      case 4u:
        if ( (*(_DWORD *)(v4 + 265) & 8) == 0 )
          *(_DWORD *)(v4 + 265) |= 8u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 52));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v4 + 265) & 0x10) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(v4 + 265) & 0x20) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 60));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(v4 + 265) & 0x40) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 64));
        goto LABEL_48;
      case 8u:
        if ( (*(_DWORD *)(v4 + 265) & 0x80) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x80u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 68));
        goto LABEL_48;
      case 9u:
        if ( (*(_DWORD *)(v4 + 265) & 0x100) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x100u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = v17 + 72;
        while ( 1 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1012B510(a3, (size_t)v6, v15);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          a3 += 48;
          if ( ++v10 >= 4 )
          {
            v4 = v17;
            goto LABEL_49;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        *(_DWORD *)(v17 + 68) = v12;
LABEL_49:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_50:
        if ( v6[1] > v7 )
          return -34;
        return Bytes;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 265) & 0x200) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x200u;
        Int64 = sub_10115A30(v6, (_BYTE *)(v4 + 264));
        goto LABEL_48;
      default:
        Int64 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_48:
        Bytes = Int64;
        if ( !Int64 )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0039::DoDebugFormat
// Address Name: SUB_1012C650
// ============================================================
//----- (1012C650) --------------------------------------------------------
int __thiscall sub_1012C650(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1012C700(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0039::DebugFormat
// Address Name: SUB_1012C700
// ============================================================
//----- (1012C700) --------------------------------------------------------
int __thiscall sub_1012C700(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v11; // [esp+1Ch] [ebp+Ch]
  _QWORD *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[guildID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[teamName]", this + 8);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[matchID]", "%d", *((_DWORD *)this + 12));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[signUpID]", "%u", *((_DWORD *)this + 13));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[signUpTM]", "%d", *((_DWORD *)this + 14));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[bestScore]", "%d", *((_DWORD *)this + 15));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[bestScoreTm]", "%d", *((_DWORD *)this + 16));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[count]", "%d", *((_DWORD *)this + 17));
                if ( !result )
                {
                  v7 = this;
                  v8 = *((_DWORD *)this + 17);
                  if ( v8 >= 0 )
                  {
                    if ( v8 <= 4 )
                    {
                      v9 = 0;
                      v11 = 0;
                      if ( v8 <= 0 )
                      {
                        return print_field(a2, a3, a4, "[acceptRound]", "0x%02x", v7[264]);
                      }
                      else
                      {
                        for ( i = this + 72; ; i += 6 )
                        {
                          result = sub_1024A230(a2, a3, a4, "[members]", v9);
                          if ( result )
                            break;
                          result = a3 >= 0 ? sub_1012B6F0(i, a2, a3 + 1, a4) : sub_1012B6F0(i, a2, a3, a4);
                          if ( result )
                            break;
                          v7 = this;
                          v9 = v11 + 1;
                          v11 = v9;
                          if ( v9 >= *((_DWORD *)this + 17) )
                            return print_field(a2, a3, a4, "[acceptRound]", "0x%02x", v7[264]);
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012B400
// ============================================================
//----- (1012B400) --------------------------------------------------------
int __thiscall sub_1012B400(_DWORD *this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int VarUInt; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(this + 11) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(this + 11) & 2) == 0 )
          *(this + 11) |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(v6, this + 2);
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        VarUInt = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(this + 11) & 4) == 0 )
        *(this + 11) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, this + 3, Size);
      if ( Bytes )
        return Bytes;
      *((_BYTE *)this + v10 + 12) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 11) & 1) == 0 )
      *(this + 11) |= 1u;
    VarUInt = TdrBuf::ReadVarULong(v6, this);
LABEL_19:
    Bytes = VarUInt;
    if ( VarUInt )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10115A30
// ============================================================
//----- (10115A30) --------------------------------------------------------
int __thiscall sub_10115A30(_DWORD *this, _BYTE *a2)
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
// Address Name: SUB_1012B510
// ============================================================
//----- (1012B510) --------------------------------------------------------
int __thiscall sub_1012B510(int this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int Int32; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 44) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 44) & 2) == 0 )
          *(_DWORD *)(this + 44) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 8));
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 44) & 4) == 0 )
        *(_DWORD *)(this + 44) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 12), Size);
      if ( Bytes )
        return Bytes;
      *(_BYTE *)(this + v10 + 12) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 44) & 1) == 0 )
      *(_DWORD *)(this + 44) |= 1u;
    Int32 = TdrBuf::ReadInt64(v6, (_BYTE *)this);
LABEL_19:
    Bytes = Int32;
    if ( Int32 )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
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
// Address Name: SUB_1024A410
// ============================================================
//----- (1024A410) --------------------------------------------------------
int __fastcall sub_1024A410(_DWORD *a1, int a2, char a3, const char *ArgList, const char *a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xAFu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s: ", ArgList);
    if ( !result )
    {
      result = Printf(a1, "%s", a5);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012B6F0
// ============================================================
//----- (1012B6F0) --------------------------------------------------------
int __thiscall sub_1012B6F0(_QWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[dBID]", "%I64u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[qQ]", "%u", *((_DWORD *)this + 2));
    if ( !result )
      return sub_1024A410(a2, a3, a4, "[name]", (const char *)this + 12);
  }
  return result;
}



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



