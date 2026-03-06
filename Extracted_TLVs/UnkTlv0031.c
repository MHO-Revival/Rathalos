// ============================================================
// Name: TLV::UnkTlv0031::Read
// Address Name: SUB_101266D0
// ============================================================
//----- (101266D0) --------------------------------------------------------
int __thiscall sub_101266D0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_101267A0((int)this, &v9, v8);
  else
    result = sub_10126D00((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0031::Read_0xAA
// Address Name: SUB_101267A0
// ============================================================
//----- (101267A0) --------------------------------------------------------
int __thiscall sub_101267A0(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // ecx
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h] BYREF
  int v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  int v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 10153) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_84;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 10153) & 1) == 0 )
          *(_DWORD *)(v3 + 10153) |= 1u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3);
        goto LABEL_82;
      case 2u:
        if ( (*(_DWORD *)(v3 + 10153) & 2) == 0 )
          *(_DWORD *)(v3 + 10153) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 1));
        goto LABEL_82;
      case 3u:
        if ( (*(_DWORD *)(v3 + 10153) & 4) == 0 )
          *(_DWORD *)(v3 + 10153) |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 5));
        goto LABEL_82;
      case 4u:
        if ( (*(_DWORD *)(v3 + 10153) & 8) == 0 )
          *(_DWORD *)(v3 + 10153) |= 8u;
        VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(v3 + 9));
        goto LABEL_82;
      case 5u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x10) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 13));
        goto LABEL_82;
      case 6u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x20) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 17));
        goto LABEL_82;
      case 7u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x40) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x40u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = this + 21;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124840(v22, a2, v24);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v25 + v21 )
            return -34;
          if ( v9 == v25 + v21 )
            break;
          v22 += 7;
          if ( ++v8 >= 64 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *(_DWORD *)(this + 17) = v10;
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x80) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x80u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 469));
        goto LABEL_82;
      case 9u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x100) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x100u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = this + 473;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124F90(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > v25 + v22 )
            return -34;
          if ( v12 == v25 + v22 )
            break;
          v21 += 9;
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(_DWORD *)(this + 469) = v13;
        goto LABEL_83;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x200) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 2777));
        goto LABEL_82;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x400) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x400u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v14 = 0;
        v25 = a2[1];
        while ( 1 )
        {
          v4 = sub_10115A30(a2, (_BYTE *)(v14 + this + 2781));
          if ( v4 )
            return v4;
          v15 = a2[1];
          if ( v15 > v25 + v22 )
            return -34;
          if ( v15 == v25 + v22 )
            break;
          if ( ++v14 >= 200 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(_DWORD *)(this + 2777) = v16;
        goto LABEL_83;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x800) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x800u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 2981));
        goto LABEL_82;
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x1000u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = this + 2985;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_101257D0(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v18 = a2[1];
          if ( v18 > v25 + v22 )
            return -34;
          if ( v18 == v25 + v22 )
            break;
          v21 += 7;
          if ( ++v17 >= 1024 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(_DWORD *)(this + 2981) = v19;
LABEL_83:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_84:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v23 & 0xF);
LABEL_82:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_83;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0031::Read_0x99
// Address Name: SUB_10126D00
// ============================================================
//----- (10126D00) --------------------------------------------------------
int __thiscall sub_10126D00(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  char *v9; // ecx
  int v10; // eax
  int v11; // ebx
  char *v12; // ecx
  int v13; // eax
  int v14; // ebx
  char *v15; // ecx
  int v16; // eax
  int v17; // ebx
  char *v18; // ecx
  int v19; // eax
  char *v21; // [esp+10h] [ebp-18h] BYREF
  char *v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  int v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 10153) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_84;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 10153) & 1) == 0 )
          *(_DWORD *)(v3 + 10153) |= 1u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3);
        goto LABEL_82;
      case 2u:
        if ( (*(_DWORD *)(v3 + 10153) & 2) == 0 )
          *(_DWORD *)(v3 + 10153) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 1));
        goto LABEL_82;
      case 3u:
        if ( (*(_DWORD *)(v3 + 10153) & 4) == 0 )
          *(_DWORD *)(v3 + 10153) |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 5));
        goto LABEL_82;
      case 4u:
        if ( (*(_DWORD *)(v3 + 10153) & 8) == 0 )
          *(_DWORD *)(v3 + 10153) |= 8u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 9));
        goto LABEL_82;
      case 5u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x10) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 13));
        goto LABEL_82;
      case 6u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x20) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 17));
        goto LABEL_82;
      case 7u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x40) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x40u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = (char *)(this + 21);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124930(v22, a2, v24);
            if ( v4 )
              return v4;
          }
          v9 = (char *)a2[1];
          if ( v9 > &v21[v25] )
            return -34;
          if ( v9 == &v21[v25] )
            break;
          v22 += 7;
          if ( ++v8 >= 64 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *(_DWORD *)(this + 17) = v10;
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x80) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 469));
        goto LABEL_82;
      case 9u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x100) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x100u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = (char *)(this + 473);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10125140((int)v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v12 = (char *)a2[1];
          if ( v12 > &v22[v25] )
            return -34;
          if ( v12 == &v22[v25] )
            break;
          v21 += 9;
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(_DWORD *)(this + 469) = v13;
        goto LABEL_83;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x200) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x200u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 2777));
        goto LABEL_82;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x400) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x400u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v14 = 0;
        v25 = a2[1];
        while ( 1 )
        {
          v4 = sub_10115A30(a2, (_BYTE *)(v14 + this + 2781));
          if ( v4 )
            return v4;
          v15 = (char *)a2[1];
          if ( v15 > &v22[v25] )
            return -34;
          if ( v15 == &v22[v25] )
            break;
          if ( ++v14 >= 200 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(_DWORD *)(this + 2777) = v16;
        goto LABEL_83;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x800) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x800u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 2981));
        goto LABEL_82;
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x1000u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = (char *)(this + 2985);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_101258C0(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v18 = (char *)a2[1];
          if ( v18 > &v22[v25] )
            return -34;
          if ( v18 == &v22[v25] )
            break;
          v21 += 7;
          if ( ++v17 >= 1024 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(_DWORD *)(this + 2981) = v19;
LABEL_83:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_84:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v23 & 0xF);
LABEL_82:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_83;
        return v4;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0031::DoDebugFormat
// Address Name: SUB_10127280
// ============================================================
//----- (10127280) --------------------------------------------------------
int __thiscall sub_10127280(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10127330(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0031::DebugFormat
// Address Name: SUB_10127330
// ============================================================
//----- (10127330) --------------------------------------------------------
int __thiscall sub_10127330(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char *v7; // eax
  int v8; // edx
  int v9; // ecx
  char *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v17; // edx
  int v18; // ecx
  int v20; // [esp+1Ch] [ebp+Ch]
  int v21; // [esp+1Ch] [ebp+Ch]
  int v22; // [esp+1Ch] [ebp+Ch]
  __int16 *v23; // [esp+20h] [ebp+10h]
  __int16 *v24; // [esp+20h] [ebp+10h]
  int v25; // [esp+20h] [ebp+10h]
  __int16 *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[openFlag]", "0x%02x", *this);
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[lib]", "%d", *(_DWORD *)(this + 1));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[group]", "%d", *(_DWORD *)(this + 5));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 9));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[curLibFinishCount]", "%d", *(_DWORD *)(this + 13));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[taskCount]", "%d", *(_DWORD *)(this + 17));
  if ( result )
    return result;
  v7 = this;
  v8 = *(_DWORD *)(this + 17);
  if ( v8 < 0 )
    return -6;
  if ( v8 > 64 )
    return -7;
  v9 = 0;
  v20 = 0;
  if ( v8 <= 0 )
  {
LABEL_19:
    result = print_field(a2, a3, a4, "[contentCount]", "%d", *(_DWORD *)(v7 + 469));
    if ( result )
      return result;
    v10 = this;
    v11 = *(_DWORD *)(this + 469);
    if ( v11 < 0 )
      return -6;
    if ( v11 <= 256 )
    {
      v12 = 0;
      v21 = 0;
      if ( v11 > 0 )
      {
        v24 = (__int16 *)(this + 473);
        do
        {
          result = sub_1024A230(a2, a3, a4, "[content]", v12);
          if ( result )
            return result;
          result = a3 >= 0 ? sub_101253C0(v24, a2, a3 + 1, a4) : sub_101253C0(v24, a2, a3, a4);
          if ( result )
            return result;
          v10 = this;
          v12 = v21 + 1;
          v24 = (__int16 *)((char *)v24 + 9);
          v21 = v12;
        }
        while ( v12 < *(_DWORD *)(this + 469) );
      }
      result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *(_DWORD *)(v10 + 2777));
      if ( result )
        return result;
      v14 = *(_DWORD *)(this + 2777);
      if ( v14 < 0 )
        return -6;
      if ( v14 <= 200 )
      {
        result = sub_1024A3B0(a2, a3, v13, "[completeBit]", v14);
        if ( result )
          return result;
        v15 = 0;
        v25 = 0;
        if ( *(int *)(this + 2777) > 0 )
        {
          v16 = this + 2781;
          do
          {
            result = Printf(a2, " 0x%02x", v16[v15]);
            if ( result )
              return result;
            v15 = v25 + 1;
            v25 = v15;
            v16 = this + 2781;
          }
          while ( v15 < *(_DWORD *)(this + 2777) );
        }
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[completeCount]", "%d", *(_DWORD *)(this + 2981));
        if ( result )
          return result;
        v17 = *(_DWORD *)(this + 2981);
        if ( v17 < 0 )
          return -6;
        if ( v17 <= 1024 )
        {
          v18 = 0;
          v22 = 0;
          if ( v17 <= 0 )
            return 0;
          for ( i = (__int16 *)(this + 2985); ; i = (__int16 *)((char *)i + 7) )
          {
            result = sub_1024A230(a2, a3, a4, "[complete]", v18);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10125AF0(i, a2, a3 + 1, a4) : sub_10125AF0(i, a2, a3, a4);
            if ( result )
              break;
            v18 = v22 + 1;
            v22 = v18;
            if ( v18 >= *(_DWORD *)(this + 2981) )
              return 0;
          }
          return result;
        }
      }
    }
    return -7;
  }
  v23 = (__int16 *)(this + 21);
  while ( 1 )
  {
    result = sub_1024A230(a2, a3, a4, "[task]", v9);
    if ( result )
      return result;
    result = a3 >= 0 ? sub_10124B60(v23, a2, a3 + 1, a4) : sub_10124B60(v23, a2, a3, a4);
    if ( result )
      return result;
    v7 = this;
    v9 = v20 + 1;
    v23 = (__int16 *)((char *)v23 + 7);
    v20 = v9;
    if ( v9 >= *(_DWORD *)(this + 17) )
      goto LABEL_19;
  }
}
// 1012758B: variable 'v13' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124F90
// ============================================================
//----- (10124F90) --------------------------------------------------------
int __thiscall sub_10124F90(int this, _DWORD *a2, int a3)
{
  int v5; // edi
  unsigned int v6; // eax
  int result; // eax
  int VarShort; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v13; // [esp+18h] [ebp+8h]

  v5 = 0;
  v12 = 0;
  *(_DWORD *)(this + 5) = 0;
  v6 = a2[1] + a3;
  v13 = v6;
  while ( a2[1] < v6 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5) & 1) == 0 )
          *(_DWORD *)(this + 5) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 5) & 2) == 0 )
          *(_DWORD *)(this + 5) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 3u:
        if ( (*(_DWORD *)(this + 5) & 4) == 0 )
          *(_DWORD *)(this + 5) |= 4u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = a2[1];
        if ( a2[2] == v10 )
          return -2;
        *(_BYTE *)(this + 3) = *(_BYTE *)(v10 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 4u:
        if ( (*(_DWORD *)(this + 5) & 8) == 0 )
          *(_DWORD *)(this + 5) |= 8u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v11 = a2[1];
        if ( a2[2] == v11 )
          return -2;
        *(_BYTE *)(this + 4) = *(_BYTE *)(v11 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        break;
      default:
        VarShort = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_27:
        v5 = VarShort;
        if ( VarShort )
          return v5;
        v6 = v13;
        continue;
    }
  }
  if ( a2[1] > v6 )
    return -34;
  return v5;
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
// Address Name: SUB_101257D0
// ============================================================
//----- (101257D0) --------------------------------------------------------
int __thiscall sub_101257D0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124840
// ============================================================
//----- (10124840) --------------------------------------------------------
int __thiscall sub_10124840(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10125140
// ============================================================
//----- (10125140) --------------------------------------------------------
int __thiscall sub_10125140(int this, _DWORD *a2, int a3)
{
  int v5; // edi
  unsigned int v6; // eax
  int result; // eax
  int Int16; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v13; // [esp+18h] [ebp+8h]

  v5 = 0;
  v12 = 0;
  *(_DWORD *)(this + 5) = 0;
  v6 = a2[1] + a3;
  v13 = v6;
  while ( a2[1] < v6 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5) & 1) == 0 )
          *(_DWORD *)(this + 5) |= 1u;
        Int16 = TdrBuf::ReadInt16(a2, (_BYTE *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 5) & 2) == 0 )
          *(_DWORD *)(this + 5) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 3u:
        if ( (*(_DWORD *)(this + 5) & 4) == 0 )
          *(_DWORD *)(this + 5) |= 4u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = a2[1];
        if ( a2[2] == v10 )
          return -2;
        *(_BYTE *)(this + 3) = *(_BYTE *)(v10 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 4u:
        if ( (*(_DWORD *)(this + 5) & 8) == 0 )
          *(_DWORD *)(this + 5) |= 8u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v11 = a2[1];
        if ( a2[2] == v11 )
          return -2;
        *(_BYTE *)(this + 4) = *(_BYTE *)(v11 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        break;
      default:
        Int16 = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_27:
        v5 = Int16;
        if ( Int16 )
          return v5;
        v6 = v13;
        continue;
    }
  }
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124930
// ============================================================
//----- (10124930) --------------------------------------------------------
int __thiscall sub_10124930(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101258C0
// ============================================================
//----- (101258C0) --------------------------------------------------------
int __thiscall sub_101258C0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
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
// Address Name: SUB_101253C0
// ============================================================
//----- (101253C0) --------------------------------------------------------
int __thiscall sub_101253C0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[task]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[id]", "%d", *((unsigned __int8 *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[state]", "%d", *((unsigned __int8 *)this + 3));
      if ( !result )
        return print_field(a2, a3, a4, "[arg1]", "%d", *((unsigned __int8 *)this + 4));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124B60
// ============================================================
//----- (10124B60) --------------------------------------------------------
int __thiscall sub_10124B60(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[state]", "%d", *((unsigned __int8 *)this + 2));
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
// Address Name: SUB_10125AF0
// ============================================================
//----- (10125AF0) --------------------------------------------------------
int __thiscall sub_10125AF0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[task]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[count]", "%d", *((unsigned __int8 *)this + 2));
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



