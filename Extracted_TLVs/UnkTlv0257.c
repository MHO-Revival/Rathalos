// ============================================================
// Name: TLV::UnkTlv0257::Read
// Address Name: SUB_102255D0
// ============================================================
//----- (102255D0) --------------------------------------------------------
int __thiscall sub_102255D0(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_102256A0(this, &v9, v8);
  else
    result = sub_10225D00(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0257::Read_0xAA
// Address Name: SUB_102256A0
// ============================================================
//----- (102256A0) --------------------------------------------------------
int __thiscall sub_102256A0(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  _DWORD *v9; // ecx
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
  _DWORD *v21; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  _DWORD *v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(int *)((char *)this + 12962) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_94;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 12962) & 1) == 0 )
          *(int *)((char *)v3 + 12962) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_92;
      case 2u:
        if ( (*(int *)((char *)v3 + 12962) & 2) == 0 )
          *(int *)((char *)v3 + 12962) |= 2u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = this + 1;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_1021EC60((int)v22, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v9 = (_DWORD *)a2[1];
          if ( v9 > (_DWORD *)((char *)v21 + v25) )
            return -34;
          if ( v9 == (_DWORD *)((char *)v21 + v25) )
            break;
          v22 = (_DWORD *)((char *)v22 + 15);
          if ( ++v8 >= 128 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *this = v10;
        goto LABEL_93;
      case 3u:
        if ( (*(int *)((char *)v3 + 12962) & 4) == 0 )
          *(int *)((char *)v3 + 12962) |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 481);
        goto LABEL_92;
      case 4u:
        if ( (*(int *)((char *)v3 + 12962) & 8) == 0 )
          *(int *)((char *)v3 + 12962) |= 8u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = this + 482;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_1021F440((int)v21, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)v22 + v25) )
            break;
          v21 = (_DWORD *)((char *)v21 + 9);
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(this + 481) = v13;
        goto LABEL_93;
      case 5u:
        if ( (*(int *)((char *)v3 + 12962) & 0x10) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 1058);
        goto LABEL_92;
      case 6u:
        if ( (*(int *)((char *)v3 + 12962) & 0x20) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x20u;
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
          v4 = sub_10115A30(a2, (_BYTE *)this + v14 + 4236);
          if ( v4 )
            return v4;
          v15 = a2[1];
          if ( v15 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)v22 + v25) )
            break;
          if ( ++v14 >= 1280 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(this + 1058) = v16;
        goto LABEL_93;
      case 0xDu:
        if ( (*(int *)((char *)v3 + 12962) & 0x40) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x40u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        VarInt = sub_10223530((int)(v3 + 1379), a2, (int)v24);
        goto LABEL_92;
      case 0xEu:
        if ( (*(int *)((char *)v3 + 12962) & 0x80) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x80u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        VarInt = sub_10223E60((int *)((char *)v3 + 5662), a2, (int)v24);
        goto LABEL_92;
      case 0xFu:
        if ( (*(int *)((char *)v3 + 12962) & 0x100) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)((char *)v3 + 5670));
        goto LABEL_92;
      case 0x10u:
        if ( (*(int *)((char *)v3 + 12962) & 0x200) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x200u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = (int *)((char *)this + 5674);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10224480(v21, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v18 = a2[1];
          if ( v18 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)v22 + v25) )
            break;
          v21 += 5;
          if ( ++v17 >= 32 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(int *)((char *)this + 5670) = v19;
LABEL_93:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_94:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0x11u:
        if ( (*(int *)((char *)v3 + 12962) & 0x400) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x400u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        VarInt = sub_10221830((int *)((char *)v3 + 6314), a2, v24);
        goto LABEL_92;
      case 0x12u:
        if ( (*(int *)((char *)v3 + 12962) & 0x800) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x800u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        VarInt = sub_10222A40((int *)((char *)v3 + 6706), a2, v24);
        goto LABEL_92;
      case 0x13u:
        if ( (*(int *)((char *)v3 + 12962) & 0x1000) == 0 )
          *(int *)((char *)v3 + 12962) |= 0x1000u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        VarInt = sub_102205C0((int *)((char *)v3 + 6810), a2, (int)v24);
LABEL_92:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_93;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v23 & 0xF);
        goto LABEL_92;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0257::Read_0x99
// Address Name: SUB_10225D00
// ============================================================
//----- (10225D00) --------------------------------------------------------
int __thiscall sub_10225D00(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
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
  _DWORD *v21; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  _DWORD *v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)((char *)this + 12962) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_94;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 12962) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
        goto LABEL_92;
      case 2u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 2) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 2u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = this + 1;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_1021EDB0((int)v22, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > (unsigned int)v21 + v25 )
            return -34;
          if ( (_DWORD *)v9 == (_DWORD *)((char *)v21 + v25) )
            break;
          v22 = (_DWORD *)((char *)v22 + 15);
          if ( ++v8 >= 128 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *this = v10;
        goto LABEL_93;
      case 3u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 4) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3 + 1924);
        goto LABEL_92;
      case 4u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 8) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 8u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = this + 482;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_1021F5F0((int)v21, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)v22 + v25) )
            break;
          v21 = (_DWORD *)((char *)v21 + 9);
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(this + 481) = v13;
        goto LABEL_93;
      case 5u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x10) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3 + 4232);
        goto LABEL_92;
      case 6u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x20) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x20u;
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
          v4 = sub_10115A30(a2, (_BYTE *)this + v14 + 4236);
          if ( v4 )
            return v4;
          v15 = a2[1];
          if ( v15 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)v22 + v25) )
            break;
          if ( ++v14 >= 1280 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(this + 1058) = v16;
        goto LABEL_93;
      case 0xDu:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x40) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x40u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        Int32 = sub_10223720((int)(v3 + 1379), a2, (int)v24);
        goto LABEL_92;
      case 0xEu:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x80) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x80u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        Int32 = sub_10223EE0((int)v3 + 5662, a2, (int)v24);
        goto LABEL_92;
      case 0xFu:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x100) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3 + 5670);
        goto LABEL_92;
      case 0x10u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x200) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x200u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = (_DWORD *)((char *)this + 5674);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10224580((int)v21, a2, (int)v24);
            if ( v4 )
              return v4;
          }
          v18 = a2[1];
          if ( v18 > (unsigned int)v22 + v25 )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)v22 + v25) )
            break;
          v21 += 5;
          if ( ++v17 >= 32 )
          {
            v3 = this;
            goto LABEL_93;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(_DWORD *)((char *)this + 5670) = v19;
LABEL_93:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_94:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 0x11u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x400) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x400u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        Int32 = sub_10221A20((_DWORD *)((char *)v3 + 6314), a2, v24);
        goto LABEL_92;
      case 0x12u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x800) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x800u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        Int32 = sub_10222C10((_DWORD *)((char *)v3 + 6706), a2, v24);
        goto LABEL_92;
      case 0x13u:
        if ( (*(_DWORD *)((char *)v3 + 12962) & 0x1000) == 0 )
          *(_DWORD *)((char *)v3 + 12962) |= 0x1000u;
        v24 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v24);
        if ( v4 )
          return v4;
        if ( !v24 )
          goto LABEL_93;
        Int32 = sub_102207E0((_DWORD *)((char *)v3 + 6810), a2, (int)v24);
LABEL_92:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_93;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v23 & 0xF);
        goto LABEL_92;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0257::DoDebugFormat
// Address Name: SUB_10226380
// ============================================================
//----- (10226380) --------------------------------------------------------
int __thiscall sub_10226380(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10226430(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0257::DebugFormat
// Address Name: SUB_10226430
// ============================================================
//----- (10226430) --------------------------------------------------------
int __thiscall sub_10226430(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  int v13; // ecx
  _DWORD *v14; // eax
  __int16 *v15; // ecx
  _DWORD *v16; // ecx
  int v17; // edx
  int v18; // ecx
  _DWORD *v19; // ecx
  _DWORD *v20; // ecx
  _DWORD *v21; // ecx
  int v23; // [esp+1Ch] [ebp+Ch]
  int v24; // [esp+1Ch] [ebp+Ch]
  int v25; // [esp+1Ch] [ebp+Ch]
  __int16 *v26; // [esp+20h] [ebp+10h]
  __int16 *v27; // [esp+20h] [ebp+10h]
  int v28; // [esp+20h] [ebp+10h]
  _DWORD *v29; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[taskCount]", "%d", *this);
  if ( result )
    return result;
  v7 = this;
  v8 = *this;
  if ( (int)*this < 0 )
    return -6;
  if ( v8 > 128 )
    return -7;
  v23 = 0;
  if ( v8 <= 0 )
  {
LABEL_17:
    result = print_field(a2, a3, a4, "[contentCount]", "%d", v7[481]);
    if ( result )
      return result;
    v9 = this;
    v10 = *(this + 481);
    if ( v10 < 0 )
      return -6;
    if ( v10 <= 256 )
    {
      v24 = 0;
      if ( v10 > 0 )
      {
        v27 = (__int16 *)(this + 482);
        do
        {
          if ( !"[content]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            return result;
          result = Printf(a2, "%s[%u]%c", "[content]", v24, (char)a4);
          if ( result )
            return result;
          result = a3 >= 0 ? sub_1021F870(v27, a2, a3 + 1, a4) : sub_1021F870(v27, a2, a3, a4);
          if ( result )
            return result;
          v9 = this;
          v27 = (__int16 *)((char *)v27 + 9);
        }
        while ( ++v24 < *(this + 481) );
      }
      result = print_field(a2, a3, a4, "[completeBitCount]", "%d", v9[1058]);
      if ( result )
        return result;
      v12 = *(this + 1058);
      if ( v12 < 0 )
        return -6;
      if ( v12 <= 1280 )
      {
        result = sub_1024A3B0(a2, a3, v11, "[completeBit]", v12);
        if ( result )
          return result;
        v13 = 0;
        v28 = 0;
        if ( (int)*(this + 1058) > 0 )
        {
          v14 = this + 1059;
          do
          {
            result = Printf(a2, " 0x%02x", *((char *)v14 + v13));
            if ( result )
              return result;
            v13 = v28 + 1;
            v28 = v13;
            v14 = this + 1059;
          }
          while ( v13 < *(this + 1058) );
        }
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_structure((int)a2, a3, a4, (int)"[daily]");
        if ( result )
          return result;
        v15 = (__int16 *)(this + 1379);
        result = a3 >= 0 ? sub_102239E0(v15, a2, a3 + 1, a4) : sub_102239E0(v15, a2, a3, a4);
        if ( result )
          return result;
        result = print_structure((int)a2, a3, a4, (int)"[schedule]");
        if ( result )
          return result;
        v16 = (_DWORD *)((char *)this + 5662);
        result = a3 >= 0 ? sub_10224030(v16, a2, a3 + 1, a4) : sub_10224030(v16, a2, a3, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[xDailyCount]", "%d", *(_DWORD *)((char *)this + 5670));
        if ( result )
          return result;
        v17 = *(_DWORD *)((char *)this + 5670);
        if ( v17 < 0 )
          return -6;
        if ( v17 <= 32 )
        {
          v18 = 0;
          v25 = 0;
          if ( v17 <= 0 )
          {
LABEL_61:
            result = print_structure((int)a2, a3, a4, (int)"[reset]");
            if ( !result )
            {
              v19 = (_DWORD *)((char *)this + 6314);
              result = a3 >= 0 ? sub_10221CE0(v19, a2, a3 + 1, a4) : sub_10221CE0(v19, a2, a3, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[trace]");
                if ( !result )
                {
                  v20 = (_DWORD *)((char *)this + 6706);
                  if ( a3 >= 0 )
                    result = sub_10222EB0(v20, a2, a3 + 1, a4);
                  else
                    result = sub_10222EB0(v20, a2, a3, a4);
                  if ( !result )
                  {
                    result = print_structure((int)a2, a3, a4, (int)"[complete]");
                    if ( !result )
                    {
                      v21 = (_DWORD *)((char *)this + 6810);
                      if ( a3 >= 0 )
                        return sub_10220AD0(v21, a2, a3 + 1, a4);
                      else
                        return sub_10220AD0(v21, a2, a3, a4);
                    }
                  }
                }
              }
            }
          }
          else
          {
            v29 = (_DWORD *)((char *)this + 5674);
            while ( 1 )
            {
              result = sub_1024A230(a2, a3, a4, "[xDaily]", v18);
              if ( result )
                break;
              result = a3 >= 0 ? sub_10224750(v29, a2, a3 + 1, a4) : sub_10224750(v29, a2, a3, a4);
              if ( result )
                break;
              v18 = v25 + 1;
              v29 += 5;
              v25 = v18;
              if ( v18 >= *(_DWORD *)((char *)this + 5670) )
                goto LABEL_61;
            }
          }
          return result;
        }
      }
    }
    return -7;
  }
  v26 = (__int16 *)(this + 1);
  while ( 1 )
  {
    if ( !"[task]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      return result;
    result = Printf(a2, "%s[%u]%c", "[task]", v23, (char)a4);
    if ( result )
      return result;
    result = a3 >= 0 ? sub_1021EFD0(v26, a2, a3 + 1, a4) : sub_1021EFD0(v26, a2, a3, a4);
    if ( result )
      return result;
    v7 = this;
    v26 = (__int16 *)((char *)v26 + 15);
    if ( ++v23 >= *this )
      goto LABEL_17;
  }
}
// 10226659: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102205C0
// ============================================================
//----- (102205C0) --------------------------------------------------------
int __thiscall sub_102205C0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  int v14; // edi
  _WORD *v15; // ebx
  int VarShort; // edx
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  int *v21; // [esp+18h] [ebp-8h]
  unsigned int v22; // [esp+1Ch] [ebp-4h] BYREF
  int v23; // [esp+28h] [ebp+8h]

  v3 = a3;
  v5 = 0;
  *(this + 1537) = 0;
  v21 = this;
  v7 = a2[1] + v3;
  v22 = 0;
  v18 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_37:
    if ( a2[1] > v7 )
      return -34;
    return v5;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v22);
    if ( result )
      return result;
    if ( v22 >> 4 == 1 )
    {
      if ( (*(_BYTE *)(this + 1537) & 1) == 0 )
        *(this + 1537) |= 1u;
      VarInt = TdrBuf::ReadVarInt(a2, this);
      goto LABEL_34;
    }
    if ( v22 >> 4 == 2 )
      break;
    if ( v22 >> 4 == 3 )
    {
      if ( (*(this + 1537) & 4) == 0 )
        *(this + 1537) |= 4u;
      a3 = 0;
      result = TdrBuf::ReadInt32(a2, &a3);
      if ( result )
        return result;
      v10 = a3;
      if ( a3 )
      {
        v11 = 0;
        v19 = a2[1];
        v23 = 0;
        while ( 1 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v12 = a2[1];
          if ( a2[2] == v12 )
            return -2;
          *((_BYTE *)this + v11 + 4100) = *(_BYTE *)(v12 + *a2);
          v13 = ++a2[1];
          if ( v13 > v10 + v19 )
            return -34;
          if ( v13 == v10 + v19 )
          {
            *this = v11 + 1;
            goto LABEL_35;
          }
          if ( ++v11 >= 2048 )
            goto LABEL_35;
        }
      }
      return -37;
    }
    VarInt = TdrBuf::SkipField(a2, v22 & 0xF);
LABEL_34:
    VarShort = VarInt;
    v23 = VarInt;
    if ( VarInt )
      return VarShort;
LABEL_35:
    v7 = v18;
    if ( a2[1] >= v18 )
    {
      v5 = v23;
      goto LABEL_37;
    }
  }
  if ( (*(this + 1537) & 2) == 0 )
    *(this + 1537) |= 2u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v14 = 0;
  v20 = a2[1];
  v15 = this + 1;
  while ( 1 )
  {
    VarShort = TdrBuf::ReadVarShort(a2, v15);
    v23 = VarShort;
    if ( VarShort )
      return VarShort;
    v17 = a2[1];
    if ( v17 > v20 + a3 )
      return -34;
    if ( v17 == v20 + a3 )
    {
      this = v21;
      *v21 = v14 + 1;
      goto LABEL_35;
    }
    ++v14;
    ++v15;
    if ( v14 >= 2048 )
    {
      this = v21;
      goto LABEL_35;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10222A40
// ============================================================
//----- (10222A40) --------------------------------------------------------
int __thiscall sub_10222A40(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int VarUInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  _WORD *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarUInt = 0;
  v20 = this;
  v19 = 0;
  *(this + 25) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v16 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return VarUInt;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    if ( v19 >> 4 == 3 )
    {
      if ( (v5[25] & 1) == 0 )
        v5[25] |= 1u;
      VarInt = TdrBuf::ReadVarInt(v4, v5);
      goto LABEL_31;
    }
    if ( v19 >> 4 == 4 )
      break;
    if ( v19 >> 4 == 5 )
    {
      if ( (v5[25] & 4) == 0 )
        v5[25] |= 4u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v10 = 0;
          v17 = v4[1];
          v11 = v20 + 9;
          a3 = v20 + 9;
          while ( 1 )
          {
            VarUInt = TdrBuf::ReadVarUInt(v4, v11);
            if ( VarUInt )
              return VarUInt;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + v17 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
              goto LABEL_27;
            ++v10;
            v11 = ++a3;
            if ( v10 >= 16 )
            {
              v5 = v20;
              goto LABEL_32;
            }
          }
        }
        return -37;
      }
      return result;
    }
    VarInt = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_31:
    VarUInt = VarInt;
    if ( VarInt )
      return VarUInt;
LABEL_32:
    v7 = v16;
    if ( v4[1] >= v16 )
      goto LABEL_33;
  }
  if ( (v5[25] & 2) == 0 )
    v5[25] |= 2u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( !result )
  {
    if ( !a2 )
      return -37;
    v10 = 0;
    v18 = v4[1];
    v13 = v20 + 1;
    a3 = v20 + 1;
    while ( 1 )
    {
      VarUInt = TdrBuf::ReadVarShort(v4, v13);
      if ( VarUInt )
        return VarUInt;
      v14 = v4[1];
      if ( v14 > (unsigned int)a2 + v18 )
        return -34;
      if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
      {
LABEL_27:
        v15 = v10 + 1;
        v5 = v20;
        *v20 = v15;
        goto LABEL_32;
      }
      ++v10;
      v13 = (_WORD *)a3 + 1;
      a3 = (_DWORD *)((char *)a3 + 2);
      if ( v10 >= 16 )
      {
        v5 = v20;
        goto LABEL_32;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021F440
// ============================================================
//----- (1021F440) --------------------------------------------------------
int __thiscall sub_1021F440(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10223530
// ============================================================
//----- (10223530) --------------------------------------------------------
int __thiscall sub_10223530(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _WORD *v5; // esi
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarShort; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  _WORD *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_WORD *)this;
  v6 = 0;
  v15 = (_WORD *)this;
  v14 = 0;
  *(_DWORD *)(this + 142) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_30;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (v5[71] & 1) == 0 )
          *(_DWORD *)(v5 + 71) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v4, v5);
        goto LABEL_28;
      case 2u:
        if ( (*(_DWORD *)(v5 + 71) & 2) == 0 )
          *(_DWORD *)(v5 + 71) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        while ( 1 )
        {
          v6 = TdrBuf::ReadVarShort(v4, &v15[v10 + 1]);
          if ( v6 )
            return v6;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v15;
            goto LABEL_29;
          }
        }
        v12 = v10 + 1;
        v5 = v15;
        *v15 = v12;
LABEL_29:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_30:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 3u:
        if ( (*(_DWORD *)(v5 + 71) & 4) == 0 )
          *(_DWORD *)(v5 + 71) |= 4u;
        VarShort = TdrBuf::ReadVarUInt(v4, v5 + 65);
        goto LABEL_28;
      case 4u:
        if ( (*(_DWORD *)(v5 + 71) & 8) == 0 )
          *(_DWORD *)(v5 + 71) |= 8u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(v5 + 67));
        goto LABEL_28;
      case 5u:
        if ( (*(_DWORD *)(v5 + 71) & 0x10) == 0 )
          *(_DWORD *)(v5 + 71) |= 0x10u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(v5 + 69));
        goto LABEL_28;
      default:
        VarShort = TdrBuf::SkipField(v4, v14 & 0xF);
LABEL_28:
        v6 = VarShort;
        if ( !VarShort )
          goto LABEL_29;
        return v6;
    }
  }
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
// Address Name: SUB_10221830
// ============================================================
//----- (10221830) --------------------------------------------------------
int __thiscall sub_10221830(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int VarUInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  _WORD *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarUInt = 0;
  v20 = this;
  v19 = 0;
  *(this + 97) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v16 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return VarUInt;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    if ( v19 >> 4 == 3 )
    {
      if ( (v5[97] & 1) == 0 )
        v5[97] |= 1u;
      VarInt = TdrBuf::ReadVarInt(v4, v5);
      goto LABEL_31;
    }
    if ( v19 >> 4 == 4 )
      break;
    if ( v19 >> 4 == 5 )
    {
      if ( (v5[97] & 4) == 0 )
        v5[97] |= 4u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v10 = 0;
          v17 = v4[1];
          v11 = v20 + 33;
          a3 = v20 + 33;
          while ( 1 )
          {
            VarUInt = TdrBuf::ReadVarUInt(v4, v11);
            if ( VarUInt )
              return VarUInt;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + v17 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
              goto LABEL_27;
            ++v10;
            v11 = ++a3;
            if ( v10 >= 64 )
            {
              v5 = v20;
              goto LABEL_32;
            }
          }
        }
        return -37;
      }
      return result;
    }
    VarInt = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_31:
    VarUInt = VarInt;
    if ( VarInt )
      return VarUInt;
LABEL_32:
    v7 = v16;
    if ( v4[1] >= v16 )
      goto LABEL_33;
  }
  if ( (v5[97] & 2) == 0 )
    v5[97] |= 2u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( !result )
  {
    if ( !a2 )
      return -37;
    v10 = 0;
    v18 = v4[1];
    v13 = v20 + 1;
    a3 = v20 + 1;
    while ( 1 )
    {
      VarUInt = TdrBuf::ReadVarShort(v4, v13);
      if ( VarUInt )
        return VarUInt;
      v14 = v4[1];
      if ( v14 > (unsigned int)a2 + v18 )
        return -34;
      if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
      {
LABEL_27:
        v15 = v10 + 1;
        v5 = v20;
        *v20 = v15;
        goto LABEL_32;
      }
      ++v10;
      v13 = (_WORD *)a3 + 1;
      a3 = (_DWORD *)((char *)a3 + 2);
      if ( v10 >= 64 )
      {
        v5 = v20;
        goto LABEL_32;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10223E60
// ============================================================
//----- (10223E60) --------------------------------------------------------
int __thiscall sub_10223E60(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarUInt; // eax
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
        VarUInt = TdrBuf::ReadVarUInt(a2, this);
      }
      else
      {
        VarUInt = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = VarUInt;
      if ( VarUInt )
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
// Address Name: SUB_10224480
// ============================================================
//----- (10224480) --------------------------------------------------------
int __thiscall sub_10224480(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
          if ( (*(_BYTE *)(this + 4) & 1) == 0 )
            *(this + 4) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        default:
          VarUInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarUInt;
      if ( VarUInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021EC60
// ============================================================
//----- (1021EC60) --------------------------------------------------------
int __thiscall sub_1021EC60(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarShort; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 11) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 11) & 1) == 0 )
            *(_DWORD *)(this + 11) |= 1u;
          VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 11) & 2) == 0 )
            *(_DWORD *)(this + 11) |= 2u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 11) & 4) == 0 )
            *(_DWORD *)(this + 11) |= 4u;
          VarShort = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 3));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 11) & 8) == 0 )
            *(_DWORD *)(this + 11) |= 8u;
          VarShort = TdrBuf::ReadVarInt(a2, (int *)(this + 7));
          goto LABEL_20;
        default:
          VarShort = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = VarShort;
          if ( !VarShort )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102207E0
// ============================================================
//----- (102207E0) --------------------------------------------------------
int __thiscall sub_102207E0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  int v14; // edi
  _BYTE *v15; // ebx
  int Int16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  _DWORD *v21; // [esp+18h] [ebp-8h]
  unsigned int v22; // [esp+1Ch] [ebp-4h] BYREF
  int v23; // [esp+28h] [ebp+8h]

  v3 = a3;
  v5 = 0;
  *(this + 1537) = 0;
  v21 = this;
  v7 = a2[1] + v3;
  v22 = 0;
  v18 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_37:
    if ( a2[1] > v7 )
      return -34;
    return v5;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v22);
    if ( result )
      return result;
    if ( v22 >> 4 == 1 )
    {
      if ( (*(_BYTE *)(this + 1537) & 1) == 0 )
        *(this + 1537) |= 1u;
      Int32 = TdrBuf::ReadInt32(a2, this);
      goto LABEL_34;
    }
    if ( v22 >> 4 == 2 )
      break;
    if ( v22 >> 4 == 3 )
    {
      if ( (*(this + 1537) & 4) == 0 )
        *(this + 1537) |= 4u;
      a3 = 0;
      result = TdrBuf::ReadInt32(a2, &a3);
      if ( result )
        return result;
      v10 = a3;
      if ( a3 )
      {
        v11 = 0;
        v19 = a2[1];
        v23 = 0;
        while ( 1 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v12 = a2[1];
          if ( a2[2] == v12 )
            return -2;
          *((_BYTE *)this + v11 + 4100) = *(_BYTE *)(v12 + *a2);
          v13 = ++a2[1];
          if ( v13 > v10 + v19 )
            return -34;
          if ( v13 == v10 + v19 )
          {
            *this = v11 + 1;
            goto LABEL_35;
          }
          if ( ++v11 >= 2048 )
            goto LABEL_35;
        }
      }
      return -37;
    }
    Int32 = TdrBuf::SkipField(a2, v22 & 0xF);
LABEL_34:
    Int16 = Int32;
    v23 = Int32;
    if ( Int32 )
      return Int16;
LABEL_35:
    v7 = v18;
    if ( a2[1] >= v18 )
    {
      v5 = v23;
      goto LABEL_37;
    }
  }
  if ( (*(this + 1537) & 2) == 0 )
    *(this + 1537) |= 2u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v14 = 0;
  v20 = a2[1];
  v15 = this + 1;
  while ( 1 )
  {
    Int16 = TdrBuf::ReadInt16(a2, v15);
    v23 = Int16;
    if ( Int16 )
      return Int16;
    v17 = a2[1];
    if ( v17 > v20 + a3 )
      return -34;
    if ( v17 == v20 + a3 )
    {
      this = v21;
      *v21 = v14 + 1;
      goto LABEL_35;
    }
    ++v14;
    v15 += 2;
    if ( v14 >= 2048 )
    {
      this = v21;
      goto LABEL_35;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10223EE0
// ============================================================
//----- (10223EE0) --------------------------------------------------------
int __thiscall sub_10223EE0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10224580
// ============================================================
//----- (10224580) --------------------------------------------------------
int __thiscall sub_10224580(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 16) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(_DWORD *)(this + 16) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 16) & 2) == 0 )
            *(_DWORD *)(this + 16) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 16) & 4) == 0 )
            *(_DWORD *)(this + 16) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 16) & 8) == 0 )
            *(_DWORD *)(this + 16) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
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
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021F5F0
// ============================================================
//----- (1021F5F0) --------------------------------------------------------
int __thiscall sub_1021F5F0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1021EDB0
// ============================================================
//----- (1021EDB0) --------------------------------------------------------
int __thiscall sub_1021EDB0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int16; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 11) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 11) & 1) == 0 )
            *(_DWORD *)(this + 11) |= 1u;
          Int16 = TdrBuf::ReadInt16(a2, (_BYTE *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 11) & 2) == 0 )
            *(_DWORD *)(this + 11) |= 2u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 11) & 4) == 0 )
            *(_DWORD *)(this + 11) |= 4u;
          Int16 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 3));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 11) & 8) == 0 )
            *(_DWORD *)(this + 11) |= 8u;
          Int16 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 7));
          goto LABEL_20;
        default:
          Int16 = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = Int16;
          if ( !Int16 )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10223720
// ============================================================
//----- (10223720) --------------------------------------------------------
int __thiscall sub_10223720(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _WORD *v5; // esi
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  __int16 v10; // si
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  _WORD *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_WORD *)this;
  v6 = 0;
  v15 = (_WORD *)this;
  v14 = 0;
  *(_DWORD *)(this + 142) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_30;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (v5[71] & 1) == 0 )
          *(_DWORD *)(v5 + 71) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, v5);
        goto LABEL_28;
      case 2u:
        if ( (*(_DWORD *)(v5 + 71) & 2) == 0 )
          *(_DWORD *)(v5 + 71) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        while ( 1 )
        {
          v6 = TdrBuf::ReadInt16(v4, &v15[v10 + 1]);
          if ( v6 )
            return v6;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v15;
            goto LABEL_29;
          }
        }
        v12 = v10 + 1;
        v5 = v15;
        *v15 = v12;
LABEL_29:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_30:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 3u:
        if ( (*(_DWORD *)(v5 + 71) & 4) == 0 )
          *(_DWORD *)(v5 + 71) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 130);
        goto LABEL_28;
      case 4u:
        if ( (*(_DWORD *)(v5 + 71) & 8) == 0 )
          *(_DWORD *)(v5 + 71) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 134);
        goto LABEL_28;
      case 5u:
        if ( (*(_DWORD *)(v5 + 71) & 0x10) == 0 )
          *(_DWORD *)(v5 + 71) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 138);
        goto LABEL_28;
      default:
        Int16 = TdrBuf::SkipField(v4, v14 & 0xF);
LABEL_28:
        v6 = Int16;
        if ( !Int16 )
          goto LABEL_29;
        return v6;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10221A20
// ============================================================
//----- (10221A20) --------------------------------------------------------
int __thiscall sub_10221A20(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Int16; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  _BYTE *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int16 = 0;
  v20 = this;
  v19 = 0;
  *(this + 97) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v16 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return Int16;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    if ( v19 >> 4 == 3 )
    {
      if ( (v5[97] & 1) == 0 )
        v5[97] |= 1u;
      Int32 = TdrBuf::ReadInt32(v4, v5);
      goto LABEL_31;
    }
    if ( v19 >> 4 == 4 )
      break;
    if ( v19 >> 4 == 5 )
    {
      if ( (v5[97] & 4) == 0 )
        v5[97] |= 4u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v10 = 0;
          v17 = v4[1];
          v11 = v20 + 33;
          a3 = v20 + 33;
          while ( 1 )
          {
            Int16 = TdrBuf::ReadInt32(v4, v11);
            if ( Int16 )
              return Int16;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + v17 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
              goto LABEL_27;
            ++v10;
            v11 = ++a3;
            if ( v10 >= 64 )
            {
              v5 = v20;
              goto LABEL_32;
            }
          }
        }
        return -37;
      }
      return result;
    }
    Int32 = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_31:
    Int16 = Int32;
    if ( Int32 )
      return Int16;
LABEL_32:
    v7 = v16;
    if ( v4[1] >= v16 )
      goto LABEL_33;
  }
  if ( (v5[97] & 2) == 0 )
    v5[97] |= 2u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( !result )
  {
    if ( !a2 )
      return -37;
    v10 = 0;
    v18 = v4[1];
    v13 = v20 + 1;
    a3 = v20 + 1;
    while ( 1 )
    {
      Int16 = TdrBuf::ReadInt16(v4, v13);
      if ( Int16 )
        return Int16;
      v14 = v4[1];
      if ( v14 > (unsigned int)a2 + v18 )
        return -34;
      if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
      {
LABEL_27:
        v15 = v10 + 1;
        v5 = v20;
        *v20 = v15;
        goto LABEL_32;
      }
      ++v10;
      v13 = (char *)a3 + 2;
      a3 = (_DWORD *)((char *)a3 + 2);
      if ( v10 >= 64 )
      {
        v5 = v20;
        goto LABEL_32;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10222C10
// ============================================================
//----- (10222C10) --------------------------------------------------------
int __thiscall sub_10222C10(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Int16; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  _BYTE *v13; // eax
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+10h] [ebp-10h]
  int v17; // [esp+14h] [ebp-Ch]
  int v18; // [esp+14h] [ebp-Ch]
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int16 = 0;
  v20 = this;
  v19 = 0;
  *(this + 25) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v16 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_33:
    if ( v4[1] > v7 )
      return -34;
    return Int16;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    if ( v19 >> 4 == 3 )
    {
      if ( (v5[25] & 1) == 0 )
        v5[25] |= 1u;
      Int32 = TdrBuf::ReadInt32(v4, v5);
      goto LABEL_31;
    }
    if ( v19 >> 4 == 4 )
      break;
    if ( v19 >> 4 == 5 )
    {
      if ( (v5[25] & 4) == 0 )
        v5[25] |= 4u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v10 = 0;
          v17 = v4[1];
          v11 = v20 + 9;
          a3 = v20 + 9;
          while ( 1 )
          {
            Int16 = TdrBuf::ReadInt32(v4, v11);
            if ( Int16 )
              return Int16;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + v17 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
              goto LABEL_27;
            ++v10;
            v11 = ++a3;
            if ( v10 >= 16 )
            {
              v5 = v20;
              goto LABEL_32;
            }
          }
        }
        return -37;
      }
      return result;
    }
    Int32 = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_31:
    Int16 = Int32;
    if ( Int32 )
      return Int16;
LABEL_32:
    v7 = v16;
    if ( v4[1] >= v16 )
      goto LABEL_33;
  }
  if ( (v5[25] & 2) == 0 )
    v5[25] |= 2u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( !result )
  {
    if ( !a2 )
      return -37;
    v10 = 0;
    v18 = v4[1];
    v13 = v20 + 1;
    a3 = v20 + 1;
    while ( 1 )
    {
      Int16 = TdrBuf::ReadInt16(v4, v13);
      if ( Int16 )
        return Int16;
      v14 = v4[1];
      if ( v14 > (unsigned int)a2 + v18 )
        return -34;
      if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
      {
LABEL_27:
        v15 = v10 + 1;
        v5 = v20;
        *v20 = v15;
        goto LABEL_32;
      }
      ++v10;
      v13 = (char *)a3 + 2;
      a3 = (_DWORD *)((char *)a3 + 2);
      if ( v10 >= 16 )
      {
        v5 = v20;
        goto LABEL_32;
      }
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
// Address Name: SUB_10221CE0
// ============================================================
//----- (10221CE0) --------------------------------------------------------
int __thiscall sub_10221CE0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  __int16 *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[resetCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 64 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[task]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_12:
        result = TdrBuf::WriteChar(v4, a4);
        if ( !result )
        {
          v12 = *this;
          if ( (int)*this < 0 )
            return -6;
          if ( v12 > 64 )
            return -7;
          result = sub_1024A3B0(v4, a3, v11, "[time]", v12);
          if ( !result )
          {
            v13 = 0;
            if ( (int)*this <= 0 )
            {
              return TdrBuf::WriteChar(v4, a4);
            }
            else
            {
              for ( i = this + 33; ; ++i )
              {
                result = Printf(a2, " %u", *i);
                if ( result )
                  break;
                if ( ++v13 >= *this )
                {
                  v4 = a2;
                  return TdrBuf::WriteChar(v4, a4);
                }
              }
            }
          }
        }
      }
      else
      {
        v10 = (__int16 *)(this + 1);
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          ++v10;
          if ( v9 >= *this )
          {
            v4 = a2;
            goto LABEL_12;
          }
        }
      }
    }
  }
  return result;
}
// 10221D3F: variable 'v7' is possibly undefined
// 10221DAE: variable 'v11' is possibly undefined



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
// Address Name: SUB_1021F870
// ============================================================
//----- (1021F870) --------------------------------------------------------
int __thiscall sub_1021F870(__int16 *this, _DWORD *a2, int a3, char a4)
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
// Address Name: SUB_10222EB0
// ============================================================
//----- (10222EB0) --------------------------------------------------------
int __thiscall sub_10222EB0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  __int16 *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[traceCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 16 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[task]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_12:
        result = TdrBuf::WriteChar(v4, a4);
        if ( !result )
        {
          v12 = *this;
          if ( (int)*this < 0 )
            return -6;
          if ( v12 > 16 )
            return -7;
          result = sub_1024A3B0(v4, a3, v11, "[time]", v12);
          if ( !result )
          {
            v13 = 0;
            if ( (int)*this <= 0 )
            {
              return TdrBuf::WriteChar(v4, a4);
            }
            else
            {
              for ( i = this + 9; ; ++i )
              {
                result = Printf(a2, " %u", *i);
                if ( result )
                  break;
                if ( ++v13 >= *this )
                {
                  v4 = a2;
                  return TdrBuf::WriteChar(v4, a4);
                }
              }
            }
          }
        }
      }
      else
      {
        v10 = (__int16 *)(this + 1);
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          ++v10;
          if ( v9 >= *this )
          {
            v4 = a2;
            goto LABEL_12;
          }
        }
      }
    }
  }
  return result;
}
// 10222F0F: variable 'v7' is possibly undefined
// 10222F7E: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10224750
// ============================================================
//----- (10224750) --------------------------------------------------------
int __thiscall sub_10224750(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lib]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[completeCount]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[remainCount]", "%d", *(this + 3));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102239E0
// ============================================================
//----- (102239E0) --------------------------------------------------------
int __thiscall sub_102239E0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // si

  result = print_field(a2, a3, a4, "[dailyCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 64 )
      {
        result = sub_1024A3B0(a2, a3, 64, "[daily]", v6);
        if ( !result )
        {
          v7 = 0;
          if ( *this <= 0 )
          {
LABEL_10:
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 65));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[refreshLevel]", "%d", *(_DWORD *)(this + 67));
                if ( !result )
                  return print_field(a2, a3, a4, "[completeCount]", "%d", *(_DWORD *)(this + 69));
              }
            }
          }
          else
          {
            while ( 1 )
            {
              result = Printf(a2, " %d", *(this + v7 + 1));
              if ( result )
                break;
              if ( ++v7 >= *this )
                goto LABEL_10;
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
// Address Name: SUB_10220AD0
// ============================================================
//----- (10220AD0) --------------------------------------------------------
int __thiscall sub_10220AD0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  __int16 *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[completeCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 2048 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[task]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_12:
        result = TdrBuf::WriteChar(v4, a4);
        if ( !result )
        {
          v12 = *this;
          if ( (int)*this < 0 )
            return -6;
          if ( v12 > 2048 )
            return -7;
          result = sub_1024A3B0(v4, a3, v11, "[count]", v12);
          if ( !result )
          {
            v13 = 0;
            if ( (int)*this <= 0 )
            {
              return TdrBuf::WriteChar(v4, a4);
            }
            else
            {
              while ( 1 )
              {
                result = Printf(v4, " %d", *((unsigned __int8 *)this + v13 + 4100));
                if ( result )
                  break;
                if ( ++v13 >= *this )
                  return TdrBuf::WriteChar(v4, a4);
              }
            }
          }
        }
      }
      else
      {
        v10 = (__int16 *)(this + 1);
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          ++v10;
          if ( v9 >= *this )
          {
            v4 = a2;
            goto LABEL_12;
          }
        }
      }
    }
  }
  return result;
}
// 10220B31: variable 'v7' is possibly undefined
// 10220BA0: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10224030
// ============================================================
//----- (10224030) --------------------------------------------------------
int __thiscall sub_10224030(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  return print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021EFD0
// ============================================================
//----- (1021EFD0) --------------------------------------------------------
int __thiscall sub_1021EFD0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[state]", "%d", *((unsigned __int8 *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[acceptTime]", "%u", *(_DWORD *)((char *)this + 3));
      if ( !result )
        return print_field(a2, a3, a4, "[timeout]", "%d", *(_DWORD *)((char *)this + 7));
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



