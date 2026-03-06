// ============================================================
// Name: TLV::UnkTlv0095::Read
// Address Name: SUB_1015BA40
// ============================================================
//----- (1015BA40) --------------------------------------------------------
int __thiscall sub_1015BA40(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  char *v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = (char *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_1015BB10(this, &v9, v8);
  else
    result = sub_1015C080(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0095::Read_0xAA
// Address Name: SUB_1015BB10
// ============================================================
//----- (1015BB10) --------------------------------------------------------
int __thiscall sub_1015BB10(_DWORD *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  int *v18; // eax
  unsigned int v19; // ecx
  int v20; // ebx
  int *v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  char *v24; // [esp+Ch] [ebp-10h]
  _DWORD *v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+10h] [ebp-Ch]
  int v27; // [esp+10h] [ebp-Ch]
  int v28; // [esp+10h] [ebp-Ch]
  unsigned int v29; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v30; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v30 = this;
  *(_DWORD *)((char *)this + 539) = 0;
  v29 = 0;
  v7 = &v3[v6[1]];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_89;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v29);
    if ( result )
      return result;
    switch ( v29 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 539) & 1) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_87;
      case 2u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 2) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_87;
      case 3u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 4) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v6[1];
        v11 = v30 + 2;
        v25 = v30 + 2;
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v11 + v10);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          v11 = v25;
          if ( ++v10 >= 10 )
          {
            v4 = v30;
            goto LABEL_88;
          }
        }
        v13 = v10 + 1;
        v4 = v30;
        v30[1] = v13;
        goto LABEL_88;
      case 4u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 8) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 8u;
        VarInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)((char *)v4 + 18));
        goto LABEL_87;
      case 5u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x10) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x10u;
        VarInt = TdrBuf::ReadByte_2(v6, (_BYTE *)v4 + 22);
        goto LABEL_87;
      case 6u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x20) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 23));
        goto LABEL_87;
      case 7u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x40) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 27));
        goto LABEL_87;
      case 8u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x80) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x80u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 31));
        goto LABEL_87;
      case 9u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x100) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 35));
        goto LABEL_87;
      case 0xAu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x200) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v26 = v6[1];
        v15 = (_DWORD *)((char *)v30 + 39);
        a3 = (char *)v30 + 39;
        do
        {
          v5 = TdrBuf::ReadVarInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v26 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v26) )
            goto LABEL_49;
          ++v14;
          v15 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v14 < 10 );
        v4 = v30;
        goto LABEL_88;
      case 0xBu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x400) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v27 = v6[1];
        v18 = (_DWORD *)((char *)v30 + 79);
        a3 = (char *)v30 + 79;
        do
        {
          v5 = TdrBuf::ReadVarInt(v6, v18);
          if ( v5 )
            return v5;
          v19 = v6[1];
          if ( v19 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + v27) )
          {
LABEL_49:
            v17 = v14 + 1;
            v4 = v30;
            *(_DWORD *)((char *)v30 + 35) = v17;
            goto LABEL_88;
          }
          ++v14;
          v18 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v14 < 10 );
        v4 = v30;
        goto LABEL_88;
      case 0xCu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x800) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x800u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 119));
        goto LABEL_87;
      case 0xDu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x1000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x1000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v20 = 0;
        v28 = v6[1];
        v21 = (_DWORD *)((char *)v30 + 123);
        a3 = (char *)v30 + 123;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v21);
          if ( v5 )
            return v5;
          v22 = v6[1];
          if ( v22 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v20;
          v21 = (int *)(a3 + 4);
          a3 += 4;
          if ( v20 >= 100 )
          {
            v4 = v30;
            goto LABEL_88;
          }
        }
        v23 = v20 + 1;
        v4 = v30;
        *(_DWORD *)((char *)v30 + 119) = v23;
LABEL_88:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_89:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x2000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x2000u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 523));
        goto LABEL_87;
      case 0xFu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x4000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x4000u;
        VarInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)((char *)v4 + 527));
        goto LABEL_87;
      case 0x10u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x8000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x8000u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 531));
        goto LABEL_87;
      case 0x11u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x10000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x10000u;
        VarInt = TdrBuf::ReadVarInt(v6, (_DWORD *)((char *)v4 + 535));
        goto LABEL_87;
      default:
        VarInt = TdrBuf::SkipField(v6, v29 & 0xF);
LABEL_87:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_88;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0095::Read_0x99
// Address Name: SUB_1015C080
// ============================================================
//----- (1015C080) --------------------------------------------------------
int __thiscall sub_1015C080(_DWORD *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  _BYTE *v18; // eax
  unsigned int v19; // ecx
  int v20; // ebx
  _BYTE *v21; // eax
  unsigned int v22; // ecx
  int v23; // eax
  char *v24; // [esp+Ch] [ebp-10h]
  _DWORD *v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+10h] [ebp-Ch]
  int v27; // [esp+10h] [ebp-Ch]
  int v28; // [esp+10h] [ebp-Ch]
  unsigned int v29; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v30; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v30 = this;
  *(_DWORD *)((char *)this + 539) = 0;
  v29 = 0;
  v7 = &v3[v6[1]];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_89;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v29);
    if ( result )
      return result;
    switch ( v29 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 539) & 1) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_87;
      case 2u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 2) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_87;
      case 3u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 4) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v6[1];
        v11 = v30 + 2;
        v25 = v30 + 2;
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v11 + v10);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          v11 = v25;
          if ( ++v10 >= 10 )
          {
            v4 = v30;
            goto LABEL_88;
          }
        }
        v13 = v10 + 1;
        v4 = v30;
        v30[1] = v13;
        goto LABEL_88;
      case 4u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 8) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 18);
        goto LABEL_87;
      case 5u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x10) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x10u;
        Int32 = TdrBuf::ReadByte_2(v6, (_BYTE *)v4 + 22);
        goto LABEL_87;
      case 6u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x20) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 23);
        goto LABEL_87;
      case 7u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x40) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 27);
        goto LABEL_87;
      case 8u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x80) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 31);
        goto LABEL_87;
      case 9u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x100) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 35);
        goto LABEL_87;
      case 0xAu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x200) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v26 = v6[1];
        v15 = (char *)v30 + 39;
        a3 = (char *)v30 + 39;
        do
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v26 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v26) )
            goto LABEL_49;
          ++v14;
          v15 = a3 + 4;
          a3 += 4;
        }
        while ( v14 < 10 );
        v4 = v30;
        goto LABEL_88;
      case 0xBu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x400) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v27 = v6[1];
        v18 = (char *)v30 + 79;
        a3 = (char *)v30 + 79;
        do
        {
          v5 = TdrBuf::ReadInt32(v6, v18);
          if ( v5 )
            return v5;
          v19 = v6[1];
          if ( v19 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + v27) )
          {
LABEL_49:
            v17 = v14 + 1;
            v4 = v30;
            *(_DWORD *)((char *)v30 + 35) = v17;
            goto LABEL_88;
          }
          ++v14;
          v18 = a3 + 4;
          a3 += 4;
        }
        while ( v14 < 10 );
        v4 = v30;
        goto LABEL_88;
      case 0xCu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x800) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x800u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 119);
        goto LABEL_87;
      case 0xDu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x1000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x1000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v20 = 0;
        v28 = v6[1];
        v21 = (char *)v30 + 123;
        a3 = (char *)v30 + 123;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v21);
          if ( v5 )
            return v5;
          v22 = v6[1];
          if ( v22 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v20;
          v21 = a3 + 4;
          a3 += 4;
          if ( v20 >= 100 )
          {
            v4 = v30;
            goto LABEL_88;
          }
        }
        v23 = v20 + 1;
        v4 = v30;
        *(_DWORD *)((char *)v30 + 119) = v23;
LABEL_88:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_89:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x2000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 523);
        goto LABEL_87;
      case 0xFu:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x4000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 527);
        goto LABEL_87;
      case 0x10u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x8000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x8000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 531);
        goto LABEL_87;
      case 0x11u:
        if ( (*(_DWORD *)((char *)v4 + 539) & 0x10000) == 0 )
          *(_DWORD *)((char *)v4 + 539) |= 0x10000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 535);
        goto LABEL_87;
      default:
        Int32 = TdrBuf::SkipField(v6, v29 & 0xF);
LABEL_87:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_88;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0095::DoDebugFormat
// Address Name: SUB_1015C610
// ============================================================
//----- (1015C610) --------------------------------------------------------
int __thiscall sub_1015C610(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1015C6C0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0095::DebugFormat
// Address Name: SUB_1015C6C0
// ============================================================
//----- (1015C6C0) --------------------------------------------------------
int __thiscall sub_1015C6C0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // ebx
  _DWORD *v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  _DWORD *v21; // eax
  int v22; // [esp+14h] [ebp+8h]
  int v23; // [esp+14h] [ebp+8h]
  int v24; // [esp+14h] [ebp+8h]

  result = print_field(a2, a3, a4, "[ansCnt]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[starBitCount]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 10 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[starBit]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_11:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)((char *)this + 18));
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[zodiacLightenCnt]", "0x%02x", *((unsigned __int8 *)this + 22));
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[activity]", "%d", *(_DWORD *)((char *)this + 23));
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[canResetTimes]", "%d", *(_DWORD *)((char *)this + 27));
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[usedResetTimes]", "%d", *(_DWORD *)((char *)this + 31));
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[taskCount]", "%d", *(_DWORD *)((char *)this + 35));
          if ( result )
            return result;
          v11 = *(_DWORD *)((char *)this + 35);
          if ( v11 < 0 )
            return -6;
          if ( v11 <= 10 )
          {
            result = sub_1024A3B0(a2, a3, v10, "[tasks]", v11);
            if ( result )
              return result;
            v12 = 0;
            if ( *(int *)((char *)this + 35) > 0 )
            {
              v13 = (_DWORD *)((char *)this + 39);
              v22 = (int)this + 39;
              do
              {
                result = Printf(a2, " %d", *v13);
                if ( result )
                  return result;
                ++v12;
                v13 = (_DWORD *)(v22 + 4);
                v22 += 4;
              }
              while ( v12 < *(_DWORD *)((char *)this + 35) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v15 = *(_DWORD *)((char *)this + 35);
            if ( v15 < 0 )
              return -6;
            if ( v15 <= 10 )
            {
              result = sub_1024A3B0(a2, a3, v14, "[prizes]", v15);
              if ( result )
                return result;
              v16 = 0;
              if ( *(int *)((char *)this + 35) > 0 )
              {
                v17 = (_DWORD *)((char *)this + 79);
                v23 = (int)this + 79;
                do
                {
                  result = Printf(a2, " %d", *v17);
                  if ( result )
                    return result;
                  ++v16;
                  v17 = (_DWORD *)(v23 + 4);
                  v23 += 4;
                }
                while ( v16 < *(_DWORD *)((char *)this + 35) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[completeTaskCount]", "%d", *(_DWORD *)((char *)this + 119));
              if ( result )
                return result;
              v19 = *(_DWORD *)((char *)this + 119);
              if ( v19 < 0 )
                return -6;
              if ( v19 <= 100 )
              {
                result = sub_1024A3B0(a2, a3, v18, "[completeTasks]", v19);
                if ( !result )
                {
                  v20 = 0;
                  if ( *(int *)((char *)this + 119) <= 0 )
                  {
LABEL_42:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[taskRefreshTimes]", "%d", *(_DWORD *)((char *)this + 523));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[lastSubmitTaskTime]", "%u", *(_DWORD *)((char *)this + 527));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[taskDoDayNum]", "%d", *(_DWORD *)((char *)this + 531));
                          if ( !result )
                            return print_field(a2, a3, a4, "[taskBuyDayNum]", "%d", *(_DWORD *)((char *)this + 535));
                        }
                      }
                    }
                  }
                  else
                  {
                    v21 = (_DWORD *)((char *)this + 123);
                    v24 = (int)this + 123;
                    while ( 1 )
                    {
                      result = Printf(a2, " %d", *v21);
                      if ( result )
                        break;
                      ++v20;
                      v21 = (_DWORD *)(v24 + 4);
                      v24 += 4;
                      if ( v20 >= *(_DWORD *)((char *)this + 119) )
                        goto LABEL_42;
                    }
                  }
                }
                return result;
              }
            }
          }
          return -7;
        }
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((char *)this + v9 + 8));
          if ( result )
            break;
          if ( ++v9 >= *(this + 1) )
            goto LABEL_11;
        }
      }
    }
  }
  return result;
}
// 1015C743: variable 'v7' is possibly undefined
// 1015C885: variable 'v10' is possibly undefined
// 1015C8FD: variable 'v14' is possibly undefined
// 1015C99E: variable 'v18' is possibly undefined



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



