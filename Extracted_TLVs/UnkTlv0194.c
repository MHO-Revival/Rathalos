// ============================================================
// Name: TLV::UnkTlv0194::Read
// Address Name: SUB_101D90E0
// ============================================================
//----- (101D90E0) --------------------------------------------------------
int __thiscall sub_101D90E0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  unsigned int v8; // [esp-Ch] [ebp-1Ch]
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
    result = sub_101D91B0((unsigned int)this, &v9, v8);
  else
    result = sub_101DACC0((unsigned int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0194::Read_0xAA
// Address Name: SUB_101D91B0
// ============================================================
//----- (101D91B0) --------------------------------------------------------
int __thiscall sub_101D91B0(unsigned int this, _DWORD *a2, unsigned int i)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int VarInt; // edx
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // ebx
  int *v10; // eax
  unsigned int v11; // eax
  int VarShort; // eax
  unsigned int v13; // ebx
  int *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  int *v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  int *v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ebx
  int *v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebx
  int *v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ebx
  int *v29; // eax
  unsigned int v30; // ecx
  _DWORD *v31; // ebx
  char *v32; // eax
  char *v33; // ecx
  _DWORD *v34; // ebx
  char *v35; // eax
  char *v36; // ecx
  unsigned int v37; // [esp+0h] [ebp-14h]
  int v38; // [esp+4h] [ebp-10h] BYREF
  int v39; // [esp+8h] [ebp-Ch] BYREF
  int v40; // [esp+Ch] [ebp-8h]
  unsigned int v41; // [esp+10h] [ebp-4h] BYREF

  v3 = i;
  v4 = a2;
  VarInt = 0;
  v41 = 0;
  *(_OWORD *)(this + 542) = 0;
  v7 = v4[1] + v3;
  v37 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_406;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v41);
    if ( result )
      return result;
    switch ( v41 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 542) & 1) == 0 )
          *(_DWORD *)(this + 542) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( !a2 )
            return -37;
          v9 = 0;
          v40 = v4[1];
          v10 = (int *)this;
          i = this;
          while ( 1 )
          {
            VarInt = TdrBuf::ReadVarInt(v4, v10);
            if ( VarInt )
              return VarInt;
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v40 )
              return -34;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v40) )
            {
              ++v9;
              v10 = (int *)(i + 4);
              i += 4;
              if ( v9 < 7 )
                continue;
            }
            goto LABEL_405;
          }
        }
        return result;
      case 4u:
        if ( (*(_DWORD *)(this + 542) & 2) == 0 )
          *(_DWORD *)(this + 542) |= 2u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 28));
        goto LABEL_404;
      case 6u:
        if ( (*(_DWORD *)(this + 542) & 4) == 0 )
          *(_DWORD *)(this + 542) |= 4u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 32));
        goto LABEL_404;
      case 7u:
        if ( (*(_DWORD *)(this + 542) & 8) == 0 )
          *(_DWORD *)(this + 542) |= 8u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 36));
        goto LABEL_404;
      case 0x10u:
        if ( (*(_DWORD *)(this + 542) & 0x10) == 0 )
          *(_DWORD *)(this + 542) |= 0x10u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 40));
        goto LABEL_404;
      case 0x11u:
        if ( (*(_DWORD *)(this + 542) & 0x20) == 0 )
          *(_DWORD *)(this + 542) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v40 = v4[1];
        v14 = (int *)(this + 44);
        i = this + 44;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v14);
          if ( VarInt )
            return VarInt;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v13;
            v14 = (int *)(i + 4);
            i += 4;
            if ( v13 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x13u:
        if ( (*(_DWORD *)(this + 542) & 0x40) == 0 )
          *(_DWORD *)(this + 542) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v40 = v4[1];
        v17 = (int *)(this + 72);
        i = this + 72;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v17);
          if ( VarInt )
            return VarInt;
          v18 = v4[1];
          if ( v18 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v18 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v16;
            v17 = (int *)(i + 4);
            i += 4;
            if ( v16 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x14u:
        if ( (*(_DWORD *)(this + 542) & 0x80) == 0 )
          *(_DWORD *)(this + 542) |= 0x80u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 100));
        goto LABEL_404;
      case 0x24u:
        if ( (*(_DWORD *)(this + 542) & 0x100) == 0 )
          *(_DWORD *)(this + 542) |= 0x100u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 102));
        goto LABEL_404;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 542) & 0x200) == 0 )
          *(_DWORD *)(this + 542) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v19 = 0;
        v40 = v4[1];
        v20 = (int *)(this + 106);
        i = this + 106;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v20);
          if ( VarInt )
            return VarInt;
          v21 = v4[1];
          if ( v21 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v21 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v19;
            v20 = (int *)(i + 4);
            i += 4;
            if ( v19 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x6Cu:
        if ( (*(_DWORD *)(this + 542) & 0x400) == 0 )
          *(_DWORD *)(this + 542) |= 0x400u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 134));
        goto LABEL_404;
      case 0x6Du:
        if ( (*(_DWORD *)(this + 542) & 0x800) == 0 )
          *(_DWORD *)(this + 542) |= 0x800u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 138));
        goto LABEL_404;
      case 0x74u:
        if ( (*(_DWORD *)(this + 542) & 0x1000) == 0 )
          *(_DWORD *)(this + 542) |= 0x1000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 142));
        goto LABEL_404;
      case 0x7Au:
        if ( (*(_DWORD *)(this + 542) & 0x2000) == 0 )
          *(_DWORD *)(this + 542) |= 0x2000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 146));
        goto LABEL_404;
      case 0x80u:
        if ( (*(_DWORD *)(this + 542) & 0x4000) == 0 )
          *(_DWORD *)(this + 542) |= 0x4000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 150));
        goto LABEL_404;
      case 0x88u:
        if ( (*(_DWORD *)(this + 542) & 0x8000) == 0 )
          *(_DWORD *)(this + 542) |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v40 = v4[1];
        v23 = (int *)(this + 154);
        i = this + 154;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v23);
          if ( VarInt )
            return VarInt;
          v24 = v4[1];
          if ( v24 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v24 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v22;
            v23 = (int *)(i + 4);
            i += 4;
            if ( v22 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x89u:
        if ( (*(_DWORD *)(this + 542) & 0x10000) == 0 )
          *(_DWORD *)(this + 542) |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v25 = 0;
        v40 = v4[1];
        v26 = (int *)(this + 182);
        i = this + 182;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v26);
          if ( VarInt )
            return VarInt;
          v27 = v4[1];
          if ( v27 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v27 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v25;
            v26 = (int *)(i + 4);
            i += 4;
            if ( v25 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x96u:
        if ( (*(_DWORD *)(this + 542) & 0x20000) == 0 )
          *(_DWORD *)(this + 542) |= 0x20000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 210));
        goto LABEL_404;
      case 0xADu:
        if ( (*(_DWORD *)(this + 542) & 0x40000) == 0 )
          *(_DWORD *)(this + 542) |= 0x40000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 214));
        goto LABEL_404;
      case 0xB0u:
        if ( (*(_DWORD *)(this + 542) & 0x80000) == 0 )
          *(_DWORD *)(this + 542) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v40 = v4[1];
        v29 = (int *)(this + 218);
        i = this + 218;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v4, v29);
          if ( VarInt )
            return VarInt;
          v30 = v4[1];
          if ( v30 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v30 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v28;
            v29 = (int *)(i + 4);
            i += 4;
            if ( v28 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0xC8u:
        if ( (*(_DWORD *)(this + 542) & 0x100000) == 0 )
          *(_DWORD *)(this + 542) |= 0x100000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 246));
        goto LABEL_404;
      case 0xCCu:
        if ( (*(_DWORD *)(this + 542) & 0x200000) == 0 )
          *(_DWORD *)(this + 542) |= 0x200000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 250));
        goto LABEL_404;
      case 0xCDu:
        if ( (*(_DWORD *)(this + 542) & 0x400000) == 0 )
          *(_DWORD *)(this + 542) |= 0x400000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 254));
        goto LABEL_404;
      case 0xCEu:
        if ( (*(_DWORD *)(this + 542) & 0x800000) == 0 )
          *(_DWORD *)(this + 542) |= 0x800000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 258));
        goto LABEL_404;
      case 0xCFu:
        if ( (*(_DWORD *)(this + 542) & 0x1000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x1000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 262));
        goto LABEL_404;
      case 0xD0u:
        if ( (*(_DWORD *)(this + 542) & 0x2000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x2000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 266));
        goto LABEL_404;
      case 0xD1u:
        if ( (*(_DWORD *)(this + 542) & 0x4000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x4000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 270));
        goto LABEL_404;
      case 0xDCu:
        if ( (*(_DWORD *)(this + 542) & 0x8000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x8000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 274));
        goto LABEL_404;
      case 0xDDu:
        if ( (*(_DWORD *)(this + 542) & 0x10000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x10000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 278));
        goto LABEL_404;
      case 0xDFu:
        if ( (*(_DWORD *)(this + 542) & 0x20000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x20000000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 282));
        goto LABEL_404;
      case 0xE3u:
        if ( (*(_DWORD *)(this + 542) & 0x40000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x40000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 286));
        goto LABEL_404;
      case 0xE4u:
        if ( *(int *)(this + 542) >= 0 )
          *(_DWORD *)(this + 542) |= 0x80000000;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 288));
        goto LABEL_404;
      case 0xE5u:
        if ( (*(_BYTE *)(this + 546) & 1) == 0 )
          *(_DWORD *)(this + 546) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 290));
        goto LABEL_404;
      case 0xE8u:
        if ( (*(_DWORD *)(this + 546) & 2) == 0 )
          *(_DWORD *)(this + 546) |= 2u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 292));
        goto LABEL_404;
      case 0xEDu:
        if ( (*(_DWORD *)(this + 546) & 4) == 0 )
          *(_DWORD *)(this + 546) |= 4u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 296));
        goto LABEL_404;
      case 0xEFu:
        if ( (*(_DWORD *)(this + 546) & 8) == 0 )
          *(_DWORD *)(this + 546) |= 8u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 300));
        goto LABEL_404;
      case 0xF4u:
        if ( (*(_DWORD *)(this + 546) & 0x10) == 0 )
          *(_DWORD *)(this + 546) |= 0x10u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 304));
        goto LABEL_404;
      case 0xF5u:
        if ( (*(_DWORD *)(this + 546) & 0x20) == 0 )
          *(_DWORD *)(this + 546) |= 0x20u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 308));
        goto LABEL_404;
      case 0xFCu:
        if ( (*(_DWORD *)(this + 546) & 0x40) == 0 )
          *(_DWORD *)(this + 546) |= 0x40u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 310));
        goto LABEL_404;
      case 0xFDu:
        if ( (*(_DWORD *)(this + 546) & 0x80) == 0 )
          *(_DWORD *)(this + 546) |= 0x80u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 312));
        goto LABEL_404;
      case 0xFEu:
        if ( (*(_DWORD *)(this + 546) & 0x100) == 0 )
          *(_DWORD *)(this + 546) |= 0x100u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 314));
        goto LABEL_404;
      case 0xFFu:
        if ( (*(_DWORD *)(this + 546) & 0x200) == 0 )
          *(_DWORD *)(this + 546) |= 0x200u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 316));
        goto LABEL_404;
      case 0x100u:
        if ( (*(_DWORD *)(this + 546) & 0x400) == 0 )
          *(_DWORD *)(this + 546) |= 0x400u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 318));
        goto LABEL_404;
      case 0x101u:
        if ( (*(_DWORD *)(this + 546) & 0x800) == 0 )
          *(_DWORD *)(this + 546) |= 0x800u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 320));
        goto LABEL_404;
      case 0x102u:
        if ( (*(_DWORD *)(this + 546) & 0x1000) == 0 )
          *(_DWORD *)(this + 546) |= 0x1000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 322));
        goto LABEL_404;
      case 0x103u:
        if ( (*(_DWORD *)(this + 546) & 0x2000) == 0 )
          *(_DWORD *)(this + 546) |= 0x2000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 324));
        goto LABEL_404;
      case 0x104u:
        if ( (*(_DWORD *)(this + 546) & 0x4000) == 0 )
          *(_DWORD *)(this + 546) |= 0x4000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 326));
        goto LABEL_404;
      case 0x105u:
        if ( (*(_DWORD *)(this + 546) & 0x8000) == 0 )
          *(_DWORD *)(this + 546) |= 0x8000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 328));
        goto LABEL_404;
      case 0x106u:
        if ( (*(_DWORD *)(this + 546) & 0x10000) == 0 )
          *(_DWORD *)(this + 546) |= 0x10000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 330));
        goto LABEL_404;
      case 0x107u:
        if ( (*(_DWORD *)(this + 546) & 0x20000) == 0 )
          *(_DWORD *)(this + 546) |= 0x20000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 332));
        goto LABEL_404;
      case 0x108u:
        if ( (*(_DWORD *)(this + 546) & 0x40000) == 0 )
          *(_DWORD *)(this + 546) |= 0x40000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 334));
        goto LABEL_404;
      case 0x109u:
        if ( (*(_DWORD *)(this + 546) & 0x80000) == 0 )
          *(_DWORD *)(this + 546) |= 0x80000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 336));
        goto LABEL_404;
      case 0x10Au:
        if ( (*(_DWORD *)(this + 546) & 0x100000) == 0 )
          *(_DWORD *)(this + 546) |= 0x100000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 338));
        goto LABEL_404;
      case 0x10Bu:
        if ( (*(_DWORD *)(this + 546) & 0x200000) == 0 )
          *(_DWORD *)(this + 546) |= 0x200000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 340));
        goto LABEL_404;
      case 0x10Cu:
        if ( (*(_DWORD *)(this + 546) & 0x400000) == 0 )
          *(_DWORD *)(this + 546) |= 0x400000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 342));
        goto LABEL_404;
      case 0x10Du:
        if ( (*(_DWORD *)(this + 546) & 0x800000) == 0 )
          *(_DWORD *)(this + 546) |= 0x800000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 344));
        goto LABEL_404;
      case 0x10Eu:
        if ( (*(_DWORD *)(this + 546) & 0x1000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x1000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 346));
        goto LABEL_404;
      case 0x10Fu:
        if ( (*(_DWORD *)(this + 546) & 0x2000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x2000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 348));
        goto LABEL_404;
      case 0x110u:
        if ( (*(_DWORD *)(this + 546) & 0x4000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x4000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 350));
        goto LABEL_404;
      case 0x111u:
        if ( (*(_DWORD *)(this + 546) & 0x8000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x8000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 352));
        goto LABEL_404;
      case 0x112u:
        if ( (*(_DWORD *)(this + 546) & 0x10000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x10000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 354));
        goto LABEL_404;
      case 0x113u:
        if ( (*(_DWORD *)(this + 546) & 0x20000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x20000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 356));
        goto LABEL_404;
      case 0x114u:
        if ( (*(_DWORD *)(this + 546) & 0x40000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x40000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 358));
        goto LABEL_404;
      case 0x11Cu:
        if ( *(int *)(this + 546) >= 0 )
          *(_DWORD *)(this + 546) |= 0x80000000;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 360));
        goto LABEL_404;
      case 0x125u:
        if ( (*(_BYTE *)(this + 550) & 1) == 0 )
          *(_DWORD *)(this + 550) |= 1u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 362));
        goto LABEL_404;
      case 0x126u:
        if ( (*(_DWORD *)(this + 550) & 2) == 0 )
          *(_DWORD *)(this + 550) |= 2u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 366));
        goto LABEL_404;
      case 0x12Cu:
        if ( (*(_DWORD *)(this + 550) & 4) == 0 )
          *(_DWORD *)(this + 550) |= 4u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 370));
        goto LABEL_404;
      case 0x133u:
        if ( (*(_DWORD *)(this + 550) & 8) == 0 )
          *(_DWORD *)(this + 550) |= 8u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 372));
        goto LABEL_404;
      case 0x134u:
        if ( (*(_DWORD *)(this + 550) & 0x10) == 0 )
          *(_DWORD *)(this + 550) |= 0x10u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 374));
        goto LABEL_404;
      case 0x135u:
        if ( (*(_DWORD *)(this + 550) & 0x20) == 0 )
          *(_DWORD *)(this + 550) |= 0x20u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 376));
        goto LABEL_404;
      case 0x136u:
        if ( (*(_DWORD *)(this + 550) & 0x40) == 0 )
          *(_DWORD *)(this + 550) |= 0x40u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 378));
        goto LABEL_404;
      case 0x137u:
        if ( (*(_DWORD *)(this + 550) & 0x80) == 0 )
          *(_DWORD *)(this + 550) |= 0x80u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 380));
        goto LABEL_404;
      case 0x142u:
        if ( (*(_DWORD *)(this + 550) & 0x100) == 0 )
          *(_DWORD *)(this + 550) |= 0x100u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 382));
        goto LABEL_404;
      case 0x143u:
        if ( (*(_DWORD *)(this + 550) & 0x200) == 0 )
          *(_DWORD *)(this + 550) |= 0x200u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 386));
        goto LABEL_404;
      case 0x148u:
        if ( (*(_DWORD *)(this + 550) & 0x400) == 0 )
          *(_DWORD *)(this + 550) |= 0x400u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 390));
        goto LABEL_404;
      case 0x149u:
        if ( (*(_DWORD *)(this + 550) & 0x800) == 0 )
          *(_DWORD *)(this + 550) |= 0x800u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 392));
        goto LABEL_404;
      case 0x14Au:
        if ( (*(_DWORD *)(this + 550) & 0x1000) == 0 )
          *(_DWORD *)(this + 550) |= 0x1000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 394));
        goto LABEL_404;
      case 0x14Bu:
        if ( (*(_DWORD *)(this + 550) & 0x2000) == 0 )
          *(_DWORD *)(this + 550) |= 0x2000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 396));
        goto LABEL_404;
      case 0x14Cu:
        if ( (*(_DWORD *)(this + 550) & 0x4000) == 0 )
          *(_DWORD *)(this + 550) |= 0x4000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 398));
        goto LABEL_404;
      case 0x14Du:
        if ( (*(_DWORD *)(this + 550) & 0x8000) == 0 )
          *(_DWORD *)(this + 550) |= 0x8000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 400));
        goto LABEL_404;
      case 0x14Eu:
        if ( (*(_DWORD *)(this + 550) & 0x10000) == 0 )
          *(_DWORD *)(this + 550) |= 0x10000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 402));
        goto LABEL_404;
      case 0x14Fu:
        if ( (*(_DWORD *)(this + 550) & 0x20000) == 0 )
          *(_DWORD *)(this + 550) |= 0x20000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 404));
        goto LABEL_404;
      case 0x150u:
        if ( (*(_DWORD *)(this + 550) & 0x40000) == 0 )
          *(_DWORD *)(this + 550) |= 0x40000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 406));
        goto LABEL_404;
      case 0x151u:
        if ( (*(_DWORD *)(this + 550) & 0x80000) == 0 )
          *(_DWORD *)(this + 550) |= 0x80000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 408));
        goto LABEL_404;
      case 0x152u:
        if ( (*(_DWORD *)(this + 550) & 0x100000) == 0 )
          *(_DWORD *)(this + 550) |= 0x100000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 410));
        goto LABEL_404;
      case 0x153u:
        if ( (*(_DWORD *)(this + 550) & 0x200000) == 0 )
          *(_DWORD *)(this + 550) |= 0x200000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 412));
        goto LABEL_404;
      case 0x154u:
        if ( (*(_DWORD *)(this + 550) & 0x400000) == 0 )
          *(_DWORD *)(this + 550) |= 0x400000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 414));
        goto LABEL_404;
      case 0x155u:
        if ( (*(_DWORD *)(this + 550) & 0x800000) == 0 )
          *(_DWORD *)(this + 550) |= 0x800000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 416));
        goto LABEL_404;
      case 0x156u:
        if ( (*(_DWORD *)(this + 550) & 0x1000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x1000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 418));
        goto LABEL_404;
      case 0x157u:
        if ( (*(_DWORD *)(this + 550) & 0x2000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x2000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 420));
        goto LABEL_404;
      case 0x158u:
        if ( (*(_DWORD *)(this + 550) & 0x4000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x4000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 422));
        goto LABEL_404;
      case 0x159u:
        if ( (*(_DWORD *)(this + 550) & 0x8000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x8000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 424));
        goto LABEL_404;
      case 0x15Au:
        if ( (*(_DWORD *)(this + 550) & 0x10000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x10000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 426));
        goto LABEL_404;
      case 0x15Bu:
        if ( (*(_DWORD *)(this + 550) & 0x20000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x20000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 428));
        goto LABEL_404;
      case 0x15Cu:
        if ( (*(_DWORD *)(this + 550) & 0x40000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x40000000u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 430));
        goto LABEL_404;
      case 0x15Du:
        if ( *(int *)(this + 550) >= 0 )
          *(_DWORD *)(this + 550) |= 0x80000000;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 432));
        goto LABEL_404;
      case 0x15Eu:
        if ( (*(_BYTE *)(this + 554) & 1) == 0 )
          *(_DWORD *)(this + 554) |= 1u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 434));
        goto LABEL_404;
      case 0x160u:
        if ( (*(_DWORD *)(this + 554) & 2) == 0 )
          *(_DWORD *)(this + 554) |= 2u;
        VarShort = TdrBuf::ReadVarShort(v4, (_WORD *)(this + 436));
        goto LABEL_404;
      case 0x167u:
        if ( (*(_DWORD *)(this + 554) & 4) == 0 )
          *(_DWORD *)(this + 554) |= 4u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 438));
        goto LABEL_404;
      case 0x168u:
        if ( (*(_DWORD *)(this + 554) & 8) == 0 )
          *(_DWORD *)(this + 554) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v31 = (_DWORD *)(this + 442);
        v40 = v4[1];
        i = 0;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v4, &v39);
          if ( VarInt )
            return VarInt;
          v32 = (char *)a2 + v40;
          *v31 = v39;
          v33 = (char *)v4[1];
          if ( v33 > v32 )
            return -34;
          if ( v33 != v32 )
          {
            ++v31;
            if ( ++i < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x169u:
        if ( (*(_DWORD *)(this + 554) & 0x10) == 0 )
          *(_DWORD *)(this + 554) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v34 = (_DWORD *)(this + 470);
        v40 = v4[1];
        for ( i = 0; i < 7; ++i )
        {
          VarInt = TdrBuf::ReadInt32(v4, &v38);
          if ( VarInt )
            return VarInt;
          v35 = (char *)a2 + v40;
          *v34 = v38;
          v36 = (char *)v4[1];
          if ( v36 > v35 )
            return -34;
          if ( v36 == v35 )
            break;
          ++v34;
        }
LABEL_405:
        v7 = v37;
        if ( v4[1] < v37 )
          continue;
LABEL_406:
        if ( v4[1] > v7 )
          return -34;
        return VarInt;
      case 0x16Bu:
        if ( (*(_DWORD *)(this + 554) & 0x20) == 0 )
          *(_DWORD *)(this + 554) |= 0x20u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 498));
        goto LABEL_404;
      case 0x172u:
        if ( (*(_DWORD *)(this + 554) & 0x40) == 0 )
          *(_DWORD *)(this + 554) |= 0x40u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 502));
        goto LABEL_404;
      case 0x179u:
        if ( (*(_DWORD *)(this + 554) & 0x80) == 0 )
          *(_DWORD *)(this + 554) |= 0x80u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 506));
        goto LABEL_404;
      case 0x17Au:
        if ( (*(_DWORD *)(this + 554) & 0x100) == 0 )
          *(_DWORD *)(this + 554) |= 0x100u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 510));
        goto LABEL_404;
      case 0x17Fu:
        if ( (*(_DWORD *)(this + 554) & 0x200) == 0 )
          *(_DWORD *)(this + 554) |= 0x200u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 514));
        goto LABEL_404;
      case 0x181u:
        if ( (*(_DWORD *)(this + 554) & 0x400) == 0 )
          *(_DWORD *)(this + 554) |= 0x400u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 518));
        goto LABEL_404;
      case 0x182u:
        if ( (*(_DWORD *)(this + 554) & 0x800) == 0 )
          *(_DWORD *)(this + 554) |= 0x800u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 522));
        goto LABEL_404;
      case 0x183u:
        if ( (*(_DWORD *)(this + 554) & 0x1000) == 0 )
          *(_DWORD *)(this + 554) |= 0x1000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 526));
        goto LABEL_404;
      case 0x192u:
        if ( (*(_DWORD *)(this + 554) & 0x2000) == 0 )
          *(_DWORD *)(this + 554) |= 0x2000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 530));
        goto LABEL_404;
      case 0x193u:
        if ( (*(_DWORD *)(this + 554) & 0x4000) == 0 )
          *(_DWORD *)(this + 554) |= 0x4000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 534));
        goto LABEL_404;
      case 0x195u:
        if ( (*(_DWORD *)(this + 554) & 0x8000) == 0 )
          *(_DWORD *)(this + 554) |= 0x8000u;
        VarShort = TdrBuf::ReadVarInt(v4, (int *)(this + 538));
        goto LABEL_404;
      default:
        VarShort = TdrBuf::SkipField(v4, v41 & 0xF);
LABEL_404:
        VarInt = VarShort;
        if ( !VarShort )
          goto LABEL_405;
        return VarInt;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0194::Read_0x99
// Address Name: SUB_101DACC0
// ============================================================
//----- (101DACC0) --------------------------------------------------------
int __thiscall sub_101DACC0(unsigned int this, _DWORD *a2, unsigned int i)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Int32; // edx
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // ebx
  _BYTE *v10; // eax
  unsigned int v11; // eax
  int Int16; // eax
  unsigned int v13; // ebx
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // ebx
  _BYTE *v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // ebx
  _BYTE *v20; // eax
  unsigned int v21; // ecx
  unsigned int v22; // ebx
  _BYTE *v23; // eax
  unsigned int v24; // ecx
  unsigned int v25; // ebx
  _BYTE *v26; // eax
  unsigned int v27; // ecx
  unsigned int v28; // ebx
  _BYTE *v29; // eax
  unsigned int v30; // ecx
  _DWORD *v31; // ebx
  char *v32; // eax
  char *v33; // ecx
  _DWORD *v34; // ebx
  char *v35; // eax
  char *v36; // ecx
  unsigned int v37; // [esp+0h] [ebp-14h]
  int v38; // [esp+4h] [ebp-10h] BYREF
  int v39; // [esp+8h] [ebp-Ch] BYREF
  int v40; // [esp+Ch] [ebp-8h]
  unsigned int v41; // [esp+10h] [ebp-4h] BYREF

  v3 = i;
  v4 = a2;
  Int32 = 0;
  v41 = 0;
  *(_OWORD *)(this + 542) = 0;
  v7 = v4[1] + v3;
  v37 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_406;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v41);
    if ( result )
      return result;
    switch ( v41 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 542) & 1) == 0 )
          *(_DWORD *)(this + 542) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( !a2 )
            return -37;
          v9 = 0;
          v40 = v4[1];
          v10 = (_BYTE *)this;
          i = this;
          while ( 1 )
          {
            Int32 = TdrBuf::ReadInt32(v4, v10);
            if ( Int32 )
              return Int32;
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v40 )
              return -34;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v40) )
            {
              ++v9;
              v10 = (_BYTE *)(i + 4);
              i += 4;
              if ( v9 < 7 )
                continue;
            }
            goto LABEL_405;
          }
        }
        return result;
      case 4u:
        if ( (*(_DWORD *)(this + 542) & 2) == 0 )
          *(_DWORD *)(this + 542) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 28));
        goto LABEL_404;
      case 6u:
        if ( (*(_DWORD *)(this + 542) & 4) == 0 )
          *(_DWORD *)(this + 542) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 32));
        goto LABEL_404;
      case 7u:
        if ( (*(_DWORD *)(this + 542) & 8) == 0 )
          *(_DWORD *)(this + 542) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 36));
        goto LABEL_404;
      case 0x10u:
        if ( (*(_DWORD *)(this + 542) & 0x10) == 0 )
          *(_DWORD *)(this + 542) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 40));
        goto LABEL_404;
      case 0x11u:
        if ( (*(_DWORD *)(this + 542) & 0x20) == 0 )
          *(_DWORD *)(this + 542) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v40 = v4[1];
        v14 = (_BYTE *)(this + 44);
        i = this + 44;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v14);
          if ( Int32 )
            return Int32;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v13;
            v14 = (_BYTE *)(i + 4);
            i += 4;
            if ( v13 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x13u:
        if ( (*(_DWORD *)(this + 542) & 0x40) == 0 )
          *(_DWORD *)(this + 542) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v40 = v4[1];
        v17 = (_BYTE *)(this + 72);
        i = this + 72;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v17);
          if ( Int32 )
            return Int32;
          v18 = v4[1];
          if ( v18 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v18 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v16;
            v17 = (_BYTE *)(i + 4);
            i += 4;
            if ( v16 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x14u:
        if ( (*(_DWORD *)(this + 542) & 0x80) == 0 )
          *(_DWORD *)(this + 542) |= 0x80u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 100));
        goto LABEL_404;
      case 0x24u:
        if ( (*(_DWORD *)(this + 542) & 0x100) == 0 )
          *(_DWORD *)(this + 542) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 102));
        goto LABEL_404;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 542) & 0x200) == 0 )
          *(_DWORD *)(this + 542) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v19 = 0;
        v40 = v4[1];
        v20 = (_BYTE *)(this + 106);
        i = this + 106;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v20);
          if ( Int32 )
            return Int32;
          v21 = v4[1];
          if ( v21 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v21 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v19;
            v20 = (_BYTE *)(i + 4);
            i += 4;
            if ( v19 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x6Cu:
        if ( (*(_DWORD *)(this + 542) & 0x400) == 0 )
          *(_DWORD *)(this + 542) |= 0x400u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 134));
        goto LABEL_404;
      case 0x6Du:
        if ( (*(_DWORD *)(this + 542) & 0x800) == 0 )
          *(_DWORD *)(this + 542) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 138));
        goto LABEL_404;
      case 0x74u:
        if ( (*(_DWORD *)(this + 542) & 0x1000) == 0 )
          *(_DWORD *)(this + 542) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 142));
        goto LABEL_404;
      case 0x7Au:
        if ( (*(_DWORD *)(this + 542) & 0x2000) == 0 )
          *(_DWORD *)(this + 542) |= 0x2000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 146));
        goto LABEL_404;
      case 0x80u:
        if ( (*(_DWORD *)(this + 542) & 0x4000) == 0 )
          *(_DWORD *)(this + 542) |= 0x4000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 150));
        goto LABEL_404;
      case 0x88u:
        if ( (*(_DWORD *)(this + 542) & 0x8000) == 0 )
          *(_DWORD *)(this + 542) |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v40 = v4[1];
        v23 = (_BYTE *)(this + 154);
        i = this + 154;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v23);
          if ( Int32 )
            return Int32;
          v24 = v4[1];
          if ( v24 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v24 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v22;
            v23 = (_BYTE *)(i + 4);
            i += 4;
            if ( v22 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x89u:
        if ( (*(_DWORD *)(this + 542) & 0x10000) == 0 )
          *(_DWORD *)(this + 542) |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v25 = 0;
        v40 = v4[1];
        v26 = (_BYTE *)(this + 182);
        i = this + 182;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v26);
          if ( Int32 )
            return Int32;
          v27 = v4[1];
          if ( v27 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v27 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v25;
            v26 = (_BYTE *)(i + 4);
            i += 4;
            if ( v25 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x96u:
        if ( (*(_DWORD *)(this + 542) & 0x20000) == 0 )
          *(_DWORD *)(this + 542) |= 0x20000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 210));
        goto LABEL_404;
      case 0xADu:
        if ( (*(_DWORD *)(this + 542) & 0x40000) == 0 )
          *(_DWORD *)(this + 542) |= 0x40000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 214));
        goto LABEL_404;
      case 0xB0u:
        if ( (*(_DWORD *)(this + 542) & 0x80000) == 0 )
          *(_DWORD *)(this + 542) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v40 = v4[1];
        v29 = (_BYTE *)(this + 218);
        i = this + 218;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v29);
          if ( Int32 )
            return Int32;
          v30 = v4[1];
          if ( v30 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v30 != (_DWORD *)((char *)a2 + v40) )
          {
            ++v28;
            v29 = (_BYTE *)(i + 4);
            i += 4;
            if ( v28 < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0xC8u:
        if ( (*(_DWORD *)(this + 542) & 0x100000) == 0 )
          *(_DWORD *)(this + 542) |= 0x100000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 246));
        goto LABEL_404;
      case 0xCCu:
        if ( (*(_DWORD *)(this + 542) & 0x200000) == 0 )
          *(_DWORD *)(this + 542) |= 0x200000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 250));
        goto LABEL_404;
      case 0xCDu:
        if ( (*(_DWORD *)(this + 542) & 0x400000) == 0 )
          *(_DWORD *)(this + 542) |= 0x400000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 254));
        goto LABEL_404;
      case 0xCEu:
        if ( (*(_DWORD *)(this + 542) & 0x800000) == 0 )
          *(_DWORD *)(this + 542) |= 0x800000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 258));
        goto LABEL_404;
      case 0xCFu:
        if ( (*(_DWORD *)(this + 542) & 0x1000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 262));
        goto LABEL_404;
      case 0xD0u:
        if ( (*(_DWORD *)(this + 542) & 0x2000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 266));
        goto LABEL_404;
      case 0xD1u:
        if ( (*(_DWORD *)(this + 542) & 0x4000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 270));
        goto LABEL_404;
      case 0xDCu:
        if ( (*(_DWORD *)(this + 542) & 0x8000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 274));
        goto LABEL_404;
      case 0xDDu:
        if ( (*(_DWORD *)(this + 542) & 0x10000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x10000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 278));
        goto LABEL_404;
      case 0xDFu:
        if ( (*(_DWORD *)(this + 542) & 0x20000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 282));
        goto LABEL_404;
      case 0xE3u:
        if ( (*(_DWORD *)(this + 542) & 0x40000000) == 0 )
          *(_DWORD *)(this + 542) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 286));
        goto LABEL_404;
      case 0xE4u:
        if ( *(int *)(this + 542) >= 0 )
          *(_DWORD *)(this + 542) |= 0x80000000;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 288));
        goto LABEL_404;
      case 0xE5u:
        if ( (*(_BYTE *)(this + 546) & 1) == 0 )
          *(_DWORD *)(this + 546) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 290));
        goto LABEL_404;
      case 0xE8u:
        if ( (*(_DWORD *)(this + 546) & 2) == 0 )
          *(_DWORD *)(this + 546) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 292));
        goto LABEL_404;
      case 0xEDu:
        if ( (*(_DWORD *)(this + 546) & 4) == 0 )
          *(_DWORD *)(this + 546) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 296));
        goto LABEL_404;
      case 0xEFu:
        if ( (*(_DWORD *)(this + 546) & 8) == 0 )
          *(_DWORD *)(this + 546) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 300));
        goto LABEL_404;
      case 0xF4u:
        if ( (*(_DWORD *)(this + 546) & 0x10) == 0 )
          *(_DWORD *)(this + 546) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 304));
        goto LABEL_404;
      case 0xF5u:
        if ( (*(_DWORD *)(this + 546) & 0x20) == 0 )
          *(_DWORD *)(this + 546) |= 0x20u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 308));
        goto LABEL_404;
      case 0xFCu:
        if ( (*(_DWORD *)(this + 546) & 0x40) == 0 )
          *(_DWORD *)(this + 546) |= 0x40u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 310));
        goto LABEL_404;
      case 0xFDu:
        if ( (*(_DWORD *)(this + 546) & 0x80) == 0 )
          *(_DWORD *)(this + 546) |= 0x80u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 312));
        goto LABEL_404;
      case 0xFEu:
        if ( (*(_DWORD *)(this + 546) & 0x100) == 0 )
          *(_DWORD *)(this + 546) |= 0x100u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 314));
        goto LABEL_404;
      case 0xFFu:
        if ( (*(_DWORD *)(this + 546) & 0x200) == 0 )
          *(_DWORD *)(this + 546) |= 0x200u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 316));
        goto LABEL_404;
      case 0x100u:
        if ( (*(_DWORD *)(this + 546) & 0x400) == 0 )
          *(_DWORD *)(this + 546) |= 0x400u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 318));
        goto LABEL_404;
      case 0x101u:
        if ( (*(_DWORD *)(this + 546) & 0x800) == 0 )
          *(_DWORD *)(this + 546) |= 0x800u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 320));
        goto LABEL_404;
      case 0x102u:
        if ( (*(_DWORD *)(this + 546) & 0x1000) == 0 )
          *(_DWORD *)(this + 546) |= 0x1000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 322));
        goto LABEL_404;
      case 0x103u:
        if ( (*(_DWORD *)(this + 546) & 0x2000) == 0 )
          *(_DWORD *)(this + 546) |= 0x2000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 324));
        goto LABEL_404;
      case 0x104u:
        if ( (*(_DWORD *)(this + 546) & 0x4000) == 0 )
          *(_DWORD *)(this + 546) |= 0x4000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 326));
        goto LABEL_404;
      case 0x105u:
        if ( (*(_DWORD *)(this + 546) & 0x8000) == 0 )
          *(_DWORD *)(this + 546) |= 0x8000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 328));
        goto LABEL_404;
      case 0x106u:
        if ( (*(_DWORD *)(this + 546) & 0x10000) == 0 )
          *(_DWORD *)(this + 546) |= 0x10000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 330));
        goto LABEL_404;
      case 0x107u:
        if ( (*(_DWORD *)(this + 546) & 0x20000) == 0 )
          *(_DWORD *)(this + 546) |= 0x20000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 332));
        goto LABEL_404;
      case 0x108u:
        if ( (*(_DWORD *)(this + 546) & 0x40000) == 0 )
          *(_DWORD *)(this + 546) |= 0x40000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 334));
        goto LABEL_404;
      case 0x109u:
        if ( (*(_DWORD *)(this + 546) & 0x80000) == 0 )
          *(_DWORD *)(this + 546) |= 0x80000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 336));
        goto LABEL_404;
      case 0x10Au:
        if ( (*(_DWORD *)(this + 546) & 0x100000) == 0 )
          *(_DWORD *)(this + 546) |= 0x100000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 338));
        goto LABEL_404;
      case 0x10Bu:
        if ( (*(_DWORD *)(this + 546) & 0x200000) == 0 )
          *(_DWORD *)(this + 546) |= 0x200000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 340));
        goto LABEL_404;
      case 0x10Cu:
        if ( (*(_DWORD *)(this + 546) & 0x400000) == 0 )
          *(_DWORD *)(this + 546) |= 0x400000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 342));
        goto LABEL_404;
      case 0x10Du:
        if ( (*(_DWORD *)(this + 546) & 0x800000) == 0 )
          *(_DWORD *)(this + 546) |= 0x800000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 344));
        goto LABEL_404;
      case 0x10Eu:
        if ( (*(_DWORD *)(this + 546) & 0x1000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 346));
        goto LABEL_404;
      case 0x10Fu:
        if ( (*(_DWORD *)(this + 546) & 0x2000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 348));
        goto LABEL_404;
      case 0x110u:
        if ( (*(_DWORD *)(this + 546) & 0x4000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 350));
        goto LABEL_404;
      case 0x111u:
        if ( (*(_DWORD *)(this + 546) & 0x8000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 352));
        goto LABEL_404;
      case 0x112u:
        if ( (*(_DWORD *)(this + 546) & 0x10000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x10000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 354));
        goto LABEL_404;
      case 0x113u:
        if ( (*(_DWORD *)(this + 546) & 0x20000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 356));
        goto LABEL_404;
      case 0x114u:
        if ( (*(_DWORD *)(this + 546) & 0x40000000) == 0 )
          *(_DWORD *)(this + 546) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 358));
        goto LABEL_404;
      case 0x11Cu:
        if ( *(int *)(this + 546) >= 0 )
          *(_DWORD *)(this + 546) |= 0x80000000;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 360));
        goto LABEL_404;
      case 0x125u:
        if ( (*(_BYTE *)(this + 550) & 1) == 0 )
          *(_DWORD *)(this + 550) |= 1u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 362));
        goto LABEL_404;
      case 0x126u:
        if ( (*(_DWORD *)(this + 550) & 2) == 0 )
          *(_DWORD *)(this + 550) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 366));
        goto LABEL_404;
      case 0x12Cu:
        if ( (*(_DWORD *)(this + 550) & 4) == 0 )
          *(_DWORD *)(this + 550) |= 4u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 370));
        goto LABEL_404;
      case 0x133u:
        if ( (*(_DWORD *)(this + 550) & 8) == 0 )
          *(_DWORD *)(this + 550) |= 8u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 372));
        goto LABEL_404;
      case 0x134u:
        if ( (*(_DWORD *)(this + 550) & 0x10) == 0 )
          *(_DWORD *)(this + 550) |= 0x10u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 374));
        goto LABEL_404;
      case 0x135u:
        if ( (*(_DWORD *)(this + 550) & 0x20) == 0 )
          *(_DWORD *)(this + 550) |= 0x20u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 376));
        goto LABEL_404;
      case 0x136u:
        if ( (*(_DWORD *)(this + 550) & 0x40) == 0 )
          *(_DWORD *)(this + 550) |= 0x40u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 378));
        goto LABEL_404;
      case 0x137u:
        if ( (*(_DWORD *)(this + 550) & 0x80) == 0 )
          *(_DWORD *)(this + 550) |= 0x80u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 380));
        goto LABEL_404;
      case 0x142u:
        if ( (*(_DWORD *)(this + 550) & 0x100) == 0 )
          *(_DWORD *)(this + 550) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 382));
        goto LABEL_404;
      case 0x143u:
        if ( (*(_DWORD *)(this + 550) & 0x200) == 0 )
          *(_DWORD *)(this + 550) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 386));
        goto LABEL_404;
      case 0x148u:
        if ( (*(_DWORD *)(this + 550) & 0x400) == 0 )
          *(_DWORD *)(this + 550) |= 0x400u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 390));
        goto LABEL_404;
      case 0x149u:
        if ( (*(_DWORD *)(this + 550) & 0x800) == 0 )
          *(_DWORD *)(this + 550) |= 0x800u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 392));
        goto LABEL_404;
      case 0x14Au:
        if ( (*(_DWORD *)(this + 550) & 0x1000) == 0 )
          *(_DWORD *)(this + 550) |= 0x1000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 394));
        goto LABEL_404;
      case 0x14Bu:
        if ( (*(_DWORD *)(this + 550) & 0x2000) == 0 )
          *(_DWORD *)(this + 550) |= 0x2000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 396));
        goto LABEL_404;
      case 0x14Cu:
        if ( (*(_DWORD *)(this + 550) & 0x4000) == 0 )
          *(_DWORD *)(this + 550) |= 0x4000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 398));
        goto LABEL_404;
      case 0x14Du:
        if ( (*(_DWORD *)(this + 550) & 0x8000) == 0 )
          *(_DWORD *)(this + 550) |= 0x8000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 400));
        goto LABEL_404;
      case 0x14Eu:
        if ( (*(_DWORD *)(this + 550) & 0x10000) == 0 )
          *(_DWORD *)(this + 550) |= 0x10000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 402));
        goto LABEL_404;
      case 0x14Fu:
        if ( (*(_DWORD *)(this + 550) & 0x20000) == 0 )
          *(_DWORD *)(this + 550) |= 0x20000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 404));
        goto LABEL_404;
      case 0x150u:
        if ( (*(_DWORD *)(this + 550) & 0x40000) == 0 )
          *(_DWORD *)(this + 550) |= 0x40000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 406));
        goto LABEL_404;
      case 0x151u:
        if ( (*(_DWORD *)(this + 550) & 0x80000) == 0 )
          *(_DWORD *)(this + 550) |= 0x80000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 408));
        goto LABEL_404;
      case 0x152u:
        if ( (*(_DWORD *)(this + 550) & 0x100000) == 0 )
          *(_DWORD *)(this + 550) |= 0x100000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 410));
        goto LABEL_404;
      case 0x153u:
        if ( (*(_DWORD *)(this + 550) & 0x200000) == 0 )
          *(_DWORD *)(this + 550) |= 0x200000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 412));
        goto LABEL_404;
      case 0x154u:
        if ( (*(_DWORD *)(this + 550) & 0x400000) == 0 )
          *(_DWORD *)(this + 550) |= 0x400000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 414));
        goto LABEL_404;
      case 0x155u:
        if ( (*(_DWORD *)(this + 550) & 0x800000) == 0 )
          *(_DWORD *)(this + 550) |= 0x800000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 416));
        goto LABEL_404;
      case 0x156u:
        if ( (*(_DWORD *)(this + 550) & 0x1000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 418));
        goto LABEL_404;
      case 0x157u:
        if ( (*(_DWORD *)(this + 550) & 0x2000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 420));
        goto LABEL_404;
      case 0x158u:
        if ( (*(_DWORD *)(this + 550) & 0x4000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 422));
        goto LABEL_404;
      case 0x159u:
        if ( (*(_DWORD *)(this + 550) & 0x8000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 424));
        goto LABEL_404;
      case 0x15Au:
        if ( (*(_DWORD *)(this + 550) & 0x10000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x10000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 426));
        goto LABEL_404;
      case 0x15Bu:
        if ( (*(_DWORD *)(this + 550) & 0x20000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 428));
        goto LABEL_404;
      case 0x15Cu:
        if ( (*(_DWORD *)(this + 550) & 0x40000000) == 0 )
          *(_DWORD *)(this + 550) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 430));
        goto LABEL_404;
      case 0x15Du:
        if ( *(int *)(this + 550) >= 0 )
          *(_DWORD *)(this + 550) |= 0x80000000;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 432));
        goto LABEL_404;
      case 0x15Eu:
        if ( (*(_BYTE *)(this + 554) & 1) == 0 )
          *(_DWORD *)(this + 554) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 434));
        goto LABEL_404;
      case 0x160u:
        if ( (*(_DWORD *)(this + 554) & 2) == 0 )
          *(_DWORD *)(this + 554) |= 2u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 436));
        goto LABEL_404;
      case 0x167u:
        if ( (*(_DWORD *)(this + 554) & 4) == 0 )
          *(_DWORD *)(this + 554) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 438));
        goto LABEL_404;
      case 0x168u:
        if ( (*(_DWORD *)(this + 554) & 8) == 0 )
          *(_DWORD *)(this + 554) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v31 = (_DWORD *)(this + 442);
        v40 = v4[1];
        i = 0;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v39);
          if ( Int32 )
            return Int32;
          v32 = (char *)a2 + v40;
          *v31 = v39;
          v33 = (char *)v4[1];
          if ( v33 > v32 )
            return -34;
          if ( v33 != v32 )
          {
            ++v31;
            if ( ++i < 7 )
              continue;
          }
          goto LABEL_405;
        }
      case 0x169u:
        if ( (*(_DWORD *)(this + 554) & 0x10) == 0 )
          *(_DWORD *)(this + 554) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v34 = (_DWORD *)(this + 470);
        v40 = v4[1];
        for ( i = 0; i < 7; ++i )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v38);
          if ( Int32 )
            return Int32;
          v35 = (char *)a2 + v40;
          *v34 = v38;
          v36 = (char *)v4[1];
          if ( v36 > v35 )
            return -34;
          if ( v36 == v35 )
            break;
          ++v34;
        }
LABEL_405:
        v7 = v37;
        if ( v4[1] < v37 )
          continue;
LABEL_406:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      case 0x16Bu:
        if ( (*(_DWORD *)(this + 554) & 0x20) == 0 )
          *(_DWORD *)(this + 554) |= 0x20u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 498));
        goto LABEL_404;
      case 0x172u:
        if ( (*(_DWORD *)(this + 554) & 0x40) == 0 )
          *(_DWORD *)(this + 554) |= 0x40u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 502));
        goto LABEL_404;
      case 0x179u:
        if ( (*(_DWORD *)(this + 554) & 0x80) == 0 )
          *(_DWORD *)(this + 554) |= 0x80u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 506));
        goto LABEL_404;
      case 0x17Au:
        if ( (*(_DWORD *)(this + 554) & 0x100) == 0 )
          *(_DWORD *)(this + 554) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 510));
        goto LABEL_404;
      case 0x17Fu:
        if ( (*(_DWORD *)(this + 554) & 0x200) == 0 )
          *(_DWORD *)(this + 554) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 514));
        goto LABEL_404;
      case 0x181u:
        if ( (*(_DWORD *)(this + 554) & 0x400) == 0 )
          *(_DWORD *)(this + 554) |= 0x400u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 518));
        goto LABEL_404;
      case 0x182u:
        if ( (*(_DWORD *)(this + 554) & 0x800) == 0 )
          *(_DWORD *)(this + 554) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 522));
        goto LABEL_404;
      case 0x183u:
        if ( (*(_DWORD *)(this + 554) & 0x1000) == 0 )
          *(_DWORD *)(this + 554) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 526));
        goto LABEL_404;
      case 0x192u:
        if ( (*(_DWORD *)(this + 554) & 0x2000) == 0 )
          *(_DWORD *)(this + 554) |= 0x2000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 530));
        goto LABEL_404;
      case 0x193u:
        if ( (*(_DWORD *)(this + 554) & 0x4000) == 0 )
          *(_DWORD *)(this + 554) |= 0x4000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 534));
        goto LABEL_404;
      case 0x195u:
        if ( (*(_DWORD *)(this + 554) & 0x8000) == 0 )
          *(_DWORD *)(this + 554) |= 0x8000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 538));
        goto LABEL_404;
      default:
        Int16 = TdrBuf::SkipField(v4, v41 & 0xF);
LABEL_404:
        Int32 = Int16;
        if ( !Int16 )
          goto LABEL_405;
        return Int32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0194::DoDebugFormat
// Address Name: SUB_101DC7F0
// ============================================================
//----- (101DC7F0) --------------------------------------------------------
int __thiscall sub_101DC7F0(void *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101DC8A0((int)this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0194::DebugFormat
// Address Name: SUB_101DC8A0
// ============================================================
//----- (101DC8A0) --------------------------------------------------------
int __thiscall sub_101DC8A0(int this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ebx
  int v8; // ecx
  int v10; // ecx
  _DWORD *v11; // ecx
  int v12; // ecx
  _DWORD *v13; // ecx
  int v14; // ecx
  _DWORD *v15; // ecx
  int v16; // ecx
  _DWORD *v17; // ecx
  int v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ecx
  _DWORD *v21; // ecx
  int v22; // ecx
  float *v23; // ecx
  int v24; // ecx
  float *v25; // ecx
  unsigned int v26; // [esp+1Ch] [ebp+8h]
  unsigned int v27; // [esp+1Ch] [ebp+8h]
  unsigned int v28; // [esp+1Ch] [ebp+8h]
  unsigned int v29; // [esp+1Ch] [ebp+8h]
  unsigned int v30; // [esp+1Ch] [ebp+8h]
  unsigned int v31; // [esp+1Ch] [ebp+8h]
  unsigned int v32; // [esp+1Ch] [ebp+8h]
  int v33; // [esp+1Ch] [ebp+8h]
  int v34; // [esp+24h] [ebp+10h]
  int v35; // [esp+24h] [ebp+10h]
  int v36; // [esp+24h] [ebp+10h]
  int v37; // [esp+24h] [ebp+10h]
  int v38; // [esp+24h] [ebp+10h]
  int v39; // [esp+24h] [ebp+10h]
  int v40; // [esp+24h] [ebp+10h]
  int i; // [esp+24h] [ebp+10h]

  if ( !"[oCharLevel]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[oCharLevel]", 6LL);
    if ( !result )
    {
      v7 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v7));
        if ( result )
          break;
        if ( (unsigned int)++v7 >= 7 )
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
          result = print_field(a2, a3, a4, "[oCharSex]", "%d", *(_DWORD *)(this + 28));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[oCharExp]", "%d", *(_DWORD *)(this + 32));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[oStarLevel]", "%d", *(_DWORD *)(this + 36));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[oCharHP]", "%d", *(_DWORD *)(this + 40));
                if ( !result )
                {
                  result = sub_1024A3B0(a2, a3, v10, "[oCharMaxHP]", 7);
                  if ( !result )
                  {
                    v11 = (_DWORD *)(this + 44);
                    v26 = 0;
                    v34 = this + 44;
                    while ( 1 )
                    {
                      result = Printf(a2, " %d", *v11);
                      if ( result )
                        break;
                      v11 = (_DWORD *)(v34 + 4);
                      ++v26;
                      v34 += 4;
                      if ( v26 >= 7 )
                      {
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( !result )
                        {
                          result = sub_1024A3B0(a2, a3, v12, "[oCharMaxReju]", 7);
                          if ( !result )
                          {
                            v13 = (_DWORD *)(this + 72);
                            v27 = 0;
                            v35 = this + 72;
                            while ( 1 )
                            {
                              result = Printf(a2, " %d", *v13);
                              if ( result )
                                break;
                              v13 = (_DWORD *)(v35 + 4);
                              ++v27;
                              v35 += 4;
                              if ( v27 >= 7 )
                              {
                                result = TdrBuf::WriteChar(a2, a4);
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[oDeath]", "%d", *(__int16 *)(this + 100));
                                  if ( !result )
                                  {
                                    result = print_field(a2, a3, a4, "[oSharpness]", "%d", *(_DWORD *)(this + 102));
                                    if ( !result )
                                    {
                                      result = sub_1024A3B0(a2, a3, v14, "[oCharAnimSpeed]", 7);
                                      if ( !result )
                                      {
                                        v15 = (_DWORD *)(this + 106);
                                        v28 = 0;
                                        v36 = this + 106;
                                        while ( 1 )
                                        {
                                          result = Printf(a2, " %d", *v15);
                                          if ( result )
                                            break;
                                          v15 = (_DWORD *)(v36 + 4);
                                          ++v28;
                                          v36 += 4;
                                          if ( v28 >= 7 )
                                          {
                                            result = TdrBuf::WriteChar(a2, a4);
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[oMaleFace]",
                                                         "%d",
                                                         *(_DWORD *)(this + 134));
                                              if ( !result )
                                              {
                                                result = print_field(
                                                           a2,
                                                           a3,
                                                           a4,
                                                           "[oMaleHair]",
                                                           "%d",
                                                           *(_DWORD *)(this + 138));
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[oQiRenLevel]",
                                                             "%d",
                                                             *(_DWORD *)(this + 142));
                                                  if ( !result )
                                                  {
                                                    result = print_field(
                                                               a2,
                                                               a3,
                                                               a4,
                                                               "[oRejuFlag]",
                                                               "%d",
                                                               *(_DWORD *)(this + 146));
                                                    if ( !result )
                                                    {
                                                      result = print_field(
                                                                 a2,
                                                                 a3,
                                                                 a4,
                                                                 "[oTeamID]",
                                                                 "%d",
                                                                 *(_DWORD *)(this + 150));
                                                      if ( !result )
                                                      {
                                                        result = sub_1024A3B0(a2, a3, v16, "[oPVPDef]", 7);
                                                        if ( !result )
                                                        {
                                                          v17 = (_DWORD *)(this + 154);
                                                          v29 = 0;
                                                          v37 = this + 154;
                                                          while ( 1 )
                                                          {
                                                            result = Printf(a2, " %d", *v17);
                                                            if ( result )
                                                              break;
                                                            v17 = (_DWORD *)(v37 + 4);
                                                            ++v29;
                                                            v37 += 4;
                                                            if ( v29 >= 7 )
                                                            {
                                                              result = TdrBuf::WriteChar(a2, a4);
                                                              if ( !result )
                                                              {
                                                                result = sub_1024A3B0(a2, a3, v18, "[oPVPDefAngle]", 7);
                                                                if ( !result )
                                                                {
                                                                  v19 = (_DWORD *)(this + 182);
                                                                  v30 = 0;
                                                                  v38 = this + 182;
                                                                  while ( 1 )
                                                                  {
                                                                    result = Printf(a2, " %d", *v19);
                                                                    if ( result )
                                                                      break;
                                                                    v19 = (_DWORD *)(v38 + 4);
                                                                    ++v30;
                                                                    v38 += 4;
                                                                    if ( v30 >= 7 )
                                                                    {
                                                                      result = TdrBuf::WriteChar(a2, a4);
                                                                      if ( !result )
                                                                      {
                                                                        result = print_field(
                                                                                   a2,
                                                                                   a3,
                                                                                   a4,
                                                                                   "[oRegion]",
                                                                                   "%d",
                                                                                   *(_DWORD *)(this + 210));
                                                                        if ( !result )
                                                                        {
                                                                          result = print_field(
                                                                                     a2,
                                                                                     a3,
                                                                                     a4,
                                                                                     "[oUnderClothes]",
                                                                                     "%d",
                                                                                     *(_DWORD *)(this + 214));
                                                                          if ( !result )
                                                                          {
                                                                            result = sub_1024A3B0(
                                                                                       a2,
                                                                                       a3,
                                                                                       v20,
                                                                                       "[oCharRejuPer]",
                                                                                       7);
                                                                            if ( !result )
                                                                            {
                                                                              v21 = (_DWORD *)(this + 218);
                                                                              v31 = 0;
                                                                              v39 = this + 218;
                                                                              while ( 1 )
                                                                              {
                                                                                result = Printf(a2, " %d", *v21);
                                                                                if ( result )
                                                                                  break;
                                                                                v21 = (_DWORD *)(v39 + 4);
                                                                                ++v31;
                                                                                v39 += 4;
                                                                                if ( v31 >= 7 )
                                                                                {
                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                  if ( !result )
                                                                                  {
                                                                                    result = print_field(
                                                                                               a2,
                                                                                               a3,
                                                                                               a4,
                                                                                               "[oCharRemainsExp]",
                                                                                               "%d",
                                                                                               *(_DWORD *)(this + 246));
                                                                                    if ( !result )
                                                                                    {
                                                                                      result = print_field(
                                                                                                 a2,
                                                                                                 a3,
                                                                                                 a4,
                                                                                                 "[oLastResetTime]",
                                                                                                 "%d",
                                                                                                 *(_DWORD *)(this + 250));
                                                                                      if ( !result )
                                                                                      {
                                                                                        result = print_field(
                                                                                                   a2,
                                                                                                   a3,
                                                                                                   a4,
                                                                                                   "[oSkinColor]",
                                                                                                   "%d",
                                                                                                   *(_DWORD *)(this + 254));
                                                                                        if ( !result )
                                                                                        {
                                                                                          result = print_field(
                                                                                                     a2,
                                                                                                     a3,
                                                                                                     a4,
                                                                                                     "[oHairColor]",
                                                                                                     "%d",
                                                                                                     *(_DWORD *)(this + 258));
                                                                                          if ( !result )
                                                                                          {
                                                                                            result = print_field(a2, a3, a4, "[oInnerColor]", "%d", *(_DWORD *)(this + 262));
                                                                                            if ( !result )
                                                                                            {
                                                                                              result = print_field(a2, a3, a4, "[oFaceTattooIndex]", "%d", *(_DWORD *)(this + 266));
                                                                                              if ( !result )
                                                                                              {
                                                                                                result = print_field(a2, a3, a4, "[oEyeBall]", "%d", *(_DWORD *)(this + 270));
                                                                                                if ( !result )
                                                                                                {
                                                                                                  result = print_field(a2, a3, a4, "[oFaceTattooColor]", "%d", *(_DWORD *)(this + 274));
                                                                                                  if ( !result )
                                                                                                  {
                                                                                                    result = print_field(a2, a3, a4, "[oEyeColor]", "%d", *(_DWORD *)(this + 278));
                                                                                                    if ( !result )
                                                                                                    {
                                                                                                      result = print_field(a2, a3, a4, "[oCombatNPCID]", "%d", *(_DWORD *)(this + 282));
                                                                                                      if ( !result )
                                                                                                      {
                                                                                                        result = print_field(a2, a3, a4, "[oHideFashion]", "%d", *(__int16 *)(this + 286));
                                                                                                        if ( !result )
                                                                                                        {
                                                                                                          result = print_field(a2, a3, a4, "[oHideSuite]", "%d", *(__int16 *)(this + 288));
                                                                                                          if ( !result )
                                                                                                          {
                                                                                                            result = print_field(a2, a3, a4, "[oHideHelm]", "%d", *(__int16 *)(this + 290));
                                                                                                            if ( !result )
                                                                                                            {
                                                                                                              result = print_field(a2, a3, a4, "[oJinLiValue]", "%d", *(_DWORD *)(this + 292));
                                                                                                              if ( !result )
                                                                                                              {
                                                                                                                result = print_field(a2, a3, a4, "[oEquipTitleID]", "%d", *(_DWORD *)(this + 296));
                                                                                                                if ( !result )
                                                                                                                {
                                                                                                                  result = print_field(a2, a3, a4, "[oTitleLevel]", "%d", *(_DWORD *)(this + 300));
                                                                                                                  if ( !result )
                                                                                                                  {
                                                                                                                    result = print_field(a2, a3, a4, "[oGuildId]", "%d", *(_DWORD *)(this + 304));
                                                                                                                    if ( !result )
                                                                                                                    {
                                                                                                                      result = print_field(a2, a3, a4, "[oTeamPasswordFlag]", "%d", *(__int16 *)(this + 308));
                                                                                                                      if ( !result )
                                                                                                                      {
                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo1]", "%d", *(__int16 *)(this + 310));
                                                                                                                        if ( !result )
                                                                                                                        {
                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo2]", "%d", *(__int16 *)(this + 312));
                                                                                                                          if ( !result )
                                                                                                                          {
                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo3]", "%d", *(__int16 *)(this + 314));
                                                                                                                            if ( !result )
                                                                                                                            {
                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo4]", "%d", *(__int16 *)(this + 316));
                                                                                                                              if ( !result )
                                                                                                                              {
                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo5]", "%d", *(__int16 *)(this + 318));
                                                                                                                                if ( !result )
                                                                                                                                {
                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo6]", "%d", *(__int16 *)(this + 320));
                                                                                                                                  if ( !result )
                                                                                                                                  {
                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo7]", "%d", *(__int16 *)(this + 322));
                                                                                                                                    if ( !result )
                                                                                                                                    {
                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo8]", "%d", *(__int16 *)(this + 324));
                                                                                                                                      if ( !result )
                                                                                                                                      {
                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo9]", "%d", *(__int16 *)(this + 326));
                                                                                                                                        if ( !result )
                                                                                                                                        {
                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo10]", "%d", *(__int16 *)(this + 328));
                                                                                                                                          if ( !result )
                                                                                                                                          {
                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo11]", "%d", *(__int16 *)(this + 330));
                                                                                                                                            if ( !result )
                                                                                                                                            {
                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo12]", "%d", *(__int16 *)(this + 332));
                                                                                                                                              if ( !result )
                                                                                                                                              {
                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo13]", "%d", *(__int16 *)(this + 334));
                                                                                                                                                if ( !result )
                                                                                                                                                {
                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo14]", "%d", *(__int16 *)(this + 336));
                                                                                                                                                  if ( !result )
                                                                                                                                                  {
                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo15]", "%d", *(__int16 *)(this + 338));
                                                                                                                                                    if ( !result )
                                                                                                                                                    {
                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo16]", "%d", *(__int16 *)(this + 340));
                                                                                                                                                      if ( !result )
                                                                                                                                                      {
                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo17]", "%d", *(__int16 *)(this + 342));
                                                                                                                                                        if ( !result )
                                                                                                                                                        {
                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo18]", "%d", *(__int16 *)(this + 344));
                                                                                                                                                          if ( !result )
                                                                                                                                                          {
                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo19]", "%d", *(__int16 *)(this + 346));
                                                                                                                                                            if ( !result )
                                                                                                                                                            {
                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo20]", "%d", *(__int16 *)(this + 348));
                                                                                                                                                              if ( !result )
                                                                                                                                                              {
                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo21]", "%d", *(__int16 *)(this + 350));
                                                                                                                                                                if ( !result )
                                                                                                                                                                {
                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo22]", "%d", *(__int16 *)(this + 352));
                                                                                                                                                                  if ( !result )
                                                                                                                                                                  {
                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo23]", "%d", *(__int16 *)(this + 354));
                                                                                                                                                                    if ( !result )
                                                                                                                                                                    {
                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo24]", "%d", *(__int16 *)(this + 356));
                                                                                                                                                                      if ( !result )
                                                                                                                                                                      {
                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo25]", "%d", *(__int16 *)(this + 358));
                                                                                                                                                                        if ( !result )
                                                                                                                                                                        {
                                                                                                                                                                          result = print_field(a2, a3, a4, "[oVIP]", "%d", *(__int16 *)(this + 360));
                                                                                                                                                                          if ( !result )
                                                                                                                                                                          {
                                                                                                                                                                            result = print_field(a2, a3, a4, "[oVIPLevel]", "%d", *(_DWORD *)(this + 362));
                                                                                                                                                                            if ( !result )
                                                                                                                                                                            {
                                                                                                                                                                              result = print_field(a2, a3, a4, "[oVIPExp]", "%d", *(_DWORD *)(this + 366));
                                                                                                                                                                              if ( !result )
                                                                                                                                                                              {
                                                                                                                                                                                result = print_field(a2, a3, a4, "[oVIPBaseCanUse]", "%d", *(__int16 *)(this + 370));
                                                                                                                                                                                if ( !result )
                                                                                                                                                                                {
                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oGameVIP]", "%d", *(__int16 *)(this + 372));
                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                  {
                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oQQVIP]", "%d", *(__int16 *)(this + 374));
                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                    {
                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oYearQQVIP]", "%d", *(__int16 *)(this + 376));
                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                      {
                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oSuperQQVIP]", "%d", *(__int16 *)(this + 378));
                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                        {
                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oNetbarLevel]", "%d", *(__int16 *)(this + 380));
                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                          {
                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oCharHRLevel]", "%d", *(_DWORD *)(this + 382));
                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                            {
                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oCharHRPoint]", "%d", *(_DWORD *)(this + 386));
                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                              {
                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oXYVIP]", "%d", *(__int16 *)(this + 390));
                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                {
                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo26]", "%d", *(__int16 *)(this + 392));
                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                  {
                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo27]", "%d", *(__int16 *)(this + 394));
                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                    {
                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo28]", "%d", *(__int16 *)(this + 396));
                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                      {
                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo29]", "%d", *(__int16 *)(this + 398));
                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                        {
                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo30]", "%d", *(__int16 *)(this + 400));
                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                          {
                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo31]", "%d", *(__int16 *)(this + 402));
                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                            {
                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo32]", "%d", *(__int16 *)(this + 404));
                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                              {
                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo33]", "%d", *(__int16 *)(this + 406));
                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                {
                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo34]", "%d", *(__int16 *)(this + 408));
                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo35]", "%d", *(__int16 *)(this + 410));
                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo36]", "%d", *(__int16 *)(this + 412));
                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo37]", "%d", *(__int16 *)(this + 414));
                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo38]", "%d", *(__int16 *)(this + 416));
                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                          {
                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo39]", "%d", *(__int16 *)(this + 418));
                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo40]", "%d", *(__int16 *)(this + 420));
                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo41]", "%d", *(__int16 *)(this + 422));
                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo42]", "%d", *(__int16 *)(this + 424));
                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo43]", "%d", *(__int16 *)(this + 426));
                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo44]", "%d", *(__int16 *)(this + 428));
                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo45]", "%d", *(__int16 *)(this + 430));
                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo46]", "%d", *(__int16 *)(this + 432));
                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo47]", "%d", *(__int16 *)(this + 434));
                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oTGPVIP]", "%d", *(__int16 *)(this + 436));
                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFluteTune]", "%d", *(_DWORD *)(this + 438));
                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                  result = sub_1024A3B0(a2, a3, v22, "[oDefenseReduceHPModifyRate]", 7);
                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                    v23 = (float *)(this + 442);
                                                                                                                                                                                                                                                    v32 = 0;
                                                                                                                                                                                                                                                    v40 = this + 442;
                                                                                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                      result = Printf(a2, " %f", *v23);
                                                                                                                                                                                                                                                      if ( result )
                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                      v23 = (float *)(v40 + 4);
                                                                                                                                                                                                                                                      ++v32;
                                                                                                                                                                                                                                                      v40 += 4;
                                                                                                                                                                                                                                                      if ( v32 >= 7 )
                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                        result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                          result = sub_1024A3B0(a2, a3, v24, "[oDefenseReduceStaModifyRate]", 7);
                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                            v25 = (float *)(this + 470);
                                                                                                                                                                                                                                                            v33 = 0;
                                                                                                                                                                                                                                                            for ( i = this + 470;
                                                                                                                                                                                                                                                                  ;
                                                                                                                                                                                                                                                                  i += 4 )
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                              result = Printf(a2, " %f", *v25);
                                                                                                                                                                                                                                                              if ( result )
                                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                                              v25 = (float *)(i + 4);
                                                                                                                                                                                                                                                              if ( (unsigned int)++v33 >= 7 )
                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oDeadTime]", "%d", *(_DWORD *)(this + 498));
                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oWildHuntCamp]", "%d", *(_DWORD *)(this + 502));
                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oTotalHRPoint]", "%d", *(_DWORD *)(this + 506));
                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oLikeHunterOfficer]", "%d", *(_DWORD *)(this + 510));
                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oLevelShowType]", "%d", *(_DWORD *)(this + 514));
                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oMonolopyRoundCount]", "%d", *(_DWORD *)(this + 518));
                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oMonolopyActivity]", "%d", *(_DWORD *)(this + 522));
                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oMonolopyCurGrid]", "%d", *(_DWORD *)(this + 526));
                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oSoulStoneLevel]", "%d", *(_DWORD *)(this + 530));
                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oWeeklyRefreshTime]", "%d", *(_DWORD *)(this + 534));
                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                      return print_field(a2, a3, a4, "[oSoulStoneAtkLevel]", "%d", *(_DWORD *)(this + 538));
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
                                                                                              }
                                                                                            }
                                                                                          }
                                                                                        }
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
                                                                      return result;
                                                                    }
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
                                              }
                                            }
                                            return result;
                                          }
                                        }
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
                    }
                  }
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
// 101DC9FB: variable 'v10' is possibly undefined
// 101DCA5F: variable 'v12' is possibly undefined
// 101DCB09: variable 'v14' is possibly undefined
// 101DCC26: variable 'v16' is possibly undefined
// 101DCC8D: variable 'v18' is possibly undefined
// 101DCD45: variable 'v20' is possibly undefined
// 101DD98F: variable 'v22' is possibly undefined
// 101DDA08: variable 'v24' is possibly undefined



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



