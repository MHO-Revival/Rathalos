// ============================================================
// Name: TLV::UnkTlv0217::Read
// Address Name: SUB_102047B0
// ============================================================
//----- (102047B0) --------------------------------------------------------
int __thiscall sub_102047B0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10204880((int)this, &v9, v8);
  else
    result = sub_10205140((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0217::Read_0xAA
// Address Name: SUB_10204880
// ============================================================
//----- (10204880) --------------------------------------------------------
int __thiscall sub_10204880(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int result; // eax
  unsigned int v5; // ecx
  int *v6; // eax
  int v7; // edi
  unsigned int v8; // edx
  int v9; // edi
  unsigned int v10; // edx
  unsigned int v11; // edi
  int v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edi
  int v15; // ebx
  unsigned int v16; // edx
  unsigned int v17; // edi
  char *v18; // ebx
  unsigned int v19; // edx
  __int16 v20; // di
  unsigned int v21; // edx
  __int16 v22; // di
  unsigned int v23; // edx
  int v25; // [esp+14h] [ebp-14h] BYREF
  unsigned int v26; // [esp+18h] [ebp-10h] BYREF
  int v27; // [esp+1Ch] [ebp-Ch] BYREF
  int v28; // [esp+20h] [ebp-8h]
  unsigned int v29; // [esp+24h] [ebp-4h]

  v3 = this;
  result = 0;
  *(_DWORD *)(this + 61917) = 0;
  v5 = a2[1] + a3;
  v26 = 0;
  v29 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_72;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v26);
    if ( result )
      return result;
    switch ( v26 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v3 + 61917) & 1) == 0 )
          *(_DWORD *)(v3 + 61917) |= 1u;
        result = TdrBuf::ReadVarInt(a2, (int *)v3);
        if ( !result )
          goto LABEL_71;
        return result;
      case 3u:
        if ( (*(_DWORD *)(v3 + 61917) & 2) == 0 )
          *(_DWORD *)(v3 + 61917) |= 2u;
        v6 = (int *)(v3 + 4);
        goto LABEL_11;
      case 4u:
        if ( (*(_DWORD *)(v3 + 61917) & 4) == 0 )
          *(_DWORD *)(v3 + 61917) |= 4u;
        result = TdrBuf::ReadVarULong(a2, (_DWORD *)(v3 + 8));
        if ( !result )
          goto LABEL_71;
        return result;
      case 5u:
        if ( (*(_DWORD *)(v3 + 61917) & 8) == 0 )
          *(_DWORD *)(v3 + 61917) |= 8u;
        v6 = (int *)(v3 + 16);
        goto LABEL_11;
      case 6u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x10) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x10u;
        v6 = (int *)(v3 + 20);
        goto LABEL_11;
      case 7u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x20) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x20u;
        v6 = (int *)(v3 + 24);
        goto LABEL_11;
      case 8u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x40) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x40u;
        v6 = (int *)(v3 + 28);
        goto LABEL_11;
      case 9u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x80) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x80u;
        v6 = (int *)(v3 + 32);
        goto LABEL_11;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x100) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x100u;
        v6 = (int *)(v3 + 36);
        goto LABEL_11;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x200) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x200u;
        v6 = (int *)(v3 + 40);
        goto LABEL_11;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x400) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x400u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v7 = 0;
        v27 = a2[1];
        while ( 1 )
        {
          result = sub_10151B00(a2, (_BYTE *)(v3 + v7 + 44));
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v27 + v25 )
            return -34;
          if ( v8 != v27 + v25 && (unsigned int)++v7 < 4 )
            continue;
          goto LABEL_71;
        }
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x800) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x800u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v9 = 0;
        v27 = a2[1];
        while ( 1 )
        {
          result = sub_10151B00(a2, (_BYTE *)(v3 + v9 + 48));
          if ( result )
            return result;
          v10 = a2[1];
          if ( v10 > v27 + v25 )
            return -34;
          if ( v10 != v27 + v25 && (unsigned int)++v9 < 2 )
            continue;
          goto LABEL_71;
        }
      case 0xEu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x1000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v11 = 0;
        v28 = a2[1];
        v12 = v3 + 50;
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_101FF2E0(v12, a2, v27);
            if ( result )
              return result;
          }
          v13 = a2[1];
          if ( v13 > v28 + v25 )
            return -34;
          if ( v13 != v28 + v25 )
          {
            ++v11;
            v12 += 22;
            if ( v11 < 6 )
              continue;
          }
          goto LABEL_70;
        }
      case 0xFu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x2000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x2000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v14 = 0;
        v28 = a2[1];
        v15 = v3 + 182;
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_101FFAD0(v15, a2, v27);
            if ( result )
              return result;
          }
          v16 = a2[1];
          if ( v16 > v28 + v25 )
            return -34;
          if ( v16 != v28 + v25 )
          {
            ++v14;
            v15 += 6;
            if ( v14 < 6 )
              continue;
          }
          goto LABEL_70;
        }
      case 0x10u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x4000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x4000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v17 = 0;
        v28 = a2[1];
        v18 = (char *)(v3 + 218);
        do
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_10200180(v18, a2, v27);
            if ( result )
              return result;
          }
          v19 = a2[1];
          if ( v19 > v28 + v25 )
            return -34;
          if ( v19 == v28 + v25 )
            break;
          ++v17;
          v18 += 13;
        }
        while ( v17 < 3 );
LABEL_70:
        v3 = this;
        goto LABEL_71;
      case 0x11u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x8000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x8000u;
        v6 = (int *)(v3 + 257);
        goto LABEL_11;
      case 0x12u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x10000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x10000u;
        v6 = (int *)(v3 + 261);
        goto LABEL_11;
      case 0x13u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x20000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x20000u;
        result = sub_10151B00(a2, (_BYTE *)(v3 + 265));
        goto LABEL_12;
      case 0x14u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x40000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x40000u;
        result = TdrBuf::ReadVarUShort(a2, (_WORD *)(v3 + 266));
        goto LABEL_12;
      case 0x15u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x80000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x80000u;
        v6 = (int *)(v3 + 268);
LABEL_11:
        result = TdrBuf::ReadVarInt(a2, v6);
        goto LABEL_12;
      case 0x16u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x100000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x100000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 272));
        goto LABEL_12;
      case 0x17u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x200000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x200000u;
        result = TdrBuf::ReadVarShort(a2, (_WORD *)(v3 + 273));
        goto LABEL_12;
      case 0x18u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x400000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x400000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v20 = 0;
        v28 = a2[1];
        while ( 2 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_102009C0(v3 + 41 * v20 + 275, a2, v27);
            if ( result )
              return result;
          }
          v21 = a2[1];
          if ( v21 > v28 + v25 )
            return -34;
          if ( v21 != v28 + v25 )
          {
            if ( ++v20 >= 30 )
              goto LABEL_71;
            continue;
          }
          break;
        }
        *(_WORD *)(v3 + 273) = v20 + 1;
        goto LABEL_71;
      case 0x19u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x800000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x800000u;
        result = TdrBuf::ReadVarShort(a2, (_WORD *)(v3 + 1505));
        goto LABEL_12;
      case 0x1Au:
        if ( (*(_DWORD *)(v3 + 61917) & 0x1000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x1000000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v22 = 0;
        v28 = a2[1];
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_10202EE0(v3 + 5034 * v22 + 1507, a2, v27);
            if ( result )
              return result;
          }
          v23 = a2[1];
          if ( v23 > v28 + v25 )
            return -34;
          if ( v23 == v28 + v25 )
            break;
          if ( ++v22 >= 12 )
            goto LABEL_71;
        }
        *(_WORD *)(v3 + 1505) = v22 + 1;
LABEL_71:
        v5 = v29;
        if ( a2[1] < v29 )
          continue;
LABEL_72:
        if ( a2[1] > v5 )
          return -34;
        return result;
      case 0x1Bu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x2000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x2000000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 61915));
        goto LABEL_12;
      case 0x1Cu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x4000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x4000000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 61916));
        goto LABEL_12;
      default:
        result = TdrBuf::SkipField(a2, v26 & 0xF);
LABEL_12:
        if ( !result )
          goto LABEL_71;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0217::Read_0x99
// Address Name: SUB_10205140
// ============================================================
//----- (10205140) --------------------------------------------------------
int __thiscall sub_10205140(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int result; // eax
  unsigned int v5; // ecx
  _BYTE *v6; // eax
  int v7; // edi
  unsigned int v8; // edx
  int v9; // edi
  unsigned int v10; // edx
  unsigned int v11; // edi
  int v12; // ebx
  unsigned int v13; // edx
  unsigned int v14; // edi
  char *v15; // ebx
  unsigned int v16; // edx
  unsigned int v17; // edi
  char *v18; // ebx
  unsigned int v19; // edx
  __int16 v20; // di
  unsigned int v21; // edx
  __int16 v22; // di
  unsigned int v23; // edx
  int v25; // [esp+14h] [ebp-14h] BYREF
  unsigned int v26; // [esp+18h] [ebp-10h] BYREF
  int v27; // [esp+1Ch] [ebp-Ch] BYREF
  int v28; // [esp+20h] [ebp-8h]
  unsigned int v29; // [esp+24h] [ebp-4h]

  v3 = this;
  result = 0;
  *(_DWORD *)(this + 61917) = 0;
  v5 = a2[1] + a3;
  v26 = 0;
  v29 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_72;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v26);
    if ( result )
      return result;
    switch ( v26 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v3 + 61917) & 1) == 0 )
          *(_DWORD *)(v3 + 61917) |= 1u;
        result = TdrBuf::ReadInt32(a2, (_BYTE *)v3);
        if ( !result )
          goto LABEL_71;
        return result;
      case 3u:
        if ( (*(_DWORD *)(v3 + 61917) & 2) == 0 )
          *(_DWORD *)(v3 + 61917) |= 2u;
        v6 = (_BYTE *)(v3 + 4);
        goto LABEL_11;
      case 4u:
        if ( (*(_DWORD *)(v3 + 61917) & 4) == 0 )
          *(_DWORD *)(v3 + 61917) |= 4u;
        result = TdrBuf::ReadInt64(a2, (_BYTE *)(v3 + 8));
        if ( !result )
          goto LABEL_71;
        return result;
      case 5u:
        if ( (*(_DWORD *)(v3 + 61917) & 8) == 0 )
          *(_DWORD *)(v3 + 61917) |= 8u;
        v6 = (_BYTE *)(v3 + 16);
        goto LABEL_11;
      case 6u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x10) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x10u;
        v6 = (_BYTE *)(v3 + 20);
        goto LABEL_11;
      case 7u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x20) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x20u;
        v6 = (_BYTE *)(v3 + 24);
        goto LABEL_11;
      case 8u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x40) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x40u;
        v6 = (_BYTE *)(v3 + 28);
        goto LABEL_11;
      case 9u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x80) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x80u;
        v6 = (_BYTE *)(v3 + 32);
        goto LABEL_11;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x100) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x100u;
        v6 = (_BYTE *)(v3 + 36);
        goto LABEL_11;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x200) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x200u;
        v6 = (_BYTE *)(v3 + 40);
        goto LABEL_11;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x400) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x400u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v7 = 0;
        v27 = a2[1];
        while ( 1 )
        {
          result = sub_10151B00(a2, (_BYTE *)(v3 + v7 + 44));
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v27 + v25 )
            return -34;
          if ( v8 != v27 + v25 && (unsigned int)++v7 < 4 )
            continue;
          goto LABEL_71;
        }
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x800) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x800u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v9 = 0;
        v27 = a2[1];
        while ( 1 )
        {
          result = sub_10151B00(a2, (_BYTE *)(v3 + v9 + 48));
          if ( result )
            return result;
          v10 = a2[1];
          if ( v10 > v27 + v25 )
            return -34;
          if ( v10 != v27 + v25 && (unsigned int)++v9 < 2 )
            continue;
          goto LABEL_71;
        }
      case 0xEu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x1000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v11 = 0;
        v28 = a2[1];
        v12 = v3 + 50;
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_101FF430(v12, a2, v27);
            if ( result )
              return result;
          }
          v13 = a2[1];
          if ( v13 > v28 + v25 )
            return -34;
          if ( v13 != v28 + v25 )
          {
            ++v11;
            v12 += 22;
            if ( v11 < 6 )
              continue;
          }
          goto LABEL_70;
        }
      case 0xFu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x2000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x2000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v14 = 0;
        v28 = a2[1];
        v15 = (char *)(v3 + 182);
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_101FFB50(v15, a2, v27);
            if ( result )
              return result;
          }
          v16 = a2[1];
          if ( v16 > v28 + v25 )
            return -34;
          if ( v16 != v28 + v25 )
          {
            ++v14;
            v15 += 6;
            if ( v14 < 6 )
              continue;
          }
          goto LABEL_70;
        }
      case 0x10u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x4000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x4000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v17 = 0;
        v28 = a2[1];
        v18 = (char *)(v3 + 218);
        do
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_10200290(v18, a2, v27);
            if ( result )
              return result;
          }
          v19 = a2[1];
          if ( v19 > v28 + v25 )
            return -34;
          if ( v19 == v28 + v25 )
            break;
          ++v17;
          v18 += 13;
        }
        while ( v17 < 3 );
LABEL_70:
        v3 = this;
        goto LABEL_71;
      case 0x11u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x8000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x8000u;
        v6 = (_BYTE *)(v3 + 257);
        goto LABEL_11;
      case 0x12u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x10000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x10000u;
        v6 = (_BYTE *)(v3 + 261);
        goto LABEL_11;
      case 0x13u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x20000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x20000u;
        result = sub_10151B00(a2, (_BYTE *)(v3 + 265));
        goto LABEL_12;
      case 0x14u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x40000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x40000u;
        result = TdrBuf::ReadInt16(a2, (_BYTE *)(v3 + 266));
        goto LABEL_12;
      case 0x15u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x80000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x80000u;
        v6 = (_BYTE *)(v3 + 268);
LABEL_11:
        result = TdrBuf::ReadInt32(a2, v6);
        goto LABEL_12;
      case 0x16u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x100000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x100000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 272));
        goto LABEL_12;
      case 0x17u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x200000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x200000u;
        result = TdrBuf::ReadInt16(a2, (_BYTE *)(v3 + 273));
        goto LABEL_12;
      case 0x18u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x400000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x400000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v20 = 0;
        v28 = a2[1];
        while ( 2 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_10200B70(v3 + 41 * v20 + 275, a2, v27);
            if ( result )
              return result;
          }
          v21 = a2[1];
          if ( v21 > v28 + v25 )
            return -34;
          if ( v21 != v28 + v25 )
          {
            if ( ++v20 >= 30 )
              goto LABEL_71;
            continue;
          }
          break;
        }
        *(_WORD *)(v3 + 273) = v20 + 1;
        goto LABEL_71;
      case 0x19u:
        if ( (*(_DWORD *)(v3 + 61917) & 0x800000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x800000u;
        result = TdrBuf::ReadInt16(a2, (_BYTE *)(v3 + 1505));
        goto LABEL_12;
      case 0x1Au:
        if ( (*(_DWORD *)(v3 + 61917) & 0x1000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x1000000u;
        v25 = 0;
        result = TdrBuf::ReadInt32(a2, &v25);
        if ( result )
          return result;
        if ( !v25 )
          return -37;
        v22 = 0;
        v28 = a2[1];
        while ( 1 )
        {
          v27 = 0;
          result = TdrBuf::ReadInt32(a2, &v27);
          if ( result )
            return result;
          if ( v27 )
          {
            result = sub_102030F0(v3 + 5034 * v22 + 1507, a2, v27);
            if ( result )
              return result;
          }
          v23 = a2[1];
          if ( v23 > v28 + v25 )
            return -34;
          if ( v23 == v28 + v25 )
            break;
          if ( ++v22 >= 12 )
            goto LABEL_71;
        }
        *(_WORD *)(v3 + 1505) = v22 + 1;
LABEL_71:
        v5 = v29;
        if ( a2[1] < v29 )
          continue;
LABEL_72:
        if ( a2[1] > v5 )
          return -34;
        return result;
      case 0x1Bu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x2000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x2000000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 61915));
        goto LABEL_12;
      case 0x1Cu:
        if ( (*(_DWORD *)(v3 + 61917) & 0x4000000) == 0 )
          *(_DWORD *)(v3 + 61917) |= 0x4000000u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(v3 + 61916));
        goto LABEL_12;
      default:
        result = TdrBuf::SkipField(a2, v26 & 0xF);
LABEL_12:
        if ( !result )
          goto LABEL_71;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0217::DoDebugFormat
// Address Name: SUB_10205A20
// ============================================================
//----- (10205A20) --------------------------------------------------------
int __thiscall sub_10205A20(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10205AD0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0217::DebugFormat
// Address Name: SUB_10205AD0
// ============================================================
//----- (10205AD0) --------------------------------------------------------
int __thiscall sub_10205AD0(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  char *v9; // eax
  int v10; // ecx
  unsigned int v11; // ecx
  char *v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  char *v16; // eax
  __int16 v17; // dx
  int v18; // ecx
  char *v19; // eax
  __int16 v20; // dx
  int v21; // ecx
  int v23; // [esp+1Ch] [ebp+Ch]
  int v24; // [esp+1Ch] [ebp+Ch]
  int v25; // [esp+1Ch] [ebp+Ch]
  int v26; // [esp+1Ch] [ebp+Ch]
  int v27; // [esp+1Ch] [ebp+Ch]
  int v28; // [esp+20h] [ebp+10h]
  int v29; // [esp+20h] [ebp+10h]
  _DWORD *v30; // [esp+20h] [ebp+10h]
  __int16 *v31; // [esp+20h] [ebp+10h]
  char *v32; // [esp+20h] [ebp+10h]
  int v33; // [esp+20h] [ebp+10h]
  int v34; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[farmID]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[ownerUID]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[ownerDBID]", "%I64u", *((_QWORD *)this + 1));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[remark]", "%d", *((_DWORD *)this + 4));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[credit]", "%d", *((_DWORD *)this + 5));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[hits]", "%d", *((_DWORD *)this + 6));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[currentHits]", "%d", *((_DWORD *)this + 7));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[maxGatherCount]", "%d", *((_DWORD *)this + 8));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[autoGatherPetID]", "%d", *((_DWORD *)this + 9));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[autoGatherBCPType]", "%d", *((_DWORD *)this + 10));
                    if ( !result )
                    {
                      result = sub_1024A3B0(a2, a3, v7, "[sACPOpen]", 4);
                      if ( !result )
                      {
                        v8 = 0;
                        v9 = this + 44;
                        v28 = 0;
                        do
                        {
                          result = Printf(a2, " 0x%02x", v9[v8]);
                          if ( result )
                            return result;
                          v9 = this + 44;
                          v8 = v28 + 1;
                          v28 = v8;
                        }
                        while ( v8 < 4 );
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( !result )
                        {
                          result = sub_1024A3B0(a2, a3, v10, "[sOFOpen]", 2);
                          if ( !result )
                          {
                            v11 = 0;
                            v12 = this + 48;
                            v29 = 0;
                            do
                            {
                              result = Printf(a2, " 0x%02x", v12[v11]);
                              if ( result )
                                return result;
                              v12 = this + 48;
                              v11 = v29 + 1;
                              v29 = v11;
                            }
                            while ( v11 < 2 );
                            result = TdrBuf::WriteChar(a2, a4);
                            if ( !result )
                            {
                              v13 = 0;
                              v23 = 0;
                              v30 = this + 50;
                              do
                              {
                                result = sub_1024A230(a2, a3, a4, "[sBCPData]", v13);
                                if ( result )
                                  return result;
                                result = a3 >= 0 ? sub_101FF650(v30, a2, a3 + 1, a4) : sub_101FF650(v30, a2, a3, a4);
                                if ( result )
                                  return result;
                                v30 = (_DWORD *)((char *)v30 + 22);
                                v13 = v23 + 1;
                                v23 = v13;
                              }
                              while ( v13 < 6 );
                              v14 = 0;
                              v24 = 0;
                              v31 = (__int16 *)(this + 182);
                              do
                              {
                                result = sub_1024A230(a2, a3, a4, "[sPFData]", v14);
                                if ( result )
                                  return result;
                                result = a3 >= 0 ? sub_101FFD00(v31, a2, a3 + 1, a4) : sub_101FFD00(v31, a2, a3, a4);
                                if ( result )
                                  return result;
                                v31 += 3;
                                v14 = v24 + 1;
                                v24 = v14;
                              }
                              while ( v14 < 6 );
                              v15 = 0;
                              v25 = 0;
                              v32 = this + 218;
                              do
                              {
                                result = sub_1024A230(a2, a3, a4, "[sPlowLandData]", v15);
                                if ( result )
                                  return result;
                                result = a3 >= 0 ? sub_10200470(v32, a2, a3 + 1, a4) : sub_10200470(v32, a2, a3, a4);
                                if ( result )
                                  return result;
                                v32 += 13;
                                v15 = v25 + 1;
                                v25 = v15;
                              }
                              while ( v15 < 3 );
                              result = print_field(a2, a3, a4, "[lastFarmRefreshTime]", "%d", *(_DWORD *)(this + 257));
                              if ( !result )
                              {
                                result = print_field(
                                           a2,
                                           a3,
                                           a4,
                                           "[farmCanBeGatheredCount]",
                                           "%d",
                                           *(_DWORD *)(this + 261));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[friendGatherBonus]", "0x%02x", *(this + 265));
                                  if ( !result )
                                  {
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[safeDataFlag]",
                                               "%d",
                                               *((unsigned __int16 *)this + 133));
                                    if ( !result )
                                    {
                                      result = print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[facilityUseFlag]",
                                                 "%d",
                                                 *((_DWORD *)this + 67));
                                      if ( !result )
                                      {
                                        result = print_field(
                                                   a2,
                                                   a3,
                                                   a4,
                                                   "[farmOpenFlag]",
                                                   "%d",
                                                   (unsigned __int8)*(this + 272));
                                        if ( !result )
                                        {
                                          result = print_field(
                                                     a2,
                                                     a3,
                                                     a4,
                                                     "[petAvatarCount]",
                                                     "%d",
                                                     *(__int16 *)(this + 273));
                                          if ( !result )
                                          {
                                            v16 = this;
                                            v17 = *(_WORD *)(this + 273);
                                            if ( v17 < 0 )
                                              return -6;
                                            if ( v17 > 30 )
                                              return -7;
                                            LOWORD(v18) = 0;
                                            v26 = 0;
                                            if ( v17 <= 0 )
                                            {
LABEL_60:
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[equipShowCount]",
                                                         "%d",
                                                         *(__int16 *)(v16 + 1505));
                                              if ( !result )
                                              {
                                                v19 = this;
                                                v20 = *(_WORD *)(this + 1505);
                                                if ( v20 < 0 )
                                                  return -6;
                                                if ( v20 > 12 )
                                                  return -7;
                                                LOWORD(v21) = 0;
                                                v27 = 0;
                                                if ( v20 <= 0 )
                                                {
LABEL_70:
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[gender]",
                                                             "0x%02x",
                                                             (unsigned __int8)v19[61915]);
                                                  if ( !result )
                                                    return print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[skipCutScene]",
                                                             "%d",
                                                             (unsigned __int8)*(this + 61916));
                                                }
                                                else
                                                {
                                                  while ( 1 )
                                                  {
                                                    v34 = (__int16)v21;
                                                    result = sub_1024A230(a2, a3, a4, "[equipShowInfo]", (__int16)v21);
                                                    if ( result )
                                                      break;
                                                    result = a3 >= 0
                                                           ? sub_102033D0(
                                                               (__int16 *)(this + 5034 * v34 + 1507),
                                                               a2,
                                                               a3 + 1,
                                                               a4)
                                                           : sub_102033D0(
                                                               (__int16 *)(this + 5034 * v34 + 1507),
                                                               a2,
                                                               a3,
                                                               a4);
                                                    if ( result )
                                                      break;
                                                    v19 = this;
                                                    v21 = v27 + 1;
                                                    v27 = v21;
                                                    if ( (__int16)v21 >= *(__int16 *)(this + 1505) )
                                                      goto LABEL_70;
                                                  }
                                                }
                                              }
                                            }
                                            else
                                            {
                                              while ( 1 )
                                              {
                                                v33 = (__int16)v18;
                                                result = sub_1024A230(a2, a3, a4, "[petAvatarInfo]", (__int16)v18);
                                                if ( result )
                                                  break;
                                                result = a3 >= 0
                                                       ? sub_10200DF0(this + 41 * v33 + 275, a2, a3 + 1, a4)
                                                       : sub_10200DF0(this + 41 * v33 + 275, a2, a3, a4);
                                                if ( result )
                                                  break;
                                                v16 = this;
                                                v18 = v26 + 1;
                                                v26 = v18;
                                                if ( (__int16)v18 >= *(__int16 *)(this + 273) )
                                                  goto LABEL_60;
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
  }
  return result;
}
// 10205C4F: variable 'v7' is possibly undefined
// 10205CB7: variable 'v10' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102009C0
// ============================================================
//----- (102009C0) --------------------------------------------------------
int __thiscall sub_102009C0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // edi
  int *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 37) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 37) & 1) == 0 )
          *(_DWORD *)(v5 + 37) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 37) & 2) == 0 )
          *(_DWORD *)(v5 + 37) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_7;
      case 3u:
        if ( (*(_DWORD *)(v5 + 37) & 4) == 0 )
          *(_DWORD *)(v5 + 37) |= 4u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v10 = 0;
          v15 = v4[1];
          v11 = (int *)(v17 + 8);
          v12 = a2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadVarInt(v12, v11);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v15 )
              break;
            if ( v13 != a3 + v15 )
            {
              ++v10;
              ++v11;
              if ( v10 < 6 )
                continue;
            }
            v5 = v17;
            v4 = a2;
LABEL_22:
            v7 = v14;
            if ( v4[1] >= v14 )
              goto LABEL_23;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 4u:
        if ( (*(_DWORD *)(v5 + 37) & 8) == 0 )
          *(_DWORD *)(v5 + 37) |= 8u;
        VarInt = sub_10115A30(v4, (_BYTE *)(v5 + 32));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 37) & 0x10) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 33));
        goto LABEL_7;
      default:
        VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_7:
        v6 = VarInt;
        if ( !VarInt )
          goto LABEL_22;
        return v6;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FF2E0
// ============================================================
//----- (101FF2E0) --------------------------------------------------------
int __thiscall sub_101FF2E0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 18) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_25:
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
          if ( (*(_BYTE *)(this + 18) & 1) == 0 )
            *(_DWORD *)(this + 18) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 18) & 2) == 0 )
            *(_DWORD *)(this + 18) |= 2u;
          VarInt = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 18) & 4) == 0 )
            *(_DWORD *)(this + 18) |= 4u;
          VarInt = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 6));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 18) & 8) == 0 )
            *(_DWORD *)(this + 18) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)(this + 8));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 18) & 0x10) == 0 )
            *(_DWORD *)(this + 18) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)(this + 12));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 18) & 0x20) == 0 )
            *(_DWORD *)(this + 18) |= 0x20u;
          VarInt = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 16));
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_25;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10200180
// ============================================================
//----- (10200180) --------------------------------------------------------
int __thiscall sub_10200180(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int *v7; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 != 1 )
        break;
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *this = *(_BYTE *)(v8 + *a2);
      ++a2[1];
LABEL_22:
      if ( a2[1] >= v4 )
      {
        v5 = v4 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
    if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      v7 = (int *)(this + 1);
    }
    else
    {
      if ( v9 >> 4 != 3 )
      {
        result = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_14;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      v7 = (int *)(this + 5);
    }
    result = TdrBuf::ReadVarInt(a2, v7);
LABEL_14:
    if ( result )
      return result;
    goto LABEL_22;
  }
  return v5 ? 0xFFFFFFDE : 0;
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
// Address Name: SUB_101FFAD0
// ============================================================
//----- (101FFAD0) --------------------------------------------------------
int __thiscall sub_101FFAD0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarShort; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
      }
      else
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = VarShort;
      if ( VarShort )
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
// Address Name: SUB_10202EE0
// ============================================================
//----- (10202EE0) --------------------------------------------------------
int __thiscall sub_10202EE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarShort; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // esi
  int *v10; // ebx
  unsigned int v11; // edx
  _DWORD *v12; // ebx
  int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarShort = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 5030) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_19;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5030) & 1) == 0 )
          *(_DWORD *)(this + 5030) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)this);
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
      case 2u:
        if ( (*(_DWORD *)(this + 5030) & 2) == 0 )
          *(_DWORD *)(this + 5030) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        a3 = v6[1];
        v10 = (int *)(this + 2);
        while ( 1 )
        {
          VarShort = TdrBuf::ReadVarInt(v6, v10);
          if ( VarShort )
            return VarShort;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v9;
            ++v10;
            if ( v9 < 6 )
              continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (*(_DWORD *)(this + 5030) & 4) == 0 )
          *(_DWORD *)(this + 5030) |= 4u;
        VarShort = TdrBuf::ReadVarInt(v6, (int *)(this + 26));
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
      case 4u:
        if ( (*(_DWORD *)(this + 5030) & 8) == 0 )
          *(_DWORD *)(this + 5030) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v12 = a2;
        if ( !a2 )
          return -37;
        v13 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarShort = TdrBuf::ReadByte(v6, (_BYTE *)(v13 + v17 + 30));
          if ( VarShort )
            return VarShort;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v12) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v12) )
            break;
          if ( ++v13 >= 5000 )
          {
LABEL_17:
            this = v17;
            goto LABEL_18;
          }
        }
        this = v17;
        *(_DWORD *)(v17 + 26) = v13 + 1;
LABEL_18:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_19:
        if ( v6[1] > v7 )
          return -34;
        return VarShort;
      default:
        VarShort = TdrBuf::SkipField(v6, v16 & 0xF);
        if ( VarShort )
          return VarShort;
        goto LABEL_18;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FF430
// ============================================================
//----- (101FF430) --------------------------------------------------------
int __thiscall sub_101FF430(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 18) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_25:
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
          if ( (*(_BYTE *)(this + 18) & 1) == 0 )
            *(_DWORD *)(this + 18) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 18) & 2) == 0 )
            *(_DWORD *)(this + 18) |= 2u;
          Int32 = TdrBuf::ReadInt16(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 18) & 4) == 0 )
            *(_DWORD *)(this + 18) |= 4u;
          Int32 = TdrBuf::ReadInt16(a2, (_BYTE *)(this + 6));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 18) & 8) == 0 )
            *(_DWORD *)(this + 18) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 18) & 0x10) == 0 )
            *(_DWORD *)(this + 18) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 18) & 0x20) == 0 )
            *(_DWORD *)(this + 18) |= 0x20u;
          Int32 = TdrBuf::ReadInt16(a2, (_BYTE *)(this + 16));
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
        goto LABEL_25;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102030F0
// ============================================================
//----- (102030F0) --------------------------------------------------------
int __thiscall sub_102030F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int Int16; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // esi
  _BYTE *v10; // ebx
  unsigned int v11; // edx
  _DWORD *v12; // ebx
  int v13; // esi
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  Int16 = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 5030) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_19;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5030) & 1) == 0 )
          *(_DWORD *)(this + 5030) |= 1u;
        Int16 = TdrBuf::ReadInt16(v6, (_BYTE *)this);
        if ( Int16 )
          return Int16;
        goto LABEL_18;
      case 2u:
        if ( (*(_DWORD *)(this + 5030) & 2) == 0 )
          *(_DWORD *)(this + 5030) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        a3 = v6[1];
        v10 = (_BYTE *)(this + 2);
        while ( 1 )
        {
          Int16 = TdrBuf::ReadInt32(v6, v10);
          if ( Int16 )
            return Int16;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v9;
            v10 += 4;
            if ( v9 < 6 )
              continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (*(_DWORD *)(this + 5030) & 4) == 0 )
          *(_DWORD *)(this + 5030) |= 4u;
        Int16 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 26));
        if ( Int16 )
          return Int16;
        goto LABEL_18;
      case 4u:
        if ( (*(_DWORD *)(this + 5030) & 8) == 0 )
          *(_DWORD *)(this + 5030) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v12 = a2;
        if ( !a2 )
          return -37;
        v13 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          Int16 = TdrBuf::ReadByte(v6, (_BYTE *)(v13 + v17 + 30));
          if ( Int16 )
            return Int16;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v12) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v12) )
            break;
          if ( ++v13 >= 5000 )
          {
LABEL_17:
            this = v17;
            goto LABEL_18;
          }
        }
        this = v17;
        *(_DWORD *)(v17 + 26) = v13 + 1;
LABEL_18:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_19:
        if ( v6[1] > v7 )
          return -34;
        return Int16;
      default:
        Int16 = TdrBuf::SkipField(v6, v16 & 0xF);
        if ( Int16 )
          return Int16;
        goto LABEL_18;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10200B70
// ============================================================
//----- (10200B70) --------------------------------------------------------
int __thiscall sub_10200B70(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // edi
  _BYTE *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch]
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 37) = 0;
  v7 = a2[1] + v3;
  v14 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 37) & 1) == 0 )
          *(_DWORD *)(v5 + 37) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 37) & 2) == 0 )
          *(_DWORD *)(v5 + 37) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_7;
      case 3u:
        if ( (*(_DWORD *)(v5 + 37) & 4) == 0 )
          *(_DWORD *)(v5 + 37) |= 4u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( a3 )
        {
          v10 = 0;
          v15 = v4[1];
          v11 = (_BYTE *)(v17 + 8);
          v12 = a2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadInt32(v12, v11);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v15 )
              break;
            if ( v13 != a3 + v15 )
            {
              ++v10;
              v11 += 4;
              if ( v10 < 6 )
                continue;
            }
            v5 = v17;
            v4 = a2;
LABEL_22:
            v7 = v14;
            if ( v4[1] >= v14 )
              goto LABEL_23;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 4u:
        if ( (*(_DWORD *)(v5 + 37) & 8) == 0 )
          *(_DWORD *)(v5 + 37) |= 8u;
        Int32 = sub_10115A30(v4, (_BYTE *)(v5 + 32));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 37) & 0x10) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 33));
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_7:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_22;
        return v6;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10200290
// ============================================================
//----- (10200290) --------------------------------------------------------
int __thiscall sub_10200290(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  _BYTE *v7; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
  v4 = a2[1] + a3;
  v5 = v4 < a2[1];
  if ( v4 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 != 1 )
        break;
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *this = *(_BYTE *)(v8 + *a2);
      ++a2[1];
LABEL_22:
      if ( a2[1] >= v4 )
      {
        v5 = v4 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
    if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      v7 = this + 1;
    }
    else
    {
      if ( v9 >> 4 != 3 )
      {
        result = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_14;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      v7 = this + 5;
    }
    result = TdrBuf::ReadInt32(a2, v7);
LABEL_14:
    if ( result )
      return result;
    goto LABEL_22;
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FFB50
// ============================================================
//----- (101FFB50) --------------------------------------------------------
int __thiscall sub_101FFB50(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 2) = 0;
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
      if ( (*(this + 2) & 1) == 0 )
        *(_DWORD *)(this + 2) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v7 = a2[1];
      if ( (unsigned int)(a2[2] - v7) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v7 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
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
// Address Name: SUB_102033D0
// ============================================================
//----- (102033D0) --------------------------------------------------------
int __thiscall sub_102033D0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned int v6; // esi
  _DWORD *v7; // ebx
  int v8; // ecx
  int v9; // ecx
  int v10; // eax
  int v11; // esi

  result = print_field(a2, a3, a4, "[index]", "%d", *this);
  if ( !result )
  {
    if ( !"[equipID]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s[0 : %I64i]:", "[equipID]", 5LL);
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
          if ( v6 >= 6 )
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
            result = print_field(a2, a3, a4, "[dataLen]", "%d", *(_DWORD *)(this + 13));
            if ( !result )
            {
              v10 = *(_DWORD *)(this + 13);
              if ( v10 >= 0 )
              {
                if ( v10 <= 5000 )
                {
                  result = sub_1024A3B0(a2, a3, v9, "[equipData]", v10);
                  if ( !result )
                  {
                    v11 = 0;
                    if ( *(int *)(this + 13) <= 0 )
                    {
                      return TdrBuf::WriteChar(a2, a4);
                    }
                    else
                    {
                      while ( 1 )
                      {
                        result = Printf(a2, " %d", *((unsigned __int8 *)this + v11 + 30));
                        if ( result )
                          break;
                        if ( ++v11 >= *(_DWORD *)(this + 13) )
                          return TdrBuf::WriteChar(a2, a4);
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
// 10203523: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FF650
// ============================================================
//----- (101FF650) --------------------------------------------------------
int __thiscall sub_101FF650(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[curExp]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[level]", "%d", *((__int16 *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[gatherCount]", "%d", *((__int16 *)this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[lastRefreshTime]", "%d", *(this + 2));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[petID]", "%d", *(this + 3));
          if ( !result )
            return print_field(a2, a3, a4, "[gatherLevel]", "%d", *((__int16 *)this + 8));
        }
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
// Address Name: SUB_10200DF0
// ============================================================
//----- (10200DF0) --------------------------------------------------------
int __thiscall sub_10200DF0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[petID]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[skinID]", "%d", *(this + 1));
    if ( !result )
    {
      result = sub_1024A3B0(a2, a3, v6, "[avatarInfo]", 6);
      if ( !result )
      {
        v7 = 0;
        for ( i = this + 2; ; ++i )
        {
          result = Printf(a2, " %d", *i);
          if ( result )
            break;
          if ( (unsigned int)++v7 >= 6 )
          {
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[sex]", "0x%02x", *((char *)this + 32));
              if ( !result )
                return print_field(a2, a3, a4, "[slot]", "%d", *(_DWORD *)((char *)this + 33));
            }
            return result;
          }
        }
      }
    }
  }
  return result;
}
// 10200E53: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10200470
// ============================================================
//----- (10200470) --------------------------------------------------------
int __thiscall sub_10200470(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[open]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[seedID]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[seedTime]", "%d", *(_DWORD *)(this + 5));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101FFD00
// ============================================================
//----- (101FFD00) --------------------------------------------------------
int __thiscall sub_101FFD00(__int16 *this, _DWORD *a2, int a3, char a4)
{
  return print_field(a2, a3, a4, "[level]", "%d", *this);
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



