// ============================================================
// Name: TLV::UnkTlv0120::Read
// Address Name: SUB_101701E0
// ============================================================
//----- (101701E0) --------------------------------------------------------
int __thiscall sub_101701E0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_101702B0((int)this, &v9, v8);
  else
    result = sub_10170620((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0120::Read_0xAA
// Address Name: SUB_101702B0
// ============================================================
//----- (101702B0) --------------------------------------------------------
int __thiscall sub_101702B0(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarULong; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  int *v12; // [esp+10h] [ebp-18h]
  int v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)(this + 257) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_53;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 257) & 1) == 0 )
          *(_DWORD *)(v3 + 257) |= 1u;
        VarULong = TdrBuf::ReadVarULong(a2, (_DWORD *)v3);
        goto LABEL_51;
      case 2u:
        if ( (*(_DWORD *)(v3 + 257) & 2) == 0 )
          *(_DWORD *)(v3 + 257) |= 2u;
        VarULong = TdrBuf::ReadVarInt(a2, (int *)(v3 + 8));
        goto LABEL_51;
      case 3u:
        if ( (*(_DWORD *)(v3 + 257) & 4) == 0 )
          *(_DWORD *)(v3 + 257) |= 4u;
        VarULong = TdrBuf::ReadVarULong(a2, (_DWORD *)(v3 + 12));
        goto LABEL_51;
      case 4u:
        if ( (*(_DWORD *)(v3 + 257) & 8) == 0 )
          *(_DWORD *)(v3 + 257) |= 8u;
        VarULong = TdrBuf::ReadVarULong(a2, (_DWORD *)(v3 + 20));
        goto LABEL_51;
      case 5u:
        if ( (*(_DWORD *)(v3 + 257) & 0x10) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x10u;
        VarULong = TdrBuf::ReadVarUInt(a2, (_DWORD *)(v3 + 28));
        goto LABEL_51;
      case 6u:
        if ( (*(_DWORD *)(v3 + 257) & 0x20) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(a2, (int *)(v3 + 32));
        goto LABEL_51;
      case 7u:
        if ( (*(_DWORD *)(v3 + 257) & 0x40) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(a2, (int *)(v3 + 36));
        goto LABEL_51;
      case 8u:
        if ( (*(_DWORD *)(v3 + 257) & 0x80) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x80u;
        VarULong = sub_10115A30(a2, (_BYTE *)(v3 + 40));
        goto LABEL_51;
      case 9u:
        if ( (*(_DWORD *)(v3 + 257) & 0x100) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x100u;
        VarULong = TdrBuf::ReadVarInt(a2, (int *)(v3 + 41));
        goto LABEL_51;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 257) & 0x200) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x200u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = (int *)(v13 + 45);
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1016F760(v12, a2, v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 += 5;
          if ( ++v8 >= 10 )
          {
            v3 = v13;
            goto LABEL_52;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *(_DWORD *)(v13 + 41) = v10;
LABEL_52:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_53:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 257) & 0x400) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x400u;
        VarULong = TdrBuf::ReadVarULong(a2, (_DWORD *)(v3 + 245));
        goto LABEL_51;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 257) & 0x800) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x800u;
        VarULong = TdrBuf::ReadVarUInt(a2, (_DWORD *)(v3 + 253));
        goto LABEL_51;
      default:
        VarULong = TdrBuf::SkipField(a2, v14 & 0xF);
LABEL_51:
        v4 = VarULong;
        if ( !VarULong )
          goto LABEL_52;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0120::Read_0x99
// Address Name: SUB_10170620
// ============================================================
//----- (10170620) --------------------------------------------------------
int __thiscall sub_10170620(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int64; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  int v12; // [esp+10h] [ebp-18h]
  int v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)(this + 257) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_53;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 257) & 1) == 0 )
          *(_DWORD *)(v3 + 257) |= 1u;
        Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)v3);
        goto LABEL_51;
      case 2u:
        if ( (*(_DWORD *)(v3 + 257) & 2) == 0 )
          *(_DWORD *)(v3 + 257) |= 2u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 8));
        goto LABEL_51;
      case 3u:
        if ( (*(_DWORD *)(v3 + 257) & 4) == 0 )
          *(_DWORD *)(v3 + 257) |= 4u;
        Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)(v3 + 12));
        goto LABEL_51;
      case 4u:
        if ( (*(_DWORD *)(v3 + 257) & 8) == 0 )
          *(_DWORD *)(v3 + 257) |= 8u;
        Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)(v3 + 20));
        goto LABEL_51;
      case 5u:
        if ( (*(_DWORD *)(v3 + 257) & 0x10) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 28));
        goto LABEL_51;
      case 6u:
        if ( (*(_DWORD *)(v3 + 257) & 0x20) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 32));
        goto LABEL_51;
      case 7u:
        if ( (*(_DWORD *)(v3 + 257) & 0x40) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 36));
        goto LABEL_51;
      case 8u:
        if ( (*(_DWORD *)(v3 + 257) & 0x80) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x80u;
        Int64 = sub_10115A30(a2, (_BYTE *)(v3 + 40));
        goto LABEL_51;
      case 9u:
        if ( (*(_DWORD *)(v3 + 257) & 0x100) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x100u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 41));
        goto LABEL_51;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 257) & 0x200) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x200u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = v13 + 45;
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1016F830(v12, a2, v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 += 20;
          if ( ++v8 >= 10 )
          {
            v3 = v13;
            goto LABEL_52;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *(_DWORD *)(v13 + 41) = v10;
LABEL_52:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_53:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 257) & 0x400) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x400u;
        Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)(v3 + 245));
        goto LABEL_51;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 257) & 0x800) == 0 )
          *(_DWORD *)(v3 + 257) |= 0x800u;
        Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 253));
        goto LABEL_51;
      default:
        Int64 = TdrBuf::SkipField(a2, v14 & 0xF);
LABEL_51:
        v4 = Int64;
        if ( !Int64 )
          goto LABEL_52;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0120::DoDebugFormat
// Address Name: SUB_101709B0
// ============================================================
//----- (101709B0) --------------------------------------------------------
int __thiscall sub_101709B0(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10170A60(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0120::DebugFormat
// Address Name: SUB_10170A60
// ============================================================
//----- (10170A60) --------------------------------------------------------
int __thiscall sub_10170A60(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // [esp+18h] [ebp+Ch]
  _DWORD *v11; // [esp+1Ch] [ebp+10h]

  result = print_field(a2, a3, a4, "[guild]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[contribution]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[contributionAcc]", "%I64u", *(_QWORD *)(this + 12));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[contributionWeekAcc]", "%I64u", *(_QWORD *)(this + 20));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[lastTime]", "%u", *((_DWORD *)this + 7));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[refreshTimestamp]", "%d", *((_DWORD *)this + 8));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[startBoatTimes]", "%d", *((_DWORD *)this + 9));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[buyStartBoatTimes]", "0x%02x", *(this + 40));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[guildCount]", "%d", *(_DWORD *)(this + 41));
                  if ( !result )
                  {
                    v8 = *(_DWORD *)(this + 41);
                    if ( v8 >= 0 )
                    {
                      if ( v8 <= 10 )
                      {
                        v9 = 0;
                        v10 = 0;
                        if ( v8 <= 0 )
                        {
LABEL_22:
                          result = print_field(a2, a3, a4, "[guildwarGrabPlayerId]", "%I64u", *(_QWORD *)(this + 245));
                          if ( !result )
                            return print_field(
                                     a2,
                                     a3,
                                     a4,
                                     "[guildwarGrabPlayerTimeStamp]",
                                     "%u",
                                     *(_DWORD *)(this + 253));
                        }
                        else
                        {
                          v11 = this + 45;
                          while ( 1 )
                          {
                            result = sub_1024A230(a2, a3, a4, "[otherGuildNews]", v9);
                            if ( result )
                              break;
                            result = a3 >= 0 ? sub_1016F9D0(v11, a2, a3 + 1, a4) : sub_1016F9D0(v11, a2, a3, a4);
                            if ( result )
                              break;
                            v11 += 5;
                            v9 = v10 + 1;
                            v10 = v9;
                            if ( v9 >= *(_DWORD *)(this + 41) )
                              goto LABEL_22;
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
// Address Name: SUB_1016F760
// ============================================================
//----- (1016F760) --------------------------------------------------------
int __thiscall sub_1016F760(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 4) = 0;
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
          if ( (*(_BYTE *)(this + 4) & 1) == 0 )
            *(this + 4) |= 1u;
          VarInt = sub_101600D0(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
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
// Address Name: SUB_1016F830
// ============================================================
//----- (1016F830) --------------------------------------------------------
int __thiscall sub_1016F830(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int64; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 16) = 0;
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
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(_DWORD *)(this + 16) |= 1u;
          Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 16) & 2) == 0 )
            *(_DWORD *)(this + 16) |= 2u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 16) & 4) == 0 )
            *(_DWORD *)(this + 16) |= 4u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        default:
          Int64 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int64;
      if ( Int64 )
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
// Address Name: SUB_1016F9D0
// ============================================================
//----- (1016F9D0) --------------------------------------------------------
int __thiscall sub_1016F9D0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[guildId]", "%I64i", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[timestamp]", "%d", *(this + 2));
    if ( !result )
      return print_field(a2, a3, a4, "[commerceId]", "%d", *(this + 3));
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
// Address Name: SUB_101600D0
// ============================================================
//----- (101600D0) --------------------------------------------------------
int __thiscall sub_101600D0(_DWORD *this, int *a2)
{
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // edx
  int v6; // eax
  char v7; // al
  int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  unsigned int v15; // [esp+8h] [ebp-Ch]
  char v16; // [esp+Ch] [ebp-8h]
  int v17; // [esp+10h] [ebp-4h]

  if ( *(this + 1) > *(this + 2) )
    _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x3DDu);
  v3 = 0;
  v4 = 0;
  v17 = 0;
  v15 = 0;
  *a2 = 0;
  a2[1] = 0;
  v5 = *(this + 1);
  if ( *(this + 2) != v5 )
  {
    v6 = v5 + *this;
    v16 = 0;
    while ( 1 )
    {
      v7 = *(_BYTE *)(v6 + v4);
      if ( (v7 & 0x7Fu) > 0xFFFFFFFFFFFFFFFFuLL >> v3 )
        break;
      *(_QWORD *)a2 |= (__int64)(v7 & 0x7F) << v16;
      v8 = *(this + 1);
      if ( *(char *)(v8 + *this + v4) < 0 )
      {
        ++v4;
        LOBYTE(v3) = v16 + 7;
        v16 += 7;
        v6 = v8 + *this;
        if ( v4 < *(this + 2) - v8 )
          continue;
      }
      v3 = 0;
      goto LABEL_9;
    }
    v3 = -1;
    v17 = -1;
  }
LABEL_9:
  v9 = *(this + 2) - *(this + 1);
  if ( v4 == v9 )
  {
    v10 = -1;
  }
  else
  {
    if ( !v3 && v9 )
      v15 = v4 + 1;
    v10 = v17;
  }
  v11 = a2[1];
  v12 = *a2;
  if ( (*a2 & 1) != 0 )
  {
    v12 = ~v12;
    v11 = ~v11;
  }
  v13 = *a2 << 31;
  *a2 = __PAIR64__(v11, v12) >> 1;
  a2[1] = v13 | (v11 >> 1) & 0x7FFFFFFF;
  if ( v10 )
    return -2;
  *(this + 1) += v15;
  return 0;
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



