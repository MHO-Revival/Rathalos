// ============================================================
// Name: TLV::UnkTlv0079::Read_0xAA
// Address Name: SUB_1014F700
// ============================================================
//----- (1014F700) --------------------------------------------------------
int __thiscall sub_1014F700(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  int *v8; // eax
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edi
  _DWORD *v14; // ecx
  _DWORD *v15; // ebx
  unsigned int v16; // edx
  int v17; // ecx
  unsigned int v18; // edi
  int *v19; // ebx
  unsigned int v20; // edx
  int v21; // edi
  int *v22; // ebx
  unsigned int v23; // edx
  int v24; // ecx
  unsigned __int8 v25; // bl
  unsigned int v26; // edx
  unsigned __int8 v27; // bl
  unsigned int v28; // edx
  unsigned __int8 v29; // bl
  unsigned int v30; // edx
  unsigned int v31; // [esp+Ch] [ebp-10h]
  int v32; // [esp+10h] [ebp-Ch]
  _DWORD *v33; // [esp+10h] [ebp-Ch]
  int v34; // [esp+10h] [ebp-Ch]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  unsigned int v37; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v38; // [esp+18h] [ebp-4h]

  v3 = a2;
  result = 0;
  v37 = 0;
  v6 = a3;
  v38 = this;
  *(_DWORD *)((char *)this + 158519) = 0;
  v7 = v3[1] + v6;
  v31 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v37);
    if ( result )
      return result;
    switch ( v37 >> 4 )
    {
      case 2u:
        if ( (*((_BYTE *)this + 158519) & 1) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 1u;
        result = TdrBuf::ReadVarInt(v3, this);
        if ( !result )
          goto LABEL_26;
        return result;
      case 0x13u:
        if ( (*(_DWORD *)((char *)this + 158519) & 2) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 2u;
        v8 = this + 1;
        goto LABEL_11;
      case 0x14u:
        if ( (*(_DWORD *)((char *)this + 158519) & 4) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v10 = (int)(v38 + 2);
        v32 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10144AF0(v10, v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v32 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v32) )
          {
            ++v9;
            v10 += 12;
            if ( v9 >= 70 )
              goto LABEL_25;
            continue;
          }
          break;
        }
        v12 = v9 + 1;
        this = v38;
        v38[1] = v12;
        goto LABEL_26;
      case 0x15u:
        if ( (*(_DWORD *)((char *)this + 158519) & 8) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 8u;
        v8 = this + 212;
        goto LABEL_11;
      case 0x16u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x10) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v14 = v38 + 213;
        v15 = a2;
        a3 = v3[1];
        v33 = v38 + 213;
        while ( 2 )
        {
          result = TdrBuf::ReadByte(v3, (_BYTE *)v14 + v13);
          if ( result )
            return result;
          v16 = v3[1];
          if ( v16 > (unsigned int)v15 + a3 )
            return -34;
          if ( (_DWORD *)v16 != (_DWORD *)((char *)v15 + a3) )
          {
            v14 = v33;
            if ( ++v13 >= 0x2000 )
              goto LABEL_25;
            continue;
          }
          break;
        }
        v17 = v13 + 1;
        this = v38;
        v38[212] = v17;
        goto LABEL_26;
      case 0x17u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x20) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_10149BF0(this + 2261, v3, (int)a2);
        goto LABEL_12;
      case 0x18u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x40) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014AC40((int)this + 63742, v3, (int)a2);
        goto LABEL_12;
      case 0x19u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x80) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014BA90(this + 15968, v3, a2);
        goto LABEL_12;
      case 0x1Au:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x100) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x100u;
        result = TdrBuf::ReadVarUShort(v3, (_WORD *)this + 35524);
        goto LABEL_12;
      case 0x1Bu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x200) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v19 = (_DWORD *)((char *)v38 + 71050);
        v34 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10143610(v19, v3, a3);
            if ( result )
              return result;
          }
          v20 = v3[1];
          if ( v20 > (unsigned int)a2 + v34 )
            return -34;
          if ( (_DWORD *)v20 != (_DWORD *)((char *)a2 + v34) )
          {
            ++v18;
            v19 += 3;
            if ( v18 < 0x40 )
              continue;
          }
          goto LABEL_25;
        }
      case 0x1Cu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x400) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x400u;
        v8 = (_DWORD *)((char *)this + 71818);
LABEL_11:
        result = TdrBuf::ReadVarInt(v3, v8);
        goto LABEL_12;
      case 0x1Du:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x800) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v21 = 0;
        v22 = (_DWORD *)((char *)v38 + 71822);
        a3 = v3[1];
        while ( 1 )
        {
          result = TdrBuf::ReadVarInt(v3, v22);
          if ( result )
            return result;
          v23 = v3[1];
          if ( v23 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v21;
          ++v22;
          if ( v21 >= 5000 )
          {
LABEL_25:
            this = v38;
            goto LABEL_26;
          }
        }
        v24 = v21 + 1;
        this = v38;
        *(_DWORD *)((char *)v38 + 71818) = v24;
        goto LABEL_26;
      case 0x1Eu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x1000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x1000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014CF40((int)this + 91822, v3, (int)a2);
        goto LABEL_12;
      case 0x1Fu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x2000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x2000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 156828);
        goto LABEL_12;
      case 0x20u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x4000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x4000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v25 = 0;
        v35 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10143C90((char *)this + 8 * v25 + v25 + 156829, v3, a3);
            if ( result )
              return result;
          }
          v26 = v3[1];
          if ( v26 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v26 != (_DWORD *)((char *)a2 + v35) )
          {
            if ( ++v25 >= 0x40u )
              goto LABEL_26;
            continue;
          }
          break;
        }
        *((_BYTE *)this + 156828) = v25 + 1;
        goto LABEL_26;
      case 0x21u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x8000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x8000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 157405);
        goto LABEL_12;
      case 0x22u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x10000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v27 = 0;
        a3 = v3[1];
        while ( 2 )
        {
          result = TdrBuf::ReadVarInt(v3, (_DWORD *)((char *)this + 4 * v27 + 157406));
          if ( result )
            return result;
          v28 = v3[1];
          if ( v28 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v28 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v27 >= 0x40u )
              goto LABEL_26;
            continue;
          }
          break;
        }
        *((_BYTE *)this + 157405) = v27 + 1;
        goto LABEL_26;
      case 0x23u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x20000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x20000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 157662);
        goto LABEL_12;
      case 0x24u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x40000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v29 = 0;
        v36 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101443F0((char *)this + 13 * v29 + 157663, v3, a3);
            if ( result )
              return result;
          }
          v30 = v3[1];
          if ( v30 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v30 == (_DWORD *)((char *)a2 + v36) )
            break;
          if ( ++v29 >= 0x40u )
            goto LABEL_26;
        }
        *((_BYTE *)this + 157662) = v29 + 1;
LABEL_26:
        v7 = v31;
        if ( v3[1] < v31 )
          continue;
LABEL_27:
        if ( v3[1] > v7 )
          return -34;
        return result;
      case 0x25u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x80000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014DFD0((_DWORD *)((char *)this + 158495), v3, (int)a2);
LABEL_12:
        if ( !result )
          goto LABEL_26;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v37 & 0xF);
        goto LABEL_12;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0079::Read_0x99
// Address Name: SUB_1014FF80
// ============================================================
//----- (1014FF80) --------------------------------------------------------
int __thiscall sub_1014FF80(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  _BYTE *v8; // eax
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edi
  _DWORD *v14; // ecx
  _DWORD *v15; // ebx
  unsigned int v16; // edx
  int v17; // ecx
  unsigned int v18; // edi
  int v19; // ebx
  unsigned int v20; // edx
  int v21; // edi
  _BYTE *v22; // ebx
  unsigned int v23; // edx
  int v24; // ecx
  unsigned __int8 v25; // bl
  unsigned int v26; // edx
  unsigned __int8 v27; // bl
  unsigned int v28; // edx
  unsigned __int8 v29; // bl
  unsigned int v30; // edx
  unsigned int v31; // [esp+Ch] [ebp-10h]
  int v32; // [esp+10h] [ebp-Ch]
  _DWORD *v33; // [esp+10h] [ebp-Ch]
  int v34; // [esp+10h] [ebp-Ch]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  unsigned int v37; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v38; // [esp+18h] [ebp-4h]

  v3 = a2;
  result = 0;
  v37 = 0;
  v6 = a3;
  v38 = this;
  *(_DWORD *)((char *)this + 158519) = 0;
  v7 = v3[1] + v6;
  v31 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v37);
    if ( result )
      return result;
    switch ( v37 >> 4 )
    {
      case 2u:
        if ( (*((_BYTE *)this + 158519) & 1) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 1u;
        result = TdrBuf::ReadInt32(v3, this);
        if ( !result )
          goto LABEL_26;
        return result;
      case 0x13u:
        if ( (*(_DWORD *)((char *)this + 158519) & 2) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 2u;
        v8 = this + 1;
        goto LABEL_11;
      case 0x14u:
        if ( (*(_DWORD *)((char *)this + 158519) & 4) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v10 = (int)(v38 + 2);
        v32 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10144BC0(v10, v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v32 )
            return -34;
          if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v32) )
          {
            ++v9;
            v10 += 12;
            if ( v9 >= 70 )
              goto LABEL_25;
            continue;
          }
          break;
        }
        v12 = v9 + 1;
        this = v38;
        v38[1] = v12;
        goto LABEL_26;
      case 0x15u:
        if ( (*(_DWORD *)((char *)this + 158519) & 8) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 8u;
        v8 = this + 212;
        goto LABEL_11;
      case 0x16u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x10) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v14 = v38 + 213;
        v15 = a2;
        a3 = v3[1];
        v33 = v38 + 213;
        while ( 2 )
        {
          result = TdrBuf::ReadByte(v3, (_BYTE *)v14 + v13);
          if ( result )
            return result;
          v16 = v3[1];
          if ( v16 > (unsigned int)v15 + a3 )
            return -34;
          if ( (_DWORD *)v16 != (_DWORD *)((char *)v15 + a3) )
          {
            v14 = v33;
            if ( ++v13 >= 0x2000 )
              goto LABEL_25;
            continue;
          }
          break;
        }
        v17 = v13 + 1;
        this = v38;
        v38[212] = v17;
        goto LABEL_26;
      case 0x17u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x20) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_10149D80(this + 2261, v3, (int)a2);
        goto LABEL_12;
      case 0x18u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x40) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014AE00((int)this + 63742, v3, (int)a2);
        goto LABEL_12;
      case 0x19u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x80) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014BE50(this + 15968, v3, a2);
        goto LABEL_12;
      case 0x1Au:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x100) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x100u;
        result = TdrBuf::ReadInt16(v3, (_BYTE *)this + 71048);
        goto LABEL_12;
      case 0x1Bu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x200) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v19 = (int)v38 + 71050;
        v34 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_101436B0(v19, v3, a3);
            if ( result )
              return result;
          }
          v20 = v3[1];
          if ( v20 > (unsigned int)a2 + v34 )
            return -34;
          if ( (_DWORD *)v20 != (_DWORD *)((char *)a2 + v34) )
          {
            ++v18;
            v19 += 12;
            if ( v18 < 0x40 )
              continue;
          }
          goto LABEL_25;
        }
      case 0x1Cu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x400) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x400u;
        v8 = (char *)this + 71818;
LABEL_11:
        result = TdrBuf::ReadInt32(v3, v8);
        goto LABEL_12;
      case 0x1Du:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x800) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v21 = 0;
        v22 = (char *)v38 + 71822;
        a3 = v3[1];
        while ( 1 )
        {
          result = TdrBuf::ReadInt32(v3, v22);
          if ( result )
            return result;
          v23 = v3[1];
          if ( v23 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + a3) )
            break;
          ++v21;
          v22 += 4;
          if ( v21 >= 5000 )
          {
LABEL_25:
            this = v38;
            goto LABEL_26;
          }
        }
        v24 = v21 + 1;
        this = v38;
        *(_DWORD *)((char *)v38 + 71818) = v24;
        goto LABEL_26;
      case 0x1Eu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x1000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x1000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014D390((int)this + 91822, v3, (int)a2);
        goto LABEL_12;
      case 0x1Fu:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x2000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x2000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 156828);
        goto LABEL_12;
      case 0x20u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x4000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x4000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v25 = 0;
        v35 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10143D80((char *)this + 8 * v25 + v25 + 156829, v3, a3);
            if ( result )
              return result;
          }
          v26 = v3[1];
          if ( v26 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v26 != (_DWORD *)((char *)a2 + v35) )
          {
            if ( ++v25 >= 0x40u )
              goto LABEL_26;
            continue;
          }
          break;
        }
        *((_BYTE *)this + 156828) = v25 + 1;
        goto LABEL_26;
      case 0x21u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x8000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x8000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 157405);
        goto LABEL_12;
      case 0x22u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x10000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v27 = 0;
        a3 = v3[1];
        while ( 2 )
        {
          result = TdrBuf::ReadInt32(v3, (_BYTE *)this + 4 * v27 + 157406);
          if ( result )
            return result;
          v28 = v3[1];
          if ( v28 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v28 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v27 >= 0x40u )
              goto LABEL_26;
            continue;
          }
          break;
        }
        *((_BYTE *)this + 157405) = v27 + 1;
        goto LABEL_26;
      case 0x23u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x20000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x20000u;
        result = TdrBuf::ReadByte(v3, (_BYTE *)this + 157662);
        goto LABEL_12;
      case 0x24u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x40000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v29 = 0;
        v36 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10144500((char *)this + 13 * v29 + 157663, v3, a3);
            if ( result )
              return result;
          }
          v30 = v3[1];
          if ( v30 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v30 == (_DWORD *)((char *)a2 + v36) )
            break;
          if ( ++v29 >= 0x40u )
            goto LABEL_26;
        }
        *((_BYTE *)this + 157662) = v29 + 1;
LABEL_26:
        v7 = v31;
        if ( v3[1] < v31 )
          continue;
LABEL_27:
        if ( v3[1] > v7 )
          return -34;
        return result;
      case 0x25u:
        if ( (*(_DWORD *)((char *)this + 158519) & 0x80000) == 0 )
          *(_DWORD *)((char *)this + 158519) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_26;
        result = sub_1014E100((int)this + 158495, v3, (int)a2);
LABEL_12:
        if ( !result )
          goto LABEL_26;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v37 & 0xF);
        goto LABEL_12;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0079::DoDebugFormat
// Address Name: SUB_10150820
// ============================================================
//----- (10150820) --------------------------------------------------------
int __thiscall sub_10150820(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_101508D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0079::DebugFormat
// Address Name: SUB_101508D0
// ============================================================
//----- (101508D0) --------------------------------------------------------
int __thiscall sub_101508D0(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  _DWORD *v11; // ecx
  _BYTE *v12; // ecx
  unsigned int *v13; // ecx
  int v14; // ecx
  int v15; // eax
  _DWORD *v16; // ecx
  unsigned __int16 *v17; // ecx
  unsigned __int8 v18; // cl
  unsigned __int8 v19; // al
  int v20; // ecx
  unsigned __int8 v21; // al
  unsigned __int8 v22; // al
  unsigned __int8 v23; // cl
  unsigned __int8 v24; // al
  unsigned __int8 *v25; // ecx
  _DWORD *v26; // ecx
  int v27; // [esp+14h] [ebp+8h]
  int v28; // [esp+14h] [ebp+8h]
  int v29; // [esp+14h] [ebp+8h]
  int v30; // [esp+14h] [ebp+8h]
  int v31; // [esp+14h] [ebp+8h]
  unsigned __int16 *v32; // [esp+18h] [ebp+Ch]
  int v33; // [esp+18h] [ebp+Ch]
  _DWORD *v34; // [esp+18h] [ebp+Ch]
  int v35; // [esp+18h] [ebp+Ch]
  unsigned __int8 v36; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v37; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v38; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[entrustMoneyLastTm]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[thousandLayerDataCount]", "%d", *((_DWORD *)this + 1));
    if ( !result )
    {
      v8 = *((_DWORD *)this + 1);
      if ( v8 < 0 )
        return -6;
      if ( v8 > 70 )
        return -7;
      v27 = 0;
      if ( v8 <= 0 )
      {
LABEL_18:
        result = print_field(a2, a3, a4, "[levelStatLen]", "%d", *((_DWORD *)this + 212));
        if ( !result )
        {
          v10 = *((_DWORD *)this + 212);
          if ( v10 < 0 )
            return -6;
          if ( v10 > 0x2000 )
            return -7;
          result = sub_1024A3B0(a2, a3, v9, "[levelStatDataPack]", v10);
          if ( !result )
          {
            v33 = 0;
            if ( *((int *)this + 212) <= 0 )
            {
LABEL_25:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[entrustAllStat]");
                if ( !result )
                {
                  v11 = this + 9044;
                  result = a3 >= 0 ? sub_10149FE0(v11, a2, a3 + 1, a4) : sub_10149FE0(v11, a2, a3, a4);
                  if ( !result )
                  {
                    result = print_structure((int)a2, a3, a4, (int)"[levelWarningData]");
                    if ( !result )
                    {
                      v12 = this + 63742;
                      result = a3 >= 0 ? sub_1014B090(v12, a2, a3 + 1, a4) : sub_1014B090(v12, a2, a3, a4);
                      if ( !result )
                      {
                        result = print_structure((int)a2, a3, a4, (int)"[monsterSizeHistroyInfo]");
                        if ( !result )
                        {
                          v13 = (unsigned int *)(this + 63872);
                          result = a3 >= 0 ? sub_1014C2E0(v13, a2, a3 + 1, a4) : sub_1014C2E0(v13, a2, a3, a4);
                          if ( !result )
                          {
                            result = print_field(
                                       a2,
                                       a3,
                                       a4,
                                       "[unlockHubPageCount]",
                                       "%d",
                                       *((unsigned __int16 *)this + 35524));
                            if ( !result )
                            {
                              v28 = 0;
                              v34 = this + 71050;
                              while ( 1 )
                              {
                                result = sub_1024A230(a2, a3, a4, "[unlockHubPageData]", result);
                                if ( result )
                                  break;
                                result = a3 >= 0 ? sub_10143850(v34, a2, a3 + 1, a4) : sub_10143850(v34, a2, a3, a4);
                                if ( result )
                                  break;
                                v34 += 3;
                                result = v28 + 1;
                                v28 = result;
                                if ( (unsigned int)result >= 0x40 )
                                {
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[levelUnLockCount]",
                                             "%d",
                                             *(_DWORD *)(this + 71818));
                                  if ( result )
                                    return result;
                                  v15 = *(_DWORD *)(this + 71818);
                                  if ( v15 < 0 )
                                    return -6;
                                  if ( v15 > 5000 )
                                    return -7;
                                  result = sub_1024A3B0(a2, a3, v14, "[unLockLevelData]", v15);
                                  if ( result )
                                    return result;
                                  v35 = 0;
                                  if ( *(int *)(this + 71818) > 0 )
                                  {
                                    v16 = this + 71822;
                                    v29 = (int)(this + 71822);
                                    do
                                    {
                                      result = Printf(a2, " %d", *v16);
                                      if ( result )
                                        return result;
                                      v16 = (_DWORD *)(v29 + 4);
                                      ++v35;
                                      v29 += 4;
                                    }
                                    while ( v35 < *(_DWORD *)(this + 71818) );
                                  }
                                  result = TdrBuf::WriteChar(a2, a4);
                                  if ( result )
                                    return result;
                                  result = print_structure((int)a2, a3, a4, (int)"[levelIntegrateData]");
                                  if ( result )
                                    return result;
                                  v17 = (unsigned __int16 *)(this + 91822);
                                  result = a3 >= 0 ? sub_1014D8B0(v17, a2, a3 + 1, a4) : sub_1014D8B0(v17, a2, a3, a4);
                                  if ( result )
                                    return result;
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[hubRewardCount]",
                                             "0x%02x",
                                             (unsigned __int8)*(this + 156828));
                                  if ( result )
                                    return result;
                                  v18 = *(this + 156828);
                                  if ( v18 > 0x40u )
                                    return -7;
                                  v19 = 0;
                                  v36 = 0;
                                  if ( v18 )
                                  {
                                    do
                                    {
                                      v30 = v19;
                                      result = sub_1024A230(a2, a3, a4, "[hubRewardData]", v19);
                                      if ( result )
                                        return result;
                                      result = a3 >= 0
                                             ? sub_10143F70(
                                                 (unsigned __int8 *)this + 8 * v30 + v30 + 156829,
                                                 a2,
                                                 a3 + 1,
                                                 a4)
                                             : sub_10143F70(
                                                 (unsigned __int8 *)this + 8 * v30 + v30 + 156829,
                                                 a2,
                                                 a3,
                                                 a4);
                                      if ( result )
                                        return result;
                                      v19 = v36 + 1;
                                      v36 = v19;
                                    }
                                    while ( v19 < (unsigned __int8)*(this + 156828) );
                                  }
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[unlockLevelGroupCount]",
                                             "0x%02x",
                                             (unsigned __int8)*(this + 157405));
                                  if ( result )
                                    return result;
                                  v21 = *(this + 157405);
                                  if ( v21 <= 0x40u )
                                  {
                                    result = sub_1024A3B0(a2, a3, v20, "[unlockLevelGroupData]", v21);
                                    if ( result )
                                      return result;
                                    v22 = 0;
                                    v37 = 0;
                                    if ( *(this + 157405) )
                                    {
                                      while ( 1 )
                                      {
                                        result = Printf(a2, " %d", *(_DWORD *)(this + 4 * v22 + 157406));
                                        if ( result )
                                          break;
                                        v22 = v37 + 1;
                                        v37 = v22;
                                        if ( v22 >= (unsigned __int8)*(this + 157405) )
                                          goto LABEL_78;
                                      }
                                    }
                                    else
                                    {
LABEL_78:
                                      result = TdrBuf::WriteChar(a2, a4);
                                      if ( !result )
                                      {
                                        result = print_field(
                                                   a2,
                                                   a3,
                                                   a4,
                                                   "[hubPageStarUnLockCount]",
                                                   "0x%02x",
                                                   (unsigned __int8)*(this + 157662));
                                        if ( !result )
                                        {
                                          v23 = *(this + 157662);
                                          if ( v23 > 0x40u )
                                            return -7;
                                          v24 = 0;
                                          v38 = 0;
                                          if ( v23 )
                                          {
                                            while ( 1 )
                                            {
                                              v31 = v24;
                                              result = sub_1024A230(a2, a3, a4, "[hubPageStarUnLockData]", v24);
                                              if ( result )
                                                break;
                                              v25 = (unsigned __int8 *)(this + 13 * v31 + 157663);
                                              result = a3 >= 0
                                                     ? sub_101446E0(v25, a2, a3 + 1, a4)
                                                     : sub_101446E0(v25, a2, a3, a4);
                                              if ( result )
                                                break;
                                              v24 = v38 + 1;
                                              v38 = v24;
                                              if ( v24 >= (unsigned __int8)*(this + 157662) )
                                                goto LABEL_88;
                                            }
                                          }
                                          else
                                          {
LABEL_88:
                                            result = print_structure((int)a2, a3, a4, (int)"[superHunterData]");
                                            if ( !result )
                                            {
                                              v26 = this + 158495;
                                              if ( a3 >= 0 )
                                                return sub_1014E300(v26, a2, a3 + 1, a4);
                                              else
                                                return sub_1014E300(v26, a2, a3, a4);
                                            }
                                          }
                                        }
                                      }
                                    }
                                    return result;
                                  }
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
              }
            }
            else
            {
              while ( 1 )
              {
                result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + result + 852));
                if ( result )
                  break;
                result = v33 + 1;
                v33 = result;
                if ( result >= *((_DWORD *)this + 212) )
                  goto LABEL_25;
              }
            }
          }
        }
      }
      else
      {
        v32 = (unsigned __int16 *)(this + 8);
        while ( 1 )
        {
          if ( !"[thousandLayerData]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[thousandLayerData]", v27, (char)a4);
          if ( result )
            break;
          result = a3 >= 0 ? sub_10144E00(v32, a2, a3 + 1, a4) : sub_10144E00(v32, a2, a3, a4);
          if ( result )
            break;
          v32 += 6;
          if ( ++v27 >= *((_DWORD *)this + 1) )
            goto LABEL_18;
        }
      }
    }
  }
  return result;
}
// 10150A34: variable 'v9' is possibly undefined
// 10150C18: variable 'v14' is possibly undefined
// 10150DA3: variable 'v20' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014DFD0
// ============================================================
//----- (1014DFD0) --------------------------------------------------------
int __thiscall sub_1014DFD0(_DWORD *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 5) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_22:
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
          if ( (*(_BYTE *)(this + 5) & 1) == 0 )
            *(this + 5) |= 1u;
          VarUInt = TdrBuf::ReadVarUInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 5) & 2) == 0 )
            *(this + 5) |= 2u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 5) & 4) == 0 )
            *(this + 5) |= 4u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 5) & 8) == 0 )
            *(this + 5) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 5) & 0x10) == 0 )
            *(this + 5) |= 0x10u;
          VarUInt = TdrBuf::ReadVarInt(a2, this + 4);
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
        goto LABEL_22;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014AC40
// ============================================================
//----- (1014AC40) --------------------------------------------------------
int __thiscall sub_1014AC40(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  v9 = 0;
  *(_DWORD *)(this + 126) = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      return result;
    switch ( v9 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadVarUInt(a2, (_DWORD *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        v8 = 0;
        result = TdrBuf::ReadInt32(a2, &v8);
        if ( result )
          return result;
        if ( !v8 )
          return -37;
        v6 = 0;
        v11 = a2[1];
        while ( 1 )
        {
          v10 = 0;
          result = TdrBuf::ReadInt32(a2, &v10);
          if ( result )
            return result;
          if ( v10 )
          {
            result = sub_1014A460((int *)(this + 6 + 12 * v6), a2, v10);
            if ( result )
              return result;
          }
          v7 = a2[1];
          if ( v7 > v11 + v8 )
            return -34;
          if ( v7 == v11 + v8 )
            break;
          if ( ++v6 >= 0xAu )
            goto LABEL_28;
        }
        *(_BYTE *)(this + 5) = v6 + 1;
LABEL_28:
        v5 = v12;
        if ( a2[1] < v12 )
          continue;
LABEL_29:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v9 & 0xF);
LABEL_27:
        if ( !result )
          goto LABEL_28;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10144AF0
// ============================================================
//----- (10144AF0) --------------------------------------------------------
int __thiscall sub_10144AF0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarInt; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 8) = 0;
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
          if ( (*(_BYTE *)(this + 8) & 1) == 0 )
            *(_DWORD *)(this + 8) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 8) & 2) == 0 )
            *(_DWORD *)(this + 8) |= 2u;
          VarInt = TdrBuf::ReadVarUShort(a2, (_WORD *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 8) & 4) == 0 )
            *(_DWORD *)(this + 8) |= 4u;
          VarInt = TdrBuf::ReadVarShort(a2, (_WORD *)(this + 6));
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
// Address Name: SUB_10149BF0
// ============================================================
//----- (10149BF0) --------------------------------------------------------
int __thiscall sub_10149BF0(int *this, _DWORD *a2, int a3)
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
  int v15; // [esp+1Ch] [ebp-Ch] BYREF
  int v16; // [esp+20h] [ebp-8h]
  unsigned int v17; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  v13 = this;
  *(int *)((char *)this + 54694) = 0;
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
        if ( (*((_BYTE *)v3 + 54694) & 1) == 0 )
          *(int *)((char *)v3 + 54694) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(int *)((char *)v3 + 54694) & 2) == 0 )
            *(int *)((char *)v3 + 54694) |= 2u;
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
              v4 = sub_10146240((int)v12, a2, v15);
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
            v12 = (_DWORD *)((char *)v12 + 3646);
            if ( ++v8 >= 15 )
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
// Address Name: SUB_1014BA90
// ============================================================
//----- (1014BA90) --------------------------------------------------------
int __thiscall sub_1014BA90(unsigned int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  unsigned int *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // eax
  _DWORD *v19; // edx
  char *v20; // eax
  char *v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  char *v24; // [esp+Ch] [ebp-18h]
  int v25; // [esp+10h] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-10h] BYREF
  int v27; // [esp+18h] [ebp-Ch]
  unsigned int v28; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int *v29; // [esp+20h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v29 = this;
  *(this + 1793) = 0;
  v28 = 0;
  v7 = (char *)v3 + v6[1];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_61;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (v4[1793] & 1) == 0 )
          v4[1793] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
        goto LABEL_59;
      case 3u:
        if ( (v4[1793] & 2) == 0 )
          v4[1793] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        do
        {
          Byte = TdrBuf::ReadVarUInt(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v27) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 4u:
        if ( (v4[1793] & 4) == 0 )
          v4[1793] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 513;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v26);
          v15 = a3;
          Byte = v14;
          if ( v14 )
            return Byte;
          v16 = (char *)a2 + v27;
          *a3 = v26;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
            goto LABEL_17;
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 5u:
        if ( (v4[1793] & 8) == 0 )
          v4[1793] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 1025;
        do
        {
          v18 = TdrBuf::ReadInt32(v6, &v25);
          v19 = a3;
          Byte = v18;
          if ( v18 )
            return Byte;
          v20 = (char *)a2 + v27;
          *a3 = v25;
          v21 = (char *)v6[1];
          if ( v21 > v20 )
            return -34;
          if ( v21 == v20 )
            goto LABEL_17;
          ++v10;
          a3 = v19 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 6u:
        if ( (v4[1793] & 0x10) == 0 )
          v4[1793] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6148);
          if ( Byte )
            return Byte;
          v22 = v6[1];
          if ( (_DWORD *)v22 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 7u:
        if ( (v4[1793] & 0x20) == 0 )
          v4[1793] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6660);
          if ( Byte )
            return Byte;
          v23 = v6[1];
          if ( (_DWORD *)v23 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_17:
            v13 = v10 + 1;
            v4 = v29;
            *v29 = v13;
            goto LABEL_60;
          }
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
LABEL_60:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_61:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Byte;
      default:
        VarUInt = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_59:
        Byte = VarUInt;
        if ( !VarUInt )
          goto LABEL_60;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10143610
// ============================================================
//----- (10143610) --------------------------------------------------------
int __thiscall sub_10143610(int *this, _DWORD *a2, int a3)
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
// Address Name: SUB_10143C90
// ============================================================
//----- (10143C90) --------------------------------------------------------
int __thiscall sub_10143C90(char *this, _DWORD *a2, int a3)
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
      result = TdrBuf::ReadVarInt(a2, (int *)(this + 1));
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
// Address Name: SUB_101443F0
// ============================================================
//----- (101443F0) --------------------------------------------------------
int __thiscall sub_101443F0(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1014CF40
// ============================================================
//----- (1014CF40) --------------------------------------------------------
int __thiscall sub_1014CF40(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _WORD *v5; // ebx
  int VarUInt; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUShort; // eax
  unsigned __int16 v10; // bx
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int v18; // [esp+Ch] [ebp-Ch]
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  _WORD *v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_WORD *)this;
  VarUInt = 0;
  v20 = (_WORD *)this;
  v19 = 0;
  *(_DWORD *)(this + 65002) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_71;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v5[32501] & 1) == 0 )
          *(_DWORD *)(v5 + 32501) |= 1u;
        VarUShort = TdrBuf::ReadVarUShort(v4, v5);
        goto LABEL_69;
      case 2u:
        if ( (*(_DWORD *)(v5 + 32501) & 2) == 0 )
          *(_DWORD *)(v5 + 32501) |= 2u;
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
          VarUInt = TdrBuf::ReadVarUInt(v4, &v20[2 * v10 + 1]);
          if ( VarUInt )
            return VarUInt;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 3u:
        if ( (*(_DWORD *)(v5 + 32501) & 4) == 0 )
          *(_DWORD *)(v5 + 32501) |= 4u;
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
          VarUInt = TdrBuf::ReadVarUShort(v4, &v20[v10 + 10001]);
          if ( VarUInt )
            return VarUInt;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 4u:
        if ( (*(_DWORD *)(v5 + 32501) & 8) == 0 )
          *(_DWORD *)(v5 + 32501) |= 8u;
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
          VarUInt = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 30002);
          if ( VarUInt )
            return VarUInt;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 5u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x10) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x10u;
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
          VarUInt = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 35002);
          if ( VarUInt )
            return VarUInt;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 6u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x20) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x20u;
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
          VarUInt = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 40002);
          if ( VarUInt )
            return VarUInt;
          v16 = v4[1];
          if ( v16 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 7u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x40) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x40u;
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
          VarUInt = TdrBuf::ReadVarUInt(v4, &v20[2 * v10 + 22501]);
          if ( VarUInt )
            return VarUInt;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_17:
            v12 = v10 + 1;
            v5 = v20;
            *v20 = v12;
            goto LABEL_70;
          }
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
LABEL_70:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_71:
        if ( v4[1] > v7 )
          return -34;
        return VarUInt;
      default:
        VarUShort = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_69:
        VarUInt = VarUShort;
        if ( !VarUShort )
          goto LABEL_70;
        return VarUInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101436B0
// ============================================================
//----- (101436B0) --------------------------------------------------------
int __thiscall sub_101436B0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_10143D80
// ============================================================
//----- (10143D80) --------------------------------------------------------
int __thiscall sub_10143D80(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1014D390
// ============================================================
//----- (1014D390) --------------------------------------------------------
int __thiscall sub_1014D390(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  _WORD *v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  unsigned __int16 v10; // bx
  unsigned int v11; // ecx
  __int16 v12; // ax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned int v18; // [esp+Ch] [ebp-Ch]
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  _WORD *v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (_WORD *)this;
  Int32 = 0;
  v20 = (_WORD *)this;
  v19 = 0;
  *(_DWORD *)(this + 65002) = 0;
  v7 = v4[1] + v3;
  v18 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_71;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (v5[32501] & 1) == 0 )
          *(_DWORD *)(v5 + 32501) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, v5);
        goto LABEL_69;
      case 2u:
        if ( (*(_DWORD *)(v5 + 32501) & 2) == 0 )
          *(_DWORD *)(v5 + 32501) |= 2u;
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
          Int32 = TdrBuf::ReadInt32(v4, &v20[2 * v10 + 1]);
          if ( Int32 )
            return Int32;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 3u:
        if ( (*(_DWORD *)(v5 + 32501) & 4) == 0 )
          *(_DWORD *)(v5 + 32501) |= 4u;
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
          Int32 = TdrBuf::ReadInt16(v4, &v20[v10 + 10001]);
          if ( Int32 )
            return Int32;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 4u:
        if ( (*(_DWORD *)(v5 + 32501) & 8) == 0 )
          *(_DWORD *)(v5 + 32501) |= 8u;
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
          Int32 = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 30002);
          if ( Int32 )
            return Int32;
          v14 = v4[1];
          if ( v14 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 5u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x10) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x10u;
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
          Int32 = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 35002);
          if ( Int32 )
            return Int32;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 6u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x20) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x20u;
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
          Int32 = TdrBuf::ReadByte(v4, (_BYTE *)v20 + v10 + 40002);
          if ( Int32 )
            return Int32;
          v16 = v4[1];
          if ( v16 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
        goto LABEL_70;
      case 7u:
        if ( (*(_DWORD *)(v5 + 32501) & 0x40) == 0 )
          *(_DWORD *)(v5 + 32501) |= 0x40u;
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
          Int32 = TdrBuf::ReadInt32(v4, &v20[2 * v10 + 22501]);
          if ( Int32 )
            return Int32;
          v17 = v4[1];
          if ( v17 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_17:
            v12 = v10 + 1;
            v5 = v20;
            *v20 = v12;
            goto LABEL_70;
          }
          ++v10;
        }
        while ( v10 < 0x1388u );
        v5 = v20;
LABEL_70:
        v7 = v18;
        if ( v4[1] < v18 )
          continue;
LABEL_71:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      default:
        Int16 = TdrBuf::SkipField(v4, v19 & 0xF);
LABEL_69:
        Int32 = Int16;
        if ( !Int16 )
          goto LABEL_70;
        return Int32;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10144BC0
// ============================================================
//----- (10144BC0) --------------------------------------------------------
int __thiscall sub_10144BC0(int this, _DWORD *a2, int a3)
{
  int v5; // ecx
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v12; // [esp+18h] [ebp+8h]

  v5 = 0;
  v11 = 0;
  *(_DWORD *)(this + 8) = 0;
  v6 = a2[1] + a3;
  v12 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 8) & 2) == 0 )
          *(_DWORD *)(this + 8) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v10 = a2[1];
        if ( (unsigned int)(a2[2] - v10) < 2 )
          return -2;
        *(_BYTE *)(this + 4) = *(_BYTE *)(*a2 + v10 + 1);
        *(_BYTE *)(this + 5) = *(_BYTE *)(*a2 + a2[1]);
        a2[1] += 2;
        v5 = 0;
      }
      else
      {
        if ( v11 >> 4 != 3 )
        {
          Int32 = TdrBuf::SkipField(a2, v11 & 0xF);
          goto LABEL_22;
        }
        if ( (*(_DWORD *)(this + 8) & 4) == 0 )
          *(_DWORD *)(this + 8) |= 4u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
        v9 = a2[1];
        if ( (unsigned int)(a2[2] - v9) < 2 )
          return -2;
        *(_BYTE *)(this + 6) = *(_BYTE *)(*a2 + v9 + 1);
        *(_BYTE *)(this + 7) = *(_BYTE *)(*a2 + a2[1]);
        a2[1] += 2;
        v5 = 0;
      }
LABEL_23:
      v6 = v12;
      if ( a2[1] >= v12 )
        goto LABEL_24;
    }
    if ( (*(_BYTE *)(this + 8) & 1) == 0 )
      *(_DWORD *)(this + 8) |= 1u;
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
LABEL_22:
    v5 = Int32;
    if ( Int32 )
      return v5;
    goto LABEL_23;
  }
LABEL_24:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10144500
// ============================================================
//----- (10144500) --------------------------------------------------------
int __thiscall sub_10144500(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1014E100
// ============================================================
//----- (1014E100) --------------------------------------------------------
int __thiscall sub_1014E100(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 20) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_22:
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
          if ( (*(_BYTE *)(this + 20) & 1) == 0 )
            *(_DWORD *)(this + 20) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 20) & 2) == 0 )
            *(_DWORD *)(this + 20) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 20) & 4) == 0 )
            *(_DWORD *)(this + 20) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 20) & 8) == 0 )
            *(_DWORD *)(this + 20) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 20) & 0x10) == 0 )
            *(_DWORD *)(this + 20) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
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
        goto LABEL_22;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10149D80
// ============================================================
//----- (10149D80) --------------------------------------------------------
int __thiscall sub_10149D80(_DWORD *this, _DWORD *a2, int a3)
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
  *(_DWORD *)((char *)this + 54694) = 0;
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
        if ( (*((_BYTE *)v3 + 54694) & 1) == 0 )
          *(_DWORD *)((char *)v3 + 54694) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, v3);
      }
      else
      {
        if ( v14 >> 4 == 2 )
        {
          if ( (*(_DWORD *)((char *)v3 + 54694) & 2) == 0 )
            *(_DWORD *)((char *)v3 + 54694) |= 2u;
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
              v4 = sub_10146520((int)v12, a2, v15);
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
            v12 = (_DWORD *)((char *)v12 + 3646);
            if ( ++v8 >= 15 )
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
// Address Name: SUB_1014AE00
// ============================================================
//----- (1014AE00) --------------------------------------------------------
int __thiscall sub_1014AE00(int this, _DWORD *a2, int a3)
{
  int result; // eax
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  unsigned int v12; // [esp+1Ch] [ebp-4h]

  result = 0;
  v9 = 0;
  *(_DWORD *)(this + 126) = 0;
  v5 = a2[1] + a3;
  v12 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_29;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      return result;
    switch ( v9 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 126) & 1) == 0 )
          *(_DWORD *)(this + 126) |= 1u;
        result = TdrBuf::ReadInt32(a2, (_BYTE *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 126) & 2) == 0 )
          *(_DWORD *)(this + 126) |= 2u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 4));
        goto LABEL_27;
      case 3u:
        if ( (*(_DWORD *)(this + 126) & 4) == 0 )
          *(_DWORD *)(this + 126) |= 4u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)(this + 5));
        goto LABEL_27;
      case 4u:
        if ( (*(_DWORD *)(this + 126) & 8) == 0 )
          *(_DWORD *)(this + 126) |= 8u;
        v8 = 0;
        result = TdrBuf::ReadInt32(a2, &v8);
        if ( result )
          return result;
        if ( !v8 )
          return -37;
        v6 = 0;
        v11 = a2[1];
        while ( 1 )
        {
          v10 = 0;
          result = TdrBuf::ReadInt32(a2, &v10);
          if ( result )
            return result;
          if ( v10 )
          {
            result = sub_1014A500(this + 6 + 12 * v6, a2, v10);
            if ( result )
              return result;
          }
          v7 = a2[1];
          if ( v7 > v11 + v8 )
            return -34;
          if ( v7 == v11 + v8 )
            break;
          if ( ++v6 >= 0xAu )
            goto LABEL_28;
        }
        *(_BYTE *)(this + 5) = v6 + 1;
LABEL_28:
        v5 = v12;
        if ( a2[1] < v12 )
          continue;
LABEL_29:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v9 & 0xF);
LABEL_27:
        if ( !result )
          goto LABEL_28;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014BE50
// ============================================================
//----- (1014BE50) --------------------------------------------------------
int __thiscall sub_1014BE50(unsigned int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  unsigned int *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  _DWORD *v15; // edx
  char *v16; // eax
  char *v17; // ecx
  int v18; // eax
  _DWORD *v19; // edx
  char *v20; // eax
  char *v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  char *v24; // [esp+Ch] [ebp-18h]
  int v25; // [esp+10h] [ebp-14h] BYREF
  int v26; // [esp+14h] [ebp-10h] BYREF
  int v27; // [esp+18h] [ebp-Ch]
  unsigned int v28; // [esp+1Ch] [ebp-8h] BYREF
  unsigned int *v29; // [esp+20h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v29 = this;
  *(this + 1793) = 0;
  v28 = 0;
  v7 = (char *)v3 + v6[1];
  v24 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_61;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (v4[1793] & 1) == 0 )
          v4[1793] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_59;
      case 3u:
        if ( (v4[1793] & 2) == 0 )
          v4[1793] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        do
        {
          Byte = TdrBuf::ReadInt32(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v27 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v27) )
            goto LABEL_17;
          ++v10;
          v11 = ++a3;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 4u:
        if ( (v4[1793] & 4) == 0 )
          v4[1793] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 513;
        do
        {
          v14 = TdrBuf::ReadInt32(v6, &v26);
          v15 = a3;
          Byte = v14;
          if ( v14 )
            return Byte;
          v16 = (char *)a2 + v27;
          *a3 = v26;
          v17 = (char *)v6[1];
          if ( v17 > v16 )
            return -34;
          if ( v17 == v16 )
            goto LABEL_17;
          ++v10;
          a3 = v15 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 5u:
        if ( (v4[1793] & 8) == 0 )
          v4[1793] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v27 = v6[1];
        a3 = v29 + 1025;
        do
        {
          v18 = TdrBuf::ReadInt32(v6, &v25);
          v19 = a3;
          Byte = v18;
          if ( v18 )
            return Byte;
          v20 = (char *)a2 + v27;
          *a3 = v25;
          v21 = (char *)v6[1];
          if ( v21 > v20 )
            return -34;
          if ( v21 == v20 )
            goto LABEL_17;
          ++v10;
          a3 = v19 + 1;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 6u:
        if ( (v4[1793] & 0x10) == 0 )
          v4[1793] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6148);
          if ( Byte )
            return Byte;
          v22 = v6[1];
          if ( (_DWORD *)v22 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v22 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
            goto LABEL_17;
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
        goto LABEL_60;
      case 7u:
        if ( (v4[1793] & 0x20) == 0 )
          v4[1793] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v29 + v10 + 6660);
          if ( Byte )
            return Byte;
          v23 = v6[1];
          if ( (_DWORD *)v23 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v23 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_17:
            v13 = v10 + 1;
            v4 = v29;
            *v29 = v13;
            goto LABEL_60;
          }
          ++v10;
        }
        while ( v10 < 0x200 );
        v4 = v29;
LABEL_60:
        v7 = v24;
        if ( v6[1] < (unsigned int)v24 )
          continue;
LABEL_61:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_59:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_60;
        return Byte;
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
// Address Name: SUB_10149FE0
// ============================================================
//----- (10149FE0) --------------------------------------------------------
int __thiscall sub_10149FE0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  __int16 *i; // edi

  result = print_field(a2, a3, a4, "[entrustGroupStatCount]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 15 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (__int16 *)(this + 1); ; i += 1823 )
          {
            if ( !"[entrustGroupStatInfo]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[entrustGroupStatInfo]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_101468D0(i, a2, a3 + 1, a4) : sub_101468D0(i, a2, a3, a4);
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
// Address Name: SUB_1014B090
// ============================================================
//----- (1014B090) --------------------------------------------------------
int __thiscall sub_1014B090(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v6; // al
  unsigned __int8 v7; // bl
  int v8; // [esp-8h] [ebp-18h]

  result = print_field(a2, a3, a4, "[lastRefreshTm]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[rewardCnt]", "0x%02x", (unsigned __int8)*(this + 4));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[levelCnt]", "0x%02x", (unsigned __int8)*(this + 5));
      if ( !result )
      {
        v6 = *(this + 5);
        if ( v6 <= 0xAu )
        {
          v7 = 0;
          if ( v6 )
          {
            while ( 1 )
            {
              if ( !"[warningData]" )
                _wassert(
                  L"NULL != variable",
                  L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                  0x43u);
              result = sub_1024A140(a3);
              if ( result )
                break;
              result = Printf(a2, "%s[%u]%c", "[warningData]", v7, a4);
              if ( result )
                break;
              v8 = a3 >= 0 ? a3 + 1 : a3;
              result = sub_1014A6A0(this + 12 * v7 + 6, a2, v8, a4);
              if ( result )
                break;
              if ( ++v7 >= *(this + 5) )
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
// Address Name: SUB_1014C2E0
// ============================================================
//----- (1014C2E0) --------------------------------------------------------
int __thiscall sub_1014C2E0(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  unsigned int v8; // ebx
  _DWORD *v9; // eax
  int v10; // ecx
  unsigned int v11; // ebx
  float *v12; // eax
  int v13; // ecx
  unsigned int v14; // ebx
  float *v15; // eax
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  int v20; // [esp+1Ch] [ebp+8h]
  int v21; // [esp+1Ch] [ebp+8h]
  int v22; // [esp+1Ch] [ebp+8h]

  result = print_field(a2, a3, a4, "[monsterCnt]", "%u", *this);
  if ( !result )
  {
    if ( *this > 0x200 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[monsterId]", *this);
    if ( !result )
    {
      v8 = 0;
      if ( *this )
      {
        v9 = this + 1;
        v20 = (int)(this + 1);
        while ( 1 )
        {
          result = Printf(a2, " %u", *v9);
          if ( result )
            break;
          ++v8;
          v9 = (_DWORD *)(v20 + 4);
          v20 += 4;
          if ( v8 >= *this )
            goto LABEL_9;
        }
      }
      else
      {
LABEL_9:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          if ( *this > 0x200 )
            return -7;
          result = sub_1024A3B0(a2, a3, v10, "[maxSize]", *this);
          if ( !result )
          {
            v11 = 0;
            if ( *this )
            {
              v12 = (float *)(this + 513);
              v21 = (int)(this + 513);
              while ( 1 )
              {
                result = Printf(a2, " %f", *v12);
                if ( result )
                  break;
                ++v11;
                v12 = (float *)(v21 + 4);
                v21 += 4;
                if ( v11 >= *this )
                  goto LABEL_16;
              }
            }
            else
            {
LABEL_16:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                if ( *this > 0x200 )
                  return -7;
                result = sub_1024A3B0(a2, a3, v13, "[minSize]", *this);
                if ( !result )
                {
                  v14 = 0;
                  if ( *this )
                  {
                    v15 = (float *)(this + 1025);
                    v22 = (int)(this + 1025);
                    while ( 1 )
                    {
                      result = Printf(a2, " %f", *v15);
                      if ( result )
                        break;
                      ++v14;
                      v15 = (float *)(v22 + 4);
                      v22 += 4;
                      if ( v14 >= *this )
                        goto LABEL_23;
                    }
                  }
                  else
                  {
LABEL_23:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( !result )
                    {
                      if ( *this > 0x200 )
                        return -7;
                      result = sub_1024A3B0(a2, a3, v16, "[maxFlag]", *this);
                      if ( !result )
                      {
                        v17 = 0;
                        if ( *this )
                        {
                          while ( 1 )
                          {
                            result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v17 + 6148));
                            if ( result )
                              break;
                            if ( ++v17 >= *this )
                              goto LABEL_29;
                          }
                        }
                        else
                        {
LABEL_29:
                          result = TdrBuf::WriteChar(a2, a4);
                          if ( !result )
                          {
                            if ( *this > 0x200 )
                              return -7;
                            result = sub_1024A3B0(a2, a3, v18, "[minFlag]", *this);
                            if ( !result )
                            {
                              v19 = 0;
                              if ( *this )
                              {
                                while ( 1 )
                                {
                                  result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v19 + 6660));
                                  if ( result )
                                    break;
                                  if ( ++v19 >= *this )
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
            }
          }
        }
      }
    }
  }
  return result;
}
// 1014C331: variable 'v7' is possibly undefined
// 1014C39F: variable 'v10' is possibly undefined
// 1014C420: variable 'v13' is possibly undefined
// 1014C4A0: variable 'v16' is possibly undefined
// 1014C509: variable 'v18' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101446E0
// ============================================================
//----- (101446E0) --------------------------------------------------------
int __thiscall sub_101446E0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[hubId]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[pageIndex]", "%d", *(_DWORD *)(this + 1));
    if ( !result )
      return print_field(a2, a3, a4, "[starLv]", "%d", *(_DWORD *)(this + 5));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014E300
// ============================================================
//----- (1014E300) --------------------------------------------------------
int __thiscall sub_1014E300(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iLastResetTime]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iGainChallangeRewardTimes]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iGainSuccessRewardTimes]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iGainVipChallangeRewardTimes]", "%d", *(this + 3));
        if ( !result )
          return print_field(a2, a3, a4, "[iGainVipSuccessRewardTimes]", "%d", *(this + 4));
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10143850
// ============================================================
//----- (10143850) --------------------------------------------------------
int __thiscall sub_10143850(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[hubId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[pageIndex]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014D8B0
// ============================================================
//----- (1014D8B0) --------------------------------------------------------
int __thiscall sub_1014D8B0(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int16 v6; // bx
  unsigned __int16 v7; // bx
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // bx
  unsigned __int16 v10; // bx
  unsigned __int16 v11; // bx

  result = print_field(a2, a3, a4, "[levelCnt]", "%d", *this);
  if ( !result )
  {
    if ( *this > 0x1388u )
      return -7;
    result = sub_1024A3B0(a2, a3, 5000, "[levelID]", *this);
    if ( !result )
    {
      v6 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          result = Printf(a2, " %u", *(_DWORD *)(this + 2 * v6 + 1));
          if ( result )
            break;
          if ( ++v6 >= *this )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          if ( *this > 0x1388u )
            return -7;
          result = sub_1024A3B0(a2, a3, 5000, "[theBestScore]", *this);
          if ( !result )
          {
            v7 = 0;
            if ( *this )
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *(this + v7 + 10001));
                if ( result )
                  break;
                if ( ++v7 >= *this )
                  goto LABEL_14;
              }
            }
            else
            {
LABEL_14:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                if ( *this > 0x1388u )
                  return -7;
                result = sub_1024A3B0(a2, a3, 5000, "[state]", *this);
                if ( !result )
                {
                  v8 = 0;
                  if ( *this )
                  {
                    while ( 1 )
                    {
                      result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v8 + 30002));
                      if ( result )
                        break;
                      if ( ++v8 >= *this )
                        goto LABEL_20;
                    }
                  }
                  else
                  {
LABEL_20:
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( !result )
                    {
                      if ( *this > 0x1388u )
                        return -7;
                      result = sub_1024A3B0(a2, a3, 5000, "[historyFinalRank]", *this);
                      if ( !result )
                      {
                        v9 = 0;
                        if ( *this )
                        {
                          while ( 1 )
                          {
                            result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v9 + 35002));
                            if ( result )
                              break;
                            if ( ++v9 >= *this )
                              goto LABEL_26;
                          }
                        }
                        else
                        {
LABEL_26:
                          result = TdrBuf::WriteChar(a2, a4);
                          if ( !result )
                          {
                            if ( *this > 0x1388u )
                              return -7;
                            result = sub_1024A3B0(a2, a3, 5000, "[gainRewardFlag]", *this);
                            if ( !result )
                            {
                              v10 = 0;
                              if ( *this )
                              {
                                while ( 1 )
                                {
                                  result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v10 + 40002));
                                  if ( result )
                                    break;
                                  if ( ++v10 >= *this )
                                    goto LABEL_32;
                                }
                              }
                              else
                              {
LABEL_32:
                                result = TdrBuf::WriteChar(a2, a4);
                                if ( !result )
                                {
                                  if ( *this > 0x1388u )
                                    return -7;
                                  result = sub_1024A3B0(a2, a3, 5000, "[lastTm]", *this);
                                  if ( !result )
                                  {
                                    v11 = 0;
                                    if ( *this )
                                    {
                                      while ( 1 )
                                      {
                                        result = Printf(a2, " %u", *(_DWORD *)(this + 2 * v11 + 22501));
                                        if ( result )
                                          break;
                                        if ( ++v11 >= *this )
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
// Address Name: SUB_10143F70
// ============================================================
//----- (10143F70) --------------------------------------------------------
int __thiscall sub_10143F70(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[hubId]", "0x%02x", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[pageIndex]", "%d", *(_DWORD *)(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10144E00
// ============================================================
//----- (10144E00) --------------------------------------------------------
int __thiscall sub_10144E00(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[levelID]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[seconds]", "%d", *(this + 2));
    if ( !result )
      return print_field(a2, a3, a4, "[layer]", "%d", (__int16)*(this + 3));
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014A460
// ============================================================
//----- (1014A460) --------------------------------------------------------
int __thiscall sub_1014A460(int *this, _DWORD *a2, int a3)
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
// Address Name: SUB_10146240
// ============================================================
//----- (10146240) --------------------------------------------------------
int __thiscall sub_10146240(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  unsigned int v10; // edx
  __int16 v11; // di
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 3642) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 3642) & 1) == 0 )
          *(_DWORD *)(this + 3642) |= 1u;
        result = TdrBuf::ReadVarInt(v6, (int *)this);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(this + 3642) & 2) == 0 )
          *(_DWORD *)(this + 3642) |= 2u;
        result = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 4));
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 3642) & 4) == 0 )
          *(_DWORD *)(this + 3642) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v6[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte(v6, (_BYTE *)(this + v8 + 6));
          if ( result )
            return result;
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_49;
            continue;
          }
          goto LABEL_20;
        }
      case 4u:
        if ( (*(_DWORD *)(this + 3642) & 8) == 0 )
          *(_DWORD *)(this + 3642) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v6[1];
        while ( 2 )
        {
          result = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 4 * (v8 + 4)));
          if ( result )
            return result;
          v10 = v6[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_49;
            continue;
          }
          break;
        }
LABEL_20:
        *(_WORD *)(this + 4) = v8 + 1;
        goto LABEL_49;
      case 5u:
        if ( (*(_DWORD *)(this + 3642) & 0x10) == 0 )
          *(_DWORD *)(this + 3642) |= 0x10u;
        result = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(this + 3642) & 0x20) == 0 )
          *(_DWORD *)(this + 3642) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v11 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10145430(v6, a3);
            if ( result )
              return result;
          }
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v11 >= 64 )
            goto LABEL_49;
        }
        *(_WORD *)(this + 56) = v11 + 1;
LABEL_49:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_50:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_48:
        if ( !result )
          goto LABEL_49;
        return result;
    }
  }
}
// 10145430: using guessed type _DWORD __stdcall sub_10145430(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10146520
// ============================================================
//----- (10146520) --------------------------------------------------------
int __thiscall sub_10146520(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  __int16 v8; // di
  unsigned int v9; // edx
  unsigned int v10; // edx
  __int16 v11; // di
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 3642) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 3642) & 1) == 0 )
          *(_DWORD *)(this + 3642) |= 1u;
        result = TdrBuf::ReadInt32(v6, (_BYTE *)this);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(this + 3642) & 2) == 0 )
          *(_DWORD *)(this + 3642) |= 2u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 4));
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 3642) & 4) == 0 )
          *(_DWORD *)(this + 3642) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v6[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte(v6, (_BYTE *)(this + v8 + 6));
          if ( result )
            return result;
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_49;
            continue;
          }
          goto LABEL_20;
        }
      case 4u:
        if ( (*(_DWORD *)(this + 3642) & 8) == 0 )
          *(_DWORD *)(this + 3642) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        a3 = v6[1];
        while ( 2 )
        {
          result = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 4 * (v8 + 4)));
          if ( result )
            return result;
          v10 = v6[1];
          if ( v10 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
          {
            if ( ++v8 >= 10 )
              goto LABEL_49;
            continue;
          }
          break;
        }
LABEL_20:
        *(_WORD *)(this + 4) = v8 + 1;
        goto LABEL_49;
      case 5u:
        if ( (*(_DWORD *)(this + 3642) & 0x10) == 0 )
          *(_DWORD *)(this + 3642) |= 0x10u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(this + 3642) & 0x20) == 0 )
          *(_DWORD *)(this + 3642) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v11 = 0;
        v14 = v6[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10145630(this + 58 + 56 * v11, v6, a3);
            if ( result )
              return result;
          }
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v11 >= 64 )
            goto LABEL_49;
        }
        *(_WORD *)(this + 56) = v11 + 1;
LABEL_49:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_50:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_48:
        if ( !result )
          goto LABEL_49;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014A500
// ============================================================
//----- (1014A500) --------------------------------------------------------
int __thiscall sub_1014A500(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_101468D0
// ============================================================
//----- (101468D0) --------------------------------------------------------
int __thiscall sub_101468D0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  __int16 v9; // di
  __int16 v10; // ax
  __int16 v11; // di
  int v12; // eax

  result = print_field(a2, a3, a4, "[groupID]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[groupStatCnt]", "%d", *(this + 2));
    if ( !result )
    {
      v6 = *(this + 2);
      if ( v6 < 0 )
        return -6;
      if ( v6 > 10 )
        return -7;
      result = sub_1024A3B0(a2, a3, 10, "[groupStatType]", v6);
      if ( !result )
      {
        v7 = 0;
        if ( *(this + 2) <= 0 )
        {
LABEL_11:
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v8 = *(this + 2);
          if ( v8 < 0 )
            return -6;
          if ( v8 <= 10 )
          {
            result = sub_1024A3B0(a2, a3, 10, "[groupStatValue]", v8);
            if ( result )
              return result;
            v9 = 0;
            if ( *(this + 2) > 0 )
            {
              do
              {
                result = Printf(a2, " %u", *((_DWORD *)this + v9 + 4));
                if ( result )
                  return result;
              }
              while ( ++v9 < *(this + 2) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            result = print_field(a2, a3, a4, "[groupLevelCnt]", "%d", *(this + 28));
            if ( result )
              return result;
            v10 = *(this + 28);
            if ( v10 < 0 )
              return -6;
            if ( v10 <= 64 )
            {
              v11 = 0;
              if ( v10 <= 0 )
                return 0;
              while ( 1 )
              {
                result = sub_1024A230(a2, a3, a4, "[entrustLevelStat]", v11);
                if ( result )
                  break;
                v12 = a3;
                if ( a3 >= 0 )
                  v12 = a3 + 1;
                result = sub_10145900(this + 28 * v11 + 29, a2, v12, a4);
                if ( result )
                  break;
                if ( ++v11 >= *(this + 28) )
                  return 0;
              }
              return result;
            }
          }
          return -7;
        }
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v7 + 6));
          if ( result )
            break;
          if ( ++v7 >= *(this + 2) )
            goto LABEL_11;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1014A6A0
// ============================================================
//----- (1014A6A0) --------------------------------------------------------
int __thiscall sub_1014A6A0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[levelId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[warningTime]", "%u", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10145430
// ============================================================
//----- (10145430) --------------------------------------------------------
int __thiscall sub_10145430(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarShort; // eax
  __int16 v10; // di
  int VarUInt; // edx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+10h] [ebp-8h]
  unsigned int v20; // [esp+14h] [ebp-4h] BYREF
  int v21; // [esp+20h] [ebp+8h]

  v3 = a3;
  v6 = 0;
  v20 = 0;
  *(_DWORD *)(this + 52) = 0;
  v7 = a2[1] + v3;
  v17 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_36:
    if ( a2[1] > v7 )
      return -34;
    return v6;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v20);
    if ( result )
      return result;
    if ( v20 >> 4 != 1 )
      break;
    if ( (*(_BYTE *)(this + 52) & 1) == 0 )
      *(_DWORD *)(this + 52) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_33:
    VarUInt = VarShort;
    v21 = VarShort;
    if ( VarShort )
      return VarUInt;
LABEL_34:
    v7 = v17;
    if ( a2[1] >= v17 )
    {
      v6 = v21;
      goto LABEL_36;
    }
  }
  if ( v20 >> 4 == 2 )
  {
    if ( (*(_DWORD *)(this + 52) & 2) == 0 )
      *(_DWORD *)(this + 52) |= 2u;
    a3 = 0;
    result = TdrBuf::ReadInt32(a2, &a3);
    if ( result )
      return result;
    if ( a3 )
    {
      v10 = 0;
      v19 = a2[1];
      v21 = 0;
      while ( 1 )
      {
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v13 = a2[1];
        if ( a2[2] == v13 )
          return -2;
        *(_BYTE *)(v10 + this + 2) = *(_BYTE *)(v13 + *a2);
        v14 = a3;
        ++a2[1];
        v15 = v19 + v14;
        v16 = a2[1];
        if ( v16 > v15 )
          return -34;
        if ( v16 == v15 )
        {
LABEL_29:
          *(_WORD *)this = v10 + 1;
          goto LABEL_34;
        }
        if ( ++v10 >= 10 )
          goto LABEL_34;
      }
    }
    return -37;
  }
  if ( v20 >> 4 != 3 )
  {
    VarShort = TdrBuf::SkipField(a2, v20 & 0xF);
    goto LABEL_33;
  }
  if ( (*(_DWORD *)(this + 52) & 4) == 0 )
    *(_DWORD *)(this + 52) |= 4u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v10 = 0;
  v18 = a2[1];
  while ( 1 )
  {
    VarUInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 4 * (v10 + 3)));
    v21 = VarUInt;
    if ( VarUInt )
      return VarUInt;
    v12 = a2[1];
    if ( v12 > v18 + a3 )
      return -34;
    if ( v12 == v18 + a3 )
      goto LABEL_29;
    if ( ++v10 >= 10 )
      goto LABEL_34;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10145630
// ============================================================
//----- (10145630) --------------------------------------------------------
int __thiscall sub_10145630(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int16; // eax
  __int16 v10; // di
  int Int32; // edx
  unsigned int v12; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  int v19; // [esp+10h] [ebp-8h]
  unsigned int v20; // [esp+14h] [ebp-4h] BYREF
  int v21; // [esp+20h] [ebp+8h]

  v3 = a3;
  v6 = 0;
  v20 = 0;
  *(_DWORD *)(this + 52) = 0;
  v7 = a2[1] + v3;
  v17 = v7;
  if ( a2[1] >= v7 )
  {
LABEL_36:
    if ( a2[1] > v7 )
      return -34;
    return v6;
  }
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v20);
    if ( result )
      return result;
    if ( v20 >> 4 != 1 )
      break;
    if ( (*(_BYTE *)(this + 52) & 1) == 0 )
      *(_DWORD *)(this + 52) |= 1u;
    Int16 = TdrBuf::ReadInt16(a2, (_BYTE *)this);
LABEL_33:
    Int32 = Int16;
    v21 = Int16;
    if ( Int16 )
      return Int32;
LABEL_34:
    v7 = v17;
    if ( a2[1] >= v17 )
    {
      v6 = v21;
      goto LABEL_36;
    }
  }
  if ( v20 >> 4 == 2 )
  {
    if ( (*(_DWORD *)(this + 52) & 2) == 0 )
      *(_DWORD *)(this + 52) |= 2u;
    a3 = 0;
    result = TdrBuf::ReadInt32(a2, &a3);
    if ( result )
      return result;
    if ( a3 )
    {
      v10 = 0;
      v19 = a2[1];
      v21 = 0;
      while ( 1 )
      {
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v13 = a2[1];
        if ( a2[2] == v13 )
          return -2;
        *(_BYTE *)(v10 + this + 2) = *(_BYTE *)(v13 + *a2);
        v14 = a3;
        ++a2[1];
        v15 = v19 + v14;
        v16 = a2[1];
        if ( v16 > v15 )
          return -34;
        if ( v16 == v15 )
        {
LABEL_29:
          *(_WORD *)this = v10 + 1;
          goto LABEL_34;
        }
        if ( ++v10 >= 10 )
          goto LABEL_34;
      }
    }
    return -37;
  }
  if ( v20 >> 4 != 3 )
  {
    Int16 = TdrBuf::SkipField(a2, v20 & 0xF);
    goto LABEL_33;
  }
  if ( (*(_DWORD *)(this + 52) & 4) == 0 )
    *(_DWORD *)(this + 52) |= 4u;
  a3 = 0;
  result = TdrBuf::ReadInt32(a2, &a3);
  if ( result )
    return result;
  if ( !a3 )
    return -37;
  v10 = 0;
  v18 = a2[1];
  while ( 1 )
  {
    Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4 * (v10 + 3)));
    v21 = Int32;
    if ( Int32 )
      return Int32;
    v12 = a2[1];
    if ( v12 > v18 + a3 )
      return -34;
    if ( v12 == v18 + a3 )
      goto LABEL_29;
    if ( ++v10 >= 10 )
      goto LABEL_34;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10145900
// ============================================================
//----- (10145900) --------------------------------------------------------
int __thiscall sub_10145900(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  __int16 v6; // ax
  __int16 v7; // di
  __int16 v8; // ax
  __int16 v9; // di

  result = print_field(a2, a3, a4, "[levelStatCnt]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this < 0 )
      return -6;
    if ( v6 > 10 )
      return -7;
    result = sub_1024A3B0(a2, a3, 10, "[levelStatType]", v6);
    if ( !result )
    {
      v7 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          v8 = *this;
          if ( *this < 0 )
            return -6;
          if ( v8 > 10 )
            return -7;
          result = sub_1024A3B0(a2, a3, 10, "[levelStatValue]", v8);
          if ( !result )
          {
            v9 = 0;
            if ( *this <= 0 )
            {
              return TdrBuf::WriteChar(a2, a4);
            }
            else
            {
              while ( 1 )
              {
                result = Printf(a2, " %u", *((_DWORD *)this + v9 + 3));
                if ( result )
                  break;
                if ( ++v9 >= *this )
                  return TdrBuf::WriteChar(a2, a4);
              }
            }
          }
        }
      }
      else
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v7 + 2));
          if ( result )
            break;
          if ( ++v7 >= *this )
            goto LABEL_10;
        }
      }
    }
  }
  return result;
}



