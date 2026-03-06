// ============================================================
// Name: TLV::UnkTlv0228::Read
// Address Name: SUB_10211840
// ============================================================
//----- (10211840) --------------------------------------------------------
int __thiscall sub_10211840(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_10211910(this, &v9, v8);
  else
    result = sub_10211D10((char *)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0228::Read_0xAA
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
// Name: TLV::UnkTlv0228::Read_0x99
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
// Name: TLV::UnkTlv0228::DoDebugFormat
// Address Name: SUB_10212130
// ============================================================
//----- (10212130) --------------------------------------------------------
int __thiscall sub_10212130(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_102121E0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0228::DebugFormat
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



