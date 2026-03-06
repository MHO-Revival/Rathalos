// ============================================================
// Name: TLV::UnkTlv0195::Read
// Address Name: SUB_101E38B0
// ============================================================
//----- (101E38B0) --------------------------------------------------------
int __thiscall sub_101E38B0(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_101E3980((int)this, &v9, v8);
  else
    result = sub_101E6B40((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0195::Read_0xAA
// Address Name: SUB_101E3980
// ============================================================
//----- (101E3980) --------------------------------------------------------
int __thiscall sub_101E3980(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  int VarInt; // edx
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // edi
  unsigned int v10; // eax
  int *v11; // eax
  int VarShort; // eax
  unsigned int v13; // edi
  int *v14; // ebx
  unsigned int v15; // ecx
  unsigned int v16; // edi
  int *v17; // ebx
  unsigned int v18; // ecx
  unsigned int v19; // edi
  int *v20; // ebx
  unsigned int v21; // ecx
  unsigned int v22; // edi
  int *v23; // ebx
  unsigned int v24; // ecx
  unsigned int v25; // edi
  int *v26; // ebx
  unsigned int v27; // ecx
  unsigned int v28; // edi
  int *v29; // ebx
  unsigned int v30; // ecx
  unsigned int v31; // ebx
  _DWORD *v32; // edi
  char *v33; // eax
  char *v34; // ecx
  unsigned int v35; // ebx
  _DWORD *v36; // edi
  char *v37; // eax
  char *v38; // ecx
  unsigned int v39; // edi
  int *v40; // ebx
  unsigned int v41; // ecx
  unsigned int v42; // edi
  int *v43; // ebx
  unsigned int v44; // ecx
  unsigned int v45; // edi
  int *v46; // ebx
  unsigned int v47; // ecx
  unsigned int v48; // edi
  int *v49; // ebx
  unsigned int v50; // ecx
  unsigned int v51; // edi
  int *v52; // ebx
  unsigned int v53; // ecx
  unsigned int v54; // edi
  int *v55; // ebx
  unsigned int v56; // ecx
  unsigned int v57; // edi
  int *v58; // ebx
  unsigned int v59; // ecx
  unsigned int v60; // edi
  int *v61; // ebx
  unsigned int v62; // ecx
  unsigned int v63; // edi
  int *v64; // ebx
  unsigned int v65; // ecx
  unsigned int v66; // edi
  int *v67; // ebx
  unsigned int v68; // ecx
  unsigned int v69; // edi
  int *v70; // ebx
  unsigned int v71; // ecx
  unsigned int v72; // edi
  int *v73; // ebx
  unsigned int v74; // ecx
  unsigned int v75; // edi
  int *v76; // ebx
  unsigned int v77; // ecx
  unsigned int v78; // edi
  int *v79; // ebx
  unsigned int v80; // ecx
  unsigned int v81; // edi
  int *v82; // ebx
  unsigned int v83; // ecx
  unsigned int v84; // edi
  int *v85; // ebx
  unsigned int v86; // ecx
  unsigned int v87; // edi
  int *v88; // ebx
  unsigned int v89; // ecx
  unsigned int v90; // edi
  int *v91; // ebx
  unsigned int v92; // ecx
  unsigned int v93; // edi
  int *v94; // ebx
  unsigned int v95; // ecx
  unsigned int v96; // edi
  int *v97; // ebx
  unsigned int v98; // ecx
  unsigned int v99; // edi
  int *v100; // ebx
  unsigned int v101; // ecx
  unsigned int v102; // edi
  int *v103; // ebx
  unsigned int v104; // ecx
  unsigned int v105; // edi
  int *v106; // ebx
  unsigned int v107; // ecx
  unsigned int v108; // edi
  int *v109; // ebx
  unsigned int v110; // ecx
  unsigned int v111; // edi
  int *v112; // ebx
  unsigned int v113; // ecx
  unsigned int v114; // ebx
  _DWORD *v115; // edi
  char *v116; // eax
  char *v117; // ecx
  unsigned int v118; // ebx
  _DWORD *v119; // edi
  char *v120; // eax
  char *v121; // ecx
  unsigned int v122; // edi
  int *v123; // ebx
  unsigned int v124; // ecx
  unsigned int v125; // edi
  int *v126; // ebx
  unsigned int v127; // ecx
  unsigned int v128; // edi
  int *v129; // ebx
  unsigned int v130; // ecx
  unsigned int v131; // edi
  int *v132; // ebx
  unsigned int v133; // ecx
  unsigned int v134; // ebx
  _DWORD *v135; // edi
  char *v136; // eax
  char *v137; // ecx
  unsigned int v138; // ebx
  _DWORD *v139; // edi
  char *v140; // eax
  char *v141; // ecx
  unsigned int v142; // edi
  int *v143; // ebx
  unsigned int v144; // ecx
  unsigned int v145; // edi
  int *v146; // ebx
  unsigned int v147; // ecx
  unsigned int v148; // [esp+0h] [ebp-24h]
  int v149; // [esp+4h] [ebp-20h] BYREF
  int v150; // [esp+8h] [ebp-1Ch] BYREF
  int v151; // [esp+Ch] [ebp-18h] BYREF
  int v152; // [esp+10h] [ebp-14h] BYREF
  int v153; // [esp+14h] [ebp-10h] BYREF
  int v154; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v155; // [esp+1Ch] [ebp-8h] BYREF
  int *v156; // [esp+20h] [ebp-4h]

  v3 = a3;
  v4 = (int *)this;
  VarInt = 0;
  v6 = a2;
  *(_OWORD *)(this + 1656) = 0;
  v156 = (int *)this;
  *(_QWORD *)(this + 1672) = 0;
  v7 = v6[1] + v3;
  v155 = 0;
  v148 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_15:
    if ( v6[1] > v7 )
      return -34;
    return VarInt;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v155);
    if ( result )
      return result;
    switch ( v155 >> 4 )
    {
      case 2u:
        if ( (v4[414] & 1) == 0 )
          v4[414] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( !result )
        {
          if ( !a2 )
            goto LABEL_865;
          v9 = 0;
          a3 = v6[1];
          while ( 1 )
          {
            VarInt = TdrBuf::ReadVarInt(v6, v4);
            if ( VarInt )
              return VarInt;
            v10 = v6[1];
            if ( v10 > (unsigned int)a2 + a3 )
              goto LABEL_864;
            if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + a3) )
            {
              ++v9;
              ++v4;
              if ( v9 < 7 )
                continue;
            }
            goto LABEL_13;
          }
        }
        return result;
      case 4u:
        if ( (v4[414] & 2) == 0 )
          v4[414] |= 2u;
        v11 = v4 + 7;
        goto LABEL_22;
      case 6u:
        if ( (v4[414] & 4) == 0 )
          v4[414] |= 4u;
        v11 = v4 + 8;
        goto LABEL_22;
      case 7u:
        if ( (v4[414] & 8) == 0 )
          v4[414] |= 8u;
        v11 = v4 + 9;
        goto LABEL_22;
      case 8u:
        if ( (v4[414] & 0x10) == 0 )
          v4[414] |= 0x10u;
        v11 = v4 + 10;
        goto LABEL_22;
      case 9u:
        if ( (v4[414] & 0x20) == 0 )
          v4[414] |= 0x20u;
        v11 = v4 + 11;
        goto LABEL_22;
      case 0xAu:
        if ( (v4[414] & 0x40) == 0 )
          v4[414] |= 0x40u;
        v11 = v4 + 12;
        goto LABEL_22;
      case 0xBu:
        if ( (v4[414] & 0x80) == 0 )
          v4[414] |= 0x80u;
        v11 = v4 + 13;
        goto LABEL_22;
      case 0xCu:
        if ( (v4[414] & 0x100) == 0 )
          v4[414] |= 0x100u;
        v11 = v4 + 14;
        goto LABEL_22;
      case 0xDu:
        if ( (v4[414] & 0x200) == 0 )
          v4[414] |= 0x200u;
        v11 = v4 + 15;
        goto LABEL_22;
      case 0xEu:
        if ( (v4[414] & 0x400) == 0 )
          v4[414] |= 0x400u;
        v11 = v4 + 16;
        goto LABEL_22;
      case 0xFu:
        if ( (v4[414] & 0x800) == 0 )
          v4[414] |= 0x800u;
        v11 = v4 + 17;
        goto LABEL_22;
      case 0x10u:
        if ( (v4[414] & 0x1000) == 0 )
          v4[414] |= 0x1000u;
        v11 = v4 + 18;
        goto LABEL_22;
      case 0x11u:
        if ( (v4[414] & 0x2000) == 0 )
          v4[414] |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v13 = 0;
        a3 = v6[1];
        v14 = v4 + 19;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v14);
          if ( VarInt )
            return VarInt;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v13;
            ++v14;
            if ( v13 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x14u:
        if ( (v4[414] & 0x4000) == 0 )
          v4[414] |= 0x4000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 52);
        goto LABEL_23;
      case 0x16u:
        if ( (v4[414] & 0x8000) == 0 )
          v4[414] |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v16 = 0;
        a3 = v6[1];
        v17 = (int *)((char *)v4 + 106);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v17);
          if ( VarInt )
            return VarInt;
          v18 = v6[1];
          if ( v18 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v18 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v16;
            ++v17;
            if ( v16 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Au:
        if ( (v4[414] & 0x10000) == 0 )
          v4[414] |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v19 = 0;
        a3 = v6[1];
        v20 = (int *)((char *)v4 + 134);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v20);
          if ( VarInt )
            return VarInt;
          v21 = v6[1];
          if ( v21 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v21 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v19;
            ++v20;
            if ( v19 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Bu:
        if ( (v4[414] & 0x20000) == 0 )
          v4[414] |= 0x20000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v22 = 0;
        a3 = v6[1];
        v23 = (int *)((char *)v4 + 162);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v23);
          if ( VarInt )
            return VarInt;
          v24 = v6[1];
          if ( v24 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v24 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v22;
            ++v23;
            if ( v22 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Cu:
        if ( (v4[414] & 0x40000) == 0 )
          v4[414] |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v25 = 0;
        a3 = v6[1];
        v26 = (int *)((char *)v4 + 190);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v26);
          if ( VarInt )
            return VarInt;
          v27 = v6[1];
          if ( v27 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v27 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v25;
            ++v26;
            if ( v25 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Du:
        if ( (v4[414] & 0x80000) == 0 )
          v4[414] |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v28 = 0;
        a3 = v6[1];
        v29 = (int *)((char *)v4 + 218);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v29);
          if ( VarInt )
            return VarInt;
          v30 = v6[1];
          if ( v30 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v30 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v28;
            ++v29;
            if ( v28 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Eu:
        if ( (v4[414] & 0x100000) == 0 )
          v4[414] |= 0x100000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v31 = 0;
        v32 = (int *)((char *)v156 + 246);
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v154);
          if ( VarInt )
            return VarInt;
          v33 = (char *)a2 + a3;
          *v32 = v154;
          v34 = (char *)v6[1];
          if ( v34 > v33 )
            goto LABEL_864;
          if ( v34 != v33 )
          {
            ++v31;
            ++v32;
            if ( v31 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x1Fu:
        if ( (v4[414] & 0x200000) == 0 )
          v4[414] |= 0x200000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v35 = 0;
        v36 = (int *)((char *)v156 + 274);
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v153);
          if ( VarInt )
            return VarInt;
          v37 = (char *)a2 + a3;
          *v36 = v153;
          v38 = (char *)v6[1];
          if ( v38 > v37 )
            goto LABEL_864;
          if ( v38 != v37 )
          {
            ++v35;
            ++v36;
            if ( v35 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x20u:
        if ( (v4[414] & 0x400000) == 0 )
          v4[414] |= 0x400000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v39 = 0;
        a3 = v6[1];
        v40 = (int *)((char *)v4 + 302);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v40);
          if ( VarInt )
            return VarInt;
          v41 = v6[1];
          if ( v41 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v41 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v39;
            ++v40;
            if ( v39 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x21u:
        if ( (v4[414] & 0x800000) == 0 )
          v4[414] |= 0x800000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v42 = 0;
        a3 = v6[1];
        v43 = (int *)((char *)v4 + 330);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v43);
          if ( VarInt )
            return VarInt;
          v44 = v6[1];
          if ( v44 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v44 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v42;
            ++v43;
            if ( v42 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x22u:
        if ( (v4[414] & 0x1000000) == 0 )
          v4[414] |= 0x1000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v45 = 0;
        a3 = v6[1];
        v46 = (int *)((char *)v4 + 358);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v46);
          if ( VarInt )
            return VarInt;
          v47 = v6[1];
          if ( v47 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v47 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v45;
            ++v46;
            if ( v45 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x23u:
        if ( (v4[414] & 0x2000000) == 0 )
          v4[414] |= 0x2000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v48 = 0;
        a3 = v6[1];
        v49 = (int *)((char *)v4 + 386);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v49);
          if ( VarInt )
            return VarInt;
          v50 = v6[1];
          if ( v50 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v50 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v48;
            ++v49;
            if ( v48 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x27u:
        if ( (v4[414] & 0x4000000) == 0 )
          v4[414] |= 0x4000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v51 = 0;
        a3 = v6[1];
        v52 = (int *)((char *)v4 + 414);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v52);
          if ( VarInt )
            return VarInt;
          v53 = v6[1];
          if ( v53 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v53 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v51;
            ++v52;
            if ( v51 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x28u:
        if ( (v4[414] & 0x8000000) == 0 )
          v4[414] |= 0x8000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v54 = 0;
        a3 = v6[1];
        v55 = (int *)((char *)v4 + 442);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v55);
          if ( VarInt )
            return VarInt;
          v56 = v6[1];
          if ( v56 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v56 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v54;
            ++v55;
            if ( v54 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x29u:
        if ( (v4[414] & 0x10000000) == 0 )
          v4[414] |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v57 = 0;
        a3 = v6[1];
        v58 = (int *)((char *)v4 + 470);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v58);
          if ( VarInt )
            return VarInt;
          v59 = v6[1];
          if ( v59 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v59 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v57;
            ++v58;
            if ( v57 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Au:
        if ( (v4[414] & 0x20000000) == 0 )
          v4[414] |= 0x20000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v60 = 0;
        a3 = v6[1];
        v61 = (int *)((char *)v4 + 498);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v61);
          if ( VarInt )
            return VarInt;
          v62 = v6[1];
          if ( v62 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v62 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v60;
            ++v61;
            if ( v60 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Bu:
        if ( (v4[414] & 0x40000000) == 0 )
          v4[414] |= 0x40000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v63 = 0;
        a3 = v6[1];
        v64 = (int *)((char *)v4 + 526);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v64);
          if ( VarInt )
            return VarInt;
          v65 = v6[1];
          if ( v65 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v65 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v63;
            ++v64;
            if ( v63 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Cu:
        if ( v4[414] >= 0 )
          v4[414] |= 0x80000000;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v66 = 0;
        a3 = v6[1];
        v67 = (int *)((char *)v4 + 554);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v67);
          if ( VarInt )
            return VarInt;
          v68 = v6[1];
          if ( v68 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v68 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v66;
            ++v67;
            if ( v66 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Du:
        if ( (v4[415] & 1) == 0 )
          v4[415] |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v69 = 0;
        a3 = v6[1];
        v70 = (int *)((char *)v4 + 582);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v70);
          if ( VarInt )
            return VarInt;
          v71 = v6[1];
          if ( v71 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v71 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v69;
            ++v70;
            if ( v69 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Eu:
        if ( (v4[415] & 2) == 0 )
          v4[415] |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v72 = 0;
        a3 = v6[1];
        v73 = (int *)((char *)v4 + 610);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v73);
          if ( VarInt )
            return VarInt;
          v74 = v6[1];
          if ( v74 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v74 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v72;
            ++v73;
            if ( v72 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x2Fu:
        if ( (v4[415] & 4) == 0 )
          v4[415] |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v75 = 0;
        a3 = v6[1];
        v76 = (int *)((char *)v4 + 638);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v76);
          if ( VarInt )
            return VarInt;
          v77 = v6[1];
          if ( v77 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v77 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v75;
            ++v76;
            if ( v75 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x30u:
        if ( (v4[415] & 8) == 0 )
          v4[415] |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v78 = 0;
        a3 = v6[1];
        v79 = (int *)((char *)v4 + 666);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v79);
          if ( VarInt )
            return VarInt;
          v80 = v6[1];
          if ( v80 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v80 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v78;
            ++v79;
            if ( v78 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x31u:
        if ( (v4[415] & 0x10) == 0 )
          v4[415] |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v81 = 0;
        a3 = v6[1];
        v82 = (int *)((char *)v4 + 694);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v82);
          if ( VarInt )
            return VarInt;
          v83 = v6[1];
          if ( v83 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v83 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v81;
            ++v82;
            if ( v81 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x32u:
        if ( (v4[415] & 0x20) == 0 )
          v4[415] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v84 = 0;
        a3 = v6[1];
        v85 = (int *)((char *)v4 + 722);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v85);
          if ( VarInt )
            return VarInt;
          v86 = v6[1];
          if ( v86 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v86 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v84;
            ++v85;
            if ( v84 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x33u:
        if ( (v4[415] & 0x40) == 0 )
          v4[415] |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v87 = 0;
        a3 = v6[1];
        v88 = (int *)((char *)v4 + 750);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v88);
          if ( VarInt )
            return VarInt;
          v89 = v6[1];
          if ( v89 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v89 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v87;
            ++v88;
            if ( v87 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x34u:
        if ( (v4[415] & 0x80) == 0 )
          v4[415] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v90 = 0;
        a3 = v6[1];
        v91 = (int *)((char *)v4 + 778);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v91);
          if ( VarInt )
            return VarInt;
          v92 = v6[1];
          if ( v92 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v92 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v90;
            ++v91;
            if ( v90 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x44u:
        if ( (v4[415] & 0x100) == 0 )
          v4[415] |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v93 = 0;
        a3 = v6[1];
        v94 = (int *)((char *)v4 + 806);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v94);
          if ( VarInt )
            return VarInt;
          v95 = v6[1];
          if ( v95 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v95 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v93;
            ++v94;
            if ( v93 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x58u:
        if ( (v4[415] & 0x200) == 0 )
          v4[415] |= 0x200u;
        v11 = (int *)((char *)v4 + 834);
        goto LABEL_22;
      case 0x59u:
        if ( (v4[415] & 0x400) == 0 )
          v4[415] |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v96 = 0;
        a3 = v6[1];
        v97 = (int *)((char *)v4 + 838);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v97);
          if ( VarInt )
            return VarInt;
          v98 = v6[1];
          if ( v98 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v98 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v96;
            ++v97;
            if ( v96 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x5Au:
        if ( (v4[415] & 0x800) == 0 )
          v4[415] |= 0x800u;
        v11 = (int *)((char *)v4 + 866);
        goto LABEL_22;
      case 0x5Bu:
        if ( (v4[415] & 0x1000) == 0 )
          v4[415] |= 0x1000u;
        v11 = (int *)((char *)v4 + 870);
        goto LABEL_22;
      case 0x5Cu:
        if ( (v4[415] & 0x2000) == 0 )
          v4[415] |= 0x2000u;
        v11 = (int *)((char *)v4 + 874);
        goto LABEL_22;
      case 0x5Du:
        if ( (v4[415] & 0x4000) == 0 )
          v4[415] |= 0x4000u;
        v11 = (int *)((char *)v4 + 878);
        goto LABEL_22;
      case 0x5Eu:
        if ( (v4[415] & 0x8000) == 0 )
          v4[415] |= 0x8000u;
        v11 = (int *)((char *)v4 + 882);
        goto LABEL_22;
      case 0x5Fu:
        if ( (v4[415] & 0x10000) == 0 )
          v4[415] |= 0x10000u;
        v11 = (int *)((char *)v4 + 886);
        goto LABEL_22;
      case 0x60u:
        if ( (v4[415] & 0x20000) == 0 )
          v4[415] |= 0x20000u;
        v11 = (int *)((char *)v4 + 890);
        goto LABEL_22;
      case 0x61u:
        if ( (v4[415] & 0x40000) == 0 )
          v4[415] |= 0x40000u;
        v11 = (int *)((char *)v4 + 894);
        goto LABEL_22;
      case 0x62u:
        if ( (v4[415] & 0x80000) == 0 )
          v4[415] |= 0x80000u;
        v11 = (int *)((char *)v4 + 898);
        goto LABEL_22;
      case 0x63u:
        if ( (v4[415] & 0x100000) == 0 )
          v4[415] |= 0x100000u;
        v11 = (int *)((char *)v4 + 902);
        goto LABEL_22;
      case 0x6Au:
        if ( (v4[415] & 0x200000) == 0 )
          v4[415] |= 0x200000u;
        v11 = (int *)((char *)v4 + 906);
        goto LABEL_22;
      case 0x6Bu:
        if ( (v4[415] & 0x400000) == 0 )
          v4[415] |= 0x400000u;
        v11 = (int *)((char *)v4 + 910);
        goto LABEL_22;
      case 0x6Cu:
        if ( (v4[415] & 0x800000) == 0 )
          v4[415] |= 0x800000u;
        v11 = (int *)((char *)v4 + 914);
        goto LABEL_22;
      case 0x6Du:
        if ( (v4[415] & 0x1000000) == 0 )
          v4[415] |= 0x1000000u;
        v11 = (int *)((char *)v4 + 918);
        goto LABEL_22;
      case 0x86u:
        if ( (v4[415] & 0x2000000) == 0 )
          v4[415] |= 0x2000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v99 = 0;
        a3 = v6[1];
        v100 = (int *)((char *)v4 + 922);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v100);
          if ( VarInt )
            return VarInt;
          v101 = v6[1];
          if ( v101 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v101 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v99;
            ++v100;
            if ( v99 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x87u:
        if ( (v4[415] & 0x4000000) == 0 )
          v4[415] |= 0x4000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v102 = 0;
        a3 = v6[1];
        v103 = (int *)((char *)v4 + 950);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v103);
          if ( VarInt )
            return VarInt;
          v104 = v6[1];
          if ( v104 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v104 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v102;
            ++v103;
            if ( v102 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x88u:
        if ( (v4[415] & 0x8000000) == 0 )
          v4[415] |= 0x8000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v105 = 0;
        a3 = v6[1];
        v106 = (int *)((char *)v4 + 978);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v106);
          if ( VarInt )
            return VarInt;
          v107 = v6[1];
          if ( v107 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v107 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v105;
            ++v106;
            if ( v105 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x89u:
        if ( (v4[415] & 0x10000000) == 0 )
          v4[415] |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v108 = 0;
        a3 = v6[1];
        v109 = (int *)((char *)v4 + 1006);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v109);
          if ( VarInt )
            return VarInt;
          v110 = v6[1];
          if ( v110 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v110 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v108;
            ++v109;
            if ( v108 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xADu:
        if ( (v4[415] & 0x20000000) == 0 )
          v4[415] |= 0x20000000u;
        v11 = (int *)((char *)v4 + 1034);
        goto LABEL_22;
      case 0xAEu:
        if ( (v4[415] & 0x40000000) == 0 )
          v4[415] |= 0x40000000u;
        v11 = (int *)((char *)v4 + 1038);
        goto LABEL_22;
      case 0xAFu:
        if ( v4[415] >= 0 )
          v4[415] |= 0x80000000;
        v11 = (int *)((char *)v4 + 1042);
        goto LABEL_22;
      case 0xB1u:
        if ( (v4[416] & 1) == 0 )
          v4[416] |= 1u;
        v11 = (int *)((char *)v4 + 1046);
        goto LABEL_22;
      case 0xB2u:
        if ( (v4[416] & 2) == 0 )
          v4[416] |= 2u;
        v11 = (int *)((char *)v4 + 1050);
        goto LABEL_22;
      case 0xB3u:
        if ( (v4[416] & 4) == 0 )
          v4[416] |= 4u;
        v11 = (int *)((char *)v4 + 1054);
        goto LABEL_22;
      case 0xB4u:
        if ( (v4[416] & 8) == 0 )
          v4[416] |= 8u;
        v11 = (int *)((char *)v4 + 1058);
        goto LABEL_22;
      case 0xC8u:
        if ( (v4[416] & 0x10) == 0 )
          v4[416] |= 0x10u;
        v11 = (int *)((char *)v4 + 1062);
        goto LABEL_22;
      case 0xC9u:
        if ( (v4[416] & 0x20) == 0 )
          v4[416] |= 0x20u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 533);
        goto LABEL_23;
      case 0xCAu:
        if ( (v4[416] & 0x40) == 0 )
          v4[416] |= 0x40u;
        v11 = v4 + 267;
        goto LABEL_22;
      case 0xCBu:
        if ( (v4[416] & 0x80) == 0 )
          v4[416] |= 0x80u;
        v11 = v4 + 268;
        goto LABEL_22;
      case 0xCCu:
        if ( (v4[416] & 0x100) == 0 )
          v4[416] |= 0x100u;
        v11 = v4 + 269;
        goto LABEL_22;
      case 0xCDu:
        if ( (v4[416] & 0x200) == 0 )
          v4[416] |= 0x200u;
        v11 = v4 + 270;
        goto LABEL_22;
      case 0xCEu:
        if ( (v4[416] & 0x400) == 0 )
          v4[416] |= 0x400u;
        v11 = v4 + 271;
        goto LABEL_22;
      case 0xCFu:
        if ( (v4[416] & 0x800) == 0 )
          v4[416] |= 0x800u;
        v11 = v4 + 272;
        goto LABEL_22;
      case 0xD0u:
        if ( (v4[416] & 0x1000) == 0 )
          v4[416] |= 0x1000u;
        v11 = v4 + 273;
        goto LABEL_22;
      case 0xD1u:
        if ( (v4[416] & 0x2000) == 0 )
          v4[416] |= 0x2000u;
        v11 = v4 + 274;
        goto LABEL_22;
      case 0xD2u:
        if ( (v4[416] & 0x4000) == 0 )
          v4[416] |= 0x4000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v111 = 0;
        a3 = v6[1];
        v112 = v4 + 275;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v112);
          if ( VarInt )
            return VarInt;
          v113 = v6[1];
          if ( v113 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v113 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v111;
            ++v112;
            if ( v111 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xD3u:
        if ( (v4[416] & 0x8000) == 0 )
          v4[416] |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v114 = 0;
        v115 = v156 + 282;
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v152);
          if ( VarInt )
            return VarInt;
          v116 = (char *)a2 + a3;
          *v115 = v152;
          v117 = (char *)v6[1];
          if ( v117 > v116 )
            goto LABEL_864;
          if ( v117 != v116 )
          {
            ++v114;
            ++v115;
            if ( v114 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xD4u:
        if ( (v4[416] & 0x10000) == 0 )
          v4[416] |= 0x10000u;
        v11 = v4 + 289;
        goto LABEL_22;
      case 0xD6u:
        if ( (v4[416] & 0x20000) == 0 )
          v4[416] |= 0x20000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v118 = 0;
        v119 = v156 + 290;
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v151);
          if ( VarInt )
            return VarInt;
          v120 = (char *)a2 + a3;
          *v119 = v151;
          v121 = (char *)v6[1];
          if ( v121 > v120 )
            goto LABEL_864;
          if ( v121 != v120 )
          {
            ++v118;
            ++v119;
            if ( v118 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xDCu:
        if ( (v4[416] & 0x40000) == 0 )
          v4[416] |= 0x40000u;
        v11 = v4 + 297;
        goto LABEL_22;
      case 0xDDu:
        if ( (v4[416] & 0x80000) == 0 )
          v4[416] |= 0x80000u;
        v11 = v4 + 298;
        goto LABEL_22;
      case 0xDEu:
        if ( (v4[416] & 0x100000) == 0 )
          v4[416] |= 0x100000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v122 = 0;
        a3 = v6[1];
        v123 = v4 + 299;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v123);
          if ( VarInt )
            return VarInt;
          v124 = v6[1];
          if ( v124 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v124 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v122;
            ++v123;
            if ( v122 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xDFu:
        if ( (v4[416] & 0x200000) == 0 )
          v4[416] |= 0x200000u;
        v11 = v4 + 306;
        goto LABEL_22;
      case 0xE0u:
        if ( (v4[416] & 0x400000) == 0 )
          v4[416] |= 0x400000u;
        v11 = v4 + 307;
        goto LABEL_22;
      case 0xE2u:
        if ( (v4[416] & 0x800000) == 0 )
          v4[416] |= 0x800000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v125 = 0;
        a3 = v6[1];
        v126 = v4 + 308;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v126);
          if ( VarInt )
            return VarInt;
          v127 = v6[1];
          if ( v127 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v127 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v125;
            ++v126;
            if ( v125 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xE3u:
        if ( (v4[416] & 0x1000000) == 0 )
          v4[416] |= 0x1000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 630);
        goto LABEL_23;
      case 0xE4u:
        if ( (v4[416] & 0x2000000) == 0 )
          v4[416] |= 0x2000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 631);
        goto LABEL_23;
      case 0xE5u:
        if ( (v4[416] & 0x4000000) == 0 )
          v4[416] |= 0x4000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 632);
        goto LABEL_23;
      case 0xE8u:
        if ( (v4[416] & 0x8000000) == 0 )
          v4[416] |= 0x8000000u;
        v11 = (int *)((char *)v4 + 1266);
        goto LABEL_22;
      case 0xE9u:
        if ( (v4[416] & 0x10000000) == 0 )
          v4[416] |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v128 = 0;
        a3 = v6[1];
        v129 = (int *)((char *)v4 + 1270);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v129);
          if ( VarInt )
            return VarInt;
          v130 = v6[1];
          if ( v130 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v130 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v128;
            ++v129;
            if ( v128 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xEAu:
        if ( (v4[416] & 0x20000000) == 0 )
          v4[416] |= 0x20000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v131 = 0;
        a3 = v6[1];
        v132 = (int *)((char *)v4 + 1298);
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v132);
          if ( VarInt )
            return VarInt;
          v133 = v6[1];
          if ( v133 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v133 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v131;
            ++v132;
            if ( v131 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0xEBu:
        if ( (v4[416] & 0x40000000) == 0 )
          v4[416] |= 0x40000000u;
        v11 = (int *)((char *)v4 + 1326);
        goto LABEL_22;
      case 0xECu:
        if ( v4[416] >= 0 )
          v4[416] |= 0x80000000;
        v11 = (int *)((char *)v4 + 1330);
        goto LABEL_22;
      case 0xEDu:
        if ( (v4[417] & 1) == 0 )
          v4[417] |= 1u;
        v11 = (int *)((char *)v4 + 1334);
        goto LABEL_22;
      case 0xEEu:
        if ( (v4[417] & 2) == 0 )
          v4[417] |= 2u;
        v11 = (int *)((char *)v4 + 1338);
        goto LABEL_22;
      case 0xEFu:
        if ( (v4[417] & 4) == 0 )
          v4[417] |= 4u;
        v11 = (int *)((char *)v4 + 1342);
        goto LABEL_22;
      case 0xF0u:
        if ( (v4[417] & 8) == 0 )
          v4[417] |= 8u;
        v11 = (int *)((char *)v4 + 1346);
        goto LABEL_22;
      case 0xF1u:
        if ( (v4[417] & 0x10) == 0 )
          v4[417] |= 0x10u;
        v11 = (int *)((char *)v4 + 1350);
        goto LABEL_22;
      case 0xF2u:
        if ( (v4[417] & 0x20) == 0 )
          v4[417] |= 0x20u;
        v11 = (int *)((char *)v4 + 1354);
        goto LABEL_22;
      case 0xF3u:
        if ( (v4[417] & 0x40) == 0 )
          v4[417] |= 0x40u;
        v11 = (int *)((char *)v4 + 1358);
        goto LABEL_22;
      case 0xF4u:
        if ( (v4[417] & 0x80) == 0 )
          v4[417] |= 0x80u;
        v11 = (int *)((char *)v4 + 1362);
        goto LABEL_22;
      case 0xF5u:
        if ( (v4[417] & 0x100) == 0 )
          v4[417] |= 0x100u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 683);
        goto LABEL_23;
      case 0xFCu:
        if ( (v4[417] & 0x200) == 0 )
          v4[417] |= 0x200u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 684);
        goto LABEL_23;
      case 0xFDu:
        if ( (v4[417] & 0x400) == 0 )
          v4[417] |= 0x400u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 685);
        goto LABEL_23;
      case 0xFEu:
        if ( (v4[417] & 0x800) == 0 )
          v4[417] |= 0x800u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 686);
        goto LABEL_23;
      case 0xFFu:
        if ( (v4[417] & 0x1000) == 0 )
          v4[417] |= 0x1000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 687);
        goto LABEL_23;
      case 0x100u:
        if ( (v4[417] & 0x2000) == 0 )
          v4[417] |= 0x2000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 688);
        goto LABEL_23;
      case 0x101u:
        if ( (v4[417] & 0x4000) == 0 )
          v4[417] |= 0x4000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 689);
        goto LABEL_23;
      case 0x102u:
        if ( (v4[417] & 0x8000) == 0 )
          v4[417] |= 0x8000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 690);
        goto LABEL_23;
      case 0x103u:
        if ( (v4[417] & 0x10000) == 0 )
          v4[417] |= 0x10000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 691);
        goto LABEL_23;
      case 0x104u:
        if ( (v4[417] & 0x20000) == 0 )
          v4[417] |= 0x20000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 692);
        goto LABEL_23;
      case 0x105u:
        if ( (v4[417] & 0x40000) == 0 )
          v4[417] |= 0x40000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 693);
        goto LABEL_23;
      case 0x106u:
        if ( (v4[417] & 0x80000) == 0 )
          v4[417] |= 0x80000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 694);
        goto LABEL_23;
      case 0x107u:
        if ( (v4[417] & 0x100000) == 0 )
          v4[417] |= 0x100000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 695);
        goto LABEL_23;
      case 0x108u:
        if ( (v4[417] & 0x200000) == 0 )
          v4[417] |= 0x200000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 696);
        goto LABEL_23;
      case 0x109u:
        if ( (v4[417] & 0x400000) == 0 )
          v4[417] |= 0x400000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 697);
        goto LABEL_23;
      case 0x10Au:
        if ( (v4[417] & 0x800000) == 0 )
          v4[417] |= 0x800000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 698);
        goto LABEL_23;
      case 0x10Bu:
        if ( (v4[417] & 0x1000000) == 0 )
          v4[417] |= 0x1000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 699);
        goto LABEL_23;
      case 0x10Cu:
        if ( (v4[417] & 0x2000000) == 0 )
          v4[417] |= 0x2000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 700);
        goto LABEL_23;
      case 0x10Du:
        if ( (v4[417] & 0x4000000) == 0 )
          v4[417] |= 0x4000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 701);
        goto LABEL_23;
      case 0x10Eu:
        if ( (v4[417] & 0x8000000) == 0 )
          v4[417] |= 0x8000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 702);
        goto LABEL_23;
      case 0x10Fu:
        if ( (v4[417] & 0x10000000) == 0 )
          v4[417] |= 0x10000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 703);
        goto LABEL_23;
      case 0x110u:
        if ( (v4[417] & 0x20000000) == 0 )
          v4[417] |= 0x20000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 704);
        goto LABEL_23;
      case 0x111u:
        if ( (v4[417] & 0x40000000) == 0 )
          v4[417] |= 0x40000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 705);
        goto LABEL_23;
      case 0x112u:
        if ( v4[417] >= 0 )
          v4[417] |= 0x80000000;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 706);
        goto LABEL_23;
      case 0x113u:
        if ( (v4[418] & 1) == 0 )
          v4[418] |= 1u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 707);
        goto LABEL_23;
      case 0x114u:
        if ( (v4[418] & 2) == 0 )
          v4[418] |= 2u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 708);
        goto LABEL_23;
      case 0x11Cu:
        if ( (v4[418] & 4) == 0 )
          v4[418] |= 4u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 709);
        goto LABEL_23;
      case 0x125u:
        if ( (v4[418] & 8) == 0 )
          v4[418] |= 8u;
        v11 = v4 + 355;
        goto LABEL_22;
      case 0x126u:
        if ( (v4[418] & 0x10) == 0 )
          v4[418] |= 0x10u;
        v11 = v4 + 356;
        goto LABEL_22;
      case 0x12Cu:
        if ( (v4[418] & 0x20) == 0 )
          v4[418] |= 0x20u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 714);
        goto LABEL_23;
      case 0x133u:
        if ( (v4[418] & 0x40) == 0 )
          v4[418] |= 0x40u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 715);
        goto LABEL_23;
      case 0x134u:
        if ( (v4[418] & 0x80) == 0 )
          v4[418] |= 0x80u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 716);
        goto LABEL_23;
      case 0x135u:
        if ( (v4[418] & 0x100) == 0 )
          v4[418] |= 0x100u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 717);
        goto LABEL_23;
      case 0x136u:
        if ( (v4[418] & 0x200) == 0 )
          v4[418] |= 0x200u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 718);
        goto LABEL_23;
      case 0x137u:
        if ( (v4[418] & 0x400) == 0 )
          v4[418] |= 0x400u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 719);
        goto LABEL_23;
      case 0x142u:
        if ( (v4[418] & 0x800) == 0 )
          v4[418] |= 0x800u;
        v11 = v4 + 360;
        goto LABEL_22;
      case 0x143u:
        if ( (v4[418] & 0x1000) == 0 )
          v4[418] |= 0x1000u;
        v11 = v4 + 361;
        goto LABEL_22;
      case 0x148u:
        if ( (v4[418] & 0x2000) == 0 )
          v4[418] |= 0x2000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 724);
        goto LABEL_23;
      case 0x149u:
        if ( (v4[418] & 0x4000) == 0 )
          v4[418] |= 0x4000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 725);
        goto LABEL_23;
      case 0x14Au:
        if ( (v4[418] & 0x8000) == 0 )
          v4[418] |= 0x8000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 726);
        goto LABEL_23;
      case 0x14Bu:
        if ( (v4[418] & 0x10000) == 0 )
          v4[418] |= 0x10000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 727);
        goto LABEL_23;
      case 0x14Cu:
        if ( (v4[418] & 0x20000) == 0 )
          v4[418] |= 0x20000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 728);
        goto LABEL_23;
      case 0x14Du:
        if ( (v4[418] & 0x40000) == 0 )
          v4[418] |= 0x40000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 729);
        goto LABEL_23;
      case 0x14Eu:
        if ( (v4[418] & 0x80000) == 0 )
          v4[418] |= 0x80000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 730);
        goto LABEL_23;
      case 0x14Fu:
        if ( (v4[418] & 0x100000) == 0 )
          v4[418] |= 0x100000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 731);
        goto LABEL_23;
      case 0x150u:
        if ( (v4[418] & 0x200000) == 0 )
          v4[418] |= 0x200000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 732);
        goto LABEL_23;
      case 0x151u:
        if ( (v4[418] & 0x400000) == 0 )
          v4[418] |= 0x400000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 733);
        goto LABEL_23;
      case 0x152u:
        if ( (v4[418] & 0x800000) == 0 )
          v4[418] |= 0x800000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 734);
        goto LABEL_23;
      case 0x153u:
        if ( (v4[418] & 0x1000000) == 0 )
          v4[418] |= 0x1000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 735);
        goto LABEL_23;
      case 0x154u:
        if ( (v4[418] & 0x2000000) == 0 )
          v4[418] |= 0x2000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 736);
        goto LABEL_23;
      case 0x155u:
        if ( (v4[418] & 0x4000000) == 0 )
          v4[418] |= 0x4000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 737);
        goto LABEL_23;
      case 0x156u:
        if ( (v4[418] & 0x8000000) == 0 )
          v4[418] |= 0x8000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 738);
        goto LABEL_23;
      case 0x157u:
        if ( (v4[418] & 0x10000000) == 0 )
          v4[418] |= 0x10000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 739);
        goto LABEL_23;
      case 0x158u:
        if ( (v4[418] & 0x20000000) == 0 )
          v4[418] |= 0x20000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 740);
        goto LABEL_23;
      case 0x159u:
        if ( (v4[418] & 0x40000000) == 0 )
          v4[418] |= 0x40000000u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 741);
        goto LABEL_23;
      case 0x15Au:
        if ( v4[418] >= 0 )
          v4[418] |= 0x80000000;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 742);
        goto LABEL_23;
      case 0x15Bu:
        if ( (v4[419] & 1) == 0 )
          v4[419] |= 1u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 743);
        goto LABEL_23;
      case 0x15Cu:
        if ( (v4[419] & 2) == 0 )
          v4[419] |= 2u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 744);
        goto LABEL_23;
      case 0x15Du:
        if ( (v4[419] & 4) == 0 )
          v4[419] |= 4u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 745);
        goto LABEL_23;
      case 0x15Eu:
        if ( (v4[419] & 8) == 0 )
          v4[419] |= 8u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 746);
        goto LABEL_23;
      case 0x160u:
        if ( (v4[419] & 0x10) == 0 )
          v4[419] |= 0x10u;
        VarShort = TdrBuf::ReadVarShort(v6, (_WORD *)v4 + 747);
        goto LABEL_23;
      case 0x167u:
        if ( (v4[419] & 0x20) == 0 )
          v4[419] |= 0x20u;
        v11 = v4 + 374;
        goto LABEL_22;
      case 0x168u:
        if ( (v4[419] & 0x40) == 0 )
          v4[419] |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v134 = 0;
        v135 = v156 + 375;
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v150);
          if ( VarInt )
            return VarInt;
          v136 = (char *)a2 + a3;
          *v135 = v150;
          v137 = (char *)v6[1];
          if ( v137 > v136 )
            goto LABEL_864;
          if ( v137 != v136 )
          {
            ++v134;
            ++v135;
            if ( v134 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x169u:
        if ( (v4[419] & 0x80) == 0 )
          v4[419] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v138 = 0;
        v139 = v156 + 382;
        a3 = v6[1];
        while ( 1 )
        {
          VarInt = TdrBuf::ReadInt32(v6, &v149);
          if ( VarInt )
            return VarInt;
          v140 = (char *)a2 + a3;
          *v139 = v149;
          v141 = (char *)v6[1];
          if ( v141 > v140 )
            goto LABEL_864;
          if ( v141 != v140 )
          {
            ++v138;
            ++v139;
            if ( v138 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x172u:
        if ( (v4[419] & 0x100) == 0 )
          v4[419] |= 0x100u;
        v11 = v4 + 389;
        goto LABEL_22;
      case 0x179u:
        if ( (v4[419] & 0x200) == 0 )
          v4[419] |= 0x200u;
        v11 = v4 + 390;
        goto LABEL_22;
      case 0x17Au:
        if ( (v4[419] & 0x400) == 0 )
          v4[419] |= 0x400u;
        v11 = v4 + 391;
        goto LABEL_22;
      case 0x17Fu:
        if ( (v4[419] & 0x800) == 0 )
          v4[419] |= 0x800u;
        v11 = v4 + 392;
        goto LABEL_22;
      case 0x181u:
        if ( (v4[419] & 0x1000) == 0 )
          v4[419] |= 0x1000u;
        v11 = v4 + 393;
        goto LABEL_22;
      case 0x182u:
        if ( (v4[419] & 0x2000) == 0 )
          v4[419] |= 0x2000u;
        v11 = v4 + 394;
        goto LABEL_22;
      case 0x183u:
        if ( (v4[419] & 0x4000) == 0 )
          v4[419] |= 0x4000u;
        v11 = v4 + 395;
        goto LABEL_22;
      case 0x192u:
        if ( (v4[419] & 0x8000) == 0 )
          v4[419] |= 0x8000u;
        v11 = v4 + 396;
        goto LABEL_22;
      case 0x193u:
        if ( (v4[419] & 0x10000) == 0 )
          v4[419] |= 0x10000u;
        v11 = v4 + 397;
        goto LABEL_22;
      case 0x195u:
        if ( (v4[419] & 0x20000) == 0 )
          v4[419] |= 0x20000u;
        v11 = v4 + 398;
        goto LABEL_22;
      case 0x196u:
        if ( (v4[419] & 0x40000) == 0 )
          v4[419] |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          goto LABEL_865;
        v142 = 0;
        a3 = v6[1];
        v143 = v4 + 399;
        while ( 1 )
        {
          VarInt = TdrBuf::ReadVarInt(v6, v143);
          if ( VarInt )
            return VarInt;
          v144 = v6[1];
          if ( v144 > (unsigned int)a2 + a3 )
            goto LABEL_864;
          if ( (_DWORD *)v144 != (_DWORD *)((char *)a2 + a3) )
          {
            ++v142;
            ++v143;
            if ( v142 < 7 )
              continue;
          }
          goto LABEL_13;
        }
      case 0x197u:
        if ( (v4[419] & 0x80000) == 0 )
          v4[419] |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( a2 )
        {
          v145 = 0;
          a3 = v6[1];
          v146 = v4 + 406;
          while ( 1 )
          {
            VarInt = TdrBuf::ReadVarInt(v6, v146);
            if ( VarInt )
              return VarInt;
            v147 = v6[1];
            if ( v147 > (unsigned int)a2 + a3 )
              break;
            if ( (_DWORD *)v147 != (_DWORD *)((char *)a2 + a3) )
            {
              ++v145;
              ++v146;
              if ( v145 < 7 )
                continue;
            }
LABEL_13:
            v4 = v156;
LABEL_14:
            v7 = v148;
            if ( v6[1] >= v148 )
              goto LABEL_15;
            goto LABEL_2;
          }
LABEL_864:
          result = -34;
        }
        else
        {
LABEL_865:
          result = -37;
        }
        break;
      case 0x198u:
        if ( (v4[419] & 0x100000) == 0 )
          v4[419] |= 0x100000u;
        v11 = v4 + 413;
LABEL_22:
        VarShort = TdrBuf::ReadVarInt(v6, v11);
        goto LABEL_23;
      default:
        VarShort = TdrBuf::SkipField(v6, v155 & 0xF);
LABEL_23:
        VarInt = VarShort;
        if ( !VarShort )
          goto LABEL_14;
        return VarInt;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0195::Read_0x99
// Address Name: SUB_101E6B40
// ============================================================
//----- (101E6B40) --------------------------------------------------------
int __thiscall sub_101E6B40(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
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
  unsigned int v37; // ebx
  _BYTE *v38; // eax
  unsigned int v39; // ecx
  unsigned int v40; // ebx
  _BYTE *v41; // eax
  unsigned int v42; // ecx
  unsigned int v43; // ebx
  _BYTE *v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // ebx
  _BYTE *v47; // eax
  unsigned int v48; // ecx
  unsigned int v49; // ebx
  _BYTE *v50; // eax
  unsigned int v51; // ecx
  unsigned int v52; // ebx
  _BYTE *v53; // eax
  unsigned int v54; // ecx
  unsigned int v55; // ebx
  _BYTE *v56; // eax
  unsigned int v57; // ecx
  unsigned int v58; // ebx
  _BYTE *v59; // eax
  unsigned int v60; // ecx
  unsigned int v61; // ebx
  _BYTE *v62; // eax
  unsigned int v63; // ecx
  unsigned int v64; // ebx
  _BYTE *v65; // eax
  unsigned int v66; // ecx
  unsigned int v67; // ebx
  _BYTE *v68; // eax
  unsigned int v69; // ecx
  unsigned int v70; // ebx
  _BYTE *v71; // eax
  unsigned int v72; // ecx
  unsigned int v73; // ebx
  _BYTE *v74; // eax
  unsigned int v75; // ecx
  unsigned int v76; // ebx
  _BYTE *v77; // eax
  unsigned int v78; // ecx
  unsigned int v79; // ebx
  _BYTE *v80; // eax
  unsigned int v81; // ecx
  unsigned int v82; // ebx
  _BYTE *v83; // eax
  unsigned int v84; // ecx
  unsigned int v85; // ebx
  _BYTE *v86; // eax
  unsigned int v87; // ecx
  unsigned int v88; // ebx
  _BYTE *v89; // eax
  unsigned int v90; // ecx
  unsigned int v91; // ebx
  _BYTE *v92; // eax
  unsigned int v93; // ecx
  unsigned int v94; // ebx
  _BYTE *v95; // eax
  unsigned int v96; // ecx
  unsigned int v97; // ebx
  _BYTE *v98; // eax
  unsigned int v99; // ecx
  unsigned int v100; // ebx
  _BYTE *v101; // eax
  unsigned int v102; // ecx
  unsigned int v103; // ebx
  _BYTE *v104; // eax
  unsigned int v105; // ecx
  unsigned int v106; // ebx
  _BYTE *v107; // eax
  unsigned int v108; // ecx
  unsigned int v109; // ebx
  _BYTE *v110; // eax
  unsigned int v111; // ecx
  _DWORD *v112; // ebx
  char *v113; // eax
  char *v114; // ecx
  _DWORD *v115; // ebx
  char *v116; // eax
  char *v117; // ecx
  unsigned int v118; // ebx
  _BYTE *v119; // eax
  unsigned int v120; // ecx
  unsigned int v121; // ebx
  _BYTE *v122; // eax
  unsigned int v123; // ecx
  unsigned int v124; // ebx
  _BYTE *v125; // eax
  unsigned int v126; // ecx
  unsigned int v127; // ebx
  _BYTE *v128; // eax
  unsigned int v129; // ecx
  unsigned int v130; // ebx
  _DWORD *v131; // eax
  unsigned int v132; // ecx
  unsigned int v133; // ebx
  _DWORD *v134; // eax
  unsigned int v135; // ecx
  unsigned int v136; // ebx
  _BYTE *v137; // eax
  unsigned int v138; // ecx
  unsigned int v139; // ebx
  _BYTE *v140; // eax
  unsigned int v141; // ecx
  unsigned int v142; // [esp+0h] [ebp-1Ch]
  int v143; // [esp+4h] [ebp-18h] BYREF
  int v144; // [esp+8h] [ebp-14h] BYREF
  int v145; // [esp+Ch] [ebp-10h] BYREF
  int v146; // [esp+10h] [ebp-Ch] BYREF
  int v147; // [esp+14h] [ebp-8h]
  unsigned int v148; // [esp+18h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  Int32 = 0;
  v148 = 0;
  *(_OWORD *)(this + 1656) = 0;
  *(_QWORD *)(this + 1672) = 0;
  v7 = v4[1] + v3;
  v142 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_858;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v148);
    if ( result )
      return result;
    switch ( v148 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 1656) & 1) == 0 )
          *(_DWORD *)(this + 1656) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( !result )
        {
          if ( !a2 )
            return -37;
          v9 = 0;
          v147 = v4[1];
          v10 = (_BYTE *)this;
          a3 = this;
          while ( 1 )
          {
            Int32 = TdrBuf::ReadInt32(v4, v10);
            if ( Int32 )
              return Int32;
            v11 = v4[1];
            if ( v11 > (unsigned int)a2 + v147 )
              return -34;
            if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v147) )
            {
              ++v9;
              v10 = (_BYTE *)(a3 + 4);
              a3 += 4;
              if ( v9 < 7 )
                continue;
            }
            goto LABEL_857;
          }
        }
        return result;
      case 4u:
        if ( (*(_DWORD *)(this + 1656) & 2) == 0 )
          *(_DWORD *)(this + 1656) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 28));
        goto LABEL_856;
      case 6u:
        if ( (*(_DWORD *)(this + 1656) & 4) == 0 )
          *(_DWORD *)(this + 1656) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 32));
        goto LABEL_856;
      case 7u:
        if ( (*(_DWORD *)(this + 1656) & 8) == 0 )
          *(_DWORD *)(this + 1656) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 36));
        goto LABEL_856;
      case 8u:
        if ( (*(_DWORD *)(this + 1656) & 0x10) == 0 )
          *(_DWORD *)(this + 1656) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 40));
        goto LABEL_856;
      case 9u:
        if ( (*(_DWORD *)(this + 1656) & 0x20) == 0 )
          *(_DWORD *)(this + 1656) |= 0x20u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 44));
        goto LABEL_856;
      case 0xAu:
        if ( (*(_DWORD *)(this + 1656) & 0x40) == 0 )
          *(_DWORD *)(this + 1656) |= 0x40u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 48));
        goto LABEL_856;
      case 0xBu:
        if ( (*(_DWORD *)(this + 1656) & 0x80) == 0 )
          *(_DWORD *)(this + 1656) |= 0x80u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 52));
        goto LABEL_856;
      case 0xCu:
        if ( (*(_DWORD *)(this + 1656) & 0x100) == 0 )
          *(_DWORD *)(this + 1656) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 56));
        goto LABEL_856;
      case 0xDu:
        if ( (*(_DWORD *)(this + 1656) & 0x200) == 0 )
          *(_DWORD *)(this + 1656) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
        goto LABEL_856;
      case 0xEu:
        if ( (*(_DWORD *)(this + 1656) & 0x400) == 0 )
          *(_DWORD *)(this + 1656) |= 0x400u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 64));
        goto LABEL_856;
      case 0xFu:
        if ( (*(_DWORD *)(this + 1656) & 0x800) == 0 )
          *(_DWORD *)(this + 1656) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 68));
        goto LABEL_856;
      case 0x10u:
        if ( (*(_DWORD *)(this + 1656) & 0x1000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 72));
        goto LABEL_856;
      case 0x11u:
        if ( (*(_DWORD *)(this + 1656) & 0x2000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v147 = v4[1];
        v14 = (_BYTE *)(this + 76);
        a3 = this + 76;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v14);
          if ( Int32 )
            return Int32;
          v15 = v4[1];
          if ( v15 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v15 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v13;
            v14 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v13 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x14u:
        if ( (*(_DWORD *)(this + 1656) & 0x4000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x4000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 104));
        goto LABEL_856;
      case 0x16u:
        if ( (*(_DWORD *)(this + 1656) & 0x8000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v16 = 0;
        v147 = v4[1];
        v17 = (_BYTE *)(this + 106);
        a3 = this + 106;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v17);
          if ( Int32 )
            return Int32;
          v18 = v4[1];
          if ( v18 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v18 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v16;
            v17 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v16 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Au:
        if ( (*(_DWORD *)(this + 1656) & 0x10000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x10000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v19 = 0;
        v147 = v4[1];
        v20 = (_BYTE *)(this + 134);
        a3 = this + 134;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v20);
          if ( Int32 )
            return Int32;
          v21 = v4[1];
          if ( v21 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v21 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v19;
            v20 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v19 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Bu:
        if ( (*(_DWORD *)(this + 1656) & 0x20000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x20000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v147 = v4[1];
        v23 = (_BYTE *)(this + 162);
        a3 = this + 162;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v23);
          if ( Int32 )
            return Int32;
          v24 = v4[1];
          if ( v24 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v24 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v22;
            v23 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v22 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 1656) & 0x40000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v25 = 0;
        v147 = v4[1];
        v26 = (_BYTE *)(this + 190);
        a3 = this + 190;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v26);
          if ( Int32 )
            return Int32;
          v27 = v4[1];
          if ( v27 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v27 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v25;
            v26 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v25 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Du:
        if ( (*(_DWORD *)(this + 1656) & 0x80000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v28 = 0;
        v147 = v4[1];
        v29 = (_BYTE *)(this + 218);
        a3 = this + 218;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v29);
          if ( Int32 )
            return Int32;
          v30 = v4[1];
          if ( v30 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v30 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v28;
            v29 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v28 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 1656) & 0x100000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x100000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v31 = (_DWORD *)(this + 246);
        v147 = v4[1];
        a3 = 0;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v146);
          if ( Int32 )
            return Int32;
          v32 = (char *)a2 + v147;
          *v31 = v146;
          v33 = (char *)v4[1];
          if ( v33 > v32 )
            return -34;
          if ( v33 != v32 )
          {
            ++v31;
            if ( (unsigned int)++a3 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 1656) & 0x200000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x200000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v34 = (_DWORD *)(this + 274);
        v147 = v4[1];
        a3 = 0;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v145);
          if ( Int32 )
            return Int32;
          v35 = (char *)a2 + v147;
          *v34 = v145;
          v36 = (char *)v4[1];
          if ( v36 > v35 )
            return -34;
          if ( v36 != v35 )
          {
            ++v34;
            if ( (unsigned int)++a3 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x20u:
        if ( (*(_DWORD *)(this + 1656) & 0x400000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x400000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v37 = 0;
        v147 = v4[1];
        v38 = (_BYTE *)(this + 302);
        a3 = this + 302;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v38);
          if ( Int32 )
            return Int32;
          v39 = v4[1];
          if ( v39 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v39 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v37;
            v38 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v37 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x21u:
        if ( (*(_DWORD *)(this + 1656) & 0x800000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x800000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v40 = 0;
        v147 = v4[1];
        v41 = (_BYTE *)(this + 330);
        a3 = this + 330;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v41);
          if ( Int32 )
            return Int32;
          v42 = v4[1];
          if ( v42 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v42 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v40;
            v41 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v40 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x22u:
        if ( (*(_DWORD *)(this + 1656) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x1000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v43 = 0;
        v147 = v4[1];
        v44 = (_BYTE *)(this + 358);
        a3 = this + 358;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v44);
          if ( Int32 )
            return Int32;
          v45 = v4[1];
          if ( v45 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v45 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v43;
            v44 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v43 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x23u:
        if ( (*(_DWORD *)(this + 1656) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x2000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v46 = 0;
        v147 = v4[1];
        v47 = (_BYTE *)(this + 386);
        a3 = this + 386;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v47);
          if ( Int32 )
            return Int32;
          v48 = v4[1];
          if ( v48 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v48 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v46;
            v47 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v46 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x27u:
        if ( (*(_DWORD *)(this + 1656) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x4000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v49 = 0;
        v147 = v4[1];
        v50 = (_BYTE *)(this + 414);
        a3 = this + 414;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v50);
          if ( Int32 )
            return Int32;
          v51 = v4[1];
          if ( v51 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v51 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v49;
            v50 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v49 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x28u:
        if ( (*(_DWORD *)(this + 1656) & 0x8000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x8000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v52 = 0;
        v147 = v4[1];
        v53 = (_BYTE *)(this + 442);
        a3 = this + 442;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v53);
          if ( Int32 )
            return Int32;
          v54 = v4[1];
          if ( v54 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v54 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v52;
            v53 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v52 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x29u:
        if ( (*(_DWORD *)(this + 1656) & 0x10000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v55 = 0;
        v147 = v4[1];
        v56 = (_BYTE *)(this + 470);
        a3 = this + 470;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v56);
          if ( Int32 )
            return Int32;
          v57 = v4[1];
          if ( v57 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v57 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v55;
            v56 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v55 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Au:
        if ( (*(_DWORD *)(this + 1656) & 0x20000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x20000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v58 = 0;
        v147 = v4[1];
        v59 = (_BYTE *)(this + 498);
        a3 = this + 498;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v59);
          if ( Int32 )
            return Int32;
          v60 = v4[1];
          if ( v60 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v60 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v58;
            v59 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v58 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Bu:
        if ( (*(_DWORD *)(this + 1656) & 0x40000000) == 0 )
          *(_DWORD *)(this + 1656) |= 0x40000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v61 = 0;
        v147 = v4[1];
        v62 = (_BYTE *)(this + 526);
        a3 = this + 526;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v62);
          if ( Int32 )
            return Int32;
          v63 = v4[1];
          if ( v63 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v63 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v61;
            v62 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v61 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Cu:
        if ( *(int *)(this + 1656) >= 0 )
          *(_DWORD *)(this + 1656) |= 0x80000000;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v64 = 0;
        v147 = v4[1];
        v65 = (_BYTE *)(this + 554);
        a3 = this + 554;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v65);
          if ( Int32 )
            return Int32;
          v66 = v4[1];
          if ( v66 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v66 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v64;
            v65 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v64 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Du:
        if ( (*(_BYTE *)(this + 1660) & 1) == 0 )
          *(_DWORD *)(this + 1660) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v67 = 0;
        v147 = v4[1];
        v68 = (_BYTE *)(this + 582);
        a3 = this + 582;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v68);
          if ( Int32 )
            return Int32;
          v69 = v4[1];
          if ( v69 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v69 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v67;
            v68 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v67 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Eu:
        if ( (*(_DWORD *)(this + 1660) & 2) == 0 )
          *(_DWORD *)(this + 1660) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v70 = 0;
        v147 = v4[1];
        v71 = (_BYTE *)(this + 610);
        a3 = this + 610;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v71);
          if ( Int32 )
            return Int32;
          v72 = v4[1];
          if ( v72 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v72 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v70;
            v71 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v70 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x2Fu:
        if ( (*(_DWORD *)(this + 1660) & 4) == 0 )
          *(_DWORD *)(this + 1660) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v73 = 0;
        v147 = v4[1];
        v74 = (_BYTE *)(this + 638);
        a3 = this + 638;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v74);
          if ( Int32 )
            return Int32;
          v75 = v4[1];
          if ( v75 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v75 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v73;
            v74 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v73 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x30u:
        if ( (*(_DWORD *)(this + 1660) & 8) == 0 )
          *(_DWORD *)(this + 1660) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v76 = 0;
        v147 = v4[1];
        v77 = (_BYTE *)(this + 666);
        a3 = this + 666;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v77);
          if ( Int32 )
            return Int32;
          v78 = v4[1];
          if ( v78 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v78 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v76;
            v77 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v76 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x31u:
        if ( (*(_DWORD *)(this + 1660) & 0x10) == 0 )
          *(_DWORD *)(this + 1660) |= 0x10u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v79 = 0;
        v147 = v4[1];
        v80 = (_BYTE *)(this + 694);
        a3 = this + 694;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v80);
          if ( Int32 )
            return Int32;
          v81 = v4[1];
          if ( v81 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v81 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v79;
            v80 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v79 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x32u:
        if ( (*(_DWORD *)(this + 1660) & 0x20) == 0 )
          *(_DWORD *)(this + 1660) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v82 = 0;
        v147 = v4[1];
        v83 = (_BYTE *)(this + 722);
        a3 = this + 722;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v83);
          if ( Int32 )
            return Int32;
          v84 = v4[1];
          if ( v84 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v84 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v82;
            v83 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v82 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x33u:
        if ( (*(_DWORD *)(this + 1660) & 0x40) == 0 )
          *(_DWORD *)(this + 1660) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v85 = 0;
        v147 = v4[1];
        v86 = (_BYTE *)(this + 750);
        a3 = this + 750;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v86);
          if ( Int32 )
            return Int32;
          v87 = v4[1];
          if ( v87 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v87 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v85;
            v86 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v85 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x34u:
        if ( (*(_DWORD *)(this + 1660) & 0x80) == 0 )
          *(_DWORD *)(this + 1660) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v88 = 0;
        v147 = v4[1];
        v89 = (_BYTE *)(this + 778);
        a3 = this + 778;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v89);
          if ( Int32 )
            return Int32;
          v90 = v4[1];
          if ( v90 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v90 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v88;
            v89 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v88 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x44u:
        if ( (*(_DWORD *)(this + 1660) & 0x100) == 0 )
          *(_DWORD *)(this + 1660) |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v91 = 0;
        v147 = v4[1];
        v92 = (_BYTE *)(this + 806);
        a3 = this + 806;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v92);
          if ( Int32 )
            return Int32;
          v93 = v4[1];
          if ( v93 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v93 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v91;
            v92 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v91 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x58u:
        if ( (*(_DWORD *)(this + 1660) & 0x200) == 0 )
          *(_DWORD *)(this + 1660) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 834));
        goto LABEL_856;
      case 0x59u:
        if ( (*(_DWORD *)(this + 1660) & 0x400) == 0 )
          *(_DWORD *)(this + 1660) |= 0x400u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v94 = 0;
        v147 = v4[1];
        v95 = (_BYTE *)(this + 838);
        a3 = this + 838;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v95);
          if ( Int32 )
            return Int32;
          v96 = v4[1];
          if ( v96 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v96 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v94;
            v95 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v94 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x5Au:
        if ( (*(_DWORD *)(this + 1660) & 0x800) == 0 )
          *(_DWORD *)(this + 1660) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 866));
        goto LABEL_856;
      case 0x5Bu:
        if ( (*(_DWORD *)(this + 1660) & 0x1000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 870));
        goto LABEL_856;
      case 0x5Cu:
        if ( (*(_DWORD *)(this + 1660) & 0x2000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x2000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 874));
        goto LABEL_856;
      case 0x5Du:
        if ( (*(_DWORD *)(this + 1660) & 0x4000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x4000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 878));
        goto LABEL_856;
      case 0x5Eu:
        if ( (*(_DWORD *)(this + 1660) & 0x8000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x8000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 882));
        goto LABEL_856;
      case 0x5Fu:
        if ( (*(_DWORD *)(this + 1660) & 0x10000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x10000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 886));
        goto LABEL_856;
      case 0x60u:
        if ( (*(_DWORD *)(this + 1660) & 0x20000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x20000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 890));
        goto LABEL_856;
      case 0x61u:
        if ( (*(_DWORD *)(this + 1660) & 0x40000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x40000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 894));
        goto LABEL_856;
      case 0x62u:
        if ( (*(_DWORD *)(this + 1660) & 0x80000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x80000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 898));
        goto LABEL_856;
      case 0x63u:
        if ( (*(_DWORD *)(this + 1660) & 0x100000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x100000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 902));
        goto LABEL_856;
      case 0x6Au:
        if ( (*(_DWORD *)(this + 1660) & 0x200000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x200000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 906));
        goto LABEL_856;
      case 0x6Bu:
        if ( (*(_DWORD *)(this + 1660) & 0x400000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x400000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 910));
        goto LABEL_856;
      case 0x6Cu:
        if ( (*(_DWORD *)(this + 1660) & 0x800000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x800000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 914));
        goto LABEL_856;
      case 0x6Du:
        if ( (*(_DWORD *)(this + 1660) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 918));
        goto LABEL_856;
      case 0x86u:
        if ( (*(_DWORD *)(this + 1660) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x2000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v97 = 0;
        v147 = v4[1];
        v98 = (_BYTE *)(this + 922);
        a3 = this + 922;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v98);
          if ( Int32 )
            return Int32;
          v99 = v4[1];
          if ( v99 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v99 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v97;
            v98 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v97 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x87u:
        if ( (*(_DWORD *)(this + 1660) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x4000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v100 = 0;
        v147 = v4[1];
        v101 = (_BYTE *)(this + 950);
        a3 = this + 950;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v101);
          if ( Int32 )
            return Int32;
          v102 = v4[1];
          if ( v102 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v102 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v100;
            v101 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v100 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x88u:
        if ( (*(_DWORD *)(this + 1660) & 0x8000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x8000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v103 = 0;
        v147 = v4[1];
        v104 = (_BYTE *)(this + 978);
        a3 = this + 978;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v104);
          if ( Int32 )
            return Int32;
          v105 = v4[1];
          if ( v105 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v105 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v103;
            v104 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v103 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x89u:
        if ( (*(_DWORD *)(this + 1660) & 0x10000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v106 = 0;
        v147 = v4[1];
        v107 = (_BYTE *)(this + 1006);
        a3 = this + 1006;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v107);
          if ( Int32 )
            return Int32;
          v108 = v4[1];
          if ( v108 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v108 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v106;
            v107 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v106 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xADu:
        if ( (*(_DWORD *)(this + 1660) & 0x20000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1034));
        goto LABEL_856;
      case 0xAEu:
        if ( (*(_DWORD *)(this + 1660) & 0x40000000) == 0 )
          *(_DWORD *)(this + 1660) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1038));
        goto LABEL_856;
      case 0xAFu:
        if ( *(int *)(this + 1660) >= 0 )
          *(_DWORD *)(this + 1660) |= 0x80000000;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1042));
        goto LABEL_856;
      case 0xB1u:
        if ( (*(_BYTE *)(this + 1664) & 1) == 0 )
          *(_DWORD *)(this + 1664) |= 1u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1046));
        goto LABEL_856;
      case 0xB2u:
        if ( (*(_DWORD *)(this + 1664) & 2) == 0 )
          *(_DWORD *)(this + 1664) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1050));
        goto LABEL_856;
      case 0xB3u:
        if ( (*(_DWORD *)(this + 1664) & 4) == 0 )
          *(_DWORD *)(this + 1664) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1054));
        goto LABEL_856;
      case 0xB4u:
        if ( (*(_DWORD *)(this + 1664) & 8) == 0 )
          *(_DWORD *)(this + 1664) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1058));
        goto LABEL_856;
      case 0xC8u:
        if ( (*(_DWORD *)(this + 1664) & 0x10) == 0 )
          *(_DWORD *)(this + 1664) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1062));
        goto LABEL_856;
      case 0xC9u:
        if ( (*(_DWORD *)(this + 1664) & 0x20) == 0 )
          *(_DWORD *)(this + 1664) |= 0x20u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1066));
        goto LABEL_856;
      case 0xCAu:
        if ( (*(_DWORD *)(this + 1664) & 0x40) == 0 )
          *(_DWORD *)(this + 1664) |= 0x40u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1068));
        goto LABEL_856;
      case 0xCBu:
        if ( (*(_DWORD *)(this + 1664) & 0x80) == 0 )
          *(_DWORD *)(this + 1664) |= 0x80u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1072));
        goto LABEL_856;
      case 0xCCu:
        if ( (*(_DWORD *)(this + 1664) & 0x100) == 0 )
          *(_DWORD *)(this + 1664) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1076));
        goto LABEL_856;
      case 0xCDu:
        if ( (*(_DWORD *)(this + 1664) & 0x200) == 0 )
          *(_DWORD *)(this + 1664) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1080));
        goto LABEL_856;
      case 0xCEu:
        if ( (*(_DWORD *)(this + 1664) & 0x400) == 0 )
          *(_DWORD *)(this + 1664) |= 0x400u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1084));
        goto LABEL_856;
      case 0xCFu:
        if ( (*(_DWORD *)(this + 1664) & 0x800) == 0 )
          *(_DWORD *)(this + 1664) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1088));
        goto LABEL_856;
      case 0xD0u:
        if ( (*(_DWORD *)(this + 1664) & 0x1000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1092));
        goto LABEL_856;
      case 0xD1u:
        if ( (*(_DWORD *)(this + 1664) & 0x2000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x2000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1096));
        goto LABEL_856;
      case 0xD2u:
        if ( (*(_DWORD *)(this + 1664) & 0x4000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x4000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v109 = 0;
        v147 = v4[1];
        v110 = (_BYTE *)(this + 1100);
        a3 = this + 1100;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v110);
          if ( Int32 )
            return Int32;
          v111 = v4[1];
          if ( v111 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v111 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v109;
            v110 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v109 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xD3u:
        if ( (*(_DWORD *)(this + 1664) & 0x8000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v112 = (_DWORD *)(this + 1128);
        v147 = v4[1];
        a3 = 0;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v144);
          if ( Int32 )
            return Int32;
          v113 = (char *)a2 + v147;
          *v112 = v144;
          v114 = (char *)v4[1];
          if ( v114 > v113 )
            return -34;
          if ( v114 != v113 )
          {
            ++v112;
            if ( (unsigned int)++a3 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xD4u:
        if ( (*(_DWORD *)(this + 1664) & 0x10000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x10000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1156));
        goto LABEL_856;
      case 0xD6u:
        if ( (*(_DWORD *)(this + 1664) & 0x20000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x20000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v115 = (_DWORD *)(this + 1160);
        v147 = v4[1];
        a3 = 0;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, &v143);
          if ( Int32 )
            return Int32;
          v116 = (char *)a2 + v147;
          *v115 = v143;
          v117 = (char *)v4[1];
          if ( v117 > v116 )
            return -34;
          if ( v117 != v116 )
          {
            ++v115;
            if ( (unsigned int)++a3 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xDCu:
        if ( (*(_DWORD *)(this + 1664) & 0x40000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x40000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1188));
        goto LABEL_856;
      case 0xDDu:
        if ( (*(_DWORD *)(this + 1664) & 0x80000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x80000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1192));
        goto LABEL_856;
      case 0xDEu:
        if ( (*(_DWORD *)(this + 1664) & 0x100000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x100000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v118 = 0;
        v147 = v4[1];
        v119 = (_BYTE *)(this + 1196);
        a3 = this + 1196;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v119);
          if ( Int32 )
            return Int32;
          v120 = v4[1];
          if ( v120 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v120 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v118;
            v119 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v118 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xDFu:
        if ( (*(_DWORD *)(this + 1664) & 0x200000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x200000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1224));
        goto LABEL_856;
      case 0xE0u:
        if ( (*(_DWORD *)(this + 1664) & 0x400000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x400000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1228));
        goto LABEL_856;
      case 0xE2u:
        if ( (*(_DWORD *)(this + 1664) & 0x800000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x800000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v121 = 0;
        v147 = v4[1];
        v122 = (_BYTE *)(this + 1232);
        a3 = this + 1232;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v122);
          if ( Int32 )
            return Int32;
          v123 = v4[1];
          if ( v123 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v123 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v121;
            v122 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v121 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xE3u:
        if ( (*(_DWORD *)(this + 1664) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1260));
        goto LABEL_856;
      case 0xE4u:
        if ( (*(_DWORD *)(this + 1664) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1262));
        goto LABEL_856;
      case 0xE5u:
        if ( (*(_DWORD *)(this + 1664) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1264));
        goto LABEL_856;
      case 0xE8u:
        if ( (*(_DWORD *)(this + 1664) & 0x8000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1266));
        goto LABEL_856;
      case 0xE9u:
        if ( (*(_DWORD *)(this + 1664) & 0x10000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x10000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v124 = 0;
        v147 = v4[1];
        v125 = (_BYTE *)(this + 1270);
        a3 = this + 1270;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v125);
          if ( Int32 )
            return Int32;
          v126 = v4[1];
          if ( v126 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v126 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v124;
            v125 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v124 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xEAu:
        if ( (*(_DWORD *)(this + 1664) & 0x20000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x20000000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v127 = 0;
        v147 = v4[1];
        v128 = (_BYTE *)(this + 1298);
        a3 = this + 1298;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v128);
          if ( Int32 )
            return Int32;
          v129 = v4[1];
          if ( v129 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v129 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v127;
            v128 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v127 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0xEBu:
        if ( (*(_DWORD *)(this + 1664) & 0x40000000) == 0 )
          *(_DWORD *)(this + 1664) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1326));
        goto LABEL_856;
      case 0xECu:
        if ( *(int *)(this + 1664) >= 0 )
          *(_DWORD *)(this + 1664) |= 0x80000000;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1330));
        goto LABEL_856;
      case 0xEDu:
        if ( (*(_BYTE *)(this + 1668) & 1) == 0 )
          *(_DWORD *)(this + 1668) |= 1u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1334));
        goto LABEL_856;
      case 0xEEu:
        if ( (*(_DWORD *)(this + 1668) & 2) == 0 )
          *(_DWORD *)(this + 1668) |= 2u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1338));
        goto LABEL_856;
      case 0xEFu:
        if ( (*(_DWORD *)(this + 1668) & 4) == 0 )
          *(_DWORD *)(this + 1668) |= 4u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1342));
        goto LABEL_856;
      case 0xF0u:
        if ( (*(_DWORD *)(this + 1668) & 8) == 0 )
          *(_DWORD *)(this + 1668) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1346));
        goto LABEL_856;
      case 0xF1u:
        if ( (*(_DWORD *)(this + 1668) & 0x10) == 0 )
          *(_DWORD *)(this + 1668) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1350));
        goto LABEL_856;
      case 0xF2u:
        if ( (*(_DWORD *)(this + 1668) & 0x20) == 0 )
          *(_DWORD *)(this + 1668) |= 0x20u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1354));
        goto LABEL_856;
      case 0xF3u:
        if ( (*(_DWORD *)(this + 1668) & 0x40) == 0 )
          *(_DWORD *)(this + 1668) |= 0x40u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1358));
        goto LABEL_856;
      case 0xF4u:
        if ( (*(_DWORD *)(this + 1668) & 0x80) == 0 )
          *(_DWORD *)(this + 1668) |= 0x80u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1362));
        goto LABEL_856;
      case 0xF5u:
        if ( (*(_DWORD *)(this + 1668) & 0x100) == 0 )
          *(_DWORD *)(this + 1668) |= 0x100u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1366));
        goto LABEL_856;
      case 0xFCu:
        if ( (*(_DWORD *)(this + 1668) & 0x200) == 0 )
          *(_DWORD *)(this + 1668) |= 0x200u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1368));
        goto LABEL_856;
      case 0xFDu:
        if ( (*(_DWORD *)(this + 1668) & 0x400) == 0 )
          *(_DWORD *)(this + 1668) |= 0x400u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1370));
        goto LABEL_856;
      case 0xFEu:
        if ( (*(_DWORD *)(this + 1668) & 0x800) == 0 )
          *(_DWORD *)(this + 1668) |= 0x800u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1372));
        goto LABEL_856;
      case 0xFFu:
        if ( (*(_DWORD *)(this + 1668) & 0x1000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x1000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1374));
        goto LABEL_856;
      case 0x100u:
        if ( (*(_DWORD *)(this + 1668) & 0x2000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x2000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1376));
        goto LABEL_856;
      case 0x101u:
        if ( (*(_DWORD *)(this + 1668) & 0x4000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x4000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1378));
        goto LABEL_856;
      case 0x102u:
        if ( (*(_DWORD *)(this + 1668) & 0x8000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x8000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1380));
        goto LABEL_856;
      case 0x103u:
        if ( (*(_DWORD *)(this + 1668) & 0x10000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x10000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1382));
        goto LABEL_856;
      case 0x104u:
        if ( (*(_DWORD *)(this + 1668) & 0x20000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x20000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1384));
        goto LABEL_856;
      case 0x105u:
        if ( (*(_DWORD *)(this + 1668) & 0x40000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x40000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1386));
        goto LABEL_856;
      case 0x106u:
        if ( (*(_DWORD *)(this + 1668) & 0x80000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x80000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1388));
        goto LABEL_856;
      case 0x107u:
        if ( (*(_DWORD *)(this + 1668) & 0x100000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x100000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1390));
        goto LABEL_856;
      case 0x108u:
        if ( (*(_DWORD *)(this + 1668) & 0x200000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x200000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1392));
        goto LABEL_856;
      case 0x109u:
        if ( (*(_DWORD *)(this + 1668) & 0x400000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x400000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1394));
        goto LABEL_856;
      case 0x10Au:
        if ( (*(_DWORD *)(this + 1668) & 0x800000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x800000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1396));
        goto LABEL_856;
      case 0x10Bu:
        if ( (*(_DWORD *)(this + 1668) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1398));
        goto LABEL_856;
      case 0x10Cu:
        if ( (*(_DWORD *)(this + 1668) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1400));
        goto LABEL_856;
      case 0x10Du:
        if ( (*(_DWORD *)(this + 1668) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1402));
        goto LABEL_856;
      case 0x10Eu:
        if ( (*(_DWORD *)(this + 1668) & 0x8000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1404));
        goto LABEL_856;
      case 0x10Fu:
        if ( (*(_DWORD *)(this + 1668) & 0x10000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x10000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1406));
        goto LABEL_856;
      case 0x110u:
        if ( (*(_DWORD *)(this + 1668) & 0x20000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1408));
        goto LABEL_856;
      case 0x111u:
        if ( (*(_DWORD *)(this + 1668) & 0x40000000) == 0 )
          *(_DWORD *)(this + 1668) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1410));
        goto LABEL_856;
      case 0x112u:
        if ( *(int *)(this + 1668) >= 0 )
          *(_DWORD *)(this + 1668) |= 0x80000000;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1412));
        goto LABEL_856;
      case 0x113u:
        if ( (*(_BYTE *)(this + 1672) & 1) == 0 )
          *(_DWORD *)(this + 1672) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1414));
        goto LABEL_856;
      case 0x114u:
        if ( (*(_DWORD *)(this + 1672) & 2) == 0 )
          *(_DWORD *)(this + 1672) |= 2u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1416));
        goto LABEL_856;
      case 0x11Cu:
        if ( (*(_DWORD *)(this + 1672) & 4) == 0 )
          *(_DWORD *)(this + 1672) |= 4u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1418));
        goto LABEL_856;
      case 0x125u:
        if ( (*(_DWORD *)(this + 1672) & 8) == 0 )
          *(_DWORD *)(this + 1672) |= 8u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1420));
        goto LABEL_856;
      case 0x126u:
        if ( (*(_DWORD *)(this + 1672) & 0x10) == 0 )
          *(_DWORD *)(this + 1672) |= 0x10u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1424));
        goto LABEL_856;
      case 0x12Cu:
        if ( (*(_DWORD *)(this + 1672) & 0x20) == 0 )
          *(_DWORD *)(this + 1672) |= 0x20u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1428));
        goto LABEL_856;
      case 0x133u:
        if ( (*(_DWORD *)(this + 1672) & 0x40) == 0 )
          *(_DWORD *)(this + 1672) |= 0x40u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1430));
        goto LABEL_856;
      case 0x134u:
        if ( (*(_DWORD *)(this + 1672) & 0x80) == 0 )
          *(_DWORD *)(this + 1672) |= 0x80u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1432));
        goto LABEL_856;
      case 0x135u:
        if ( (*(_DWORD *)(this + 1672) & 0x100) == 0 )
          *(_DWORD *)(this + 1672) |= 0x100u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1434));
        goto LABEL_856;
      case 0x136u:
        if ( (*(_DWORD *)(this + 1672) & 0x200) == 0 )
          *(_DWORD *)(this + 1672) |= 0x200u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1436));
        goto LABEL_856;
      case 0x137u:
        if ( (*(_DWORD *)(this + 1672) & 0x400) == 0 )
          *(_DWORD *)(this + 1672) |= 0x400u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1438));
        goto LABEL_856;
      case 0x142u:
        if ( (*(_DWORD *)(this + 1672) & 0x800) == 0 )
          *(_DWORD *)(this + 1672) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1440));
        goto LABEL_856;
      case 0x143u:
        if ( (*(_DWORD *)(this + 1672) & 0x1000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1444));
        goto LABEL_856;
      case 0x148u:
        if ( (*(_DWORD *)(this + 1672) & 0x2000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x2000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1448));
        goto LABEL_856;
      case 0x149u:
        if ( (*(_DWORD *)(this + 1672) & 0x4000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x4000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1450));
        goto LABEL_856;
      case 0x14Au:
        if ( (*(_DWORD *)(this + 1672) & 0x8000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x8000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1452));
        goto LABEL_856;
      case 0x14Bu:
        if ( (*(_DWORD *)(this + 1672) & 0x10000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x10000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1454));
        goto LABEL_856;
      case 0x14Cu:
        if ( (*(_DWORD *)(this + 1672) & 0x20000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x20000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1456));
        goto LABEL_856;
      case 0x14Du:
        if ( (*(_DWORD *)(this + 1672) & 0x40000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x40000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1458));
        goto LABEL_856;
      case 0x14Eu:
        if ( (*(_DWORD *)(this + 1672) & 0x80000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x80000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1460));
        goto LABEL_856;
      case 0x14Fu:
        if ( (*(_DWORD *)(this + 1672) & 0x100000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x100000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1462));
        goto LABEL_856;
      case 0x150u:
        if ( (*(_DWORD *)(this + 1672) & 0x200000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x200000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1464));
        goto LABEL_856;
      case 0x151u:
        if ( (*(_DWORD *)(this + 1672) & 0x400000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x400000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1466));
        goto LABEL_856;
      case 0x152u:
        if ( (*(_DWORD *)(this + 1672) & 0x800000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x800000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1468));
        goto LABEL_856;
      case 0x153u:
        if ( (*(_DWORD *)(this + 1672) & 0x1000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x1000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1470));
        goto LABEL_856;
      case 0x154u:
        if ( (*(_DWORD *)(this + 1672) & 0x2000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x2000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1472));
        goto LABEL_856;
      case 0x155u:
        if ( (*(_DWORD *)(this + 1672) & 0x4000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x4000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1474));
        goto LABEL_856;
      case 0x156u:
        if ( (*(_DWORD *)(this + 1672) & 0x8000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x8000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1476));
        goto LABEL_856;
      case 0x157u:
        if ( (*(_DWORD *)(this + 1672) & 0x10000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x10000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1478));
        goto LABEL_856;
      case 0x158u:
        if ( (*(_DWORD *)(this + 1672) & 0x20000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x20000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1480));
        goto LABEL_856;
      case 0x159u:
        if ( (*(_DWORD *)(this + 1672) & 0x40000000) == 0 )
          *(_DWORD *)(this + 1672) |= 0x40000000u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1482));
        goto LABEL_856;
      case 0x15Au:
        if ( *(int *)(this + 1672) >= 0 )
          *(_DWORD *)(this + 1672) |= 0x80000000;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1484));
        goto LABEL_856;
      case 0x15Bu:
        if ( (*(_BYTE *)(this + 1676) & 1) == 0 )
          *(_DWORD *)(this + 1676) |= 1u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1486));
        goto LABEL_856;
      case 0x15Cu:
        if ( (*(_DWORD *)(this + 1676) & 2) == 0 )
          *(_DWORD *)(this + 1676) |= 2u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1488));
        goto LABEL_856;
      case 0x15Du:
        if ( (*(_DWORD *)(this + 1676) & 4) == 0 )
          *(_DWORD *)(this + 1676) |= 4u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1490));
        goto LABEL_856;
      case 0x15Eu:
        if ( (*(_DWORD *)(this + 1676) & 8) == 0 )
          *(_DWORD *)(this + 1676) |= 8u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1492));
        goto LABEL_856;
      case 0x160u:
        if ( (*(_DWORD *)(this + 1676) & 0x10) == 0 )
          *(_DWORD *)(this + 1676) |= 0x10u;
        Int16 = TdrBuf::ReadInt16(v4, (_BYTE *)(this + 1494));
        goto LABEL_856;
      case 0x167u:
        if ( (*(_DWORD *)(this + 1676) & 0x20) == 0 )
          *(_DWORD *)(this + 1676) |= 0x20u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1496));
        goto LABEL_856;
      case 0x168u:
        if ( (*(_DWORD *)(this + 1676) & 0x40) == 0 )
          *(_DWORD *)(this + 1676) |= 0x40u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v130 = 0;
        v147 = v4[1];
        v131 = (_DWORD *)(this + 1500);
        a3 = this + 1500;
        while ( 1 )
        {
          Int32 = sub_101422B0(v4, v131);
          if ( Int32 )
            return Int32;
          v132 = v4[1];
          if ( v132 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v132 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v130;
            v131 = (_DWORD *)(a3 + 4);
            a3 += 4;
            if ( v130 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x169u:
        if ( (*(_DWORD *)(this + 1676) & 0x80) == 0 )
          *(_DWORD *)(this + 1676) |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v133 = 0;
        v147 = v4[1];
        v134 = (_DWORD *)(this + 1528);
        a3 = this + 1528;
        while ( 1 )
        {
          Int32 = sub_101422B0(v4, v134);
          if ( Int32 )
            return Int32;
          v135 = v4[1];
          if ( v135 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v135 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v133;
            v134 = (_DWORD *)(a3 + 4);
            a3 += 4;
            if ( v133 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x172u:
        if ( (*(_DWORD *)(this + 1676) & 0x100) == 0 )
          *(_DWORD *)(this + 1676) |= 0x100u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1556));
        goto LABEL_856;
      case 0x179u:
        if ( (*(_DWORD *)(this + 1676) & 0x200) == 0 )
          *(_DWORD *)(this + 1676) |= 0x200u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1560));
        goto LABEL_856;
      case 0x17Au:
        if ( (*(_DWORD *)(this + 1676) & 0x400) == 0 )
          *(_DWORD *)(this + 1676) |= 0x400u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1564));
        goto LABEL_856;
      case 0x17Fu:
        if ( (*(_DWORD *)(this + 1676) & 0x800) == 0 )
          *(_DWORD *)(this + 1676) |= 0x800u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1568));
        goto LABEL_856;
      case 0x181u:
        if ( (*(_DWORD *)(this + 1676) & 0x1000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x1000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1572));
        goto LABEL_856;
      case 0x182u:
        if ( (*(_DWORD *)(this + 1676) & 0x2000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x2000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1576));
        goto LABEL_856;
      case 0x183u:
        if ( (*(_DWORD *)(this + 1676) & 0x4000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x4000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1580));
        goto LABEL_856;
      case 0x192u:
        if ( (*(_DWORD *)(this + 1676) & 0x8000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x8000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1584));
        goto LABEL_856;
      case 0x193u:
        if ( (*(_DWORD *)(this + 1676) & 0x10000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x10000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1588));
        goto LABEL_856;
      case 0x195u:
        if ( (*(_DWORD *)(this + 1676) & 0x20000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x20000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1592));
        goto LABEL_856;
      case 0x196u:
        if ( (*(_DWORD *)(this + 1676) & 0x40000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x40000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v136 = 0;
        v147 = v4[1];
        v137 = (_BYTE *)(this + 1596);
        a3 = this + 1596;
        while ( 1 )
        {
          Int32 = TdrBuf::ReadInt32(v4, v137);
          if ( Int32 )
            return Int32;
          v138 = v4[1];
          if ( v138 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v138 != (_DWORD *)((char *)a2 + v147) )
          {
            ++v136;
            v137 = (_BYTE *)(a3 + 4);
            a3 += 4;
            if ( v136 < 7 )
              continue;
          }
          goto LABEL_857;
        }
      case 0x197u:
        if ( (*(_DWORD *)(this + 1676) & 0x80000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x80000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v139 = 0;
        v147 = v4[1];
        v140 = (_BYTE *)(this + 1624);
        a3 = this + 1624;
        do
        {
          Int32 = TdrBuf::ReadInt32(v4, v140);
          if ( Int32 )
            return Int32;
          v141 = v4[1];
          if ( v141 > (unsigned int)a2 + v147 )
            return -34;
          if ( (_DWORD *)v141 == (_DWORD *)((char *)a2 + v147) )
            break;
          ++v139;
          v140 = (_BYTE *)(a3 + 4);
          a3 += 4;
        }
        while ( v139 < 7 );
LABEL_857:
        v7 = v142;
        if ( v4[1] < v142 )
          continue;
LABEL_858:
        if ( v4[1] > v7 )
          return -34;
        return Int32;
      case 0x198u:
        if ( (*(_DWORD *)(this + 1676) & 0x100000) == 0 )
          *(_DWORD *)(this + 1676) |= 0x100000u;
        Int16 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 1652));
        goto LABEL_856;
      default:
        Int16 = TdrBuf::SkipField(v4, v148 & 0xF);
LABEL_856:
        Int32 = Int16;
        if ( !Int16 )
          goto LABEL_857;
        return Int32;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0195::DoDebugFormat
// Address Name: SUB_101EA110
// ============================================================
//----- (101EA110) --------------------------------------------------------
int __thiscall sub_101EA110(void *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101EA1C0((int)this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0195::DebugFormat
// Address Name: SUB_101EA1C0
// ============================================================
//----- (101EA1C0) --------------------------------------------------------
int __thiscall sub_101EA1C0(int this, _DWORD *a2, int a3, char a4)
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
  int v26; // ecx
  _DWORD *v27; // ecx
  int v28; // ecx
  _DWORD *v29; // ecx
  int v30; // ecx
  _DWORD *v31; // ecx
  int v32; // ecx
  _DWORD *v33; // ecx
  int v34; // ecx
  _DWORD *v35; // ecx
  int v36; // ecx
  _DWORD *v37; // ecx
  int v38; // ecx
  _DWORD *v39; // ecx
  int v40; // ecx
  _DWORD *v41; // ecx
  int v42; // ecx
  _DWORD *v43; // ecx
  int v44; // ecx
  _DWORD *v45; // ecx
  int v46; // ecx
  _DWORD *v47; // ecx
  int v48; // ecx
  _DWORD *v49; // ecx
  int v50; // ecx
  _DWORD *v51; // ecx
  int v52; // ecx
  _DWORD *v53; // ecx
  int v54; // ecx
  _DWORD *v55; // ecx
  int v56; // ecx
  _DWORD *v57; // ecx
  int v58; // ecx
  _DWORD *v59; // ecx
  int v60; // ecx
  _DWORD *v61; // ecx
  int v62; // ecx
  _DWORD *v63; // ecx
  int v64; // ecx
  _DWORD *v65; // ecx
  int v66; // ecx
  _DWORD *v67; // ecx
  int v68; // ecx
  _DWORD *v69; // ecx
  int v70; // ecx
  _DWORD *v71; // ecx
  int v72; // ecx
  _DWORD *v73; // ecx
  int v74; // ecx
  _DWORD *v75; // ecx
  int v76; // ecx
  float *v77; // ecx
  int v78; // ecx
  float *v79; // ecx
  int v80; // ecx
  _DWORD *v81; // ecx
  int v82; // ecx
  _DWORD *v83; // ecx
  int v84; // ecx
  _DWORD *v85; // ecx
  int v86; // ecx
  _DWORD *v87; // ecx
  int v88; // ecx
  float *v89; // ecx
  int v90; // ecx
  float *v91; // ecx
  int v92; // ecx
  _DWORD *v93; // ecx
  int v94; // ecx
  _DWORD *v95; // ecx
  unsigned int v96; // [esp+1Ch] [ebp+8h]
  unsigned int v97; // [esp+1Ch] [ebp+8h]
  unsigned int v98; // [esp+1Ch] [ebp+8h]
  unsigned int v99; // [esp+1Ch] [ebp+8h]
  unsigned int v100; // [esp+1Ch] [ebp+8h]
  unsigned int v101; // [esp+1Ch] [ebp+8h]
  unsigned int v102; // [esp+1Ch] [ebp+8h]
  unsigned int v103; // [esp+1Ch] [ebp+8h]
  unsigned int v104; // [esp+1Ch] [ebp+8h]
  unsigned int v105; // [esp+1Ch] [ebp+8h]
  unsigned int v106; // [esp+1Ch] [ebp+8h]
  unsigned int v107; // [esp+1Ch] [ebp+8h]
  unsigned int v108; // [esp+1Ch] [ebp+8h]
  unsigned int v109; // [esp+1Ch] [ebp+8h]
  unsigned int v110; // [esp+1Ch] [ebp+8h]
  unsigned int v111; // [esp+1Ch] [ebp+8h]
  unsigned int v112; // [esp+1Ch] [ebp+8h]
  unsigned int v113; // [esp+1Ch] [ebp+8h]
  unsigned int v114; // [esp+1Ch] [ebp+8h]
  unsigned int v115; // [esp+1Ch] [ebp+8h]
  unsigned int v116; // [esp+1Ch] [ebp+8h]
  unsigned int v117; // [esp+1Ch] [ebp+8h]
  unsigned int v118; // [esp+1Ch] [ebp+8h]
  unsigned int v119; // [esp+1Ch] [ebp+8h]
  unsigned int v120; // [esp+1Ch] [ebp+8h]
  unsigned int v121; // [esp+1Ch] [ebp+8h]
  unsigned int v122; // [esp+1Ch] [ebp+8h]
  unsigned int v123; // [esp+1Ch] [ebp+8h]
  unsigned int v124; // [esp+1Ch] [ebp+8h]
  unsigned int v125; // [esp+1Ch] [ebp+8h]
  unsigned int v126; // [esp+1Ch] [ebp+8h]
  unsigned int v127; // [esp+1Ch] [ebp+8h]
  unsigned int v128; // [esp+1Ch] [ebp+8h]
  unsigned int v129; // [esp+1Ch] [ebp+8h]
  unsigned int v130; // [esp+1Ch] [ebp+8h]
  unsigned int v131; // [esp+1Ch] [ebp+8h]
  unsigned int v132; // [esp+1Ch] [ebp+8h]
  unsigned int v133; // [esp+1Ch] [ebp+8h]
  unsigned int v134; // [esp+1Ch] [ebp+8h]
  unsigned int v135; // [esp+1Ch] [ebp+8h]
  unsigned int v136; // [esp+1Ch] [ebp+8h]
  unsigned int v137; // [esp+1Ch] [ebp+8h]
  int v138; // [esp+1Ch] [ebp+8h]
  int v139; // [esp+24h] [ebp+10h]
  int v140; // [esp+24h] [ebp+10h]
  int v141; // [esp+24h] [ebp+10h]
  int v142; // [esp+24h] [ebp+10h]
  int v143; // [esp+24h] [ebp+10h]
  int v144; // [esp+24h] [ebp+10h]
  int v145; // [esp+24h] [ebp+10h]
  int v146; // [esp+24h] [ebp+10h]
  int v147; // [esp+24h] [ebp+10h]
  int v148; // [esp+24h] [ebp+10h]
  int v149; // [esp+24h] [ebp+10h]
  int v150; // [esp+24h] [ebp+10h]
  int v151; // [esp+24h] [ebp+10h]
  int v152; // [esp+24h] [ebp+10h]
  int v153; // [esp+24h] [ebp+10h]
  int v154; // [esp+24h] [ebp+10h]
  int v155; // [esp+24h] [ebp+10h]
  int v156; // [esp+24h] [ebp+10h]
  int v157; // [esp+24h] [ebp+10h]
  int v158; // [esp+24h] [ebp+10h]
  int v159; // [esp+24h] [ebp+10h]
  int v160; // [esp+24h] [ebp+10h]
  int v161; // [esp+24h] [ebp+10h]
  int v162; // [esp+24h] [ebp+10h]
  int v163; // [esp+24h] [ebp+10h]
  int v164; // [esp+24h] [ebp+10h]
  int v165; // [esp+24h] [ebp+10h]
  int v166; // [esp+24h] [ebp+10h]
  int v167; // [esp+24h] [ebp+10h]
  int v168; // [esp+24h] [ebp+10h]
  int v169; // [esp+24h] [ebp+10h]
  int v170; // [esp+24h] [ebp+10h]
  int v171; // [esp+24h] [ebp+10h]
  int v172; // [esp+24h] [ebp+10h]
  int v173; // [esp+24h] [ebp+10h]
  int v174; // [esp+24h] [ebp+10h]
  int v175; // [esp+24h] [ebp+10h]
  int v176; // [esp+24h] [ebp+10h]
  int v177; // [esp+24h] [ebp+10h]
  int v178; // [esp+24h] [ebp+10h]
  int v179; // [esp+24h] [ebp+10h]
  int v180; // [esp+24h] [ebp+10h]
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
                result = print_field(a2, a3, a4, "[oStarCollection]", "%d", *(_DWORD *)(this + 40));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[oStarQuest]", "%d", *(_DWORD *)(this + 44));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[oStarCombat]", "%d", *(_DWORD *)(this + 48));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[oStarPet]", "%d", *(_DWORD *)(this + 52));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[oStarProduct]", "%d", *(_DWORD *)(this + 56));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[oStarGuild]", "%d", *(_DWORD *)(this + 60));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[oStarTame]", "%d", *(_DWORD *)(this + 64));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[oStarPvP]", "%d", *(_DWORD *)(this + 68));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[oCharHP]", "%d", *(_DWORD *)(this + 72));
                                if ( !result )
                                {
                                  result = sub_1024A3B0(a2, a3, v10, "[oCharMaxHP]", 7);
                                  if ( !result )
                                  {
                                    v11 = (_DWORD *)(this + 76);
                                    v96 = 0;
                                    v139 = this + 76;
                                    while ( 1 )
                                    {
                                      result = Printf(a2, " %d", *v11);
                                      if ( result )
                                        break;
                                      v11 = (_DWORD *)(v139 + 4);
                                      ++v96;
                                      v139 += 4;
                                      if ( v96 >= 7 )
                                      {
                                        result = TdrBuf::WriteChar(a2, a4);
                                        if ( !result )
                                        {
                                          result = print_field(a2, a3, a4, "[oDeath]", "%d", *(__int16 *)(this + 104));
                                          if ( !result )
                                          {
                                            result = sub_1024A3B0(a2, a3, v12, "[oCharMaxSta]", 7);
                                            if ( !result )
                                            {
                                              v13 = (_DWORD *)(this + 106);
                                              v97 = 0;
                                              v140 = this + 106;
                                              while ( 1 )
                                              {
                                                result = Printf(a2, " %d", *v13);
                                                if ( result )
                                                  break;
                                                v13 = (_DWORD *)(v140 + 4);
                                                ++v97;
                                                v140 += 4;
                                                if ( v97 >= 7 )
                                                {
                                                  result = TdrBuf::WriteChar(a2, a4);
                                                  if ( !result )
                                                  {
                                                    result = sub_1024A3B0(a2, a3, v14, "[oCharStr]", 7);
                                                    if ( !result )
                                                    {
                                                      v15 = (_DWORD *)(this + 134);
                                                      v98 = 0;
                                                      v141 = this + 134;
                                                      while ( 1 )
                                                      {
                                                        result = Printf(a2, " %d", *v15);
                                                        if ( result )
                                                          break;
                                                        v15 = (_DWORD *)(v141 + 4);
                                                        ++v98;
                                                        v141 += 4;
                                                        if ( v98 >= 7 )
                                                        {
                                                          result = TdrBuf::WriteChar(a2, a4);
                                                          if ( !result )
                                                          {
                                                            result = sub_1024A3B0(a2, a3, v16, "[oCharBst]", 7);
                                                            if ( !result )
                                                            {
                                                              v17 = (_DWORD *)(this + 162);
                                                              v99 = 0;
                                                              v142 = this + 162;
                                                              while ( 1 )
                                                              {
                                                                result = Printf(a2, " %d", *v17);
                                                                if ( result )
                                                                  break;
                                                                v17 = (_DWORD *)(v142 + 4);
                                                                ++v99;
                                                                v142 += 4;
                                                                if ( v99 >= 7 )
                                                                {
                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                  if ( !result )
                                                                  {
                                                                    result = sub_1024A3B0(a2, a3, v18, "[oCharLck]", 7);
                                                                    if ( !result )
                                                                    {
                                                                      v19 = (_DWORD *)(this + 190);
                                                                      v100 = 0;
                                                                      v143 = this + 190;
                                                                      while ( 1 )
                                                                      {
                                                                        result = Printf(a2, " %d", *v19);
                                                                        if ( result )
                                                                          break;
                                                                        v19 = (_DWORD *)(v143 + 4);
                                                                        ++v100;
                                                                        v143 += 4;
                                                                        if ( v100 >= 7 )
                                                                        {
                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                          if ( !result )
                                                                          {
                                                                            result = sub_1024A3B0(
                                                                                       a2,
                                                                                       a3,
                                                                                       v20,
                                                                                       "[oCharVgr]",
                                                                                       7);
                                                                            if ( !result )
                                                                            {
                                                                              v21 = (_DWORD *)(this + 218);
                                                                              v101 = 0;
                                                                              v144 = this + 218;
                                                                              while ( 1 )
                                                                              {
                                                                                result = Printf(a2, " %d", *v21);
                                                                                if ( result )
                                                                                  break;
                                                                                v21 = (_DWORD *)(v144 + 4);
                                                                                ++v101;
                                                                                v144 += 4;
                                                                                if ( v101 >= 7 )
                                                                                {
                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                  if ( !result )
                                                                                  {
                                                                                    result = sub_1024A3B0(
                                                                                               a2,
                                                                                               a3,
                                                                                               v22,
                                                                                               "[oCharMelee]",
                                                                                               7);
                                                                                    if ( !result )
                                                                                    {
                                                                                      v23 = (float *)(this + 246);
                                                                                      v102 = 0;
                                                                                      v145 = this + 246;
                                                                                      while ( 1 )
                                                                                      {
                                                                                        result = Printf(a2, " %f", *v23);
                                                                                        if ( result )
                                                                                          break;
                                                                                        v23 = (float *)(v145 + 4);
                                                                                        ++v102;
                                                                                        v145 += 4;
                                                                                        if ( v102 >= 7 )
                                                                                        {
                                                                                          result = TdrBuf::WriteChar(
                                                                                                     a2,
                                                                                                     a4);
                                                                                          if ( !result )
                                                                                          {
                                                                                            result = sub_1024A3B0(a2, a3, v24, "[oCharRange]", 7);
                                                                                            if ( !result )
                                                                                            {
                                                                                              v25 = (float *)(this + 274);
                                                                                              v103 = 0;
                                                                                              v146 = this + 274;
                                                                                              while ( 1 )
                                                                                              {
                                                                                                result = Printf(a2, " %f", *v25);
                                                                                                if ( result )
                                                                                                  break;
                                                                                                v25 = (float *)(v146 + 4);
                                                                                                ++v103;
                                                                                                v146 += 4;
                                                                                                if ( v103 >= 7 )
                                                                                                {
                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                  if ( !result )
                                                                                                  {
                                                                                                    result = sub_1024A3B0(a2, a3, v26, "[oCharDefence]", 7);
                                                                                                    if ( !result )
                                                                                                    {
                                                                                                      v27 = (_DWORD *)(this + 302);
                                                                                                      v104 = 0;
                                                                                                      v147 = this + 302;
                                                                                                      while ( 1 )
                                                                                                      {
                                                                                                        result = Printf(a2, " %d", *v27);
                                                                                                        if ( result )
                                                                                                          break;
                                                                                                        v27 = (_DWORD *)(v147 + 4);
                                                                                                        ++v104;
                                                                                                        v147 += 4;
                                                                                                        if ( v104 >= 7 )
                                                                                                        {
                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                          if ( !result )
                                                                                                          {
                                                                                                            result = sub_1024A3B0(a2, a3, v28, "[oCritLevel]", 7);
                                                                                                            if ( !result )
                                                                                                            {
                                                                                                              v29 = (_DWORD *)(this + 330);
                                                                                                              v105 = 0;
                                                                                                              v148 = this + 330;
                                                                                                              while ( 1 )
                                                                                                              {
                                                                                                                result = Printf(a2, " %d", *v29);
                                                                                                                if ( result )
                                                                                                                  break;
                                                                                                                v29 = (_DWORD *)(v148 + 4);
                                                                                                                ++v105;
                                                                                                                v148 += 4;
                                                                                                                if ( v105 >= 7 )
                                                                                                                {
                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                  if ( !result )
                                                                                                                  {
                                                                                                                    result = sub_1024A3B0(a2, a3, v30, "[oCritDmg]", 7);
                                                                                                                    if ( !result )
                                                                                                                    {
                                                                                                                      v31 = (_DWORD *)(this + 358);
                                                                                                                      v106 = 0;
                                                                                                                      v149 = this + 358;
                                                                                                                      while ( 1 )
                                                                                                                      {
                                                                                                                        result = Printf(a2, " %d", *v31);
                                                                                                                        if ( result )
                                                                                                                          break;
                                                                                                                        v31 = (_DWORD *)(v149 + 4);
                                                                                                                        ++v106;
                                                                                                                        v149 += 4;
                                                                                                                        if ( v106 >= 7 )
                                                                                                                        {
                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                          if ( !result )
                                                                                                                          {
                                                                                                                            result = sub_1024A3B0(a2, a3, v32, "[oAntiCritDmg]", 7);
                                                                                                                            if ( !result )
                                                                                                                            {
                                                                                                                              v33 = (_DWORD *)(this + 386);
                                                                                                                              v107 = 0;
                                                                                                                              v150 = this + 386;
                                                                                                                              while ( 1 )
                                                                                                                              {
                                                                                                                                result = Printf(a2, " %d", *v33);
                                                                                                                                if ( result )
                                                                                                                                  break;
                                                                                                                                v33 = (_DWORD *)(v150 + 4);
                                                                                                                                ++v107;
                                                                                                                                v150 += 4;
                                                                                                                                if ( v107 >= 7 )
                                                                                                                                {
                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                  if ( !result )
                                                                                                                                  {
                                                                                                                                    result = sub_1024A3B0(a2, a3, v34, "[oWaterAttack]", 7);
                                                                                                                                    if ( !result )
                                                                                                                                    {
                                                                                                                                      v35 = (_DWORD *)(this + 414);
                                                                                                                                      v108 = 0;
                                                                                                                                      v151 = this + 414;
                                                                                                                                      while ( 1 )
                                                                                                                                      {
                                                                                                                                        result = Printf(a2, " %d", *v35);
                                                                                                                                        if ( result )
                                                                                                                                          break;
                                                                                                                                        v35 = (_DWORD *)(v151 + 4);
                                                                                                                                        ++v108;
                                                                                                                                        v151 += 4;
                                                                                                                                        if ( v108 >= 7 )
                                                                                                                                        {
                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                          if ( !result )
                                                                                                                                          {
                                                                                                                                            result = sub_1024A3B0(a2, a3, v36, "[oFireAttack]", 7);
                                                                                                                                            if ( !result )
                                                                                                                                            {
                                                                                                                                              v37 = (_DWORD *)(this + 442);
                                                                                                                                              v109 = 0;
                                                                                                                                              v152 = this + 442;
                                                                                                                                              while ( 1 )
                                                                                                                                              {
                                                                                                                                                result = Printf(a2, " %d", *v37);
                                                                                                                                                if ( result )
                                                                                                                                                  break;
                                                                                                                                                v37 = (_DWORD *)(v152 + 4);
                                                                                                                                                ++v109;
                                                                                                                                                v152 += 4;
                                                                                                                                                if ( v109 >= 7 )
                                                                                                                                                {
                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                  if ( !result )
                                                                                                                                                  {
                                                                                                                                                    result = sub_1024A3B0(a2, a3, v38, "[oLightningAttack]", 7);
                                                                                                                                                    if ( !result )
                                                                                                                                                    {
                                                                                                                                                      v39 = (_DWORD *)(this + 470);
                                                                                                                                                      v110 = 0;
                                                                                                                                                      v153 = this + 470;
                                                                                                                                                      while ( 1 )
                                                                                                                                                      {
                                                                                                                                                        result = Printf(a2, " %d", *v39);
                                                                                                                                                        if ( result )
                                                                                                                                                          break;
                                                                                                                                                        v39 = (_DWORD *)(v153 + 4);
                                                                                                                                                        ++v110;
                                                                                                                                                        v153 += 4;
                                                                                                                                                        if ( v110 >= 7 )
                                                                                                                                                        {
                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                          if ( !result )
                                                                                                                                                          {
                                                                                                                                                            result = sub_1024A3B0(a2, a3, v40, "[oDragonAttack]", 7);
                                                                                                                                                            if ( !result )
                                                                                                                                                            {
                                                                                                                                                              v41 = (_DWORD *)(this + 498);
                                                                                                                                                              v111 = 0;
                                                                                                                                                              v154 = this + 498;
                                                                                                                                                              while ( 1 )
                                                                                                                                                              {
                                                                                                                                                                result = Printf(a2, " %d", *v41);
                                                                                                                                                                if ( result )
                                                                                                                                                                  break;
                                                                                                                                                                v41 = (_DWORD *)(v154 + 4);
                                                                                                                                                                ++v111;
                                                                                                                                                                v154 += 4;
                                                                                                                                                                if ( v111 >= 7 )
                                                                                                                                                                {
                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                  if ( !result )
                                                                                                                                                                  {
                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v42, "[oIceAttack]", 7);
                                                                                                                                                                    if ( !result )
                                                                                                                                                                    {
                                                                                                                                                                      v43 = (_DWORD *)(this + 526);
                                                                                                                                                                      v112 = 0;
                                                                                                                                                                      v155 = this + 526;
                                                                                                                                                                      while ( 1 )
                                                                                                                                                                      {
                                                                                                                                                                        result = Printf(a2, " %d", *v43);
                                                                                                                                                                        if ( result )
                                                                                                                                                                          break;
                                                                                                                                                                        v43 = (_DWORD *)(v155 + 4);
                                                                                                                                                                        ++v112;
                                                                                                                                                                        v155 += 4;
                                                                                                                                                                        if ( v112 >= 7 )
                                                                                                                                                                        {
                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                          if ( !result )
                                                                                                                                                                          {
                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v44, "[oNonAttack]", 7);
                                                                                                                                                                            if ( !result )
                                                                                                                                                                            {
                                                                                                                                                                              v45 = (_DWORD *)(this + 554);
                                                                                                                                                                              v113 = 0;
                                                                                                                                                                              v156 = this + 554;
                                                                                                                                                                              while ( 1 )
                                                                                                                                                                              {
                                                                                                                                                                                result = Printf(a2, " %d", *v45);
                                                                                                                                                                                if ( result )
                                                                                                                                                                                  break;
                                                                                                                                                                                v45 = (_DWORD *)(v156 + 4);
                                                                                                                                                                                ++v113;
                                                                                                                                                                                v156 += 4;
                                                                                                                                                                                if ( v113 >= 7 )
                                                                                                                                                                                {
                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                  {
                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v46, "[oPoisonAttack]", 7);
                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                    {
                                                                                                                                                                                      v47 = (_DWORD *)(this + 582);
                                                                                                                                                                                      v114 = 0;
                                                                                                                                                                                      v157 = this + 582;
                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                      {
                                                                                                                                                                                        result = Printf(a2, " %d", *v47);
                                                                                                                                                                                        if ( result )
                                                                                                                                                                                          break;
                                                                                                                                                                                        v47 = (_DWORD *)(v157 + 4);
                                                                                                                                                                                        ++v114;
                                                                                                                                                                                        v157 += 4;
                                                                                                                                                                                        if ( v114 >= 7 )
                                                                                                                                                                                        {
                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                          {
                                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v48, "[oSleepyAttack]", 7);
                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                            {
                                                                                                                                                                                              v49 = (_DWORD *)(this + 610);
                                                                                                                                                                                              v115 = 0;
                                                                                                                                                                                              v158 = this + 610;
                                                                                                                                                                                              while ( 1 )
                                                                                                                                                                                              {
                                                                                                                                                                                                result = Printf(a2, " %d", *v49);
                                                                                                                                                                                                if ( result )
                                                                                                                                                                                                  break;
                                                                                                                                                                                                v49 = (_DWORD *)(v158 + 4);
                                                                                                                                                                                                ++v115;
                                                                                                                                                                                                v158 += 4;
                                                                                                                                                                                                if ( v115 >= 7 )
                                                                                                                                                                                                {
                                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                  {
                                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v50, "[oParalysisAttack]", 7);
                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                    {
                                                                                                                                                                                                      v51 = (_DWORD *)(this + 638);
                                                                                                                                                                                                      v116 = 0;
                                                                                                                                                                                                      v159 = this + 638;
                                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                                      {
                                                                                                                                                                                                        result = Printf(a2, " %d", *v51);
                                                                                                                                                                                                        if ( result )
                                                                                                                                                                                                          break;
                                                                                                                                                                                                        v51 = (_DWORD *)(v159 + 4);
                                                                                                                                                                                                        ++v116;
                                                                                                                                                                                                        v159 += 4;
                                                                                                                                                                                                        if ( v116 >= 7 )
                                                                                                                                                                                                        {
                                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                          {
                                                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v52, "[oWaterRes]", 7);
                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                            {
                                                                                                                                                                                                              v53 = (_DWORD *)(this + 666);
                                                                                                                                                                                                              v117 = 0;
                                                                                                                                                                                                              v160 = this + 666;
                                                                                                                                                                                                              while ( 1 )
                                                                                                                                                                                                              {
                                                                                                                                                                                                                result = Printf(a2, " %d", *v53);
                                                                                                                                                                                                                if ( result )
                                                                                                                                                                                                                  break;
                                                                                                                                                                                                                v53 = (_DWORD *)(v160 + 4);
                                                                                                                                                                                                                ++v117;
                                                                                                                                                                                                                v160 += 4;
                                                                                                                                                                                                                if ( v117 >= 7 )
                                                                                                                                                                                                                {
                                                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v54, "[oFireRes]", 7);
                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                      v55 = (_DWORD *)(this + 694);
                                                                                                                                                                                                                      v118 = 0;
                                                                                                                                                                                                                      v161 = this + 694;
                                                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                        result = Printf(a2, " %d", *v55);
                                                                                                                                                                                                                        if ( result )
                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                        v55 = (_DWORD *)(v161 + 4);
                                                                                                                                                                                                                        ++v118;
                                                                                                                                                                                                                        v161 += 4;
                                                                                                                                                                                                                        if ( v118 >= 7 )
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                          {
                                                                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v56, "[oLightningRes]", 7);
                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                              v57 = (_DWORD *)(this + 722);
                                                                                                                                                                                                                              v119 = 0;
                                                                                                                                                                                                                              v162 = this + 722;
                                                                                                                                                                                                                              while ( 1 )
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                result = Printf(a2, " %d", *v57);
                                                                                                                                                                                                                                if ( result )
                                                                                                                                                                                                                                  break;
                                                                                                                                                                                                                                v57 = (_DWORD *)(v162 + 4);
                                                                                                                                                                                                                                ++v119;
                                                                                                                                                                                                                                v162 += 4;
                                                                                                                                                                                                                                if ( v119 >= 7 )
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v58, "[oDragonRes]", 7);
                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                      v59 = (_DWORD *)(this + 750);
                                                                                                                                                                                                                                      v120 = 0;
                                                                                                                                                                                                                                      v163 = this + 750;
                                                                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                        result = Printf(a2, " %d", *v59);
                                                                                                                                                                                                                                        if ( result )
                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                        v59 = (_DWORD *)(v163 + 4);
                                                                                                                                                                                                                                        ++v120;
                                                                                                                                                                                                                                        v163 += 4;
                                                                                                                                                                                                                                        if ( v120 >= 7 )
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v60, "[oIceRes]", 7);
                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                              v61 = (_DWORD *)(this + 778);
                                                                                                                                                                                                                                              v121 = 0;
                                                                                                                                                                                                                                              v164 = this + 778;
                                                                                                                                                                                                                                              while ( 1 )
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                result = Printf(a2, " %d", *v61);
                                                                                                                                                                                                                                                if ( result )
                                                                                                                                                                                                                                                  break;
                                                                                                                                                                                                                                                v61 = (_DWORD *)(v164 + 4);
                                                                                                                                                                                                                                                ++v121;
                                                                                                                                                                                                                                                v164 += 4;
                                                                                                                                                                                                                                                if ( v121 >= 7 )
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v62, "[oParaThrsh]", 7);
                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                      v63 = (_DWORD *)(this + 806);
                                                                                                                                                                                                                                                      v122 = 0;
                                                                                                                                                                                                                                                      v165 = this + 806;
                                                                                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                        result = Printf(a2, " %d", *v63);
                                                                                                                                                                                                                                                        if ( result )
                                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                                        v63 = (_DWORD *)(v165 + 4);
                                                                                                                                                                                                                                                        ++v122;
                                                                                                                                                                                                                                                        v165 += 4;
                                                                                                                                                                                                                                                        if ( v122 >= 7 )
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oCharEnergy]", "%d", *(_DWORD *)(this + 834));
                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                              result = sub_1024A3B0(a2, a3, v64, "[oCharMaxEnergy]", 7);
                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                v65 = (_DWORD *)(this + 838);
                                                                                                                                                                                                                                                                v123 = 0;
                                                                                                                                                                                                                                                                v166 = this + 838;
                                                                                                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                  result = Printf(a2, " %d", *v65);
                                                                                                                                                                                                                                                                  if ( result )
                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                  v65 = (_DWORD *)(v166 + 4);
                                                                                                                                                                                                                                                                  ++v123;
                                                                                                                                                                                                                                                                  v166 += 4;
                                                                                                                                                                                                                                                                  if ( v123 >= 7 )
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                    result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oClaymoreExp]", "%d", *(_DWORD *)(this + 866));
                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oHammerExp]", "%d", *(_DWORD *)(this + 870));
                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oKatanaExp]", "%d", *(_DWORD *)(this + 874));
                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oDuelSwordExp]", "%d", *(_DWORD *)(this + 878));
                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oSwordExp]", "%d", *(_DWORD *)(this + 882));
                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oSpearExp]", "%d", *(_DWORD *)(this + 886));
                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oGunExp]", "%d", *(_DWORD *)(this + 890));
                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oBowExp]", "%d", *(_DWORD *)(this + 894));
                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oCrossbowExp]", "%d", *(_DWORD *)(this + 898));
                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFluteExp]", "%d", *(_DWORD *)(this + 902));
                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oCharGuild]", "%d", *(_DWORD *)(this + 906));
                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oCharWarteam]", "%d", *(_DWORD *)(this + 910));
                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oMaleFace]", "%d", *(_DWORD *)(this + 914));
                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oMaleHair]", "%d", *(_DWORD *)(this + 918));
                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                  result = sub_1024A3B0(a2, a3, v66, "[oPVEDef]", 7);
                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                    v67 = (_DWORD *)(this + 922);
                                                                                                                                                                                                                                                                                                    v124 = 0;
                                                                                                                                                                                                                                                                                                    v167 = this + 922;
                                                                                                                                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                      result = Printf(a2, " %d", *v67);
                                                                                                                                                                                                                                                                                                      if ( result )
                                                                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                                                                      v67 = (_DWORD *)(v167 + 4);
                                                                                                                                                                                                                                                                                                      ++v124;
                                                                                                                                                                                                                                                                                                      v167 += 4;
                                                                                                                                                                                                                                                                                                      if ( v124 >= 7 )
                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                        result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                          result = sub_1024A3B0(a2, a3, v68, "[oPVEDefAngle]", 7);
                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                            v69 = (_DWORD *)(this + 950);
                                                                                                                                                                                                                                                                                                            v125 = 0;
                                                                                                                                                                                                                                                                                                            v168 = this + 950;
                                                                                                                                                                                                                                                                                                            while ( 1 )
                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                              result = Printf(a2, " %d", *v69);
                                                                                                                                                                                                                                                                                                              if ( result )
                                                                                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                                                                                              v69 = (_DWORD *)(v168 + 4);
                                                                                                                                                                                                                                                                                                              ++v125;
                                                                                                                                                                                                                                                                                                              v168 += 4;
                                                                                                                                                                                                                                                                                                              if ( v125 >= 7 )
                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                  result = sub_1024A3B0(a2, a3, v70, "[oPVPDef]", 7);
                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                    v71 = (_DWORD *)(this + 978);
                                                                                                                                                                                                                                                                                                                    v126 = 0;
                                                                                                                                                                                                                                                                                                                    v169 = this + 978;
                                                                                                                                                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                      result = Printf(a2, " %d", *v71);
                                                                                                                                                                                                                                                                                                                      if ( result )
                                                                                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                                                                                      v71 = (_DWORD *)(v169 + 4);
                                                                                                                                                                                                                                                                                                                      ++v126;
                                                                                                                                                                                                                                                                                                                      v169 += 4;
                                                                                                                                                                                                                                                                                                                      if ( v126 >= 7 )
                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                        result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                          result = sub_1024A3B0(a2, a3, v72, "[oPVPDefAngle]", 7);
                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                            v73 = (_DWORD *)(this + 1006);
                                                                                                                                                                                                                                                                                                                            v127 = 0;
                                                                                                                                                                                                                                                                                                                            v170 = this + 1006;
                                                                                                                                                                                                                                                                                                                            while ( 1 )
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                              result = Printf(a2, " %d", *v73);
                                                                                                                                                                                                                                                                                                                              if ( result )
                                                                                                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                                                                                                              v73 = (_DWORD *)(v170 + 4);
                                                                                                                                                                                                                                                                                                                              ++v127;
                                                                                                                                                                                                                                                                                                                              v170 += 4;
                                                                                                                                                                                                                                                                                                                              if ( v127 >= 7 )
                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oUnderClothes]", "%d", *(_DWORD *)(this + 1034));
                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oNewbie]", "%d", *(_DWORD *)(this + 1038));
                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oStateFlag]", "%d", *(_DWORD *)(this + 1042));
                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oPetCarryNum]", "%d", *(_DWORD *)(this + 1046));
                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oPetHomeNum]", "%d", *(_DWORD *)(this + 1050));
                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oPetOwendNumMax]", "%d", *(_DWORD *)(this + 1054));
                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oCharContribution]", "%d", *(_DWORD *)(this + 1058));
                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oCharRemainsExp]", "%d", *(_DWORD *)(this + 1062));
                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFarmOpenFlag]", "%d", *(__int16 *)(this + 1066));
                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFarmExp]", "%d", *(_DWORD *)(this + 1068));
                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFarmEvaluation]", "%d", *(_DWORD *)(this + 1072));
                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oLastResetTime]", "%d", *(_DWORD *)(this + 1076));
                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oSkinColor]", "%d", *(_DWORD *)(this + 1080));
                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oHairColor]", "%d", *(_DWORD *)(this + 1084));
                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oInnerColor]", "%d", *(_DWORD *)(this + 1088));
                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFaceTattooIndex]", "%d", *(_DWORD *)(this + 1092));
                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oEyeBall]", "%d", *(_DWORD *)(this + 1096));
                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                    result = sub_1024A3B0(a2, a3, v74, "[oAdditionalHate]", 7);
                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                      v75 = (_DWORD *)(this + 1100);
                                                                                                                                                                                                                                                                                                                                                                      v128 = 0;
                                                                                                                                                                                                                                                                                                                                                                      v171 = this + 1100;
                                                                                                                                                                                                                                                                                                                                                                      while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                        result = Printf(a2, " %d", *v75);
                                                                                                                                                                                                                                                                                                                                                                        if ( result )
                                                                                                                                                                                                                                                                                                                                                                          break;
                                                                                                                                                                                                                                                                                                                                                                        v75 = (_DWORD *)(v171 + 4);
                                                                                                                                                                                                                                                                                                                                                                        ++v128;
                                                                                                                                                                                                                                                                                                                                                                        v171 += 4;
                                                                                                                                                                                                                                                                                                                                                                        if ( v128 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                          result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                            result = sub_1024A3B0(a2, a3, v76, "[oPlayerAtk]", 7);
                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                              v77 = (float *)(this + 1128);
                                                                                                                                                                                                                                                                                                                                                                              v129 = 0;
                                                                                                                                                                                                                                                                                                                                                                              v172 = this + 1128;
                                                                                                                                                                                                                                                                                                                                                                              while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                result = Printf(a2, " %f", *v77);
                                                                                                                                                                                                                                                                                                                                                                                if ( result )
                                                                                                                                                                                                                                                                                                                                                                                  break;
                                                                                                                                                                                                                                                                                                                                                                                v77 = (float *)(v172 + 4);
                                                                                                                                                                                                                                                                                                                                                                                ++v129;
                                                                                                                                                                                                                                                                                                                                                                                v172 += 4;
                                                                                                                                                                                                                                                                                                                                                                                if ( v129 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                  result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFarmFriendGatherCount]", "%d", *(_DWORD *)(this + 1156));
                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                      result = sub_1024A3B0(a2, a3, v78, "[oPlayerCrit]", 7);
                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                        v79 = (float *)(this + 1160);
                                                                                                                                                                                                                                                                                                                                                                                        v130 = 0;
                                                                                                                                                                                                                                                                                                                                                                                        v173 = this + 1160;
                                                                                                                                                                                                                                                                                                                                                                                        while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                          result = Printf(a2, " %f", *v79);
                                                                                                                                                                                                                                                                                                                                                                                          if ( result )
                                                                                                                                                                                                                                                                                                                                                                                            break;
                                                                                                                                                                                                                                                                                                                                                                                          v79 = (float *)(v173 + 4);
                                                                                                                                                                                                                                                                                                                                                                                          ++v130;
                                                                                                                                                                                                                                                                                                                                                                                          v173 += 4;
                                                                                                                                                                                                                                                                                                                                                                                          if ( v130 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                            result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFaceTattooColor]", "%d", *(_DWORD *)(this + 1188));
                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oEyeColor]", "%d", *(_DWORD *)(this + 1192));
                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                  result = sub_1024A3B0(a2, a3, v80, "[oAttrAtkFlag]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                    v81 = (_DWORD *)(this + 1196);
                                                                                                                                                                                                                                                                                                                                                                                                    v131 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                    v174 = this + 1196;
                                                                                                                                                                                                                                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                      result = Printf(a2, " %d", *v81);
                                                                                                                                                                                                                                                                                                                                                                                                      if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                                                                                                                                                                      v81 = (_DWORD *)(v174 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                      ++v131;
                                                                                                                                                                                                                                                                                                                                                                                                      v174 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                      if ( v131 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                        result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oCombatNPCID]", "%d", *(_DWORD *)(this + 1224));
                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oBattleState]", "%d", *(_DWORD *)(this + 1228));
                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                              result = sub_1024A3B0(a2, a3, v82, "[oHammerModeTime]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                v83 = (_DWORD *)(this + 1232);
                                                                                                                                                                                                                                                                                                                                                                                                                v132 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                v175 = this + 1232;
                                                                                                                                                                                                                                                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                  result = Printf(a2, " %d", *v83);
                                                                                                                                                                                                                                                                                                                                                                                                                  if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                                                                                                                                                                  v83 = (_DWORD *)(v175 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                  ++v132;
                                                                                                                                                                                                                                                                                                                                                                                                                  v175 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                  if ( v132 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                    result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oHideFashion]", "%d", *(__int16 *)(this + 1260));
                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oHideSuite]", "%d", *(__int16 *)(this + 1262));
                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oHideHelm]", "%d", *(__int16 *)(this + 1264));
                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oJinLiValue]", "%d", *(_DWORD *)(this + 1266));
                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                              result = sub_1024A3B0(a2, a3, v84, "[oJinLiStep1MaxValue]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                v85 = (_DWORD *)(this + 1270);
                                                                                                                                                                                                                                                                                                                                                                                                                                v133 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                v176 = this + 1270;
                                                                                                                                                                                                                                                                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                  result = Printf(a2, " %d", *v85);
                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                                                                                                                                                                                  v85 = (_DWORD *)(v176 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                  ++v133;
                                                                                                                                                                                                                                                                                                                                                                                                                                  v176 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( v133 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                    result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                      result = sub_1024A3B0(a2, a3, v86, "[oJinLiStep2MaxValue]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                        v87 = (_DWORD *)(this + 1298);
                                                                                                                                                                                                                                                                                                                                                                                                                                        v134 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                        v177 = this + 1298;
                                                                                                                                                                                                                                                                                                                                                                                                                                        while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                          result = Printf(a2, " %d", *v87);
                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                            break;
                                                                                                                                                                                                                                                                                                                                                                                                                                          v87 = (_DWORD *)(v177 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                          ++v134;
                                                                                                                                                                                                                                                                                                                                                                                                                                          v177 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( v134 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                            result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oJinLiStep1ReduceValue]", "%d", *(_DWORD *)(this + 1326));
                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oJinLiStep2ReduceValue]", "%d", *(_DWORD *)(this + 1330));
                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oEquipTitleID]", "%d", *(_DWORD *)(this + 1334));
                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oTitleExp]", "%d", *(_DWORD *)(this + 1338));
                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oTitleLevel]", "%d", *(_DWORD *)(this + 1342));
                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oEquipTitleBuff]", "%d", *(_DWORD *)(this + 1346));
                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oSystemUnlockData]", "%d", *(_DWORD *)(this + 1350));
                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oGuildContribution]", "%d", *(_DWORD *)(this + 1354));
                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oExtDailyExp]", "%d", *(_DWORD *)(this + 1358));
                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oGuildId]", "%d", *(_DWORD *)(this + 1362));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oTeamPasswordFlag]", "%d", *(__int16 *)(this + 1366));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo1]", "%d", *(__int16 *)(this + 1368));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo2]", "%d", *(__int16 *)(this + 1370));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo3]", "%d", *(__int16 *)(this + 1372));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo4]", "%d", *(__int16 *)(this + 1374));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo5]", "%d", *(__int16 *)(this + 1376));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo6]", "%d", *(__int16 *)(this + 1378));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo7]", "%d", *(__int16 *)(this + 1380));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo8]", "%d", *(__int16 *)(this + 1382));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo9]", "%d", *(__int16 *)(this + 1384));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo10]", "%d", *(__int16 *)(this + 1386));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo11]", "%d", *(__int16 *)(this + 1388));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo12]", "%d", *(__int16 *)(this + 1390));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo13]", "%d", *(__int16 *)(this + 1392));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo14]", "%d", *(__int16 *)(this + 1394));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo15]", "%d", *(__int16 *)(this + 1396));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo16]", "%d", *(__int16 *)(this + 1398));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo17]", "%d", *(__int16 *)(this + 1400));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo18]", "%d", *(__int16 *)(this + 1402));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo19]", "%d", *(__int16 *)(this + 1404));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo20]", "%d", *(__int16 *)(this + 1406));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo21]", "%d", *(__int16 *)(this + 1408));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo22]", "%d", *(__int16 *)(this + 1410));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo23]", "%d", *(__int16 *)(this + 1412));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo24]", "%d", *(__int16 *)(this + 1414));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo25]", "%d", *(__int16 *)(this + 1416));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oVIP]", "%d", *(__int16 *)(this + 1418));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oVIPLevel]", "%d", *(_DWORD *)(this + 1420));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oVIPExp]", "%d", *(_DWORD *)(this + 1424));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oVIPBaseCanUse]", "%d", *(__int16 *)(this + 1428));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oGameVIP]", "%d", *(__int16 *)(this + 1430));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oQQVIP]", "%d", *(__int16 *)(this + 1432));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oYearQQVIP]", "%d", *(__int16 *)(this + 1434));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oSuperQQVIP]", "%d", *(__int16 *)(this + 1436));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oNetbarLevel]", "%d", *(__int16 *)(this + 1438));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oCharHRLevel]", "%d", *(_DWORD *)(this + 1440));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oCharHRPoint]", "%d", *(_DWORD *)(this + 1444));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oXYVIP]", "%d", *(__int16 *)(this + 1448));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo26]", "%d", *(__int16 *)(this + 1450));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo27]", "%d", *(__int16 *)(this + 1452));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo28]", "%d", *(__int16 *)(this + 1454));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo29]", "%d", *(__int16 *)(this + 1456));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo30]", "%d", *(__int16 *)(this + 1458));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo31]", "%d", *(__int16 *)(this + 1460));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo32]", "%d", *(__int16 *)(this + 1462));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo33]", "%d", *(__int16 *)(this + 1464));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo34]", "%d", *(__int16 *)(this + 1466));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo35]", "%d", *(__int16 *)(this + 1468));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo36]", "%d", *(__int16 *)(this + 1470));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo37]", "%d", *(__int16 *)(this + 1472));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo38]", "%d", *(__int16 *)(this + 1474));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo39]", "%d", *(__int16 *)(this + 1476));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo40]", "%d", *(__int16 *)(this + 1478));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo41]", "%d", *(__int16 *)(this + 1480));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo42]", "%d", *(__int16 *)(this + 1482));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo43]", "%d", *(__int16 *)(this + 1484));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo44]", "%d", *(__int16 *)(this + 1486));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo45]", "%d", *(__int16 *)(this + 1488));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo46]", "%d", *(__int16 *)(this + 1490));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo47]", "%d", *(__int16 *)(this + 1492));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oTGPVIP]", "%d", *(__int16 *)(this + 1494));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFluteTune]", "%d", *(_DWORD *)(this + 1496));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = sub_1024A3B0(a2, a3, v88, "[oDefenseReduceHPModifyRate]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                v89 = (float *)(this + 1500);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                v135 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                v178 = this + 1500;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = Printf(a2, " %f", *v89);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  v89 = (float *)(v178 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ++v135;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  v178 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( v135 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = sub_1024A3B0(a2, a3, v90, "[oDefenseReduceStaModifyRate]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        v91 = (float *)(this + 1528);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        v136 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        v179 = this + 1528;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = Printf(a2, " %f", *v91);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          v91 = (float *)(v179 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ++v136;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          v179 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( v136 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oWildHuntCamp]", "%d", *(_DWORD *)(this + 1556));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oTotalHRPoint]", "%d", *(_DWORD *)(this + 1560));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oLikeHunterOfficer]", "%d", *(_DWORD *)(this + 1564));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oLevelShowType]", "%d", *(_DWORD *)(this + 1568));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oMonolopyRoundCount]", "%d", *(_DWORD *)(this + 1572));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oMonolopyActivity]", "%d", *(_DWORD *)(this + 1576));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oMonolopyCurGrid]", "%d", *(_DWORD *)(this + 1580));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oSoulStoneLevel]", "%d", *(_DWORD *)(this + 1584));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oWeeklyRefreshTime]", "%d", *(_DWORD *)(this + 1588));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oSoulStoneAtkLevel]", "%d", *(_DWORD *)(this + 1592));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  result = sub_1024A3B0(a2, a3, v92, "[oDynamiteAttack]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    v93 = (_DWORD *)(this + 1596);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    v137 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    v180 = this + 1596;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    while ( 1 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      result = Printf(a2, " %d", *v93);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      v93 = (_DWORD *)(v180 + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ++v137;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      v180 += 4;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      if ( v137 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          result = sub_1024A3B0(a2, a3, v94, "[oDynamiteThrsh]", 7);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            v95 = (_DWORD *)(this + 1624);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            v138 = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            for ( i = this + 1624;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  ;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  i += 4 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              result = Printf(a2, " %d", *v95);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                break;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              v95 = (_DWORD *)(i + 4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              if ( (unsigned int)++v138 >= 7 )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                result = TdrBuf::WriteChar(a2, a4);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  return print_field(a2, a3, a4, "[oGuildBanChatEndTime]", "%d", *(_DWORD *)(this + 1652));
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
                                                                                                                                                                                                                                                                    return result;
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
          return result;
        }
      }
    }
  }
  return result;
}
// 101EA42B: variable 'v10' is possibly undefined
// 101EA4B3: variable 'v12' is possibly undefined
// 101EA51B: variable 'v14' is possibly undefined
// 101EA582: variable 'v16' is possibly undefined
// 101EA5EB: variable 'v18' is possibly undefined
// 101EA652: variable 'v20' is possibly undefined
// 101EA6BB: variable 'v22' is possibly undefined
// 101EA738: variable 'v24' is possibly undefined
// 101EA7AC: variable 'v26' is possibly undefined
// 101EA813: variable 'v28' is possibly undefined
// 101EA87B: variable 'v30' is possibly undefined
// 101EA8E2: variable 'v32' is possibly undefined
// 101EA94B: variable 'v34' is possibly undefined
// 101EA9B2: variable 'v36' is possibly undefined
// 101EAA1B: variable 'v38' is possibly undefined
// 101EAA82: variable 'v40' is possibly undefined
// 101EAAEB: variable 'v42' is possibly undefined
// 101EAB52: variable 'v44' is possibly undefined
// 101EABBB: variable 'v46' is possibly undefined
// 101EAC22: variable 'v48' is possibly undefined
// 101EAC8B: variable 'v50' is possibly undefined
// 101EACF2: variable 'v52' is possibly undefined
// 101EAD5B: variable 'v54' is possibly undefined
// 101EADC2: variable 'v56' is possibly undefined
// 101EAE2B: variable 'v58' is possibly undefined
// 101EAE92: variable 'v60' is possibly undefined
// 101EAEFB: variable 'v62' is possibly undefined
// 101EAF87: variable 'v64' is possibly undefined
// 101EB1F4: variable 'v66' is possibly undefined
// 101EB25B: variable 'v68' is possibly undefined
// 101EB2C2: variable 'v70' is possibly undefined
// 101EB32B: variable 'v72' is possibly undefined
// 101EB609: variable 'v74' is possibly undefined
// 101EB670: variable 'v76' is possibly undefined
// 101EB70D: variable 'v78' is possibly undefined
// 101EB7D2: variable 'v80' is possibly undefined
// 101EB885: variable 'v82' is possibly undefined
// 101EB986: variable 'v84' is possibly undefined
// 101EB9ED: variable 'v86' is possibly undefined
// 101EC535: variable 'v88' is possibly undefined
// 101EC5A9: variable 'v90' is possibly undefined
// 101EC78F: variable 'v92' is possibly undefined
// 101EC7FB: variable 'v94' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101422B0
// ============================================================
//----- (101422B0) --------------------------------------------------------
int __thiscall sub_101422B0(_DWORD *this, _DWORD *a2)
{
  int result; // eax
  _DWORD *v3; // [esp+0h] [ebp-4h] BYREF

  v3 = this;
  result = TdrBuf::ReadInt32(this, &v3);
  if ( !result )
    *a2 = v3;
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



