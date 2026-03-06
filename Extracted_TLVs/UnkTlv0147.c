// ============================================================
// Name: TLV::UnkTlv0147::Read
// Address Name: SUB_101826E0
// ============================================================
//----- (101826E0) --------------------------------------------------------
int __thiscall sub_101826E0(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  _DWORD *v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = (_DWORD *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_101827B0(this, &v9, v8);
  else
    result = sub_10182E80(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0147::Read_0xAA
// Address Name: SUB_101827B0
// ============================================================
//----- (101827B0) --------------------------------------------------------
int __thiscall sub_101827B0(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int *v14; // eax
  unsigned int v15; // ecx
  int v16; // ebx
  int *v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  int *v20; // eax
  unsigned int v21; // ecx
  int v22; // ebx
  int *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  int *v26; // eax
  unsigned int v27; // ecx
  int v28; // ebx
  int *v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  int *v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // [esp+Ch] [ebp-10h]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  int v38; // [esp+10h] [ebp-Ch]
  int v39; // [esp+10h] [ebp-Ch]
  int v40; // [esp+10h] [ebp-Ch]
  int v41; // [esp+10h] [ebp-Ch]
  int v42; // [esp+10h] [ebp-Ch]
  unsigned int v43; // [esp+14h] [ebp-8h] BYREF
  int *v44; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v44 = this;
  v43 = 0;
  *(this + 255) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v34 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_112;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v43);
    if ( result )
      return result;
    switch ( v43 >> 4 )
    {
      case 1u:
        if ( (v5[255] & 1) == 0 )
          v5[255] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, v5);
        goto LABEL_110;
      case 2u:
        if ( (v5[255] & 2) == 0 )
          v5[255] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v35 = v4[1];
        v11 = v44 + 1;
        a3 = v44 + 1;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v11);
          if ( v6 )
            return v6;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v35) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 3u:
        if ( (v5[255] & 4) == 0 )
          v5[255] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v36 = v4[1];
        v14 = v44 + 21;
        a3 = v44 + 21;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v14);
          if ( v6 )
            return v6;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v36) )
          {
LABEL_17:
            v13 = v10 + 1;
            v5 = v44;
            *v44 = v13;
            goto LABEL_111;
          }
          ++v10;
          v14 = ++a3;
        }
        while ( v10 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 4u:
        if ( (v5[255] & 8) == 0 )
          v5[255] |= 8u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 41);
        goto LABEL_110;
      case 5u:
        if ( (v5[255] & 0x10) == 0 )
          v5[255] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v37 = v4[1];
        v17 = v44 + 42;
        a3 = v44 + 42;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v17);
          if ( v6 )
            return v6;
          v18 = v4[1];
          if ( v18 > (unsigned int)a2 + v37 )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + v37) )
            goto LABEL_41;
          ++v16;
          v17 = ++a3;
        }
        while ( v16 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 6u:
        if ( (v5[255] & 0x20) == 0 )
          v5[255] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v38 = v4[1];
        v20 = v44 + 62;
        a3 = v44 + 62;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v20);
          if ( v6 )
            return v6;
          v21 = v4[1];
          if ( v21 > (unsigned int)a2 + v38 )
            return -34;
          if ( (_DWORD *)v21 == (_DWORD *)((char *)a2 + v38) )
          {
LABEL_41:
            v19 = v16 + 1;
            v5 = v44;
            v44[41] = v19;
            goto LABEL_111;
          }
          ++v16;
          v20 = ++a3;
        }
        while ( v16 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 7u:
        if ( (v5[255] & 0x40) == 0 )
          v5[255] |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 82);
        goto LABEL_110;
      case 8u:
        if ( (v5[255] & 0x80) == 0 )
          v5[255] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v39 = v4[1];
        v23 = v44 + 83;
        a3 = v44 + 83;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v23);
          if ( v6 )
            return v6;
          v24 = v4[1];
          if ( v24 > (unsigned int)a2 + v39 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v39) )
            goto LABEL_65;
          ++v22;
          v23 = ++a3;
        }
        while ( v22 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 9u:
        if ( (v5[255] & 0x100) == 0 )
          v5[255] |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v40 = v4[1];
        v26 = v44 + 103;
        a3 = v44 + 103;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v26);
          if ( v6 )
            return v6;
          v27 = v4[1];
          if ( v27 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v27 == (_DWORD *)((char *)a2 + v40) )
          {
LABEL_65:
            v25 = v22 + 1;
            v5 = v44;
            v44[82] = v25;
            goto LABEL_111;
          }
          ++v22;
          v26 = ++a3;
        }
        while ( v22 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 0xAu:
        if ( (v5[255] & 0x200) == 0 )
          v5[255] |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 123);
        goto LABEL_110;
      case 0xBu:
        if ( (v5[255] & 0x400) == 0 )
          v5[255] |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v41 = v4[1];
        v29 = v44 + 124;
        a3 = v44 + 124;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v29);
          if ( v6 )
            return v6;
          v30 = v4[1];
          if ( v30 > (unsigned int)a2 + v41 )
            return -34;
          if ( (_DWORD *)v30 == (_DWORD *)((char *)a2 + v41) )
            goto LABEL_89;
          ++v28;
          v29 = ++a3;
        }
        while ( v28 < 64 );
        v5 = v44;
        goto LABEL_111;
      case 0xCu:
        if ( (v5[255] & 0x800) == 0 )
          v5[255] |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v42 = v4[1];
        v32 = v44 + 188;
        a3 = v44 + 188;
        do
        {
          v6 = TdrBuf::ReadVarInt(v4, v32);
          if ( v6 )
            return v6;
          v33 = v4[1];
          if ( v33 > (unsigned int)a2 + v42 )
            return -34;
          if ( (_DWORD *)v33 == (_DWORD *)((char *)a2 + v42) )
          {
LABEL_89:
            v31 = v28 + 1;
            v5 = v44;
            v44[123] = v31;
            goto LABEL_111;
          }
          ++v28;
          v32 = ++a3;
        }
        while ( v28 < 64 );
        v5 = v44;
LABEL_111:
        v7 = v34;
        if ( v4[1] < v34 )
          continue;
LABEL_112:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 0xDu:
        if ( (v5[255] & 0x1000) == 0 )
          v5[255] |= 0x1000u;
        VarInt = TdrBuf::ReadVarUInt(v4, v5 + 252);
        goto LABEL_110;
      case 0xEu:
        if ( (v5[255] & 0x2000) == 0 )
          v5[255] |= 0x2000u;
        VarInt = TdrBuf::ReadVarUInt(v4, v5 + 253);
        goto LABEL_110;
      case 0xFu:
        if ( (v5[255] & 0x4000) == 0 )
          v5[255] |= 0x4000u;
        VarInt = TdrBuf::ReadVarUInt(v4, v5 + 254);
        goto LABEL_110;
      default:
        VarInt = TdrBuf::SkipField(v4, v43 & 0xF);
LABEL_110:
        v6 = VarInt;
        if ( !VarInt )
          goto LABEL_111;
        return v6;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0147::Read_0x99
// Address Name: SUB_10182E80
// ============================================================
//----- (10182E80) --------------------------------------------------------
int __thiscall sub_10182E80(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  int v16; // ebx
  _BYTE *v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  _BYTE *v20; // eax
  unsigned int v21; // ecx
  int v22; // ebx
  _BYTE *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  _BYTE *v26; // eax
  unsigned int v27; // ecx
  int v28; // ebx
  _BYTE *v29; // eax
  unsigned int v30; // ecx
  int v31; // eax
  _BYTE *v32; // eax
  unsigned int v33; // ecx
  unsigned int v34; // [esp+Ch] [ebp-10h]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  int v38; // [esp+10h] [ebp-Ch]
  int v39; // [esp+10h] [ebp-Ch]
  int v40; // [esp+10h] [ebp-Ch]
  int v41; // [esp+10h] [ebp-Ch]
  int v42; // [esp+10h] [ebp-Ch]
  unsigned int v43; // [esp+14h] [ebp-8h] BYREF
  int *v44; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v44 = this;
  v43 = 0;
  *(this + 255) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v34 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_112;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v43);
    if ( result )
      return result;
    switch ( v43 >> 4 )
    {
      case 1u:
        if ( (v5[255] & 1) == 0 )
          v5[255] |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_110;
      case 2u:
        if ( (v5[255] & 2) == 0 )
          v5[255] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v35 = v4[1];
        v11 = v44 + 1;
        a3 = v44 + 1;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v11);
          if ( v6 )
            return v6;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v35) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 3u:
        if ( (v5[255] & 4) == 0 )
          v5[255] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v36 = v4[1];
        v14 = v44 + 21;
        a3 = v44 + 21;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v14);
          if ( v6 )
            return v6;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v36) )
          {
LABEL_17:
            v13 = v10 + 1;
            v5 = v44;
            *v44 = v13;
            goto LABEL_111;
          }
          ++v10;
          v14 = ++a3;
        }
        while ( v10 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 4u:
        if ( (v5[255] & 8) == 0 )
          v5[255] |= 8u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 164);
        goto LABEL_110;
      case 5u:
        if ( (v5[255] & 0x10) == 0 )
          v5[255] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v37 = v4[1];
        v17 = v44 + 42;
        a3 = v44 + 42;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v17);
          if ( v6 )
            return v6;
          v18 = v4[1];
          if ( v18 > (unsigned int)a2 + v37 )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + v37) )
            goto LABEL_41;
          ++v16;
          v17 = ++a3;
        }
        while ( v16 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 6u:
        if ( (v5[255] & 0x20) == 0 )
          v5[255] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v38 = v4[1];
        v20 = v44 + 62;
        a3 = v44 + 62;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v20);
          if ( v6 )
            return v6;
          v21 = v4[1];
          if ( v21 > (unsigned int)a2 + v38 )
            return -34;
          if ( (_DWORD *)v21 == (_DWORD *)((char *)a2 + v38) )
          {
LABEL_41:
            v19 = v16 + 1;
            v5 = v44;
            v44[41] = v19;
            goto LABEL_111;
          }
          ++v16;
          v20 = ++a3;
        }
        while ( v16 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 7u:
        if ( (v5[255] & 0x40) == 0 )
          v5[255] |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 328);
        goto LABEL_110;
      case 8u:
        if ( (v5[255] & 0x80) == 0 )
          v5[255] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v39 = v4[1];
        v23 = v44 + 83;
        a3 = v44 + 83;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v23);
          if ( v6 )
            return v6;
          v24 = v4[1];
          if ( v24 > (unsigned int)a2 + v39 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v39) )
            goto LABEL_65;
          ++v22;
          v23 = ++a3;
        }
        while ( v22 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 9u:
        if ( (v5[255] & 0x100) == 0 )
          v5[255] |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v40 = v4[1];
        v26 = v44 + 103;
        a3 = v44 + 103;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v26);
          if ( v6 )
            return v6;
          v27 = v4[1];
          if ( v27 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v27 == (_DWORD *)((char *)a2 + v40) )
          {
LABEL_65:
            v25 = v22 + 1;
            v5 = v44;
            v44[82] = v25;
            goto LABEL_111;
          }
          ++v22;
          v26 = ++a3;
        }
        while ( v22 < 20 );
        v5 = v44;
        goto LABEL_111;
      case 0xAu:
        if ( (v5[255] & 0x200) == 0 )
          v5[255] |= 0x200u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 492);
        goto LABEL_110;
      case 0xBu:
        if ( (v5[255] & 0x400) == 0 )
          v5[255] |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v41 = v4[1];
        v29 = v44 + 124;
        a3 = v44 + 124;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v29);
          if ( v6 )
            return v6;
          v30 = v4[1];
          if ( v30 > (unsigned int)a2 + v41 )
            return -34;
          if ( (_DWORD *)v30 == (_DWORD *)((char *)a2 + v41) )
            goto LABEL_89;
          ++v28;
          v29 = ++a3;
        }
        while ( v28 < 64 );
        v5 = v44;
        goto LABEL_111;
      case 0xCu:
        if ( (v5[255] & 0x800) == 0 )
          v5[255] |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v42 = v4[1];
        v32 = v44 + 188;
        a3 = v44 + 188;
        do
        {
          v6 = TdrBuf::ReadInt32(v4, v32);
          if ( v6 )
            return v6;
          v33 = v4[1];
          if ( v33 > (unsigned int)a2 + v42 )
            return -34;
          if ( (_DWORD *)v33 == (_DWORD *)((char *)a2 + v42) )
          {
LABEL_89:
            v31 = v28 + 1;
            v5 = v44;
            v44[123] = v31;
            goto LABEL_111;
          }
          ++v28;
          v32 = ++a3;
        }
        while ( v28 < 64 );
        v5 = v44;
LABEL_111:
        v7 = v34;
        if ( v4[1] < v34 )
          continue;
LABEL_112:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 0xDu:
        if ( (v5[255] & 0x1000) == 0 )
          v5[255] |= 0x1000u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 1008);
        goto LABEL_110;
      case 0xEu:
        if ( (v5[255] & 0x2000) == 0 )
          v5[255] |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 1012);
        goto LABEL_110;
      case 0xFu:
        if ( (v5[255] & 0x4000) == 0 )
          v5[255] |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 1016);
        goto LABEL_110;
      default:
        Int32 = TdrBuf::SkipField(v4, v43 & 0xF);
LABEL_110:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_111;
        return v6;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0147::DoDebugFormat
// Address Name: SUB_10183570
// ============================================================
//----- (10183570) --------------------------------------------------------
int __thiscall sub_10183570(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10183620(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0147::DebugFormat
// Address Name: SUB_10183620
// ============================================================
//----- (10183620) --------------------------------------------------------
int __thiscall sub_10183620(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  _DWORD *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ebx
  _DWORD *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ebx
  _DWORD *v26; // eax
  int v27; // ecx
  int v28; // eax
  int v29; // ebx
  _DWORD *v30; // eax
  int v31; // ecx
  int v32; // eax
  int v33; // ebx
  _DWORD *v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // ebx
  _DWORD *v38; // eax
  int v39; // [esp+14h] [ebp+8h]
  int v40; // [esp+14h] [ebp+8h]
  int v41; // [esp+14h] [ebp+8h]
  int v42; // [esp+14h] [ebp+8h]
  int v43; // [esp+14h] [ebp+8h]
  int v44; // [esp+14h] [ebp+8h]
  int v45; // [esp+14h] [ebp+8h]
  int v46; // [esp+14h] [ebp+8h]

  result = print_field(a2, a3, a4, "[dailyLimitCnt]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( *this < 0 )
      return -6;
    if ( v8 > 20 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[dailyLimitType]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( *this <= 0 )
      {
LABEL_11:
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        v12 = *this;
        if ( *this < 0 )
          return -6;
        if ( v12 <= 20 )
        {
          result = sub_1024A3B0(a2, a3, v11, "[dailyLimitData]", v12);
          if ( result )
            return result;
          v13 = 0;
          if ( *this > 0 )
          {
            v14 = this + 21;
            v40 = (int)(this + 21);
            do
            {
              result = Printf(a2, " %d", *v14);
              if ( result )
                return result;
              ++v13;
              v14 = (_DWORD *)(v40 + 4);
              v40 += 4;
            }
            while ( v13 < *this );
          }
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[weekLimitCnt]", "%d", *(this + 41));
          if ( result )
            return result;
          v16 = *(this + 41);
          if ( v16 < 0 )
            return -6;
          if ( v16 <= 20 )
          {
            result = sub_1024A3B0(a2, a3, v15, "[weekLimitType]", v16);
            if ( result )
              return result;
            v17 = 0;
            if ( *(this + 41) > 0 )
            {
              v18 = this + 42;
              v41 = (int)(this + 42);
              do
              {
                result = Printf(a2, " %d", *v18);
                if ( result )
                  return result;
                ++v17;
                v18 = (_DWORD *)(v41 + 4);
                v41 += 4;
              }
              while ( v17 < *(this + 41) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v20 = *(this + 41);
            if ( v20 < 0 )
              return -6;
            if ( v20 <= 20 )
            {
              result = sub_1024A3B0(a2, a3, v19, "[weekLimitData]", v20);
              if ( result )
                return result;
              v21 = 0;
              if ( *(this + 41) > 0 )
              {
                v22 = this + 62;
                v42 = (int)(this + 62);
                do
                {
                  result = Printf(a2, " %d", *v22);
                  if ( result )
                    return result;
                  ++v21;
                  v22 = (_DWORD *)(v42 + 4);
                  v42 += 4;
                }
                while ( v21 < *(this + 41) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[monthLimitCnt]", "%d", *(this + 82));
              if ( result )
                return result;
              v24 = *(this + 82);
              if ( v24 < 0 )
                return -6;
              if ( v24 <= 20 )
              {
                result = sub_1024A3B0(a2, a3, v23, "[monthLimitType]", v24);
                if ( result )
                  return result;
                v25 = 0;
                if ( *(this + 82) > 0 )
                {
                  v26 = this + 83;
                  v43 = (int)(this + 83);
                  do
                  {
                    result = Printf(a2, " %d", *v26);
                    if ( result )
                      return result;
                    ++v25;
                    v26 = (_DWORD *)(v43 + 4);
                    v43 += 4;
                  }
                  while ( v25 < *(this + 82) );
                }
                result = TdrBuf::WriteChar(a2, a4);
                if ( result )
                  return result;
                v28 = *(this + 82);
                if ( v28 < 0 )
                  return -6;
                if ( v28 <= 20 )
                {
                  result = sub_1024A3B0(a2, a3, v27, "[monthLimitData]", v28);
                  if ( result )
                    return result;
                  v29 = 0;
                  if ( *(this + 82) > 0 )
                  {
                    v30 = this + 103;
                    v44 = (int)(this + 103);
                    do
                    {
                      result = Printf(a2, " %d", *v30);
                      if ( result )
                        return result;
                      ++v29;
                      v30 = (_DWORD *)(v44 + 4);
                      v44 += 4;
                    }
                    while ( v29 < *(this + 82) );
                  }
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( result )
                    return result;
                  result = print_field(a2, a3, a4, "[foreverLimitCnt]", "%d", *(this + 123));
                  if ( result )
                    return result;
                  v32 = *(this + 123);
                  if ( v32 < 0 )
                    return -6;
                  if ( v32 <= 64 )
                  {
                    result = sub_1024A3B0(a2, a3, v31, "[foreverLimitType]", v32);
                    if ( result )
                      return result;
                    v33 = 0;
                    if ( *(this + 123) > 0 )
                    {
                      v34 = this + 124;
                      v45 = (int)(this + 124);
                      do
                      {
                        result = Printf(a2, " %d", *v34);
                        if ( result )
                          return result;
                        ++v33;
                        v34 = (_DWORD *)(v45 + 4);
                        v45 += 4;
                      }
                      while ( v33 < *(this + 123) );
                    }
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( result )
                      return result;
                    v36 = *(this + 123);
                    if ( v36 < 0 )
                      return -6;
                    if ( v36 <= 64 )
                    {
                      result = sub_1024A3B0(a2, a3, v35, "[foreverLimitData]", v36);
                      if ( !result )
                      {
                        v37 = 0;
                        if ( *(this + 123) <= 0 )
                        {
LABEL_70:
                          result = TdrBuf::WriteChar(a2, a4);
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[lastDailyTm]", "%u", *(this + 252));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[lastWeekTm]", "%u", *(this + 253));
                              if ( !result )
                                return print_field(a2, a3, a4, "[lastMonthTm]", "%u", *(this + 254));
                            }
                          }
                        }
                        else
                        {
                          v38 = this + 188;
                          v46 = (int)(this + 188);
                          while ( 1 )
                          {
                            result = Printf(a2, " %d", *v38);
                            if ( result )
                              break;
                            ++v37;
                            v38 = (_DWORD *)(v46 + 4);
                            v46 += 4;
                            if ( v37 >= *(this + 123) )
                              goto LABEL_70;
                          }
                        }
                      }
                      return result;
                    }
                  }
                }
              }
            }
          }
        }
        return -7;
      }
      v10 = this + 1;
      v39 = (int)(this + 1);
      while ( 1 )
      {
        result = Printf(a2, " %d", *v10);
        if ( result )
          break;
        ++v9;
        v10 = (_DWORD *)(v39 + 4);
        v39 += 4;
        if ( v9 >= *this )
          goto LABEL_11;
      }
    }
  }
  return result;
}
// 1018367F: variable 'v7' is possibly undefined
// 101836FA: variable 'v11' is possibly undefined
// 10183799: variable 'v15' is possibly undefined
// 10183822: variable 'v19' is possibly undefined
// 101838CC: variable 'v23' is possibly undefined
// 10183952: variable 'v27' is possibly undefined
// 101839FC: variable 'v31' is possibly undefined
// 10183A82: variable 'v35' is possibly undefined



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



