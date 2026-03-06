// ============================================================
// Name: TLV::UnkTlv0157::Read
// Address Name: SUB_1018B3D0
// ============================================================
//----- (1018B3D0) --------------------------------------------------------
int __thiscall sub_1018B3D0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1018B4A0((int)this, &v9, v8);
  else
    result = sub_1018B910((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0157::Read_0xAA
// Address Name: SUB_1018B4A0
// ============================================================
//----- (1018B4A0) --------------------------------------------------------
int __thiscall sub_1018B4A0(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  int v16; // [esp+10h] [ebp-18h] BYREF
  int *v17; // [esp+14h] [ebp-14h]
  unsigned int v18; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch] BYREF
  int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 48990) = 0;
  v18 = 0;
  v5 = a2[1] + a3;
  v21 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_69;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 48990) & 1) == 0 )
          *(_DWORD *)(v3 + 48990) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)v3);
        goto LABEL_67;
      case 2u:
        if ( (*(_DWORD *)(v3 + 48990) & 2) == 0 )
          *(_DWORD *)(v3 + 48990) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 4));
        goto LABEL_67;
      case 3u:
        if ( (*(_DWORD *)(v3 + 48990) & 4) == 0 )
          *(_DWORD *)(v3 + 48990) |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 8));
        goto LABEL_67;
      case 4u:
        if ( (*(_DWORD *)(v3 + 48990) & 8) == 0 )
          *(_DWORD *)(v3 + 48990) |= 8u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 12));
        goto LABEL_67;
      case 5u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x10) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x10u;
        VarInt = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 16));
        goto LABEL_67;
      case 6u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x20) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x20u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v8 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v4 = TdrBuf::ReadVarInt(a2, (int *)(this + 4 * v8 + 17));
          if ( v4 )
            return v4;
          v9 = a2[1];
          if ( v9 > v19 + v16 )
            return -34;
          if ( v9 == v19 + v16 )
            break;
          if ( ++v8 >= 0x28u )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        *(_BYTE *)(this + 16) = v8 + 1;
        v3 = this;
        goto LABEL_68;
      case 7u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x40) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x40u;
        VarInt = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 177));
        goto LABEL_67;
      case 8u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x80) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x80u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v10 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v4 = TdrBuf::ReadVarInt(a2, (int *)(this + 4 * v10 + 178));
          if ( v4 )
            return v4;
          v11 = a2[1];
          if ( v11 > v19 + v16 )
            return -34;
          if ( v11 == v19 + v16 )
            break;
          if ( ++v10 >= 0xC8u )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        *(_BYTE *)(this + 177) = v10 + 1;
        v3 = this;
        goto LABEL_68;
      case 9u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x100) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 978));
        goto LABEL_67;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x200) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 982));
        goto LABEL_67;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x400) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x400u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v12 = 0;
        v20 = a2[1];
        v17 = (int *)(this + 986);
        while ( 1 )
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_1018A740(v17, a2, v19);
            if ( v4 )
              return v4;
          }
          v13 = a2[1];
          if ( v13 > v20 + v16 )
            return -34;
          if ( v13 == v20 + v16 )
            break;
          v17 += 12;
          if ( ++v12 >= 1000 )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        v14 = v12 + 1;
        v3 = this;
        *(_DWORD *)(this + 982) = v14;
LABEL_68:
        v5 = v21;
        if ( a2[1] < v21 )
          continue;
LABEL_69:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x800) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x800u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 48986));
        goto LABEL_67;
      default:
        VarInt = TdrBuf::SkipField(a2, v18 & 0xF);
LABEL_67:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_68;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0157::Read_0x99
// Address Name: SUB_1018B910
// ============================================================
//----- (1018B910) --------------------------------------------------------
int __thiscall sub_1018B910(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  int v16; // [esp+10h] [ebp-18h] BYREF
  int v17; // [esp+14h] [ebp-14h]
  unsigned int v18; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch] BYREF
  int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 48990) = 0;
  v18 = 0;
  v5 = a2[1] + a3;
  v21 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_69;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 48990) & 1) == 0 )
          *(_DWORD *)(v3 + 48990) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3);
        goto LABEL_67;
      case 2u:
        if ( (*(_DWORD *)(v3 + 48990) & 2) == 0 )
          *(_DWORD *)(v3 + 48990) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 4));
        goto LABEL_67;
      case 3u:
        if ( (*(_DWORD *)(v3 + 48990) & 4) == 0 )
          *(_DWORD *)(v3 + 48990) |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 8));
        goto LABEL_67;
      case 4u:
        if ( (*(_DWORD *)(v3 + 48990) & 8) == 0 )
          *(_DWORD *)(v3 + 48990) |= 8u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 12));
        goto LABEL_67;
      case 5u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x10) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x10u;
        Int32 = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 16));
        goto LABEL_67;
      case 6u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x20) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x20u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v8 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v4 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4 * v8 + 17));
          if ( v4 )
            return v4;
          v9 = a2[1];
          if ( v9 > v19 + v16 )
            return -34;
          if ( v9 == v19 + v16 )
            break;
          if ( ++v8 >= 0x28u )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        *(_BYTE *)(this + 16) = v8 + 1;
        v3 = this;
        goto LABEL_68;
      case 7u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x40) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x40u;
        Int32 = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 177));
        goto LABEL_67;
      case 8u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x80) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x80u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v10 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v4 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4 * v10 + 178));
          if ( v4 )
            return v4;
          v11 = a2[1];
          if ( v11 > v19 + v16 )
            return -34;
          if ( v11 == v19 + v16 )
            break;
          if ( ++v10 >= 0xC8u )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        *(_BYTE *)(this + 177) = v10 + 1;
        v3 = this;
        goto LABEL_68;
      case 9u:
        if ( (*(_DWORD *)(v3 + 48990) & 0x100) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 978));
        goto LABEL_67;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x200) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x200u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 982));
        goto LABEL_67;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x400) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x400u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v12 = 0;
        v20 = a2[1];
        v17 = this + 986;
        while ( 1 )
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_1018A820(v17, a2, v19);
            if ( v4 )
              return v4;
          }
          v13 = a2[1];
          if ( v13 > v20 + v16 )
            return -34;
          if ( v13 == v20 + v16 )
            break;
          v17 += 48;
          if ( ++v12 >= 1000 )
          {
            v3 = this;
            goto LABEL_68;
          }
        }
        v14 = v12 + 1;
        v3 = this;
        *(_DWORD *)(this + 982) = v14;
LABEL_68:
        v5 = v21;
        if ( a2[1] < v21 )
          continue;
LABEL_69:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 48990) & 0x800) == 0 )
          *(_DWORD *)(v3 + 48990) |= 0x800u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 48986));
        goto LABEL_67;
      default:
        Int32 = TdrBuf::SkipField(a2, v18 & 0xF);
LABEL_67:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_68;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0157::DoDebugFormat
// Address Name: SUB_1018BDA0
// ============================================================
//----- (1018BDA0) --------------------------------------------------------
int __thiscall sub_1018BDA0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1018BE50(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0157::DebugFormat
// Address Name: SUB_1018BE50
// ============================================================
//----- (1018BE50) --------------------------------------------------------
int __thiscall sub_1018BE50(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  int v11; // ecx
  unsigned __int8 v12; // al
  unsigned __int8 v13; // al
  int v14; // ecx
  int v15; // eax
  int v16; // [esp+14h] [ebp+8h]
  _DWORD *v17; // [esp+18h] [ebp+Ch]
  unsigned __int8 v18; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v19; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[stage]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[level]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[attrPoint]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[failureTimes]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[stageCount]", "0x%02x", *((unsigned __int8 *)this + 16));
          if ( !result )
          {
            v9 = *((_BYTE *)this + 16);
            if ( v9 > 0x28u )
              return -7;
            result = sub_1024A3B0(a2, a3, v8, "[stages]", v9);
            if ( !result )
            {
              v10 = 0;
              v18 = 0;
              if ( *((_BYTE *)this + 16) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %d", *(_DWORD *)((char *)this + 4 * v10 + 17));
                  if ( result )
                    break;
                  v10 = v18 + 1;
                  v18 = v10;
                  if ( v10 >= *((_BYTE *)this + 16) )
                    goto LABEL_12;
                }
              }
              else
              {
LABEL_12:
                result = TdrBuf::WriteChar(a2, a4);
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[attrCount]", "0x%02x", *((unsigned __int8 *)this + 177));
                  if ( !result )
                  {
                    v12 = *((_BYTE *)this + 177);
                    if ( v12 > 0xC8u )
                      return -7;
                    result = sub_1024A3B0(a2, a3, v11, "[attrs]", v12);
                    if ( !result )
                    {
                      v13 = 0;
                      v19 = 0;
                      if ( *((_BYTE *)this + 177) )
                      {
                        while ( 1 )
                        {
                          result = Printf(a2, " %d", *(_DWORD *)((char *)this + 4 * v13 + 178));
                          if ( result )
                            break;
                          v13 = v19 + 1;
                          v19 = v13;
                          if ( v13 >= *((_BYTE *)this + 177) )
                            goto LABEL_19;
                        }
                      }
                      else
                      {
LABEL_19:
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[attrLearnCount]", "%d", *(_DWORD *)((char *)this + 978));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[beastCount]", "%d", *(_DWORD *)((char *)this + 982));
                            if ( !result )
                            {
                              v14 = *(_DWORD *)((char *)this + 982);
                              if ( v14 >= 0 )
                              {
                                if ( v14 > 1000 )
                                  return -7;
                                v15 = 0;
                                v16 = 0;
                                if ( v14 <= 0 )
                                {
                                  return print_field(
                                           a2,
                                           a3,
                                           a4,
                                           "[followBeast]",
                                           "%d",
                                           *(_DWORD *)((char *)this + 48986));
                                }
                                else
                                {
                                  v17 = (_DWORD *)((char *)this + 986);
                                  while ( 1 )
                                  {
                                    result = sub_1024A230(a2, a3, a4, "[beasts]", v15);
                                    if ( result )
                                      break;
                                    result = a3 >= 0 ? sub_1018A9D0(v17, a2, a3 + 1, a4) : sub_1018A9D0(v17, a2, a3, a4);
                                    if ( result )
                                      break;
                                    v17 += 12;
                                    v15 = v16 + 1;
                                    v16 = v15;
                                    if ( v15 >= *(_DWORD *)((char *)this + 982) )
                                      return print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[followBeast]",
                                               "%d",
                                               *(_DWORD *)((char *)this + 48986));
                                  }
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
          }
        }
      }
    }
  }
  return result;
}
// 1018BF2C: variable 'v8' is possibly undefined
// 1018BFD1: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018A740
// ============================================================
//----- (1018A740) --------------------------------------------------------
int __thiscall sub_1018A740(int *this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(this + 11) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        return result;
      if ( v8 >> 4 == 1 )
        break;
      if ( v8 >> 4 != 2 )
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_14;
      }
      if ( (*(this + 11) & 2) == 0 )
        *(this + 11) |= 2u;
      v9 = 0;
      v4 = TdrBuf::ReadInt32(a2, &v9);
      if ( v4 )
        return v4;
      if ( v9 )
      {
        VarInt = sub_102070B0(this + 1, a2, v9);
        goto LABEL_14;
      }
LABEL_15:
      v5 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_16;
    }
    if ( (*(_BYTE *)(this + 11) & 1) == 0 )
      *(this + 11) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, this);
LABEL_14:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_15;
  }
LABEL_16:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018A820
// ============================================================
//----- (1018A820) --------------------------------------------------------
int __thiscall sub_1018A820(int this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 44) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v8);
      if ( result )
        return result;
      if ( v8 >> 4 == 1 )
        break;
      if ( v8 >> 4 != 2 )
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_14;
      }
      if ( (*(_DWORD *)(this + 44) & 2) == 0 )
        *(_DWORD *)(this + 44) |= 2u;
      v9 = 0;
      v4 = TdrBuf::ReadInt32(a2, &v9);
      if ( v4 )
        return v4;
      if ( v9 )
      {
        Int32 = sub_10207260(this + 4, a2, v9);
        goto LABEL_14;
      }
LABEL_15:
      v5 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_16;
    }
    if ( (*(_BYTE *)(this + 44) & 1) == 0 )
      *(_DWORD *)(this + 44) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_14:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_15;
  }
LABEL_16:
  if ( a2[1] > v5 )
    return -34;
  return v4;
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
// Address Name: SUB_1018A9D0
// ============================================================
//----- (1018A9D0) --------------------------------------------------------
int __thiscall sub_1018A9D0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  _DWORD *v5; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    if ( !"[attrs]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[attrs]", a4);
      if ( !result )
      {
        v5 = this + 1;
        if ( a3 >= 0 )
          return sub_102074E0(v5, a2, a3 + 1, a4);
        else
          return sub_102074E0(v5, a2, a3, a4);
      }
    }
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
// Address Name: SUB_102070B0
// ============================================================
//----- (102070B0) --------------------------------------------------------
int __thiscall sub_102070B0(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 9) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_31:
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
          if ( (*(_BYTE *)(this + 9) & 1) == 0 )
            *(this + 9) |= 1u;
          VarULong = TdrBuf::ReadVarULong(a2, this);
          break;
        case 2u:
          if ( (*(this + 9) & 2) == 0 )
            *(this + 9) |= 2u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 9) & 4) == 0 )
            *(this + 9) |= 4u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 9) & 8) == 0 )
            *(this + 9) |= 8u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 9) & 0x10) == 0 )
            *(this + 9) |= 0x10u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 9) & 0x20) == 0 )
            *(this + 9) |= 0x20u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 6);
          break;
        case 8u:
          if ( (*(this + 9) & 0x40) == 0 )
            *(this + 9) |= 0x40u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 7);
          break;
        case 9u:
          if ( (*(this + 9) & 0x80) == 0 )
            *(this + 9) |= 0x80u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 8);
          break;
        default:
          VarULong = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarULong;
      if ( VarULong )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_31;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10207260
// ============================================================
//----- (10207260) --------------------------------------------------------
int __thiscall sub_10207260(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 36) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_31:
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
          if ( (*(_BYTE *)(this + 36) & 1) == 0 )
            *(_DWORD *)(this + 36) |= 1u;
          Int64 = TdrBuf::ReadInt64(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 36) & 2) == 0 )
            *(_DWORD *)(this + 36) |= 2u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 36) & 4) == 0 )
            *(_DWORD *)(this + 36) |= 4u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 36) & 8) == 0 )
            *(_DWORD *)(this + 36) |= 8u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 36) & 0x10) == 0 )
            *(_DWORD *)(this + 36) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 36) & 0x20) == 0 )
            *(_DWORD *)(this + 36) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 36) & 0x40) == 0 )
            *(_DWORD *)(this + 36) |= 0x40u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 28));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 36) & 0x80) == 0 )
            *(_DWORD *)(this + 36) |= 0x80u;
          Int64 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 32));
          break;
        default:
          Int64 = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Int64;
      if ( Int64 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_31;
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
// Address Name: SUB_102074E0
// ============================================================
//----- (102074E0) --------------------------------------------------------
int __thiscall sub_102074E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[soulBeastGID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[oCharLevel]", "%d", *(this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[oCharExp]", "%d", *(this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[oCharGlut]", "%d", *(this + 4));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[oEvloveStage]", "%d", *(this + 5));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[oImage]", "%d", *(this + 6));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[oFollow]", "%d", *(this + 7));
              if ( !result )
                return print_field(a2, a3, a4, "[oFeedTime]", "%d", *(this + 8));
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



