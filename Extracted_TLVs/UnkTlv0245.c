// ============================================================
// Name: TLV::UnkTlv0245::Read
// Address Name: SUB_1021D300
// ============================================================
//----- (1021D300) --------------------------------------------------------
int __thiscall sub_1021D300(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1021D3D0((int)this, &v9, v8);
  else
    result = sub_1021D840((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0245::Read_0xAA
// Address Name: SUB_1021D3D0
// ============================================================
//----- (1021D3D0) --------------------------------------------------------
int __thiscall sub_1021D3D0(int this, _DWORD *a2, int a3)
{
  int *v3; // ebx
  int VarUShort; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  int v8; // ebx
  _WORD *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  int *v12; // eax
  unsigned int v13; // ecx
  unsigned int v15; // [esp+14h] [ebp-14h] BYREF
  unsigned int v16; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]
  unsigned int v19; // [esp+24h] [ebp-4h]

  v3 = (int *)this;
  VarUShort = 0;
  *(_DWORD *)(this + 55150) = 0;
  v16 = 0;
  v5 = a2[1] + a3;
  v19 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_66;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*((_BYTE *)v3 + 55150) & 1) == 0 )
          *(int *)((char *)v3 + 55150) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, v3);
        goto LABEL_64;
      case 3u:
        if ( (*(int *)((char *)v3 + 55150) & 2) == 0 )
          *(int *)((char *)v3 + 55150) |= 2u;
        VarInt = TdrBuf::ReadVarUInt(a2, v3 + 1);
        goto LABEL_64;
      case 4u:
        if ( (*(int *)((char *)v3 + 55150) & 4) == 0 )
          *(int *)((char *)v3 + 55150) |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 2);
        goto LABEL_64;
      case 5u:
        if ( (*(int *)((char *)v3 + 55150) & 8) == 0 )
          *(int *)((char *)v3 + 55150) |= 8u;
        VarInt = TdrBuf::ReadVarInt(a2, v3 + 3);
        goto LABEL_64;
      case 6u:
        if ( (*(int *)((char *)v3 + 55150) & 0x10) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x10u;
        v15 = 0;
        VarUShort = TdrBuf::ReadInt32(a2, &v15);
        if ( VarUShort )
          return VarUShort;
        if ( !v15 )
          goto LABEL_65;
        VarInt = sub_102175D0((int)(v3 + 4), a2, v15);
        goto LABEL_64;
      case 7u:
        if ( (*(int *)((char *)v3 + 55150) & 0x20) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x20u;
        v15 = 0;
        VarUShort = TdrBuf::ReadInt32(a2, &v15);
        if ( VarUShort )
          return VarUShort;
        if ( !v15 )
          goto LABEL_65;
        VarInt = sub_10219D20((int)(v3 + 108), a2, v15);
        goto LABEL_64;
      case 8u:
        if ( (*(int *)((char *)v3 + 55150) & 0x40) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x40u;
        v15 = 0;
        VarUShort = TdrBuf::ReadInt32(a2, &v15);
        if ( VarUShort )
          return VarUShort;
        if ( !v15 )
          goto LABEL_65;
        VarInt = sub_1021B9B0((int)v3 + 5486, a2, v15);
        goto LABEL_64;
      case 9u:
        if ( (*(int *)((char *)v3 + 55150) & 0x80) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x80u;
        v15 = 0;
        VarUShort = TdrBuf::ReadInt32(a2, &v15);
        if ( VarUShort )
          return VarUShort;
        if ( !v15 )
          goto LABEL_65;
        VarInt = sub_1021C5A0((int *)((char *)v3 + 37094), a2, v15);
LABEL_64:
        VarUShort = VarInt;
        if ( !VarInt )
          goto LABEL_65;
        return VarUShort;
      case 0xAu:
        if ( (*(int *)((char *)v3 + 55150) & 0x100) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x100u;
        VarInt = TdrBuf::ReadVarUInt(a2, (int *)((char *)v3 + 37142));
        goto LABEL_64;
      case 0xBu:
        if ( (*(int *)((char *)v3 + 55150) & 0x200) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)((char *)v3 + 37146));
        goto LABEL_64;
      case 0xCu:
        if ( (*(int *)((char *)v3 + 55150) & 0x400) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x400u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v18 = a2[1];
        v9 = (_WORD *)(this + 37150);
        v17 = this + 37150;
        do
        {
          VarUShort = TdrBuf::ReadVarUShort(a2, v9);
          if ( VarUShort )
            return VarUShort;
          v10 = a2[1];
          if ( v10 > v18 + v15 )
            return -34;
          if ( v10 == v18 + v15 )
            goto LABEL_52;
          ++v8;
          v9 = (_WORD *)(v17 + 2);
          v17 += 2;
        }
        while ( v8 < 3000 );
        v3 = (int *)this;
        goto LABEL_65;
      case 0xDu:
        if ( (*(int *)((char *)v3 + 55150) & 0x800) == 0 )
          *(int *)((char *)v3 + 55150) |= 0x800u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v18 = a2[1];
        v12 = (int *)(this + 43150);
        v17 = this + 43150;
        do
        {
          VarUShort = TdrBuf::ReadVarInt(a2, v12);
          if ( VarUShort )
            return VarUShort;
          v13 = a2[1];
          if ( v13 > v18 + v15 )
            return -34;
          if ( v13 == v18 + v15 )
          {
LABEL_52:
            v11 = v8 + 1;
            v3 = (int *)this;
            *(_DWORD *)(this + 37146) = v11;
            goto LABEL_65;
          }
          ++v8;
          v12 = (int *)(v17 + 4);
          v17 += 4;
        }
        while ( v8 < 3000 );
        v3 = (int *)this;
LABEL_65:
        v5 = v19;
        if ( a2[1] < v19 )
          continue;
LABEL_66:
        if ( a2[1] > v5 )
          return -34;
        return VarUShort;
      default:
        VarInt = TdrBuf::SkipField(a2, v16 & 0xF);
        goto LABEL_64;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0245::Read_0x99
// Address Name: SUB_1021D840
// ============================================================
//----- (1021D840) --------------------------------------------------------
int __thiscall sub_1021D840(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int Int16; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  _BYTE *v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  _BYTE *v12; // eax
  unsigned int v13; // ecx
  int v15; // [esp+14h] [ebp-14h] BYREF
  unsigned int v16; // [esp+18h] [ebp-10h] BYREF
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+20h] [ebp-8h]
  unsigned int v19; // [esp+24h] [ebp-4h]

  v3 = this;
  Int16 = 0;
  *(_DWORD *)(this + 55150) = 0;
  v16 = 0;
  v5 = a2[1] + a3;
  v19 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_66;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(v3 + 55150) & 1) == 0 )
          *(_DWORD *)(v3 + 55150) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)v3);
        goto LABEL_64;
      case 3u:
        if ( (*(_DWORD *)(v3 + 55150) & 2) == 0 )
          *(_DWORD *)(v3 + 55150) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 4));
        goto LABEL_64;
      case 4u:
        if ( (*(_DWORD *)(v3 + 55150) & 4) == 0 )
          *(_DWORD *)(v3 + 55150) |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 8));
        goto LABEL_64;
      case 5u:
        if ( (*(_DWORD *)(v3 + 55150) & 8) == 0 )
          *(_DWORD *)(v3 + 55150) |= 8u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 12));
        goto LABEL_64;
      case 6u:
        if ( (*(_DWORD *)(v3 + 55150) & 0x10) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x10u;
        v15 = 0;
        Int16 = TdrBuf::ReadInt32(a2, &v15);
        if ( Int16 )
          return Int16;
        if ( !v15 )
          goto LABEL_65;
        Int32 = sub_10217820(v3 + 16, a2, v15);
        goto LABEL_64;
      case 7u:
        if ( (*(_DWORD *)(v3 + 55150) & 0x20) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x20u;
        v15 = 0;
        Int16 = TdrBuf::ReadInt32(a2, &v15);
        if ( Int16 )
          return Int16;
        if ( !v15 )
          goto LABEL_65;
        Int32 = sub_1021A010(a2, v15);
        goto LABEL_64;
      case 8u:
        if ( (*(_DWORD *)(v3 + 55150) & 0x40) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x40u;
        v15 = 0;
        Int16 = TdrBuf::ReadInt32(a2, &v15);
        if ( Int16 )
          return Int16;
        if ( !v15 )
          goto LABEL_65;
        Int32 = sub_1021BC10(a2, v15);
        goto LABEL_64;
      case 9u:
        if ( (*(_DWORD *)(v3 + 55150) & 0x80) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x80u;
        v15 = 0;
        Int16 = TdrBuf::ReadInt32(a2, &v15);
        if ( Int16 )
          return Int16;
        if ( !v15 )
          goto LABEL_65;
        Int32 = sub_1021C6D0(a2, v15);
LABEL_64:
        Int16 = Int32;
        if ( !Int32 )
          goto LABEL_65;
        return Int16;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 55150) & 0x100) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x100u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 37142));
        goto LABEL_64;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 55150) & 0x200) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x200u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 37146));
        goto LABEL_64;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 55150) & 0x400) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x400u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v18 = a2[1];
        v9 = (_BYTE *)(this + 37150);
        v17 = this + 37150;
        do
        {
          Int16 = TdrBuf::ReadInt16(a2, v9);
          if ( Int16 )
            return Int16;
          v10 = a2[1];
          if ( v10 > v18 + v15 )
            return -34;
          if ( v10 == v18 + v15 )
            goto LABEL_52;
          ++v8;
          v9 = (_BYTE *)(v17 + 2);
          v17 += 2;
        }
        while ( v8 < 3000 );
        v3 = this;
        goto LABEL_65;
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 55150) & 0x800) == 0 )
          *(_DWORD *)(v3 + 55150) |= 0x800u;
        v15 = 0;
        result = TdrBuf::ReadInt32(a2, &v15);
        if ( result )
          return result;
        if ( !v15 )
          return -37;
        v8 = 0;
        v18 = a2[1];
        v12 = (_BYTE *)(this + 43150);
        v17 = this + 43150;
        do
        {
          Int16 = TdrBuf::ReadInt32(a2, v12);
          if ( Int16 )
            return Int16;
          v13 = a2[1];
          if ( v13 > v18 + v15 )
            return -34;
          if ( v13 == v18 + v15 )
          {
LABEL_52:
            v11 = v8 + 1;
            v3 = this;
            *(_DWORD *)(this + 37146) = v11;
            goto LABEL_65;
          }
          ++v8;
          v12 = (_BYTE *)(v17 + 4);
          v17 += 4;
        }
        while ( v8 < 3000 );
        v3 = this;
LABEL_65:
        v5 = v19;
        if ( a2[1] < v19 )
          continue;
LABEL_66:
        if ( a2[1] > v5 )
          return -34;
        return Int16;
      default:
        Int32 = TdrBuf::SkipField(a2, v16 & 0xF);
        goto LABEL_64;
    }
  }
}
// 1021A010: using guessed type _DWORD __stdcall sub_1021A010(_DWORD, _DWORD);
// 1021BC10: using guessed type _DWORD __stdcall sub_1021BC10(_DWORD, _DWORD);
// 1021C6D0: using guessed type _DWORD __stdcall sub_1021C6D0(_DWORD, _DWORD);



// ============================================================
// Name: TLV::UnkTlv0245::DoDebugFormat
// Address Name: SUB_1021DCD0
// ============================================================
//----- (1021DCD0) --------------------------------------------------------
int __thiscall sub_1021DCD0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1021DD80(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0245::DebugFormat
// Address Name: SUB_1021DD80
// ============================================================
//----- (1021DD80) --------------------------------------------------------
int __thiscall sub_1021DD80(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 *v8; // ecx
  int *v9; // ecx
  unsigned __int16 *v10; // ecx
  int *v11; // ecx
  int v12; // ecx
  int v13; // eax
  unsigned __int16 *v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  _DWORD *v18; // eax
  int v19; // [esp+14h] [ebp+8h]
  int v20; // [esp+18h] [ebp+Ch]
  int i; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[openFlag]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[resetTime]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[recordCardLevelUpTimes]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[starScore]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[levelInfo]");
          if ( !result )
          {
            v8 = (unsigned __int8 *)(this + 4);
            result = a3 >= 0 ? sub_10217B40(v8, a2, a3 + 1, a4) : sub_10217B40(v8, a2, a3, a4);
            if ( !result )
            {
              result = print_structure((int)a2, a3, a4, (int)"[cardInfo]");
              if ( !result )
              {
                v9 = this + 108;
                result = a3 >= 0 ? sub_1021A3D0(v9, a2, a3 + 1, a4) : sub_1021A3D0(v9, a2, a3, a4);
                if ( !result )
                {
                  result = print_structure((int)a2, a3, a4, (int)"[statInfo]");
                  if ( !result )
                  {
                    v10 = (unsigned __int16 *)this + 2743;
                    result = a3 >= 0 ? sub_1021BF40(v10, a2, a3 + 1, a4) : sub_1021BF40(v10, a2, a3, a4);
                    if ( !result )
                    {
                      result = print_structure((int)a2, a3, a4, (int)"[trackCards]");
                      if ( !result )
                      {
                        v11 = (_DWORD *)((char *)this + 37094);
                        result = a3 >= 0 ? sub_1021C8D0(v11, a2, a3 + 1, a4) : sub_1021C8D0(v11, a2, a3, a4);
                        if ( !result )
                        {
                          result = print_field(
                                     a2,
                                     a3,
                                     a4,
                                     "[weeklyRefreshTime]",
                                     "%u",
                                     *(_DWORD *)((char *)this + 37142));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[newStatCount]", "%d", *(_DWORD *)((char *)this + 37146));
                            if ( !result )
                            {
                              v13 = *(_DWORD *)((char *)this + 37146);
                              if ( v13 < 0 )
                                return -6;
                              if ( v13 > 3000 )
                                return -7;
                              result = sub_1024A3B0(a2, a3, v12, "[newStatIds]", v13);
                              if ( !result )
                              {
                                v20 = 0;
                                if ( *(int *)((char *)this + 37146) <= 0 )
                                {
LABEL_36:
                                  result = TdrBuf::WriteChar(a2, a4);
                                  if ( !result )
                                  {
                                    v16 = *(_DWORD *)((char *)this + 37146);
                                    if ( v16 < 0 )
                                      return -6;
                                    if ( v16 > 3000 )
                                      return -7;
                                    result = sub_1024A3B0(a2, a3, v15, "[newStatVals]", v16);
                                    if ( !result )
                                    {
                                      v17 = 0;
                                      if ( *(int *)((char *)this + 37146) <= 0 )
                                      {
                                        return TdrBuf::WriteChar(a2, a4);
                                      }
                                      else
                                      {
                                        v18 = (_DWORD *)((char *)this + 43150);
                                        for ( i = (int)this + 43150; ; i += 4 )
                                        {
                                          result = Printf(a2, " %d", *v18);
                                          if ( result )
                                            break;
                                          ++v17;
                                          v18 = (_DWORD *)(i + 4);
                                          if ( v17 >= *(_DWORD *)((char *)this + 37146) )
                                            return TdrBuf::WriteChar(a2, a4);
                                        }
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  v14 = (unsigned __int16 *)this + 18575;
                                  v19 = (int)this + 37150;
                                  while ( 1 )
                                  {
                                    result = Printf(a2, " %d", *v14);
                                    if ( result )
                                      break;
                                    v14 = (unsigned __int16 *)(v19 + 2);
                                    ++v20;
                                    v19 += 2;
                                    if ( v20 >= *(_DWORD *)((char *)this + 37146) )
                                      goto LABEL_36;
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
// 1021DF8E: variable 'v12' is possibly undefined
// 1021E018: variable 'v15' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10219D20
// ============================================================
//----- (10219D20) --------------------------------------------------------
int __thiscall sub_10219D20(int this, _DWORD *a2, unsigned int a3)
{
  unsigned int v3; // eax
  int VarUInt; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  _DWORD *v10; // ebx
  int v11; // edi
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  int v14; // edi
  unsigned int v15; // edx
  _DWORD *v16; // ebx
  unsigned __int16 v17; // di
  unsigned int v18; // edx
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  VarUInt = 0;
  v6 = a2;
  *(_DWORD *)(this + 5050) = 0;
  v20 = this;
  v7 = v6[1] + v3;
  v19 = 0;
  a3 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_49;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5050) & 1) == 0 )
          *(_DWORD *)(this + 5050) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)this);
        goto LABEL_47;
      case 2u:
        if ( (*(_DWORD *)(this + 5050) & 2) == 0 )
          *(_DWORD *)(this + 5050) |= 2u;
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
          VarUInt = sub_10115A30(v6, (_BYTE *)(v11 + v20 + 4));
          if ( VarUInt )
            return VarUInt;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)v20 = v11 + 1;
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 5050) & 4) == 0 )
          *(_DWORD *)(this + 5050) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)(this + 2504));
        goto LABEL_47;
      case 4u:
        if ( (*(_DWORD *)(this + 5050) & 8) == 0 )
          *(_DWORD *)(this + 5050) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v14 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = sub_10115A30(v6, (_BYTE *)(v14 + v20 + 2508));
          if ( VarUInt )
            return VarUInt;
          v15 = v6[1];
          if ( (_DWORD *)v15 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
            break;
          if ( ++v14 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)(v20 + 2504) = v14 + 1;
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(this + 5050) & 0x10) == 0 )
          *(_DWORD *)(this + 5050) |= 0x10u;
        VarInt = TdrBuf::ReadVarUShort(v6, (_WORD *)(this + 5008));
        goto LABEL_47;
      case 6u:
        if ( (*(_DWORD *)(this + 5050) & 0x20) == 0 )
          *(_DWORD *)(this + 5050) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v16 = a2;
        if ( !a2 )
          return -37;
        v17 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          VarUInt = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v20 + 4 * v17 + 5010));
          if ( VarUInt )
            return VarUInt;
          v18 = v6[1];
          if ( (_DWORD *)v18 > (_DWORD *)((char *)a2 + (int)v16) )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + (_DWORD)v16) )
            break;
          if ( ++v17 >= 0xAu )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_WORD *)(v20 + 5008) = v17 + 1;
LABEL_48:
        v7 = a3;
        if ( v6[1] < a3 )
          continue;
LABEL_49:
        if ( v6[1] > v7 )
          return -34;
        return VarUInt;
      default:
        VarInt = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_47:
        VarUInt = VarInt;
        if ( !VarInt )
          goto LABEL_48;
        return VarUInt;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102175D0
// ============================================================
//----- (102175D0) --------------------------------------------------------
int __thiscall sub_102175D0(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned __int8 v8; // bl
  unsigned int v9; // edx
  unsigned __int8 v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v15 = 0;
  v6 = a3;
  *(_DWORD *)(this + 412) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v3, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 412) & 1) == 0 )
          *(_DWORD *)(this + 412) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_37;
      case 3u:
        if ( (*(_DWORD *)(this + 412) & 2) == 0 )
          *(_DWORD *)(this + 412) |= 2u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 1));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 412) & 4) == 0 )
          *(_DWORD *)(this + 412) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_102162D0((char *)(23 * v8 + this + 2), v3, a3);
            if ( result )
              return result;
          }
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xAu )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_BYTE *)(this + 1) = v8 + 1;
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(this + 412) & 8) == 0 )
          *(_DWORD *)(this + 412) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216BA0((char *)(this + 232 + 8 * v10 + v10), v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0x14u )
            goto LABEL_38;
        }
        *(_BYTE *)this = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_39:
        if ( v3[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021B9B0
// ============================================================
//----- (1021B9B0) --------------------------------------------------------
int __thiscall sub_1021B9B0(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 31604) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 31604) & 1) == 0 )
          *(_DWORD *)(this + 31604) |= 1u;
        result = TdrBuf::ReadVarUShort(v6, (_WORD *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 31604) & 2) == 0 )
          *(_DWORD *)(this + 31604) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021B000(this + 2 * (5 * v8 + 1), v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xC8u )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 31604) & 4) == 0 )
          *(_DWORD *)(this + 31604) |= 4u;
        result = TdrBuf::ReadVarUShort(v6, (_WORD *)(this + 2002));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 31604) & 8) == 0 )
          *(_DWORD *)(this + 31604) |= 8u;
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
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021A950(this + 2004 + 8 * v10, v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0xE74u )
            goto LABEL_38;
        }
        *(_WORD *)(this + 2002) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021C5A0
// ============================================================
//----- (1021C5A0) --------------------------------------------------------
int __thiscall sub_1021C5A0(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int VarUInt; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // esi
  _DWORD *v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  int *v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  VarUInt = 0;
  v6 = a2;
  v14 = this;
  *(this + 11) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_22:
    if ( v6[1] > v7 )
      return -34;
    return VarUInt;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 11) & 1) == 0 )
          *(this + 11) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 11) & 2) == 0 )
            *(this + 11) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          a3 = v6[1];
          v11 = this + 1;
          while ( 1 )
          {
            VarUInt = TdrBuf::ReadVarUInt(v6, v11);
            if ( VarUInt )
              return VarUInt;
            v12 = v6[1];
            if ( v12 > (unsigned int)a2 + a3 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            {
              this = v14;
              *v14 = v10 + 1;
              goto LABEL_21;
            }
            ++v10;
            ++v11;
            if ( v10 >= 10 )
            {
              this = v14;
              goto LABEL_21;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
      }
      VarUInt = VarInt;
      if ( VarInt )
        return VarUInt;
LABEL_21:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_22;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10217820
// ============================================================
//----- (10217820) --------------------------------------------------------
int __thiscall sub_10217820(int this, _DWORD *a2, int a3)
{
  _DWORD *v3; // esi
  int result; // eax
  int v6; // ecx
  unsigned int v7; // ecx
  char v8; // bl
  unsigned int v9; // edx
  char v10; // bl
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a2;
  result = 0;
  v15 = 0;
  v6 = a3;
  *(_DWORD *)(this + 412) = 0;
  v7 = v3[1] + v6;
  v12 = v7;
  if ( v3[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(&v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 412) & 1) == 0 )
          *(_DWORD *)(this + 412) |= 1u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)this);
        goto LABEL_37;
      case 3u:
        if ( (*(_DWORD *)(this + 412) & 2) == 0 )
          *(_DWORD *)(this + 412) |= 2u;
        result = TdrBuf::ReadByte_2(v3, (_BYTE *)(this + 1));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 412) & 4) == 0 )
          *(_DWORD *)(this + 412) |= 4u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v3[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216470(v3, a3);
            if ( result )
              return result;
          }
          v9 = v3[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( (unsigned __int8)++v8 >= 0xAu )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_BYTE *)(this + 1) = v8 + 1;
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(this + 412) & 8) == 0 )
          *(_DWORD *)(this + 412) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v3, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v14 = v3[1];
        while ( 1 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v3, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_10216C90(v3, a3);
            if ( result )
              return result;
          }
          v11 = v3[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( (unsigned __int8)++v10 >= 0x14u )
            goto LABEL_38;
        }
        *(_BYTE *)this = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v3[1] < v12 )
          continue;
LABEL_39:
        if ( v3[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v3, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}
// 1010CCB0: using guessed type _DWORD __stdcall sub_1010CCB0(_DWORD);
// 1010D4F0: using guessed type int __fastcall sub_1010D4F0(_DWORD, _DWORD);
// 10216470: using guessed type _DWORD __stdcall sub_10216470(_DWORD, _DWORD);
// 10216C90: using guessed type _DWORD __stdcall sub_10216C90(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021C6D0
// ============================================================
//----- (1021C6D0) --------------------------------------------------------
int __thiscall sub_1021C6D0(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // esi
  _BYTE *v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  _DWORD *v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v14 = this;
  *(this + 11) = 0;
  v15 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_22:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v15);
      if ( result )
        break;
      if ( v15 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 11) & 1) == 0 )
          *(this + 11) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 11) & 2) == 0 )
            *(this + 11) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          a3 = v6[1];
          v11 = this + 1;
          while ( 1 )
          {
            v5 = TdrBuf::ReadInt32(v6, v11);
            if ( v5 )
              return v5;
            v12 = v6[1];
            if ( v12 > (unsigned int)a2 + a3 )
              return -34;
            if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + a3) )
            {
              this = v14;
              *v14 = v10 + 1;
              goto LABEL_21;
            }
            ++v10;
            v11 += 4;
            if ( v10 >= 10 )
            {
              this = v14;
              goto LABEL_21;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v15 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_21:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_22;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021BC10
// ============================================================
//----- (1021BC10) --------------------------------------------------------
int __thiscall sub_1021BC10(int this, _DWORD *a2, int a3)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // ecx
  unsigned __int16 v8; // di
  unsigned int v9; // edx
  unsigned __int16 v10; // di
  unsigned int v11; // edx
  unsigned int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  result = 0;
  v5 = a3;
  v6 = a2;
  *(_DWORD *)(this + 31604) = 0;
  v15 = 0;
  v7 = v6[1] + v5;
  v12 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_39;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 31604) & 1) == 0 )
          *(_DWORD *)(this + 31604) |= 1u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)this);
        goto LABEL_37;
      case 2u:
        if ( (*(_DWORD *)(this + 31604) & 2) == 0 )
          *(_DWORD *)(this + 31604) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v8 = 0;
        v13 = v6[1];
        while ( 2 )
        {
          a3 = 0;
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021B0A0((char *)(this + 2 * (5 * v8 + 1)), v6, a3);
            if ( result )
              return result;
          }
          v9 = v6[1];
          if ( v9 > (unsigned int)a2 + v13 )
            return -34;
          if ( (_DWORD *)v9 != (_DWORD *)((char *)a2 + v13) )
          {
            if ( ++v8 >= 0xC8u )
              goto LABEL_38;
            continue;
          }
          break;
        }
        *(_WORD *)this = v8 + 1;
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(this + 31604) & 4) == 0 )
          *(_DWORD *)(this + 31604) |= 4u;
        result = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 2002));
        goto LABEL_37;
      case 4u:
        if ( (*(_DWORD *)(this + 31604) & 8) == 0 )
          *(_DWORD *)(this + 31604) |= 8u;
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
          result = TdrBuf::ReadInt32(v6, &a3);
          if ( result )
            return result;
          if ( a3 )
          {
            result = sub_1021A9F0((_DWORD *)(this + 2004 + 8 * v10), v6, a3);
            if ( result )
              return result;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v14 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            break;
          if ( ++v10 >= 0xE74u )
            goto LABEL_38;
        }
        *(_WORD *)(this + 2002) = v10 + 1;
LABEL_38:
        v7 = v12;
        if ( v6[1] < v12 )
          continue;
LABEL_39:
        if ( v6[1] > v7 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(v6, v15 & 0xF);
LABEL_37:
        if ( !result )
          goto LABEL_38;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021A010
// ============================================================
//----- (1021A010) --------------------------------------------------------
int __thiscall sub_1021A010(int this, _DWORD *a2, unsigned int a3)
{
  unsigned int v3; // eax
  int v5; // ecx
  _DWORD *v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // ebx
  int v11; // edi
  unsigned int v12; // edx
  _DWORD *v13; // ebx
  int v14; // edi
  unsigned int v15; // edx
  _DWORD *v16; // ebx
  unsigned __int16 v17; // di
  unsigned int v18; // edx
  unsigned int v19; // [esp+10h] [ebp-8h] BYREF
  int v20; // [esp+14h] [ebp-4h]

  v3 = a3;
  v5 = 0;
  v6 = a2;
  *(_DWORD *)(this + 5050) = 0;
  v20 = this;
  v7 = v6[1] + v3;
  v19 = 0;
  a3 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_49;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v19);
    if ( result )
      return result;
    switch ( v19 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5050) & 1) == 0 )
          *(_DWORD *)(this + 5050) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)this);
        goto LABEL_47;
      case 2u:
        if ( (*(_DWORD *)(this + 5050) & 2) == 0 )
          *(_DWORD *)(this + 5050) |= 2u;
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
          v5 = sub_10115A30(v6, (_BYTE *)(v11 + v20 + 4));
          if ( v5 )
            return v5;
          v12 = v6[1];
          if ( (_DWORD *)v12 > (_DWORD *)((char *)a2 + (int)v10) )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + (_DWORD)v10) )
            break;
          if ( ++v11 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)v20 = v11 + 1;
        goto LABEL_48;
      case 3u:
        if ( (*(_DWORD *)(this + 5050) & 4) == 0 )
          *(_DWORD *)(this + 5050) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 2504));
        goto LABEL_47;
      case 4u:
        if ( (*(_DWORD *)(this + 5050) & 8) == 0 )
          *(_DWORD *)(this + 5050) |= 8u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v13 = a2;
        if ( !a2 )
          return -37;
        v14 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = sub_10115A30(v6, (_BYTE *)(v14 + v20 + 2508));
          if ( v5 )
            return v5;
          v15 = v6[1];
          if ( (_DWORD *)v15 > (_DWORD *)((char *)a2 + (int)v13) )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + (_DWORD)v13) )
            break;
          if ( ++v14 >= 2500 )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_DWORD *)(v20 + 2504) = v14 + 1;
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(this + 5050) & 0x10) == 0 )
          *(_DWORD *)(this + 5050) |= 0x10u;
        Int32 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 5008));
        goto LABEL_47;
      case 6u:
        if ( (*(_DWORD *)(this + 5050) & 0x20) == 0 )
          *(_DWORD *)(this + 5050) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        v16 = a2;
        if ( !a2 )
          return -37;
        v17 = 0;
        a2 = (_DWORD *)v6[1];
        while ( 1 )
        {
          v5 = TdrBuf::ReadInt32(v6, (_BYTE *)(v20 + 4 * v17 + 5010));
          if ( v5 )
            return v5;
          v18 = v6[1];
          if ( (_DWORD *)v18 > (_DWORD *)((char *)a2 + (int)v16) )
            return -34;
          if ( (_DWORD *)v18 == (_DWORD *)((char *)a2 + (_DWORD)v16) )
            break;
          if ( ++v17 >= 0xAu )
          {
            this = v20;
            goto LABEL_48;
          }
        }
        this = v20;
        *(_WORD *)(v20 + 5008) = v17 + 1;
LABEL_48:
        v7 = a3;
        if ( v6[1] < a3 )
          continue;
LABEL_49:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v19 & 0xF);
LABEL_47:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_48;
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
// Address Name: SUB_1021BF40
// ============================================================
//----- (1021BF40) --------------------------------------------------------
int __thiscall sub_1021BF40(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v8; // eax
  unsigned __int16 v9; // cx
  int v10; // eax
  int v11; // [esp+14h] [ebp+8h]
  int v12; // [esp+14h] [ebp+8h]
  int v13; // [esp+18h] [ebp+Ch]
  int v14; // [esp+18h] [ebp+Ch]

  result = print_field(a2, a3, a4, "[statNumInt]", "%d", *this);
  if ( !result )
  {
    if ( *this > 0xC8u )
      return -7;
    LOWORD(v8) = 0;
    v11 = 0;
    if ( *this )
    {
      while ( 1 )
      {
        v13 = (unsigned __int16)v8;
        if ( !"[statListInt]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[statListInt]", v13, a4);
        if ( result )
          break;
        result = a3 >= 0
               ? sub_1021B2A0(this + 5 * v13 + 1, a2, a3 + 1, a4)
               : sub_1021B2A0(this + 5 * v13 + 1, a2, a3, a4);
        if ( result )
          break;
        v8 = v11 + 1;
        v11 = v8;
        if ( (unsigned __int16)v8 >= *this )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      result = print_field(a2, a3, a4, "[statNum]", "%d", *(this + 1001));
      if ( !result )
      {
        v9 = *(this + 1001);
        if ( v9 > 0xE74u )
          return -7;
        LOWORD(v10) = 0;
        v12 = 0;
        if ( v9 )
        {
          while ( 1 )
          {
            v14 = (unsigned __int16)v10;
            if ( !"[statList]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[statList]", v14, a4);
            if ( result )
              break;
            result = a3 >= 0
                   ? sub_1021AC30(this + 4 * v14 + 1002, a2, a3 + 1, a4)
                   : sub_1021AC30(this + 4 * v14 + 1002, a2, a3, a4);
            if ( result )
              break;
            v10 = v12 + 1;
            v12 = v10;
            if ( (unsigned __int16)v10 >= *(this + 1001) )
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
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021A3D0
// ============================================================
//----- (1021A3D0) --------------------------------------------------------
int __thiscall sub_1021A3D0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  unsigned __int16 v12; // di

  result = print_field(a2, a3, a4, "[unlockBitCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this < 0 )
      return -6;
    if ( v7 > 2500 )
      return -7;
    result = sub_1024A3B0(a2, a3, v6, "[unlockBit]", v7);
    if ( !result )
    {
      v8 = 0;
      if ( *this <= 0 )
      {
LABEL_10:
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *(this + 626));
        if ( result )
          return result;
        v10 = *(this + 626);
        if ( v10 < 0 )
          return -6;
        if ( v10 <= 2500 )
        {
          result = sub_1024A3B0(a2, a3, v9, "[completeBit]", v10);
          if ( result )
            return result;
          v11 = 0;
          if ( *(this + 626) > 0 )
          {
            do
            {
              result = Printf(a2, " 0x%02x", *((char *)this + v11 + 2508));
              if ( result )
                return result;
            }
            while ( ++v11 < *(this + 626) );
          }
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          result = print_field(a2, a3, a4, "[newFinishCardNum]", "%d", *((unsigned __int16 *)this + 2504));
          if ( result )
            return result;
          if ( *((_WORD *)this + 2504) <= 0xAu )
          {
            result = sub_1024A3B0(a2, a3, 10, "[newFinishCardList]", *((unsigned __int16 *)this + 2504));
            if ( !result )
            {
              v12 = 0;
              if ( *((_WORD *)this + 2504) )
              {
                while ( 1 )
                {
                  result = Printf(a2, " %u", *(int *)((char *)this + 4 * v12 + 5010));
                  if ( result )
                    break;
                  if ( ++v12 >= *((_WORD *)this + 2504) )
                    return TdrBuf::WriteChar(a2, a4);
                }
              }
              else
              {
                return TdrBuf::WriteChar(a2, a4);
              }
            }
            return result;
          }
        }
        return -7;
      }
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
  return result;
}
// 1021A431: variable 'v6' is possibly undefined
// 1021A4D0: variable 'v9' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021C8D0
// ============================================================
//----- (1021C8D0) --------------------------------------------------------
int __thiscall sub_1021C8D0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 10 )
      {
        result = sub_1024A3B0(a2, a3, v6, "[cards]", v7);
        if ( !result )
        {
          v8 = 0;
          if ( *this <= 0 )
          {
            return TdrBuf::WriteChar(a2, a4);
          }
          else
          {
            for ( i = this + 1; ; ++i )
            {
              result = Printf(a2, " %u", *i);
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
// 1021C92B: variable 'v6' is possibly undefined



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
// Address Name: SUB_10217B40
// ============================================================
//----- (10217B40) --------------------------------------------------------
int __thiscall sub_10217B40(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl
  bool v9; // zf
  void (__cdecl *v10)(const wchar_t *, const wchar_t *, unsigned int); // edx
  unsigned __int8 v11; // al
  unsigned __int8 v12; // cl
  int v13; // [esp-4h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp+Ch]
  int v16; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *v17; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 v18; // [esp+23h] [ebp+13h]
  unsigned __int8 v19; // [esp+23h] [ebp+13h]

  result = print_field(a2, a3, a4, "[starNum]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[branchNum]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v6 = this;
      v7 = *(this + 1);
      if ( v7 > 0xAu )
        return -7;
      v8 = 0;
      v9 = v7 == 0;
      v10 = _wassert;
      v18 = 0;
      if ( v9 )
      {
LABEL_15:
        v11 = *v6;
        if ( v11 > 0x14u )
          return -7;
        v12 = 0;
        v19 = 0;
        if ( v11 )
        {
          while ( 1 )
          {
            v16 = v12;
            if ( !"[starList]" )
              v10(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[starList]", v16, a4);
            if ( result )
              break;
            v17 = this + 8 * v16 + v16 + 232;
            v13 = *v17;
            if ( a3 >= 0 )
            {
              result = print_field(a2, a3 + 1, a4, "[quality]", "0x%02x", v13);
              if ( result )
                return result;
              result = print_field(a2, a3 + 1, a4, "[finishTime]", "%u", *(_DWORD *)(v17 + 1));
            }
            else
            {
              result = print_field(a2, a3, a4, "[quality]", "0x%02x", v13);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[finishTime]", "%u", *(_DWORD *)(v17 + 1));
            }
            if ( result )
              break;
            v12 = v19 + 1;
            v19 = v12;
            if ( v12 >= *this )
              return 0;
            v10 = _wassert;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        while ( 1 )
        {
          v15 = v8;
          if ( !"[branchList]" )
            v10(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[branchList]", v15, a4);
          if ( result )
            break;
          result = a3 >= 0
                 ? sub_102166E0(this + 23 * v15 + 2, a2, a3 + 1, a4)
                 : sub_102166E0(this + 23 * v15 + 2, a2, a3, a4);
          if ( result )
            break;
          v6 = this;
          v8 = v18 + 1;
          v10 = _wassert;
          v18 = v8;
          if ( v8 >= *(this + 1) )
            goto LABEL_15;
        }
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
// Address Name: SUB_102162D0
// ============================================================
//----- (102162D0) --------------------------------------------------------
int __thiscall sub_102162D0(char *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int v8; // ecx
  int VarUShort; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 19) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(this + 19) & 1) == 0 )
              *(_DWORD *)(this + 19) |= 1u;
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0x290u);
            v8 = a2[1];
            if ( a2[2] != v8 )
            {
              *this = *(_BYTE *)(v8 + *a2);
              ++a2[1];
              v5 = 0;
              goto LABEL_27;
            }
            return -2;
          case 2u:
            if ( (*(_DWORD *)(this + 19) & 2) == 0 )
              *(_DWORD *)(this + 19) |= 2u;
            VarUShort = TdrBuf::ReadVarUShort(a2, this + 1);
            goto LABEL_26;
          case 3u:
            if ( (*(_DWORD *)(this + 19) & 4) == 0 )
              *(_DWORD *)(this + 19) |= 4u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 3);
            goto LABEL_26;
          case 4u:
            if ( (*(_DWORD *)(this + 19) & 8) == 0 )
              *(_DWORD *)(this + 19) |= 8u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 7);
            goto LABEL_26;
          case 5u:
            if ( (*(_DWORD *)(this + 19) & 0x10) == 0 )
              *(_DWORD *)(this + 19) |= 0x10u;
            VarUShort = TdrBuf::ReadVarInt(a2, (int *)(this + 11));
            goto LABEL_26;
          case 6u:
            if ( (*(_DWORD *)(this + 19) & 0x20) == 0 )
              *(_DWORD *)(this + 19) |= 0x20u;
            VarUShort = TdrBuf::ReadVarUInt(a2, this + 15);
            goto LABEL_26;
          default:
            VarUShort = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_26:
            v5 = VarUShort;
            if ( VarUShort )
              return v5;
LABEL_27:
            v6 = v11;
            if ( a2[1] >= v11 )
              goto LABEL_28;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10216BA0
// ============================================================
//----- (10216BA0) --------------------------------------------------------
int __thiscall sub_10216BA0(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1021B000
// ============================================================
//----- (1021B000) --------------------------------------------------------
int __thiscall sub_1021B000(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUShort; // eax
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
        if ( (*(_BYTE *)(this + 6) & 1) == 0 )
          *(_DWORD *)(this + 6) |= 1u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 6) & 2) == 0 )
          *(_DWORD *)(this + 6) |= 2u;
        VarUShort = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 2));
      }
      else
      {
        VarUShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUShort;
      if ( VarUShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021A950
// ============================================================
//----- (1021A950) --------------------------------------------------------
int __thiscall sub_1021A950(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarUShort; // eax
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
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)this);
      }
      else if ( v8 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 4) & 2) == 0 )
          *(_DWORD *)(this + 4) |= 2u;
        VarUShort = TdrBuf::ReadVarUShort(a2, (_WORD *)(this + 2));
      }
      else
      {
        VarUShort = TdrBuf::SkipField(a2, v8 & 0xF);
      }
      v4 = VarUShort;
      if ( VarUShort )
        return v4;
      if ( a2[1] >= v5 )
        goto LABEL_14;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10216C90
// ============================================================
//----- (10216C90) --------------------------------------------------------
int __thiscall sub_10216C90(char *this, _DWORD *a2, int a3)
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
// Address Name: SUB_10216470
// ============================================================
//----- (10216470) --------------------------------------------------------
int __thiscall sub_10216470(char *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int v8; // ecx
  int Int16; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 19) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_28:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(this + 19) & 1) == 0 )
              *(_DWORD *)(this + 19) |= 1u;
            if ( a2[1] > a2[2] )
              _wassert(
                L"position <= length",
                L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                0x290u);
            v8 = a2[1];
            if ( a2[2] != v8 )
            {
              *this = *(_BYTE *)(v8 + *a2);
              ++a2[1];
              v5 = 0;
              goto LABEL_27;
            }
            return -2;
          case 2u:
            if ( (*(_DWORD *)(this + 19) & 2) == 0 )
              *(_DWORD *)(this + 19) |= 2u;
            Int16 = TdrBuf::ReadInt16(a2, this + 1);
            goto LABEL_26;
          case 3u:
            if ( (*(_DWORD *)(this + 19) & 4) == 0 )
              *(_DWORD *)(this + 19) |= 4u;
            Int16 = TdrBuf::ReadInt32(a2, this + 3);
            goto LABEL_26;
          case 4u:
            if ( (*(_DWORD *)(this + 19) & 8) == 0 )
              *(_DWORD *)(this + 19) |= 8u;
            Int16 = TdrBuf::ReadInt32(a2, this + 7);
            goto LABEL_26;
          case 5u:
            if ( (*(_DWORD *)(this + 19) & 0x10) == 0 )
              *(_DWORD *)(this + 19) |= 0x10u;
            Int16 = TdrBuf::ReadInt32(a2, this + 11);
            goto LABEL_26;
          case 6u:
            if ( (*(_DWORD *)(this + 19) & 0x20) == 0 )
              *(_DWORD *)(this + 19) |= 0x20u;
            Int16 = TdrBuf::ReadInt32(a2, this + 15);
            goto LABEL_26;
          default:
            Int16 = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_26:
            v5 = Int16;
            if ( Int16 )
              return v5;
LABEL_27:
            v6 = v11;
            if ( a2[1] >= v11 )
              goto LABEL_28;
            continue;
        }
      }
      break;
    }
  }
  return result;
}
// 1010D4F0: using guessed type int __fastcall sub_1010D4F0(_DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1021B0A0
// ============================================================
//----- (1021B0A0) --------------------------------------------------------
int __thiscall sub_1021B0A0(char *this, _DWORD *a2, int a3)
{
  unsigned int v4; // ebx
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  unsigned int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  *(_DWORD *)(this + 6) = 0;
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
      if ( (*(this + 6) & 1) == 0 )
        *(_DWORD *)(this + 6) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v7 = a2[1];
      if ( (unsigned int)(a2[2] - v7) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v7 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v8 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 6) & 2) == 0 )
        *(_DWORD *)(this + 6) |= 2u;
      result = TdrBuf::ReadInt32(a2, this + 2);
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
// Address Name: SUB_1021A9F0
// ============================================================
//----- (1021A9F0) --------------------------------------------------------
int __thiscall sub_1021A9F0(_DWORD *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1021B2A0
// ============================================================
//----- (1021B2A0) --------------------------------------------------------
int __thiscall sub_1021B2A0(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[statIdx]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[statValue]", "%u", *(_DWORD *)(this + 1));
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
// Address Name: SUB_1021AC30
// ============================================================
//----- (1021AC30) --------------------------------------------------------
int __thiscall sub_1021AC30(unsigned __int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[statIdx]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[statValue]", "%d", *(this + 1));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_102166E0
// ============================================================
//----- (102166E0) --------------------------------------------------------
int __thiscall sub_102166E0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[branchType]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[branchLevel]", "%d", *(unsigned __int16 *)(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[branchAllScore]", "%u", *(_DWORD *)(this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[branchDayScore]", "%u", *(_DWORD *)(this + 7));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[branchRecordCardLevelUpTimes]", "%d", *(_DWORD *)(this + 11));
          if ( !result )
            return print_field(a2, a3, a4, "[branchChallengeScore]", "%u", *(_DWORD *)(this + 15));
        }
      }
    }
  }
  return result;
}



