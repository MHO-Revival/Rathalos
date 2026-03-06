// ============================================================
// Name: TLV::UnkTlv0040::Read_0xAA
// Address Name: SUB_1012D6F0
// ============================================================
//----- (1012D6F0) --------------------------------------------------------
int __thiscall sub_1012D6F0(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  int v18; // ebx
  _DWORD *v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  _DWORD *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  int v26; // ebx
  _DWORD *v27; // eax
  unsigned int v28; // ecx
  int v29; // eax
  int v30; // ebx
  _DWORD *v31; // eax
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int v34; // [esp+Ch] [ebp-10h]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  int v38; // [esp+10h] [ebp-Ch]
  int v39; // [esp+10h] [ebp-Ch]
  int v40; // [esp+10h] [ebp-Ch]
  unsigned int v41; // [esp+14h] [ebp-8h] BYREF
  int *v42; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v42 = this;
  *(this + 137) = 0;
  v41 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v34 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_106;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v41);
    if ( result )
      return result;
    switch ( v41 >> 4 )
    {
      case 1u:
        if ( (v4[137] & 1) == 0 )
          v4[137] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
        goto LABEL_104;
      case 2u:
        if ( (v4[137] & 2) == 0 )
          v4[137] |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4 + 1);
        goto LABEL_104;
      case 3u:
        if ( (v4[137] & 4) == 0 )
          v4[137] |= 4u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4 + 2);
        goto LABEL_104;
      case 4u:
        if ( (v4[137] & 8) == 0 )
          v4[137] |= 8u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4 + 3);
        goto LABEL_104;
      case 5u:
        if ( (v4[137] & 0x10) == 0 )
          v4[137] |= 0x10u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 4);
        goto LABEL_104;
      case 6u:
        if ( (v4[137] & 0x20) == 0 )
          v4[137] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v35 = v6[1];
        v11 = v42 + 5;
        a3 = v42 + 5;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v35) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 64 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v13 = v10 + 1;
        v4 = v42;
        v42[4] = v13;
        goto LABEL_105;
      case 7u:
        if ( (v4[137] & 0x40) == 0 )
          v4[137] |= 0x40u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 69);
        goto LABEL_104;
      case 8u:
        if ( (v4[137] & 0x80) == 0 )
          v4[137] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v36 = v6[1];
        v15 = v42 + 70;
        a3 = v42 + 70;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v36) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 32 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v17 = v14 + 1;
        v4 = v42;
        v42[69] = v17;
        goto LABEL_105;
      case 9u:
        if ( (v4[137] & 0x100) == 0 )
          v4[137] |= 0x100u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 102);
        goto LABEL_104;
      case 0xAu:
        if ( (v4[137] & 0x200) == 0 )
          v4[137] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v37 = v6[1];
        v19 = v42 + 103;
        a3 = v42 + 103;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v19);
          if ( v5 )
            return v5;
          v20 = v6[1];
          if ( v20 > (unsigned int)a2 + v37 )
            return -34;
          if ( (_DWORD *)v20 == (_DWORD *)((char *)a2 + v37) )
            break;
          ++v18;
          v19 = ++a3;
          if ( v18 >= 16 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v21 = v18 + 1;
        v4 = v42;
        v42[102] = v21;
        goto LABEL_105;
      case 0xBu:
        if ( (v4[137] & 0x400) == 0 )
          v4[137] |= 0x400u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 119);
        goto LABEL_104;
      case 0xCu:
        if ( (v4[137] & 0x800) == 0 )
          v4[137] |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v38 = v6[1];
        v23 = v42 + 120;
        a3 = v42 + 120;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v23);
          if ( v5 )
            return v5;
          v24 = v6[1];
          if ( v24 > (unsigned int)a2 + v38 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v38) )
            break;
          ++v22;
          v23 = ++a3;
          if ( v22 >= 8 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v25 = v22 + 1;
        v4 = v42;
        v42[119] = v25;
        goto LABEL_105;
      case 0xDu:
        if ( (v4[137] & 0x1000) == 0 )
          v4[137] |= 0x1000u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 128);
        goto LABEL_104;
      case 0xEu:
        if ( (v4[137] & 0x2000) == 0 )
          v4[137] |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v26 = 0;
        v39 = v6[1];
        v27 = v42 + 129;
        a3 = v42 + 129;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v27);
          if ( v5 )
            return v5;
          v28 = v6[1];
          if ( v28 > (unsigned int)a2 + v39 )
            return -34;
          if ( (_DWORD *)v28 == (_DWORD *)((char *)a2 + v39) )
            break;
          ++v26;
          v27 = ++a3;
          if ( v26 >= 4 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v29 = v26 + 1;
        v4 = v42;
        v42[128] = v29;
        goto LABEL_105;
      case 0xFu:
        if ( (v4[137] & 0x4000) == 0 )
          v4[137] |= 0x4000u;
        VarUInt = TdrBuf::ReadVarInt(v6, v4 + 133);
        goto LABEL_104;
      case 0x10u:
        if ( (v4[137] & 0x8000) == 0 )
          v4[137] |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v30 = 0;
        v40 = v6[1];
        v31 = v42 + 134;
        a3 = v42 + 134;
        while ( 1 )
        {
          v5 = TdrBuf::ReadVarUInt(v6, v31);
          if ( v5 )
            return v5;
          v32 = v6[1];
          if ( v32 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v32 == (_DWORD *)((char *)a2 + v40) )
            break;
          ++v30;
          v31 = ++a3;
          if ( v30 >= 2 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v33 = v30 + 1;
        v4 = v42;
        v42[133] = v33;
LABEL_105:
        v7 = v34;
        if ( v6[1] < v34 )
          continue;
LABEL_106:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      case 0x11u:
        if ( (v4[137] & 0x10000) == 0 )
          v4[137] |= 0x10000u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4 + 136);
        goto LABEL_104;
      default:
        VarUInt = TdrBuf::SkipField(v6, v41 & 0xF);
LABEL_104:
        v5 = VarUInt;
        if ( !VarUInt )
          goto LABEL_105;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0040::Read_0x99
// Address Name: SUB_1012DD70
// ============================================================
//----- (1012DD70) --------------------------------------------------------
int __thiscall sub_1012DD70(_DWORD *this, _DWORD *a2, _DWORD *a3)
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
  int v18; // ebx
  _BYTE *v19; // eax
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  _BYTE *v23; // eax
  unsigned int v24; // ecx
  int v25; // eax
  int v26; // ebx
  _BYTE *v27; // eax
  unsigned int v28; // ecx
  int v29; // eax
  int v30; // ebx
  _BYTE *v31; // eax
  unsigned int v32; // ecx
  int v33; // eax
  unsigned int v34; // [esp+Ch] [ebp-10h]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  int v38; // [esp+10h] [ebp-Ch]
  int v39; // [esp+10h] [ebp-Ch]
  int v40; // [esp+10h] [ebp-Ch]
  unsigned int v41; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v42; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v42 = this;
  *(this + 137) = 0;
  v41 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v34 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_106;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v41);
    if ( result )
      return result;
    switch ( v41 >> 4 )
    {
      case 1u:
        if ( (v4[137] & 1) == 0 )
          v4[137] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_104;
      case 2u:
        if ( (v4[137] & 2) == 0 )
          v4[137] |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 4);
        goto LABEL_104;
      case 3u:
        if ( (v4[137] & 4) == 0 )
          v4[137] |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 8);
        goto LABEL_104;
      case 4u:
        if ( (v4[137] & 8) == 0 )
          v4[137] |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 12);
        goto LABEL_104;
      case 5u:
        if ( (v4[137] & 0x10) == 0 )
          v4[137] |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 16);
        goto LABEL_104;
      case 6u:
        if ( (v4[137] & 0x20) == 0 )
          v4[137] |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v35 = v6[1];
        v11 = v42 + 5;
        a3 = v42 + 5;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v11);
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v35 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v35) )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 64 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v13 = v10 + 1;
        v4 = v42;
        v42[4] = v13;
        goto LABEL_105;
      case 7u:
        if ( (v4[137] & 0x40) == 0 )
          v4[137] |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 276);
        goto LABEL_104;
      case 8u:
        if ( (v4[137] & 0x80) == 0 )
          v4[137] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v14 = 0;
        v36 = v6[1];
        v15 = v42 + 70;
        a3 = v42 + 70;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v15);
          if ( v5 )
            return v5;
          v16 = v6[1];
          if ( v16 > (unsigned int)a2 + v36 )
            return -34;
          if ( (_DWORD *)v16 == (_DWORD *)((char *)a2 + v36) )
            break;
          ++v14;
          v15 = ++a3;
          if ( v14 >= 32 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v17 = v14 + 1;
        v4 = v42;
        v42[69] = v17;
        goto LABEL_105;
      case 9u:
        if ( (v4[137] & 0x100) == 0 )
          v4[137] |= 0x100u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 408);
        goto LABEL_104;
      case 0xAu:
        if ( (v4[137] & 0x200) == 0 )
          v4[137] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v18 = 0;
        v37 = v6[1];
        v19 = v42 + 103;
        a3 = v42 + 103;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v19);
          if ( v5 )
            return v5;
          v20 = v6[1];
          if ( v20 > (unsigned int)a2 + v37 )
            return -34;
          if ( (_DWORD *)v20 == (_DWORD *)((char *)a2 + v37) )
            break;
          ++v18;
          v19 = ++a3;
          if ( v18 >= 16 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v21 = v18 + 1;
        v4 = v42;
        v42[102] = v21;
        goto LABEL_105;
      case 0xBu:
        if ( (v4[137] & 0x400) == 0 )
          v4[137] |= 0x400u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 476);
        goto LABEL_104;
      case 0xCu:
        if ( (v4[137] & 0x800) == 0 )
          v4[137] |= 0x800u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v22 = 0;
        v38 = v6[1];
        v23 = v42 + 120;
        a3 = v42 + 120;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v23);
          if ( v5 )
            return v5;
          v24 = v6[1];
          if ( v24 > (unsigned int)a2 + v38 )
            return -34;
          if ( (_DWORD *)v24 == (_DWORD *)((char *)a2 + v38) )
            break;
          ++v22;
          v23 = ++a3;
          if ( v22 >= 8 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v25 = v22 + 1;
        v4 = v42;
        v42[119] = v25;
        goto LABEL_105;
      case 0xDu:
        if ( (v4[137] & 0x1000) == 0 )
          v4[137] |= 0x1000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 512);
        goto LABEL_104;
      case 0xEu:
        if ( (v4[137] & 0x2000) == 0 )
          v4[137] |= 0x2000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v26 = 0;
        v39 = v6[1];
        v27 = v42 + 129;
        a3 = v42 + 129;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v27);
          if ( v5 )
            return v5;
          v28 = v6[1];
          if ( v28 > (unsigned int)a2 + v39 )
            return -34;
          if ( (_DWORD *)v28 == (_DWORD *)((char *)a2 + v39) )
            break;
          ++v26;
          v27 = ++a3;
          if ( v26 >= 4 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v29 = v26 + 1;
        v4 = v42;
        v42[128] = v29;
        goto LABEL_105;
      case 0xFu:
        if ( (v4[137] & 0x4000) == 0 )
          v4[137] |= 0x4000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 532);
        goto LABEL_104;
      case 0x10u:
        if ( (v4[137] & 0x8000) == 0 )
          v4[137] |= 0x8000u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v30 = 0;
        v40 = v6[1];
        v31 = v42 + 134;
        a3 = v42 + 134;
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, v31);
          if ( v5 )
            return v5;
          v32 = v6[1];
          if ( v32 > (unsigned int)a2 + v40 )
            return -34;
          if ( (_DWORD *)v32 == (_DWORD *)((char *)a2 + v40) )
            break;
          ++v30;
          v31 = ++a3;
          if ( v30 >= 2 )
          {
            v4 = v42;
            goto LABEL_105;
          }
        }
        v33 = v30 + 1;
        v4 = v42;
        v42[133] = v33;
LABEL_105:
        v7 = v34;
        if ( v6[1] < v34 )
          continue;
LABEL_106:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      case 0x11u:
        if ( (v4[137] & 0x10000) == 0 )
          v4[137] |= 0x10000u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 544);
        goto LABEL_104;
      default:
        Int32 = TdrBuf::SkipField(v6, v41 & 0xF);
LABEL_104:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_105;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0040::DoDebugFormat
// Address Name: SUB_1012E410
// ============================================================
//----- (1012E410) --------------------------------------------------------
int __thiscall sub_1012E410(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1012E4C0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0040::DebugFormat
// Address Name: SUB_1012E4C0
// ============================================================
//----- (1012E4C0) --------------------------------------------------------
int __thiscall sub_1012E4C0(_DWORD *this, _DWORD *a2, int a3, char a4)
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
  int v31; // [esp+14h] [ebp+8h]
  int v32; // [esp+14h] [ebp+8h]
  int v33; // [esp+14h] [ebp+8h]
  int v34; // [esp+14h] [ebp+8h]
  int v35; // [esp+14h] [ebp+8h]
  int v36; // [esp+14h] [ebp+8h]

  result = print_field(a2, a3, a4, "[allocID]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[saveTM]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[state]", "%u", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[round]", "%u", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[count64]", "%d", *(this + 4));
          if ( !result )
          {
            v8 = *(this + 4);
            if ( v8 < 0 )
              return -6;
            if ( v8 > 64 )
              return -7;
            result = sub_1024A3B0(a2, a3, v7, "[sign64IDs]", v8);
            if ( !result )
            {
              v9 = 0;
              if ( (int)*(this + 4) <= 0 )
              {
LABEL_15:
                result = TdrBuf::WriteChar(a2, a4);
                if ( result )
                  return result;
                result = print_field(a2, a3, a4, "[count32]", "%d", *(this + 69));
                if ( result )
                  return result;
                v12 = *(this + 69);
                if ( v12 < 0 )
                  return -6;
                if ( v12 <= 32 )
                {
                  result = sub_1024A3B0(a2, a3, v11, "[sign32IDs]", v12);
                  if ( result )
                    return result;
                  v13 = 0;
                  if ( (int)*(this + 69) > 0 )
                  {
                    v14 = this + 70;
                    v32 = (int)(this + 70);
                    do
                    {
                      result = Printf(a2, " %u", *v14);
                      if ( result )
                        return result;
                      ++v13;
                      v14 = (_DWORD *)(v32 + 4);
                      v32 += 4;
                    }
                    while ( v13 < *(this + 69) );
                  }
                  result = TdrBuf::WriteChar(a2, a4);
                  if ( result )
                    return result;
                  result = print_field(a2, a3, a4, "[count16]", "%d", *(this + 102));
                  if ( result )
                    return result;
                  v16 = *(this + 102);
                  if ( v16 < 0 )
                    return -6;
                  if ( v16 <= 16 )
                  {
                    result = sub_1024A3B0(a2, a3, v15, "[sign16IDs]", v16);
                    if ( result )
                      return result;
                    v17 = 0;
                    if ( (int)*(this + 102) > 0 )
                    {
                      v18 = this + 103;
                      v33 = (int)(this + 103);
                      do
                      {
                        result = Printf(a2, " %u", *v18);
                        if ( result )
                          return result;
                        ++v17;
                        v18 = (_DWORD *)(v33 + 4);
                        v33 += 4;
                      }
                      while ( v17 < *(this + 102) );
                    }
                    result = TdrBuf::WriteChar(a2, a4);
                    if ( result )
                      return result;
                    result = print_field(a2, a3, a4, "[count8]", "%d", *(this + 119));
                    if ( result )
                      return result;
                    v20 = *(this + 119);
                    if ( v20 < 0 )
                      return -6;
                    if ( v20 <= 8 )
                    {
                      result = sub_1024A3B0(a2, a3, v19, "[sign8IDs]", v20);
                      if ( result )
                        return result;
                      v21 = 0;
                      if ( (int)*(this + 119) > 0 )
                      {
                        v22 = this + 120;
                        v34 = (int)(this + 120);
                        do
                        {
                          result = Printf(a2, " %u", *v22);
                          if ( result )
                            return result;
                          ++v21;
                          v22 = (_DWORD *)(v34 + 4);
                          v34 += 4;
                        }
                        while ( v21 < *(this + 119) );
                      }
                      result = TdrBuf::WriteChar(a2, a4);
                      if ( result )
                        return result;
                      result = print_field(a2, a3, a4, "[count4]", "%d", *(this + 128));
                      if ( result )
                        return result;
                      v24 = *(this + 128);
                      if ( v24 < 0 )
                        return -6;
                      if ( v24 <= 4 )
                      {
                        result = sub_1024A3B0(a2, a3, v23, "[sign4IDs]", v24);
                        if ( result )
                          return result;
                        v25 = 0;
                        if ( (int)*(this + 128) > 0 )
                        {
                          v26 = this + 129;
                          v35 = (int)(this + 129);
                          do
                          {
                            result = Printf(a2, " %u", *v26);
                            if ( result )
                              return result;
                            ++v25;
                            v26 = (_DWORD *)(v35 + 4);
                            v35 += 4;
                          }
                          while ( v25 < *(this + 128) );
                        }
                        result = TdrBuf::WriteChar(a2, a4);
                        if ( result )
                          return result;
                        result = print_field(a2, a3, a4, "[count2]", "%d", *(this + 133));
                        if ( result )
                          return result;
                        v28 = *(this + 133);
                        if ( v28 < 0 )
                          return -6;
                        if ( v28 <= 2 )
                        {
                          result = sub_1024A3B0(a2, a3, v27, "[sign2IDs]", v28);
                          if ( !result )
                          {
                            v29 = 0;
                            if ( (int)*(this + 133) <= 0 )
                            {
LABEL_60:
                              result = TdrBuf::WriteChar(a2, a4);
                              if ( !result )
                                return print_field(a2, a3, a4, "[winSignID]", "%u", *(this + 136));
                            }
                            else
                            {
                              v30 = this + 134;
                              v36 = (int)(this + 134);
                              while ( 1 )
                              {
                                result = Printf(a2, " %u", *v30);
                                if ( result )
                                  break;
                                ++v29;
                                v30 = (_DWORD *)(v36 + 4);
                                v36 += 4;
                                if ( v29 >= *(this + 133) )
                                  goto LABEL_60;
                              }
                            }
                          }
                          return result;
                        }
                      }
                    }
                  }
                }
                return -7;
              }
              v10 = this + 5;
              v31 = (int)(this + 5);
              while ( 1 )
              {
                result = Printf(a2, " %u", *v10);
                if ( result )
                  break;
                ++v9;
                v10 = (_DWORD *)(v31 + 4);
                v31 += 4;
                if ( v9 >= *(this + 4) )
                  goto LABEL_15;
              }
            }
          }
        }
      }
    }
  }
  return result;
}
// 1012E5A9: variable 'v7' is possibly undefined
// 1012E64A: variable 'v11' is possibly undefined
// 1012E6F7: variable 'v15' is possibly undefined
// 1012E7A7: variable 'v19' is possibly undefined
// 1012E857: variable 'v23' is possibly undefined
// 1012E907: variable 'v27' is possibly undefined



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



