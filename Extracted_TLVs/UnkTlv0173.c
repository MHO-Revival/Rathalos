// ============================================================
// Name: TLV::UnkTlv0173::Read_0xAA
// Address Name: SUB_1019C930
// ============================================================
//----- (1019C930) --------------------------------------------------------
int __thiscall sub_1019C930(int this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 71) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_75:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 71) & 1) == 0 )
              *(_DWORD *)(this + 71) |= 1u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)this);
            goto LABEL_73;
          case 2u:
            if ( (*(_DWORD *)(this + 71) & 2) == 0 )
              *(_DWORD *)(this + 71) |= 2u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 4));
            goto LABEL_73;
          case 3u:
            if ( (*(_DWORD *)(this + 71) & 4) == 0 )
              *(_DWORD *)(this + 71) |= 4u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 8));
            goto LABEL_73;
          case 4u:
            if ( (*(_DWORD *)(this + 71) & 8) == 0 )
              *(_DWORD *)(this + 71) |= 8u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 12));
            goto LABEL_73;
          case 5u:
            if ( (*(_DWORD *)(this + 71) & 0x10) == 0 )
              *(_DWORD *)(this + 71) |= 0x10u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 16));
            goto LABEL_73;
          case 6u:
            if ( (*(_DWORD *)(this + 71) & 0x20) == 0 )
              *(_DWORD *)(this + 71) |= 0x20u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 20));
            goto LABEL_73;
          case 7u:
            if ( (*(_DWORD *)(this + 71) & 0x40) == 0 )
              *(_DWORD *)(this + 71) |= 0x40u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 24));
            goto LABEL_73;
          case 8u:
            if ( (*(_DWORD *)(this + 71) & 0x80) == 0 )
              *(_DWORD *)(this + 71) |= 0x80u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 25));
            goto LABEL_73;
          case 0xAu:
            if ( (*(_DWORD *)(this + 71) & 0x100) == 0 )
              *(_DWORD *)(this + 71) |= 0x100u;
            VarInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 29));
            goto LABEL_73;
          case 0xBu:
            if ( (*(_DWORD *)(this + 71) & 0x200) == 0 )
              *(_DWORD *)(this + 71) |= 0x200u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 33));
            goto LABEL_73;
          case 0xCu:
            if ( (*(_DWORD *)(this + 71) & 0x400) == 0 )
              *(_DWORD *)(this + 71) |= 0x400u;
            VarInt = sub_10151B00(v4, (_BYTE *)(this + 34));
            goto LABEL_73;
          case 0xDu:
            if ( (*(_DWORD *)(this + 71) & 0x800) == 0 )
              *(_DWORD *)(this + 71) |= 0x800u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 35));
            goto LABEL_73;
          case 0xEu:
            if ( (*(_DWORD *)(this + 71) & 0x1000) == 0 )
              *(_DWORD *)(this + 71) |= 0x1000u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 39));
            goto LABEL_73;
          case 0xFu:
            if ( (*(_DWORD *)(this + 71) & 0x2000) == 0 )
              *(_DWORD *)(this + 71) |= 0x2000u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 40));
            goto LABEL_73;
          case 0x10u:
            if ( (*(_DWORD *)(this + 71) & 0x4000) == 0 )
              *(_DWORD *)(this + 71) |= 0x4000u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 41));
            goto LABEL_73;
          case 0x11u:
            if ( (*(_DWORD *)(this + 71) & 0x8000) == 0 )
              *(_DWORD *)(this + 71) |= 0x8000u;
            VarInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 45));
            goto LABEL_73;
          case 0x12u:
            if ( (*(_DWORD *)(this + 71) & 0x10000) == 0 )
              *(_DWORD *)(this + 71) |= 0x10000u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 49));
            goto LABEL_73;
          case 0x13u:
            if ( (*(_DWORD *)(this + 71) & 0x20000) == 0 )
              *(_DWORD *)(this + 71) |= 0x20000u;
            VarInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 50));
            goto LABEL_73;
          case 0x14u:
            if ( (*(_DWORD *)(this + 71) & 0x40000) == 0 )
              *(_DWORD *)(this + 71) |= 0x40000u;
            VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(this + 54));
            goto LABEL_73;
          case 0x15u:
            if ( (*(_DWORD *)(this + 71) & 0x80000) == 0 )
              *(_DWORD *)(this + 71) |= 0x80000u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_74;
            VarInt = sub_1019BCE0((int *)(this + 55), v4, a2);
LABEL_73:
            v6 = VarInt;
            if ( VarInt )
              return v6;
LABEL_74:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_75;
            continue;
          case 0x16u:
            if ( (*(_DWORD *)(this + 71) & 0x100000) == 0 )
              *(_DWORD *)(this + 71) |= 0x100000u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 63));
            goto LABEL_73;
          case 0x17u:
            if ( (*(_DWORD *)(this + 71) & 0x200000) == 0 )
              *(_DWORD *)(this + 71) |= 0x200000u;
            VarInt = TdrBuf::ReadVarInt(v4, (int *)(this + 67));
            goto LABEL_73;
          default:
            VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_73;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0173::Read_0x99
// Address Name: SUB_1019CD40
// ============================================================
//----- (1019CD40) --------------------------------------------------------
int __thiscall sub_1019CD40(int this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 71) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_75:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 71) & 1) == 0 )
              *(_DWORD *)(this + 71) |= 1u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
            goto LABEL_73;
          case 2u:
            if ( (*(_DWORD *)(this + 71) & 2) == 0 )
              *(_DWORD *)(this + 71) |= 2u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
            goto LABEL_73;
          case 3u:
            if ( (*(_DWORD *)(this + 71) & 4) == 0 )
              *(_DWORD *)(this + 71) |= 4u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
            goto LABEL_73;
          case 4u:
            if ( (*(_DWORD *)(this + 71) & 8) == 0 )
              *(_DWORD *)(this + 71) |= 8u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 12));
            goto LABEL_73;
          case 5u:
            if ( (*(_DWORD *)(this + 71) & 0x10) == 0 )
              *(_DWORD *)(this + 71) |= 0x10u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 16));
            goto LABEL_73;
          case 6u:
            if ( (*(_DWORD *)(this + 71) & 0x20) == 0 )
              *(_DWORD *)(this + 71) |= 0x20u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 20));
            goto LABEL_73;
          case 7u:
            if ( (*(_DWORD *)(this + 71) & 0x40) == 0 )
              *(_DWORD *)(this + 71) |= 0x40u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 24));
            goto LABEL_73;
          case 8u:
            if ( (*(_DWORD *)(this + 71) & 0x80) == 0 )
              *(_DWORD *)(this + 71) |= 0x80u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 25));
            goto LABEL_73;
          case 0xAu:
            if ( (*(_DWORD *)(this + 71) & 0x100) == 0 )
              *(_DWORD *)(this + 71) |= 0x100u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 29));
            goto LABEL_73;
          case 0xBu:
            if ( (*(_DWORD *)(this + 71) & 0x200) == 0 )
              *(_DWORD *)(this + 71) |= 0x200u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 33));
            goto LABEL_73;
          case 0xCu:
            if ( (*(_DWORD *)(this + 71) & 0x400) == 0 )
              *(_DWORD *)(this + 71) |= 0x400u;
            Int32 = sub_10151B00(v4, (_BYTE *)(this + 34));
            goto LABEL_73;
          case 0xDu:
            if ( (*(_DWORD *)(this + 71) & 0x800) == 0 )
              *(_DWORD *)(this + 71) |= 0x800u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 35));
            goto LABEL_73;
          case 0xEu:
            if ( (*(_DWORD *)(this + 71) & 0x1000) == 0 )
              *(_DWORD *)(this + 71) |= 0x1000u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 39));
            goto LABEL_73;
          case 0xFu:
            if ( (*(_DWORD *)(this + 71) & 0x2000) == 0 )
              *(_DWORD *)(this + 71) |= 0x2000u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 40));
            goto LABEL_73;
          case 0x10u:
            if ( (*(_DWORD *)(this + 71) & 0x4000) == 0 )
              *(_DWORD *)(this + 71) |= 0x4000u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 41));
            goto LABEL_73;
          case 0x11u:
            if ( (*(_DWORD *)(this + 71) & 0x8000) == 0 )
              *(_DWORD *)(this + 71) |= 0x8000u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 45));
            goto LABEL_73;
          case 0x12u:
            if ( (*(_DWORD *)(this + 71) & 0x10000) == 0 )
              *(_DWORD *)(this + 71) |= 0x10000u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 49));
            goto LABEL_73;
          case 0x13u:
            if ( (*(_DWORD *)(this + 71) & 0x20000) == 0 )
              *(_DWORD *)(this + 71) |= 0x20000u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 50));
            goto LABEL_73;
          case 0x14u:
            if ( (*(_DWORD *)(this + 71) & 0x40000) == 0 )
              *(_DWORD *)(this + 71) |= 0x40000u;
            Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 54));
            goto LABEL_73;
          case 0x15u:
            if ( (*(_DWORD *)(this + 71) & 0x80000) == 0 )
              *(_DWORD *)(this + 71) |= 0x80000u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_74;
            Int32 = sub_1019BD60(this + 55, v4, a2);
LABEL_73:
            v6 = Int32;
            if ( Int32 )
              return v6;
LABEL_74:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_75;
            continue;
          case 0x16u:
            if ( (*(_DWORD *)(this + 71) & 0x100000) == 0 )
              *(_DWORD *)(this + 71) |= 0x100000u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 63));
            goto LABEL_73;
          case 0x17u:
            if ( (*(_DWORD *)(this + 71) & 0x200000) == 0 )
              *(_DWORD *)(this + 71) |= 0x200000u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 67));
            goto LABEL_73;
          default:
            Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_73;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0173::DoDebugFormat
// Address Name: SUB_1019D170
// ============================================================
//----- (1019D170) --------------------------------------------------------
int __thiscall sub_1019D170(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1019D220(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0173::DebugFormat
// Address Name: SUB_1019D220
// ============================================================
//----- (1019D220) --------------------------------------------------------
int __thiscall sub_1019D220(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx

  result = print_field(a2, a3, a4, "[iVIPLevel]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iVIPExp]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iQQGame_MHOVIP_Level]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iQQGame_MHOVIP_EndTime]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[iQQGame_MHOVIP_LastUpdateTime]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[iVIPBaseLastestEndTime]", "%d", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[uVIPPayReq]", "0x%02x", *((unsigned __int8 *)this + 24));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[iVIPOpenPeriod]", "%d", *(_DWORD *)((char *)this + 25));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[uLastEnterOrExitTime]", "%u", *(_DWORD *)((char *)this + 29));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[uFinishRoleVIPMerge]", "0x%02x", *((unsigned __int8 *)this + 33));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[createdRole]", "0x%02x", *((char *)this + 34));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[iLastAddVIPExpDaily]", "%d", *(_DWORD *)((char *)this + 35));
                        if ( !result )
                        {
                          result = print_field(
                                     a2,
                                     a3,
                                     a4,
                                     "[uVIPPaySuccCount]",
                                     "0x%02x",
                                     *((unsigned __int8 *)this + 39));
                          if ( !result )
                          {
                            result = print_field(
                                       a2,
                                       a3,
                                       a4,
                                       "[uDelRoleCount]",
                                       "0x%02x",
                                       *((unsigned __int8 *)this + 40));
                            if ( !result )
                            {
                              result = print_field(
                                         a2,
                                         a3,
                                         a4,
                                         "[iSanctionEndTime]",
                                         "%d",
                                         *(_DWORD *)((char *)this + 41));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[iFaceCount]", "%u", *(_DWORD *)((char *)this + 45));
                                if ( !result )
                                {
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[iSanctionRatio]",
                                             "0x%02x",
                                             *((unsigned __int8 *)this + 49));
                                  if ( !result )
                                  {
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[iChgSexCount]",
                                               "%u",
                                               *(_DWORD *)((char *)this + 50));
                                    if ( !result )
                                    {
                                      result = print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[iIsNewbie]",
                                                 "0x%02x",
                                                 *((unsigned __int8 *)this + 54));
                                      if ( !result )
                                      {
                                        result = print_structure((int)a2, a3, a4, (int)"[stSelfUIOption]");
                                        if ( !result )
                                        {
                                          v5 = (_DWORD *)((char *)this + 55);
                                          if ( a3 >= 0 )
                                            result = sub_1019BEB0(v5, a2, a3 + 1, a4);
                                          else
                                            result = sub_1019BEB0(v5, a2, a3, a4);
                                          if ( !result )
                                          {
                                            result = print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[iParentControlStartTime]",
                                                       "%d",
                                                       *(_DWORD *)((char *)this + 63));
                                            if ( !result )
                                              return print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[iParentControlEndTime]",
                                                       "%d",
                                                       *(_DWORD *)((char *)this + 67));
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
// Address Name: SUB_10151B00
// ============================================================
//----- (10151B00) --------------------------------------------------------
int __thiscall sub_10151B00(_DWORD *this, _BYTE *a2)
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
// Address Name: SUB_1019BCE0
// ============================================================
//----- (1019BCE0) --------------------------------------------------------
int __thiscall sub_1019BCE0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 1) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
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
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1019BD60
// ============================================================
//----- (1019BD60) --------------------------------------------------------
int __thiscall sub_1019BD60(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
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
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
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
// Address Name: SUB_1019BEB0
// ============================================================
//----- (1019BEB0) --------------------------------------------------------
int __thiscall sub_1019BEB0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  return print_field(a2, a3, a4, "[iEntrustUIStep]", "%d", *this);
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



