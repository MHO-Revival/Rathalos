// ============================================================
// Name: TLV::UnkTlv0072::Read
// Address Name: SUB_10148AD0
// ============================================================
//----- (10148AD0) --------------------------------------------------------
int __thiscall sub_10148AD0(_DWORD *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10148BA0(this, &v9, v8);
  else
    result = sub_10148F70(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0072::Read_0xAA
// Address Name: SUB_10148BA0
// ============================================================
//----- (10148BA0) --------------------------------------------------------
int __thiscall sub_10148BA0(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax
  _DWORD *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned __int16 v9; // di
  _DWORD *v10; // ebx
  unsigned int v11; // edx
  __int16 v12; // cx
  unsigned __int8 v13; // bl
  unsigned int v14; // edx
  int v15; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v16; // [esp+14h] [ebp-14h]
  unsigned int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch] BYREF
  int v19; // [esp+20h] [ebp-8h]
  unsigned int v20; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v17 = 0;
  v16 = this;
  *(this + 73911) = 0;
  v5 = a2[1] + a3;
  v20 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_63;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v4[73911] & 1) == 0 )
          v4[73911] |= 1u;
        result = TdrBuf::ReadByte(a2, v4);
        goto LABEL_61;
      case 2u:
        if ( (v4[73911] & 2) == 0 )
          v4[73911] |= 2u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v6 = 0;
        v18 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte(a2, (_BYTE *)v4 + v6 + 1);
          if ( result )
            return result;
          v7 = a2[1];
          if ( v7 > v18 + v15 )
            return -34;
          if ( v7 != v18 + v15 )
          {
            if ( ++v6 >= 0xAu )
              goto LABEL_62;
            continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (v4[73911] & 4) == 0 )
          v4[73911] |= 4u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v6 = 0;
        v18 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadVarUInt(a2, (_DWORD *)((char *)&v4[v6 + 2] + 3));
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v18 + v15 )
            return -34;
          if ( v8 != v18 + v15 )
          {
            if ( ++v6 >= 0xAu )
              goto LABEL_62;
            continue;
          }
          break;
        }
LABEL_17:
        *(_BYTE *)v4 = v6 + 1;
        goto LABEL_62;
      case 4u:
        if ( (v4[73911] & 8) == 0 )
          v4[73911] |= 8u;
        result = TdrBuf::ReadVarUShort(a2, (_DWORD *)((char *)v4 + 51));
        goto LABEL_61;
      case 5u:
        if ( (v4[73911] & 0x10) == 0 )
          v4[73911] |= 0x10u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v9 = 0;
        v10 = v16;
        v19 = a2[1];
        while ( 1 )
        {
          v18 = 0;
          result = TdrBuf::ReadInt32(a2, &v18);
          if ( result )
            return result;
          if ( v18 )
          {
            result = sub_10147090((int)v10 + 59 * v9 + 53, a2, v18);
            if ( result )
              return result;
          }
          v11 = a2[1];
          if ( v11 > v19 + v15 )
            return -34;
          if ( v11 == v19 + v15 )
            break;
          if ( ++v9 >= 0x1388u )
          {
            v4 = v10;
            goto LABEL_62;
          }
        }
        v12 = v9 + 1;
        v4 = v10;
        *(_WORD *)((char *)v10 + 51) = v12;
        goto LABEL_62;
      case 6u:
        if ( (v4[73911] & 0x20) == 0 )
          v4[73911] |= 0x20u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)v4 + 295053);
        goto LABEL_61;
      case 7u:
        if ( (v4[73911] & 0x40) == 0 )
          v4[73911] |= 0x40u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v13 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v18 = 0;
          result = TdrBuf::ReadInt32(a2, &v18);
          if ( result )
            return result;
          if ( v18 )
          {
            result = sub_10147C20((int)v4 + 59 * v13 + 295054, a2, v18);
            if ( result )
              return result;
          }
          v14 = a2[1];
          if ( v14 > v19 + v15 )
            return -34;
          if ( v14 == v19 + v15 )
            break;
          if ( ++v13 >= 0xAu )
            goto LABEL_62;
        }
        *((_BYTE *)v4 + 295053) = v13 + 1;
LABEL_62:
        v5 = v20;
        if ( a2[1] < v20 )
          continue;
LABEL_63:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v17 & 0xF);
LABEL_61:
        if ( !result )
          goto LABEL_62;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0072::Read_0x99
// Address Name: SUB_10148F70
// ============================================================
//----- (10148F70) --------------------------------------------------------
int __thiscall sub_10148F70(_DWORD *this, _DWORD *a2, int a3)
{
  int result; // eax
  _DWORD *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  unsigned int v8; // edx
  unsigned __int16 v9; // di
  _DWORD *v10; // ebx
  unsigned int v11; // edx
  __int16 v12; // cx
  unsigned __int8 v13; // bl
  unsigned int v14; // edx
  int v15; // [esp+10h] [ebp-18h] BYREF
  _DWORD *v16; // [esp+14h] [ebp-14h]
  unsigned int v17; // [esp+18h] [ebp-10h] BYREF
  int v18; // [esp+1Ch] [ebp-Ch] BYREF
  int v19; // [esp+20h] [ebp-8h]
  unsigned int v20; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v17 = 0;
  v16 = this;
  *(this + 73911) = 0;
  v5 = a2[1] + a3;
  v20 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_63;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v4[73911] & 1) == 0 )
          v4[73911] |= 1u;
        result = TdrBuf::ReadByte(a2, v4);
        goto LABEL_61;
      case 2u:
        if ( (v4[73911] & 2) == 0 )
          v4[73911] |= 2u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v6 = 0;
        v18 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadByte(a2, (_BYTE *)v4 + v6 + 1);
          if ( result )
            return result;
          v7 = a2[1];
          if ( v7 > v18 + v15 )
            return -34;
          if ( v7 != v18 + v15 )
          {
            if ( ++v6 >= 0xAu )
              goto LABEL_62;
            continue;
          }
          goto LABEL_17;
        }
      case 3u:
        if ( (v4[73911] & 4) == 0 )
          v4[73911] |= 4u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v6 = 0;
        v18 = a2[1];
        while ( 2 )
        {
          result = TdrBuf::ReadInt32(a2, (_BYTE *)&v4[v6 + 2] + 3);
          if ( result )
            return result;
          v8 = a2[1];
          if ( v8 > v18 + v15 )
            return -34;
          if ( v8 != v18 + v15 )
          {
            if ( ++v6 >= 0xAu )
              goto LABEL_62;
            continue;
          }
          break;
        }
LABEL_17:
        *(_BYTE *)v4 = v6 + 1;
        goto LABEL_62;
      case 4u:
        if ( (v4[73911] & 8) == 0 )
          v4[73911] |= 8u;
        result = TdrBuf::ReadInt16(a2, (_BYTE *)v4 + 51);
        goto LABEL_61;
      case 5u:
        if ( (v4[73911] & 0x10) == 0 )
          v4[73911] |= 0x10u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v9 = 0;
        v10 = v16;
        v19 = a2[1];
        while ( 1 )
        {
          v18 = 0;
          result = TdrBuf::ReadInt32(a2, &v18);
          if ( result )
            return result;
          if ( v18 )
          {
            result = sub_10147280((int)v10 + 59 * v9 + 53, a2, v18);
            if ( result )
              return result;
          }
          v11 = a2[1];
          if ( v11 > v19 + v15 )
            return -34;
          if ( v11 == v19 + v15 )
            break;
          if ( ++v9 >= 0x1388u )
          {
            v4 = v10;
            goto LABEL_62;
          }
        }
        v12 = v9 + 1;
        v4 = v10;
        *(_WORD *)((char *)v10 + 51) = v12;
        goto LABEL_62;
      case 6u:
        if ( (v4[73911] & 0x20) == 0 )
          v4[73911] |= 0x20u;
        result = TdrBuf::ReadByte(a2, (_BYTE *)v4 + 295053);
        goto LABEL_61;
      case 7u:
        if ( (v4[73911] & 0x40) == 0 )
          v4[73911] |= 0x40u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v13 = 0;
        v19 = a2[1];
        while ( 1 )
        {
          v18 = 0;
          result = TdrBuf::ReadInt32(a2, &v18);
          if ( result )
            return result;
          if ( v18 )
          {
            result = sub_10147E10((int)v4 + 59 * v13 + 295054, a2, v18);
            if ( result )
              return result;
          }
          v14 = a2[1];
          if ( v14 > v19 + v15 )
            return -34;
          if ( v14 == v19 + v15 )
            break;
          if ( ++v13 >= 0xAu )
            goto LABEL_62;
        }
        *((_BYTE *)v4 + 295053) = v13 + 1;
LABEL_62:
        v5 = v20;
        if ( a2[1] < v20 )
          continue;
LABEL_63:
        if ( a2[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(a2, v17 & 0xF);
LABEL_61:
        if ( !result )
          goto LABEL_62;
        return result;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0072::DoDebugFormat
// Address Name: SUB_10149360
// ============================================================
//----- (10149360) --------------------------------------------------------
int __thiscall sub_10149360(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10149410(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0072::DebugFormat
// Address Name: SUB_10149410
// ============================================================
//----- (10149410) --------------------------------------------------------
int __thiscall sub_10149410(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // ecx
  unsigned __int8 v9; // al
  int v10; // ecx
  unsigned __int8 v11; // al
  unsigned __int16 v12; // cx
  int v13; // eax
  unsigned __int8 *v14; // ecx
  unsigned __int8 v15; // cl
  unsigned __int8 v16; // al
  unsigned __int8 *v17; // ecx
  int v18; // [esp+14h] [ebp+8h]
  int v19; // [esp+14h] [ebp+8h]
  int v20; // [esp+18h] [ebp+Ch]
  unsigned __int8 v21; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v22; // [esp+1Bh] [ebp+Fh]
  unsigned __int8 v23; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[globalStatCnt]", "0x%02x", *this);
  if ( !result )
  {
    if ( *this > 0xAu )
      return -7;
    result = sub_1024A3B0(a2, a3, v8, "[globalStatDataType]", *this);
    if ( !result )
    {
      v9 = 0;
      v21 = 0;
      if ( *this )
      {
        while ( 1 )
        {
          result = Printf(a2, " 0x%02x", *(this + v9 + 1));
          if ( result )
            break;
          v9 = v21 + 1;
          v21 = v9;
          if ( v9 >= *this )
            goto LABEL_8;
        }
      }
      else
      {
LABEL_8:
        result = TdrBuf::WriteChar(a2, a4);
        if ( !result )
        {
          if ( *this > 0xAu )
            return -7;
          result = sub_1024A3B0(a2, a3, v10, "[globalStatDataVal]", *this);
          if ( !result )
          {
            v11 = 0;
            v22 = 0;
            if ( *this )
            {
              while ( 1 )
              {
                result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v11 + 11));
                if ( result )
                  break;
                v11 = v22 + 1;
                v22 = v11;
                if ( v11 >= *this )
                  goto LABEL_14;
              }
            }
            else
            {
LABEL_14:
              result = TdrBuf::WriteChar(a2, a4);
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[levelDataCnt]", "%d", *(unsigned __int16 *)(this + 51));
                if ( !result )
                {
                  v12 = *(_WORD *)(this + 51);
                  if ( v12 > 0x1388u )
                    return -7;
                  LOWORD(v13) = 0;
                  v18 = 0;
                  if ( v12 )
                  {
                    while ( 1 )
                    {
                      v20 = (unsigned __int16)v13;
                      result = sub_1024A230(a2, a3, a4, "[levelStatDataInfo]", (unsigned __int16)v13);
                      if ( result )
                        break;
                      v14 = this + 59 * v20 + 53;
                      result = a3 >= 0 ? sub_10147540(v14, a2, a3 + 1, a4) : sub_10147540(v14, a2, a3, a4);
                      if ( result )
                        break;
                      v13 = v18 + 1;
                      v18 = v13;
                      if ( (unsigned __int16)v13 >= *(_WORD *)(this + 51) )
                        goto LABEL_24;
                    }
                  }
                  else
                  {
LABEL_24:
                    result = print_field(a2, a3, a4, "[levelModeDataCnt]", "0x%02x", *(this + 295053));
                    if ( !result )
                    {
                      v15 = *(this + 295053);
                      if ( v15 > 0xAu )
                        return -7;
                      v16 = 0;
                      v23 = 0;
                      if ( v15 )
                      {
                        while ( 1 )
                        {
                          v19 = v16;
                          if ( !"[levelModeStatDataInfo]" )
                            _wassert(
                              L"NULL != variable",
                              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                              0x43u);
                          result = sub_1024A140(a3);
                          if ( result )
                            break;
                          result = Printf(a2, "%s[%u]%c", "[levelModeStatDataInfo]", v19, a4);
                          if ( result )
                            break;
                          v17 = this + 59 * v19 + 295054;
                          result = a3 >= 0 ? sub_101480D0(v17, a2, a3 + 1, a4) : sub_101480D0(v17, a2, a3, a4);
                          if ( result )
                            break;
                          v16 = v23 + 1;
                          v23 = v16;
                          if ( v16 >= *(this + 295053) )
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
  }
  return result;
}
// 10149463: variable 'v8' is possibly undefined
// 101494D3: variable 'v10' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10147C20
// ============================================================
//----- (10147C20) --------------------------------------------------------
int __thiscall sub_10147C20(int this, _DWORD *a2, int a3)
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
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
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
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        VarInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_32:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10147090
// ============================================================
//----- (10147090) --------------------------------------------------------
int __thiscall sub_10147090(int this, _DWORD *a2, int a3)
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
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, (int *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        VarInt = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
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
          Byte = TdrBuf::ReadVarUInt(v4, (_DWORD *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        VarInt = TdrBuf::SkipField(v4, v15 & 0xF);
LABEL_32:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_33;
        return Byte;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10147E10
// ============================================================
//----- (10147E10) --------------------------------------------------------
int __thiscall sub_10147E10(int this, _DWORD *a2, int a3)
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
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
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
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
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
// Address Name: SUB_10147280
// ============================================================
//----- (10147280) --------------------------------------------------------
int __thiscall sub_10147280(int this, _DWORD *a2, int a3)
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
  *(_DWORD *)(this + 55) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_34;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v5 + 55) & 1) == 0 )
          *(_DWORD *)(v5 + 55) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5);
        goto LABEL_32;
      case 2u:
        if ( (*(_DWORD *)(v5 + 55) & 2) == 0 )
          *(_DWORD *)(v5 + 55) |= 2u;
        Int32 = TdrBuf::ReadByte(v4, (_BYTE *)(v5 + 4));
        goto LABEL_32;
      case 3u:
        if ( (*(_DWORD *)(v5 + 55) & 4) == 0 )
          *(_DWORD *)(v5 + 55) |= 4u;
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
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)(v16 + 5 + v10));
          if ( Byte )
            return Byte;
          v11 = v4[1];
          if ( v11 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + a3) )
            goto LABEL_20;
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
        goto LABEL_33;
      case 4u:
        if ( (*(_DWORD *)(v5 + 55) & 8) == 0 )
          *(_DWORD *)(v5 + 55) |= 8u;
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
          Byte = TdrBuf::ReadInt32(v4, (_BYTE *)(v16 + 4 * v10 + 15));
          if ( Byte )
            return Byte;
          v13 = v4[1];
          if ( v13 > (unsigned int)a2 + a3 )
            return -34;
          if ( (_DWORD *)v13 == (_DWORD *)((char *)a2 + a3) )
          {
LABEL_20:
            v12 = v16;
            *(_BYTE *)(v16 + 4) = v10 + 1;
            v5 = v12;
            goto LABEL_33;
          }
          ++v10;
        }
        while ( v10 < 0xAu );
        v5 = v16;
LABEL_33:
        v7 = v14;
        if ( v4[1] < v14 )
          continue;
LABEL_34:
        if ( v4[1] > v7 )
          return -34;
        return Byte;
      default:
        Int32 = TdrBuf::SkipField(v4, v15 & 0xF);
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
// Address Name: SUB_101480D0
// ============================================================
//----- (101480D0) --------------------------------------------------------
int __thiscall sub_101480D0(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  result = print_field(a2, a3, a4, "[levelMode]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[modeStatCnt]", "0x%02x", (unsigned __int8)*(this + 4));
    if ( !result )
    {
      v7 = *(this + 4);
      if ( v7 > 0xAu )
        return -7;
      result = sub_1024A3B0(a2, a3, v6, "[modeStatType]", v7);
      if ( !result )
      {
        v8 = 0;
        if ( *(this + 4) )
        {
          while ( 1 )
          {
            result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v8 + 5));
            if ( result )
              break;
            if ( ++v8 >= *(this + 4) )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          result = TdrBuf::WriteChar(a2, a4);
          if ( !result )
          {
            v10 = *(this + 4);
            if ( v10 > 0xAu )
              return -7;
            result = sub_1024A3B0(a2, a3, v9, "[modeStatVal]", v10);
            if ( !result )
            {
              v11 = 0;
              if ( *(this + 4) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v11 + 15));
                  if ( result )
                    break;
                  if ( ++v11 >= *(this + 4) )
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
  return result;
}
// 10148147: variable 'v6' is possibly undefined
// 101481A8: variable 'v9' is possibly undefined



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
// Address Name: SUB_10147540
// ============================================================
//----- (10147540) --------------------------------------------------------
int __thiscall sub_10147540(_BYTE *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  unsigned __int8 v7; // al
  unsigned __int8 v8; // bl
  int v9; // ecx
  unsigned __int8 v10; // al
  unsigned __int8 v11; // bl

  result = print_field(a2, a3, a4, "[levelID]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dataCnt]", "0x%02x", (unsigned __int8)*(this + 4));
    if ( !result )
    {
      v7 = *(this + 4);
      if ( v7 > 0xAu )
        return -7;
      result = sub_1024A3B0(a2, a3, v6, "[dataType]", v7);
      if ( !result )
      {
        v8 = 0;
        if ( *(this + 4) )
        {
          while ( 1 )
          {
            result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v8 + 5));
            if ( result )
              break;
            if ( ++v8 >= *(this + 4) )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          result = TdrBuf::WriteChar(a2, a4);
          if ( !result )
          {
            v10 = *(this + 4);
            if ( v10 > 0xAu )
              return -7;
            result = sub_1024A3B0(a2, a3, v9, "[dataVal]", v10);
            if ( !result )
            {
              v11 = 0;
              if ( *(this + 4) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %u", *(_DWORD *)(this + 4 * v11 + 15));
                  if ( result )
                    break;
                  if ( ++v11 >= *(this + 4) )
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
  return result;
}
// 101475B7: variable 'v6' is possibly undefined
// 10147618: variable 'v9' is possibly undefined



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



