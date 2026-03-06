// ============================================================
// Name: TLV::UnkTlv0294::Read_0xAA
// Address Name: SUB_10248370
// ============================================================
//----- (10248370) --------------------------------------------------------
int __thiscall sub_10248370(int *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  int *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  int v10; // ebx
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  _DWORD *v21; // [esp+10h] [ebp-Ch]
  unsigned int v22; // [esp+14h] [ebp-8h] BYREF
  int *v23; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v23 = this;
  *(this + 85019) = 0;
  v22 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_77;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (v4[85019] & 1) == 0 )
          v4[85019] |= 1u;
        VarULong = TdrBuf::ReadVarULong(v6, v4);
        goto LABEL_75;
      case 2u:
        if ( (v4[85019] & 2) == 0 )
          v4[85019] |= 2u;
        VarULong = TdrBuf::ReadVarULong(v6, v4 + 2);
        goto LABEL_75;
      case 3u:
        if ( (v4[85019] & 4) == 0 )
          v4[85019] |= 4u;
        VarULong = TdrBuf::ReadVarULong(v6, v4 + 4);
        goto LABEL_75;
      case 4u:
        if ( (v4[85019] & 8) == 0 )
          v4[85019] |= 8u;
        VarULong = TdrBuf::ReadVarULong(v6, v4 + 6);
        goto LABEL_75;
      case 5u:
        if ( (v4[85019] & 0x10) == 0 )
          v4[85019] |= 0x10u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 8);
        goto LABEL_75;
      case 6u:
        if ( (v4[85019] & 0x20) == 0 )
          v4[85019] |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 9);
        goto LABEL_75;
      case 7u:
        if ( (v4[85019] & 0x40) == 0 )
          v4[85019] |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 10);
        goto LABEL_75;
      case 8u:
        if ( (v4[85019] & 0x80) == 0 )
          v4[85019] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v23 + 11;
        a3 = v23 + 11;
        do
        {
          Byte = TdrBuf::ReadVarULong(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_35;
          ++v10;
          v11 = a3 + 2;
          a3 += 2;
        }
        while ( v10 < 20000 );
        v4 = v23;
        goto LABEL_76;
      case 9u:
        if ( (v4[85019] & 0x100) == 0 )
          v4[85019] |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v6[1];
        v14 = v23 + 40011;
        a3 = v23 + 40011;
        do
        {
          Byte = TdrBuf::ReadVarULong(v6, v14);
          if ( Byte )
            return Byte;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_35;
          ++v10;
          v14 = a3 + 2;
          a3 += 2;
        }
        while ( v10 < 20000 );
        v4 = v23;
        goto LABEL_76;
      case 0xAu:
        if ( (v4[85019] & 0x200) == 0 )
          v4[85019] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        v16 = v23 + 80011;
        v21 = v23 + 80011;
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v16 + v10);
          if ( Byte )
            return Byte;
          v17 = v6[1];
          if ( (_DWORD *)v17 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_35:
            v13 = v10 + 1;
            v4 = v23;
            v23[10] = v13;
            goto LABEL_76;
          }
          v16 = v21;
          ++v10;
        }
        while ( v10 < 20000 );
        v4 = v23;
LABEL_76:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_77:
        if ( v6[1] > v7 )
          return -34;
        return Byte;
      case 0xBu:
        if ( (v4[85019] & 0x400) == 0 )
          v4[85019] |= 0x400u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 85011);
        goto LABEL_75;
      case 0xCu:
        if ( (v4[85019] & 0x800) == 0 )
          v4[85019] |= 0x800u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 85012);
        goto LABEL_75;
      case 0xDu:
        if ( (v4[85019] & 0x1000) == 0 )
          v4[85019] |= 0x1000u;
        VarULong = TdrBuf::ReadVarULong(v6, v4 + 85013);
        goto LABEL_75;
      case 0xEu:
        if ( (v4[85019] & 0x2000) == 0 )
          v4[85019] |= 0x2000u;
        VarULong = TdrBuf::ReadVarULong(v6, v4 + 85015);
        goto LABEL_75;
      case 0xFu:
        if ( (v4[85019] & 0x4000) == 0 )
          v4[85019] |= 0x4000u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 85017);
        goto LABEL_75;
      case 0x10u:
        if ( (v4[85019] & 0x8000) == 0 )
          v4[85019] |= 0x8000u;
        VarULong = TdrBuf::ReadVarInt(v6, v4 + 85018);
        goto LABEL_75;
      default:
        VarULong = TdrBuf::SkipField(v6, v22 & 0xF);
LABEL_75:
        Byte = VarULong;
        if ( !VarULong )
          goto LABEL_76;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0294::Read_0x99
// Address Name: SUB_10248840
// ============================================================
//----- (10248840) --------------------------------------------------------
int __thiscall sub_10248840(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int Byte; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _BYTE *v14; // eax
  unsigned int v15; // ecx
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // [esp+Ch] [ebp-10h]
  int v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+10h] [ebp-Ch]
  _DWORD *v21; // [esp+10h] [ebp-Ch]
  unsigned int v22; // [esp+14h] [ebp-8h] BYREF
  _DWORD *v23; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = this;
  Byte = 0;
  v6 = a2;
  v23 = this;
  *(this + 85019) = 0;
  v22 = 0;
  v7 = (unsigned int)v3 + v6[1];
  v18 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_77;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v22);
    if ( result )
      return result;
    switch ( v22 >> 4 )
    {
      case 1u:
        if ( (v4[85019] & 1) == 0 )
          v4[85019] |= 1u;
        Int64 = TdrBuf::ReadInt64(v6, v4);
        goto LABEL_75;
      case 2u:
        if ( (v4[85019] & 2) == 0 )
          v4[85019] |= 2u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4 + 8);
        goto LABEL_75;
      case 3u:
        if ( (v4[85019] & 4) == 0 )
          v4[85019] |= 4u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4 + 16);
        goto LABEL_75;
      case 4u:
        if ( (v4[85019] & 8) == 0 )
          v4[85019] |= 8u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4 + 24);
        goto LABEL_75;
      case 5u:
        if ( (v4[85019] & 0x10) == 0 )
          v4[85019] |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 32);
        goto LABEL_75;
      case 6u:
        if ( (v4[85019] & 0x20) == 0 )
          v4[85019] |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 36);
        goto LABEL_75;
      case 7u:
        if ( (v4[85019] & 0x40) == 0 )
          v4[85019] |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 40);
        goto LABEL_75;
      case 8u:
        if ( (v4[85019] & 0x80) == 0 )
          v4[85019] |= 0x80u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v19 = v6[1];
        v11 = v23 + 11;
        a3 = v23 + 11;
        do
        {
          Byte = TdrBuf::ReadInt64(v6, v11);
          if ( Byte )
            return Byte;
          v12 = v6[1];
          if ( v12 > (unsigned int)a2 + v19 )
            return -34;
          if ( (_DWORD *)v12 == (_DWORD *)((char *)a2 + v19) )
            goto LABEL_35;
          ++v10;
          v11 = a3 + 2;
          a3 += 2;
        }
        while ( v10 < 20000 );
        v4 = v23;
        goto LABEL_76;
      case 9u:
        if ( (v4[85019] & 0x100) == 0 )
          v4[85019] |= 0x100u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v20 = v6[1];
        v14 = v23 + 40011;
        a3 = v23 + 40011;
        do
        {
          Byte = TdrBuf::ReadInt64(v6, v14);
          if ( Byte )
            return Byte;
          v15 = v6[1];
          if ( v15 > (unsigned int)a2 + v20 )
            return -34;
          if ( (_DWORD *)v15 == (_DWORD *)((char *)a2 + v20) )
            goto LABEL_35;
          ++v10;
          v14 = a3 + 2;
          a3 += 2;
        }
        while ( v10 < 20000 );
        v4 = v23;
        goto LABEL_76;
      case 0xAu:
        if ( (v4[85019] & 0x200) == 0 )
          v4[85019] |= 0x200u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        a3 = (_DWORD *)v6[1];
        v16 = v23 + 80011;
        v21 = v23 + 80011;
        do
        {
          Byte = TdrBuf::ReadByte(v6, (_BYTE *)v16 + v10);
          if ( Byte )
            return Byte;
          v17 = v6[1];
          if ( (_DWORD *)v17 > (_DWORD *)((char *)a2 + (int)a3) )
            return -34;
          if ( (_DWORD *)v17 == (_DWORD *)((char *)a2 + (_DWORD)a3) )
          {
LABEL_35:
            v13 = v10 + 1;
            v4 = v23;
            v23[10] = v13;
            goto LABEL_76;
          }
          v16 = v21;
          ++v10;
        }
        while ( v10 < 20000 );
        v4 = v23;
LABEL_76:
        v7 = v18;
        if ( v6[1] < v18 )
          continue;
LABEL_77:
        if ( v6[1] > v7 )
          return -34;
        return Byte;
      case 0xBu:
        if ( (v4[85019] & 0x400) == 0 )
          v4[85019] |= 0x400u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 340044);
        goto LABEL_75;
      case 0xCu:
        if ( (v4[85019] & 0x800) == 0 )
          v4[85019] |= 0x800u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 340048);
        goto LABEL_75;
      case 0xDu:
        if ( (v4[85019] & 0x1000) == 0 )
          v4[85019] |= 0x1000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4 + 340052);
        goto LABEL_75;
      case 0xEu:
        if ( (v4[85019] & 0x2000) == 0 )
          v4[85019] |= 0x2000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4 + 340060);
        goto LABEL_75;
      case 0xFu:
        if ( (v4[85019] & 0x4000) == 0 )
          v4[85019] |= 0x4000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 340068);
        goto LABEL_75;
      case 0x10u:
        if ( (v4[85019] & 0x8000) == 0 )
          v4[85019] |= 0x8000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 340072);
        goto LABEL_75;
      default:
        Int64 = TdrBuf::SkipField(v6, v22 & 0xF);
LABEL_75:
        Byte = Int64;
        if ( !Int64 )
          goto LABEL_76;
        return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0294::DoDebugFormat
// Address Name: SUB_10248D30
// ============================================================
//----- (10248D30) --------------------------------------------------------
int __thiscall sub_10248D30(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10248DE0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0294::DebugFormat
// Address Name: SUB_10248DE0
// ============================================================
//----- (10248DE0) --------------------------------------------------------
int __thiscall sub_10248DE0(char *this, _DWORD *a2, int a3, char a4)
{
  char v4; // bl
  int result; // eax
  int v8; // ecx
  int v9; // eax
  _QWORD *v10; // ebx
  int v11; // ecx
  int v12; // eax
  _QWORD *v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  int v17; // [esp+14h] [ebp+8h]
  int v18; // [esp+14h] [ebp+8h]

  v4 = a4;
  result = print_field(a2, a3, a4, "[redSoul]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[yellowSoul]", "%I64u", *((_QWORD *)this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[redSoulAll]", "%I64u", *((_QWORD *)this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[yellowSoulAll]", "%I64u", *((_QWORD *)this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[phase]", "%d", *((_DWORD *)this + 8));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[activity]", "%d", *((_DWORD *)this + 9));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[instCount]", "%d", *((_DWORD *)this + 10));
              if ( !result )
              {
                v9 = *((_DWORD *)this + 10);
                if ( v9 < 0 )
                  return -6;
                if ( v9 > 20000 )
                  return -7;
                result = sub_1024A3B0(a2, a3, v8, "[instUid]", v9);
                if ( !result )
                {
                  v17 = 0;
                  if ( *((int *)this + 10) <= 0 )
                  {
LABEL_18:
                    result = TdrBuf::WriteChar(a2, v4);
                    if ( result )
                      return result;
                    v12 = *((_DWORD *)this + 10);
                    if ( v12 < 0 )
                      return -6;
                    if ( v12 <= 20000 )
                    {
                      result = sub_1024A3B0(a2, a3, v11, "[instGuild]", v12);
                      if ( result )
                        return result;
                      v18 = 0;
                      if ( *((int *)this + 10) > 0 )
                      {
                        v13 = this + 160044;
                        while ( 1 )
                        {
                          result = Printf(a2, " %I64u", *v13);
                          if ( result )
                            return result;
                          ++v13;
                          if ( ++v18 >= *((_DWORD *)this + 10) )
                          {
                            v4 = a4;
                            break;
                          }
                        }
                      }
                      result = TdrBuf::WriteChar(a2, v4);
                      if ( result )
                        return result;
                      v15 = *((_DWORD *)this + 10);
                      if ( v15 < 0 )
                        return -6;
                      if ( v15 <= 20000 )
                      {
                        result = sub_1024A3B0(a2, a3, v14, "[instCamp]", v15);
                        if ( !result )
                        {
                          v16 = 0;
                          if ( *((int *)this + 10) <= 0 )
                          {
LABEL_34:
                            result = TdrBuf::WriteChar(a2, a4);
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[redCount]", "%d", *((_DWORD *)this + 85011));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[yellowCount]", "%d", *((_DWORD *)this + 85012));
                                if ( !result )
                                {
                                  result = print_field(
                                             a2,
                                             a3,
                                             a4,
                                             "[applyYellowSoulAll]",
                                             "%I64u",
                                             *(_QWORD *)(this + 340052));
                                  if ( !result )
                                  {
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[applyRedSoulAll]",
                                               "%I64u",
                                               *(_QWORD *)(this + 340060));
                                    if ( !result )
                                    {
                                      result = print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[activeRedCount]",
                                                 "%d",
                                                 *((_DWORD *)this + 85017));
                                      if ( !result )
                                        return print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[activeYellowCount]",
                                                 "%d",
                                                 *((_DWORD *)this + 85018));
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
                              result = Printf(a2, " 0x%02x", (unsigned __int8)*(this + v16 + 320044));
                              if ( result )
                                break;
                              if ( ++v16 >= *((_DWORD *)this + 10) )
                                goto LABEL_34;
                            }
                          }
                        }
                        return result;
                      }
                    }
                    return -7;
                  }
                  v10 = this + 44;
                  while ( 1 )
                  {
                    result = Printf(a2, " %I64u", *v10);
                    if ( result )
                      break;
                    ++v10;
                    if ( ++v17 >= *((_DWORD *)this + 10) )
                    {
                      v4 = a4;
                      goto LABEL_18;
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
// 10248F1B: variable 'v8' is possibly undefined
// 10248F97: variable 'v11' is possibly undefined
// 10249016: variable 'v14' is possibly undefined



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



