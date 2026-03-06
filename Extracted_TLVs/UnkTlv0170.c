// ============================================================
// Name: TLV::UnkTlv0170::Read_0xAA
// Address Name: SUB_10196A30
// ============================================================
//----- (10196A30) --------------------------------------------------------
int __thiscall sub_10196A30(int this, _DWORD *Size, int a3)
{
  int v3; // eax
  int Byte; // edx
  _DWORD *v5; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  _DWORD *v12; // ecx
  __int16 v13; // bx
  _DWORD *v14; // ecx
  unsigned __int16 v15; // bx
  _DWORD *v16; // ecx
  int v17; // ebx
  int *v18; // eax
  _DWORD *v19; // ecx
  int v20; // ebx
  int *v21; // eax
  _DWORD *v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // ecx
  unsigned int v25; // ebx
  int *v26; // eax
  _DWORD *v27; // ecx
  _DWORD *v28; // eax
  _DWORD *v29; // ecx
  int v30; // ebx
  int *v31; // eax
  _DWORD *v32; // ecx
  _DWORD *v33; // ecx
  _DWORD *v34; // eax
  _DWORD *v35; // ecx
  int v36; // ebx
  _DWORD *v37; // ecx
  int v38; // ebx
  _DWORD *v39; // ecx
  unsigned int v40; // [esp+8h] [ebp-10h]
  int v41; // [esp+Ch] [ebp-Ch]
  int v42; // [esp+10h] [ebp-8h] BYREF
  unsigned int v43; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  Byte = 0;
  v5 = Size;
  v43 = 0;
  *(_QWORD *)(this + 206775) = 0;
  *(_DWORD *)(this + 206783) = 0;
  v7 = v5[1] + v3;
  v40 = v7;
  if ( v5[1] >= v7 )
  {
LABEL_398:
    if ( v5[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v5, &v43);
    if ( result )
      return result;
    switch ( v43 >> 4 )
    {
      case 6u:
        if ( (*(_BYTE *)(this + 206775) & 1) == 0 )
          *(_DWORD *)(this + 206775) |= 1u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10164190(v5, Size);
        goto LABEL_396;
      case 0xAu:
        if ( (*(_DWORD *)(this + 206775) & 2) == 0 )
          *(_DWORD *)(this + 206775) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 10));
        goto LABEL_396;
      case 0xBu:
        if ( (*(_DWORD *)(this + 206775) & 4) == 0 )
          *(_DWORD *)(this + 206775) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v10 = 0;
        v42 = v5[1];
        v11 = (int *)(this + 14);
        a3 = this + 14;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarInt(v5, v11);
          if ( Byte )
            return Byte;
          v12 = (_DWORD *)v5[1];
          if ( v12 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v12 != (_DWORD *)((char *)Size + v42) )
          {
            ++v10;
            v11 = (int *)(a3 + 4);
            a3 += 4;
            if ( v10 >= 9 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 10) = v10 + 1;
        goto LABEL_397;
      case 0xCu:
        if ( (*(_DWORD *)(this + 206775) & 8) == 0 )
          *(_DWORD *)(this + 206775) |= 8u;
        VarInt = TdrBuf::ReadVarUShort(v5, (_WORD *)(this + 50));
        goto LABEL_396;
      case 0xDu:
        if ( (*(_DWORD *)(this + 206775) & 0x10) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v13 = 0;
        v42 = v5[1];
        while ( 2 )
        {
          a3 = 0;
          Byte = TdrBuf::ReadInt32(v5, &a3);
          if ( Byte )
            return Byte;
          if ( a3 )
          {
            Byte = sub_101669B0(v5, a3);
            if ( Byte )
              return Byte;
          }
          v14 = (_DWORD *)v5[1];
          if ( v14 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v14 != (_DWORD *)((char *)Size + v42) )
          {
            if ( (unsigned __int16)++v13 >= 0x100u )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 50) = v13 + 1;
        goto LABEL_397;
      case 0x10u:
        if ( (*(_DWORD *)(this + 206775) & 0x20) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10171030(v5, Size);
        goto LABEL_396;
      case 0x11u:
        if ( (*(_DWORD *)(this + 206775) & 0x40) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101725E0(v5, Size);
        goto LABEL_396;
      case 0x12u:
        if ( (*(_DWORD *)(this + 206775) & 0x80) == 0 )
          *(_DWORD *)(this + 206775) |= 0x80u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1024C9D0(v5, Size);
        goto LABEL_396;
      case 0x13u:
        if ( (*(_DWORD *)(this + 206775) & 0x100) == 0 )
          *(_DWORD *)(this + 206775) |= 0x100u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1022ACA0(v5, Size);
        goto LABEL_396;
      case 0x14u:
        if ( (*(_DWORD *)(this + 206775) & 0x200) == 0 )
          *(_DWORD *)(this + 206775) |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 7173));
        goto LABEL_396;
      case 0x15u:
        if ( (*(_DWORD *)(this + 206775) & 0x400) == 0 )
          *(_DWORD *)(this + 206775) |= 0x400u;
        VarInt = TdrBuf::ReadVarUShort(v5, (_WORD *)(this + 7177));
        goto LABEL_396;
      case 0x16u:
        if ( (*(_DWORD *)(this + 206775) & 0x800) == 0 )
          *(_DWORD *)(this + 206775) |= 0x800u;
        VarInt = TdrBuf::ReadByte(v5, (_BYTE *)(this + 7179));
        goto LABEL_396;
      case 0x17u:
        if ( (*(_DWORD *)(this + 206775) & 0x1000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x1000u;
        VarInt = TdrBuf::ReadByte(v5, (_BYTE *)(this + 7180));
        goto LABEL_396;
      case 0x18u:
        if ( (*(_DWORD *)(this + 206775) & 0x2000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x2000u;
        VarInt = TdrBuf::ReadVarUInt(v5, (_DWORD *)(this + 7181));
        goto LABEL_396;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 206775) & 0x4000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x4000u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 7185));
        goto LABEL_396;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 206775) & 0x8000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x8000u;
        VarInt = TdrBuf::ReadVarUInt(v5, (_DWORD *)(this + 7189));
        goto LABEL_396;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 206775) & 0x10000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101702B0(v5, Size);
        goto LABEL_396;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 206775) & 0x20000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20000u;
        VarInt = TdrBuf::ReadVarUShort(v5, (_WORD *)(this + 7454));
        goto LABEL_396;
      case 0x20u:
        if ( (*(_DWORD *)(this + 206775) & 0x40000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v15 = 0;
        a3 = v5[1];
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v5, (_BYTE *)(this + v15 + 7456));
          if ( Byte )
            return Byte;
          v16 = (_DWORD *)v5[1];
          if ( v16 > (_DWORD *)((char *)Size + a3) )
            goto LABEL_402;
          if ( v16 != (_DWORD *)((char *)Size + a3) )
          {
            if ( ++v15 >= 0x80u )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 7454) = v15 + 1;
        goto LABEL_397;
      case 0x21u:
        if ( (*(_DWORD *)(this + 206775) & 0x80000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x80000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1016ABF0((size_t)v5, (int)Size);
        goto LABEL_396;
      case 0x2Au:
        if ( (*(_DWORD *)(this + 206775) & 0x100000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x100000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10176230(v5, Size);
        goto LABEL_396;
      case 0x2Bu:
        if ( (*(_DWORD *)(this + 206775) & 0x200000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x200000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10177870(v5, Size);
        goto LABEL_396;
      case 0x2Fu:
        if ( (*(_DWORD *)(this + 206775) & 0x400000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x400000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101585E0(v5, Size);
        goto LABEL_396;
      case 0x34u:
        if ( (*(_DWORD *)(this + 206775) & 0x800000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x800000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1017B710(v5, Size);
        goto LABEL_396;
      case 0x35u:
        if ( (*(_DWORD *)(this + 206775) & 0x1000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x1000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10231920(v5, Size);
        goto LABEL_396;
      case 0x36u:
        if ( (*(_DWORD *)(this + 206775) & 0x2000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x2000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10211910(v5, Size);
        goto LABEL_396;
      case 0x37u:
        if ( (*(_DWORD *)(this + 206775) & 0x4000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x4000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1017E050(v5, Size);
        goto LABEL_396;
      case 0x38u:
        if ( (*(_DWORD *)(this + 206775) & 0x8000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x8000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101827B0(v5, Size);
        goto LABEL_396;
      case 0x39u:
        if ( (*(_DWORD *)(this + 206775) & 0x10000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10184830(v5, Size);
        goto LABEL_396;
      case 0x3Au:
        if ( (*(_DWORD *)(this + 206775) & 0x20000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1017D630(v5, Size);
        goto LABEL_396;
      case 0x3Bu:
        if ( (*(_DWORD *)(this + 206775) & 0x40000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10111B10(this + 88631, v5, (int)Size);
        goto LABEL_396;
      case 0x3Cu:
        if ( *(int *)(this + 206775) >= 0 )
          *(_DWORD *)(this + 206775) |= 0x80000000;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 103357));
        goto LABEL_396;
      case 0x3Du:
        if ( (*(_BYTE *)(this + 206779) & 1) == 0 )
          *(_DWORD *)(this + 206779) |= 1u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v17 = 0;
        v42 = v5[1];
        v18 = (int *)(this + 103361);
        a3 = this + 103361;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarInt(v5, v18);
          if ( Byte )
            return Byte;
          v19 = (_DWORD *)v5[1];
          if ( v19 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v19 != (_DWORD *)((char *)Size + v42) )
          {
            ++v17;
            v18 = (int *)(a3 + 4);
            a3 += 4;
            if ( v17 >= 60 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 103357) = v17 + 1;
        goto LABEL_397;
      case 0x3Eu:
        if ( (*(_DWORD *)(this + 206779) & 2) == 0 )
          *(_DWORD *)(this + 206779) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 103601));
        goto LABEL_396;
      case 0x3Fu:
        if ( (*(_DWORD *)(this + 206779) & 4) == 0 )
          *(_DWORD *)(this + 206779) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v20 = 0;
        v42 = v5[1];
        v21 = (int *)(this + 103605);
        a3 = this + 103605;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarInt(v5, v21);
          if ( Byte )
            return Byte;
          v22 = (_DWORD *)v5[1];
          if ( v22 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v22 != (_DWORD *)((char *)Size + v42) )
          {
            ++v20;
            v21 = (int *)(a3 + 4);
            a3 += 4;
            if ( v20 >= 128 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_186;
        }
      case 0x40u:
        if ( (*(_DWORD *)(this + 206779) & 8) == 0 )
          *(_DWORD *)(this + 206779) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v20 = 0;
        v42 = v5[1];
        v23 = (_DWORD *)(this + 104117);
        a3 = this + 104117;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v5, v23);
          if ( Byte )
            return Byte;
          v24 = (_DWORD *)v5[1];
          if ( v24 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v24 != (_DWORD *)((char *)Size + v42) )
          {
            ++v20;
            v23 = (_DWORD *)(a3 + 4);
            a3 += 4;
            if ( v20 >= 128 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_186:
        *(_DWORD *)(this + 103601) = v20 + 1;
        goto LABEL_397;
      case 0x45u:
        if ( (*(_DWORD *)(this + 206779) & 0x10) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10u;
        VarInt = TdrBuf::ReadVarUInt(v5, (_DWORD *)(this + 104629));
        goto LABEL_396;
      case 0x46u:
        if ( (*(_DWORD *)(this + 206779) & 0x20) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v25 = 0;
        v42 = v5[1];
        v26 = (int *)(this + 104633);
        a3 = this + 104633;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarInt(v5, v26);
          if ( Byte )
            return Byte;
          v27 = (_DWORD *)v5[1];
          if ( v27 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v27 != (_DWORD *)((char *)Size + v42) )
          {
            ++v25;
            v26 = (int *)(a3 + 4);
            a3 += 4;
            if ( v25 >= 0x1F4 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_210;
        }
      case 0x47u:
        if ( (*(_DWORD *)(this + 206779) & 0x40) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v25 = 0;
        v42 = v5[1];
        v28 = (_DWORD *)(this + 106633);
        a3 = this + 106633;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v5, v28);
          if ( Byte )
            return Byte;
          v29 = (_DWORD *)v5[1];
          if ( v29 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v29 != (_DWORD *)((char *)Size + v42) )
          {
            ++v25;
            v28 = (_DWORD *)(a3 + 4);
            a3 += 4;
            if ( v25 >= 0x1F4 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_210:
        *(_DWORD *)(this + 104629) = v25 + 1;
        goto LABEL_397;
      case 0x48u:
        if ( (*(_DWORD *)(this + 206779) & 0x80) == 0 )
          *(_DWORD *)(this + 206779) |= 0x80u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10185B80(v5, Size);
        goto LABEL_396;
      case 0x49u:
        if ( (*(_DWORD *)(this + 206779) & 0x100) == 0 )
          *(_DWORD *)(this + 206779) |= 0x100u;
        VarInt = TdrBuf::ReadVarULong(v5, (_DWORD *)(this + 108757));
        goto LABEL_396;
      case 0x4Au:
        if ( (*(_DWORD *)(this + 206779) & 0x200) == 0 )
          *(_DWORD *)(this + 206779) |= 0x200u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101868F0(v5, Size);
        goto LABEL_396;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 206779) & 0x400) == 0 )
          *(_DWORD *)(this + 206779) |= 0x400u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1017EC70(v5, Size);
        goto LABEL_396;
      case 0x4Cu:
        if ( (*(_DWORD *)(this + 206779) & 0x800) == 0 )
          *(_DWORD *)(this + 206779) |= 0x800u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10187DA0((size_t)v5, (int)Size);
        goto LABEL_396;
      case 0x4Du:
        if ( (*(_DWORD *)(this + 206779) & 0x1000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x1000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10114930((size_t)v5, (int)Size);
        goto LABEL_396;
      case 0x4Eu:
        if ( (*(_DWORD *)(this + 206779) & 0x2000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x2000u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 112238));
        goto LABEL_396;
      case 0x4Fu:
        if ( (*(_DWORD *)(this + 206779) & 0x4000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x4000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        v42 = v5[1];
        v31 = (int *)(this + 112242);
        a3 = this + 112242;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarInt(v5, v31);
          if ( Byte )
            return Byte;
          v32 = (_DWORD *)v5[1];
          if ( v32 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v32 != (_DWORD *)((char *)Size + v42) )
          {
            ++v30;
            v31 = (int *)(a3 + 4);
            a3 += 4;
            if ( v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_262;
        }
      case 0x50u:
        if ( (*(_DWORD *)(this + 206779) & 0x8000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x8000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        a3 = v5[1];
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v5, (_BYTE *)(v30 + this + 112442));
          if ( Byte )
            return Byte;
          v33 = (_DWORD *)v5[1];
          if ( v33 > (_DWORD *)((char *)Size + a3) )
            goto LABEL_402;
          if ( v33 != (_DWORD *)((char *)Size + a3) )
          {
            if ( ++v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_262;
        }
      case 0x51u:
        if ( (*(_DWORD *)(this + 206779) & 0x10000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        v42 = v5[1];
        v34 = (_DWORD *)(this + 112492);
        a3 = this + 112492;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v5, v34);
          if ( Byte )
            return Byte;
          v35 = (_DWORD *)v5[1];
          if ( v35 > (_DWORD *)((char *)Size + v42) )
            goto LABEL_402;
          if ( v35 != (_DWORD *)((char *)Size + v42) )
          {
            ++v30;
            v34 = (_DWORD *)(a3 + 4);
            a3 += 4;
            if ( v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_262:
        *(_DWORD *)(this + 112238) = v30 + 1;
        goto LABEL_397;
      case 0x52u:
        if ( (*(_DWORD *)(this + 206779) & 0x20000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20000u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 112692));
        goto LABEL_396;
      case 0x53u:
        if ( (*(_DWORD *)(this + 206779) & 0x40000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10189DD0(v5, Size);
        goto LABEL_396;
      case 0x54u:
        if ( (*(_DWORD *)(this + 206779) & 0x80000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x80000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1017FA00(v5, Size);
        goto LABEL_396;
      case 0x55u:
        if ( (*(_DWORD *)(this + 206779) & 0x100000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x100000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1015BB10(v5, Size);
        goto LABEL_396;
      case 0x56u:
        if ( (*(_DWORD *)(this + 206779) & 0x200000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x200000u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 149928));
        goto LABEL_396;
      case 0x57u:
        if ( (*(_DWORD *)(this + 206779) & 0x400000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x400000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1015DD80(v5, Size);
        goto LABEL_396;
      case 0x58u:
        if ( (*(_DWORD *)(this + 206779) & 0x800000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x800000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1018B4A0(v5, Size);
        goto LABEL_396;
      case 0x59u:
        if ( (*(_DWORD *)(this + 206779) & 0x1000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x1000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1015F010(v5, Size);
        goto LABEL_396;
      case 0x5Au:
        if ( (*(_DWORD *)(this + 206779) & 0x2000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x2000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101813E0(v5, Size);
        goto LABEL_396;
      case 0x5Bu:
        if ( (*(_DWORD *)(this + 206779) & 0x4000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x4000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1018C5B0(v5, Size);
        goto LABEL_396;
      case 0x5Cu:
        if ( (*(_DWORD *)(this + 206779) & 0x8000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x8000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1018D030(v5, Size);
        goto LABEL_396;
      case 0x5Du:
        if ( (*(_DWORD *)(this + 206779) & 0x10000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10180430(v5, Size);
        goto LABEL_396;
      case 0x5Eu:
        if ( (*(_DWORD *)(this + 206779) & 0x20000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20000000u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 204795));
        goto LABEL_396;
      case 0x5Fu:
        if ( (*(_DWORD *)(this + 206779) & 0x40000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40000000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v36 = 0;
        a3 = v5[1];
        while ( 2 )
        {
          Byte = sub_10115A30(v36 + this + 204799);
          if ( Byte )
            return Byte;
          v37 = (_DWORD *)v5[1];
          if ( v37 > (_DWORD *)((char *)Size + a3) )
            goto LABEL_402;
          if ( v37 != (_DWORD *)((char *)Size + a3) )
          {
            if ( ++v36 >= 750 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 204795) = v36 + 1;
        goto LABEL_397;
      case 0x60u:
        if ( *(int *)(this + 206779) >= 0 )
          *(_DWORD *)(this + 206779) |= 0x80000000;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10180BB0(v5, Size);
        goto LABEL_396;
      case 0x61u:
        if ( (*(_BYTE *)(this + 206783) & 1) == 0 )
          *(_DWORD *)(this + 206783) |= 1u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_1018F6E0(v5, Size);
        goto LABEL_396;
      case 0x62u:
        if ( (*(_DWORD *)(this + 206783) & 2) == 0 )
          *(_DWORD *)(this + 206783) |= 2u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_10190A80(v5, Size);
        goto LABEL_396;
      case 0x63u:
        if ( (*(_DWORD *)(this + 206783) & 4) == 0 )
          *(_DWORD *)(this + 206783) |= 4u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        VarInt = sub_101929C0(v5, Size);
LABEL_396:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_397;
        return Byte;
      case 0x64u:
        if ( (*(_DWORD *)(this + 206783) & 8) == 0 )
          *(_DWORD *)(this + 206783) |= 8u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 206691));
        goto LABEL_396;
      case 0x66u:
        if ( (*(_DWORD *)(this + 206783) & 0x10) == 0 )
          *(_DWORD *)(this + 206783) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 206695));
        goto LABEL_396;
      case 0x67u:
        if ( (*(_DWORD *)(this + 206783) & 0x20) == 0 )
          *(_DWORD *)(this + 206783) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v5, (int *)(this + 206699));
        goto LABEL_396;
      case 0x68u:
        if ( (*(_DWORD *)(this + 206783) & 0x40) == 0 )
          *(_DWORD *)(this + 206783) |= 0x40u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( Size )
        {
          v38 = 0;
          v41 = v5[1];
          a3 = this + 206703;
          while ( 1 )
          {
            v42 = 0;
            Byte = TdrBuf::ReadInt32(v5, &v42);
            if ( Byte )
              return Byte;
            if ( v42 )
            {
              Byte = sub_101931C0(v5, v42);
              if ( Byte )
                return Byte;
            }
            v39 = (_DWORD *)v5[1];
            if ( v39 > (_DWORD *)((char *)Size + v41) )
              break;
            if ( v39 == (_DWORD *)((char *)Size + v41) )
            {
              *(_DWORD *)(this + 206699) = v38 + 1;
LABEL_397:
              v7 = v40;
              if ( v5[1] >= v40 )
                goto LABEL_398;
              goto LABEL_2;
            }
            a3 += 12;
            if ( ++v38 >= 6 )
              goto LABEL_397;
          }
LABEL_402:
          result = -34;
        }
        else
        {
LABEL_403:
          result = -37;
        }
        break;
      default:
        VarInt = TdrBuf::SkipField(v5, v43 & 0xF);
        goto LABEL_396;
    }
  }
  return result;
}
// 10115A30: using guessed type _DWORD __stdcall sub_10115A30(_DWORD);
// 101585E0: using guessed type _DWORD __stdcall sub_101585E0(_DWORD, _DWORD);
// 1015BB10: using guessed type _DWORD __stdcall sub_1015BB10(_DWORD, _DWORD);
// 1015DD80: using guessed type _DWORD __stdcall sub_1015DD80(_DWORD, _DWORD);
// 1015F010: using guessed type _DWORD __stdcall sub_1015F010(_DWORD, _DWORD);
// 10164190: using guessed type _DWORD __stdcall sub_10164190(_DWORD, _DWORD);
// 101669B0: using guessed type _DWORD __stdcall sub_101669B0(_DWORD, _DWORD);
// 101702B0: using guessed type _DWORD __stdcall sub_101702B0(_DWORD, _DWORD);
// 10171030: using guessed type _DWORD __stdcall sub_10171030(_DWORD, _DWORD);
// 101725E0: using guessed type _DWORD __stdcall sub_101725E0(_DWORD, _DWORD);
// 10176230: using guessed type _DWORD __stdcall sub_10176230(_DWORD, _DWORD);
// 10177870: using guessed type _DWORD __stdcall sub_10177870(_DWORD, _DWORD);
// 1017B710: using guessed type _DWORD __stdcall sub_1017B710(_DWORD, _DWORD);
// 1017D630: using guessed type _DWORD __stdcall sub_1017D630(_DWORD, _DWORD);
// 1017E050: using guessed type _DWORD __stdcall sub_1017E050(_DWORD, _DWORD);
// 1017EC70: using guessed type _DWORD __stdcall sub_1017EC70(_DWORD, _DWORD);
// 1017FA00: using guessed type _DWORD __stdcall sub_1017FA00(_DWORD, _DWORD);
// 10180430: using guessed type _DWORD __stdcall sub_10180430(_DWORD, _DWORD);
// 10180BB0: using guessed type _DWORD __stdcall sub_10180BB0(_DWORD, _DWORD);
// 101813E0: using guessed type _DWORD __stdcall sub_101813E0(_DWORD, _DWORD);
// 101827B0: using guessed type _DWORD __stdcall sub_101827B0(_DWORD, _DWORD);
// 10184830: using guessed type _DWORD __stdcall sub_10184830(_DWORD, _DWORD);
// 10185B80: using guessed type _DWORD __stdcall sub_10185B80(_DWORD, _DWORD);
// 101868F0: using guessed type _DWORD __stdcall sub_101868F0(_DWORD, _DWORD);
// 10189DD0: using guessed type _DWORD __stdcall sub_10189DD0(_DWORD, _DWORD);
// 1018B4A0: using guessed type _DWORD __stdcall sub_1018B4A0(_DWORD, _DWORD);
// 1018C5B0: using guessed type _DWORD __stdcall sub_1018C5B0(_DWORD, _DWORD);
// 1018D030: using guessed type _DWORD __stdcall sub_1018D030(_DWORD, _DWORD);
// 1018F6E0: using guessed type _DWORD __stdcall sub_1018F6E0(_DWORD, _DWORD);
// 10190A80: using guessed type _DWORD __stdcall sub_10190A80(_DWORD, _DWORD);
// 101929C0: using guessed type _DWORD __stdcall sub_101929C0(_DWORD, _DWORD);
// 101931C0: using guessed type _DWORD __stdcall sub_101931C0(_DWORD, _DWORD);
// 10211910: using guessed type _DWORD __stdcall sub_10211910(_DWORD, _DWORD);
// 1022ACA0: using guessed type _DWORD __stdcall sub_1022ACA0(_DWORD, _DWORD);
// 10231920: using guessed type _DWORD __stdcall sub_10231920(_DWORD, _DWORD);
// 1024C9D0: using guessed type _DWORD __stdcall sub_1024C9D0(_DWORD, _DWORD);



// ============================================================
// Name: TLV::UnkTlv0170::Read_0x99
// Address Name: SUB_101983A0
// ============================================================
//----- (101983A0) --------------------------------------------------------
int __thiscall sub_101983A0(int this, char *Size, int a3)
{
  int v3; // eax
  int Byte; // edx
  char *v5; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  char *v12; // ecx
  unsigned __int16 v13; // bx
  char *v14; // ecx
  unsigned __int16 v15; // bx
  char *v16; // ecx
  int v17; // ebx
  _BYTE *v18; // eax
  char *v19; // ecx
  int v20; // ebx
  _BYTE *v21; // eax
  char *v22; // ecx
  _BYTE *v23; // eax
  char *v24; // ecx
  unsigned int v25; // ebx
  _BYTE *v26; // eax
  char *v27; // ecx
  _BYTE *v28; // eax
  char *v29; // ecx
  int v30; // ebx
  _BYTE *v31; // eax
  char *v32; // ecx
  char *v33; // ecx
  _BYTE *v34; // eax
  char *v35; // ecx
  int v36; // ebx
  char *v37; // ecx
  int v38; // ebx
  char *v39; // ecx
  unsigned int v40; // [esp+8h] [ebp-10h]
  int v41; // [esp+Ch] [ebp-Ch]
  int v42; // [esp+10h] [ebp-8h] BYREF
  unsigned int v43; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  Byte = 0;
  v5 = Size;
  v43 = 0;
  *(_QWORD *)(this + 206775) = 0;
  *(_DWORD *)(this + 206783) = 0;
  v7 = *((_DWORD *)v5 + 1) + v3;
  v40 = v7;
  if ( *((_DWORD *)v5 + 1) >= v7 )
  {
LABEL_398:
    if ( *((_DWORD *)v5 + 1) > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v5, &v43);
    if ( result )
      return result;
    switch ( v43 >> 4 )
    {
      case 6u:
        if ( (*(_BYTE *)(this + 206775) & 1) == 0 )
          *(_DWORD *)(this + 206775) |= 1u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10164240((char *)this, v5, (int)Size);
        goto LABEL_396;
      case 0xAu:
        if ( (*(_DWORD *)(this + 206775) & 2) == 0 )
          *(_DWORD *)(this + 206775) |= 2u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 10));
        goto LABEL_396;
      case 0xBu:
        if ( (*(_DWORD *)(this + 206775) & 4) == 0 )
          *(_DWORD *)(this + 206775) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v10 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v11 = (_BYTE *)(this + 14);
        a3 = this + 14;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v11);
          if ( Byte )
            return Byte;
          v12 = (char *)*((_DWORD *)v5 + 1);
          if ( v12 > &Size[v42] )
            goto LABEL_402;
          if ( v12 != &Size[v42] )
          {
            ++v10;
            v11 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v10 >= 9 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 10) = v10 + 1;
        goto LABEL_397;
      case 0xCu:
        if ( (*(_DWORD *)(this + 206775) & 8) == 0 )
          *(_DWORD *)(this + 206775) |= 8u;
        Int32 = TdrBuf::ReadInt16(v5, (_BYTE *)(this + 50));
        goto LABEL_396;
      case 0xDu:
        if ( (*(_DWORD *)(this + 206775) & 0x10) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v13 = 0;
        v42 = *((_DWORD *)v5 + 1);
        while ( 2 )
        {
          a3 = 0;
          Byte = TdrBuf::ReadInt32(v5, &a3);
          if ( Byte )
            return Byte;
          if ( a3 )
          {
            Byte = sub_10166AD0((char *)(this + 2 * (3 * v13 + 26)), v5, a3);
            if ( Byte )
              return Byte;
          }
          v14 = (char *)*((_DWORD *)v5 + 1);
          if ( v14 > &Size[v42] )
            goto LABEL_402;
          if ( v14 != &Size[v42] )
          {
            if ( ++v13 >= 0x100u )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 50) = v13 + 1;
        goto LABEL_397;
      case 0x10u:
        if ( (*(_DWORD *)(this + 206775) & 0x20) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_101710F0(this + 1588, v5, (int)Size);
        goto LABEL_396;
      case 0x11u:
        if ( (*(_DWORD *)(this + 206775) & 0x40) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_101727D0(this + 1604, v5, (int)Size);
        goto LABEL_396;
      case 0x12u:
        if ( (*(_DWORD *)(this + 206775) & 0x80) == 0 )
          *(_DWORD *)(this + 206775) |= 0x80u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1024CC10(this + 1716, (int)v5, (int)Size);
        goto LABEL_396;
      case 0x13u:
        if ( (*(_DWORD *)(this + 206775) & 0x100) == 0 )
          *(_DWORD *)(this + 206775) |= 0x100u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1022B030((int *)(this + 2237), v5, (int)Size);
        goto LABEL_396;
      case 0x14u:
        if ( (*(_DWORD *)(this + 206775) & 0x200) == 0 )
          *(_DWORD *)(this + 206775) |= 0x200u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 7173));
        goto LABEL_396;
      case 0x15u:
        if ( (*(_DWORD *)(this + 206775) & 0x400) == 0 )
          *(_DWORD *)(this + 206775) |= 0x400u;
        Int32 = TdrBuf::ReadInt16(v5, (_BYTE *)(this + 7177));
        goto LABEL_396;
      case 0x16u:
        if ( (*(_DWORD *)(this + 206775) & 0x800) == 0 )
          *(_DWORD *)(this + 206775) |= 0x800u;
        Int32 = TdrBuf::ReadByte(v5, (_BYTE *)(this + 7179));
        goto LABEL_396;
      case 0x17u:
        if ( (*(_DWORD *)(this + 206775) & 0x1000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x1000u;
        Int32 = TdrBuf::ReadByte(v5, (_BYTE *)(this + 7180));
        goto LABEL_396;
      case 0x18u:
        if ( (*(_DWORD *)(this + 206775) & 0x2000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 7181));
        goto LABEL_396;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 206775) & 0x4000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 7185));
        goto LABEL_396;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 206775) & 0x8000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x8000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 7189));
        goto LABEL_396;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 206775) & 0x10000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10170620(this + 7193, v5, (int)Size);
        goto LABEL_396;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 206775) & 0x20000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20000u;
        Int32 = TdrBuf::ReadInt16(v5, (_BYTE *)(this + 7454));
        goto LABEL_396;
      case 0x20u:
        if ( (*(_DWORD *)(this + 206775) & 0x40000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v15 = 0;
        a3 = *((_DWORD *)v5 + 1);
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v5, (_BYTE *)(this + v15 + 7456));
          if ( Byte )
            return Byte;
          v16 = (char *)*((_DWORD *)v5 + 1);
          if ( v16 > &Size[a3] )
            goto LABEL_402;
          if ( v16 != &Size[a3] )
          {
            if ( ++v15 >= 0x80u )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_WORD *)(this + 7454) = v15 + 1;
        goto LABEL_397;
      case 0x21u:
        if ( (*(_DWORD *)(this + 206775) & 0x80000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x80000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1016ADD0(this + 7584, v5, (int)Size);
        goto LABEL_396;
      case 0x2Au:
        if ( (*(_DWORD *)(this + 206775) & 0x100000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x100000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_101764A0((_DWORD *)(this + 8222), v5, Size);
        goto LABEL_396;
      case 0x2Bu:
        if ( (*(_DWORD *)(this + 206775) & 0x200000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x200000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10177AE0(this + 9438, v5, (int)Size);
        goto LABEL_396;
      case 0x2Fu:
        if ( (*(_DWORD *)(this + 206775) & 0x400000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x400000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10158750((_DWORD *)(this + 9480), v5, (int)Size);
        goto LABEL_396;
      case 0x34u:
        if ( (*(_DWORD *)(this + 206775) & 0x800000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x800000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1017BA00(this + 55937, v5, (int)Size);
        goto LABEL_396;
      case 0x35u:
        if ( (*(_DWORD *)(this + 206775) & 0x1000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x1000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10231AF0((char *)(this + 56681), v5, (int)Size);
        goto LABEL_396;
      case 0x36u:
        if ( (*(_DWORD *)(this + 206775) & 0x2000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x2000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10211D10((char *)(this + 59266), v5, (int)Size);
        goto LABEL_396;
      case 0x37u:
        if ( (*(_DWORD *)(this + 206775) & 0x4000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x4000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1017E210(this + 82986, v5, (int)Size);
        goto LABEL_396;
      case 0x38u:
        if ( (*(_DWORD *)(this + 206775) & 0x8000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x8000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10182E80((int *)(this + 83015), v5, Size);
        goto LABEL_396;
      case 0x39u:
        if ( (*(_DWORD *)(this + 206775) & 0x10000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x10000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10184AA0(this + 84039, v5, (int)Size);
        goto LABEL_396;
      case 0x3Au:
        if ( (*(_DWORD *)(this + 206775) & 0x20000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x20000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1017D7B0((_DWORD *)(this + 84173), v5, (int)Size);
        goto LABEL_396;
      case 0x3Bu:
        if ( (*(_DWORD *)(this + 206775) & 0x40000000) == 0 )
          *(_DWORD *)(this + 206775) |= 0x40000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10111D50(this + 88631, v5, (int)Size);
        goto LABEL_396;
      case 0x3Cu:
        if ( *(int *)(this + 206775) >= 0 )
          *(_DWORD *)(this + 206775) |= 0x80000000;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 103357));
        goto LABEL_396;
      case 0x3Du:
        if ( (*(_BYTE *)(this + 206779) & 1) == 0 )
          *(_DWORD *)(this + 206779) |= 1u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v17 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v18 = (_BYTE *)(this + 103361);
        a3 = this + 103361;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v18);
          if ( Byte )
            return Byte;
          v19 = (char *)*((_DWORD *)v5 + 1);
          if ( v19 > &Size[v42] )
            goto LABEL_402;
          if ( v19 != &Size[v42] )
          {
            ++v17;
            v18 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v17 >= 60 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 103357) = v17 + 1;
        goto LABEL_397;
      case 0x3Eu:
        if ( (*(_DWORD *)(this + 206779) & 2) == 0 )
          *(_DWORD *)(this + 206779) |= 2u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 103601));
        goto LABEL_396;
      case 0x3Fu:
        if ( (*(_DWORD *)(this + 206779) & 4) == 0 )
          *(_DWORD *)(this + 206779) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v20 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v21 = (_BYTE *)(this + 103605);
        a3 = this + 103605;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v21);
          if ( Byte )
            return Byte;
          v22 = (char *)*((_DWORD *)v5 + 1);
          if ( v22 > &Size[v42] )
            goto LABEL_402;
          if ( v22 != &Size[v42] )
          {
            ++v20;
            v21 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v20 >= 128 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_186;
        }
      case 0x40u:
        if ( (*(_DWORD *)(this + 206779) & 8) == 0 )
          *(_DWORD *)(this + 206779) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v20 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v23 = (_BYTE *)(this + 104117);
        a3 = this + 104117;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v23);
          if ( Byte )
            return Byte;
          v24 = (char *)*((_DWORD *)v5 + 1);
          if ( v24 > &Size[v42] )
            goto LABEL_402;
          if ( v24 != &Size[v42] )
          {
            ++v20;
            v23 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v20 >= 128 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_186:
        *(_DWORD *)(this + 103601) = v20 + 1;
        goto LABEL_397;
      case 0x45u:
        if ( (*(_DWORD *)(this + 206779) & 0x10) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 104629));
        goto LABEL_396;
      case 0x46u:
        if ( (*(_DWORD *)(this + 206779) & 0x20) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v25 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v26 = (_BYTE *)(this + 104633);
        a3 = this + 104633;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v26);
          if ( Byte )
            return Byte;
          v27 = (char *)*((_DWORD *)v5 + 1);
          if ( v27 > &Size[v42] )
            goto LABEL_402;
          if ( v27 != &Size[v42] )
          {
            ++v25;
            v26 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v25 >= 0x1F4 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_210;
        }
      case 0x47u:
        if ( (*(_DWORD *)(this + 206779) & 0x40) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v25 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v28 = (_BYTE *)(this + 106633);
        a3 = this + 106633;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v28);
          if ( Byte )
            return Byte;
          v29 = (char *)*((_DWORD *)v5 + 1);
          if ( v29 > &Size[v42] )
            goto LABEL_402;
          if ( v29 != &Size[v42] )
          {
            ++v25;
            v28 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v25 >= 0x1F4 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_210:
        *(_DWORD *)(this + 104629) = v25 + 1;
        goto LABEL_397;
      case 0x48u:
        if ( (*(_DWORD *)(this + 206779) & 0x80) == 0 )
          *(_DWORD *)(this + 206779) |= 0x80u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10185D80((_DWORD *)(this + 108633), v5, (int)Size);
        goto LABEL_396;
      case 0x49u:
        if ( (*(_DWORD *)(this + 206779) & 0x100) == 0 )
          *(_DWORD *)(this + 206779) |= 0x100u;
        Int32 = TdrBuf::ReadInt64(v5, (_BYTE *)(this + 108757));
        goto LABEL_396;
      case 0x4Au:
        if ( (*(_DWORD *)(this + 206779) & 0x200) == 0 )
          *(_DWORD *)(this + 206779) |= 0x200u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10186BA0(this + 108765, v5, (int)Size);
        goto LABEL_396;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 206779) & 0x400) == 0 )
          *(_DWORD *)(this + 206779) |= 0x400u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1017EEC0(this + 109674, v5, (int)Size);
        goto LABEL_396;
      case 0x4Cu:
        if ( (*(_DWORD *)(this + 206779) & 0x800) == 0 )
          *(_DWORD *)(this + 206779) |= 0x800u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10188290((int *)(this + 109726), (size_t)v5, Size);
        goto LABEL_396;
      case 0x4Du:
        if ( (*(_DWORD *)(this + 206779) & 0x1000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x1000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10114B70(this + 110272, v5, (int)Size);
        goto LABEL_396;
      case 0x4Eu:
        if ( (*(_DWORD *)(this + 206779) & 0x2000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 112238));
        goto LABEL_396;
      case 0x4Fu:
        if ( (*(_DWORD *)(this + 206779) & 0x4000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x4000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v31 = (_BYTE *)(this + 112242);
        a3 = this + 112242;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v31);
          if ( Byte )
            return Byte;
          v32 = (char *)*((_DWORD *)v5 + 1);
          if ( v32 > &Size[v42] )
            goto LABEL_402;
          if ( v32 != &Size[v42] )
          {
            ++v30;
            v31 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_262;
        }
      case 0x50u:
        if ( (*(_DWORD *)(this + 206779) & 0x8000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x8000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        a3 = *((_DWORD *)v5 + 1);
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v5, (_BYTE *)(v30 + this + 112442));
          if ( Byte )
            return Byte;
          v33 = (char *)*((_DWORD *)v5 + 1);
          if ( v33 > &Size[a3] )
            goto LABEL_402;
          if ( v33 != &Size[a3] )
          {
            if ( ++v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          goto LABEL_262;
        }
      case 0x51u:
        if ( (*(_DWORD *)(this + 206779) & 0x10000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v30 = 0;
        v42 = *((_DWORD *)v5 + 1);
        v34 = (_BYTE *)(this + 112492);
        a3 = this + 112492;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v5, v34);
          if ( Byte )
            return Byte;
          v35 = (char *)*((_DWORD *)v5 + 1);
          if ( v35 > &Size[v42] )
            goto LABEL_402;
          if ( v35 != &Size[v42] )
          {
            ++v30;
            v34 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v30 >= 50 )
              goto LABEL_397;
            continue;
          }
          break;
        }
LABEL_262:
        *(_DWORD *)(this + 112238) = v30 + 1;
        goto LABEL_397;
      case 0x52u:
        if ( (*(_DWORD *)(this + 206779) & 0x20000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 112692));
        goto LABEL_396;
      case 0x53u:
        if ( (*(_DWORD *)(this + 206779) & 0x40000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10189FA0((char *)(this + 112696), v5, (int)Size);
        goto LABEL_396;
      case 0x54u:
        if ( (*(_DWORD *)(this + 206779) & 0x80000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x80000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1017FB80((_DWORD *)(this + 149221), v5, (int)Size);
        goto LABEL_396;
      case 0x55u:
        if ( (*(_DWORD *)(this + 206779) & 0x100000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x100000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1015C080((_DWORD *)(this + 149385), v5, Size);
        goto LABEL_396;
      case 0x56u:
        if ( (*(_DWORD *)(this + 206779) & 0x200000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x200000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 149928));
        goto LABEL_396;
      case 0x57u:
        if ( (*(_DWORD *)(this + 206779) & 0x400000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x400000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1015E1B0((_DWORD *)(this + 149932), v5, Size);
        goto LABEL_396;
      case 0x58u:
        if ( (*(_DWORD *)(this + 206779) & 0x800000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x800000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1018B910(this + 151080, v5, (int)Size);
        goto LABEL_396;
      case 0x59u:
        if ( (*(_DWORD *)(this + 206779) & 0x1000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x1000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1015F270(this + 200074, v5, (int)Size);
        goto LABEL_396;
      case 0x5Au:
        if ( (*(_DWORD *)(this + 206779) & 0x2000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x2000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10181560(this + 200115, v5, (int)Size);
        goto LABEL_396;
      case 0x5Bu:
        if ( (*(_DWORD *)(this + 206779) & 0x4000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x4000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1018C730(this + 200147, v5, (int)Size);
        goto LABEL_396;
      case 0x5Cu:
        if ( (*(_DWORD *)(this + 206779) & 0x8000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x8000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1018D250((_DWORD *)(this + 200283), v5, (int)Size);
        goto LABEL_396;
      case 0x5Du:
        if ( (*(_DWORD *)(this + 206779) & 0x10000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x10000000u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10180520((_DWORD *)(this + 204711), v5, (int)Size);
        goto LABEL_396;
      case 0x5Eu:
        if ( (*(_DWORD *)(this + 206779) & 0x20000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x20000000u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 204795));
        goto LABEL_396;
      case 0x5Fu:
        if ( (*(_DWORD *)(this + 206779) & 0x40000000) == 0 )
          *(_DWORD *)(this + 206779) |= 0x40000000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( !Size )
          goto LABEL_403;
        v36 = 0;
        a3 = *((_DWORD *)v5 + 1);
        while ( 2 )
        {
          Byte = sub_10115A30(v5, (_BYTE *)(v36 + this + 204799));
          if ( Byte )
            return Byte;
          v37 = (char *)*((_DWORD *)v5 + 1);
          if ( v37 > &Size[a3] )
            goto LABEL_402;
          if ( v37 != &Size[a3] )
          {
            if ( ++v36 >= 750 )
              goto LABEL_397;
            continue;
          }
          break;
        }
        *(_DWORD *)(this + 204795) = v36 + 1;
        goto LABEL_397;
      case 0x60u:
        if ( *(int *)(this + 206779) >= 0 )
          *(_DWORD *)(this + 206779) |= 0x80000000;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10180CB0(this + 205549, v5, (int)Size);
        goto LABEL_396;
      case 0x61u:
        if ( (*(_BYTE *)(this + 206783) & 1) == 0 )
          *(_DWORD *)(this + 206783) |= 1u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_1018F920((_DWORD *)(this + 205569), v5, (int)Size);
        goto LABEL_396;
      case 0x62u:
        if ( (*(_DWORD *)(this + 206783) & 2) == 0 )
          *(_DWORD *)(this + 206783) |= 2u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10190C60((_DWORD *)(this + 205951), v5, (int)Size);
        goto LABEL_396;
      case 0x63u:
        if ( (*(_DWORD *)(this + 206783) & 4) == 0 )
          *(_DWORD *)(this + 206783) |= 4u;
        Size = 0;
        Byte = TdrBuf::ReadInt32(v5, &Size);
        if ( Byte )
          return Byte;
        if ( !Size )
          goto LABEL_397;
        Int32 = sub_10192B30((_DWORD *)(this + 206131), v5, Size);
LABEL_396:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_397;
        return Byte;
      case 0x64u:
        if ( (*(_DWORD *)(this + 206783) & 8) == 0 )
          *(_DWORD *)(this + 206783) |= 8u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 206691));
        goto LABEL_396;
      case 0x66u:
        if ( (*(_DWORD *)(this + 206783) & 0x10) == 0 )
          *(_DWORD *)(this + 206783) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 206695));
        goto LABEL_396;
      case 0x67u:
        if ( (*(_DWORD *)(this + 206783) & 0x20) == 0 )
          *(_DWORD *)(this + 206783) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v5, (_BYTE *)(this + 206699));
        goto LABEL_396;
      case 0x68u:
        if ( (*(_DWORD *)(this + 206783) & 0x40) == 0 )
          *(_DWORD *)(this + 206783) |= 0x40u;
        Size = 0;
        result = TdrBuf::ReadInt32(v5, &Size);
        if ( result )
          return result;
        if ( Size )
        {
          v38 = 0;
          v41 = *((_DWORD *)v5 + 1);
          a3 = this + 206703;
          while ( 1 )
          {
            v42 = 0;
            Byte = TdrBuf::ReadInt32(v5, &v42);
            if ( Byte )
              return Byte;
            if ( v42 )
            {
              Byte = sub_10193260(a3, v5, v42);
              if ( Byte )
                return Byte;
            }
            v39 = (char *)*((_DWORD *)v5 + 1);
            if ( v39 > &Size[v41] )
              break;
            if ( v39 == &Size[v41] )
            {
              *(_DWORD *)(this + 206699) = v38 + 1;
LABEL_397:
              v7 = v40;
              if ( *((_DWORD *)v5 + 1) >= v40 )
                goto LABEL_398;
              goto LABEL_2;
            }
            a3 += 12;
            if ( ++v38 >= 6 )
              goto LABEL_397;
          }
LABEL_402:
          result = -34;
        }
        else
        {
LABEL_403:
          result = -37;
        }
        break;
      default:
        Int32 = TdrBuf::SkipField(v5, v43 & 0xF);
        goto LABEL_396;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0170::DoDebugFormat
// Address Name: SUB_10199D30
// ============================================================
//----- (10199D30) --------------------------------------------------------
int __thiscall sub_10199D30(void *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10199DE0((int)this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0170::DebugFormat
// Address Name: SUB_10199DE0
// ============================================================
//----- (10199DE0) --------------------------------------------------------
int __thiscall sub_10199DE0(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // ecx
  unsigned __int16 v11; // cx
  int v12; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // ecx
  int v15; // ecx
  int *v16; // ecx
  char *v17; // ecx
  unsigned __int8 *v18; // ecx
  _DWORD *v19; // ecx
  _DWORD *v20; // ecx
  int *v21; // ecx
  unsigned __int8 *v22; // ecx
  char *v23; // ecx
  int *v24; // ecx
  _QWORD *v25; // ecx
  int *v26; // ecx
  unsigned __int8 *v27; // ecx
  _DWORD *v28; // ecx
  unsigned __int8 *v29; // ecx
  int v30; // ecx
  int v31; // eax
  _DWORD *v32; // ecx
  int v33; // ecx
  int v34; // eax
  _DWORD *v35; // ecx
  int v36; // ecx
  int v37; // eax
  _DWORD *v38; // ecx
  int v39; // ecx
  unsigned int v40; // eax
  _DWORD *v41; // ecx
  int v42; // ecx
  unsigned int v43; // eax
  _DWORD *v44; // ecx
  _DWORD *v45; // ecx
  unsigned __int8 *v46; // ecx
  _DWORD *v47; // ecx
  _DWORD *v48; // ecx
  unsigned __int8 *v49; // ecx
  int v50; // ecx
  int v51; // eax
  _DWORD *v52; // ecx
  int v53; // ecx
  int v54; // eax
  int v55; // ecx
  int v56; // eax
  _DWORD *v57; // ecx
  unsigned __int8 *v58; // ecx
  _DWORD *v59; // ecx
  _DWORD *v60; // ecx
  _DWORD *v61; // ecx
  _DWORD *v62; // ecx
  _DWORD *v63; // ecx
  _DWORD *v64; // ecx
  int *v65; // ecx
  _DWORD *v66; // ecx
  _DWORD *v67; // ecx
  int v68; // ecx
  int v69; // eax
  _DWORD *v70; // ecx
  int *v71; // ecx
  _DWORD *v72; // ecx
  _DWORD *v73; // ecx
  int v74; // ecx
  int v75; // [esp+14h] [ebp+8h]
  int v76; // [esp+14h] [ebp+8h]
  int v77; // [esp+14h] [ebp+8h]
  int v78; // [esp+14h] [ebp+8h]
  int v79; // [esp+14h] [ebp+8h]
  int v80; // [esp+14h] [ebp+8h]
  int v81; // [esp+14h] [ebp+8h]
  int v82; // [esp+14h] [ebp+8h]
  int v83; // [esp+14h] [ebp+8h]
  int v84; // [esp+14h] [ebp+8h]
  int v85; // [esp+18h] [ebp+Ch]
  int v86; // [esp+18h] [ebp+Ch]
  int v87; // [esp+18h] [ebp+Ch]
  int v88; // [esp+18h] [ebp+Ch]
  int v89; // [esp+18h] [ebp+Ch]
  int v90; // [esp+18h] [ebp+Ch]
  unsigned int v91; // [esp+18h] [ebp+Ch]
  unsigned int v92; // [esp+18h] [ebp+Ch]
  int v93; // [esp+18h] [ebp+Ch]
  int v94; // [esp+18h] [ebp+Ch]
  int v95; // [esp+18h] [ebp+Ch]
  int v96; // [esp+18h] [ebp+Ch]
  _DWORD *v97; // [esp+18h] [ebp+Ch]

  if ( !"[itemColumnData]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[itemColumnData]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_101644B0((__int16 *)this, a2, a3 + 1, a4) : sub_101644B0((__int16 *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iCreditCount]", "%d", *(_DWORD *)(this + 10));
        if ( !result )
        {
          v9 = *(_DWORD *)(this + 10);
          if ( v9 < 0 )
            return -6;
          if ( v9 > 9 )
            return -7;
          result = sub_1024A3B0(a2, a3, v8, "[creditValue]", v9);
          if ( !result )
          {
            v85 = 0;
            if ( *(int *)(this + 10) <= 0 )
            {
LABEL_19:
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[wGuideStepCount]", "%d", *(unsigned __int16 *)(this + 50));
              if ( result )
                return result;
              v11 = *(_WORD *)(this + 50);
              if ( v11 <= 0x100u )
              {
                LOWORD(v12) = 0;
                v76 = 0;
                if ( v11 )
                {
                  do
                  {
                    v86 = (unsigned __int16)v12;
                    result = sub_1024A230(a2, a3, a4, "[astGuideSteps]", (unsigned __int16)v12);
                    if ( result )
                      return result;
                    result = a3 >= 0
                           ? sub_10166CF0((unsigned __int8 *)(this + 2 * (3 * v86 + 26)), a2, a3 + 1, a4)
                           : sub_10166CF0((unsigned __int8 *)(this + 2 * (3 * v86 + 26)), a2, a3, a4);
                    if ( result )
                      return result;
                    v12 = v76 + 1;
                    v76 = v12;
                  }
                  while ( (unsigned __int16)v12 < *(_WORD *)(this + 50) );
                }
                result = print_structure((int)a2, a3, a4, (int)"[mailInfo]");
                if ( result )
                  return result;
                v13 = (_DWORD *)(this + 1588);
                result = a3 >= 0 ? sub_10171270(v13, a2, a3 + 1, a4) : sub_10171270(v13, a2, a3, a4);
                if ( result )
                  return result;
                result = print_structure((int)a2, a3, a4, (int)"[schedulePrizeInfo]");
                if ( result )
                  return result;
                v14 = (_DWORD *)(this + 1604);
                result = a3 >= 0 ? sub_10172A90(v14, a2, a3 + 1, a4) : sub_10172A90(v14, a2, a3, a4);
                if ( result )
                  return result;
                result = print_structure((int)a2, a3, a4, (int)"[giftBag]");
                if ( result )
                  return result;
                v15 = this + 1716;
                result = a3 >= 0 ? sub_1024CF20(v15, a2, a3 + 1, a4) : sub_1024CF20(v15, a2, a3, a4);
                if ( result )
                  return result;
                result = print_structure((int)a2, a3, a4, (int)"[npcAtd]");
                if ( result )
                  return result;
                v16 = (int *)(this + 2237);
                result = a3 >= 0 ? sub_1022B490(v16, a2, a3 + 1, a4) : sub_1022B490(v16, a2, a3, a4);
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[iCatCuisineID]", "%d", *(_DWORD *)(this + 7173));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[wCatCuisineCount]", "%d", *(unsigned __int16 *)(this + 7177));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[bCatCuisineLevel]", "0x%02x", *(unsigned __int8 *)(this + 7179));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[bCatCuisineBuffs]", "0x%02x", *(unsigned __int8 *)(this + 7180));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[dwCatCuisineLastTm]", "%u", *(_DWORD *)(this + 7181));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[equipTitle]", "%d", *(_DWORD *)(this + 7185));
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[equipTitleBuff]", "%u", *(_DWORD *)(this + 7189));
                if ( result )
                  return result;
                result = print_structure((int)a2, a3, a4, (int)"[guild]");
                if ( result )
                  return result;
                v17 = (char *)(this + 7193);
                result = a3 >= 0 ? sub_10170A60(v17, a2, a3 + 1, a4) : sub_10170A60(v17, a2, a3, a4);
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[videoSize]", "%d", *(unsigned __int16 *)(this + 7454));
                if ( result )
                  return result;
                if ( *(_WORD *)(this + 7454) <= 0x80u )
                {
                  result = sub_1024A3B0(a2, a3, 128, "[video]", *(unsigned __int16 *)(this + 7454));
                  if ( result )
                    return result;
                  v87 = 0;
                  if ( *(_WORD *)(this + 7454) )
                  {
                    do
                    {
                      result = Printf(a2, " %d", *(unsigned __int8 *)((unsigned __int16)result + this + 7456));
                      if ( result )
                        return result;
                      result = v87 + 1;
                      v87 = result;
                    }
                    while ( (unsigned __int16)result < *(_WORD *)(this + 7454) );
                  }
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[stClientSettings]");
                  if ( result )
                    return result;
                  v18 = (unsigned __int8 *)(this + 7584);
                  result = a3 >= 0 ? sub_1016B080(v18, a2, a3 + 1, a4) : sub_1016B080(v18, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[spoor]");
                  if ( result )
                    return result;
                  v19 = (_DWORD *)(this + 8222);
                  result = a3 >= 0 ? sub_101767E0(v19, a2, a3 + 1, a4) : sub_101767E0(v19, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[rapidHunt]");
                  if ( result )
                    return result;
                  v20 = (_DWORD *)(this + 9438);
                  result = a3 >= 0 ? sub_10177E20(v20, a2, a3 + 1, a4) : sub_10177E20(v20, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[activity]");
                  if ( result )
                    return result;
                  v21 = (int *)(this + 9480);
                  result = a3 >= 0 ? sub_10158990(v21, a2, a3 + 1, a4) : sub_10158990(v21, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[itemRebuild]");
                  if ( result )
                    return result;
                  v22 = (unsigned __int8 *)(this + 55937);
                  result = a3 >= 0 ? sub_1017BDC0(v22, a2, a3 + 1, a4) : sub_1017BDC0(v22, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[itemBox]");
                  if ( result )
                    return result;
                  v23 = (char *)(this + 56681);
                  result = a3 >= 0 ? sub_10231D90(v23, a2, a3 + 1, a4) : sub_10231D90(v23, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[shop]");
                  if ( result )
                    return result;
                  v24 = (int *)(this + 59266);
                  result = a3 >= 0 ? sub_102121E0(v24, a2, a3 + 1, a4) : sub_102121E0(v24, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[catTreature]");
                  if ( result )
                    return result;
                  v25 = (_QWORD *)(this + 82986);
                  result = a3 >= 0 ? sub_1017E4A0(v25, a2, a3 + 1, a4) : sub_1017E4A0(v25, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[normalLimitInfo]");
                  if ( result )
                    return result;
                  v26 = (int *)(this + 83015);
                  result = a3 >= 0 ? sub_10183620(v26, a2, a3 + 1, a4) : sub_10183620(v26, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[reportInfo]");
                  if ( result )
                    return result;
                  v27 = (unsigned __int8 *)(this + 84039);
                  result = a3 >= 0 ? sub_10184DE0(v27, a2, a3 + 1, a4) : sub_10184DE0(v27, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[trace]");
                  if ( result )
                    return result;
                  v28 = (_DWORD *)(this + 84173);
                  result = a3 >= 0 ? sub_1017DA00(v28, a2, a3 + 1, a4) : sub_1017DA00(v28, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_structure((int)a2, a3, a4, (int)"[equipPlan]");
                  if ( result )
                    return result;
                  v29 = (unsigned __int8 *)(this + 88631);
                  result = a3 >= 0 ? sub_10112060(v29, a2, a3 + 1, a4) : sub_10112060(v29, a2, a3, a4);
                  if ( result )
                    return result;
                  result = print_field(a2, a3, a4, "[shortcutCount]", "%d", *(_DWORD *)(this + 103357));
                  if ( result )
                    return result;
                  v31 = *(_DWORD *)(this + 103357);
                  if ( v31 < 0 )
                    return -6;
                  if ( v31 <= 60 )
                  {
                    result = sub_1024A3B0(a2, a3, v30, "[shortcutData]", v31);
                    if ( result )
                      return result;
                    v88 = 0;
                    if ( *(int *)(this + 103357) > 0 )
                    {
                      v32 = (_DWORD *)(this + 103361);
                      v77 = this + 103361;
                      do
                      {
                        result = Printf(a2, " %d", *v32);
                        if ( result )
                          return result;
                        v32 = (_DWORD *)(v77 + 4);
                        ++v88;
                        v77 += 4;
                      }
                      while ( v88 < *(_DWORD *)(this + 103357) );
                    }
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( result )
                      return result;
                    result = print_field(a2, a3, a4, "[catCuisineFormulaCount]", "%d", *(_DWORD *)(this + 103601));
                    if ( result )
                      return result;
                    v34 = *(_DWORD *)(this + 103601);
                    if ( v34 < 0 )
                      return -6;
                    if ( v34 <= 128 )
                    {
                      result = sub_1024A3B0(a2, a3, v33, "[catCuisineID]", v34);
                      if ( result )
                        return result;
                      v89 = 0;
                      if ( *(int *)(this + 103601) > 0 )
                      {
                        v35 = (_DWORD *)(this + 103605);
                        v78 = this + 103605;
                        do
                        {
                          result = Printf(a2, " %d", *v35);
                          if ( result )
                            return result;
                          v35 = (_DWORD *)(v78 + 4);
                          ++v89;
                          v78 += 4;
                        }
                        while ( v89 < *(_DWORD *)(this + 103601) );
                      }
                      result = TdrBuf::WriteChar(a2, a4);
                      if ( result )
                        return result;
                      v37 = *(_DWORD *)(this + 103601);
                      if ( v37 < 0 )
                        return -6;
                      if ( v37 <= 128 )
                      {
                        result = sub_1024A3B0(a2, a3, v36, "[catCuisineState]", v37);
                        if ( result )
                          return result;
                        v90 = 0;
                        if ( *(int *)(this + 103601) > 0 )
                        {
                          v38 = (_DWORD *)(this + 104117);
                          v79 = this + 104117;
                          do
                          {
                            result = Printf(a2, " %u", *v38);
                            if ( result )
                              return result;
                            v38 = (_DWORD *)(v79 + 4);
                            ++v90;
                            v79 += 4;
                          }
                          while ( v90 < *(_DWORD *)(this + 103601) );
                        }
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( result )
                          return result;
                        result = print_field(a2, a3, a4, "[titleInfoCount]", "%u", *(_DWORD *)(this + 104629));
                        if ( result )
                          return result;
                        v40 = *(_DWORD *)(this + 104629);
                        if ( v40 <= 0x1F4 )
                        {
                          result = sub_1024A3B0(a2, a3, v39, "[titleID]", v40);
                          if ( result )
                            return result;
                          v91 = 0;
                          if ( *(_DWORD *)(this + 104629) )
                          {
                            v41 = (_DWORD *)(this + 104633);
                            v80 = this + 104633;
                            do
                            {
                              result = Printf(a2, " %d", *v41);
                              if ( result )
                                return result;
                              v41 = (_DWORD *)(v80 + 4);
                              ++v91;
                              v80 += 4;
                            }
                            while ( v91 < *(_DWORD *)(this + 104629) );
                          }
                          result = TdrBuf::WriteChar(a2, a4);
                          if ( result )
                            return result;
                          v43 = *(_DWORD *)(this + 104629);
                          if ( v43 <= 0x1F4 )
                          {
                            result = sub_1024A3B0(a2, a3, v42, "[titleUnlockTime]", v43);
                            if ( result )
                              return result;
                            v92 = 0;
                            if ( *(_DWORD *)(this + 104629) )
                            {
                              v44 = (_DWORD *)(this + 106633);
                              v81 = this + 106633;
                              do
                              {
                                result = Printf(a2, " %u", *v44);
                                if ( result )
                                  return result;
                                v44 = (_DWORD *)(v81 + 4);
                                ++v92;
                                v81 += 4;
                              }
                              while ( v92 < *(_DWORD *)(this + 104629) );
                            }
                            result = TdrBuf::WriteChar(a2, a4);
                            if ( result )
                              return result;
                            result = print_structure((int)a2, a3, a4, (int)"[starStoneData]");
                            if ( result )
                              return result;
                            v45 = (_DWORD *)(this + 108633);
                            result = a3 >= 0 ? sub_10186050(v45, a2, a3 + 1, a4) : sub_10186050(v45, a2, a3, a4);
                            if ( result )
                              return result;
                            result = print_field(a2, a3, a4, "[dataRepairFlag]", "%I64u", *(_QWORD *)(this + 108757));
                            if ( result )
                              return result;
                            result = print_structure((int)a2, a3, a4, (int)"[itemSnapshot]");
                            if ( result )
                              return result;
                            v46 = (unsigned __int8 *)(this + 108765);
                            result = a3 >= 0 ? sub_10186F20(v46, a2, a3 + 1, a4) : sub_10186F20(v46, a2, a3, a4);
                            if ( result )
                              return result;
                            result = print_structure((int)a2, a3, a4, (int)"[personalLeagueData]");
                            if ( result )
                              return result;
                            v47 = (_DWORD *)(this + 109674);
                            result = a3 >= 0 ? sub_1017F1E0(v47, a2, a3 + 1, a4) : sub_1017F1E0(v47, a2, a3, a4);
                            if ( result )
                              return result;
                            result = print_structure((int)a2, a3, a4, (int)"[speak]");
                            if ( result )
                              return result;
                            v48 = (_DWORD *)(this + 109726);
                            result = a3 >= 0 ? sub_10188850(v48, a2, a3 + 1, a4) : sub_10188850(v48, a2, a3, a4);
                            if ( result )
                              return result;
                            result = print_structure((int)a2, a3, a4, (int)"[supplyPlanData]");
                            if ( result )
                              return result;
                            v49 = (unsigned __int8 *)(this + 110272);
                            result = a3 >= 0 ? sub_10114E80(v49, a2, a3 + 1, a4) : sub_10114E80(v49, a2, a3, a4);
                            if ( result )
                              return result;
                            result = print_field(a2, a3, a4, "[cDCount]", "%d", *(_DWORD *)(this + 112238));
                            if ( result )
                              return result;
                            v51 = *(_DWORD *)(this + 112238);
                            if ( v51 < 0 )
                              return -6;
                            if ( v51 <= 50 )
                            {
                              result = sub_1024A3B0(a2, a3, v50, "[cDGroupID]", v51);
                              if ( result )
                                return result;
                              v93 = 0;
                              if ( *(int *)(this + 112238) > 0 )
                              {
                                v52 = (_DWORD *)(this + 112242);
                                v82 = this + 112242;
                                do
                                {
                                  result = Printf(a2, " %d", *v52);
                                  if ( result )
                                    return result;
                                  v52 = (_DWORD *)(v82 + 4);
                                  ++v93;
                                  v82 += 4;
                                }
                                while ( v93 < *(_DWORD *)(this + 112238) );
                              }
                              result = TdrBuf::WriteChar(a2, a4);
                              if ( result )
                                return result;
                              v54 = *(_DWORD *)(this + 112238);
                              if ( v54 < 0 )
                                return -6;
                              if ( v54 <= 50 )
                              {
                                result = sub_1024A3B0(a2, a3, v53, "[cDType]", v54);
                                if ( result )
                                  return result;
                                v94 = 0;
                                if ( *(int *)(this + 112238) > 0 )
                                {
                                  do
                                  {
                                    result = Printf(a2, " 0x%02x", *(unsigned __int8 *)(this + result + 112442));
                                    if ( result )
                                      return result;
                                    result = v94 + 1;
                                    v94 = result;
                                  }
                                  while ( result < *(_DWORD *)(this + 112238) );
                                }
                                result = TdrBuf::WriteChar(a2, a4);
                                if ( result )
                                  return result;
                                v56 = *(_DWORD *)(this + 112238);
                                if ( v56 < 0 )
                                  return -6;
                                if ( v56 <= 50 )
                                {
                                  result = sub_1024A3B0(a2, a3, v55, "[cDTime]", v56);
                                  if ( result )
                                    return result;
                                  v95 = 0;
                                  if ( *(int *)(this + 112238) > 0 )
                                  {
                                    v57 = (_DWORD *)(this + 112492);
                                    v83 = this + 112492;
                                    do
                                    {
                                      result = Printf(a2, " %u", *v57);
                                      if ( result )
                                        return result;
                                      v57 = (_DWORD *)(v83 + 4);
                                      ++v95;
                                      v83 += 4;
                                    }
                                    while ( v95 < *(_DWORD *)(this + 112238) );
                                  }
                                  result = TdrBuf::WriteChar(a2, a4);
                                  if ( result )
                                    return result;
                                  result = print_field(a2, a3, a4, "[creditVersion]", "%d", *(_DWORD *)(this + 112692));
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[equipSuitSkill]");
                                  if ( result )
                                    return result;
                                  v58 = (unsigned __int8 *)(this + 112696);
                                  result = a3 >= 0 ? sub_1018A240(v58, a2, a3 + 1, a4) : sub_1018A240(v58, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[weaponTrial]");
                                  if ( result )
                                    return result;
                                  v59 = (_DWORD *)(this + 149221);
                                  result = a3 >= 0 ? sub_1017FDD0(v59, a2, a3 + 1, a4) : sub_1017FDD0(v59, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[astrolabe]");
                                  if ( result )
                                    return result;
                                  v60 = (_DWORD *)(this + 149385);
                                  result = a3 >= 0 ? sub_1015C6C0(v60, a2, a3 + 1, a4) : sub_1015C6C0(v60, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[creditNoChangeCount]",
                                             "%d",
                                             *(_DWORD *)(this + 149928));
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[wildHunt]");
                                  if ( result )
                                    return result;
                                  v61 = (_DWORD *)(this + 149932);
                                  result = a3 >= 0 ? sub_1015E6B0(v61, a2, a3 + 1, a4) : sub_1015E6B0(v61, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[soulStone]");
                                  if ( result )
                                    return result;
                                  v62 = (_DWORD *)(this + 151080);
                                  result = a3 >= 0 ? sub_1018BE50(v62, a2, a3 + 1, a4) : sub_1018BE50(v62, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[monolopy]");
                                  if ( result )
                                    return result;
                                  v63 = (_DWORD *)(this + 200074);
                                  result = a3 >= 0 ? sub_1015F5A0(v63, a2, a3 + 1, a4) : sub_1015F5A0(v63, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[growHigher]");
                                  if ( result )
                                    return result;
                                  v64 = (_DWORD *)(this + 200115);
                                  result = a3 >= 0 ? sub_101817B0(v64, a2, a3 + 1, a4) : sub_101817B0(v64, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[achieve]");
                                  if ( result )
                                    return result;
                                  v65 = (int *)(this + 200147);
                                  result = a3 >= 0 ? sub_1018C980(v65, a2, a3 + 1, a4) : sub_1018C980(v65, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[illustrate]");
                                  if ( result )
                                    return result;
                                  v66 = (_DWORD *)(this + 200283);
                                  result = a3 >= 0 ? sub_1018D540(v66, a2, a3 + 1, a4) : sub_1018D540(v66, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[weaponStyle]");
                                  if ( result )
                                    return result;
                                  v67 = (_DWORD *)(this + 204711);
                                  result = a3 >= 0 ? sub_101806E0(v67, a2, a3 + 1, a4) : sub_101806E0(v67, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[weaponHavenInfoCount]",
                                             "%d",
                                             *(_DWORD *)(this + 204795));
                                  if ( result )
                                    return result;
                                  v69 = *(_DWORD *)(this + 204795);
                                  if ( v69 < 0 )
                                    return -6;
                                  if ( v69 <= 750 )
                                  {
                                    result = sub_1024A3B0(a2, a3, v68, "[weaponHavenInfo]", v69);
                                    if ( result )
                                      return result;
                                    v96 = 0;
                                    if ( *(int *)(this + 204795) > 0 )
                                    {
                                      do
                                      {
                                        result = Printf(a2, " 0x%02x", *(char *)(this + result + 204799));
                                        if ( result )
                                          return result;
                                        result = v96 + 1;
                                        v96 = result;
                                      }
                                      while ( result < *(_DWORD *)(this + 204795) );
                                    }
                                    result = TdrBuf::WriteChar(a2, a4);
                                    if ( result )
                                      return result;
                                    result = print_structure((int)a2, a3, a4, (int)"[silverStorageBox]");
                                    if ( result )
                                      return result;
                                    v70 = (_DWORD *)(this + 205549);
                                    result = a3 >= 0 ? sub_10180E80(v70, a2, a3 + 1, a4) : sub_10180E80(v70, a2, a3, a4);
                                    if ( result )
                                      return result;
                                    result = print_structure((int)a2, a3, a4, (int)"[guideBook]");
                                    if ( result )
                                      return result;
                                    v71 = (int *)(this + 205569);
                                    result = a3 >= 0 ? sub_1018FC30(v71, a2, a3 + 1, a4) : sub_1018FC30(v71, a2, a3, a4);
                                    if ( result )
                                      return result;
                                    result = print_structure((int)a2, a3, a4, (int)"[monsterTalkData]");
                                    if ( result )
                                      return result;
                                    v72 = (_DWORD *)(this + 205951);
                                    result = a3 >= 0 ? sub_10190F10(v72, a2, a3 + 1, a4) : sub_10190F10(v72, a2, a3, a4);
                                    if ( result )
                                      return result;
                                    result = print_structure((int)a2, a3, a4, (int)"[secretResearchData]");
                                    if ( result )
                                      return result;
                                    v73 = (_DWORD *)(this + 206131);
                                    result = a3 >= 0 ? sub_10192D70(v73, a2, a3 + 1, a4) : sub_10192D70(v73, a2, a3, a4);
                                    if ( result )
                                      return result;
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[dragonBoxShopID]",
                                               "%d",
                                               *(_DWORD *)(this + 206691));
                                    if ( result )
                                      return result;
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[rewardActivityCost]",
                                               "%d",
                                               *(_DWORD *)(this + 206695));
                                    if ( result )
                                      return result;
                                    result = print_field(a2, a3, a4, "[count]", "%d", *(_DWORD *)(this + 206699));
                                    if ( result )
                                      return result;
                                    v74 = *(_DWORD *)(this + 206699);
                                    if ( v74 < 0 )
                                      return -6;
                                    if ( v74 <= 6 )
                                    {
                                      v84 = 0;
                                      if ( v74 <= 0 )
                                        return 0;
                                      v97 = (_DWORD *)(this + 206703);
                                      while ( 1 )
                                      {
                                        result = sub_1024A230(a2, a3, a4, "[rewardActivityState]", result);
                                        if ( result )
                                          break;
                                        result = a3 >= 0
                                               ? sub_10193400(v97, a2, a3 + 1, a4)
                                               : sub_10193400(v97, a2, a3, a4);
                                        if ( result )
                                          break;
                                        v97 += 3;
                                        result = v84 + 1;
                                        v84 = result;
                                        if ( result >= *(_DWORD *)(this + 206699) )
                                          return 0;
                                      }
                                      return result;
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
              return -7;
            }
            v10 = (_DWORD *)(this + 14);
            v75 = this + 14;
            while ( 1 )
            {
              result = Printf(a2, " %d", *v10);
              if ( result )
                break;
              v10 = (_DWORD *)(v75 + 4);
              ++v85;
              v75 += 4;
              if ( v85 >= *(_DWORD *)(this + 10) )
                goto LABEL_19;
            }
          }
        }
      }
    }
  }
  return result;
}
// 10199EB2: variable 'v8' is possibly undefined
// 1019A5E1: variable 'v30' is possibly undefined
// 1019A692: variable 'v33' is possibly undefined
// 1019A71E: variable 'v36' is possibly undefined
// 1019A7C7: variable 'v39' is possibly undefined
// 1019A850: variable 'v42' is possibly undefined
// 1019AA65: variable 'v50' is possibly undefined
// 1019AAF6: variable 'v53' is possibly undefined
// 1019AB75: variable 'v55' is possibly undefined
// 1019AEED: variable 'v68' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024C9D0
// ============================================================
//----- (1024C9D0) --------------------------------------------------------
int __thiscall sub_1024C9D0(int this, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = (_DWORD *)a2;
  v5 = this;
  VarInt = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 517) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_36;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v5 + 517) & 1) == 0 )
          *(_DWORD *)(v5 + 517) |= 1u;
        a2 = 0;
        VarInt = TdrBuf::ReadInt32(v4, &a2);
        if ( VarInt )
          return VarInt;
        if ( !a2 )
          goto LABEL_35;
        Byte_2 = sub_1024C0C0((_DWORD *)v5, v4, a2);
        goto LABEL_34;
      case 3u:
        if ( (*(_DWORD *)(v5 + 517) & 2) == 0 )
          *(_DWORD *)(v5 + 517) |= 2u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v5 + 16));
        goto LABEL_34;
      case 4u:
        if ( (*(_DWORD *)(v5 + 517) & 4) == 0 )
          *(_DWORD *)(v5 + 517) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(v16 + 4 * v10 + 17));
          if ( VarInt )
            return VarInt;
          v11 = v4[1];
          if ( v11 > a3 + a2 )
            return -34;
          if ( v11 == a3 + a2 )
            goto LABEL_22;
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
        goto LABEL_35;
      case 5u:
        if ( (*(_DWORD *)(v5 + 517) & 8) == 0 )
          *(_DWORD *)(v5 + 517) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          VarInt = TdrBuf::ReadByte_2(v4, (_BYTE *)(v16 + 417 + v10));
          if ( VarInt )
            return VarInt;
          v13 = v4[1];
          if ( v13 > a3 + a2 )
            return -34;
          if ( v13 == a3 + a2 )
          {
LABEL_22:
            v12 = v16;
            *(_BYTE *)(v16 + 16) = v10 + 1;
            v5 = v12;
            goto LABEL_35;
          }
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
LABEL_35:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_36:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_34:
        VarInt = Byte_2;
        if ( !Byte_2 )
          goto LABEL_35;
        return VarInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10190A80
// ============================================================
//----- (10190A80) --------------------------------------------------------
int __thiscall sub_10190A80(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  char *v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 44) = 0;
  v15 = 0;
  v7 = (char *)v3 + v6[1];
  v12 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_28:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[44] & 1) == 0 )
          v4[44] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[44] & 2) == 0 )
          v4[44] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_7;
      case 3u:
        if ( (v4[44] & 4) == 0 )
          v4[44] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_7;
      case 4u:
        if ( (v4[44] & 8) == 0 )
          v4[44] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = v16 + 3;
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_101901B0(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 5;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= (unsigned int)v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[44] & 0x10) == 0 )
          v4[44] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 43);
        goto LABEL_7;
      default:
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101931C0
// ============================================================
//----- (101931C0) --------------------------------------------------------
int __thiscall sub_101931C0(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018D030
// ============================================================
//----- (1018D030) --------------------------------------------------------
int __thiscall sub_1018D030(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarUInt; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  _DWORD *v10; // ebx
  int v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // esi
  _DWORD *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h] BYREF
  int *v18; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarUInt = 0;
  v6 = a2;
  v18 = this;
  *(this + 1106) = 0;
  v17 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_35;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 1106) & 1) == 0 )
          *(this + 1106) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, this);
        goto LABEL_33;
      case 2u:
        if ( (*(this + 1106) & 2) == 0 )
          *(this + 1106) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v10 = a2;
        if ( !a2 )
          return -37;
        v11 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = sub_10115A30(v6, (_BYTE *)v18 + v11 + 4);
          if ( VarUInt )
            return VarUInt;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 320 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        *v18 = v11 + 1;
        goto LABEL_34;
      case 3u:
        if ( (*(this + 1106) & 4) == 0 )
          *(this + 1106) |= 4u;
        VarInt = TdrBuf::ReadVarUInt(v6, this + 81);
        goto LABEL_33;
      case 4u:
        if ( (*(this + 1106) & 8) == 0 )
          *(this + 1106) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = v6[1];
        v14 = this + 82;
        while ( 1 )
        {
          VarUInt = TdrBuf::ReadVarUInt(v6, v14);
          if ( VarUInt )
            return VarUInt;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v13;
          ++v14;
          if ( v13 >= 0x400 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        v18[81] = v13 + 1;
LABEL_34:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_35:
        if ( v6[1] > v7 )
          return -34;
        return VarUInt;
      default:
        VarInt = TdrBuf::SkipField(v6, v17 & 0xF);
LABEL_33:
        VarUInt = VarInt;
        if ( !VarInt )
          goto LABEL_34;
        return VarUInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_1017B710
// ============================================================
//----- (1017B710) --------------------------------------------------------
int __thiscall sub_1017B710(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned __int8 v9; // bl
  unsigned int v10; // edx
  int v11; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v12; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+14h] [ebp-Ch] BYREF
  int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  result = 0;
  v12 = 0;
  *(_DWORD *)(this + 740) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 5u:
        if ( (*(_BYTE *)(this + 740) & 1) == 0 )
          *(_DWORD *)(this + 740) |= 1u;
        result = TdrBuf::ReadByte_2(a2, (_BYTE *)this);
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(this + 740) & 2) == 0 )
          *(_DWORD *)(this + 740) |= 2u;
        result = TdrBuf::ReadVarULong(a2, (_DWORD *)(this + 1));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(this + 740) & 4) == 0 )
          *(_DWORD *)(this + 740) |= 4u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v6 = 0;
        v13 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte_2(a2, (_BYTE *)(this + v6 + 9));
          if ( result )
            return result;
          v7 = a2[1];
          if ( v7 > v13 + v11 )
            return -34;
          if ( v7 != v13 + v11 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_49;
            continue;
          }
          goto LABEL_20;
        }
      case 8u:
        if ( (*(_DWORD *)(this + 740) & 8) == 0 )
          *(_DWORD *)(this + 740) |= 8u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v6 = 0;
        v13 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadVarInt(a2, (int *)(this + 4 * v6 + 17));
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v13 + v11 )
            return -34;
          if ( v8 != v13 + v11 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_49;
            continue;
          }
          break;
        }
LABEL_20:
        *(_BYTE *)this = v6 + 1;
        goto LABEL_49;
      case 9u:
        if ( (*(_DWORD *)(this + 740) & 0x10) == 0 )
          *(_DWORD *)(this + 740) |= 0x10u;
        result = TdrBuf::ReadByte_2(a2, (_BYTE *)(this + 49));
        goto LABEL_48;
      case 0xAu:
        if ( (*(_DWORD *)(this + 740) & 0x20) == 0 )
          *(_DWORD *)(this + 740) |= 0x20u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v9 = 0;
        v14 = a2[1];
        while ( 1 )
        {
          v13 = 0;
          result = TdrBuf::ReadInt32(a2, &v13);
          if ( result )
            return result;
          if ( v13 )
          {
            result = sub_10179DE0(69 * v9 + this + 50, a2, v13);
            if ( result )
              return result;
          }
          v10 = a2[1];
          if ( v10 > v14 + v11 )
            return -34;
          if ( v10 == v14 + v11 )
            break;
          if ( ++v9 >= 0xAu )
            goto LABEL_49;
        }
        *(_BYTE *)(this + 49) = v9 + 1;
LABEL_49:
        v5 = v15;
        if ( a2[1] < v15 )
          continue;
LABEL_50:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_48:
        if ( !result )
          goto LABEL_49;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101669B0
// ============================================================
//----- (101669B0) --------------------------------------------------------
int __thiscall sub_101669B0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101813E0
// ============================================================
//----- (101813E0) --------------------------------------------------------
int __thiscall sub_101813E0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 7) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 7) & 1) == 0 )
            *(this + 7) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 7) & 2) == 0 )
            *(this + 7) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 7) & 4) == 0 )
            *(this + 7) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 7) & 8) == 0 )
            *(this + 7) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 7) & 0x10) == 0 )
            *(this + 7) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 7) & 0x20) == 0 )
            *(this + 7) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 7) & 0x40) == 0 )
            *(this + 7) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 6);
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
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101929C0
// ============================================================
//----- (101929C0) --------------------------------------------------------
int __thiscall sub_101929C0(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int VarInt; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int *v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  int *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  VarInt = 0;
  v6 = a2;
  v15 = this;
  *(this + 139) = 0;
  v14 = 0;
  v7 = (char *)v3 + v6[1];
  v11 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return VarInt;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v4[139] & 1) == 0 )
          v4[139] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v6[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          VarInt = TdrBuf::ReadInt32(v6, &v13);
          if ( VarInt )
            return VarInt;
          if ( v13 )
          {
            VarInt = sub_10191D40(a3, v6, v13);
            if ( VarInt )
              return VarInt;
          }
          v10 = v6[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 46;
            if ( (unsigned int)++v9 < 3 )
              continue;
          }
          v4 = v15;
          goto LABEL_23;
        }
      }
      if ( v14 >> 4 == 2 )
      {
        if ( (v4[139] & 2) == 0 )
          v4[139] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 138);
        if ( VarInt )
          return VarInt;
      }
      else
      {
        VarInt = TdrBuf::SkipField(v6, v14 & 0xF);
        if ( VarInt )
          return VarInt;
      }
LABEL_23:
      v7 = v11;
      if ( v6[1] >= (unsigned int)v11 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017EC70
// ============================================================
//----- (1017EC70) --------------------------------------------------------
int __thiscall sub_1017EC70(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 12) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_43:
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(this + 12) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 12) & 2) == 0 )
            *(this + 12) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 12) & 4) == 0 )
            *(this + 12) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 12) & 8) == 0 )
            *(this + 12) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 12) & 0x10) == 0 )
            *(this + 12) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 12) & 0x20) == 0 )
            *(this + 12) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 12) & 0x40) == 0 )
            *(this + 12) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 6);
          break;
        case 8u:
          if ( (*(this + 12) & 0x80) == 0 )
            *(this + 12) |= 0x80u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 7);
          break;
        case 9u:
          if ( (*(this + 12) & 0x100) == 0 )
            *(this + 12) |= 0x100u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 8);
          break;
        case 0xAu:
          if ( (*(this + 12) & 0x200) == 0 )
            *(this + 12) |= 0x200u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 9);
          break;
        case 0xBu:
          if ( (*(this + 12) & 0x400) == 0 )
            *(this + 12) |= 0x400u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 10);
          break;
        case 0xCu:
          if ( (*(this + 12) & 0x800) == 0 )
            *(this + 12) |= 0x800u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 11);
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
        goto LABEL_43;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10189DD0
// ============================================================
//----- (10189DD0) --------------------------------------------------------
int __thiscall sub_10189DD0(char *this, _DWORD *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+14h] [ebp-14h] BYREF
  unsigned int v12; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp-8h]
  unsigned int v15; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v12 = 0;
  *(_DWORD *)(this + 36521) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_27:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v12);
      if ( result )
        break;
      if ( v12 >> 4 == 1 )
      {
        if ( (v3[36521] & 1) == 0 )
          *(_DWORD *)(v3 + 36521) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v4 = 0;
      }
      else
      {
        if ( v12 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 36521) & 2) == 0 )
            *(_DWORD *)(v3 + 36521) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v14 = a2[1];
          while ( 1 )
          {
            v13 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v13);
            if ( v4 )
              return v4;
            if ( v13 )
            {
              v4 = sub_101891C0((int)(this + 913 * v7 + 1), a2, v13);
              if ( v4 )
                return v4;
            }
            v8 = a2[1];
            if ( v8 > v14 + v11 )
              return -34;
            if ( v8 == v14 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            if ( ++v7 >= 0x28u )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v12 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v15;
      if ( a2[1] >= v15 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016ABF0
// ============================================================
//----- (1016ABF0) --------------------------------------------------------
int __thiscall sub_1016ABF0(int this, _DWORD *Size, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 634) = 0;
  v5 = Size[1] + a3;
  v10 = v5;
  if ( Size[1] >= v5 )
  {
LABEL_27:
    if ( Size[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(Size, &v8);
      if ( result )
        break;
      switch ( v8 >> 4 )
      {
        case 2u:
          if ( (*(_BYTE *)(this + 634) & 1) == 0 )
            *(_DWORD *)(this + 634) |= 1u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10167BB0(this, Size, v9);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 634) & 2) == 0 )
            *(_DWORD *)(this + 634) |= 2u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_101684B0((_DWORD *)(this + 585), Size, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 634) & 4) == 0 )
            *(_DWORD *)(this + 634) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_101691E0(this + 597, Size, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 634) & 8) == 0 )
            *(_DWORD *)(this + 634) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_1016A260((char *)(this + 625), Size, v9);
          break;
        default:
          v7 = TdrBuf::SkipField(Size, v8 & 0xF);
          break;
      }
      v4 = v7;
      if ( v7 )
        return v4;
LABEL_26:
      v5 = v10;
      if ( Size[1] >= v10 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101725E0
// ============================================================
//----- (101725E0) --------------------------------------------------------
int __thiscall sub_101725E0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarInt; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // esi
  int *v11; // ebx
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarInt = 0;
  v6 = a2;
  v17 = this;
  *(this + 27) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 27) & 1) == 0 )
          *(this + 27) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, this);
        goto LABEL_32;
      case 4u:
        if ( (*(this + 27) & 2) == 0 )
          *(this + 27) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v6, this + 1);
        goto LABEL_32;
      case 5u:
        if ( (*(this + 27) & 4) == 0 )
          *(this + 27) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        v11 = this + 2;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v6, v11);
          if ( VarInt )
            return VarInt;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
          ++v11;
        }
        while ( v10 < 20 );
        this = v17;
        goto LABEL_33;
      case 6u:
        if ( (*(this + 27) & 8) == 0 )
          *(this + 27) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v10 = 0;
        a2 = (_DWORD *)v6[1];
        do
        {
          VarInt = TdrBuf::ReadByte(v6, (_BYTE *)v17 + v10 + 88);
          if ( VarInt )
            return VarInt;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
          {
LABEL_20:
            this = v17;
            v17[1] = v10 + 1;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 20 );
        this = v17;
LABEL_33:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_34:
        if ( v6[1] > v7 )
          return -34;
        return VarInt;
      default:
        VarUInt = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_32:
        VarInt = VarUInt;
        if ( !VarUInt )
          goto LABEL_33;
        return VarInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10180BB0
// ============================================================
//----- (10180BB0) --------------------------------------------------------
int __thiscall sub_10180BB0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
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
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
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
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10111B10
// ============================================================
//----- (10111B10) --------------------------------------------------------
int __thiscall sub_10111B10(int this, _DWORD *Size, int a3)
{
  int v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v12; // [esp+14h] [ebp-14h] BYREF
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 14722) = 0;
  v5 = Size[1] + a3;
  for ( i = v5; ; v5 = i )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_2:
        if ( Size[1] >= v5 )
        {
          if ( Size[1] > v5 )
            return -34;
          return v4;
        }
        result = TdrBuf::ReadVarUInt(Size, &v13);
        if ( result )
          return result;
        if ( v13 >> 4 != 1 )
          break;
        if ( (*(_BYTE *)(v3 + 14722) & 1) == 0 )
          *(_DWORD *)(v3 + 14722) |= 1u;
        if ( Size[1] > Size[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = Size[1];
        if ( Size[2] == v10 )
          return -2;
        *(_BYTE *)v3 = *(_BYTE *)(v10 + *Size);
        ++Size[1];
        v4 = 0;
        v5 = i;
      }
      if ( v13 >> 4 != 2 )
        break;
      if ( (*(_DWORD *)(v3 + 14722) & 2) == 0 )
        *(_DWORD *)(v3 + 14722) |= 2u;
      if ( Size[1] > Size[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = Size[1];
      if ( Size[2] == v9 )
        return -2;
      *(_BYTE *)(v3 + 1) = *(_BYTE *)(v9 + *Size);
      ++Size[1];
      v4 = 0;
      v5 = i;
    }
    if ( v13 >> 4 == 3 )
      break;
    v4 = TdrBuf::SkipField(Size, v13 & 0xF);
    if ( v4 )
      return v4;
  }
  if ( (*(_DWORD *)(v3 + 14722) & 4) == 0 )
    *(_DWORD *)(v3 + 14722) |= 4u;
  v12 = 0;
  result = TdrBuf::ReadInt32(Size, &v12);
  if ( !result )
  {
    if ( !v12 )
      return -37;
    v7 = 0;
    v15 = Size[1];
    while ( 1 )
    {
      v14 = 0;
      v4 = TdrBuf::ReadInt32(Size, &v14);
      if ( v4 )
        return v4;
      if ( v14 )
      {
        v4 = sub_10110EE0((_DWORD *)(736 * v7 + this + 2), (size_t)Size, v14);
        if ( v4 )
          return v4;
      }
      v8 = Size[1];
      if ( v8 > v15 + v12 )
        return -34;
      if ( v8 == v15 + v12 )
      {
        *(_BYTE *)(this + 1) = v7 + 1;
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
      if ( ++v7 >= 0x14u )
      {
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_1015DD80
// ============================================================
//----- (1015DD80) --------------------------------------------------------
int __thiscall sub_1015DD80(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // ebx
  int *v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  char *v26; // [esp+Ch] [ebp-14h]
  int v27; // [esp+10h] [ebp-10h] BYREF
  int v28; // [esp+14h] [ebp-Ch]
  unsigned int v29; // [esp+18h] [ebp-8h] BYREF
  int *v30; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v30 = this;
  *(this + 286) = 0;
  v29 = 0;
  v7 = (char *)v3 + v6[1];
  v26 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_68;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v29);
    if ( result )
      return result;
    switch ( v29 >> 4 )
    {
      case 1u:
        if ( (v4[286] & 1) == 0 )
          v4[286] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_66;
      case 2u:
        if ( (v4[286] & 2) == 0 )
          v4[286] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_66;
      case 3u:
        if ( (v4[286] & 4) == 0 )
          v4[286] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v28 = v6[1];
        v11 = v30 + 2;
        a3 = v30 + 2;
        do
        {
          v5 = TdrBuf::ReadVarInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v28) )
            goto LABEL_20;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 5 );
        v4 = v30;
        goto LABEL_67;
      case 4u:
        if ( (v4[286] & 8) == 0 )
          v4[286] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v28 = v6[1];
        a3 = v30 + 7;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v27);
          v15 = a3;
          v5 = v14;
          if ( v14 )
            return v5;
          v16 = (char *)a2 + v28;
          *a3 = v27;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
          {
LABEL_20:
            v13 = v10 + 1;
            v4 = v30;
            v30[1] = v13;
            goto LABEL_67;
          }
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 5 );
        v4 = v30;
        goto LABEL_67;
      case 5u:
        if ( (v4[286] & 0x10) == 0 )
          v4[286] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 12);
        goto LABEL_66;
      case 6u:
        if ( (v4[286] & 0x20) == 0 )
          v4[286] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v28 = v6[1];
        v19 = v30 + 13;
        a3 = v30 + 13;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v19);
          if ( v5 )
            return v5;
          v20 = v6[1];
          if ( v20 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v20 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v18;
          v19 = ++a3;
          if ( v18 >= 20 )
          {
            v4 = v30;
            goto LABEL_67;
          }
        }
        v21 = v18 + 1;
        v4 = v30;
        v30[12] = v21;
        goto LABEL_67;
      case 7u:
        if ( (v4[286] & 0x40) == 0 )
          v4[286] |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 33);
        goto LABEL_66;
      case 8u:
        if ( (v4[286] & 0x80) == 0 )
          v4[286] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v28 = v6[1];
        v23 = v30 + 34;
        a3 = v30 + 34;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v23);
          if ( v5 )
            return v5;
          v24 = v6[1];
          if ( v24 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v22;
          v23 = ++a3;
          if ( v22 >= 250 )
          {
            v4 = v30;
            goto LABEL_67;
          }
        }
        v25 = v22 + 1;
        v4 = v30;
        v30[33] = v25;
LABEL_67:
        v7 = v26;
        if ( v6[1] < (unsigned int)v26 )
          continue;
LABEL_68:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      case 9u:
        if ( (v4[286] & 0x100) == 0 )
          v4[286] |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 284);
        goto LABEL_66;
      case 0xAu:
        if ( (v4[286] & 0x200) == 0 )
          v4[286] |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 285);
        goto LABEL_66;
      default:
        VarInt = TdrBuf::SkipField(v6, v29 & 0xF);
LABEL_66:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_67;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10211910
// ============================================================
//----- (10211910) --------------------------------------------------------
int __thiscall sub_10211910(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
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
  _DWORD *v15; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v16; // [esp+14h] [ebp-14h] BYREF
  unsigned int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch] BYREF
  int v19; // [esp+20h] [ebp-8h]
  unsigned int v20; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(this + 5929) = 0;
  v17 = 0;
  v5 = a2[1] + a3;
  v20 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_59;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v3[5929] & 1) == 0 )
          v3[5929] |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_57;
      case 2u:
        if ( (v3[5929] & 2) == 0 )
          v3[5929] |= 2u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v19 = a2[1];
        v16 = this + 1;
        while ( 1 )
        {
          v18 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v18);
          if ( v4 )
            return v4;
          if ( v18 )
          {
            v4 = sub_10210220((int)v16, a2, v18);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > (unsigned int)v15 + v19 )
            return -34;
          if ( (_DWORD *)v9 == (_DWORD *)((char *)v15 + v19) )
            break;
          v16 = (_DWORD *)((char *)v16 + 530);
          if ( ++v8 >= 20 )
          {
            v3 = this;
            goto LABEL_58;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *this = v10;
        goto LABEL_58;
      case 3u:
        if ( (v3[5929] & 4) == 0 )
          v3[5929] |= 4u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        VarInt = sub_1020EB80((int)(v3 + 2651), a2, v18);
        goto LABEL_57;
      case 4u:
        if ( (v3[5929] & 8) == 0 )
          v3[5929] |= 8u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        VarInt = sub_1020EB80((int)v3 + 13433, a2, v18);
        goto LABEL_57;
      case 5u:
        if ( (v3[5929] & 0x10) == 0 )
          v3[5929] |= 0x10u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        VarInt = sub_1020EB80((int)v3 + 16262, a2, v18);
        goto LABEL_57;
      case 6u:
        if ( (v3[5929] & 0x20) == 0 )
          v3[5929] |= 0x20u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        VarInt = sub_1020EB80((int)v3 + 19091, a2, v18);
LABEL_57:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_58;
        return v4;
      case 7u:
        if ( (v3[5929] & 0x40) == 0 )
          v3[5929] |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 5480);
        goto LABEL_57;
      case 8u:
        if ( (v3[5929] & 0x80) == 0 )
          v3[5929] |= 0x80u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v11 = 0;
        v19 = a2[1];
        v15 = this + 5481;
        while ( 1 )
        {
          v18 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v18);
          if ( v4 )
            return v4;
          if ( v18 )
          {
            v4 = sub_10210BB0((int)v15, a2, v18);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > (unsigned int)v16 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)v16 + v19) )
            break;
          v15 = (_DWORD *)((char *)v15 + 14);
          if ( ++v11 >= 128 )
          {
            v3 = this;
            goto LABEL_58;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(this + 5480) = v13;
LABEL_58:
        v5 = v20;
        if ( a2[1] < v20 )
          continue;
LABEL_59:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v17 & 0xF);
        goto LABEL_57;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017FA00
// ============================================================
//----- (1017FA00) --------------------------------------------------------
int __thiscall sub_1017FA00(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  bool v6; // cf
  int result; // eax
  unsigned int v8; // edi
  int *v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  int *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v15 = this;
  v14 = 0;
  *(this + 40) = 0;
  v13 = v4[1] + v3;
  v6 = v13 < v4[1];
  if ( v13 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    if ( v14 >> 4 == 1 )
      break;
    if ( v14 >> 4 == 2 )
    {
      if ( (v5[40] & 2) == 0 )
        v5[40] |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v8 = 0;
        a3 = v4[1];
        v9 = v5 + 20;
        while ( 1 )
        {
          result = TdrBuf::ReadVarInt(v4, v9);
          if ( result )
            return result;
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v8;
            ++v9;
            if ( v8 < 0x14 )
              continue;
          }
          goto LABEL_26;
        }
      }
      return -37;
    }
    result = TdrBuf::SkipField(v4, v14 & 0xF);
    if ( result )
      return result;
LABEL_27:
    if ( v4[1] >= v13 )
    {
      v6 = v13 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  if ( (v5[40] & 1) == 0 )
    v5[40] |= 1u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( result )
    return result;
  if ( !a2 )
    return -37;
  v11 = 0;
  a3 = v4[1];
  while ( 1 )
  {
    result = TdrBuf::ReadVarInt(v4, v5);
    if ( result )
      return result;
    v12 = v4[1];
    if ( v12 > (unsigned int)a2 + a3 )
      return -34;
    if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
    {
      ++v11;
      ++v5;
      if ( v11 < 0x14 )
        continue;
    }
LABEL_26:
    v5 = v15;
    goto LABEL_27;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1015F010
// ============================================================
//----- (1015F010) --------------------------------------------------------
int __thiscall sub_1015F010(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int *v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // edi
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int *v15; // [esp+10h] [ebp-Ch]
  unsigned int v16; // [esp+14h] [ebp-8h] BYREF
  int *v17; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(int *)((char *)this + 37) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_42;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 37) & 1) == 0 )
          *(int *)((char *)v5 + 37) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, v5);
        goto LABEL_40;
      case 2u:
        if ( (*(int *)((char *)v5 + 37) & 2) == 0 )
          *(int *)((char *)v5 + 37) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 1);
        goto LABEL_40;
      case 3u:
        if ( (*(int *)((char *)v5 + 37) & 4) == 0 )
          *(int *)((char *)v5 + 37) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 2);
        goto LABEL_40;
      case 4u:
        if ( (*(int *)((char *)v5 + 37) & 8) == 0 )
          *(int *)((char *)v5 + 37) |= 8u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 3);
        goto LABEL_40;
      case 5u:
        if ( (*(int *)((char *)v5 + 37) & 0x10) == 0 )
          *(int *)((char *)v5 + 37) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 4);
        goto LABEL_40;
      case 6u:
        if ( (*(int *)((char *)v5 + 37) & 0x20) == 0 )
          *(int *)((char *)v5 + 37) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 5);
        goto LABEL_40;
      case 7u:
        if ( (*(int *)((char *)v5 + 37) & 0x40) == 0 )
          *(int *)((char *)v5 + 37) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        v11 = v17 + 6;
        v15 = v17 + 6;
        while ( 1 )
        {
          v6 = sub_10115A30(v4, (_BYTE *)v11 + v10);
          if ( v6 )
            return v6;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            break;
          v11 = v15;
          if ( ++v10 >= 5 )
          {
            v5 = v17;
            goto LABEL_41;
          }
        }
        v13 = v10 + 1;
        v5 = v17;
        v17[5] = v13;
LABEL_41:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_42:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 8u:
        if ( (*(int *)((char *)v5 + 37) & 0x80) == 0 )
          *(int *)((char *)v5 + 37) |= 0x80u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)((char *)v5 + 29));
        goto LABEL_40;
      case 9u:
        if ( (*(int *)((char *)v5 + 37) & 0x100) == 0 )
          *(int *)((char *)v5 + 37) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)((char *)v5 + 33));
        goto LABEL_40;
      default:
        VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_40:
        v6 = VarInt;
        if ( !VarInt )
          goto LABEL_41;
        return v6;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10187DA0
// ============================================================
//----- (10187DA0) --------------------------------------------------------
int __thiscall sub_10187DA0(int *this, size_t Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  size_t v12; // ecx
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  int *v17; // eax
  size_t v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ebx
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // ecx
  unsigned int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch] BYREF
  int v28; // [esp+18h] [ebp-8h]
  int *v29; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Byte = 0;
  v29 = this;
  v27 = 0;
  *(int *)((char *)this + 542) = 0;
  v7 = v4[1] + v3;
  v25 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_82;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v27);
    if ( result )
      return result;
    switch ( v27 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 542) & 1) == 0 )
          *(int *)((char *)v5 + 542) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, v5);
        goto LABEL_80;
      case 2u:
        if ( (*(int *)((char *)v5 + 542) & 2) == 0 )
          *(int *)((char *)v5 + 542) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v28 = v4[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        while ( 1 )
        {
          Byte = TdrBuf::ReadVarInt(v4, v11);
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > v28 + Size )
            return -34;
          if ( v12 == v28 + Size )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 40 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v13 = v10 + 1;
        v5 = v29;
        *v29 = v13;
        goto LABEL_81;
      case 3u:
        if ( (*(int *)((char *)v5 + 542) & 4) == 0 )
          *(int *)((char *)v5 + 542) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 41);
        goto LABEL_80;
      case 4u:
        if ( (*(int *)((char *)v5 + 542) & 8) == 0 )
          *(int *)((char *)v5 + 542) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 168);
          if ( Byte )
            return Byte;
          v15 = (_DWORD *)v4[1];
          if ( v15 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v15 == (_DWORD *)((char *)a3 + Size) )
            goto LABEL_31;
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 5u:
        if ( (*(int *)((char *)v5 + 542) & 0x10) == 0 )
          *(int *)((char *)v5 + 542) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        v28 = v4[1];
        v17 = v29 + 47;
        a3 = v29 + 47;
        do
        {
          Byte = TdrBuf::ReadVarInt(v4, v17);
          if ( Byte )
            return Byte;
          v18 = v4[1];
          if ( v18 > v28 + Size )
            return -34;
          if ( v18 == v28 + Size )
            goto LABEL_31;
          ++v14;
          v17 = ++a3;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 6u:
        if ( (*(int *)((char *)v5 + 542) & 0x20) == 0 )
          *(int *)((char *)v5 + 542) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 268);
          if ( Byte )
            return Byte;
          v19 = (_DWORD *)v4[1];
          if ( v19 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v19 == (_DWORD *)((char *)a3 + Size) )
          {
LABEL_31:
            v16 = v14 + 1;
            v5 = v29;
            v29[41] = v16;
            goto LABEL_81;
          }
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 7u:
        if ( (*(int *)((char *)v5 + 542) & 0x40) == 0 )
          *(int *)((char *)v5 + 542) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 72);
        goto LABEL_80;
      case 8u:
        if ( (*(int *)((char *)v5 + 542) & 0x80) == 0 )
          *(int *)((char *)v5 + 542) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v20 = 0;
        a3 = (_DWORD *)v4[1];
        while ( 1 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v20 + 292);
          if ( Byte )
            return Byte;
          v21 = (_DWORD *)v4[1];
          if ( v21 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v21 == (_DWORD *)((char *)a3 + Size) )
            break;
          if ( ++v20 >= 10 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v22 = v20 + 1;
        v5 = v29;
        v29[72] = v22;
        goto LABEL_81;
      case 9u:
        if ( (*(int *)((char *)v5 + 542) & 0x100) == 0 )
          *(int *)((char *)v5 + 542) |= 0x100u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v26 = v4[1];
        v28 = 0;
        v23 = 0;
        break;
      default:
        VarInt = TdrBuf::SkipField(v4, v27 & 0xF);
LABEL_80:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_81;
        return Byte;
    }
    while ( 1 )
    {
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      if ( Size >= 0x18 )
        return -3;
      Byte = TdrBuf::ReadBytes(v4, (char *)&v29[v23 + 75] + 2, Size);
      if ( Byte )
        return Byte;
      *((_BYTE *)&v29[v23 + 75] + Size + 2) = 0;
      v24 = v4[1];
      if ( v24 > (unsigned int)a3 + v26 )
        return -34;
      if ( (_DWORD *)v24 == (_DWORD *)((char *)a3 + v26) )
        break;
      ++v28;
      v23 += 6;
      if ( v23 >= 60 )
      {
        v5 = v29;
        goto LABEL_81;
      }
    }
    v5 = v29;
    v29[72] = v28 + 1;
LABEL_81:
    v7 = v25;
    if ( v4[1] >= v25 )
    {
LABEL_82:
      if ( v4[1] > v7 )
        return -34;
      return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018C5B0
// ============================================================
//----- (1018C5B0) --------------------------------------------------------
int __thiscall sub_1018C5B0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // ecx
  unsigned int v14; // edx
  char v15; // al
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(this + 33) = 0;
  v7 = a2[1] + v3;
  v16 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      if ( v18 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 33) & 1) == 0 )
          *(this + 33) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, this);
      }
      else
      {
        if ( v18 >> 4 == 2 )
        {
          if ( (*(this + 33) & 2) == 0 )
            *(this + 33) |= 2u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( !result )
          {
            v10 = a3;
            if ( a3 )
            {
              v11 = v4[1];
              v12 = 0;
              v17 = v11;
              while ( 1 )
              {
                if ( v11 > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v13 = v4[1];
                if ( v4[2] == v13 )
                  return -2;
                v14 = v17 + v10;
                v15 = *(_BYTE *)(v13 + *v4);
                v6 = 0;
                *((_BYTE *)this + v12 + 4) = v15;
                v11 = ++v4[1];
                v4 = a2;
                if ( v11 > v14 )
                  return -34;
                if ( v11 == v14 )
                {
                  *this = v12 + 1;
                  goto LABEL_23;
                }
                v10 = a3;
                if ( ++v12 >= 128 )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        VarInt = TdrBuf::SkipField(v4, v18 & 0xF);
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_23:
      v7 = v16;
      if ( v4[1] >= v16 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101868F0
// ============================================================
//----- (101868F0) --------------------------------------------------------
int __thiscall sub_101868F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-10h]
  int v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+10h] [ebp-Ch]
  unsigned int v20; // [esp+14h] [ebp-8h] BYREF
  int v21; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v21 = this;
  v20 = 0;
  *(_DWORD *)(this + 905) = 0;
  v7 = v4[1] + v3;
  v17 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 905) & 1) == 0 )
          *(_DWORD *)(v5 + 905) |= 1u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 905) & 2) == 0 )
          *(_DWORD *)(v5 + 905) |= 2u;
        Byte = TdrBuf::ReadVarInt(v4, (int *)(v5 + 1));
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)(v5 + 905) & 4) == 0 )
          *(_DWORD *)(v5 + 905) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v4[1];
        v11 = (int *)(v21 + 5);
        a3 = v21 + 5;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v11);
          if ( VarInt )
            return VarInt;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v18) )
            goto LABEL_20;
          ++v10;
          v11 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 100 );
        v5 = v21;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)(v5 + 905) & 8) == 0 )
          *(_DWORD *)(v5 + 905) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v21 + 405));
          if ( VarInt )
            return VarInt;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 100 );
        v5 = v21;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 905) & 0x10) == 0 )
          *(_DWORD *)(v5 + 905) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v15 = (int *)(v21 + 505);
        a3 = v21 + 505;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v15);
          if ( VarInt )
            return VarInt;
          v16 = v4[1];
          if ( v16 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v19) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v21;
            *(_DWORD *)(v21 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v15 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 100 );
        v5 = v21;
LABEL_43:
        v7 = v17;
        if ( v4[1] < v17 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      default:
        Byte = TdrBuf::SkipField(v4, v20 & 0xF);
LABEL_42:
        VarInt = Byte;
        if ( !Byte )
          goto LABEL_43;
        return VarInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101585E0
// ============================================================
//----- (101585E0) --------------------------------------------------------
int __thiscall sub_101585E0(int *this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int *v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int i; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(int *)((char *)this + 46453) = 0;
  v5 = a2[1] + a3;
  for ( i = v5; a2[1] < i; v5 = i )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      return result;
    switch ( v8 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)this + 46453) & 1) == 0 )
          *(int *)((char *)this + 46453) |= 1u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_101534E0(this, a2, v9);
LABEL_22:
          v4 = v7;
          if ( v7 )
            return v4;
        }
        break;
      case 2u:
        if ( (*(int *)((char *)this + 46453) & 2) == 0 )
          *(int *)((char *)this + 46453) |= 2u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_10156350(this + 1342, a2, (int)v9);
          goto LABEL_22;
        }
        break;
      case 3u:
        if ( (*(int *)((char *)this + 46453) & 4) == 0 )
          *(int *)((char *)this + 46453) |= 4u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_10157930((int)(this + 11508), (int)a2, (int)v9);
          goto LABEL_22;
        }
        break;
      default:
        v7 = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_22;
    }
  }
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10180430
// ============================================================
//----- (10180430) --------------------------------------------------------
int __thiscall sub_10180430(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int *v5; // edi
  bool v6; // cf
  int result; // eax
  unsigned int v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v5 = this;
  v12 = 0;
  *(this + 20) = 0;
  v10 = v4[1] + v3;
  v6 = v10 < v4[1];
  if ( v10 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (v5[20] & 1) == 0 )
        v5[20] |= 1u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v8 = 0;
          a3 = v4[1];
          while ( 1 )
          {
            result = TdrBuf::ReadVarInt(v4, v5);
            if ( result )
              break;
            v9 = v4[1];
            if ( v9 > (unsigned int)a2 + a3 )
              return -34;
            if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
            {
              ++v8;
              ++v5;
              if ( v8 < 0x14 )
                continue;
            }
            v5 = this;
            goto LABEL_16;
          }
        }
        else
        {
          return -37;
        }
      }
      return result;
    }
    result = TdrBuf::SkipField(v4, v12 & 0xF);
    if ( result )
      return result;
LABEL_16:
    if ( v4[1] >= v10 )
    {
      v6 = v10 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022ACA0
// ============================================================
//----- (1022ACA0) --------------------------------------------------------
int __thiscall sub_1022ACA0(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  int *v9; // ecx
  int v10; // eax
  int *v11; // ecx
  int v12; // ebx
  int *v13; // ecx
  int v14; // eax
  int *v16; // [esp+10h] [ebp-18h] BYREF
  int *v17; // [esp+14h] [ebp-14h] BYREF
  unsigned int v18; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch] BYREF
  int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(this + 1233) = 0;
  v18 = 0;
  v5 = a2[1] + a3;
  v21 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_54;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (v3[1233] & 1) == 0 )
          v3[1233] |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_52;
      case 2u:
        if ( (v3[1233] & 2) == 0 )
          v3[1233] |= 2u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v8 = 0;
        v20 = a2[1];
        v17 = this + 1;
        do
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_10229120(v17, a2, v19);
            if ( v4 )
              return v4;
          }
          v9 = (int *)a2[1];
          if ( v9 > (int *)((char *)v16 + v20) )
            return -34;
          if ( v9 == (int *)((char *)v16 + v20) )
            goto LABEL_19;
          v17 += 4;
          ++v8;
        }
        while ( v8 < 30 );
        v3 = this;
        goto LABEL_53;
      case 3u:
        if ( (v3[1233] & 4) == 0 )
          v3[1233] |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 121);
        goto LABEL_52;
      case 4u:
        if ( (v3[1233] & 8) == 0 )
          v3[1233] |= 8u;
        v17 = 0;
        result = TdrBuf::ReadInt32(a2, &v17);
        if ( result )
          return result;
        if ( !v17 )
          return -37;
        v8 = 0;
        v20 = a2[1];
        v16 = this + 122;
        do
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_10229770(v16, a2, v19);
            if ( v4 )
              return v4;
          }
          v11 = (int *)a2[1];
          if ( v11 > (int *)((char *)v17 + v20) )
            return -34;
          if ( v11 == (int *)((char *)v17 + v20) )
          {
LABEL_19:
            v10 = v8 + 1;
            v3 = this;
            *this = v10;
            goto LABEL_53;
          }
          v16 += 4;
          ++v8;
        }
        while ( v8 < 30 );
        v3 = this;
        goto LABEL_53;
      case 5u:
        if ( (v3[1233] & 0x10) == 0 )
          v3[1233] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 242);
        goto LABEL_52;
      case 6u:
        if ( (v3[1233] & 0x20) == 0 )
          v3[1233] |= 0x20u;
        v17 = 0;
        result = TdrBuf::ReadInt32(a2, &v17);
        if ( result )
          return result;
        if ( !v17 )
          return -37;
        v12 = 0;
        v20 = a2[1];
        v16 = this + 243;
        while ( 1 )
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_10229EF0(v16, a2, v19);
            if ( v4 )
              return v4;
          }
          v13 = (int *)a2[1];
          if ( v13 > (int *)((char *)v17 + v20) )
            return -34;
          if ( v13 == (int *)((char *)v17 + v20) )
            break;
          v16 += 33;
          if ( ++v12 >= 30 )
          {
            v3 = this;
            goto LABEL_53;
          }
        }
        v14 = v12 + 1;
        v3 = this;
        *(this + 242) = v14;
LABEL_53:
        v5 = v21;
        if ( a2[1] < v21 )
          continue;
LABEL_54:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v18 & 0xF);
LABEL_52:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_53;
        return v4;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10231920
// ============================================================
//----- (10231920) --------------------------------------------------------
int __thiscall sub_10231920(char *this, char *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  int v7; // ebx
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+10h] [ebp-18h] BYREF
  int *v12; // [esp+14h] [ebp-14h]
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int v16; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 2581) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v16 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_27:
    if ( *((_DWORD *)a2 + 1) > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v13);
      if ( result )
        break;
      if ( v13 >> 4 == 1 )
      {
        if ( (v3[2581] & 1) == 0 )
          *(_DWORD *)(v3 + 2581) |= 1u;
        if ( *((_DWORD *)a2 + 1) > *((_DWORD *)a2 + 2) )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = *((_DWORD *)a2 + 1);
        if ( *((_DWORD *)a2 + 2) == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *(_DWORD *)a2);
        ++*((_DWORD *)a2 + 1);
        v4 = 0;
      }
      else
      {
        if ( v13 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 2581) & 2) == 0 )
            *(_DWORD *)(v3 + 2581) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v15 = *((_DWORD *)a2 + 1);
          v12 = (int *)(this + 1);
          while ( 1 )
          {
            v14 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v14);
            if ( v4 )
              return v4;
            if ( v14 )
            {
              v4 = sub_10230DE0(v12, a2, v14);
              if ( v4 )
                return v4;
            }
            v8 = *((_DWORD *)a2 + 1);
            if ( v8 > v15 + v11 )
              return -34;
            if ( v8 == v15 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            v12 += 129;
            if ( ++v7 >= 5 )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v13 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v16;
      if ( *((_DWORD *)a2 + 1) >= v16 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_1017E050
// ============================================================
//----- (1017E050) --------------------------------------------------------
int __thiscall sub_1017E050(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 25) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_20:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 25) & 1) == 0 )
          *(_DWORD *)(v5 + 25) |= 1u;
        v9 = sub_101600D0(v4, (int *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 25) & 2) == 0 )
          *(_DWORD *)(v5 + 25) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          v11 = v16 + 8;
          v14 = v16 + 8;
          while ( 1 )
          {
            Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v11));
            if ( Byte )
              return Byte;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
            {
              v11 = v14;
              if ( (unsigned int)++v10 < 7 )
                continue;
            }
            v5 = v16;
LABEL_19:
            v7 = v13;
            if ( v4[1] >= v13 )
              goto LABEL_20;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 3u:
        if ( (*(_DWORD *)(v5 + 25) & 4) == 0 )
          *(_DWORD *)(v5 + 25) |= 4u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 15));
        if ( Byte )
          return Byte;
        goto LABEL_19;
      case 4u:
        if ( (*(_DWORD *)(v5 + 25) & 8) == 0 )
          *(_DWORD *)(v5 + 25) |= 8u;
        v9 = sub_101600D0(v4, (int *)(v5 + 16));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 25) & 0x10) == 0 )
          *(_DWORD *)(v5 + 25) |= 0x10u;
        v9 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 24));
        goto LABEL_7;
      default:
        v9 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_7:
        Byte = v9;
        if ( !v9 )
          goto LABEL_19;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10176230
// ============================================================
//----- (10176230) --------------------------------------------------------
int __thiscall sub_10176230(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  unsigned int v21; // [esp+14h] [ebp-8h] BYREF
  int *v22; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(this + 303) = 0;
  v21 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (v4[303] & 1) == 0 )
          v4[303] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_36;
      case 6u:
        if ( (v4[303] & 2) == 0 )
          v4[303] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_36;
      case 7u:
        if ( (v4[303] & 4) == 0 )
          v4[303] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v22 + 2;
        a3 = v22 + 2;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 200 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        v22[1] = v13;
        goto LABEL_37;
      case 8u:
        if ( (v4[303] & 8) == 0 )
          v4[303] |= 8u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 202);
        goto LABEL_36;
      case 9u:
        if ( (v4[303] & 0x10) == 0 )
          v4[303] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = v6[1];
        v15 = v22 + 203;
        a3 = v22 + 203;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v20) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 100 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        v22[202] = v17;
LABEL_37:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v21 & 0xF);
LABEL_36:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_37;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017D630
// ============================================================
//----- (1017D630) --------------------------------------------------------
int __thiscall sub_1017D630(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  int *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int *v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(int *)((char *)this + 4454) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (*((_BYTE *)v3 + 4454) & 1) == 0 )
          *(int *)((char *)v3 + 4454) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(int *)((char *)v3 + 4454) & 2) == 0 )
            *(int *)((char *)v3 + 4454) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v8 = 0;
          v16 = a2[1];
          v12 = v13 + 1;
          while ( 1 )
          {
            v15 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v15);
            if ( v4 )
              return v4;
            if ( v15 )
            {
              v4 = sub_1017CB80((int)v12, a2, v15);
              if ( v4 )
                return v4;
            }
            v9 = a2[1];
            if ( v9 > v16 + v11 )
              return -34;
            if ( v9 == v16 + v11 )
            {
              v10 = v8 + 1;
              v3 = v13;
              *v13 = v10;
              goto LABEL_23;
            }
            v12 = (_DWORD *)((char *)v12 + 89);
            if ( ++v8 >= 50 )
            {
              v3 = v13;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(a2, v14 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
LABEL_23:
      v5 = v17;
      if ( a2[1] >= v17 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10177870
// ============================================================
//----- (10177870) --------------------------------------------------------
int __thiscall sub_10177870(_DWORD *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int Byte_2; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte_2 = 0;
  v19 = this;
  v18 = 0;
  *(_DWORD *)((char *)this + 38) = 0;
  v7 = (unsigned int)&v3[v4[1]];
  v16 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 38) & 1) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 2) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v4, v5 + 1);
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 4) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v19 + v10 + 8);
          if ( Byte_2 )
            return Byte_2;
          v11 = v4[1];
          if ( (_DWORD *)v11 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 8) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (char *)v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v19 + v10 + 13);
          if ( Byte_2 )
            return Byte_2;
          v13 = v4[1];
          if ( (_DWORD *)v13 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)((char *)v5 + 38) & 0x10) == 0 )
          *(_DWORD *)((char *)v5 + 38) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v4[1];
        v14 = (_DWORD *)((char *)v19 + 18);
        a3 = (char *)v19 + 18;
        do
        {
          Byte_2 = TdrBuf::ReadVarInt(v4, v14);
          if ( Byte_2 )
            return Byte_2;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v17) )
          {
LABEL_20:
            v12 = v10 + 1;
            v5 = v19;
            v19[1] = v12;
            goto LABEL_43;
          }
          ++v10;
          v14 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v19;
LABEL_43:
        v7 = v16;
        if ( v4[1] < v16 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Byte_2;
      default:
        VarUInt = TdrBuf::SkipField(v4, v18 & 0xF);
LABEL_42:
        Byte_2 = VarUInt;
        if ( !VarUInt )
          goto LABEL_43;
        return Byte_2;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10171030
// ============================================================
//----- (10171030) --------------------------------------------------------
int __thiscall sub_10171030(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarInt = TdrBuf::ReadVarUInt(a2, this + 2);
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
// Address Name: SUB_10164190
// ============================================================
//----- (10164190) --------------------------------------------------------
int __thiscall sub_10164190(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
        case 2u:
          if ( (*(_BYTE *)(this + 6) & 1) == 0 )
            *(_DWORD *)(this + 6) |= 1u;
          VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 6) & 2) == 0 )
            *(_DWORD *)(this + 6) |= 2u;
          VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 6) & 4) == 0 )
            *(_DWORD *)(this + 6) |= 4u;
          VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 4));
          break;
        default:
          VarShort = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarShort;
      if ( VarShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10184830
// ============================================================
//----- (10184830) --------------------------------------------------------
int __thiscall sub_10184830(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int VarULong; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  VarULong = 0;
  v6 = a2;
  v20 = this;
  *(_DWORD *)(this + 130) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 130) & 1) == 0 )
          *(_DWORD *)(v4 + 130) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 130) & 2) == 0 )
          *(_DWORD *)(v4 + 130) |= 2u;
        VarInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 4));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 130) & 4) == 0 )
          *(_DWORD *)(v4 + 130) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 5));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(v4 + 130) & 8) == 0 )
          *(_DWORD *)(v4 + 130) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = (_DWORD *)(v20 + 9);
        a3 = v20 + 9;
        do
        {
          VarULong = TdrBuf::ReadVarULong(v6, v11);
          if ( VarULong )
            return VarULong;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
            goto LABEL_23;
          ++v10;
          v11 = (_DWORD *)(a3 + 8);
          a3 += 8;
        }
        while ( v10 < 10 );
        v4 = v20;
        goto LABEL_39;
      case 5u:
        if ( (*(_DWORD *)(v4 + 130) & 0x10) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v6[1];
        v14 = (_DWORD *)(v20 + 89);
        a3 = v20 + 89;
        do
        {
          VarULong = TdrBuf::ReadVarUInt(v6, v14);
          if ( VarULong )
            return VarULong;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v18) )
          {
LABEL_23:
            v13 = v10 + 1;
            v4 = v20;
            *(_DWORD *)(v20 + 5) = v13;
            goto LABEL_39;
          }
          ++v10;
          v14 = (_DWORD *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 10 );
        v4 = v20;
LABEL_39:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_40:
        if ( v6[1] > v7 )
          return -34;
        return VarULong;
      case 6u:
        if ( (*(_DWORD *)(v4 + 130) & 0x20) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x20u;
        VarInt = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 129));
        goto LABEL_38;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_38:
        VarULong = VarInt;
        if ( !VarInt )
          goto LABEL_39;
        return VarULong;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018F6E0
// ============================================================
//----- (1018F6E0) --------------------------------------------------------
int __thiscall sub_1018F6E0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int *v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 378) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 378) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 2) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 2u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = v13 + 1;
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1018ED90((int)v12, a2, (int)v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 = (_DWORD *)((char *)v12 + 13);
          if ( ++v8 >= 8 )
          {
            v3 = v13;
            goto LABEL_33;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *v13 = v10;
LABEL_33:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_34:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 3u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 4) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 4u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3 + 108);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 8) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 8u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3 + 109);
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 0x10) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 0x10u;
        v15 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v15);
        if ( v4 )
          return v4;
        if ( !v15 )
          goto LABEL_33;
        VarInt = sub_1018E340((_DWORD *)((char *)v3 + 110), a2, v15);
LABEL_32:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_33;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v14 & 0xF);
        goto LABEL_32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10185B80
// ============================================================
//----- (10185B80) --------------------------------------------------------
int __thiscall sub_10185B80(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  char *v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 30) = 0;
  v15 = 0;
  v7 = (char *)v3 + v6[1];
  v12 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_37:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[30] & 1) == 0 )
          v4[30] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[30] & 2) == 0 )
          v4[30] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_7;
      case 3u:
        if ( (v4[30] & 4) == 0 )
          v4[30] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_7;
      case 4u:
        if ( (v4[30] & 8) == 0 )
          v4[30] |= 8u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 3);
        goto LABEL_7;
      case 5u:
        if ( (v4[30] & 0x10) == 0 )
          v4[30] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 4);
        goto LABEL_7;
      case 6u:
        if ( (v4[30] & 0x20) == 0 )
          v4[30] |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 5);
        goto LABEL_7;
      case 7u:
        if ( (v4[30] & 0x40) == 0 )
          v4[30] |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = v16 + 6;
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_10185300(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 3;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_36:
            v7 = v12;
            if ( v6[1] >= (unsigned int)v12 )
              goto LABEL_37;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      default:
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_36;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10114930
// ============================================================
//----- (10114930) --------------------------------------------------------
int __thiscall sub_10114930(int this, _DWORD *Size, int a3)
{
  int v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v12; // [esp+14h] [ebp-14h] BYREF
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 1962) = 0;
  v5 = Size[1] + a3;
  for ( i = v5; ; v5 = i )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_2:
        if ( Size[1] >= v5 )
        {
          if ( Size[1] > v5 )
            return -34;
          return v4;
        }
        result = TdrBuf::ReadVarUInt(Size, &v13);
        if ( result )
          return result;
        if ( v13 >> 4 != 1 )
          break;
        if ( (*(_BYTE *)(v3 + 1962) & 1) == 0 )
          *(_DWORD *)(v3 + 1962) |= 1u;
        if ( Size[1] > Size[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = Size[1];
        if ( Size[2] == v10 )
          return -2;
        *(_BYTE *)v3 = *(_BYTE *)(v10 + *Size);
        ++Size[1];
        v4 = 0;
        v5 = i;
      }
      if ( v13 >> 4 != 2 )
        break;
      if ( (*(_DWORD *)(v3 + 1962) & 2) == 0 )
        *(_DWORD *)(v3 + 1962) |= 2u;
      if ( Size[1] > Size[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = Size[1];
      if ( Size[2] == v9 )
        return -2;
      *(_BYTE *)(v3 + 1) = *(_BYTE *)(v9 + *Size);
      ++Size[1];
      v4 = 0;
      v5 = i;
    }
    if ( v13 >> 4 == 3 )
      break;
    v4 = TdrBuf::SkipField(Size, v13 & 0xF);
    if ( v4 )
      return v4;
  }
  if ( (*(_DWORD *)(v3 + 1962) & 4) == 0 )
    *(_DWORD *)(v3 + 1962) |= 4u;
  v12 = 0;
  result = TdrBuf::ReadInt32(Size, &v12);
  if ( !result )
  {
    if ( !v12 )
      return -37;
    v7 = 0;
    v15 = Size[1];
    while ( 1 )
    {
      v14 = 0;
      v4 = TdrBuf::ReadInt32(Size, &v14);
      if ( v4 )
        return v4;
      if ( v14 )
      {
        v4 = sub_10113A10((int *)(392 * v7 + this + 2), (size_t)Size, (int *)v14);
        if ( v4 )
          return v4;
      }
      v8 = Size[1];
      if ( v8 > v15 + v12 )
        return -34;
      if ( v8 == v15 + v12 )
      {
        *(_BYTE *)(this + 1) = v7 + 1;
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
      if ( ++v7 >= 5u )
      {
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
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
// Address Name: SUB_10189FA0
// ============================================================
//----- (10189FA0) --------------------------------------------------------
int __thiscall sub_10189FA0(char *this, _DWORD *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+14h] [ebp-14h] BYREF
  unsigned int v12; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-Ch] BYREF
  int v14; // [esp+20h] [ebp-8h]
  unsigned int v15; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v12 = 0;
  *(_DWORD *)(this + 36521) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_27:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v12);
      if ( result )
        break;
      if ( v12 >> 4 == 1 )
      {
        if ( (v3[36521] & 1) == 0 )
          *(_DWORD *)(v3 + 36521) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v4 = 0;
      }
      else
      {
        if ( v12 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 36521) & 2) == 0 )
            *(_DWORD *)(v3 + 36521) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v14 = a2[1];
          while ( 1 )
          {
            v13 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v13);
            if ( v4 )
              return v4;
            if ( v13 )
            {
              v4 = sub_10189400((int)(this + 913 * v7 + 1), a2, v13);
              if ( v4 )
                return v4;
            }
            v8 = a2[1];
            if ( v8 > v14 + v11 )
              return -34;
            if ( v8 == v14 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            if ( ++v7 >= 0x28u )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v12 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v15;
      if ( a2[1] >= v15 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10231AF0
// ============================================================
//----- (10231AF0) --------------------------------------------------------
int __thiscall sub_10231AF0(char *this, char *a2, int a3)
{
  char *v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  int v7; // ebx
  unsigned int v8; // ecx
  int v9; // ecx
  int v11; // [esp+10h] [ebp-18h] BYREF
  char *v12; // [esp+14h] [ebp-14h]
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int v16; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 2581) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v16 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_27:
    if ( *((_DWORD *)a2 + 1) > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v13);
      if ( result )
        break;
      if ( v13 >> 4 == 1 )
      {
        if ( (v3[2581] & 1) == 0 )
          *(_DWORD *)(v3 + 2581) |= 1u;
        if ( *((_DWORD *)a2 + 1) > *((_DWORD *)a2 + 2) )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = *((_DWORD *)a2 + 1);
        if ( *((_DWORD *)a2 + 2) == v9 )
          return -2;
        *v3 = *(_BYTE *)(v9 + *(_DWORD *)a2);
        ++*((_DWORD *)a2 + 1);
        v4 = 0;
      }
      else
      {
        if ( v13 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v3 + 2581) & 2) == 0 )
            *(_DWORD *)(v3 + 2581) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v7 = 0;
          v15 = *((_DWORD *)a2 + 1);
          v12 = this + 1;
          while ( 1 )
          {
            v14 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v14);
            if ( v4 )
              return v4;
            if ( v14 )
            {
              v4 = sub_10230FC0((int)v12, a2, v14);
              if ( v4 )
                return v4;
            }
            v8 = *((_DWORD *)a2 + 1);
            if ( v8 > v15 + v11 )
              return -34;
            if ( v8 == v15 + v11 )
            {
              *this = v7 + 1;
              v3 = this;
              goto LABEL_26;
            }
            v12 += 516;
            if ( ++v7 >= 5 )
            {
              v3 = this;
              goto LABEL_26;
            }
          }
        }
        v4 = TdrBuf::SkipField(a2, v13 & 0xF);
        if ( v4 )
          return v4;
      }
LABEL_26:
      v5 = v16;
      if ( *((_DWORD *)a2 + 1) >= v16 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1015F270
// ============================================================
//----- (1015F270) --------------------------------------------------------
int __thiscall sub_1015F270(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // edi
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  unsigned int v16; // [esp+14h] [ebp-8h] BYREF
  int v17; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 37) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_42;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 37) & 1) == 0 )
          *(_DWORD *)(v5 + 37) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_40;
      case 2u:
        if ( (*(_DWORD *)(v5 + 37) & 2) == 0 )
          *(_DWORD *)(v5 + 37) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_40;
      case 3u:
        if ( (*(_DWORD *)(v5 + 37) & 4) == 0 )
          *(_DWORD *)(v5 + 37) |= 4u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 8));
        goto LABEL_40;
      case 4u:
        if ( (*(_DWORD *)(v5 + 37) & 8) == 0 )
          *(_DWORD *)(v5 + 37) |= 8u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 12));
        goto LABEL_40;
      case 5u:
        if ( (*(_DWORD *)(v5 + 37) & 0x10) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 16));
        goto LABEL_40;
      case 6u:
        if ( (*(_DWORD *)(v5 + 37) & 0x20) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 20));
        goto LABEL_40;
      case 7u:
        if ( (*(_DWORD *)(v5 + 37) & 0x40) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        v11 = v17 + 24;
        v15 = v17 + 24;
        while ( 1 )
        {
          v6 = sub_10115A30(v4, (_BYTE *)(v10 + v11));
          if ( v6 )
            return v6;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            break;
          v11 = v15;
          if ( ++v10 >= 5 )
          {
            v5 = v17;
            goto LABEL_41;
          }
        }
        v13 = v10 + 1;
        v5 = v17;
        *(_DWORD *)(v17 + 20) = v13;
LABEL_41:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_42:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 8u:
        if ( (*(_DWORD *)(v5 + 37) & 0x80) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 29));
        goto LABEL_40;
      case 9u:
        if ( (*(_DWORD *)(v5 + 37) & 0x100) == 0 )
          *(_DWORD *)(v5 + 37) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 33));
        goto LABEL_40;
      default:
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_40:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_41;
        return v6;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10211D10
// ============================================================
//----- (10211D10) --------------------------------------------------------
int __thiscall sub_10211D10(char *this, _DWORD *a2, int a3)
{
  char *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  char *v9; // ecx
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // ecx
  int v13; // eax
  char *v15; // [esp+10h] [ebp-18h] BYREF
  char *v16; // [esp+14h] [ebp-14h] BYREF
  unsigned int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch] BYREF
  int v19; // [esp+20h] [ebp-8h]
  unsigned int v20; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *((_DWORD *)this + 5929) = 0;
  v17 = 0;
  v5 = a2[1] + a3;
  v20 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_59;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v3[23716] & 1) == 0 )
          *((_DWORD *)v3 + 5929) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
        goto LABEL_57;
      case 2u:
        if ( (*((_DWORD *)v3 + 5929) & 2) == 0 )
          *((_DWORD *)v3 + 5929) |= 2u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v19 = a2[1];
        v16 = this + 4;
        while ( 1 )
        {
          v18 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v18);
          if ( v4 )
            return v4;
          if ( v18 )
          {
            v4 = sub_10210420((int)v16, a2, v18);
            if ( v4 )
              return v4;
          }
          v9 = (char *)a2[1];
          if ( v9 > &v15[v19] )
            return -34;
          if ( v9 == &v15[v19] )
            break;
          v16 += 530;
          if ( ++v8 >= 20 )
          {
            v3 = this;
            goto LABEL_58;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *(_DWORD *)this = v10;
        goto LABEL_58;
      case 3u:
        if ( (*((_DWORD *)v3 + 5929) & 4) == 0 )
          *((_DWORD *)v3 + 5929) |= 4u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        Int32 = sub_1020EED0((int)(v3 + 10604), a2, v18);
        goto LABEL_57;
      case 4u:
        if ( (*((_DWORD *)v3 + 5929) & 8) == 0 )
          *((_DWORD *)v3 + 5929) |= 8u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        Int32 = sub_1020EED0((int)(v3 + 13433), a2, v18);
        goto LABEL_57;
      case 5u:
        if ( (*((_DWORD *)v3 + 5929) & 0x10) == 0 )
          *((_DWORD *)v3 + 5929) |= 0x10u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        Int32 = sub_1020EED0((int)(v3 + 16262), a2, v18);
        goto LABEL_57;
      case 6u:
        if ( (*((_DWORD *)v3 + 5929) & 0x20) == 0 )
          *((_DWORD *)v3 + 5929) |= 0x20u;
        v18 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v18);
        if ( v4 )
          return v4;
        if ( !v18 )
          goto LABEL_58;
        Int32 = sub_1020EED0((int)(v3 + 19091), a2, v18);
LABEL_57:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_58;
        return v4;
      case 7u:
        if ( (*((_DWORD *)v3 + 5929) & 0x40) == 0 )
          *((_DWORD *)v3 + 5929) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(a2, v3 + 21920);
        goto LABEL_57;
      case 8u:
        if ( (*((_DWORD *)v3 + 5929) & 0x80) == 0 )
          *((_DWORD *)v3 + 5929) |= 0x80u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v11 = 0;
        v19 = a2[1];
        v15 = this + 21924;
        while ( 1 )
        {
          v18 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v18);
          if ( v4 )
            return v4;
          if ( v18 )
          {
            v4 = sub_10210C80(v15, a2, v18);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > (unsigned int)&v16[v19] )
            return -34;
          if ( (char *)v12 == &v16[v19] )
            break;
          v15 += 14;
          if ( ++v11 >= 128 )
          {
            v3 = this;
            goto LABEL_58;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *((_DWORD *)this + 5480) = v13;
LABEL_58:
        v5 = v20;
        if ( a2[1] < v20 )
          continue;
LABEL_59:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v17 & 0xF);
        goto LABEL_57;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017FB80
// ============================================================
//----- (1017FB80) --------------------------------------------------------
int __thiscall sub_1017FB80(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  bool v6; // cf
  int result; // eax
  unsigned int v8; // edi
  _BYTE *v9; // ebx
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  unsigned int v14; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v15; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v15 = this;
  v14 = 0;
  *(this + 40) = 0;
  v13 = v4[1] + v3;
  v6 = v13 < v4[1];
  if ( v13 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v14);
    if ( result )
      return result;
    if ( v14 >> 4 == 1 )
      break;
    if ( v14 >> 4 == 2 )
    {
      if ( (v5[40] & 2) == 0 )
        v5[40] |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v8 = 0;
        a3 = v4[1];
        v9 = v5 + 20;
        while ( 1 )
        {
          result = TdrBuf::ReadInt32(v4, v9);
          if ( result )
            return result;
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v8;
            v9 += 4;
            if ( v8 < 0x14 )
              continue;
          }
          goto LABEL_26;
        }
      }
      return -37;
    }
    result = TdrBuf::SkipField(v4, v14 & 0xF);
    if ( result )
      return result;
LABEL_27:
    if ( v4[1] >= v13 )
    {
      v6 = v13 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
  if ( (v5[40] & 1) == 0 )
    v5[40] |= 1u;
  a2 = 0;
  result = TdrBuf::ReadInt32(v4, &a2);
  if ( result )
    return result;
  if ( !a2 )
    return -37;
  v11 = 0;
  a3 = v4[1];
  while ( 1 )
  {
    result = TdrBuf::ReadInt32(v4, v5);
    if ( result )
      return result;
    v12 = v4[1];
    if ( v12 > (unsigned int)a2 + a3 )
      return -34;
    if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
    {
      ++v11;
      ++v5;
      if ( v11 < 0x14 )
        continue;
    }
LABEL_26:
    v5 = v15;
    goto LABEL_27;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10164240
// ============================================================
//----- (10164240) --------------------------------------------------------
int __thiscall sub_10164240(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v10 = 0;
  *(_DWORD *)(this + 6) = 0;
  v11 = a2[1] + a3;
  v5 = v11 < a2[1];
  if ( v11 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 2u:
          if ( (*(this + 6) & 1) == 0 )
            *(_DWORD *)(this + 6) |= 1u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x2A4u);
          v9 = a2[1];
          if ( (unsigned int)(a2[2] - v9) < 2 )
            return -2;
          *this = *(_BYTE *)(*a2 + v9 + 1);
          *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 6) & 2) == 0 )
            *(_DWORD *)(this + 6) |= 2u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x2A4u);
          v8 = a2[1];
          if ( (unsigned int)(a2[2] - v8) < 2 )
            return -2;
          *(this + 2) = *(_BYTE *)(*a2 + v8 + 1);
          *(this + 3) = *(_BYTE *)(*a2 + a2[1]);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 6) & 4) == 0 )
            *(_DWORD *)(this + 6) |= 4u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x2A4u);
          v7 = a2[1];
          if ( (unsigned int)(a2[2] - v7) < 2 )
            return -2;
          *(this + 4) = *(_BYTE *)(*a2 + v7 + 1);
          *(this + 5) = *(_BYTE *)(*a2 + a2[1]);
          break;
        default:
          result = TdrBuf::SkipField(a2, v10 & 0xF);
          if ( result )
            return result;
          goto LABEL_27;
      }
      a2[1] += 2;
LABEL_27:
      if ( a2[1] >= v11 )
      {
        v5 = v11 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101727D0
// ============================================================
//----- (101727D0) --------------------------------------------------------
int __thiscall sub_101727D0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int Byte; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // esi
  _BYTE *v11; // ebx
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // [esp+Ch] [ebp-Ch]
  unsigned int v16; // [esp+10h] [ebp-8h] BYREF
  int v17; // [esp+14h] [ebp-4h]

  v3 = a3;
  Byte = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 108) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v15 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 108) & 1) == 0 )
          *(_DWORD *)(this + 108) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)(this + 108) & 2) == 0 )
          *(_DWORD *)(this + 108) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 4));
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)(this + 108) & 4) == 0 )
          *(_DWORD *)(this + 108) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v6[1];
        v11 = (_BYTE *)(this + 8);
        do
        {
          Byte = TdrBuf::ReadInt32(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
          v11 += 4;
        }
        while ( v10 < 20 );
        this = v17;
        goto LABEL_33;
      case 6u:
        if ( (*(_DWORD *)(this + 108) & 8) == 0 )
          *(_DWORD *)(this + 108) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v10 = 0;
        a2 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)(v10 + v17 + 88));
          if ( Byte )
            return Byte;
          v14 = v6[1];
          if ( (_DWORD *)v14 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
          {
LABEL_20:
            this = v17;
            *(_DWORD *)(v17 + 4) = v10 + 1;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 20 );
        this = v17;
LABEL_33:
        v7 = v15;
        if ( v6[1] < v15 )
          continue;
LABEL_34:
        if ( v6[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_32:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017D7B0
// ============================================================
//----- (1017D7B0) --------------------------------------------------------
int __thiscall sub_1017D7B0(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 4454) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
  {
LABEL_24:
    if ( a2[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (*((_BYTE *)v3 + 4454) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 4454) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(_DWORD *)((char *)v3 + 4454) & 2) == 0 )
            *(_DWORD *)((char *)v3 + 4454) |= 2u;
          v11 = 0;
          result = TdrBuf::ReadInt32(a2, &v11);
          if ( result )
            return result;
          if ( !v11 )
            return -37;
          v8 = 0;
          v16 = a2[1];
          v12 = v13 + 1;
          while ( 1 )
          {
            v15 = 0;
            v4 = TdrBuf::ReadInt32(a2, &v15);
            if ( v4 )
              return v4;
            if ( v15 )
            {
              v4 = sub_1017CD60((int)v12, a2, v15);
              if ( v4 )
                return v4;
            }
            v9 = a2[1];
            if ( v9 > v16 + v11 )
              return -34;
            if ( v9 == v16 + v11 )
            {
              v10 = v8 + 1;
              v3 = v13;
              *v13 = v10;
              goto LABEL_23;
            }
            v12 = (_DWORD *)((char *)v12 + 89);
            if ( ++v8 >= 50 )
            {
              v3 = v13;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(a2, v14 & 0xF);
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
LABEL_23:
      v5 = v17;
      if ( a2[1] >= v17 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017BA00
// ============================================================
//----- (1017BA00) --------------------------------------------------------
int __thiscall sub_1017BA00(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned __int8 v9; // bl
  unsigned int v10; // edx
  int v11; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v12; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+14h] [ebp-Ch] BYREF
  int v14; // [esp+18h] [ebp-8h]
  unsigned int v15; // [esp+1Ch] [ebp-4h]

  result = 0;
  v12 = 0;
  *(_DWORD *)(this + 740) = 0;
  v5 = a2[1] + a3;
  v15 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 5u:
        if ( (*(_BYTE *)(this + 740) & 1) == 0 )
          *(_DWORD *)(this + 740) |= 1u;
        result = TdrBuf::ReadByte_2(a2, (_BYTE *)this);
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(this + 740) & 2) == 0 )
          *(_DWORD *)(this + 740) |= 2u;
        result = TdrBuf::ReadInt64(a2, (_BYTE *)(this + 1));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(this + 740) & 4) == 0 )
          *(_DWORD *)(this + 740) |= 4u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v6 = 0;
        v13 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte_2(a2, (_BYTE *)(this + v6 + 9));
          if ( result )
            return result;
          v7 = a2[1];
          if ( v7 > v13 + v11 )
            return -34;
          if ( v7 != v13 + v11 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_49;
            continue;
          }
          goto LABEL_20;
        }
      case 8u:
        if ( (*(_DWORD *)(this + 740) & 8) == 0 )
          *(_DWORD *)(this + 740) |= 8u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v6 = 0;
        v13 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4 * v6 + 17));
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v13 + v11 )
            return -34;
          if ( v8 != v13 + v11 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_49;
            continue;
          }
          break;
        }
LABEL_20:
        *(_BYTE *)this = v6 + 1;
        goto LABEL_49;
      case 9u:
        if ( (*(_DWORD *)(this + 740) & 0x10) == 0 )
          *(_DWORD *)(this + 740) |= 0x10u;
        result = TdrBuf::ReadByte_2(a2, (_BYTE *)(this + 49));
        goto LABEL_48;
      case 0xAu:
        if ( (*(_DWORD *)(this + 740) & 0x20) == 0 )
          *(_DWORD *)(this + 740) |= 0x20u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v9 = 0;
        v14 = a2[1];
        while ( 1 )
        {
          v13 = 0;
          result = TdrBuf::ReadInt32(a2, &v13);
          if ( result )
            return result;
          if ( v13 )
          {
            result = sub_1017A070(69 * v9 + this + 50, a2, v13);
            if ( result )
              return result;
          }
          v10 = a2[1];
          if ( v10 > v14 + v11 )
            return -34;
          if ( v10 == v14 + v11 )
            break;
          if ( ++v9 >= 0xAu )
            goto LABEL_49;
        }
        *(_BYTE *)(this + 49) = v9 + 1;
LABEL_49:
        v5 = v15;
        if ( a2[1] < v15 )
          continue;
LABEL_50:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_48:
        if ( !result )
          goto LABEL_49;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018C730
// ============================================================
//----- (1018C730) --------------------------------------------------------
int __thiscall sub_1018C730(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // edx
  unsigned int v11; // eax
  int v12; // edi
  int v13; // ecx
  unsigned int v14; // edx
  char v15; // al
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h]
  unsigned int v18; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(_DWORD *)(this + 132) = 0;
  v7 = a2[1] + v3;
  v16 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      if ( v18 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 132) & 1) == 0 )
          *(_DWORD *)(this + 132) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
      }
      else
      {
        if ( v18 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 132) & 2) == 0 )
            *(_DWORD *)(this + 132) |= 2u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( !result )
          {
            v10 = a3;
            if ( a3 )
            {
              v11 = v4[1];
              v12 = 0;
              v17 = v11;
              while ( 1 )
              {
                if ( v11 > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v13 = v4[1];
                if ( v4[2] == v13 )
                  return -2;
                v14 = v17 + v10;
                v15 = *(_BYTE *)(v13 + *v4);
                v6 = 0;
                *(_BYTE *)(v12 + this + 4) = v15;
                v11 = ++v4[1];
                v4 = a2;
                if ( v11 > v14 )
                  return -34;
                if ( v11 == v14 )
                {
                  *(_DWORD *)this = v12 + 1;
                  goto LABEL_23;
                }
                v10 = a3;
                if ( ++v12 >= 128 )
                  goto LABEL_23;
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_23:
      v7 = v16;
      if ( v4[1] >= v16 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10180CB0
// ============================================================
//----- (10180CB0) --------------------------------------------------------
int __thiscall sub_10180CB0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10186BA0
// ============================================================
//----- (10186BA0) --------------------------------------------------------
int __thiscall sub_10186BA0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // [esp+Ch] [ebp-10h]
  int v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+10h] [ebp-Ch]
  unsigned int v20; // [esp+14h] [ebp-8h] BYREF
  int v21; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v21 = this;
  v20 = 0;
  *(_DWORD *)(this + 905) = 0;
  v7 = v4[1] + v3;
  v17 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 905) & 1) == 0 )
          *(_DWORD *)(v5 + 905) |= 1u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 905) & 2) == 0 )
          *(_DWORD *)(v5 + 905) |= 2u;
        Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 1));
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)(v5 + 905) & 4) == 0 )
          *(_DWORD *)(v5 + 905) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v4[1];
        v11 = (_BYTE *)(v21 + 5);
        a3 = v21 + 5;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v11);
          if ( Int32 )
            return Int32;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v18) )
            goto LABEL_20;
          ++v10;
          v11 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 100 );
        v5 = v21;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)(v5 + 905) & 8) == 0 )
          *(_DWORD *)(v5 + 905) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v21 + 405));
          if ( Int32 )
            return Int32;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 100 );
        v5 = v21;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 905) & 0x10) == 0 )
          *(_DWORD *)(v5 + 905) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v15 = (_BYTE *)(v21 + 505);
        a3 = v21 + 505;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v15);
          if ( Int32 )
            return Int32;
          v16 = v4[1];
          if ( v16 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v19) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v21;
            *(_DWORD *)(v21 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v15 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 100 );
        v5 = v21;
LABEL_43:
        v7 = v17;
        if ( v4[1] < v17 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Byte = TdrBuf::SkipField(v4, v20 & 0xF);
LABEL_42:
        Int32 = Byte;
        if ( !Byte )
          goto LABEL_43;
        return Int32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10184AA0
// ============================================================
//----- (10184AA0) --------------------------------------------------------
int __thiscall sub_10184AA0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Int64; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+10h] [ebp-Ch]
  unsigned int v19; // [esp+14h] [ebp-8h] BYREF
  int v20; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Int64 = 0;
  v6 = a2;
  v20 = this;
  *(_DWORD *)(this + 130) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 130) & 1) == 0 )
          *(_DWORD *)(v4 + 130) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 130) & 2) == 0 )
          *(_DWORD *)(v4 + 130) |= 2u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 4));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 130) & 4) == 0 )
          *(_DWORD *)(v4 + 130) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 5));
        goto LABEL_38;
      case 4u:
        if ( (*(_DWORD *)(v4 + 130) & 8) == 0 )
          *(_DWORD *)(v4 + 130) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        v11 = (_BYTE *)(v20 + 9);
        a3 = v20 + 9;
        do
        {
          Int64 = TdrBuf::ReadInt64(v6, v11);
          if ( Int64 )
            return Int64;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v17) )
            goto LABEL_23;
          ++v10;
          v11 = (_BYTE *)(a3 + 8);
          a3 += 8;
        }
        while ( v10 < 10 );
        v4 = v20;
        goto LABEL_39;
      case 5u:
        if ( (*(_DWORD *)(v4 + 130) & 0x10) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v18 = v6[1];
        v14 = (_BYTE *)(v20 + 89);
        a3 = v20 + 89;
        do
        {
          Int64 = TdrBuf::ReadInt32(v6, v14);
          if ( Int64 )
            return Int64;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v18) )
          {
LABEL_23:
            v13 = v10 + 1;
            v4 = v20;
            *(_DWORD *)(v20 + 5) = v13;
            goto LABEL_39;
          }
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 10 );
        v4 = v20;
LABEL_39:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_40:
        if ( v6[1] > v7 )
          return -34;
        return Int64;
      case 6u:
        if ( (*(_DWORD *)(v4 + 130) & 0x20) == 0 )
          *(_DWORD *)(v4 + 130) |= 0x20u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 129));
        goto LABEL_38;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_38:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_39;
        return Int64;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10192B30
// ============================================================
//----- (10192B30) --------------------------------------------------------
int __thiscall sub_10192B30(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int Int32; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Int32 = 0;
  v6 = a2;
  v15 = this;
  *(this + 139) = 0;
  v14 = 0;
  v7 = (char *)v3 + v6[1];
  v11 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return Int32;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v4[139] & 1) == 0 )
          v4[139] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v6[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          Int32 = TdrBuf::ReadInt32(v6, &v13);
          if ( Int32 )
            return Int32;
          if ( v13 )
          {
            Int32 = sub_10191F50(a3, v6, v13);
            if ( Int32 )
              return Int32;
          }
          v10 = v6[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 46;
            if ( (unsigned int)++v9 < 3 )
              continue;
          }
          v4 = v15;
          goto LABEL_23;
        }
      }
      if ( v14 >> 4 == 2 )
      {
        if ( (v4[139] & 2) == 0 )
          v4[139] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 552);
        if ( Int32 )
          return Int32;
      }
      else
      {
        Int32 = TdrBuf::SkipField(v6, v14 & 0xF);
        if ( Int32 )
          return Int32;
      }
LABEL_23:
      v7 = v11;
      if ( v6[1] >= (unsigned int)v11 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_10114B70
// ============================================================
//----- (10114B70) --------------------------------------------------------
int __thiscall sub_10114B70(int this, _DWORD *Size, int a3)
{
  int v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  unsigned __int8 v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v12; // [esp+14h] [ebp-14h] BYREF
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 1962) = 0;
  v5 = Size[1] + a3;
  for ( i = v5; ; v5 = i )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_2:
        if ( Size[1] >= v5 )
        {
          if ( Size[1] > v5 )
            return -34;
          return v4;
        }
        result = TdrBuf::ReadVarUInt(Size, &v13);
        if ( result )
          return result;
        if ( v13 >> 4 != 1 )
          break;
        if ( (*(_BYTE *)(v3 + 1962) & 1) == 0 )
          *(_DWORD *)(v3 + 1962) |= 1u;
        if ( Size[1] > Size[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = Size[1];
        if ( Size[2] == v10 )
          return -2;
        *(_BYTE *)v3 = *(_BYTE *)(v10 + *Size);
        ++Size[1];
        v4 = 0;
        v5 = i;
      }
      if ( v13 >> 4 != 2 )
        break;
      if ( (*(_DWORD *)(v3 + 1962) & 2) == 0 )
        *(_DWORD *)(v3 + 1962) |= 2u;
      if ( Size[1] > Size[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = Size[1];
      if ( Size[2] == v9 )
        return -2;
      *(_BYTE *)(v3 + 1) = *(_BYTE *)(v9 + *Size);
      ++Size[1];
      v4 = 0;
      v5 = i;
    }
    if ( v13 >> 4 == 3 )
      break;
    v4 = TdrBuf::SkipField(Size, v13 & 0xF);
    if ( v4 )
      return v4;
  }
  if ( (*(_DWORD *)(v3 + 1962) & 4) == 0 )
    *(_DWORD *)(v3 + 1962) |= 4u;
  v12 = 0;
  result = TdrBuf::ReadInt32(Size, &v12);
  if ( !result )
  {
    if ( !v12 )
      return -37;
    v7 = 0;
    v15 = Size[1];
    while ( 1 )
    {
      v14 = 0;
      v4 = TdrBuf::ReadInt32(Size, &v14);
      if ( v4 )
        return v4;
      if ( v14 )
      {
        v4 = sub_10113D40((_DWORD *)(392 * v7 + this + 2), (size_t)Size, (_DWORD *)v14);
        if ( v4 )
          return v4;
      }
      v8 = Size[1];
      if ( v8 > v15 + v12 )
        return -34;
      if ( v8 == v15 + v12 )
      {
        *(_BYTE *)(this + 1) = v7 + 1;
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
      if ( ++v7 >= 5u )
      {
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10185D80
// ============================================================
//----- (10185D80) --------------------------------------------------------
int __thiscall sub_10185D80(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 30) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_37:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[30] & 1) == 0 )
          v4[30] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[30] & 2) == 0 )
          v4[30] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_7;
      case 3u:
        if ( (v4[30] & 4) == 0 )
          v4[30] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_7;
      case 4u:
        if ( (v4[30] & 8) == 0 )
          v4[30] |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 12);
        goto LABEL_7;
      case 5u:
        if ( (v4[30] & 0x10) == 0 )
          v4[30] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 16);
        goto LABEL_7;
      case 6u:
        if ( (v4[30] & 0x20) == 0 )
          v4[30] |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 20);
        goto LABEL_7;
      case 7u:
        if ( (v4[30] & 0x40) == 0 )
          v4[30] |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = (int)(v16 + 6);
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_101853A0(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 12;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_36:
            v7 = v12;
            if ( v6[1] >= v12 )
              goto LABEL_37;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      default:
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_36;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_101710F0
// ============================================================
//----- (101710F0) --------------------------------------------------------
int __thiscall sub_101710F0(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018F920
// ============================================================
//----- (1018F920) --------------------------------------------------------
int __thiscall sub_1018F920(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-1Ch] BYREF
  _DWORD *v12; // [esp+10h] [ebp-18h]
  _DWORD *v13; // [esp+14h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(_DWORD *)((char *)this + 378) = 0;
  v14 = 0;
  v5 = a2[1] + a3;
  v17 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v14);
    if ( result )
      return result;
    switch ( v14 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v3 + 378) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 2) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 2u;
        v11 = 0;
        result = TdrBuf::ReadInt32(a2, &v11);
        if ( result )
          return result;
        if ( !v11 )
          return -37;
        v8 = 0;
        v16 = a2[1];
        v12 = v13 + 1;
        while ( 1 )
        {
          v15 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v15);
          if ( v4 )
            return v4;
          if ( v15 )
          {
            v4 = sub_1018EE90((int)v12, a2, v15);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v16 + v11 )
            return -34;
          if ( v9 == v16 + v11 )
            break;
          v12 = (_DWORD *)((char *)v12 + 13);
          if ( ++v8 >= 8 )
          {
            v3 = v13;
            goto LABEL_33;
          }
        }
        v10 = v8 + 1;
        v3 = v13;
        *v13 = v10;
LABEL_33:
        v5 = v17;
        if ( a2[1] < v17 )
          continue;
LABEL_34:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      case 3u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 4) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 4u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3 + 108);
        goto LABEL_32;
      case 4u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 8) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 8u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3 + 109);
        goto LABEL_32;
      case 5u:
        if ( (*(_DWORD *)((char *)v3 + 378) & 0x10) == 0 )
          *(_DWORD *)((char *)v3 + 378) |= 0x10u;
        v15 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v15);
        if ( v4 )
          return v4;
        if ( !v15 )
          goto LABEL_33;
        Int32 = sub_1018E580((_DWORD *)((char *)v3 + 110), a2, v15);
LABEL_32:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_33;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v14 & 0xF);
        goto LABEL_32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017E210
// ============================================================
//----- (1017E210) --------------------------------------------------------
int __thiscall sub_1017E210(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // esi
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  unsigned int v15; // [esp+14h] [ebp-8h] BYREF
  int v16; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 25) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_20:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 25) & 1) == 0 )
          *(_DWORD *)(v5 + 25) |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)v5);
        goto LABEL_7;
      case 2u:
        if ( (*(_DWORD *)(v5 + 25) & 2) == 0 )
          *(_DWORD *)(v5 + 25) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          v11 = v16 + 8;
          v14 = v16 + 8;
          while ( 1 )
          {
            Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v10 + v11));
            if ( Byte )
              return Byte;
            v12 = v4[1];
            if ( v12 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
            {
              v11 = v14;
              if ( (unsigned int)++v10 < 7 )
                continue;
            }
            v5 = v16;
LABEL_19:
            v7 = v13;
            if ( v4[1] >= v13 )
              goto LABEL_20;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 3u:
        if ( (*(_DWORD *)(v5 + 25) & 4) == 0 )
          *(_DWORD *)(v5 + 25) |= 4u;
        Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 15));
        if ( Byte )
          return Byte;
        goto LABEL_19;
      case 4u:
        if ( (*(_DWORD *)(v5 + 25) & 8) == 0 )
          *(_DWORD *)(v5 + 25) |= 8u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)(v5 + 16));
        goto LABEL_7;
      case 5u:
        if ( (*(_DWORD *)(v5 + 25) & 0x10) == 0 )
          *(_DWORD *)(v5 + 25) |= 0x10u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 24));
        goto LABEL_7;
      default:
        Int64 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_7:
        Byte = Int64;
        if ( !Int64 )
          goto LABEL_19;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10158750
// ============================================================
//----- (10158750) --------------------------------------------------------
int __thiscall sub_10158750(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int i; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)((char *)this + 46453) = 0;
  v5 = a2[1] + a3;
  for ( i = v5; a2[1] < i; v5 = i )
  {
    result = TdrBuf::ReadVarUInt(a2, &v8);
    if ( result )
      return result;
    switch ( v8 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)this + 46453) & 1) == 0 )
          *(_DWORD *)((char *)this + 46453) |= 1u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_10153650(this, a2, v9);
LABEL_22:
          v4 = v7;
          if ( v7 )
            return v4;
        }
        break;
      case 2u:
        if ( (*(_DWORD *)((char *)this + 46453) & 2) == 0 )
          *(_DWORD *)((char *)this + 46453) |= 2u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_101564C0(this + 1342, a2, v9);
          goto LABEL_22;
        }
        break;
      case 3u:
        if ( (*(_DWORD *)((char *)this + 46453) & 4) == 0 )
          *(_DWORD *)((char *)this + 46453) |= 4u;
        v9 = 0;
        v4 = TdrBuf::ReadInt32(a2, &v9);
        if ( v4 )
          return v4;
        if ( v9 )
        {
          v7 = sub_10157BB0((int)(this + 11508), (int)a2, v9);
          goto LABEL_22;
        }
        break;
      default:
        v7 = TdrBuf::SkipField(a2, v8 & 0xF);
        goto LABEL_22;
    }
  }
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024CC10
// ============================================================
//----- (1024CC10) --------------------------------------------------------
int __thiscall sub_1024CC10(int this, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = (_DWORD *)a2;
  v5 = this;
  Int32 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 517) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_36;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v5 + 517) & 1) == 0 )
          *(_DWORD *)(v5 + 517) |= 1u;
        a2 = 0;
        Int32 = TdrBuf::ReadInt32(v4, &a2);
        if ( Int32 )
          return Int32;
        if ( !a2 )
          goto LABEL_35;
        Byte_2 = sub_1024C170(v5, v4, a2);
        goto LABEL_34;
      case 3u:
        if ( (*(_DWORD *)(v5 + 517) & 2) == 0 )
          *(_DWORD *)(v5 + 517) |= 2u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v5 + 16));
        goto LABEL_34;
      case 4u:
        if ( (*(_DWORD *)(v5 + 517) & 4) == 0 )
          *(_DWORD *)(v5 + 517) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 17));
          if ( Int32 )
            return Int32;
          v11 = v4[1];
          if ( v11 > a3 + a2 )
            return -34;
          if ( v11 == a3 + a2 )
            goto LABEL_22;
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
        goto LABEL_35;
      case 5u:
        if ( (*(_DWORD *)(v5 + 517) & 8) == 0 )
          *(_DWORD *)(v5 + 517) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Int32 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v16 + 417 + v10));
          if ( Int32 )
            return Int32;
          v13 = v4[1];
          if ( v13 > a3 + a2 )
            return -34;
          if ( v13 == a3 + a2 )
          {
LABEL_22:
            v12 = v16;
            *(_BYTE *)(v16 + 16) = v10 + 1;
            v5 = v12;
            goto LABEL_35;
          }
          ++v10;
        }
        while ( v10 < 0x64u );
        v5 = v16;
LABEL_35:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_36:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_34:
        Int32 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_35;
        return Int32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1015E1B0
// ============================================================
//----- (1015E1B0) --------------------------------------------------------
int __thiscall sub_1015E1B0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // ebx
  _BYTE *v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  _BYTE *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  char *v26; // [esp+Ch] [ebp-14h]
  int v27; // [esp+10h] [ebp-10h] BYREF
  int v28; // [esp+14h] [ebp-Ch]
  unsigned int v29; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v30; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v30 = this;
  *(this + 286) = 0;
  v29 = 0;
  v7 = (char *)v3 + v6[1];
  v26 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_68;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v29);
    if ( result )
      return result;
    switch ( v29 >> 4 )
    {
      case 1u:
        if ( (v4[286] & 1) == 0 )
          v4[286] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_66;
      case 2u:
        if ( (v4[286] & 2) == 0 )
          v4[286] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_66;
      case 3u:
        if ( (v4[286] & 4) == 0 )
          v4[286] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v28 = v6[1];
        v11 = v30 + 2;
        a3 = v30 + 2;
        do
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v28) )
            goto LABEL_20;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 5 );
        v4 = v30;
        goto LABEL_67;
      case 4u:
        if ( (v4[286] & 8) == 0 )
          v4[286] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v28 = v6[1];
        a3 = v30 + 7;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v27);
          v15 = a3;
          v5 = v14;
          if ( v14 )
            return v5;
          v16 = (char *)a2 + v28;
          *a3 = v27;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
          {
LABEL_20:
            v13 = v10 + 1;
            v4 = v30;
            v30[1] = v13;
            goto LABEL_67;
          }
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 5 );
        v4 = v30;
        goto LABEL_67;
      case 5u:
        if ( (v4[286] & 0x10) == 0 )
          v4[286] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 48);
        goto LABEL_66;
      case 6u:
        if ( (v4[286] & 0x20) == 0 )
          v4[286] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v28 = v6[1];
        v19 = v30 + 13;
        a3 = v30 + 13;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v19);
          if ( v5 )
            return v5;
          v20 = v6[1];
          if ( v20 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v20 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v18;
          v19 = ++a3;
          if ( v18 >= 20 )
          {
            v4 = v30;
            goto LABEL_67;
          }
        }
        v21 = v18 + 1;
        v4 = v30;
        v30[12] = v21;
        goto LABEL_67;
      case 7u:
        if ( (v4[286] & 0x40) == 0 )
          v4[286] |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 132);
        goto LABEL_66;
      case 8u:
        if ( (v4[286] & 0x80) == 0 )
          v4[286] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v28 = v6[1];
        v23 = v30 + 34;
        a3 = v30 + 34;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v23);
          if ( v5 )
            return v5;
          v24 = v6[1];
          if ( v24 > (unsigned int)a2 + v28 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v28) )
            break;
          ++v22;
          v23 = ++a3;
          if ( v22 >= 250 )
          {
            v4 = v30;
            goto LABEL_67;
          }
        }
        v25 = v22 + 1;
        v4 = v30;
        v30[33] = v25;
LABEL_67:
        v7 = v26;
        if ( v6[1] < (unsigned int)v26 )
          continue;
LABEL_68:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      case 9u:
        if ( (v4[286] & 0x100) == 0 )
          v4[286] |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 1136);
        goto LABEL_66;
      case 0xAu:
        if ( (v4[286] & 0x200) == 0 )
          v4[286] |= 0x200u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 1140);
        goto LABEL_66;
      default:
        Int32 = TdrBuf::SkipField(v6, v29 & 0xF);
LABEL_66:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_67;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017EEC0
// ============================================================
//----- (1017EEC0) --------------------------------------------------------
int __thiscall sub_1017EEC0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 48) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_43:
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
          if ( (*(_BYTE *)(this + 48) & 1) == 0 )
            *(_DWORD *)(this + 48) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 48) & 2) == 0 )
            *(_DWORD *)(this + 48) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 48) & 4) == 0 )
            *(_DWORD *)(this + 48) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 48) & 8) == 0 )
            *(_DWORD *)(this + 48) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 48) & 0x10) == 0 )
            *(_DWORD *)(this + 48) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 48) & 0x20) == 0 )
            *(_DWORD *)(this + 48) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 48) & 0x40) == 0 )
            *(_DWORD *)(this + 48) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 48) & 0x80) == 0 )
            *(_DWORD *)(this + 48) |= 0x80u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 28));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 48) & 0x100) == 0 )
            *(_DWORD *)(this + 48) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 32));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 48) & 0x200) == 0 )
            *(_DWORD *)(this + 48) |= 0x200u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 36));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 48) & 0x400) == 0 )
            *(_DWORD *)(this + 48) |= 0x400u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 40));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 48) & 0x800) == 0 )
            *(_DWORD *)(this + 48) |= 0x800u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 44));
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
        goto LABEL_43;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022B030
// ============================================================
//----- (1022B030) --------------------------------------------------------
int __thiscall sub_1022B030(int *this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebx
  unsigned int v13; // ecx
  int v14; // eax
  _DWORD *v16; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v17; // [esp+14h] [ebp-14h] BYREF
  unsigned int v18; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-Ch] BYREF
  int v20; // [esp+20h] [ebp-8h]
  unsigned int v21; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(this + 1233) = 0;
  v18 = 0;
  v5 = a2[1] + a3;
  v21 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_54;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (v3[1233] & 1) == 0 )
          v3[1233] |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
        goto LABEL_52;
      case 2u:
        if ( (v3[1233] & 2) == 0 )
          v3[1233] |= 2u;
        v16 = 0;
        result = TdrBuf::ReadInt32(a2, &v16);
        if ( result )
          return result;
        if ( !v16 )
          return -37;
        v8 = 0;
        v20 = a2[1];
        v17 = this + 1;
        do
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_102291D0((int)v17, a2, v19);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > (unsigned int)v16 + v20 )
            return -34;
          if ( (_DWORD *)v9 == (_DWORD *)((char *)v16 + v20) )
            goto LABEL_19;
          v17 += 4;
          ++v8;
        }
        while ( v8 < 30 );
        v3 = this;
        goto LABEL_53;
      case 3u:
        if ( (v3[1233] & 4) == 0 )
          v3[1233] |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3 + 484);
        goto LABEL_52;
      case 4u:
        if ( (v3[1233] & 8) == 0 )
          v3[1233] |= 8u;
        v17 = 0;
        result = TdrBuf::ReadInt32(a2, &v17);
        if ( result )
          return result;
        if ( !v17 )
          return -37;
        v8 = 0;
        v20 = a2[1];
        v16 = this + 122;
        do
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_10229820((int)v16, a2, v19);
            if ( v4 )
              return v4;
          }
          v11 = a2[1];
          if ( v11 > (unsigned int)v17 + v20 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)v17 + v20) )
          {
LABEL_19:
            v10 = v8 + 1;
            v3 = this;
            *this = v10;
            goto LABEL_53;
          }
          v16 += 4;
          ++v8;
        }
        while ( v8 < 30 );
        v3 = this;
        goto LABEL_53;
      case 5u:
        if ( (v3[1233] & 0x10) == 0 )
          v3[1233] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3 + 968);
        goto LABEL_52;
      case 6u:
        if ( (v3[1233] & 0x20) == 0 )
          v3[1233] |= 0x20u;
        v17 = 0;
        result = TdrBuf::ReadInt32(a2, &v17);
        if ( result )
          return result;
        if ( !v17 )
          return -37;
        v12 = 0;
        v20 = a2[1];
        v16 = this + 243;
        while ( 1 )
        {
          v19 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v19);
          if ( v4 )
            return v4;
          if ( v19 )
          {
            v4 = sub_1022A070((int)v16, a2, v19);
            if ( v4 )
              return v4;
          }
          v13 = a2[1];
          if ( v13 > (unsigned int)v17 + v20 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)v17 + v20) )
            break;
          v16 += 33;
          if ( ++v12 >= 30 )
          {
            v3 = this;
            goto LABEL_53;
          }
        }
        v14 = v12 + 1;
        v3 = this;
        *(this + 242) = v14;
LABEL_53:
        v5 = v21;
        if ( a2[1] < v21 )
          continue;
LABEL_54:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v18 & 0xF);
LABEL_52:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_53;
        return v4;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10190C60
// ============================================================
//----- (10190C60) --------------------------------------------------------
int __thiscall sub_10190C60(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 44) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_28:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[44] & 1) == 0 )
          v4[44] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[44] & 2) == 0 )
          v4[44] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_7;
      case 3u:
        if ( (v4[44] & 4) == 0 )
          v4[44] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_7;
      case 4u:
        if ( (v4[44] & 8) == 0 )
          v4[44] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = (int)(v16 + 3);
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_101902B0(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 20;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[44] & 0x10) == 0 )
          v4[44] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 172);
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018D250
// ============================================================
//----- (1018D250) --------------------------------------------------------
int __thiscall sub_1018D250(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // ebx
  int v11; // esi
  unsigned int v12; // edx
  unsigned int v13; // esi
  _BYTE *v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // [esp+Ch] [ebp-Ch]
  unsigned int v17; // [esp+10h] [ebp-8h] BYREF
  _DWORD *v18; // [esp+14h] [ebp-4h]

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v18 = this;
  *(this + 1106) = 0;
  v17 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_35;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 1106) & 1) == 0 )
          *(this + 1106) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, this);
        goto LABEL_33;
      case 2u:
        if ( (*(this + 1106) & 2) == 0 )
          *(this + 1106) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v10 = a2;
        if ( !a2 )
          return -37;
        v11 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v18 + v11 + 4);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 320 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        *v18 = v11 + 1;
        goto LABEL_34;
      case 3u:
        if ( (*(this + 1106) & 4) == 0 )
          *(this + 1106) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this + 324);
        goto LABEL_33;
      case 4u:
        if ( (*(this + 1106) & 8) == 0 )
          *(this + 1106) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        a3 = v6[1];
        v14 = this + 82;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v14);
          if ( v5 )
            return v5;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v13;
          v14 += 4;
          if ( v13 >= 0x400 )
          {
            this = v18;
            goto LABEL_34;
          }
        }
        this = v18;
        v18[81] = v13 + 1;
LABEL_34:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_35:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v17 & 0xF);
LABEL_33:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_34;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_10180520
// ============================================================
//----- (10180520) --------------------------------------------------------
int __thiscall sub_10180520(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // edi
  bool v6; // cf
  int result; // eax
  unsigned int v8; // esi
  unsigned int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-Ch]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v5 = this;
  v12 = 0;
  *(this + 20) = 0;
  v10 = v4[1] + v3;
  v6 = v10 < v4[1];
  if ( v10 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (v5[20] & 1) == 0 )
        v5[20] |= 1u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( !result )
      {
        if ( a2 )
        {
          v8 = 0;
          a3 = v4[1];
          while ( 1 )
          {
            result = TdrBuf::ReadInt32(v4, v5);
            if ( result )
              break;
            v9 = v4[1];
            if ( v9 > (unsigned int)a2 + a3 )
              return -34;
            if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
            {
              ++v8;
              ++v5;
              if ( v8 < 0x14 )
                continue;
            }
            v5 = this;
            goto LABEL_16;
          }
        }
        else
        {
          return -37;
        }
      }
      return result;
    }
    result = TdrBuf::SkipField(v4, v12 & 0xF);
    if ( result )
      return result;
LABEL_16:
    if ( v4[1] >= v10 )
    {
      v6 = v10 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10181560
// ============================================================
//----- (10181560) --------------------------------------------------------
int __thiscall sub_10181560(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 28) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 28) & 1) == 0 )
            *(_DWORD *)(this + 28) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 28) & 2) == 0 )
            *(_DWORD *)(this + 28) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 28) & 4) == 0 )
            *(_DWORD *)(this + 28) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 28) & 8) == 0 )
            *(_DWORD *)(this + 28) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 28) & 0x10) == 0 )
            *(_DWORD *)(this + 28) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 28) & 0x20) == 0 )
            *(_DWORD *)(this + 28) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 28) & 0x40) == 0 )
            *(_DWORD *)(this + 28) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
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
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10193260
// ============================================================
//----- (10193260) --------------------------------------------------------
int __thiscall sub_10193260(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
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
// Address Name: SUB_10177AE0
// ============================================================
//----- (10177AE0) --------------------------------------------------------
int __thiscall sub_10177AE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte_2; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // [esp+Ch] [ebp-10h]
  int v17; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h] BYREF
  int v19; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte_2 = 0;
  v19 = this;
  v18 = 0;
  *(_DWORD *)(this + 38) = 0;
  v7 = v4[1] + v3;
  v16 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v18);
    if ( result )
      return result;
    switch ( v18 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 38) & 1) == 0 )
          *(_DWORD *)(v5 + 38) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 38) & 2) == 0 )
          *(_DWORD *)(v5 + 38) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_42;
      case 3u:
        if ( (*(_DWORD *)(v5 + 38) & 4) == 0 )
          *(_DWORD *)(v5 + 38) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v10 + v19 + 8));
          if ( Byte_2 )
            return Byte_2;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)(v5 + 38) & 8) == 0 )
          *(_DWORD *)(v5 + 38) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)(v10 + v19 + 13));
          if ( Byte_2 )
            return Byte_2;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 5 );
        v5 = v19;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 38) & 0x10) == 0 )
          *(_DWORD *)(v5 + 38) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v4[1];
        v14 = (_BYTE *)(v19 + 18);
        a3 = v19 + 18;
        do
        {
          Byte_2 = TdrBuf::ReadInt32(v4, v14);
          if ( Byte_2 )
            return Byte_2;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v17) )
          {
LABEL_20:
            v12 = v10 + 1;
            v5 = v19;
            *(_DWORD *)(v19 + 4) = v12;
            goto LABEL_43;
          }
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v19;
LABEL_43:
        v7 = v16;
        if ( v4[1] < v16 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Byte_2;
      default:
        Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
LABEL_42:
        Byte_2 = Int32;
        if ( !Int32 )
          goto LABEL_43;
        return Byte_2;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_10111D50
// ============================================================
//----- (10111D50) --------------------------------------------------------
int __thiscall sub_10111D50(int this, _DWORD *Size, int a3)
{
  int v3; // ebx
  int v4; // edi
  unsigned int v5; // eax
  int result; // eax
  char v7; // bl
  unsigned int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v12; // [esp+14h] [ebp-14h] BYREF
  unsigned int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = 0;
  *(_DWORD *)(this + 14722) = 0;
  v5 = Size[1] + a3;
  for ( i = v5; ; v5 = i )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_2:
        if ( Size[1] >= v5 )
        {
          if ( Size[1] > v5 )
            return -34;
          return v4;
        }
        result = TdrBuf::ReadVarUInt(Size, &v13);
        if ( result )
          return result;
        if ( v13 >> 4 != 1 )
          break;
        if ( (*(_BYTE *)(v3 + 14722) & 1) == 0 )
          *(_DWORD *)(v3 + 14722) |= 1u;
        if ( Size[1] > Size[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = Size[1];
        if ( Size[2] == v10 )
          return -2;
        *(_BYTE *)v3 = *(_BYTE *)(v10 + *Size);
        ++Size[1];
        v4 = 0;
        v5 = i;
      }
      if ( v13 >> 4 != 2 )
        break;
      if ( (*(_DWORD *)(v3 + 14722) & 2) == 0 )
        *(_DWORD *)(v3 + 14722) |= 2u;
      if ( Size[1] > Size[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = Size[1];
      if ( Size[2] == v9 )
        return -2;
      *(_BYTE *)(v3 + 1) = *(_BYTE *)(v9 + *Size);
      ++Size[1];
      v4 = 0;
      v5 = i;
    }
    if ( v13 >> 4 == 3 )
      break;
    v4 = TdrBuf::SkipField(Size, v13 & 0xF);
    if ( v4 )
      return v4;
  }
  if ( (*(_DWORD *)(v3 + 14722) & 4) == 0 )
    *(_DWORD *)(v3 + 14722) |= 4u;
  v12 = 0;
  result = TdrBuf::ReadInt32(Size, &v12);
  if ( !result )
  {
    if ( !v12 )
      return -37;
    v7 = 0;
    v15 = Size[1];
    while ( 1 )
    {
      v14 = 0;
      v4 = TdrBuf::ReadInt32(Size, &v14);
      if ( v4 )
        return v4;
      if ( v14 )
      {
        v4 = sub_10111100((size_t)Size, v14);
        if ( v4 )
          return v4;
      }
      v8 = Size[1];
      if ( v8 > v15 + v12 )
        return -34;
      if ( v8 == v15 + v12 )
      {
        *(_BYTE *)(this + 1) = v7 + 1;
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
      if ( (unsigned __int8)++v7 >= 0x14u )
      {
        v3 = this;
        v5 = i;
        goto LABEL_2;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10188290
// ============================================================
//----- (10188290) --------------------------------------------------------
int __thiscall sub_10188290(int *this, size_t Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  size_t v12; // ecx
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  _BYTE *v17; // eax
  size_t v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ebx
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // ecx
  unsigned int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch] BYREF
  int v28; // [esp+18h] [ebp-8h]
  int *v29; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Byte = 0;
  v29 = this;
  v27 = 0;
  *(int *)((char *)this + 542) = 0;
  v7 = v4[1] + v3;
  v25 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_82;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v27);
    if ( result )
      return result;
    switch ( v27 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 542) & 1) == 0 )
          *(int *)((char *)v5 + 542) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_80;
      case 2u:
        if ( (*(int *)((char *)v5 + 542) & 2) == 0 )
          *(int *)((char *)v5 + 542) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v28 = v4[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        while ( 1 )
        {
          Byte = TdrBuf::ReadInt32(v4, v11);
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > v28 + Size )
            return -34;
          if ( v12 == v28 + Size )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 40 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v13 = v10 + 1;
        v5 = v29;
        *v29 = v13;
        goto LABEL_81;
      case 3u:
        if ( (*(int *)((char *)v5 + 542) & 4) == 0 )
          *(int *)((char *)v5 + 542) |= 4u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 164);
        goto LABEL_80;
      case 4u:
        if ( (*(int *)((char *)v5 + 542) & 8) == 0 )
          *(int *)((char *)v5 + 542) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 168);
          if ( Byte )
            return Byte;
          v15 = (_DWORD *)v4[1];
          if ( v15 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v15 == (_DWORD *)((char *)a3 + Size) )
            goto LABEL_31;
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 5u:
        if ( (*(int *)((char *)v5 + 542) & 0x10) == 0 )
          *(int *)((char *)v5 + 542) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        v28 = v4[1];
        v17 = v29 + 47;
        a3 = v29 + 47;
        do
        {
          Byte = TdrBuf::ReadInt32(v4, v17);
          if ( Byte )
            return Byte;
          v18 = v4[1];
          if ( v18 > v28 + Size )
            return -34;
          if ( v18 == v28 + Size )
            goto LABEL_31;
          ++v14;
          v17 = ++a3;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 6u:
        if ( (*(int *)((char *)v5 + 542) & 0x20) == 0 )
          *(int *)((char *)v5 + 542) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 268);
          if ( Byte )
            return Byte;
          v19 = (_DWORD *)v4[1];
          if ( v19 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v19 == (_DWORD *)((char *)a3 + Size) )
          {
LABEL_31:
            v16 = v14 + 1;
            v5 = v29;
            v29[41] = v16;
            goto LABEL_81;
          }
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 7u:
        if ( (*(int *)((char *)v5 + 542) & 0x40) == 0 )
          *(int *)((char *)v5 + 542) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 288);
        goto LABEL_80;
      case 8u:
        if ( (*(int *)((char *)v5 + 542) & 0x80) == 0 )
          *(int *)((char *)v5 + 542) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v20 = 0;
        a3 = (_DWORD *)v4[1];
        while ( 1 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v20 + 292);
          if ( Byte )
            return Byte;
          v21 = (_DWORD *)v4[1];
          if ( v21 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v21 == (_DWORD *)((char *)a3 + Size) )
            break;
          if ( ++v20 >= 10 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v22 = v20 + 1;
        v5 = v29;
        v29[72] = v22;
        goto LABEL_81;
      case 9u:
        if ( (*(int *)((char *)v5 + 542) & 0x100) == 0 )
          *(int *)((char *)v5 + 542) |= 0x100u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v26 = v4[1];
        v28 = 0;
        v23 = 0;
        break;
      default:
        Int32 = TdrBuf::SkipField(v4, v27 & 0xF);
LABEL_80:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_81;
        return Byte;
    }
    while ( 1 )
    {
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      if ( Size >= 0x18 )
        return -3;
      Byte = TdrBuf::ReadBytes(v4, (char *)&v29[v23 + 75] + 2, Size);
      if ( Byte )
        return Byte;
      *((_BYTE *)&v29[v23 + 75] + Size + 2) = 0;
      v24 = v4[1];
      if ( v24 > (unsigned int)a3 + v26 )
        return -34;
      if ( (_DWORD *)v24 == (_DWORD *)((char *)a3 + v26) )
        break;
      ++v28;
      v23 += 6;
      if ( v23 >= 60 )
      {
        v5 = v29;
        goto LABEL_81;
      }
    }
    v5 = v29;
    v29[72] = v28 + 1;
LABEL_81:
    v7 = v25;
    if ( v4[1] >= v25 )
    {
LABEL_82:
      if ( v4[1] > v7 )
        return -34;
      return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10166AD0
// ============================================================
//----- (10166AD0) --------------------------------------------------------
int __thiscall sub_10166AD0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016ADD0
// ============================================================
//----- (1016ADD0) --------------------------------------------------------
int __thiscall sub_1016ADD0(int this, _DWORD *Size, int a3)
{
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 634) = 0;
  v5 = Size[1] + a3;
  v10 = v5;
  if ( Size[1] >= v5 )
  {
LABEL_27:
    if ( Size[1] > v5 )
      return -34;
    return v4;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(Size, &v8);
      if ( result )
        break;
      switch ( v8 >> 4 )
      {
        case 2u:
          if ( (*(_BYTE *)(this + 634) & 1) == 0 )
            *(_DWORD *)(this + 634) |= 1u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10167D60(this, Size, v9);
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 634) & 2) == 0 )
            *(_DWORD *)(this + 634) |= 2u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10168550(this + 585, Size, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 634) & 4) == 0 )
            *(_DWORD *)(this + 634) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_10169610(this + 597, Size, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 634) & 8) == 0 )
            *(_DWORD *)(this + 634) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(Size, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_26;
          v7 = sub_1016A350((char *)(this + 625), Size, v9);
          break;
        default:
          v7 = TdrBuf::SkipField(Size, v8 & 0xF);
          break;
      }
      v4 = v7;
      if ( v7 )
        return v4;
LABEL_26:
      v5 = v10;
      if ( Size[1] >= v10 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101764A0
// ============================================================
//----- (101764A0) --------------------------------------------------------
int __thiscall sub_101764A0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  unsigned int v21; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v22; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(this + 303) = 0;
  v21 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (v4[303] & 1) == 0 )
          v4[303] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_36;
      case 6u:
        if ( (v4[303] & 2) == 0 )
          v4[303] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_36;
      case 7u:
        if ( (v4[303] & 4) == 0 )
          v4[303] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v22 + 2;
        a3 = v22 + 2;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 200 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        v22[1] = v13;
        goto LABEL_37;
      case 8u:
        if ( (v4[303] & 8) == 0 )
          v4[303] |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 808);
        goto LABEL_36;
      case 9u:
        if ( (v4[303] & 0x10) == 0 )
          v4[303] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = v6[1];
        v15 = v22 + 203;
        a3 = v22 + 203;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v20) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 100 )
          {
            v4 = v22;
            goto LABEL_37;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        v22[202] = v17;
LABEL_37:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v21 & 0xF);
LABEL_36:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_37;
        return v5;
    }
  }
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
// Address Name: SUB_1015F5A0
// ============================================================
//----- (1015F5A0) --------------------------------------------------------
int __thiscall sub_1015F5A0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  result = print_field(a2, a3, a4, "[fixedTimes]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[blockArg1]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[blockArg2]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[blockArg3]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[blockArg4]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *(this + 5));
            if ( !result )
            {
              v7 = *(this + 5);
              if ( v7 >= 0 )
              {
                if ( v7 <= 5 )
                {
                  result = sub_1024A3B0(a2, a3, v6, "[completeBit]", v7);
                  if ( !result )
                  {
                    v8 = 0;
                    if ( (int)*(this + 5) <= 0 )
                    {
LABEL_15:
                      result = TdrBuf::WriteChar(a2, a4);
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[levelId]", "%d", *(_DWORD *)((char *)this + 29));
                        if ( !result )
                          return print_field(a2, a3, a4, "[levelResult]", "%d", *(_DWORD *)((char *)this + 33));
                      }
                    }
                    else
                    {
                      while ( 1 )
                      {
                        result = Printf(a2, " 0x%02x", *((char *)this + v8 + 24));
                        if ( result )
                          break;
                        if ( ++v8 >= *(this + 5) )
                          goto LABEL_15;
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
          }
        }
      }
    }
  }
  return result;
}
// 1015F6AB: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10171270
// ============================================================
//----- (10171270) --------------------------------------------------------
int __thiscall sub_10171270(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[accMailSendTimes]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[passerbySendTimes]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101806E0
// ============================================================
//----- (101806E0) --------------------------------------------------------
int __thiscall sub_101806E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int v7; // edx

  if ( !"[weaponStyleData]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[weaponStyleData]", 19LL);
    if ( !result )
    {
      v6 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(this + v6));
        if ( result )
          break;
        if ( (unsigned int)++v6 >= 0x14 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v7 = a2[1];
          if ( (unsigned int)(a2[2] - v7) < 2 )
            return -1;
          *(_BYTE *)(v7 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          return 0;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10192D70
// ============================================================
//----- (10192D70) --------------------------------------------------------
int __thiscall sub_10192D70(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int v4; // esi
  _DWORD *i; // edi
  int result; // eax

  v4 = 0;
  for ( i = this; ; i += 46 )
  {
    if ( !"[cLotteryBox]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      break;
    result = Printf(a2, "%s[%u]%c", "[cLotteryBox]", v4, a4);
    if ( result )
      break;
    result = a3 >= 0 ? sub_10192230(i, a2, a3 + 1, a4) : sub_10192230(i, a2, a3, a4);
    if ( result )
      break;
    if ( (unsigned int)++v4 >= 3 )
      return print_field(a2, a3, a4, "[iLastDailyRefreshTime]", "%d", *(this + 138));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018D540
// ============================================================
//----- (1018D540) --------------------------------------------------------
int __thiscall sub_1018D540(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // esi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 320 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[completeBit]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[illustrateCardCount]", "%u", *(this + 81));
          if ( !result )
          {
            v11 = *(this + 81);
            if ( v11 > 0x400 )
              return -7;
            result = sub_1024A3B0(a2, a3, v10, "[illustrateCardInfo]", v11);
            if ( !result )
            {
              v12 = 0;
              if ( *(this + 81) )
              {
                for ( i = this + 82; ; ++i )
                {
                  result = Printf(a2, " %u", *i);
                  if ( result )
                    break;
                  if ( (unsigned int)++v12 >= *(this + 81) )
                  {
                    v4 = a2;
                    return TdrBuf::WriteChar(v4, a4);
                  }
                }
              }
              else
              {
                return TdrBuf::WriteChar(v4, a4);
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((char *)this + v9 + 4));
          if ( result )
            break;
          if ( ++v9 >= *this )
            goto LABEL_10;
        }
      }
    }
  }
  return result;
}
// 1018D5A1: variable 'v7' is possibly undefined
// 1018D634: variable 'v10' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017BDC0
// ============================================================
//----- (1017BDC0) --------------------------------------------------------
int __thiscall sub_1017BDC0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // bl
  int v8; // ecx
  unsigned __int8 v9; // bl
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl
  int v12; // eax

  result = print_field(a2, a3, a4, "[itemRebuildTypeCount]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lastItemRebuildTime]", "%I64u", *(_QWORD *)(this + 1));
    if ( !result )
    {
      if ( *this > 8u )
        return -7;
      result = sub_1024A3B0(a2, a3, v6, "[itemRebuildlimitId]", *this);
      if ( !result )
      {
        v7 = 0;
        if ( *this )
        {
          while ( 1 )
          {
            result = Printf(a2, " 0x%02x", *(this + v7 + 9));
            if ( result )
              break;
            if ( ++v7 >= *this )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          result = TdrBuf::WriteChar(a2, a4);
          if ( !result )
          {
            if ( *this > 8u )
              return -7;
            result = sub_1024A3B0(a2, a3, v8, "[itemRebuildLimitcount]", *this);
            if ( !result )
            {
              v9 = 0;
              if ( *this )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v9 + 17));
                  if ( result )
                    break;
                  if ( ++v9 >= *this )
                    goto LABEL_15;
                }
              }
              else
              {
LABEL_15:
                result = TdrBuf::WriteChar(a2, a4);
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[tracksCount]", "0x%02x", *(this + 49));
                  if ( !result )
                  {
                    v10 = *(this + 49);
                    if ( v10 > 0xAu )
                      return -7;
                    v11 = 0;
                    if ( v10 )
                    {
                      while ( 1 )
                      {
                        result = sub_1024A230(a2, a3, a4, "[tracksSet]", v11);
                        if ( result )
                          break;
                        v12 = a3;
                        if ( a3 >= 0 )
                          v12 = a3 + 1;
                        result = sub_1017A3D0(this + 69 * v11 + 50, a2, v12, a4);
                        if ( result )
                          break;
                        if ( ++v11 >= *(this + 49) )
                          return 0;
                      }
                    }
                    else
                    {
                      return 0;
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
// 1017BE39: variable 'v6' is possibly undefined
// 1017BE9E: variable 'v8' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018A240
// ============================================================
//----- (1018A240) --------------------------------------------------------
int __thiscall sub_1018A240(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // bl
  unsigned __int8 *v7; // ecx

  result = print_field(a2, a3, a4, "[groupCnt]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this <= 0x28u )
    {
      v6 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          if ( !"[suitSkillGroupData]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[suitSkillGroupData]", v6, a4);
          if ( result )
            break;
          v7 = this + 913 * v6 + 1;
          result = a3 >= 0 ? sub_10189710(v7, a2, a3 + 1, a4) : sub_10189710(v7, a2, a3, a4);
          if ( result )
            break;
          if ( ++v6 >= *this )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Address Name: SUB_10114E80
// ============================================================
//----- (10114E80) --------------------------------------------------------
int __thiscall sub_10114E80(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  unsigned __int8 *v8; // ecx

  result = print_field(a2, a3, a4, "[curPlan]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[planCnt]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v6 = *(this + 1);
      if ( v6 <= 5u )
      {
        v7 = 0;
        if ( v6 )
        {
          while ( 1 )
          {
            if ( !"[supplyPlanList]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[supplyPlanList]", v7, (char)a4);
            if ( result )
              break;
            v8 = this + 392 * v7 + 2;
            result = a3 >= 0 ? sub_10114140(v8, a2, a3 + 1, a4) : sub_10114140(v8, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *(this + 1) )
              return 0;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return -7;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10172A90
// ============================================================
//----- (10172A90) --------------------------------------------------------
int __thiscall sub_10172A90(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 20 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[prizeId]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_13:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            v12 = *(this + 1);
            if ( v12 < 0 )
              return -6;
            if ( v12 > 20 )
              return -7;
            result = sub_1024A3B0(v4, a3, v11, "[state]", v12);
            if ( !result )
            {
              v13 = 0;
              if ( (int)*(this + 1) <= 0 )
              {
                return TdrBuf::WriteChar(v4, a4);
              }
              else
              {
                while ( 1 )
                {
                  result = Printf(v4, " 0x%02x", *((unsigned __int8 *)this + v13 + 88));
                  if ( result )
                    break;
                  if ( ++v13 >= *(this + 1) )
                    return TdrBuf::WriteChar(v4, a4);
                }
              }
            }
          }
        }
        else
        {
          v10 = this + 2;
          while ( 1 )
          {
            result = Printf(a2, " %d", *v10);
            if ( result )
              break;
            ++v9;
            ++v10;
            if ( v9 >= *(this + 1) )
            {
              v4 = a2;
              goto LABEL_13;
            }
          }
        }
      }
    }
  }
  return result;
}
// 10172B13: variable 'v7' is possibly undefined
// 10172B7A: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017DA00
// ============================================================
//----- (1017DA00) --------------------------------------------------------
int __thiscall sub_1017DA00(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  unsigned __int8 *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 50 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (unsigned __int8 *)(this + 1); ; i += 89 )
          {
            if ( !"[tracesSet]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[tracesSet]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1017D010(i, a2, a3 + 1, a4) : sub_1017D010(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10188850
// ============================================================
//----- (10188850) --------------------------------------------------------
int __thiscall sub_10188850(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  int v21; // ecx
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // ebx
  const char *v26; // eax
  int v27; // [esp+14h] [ebp+8h]
  int v28; // [esp+14h] [ebp+8h]
  int i; // [esp+14h] [ebp+8h]

  result = print_field(a2, a3, a4, "[autoCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 40 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[autoSpeak]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_11:
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[quickCount]", "%d", *(this + 41));
        if ( result )
          return result;
        v12 = *(this + 41);
        if ( v12 < 0 )
          return -6;
        if ( v12 <= 20 )
        {
          result = sub_1024A3B0(a2, a3, v11, "[quickSpeakIndex]", v12);
          if ( result )
            return result;
          v13 = 0;
          if ( (int)*(this + 41) > 0 )
          {
            do
            {
              result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v13 + 168));
              if ( result )
                return result;
            }
            while ( ++v13 < *(this + 41) );
          }
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v15 = *(this + 41);
          if ( v15 < 0 )
            return -6;
          if ( v15 <= 20 )
          {
            result = sub_1024A3B0(a2, a3, v14, "[quickSpeakId]", v15);
            if ( result )
              return result;
            v16 = 0;
            if ( (int)*(this + 41) > 0 )
            {
              v17 = this + 47;
              v28 = (int)(this + 47);
              do
              {
                result = Printf(a2, " %d", *v17);
                if ( result )
                  return result;
                ++v16;
                v17 = (_DWORD *)(v28 + 4);
                v28 += 4;
              }
              while ( v16 < *(this + 41) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v19 = *(this + 41);
            if ( v19 < 0 )
              return -6;
            if ( v19 <= 20 )
            {
              result = sub_1024A3B0(a2, a3, v18, "[quickSpeakType]", v19);
              if ( result )
                return result;
              v20 = 0;
              if ( (int)*(this + 41) > 0 )
              {
                do
                {
                  result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v20 + 268));
                  if ( result )
                    return result;
                }
                while ( ++v20 < *(this + 41) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[selfDefCount]", "%d", *(this + 72));
              if ( result )
                return result;
              v22 = *(this + 72);
              if ( v22 < 0 )
                return -6;
              if ( v22 <= 10 )
              {
                result = sub_1024A3B0(a2, a3, v21, "[selfDefIndex]", v22);
                if ( result )
                  return result;
                v23 = 0;
                if ( (int)*(this + 72) > 0 )
                {
                  do
                  {
                    result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v23 + 292));
                    if ( result )
                      return result;
                  }
                  while ( ++v23 < *(this + 72) );
                }
                result = TdrBuf::WriteChar(a2, a4);
                if ( result )
                  return result;
                v24 = *(this + 72);
                if ( v24 < 0 )
                  return -6;
                if ( v24 <= 10 )
                {
                  v25 = 0;
                  if ( v24 <= 0 )
                    return 0;
                  v26 = (char *)this + 302;
                  for ( i = (int)this + 302; ; i += 24 )
                  {
                    result = sub_1024A480(a2, a3, a4, "[selfDefContent]", v25, v26);
                    if ( result )
                      break;
                    ++v25;
                    v26 = (const char *)(i + 24);
                    if ( v25 >= *(this + 72) )
                      return 0;
                  }
                  return result;
                }
              }
            }
          }
        }
        return -7;
      }
      v10 = this + 1;
      v27 = (int)(this + 1);
      while ( 1 )
      {
        result = Printf(a2, " %d", *v10);
        if ( result )
          break;
        ++v9;
        v10 = (_DWORD *)(v27 + 4);
        v27 += 4;
        if ( v9 >= *this )
          goto LABEL_11;
      }
    }
  }
  return result;
}
// 101888AF: variable 'v7' is possibly undefined
// 10188953: variable 'v11' is possibly undefined
// 101889CF: variable 'v14' is possibly undefined
// 10188A53: variable 'v18' is possibly undefined
// 10188AF5: variable 'v21' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101817B0
// ============================================================
//----- (101817B0) --------------------------------------------------------
int __thiscall sub_101817B0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[dateDay]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[curHigher]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[meetTime]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[giantTime]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[dailyRewardFlag]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[rewardFlag]", "%d", *(this + 5));
            if ( !result )
              return print_field(a2, a3, a4, "[activity]", "%d", *(this + 6));
          }
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
// Address Name: SUB_1017F1E0
// ============================================================
//----- (1017F1E0) --------------------------------------------------------
int __thiscall sub_1017F1E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iCurSeason]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iScore]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iScoreTop]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iWeekReward]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[iStreak]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[iWinNum]", "%d", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[iLoseNum]", "%d", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[iTotalNum]", "%d", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[iRewardMask]", "%d", *(this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[iExRewardCount]", "%d", *(this + 9));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[iStepReward]", "%d", *(this + 10));
                      if ( !result )
                        return print_field(a2, a3, a4, "[iExMedalCount]", "%d", *(this + 11));
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
// Address Name: SUB_1018FC30
// ============================================================
//----- (1018FC30) --------------------------------------------------------
int __thiscall sub_1018FC30(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v7; // eax
  int v8; // ebx
  bool v9; // cc
  int *v10; // eax
  int *v11; // ecx
  _DWORD *v13; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[guideBookChapterCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 8 )
      {
        v8 = 0;
        v9 = v7 <= 0;
        v10 = this;
        if ( v9 )
        {
LABEL_17:
          result = print_field(a2, a3, a4, "[isFisrtAutoOpenGuideBook]", "0x%02x", *((char *)v10 + 108));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[weaopnId]", "0x%02x", *((char *)this + 109));
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[guideActionInfos]");
              if ( !result )
              {
                v11 = (int *)((char *)this + 110);
                if ( a3 >= 0 )
                  return sub_1018E890(v11, a2, a3 + 1, a4);
                else
                  return sub_1018E890(v11, a2, a3, a4);
              }
            }
          }
        }
        else
        {
          v13 = this + 1;
          while ( 1 )
          {
            if ( !"[guideBookChapterInfos]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guideBookChapterInfos]", v8, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1018F060(v13, a2, a3 + 1, a4) : sub_1018F060(v13, a2, a3, a4);
            if ( result )
              break;
            v10 = this;
            ++v8;
            v13 = (_DWORD *)((char *)v13 + 13);
            if ( v8 >= *this )
              goto LABEL_17;
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
// Address Name: SUB_10158990
// ============================================================
//----- (10158990) --------------------------------------------------------
int __thiscall sub_10158990(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int *v5; // ecx
  int v6; // ecx

  if ( !"[fetchProcs]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[fetchProcs]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_10153890(this, a2, a3 + 1, a4) : sub_10153890(this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[scriptVars]");
        if ( !result )
        {
          v5 = this + 1342;
          if ( a3 >= 0 )
            result = sub_10156700(v5, a2, a3 + 1, a4);
          else
            result = sub_10156700(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[onlineTime]");
            if ( !result )
            {
              v6 = (int)(this + 11508);
              if ( a3 >= 0 )
                return sub_10157F00(v6, a2, a3 + 1, a4);
              else
                return sub_10157F00(v6, a2, a3, a4);
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
// Address Name: SUB_10193400
// ============================================================
//----- (10193400) --------------------------------------------------------
int __thiscall sub_10193400(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[index]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[state]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016B080
// ============================================================
//----- (1016B080) --------------------------------------------------------
int __thiscall sub_1016B080(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // ecx

  if ( !"[stChatTabs]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[stChatTabs]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_10167FE0(this, a2, a3 + 1, a4) : sub_10167FE0(this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[stHunterStar]");
        if ( !result )
        {
          v5 = this + 585;
          result = a3 >= 0 ? sub_101686F0(v5, a2, a3 + 1, a4) : sub_101686F0(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[stGamePadCustom]");
            if ( !result )
            {
              v6 = this + 597;
              if ( a3 >= 0 )
                result = sub_10169B10(v6, a2, a3 + 1, a4);
              else
                result = sub_10169B10(v6, a2, a3, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[stSilverTips]");
                if ( !result )
                {
                  v7 = this + 625;
                  if ( a3 >= 0 )
                    return sub_1016A540(v7, a2, a3 + 1, a4);
                  else
                    return sub_1016A540(v7, a2, a3, a4);
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
// Address Name: SUB_102121E0
// ============================================================
//----- (102121E0) --------------------------------------------------------
int __thiscall sub_102121E0(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v7; // ecx
  bool v8; // cc
  void (__cdecl *v9)(const wchar_t *, const wchar_t *, unsigned int); // ecx
  _BYTE *v10; // ecx
  _BYTE *v11; // ecx
  _BYTE *v12; // ecx
  _BYTE *v13; // ecx
  int v14; // edx
  int v16; // [esp+1Ch] [ebp+Ch]
  int v17; // [esp+1Ch] [ebp+Ch]
  __int16 *v18; // [esp+20h] [ebp+10h]
  __int16 *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[shopCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 20 )
      return -7;
    v8 = v7 <= 0;
    v16 = 0;
    v9 = _wassert;
    if ( v8 )
    {
LABEL_17:
      if ( !"[dayBuyItemLimitData]" )
        v9(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
      result = sub_1024A140(a3);
      if ( !result )
      {
        result = Printf(a2, "%s%c", "[dayBuyItemLimitData]", (char)a4);
        if ( !result )
        {
          v10 = this + 2651;
          result = a3 >= 0 ? sub_1020F2F0(v10, a2, a3 + 1, a4) : sub_1020F2F0(v10, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[weekBuyItemLimitData]");
            if ( !result )
            {
              v11 = (char *)this + 13433;
              result = a3 >= 0 ? sub_1020F2F0(v11, a2, a3 + 1, a4) : sub_1020F2F0(v11, a2, a3, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[monthBuyItemLimitData]");
                if ( !result )
                {
                  v12 = (char *)this + 16262;
                  result = a3 >= 0 ? sub_1020F2F0(v12, a2, a3 + 1, a4) : sub_1020F2F0(v12, a2, a3, a4);
                  if ( !result )
                  {
                    result = print_structure((int)a2, a3, a4, (int)"[foreverBuyLimitData]");
                    if ( !result )
                    {
                      v13 = (char *)this + 19091;
                      result = a3 >= 0 ? sub_1020F2F0(v13, a2, a3 + 1, a4) : sub_1020F2F0(v13, a2, a3, a4);
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[groupCount]", "%d", *(this + 5480));
                        if ( !result )
                        {
                          v14 = *(this + 5480);
                          if ( v14 < 0 )
                            return -6;
                          if ( v14 > 128 )
                            return -7;
                          v17 = 0;
                          if ( v14 <= 0 )
                          {
                            return 0;
                          }
                          else
                          {
                            for ( i = (__int16 *)(this + 5481); ; i += 7 )
                            {
                              result = sub_1024A230(a2, a3, a4, "[groups]", result);
                              if ( result )
                                break;
                              result = a3 >= 0 ? sub_10210E70(i, a2, a3 + 1, a4) : sub_10210E70(i, a2, a3, a4);
                              if ( result )
                                break;
                              result = v17 + 1;
                              v17 = result;
                              if ( result >= *(this + 5480) )
                                return 0;
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
    else
    {
      v18 = (__int16 *)(this + 1);
      while ( 1 )
      {
        if ( !"[shops]" )
          v9(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[shops]", v16, (char)a4);
        if ( result )
          break;
        result = a3 >= 0 ? sub_102106F0(v18, a2, a3 + 1, a4) : sub_102106F0(v18, a2, a3, a4);
        if ( result )
          break;
        v18 += 265;
        ++v16;
        v9 = _wassert;
        if ( v16 >= *this )
          goto LABEL_17;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10166CF0
// ============================================================
//----- (10166CF0) --------------------------------------------------------
int __thiscall sub_10166CF0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[bStepID]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[bStepState]", "0x%02x", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017E4A0
// ============================================================
//----- (1017E4A0) --------------------------------------------------------
int __thiscall sub_1017E4A0(_QWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int v7; // ecx

  result = print_field(a2, a3, a4, "[tCatTime]", "%I64i", *this);
  if ( !result )
  {
    if ( !"[vCatSeq]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s[0 : %I64i]:", "[vCatSeq]", 6LL);
      if ( !result )
      {
        v6 = 0;
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v6 + 8));
          if ( result )
            break;
          if ( (unsigned int)++v6 >= 7 )
          {
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0xC4u);
            v7 = a2[1];
            if ( (unsigned int)(a2[2] - v7) < 2 )
              return -1;
            *(_BYTE *)(v7 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            result = print_field(a2, a3, a4, "[iOpen]", "0x%02x", *((unsigned __int8 *)this + 15));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[tOpenTime]", "%I64i", *(this + 2));
              if ( !result )
                return print_field(a2, a3, a4, "[iTools]", "0x%02x", *((unsigned __int8 *)this + 24));
            }
            return result;
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
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
// Address Name: SUB_101767E0
// ============================================================
//----- (101767E0) --------------------------------------------------------
int __thiscall sub_101767E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[points]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[ctxCount]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 200 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[ctxInfo]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_13:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            result = print_field(v4, a3, a4, "[prizesCount]", "%d", *(this + 202));
            if ( !result )
            {
              v12 = *(this + 202);
              if ( v12 < 0 )
                return -6;
              if ( v12 > 100 )
                return -7;
              result = sub_1024A3B0(v4, a3, v11, "[prizesID]", v12);
              if ( !result )
              {
                v13 = 0;
                if ( (int)*(this + 202) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = this + 203; ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v13 >= *(this + 202) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v10 = this + 2;
          while ( 1 )
          {
            result = Printf(a2, " %d", *v10);
            if ( result )
              break;
            ++v9;
            ++v10;
            if ( v9 >= *(this + 1) )
            {
              v4 = a2;
              goto LABEL_13;
            }
          }
        }
      }
    }
  }
  return result;
}
// 10176865: variable 'v7' is possibly undefined
// 101768FF: variable 'v11' is possibly undefined



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
// Address Name: SUB_1024CF20
// ============================================================
//----- (1024CF20) --------------------------------------------------------
int __thiscall sub_1024CF20(int this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  if ( !"[giftAttr]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[giftAttr]", a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_1024C2F0((_DWORD *)this, a2, a3 + 1, a4) : sub_1024C2F0((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[giftNum]", "0x%02x", *(unsigned __int8 *)(this + 16));
        if ( !result )
        {
          v7 = *(_BYTE *)(this + 16);
          if ( v7 > 0x64u )
            return -7;
          result = sub_1024A3B0(a2, a3, v6, "[giftId]", v7);
          if ( !result )
          {
            v8 = 0;
            if ( *(_BYTE *)(this + 16) )
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v8 + 17));
                if ( result )
                  break;
                if ( ++v8 >= *(_BYTE *)(this + 16) )
                  goto LABEL_16;
              }
            }
            else
            {
LABEL_16:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                v10 = *(_BYTE *)(this + 16);
                if ( v10 > 0x64u )
                  return -7;
                result = sub_1024A3B0(a2, a3, v9, "[giftState]", v10);
                if ( !result )
                {
                  v11 = 0;
                  if ( *(_BYTE *)(this + 16) )
                  {
                    while ( 1 )
                    {
                      result = Printf(a2, " 0x%02x", *(unsigned __int8 *)(v11 + this + 417));
                      if ( result )
                        break;
                      if ( ++v11 >= *(_BYTE *)(this + 16) )
                        return TdrBuf::WriteChar(a2, a4);
                    }
                  }
                  else
                  {
                    return TdrBuf::WriteChar(a2, a4);
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
// 1024CFE6: variable 'v6' is possibly undefined
// 1024D046: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10184DE0
// ============================================================
//----- (10184DE0) --------------------------------------------------------
int __thiscall sub_10184DE0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // edi
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _QWORD *v10; // edi
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[lastReportTime]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[todayReportTimes]", "0x%02x", *(this + 4));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[reportOtherPlayerNum]", "%d", *(_DWORD *)(this + 5));
      if ( !result )
      {
        v8 = *(_DWORD *)(this + 5);
        if ( v8 < 0 )
          return -6;
        if ( v8 > 10 )
          return -7;
        result = sub_1024A3B0(a2, a3, v7, "[otherPlayerDBID]", v8);
        if ( !result )
        {
          v9 = 0;
          if ( *(int *)(this + 5) <= 0 )
          {
LABEL_14:
            result = TdrBuf::WriteChar(v4, a4);
            if ( !result )
            {
              v12 = *(_DWORD *)(this + 5);
              if ( v12 < 0 )
                return -6;
              if ( v12 > 10 )
                return -7;
              result = sub_1024A3B0(v4, a3, v11, "[reportOtherPlayerTime]", v12);
              if ( !result )
              {
                v13 = 0;
                if ( *(int *)(this + 5) <= 0 )
                {
LABEL_22:
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( !result )
                    return print_field(a2, a3, a4, "[todayHangUpTimes]", "0x%02x", *(this + 129));
                }
                else
                {
                  v14 = this + 89;
                  while ( 1 )
                  {
                    result = Printf(a2, " %u", *v14);
                    if ( result )
                      break;
                    ++v13;
                    ++v14;
                    if ( v13 >= *(_DWORD *)(this + 5) )
                      goto LABEL_22;
                  }
                }
              }
            }
          }
          else
          {
            v10 = this + 9;
            while ( 1 )
            {
              result = Printf(a2, " %I64u", *v10);
              if ( result )
                break;
              ++v9;
              ++v10;
              if ( v9 >= *(_DWORD *)(this + 5) )
              {
                v4 = a2;
                goto LABEL_14;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 10184E88: variable 'v7' is possibly undefined
// 10184EFB: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1015E6B0
// ============================================================
//----- (1015E6B0) --------------------------------------------------------
int __thiscall sub_1015E6B0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  float *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  _DWORD *v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ebx
  _DWORD *v22; // eax
  int v23; // [esp+1Ch] [ebp+8h]
  int v24; // [esp+1Ch] [ebp+8h]
  int v25; // [esp+1Ch] [ebp+8h]
  int v26; // [esp+1Ch] [ebp+8h]

  result = print_field(a2, a3, a4, "[resetTimes]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[taskCount]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 5 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[tasks]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_12:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v12 = *(this + 1);
          if ( v12 < 0 )
            return -6;
          if ( v12 <= 5 )
          {
            result = sub_1024A3B0(a2, a3, v11, "[ratios]", v12);
            if ( result )
              return result;
            v13 = 0;
            if ( (int)*(this + 1) > 0 )
            {
              v14 = (float *)(this + 7);
              v24 = (int)(this + 7);
              do
              {
                result = Printf(a2, " %f", *v14);
                if ( result )
                  return result;
                ++v13;
                v14 = (float *)(v24 + 4);
                v24 += 4;
              }
              while ( v13 < *(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            result = print_field(a2, a3, a4, "[completeTaskCount]", "%d", *(this + 12));
            if ( result )
              return result;
            v16 = *(this + 12);
            if ( v16 < 0 )
              return -6;
            if ( v16 <= 20 )
            {
              result = sub_1024A3B0(a2, a3, v15, "[completeTasks]", v16);
              if ( result )
                return result;
              v17 = 0;
              if ( (int)*(this + 12) > 0 )
              {
                v18 = this + 13;
                v25 = (int)(this + 13);
                do
                {
                  result = Printf(a2, " %d", *v18);
                  if ( result )
                    return result;
                  ++v17;
                  v18 = (_DWORD *)(v25 + 4);
                  v25 += 4;
                }
                while ( v17 < *(this + 12) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[levelCount]", "%d", *(this + 33));
              if ( result )
                return result;
              v20 = *(this + 33);
              if ( v20 < 0 )
                return -6;
              if ( v20 <= 250 )
              {
                result = sub_1024A3B0(a2, a3, v19, "[levels]", v20);
                if ( !result )
                {
                  v21 = 0;
                  if ( (int)*(this + 33) <= 0 )
                  {
LABEL_38:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[maxTaskCount]", "%d", *(this + 284));
                      if ( !result )
                        return print_field(a2, a3, a4, "[bTaskMoreThan100]", "%d", *(this + 285));
                    }
                  }
                  else
                  {
                    v22 = this + 34;
                    v26 = (int)(this + 34);
                    while ( 1 )
                    {
                      result = Printf(a2, " %d", *v22);
                      if ( result )
                        break;
                      ++v21;
                      v22 = (_DWORD *)(v26 + 4);
                      v26 += 4;
                      if ( v21 >= *(this + 33) )
                        goto LABEL_38;
                    }
                  }
                }
                return result;
              }
            }
          }
          return -7;
        }
        v10 = this + 2;
        v23 = (int)(this + 2);
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          v10 = (_DWORD *)(v23 + 4);
          v23 += 4;
          if ( v9 >= *(this + 1) )
            goto LABEL_12;
        }
      }
    }
  }
  return result;
}
// 1015E733: variable 'v7' is possibly undefined
// 1015E7A7: variable 'v11' is possibly undefined
// 1015E84F: variable 'v15' is possibly undefined
// 1015E8F6: variable 'v19' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10190F10
// ============================================================
//----- (10190F10) --------------------------------------------------------
int __thiscall sub_10190F10(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ebx
  _DWORD *i; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[iSearchCount]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iRrefreshCount]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iVipRefreshCount]", "%d", *(this + 2));
      if ( !result )
      {
        v6 = 0;
        for ( i = this + 3; ; i += 5 )
        {
          if ( !"[vItemPoolList]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[vItemPoolList]", v6, a4);
          if ( result )
            break;
          result = a3 >= 0 ? sub_10190480(i, a2, a3 + 1, a4) : sub_10190480(i, a2, a3, a4);
          if ( result )
            break;
          if ( (unsigned int)++v6 >= 8 )
            return print_field(a2, a3, a4, "[iLastUpdateTime]", "%d", *(this + 43));
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10186050
// ============================================================
//----- (10186050) --------------------------------------------------------
int __thiscall sub_10186050(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned int v5; // edi
  _DWORD *v6; // ebx

  result = print_field(a2, a3, a4, "[waterExp]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[fireExp]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[thunderExp]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[dragonExp]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[iceExp]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[duration]", "%d", *(this + 5));
            if ( !result )
            {
              v5 = 0;
              v6 = this + 6;
              do
              {
                result = sub_1024A230(a2, a3, a4, "[slots]", v5);
                if ( result )
                  break;
                result = a3 >= 0 ? sub_10185540(v6, a2, a3 + 1, a4) : sub_10185540(v6, a2, a3, a4);
                if ( result )
                  break;
                ++v5;
                v6 += 3;
              }
              while ( v5 < 8 );
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
// Address Name: SUB_10112060
// ============================================================
//----- (10112060) --------------------------------------------------------
int __thiscall sub_10112060(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  unsigned __int8 *v8; // ecx

  result = print_field(a2, a3, a4, "[curPlan]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[planCnt]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v6 = *(this + 1);
      if ( v6 <= 0x14u )
      {
        v7 = 0;
        if ( v6 )
        {
          while ( 1 )
          {
            if ( !"[equipPlanList]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[equipPlanList]", v7, (char)a4);
            if ( result )
              break;
            v8 = this + 736 * v7 + 2;
            result = a3 >= 0 ? sub_101113F0(v8, a2, a3 + 1, a4) : sub_101113F0(v8, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *(this + 1) )
              return 0;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return -7;
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10231D90
// ============================================================
//----- (10231D90) --------------------------------------------------------
int __thiscall sub_10231D90(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  char v6; // al
  int v7; // esi
  _DWORD *i; // ebx

  result = print_field(a2, a3, a4, "[count]", "0x%02x", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 5 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 129 )
          {
            if ( !"[boxes]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[boxes]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10231270(i, a2, a3 + 1, a4) : sub_10231270(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10177E20
// ============================================================
//----- (10177E20) --------------------------------------------------------
int __thiscall sub_10177E20(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  int v15; // edi
  _DWORD *i; // ebx

  v4 = a2;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 5 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[awardsType]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( (int)*(this + 1) <= 0 )
        {
LABEL_11:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v11 = *(this + 1);
          if ( v11 < 0 )
            return -6;
          if ( v11 <= 5 )
          {
            result = sub_1024A3B0(a2, a3, v10, "[awardsState]", v11);
            if ( result )
              return result;
            v12 = 0;
            if ( (int)*(this + 1) > 0 )
            {
              do
              {
                result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v12 + 13));
                if ( result )
                  return result;
              }
              while ( ++v12 < *(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v14 = *(this + 1);
            if ( v14 < 0 )
              return -6;
            if ( v14 <= 5 )
            {
              result = sub_1024A3B0(a2, a3, v13, "[awardsId]", v14);
              if ( !result )
              {
                v15 = 0;
                if ( (int)*(this + 1) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = (_DWORD *)((char *)this + 18); ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v15 >= *(this + 1) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
              return result;
            }
          }
          return -7;
        }
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v9 + 8));
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
// 10177EA3: variable 'v7' is possibly undefined
// 10177F12: variable 'v10' is possibly undefined
// 10177F7E: variable 'v13' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10180E80
// ============================================================
//----- (10180E80) --------------------------------------------------------
int __thiscall sub_10180E80(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[silverCount]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[weekFreeFetchTimes]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[weekBuyFetchTimes]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[enlargeTimes]", "%d", *(this + 3));
    }
  }
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
// Address Name: SUB_1018C980
// ============================================================
//----- (1018C980) --------------------------------------------------------
int __thiscall sub_1018C980(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 128 )
      {
        result = sub_1024A3B0(a2, a3, v6, "[completeBit]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *this <= 0 )
          {
            return TdrBuf::WriteChar(a2, a4);
          }
          else
          {
            while ( 1 )
            {
              result = Printf(a2, " 0x%02x", *((char *)this + v8 + 4));
              if ( result )
                break;
              if ( ++v8 >= *this )
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
// 1018C9DD: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022B490
// ============================================================
//----- (1022B490) --------------------------------------------------------
int __thiscall sub_1022B490(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int *v7; // eax
  int v8; // ecx
  int *v9; // eax
  int v10; // ecx
  int v11; // edx
  int v13; // [esp+1Ch] [ebp+Ch]
  int v14; // [esp+1Ch] [ebp+Ch]
  int v15; // [esp+1Ch] [ebp+Ch]
  _DWORD *v16; // [esp+20h] [ebp+10h]
  _DWORD *v17; // [esp+20h] [ebp+10h]
  _DWORD *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( result )
    return result;
  v7 = this;
  v8 = *this;
  if ( *this < 0 )
    return -6;
  if ( v8 > 30 )
    return -7;
  v13 = 0;
  if ( v8 <= 0 )
  {
LABEL_18:
    result = print_field(a2, a3, a4, "[orgNum]", "%d", v7[121]);
    if ( result )
      return result;
    v9 = this;
    v10 = *this;
    if ( *this < 0 )
      return -6;
    if ( v10 <= 30 )
    {
      v14 = 0;
      if ( v10 > 0 )
      {
        v17 = this + 122;
        while ( 1 )
        {
          if ( !"[npcOrgPkg]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            return result;
          result = Printf(a2, "%s[%u]%c", "[npcOrgPkg]", v14, a4);
          if ( result )
            return result;
          result = a3 >= 0 ? sub_102299A0(v17, a2, a3 + 1, a4) : sub_102299A0(v17, a2, a3, a4);
          if ( result )
            return result;
          v17 += 4;
          if ( ++v14 >= *this )
          {
            v9 = this;
            break;
          }
        }
      }
      result = print_field(a2, a3, a4, "[preferNum]", "%d", v9[242]);
      if ( result )
        return result;
      v11 = *(this + 242);
      if ( v11 < 0 )
        return -6;
      if ( v11 <= 30 )
      {
        v15 = 0;
        if ( v11 <= 0 )
          return 0;
        for ( i = this + 243; ; i += 33 )
        {
          result = sub_1024A230(a2, a3, a4, "[npcPrefersPkg]", result);
          if ( result )
            break;
          result = a3 >= 0 ? sub_1022A2C0(i, a2, a3 + 1, a4) : sub_1022A2C0(i, a2, a3, a4);
          if ( result )
            break;
          result = v15 + 1;
          v15 = result;
          if ( result >= *(this + 242) )
            return 0;
        }
        return result;
      }
    }
    return -7;
  }
  v16 = this + 1;
  while ( 1 )
  {
    if ( !"[npcAtdPkg]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      return result;
    result = Printf(a2, "%s[%u]%c", "[npcAtdPkg]", v13, a4);
    if ( result )
      return result;
    result = a3 >= 0 ? sub_10229350(v16, a2, a3 + 1, a4) : sub_10229350(v16, a2, a3, a4);
    if ( result )
      return result;
    v16 += 4;
    if ( ++v13 >= *this )
    {
      v7 = this;
      goto LABEL_18;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017FDD0
// ============================================================
//----- (1017FDD0) --------------------------------------------------------
int __thiscall sub_1017FDD0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edi
  _DWORD *i; // ebx
  int v10; // ecx

  if ( !"[weaponRecord]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[weaponRecord]", 19LL);
    if ( !result )
    {
      v6 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(this + v6));
        if ( result )
          break;
        if ( (unsigned int)++v6 >= 0x14 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v7 = a2[1];
          if ( (unsigned int)(a2[2] - v7) < 2 )
            return -1;
          *(_BYTE *)(v7 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          if ( !"[weaponRecordTime]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x9Du);
          result = sub_1024A140(a3);
          if ( !result )
          {
            result = Printf(a2, "%s[0 : %I64i]:", "[weaponRecordTime]", 19LL);
            if ( !result )
            {
              v8 = 0;
              for ( i = this + 20; ; ++i )
              {
                result = Printf(a2, " %d", *i);
                if ( result )
                  break;
                if ( (unsigned int)++v8 >= 0x14 )
                {
                  if ( a2[1] > a2[2] )
                    _wassert(
                      L"position <= length",
                      L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                      0xC4u);
                  v10 = a2[1];
                  if ( (unsigned int)(a2[2] - v10) >= 2 )
                  {
                    *(_BYTE *)(v10 + *a2) = a4;
                    *(_BYTE *)(++a2[1] + *a2) = 0;
                    return 0;
                  }
                  return -1;
                }
              }
            }
          }
          return result;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10186F20
// ============================================================
//----- (10186F20) --------------------------------------------------------
int __thiscall sub_10186F20(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  _DWORD *i; // ebx
  unsigned __int8 *v18; // [esp+Ch] [ebp-4h]

  v4 = a2;
  result = print_field(a2, a3, a4, "[hasFlag]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[snapCnt]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
    {
      v8 = *(_DWORD *)(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 100 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[itemType]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( *(int *)(this + 1) <= 0 )
        {
LABEL_12:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v12 = *(_DWORD *)(this + 1);
          if ( v12 < 0 )
            return -6;
          if ( v12 <= 100 )
          {
            result = sub_1024A3B0(a2, a3, v11, "[bindType]", v12);
            if ( result )
              return result;
            v13 = 0;
            if ( *(int *)(this + 1) > 0 )
            {
              do
              {
                result = Printf(a2, " 0x%02x", *(this + v13 + 405));
                if ( result )
                  return result;
              }
              while ( ++v13 < *(_DWORD *)(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v15 = *(_DWORD *)(this + 1);
            if ( v15 < 0 )
              return -6;
            if ( v15 <= 100 )
            {
              result = sub_1024A3B0(a2, a3, v14, "[itemCount]", v15);
              if ( !result )
              {
                v16 = 0;
                if ( *(int *)(this + 1) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = this + 505; ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v16 >= *(_DWORD *)(this + 1) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
              return result;
            }
          }
          return -7;
        }
        v10 = this + 5;
        v18 = this + 5;
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          v10 = v18 + 4;
          v18 += 4;
          if ( v9 >= *(_DWORD *)(this + 1) )
            goto LABEL_12;
        }
      }
    }
  }
  return result;
}
// 10186FAA: variable 'v7' is possibly undefined
// 10187022: variable 'v11' is possibly undefined
// 10187095: variable 'v14' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101644B0
// ============================================================
//----- (101644B0) --------------------------------------------------------
int __thiscall sub_101644B0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[storeSize]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[normalSize]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[materialStoreSize]", "%d", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024C0C0
// ============================================================
//----- (1024C0C0) --------------------------------------------------------
int __thiscall sub_1024C0C0(_DWORD *this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 2);
          break;
        default:
          VarUInt = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarUInt;
      if ( VarUInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101901B0
// ============================================================
//----- (101901B0) --------------------------------------------------------
int __thiscall sub_101901B0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
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
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
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
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10179DE0
// ============================================================
//----- (10179DE0) --------------------------------------------------------
int __thiscall sub_10179DE0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int *v14; // eax
  unsigned int v15; // ecx
  int *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-Ch]
  unsigned int v22; // [esp+18h] [ebp-8h] BYREF
  int v23; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v23 = this;
  v22 = 0;
  *(_DWORD *)(this + 65) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 65) & 1) == 0 )
          *(_DWORD *)(v5 + 65) |= 1u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 65) & 2) == 0 )
          *(_DWORD *)(v5 + 65) |= 2u;
        Byte_2 = TdrBuf::ReadVarInt(v4, (int *)(v5 + 1));
        goto LABEL_42;
      case 4u:
        if ( (*(_DWORD *)(v5 + 65) & 4) == 0 )
          *(_DWORD *)(v5 + 65) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v11 = (int *)(v23 + 5);
        a3 = v23 + 5;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v11);
          if ( VarInt )
            return VarInt;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_20;
          ++v10;
          v11 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 65) & 8) == 0 )
          *(_DWORD *)(v5 + 65) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v4[1];
        v14 = (int *)(v23 + 25);
        a3 = v23 + 25;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v14);
          if ( VarInt )
            return VarInt;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_20;
          ++v10;
          v14 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 6u:
        if ( (*(_DWORD *)(v5 + 65) & 0x10) == 0 )
          *(_DWORD *)(v5 + 65) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v21 = v4[1];
        v16 = (int *)(v23 + 45);
        a3 = v23 + 45;
        do
        {
          VarInt = TdrBuf::ReadVarInt(v4, v16);
          if ( VarInt )
            return VarInt;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + v21 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + v21) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v23;
            *(_DWORD *)(v23 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v16 = (int *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
LABEL_43:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v22 & 0xF);
LABEL_42:
        VarInt = Byte_2;
        if ( !Byte_2 )
          goto LABEL_43;
        return VarInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10191D40
// ============================================================
//----- (10191D40) --------------------------------------------------------
int __thiscall sub_10191D40(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  char *v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 45) = 0;
  v15 = 0;
  v7 = (char *)v3 + v6[1];
  v12 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_28:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[45] & 1) == 0 )
          v4[45] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[45] & 2) == 0 )
          v4[45] |= 2u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 1);
        goto LABEL_7;
      case 3u:
        if ( (v4[45] & 4) == 0 )
          v4[45] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 2);
        goto LABEL_7;
      case 4u:
        if ( (v4[45] & 8) == 0 )
          v4[45] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = v16 + 3;
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_10191430(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 5;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= (unsigned int)v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[45] & 0x10) == 0 )
          v4[45] |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 43);
        goto LABEL_7;
      case 6u:
        if ( (v4[45] & 0x20) == 0 )
          v4[45] |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 44);
        goto LABEL_7;
      default:
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101891C0
// ============================================================
//----- (101891C0) --------------------------------------------------------
int __thiscall sub_101891C0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 909) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 909) & 1) == 0 )
          *(_DWORD *)(v5 + 909) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v5 + 909) & 2) == 0 )
          *(_DWORD *)(v5 + 909) |= 2u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_35;
      case 3u:
        if ( (*(_DWORD *)(v5 + 909) & 4) == 0 )
          *(_DWORD *)(v5 + 909) |= 4u;
        VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_35;
      case 4u:
        if ( (*(_DWORD *)(v5 + 909) & 8) == 0 )
          *(_DWORD *)(v5 + 909) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadVarInt(v4, (int *)(v16 + 4 * v10 + 9));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v5 + 909) & 0x10) == 0 )
          *(_DWORD *)(v5 + 909) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 729 + v10));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v16;
            *(_BYTE *)(v16 + 8) = v10 + 1;
            v5 = v12;
            goto LABEL_36;
          }
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
LABEL_36:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_37:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        VarInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_35:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_36;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10167BB0
// ============================================================
//----- (10167BB0) --------------------------------------------------------
int __thiscall sub_10167BB0(int this, _DWORD *Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = Size;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 581) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[581] & 1) == 0 )
          *(_DWORD *)(v5 + 581) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 581) & 2) == 0 )
            *(_DWORD *)(v5 + 581) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10167210(&v16[29 * v9 + 1], (size_t)v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = (_DWORD *)v4[1];
            if ( v10 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v10 == (_DWORD *)((char *)Size + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x14u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101684B0
// ============================================================
//----- (101684B0) --------------------------------------------------------
int __thiscall sub_101684B0(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
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
// Address Name: SUB_101691E0
// ============================================================
//----- (101691E0) --------------------------------------------------------
int __thiscall sub_101691E0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016A260
// ============================================================
//----- (1016A260) --------------------------------------------------------
int __thiscall sub_1016A260(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
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
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadVarUInt(a2, this + 1);
      if ( result )
        return result;
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
// Address Name: SUB_10110EE0
// ============================================================
//----- (10110EE0) --------------------------------------------------------
int __thiscall sub_10110EE0(_DWORD *this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte; // eax
  char v10; // bl
  size_t v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v16 = this;
  *(this + 183) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_32;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[183] & 1) == 0 )
          v4[183] |= 1u;
        Byte = TdrBuf::ReadByte(v6, v4);
        goto LABEL_30;
      case 2u:
        if ( (v4[183] & 2) == 0 )
          v4[183] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x14 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (char *)v4 + 1, Size);
        if ( !Bytes )
        {
          *((_BYTE *)v4 + Size + 1) = 0;
          goto LABEL_31;
        }
        return Bytes;
      case 3u:
        if ( (v4[183] & 4) == 0 )
          v4[183] |= 4u;
        Byte = TdrBuf::ReadByte(v6, (_BYTE *)v4 + 21);
        goto LABEL_30;
      case 4u:
        if ( (v4[183] & 8) == 0 )
          v4[183] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &a3);
          if ( Bytes )
            return Bytes;
          if ( a3 )
          {
            Bytes = sub_10110200(v6, a3);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          if ( (unsigned __int8)++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_31;
          }
        }
        v12 = v16;
        *((_BYTE *)v16 + 21) = v10 + 1;
        v4 = v12;
LABEL_31:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_32:
        if ( v6[1] > v7 )
          return -34;
        return Bytes;
      default:
        Byte = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_30:
        Bytes = Byte;
        if ( !Byte )
          goto LABEL_31;
        return Bytes;
    }
  }
}
// 10110200: using guessed type _DWORD __stdcall sub_10110200(_DWORD, _DWORD);



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
// Address Name: SUB_10210220
// ============================================================
//----- (10210220) --------------------------------------------------------
int __thiscall sub_10210220(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  __int16 v10; // di
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 526) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_32;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 526) & 1) == 0 )
          *(_DWORD *)(v5 + 526) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)v5);
        goto LABEL_30;
      case 2u:
        if ( (*(_DWORD *)(v5 + 526) & 2) == 0 )
          *(_DWORD *)(v5 + 526) |= 2u;
        VarUInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 4));
        goto LABEL_30;
      case 3u:
        if ( (*(_DWORD *)(v5 + 526) & 4) == 0 )
          *(_DWORD *)(v5 + 526) |= 4u;
        VarUInt = TdrBuf::ReadVarShort(v4, (_WORD *)(v5 + 8));
        goto LABEL_30;
      case 4u:
        if ( (*(_DWORD *)(v5 + 526) & 8) == 0 )
          *(_DWORD *)(v5 + 526) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v4[1];
        while ( 1 )
        {
          a3 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a3);
          if ( v6 )
            return v6;
          if ( a3 )
          {
            v6 = sub_1020F920(v16 + 8 * v10 + 10, v4, a3);
            if ( v6 )
              return v6;
          }
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v16;
            goto LABEL_31;
          }
        }
        v12 = v10 + 1;
        v5 = v16;
        *(_WORD *)(v16 + 8) = v12;
LABEL_31:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_32:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 5u:
        if ( (*(_DWORD *)(v5 + 526) & 0x10) == 0 )
          *(_DWORD *)(v5 + 526) |= 0x10u;
        VarUInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 522));
        goto LABEL_30;
      default:
        VarUInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_30:
        v6 = VarUInt;
        if ( !VarUInt )
          goto LABEL_31;
        return v6;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10210BB0
// ============================================================
//----- (10210BB0) --------------------------------------------------------
int __thiscall sub_10210BB0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 10) = 0;
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
          if ( (*(_BYTE *)(this + 10) & 1) == 0 )
            *(_DWORD *)(this + 10) |= 1u;
          VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 10) & 2) == 0 )
            *(_DWORD *)(this + 10) |= 2u;
          VarShort = TdrBuf::ReadVarInt(a2, (int *)(this + 2));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 10) & 4) == 0 )
            *(_DWORD *)(this + 10) |= 4u;
          VarShort = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 6));
          break;
        default:
          VarShort = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarShort;
      if ( VarShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1020EB80
// ============================================================
//----- (1020EB80) --------------------------------------------------------
int __thiscall sub_1020EB80(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int i; // eax
  unsigned int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-Ch]
  unsigned int v21; // [esp+10h] [ebp-8h] BYREF
  int v22; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v22 = this;
  v21 = 0;
  *(_DWORD *)(this + 2825) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_50:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 2825) & 1) == 0 )
          *(_DWORD *)(v5 + 2825) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)v5);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v5 + 2825) & 2) == 0 )
          *(_DWORD *)(v5 + 2825) |= 2u;
        VarULong = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v5 + 2825) & 4) == 0 )
          *(_DWORD *)(v5 + 2825) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v11 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v22 + 9 + v11));
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
          {
            v11 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 6u:
        if ( (*(_DWORD *)(v5 + 2825) & 8) == 0 )
          *(_DWORD *)(v5 + 2825) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v14 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v22 + 4 * v14 + 265));
          if ( Byte )
            return Byte;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + a3) )
          {
            v14 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 7u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x10) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v16 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v22 + 4 * v16 + 1289));
          if ( Byte )
            return Byte;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + a3) )
          {
            v16 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 8u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x20) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          for ( i = 0; ; i = v10 )
          {
            Byte = TdrBuf::ReadVarUShort(v4, (_WORD *)(v22 + 2 * i + 2313));
            if ( Byte )
              return Byte;
            v19 = v4[1];
            if ( v19 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + a3) )
            {
LABEL_19:
              v13 = v22;
              *(_BYTE *)(v22 + 8) = v10 + 1;
              v5 = v13;
LABEL_49:
              v7 = v20;
              if ( v4[1] >= v20 )
                goto LABEL_50;
              goto LABEL_2;
            }
            ++v10;
          }
LABEL_54:
          result = -34;
        }
        else
        {
LABEL_55:
          result = -37;
        }
        break;
      default:
        VarULong = TdrBuf::SkipField(v4, v21 & 0xF);
LABEL_48:
        Byte = VarULong;
        if ( !VarULong )
          goto LABEL_49;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101534E0
// ============================================================
//----- (101534E0) --------------------------------------------------------
int __thiscall sub_101534E0(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 1341) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[1341] & 1) == 0 )
          v4[1341] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[1341] & 2) == 0 )
            v4[1341] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10152AE0(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 67;
            if ( ++v10 >= 20 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10157930
// ============================================================
//----- (10157930) --------------------------------------------------------
int __thiscall sub_10157930(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = (_DWORD *)a2;
  v16 = this;
  *(_DWORD *)(this + 417) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 417) & 1) == 0 )
          *(_DWORD *)(v4 + 417) |= 1u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)v4, v6, a2);
        goto LABEL_36;
      case 2u:
        if ( (*(_DWORD *)(v4 + 417) & 2) == 0 )
          *(_DWORD *)(v4 + 417) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)(v4 + 32), v6, a2);
        goto LABEL_36;
      case 3u:
        if ( (*(_DWORD *)(v4 + 417) & 4) == 0 )
          *(_DWORD *)(v4 + 417) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156CC0((_DWORD *)(v4 + 64), v6, a2);
LABEL_36:
        v5 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_37;
        return v5;
      case 4u:
        if ( (*(_DWORD *)(v4 + 417) & 8) == 0 )
          *(_DWORD *)(v4 + 417) |= 8u;
        Byte_2 = TdrBuf::ReadByte_2(v6, (_BYTE *)(v4 + 96));
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v4 + 417) & 0x10) == 0 )
          *(_DWORD *)(v4 + 417) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          v5 = TdrBuf::ReadInt32(v6, &a3);
          if ( v5 )
            return v5;
          if ( a3 )
          {
            v5 = sub_10156CC0((_DWORD *)(32 * v10 + v16 + 97), v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > v14 + a2 )
            return -34;
          if ( v11 == v14 + a2 )
            break;
          if ( ++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_37;
          }
        }
        v12 = v16;
        *(_BYTE *)(v16 + 96) = v10 + 1;
        v4 = v12;
LABEL_37:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Byte_2 = TdrBuf::SkipField(v6, v15 & 0xF);
        goto LABEL_36;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10156350
// ============================================================
//----- (10156350) --------------------------------------------------------
int __thiscall sub_10156350(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  unsigned int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 10165) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[10165] & 1) == 0 )
          v4[10165] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10165] & 2) == 0 )
            v4[10165] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10155990(a3, (int)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 726;
            if ( ++v10 >= 56 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10229EF0
// ============================================================
//----- (10229EF0) --------------------------------------------------------
int __thiscall sub_10229EF0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int *v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int *v17; // [esp+18h] [ebp-8h]
  unsigned int v18; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(this + 32) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_26:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      switch ( v18 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 32) & 1) == 0 )
            *(this + 32) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          break;
        case 2u:
          if ( (*(this + 32) & 2) == 0 )
            *(this + 32) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 1);
          break;
        case 3u:
          if ( (*(this + 32) & 4) == 0 )
            *(this + 32) |= 4u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( result )
            return result;
          if ( !a3 )
            return -37;
          v10 = this + 2;
          v16 = v4[1];
          v11 = 0;
          v12 = a2;
          v17 = this + 2;
          while ( 1 )
          {
            v6 = TdrBuf::ReadVarInt(v12, v10);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v16 )
              return -34;
            if ( v13 == a3 + v16 )
            {
              v14 = v11 + 1;
              v4 = a2;
              *(this + 1) = v14;
              goto LABEL_25;
            }
            ++v11;
            v10 = ++v17;
            if ( v11 >= 30 )
            {
              v4 = a2;
              goto LABEL_25;
            }
          }
        default:
          VarInt = TdrBuf::SkipField(v4, v18 & 0xF);
          break;
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_25:
      v7 = v15;
      if ( v4[1] >= v15 )
        goto LABEL_26;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10229770
// ============================================================
//----- (10229770) --------------------------------------------------------
int __thiscall sub_10229770(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
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
// Address Name: SUB_10229120
// ============================================================
//----- (10229120) --------------------------------------------------------
int __thiscall sub_10229120(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
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
// Address Name: SUB_10230DE0
// ============================================================
//----- (10230DE0) --------------------------------------------------------
int __thiscall sub_10230DE0(int *this, char *a2, int a3)
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
  *(this + 128) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v10 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_29:
    if ( *((_DWORD *)a2 + 1) > v5 )
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
          if ( (*(_BYTE *)(this + 128) & 1) == 0 )
            *(this + 128) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 128) & 2) == 0 )
            *(this + 128) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 128) & 4) == 0 )
            *(this + 128) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          VarInt = sub_1022D150((int)(this + 2), a2, v9);
          break;
        case 4u:
          if ( (*(this + 128) & 8) == 0 )
            *(this + 128) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          VarInt = sub_1022FA50((int)this + 15, a2, v9);
          break;
        case 5u:
          if ( (*(this + 128) & 0x10) == 0 )
            *(this + 128) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 126);
          break;
        case 6u:
          if ( (*(this + 128) & 0x20) == 0 )
            *(this + 128) |= 0x20u;
          VarInt = TdrBuf::ReadVarUInt(a2, this + 127);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
LABEL_28:
      v5 = v10;
      if ( *((_DWORD *)a2 + 1) >= v10 )
        goto LABEL_29;
    }
  }
  return result;
}



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
// Address Name: SUB_1017CB80
// ============================================================
//----- (1017CB80) --------------------------------------------------------
int __thiscall sub_1017CB80(int this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int VarInt; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 85) = 0;
  v7 = (char *)v3 + v4[1];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_32:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return VarInt;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(v5 + 85) & 1) == 0 )
            *(_DWORD *)(v5 + 85) |= 1u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v12 = v4[1];
          if ( v4[2] == v12 )
            return -2;
          *(_BYTE *)v5 = *(_BYTE *)(v12 + *v4);
          ++v4[1];
          VarInt = 0;
          break;
        case 2u:
          if ( (*(_DWORD *)(v5 + 85) & 2) == 0 )
            *(_DWORD *)(v5 + 85) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, (int *)(v5 + 1));
          if ( VarInt )
            return VarInt;
          break;
        case 3u:
          if ( (*(_DWORD *)(v5 + 85) & 4) == 0 )
            *(_DWORD *)(v5 + 85) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = (int *)(v17 + 5);
          while ( 1 )
          {
            v15 = 0;
            VarInt = TdrBuf::ReadInt32(v4, &v15);
            if ( VarInt )
              return VarInt;
            if ( v15 )
            {
              VarInt = sub_1017C330(a3, v4, v15);
              if ( VarInt )
                return VarInt;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v9 + 1;
              v5 = v17;
              *(_DWORD *)(v17 + 1) = v11;
              goto LABEL_31;
            }
            a3 += 4;
            if ( ++v9 >= 5 )
            {
              v5 = v17;
              goto LABEL_31;
            }
          }
        default:
          VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
          if ( VarInt )
            return VarInt;
          break;
      }
LABEL_31:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_32;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018E340
// ============================================================
//----- (1018E340) --------------------------------------------------------
int __thiscall sub_1018E340(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  char *v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  int *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v20 = this;
  *(this + 66) = 0;
  v19 = 0;
  v7 = (char *)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v4[66] & 1) == 0 )
          v4[66] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_35;
      case 2u:
        if ( (v4[66] & 2) == 0 )
          v4[66] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (int *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)v20 + v10 + 4);
          if ( v5 )
            return v5;
          v11 = v6[1];
          if ( (_DWORD *)v11 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            break;
          if ( ++v10 >= 160 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v12 = v10 + 1;
        v4 = v20;
        *v20 = v12;
        goto LABEL_36;
      case 3u:
        if ( (v4[66] & 4) == 0 )
          v4[66] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 41);
        goto LABEL_35;
      case 4u:
        if ( (v4[66] & 8) == 0 )
          v4[66] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v17 = v6[1];
        a3 = v20 + 42;
        while ( 1 )
        {
          v18 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v18);
          if ( v5 )
            return v5;
          if ( v18 )
          {
            v5 = sub_1018DA20(a3, v6, v18);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 += 3;
          if ( ++v13 >= 8 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v15 = v13 + 1;
        v4 = v20;
        v20[41] = v15;
LABEL_36:
        v7 = v16;
        if ( v6[1] < (unsigned int)v16 )
          continue;
LABEL_37:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_35:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_36;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018ED90
// ============================================================
//----- (1018ED90) --------------------------------------------------------
int __thiscall sub_1018ED90(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
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
      if ( v9 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 9) & 2) == 0 )
          *(_DWORD *)(this + 9) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(this + 4));
        goto LABEL_19;
      }
      if ( v9 >> 4 != 3 )
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 8) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
LABEL_19:
    v4 = VarInt;
    if ( VarInt )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10185300
// ============================================================
//----- (10185300) --------------------------------------------------------
int __thiscall sub_10185300(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarUInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10113A10
// ============================================================
//----- (10113A10) --------------------------------------------------------
int __thiscall sub_10113A10(int *this, size_t Size, int *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Bytes; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  size_t v10; // ebx
  int *v11; // eax
  int v12; // ebx
  int *v13; // eax
  size_t v14; // ecx
  int v15; // eax
  int *v16; // eax
  size_t v17; // ecx
  int *v18; // eax
  size_t v19; // ecx
  unsigned int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-Ch]
  unsigned int v24; // [esp+18h] [ebp-8h] BYREF
  int *v25; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Bytes = 0;
  v25 = this;
  v24 = 0;
  *(this + 97) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v24);
    if ( result )
      return result;
    switch ( v24 >> 4 )
    {
      case 1u:
        if ( (v5[97] & 1) == 0 )
          v5[97] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, v5);
        goto LABEL_48;
      case 2u:
        if ( (v5[97] & 2) == 0 )
          v5[97] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x14 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, v25 + 1, Size);
        if ( !Bytes )
        {
          v11 = v25;
          *((_BYTE *)v25 + v10 + 4) = 0;
          v5 = v11;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (v5[97] & 4) == 0 )
          v5[97] |= 4u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 6);
        goto LABEL_48;
      case 4u:
        if ( (v5[97] & 8) == 0 )
          v5[97] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v21 = v4[1];
        v13 = v25 + 7;
        a3 = v25 + 7;
        do
        {
          Bytes = TdrBuf::ReadVarInt(v4, v13);
          if ( Bytes )
            return Bytes;
          v14 = v4[1];
          if ( v14 > v21 + Size )
            return -34;
          if ( v14 == v21 + Size )
            goto LABEL_26;
          ++v12;
          v13 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
        goto LABEL_49;
      case 5u:
        if ( (v5[97] & 0x10) == 0 )
          v5[97] |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v22 = v4[1];
        v16 = v25 + 37;
        a3 = v25 + 37;
        do
        {
          Bytes = TdrBuf::ReadVarInt(v4, v16);
          if ( Bytes )
            return Bytes;
          v17 = v4[1];
          if ( v17 > v22 + Size )
            return -34;
          if ( v17 == v22 + Size )
            goto LABEL_26;
          ++v12;
          v16 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
        goto LABEL_49;
      case 6u:
        if ( (v5[97] & 0x20) == 0 )
          v5[97] |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v23 = v4[1];
        v18 = v25 + 67;
        a3 = v25 + 67;
        do
        {
          Bytes = TdrBuf::ReadVarInt(v4, v18);
          if ( Bytes )
            return Bytes;
          v19 = v4[1];
          if ( v19 > v23 + Size )
            return -34;
          if ( v19 == v23 + Size )
          {
LABEL_26:
            v15 = v12 + 1;
            v5 = v25;
            v25[6] = v15;
            goto LABEL_49;
          }
          ++v12;
          v18 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
LABEL_49:
        v7 = v20;
        if ( v4[1] < v20 )
          continue;
LABEL_50:
        if ( v4[1] > v7 )
          return -34;
        return Bytes;
      default:
        VarInt = TdrBuf::SkipField(v4, v24 & 0xF);
LABEL_48:
        Bytes = VarInt;
        if ( !VarInt )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10189400
// ============================================================
//----- (10189400) --------------------------------------------------------
int __thiscall sub_10189400(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  unsigned int v15; // [esp+10h] [ebp-8h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 909) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 909) & 1) == 0 )
          *(_DWORD *)(v5 + 909) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v5 + 909) & 2) == 0 )
          *(_DWORD *)(v5 + 909) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_35;
      case 3u:
        if ( (*(_DWORD *)(v5 + 909) & 4) == 0 )
          *(_DWORD *)(v5 + 909) |= 4u;
        Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_35;
      case 4u:
        if ( (*(_DWORD *)(v5 + 909) & 8) == 0 )
          *(_DWORD *)(v5 + 909) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 9));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_23;
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v5 + 909) & 0x10) == 0 )
          *(_DWORD *)(v5 + 909) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 729 + v10));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_23:
            v12 = v16;
            *(_BYTE *)(v16 + 8) = v10 + 1;
            v5 = v12;
            goto LABEL_36;
          }
          ++v10;
        }
        while ( v10 < 0xB4u );
        v5 = v16;
LABEL_36:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_37:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_35:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_36;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10230FC0
// ============================================================
//----- (10230FC0) --------------------------------------------------------
int __thiscall sub_10230FC0(int this, char *a2, int a3)
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
  *(_DWORD *)(this + 512) = 0;
  v5 = *((_DWORD *)a2 + 1) + a3;
  v10 = v5;
  if ( *((_DWORD *)a2 + 1) >= v5 )
  {
LABEL_29:
    if ( *((_DWORD *)a2 + 1) > v5 )
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
          if ( (*(_BYTE *)(this + 512) & 1) == 0 )
            *(_DWORD *)(this + 512) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 512) & 2) == 0 )
            *(_DWORD *)(this + 512) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 512) & 4) == 0 )
            *(_DWORD *)(this + 512) |= 4u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          Int32 = sub_1022D240((char *)(this + 8), a2, v9);
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 512) & 8) == 0 )
            *(_DWORD *)(this + 512) |= 8u;
          v9 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v9);
          if ( v4 )
            return v4;
          if ( !v9 )
            goto LABEL_28;
          Int32 = sub_1022FF30(this + 15, a2, v9);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 512) & 0x10) == 0 )
            *(_DWORD *)(this + 512) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 504));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 512) & 0x20) == 0 )
            *(_DWORD *)(this + 512) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 508));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
LABEL_28:
      v5 = v10;
      if ( *((_DWORD *)a2 + 1) >= v10 )
        goto LABEL_29;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10210C80
// ============================================================
//----- (10210C80) --------------------------------------------------------
int __thiscall sub_10210C80(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  _BYTE *v7; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 0;
  *(_DWORD *)(this + 10) = 0;
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
      if ( (*(this + 10) & 1) == 0 )
        *(_DWORD *)(this + 10) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
LABEL_22:
      if ( a2[1] >= v4 )
      {
        v5 = v4 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
    if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 10) & 2) == 0 )
        *(_DWORD *)(this + 10) |= 2u;
      v7 = this + 2;
    }
    else
    {
      if ( v9 >> 4 != 3 )
      {
        result = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_14;
      }
      if ( (*(_DWORD *)(this + 10) & 4) == 0 )
        *(_DWORD *)(this + 10) |= 4u;
      v7 = this + 6;
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
// Address Name: SUB_10210420
// ============================================================
//----- (10210420) --------------------------------------------------------
int __thiscall sub_10210420(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  __int16 v10; // di
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  v6 = 0;
  v16 = this;
  v15 = 0;
  *(_DWORD *)(this + 526) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_32;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 526) & 1) == 0 )
          *(_DWORD *)(v5 + 526) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_30;
      case 2u:
        if ( (*(_DWORD *)(v5 + 526) & 2) == 0 )
          *(_DWORD *)(v5 + 526) |= 2u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 4));
        goto LABEL_30;
      case 3u:
        if ( (*(_DWORD *)(v5 + 526) & 4) == 0 )
          *(_DWORD *)(v5 + 526) |= 4u;
        Int32 = TdrBuf::ReadInt16(v4, (_BYTE *)(v5 + 8));
        goto LABEL_30;
      case 4u:
        if ( (*(_DWORD *)(v5 + 526) & 8) == 0 )
          *(_DWORD *)(v5 + 526) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v4[1];
        while ( 1 )
        {
          a3 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a3);
          if ( v6 )
            return v6;
          if ( a3 )
          {
            v6 = sub_1020F9C0((_DWORD *)(v16 + 8 * v10 + 10), v4, a3);
            if ( v6 )
              return v6;
          }
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 64 )
          {
            v5 = v16;
            goto LABEL_31;
          }
        }
        v12 = v10 + 1;
        v5 = v16;
        *(_WORD *)(v16 + 8) = v12;
LABEL_31:
        v7 = v13;
        if ( v4[1] < v13 )
          continue;
LABEL_32:
        if ( v4[1] > v7 )
          return -34;
        return v6;
      case 5u:
        if ( (*(_DWORD *)(v5 + 526) & 0x10) == 0 )
          *(_DWORD *)(v5 + 526) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 522));
        goto LABEL_30;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_30:
        v6 = Int32;
        if ( !Int32 )
          goto LABEL_31;
        return v6;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1020EED0
// ============================================================
//----- (1020EED0) --------------------------------------------------------
int __thiscall sub_1020EED0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned __int8 v10; // bl
  int v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // ecx
  int v16; // eax
  unsigned int v17; // ecx
  int i; // eax
  unsigned int v19; // ecx
  unsigned int v20; // [esp+Ch] [ebp-Ch]
  unsigned int v21; // [esp+10h] [ebp-8h] BYREF
  int v22; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Byte = 0;
  v22 = this;
  v21 = 0;
  *(_DWORD *)(this + 2825) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_50:
    if ( v4[1] > v7 )
      return -34;
    return Byte;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v4, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 2825) & 1) == 0 )
          *(_DWORD *)(v5 + 2825) |= 1u;
        Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)v5);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v5 + 2825) & 2) == 0 )
          *(_DWORD *)(v5 + 2825) |= 2u;
        Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 8));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v5 + 2825) & 4) == 0 )
          *(_DWORD *)(v5 + 2825) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v11 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v22 + 9 + v11));
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + a3) )
          {
            v11 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 6u:
        if ( (*(_DWORD *)(v5 + 2825) & 8) == 0 )
          *(_DWORD *)(v5 + 2825) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v14 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v22 + 4 * v14 + 265));
          if ( Byte )
            return Byte;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + a3) )
          {
            v14 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 7u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x10) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_55;
        v10 = 0;
        a3 = v4[1];
        v16 = 0;
        while ( 2 )
        {
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v22 + 4 * v16 + 1289));
          if ( Byte )
            return Byte;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            goto LABEL_54;
          if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + a3) )
          {
            v16 = ++v10;
            continue;
          }
          goto LABEL_19;
        }
      case 8u:
        if ( (*(_DWORD *)(v5 + 2825) & 0x20) == 0 )
          *(_DWORD *)(v5 + 2825) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          a3 = v4[1];
          for ( i = 0; ; i = v10 )
          {
            Byte = TdrBuf::ReadInt16(v4, (_BYTE *)(v22 + 2 * i + 2313));
            if ( Byte )
              return Byte;
            v19 = v4[1];
            if ( v19 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v19 == (_DWORD *)((char *)a2 + a3) )
            {
LABEL_19:
              v13 = v22;
              *(_BYTE *)(v22 + 8) = v10 + 1;
              v5 = v13;
LABEL_49:
              v7 = v20;
              if ( v4[1] >= v20 )
                goto LABEL_50;
              goto LABEL_2;
            }
            ++v10;
          }
LABEL_54:
          result = -34;
        }
        else
        {
LABEL_55:
          result = -37;
        }
        break;
      default:
        Int64 = TdrBuf::SkipField(v4, v21 & 0xF);
LABEL_48:
        Byte = Int64;
        if ( !Int64 )
          goto LABEL_49;
        return Byte;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017CD60
// ============================================================
//----- (1017CD60) --------------------------------------------------------
int __thiscall sub_1017CD60(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  int v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v17 = this;
  v16 = 0;
  *(_DWORD *)(this + 85) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_32:
    if ( v4[1] > v7 )
      return -34;
    return Int32;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(v5 + 85) & 1) == 0 )
            *(_DWORD *)(v5 + 85) |= 1u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v12 = v4[1];
          if ( v4[2] == v12 )
            return -2;
          *(_BYTE *)v5 = *(_BYTE *)(v12 + *v4);
          ++v4[1];
          Int32 = 0;
          break;
        case 2u:
          if ( (*(_DWORD *)(v5 + 85) & 2) == 0 )
            *(_DWORD *)(v5 + 85) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 1));
          if ( Int32 )
            return Int32;
          break;
        case 3u:
          if ( (*(_DWORD *)(v5 + 85) & 4) == 0 )
            *(_DWORD *)(v5 + 85) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 5;
          while ( 1 )
          {
            v15 = 0;
            Int32 = TdrBuf::ReadInt32(v4, &v15);
            if ( Int32 )
              return Int32;
            if ( v15 )
            {
              Int32 = sub_1017C3E0(a3, v4, v15);
              if ( Int32 )
                return Int32;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v9 + 1;
              v5 = v17;
              *(_DWORD *)(v17 + 1) = v11;
              goto LABEL_31;
            }
            a3 += 16;
            if ( ++v9 >= 5 )
            {
              v5 = v17;
              goto LABEL_31;
            }
          }
        default:
          Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
          if ( Int32 )
            return Int32;
          break;
      }
LABEL_31:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_32;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017A070
// ============================================================
//----- (1017A070) --------------------------------------------------------
int __thiscall sub_1017A070(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  _BYTE *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+14h] [ebp-Ch]
  unsigned int v22; // [esp+18h] [ebp-8h] BYREF
  int v23; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v23 = this;
  v22 = 0;
  *(_DWORD *)(this + 65) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_44;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 65) & 1) == 0 )
          *(_DWORD *)(v5 + 65) |= 1u;
        Byte_2 = TdrBuf::ReadByte_2(v4, (_BYTE *)v5);
        goto LABEL_42;
      case 2u:
        if ( (*(_DWORD *)(v5 + 65) & 2) == 0 )
          *(_DWORD *)(v5 + 65) |= 2u;
        Byte_2 = TdrBuf::ReadInt32(v4, (_BYTE *)(v5 + 1));
        goto LABEL_42;
      case 4u:
        if ( (*(_DWORD *)(v5 + 65) & 4) == 0 )
          *(_DWORD *)(v5 + 65) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v4[1];
        v11 = (_BYTE *)(v23 + 5);
        a3 = v23 + 5;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v11);
          if ( Int32 )
            return Int32;
          v12 = v4[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_20;
          ++v10;
          v11 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)(v5 + 65) & 8) == 0 )
          *(_DWORD *)(v5 + 65) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v4[1];
        v14 = (_BYTE *)(v23 + 25);
        a3 = v23 + 25;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v14);
          if ( Int32 )
            return Int32;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_20;
          ++v10;
          v14 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
        goto LABEL_43;
      case 6u:
        if ( (*(_DWORD *)(v5 + 65) & 0x10) == 0 )
          *(_DWORD *)(v5 + 65) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v21 = v4[1];
        v16 = (_BYTE *)(v23 + 45);
        a3 = v23 + 45;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v16);
          if ( Int32 )
            return Int32;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + v21 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + v21) )
          {
LABEL_20:
            v13 = v10 + 1;
            v5 = v23;
            *(_DWORD *)(v23 + 1) = v13;
            goto LABEL_43;
          }
          ++v10;
          v16 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v10 < 5 );
        v5 = v23;
LABEL_43:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_44:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Byte_2 = TdrBuf::SkipField(v4, v22 & 0xF);
LABEL_42:
        Int32 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_43;
        return Int32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10191F50
// ============================================================
//----- (10191F50) --------------------------------------------------------
int __thiscall sub_10191F50(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v16 = this;
  *(this + 45) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v12 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_28:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[45] & 1) == 0 )
          v4[45] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_7;
      case 2u:
        if ( (v4[45] & 2) == 0 )
          v4[45] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_7;
      case 3u:
        if ( (v4[45] & 4) == 0 )
          v4[45] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_7;
      case 4u:
        if ( (v4[45] & 8) == 0 )
          v4[45] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v10 = 0;
          v13 = v6[1];
          a3 = (int)(v16 + 3);
          while ( 1 )
          {
            v14 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v14);
            if ( v5 )
              return v5;
            if ( v14 )
            {
              v5 = sub_10191530(a3, v6, v14);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v13 )
              break;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v13) )
            {
              a3 += 20;
              if ( (unsigned int)++v10 < 8 )
                continue;
            }
            v4 = v16;
LABEL_27:
            v7 = v12;
            if ( v6[1] >= v12 )
              goto LABEL_28;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 5u:
        if ( (v4[45] & 0x10) == 0 )
          v4[45] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 172);
        goto LABEL_7;
      case 6u:
        if ( (v4[45] & 0x20) == 0 )
          v4[45] |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 176);
        goto LABEL_7;
      default:
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_7:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_27;
        return v5;
    }
  }
  return result;
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
// Address Name: SUB_10113D40
// ============================================================
//----- (10113D40) --------------------------------------------------------
int __thiscall sub_10113D40(_DWORD *this, size_t Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int Bytes; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  size_t v10; // ebx
  _DWORD *v11; // eax
  int v12; // ebx
  _BYTE *v13; // eax
  size_t v14; // ecx
  int v15; // eax
  _BYTE *v16; // eax
  size_t v17; // ecx
  _BYTE *v18; // eax
  size_t v19; // ecx
  unsigned int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+14h] [ebp-Ch]
  unsigned int v24; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v25; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Bytes = 0;
  v25 = this;
  v24 = 0;
  *(this + 97) = 0;
  v7 = v4[1] + v3;
  v20 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v24);
    if ( result )
      return result;
    switch ( v24 >> 4 )
    {
      case 1u:
        if ( (v5[97] & 1) == 0 )
          v5[97] |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_48;
      case 2u:
        if ( (v5[97] & 2) == 0 )
          v5[97] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x14 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v4, v25 + 1, Size);
        if ( !Bytes )
        {
          v11 = v25;
          *((_BYTE *)v25 + v10 + 4) = 0;
          v5 = v11;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (v5[97] & 4) == 0 )
          v5[97] |= 4u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 24);
        goto LABEL_48;
      case 4u:
        if ( (v5[97] & 8) == 0 )
          v5[97] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v21 = v4[1];
        v13 = v25 + 7;
        a3 = v25 + 7;
        do
        {
          Bytes = TdrBuf::ReadInt32(v4, v13);
          if ( Bytes )
            return Bytes;
          v14 = v4[1];
          if ( v14 > v21 + Size )
            return -34;
          if ( v14 == v21 + Size )
            goto LABEL_26;
          ++v12;
          v13 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
        goto LABEL_49;
      case 5u:
        if ( (v5[97] & 0x10) == 0 )
          v5[97] |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v22 = v4[1];
        v16 = v25 + 37;
        a3 = v25 + 37;
        do
        {
          Bytes = TdrBuf::ReadInt32(v4, v16);
          if ( Bytes )
            return Bytes;
          v17 = v4[1];
          if ( v17 > v22 + Size )
            return -34;
          if ( v17 == v22 + Size )
            goto LABEL_26;
          ++v12;
          v16 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
        goto LABEL_49;
      case 6u:
        if ( (v5[97] & 0x20) == 0 )
          v5[97] |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v12 = 0;
        v23 = v4[1];
        v18 = v25 + 67;
        a3 = v25 + 67;
        do
        {
          Bytes = TdrBuf::ReadInt32(v4, v18);
          if ( Bytes )
            return Bytes;
          v19 = v4[1];
          if ( v19 > v23 + Size )
            return -34;
          if ( v19 == v23 + Size )
          {
LABEL_26:
            v15 = v12 + 1;
            v5 = v25;
            v25[6] = v15;
            goto LABEL_49;
          }
          ++v12;
          v18 = ++a3;
        }
        while ( v12 < 30 );
        v5 = v25;
LABEL_49:
        v7 = v20;
        if ( v4[1] < v20 )
          continue;
LABEL_50:
        if ( v4[1] > v7 )
          return -34;
        return Bytes;
      default:
        Int32 = TdrBuf::SkipField(v4, v24 & 0xF);
LABEL_48:
        Bytes = Int32;
        if ( !Int32 )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101853A0
// ============================================================
//----- (101853A0) --------------------------------------------------------
int __thiscall sub_101853A0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
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
// Address Name: SUB_1018EE90
// ============================================================
//----- (1018EE90) --------------------------------------------------------
int __thiscall sub_1018EE90(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 9) = 0;
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
      if ( v9 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 9) & 2) == 0 )
          *(_DWORD *)(this + 9) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
        goto LABEL_19;
      }
      if ( v9 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 9) & 4) == 0 )
        *(_DWORD *)(this + 9) |= 4u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 8) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_20:
      if ( a2[1] >= v5 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 9) & 1) == 0 )
      *(_DWORD *)(this + 9) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_19:
    v4 = Int32;
    if ( Int32 )
      return v4;
    goto LABEL_20;
  }
LABEL_21:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018E580
// ============================================================
//----- (1018E580) --------------------------------------------------------
int __thiscall sub_1018E580(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v19; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v20; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v20 = this;
  *(this + 66) = 0;
  v19 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_37;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v4[66] & 1) == 0 )
          v4[66] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_35;
      case 2u:
        if ( (v4[66] & 2) == 0 )
          v4[66] |= 2u;
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
          v5 = sub_10115A30(v6, (_BYTE *)v20 + v10 + 4);
          if ( v5 )
            return v5;
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            break;
          if ( ++v10 >= 160 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v12 = v10 + 1;
        v4 = v20;
        *v20 = v12;
        goto LABEL_36;
      case 3u:
        if ( (v4[66] & 4) == 0 )
          v4[66] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 164);
        goto LABEL_35;
      case 4u:
        if ( (v4[66] & 8) == 0 )
          v4[66] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v17 = v6[1];
        a3 = (int)(v20 + 42);
        while ( 1 )
        {
          v18 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v18);
          if ( v5 )
            return v5;
          if ( v18 )
          {
            v5 = sub_1018DAC0(a3, v6, v18);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 += 12;
          if ( ++v13 >= 8 )
          {
            v4 = v20;
            goto LABEL_36;
          }
        }
        v15 = v13 + 1;
        v4 = v20;
        v20[41] = v15;
LABEL_36:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_37:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_35:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_36;
        return v5;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10153650
// ============================================================
//----- (10153650) --------------------------------------------------------
int __thiscall sub_10153650(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 1341) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[1341] & 1) == 0 )
          v4[1341] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[1341] & 2) == 0 )
            v4[1341] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10152C90(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 268;
            if ( ++v10 >= 20 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10157BB0
// ============================================================
//----- (10157BB0) --------------------------------------------------------
int __thiscall sub_10157BB0(int this, int a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte_2; // eax
  unsigned __int8 v10; // bl
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  int v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = (_DWORD *)a2;
  v16 = this;
  *(_DWORD *)(this + 417) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_38;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 417) & 1) == 0 )
          *(_DWORD *)(v4 + 417) |= 1u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4, v6, a2);
        goto LABEL_36;
      case 2u:
        if ( (*(_DWORD *)(v4 + 417) & 2) == 0 )
          *(_DWORD *)(v4 + 417) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4 + 32, v6, a2);
        goto LABEL_36;
      case 3u:
        if ( (*(_DWORD *)(v4 + 417) & 4) == 0 )
          *(_DWORD *)(v4 + 417) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_37;
        Byte_2 = sub_10156E40(v4 + 64, v6, a2);
LABEL_36:
        v5 = Byte_2;
        if ( !Byte_2 )
          goto LABEL_37;
        return v5;
      case 4u:
        if ( (*(_DWORD *)(v4 + 417) & 8) == 0 )
          *(_DWORD *)(v4 + 417) |= 8u;
        Byte_2 = TdrBuf::ReadByte_2(v6, (_BYTE *)(v4 + 96));
        goto LABEL_36;
      case 5u:
        if ( (*(_DWORD *)(v4 + 417) & 0x10) == 0 )
          *(_DWORD *)(v4 + 417) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          v5 = TdrBuf::ReadInt32(v6, &a3);
          if ( v5 )
            return v5;
          if ( a3 )
          {
            v5 = sub_10156E40(32 * v10 + v16 + 97, v6, a3);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > v14 + a2 )
            return -34;
          if ( v11 == v14 + a2 )
            break;
          if ( ++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_37;
          }
        }
        v12 = v16;
        *(_BYTE *)(v16 + 96) = v10 + 1;
        v4 = v12;
LABEL_37:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_38:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Byte_2 = TdrBuf::SkipField(v6, v15 & 0xF);
        goto LABEL_36;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101564C0
// ============================================================
//----- (101564C0) --------------------------------------------------------
int __thiscall sub_101564C0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  unsigned int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 10165) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[10165] & 1) == 0 )
          v4[10165] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10165] & 2) == 0 )
            v4[10165] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10155B00(a3, (int)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 726;
            if ( ++v10 >= 56 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024C170
// ============================================================
//----- (1024C170) --------------------------------------------------------
int __thiscall sub_1024C170(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10229820
// ============================================================
//----- (10229820) --------------------------------------------------------
int __thiscall sub_10229820(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022A070
// ============================================================
//----- (1022A070) --------------------------------------------------------
int __thiscall sub_1022A070(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _BYTE *v10; // ecx
  int v11; // edi
  _DWORD *v12; // eax
  unsigned int v13; // edx
  int v14; // eax
  unsigned int v15; // [esp+10h] [ebp-10h]
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  unsigned int v18; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v18 = 0;
  *(_DWORD *)(this + 128) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_26:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v18);
      if ( result )
        break;
      switch ( v18 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 128) & 1) == 0 )
            *(_DWORD *)(this + 128) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 128) & 2) == 0 )
            *(_DWORD *)(this + 128) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 128) & 4) == 0 )
            *(_DWORD *)(this + 128) |= 4u;
          a3 = 0;
          result = TdrBuf::ReadInt32(v4, &a3);
          if ( result )
            return result;
          if ( !a3 )
            return -37;
          v10 = (_BYTE *)(this + 8);
          v16 = v4[1];
          v11 = 0;
          v12 = a2;
          v17 = this + 8;
          while ( 1 )
          {
            v6 = TdrBuf::ReadInt32(v12, v10);
            if ( v6 )
              return v6;
            v12 = a2;
            v13 = a2[1];
            if ( v13 > a3 + v16 )
              return -34;
            if ( v13 == a3 + v16 )
            {
              v14 = v11 + 1;
              v4 = a2;
              *(_DWORD *)(this + 4) = v14;
              goto LABEL_25;
            }
            ++v11;
            v10 = (_BYTE *)(v17 + 4);
            v17 += 4;
            if ( v11 >= 30 )
            {
              v4 = a2;
              goto LABEL_25;
            }
          }
        default:
          Int32 = TdrBuf::SkipField(v4, v18 & 0xF);
          break;
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_25:
      v7 = v15;
      if ( v4[1] >= v15 )
        goto LABEL_26;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102291D0
// ============================================================
//----- (102291D0) --------------------------------------------------------
int __thiscall sub_102291D0(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101902B0
// ============================================================
//----- (101902B0) --------------------------------------------------------
int __thiscall sub_101902B0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10111100
// ============================================================
//----- (10111100) --------------------------------------------------------
int __thiscall sub_10111100(_DWORD *this, size_t Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Byte; // eax
  char v10; // bl
  size_t v11; // ecx
  _DWORD *v12; // eax
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v16 = this;
  *(this + 183) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_32;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (v4[183] & 1) == 0 )
          v4[183] |= 1u;
        Byte = TdrBuf::ReadByte(v6, v4);
        goto LABEL_30;
      case 2u:
        if ( (v4[183] & 2) == 0 )
          v4[183] |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x14 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (char *)v4 + 1, Size);
        if ( !Bytes )
        {
          *((_BYTE *)v4 + Size + 1) = 0;
          goto LABEL_31;
        }
        return Bytes;
      case 3u:
        if ( (v4[183] & 4) == 0 )
          v4[183] |= 4u;
        Byte = TdrBuf::ReadByte(v6, (_BYTE *)v4 + 21);
        goto LABEL_30;
      case 4u:
        if ( (v4[183] & 8) == 0 )
          v4[183] |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &a3);
          if ( Bytes )
            return Bytes;
          if ( a3 )
          {
            Bytes = sub_101103F0(v6, a3);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          if ( (unsigned __int8)++v10 >= 0xAu )
          {
            v4 = v16;
            goto LABEL_31;
          }
        }
        v12 = v16;
        *((_BYTE *)v16 + 21) = v10 + 1;
        v4 = v12;
LABEL_31:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_32:
        if ( v6[1] > v7 )
          return -34;
        return Bytes;
      default:
        Byte = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_30:
        Bytes = Byte;
        if ( !Byte )
          goto LABEL_31;
        return Bytes;
    }
  }
}
// 101103F0: using guessed type _DWORD __stdcall sub_101103F0(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10167D60
// ============================================================
//----- (10167D60) --------------------------------------------------------
int __thiscall sub_10167D60(int this, _DWORD *Size, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  _DWORD *v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = Size;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 581) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[581] & 1) == 0 )
          *(_DWORD *)(v5 + 581) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 581) & 2) == 0 )
            *(_DWORD *)(v5 + 581) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10167350(&v16[29 * v9 + 1], (size_t)v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = (_DWORD *)v4[1];
            if ( v10 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v10 == (_DWORD *)((char *)Size + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x14u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016A350
// ============================================================
//----- (1016A350) --------------------------------------------------------
int __thiscall sub_1016A350(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 5) = 0;
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
      if ( (*(this + 5) & 1) == 0 )
        *(_DWORD *)(this + 5) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *this = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 5) & 2) == 0 )
        *(_DWORD *)(this + 5) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 1);
      if ( result )
        return result;
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
// Address Name: SUB_10169610
// ============================================================
//----- (10169610) --------------------------------------------------------
int __thiscall sub_10169610(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Byte; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 24) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_79:
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
          if ( (*(_BYTE *)(this + 24) & 1) == 0 )
            *(_DWORD *)(this + 24) |= 1u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 24) & 2) == 0 )
            *(_DWORD *)(this + 24) |= 2u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 1));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 24) & 4) == 0 )
            *(_DWORD *)(this + 24) |= 4u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 2));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 24) & 8) == 0 )
            *(_DWORD *)(this + 24) |= 8u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 3));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 24) & 0x10) == 0 )
            *(_DWORD *)(this + 24) |= 0x10u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 24) & 0x20) == 0 )
            *(_DWORD *)(this + 24) |= 0x20u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 24) & 0x40) == 0 )
            *(_DWORD *)(this + 24) |= 0x40u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 6));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 24) & 0x80) == 0 )
            *(_DWORD *)(this + 24) |= 0x80u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 7));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 24) & 0x100) == 0 )
            *(_DWORD *)(this + 24) |= 0x100u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 8));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 24) & 0x200) == 0 )
            *(_DWORD *)(this + 24) |= 0x200u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 9));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 24) & 0x400) == 0 )
            *(_DWORD *)(this + 24) |= 0x400u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 10));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 24) & 0x800) == 0 )
            *(_DWORD *)(this + 24) |= 0x800u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 11));
          break;
        case 0xDu:
          if ( (*(_DWORD *)(this + 24) & 0x1000) == 0 )
            *(_DWORD *)(this + 24) |= 0x1000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 12));
          break;
        case 0xEu:
          if ( (*(_DWORD *)(this + 24) & 0x2000) == 0 )
            *(_DWORD *)(this + 24) |= 0x2000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 13));
          break;
        case 0xFu:
          if ( (*(_DWORD *)(this + 24) & 0x4000) == 0 )
            *(_DWORD *)(this + 24) |= 0x4000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 14));
          break;
        case 0x10u:
          if ( (*(_DWORD *)(this + 24) & 0x8000) == 0 )
            *(_DWORD *)(this + 24) |= 0x8000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 15));
          break;
        case 0x11u:
          if ( (*(_DWORD *)(this + 24) & 0x10000) == 0 )
            *(_DWORD *)(this + 24) |= 0x10000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 16));
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 24) & 0x20000) == 0 )
            *(_DWORD *)(this + 24) |= 0x20000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 17));
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 24) & 0x40000) == 0 )
            *(_DWORD *)(this + 24) |= 0x40000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 18));
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 24) & 0x80000) == 0 )
            *(_DWORD *)(this + 24) |= 0x80000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 19));
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 24) & 0x100000) == 0 )
            *(_DWORD *)(this + 24) |= 0x100000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 20));
          break;
        case 0x16u:
          if ( (*(_DWORD *)(this + 24) & 0x200000) == 0 )
            *(_DWORD *)(this + 24) |= 0x200000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 21));
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 24) & 0x400000) == 0 )
            *(_DWORD *)(this + 24) |= 0x400000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 22));
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 24) & 0x800000) == 0 )
            *(_DWORD *)(this + 24) |= 0x800000u;
          Byte = TdrBuf::ReadByte(a2, (_BYTE *)(this + 23));
          break;
        default:
          Byte = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Byte;
      if ( Byte )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_79;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10168550
// ============================================================
//----- (10168550) --------------------------------------------------------
int __thiscall sub_10168550(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
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
// Address Name: SUB_10192230
// ============================================================
//----- (10192230) --------------------------------------------------------
int __thiscall sub_10192230(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ebx
  _DWORD *i; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[iReSearchCount]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iRrefreshCount]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iVipRefreshCount]", "%d", *(this + 2));
      if ( !result )
      {
        v6 = 0;
        for ( i = this + 3; ; i += 5 )
        {
          if ( !"[vItemPoolList]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[vItemPoolList]", v6, a4);
          if ( result )
            break;
          result = a3 >= 0 ? sub_10191700(i, a2, a3 + 1, a4) : sub_10191700(i, a2, a3, a4);
          if ( result )
            break;
          if ( (unsigned int)++v6 >= 8 )
          {
            result = print_field(a2, a3, a4, "[iBoxId]", "%d", *(this + 43));
            if ( !result )
              return print_field(a2, a3, a4, "[iLastClockRefreshTime]", "%d", *(this + 44));
            return result;
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017A3D0
// ============================================================
//----- (1017A3D0) --------------------------------------------------------
int __thiscall sub_1017A3D0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  _DWORD *i; // ebx
  unsigned __int8 *v19; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v20; // [esp+Ch] [ebp-4h]

  v4 = a2;
  result = print_field(a2, a3, a4, "[type]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
    {
      v8 = *(_DWORD *)(this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 5 )
        return -7;
      result = sub_1024A3B0(a2, a3, v7, "[arg1]", v8);
      if ( !result )
      {
        v9 = 0;
        if ( *(int *)(this + 1) <= 0 )
        {
LABEL_12:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v12 = *(_DWORD *)(this + 1);
          if ( v12 < 0 )
            return -6;
          if ( v12 <= 5 )
          {
            result = sub_1024A3B0(a2, a3, v11, "[arg2]", v12);
            if ( result )
              return result;
            v13 = 0;
            if ( *(int *)(this + 1) > 0 )
            {
              v14 = this + 25;
              v20 = this + 25;
              do
              {
                result = Printf(a2, " %d", *v14);
                if ( result )
                  return result;
                ++v13;
                v14 = v20 + 4;
                v20 += 4;
              }
              while ( v13 < *(_DWORD *)(this + 1) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v16 = *(_DWORD *)(this + 1);
            if ( v16 < 0 )
              return -6;
            if ( v16 <= 5 )
            {
              result = sub_1024A3B0(a2, a3, v15, "[arg3]", v16);
              if ( !result )
              {
                v17 = 0;
                if ( *(int *)(this + 1) <= 0 )
                {
                  return TdrBuf::WriteChar(v4, a4);
                }
                else
                {
                  for ( i = this + 45; ; ++i )
                  {
                    result = Printf(a2, " %d", *i);
                    if ( result )
                      break;
                    if ( ++v17 >= *(_DWORD *)(this + 1) )
                    {
                      v4 = a2;
                      return TdrBuf::WriteChar(v4, a4);
                    }
                  }
                }
              }
              return result;
            }
          }
          return -7;
        }
        v10 = this + 5;
        v19 = this + 5;
        while ( 1 )
        {
          result = Printf(a2, " %d", *v10);
          if ( result )
            break;
          ++v9;
          v10 = v19 + 4;
          v19 += 4;
          if ( v9 >= *(_DWORD *)(this + 1) )
            goto LABEL_12;
        }
      }
    }
  }
  return result;
}
// 1017A45A: variable 'v7' is possibly undefined
// 1017A4D2: variable 'v11' is possibly undefined
// 1017A547: variable 'v15' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10189710
// ============================================================
//----- (10189710) --------------------------------------------------------
int __thiscall sub_10189710(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  result = print_field(a2, a3, a4, "[skillGroup]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[leftEditCnt]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[skillCnt]", "0x%02x", *((unsigned __int8 *)this + 8));
      if ( !result )
      {
        v7 = *((_BYTE *)this + 8);
        if ( v7 > 0xB4u )
          return -7;
        result = sub_1024A3B0(a2, a3, v6, "[skillID]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *((_BYTE *)this + 8) )
          {
            while ( 1 )
            {
              result = Printf(a2, " %d", *(_DWORD *)((char *)this + 4 * v8 + 9));
              if ( result )
                break;
              if ( ++v8 >= *((_BYTE *)this + 8) )
                goto LABEL_10;
            }
          }
          else
          {
LABEL_10:
            result = TdrBuf::WriteChar(a2, a4);
            if ( !result )
            {
              v10 = *((_BYTE *)this + 8);
              if ( v10 > 0xB4u )
                return -7;
              result = sub_1024A3B0(a2, a3, v9, "[actFlag]", v10);
              if ( !result )
              {
                v11 = 0;
                if ( *((_BYTE *)this + 8) )
                {
                  while ( 1 )
                  {
                    result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v11 + 729));
                    if ( result )
                      break;
                    if ( ++v11 >= *((_BYTE *)this + 8) )
                      return TdrBuf::WriteChar(a2, a4);
                  }
                }
                else
                {
                  return TdrBuf::WriteChar(a2, a4);
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
// 101897AA: variable 'v6' is possibly undefined
// 10189807: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10114140
// ============================================================
//----- (10114140) --------------------------------------------------------
int __thiscall sub_10114140(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  _DWORD *v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edi
  _DWORD *v18; // eax
  int v19; // [esp+14h] [ebp+8h]
  int v20; // [esp+14h] [ebp+8h]
  int i; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[supplyPlanId]", "%d", *this);
  if ( !result )
  {
    result = sub_1024A410((int)a2, a4, (char)"[name]", (_BYTE)this + 4);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[supplyCnt]", "%d", *(this + 6));
      if ( !result )
      {
        v8 = *(this + 6);
        if ( v8 < 0 )
          return -6;
        if ( v8 > 30 )
          return -7;
        result = sub_1024A3B0(a2, a3, v7, "[itemType]", v8);
        if ( !result )
        {
          v9 = 0;
          if ( (int)*(this + 6) <= 0 )
          {
LABEL_13:
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v12 = *(this + 6);
            if ( v12 < 0 )
              return -6;
            if ( v12 <= 30 )
            {
              result = sub_1024A3B0(a2, a3, v11, "[itemCount]", v12);
              if ( result )
                return result;
              v13 = 0;
              if ( (int)*(this + 6) > 0 )
              {
                v14 = this + 37;
                v20 = (int)(this + 37);
                do
                {
                  result = Printf(a2, " %d", *v14);
                  if ( result )
                    return result;
                  ++v13;
                  v14 = (_DWORD *)(v20 + 4);
                  v20 += 4;
                }
                while ( v13 < *(this + 6) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              v16 = *(this + 6);
              if ( v16 < 0 )
                return -6;
              if ( v16 <= 30 )
              {
                result = sub_1024A3B0(a2, a3, v15, "[posGrid]", v16);
                if ( !result )
                {
                  v17 = 0;
                  if ( (int)*(this + 6) <= 0 )
                  {
                    return TdrBuf::WriteChar(a2, a4);
                  }
                  else
                  {
                    v18 = this + 67;
                    for ( i = (int)(this + 67); ; i += 4 )
                    {
                      result = Printf(a2, " %d", *v18);
                      if ( result )
                        break;
                      ++v17;
                      v18 = (_DWORD *)(i + 4);
                      if ( v17 >= *(this + 6) )
                        return TdrBuf::WriteChar(a2, a4);
                    }
                  }
                }
                return result;
              }
            }
            return -7;
          }
          v10 = this + 7;
          v19 = (int)(this + 7);
          while ( 1 )
          {
            result = Printf(a2, " %d", *v10);
            if ( result )
              break;
            ++v9;
            v10 = (_DWORD *)(v19 + 4);
            v19 += 4;
            if ( v9 >= *(this + 6) )
              goto LABEL_13;
          }
        }
      }
    }
  }
  return result;
}
// 101141E2: variable 'v7' is possibly undefined
// 10114257: variable 'v11' is possibly undefined
// 101142CE: variable 'v15' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017D010
// ============================================================
//----- (1017D010) --------------------------------------------------------
int __thiscall sub_1017D010(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v5; // eax
  int v6; // esi
  _DWORD *i; // ebx

  result = print_field(a2, a3, a4, "[type]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
    {
      v5 = *(_DWORD *)(this + 1);
      if ( v5 >= 0 )
      {
        if ( v5 <= 5 )
        {
          v6 = 0;
          if ( v5 <= 0 )
          {
            return 0;
          }
          else
          {
            for ( i = this + 5; ; i += 4 )
            {
              if ( !"[trace]" )
                _wassert(
                  L"NULL != variable",
                  L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                  0x43u);
              result = sub_1024A140(a3);
              if ( result )
                break;
              result = Printf(a2, "%s[%u]%c", "[trace]", v6, a4);
              if ( result )
                break;
              result = a3 >= 0 ? sub_1017C560(i, a2, a3 + 1, a4) : sub_1017C560(i, a2, a3, a4);
              if ( result )
                break;
              if ( ++v6 >= *(_DWORD *)(this + 1) )
                return 0;
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A480
// ============================================================
//----- (1024A480) --------------------------------------------------------
int __fastcall sub_1024A480(_DWORD *a1, int a2, char a3, const char *ArgList, int a5, const char *a6)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xCBu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s[%u]: ", ArgList, a5);
    if ( !result )
    {
      result = Printf(a1, "%s", a6);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
    }
  }
  return result;
}



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
// Address Name: SUB_1018E890
// ============================================================
//----- (1018E890) --------------------------------------------------------
int __thiscall sub_1018E890(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  int v10; // esi
  _DWORD *i; // edi
  int v12; // eax

  result = print_field(a2, a3, a4, "[finishActionBitTagCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 160 )
      return -7;
    result = sub_1024A3B0(a2, a3, v6, "[finishActionBitTag]", v7);
    if ( !result )
    {
      v8 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[actionStepInfoCount]", "%d", *(this + 41));
          if ( !result )
          {
            v9 = *(this + 41);
            if ( v9 < 0 )
              return -6;
            if ( v9 > 8 )
              return -7;
            v10 = 0;
            if ( v9 <= 0 )
            {
              return 0;
            }
            else
            {
              for ( i = this + 42; ; i += 3 )
              {
                result = sub_1024A230(a2, a3, a4, "[actionStepInfos]", v10);
                if ( result )
                  break;
                v12 = a3;
                if ( a3 >= 0 )
                  v12 = a3 + 1;
                result = sub_1018DC60(i, a2, v12, a4);
                if ( result )
                  break;
                if ( ++v10 >= *(this + 41) )
                  return 0;
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((char *)this + v8 + 4));
          if ( result )
            break;
          if ( ++v8 >= *this )
            goto LABEL_10;
        }
      }
    }
  }
  return result;
}
// 1018E8F1: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018F060
// ============================================================
//----- (1018F060) --------------------------------------------------------
int __thiscall sub_1018F060(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[chapterId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[getRewardCount]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[isNotNew]", "0x%02x", *((char *)this + 8));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10153890
// ============================================================
//----- (10153890) --------------------------------------------------------
int __thiscall sub_10153890(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[procsCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 20 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 67 )
          {
            if ( !"[procs]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[procs]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10152F10(i, a2, a3 + 1, a4) : sub_10152F10(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10157F00
// ============================================================
//----- (10157F00) --------------------------------------------------------
int __thiscall sub_10157F00(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v7; // ecx
  _DWORD *v8; // ecx
  unsigned __int8 v9; // al
  unsigned __int8 v10; // cl
  int v11; // ebx
  _DWORD *v12; // ecx
  unsigned __int8 v14; // [esp+1Fh] [ebp+Fh]

  if ( !"[daily]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[daily]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_10157090((_DWORD *)this, a2, a3 + 1, a4) : sub_10157090((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[weekly]");
        if ( !result )
        {
          v7 = (_DWORD *)(this + 32);
          result = a3 >= 0 ? sub_10157090(v7, a2, a3 + 1, a4) : sub_10157090(v7, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[monthly]");
            if ( !result )
            {
              v8 = (_DWORD *)(this + 64);
              result = a3 >= 0 ? sub_10157090(v8, a2, a3 + 1, a4) : sub_10157090(v8, a2, a3, a4);
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[count]", "0x%02x", *(unsigned __int8 *)(this + 96));
                if ( !result )
                {
                  v9 = *(_BYTE *)(this + 96);
                  if ( v9 <= 0xAu )
                  {
                    v10 = 0;
                    v14 = 0;
                    if ( v9 )
                    {
                      while ( 1 )
                      {
                        v11 = v10;
                        result = sub_1024A230(a2, a3, a4, "[selfDefs]", v10);
                        if ( result )
                          break;
                        v12 = (_DWORD *)(32 * v11 + this + 97);
                        result = a3 >= 0 ? sub_10157090(v12, a2, a3 + 1, a4) : sub_10157090(v12, a2, a3, a4);
                        if ( result )
                          break;
                        v10 = v14 + 1;
                        v14 = v10;
                        if ( v10 >= *(_BYTE *)(this + 96) )
                          return 0;
                      }
                    }
                    else
                    {
                      return 0;
                    }
                  }
                  else
                  {
                    return -7;
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
// Address Name: SUB_10156700
// ============================================================
//----- (10156700) --------------------------------------------------------
int __thiscall sub_10156700(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 56 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i = (_DWORD *)((char *)i + 726) )
          {
            if ( !"[data]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[data]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10155D40(i, a2, a3 + 1, a4) : sub_10155D40(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10167FE0
// ============================================================
//----- (10167FE0) --------------------------------------------------------
int __thiscall sub_10167FE0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v10; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[nNumTabs]", "0x%02x", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this <= 0x14u )
    {
      v8 = 0;
      if ( v7 )
      {
        while ( 1 )
        {
          if ( !"[astTabs]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[astTabs]", v8, a4);
          if ( result )
            break;
          v10 = (int)(this + 29 * v8 + 1);
          if ( a3 >= 0 )
          {
            result = sub_1024A410(a2, a3 + 1, a4, "[strName]", (const char *)v10);
            if ( result )
              return result;
            result = print_field(a2, a3 + 1, a4, "[nChannelFlags]", "%u", *(_DWORD *)(v10 + 21));
          }
          else
          {
            result = sub_1024A410(a2, a3, a4, "[strName]", (const char *)v10);
            if ( result )
              return result;
            result = print_field(a2, a3, a4, "[nChannelFlags]", "%u", *(_DWORD *)(v10 + 21));
          }
          if ( result )
            break;
          if ( ++v8 >= *this )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016A540
// ============================================================
//----- (1016A540) --------------------------------------------------------
int __thiscall sub_1016A540(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[tipsCheck]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101686F0
// ============================================================
//----- (101686F0) --------------------------------------------------------
int __thiscall sub_101686F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nFirstSettingData]", "%u", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[nSecondSettingData]", "%u", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10169B10
// ============================================================
//----- (10169B10) --------------------------------------------------------
int __thiscall sub_10169B10(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nBUTTON_UP]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[nBUTTON_LEFT]", "0x%02x", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[nBUTTON_DOWN]", "0x%02x", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[nBUTTON_RIGHT]", "0x%02x", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[nSTICK_LEFT_LEFT]", "0x%02x", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[nSTICK_LEFT_RIGHT]", "0x%02x", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[nSTICK_LEFT_UP]", "0x%02x", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[nSTICK_LEFT_DOWN]", "0x%02x", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[nSTICK_RIGHT_LEFT]", "0x%02x", *(this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[nSTICK_RIGHT_RIGHT]", "0x%02x", *(this + 9));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[nSTICK_RIGHT_UP]", "0x%02x", *(this + 10));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[nSTICK_RIGHT_DOWN]", "0x%02x", *(this + 11));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[nBUTTON_L2]", "0x%02x", *(this + 12));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[nBUTTON_R2]", "0x%02x", *(this + 13));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[nBUTTON_L1]", "0x%02x", *(this + 14));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[nBUTTON_R1]", "0x%02x", *(this + 15));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[nBUTTON_TRIANGLE]", "0x%02x", *(this + 16));
                                  if ( !result )
                                  {
                                    result = print_field(a2, a3, a4, "[nBUTTON_CIRCLE]", "0x%02x", *(this + 17));
                                    if ( !result )
                                    {
                                      result = print_field(a2, a3, a4, "[nBUTTON_CROSS]", "0x%02x", *(this + 18));
                                      if ( !result )
                                      {
                                        result = print_field(a2, a3, a4, "[nBUTTON_SQUARE]", "0x%02x", *(this + 19));
                                        if ( !result )
                                        {
                                          result = print_field(a2, a3, a4, "[nBUTTON_SELECT]", "0x%02x", *(this + 20));
                                          if ( !result )
                                          {
                                            result = print_field(a2, a3, a4, "[nBUTTON_START]", "0x%02x", *(this + 21));
                                            if ( !result )
                                            {
                                              result = print_field(a2, a3, a4, "[nBUTTON_L3]", "0x%02x", *(this + 22));
                                              if ( !result )
                                                return print_field(a2, a3, a4, "[nBUTTON_R3]", "0x%02x", *(this + 23));
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
// Address Name: SUB_10210E70
// ============================================================
//----- (10210E70) --------------------------------------------------------
int __thiscall sub_10210E70(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[group]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[saledCount]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 3));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1020F2F0
// ============================================================
//----- (1020F2F0) --------------------------------------------------------
int __thiscall sub_1020F2F0(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // bl
  int v11; // ecx
  unsigned __int8 v12; // bl
  int v13; // edx
  unsigned __int8 v14; // bl
  int v15; // ecx
  int v16; // [esp+18h] [ebp+8h]

  result = print_field(a2, a3, a4, "[lastResetTm]", "%I64u", *(_QWORD *)this);
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[limitDataCnt]", "0x%02x", (unsigned __int8)*(this + 8));
  if ( result )
    return result;
  result = sub_1024A3B0(a2, a3, v7, "[shopType]", (unsigned __int8)*(this + 8));
  if ( result )
    return result;
  v8 = 0;
  if ( *(this + 8) )
  {
    while ( 1 )
    {
      result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v8 + 9));
      if ( result )
        break;
      if ( ++v8 >= *(this + 8) )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    result = TdrBuf::WriteChar(a2, a4);
    if ( result )
      return result;
    result = sub_1024A3B0(a2, a3, v9, "[shopID]", (unsigned __int8)*(this + 8));
    if ( result )
      return result;
    v10 = 0;
    if ( *(this + 8) )
    {
      while ( 1 )
      {
        result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v10 + 265));
        if ( result )
          break;
        if ( ++v10 >= *(this + 8) )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      result = TdrBuf::WriteChar(a2, a4);
      if ( result )
        return result;
      result = sub_1024A3B0(a2, a3, v11, "[saleID]", (unsigned __int8)*(this + 8));
      if ( result )
        return result;
      v12 = 0;
      if ( !*(this + 8) )
      {
LABEL_17:
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0xC4u);
        v13 = a2[1];
        if ( (unsigned int)(a2[2] - v13) >= 2 )
        {
          *(_BYTE *)(v13 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          v16 = (unsigned __int8)*(this + 8);
          if ( !"[buyCount]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x9Du);
          result = sub_1024A140(a3);
          if ( result )
            return result;
          result = Printf(a2, "%s[0 : %I64i]:", "[buyCount]", (unsigned int)v16 - 1LL);
          if ( result )
            return result;
          v14 = 0;
          if ( *(this + 8) )
          {
            do
            {
              result = Printf(a2, " %d", *(unsigned __int16 *)(this + 2 * v14 + 2313));
              if ( result )
                return result;
            }
            while ( ++v14 < *(this + 8) );
          }
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v15 = a2[1];
          if ( (unsigned int)(a2[2] - v15) >= 2 )
          {
            *(_BYTE *)(v15 + *a2) = a4;
            *(_BYTE *)(++a2[1] + *a2) = 0;
            return 0;
          }
        }
        return -1;
      }
      while ( 1 )
      {
        result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v12 + 1289));
        if ( result )
          break;
        if ( ++v12 >= *(this + 8) )
          goto LABEL_17;
      }
    }
  }
  return result;
}
// 1020F358: variable 'v7' is possibly undefined
// 1020F3BA: variable 'v9' is possibly undefined
// 1020F41C: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102106F0
// ============================================================
//----- (102106F0) --------------------------------------------------------
int __thiscall sub_102106F0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // si

  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lib]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[commodityCount]", "%d", *(this + 4));
      if ( !result )
      {
        v6 = *(this + 4);
        if ( v6 >= 0 )
        {
          if ( v6 <= 64 )
          {
            v7 = 0;
            if ( v6 <= 0 )
            {
              return print_field(a2, a3, a4, "[resetTimes]", "%d", *(_DWORD *)(this + 261));
            }
            else
            {
              while ( 1 )
              {
                result = sub_1024A230(a2, a3, a4, "[commodity]", v7);
                if ( result )
                  break;
                result = a3 >= 0
                       ? sub_1020FC00(this + 4 * v7 + 5, a2, a3 + 1, a4)
                       : sub_1020FC00(this + 4 * v7 + 5, a2, a3, a4);
                if ( result )
                  break;
                if ( ++v7 >= *(this + 4) )
                  return print_field(a2, a3, a4, "[resetTimes]", "%d", *(_DWORD *)(this + 261));
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024C2F0
// ============================================================
//----- (1024C2F0) --------------------------------------------------------
int __thiscall sub_1024C2F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[onlineTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[consecDays]", "%u", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10190480
// ============================================================
//----- (10190480) --------------------------------------------------------
int __thiscall sub_10190480(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iPosition]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iItemId]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iItemNum]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[iQuality]", "%d", *(this + 3));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10185540
// ============================================================
//----- (10185540) --------------------------------------------------------
int __thiscall sub_10185540(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[itemID]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[enchanseCount]", "%u", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101113F0
// ============================================================
//----- (101113F0) --------------------------------------------------------
int __thiscall sub_101113F0(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  unsigned __int8 *v8; // ecx

  result = print_field(a2, a3, a4, "[planId]", "0x%02x", *this);
  if ( !result )
  {
    result = sub_1024A410((int)a2, a4, (char)"[name]", (_BYTE)this + 1);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[equipCnt]", "0x%02x", *(this + 21));
      if ( !result )
      {
        v6 = *(this + 21);
        if ( v6 <= 0xAu )
        {
          v7 = 0;
          if ( v6 )
          {
            while ( 1 )
            {
              if ( !"[equipList]" )
                _wassert(
                  L"NULL != variable",
                  L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                  0x43u);
              result = sub_1024A140(a3);
              if ( result )
                break;
              result = Printf(a2, "%s[%u]%c", "[equipList]", v7, (char)a4);
              if ( result )
                break;
              v8 = this + 71 * v7 + 22;
              result = a3 >= 0 ? sub_101106B0(v8, a2, a3 + 1, a4) : sub_101106B0(v8, a2, a3, a4);
              if ( result )
                break;
              if ( ++v7 >= *(this + 21) )
                return 0;
            }
          }
          else
          {
            return 0;
          }
        }
        else
        {
          return -7;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10231270
// ============================================================
//----- (10231270) --------------------------------------------------------
int __thiscall sub_10231270(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  __int16 *v5; // ecx
  char *v6; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[relicPoint]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_structure((int)a2, a3, a4, (int)"[relicPrize]");
      if ( !result )
      {
        v5 = (__int16 *)(this + 2);
        result = a3 >= 0 ? sub_1022D470(v5, a2, a3 + 1, a4) : sub_1022D470(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[chess]");
          if ( !result )
          {
            v6 = (char *)this + 15;
            if ( a3 >= 0 )
              result = sub_102304E0(v6, a2, a3 + 1, a4);
            else
              result = sub_102304E0(v6, a2, a3, a4);
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[activity]", "%d", *(this + 126));
              if ( !result )
                return print_field(a2, a3, a4, "[refreshTime]", "%u", *(this + 127));
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
// Address Name: SUB_1022A2C0
// ============================================================
//----- (1022A2C0) --------------------------------------------------------
int __thiscall sub_1022A2C0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[groupId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[preferNum]", "%d", *(this + 1));
    if ( !result )
    {
      v7 = *(this + 1);
      if ( v7 >= 0 )
      {
        if ( v7 <= 30 )
        {
          result = sub_1024A3B0(a2, a3, v6, "[preferIds]", v7);
          if ( !result )
          {
            v8 = 0;
            if ( (int)*(this + 1) <= 0 )
            {
              return TdrBuf::WriteChar(a2, a4);
            }
            else
            {
              for ( i = this + 2; ; ++i )
              {
                result = Printf(a2, " %d", *i);
                if ( result )
                  break;
                if ( ++v8 >= *(this + 1) )
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
  }
  return result;
}
// 1022A33E: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10229350
// ============================================================
//----- (10229350) --------------------------------------------------------
int __thiscall sub_10229350(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nNpcAtdId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[nNpcAtdValue]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[nNpcAtdStage]", "%d", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102299A0
// ============================================================
//----- (102299A0) --------------------------------------------------------
int __thiscall sub_102299A0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[nNpcOrgId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[nNpcOrgValue]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[nNpcOrgStage]", "%d", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10191430
// ============================================================
//----- (10191430) --------------------------------------------------------
int __thiscall sub_10191430(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
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
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
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
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10167210
// ============================================================
//----- (10167210) --------------------------------------------------------
int __thiscall sub_10167210(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 25) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 25) & 1) == 0 )
        *(_DWORD *)(this + 25) |= 1u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x15 )
        return -3;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9) = 0;
      v6 = a3;
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 25) & 2) == 0 )
        *(_DWORD *)(this + 25) |= 2u;
      result = TdrBuf::ReadVarUInt(v4, this + 21);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10110200
// ============================================================
//----- (10110200) --------------------------------------------------------
int __thiscall sub_10110200(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // eax
  int Byte; // eax
  int v11; // ebx
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 67) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_36:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 67) & 1) == 0 )
          *(_DWORD *)(v4 + 67) |= 1u;
        v5 = TdrBuf::ReadVarULong(v4);
        if ( v5 )
          return v5;
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v4 + 67) & 2) == 0 )
          *(_DWORD *)(v4 + 67) |= 2u;
        v9 = v4 + 8;
        goto LABEL_11;
      case 3u:
        if ( (*(_DWORD *)(v4 + 67) & 4) == 0 )
          *(_DWORD *)(v4 + 67) |= 4u;
        v9 = v4 + 12;
LABEL_11:
        Byte = TdrBuf::ReadVarInt(v9);
        goto LABEL_12;
      case 4u:
        if ( (*(_DWORD *)(v4 + 67) & 8) == 0 )
          *(_DWORD *)(v4 + 67) |= 8u;
        Byte = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 16));
        goto LABEL_12;
      case 5u:
        if ( (*(_DWORD *)(v4 + 67) & 0x10) == 0 )
          *(_DWORD *)(v4 + 67) |= 0x10u;
        Byte = TdrBuf::ReadVarUShort(v4 + 17);
        goto LABEL_12;
      case 6u:
        if ( (*(_DWORD *)(v4 + 67) & 0x20) == 0 )
          *(_DWORD *)(v4 + 67) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v11 = 0;
          v14 = v6[1];
          a3 = v17 + 19;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1010F9B0(v6, v15);
              if ( v5 )
                return v5;
            }
            v12 = v6[1];
            if ( v12 > (unsigned int)a2 + v14 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + v14) )
            {
              a3 += 16;
              if ( (unsigned int)++v11 < 3 )
                continue;
            }
            v4 = v17;
LABEL_35:
            v7 = v13;
            if ( v6[1] >= v13 )
              goto LABEL_36;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      default:
        Byte = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_12:
        v5 = Byte;
        if ( !Byte )
          goto LABEL_35;
        return v5;
    }
  }
  return result;
}
// 1010CB00: using guessed type _DWORD __stdcall sub_1010CB00(_DWORD);
// 1010CBD0: using guessed type _DWORD __stdcall sub_1010CBD0(_DWORD);
// 1010CD70: using guessed type _DWORD __stdcall sub_1010CD70(_DWORD);
// 1010F9B0: using guessed type _DWORD __stdcall sub_1010F9B0(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1020F920
// ============================================================
//----- (1020F920) --------------------------------------------------------
int __thiscall sub_1020F920(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 4) = 0;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 4) & 2) == 0 )
          *(_DWORD *)(this + 4) |= 2u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 2));
      }
      else
      {
        VarShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarShort;
      if ( VarShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10152AE0
// ============================================================
//----- (10152AE0) --------------------------------------------------------
int __thiscall sub_10152AE0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(this + 66) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_28:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 66) & 1) == 0 )
            *(this + 66) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          break;
        case 2u:
          if ( (*(this + 66) & 2) == 0 )
            *(this + 66) |= 2u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 1);
          break;
        case 3u:
          if ( (*(this + 66) & 4) == 0 )
            *(this + 66) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *((_BYTE *)this + v11 + 8) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *(this + 1) = v11 + 1;
                  goto LABEL_27;
                }
                if ( ++v11 >= 256 )
                {
                  v6 = a3;
                  goto LABEL_27;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        default:
          VarInt = TdrBuf::SkipField(v4, v16 & 0xF);
          break;
      }
      v6 = VarInt;
      if ( VarInt )
        return v6;
LABEL_27:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10156CC0
// ============================================================
//----- (10156CC0) --------------------------------------------------------
int __thiscall sub_10156CC0(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 7) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 7) & 1) == 0 )
            *(this + 7) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 7) & 2) == 0 )
            *(this + 7) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 7) & 4) == 0 )
            *(this + 7) |= 4u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 7) & 8) == 0 )
            *(this + 7) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 7) & 0x10) == 0 )
            *(this + 7) |= 0x10u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 7) & 0x20) == 0 )
            *(this + 7) |= 0x20u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 7) & 0x40) == 0 )
            *(this + 7) |= 0x40u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 6);
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
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155990
// ============================================================
//----- (10155990) --------------------------------------------------------
int __thiscall sub_10155990(int this, int a2, unsigned int a3)
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
  *(_DWORD *)(this + 722) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 722) & 1) == 0 )
            *(_DWORD *)(this + 722) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 722) & 2) == 0 )
            *(_DWORD *)(this + 722) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 4));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 722) & 4) == 0 )
            *(_DWORD *)(this + 722) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_22;
          VarUInt = sub_10155090((char *)(this + 8), v4, a2);
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 722) & 8) == 0 )
            *(_DWORD *)(this + 722) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_22;
          VarUInt = sub_101546C0(this + 77, v4, a2);
          break;
        default:
          VarUInt = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = VarUInt;
      if ( VarUInt )
        return v6;
LABEL_22:
      v7 = a3;
      if ( v4[1] >= a3 )
        goto LABEL_23;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022D150
// ============================================================
//----- (1022D150) --------------------------------------------------------
int __thiscall sub_1022D150(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1022FA50
// ============================================================
//----- (1022FA50) --------------------------------------------------------
int __thiscall sub_1022FA50(int this, char *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  char *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  int *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  unsigned int v21; // [esp+18h] [ebp-8h] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(_DWORD *)(this + 485) = 0;
  v21 = 0;
  v7 = *((_DWORD *)v6 + 1) + v3;
  v18 = v7;
  if ( *((_DWORD *)v6 + 1) >= v7 )
    goto LABEL_76;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 485) & 1) == 0 )
          *(_DWORD *)(v4 + 485) |= 1u;
        VarInt = sub_10115A30(v6, (_BYTE *)v4);
        goto LABEL_74;
      case 2u:
        if ( (*(_DWORD *)(v4 + 485) & 2) == 0 )
          *(_DWORD *)(v4 + 485) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022C890(v4 + 1, v6, a2);
        goto LABEL_74;
      case 3u:
        if ( (*(_DWORD *)(v4 + 485) & 4) == 0 )
          *(_DWORD *)(v4 + 485) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022D150(v4 + 156, v6, (int)a2);
        goto LABEL_74;
      case 4u:
        if ( (*(_DWORD *)(v4 + 485) & 8) == 0 )
          *(_DWORD *)(v4 + 485) |= 8u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022DA00(v4 + 163, v6, (int)a2);
        goto LABEL_74;
      case 5u:
        if ( (*(_DWORD *)(v4 + 485) & 0x10) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 245));
        goto LABEL_74;
      case 6u:
        if ( (*(_DWORD *)(v4 + 485) & 0x20) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 249));
        goto LABEL_74;
      case 7u:
        if ( (*(_DWORD *)(v4 + 485) & 0x40) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 253));
        goto LABEL_74;
      case 8u:
        if ( (*(_DWORD *)(v4 + 485) & 0x80) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x80u;
        VarInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 257));
        goto LABEL_74;
      case 9u:
        if ( (*(_DWORD *)(v4 + 485) & 0x100) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x100u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 261));
        goto LABEL_74;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 485) & 0x200) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = *((_DWORD *)v6 + 1);
        v11 = (int *)(v22 + 265);
        a3 = v22 + 265;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = *((_DWORD *)v6 + 1);
          if ( v12 > (unsigned int)&a2[v19] )
            return -34;
          if ( (char *)v12 == &a2[v19] )
            break;
          ++v10;
          v11 = (int *)(a3 + 4);
          a3 += 4;
          if ( v10 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 261) = v13;
        goto LABEL_75;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 485) & 0x400) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x400u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 305));
        goto LABEL_74;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 485) & 0x800) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = *((_DWORD *)v6 + 1);
        v15 = (int *)(v22 + 309);
        a3 = v22 + 309;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = *((_DWORD *)v6 + 1);
          if ( v16 > (unsigned int)&a2[v20] )
            return -34;
          if ( (char *)v16 == &a2[v20] )
            break;
          ++v14;
          v15 = (int *)(a3 + 4);
          a3 += 4;
          if ( v14 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 305) = v17;
LABEL_75:
        v7 = v18;
        if ( *((_DWORD *)v6 + 1) < v18 )
          continue;
LABEL_76:
        if ( *((_DWORD *)v6 + 1) > v7 )
          return -34;
        return v5;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 485) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x1000u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        VarInt = sub_1022EA10((int *)(v4 + 349), v6, (int *)a2);
LABEL_74:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_75;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 485) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x2000u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 477));
        goto LABEL_74;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 485) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x4000u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(v4 + 481));
        goto LABEL_74;
      default:
        VarInt = TdrBuf::SkipField(v6, v21 & 0xF);
        goto LABEL_74;
    }
  }
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
// Address Name: SUB_1017C330
// ============================================================
//----- (1017C330) --------------------------------------------------------
int __thiscall sub_1017C330(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
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
// Address Name: SUB_1018DA20
// ============================================================
//----- (1018DA20) --------------------------------------------------------
int __thiscall sub_1018DA20(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022D240
// ============================================================
//----- (1022D240) --------------------------------------------------------
int __thiscall sub_1022D240(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1022FF30
// ============================================================
//----- (1022FF30) --------------------------------------------------------
int __thiscall sub_1022FF30(int this, char *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  char *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _BYTE *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  unsigned int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-Ch]
  unsigned int v21; // [esp+18h] [ebp-8h] BYREF
  int v22; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v22 = this;
  *(_DWORD *)(this + 485) = 0;
  v21 = 0;
  v7 = *((_DWORD *)v6 + 1) + v3;
  v18 = v7;
  if ( *((_DWORD *)v6 + 1) >= v7 )
    goto LABEL_76;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v21);
    if ( result )
      return result;
    switch ( v21 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 485) & 1) == 0 )
          *(_DWORD *)(v4 + 485) |= 1u;
        Int32 = sub_10115A30(v6, (_BYTE *)v4);
        goto LABEL_74;
      case 2u:
        if ( (*(_DWORD *)(v4 + 485) & 2) == 0 )
          *(_DWORD *)(v4 + 485) |= 2u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022CA50(v4 + 1, v6, a2);
        goto LABEL_74;
      case 3u:
        if ( (*(_DWORD *)(v4 + 485) & 4) == 0 )
          *(_DWORD *)(v4 + 485) |= 4u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022D240((char *)(v4 + 156), v6, (int)a2);
        goto LABEL_74;
      case 4u:
        if ( (*(_DWORD *)(v4 + 485) & 8) == 0 )
          *(_DWORD *)(v4 + 485) |= 8u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022DBB0(v4 + 163, v6, a2);
        goto LABEL_74;
      case 5u:
        if ( (*(_DWORD *)(v4 + 485) & 0x10) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 245));
        goto LABEL_74;
      case 6u:
        if ( (*(_DWORD *)(v4 + 485) & 0x20) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 249));
        goto LABEL_74;
      case 7u:
        if ( (*(_DWORD *)(v4 + 485) & 0x40) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 253));
        goto LABEL_74;
      case 8u:
        if ( (*(_DWORD *)(v4 + 485) & 0x80) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 257));
        goto LABEL_74;
      case 9u:
        if ( (*(_DWORD *)(v4 + 485) & 0x100) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 261));
        goto LABEL_74;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 485) & 0x200) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = *((_DWORD *)v6 + 1);
        v11 = (_BYTE *)(v22 + 265);
        a3 = v22 + 265;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = *((_DWORD *)v6 + 1);
          if ( v12 > (unsigned int)&a2[v19] )
            return -34;
          if ( (char *)v12 == &a2[v19] )
            break;
          ++v10;
          v11 = (_BYTE *)(a3 + 4);
          a3 += 4;
          if ( v10 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v13 = v10 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 261) = v13;
        goto LABEL_75;
      case 0xBu:
        if ( (*(_DWORD *)(v4 + 485) & 0x400) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x400u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 305));
        goto LABEL_74;
      case 0xCu:
        if ( (*(_DWORD *)(v4 + 485) & 0x800) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v20 = *((_DWORD *)v6 + 1);
        v15 = (_BYTE *)(v22 + 309);
        a3 = v22 + 309;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = *((_DWORD *)v6 + 1);
          if ( v16 > (unsigned int)&a2[v20] )
            return -34;
          if ( (char *)v16 == &a2[v20] )
            break;
          ++v14;
          v15 = (_BYTE *)(a3 + 4);
          a3 += 4;
          if ( v14 >= 10 )
          {
            v4 = v22;
            goto LABEL_75;
          }
        }
        v17 = v14 + 1;
        v4 = v22;
        *(_DWORD *)(v22 + 305) = v17;
LABEL_75:
        v7 = v18;
        if ( *((_DWORD *)v6 + 1) < v18 )
          continue;
LABEL_76:
        if ( *((_DWORD *)v6 + 1) > v7 )
          return -34;
        return v5;
      case 0xDu:
        if ( (*(_DWORD *)(v4 + 485) & 0x1000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x1000u;
        a2 = 0;
        v5 = TdrBuf::ReadInt32(v6, &a2);
        if ( v5 )
          return v5;
        if ( !a2 )
          goto LABEL_75;
        Int32 = sub_1022EB70((_DWORD *)(v4 + 349), v6, (int)a2);
LABEL_74:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_75;
        return v5;
      case 0xEu:
        if ( (*(_DWORD *)(v4 + 485) & 0x2000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x2000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 477));
        goto LABEL_74;
      case 0xFu:
        if ( (*(_DWORD *)(v4 + 485) & 0x4000) == 0 )
          *(_DWORD *)(v4 + 485) |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 481));
        goto LABEL_74;
      default:
        Int32 = TdrBuf::SkipField(v6, v21 & 0xF);
        goto LABEL_74;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1020F9C0
// ============================================================
//----- (1020F9C0) --------------------------------------------------------
int __thiscall sub_1020F9C0(_DWORD *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(this + 1) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v8 = a2[1];
        if ( (unsigned int)(a2[2] - v8) < 2 )
          return -2;
        *(_BYTE *)this = *(_BYTE *)(*a2 + v8 + 1);
        *((_BYTE *)this + 1) = *(_BYTE *)(*a2 + a2[1]);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(this + 1) & 2) == 0 )
          *(this + 1) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v7 = a2[1];
        if ( (unsigned int)(a2[2] - v7) < 2 )
          return -2;
        *((_BYTE *)this + 2) = *(_BYTE *)(*a2 + v7 + 1);
        *((_BYTE *)this + 3) = *(_BYTE *)(*a2 + a2[1]);
      }
      a2[1] += 2;
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1017C3E0
// ============================================================
//----- (1017C3E0) --------------------------------------------------------
int __thiscall sub_1017C3E0(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10191530
// ============================================================
//----- (10191530) --------------------------------------------------------
int __thiscall sub_10191530(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1018DAC0
// ============================================================
//----- (1018DAC0) --------------------------------------------------------
int __thiscall sub_1018DAC0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
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
// Address Name: SUB_10152C90
// ============================================================
//----- (10152C90) --------------------------------------------------------
int __thiscall sub_10152C90(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)(this + 264) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_28:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      switch ( v16 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 264) & 1) == 0 )
            *(_DWORD *)(this + 264) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 264) & 2) == 0 )
            *(_DWORD *)(this + 264) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 264) & 4) == 0 )
            *(_DWORD *)(this + 264) |= 4u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *(_BYTE *)(v11 + this + 8) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *(_DWORD *)(this + 4) = v11 + 1;
                  goto LABEL_27;
                }
                if ( ++v11 >= 256 )
                {
                  v6 = a3;
                  goto LABEL_27;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        default:
          Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
          break;
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_27:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10156E40
// ============================================================
//----- (10156E40) --------------------------------------------------------
int __thiscall sub_10156E40(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 28) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
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
          if ( (*(_BYTE *)(this + 28) & 1) == 0 )
            *(_DWORD *)(this + 28) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 28) & 2) == 0 )
            *(_DWORD *)(this + 28) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 28) & 4) == 0 )
            *(_DWORD *)(this + 28) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 28) & 8) == 0 )
            *(_DWORD *)(this + 28) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 28) & 0x10) == 0 )
            *(_DWORD *)(this + 28) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 28) & 0x20) == 0 )
            *(_DWORD *)(this + 28) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 28) & 0x40) == 0 )
            *(_DWORD *)(this + 28) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
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
        goto LABEL_28;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155B00
// ============================================================
//----- (10155B00) --------------------------------------------------------
int __thiscall sub_10155B00(int this, int a2, unsigned int a3)
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
  *(_DWORD *)(this + 722) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_23:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 722) & 1) == 0 )
            *(_DWORD *)(this + 722) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 722) & 2) == 0 )
            *(_DWORD *)(this + 722) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 722) & 4) == 0 )
            *(_DWORD *)(this + 722) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_22;
          Int32 = sub_10155200((char *)(this + 8), v4, a2);
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 722) & 8) == 0 )
            *(_DWORD *)(this + 722) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_22;
          Int32 = sub_10154870(this + 77, v4, a2);
          break;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_22:
      v7 = a3;
      if ( v4[1] >= a3 )
        goto LABEL_23;
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
// Address Name: SUB_101103F0
// ============================================================
//----- (101103F0) --------------------------------------------------------
int __thiscall sub_101103F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Int64; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  _BYTE *v9; // eax
  int Int32; // eax
  int v11; // ebx
  unsigned int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Int64 = 0;
  v6 = a2;
  v17 = this;
  *(_DWORD *)(this + 67) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_36:
    if ( v6[1] > v7 )
      return -34;
    return Int64;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 67) & 1) == 0 )
          *(_DWORD *)(v4 + 67) |= 1u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4);
        if ( Int64 )
          return Int64;
        goto LABEL_35;
      case 2u:
        if ( (*(_DWORD *)(v4 + 67) & 2) == 0 )
          *(_DWORD *)(v4 + 67) |= 2u;
        v9 = (_BYTE *)(v4 + 8);
        goto LABEL_11;
      case 3u:
        if ( (*(_DWORD *)(v4 + 67) & 4) == 0 )
          *(_DWORD *)(v4 + 67) |= 4u;
        v9 = (_BYTE *)(v4 + 12);
LABEL_11:
        Int32 = TdrBuf::ReadInt32(v6, v9);
        goto LABEL_12;
      case 4u:
        if ( (*(_DWORD *)(v4 + 67) & 8) == 0 )
          *(_DWORD *)(v4 + 67) |= 8u;
        Int32 = TdrBuf::ReadByte(v6, (_BYTE *)(v4 + 16));
        goto LABEL_12;
      case 5u:
        if ( (*(_DWORD *)(v4 + 67) & 0x10) == 0 )
          *(_DWORD *)(v4 + 67) |= 0x10u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)(v4 + 17));
        goto LABEL_12;
      case 6u:
        if ( (*(_DWORD *)(v4 + 67) & 0x20) == 0 )
          *(_DWORD *)(v4 + 67) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v11 = 0;
          v14 = v6[1];
          a3 = v17 + 19;
          while ( 1 )
          {
            v15 = 0;
            Int64 = TdrBuf::ReadInt32(v6, &v15);
            if ( Int64 )
              return Int64;
            if ( v15 )
            {
              Int64 = sub_1010FA60(v6, v15);
              if ( Int64 )
                return Int64;
            }
            v12 = v6[1];
            if ( v12 > (unsigned int)a2 + v14 )
              break;
            if ( (_DWORD *)v12 != (_DWORD *)((char *)a2 + v14) )
            {
              a3 += 16;
              if ( (unsigned int)++v11 < 3 )
                continue;
            }
            v4 = v17;
LABEL_35:
            v7 = v13;
            if ( v6[1] >= v13 )
              goto LABEL_36;
            goto LABEL_2;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      default:
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_12:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_35;
        return Int64;
    }
  }
  return result;
}
// 1010FA60: using guessed type _DWORD __stdcall sub_1010FA60(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10167350
// ============================================================
//----- (10167350) --------------------------------------------------------
int __thiscall sub_10167350(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 25) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 25) & 1) == 0 )
        *(_DWORD *)(this + 25) |= 1u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x15 )
        return -3;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9) = 0;
      v6 = a3;
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 25) & 2) == 0 )
        *(_DWORD *)(this + 25) |= 2u;
      result = TdrBuf::ReadInt32(v4, this + 21);
      if ( result )
        return result;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10191700
// ============================================================
//----- (10191700) --------------------------------------------------------
int __thiscall sub_10191700(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iPosition]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iItemId]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iItemNum]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[iQuality]", "%d", *(this + 3));
    }
  }
  return result;
}



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
// Address Name: SUB_1017C560
// ============================================================
//----- (1017C560) --------------------------------------------------------
int __thiscall sub_1017C560(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[arg1]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[arg2]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[arg3]", "%d", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1018DC60
// ============================================================
//----- (1018DC60) --------------------------------------------------------
int __thiscall sub_1018DC60(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[actionId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[steps]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10152F10
// ============================================================
//----- (10152F10) --------------------------------------------------------
int __thiscall sub_10152F10(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi

  result = print_field(a2, a3, a4, "[type]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[procLen]", "%d", *(this + 1));
    if ( !result )
    {
      v7 = *(this + 1);
      if ( v7 >= 0 )
      {
        if ( v7 <= 256 )
        {
          result = sub_1024A3B0(a2, a3, v6, "[procData]", v7);
          if ( !result )
          {
            v8 = 0;
            if ( (int)*(this + 1) <= 0 )
            {
              return TdrBuf::WriteChar(a2, a4);
            }
            else
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *((unsigned __int8 *)this + v8 + 8));
                if ( result )
                  break;
                if ( ++v8 >= *(this + 1) )
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
  }
  return result;
}
// 10152F90: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10157090
// ============================================================
//----- (10157090) --------------------------------------------------------
int __thiscall sub_10157090(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[onlineTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lastUpdateTime]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[activityID]", "%u", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[hour]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[min]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[second]", "%d", *(this + 5));
            if ( !result )
              return print_field(a2, a3, a4, "[offset]", "%d", *(this + 6));
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155D40
// ============================================================
//----- (10155D40) --------------------------------------------------------
int __thiscall sub_10155D40(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // ecx

  result = print_field(a2, a3, a4, "[activityID]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[lastUpdate]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_structure((int)a2, a3, a4, (int)"[vars]");
      if ( !result )
      {
        v5 = (unsigned __int8 *)(this + 2);
        if ( a3 >= 0 )
          result = sub_10155440(v5, a2, a3 + 1, a4);
        else
          result = sub_10155440(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[counters]");
          if ( !result )
          {
            v6 = (unsigned __int8 *)this + 77;
            if ( a3 >= 0 )
              return sub_10154AF0(v6, a2, a3 + 1, a4);
            else
              return sub_10154AF0(v6, a2, a3, a4);
          }
        }
      }
    }
  }
  return result;
}



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
// Address Name: SUB_1020FC00
// ============================================================
//----- (1020FC00) --------------------------------------------------------
int __thiscall sub_1020FC00(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commodity]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[saledCount]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101106B0
// ============================================================
//----- (101106B0) --------------------------------------------------------
int __thiscall sub_101106B0(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned int v5; // edi
  _DWORD *v6; // ebx

  result = print_field(a2, a3, a4, "[itemId]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[itemType]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[targetPos]", "%d", *((_DWORD *)this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[posColumn]", "0x%02x", *(this + 16));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[posGrid]", "%d", *(unsigned __int16 *)(this + 17));
          if ( !result )
          {
            v5 = 0;
            v6 = this + 19;
            do
            {
              result = sub_1024A230((int)a2, a4, (char)"[skillBeadsInfo]", v5);
              if ( result )
                break;
              result = a3 >= 0 ? sub_1010FBE0(v6, a2, a3 + 1, a4) : sub_1010FBE0(v6, a2, a3, a4);
              if ( result )
                break;
              ++v5;
              v6 += 4;
            }
            while ( v5 < 3 );
          }
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102304E0
// ============================================================
//----- (102304E0) --------------------------------------------------------
int __thiscall sub_102304E0(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  char *v8; // ecx
  __int16 *v9; // ecx
  char *v10; // ecx
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // ecx
  int v15; // eax
  _DWORD *v16; // ecx
  int *v17; // ecx
  int v18; // [esp+14h] [ebp+8h]
  int v19; // [esp+14h] [ebp+8h]
  int v20; // [esp+18h] [ebp+Ch]
  int v21; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[hitCount]", "0x%02x", *this);
  if ( !result )
  {
    if ( !"[pieces]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[pieces]", (char)a4);
      if ( !result )
      {
        v8 = this + 1;
        result = a3 >= 0 ? sub_1022CCE0(v8, a2, a3 + 1, a4) : sub_1022CCE0(v8, a2, a3, a4);
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[ultimatePrize]");
          if ( !result )
          {
            v9 = (__int16 *)(this + 156);
            result = a3 >= 0 ? sub_1022D470(v9, a2, a3 + 1, a4) : sub_1022D470(v9, a2, a3, a4);
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[piecePrizes]");
              if ( !result )
              {
                v10 = this + 163;
                result = a3 >= 0 ? sub_1022DE30(v10, a2, a3 + 1, a4) : sub_1022DE30(v10, a2, a3, a4);
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[blackFaceCount]", "%d", *(_DWORD *)(this + 245));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[iFHasSSR]", "%d", *(_DWORD *)(this + 249));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[dragonShopID]", "%d", *(_DWORD *)(this + 253));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[dragonShopEndTime]", "%u", *(_DWORD *)(this + 257));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[freshNumBitCount]", "%d", *(_DWORD *)(this + 261));
                          if ( !result )
                          {
                            v12 = *(_DWORD *)(this + 261);
                            if ( v12 < 0 )
                              return -6;
                            if ( v12 > 10 )
                              return -7;
                            result = sub_1024A3B0(a2, a3, v11, "[freshNumBit]", v12);
                            if ( !result )
                            {
                              v20 = 0;
                              if ( *(int *)(this + 261) <= 0 )
                              {
LABEL_34:
                                result = TdrBuf::WriteChar(a2, a4);
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[freshNumTenCount]", "%d", *(_DWORD *)(this + 305));
                                  if ( !result )
                                  {
                                    v15 = *(_DWORD *)(this + 305);
                                    if ( v15 < 0 )
                                      return -6;
                                    if ( v15 > 10 )
                                      return -7;
                                    result = sub_1024A3B0(a2, a3, v14, "[freshNumTen]", v15);
                                    if ( !result )
                                    {
                                      v21 = 0;
                                      if ( *(int *)(this + 305) <= 0 )
                                      {
LABEL_43:
                                        result = TdrBuf::WriteChar(a2, a4);
                                        if ( !result )
                                        {
                                          result = print_structure((int)a2, a3, a4, (int)"[dragonBoxShopItems]");
                                          if ( !result )
                                          {
                                            v17 = (int *)(this + 349);
                                            if ( a3 >= 0 )
                                              result = sub_1022EDA0(v17, a2, a3 + 1, a4);
                                            else
                                              result = sub_1022EDA0(v17, a2, a3, a4);
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[freshNumCnt]",
                                                         "%d",
                                                         *(_DWORD *)(this + 477));
                                              if ( !result )
                                                return print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[fetchState]",
                                                         "%d",
                                                         *(_DWORD *)(this + 481));
                                            }
                                          }
                                        }
                                      }
                                      else
                                      {
                                        v16 = this + 309;
                                        v19 = (int)(this + 309);
                                        while ( 1 )
                                        {
                                          result = Printf(a2, " %d", *v16);
                                          if ( result )
                                            break;
                                          v16 = (_DWORD *)(v19 + 4);
                                          ++v21;
                                          v19 += 4;
                                          if ( v21 >= *(_DWORD *)(this + 305) )
                                            goto LABEL_43;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              else
                              {
                                v13 = this + 265;
                                v18 = (int)(this + 265);
                                while ( 1 )
                                {
                                  result = Printf(a2, " %d", *v13);
                                  if ( result )
                                    break;
                                  v13 = (_DWORD *)(v18 + 4);
                                  ++v20;
                                  v18 += 4;
                                  if ( v20 >= *(_DWORD *)(this + 261) )
                                    goto LABEL_34;
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
// 102306EC: variable 'v11' is possibly undefined
// 1023079B: variable 'v14' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022D470
// ============================================================
//----- (1022D470) --------------------------------------------------------
int __thiscall sub_1022D470(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[state]", "0x%02x", *((char *)this + 2));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1010F9B0
// ============================================================
//----- (1010F9B0) --------------------------------------------------------
int __thiscall sub_1010F9B0(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int v7; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 3) = 0;
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
          if ( (*(_BYTE *)(this + 3) & 1) == 0 )
            *(this + 3) |= 1u;
          v7 = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 3) & 2) == 0 )
            *(this + 3) |= 2u;
          v7 = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 3) & 4) == 0 )
            *(this + 3) |= 4u;
          v7 = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        default:
          v7 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = v7;
      if ( v7 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101546C0
// ============================================================
//----- (101546C0) --------------------------------------------------------
int __thiscall sub_101546C0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 641) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[641] & 1) == 0 )
          *(_DWORD *)(v5 + 641) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 641) & 2) == 0 )
            *(_DWORD *)(v5 + 641) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10153DB0(&v16[10 * v9 + 1], v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x40u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155090
// ============================================================
//----- (10155090) --------------------------------------------------------
int __thiscall sub_10155090(char *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  bool v6; // cf
  int result; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v12 = 0;
  *(_DWORD *)(this + 65) = 0;
  v11 = v4[1] + v3;
  v6 = v11 < v4[1];
  if ( v11 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 65) & 1) == 0 )
        *(_DWORD *)(this + 65) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v10 = v4[1];
      if ( v4[2] == v10 )
        return -2;
      *this = *(_BYTE *)(v10 + *v4);
      ++v4[1];
    }
    else
    {
      if ( v12 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 65) & 2) == 0 )
          *(_DWORD *)(this + 65) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v8 = 0;
            a3 = v4[1];
            while ( 1 )
            {
              result = TdrBuf::ReadVarInt(v4, (int *)(this + 4 * v8 + 1));
              if ( result )
                break;
              v9 = v4[1];
              if ( v9 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + a3) )
              {
                *this = v8 + 1;
                goto LABEL_24;
              }
              if ( ++v8 >= 0x10u )
                goto LABEL_24;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      }
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
LABEL_24:
    if ( v4[1] >= v11 )
    {
      v6 = v11 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022DA00
// ============================================================
//----- (1022DA00) --------------------------------------------------------
int __thiscall sub_1022DA00(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 78) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v5[78] & 1) == 0 )
          *(_DWORD *)(v5 + 78) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 78) & 2) == 0 )
            *(_DWORD *)(v5 + 78) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022D150(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 7;
            if ( ++v9 >= 11 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022EA10
// ============================================================
//----- (1022EA10) --------------------------------------------------------
int __thiscall sub_1022EA10(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 31) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[31] & 1) == 0 )
          v4[31] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[31] & 2) == 0 )
            v4[31] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1022E2B0(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 3;
            if ( ++v10 >= 10 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022C890
// ============================================================
//----- (1022C890) --------------------------------------------------------
int __thiscall sub_1022C890(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 151) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v5[151] & 1) == 0 )
          *(_DWORD *)(v5 + 151) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 151) & 2) == 0 )
            *(_DWORD *)(v5 + 151) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022BFD0(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 6;
            if ( ++v9 >= 25 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022DBB0
// ============================================================
//----- (1022DBB0) --------------------------------------------------------
int __thiscall sub_1022DBB0(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 78) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v5[78] & 1) == 0 )
          *(_DWORD *)(v5 + 78) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 78) & 2) == 0 )
            *(_DWORD *)(v5 + 78) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022D240(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 7;
            if ( ++v9 >= 11 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022CA50
// ============================================================
//----- (1022CA50) --------------------------------------------------------
int __thiscall sub_1022CA50(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v17 = (_BYTE *)this;
  v16 = 0;
  *(_DWORD *)(this + 151) = 0;
  v7 = &v3[v4[1]];
  v13 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_27:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v5[151] & 1) == 0 )
          *(_DWORD *)(v5 + 151) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 151) & 2) == 0 )
            *(_DWORD *)(v5 + 151) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            if ( v15 )
            {
              v6 = sub_1022C0F0(a3, v4, v15);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v17;
              *v17 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            a3 += 6;
            if ( ++v9 >= 25 )
            {
              v5 = v17;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v16 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= (unsigned int)v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022EB70
// ============================================================
//----- (1022EB70) --------------------------------------------------------
int __thiscall sub_1022EB70(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 31) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[31] & 1) == 0 )
          v4[31] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[31] & 2) == 0 )
            v4[31] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1022E350(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 12;
            if ( ++v10 >= 10 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155200
// ============================================================
//----- (10155200) --------------------------------------------------------
int __thiscall sub_10155200(char *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  bool v6; // cf
  int result; // eax
  unsigned __int8 v8; // bl
  unsigned int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+10h] [ebp-8h]
  unsigned int v12; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v12 = 0;
  *(_DWORD *)(this + 65) = 0;
  v11 = v4[1] + v3;
  v6 = v11 < v4[1];
  if ( v11 <= v4[1] )
    return v6 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      return result;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 65) & 1) == 0 )
        *(_DWORD *)(this + 65) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v10 = v4[1];
      if ( v4[2] == v10 )
        return -2;
      *this = *(_BYTE *)(v10 + *v4);
      ++v4[1];
    }
    else
    {
      if ( v12 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 65) & 2) == 0 )
          *(_DWORD *)(this + 65) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( a2 )
          {
            v8 = 0;
            a3 = v4[1];
            while ( 1 )
            {
              result = TdrBuf::ReadInt32(v4, this + 4 * v8 + 1);
              if ( result )
                break;
              v9 = v4[1];
              if ( v9 > (unsigned int)a2 + a3 )
                return -34;
              if ( (_DWORD *)v9 == (_DWORD *)((char *)a2 + a3) )
              {
                *this = v8 + 1;
                goto LABEL_24;
              }
              if ( ++v8 >= 0x10u )
                goto LABEL_24;
            }
          }
          else
          {
            return -37;
          }
        }
        return result;
      }
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
LABEL_24:
    if ( v4[1] >= v11 )
    {
      v6 = v11 < v4[1];
      return v6 ? 0xFFFFFFDE : 0;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10154870
// ============================================================
//----- (10154870) --------------------------------------------------------
int __thiscall sub_10154870(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _BYTE *v5; // ebx
  int v6; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned __int8 v9; // bl
  unsigned int v10; // ecx
  _BYTE *v11; // eax
  int v12; // ecx
  unsigned int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  unsigned int v15; // [esp+18h] [ebp-8h] BYREF
  _BYTE *v16; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_BYTE *)this;
  v6 = 0;
  v16 = (_BYTE *)this;
  v15 = 0;
  *(_DWORD *)(this + 641) = 0;
  v7 = v4[1] + v3;
  v13 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_27:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (v5[641] & 1) == 0 )
          *(_DWORD *)(v5 + 641) |= 1u;
        if ( v4[1] > v4[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v12 = v4[1];
        if ( v4[2] == v12 )
          return -2;
        *v5 = *(_BYTE *)(v12 + *v4);
        ++v4[1];
        v6 = 0;
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(v5 + 641) & 2) == 0 )
            *(_DWORD *)(v5 + 641) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v9 = 0;
          v14 = v4[1];
          while ( 1 )
          {
            a3 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            if ( a3 )
            {
              v6 = sub_10153F00(&v16[10 * v9 + 1], v4, a3);
              if ( v6 )
                return v6;
            }
            v10 = v4[1];
            if ( v10 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v10 == (_DWORD *)((char *)a2 + v14) )
            {
              v11 = v16;
              *v16 = v9 + 1;
              v5 = v11;
              goto LABEL_26;
            }
            if ( ++v9 >= 0x40u )
            {
              v5 = v16;
              goto LABEL_26;
            }
          }
        }
        v6 = TdrBuf::SkipField(v4, v15 & 0xF);
        if ( v6 )
          return v6;
      }
LABEL_26:
      v7 = v13;
      if ( v4[1] >= v13 )
        goto LABEL_27;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1010FA60
// ============================================================
//----- (1010FA60) --------------------------------------------------------
int __thiscall sub_1010FA60(int this, _DWORD *a2, int a3)
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(_DWORD *)(this + 12) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 12) & 2) == 0 )
            *(_DWORD *)(this + 12) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 12) & 4) == 0 )
            *(_DWORD *)(this + 12) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v8 & 0xF);
          break;
      }
      v4 = Int32;
      if ( Int32 )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_18;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10155440
// ============================================================
//----- (10155440) --------------------------------------------------------
int __thiscall sub_10155440(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // bl

  result = print_field(a2, a3, a4, "[varNum]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this <= 0x10u )
    {
      result = sub_1024A3B0(a2, a3, v6, "[varData]", *this);
      if ( !result )
      {
        v7 = 0;
        if ( *this )
        {
          while ( 1 )
          {
            result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v7 + 1));
            if ( result )
              break;
            if ( ++v7 >= *this )
              return TdrBuf::WriteChar(a2, a4);
          }
        }
        else
        {
          return TdrBuf::WriteChar(a2, a4);
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
// 1015548F: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10154AF0
// ============================================================
//----- (10154AF0) --------------------------------------------------------
int __thiscall sub_10154AF0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // bl
  int v7; // [esp-Ch] [ebp-18h]

  result = print_field(a2, a3, a4, "[counterNum]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this <= 0x40u )
    {
      v6 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          if ( !"[counterData]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[counterData]", v6, a4);
          if ( result )
            break;
          v7 = a3 >= 0 ? a3 + 1 : a3;
          result = sub_10154120(this + 10 * v6 + 1, a2, v7, a4);
          if ( result )
            break;
          if ( ++v6 >= *this )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1010FBE0
// ============================================================
//----- (1010FBE0) --------------------------------------------------------
int __thiscall sub_1010FBE0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[slotItemId]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[beadLevel]", "%d", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[isLegend]", "%d", *(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022CCE0
// ============================================================
//----- (1022CCE0) --------------------------------------------------------
int __thiscall sub_1022CCE0(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char v6; // al
  int v7; // esi
  char *i; // ebx

  result = print_field(a2, a3, a4, "[count]", "0x%02x", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 25 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 6 )
          {
            if ( !"[pieces]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[pieces]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022C310(i, a2, a3 + 1, a4) : sub_1022C310(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_1022EDA0
// ============================================================
//----- (1022EDA0) --------------------------------------------------------
int __thiscall sub_1022EDA0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 10 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 3 )
          {
            if ( !"[dragonBoxShopItems]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[dragonBoxShopItems]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022E4F0(i, a2, a3 + 1, a4) : sub_1022E4F0(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_1022DE30
// ============================================================
//----- (1022DE30) --------------------------------------------------------
int __thiscall sub_1022DE30(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char v6; // al
  int v7; // esi
  __int16 *i; // ebx

  result = print_field(a2, a3, a4, "[count]", "0x%02x", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 11 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (__int16 *)(this + 1); ; i = (__int16 *)((char *)i + 7) )
          {
            if ( !"[piecePrizes]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[piecePrizes]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1022D470(i, a2, a3 + 1, a4) : sub_1022D470(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10153DB0
// ============================================================
//----- (10153DB0) --------------------------------------------------------
int __thiscall sub_10153DB0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 6) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 3 )
        {
          if ( v9 >> 4 == 4 )
          {
            if ( (*(_DWORD *)(this + 6) & 4) == 0 )
              *(_DWORD *)(this + 6) |= 4u;
            result = TdrBuf::ReadVarUInt(a2, this + 2);
            if ( result )
              return result;
          }
          else
          {
            result = TdrBuf::SkipField(a2, v9 & 0xF);
            if ( result )
              return result;
          }
          goto LABEL_25;
        }
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_25:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022E2B0
// ============================================================
//----- (1022E2B0) --------------------------------------------------------
int __thiscall sub_1022E2B0(int *this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(this + 2) = 0;
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
        if ( (*(_BYTE *)(this + 2) & 1) == 0 )
          *(this + 2) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(this + 2) & 2) == 0 )
          *(this + 2) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, this + 1);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarInt;
      if ( VarInt )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022BFD0
// ============================================================
//----- (1022BFD0) --------------------------------------------------------
int __thiscall sub_1022BFD0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022C0F0
// ============================================================
//----- (1022C0F0) --------------------------------------------------------
int __thiscall sub_1022C0F0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 2) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 2) & 1) == 0 )
          *(_DWORD *)(this + 2) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 2 )
        {
          result = TdrBuf::SkipField(a2, v9 & 0xF);
          if ( result )
            return result;
          goto LABEL_20;
        }
        if ( (*(_DWORD *)(this + 2) & 2) == 0 )
          *(_DWORD *)(this + 2) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_20:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022E350
// ============================================================
//----- (1022E350) --------------------------------------------------------
int __thiscall sub_1022E350(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int Int32; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
        if ( (*(_BYTE *)(this + 8) & 1) == 0 )
          *(_DWORD *)(this + 8) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
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
// Address Name: SUB_10153F00
// ============================================================
//----- (10153F00) --------------------------------------------------------
int __thiscall sub_10153F00(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 6) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 > a2[1] )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v8 = a2[1];
        if ( a2[2] == v8 )
          return -2;
        *this = *(_BYTE *)(v8 + *a2);
      }
      else
      {
        if ( v9 >> 4 != 3 )
        {
          if ( v9 >> 4 == 4 )
          {
            if ( (*(_DWORD *)(this + 6) & 4) == 0 )
              *(_DWORD *)(this + 6) |= 4u;
            result = TdrBuf::ReadInt32(a2, this + 2);
            if ( result )
              return result;
          }
          else
          {
            result = TdrBuf::SkipField(a2, v9 & 0xF);
            if ( result )
              return result;
          }
          goto LABEL_25;
        }
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v7 = a2[1];
        if ( a2[2] == v7 )
          return -2;
        *(this + 1) = *(_BYTE *)(v7 + *a2);
      }
      ++a2[1];
LABEL_25:
      if ( a2[1] >= v10 )
      {
        v5 = v10 < a2[1];
        return v5 ? 0xFFFFFFDE : 0;
      }
    }
  }
  return v5 ? 0xFFFFFFDE : 0;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10154120
// ============================================================
//----- (10154120) --------------------------------------------------------
int __thiscall sub_10154120(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[phase]", "0x%02x", *(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[counter]", "%u", *(_DWORD *)(this + 2));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022C310
// ============================================================
//----- (1022C310) --------------------------------------------------------
int __thiscall sub_1022C310(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[val]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[hit]", "0x%02x", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1022E4F0
// ============================================================
//----- (1022E4F0) --------------------------------------------------------
int __thiscall sub_1022E4F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[thisID]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[buyTimes]", "%d", *(this + 1));
  return result;
}



