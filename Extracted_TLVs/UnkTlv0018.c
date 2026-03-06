// ============================================================
// Name: TLV::UnkTlv0018::Read_0xAA
// Address Name: SUB_1011C3B0
// ============================================================
//----- (1011C3B0) --------------------------------------------------------
int __thiscall sub_1011C3B0(int this, unsigned int a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int v4; // ebx
  int VarULong; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // ecx
  int v18; // eax
  char *v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v23; // [esp+18h] [ebp-8h] BYREF
  int v24; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  VarULong = 0;
  v6 = (_DWORD *)a2;
  v24 = this;
  *(_DWORD *)(this + 2014) = 0;
  v23 = 0;
  v7 = (char *)v3 + v6[1];
  v19 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_85;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 2014) & 1) == 0 )
          *(_DWORD *)(v4 + 2014) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)v4);
        goto LABEL_83;
      case 2u:
        if ( (*(_DWORD *)(v4 + 2014) & 2) == 0 )
          *(_DWORD *)(v4 + 2014) |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 4));
        goto LABEL_83;
      case 3u:
        if ( (*(_DWORD *)(v4 + 2014) & 4) == 0 )
          *(_DWORD *)(v4 + 2014) |= 4u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 8));
        goto LABEL_83;
      case 4u:
        if ( (*(_DWORD *)(v4 + 2014) & 8) == 0 )
          *(_DWORD *)(v4 + 2014) |= 8u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 12));
        goto LABEL_83;
      case 6u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x10) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x10u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 16));
        goto LABEL_83;
      case 7u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x20) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x20u;
        VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 20));
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x40) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x40u;
        VarUInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 24));
        goto LABEL_83;
      case 9u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x80) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(v24 + 8 * v10 + 25));
          if ( VarULong )
            return VarULong;
          v11 = v6[1];
          if ( v11 > (unsigned int)a3 + a2 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a3 + a2) )
            break;
          if ( ++v10 >= 0xC8u )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v12 = v24;
        *(_BYTE *)(v24 + 24) = v10 + 1;
        v4 = v12;
        goto LABEL_84;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x100) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x100u;
        VarUInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 1625));
        goto LABEL_83;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x200) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v20 = v6[1];
        a3 = (_DWORD *)(v24 + 1629);
        while ( 1 )
        {
          v22 = 0;
          VarULong = TdrBuf::ReadInt32(v6, &v22);
          if ( VarULong )
            return VarULong;
          if ( v22 )
          {
            VarULong = sub_1011A1C0(a3, v6, v22);
            if ( VarULong )
              return VarULong;
          }
          v14 = v6[1];
          if ( v14 > v20 + a2 )
            return -34;
          if ( v14 == v20 + a2 )
            break;
          a3 += 4;
          if ( ++v13 >= 10 )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v15 = v13 + 1;
        v4 = v24;
        *(_DWORD *)(v24 + 1625) = v15;
        goto LABEL_84;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x400) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x400u;
        VarUInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 1789));
        goto LABEL_83;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x800) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x800u;
        a2 = 0;
        VarULong = TdrBuf::ReadInt32(v6, &a2);
        if ( VarULong )
          return VarULong;
        if ( !a2 )
          goto LABEL_84;
        VarUInt = sub_1011B300((_DWORD *)(v4 + 1790), (int)v6, a2);
LABEL_83:
        VarULong = VarUInt;
        if ( !VarUInt )
          goto LABEL_84;
        return VarULong;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x1000u;
        VarUInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 1862));
        goto LABEL_83;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v21 = v6[1];
        a3 = (_DWORD *)(v24 + 1866);
        while ( 1 )
        {
          v22 = 0;
          VarULong = TdrBuf::ReadInt32(v6, &v22);
          if ( VarULong )
            return VarULong;
          if ( v22 )
          {
            VarULong = sub_10119B50(a3, v6, v22);
            if ( VarULong )
              return VarULong;
          }
          v17 = v6[1];
          if ( v17 > v21 + a2 )
            return -34;
          if ( v17 == v21 + a2 )
            break;
          a3 += 5;
          if ( ++v16 >= 7 )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v18 = v16 + 1;
        v4 = v24;
        *(_DWORD *)(v24 + 1862) = v18;
LABEL_84:
        v7 = v19;
        if ( v6[1] < (unsigned int)v19 )
          continue;
LABEL_85:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return VarULong;
      case 0x10u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x4000u;
        VarUInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 2006));
        goto LABEL_83;
      case 0x11u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x8000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x8000u;
        VarUInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 2010));
        goto LABEL_83;
      default:
        VarUInt = TdrBuf::SkipField(v6, v23 & 0xF);
        goto LABEL_83;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0018::Read_0x99
// Address Name: SUB_1011C900
// ============================================================
//----- (1011C900) --------------------------------------------------------
int __thiscall sub_1011C900(int this, unsigned int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Int64; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // ecx
  int v18; // eax
  unsigned int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v23; // [esp+18h] [ebp-8h] BYREF
  int v24; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Int64 = 0;
  v6 = (_DWORD *)a2;
  v24 = this;
  *(_DWORD *)(this + 2014) = 0;
  v23 = 0;
  v7 = v6[1] + v3;
  v19 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_85;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 2014) & 1) == 0 )
          *(_DWORD *)(v4 + 2014) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4);
        goto LABEL_83;
      case 2u:
        if ( (*(_DWORD *)(v4 + 2014) & 2) == 0 )
          *(_DWORD *)(v4 + 2014) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 4));
        goto LABEL_83;
      case 3u:
        if ( (*(_DWORD *)(v4 + 2014) & 4) == 0 )
          *(_DWORD *)(v4 + 2014) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 8));
        goto LABEL_83;
      case 4u:
        if ( (*(_DWORD *)(v4 + 2014) & 8) == 0 )
          *(_DWORD *)(v4 + 2014) |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 12));
        goto LABEL_83;
      case 6u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x10) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 16));
        goto LABEL_83;
      case 7u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x20) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 20));
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x40) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x40u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 24));
        goto LABEL_83;
      case 9u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x80) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        while ( 1 )
        {
          Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(v24 + 8 * v10 + 25));
          if ( Int64 )
            return Int64;
          v11 = v6[1];
          if ( v11 > a3 + a2 )
            return -34;
          if ( v11 == a3 + a2 )
            break;
          if ( ++v10 >= 0xC8u )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v12 = v24;
        *(_BYTE *)(v24 + 24) = v10 + 1;
        v4 = v12;
        goto LABEL_84;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x100) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 1625));
        goto LABEL_83;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x200) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v20 = v6[1];
        a3 = v24 + 1629;
        while ( 1 )
        {
          v22 = 0;
          Int64 = TdrBuf::ReadInt32(v6, &v22);
          if ( Int64 )
            return Int64;
          if ( v22 )
          {
            Int64 = sub_1011A260(a3, v6, v22);
            if ( Int64 )
              return Int64;
          }
          v14 = v6[1];
          if ( v14 > v20 + a2 )
            return -34;
          if ( v14 == v20 + a2 )
            break;
          a3 += 16;
          if ( ++v13 >= 10 )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v15 = v13 + 1;
        v4 = v24;
        *(_DWORD *)(v24 + 1625) = v15;
        goto LABEL_84;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x400) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x400u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 1789));
        goto LABEL_83;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x800) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x800u;
        a2 = 0;
        Int64 = TdrBuf::ReadInt32(v6, &a2);
        if ( Int64 )
          return Int64;
        if ( !a2 )
          goto LABEL_84;
        Int32 = sub_1011B450(v4 + 1790, (int)v6, a2);
LABEL_83:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_84;
        return Int64;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x1000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 1862));
        goto LABEL_83;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 2014) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v21 = v6[1];
        a3 = v24 + 1866;
        while ( 1 )
        {
          v22 = 0;
          Int64 = TdrBuf::ReadInt32(v6, &v22);
          if ( Int64 )
            return Int64;
          if ( v22 )
          {
            Int64 = sub_10119C20(a3, v6, v22);
            if ( Int64 )
              return Int64;
          }
          v17 = v6[1];
          if ( v17 > v21 + a2 )
            return -34;
          if ( v17 == v21 + a2 )
            break;
          a3 += 20;
          if ( ++v16 >= 7 )
          {
            v4 = v24;
            goto LABEL_84;
          }
        }
        v18 = v16 + 1;
        v4 = v24;
        *(_DWORD *)(v24 + 1862) = v18;
LABEL_84:
        v7 = v19;
        if ( v6[1] < v19 )
          continue;
LABEL_85:
        if ( v6[1] > v7 )
          return -34;
        return Int64;
      case 0x10u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 2006));
        goto LABEL_83;
      case 0x11u:
        if ( (*(_DWORD *)(v4 + 2014) & 0x8000) == 0 )
          *(_DWORD *)(v4 + 2014) |= 0x8000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 2010));
        goto LABEL_83;
      default:
        Int32 = TdrBuf::SkipField(v6, v23 & 0xF);
        goto LABEL_83;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0018::DoDebugFormat
// Address Name: SUB_1011CE70
// ============================================================
//----- (1011CE70) --------------------------------------------------------
int __thiscall sub_1011CE70(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1011CF20(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0018::DebugFormat
// Address Name: SUB_1011CF20
// ============================================================
//----- (1011CF20) --------------------------------------------------------
int __thiscall sub_1011CF20(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // [esp+14h] [ebp+8h]
  int v16; // [esp+14h] [ebp+8h]
  int v17; // [esp+18h] [ebp+Ch]
  int v18; // [esp+18h] [ebp+Ch]
  unsigned __int8 v19; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[wageTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[logTime]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[depotFetchCountTime]", "%u", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[randCommodityTime]", "%u", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[daily3Time]", "%u", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[week3Time]", "%u", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[eliteGuildCount]", "0x%02x", *((unsigned __int8 *)this + 24));
              if ( !result )
              {
                v9 = *((_BYTE *)this + 24);
                if ( v9 > 0xC8u )
                  return -7;
                result = sub_1024A3B0((int)a2, v8, (char)"[eliteGuilds]", v9, 0);
                if ( !result )
                {
                  v10 = 0;
                  v19 = 0;
                  if ( *((_BYTE *)this + 24) )
                  {
                    while ( 1 )
                    {
                      result = Printf(a2, " %I64u", *(_QWORD *)((char *)this + 8 * v10 + 25));
                      if ( result )
                        break;
                      v10 = v19 + 1;
                      v19 = v10;
                      if ( v10 >= *((_BYTE *)this + 24) )
                        goto LABEL_14;
                    }
                  }
                  else
                  {
LABEL_14:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( result )
                      return result;
                    result = print_field(a2, a3, a4, "[commerceCount]", "%d", *(_DWORD *)((char *)this + 1625));
                    if ( result )
                      return result;
                    v11 = *(_DWORD *)((char *)this + 1625);
                    if ( v11 < 0 )
                      return -6;
                    if ( v11 > 10 )
                      return -7;
                    v12 = 0;
                    v15 = 0;
                    if ( v11 > 0 )
                    {
                      v17 = (int)this + 1629;
                      do
                      {
                        result = sub_1024A230((int)a2, a4, (char)"[commerceInfo]", v12);
                        if ( result )
                          return result;
                        result = a3 >= 0 ? sub_1011A400(a2, a3 + 1, a4) : sub_1011A400(a2, a3, a4);
                        if ( result )
                          return result;
                        v17 += 16;
                        v12 = v15 + 1;
                        v15 = v12;
                      }
                      while ( v12 < *(_DWORD *)((char *)this + 1625) );
                    }
                    result = print_field(a2, a3, a4, "[dragonBoatCount]", "0x%02x", *((unsigned __int8 *)this + 1789));
                    if ( result )
                      return result;
                    result = print_structure((int)a2, a3, a4, (int)"[dragonBoatInfo]");
                    if ( result )
                      return result;
                    v13 = (_DWORD *)((char *)this + 1790);
                    result = a3 >= 0 ? sub_1011B670(v13, a2, a3 + 1, a4) : sub_1011B670(v13, a2, a3, a4);
                    if ( result )
                      return result;
                    result = print_field(a2, a3, a4, "[guildWarHistoryCount]", "%d", *(_DWORD *)((char *)this + 1862));
                    if ( result )
                      return result;
                    v14 = *(_DWORD *)((char *)this + 1862);
                    if ( v14 < 0 )
                      return -6;
                    if ( v14 > 7 )
                      return -7;
                    v16 = 0;
                    if ( v14 <= 0 )
                    {
LABEL_44:
                      result = print_field(
                                 a2,
                                 a3,
                                 a4,
                                 "[guildWarDailyRefreshTimestamp]",
                                 "%d",
                                 *(_DWORD *)((char *)this + 2006));
                      if ( !result )
                        return print_field(
                                 a2,
                                 a3,
                                 a4,
                                 "[guildWarWeeklyRefreshTimestamp]",
                                 "%d",
                                 *(_DWORD *)((char *)this + 2010));
                    }
                    else
                    {
                      v18 = (int)this + 1866;
                      while ( 1 )
                      {
                        result = sub_1024A230((int)a2, a4, (char)"[guildWarHistoryInfo]", result);
                        if ( result )
                          break;
                        result = a3 >= 0 ? sub_10119DC0(a2, a3 + 1, a4) : sub_10119DC0(a2, a3, a4);
                        if ( result )
                          break;
                        v18 += 20;
                        result = v16 + 1;
                        v16 = result;
                        if ( result >= *(_DWORD *)((char *)this + 1862) )
                          goto LABEL_44;
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
// 1011D040: variable 'v8' is possibly undefined
// 10119DC0: using guessed type _DWORD __stdcall sub_10119DC0(_DWORD, _DWORD, _DWORD);
// 1011A400: using guessed type _DWORD __stdcall sub_1011A400(_DWORD, _DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10119B50
// ============================================================
//----- (10119B50) --------------------------------------------------------
int __thiscall sub_10119B50(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarULong; // eax
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
          VarULong = TdrBuf::ReadVarULong(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarULong = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        default:
          VarULong = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarULong;
      if ( VarULong )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B300
// ============================================================
//----- (1011B300) --------------------------------------------------------
int __thiscall sub_1011B300(_DWORD *this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(this + 17) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
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
            if ( (*(_BYTE *)(this + 17) & 1) == 0 )
              *(this + 17) |= 1u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this);
            goto LABEL_22;
          case 2u:
            if ( (*(this + 17) & 2) == 0 )
              *(this + 17) |= 2u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 1);
            goto LABEL_22;
          case 3u:
            if ( (*(this + 17) & 4) == 0 )
              *(this + 17) |= 4u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 2);
            goto LABEL_22;
          case 4u:
            if ( (*(this + 17) & 8) == 0 )
              *(this + 17) |= 8u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 3);
            goto LABEL_22;
          case 5u:
            if ( (*(this + 17) & 0x10) == 0 )
              *(this + 17) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            VarUInt = sub_1011A940(this + 4, v4, a2);
LABEL_22:
            v6 = VarUInt;
            if ( VarUInt )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            VarUInt = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011A1C0
// ============================================================
//----- (1011A1C0) --------------------------------------------------------
int __thiscall sub_1011A1C0(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
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
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 3) & 1) == 0 )
          *(this + 3) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 3) & 2) == 0 )
          *(this + 3) |= 2u;
        VarUInt = TdrBuf::ReadVarULong(a2, this + 1);
      }
      else
      {
        VarUInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUInt;
      if ( VarUInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10119C20
// ============================================================
//----- (10119C20) --------------------------------------------------------
int __thiscall sub_10119C20(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1011A260
// ============================================================
//----- (1011A260) --------------------------------------------------------
int __thiscall sub_1011A260(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 12) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] >= v5 )
  {
LABEL_14:
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
      if ( v8 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 12) & 1) == 0 )
          *(_DWORD *)(this + 12) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 12) & 2) == 0 )
          *(_DWORD *)(this + 12) |= 2u;
        Int32 = TdrBuf::ReadInt64(a2, (_BYTE *)(this + 4));
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B450
// ============================================================
//----- (1011B450) --------------------------------------------------------
int __thiscall sub_1011B450(int this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 68) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
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
            if ( (*(_BYTE *)(this + 68) & 1) == 0 )
              *(_DWORD *)(this + 68) |= 1u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
            goto LABEL_22;
          case 2u:
            if ( (*(_DWORD *)(this + 68) & 2) == 0 )
              *(_DWORD *)(this + 68) |= 2u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
            goto LABEL_22;
          case 3u:
            if ( (*(_DWORD *)(this + 68) & 4) == 0 )
              *(_DWORD *)(this + 68) |= 4u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
            goto LABEL_22;
          case 4u:
            if ( (*(_DWORD *)(this + 68) & 8) == 0 )
              *(_DWORD *)(this + 68) |= 8u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 12));
            goto LABEL_22;
          case 5u:
            if ( (*(_DWORD *)(this + 68) & 0x10) == 0 )
              *(_DWORD *)(this + 68) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            Int32 = sub_1011AAE0((unsigned int *)(this + 16), v4, a2);
LABEL_22:
            v6 = Int32;
            if ( Int32 )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
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
// Address Name: SUB_1011B670
// ============================================================
//----- (1011B670) --------------------------------------------------------
int __thiscall sub_1011B670(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commerceBoatId]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[commerceBoatStartTime]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[commerceBoatStatus]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[levelId]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[grabInfo]");
          if ( !result )
          {
            if ( a3 >= 0 )
              return sub_1011AD50(a2, a3 + 1, a4);
            else
              return sub_1011AD50(a2, a3, a4);
          }
        }
      }
    }
  }
  return result;
}
// 1011AD50: using guessed type _DWORD __stdcall sub_1011AD50(_DWORD, _DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011A400
// ============================================================
//----- (1011A400) --------------------------------------------------------
int __thiscall sub_1011A400(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commerceId]", "%u", *(_DWORD *)this);
  if ( !result )
    return print_field(a2, a3, a4, "[ownGuildId]", "%I64u", *(_QWORD *)(this + 4));
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
// Address Name: SUB_10119DC0
// ============================================================
//----- (10119DC0) --------------------------------------------------------
int __thiscall sub_10119DC0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[guildId]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[commerceId]", "%d", *(this + 2));
    if ( !result )
      return print_field(a2, a3, a4, "[activityStartTime]", "%d", *(this + 3));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011A940
// ============================================================
//----- (1011A940) --------------------------------------------------------
int __thiscall sub_1011A940(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int VarULong; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarULong = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          VarULong = TdrBuf::ReadVarULong(v12, v11);
          if ( VarULong )
            return VarULong;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 2;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return VarULong;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        VarUInt = TdrBuf::ReadVarULong(v4, v5 + 9);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5 + 11);
        goto LABEL_25;
      default:
        VarUInt = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        VarULong = VarUInt;
        if ( !VarUInt )
          goto LABEL_26;
        return VarULong;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011AAE0
// ============================================================
//----- (1011AAE0) --------------------------------------------------------
int __thiscall sub_1011AAE0(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int Int64; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // edi
  _BYTE *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int64 = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          Int64 = TdrBuf::ReadInt64(v12, v11);
          if ( Int64 )
            return Int64;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 8;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return Int64;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        Int32 = TdrBuf::ReadInt64(v4, (_BYTE *)v5 + 36);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 44);
        goto LABEL_25;
      default:
        Int32 = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_26;
        return Int64;
    }
  }
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
// Address Name: SUB_1011AD50
// ============================================================
//----- (1011AD50) --------------------------------------------------------
int __thiscall sub_1011AD50(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // esi
  int result; // eax
  int v7; // ecx
  unsigned int v8; // edi
  _QWORD *v9; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[playerCount]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 4 )
    {
      result = sub_1024A3B0(a2, a3, v7, "[playerId]", *this);
      if ( !result )
      {
        v8 = 0;
        if ( *this )
        {
          v9 = this + 1;
          while ( 1 )
          {
            result = Printf(a2, " %I64u", *v9);
            if ( result )
              break;
            ++v8;
            ++v9;
            if ( v8 >= *this )
            {
              v4 = a2;
              goto LABEL_10;
            }
          }
        }
        else
        {
LABEL_10:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            result = print_field(v4, a3, a4, "[ownGuildId]", "%I64u", *(_QWORD *)(this + 9));
            if ( !result )
              return print_field(v4, a3, a4, "[minTime]", "%u", *(this + 11));
          }
        }
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}
// 1011AD9F: variable 'v7' is possibly undefined



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



