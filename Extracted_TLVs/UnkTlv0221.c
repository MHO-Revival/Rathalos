// ============================================================
// Name: TLV::UnkTlv0221::Read
// Address Name: SUB_1020A600
// ============================================================
//----- (1020A600) --------------------------------------------------------
int __thiscall sub_1020A600(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  int *v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = (int *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_1020A6D0(this, &v9, v8);
  else
    result = sub_1020AB60(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0221::Read_0xAA
// Address Name: SUB_1020A6D0
// ============================================================
//----- (1020A6D0) --------------------------------------------------------
int __thiscall sub_1020A6D0(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int VarInt; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // ebx
  int *v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ebx
  int *v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ebx
  int *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ebx
  int *v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  int *v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  int *v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // ebx
  int *v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // [esp+Ch] [ebp-10h]
  int v31; // [esp+10h] [ebp-Ch]
  int v32; // [esp+10h] [ebp-Ch]
  int v33; // [esp+10h] [ebp-Ch]
  int v34; // [esp+10h] [ebp-Ch]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  unsigned int v38; // [esp+14h] [ebp-8h] BYREF
  int *v39; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarInt = 0;
  v39 = this;
  v38 = 0;
  *(this + 49) = 0;
  v7 = (unsigned int)v3 + v4[1];
  v30 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_15:
    if ( v4[1] > v7 )
      return -34;
    return VarInt;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v38);
      if ( !result )
      {
        switch ( v38 >> 4 )
        {
          case 2u:
            if ( (v5[49] & 1) == 0 )
              v5[49] |= 1u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v9 = 0;
              v31 = v4[1];
              v10 = v39;
              a3 = v39;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v10);
                if ( VarInt )
                  return VarInt;
                v11 = v4[1];
                if ( v11 > (unsigned int)a2 + v31 )
                  goto LABEL_81;
                if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v31) )
                {
                  ++v9;
                  v10 = ++a3;
                  if ( v9 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 4u:
            if ( (v5[49] & 2) == 0 )
              v5[49] |= 2u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v12 = 0;
              v32 = v4[1];
              v13 = v39 + 7;
              a3 = v39 + 7;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v13);
                if ( VarInt )
                  return VarInt;
                v14 = v4[1];
                if ( v14 > (unsigned int)a2 + v32 )
                  goto LABEL_81;
                if ( (_DWORD *)v14 != (_DWORD *)((char *)a2 + v32) )
                {
                  ++v12;
                  v13 = ++a3;
                  if ( v12 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 5u:
            if ( (v5[49] & 4) == 0 )
              v5[49] |= 4u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v15 = 0;
              v33 = v4[1];
              v16 = v39 + 14;
              a3 = v39 + 14;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v16);
                if ( VarInt )
                  return VarInt;
                v17 = v4[1];
                if ( v17 > (unsigned int)a2 + v33 )
                  goto LABEL_81;
                if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + v33) )
                {
                  ++v15;
                  v16 = ++a3;
                  if ( v15 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 6u:
            if ( (v5[49] & 8) == 0 )
              v5[49] |= 8u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v18 = 0;
              v34 = v4[1];
              v19 = v39 + 21;
              a3 = v39 + 21;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v19);
                if ( VarInt )
                  return VarInt;
                v20 = v4[1];
                if ( v20 > (unsigned int)a2 + v34 )
                  goto LABEL_81;
                if ( (_DWORD *)v20 != (_DWORD *)((char *)a2 + v34) )
                {
                  ++v18;
                  v19 = ++a3;
                  if ( v18 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 7u:
            if ( (v5[49] & 0x10) == 0 )
              v5[49] |= 0x10u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v21 = 0;
              v35 = v4[1];
              v22 = v39 + 28;
              a3 = v39 + 28;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v22);
                if ( VarInt )
                  return VarInt;
                v23 = v4[1];
                if ( v23 > (unsigned int)a2 + v35 )
                  goto LABEL_81;
                if ( (_DWORD *)v23 != (_DWORD *)((char *)a2 + v35) )
                {
                  ++v21;
                  v22 = ++a3;
                  if ( v21 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 8u:
            if ( (v5[49] & 0x20) == 0 )
              v5[49] |= 0x20u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v24 = 0;
              v36 = v4[1];
              v25 = v39 + 35;
              a3 = v39 + 35;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v25);
                if ( VarInt )
                  return VarInt;
                v26 = v4[1];
                if ( v26 > (unsigned int)a2 + v36 )
                  goto LABEL_81;
                if ( (_DWORD *)v26 != (_DWORD *)((char *)a2 + v36) )
                {
                  ++v24;
                  v25 = ++a3;
                  if ( v24 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 9u:
            if ( (v5[49] & 0x40) == 0 )
              v5[49] |= 0x40u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( result )
              return result;
            if ( a2 )
            {
              v27 = 0;
              v37 = v4[1];
              v28 = v39 + 42;
              a3 = v39 + 42;
              while ( 1 )
              {
                VarInt = TdrBuf::ReadVarInt(v4, v28);
                if ( VarInt )
                  return VarInt;
                v29 = v4[1];
                if ( v29 > (unsigned int)a2 + v37 )
                  break;
                if ( (_DWORD *)v29 != (_DWORD *)((char *)a2 + v37) )
                {
                  ++v27;
                  v28 = ++a3;
                  if ( v27 < 7 )
                    continue;
                }
LABEL_13:
                v5 = v39;
                goto LABEL_14;
              }
LABEL_81:
              result = -34;
            }
            else
            {
LABEL_82:
              result = -37;
            }
            break;
          default:
            VarInt = TdrBuf::SkipField(v4, v38 & 0xF);
            if ( VarInt )
              return VarInt;
LABEL_14:
            v7 = v30;
            if ( v4[1] >= v30 )
              goto LABEL_15;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0221::Read_0x99
// Address Name: SUB_1020AB60
// ============================================================
//----- (1020AB60) --------------------------------------------------------
int __thiscall sub_1020AB60(_DWORD *this, _DWORD *a2, _BYTE *a3)
{
  _BYTE *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // ebx
  int Int32; // edi
  unsigned int v7; // eax
  int result; // eax
  unsigned int v9; // ebx
  _BYTE *v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ebx
  _BYTE *v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ebx
  _BYTE *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // ebx
  _BYTE *v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // ebx
  _BYTE *v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ebx
  _BYTE *v25; // eax
  unsigned int v26; // ecx
  unsigned int v27; // ebx
  _BYTE *v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // [esp+Ch] [ebp-10h]
  int v31; // [esp+10h] [ebp-Ch]
  int v32; // [esp+10h] [ebp-Ch]
  int v33; // [esp+10h] [ebp-Ch]
  int v34; // [esp+10h] [ebp-Ch]
  int v35; // [esp+10h] [ebp-Ch]
  int v36; // [esp+10h] [ebp-Ch]
  int v37; // [esp+10h] [ebp-Ch]
  unsigned int v38; // [esp+14h] [ebp-8h] BYREF
  _BYTE *v39; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int32 = 0;
  v39 = this;
  v38 = 0;
  *(this + 49) = 0;
  v7 = (unsigned int)&v3[v4[1]];
  v30 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_15:
    if ( v4[1] > v7 )
      return -34;
    return Int32;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v38);
      if ( !result )
      {
        switch ( v38 >> 4 )
        {
          case 2u:
            if ( (v5[49] & 1) == 0 )
              v5[49] |= 1u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v9 = 0;
              v31 = v4[1];
              v10 = v39;
              a3 = v39;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v10);
                if ( Int32 )
                  return Int32;
                v11 = v4[1];
                if ( v11 > (unsigned int)a2 + v31 )
                  goto LABEL_81;
                if ( (_DWORD *)v11 != (_DWORD *)((char *)a2 + v31) )
                {
                  ++v9;
                  v10 = a3 + 4;
                  a3 += 4;
                  if ( v9 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 4u:
            if ( (v5[49] & 2) == 0 )
              v5[49] |= 2u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v12 = 0;
              v32 = v4[1];
              v13 = v39 + 28;
              a3 = v39 + 28;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v13);
                if ( Int32 )
                  return Int32;
                v14 = v4[1];
                if ( v14 > (unsigned int)a2 + v32 )
                  goto LABEL_81;
                if ( (_DWORD *)v14 != (_DWORD *)((char *)a2 + v32) )
                {
                  ++v12;
                  v13 = a3 + 4;
                  a3 += 4;
                  if ( v12 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 5u:
            if ( (v5[49] & 4) == 0 )
              v5[49] |= 4u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v15 = 0;
              v33 = v4[1];
              v16 = v39 + 56;
              a3 = v39 + 56;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v16);
                if ( Int32 )
                  return Int32;
                v17 = v4[1];
                if ( v17 > (unsigned int)a2 + v33 )
                  goto LABEL_81;
                if ( (_DWORD *)v17 != (_DWORD *)((char *)a2 + v33) )
                {
                  ++v15;
                  v16 = a3 + 4;
                  a3 += 4;
                  if ( v15 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 6u:
            if ( (v5[49] & 8) == 0 )
              v5[49] |= 8u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v18 = 0;
              v34 = v4[1];
              v19 = v39 + 84;
              a3 = v39 + 84;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v19);
                if ( Int32 )
                  return Int32;
                v20 = v4[1];
                if ( v20 > (unsigned int)a2 + v34 )
                  goto LABEL_81;
                if ( (_DWORD *)v20 != (_DWORD *)((char *)a2 + v34) )
                {
                  ++v18;
                  v19 = a3 + 4;
                  a3 += 4;
                  if ( v18 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 7u:
            if ( (v5[49] & 0x10) == 0 )
              v5[49] |= 0x10u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v21 = 0;
              v35 = v4[1];
              v22 = v39 + 112;
              a3 = v39 + 112;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v22);
                if ( Int32 )
                  return Int32;
                v23 = v4[1];
                if ( v23 > (unsigned int)a2 + v35 )
                  goto LABEL_81;
                if ( (_DWORD *)v23 != (_DWORD *)((char *)a2 + v35) )
                {
                  ++v21;
                  v22 = a3 + 4;
                  a3 += 4;
                  if ( v21 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 8u:
            if ( (v5[49] & 0x20) == 0 )
              v5[49] |= 0x20u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( !result )
            {
              if ( !a2 )
                goto LABEL_82;
              v24 = 0;
              v36 = v4[1];
              v25 = v39 + 140;
              a3 = v39 + 140;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v25);
                if ( Int32 )
                  return Int32;
                v26 = v4[1];
                if ( v26 > (unsigned int)a2 + v36 )
                  goto LABEL_81;
                if ( (_DWORD *)v26 != (_DWORD *)((char *)a2 + v36) )
                {
                  ++v24;
                  v25 = a3 + 4;
                  a3 += 4;
                  if ( v24 < 7 )
                    continue;
                }
                goto LABEL_13;
              }
            }
            return result;
          case 9u:
            if ( (v5[49] & 0x40) == 0 )
              v5[49] |= 0x40u;
            a2 = 0;
            result = TdrBuf::ReadInt32(v4, &a2);
            if ( result )
              return result;
            if ( a2 )
            {
              v27 = 0;
              v37 = v4[1];
              v28 = v39 + 168;
              a3 = v39 + 168;
              while ( 1 )
              {
                Int32 = TdrBuf::ReadInt32(v4, v28);
                if ( Int32 )
                  return Int32;
                v29 = v4[1];
                if ( v29 > (unsigned int)a2 + v37 )
                  break;
                if ( (_DWORD *)v29 != (_DWORD *)((char *)a2 + v37) )
                {
                  ++v27;
                  v28 = a3 + 4;
                  a3 += 4;
                  if ( v27 < 7 )
                    continue;
                }
LABEL_13:
                v5 = v39;
                goto LABEL_14;
              }
LABEL_81:
              result = -34;
            }
            else
            {
LABEL_82:
              result = -37;
            }
            break;
          default:
            Int32 = TdrBuf::SkipField(v4, v38 & 0xF);
            if ( Int32 )
              return Int32;
LABEL_14:
            v7 = v30;
            if ( v4[1] >= v30 )
              goto LABEL_15;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0221::DoDebugFormat
// Address Name: SUB_1020B010
// ============================================================
//----- (1020B010) --------------------------------------------------------
int __thiscall sub_1020B010(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1020B0C0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0221::DebugFormat
// Address Name: SUB_1020B0C0
// ============================================================
//----- (1020B0C0) --------------------------------------------------------
int __thiscall sub_1020B0C0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v5; // edi
  int v6; // ecx
  unsigned int v7; // edi
  _DWORD *v8; // ebx
  int v9; // ecx
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  int v12; // ecx
  unsigned int v13; // edi
  _DWORD *v14; // ebx
  int v15; // ecx
  unsigned int v16; // edi
  _DWORD *v17; // ebx
  int v18; // ecx
  unsigned int v19; // edi
  _DWORD *v20; // ebx
  int v21; // ecx
  int v22; // edi
  _DWORD *i; // ebx
  int v24; // ecx

  if ( !"[oCharLevel]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x9Du);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s[0 : %I64i]:", "[oCharLevel]", 6LL);
    if ( !result )
    {
      v5 = 0;
      while ( 1 )
      {
        result = Printf(a2, " %d", *(this + v5));
        if ( result )
          break;
        if ( (unsigned int)++v5 >= 7 )
        {
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0xC4u);
          v6 = a2[1];
          if ( (unsigned int)(a2[2] - v6) < 2 )
            return -1;
          *(_BYTE *)(v6 + *a2) = a4;
          *(_BYTE *)(++a2[1] + *a2) = 0;
          if ( !"[oCharExp]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x9Du);
          result = sub_1024A140(a3);
          if ( !result )
          {
            result = Printf(a2, "%s[0 : %I64i]:", "[oCharExp]", 6LL);
            if ( !result )
            {
              v7 = 0;
              v8 = this + 7;
              while ( 1 )
              {
                result = Printf(a2, " %d", *v8);
                if ( result )
                  break;
                ++v7;
                ++v8;
                if ( v7 >= 7 )
                {
                  if ( a2[1] > a2[2] )
                    _wassert(
                      L"position <= length",
                      L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                      0xC4u);
                  v9 = a2[1];
                  if ( (unsigned int)(a2[2] - v9) < 2 )
                    return -1;
                  *(_BYTE *)(v9 + *a2) = a4;
                  *(_BYTE *)(++a2[1] + *a2) = 0;
                  if ( !"[oCharGlut]" )
                    _wassert(
                      L"NULL != variable",
                      L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                      0x9Du);
                  result = sub_1024A140(a3);
                  if ( !result )
                  {
                    result = Printf(a2, "%s[0 : %I64i]:", "[oCharGlut]", 6LL);
                    if ( !result )
                    {
                      v10 = 0;
                      v11 = this + 14;
                      while ( 1 )
                      {
                        result = Printf(a2, " %d", *v11);
                        if ( result )
                          break;
                        ++v10;
                        ++v11;
                        if ( v10 >= 7 )
                        {
                          if ( a2[1] > a2[2] )
                            _wassert(
                              L"position <= length",
                              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                              0xC4u);
                          v12 = a2[1];
                          if ( (unsigned int)(a2[2] - v12) < 2 )
                            return -1;
                          *(_BYTE *)(v12 + *a2) = a4;
                          *(_BYTE *)(++a2[1] + *a2) = 0;
                          if ( !"[oEvloveStage]" )
                            _wassert(
                              L"NULL != variable",
                              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                              0x9Du);
                          result = sub_1024A140(a3);
                          if ( !result )
                          {
                            result = Printf(a2, "%s[0 : %I64i]:", "[oEvloveStage]", 6LL);
                            if ( !result )
                            {
                              v13 = 0;
                              v14 = this + 21;
                              while ( 1 )
                              {
                                result = Printf(a2, " %d", *v14);
                                if ( result )
                                  break;
                                ++v13;
                                ++v14;
                                if ( v13 >= 7 )
                                {
                                  if ( a2[1] > a2[2] )
                                    _wassert(
                                      L"position <= length",
                                      L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                                      0xC4u);
                                  v15 = a2[1];
                                  if ( (unsigned int)(a2[2] - v15) < 2 )
                                    return -1;
                                  *(_BYTE *)(v15 + *a2) = a4;
                                  *(_BYTE *)(++a2[1] + *a2) = 0;
                                  if ( !"[oImage]" )
                                    _wassert(
                                      L"NULL != variable",
                                      L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                                      0x9Du);
                                  result = sub_1024A140(a3);
                                  if ( !result )
                                  {
                                    result = Printf(a2, "%s[0 : %I64i]:", "[oImage]", 6LL);
                                    if ( !result )
                                    {
                                      v16 = 0;
                                      v17 = this + 28;
                                      while ( 1 )
                                      {
                                        result = Printf(a2, " %d", *v17);
                                        if ( result )
                                          break;
                                        ++v16;
                                        ++v17;
                                        if ( v16 >= 7 )
                                        {
                                          if ( a2[1] > a2[2] )
                                            _wassert(
                                              L"position <= length",
                                              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                                              0xC4u);
                                          v18 = a2[1];
                                          if ( (unsigned int)(a2[2] - v18) < 2 )
                                            return -1;
                                          *(_BYTE *)(v18 + *a2) = a4;
                                          *(_BYTE *)(++a2[1] + *a2) = 0;
                                          if ( !"[oFollow]" )
                                            _wassert(
                                              L"NULL != variable",
                                              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                                              0x9Du);
                                          result = sub_1024A140(a3);
                                          if ( !result )
                                          {
                                            result = Printf(a2, "%s[0 : %I64i]:", "[oFollow]", 6LL);
                                            if ( !result )
                                            {
                                              v19 = 0;
                                              v20 = this + 35;
                                              while ( 1 )
                                              {
                                                result = Printf(a2, " %d", *v20);
                                                if ( result )
                                                  break;
                                                ++v19;
                                                ++v20;
                                                if ( v19 >= 7 )
                                                {
                                                  if ( a2[1] > a2[2] )
                                                    _wassert(
                                                      L"position <= length",
                                                      L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                                                      0xC4u);
                                                  v21 = a2[1];
                                                  if ( (unsigned int)(a2[2] - v21) < 2 )
                                                    return -1;
                                                  *(_BYTE *)(v21 + *a2) = a4;
                                                  *(_BYTE *)(++a2[1] + *a2) = 0;
                                                  if ( !"[oFeedTime]" )
                                                    _wassert(
                                                      L"NULL != variable",
                                                      L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                                                      0x9Du);
                                                  result = sub_1024A140(a3);
                                                  if ( !result )
                                                  {
                                                    result = Printf(a2, "%s[0 : %I64i]:", "[oFeedTime]", 6LL);
                                                    if ( !result )
                                                    {
                                                      v22 = 0;
                                                      for ( i = this + 42; ; ++i )
                                                      {
                                                        result = Printf(a2, " %d", *i);
                                                        if ( result )
                                                          break;
                                                        if ( (unsigned int)++v22 >= 7 )
                                                        {
                                                          if ( a2[1] > a2[2] )
                                                            _wassert(
                                                              L"position <= length",
                                                              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                                                              0xC4u);
                                                          v24 = a2[1];
                                                          if ( (unsigned int)(a2[2] - v24) >= 2 )
                                                          {
                                                            *(_BYTE *)(v24 + *a2) = a4;
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



