// ============================================================
// Name: TLV::UnkTlv0097::Read
// Address Name: SUB_1015DCB0
// ============================================================
//----- (1015DCB0) --------------------------------------------------------
int __thiscall sub_1015DCB0(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  unsigned int v6; // esi
  char v7; // bl
  _DWORD *v8; // [esp-Ch] [ebp-1Ch]
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
  v8 = (_DWORD *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_1015DD80(this, &v9, v8);
  else
    result = sub_1015E1B0(this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0097::Read_0xAA
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
// Name: TLV::UnkTlv0097::Read_0x99
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
// Name: TLV::UnkTlv0097::DoDebugFormat
// Address Name: SUB_1015E600
// ============================================================
//----- (1015E600) --------------------------------------------------------
int __thiscall sub_1015E600(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1015E6B0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0097::DebugFormat
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



