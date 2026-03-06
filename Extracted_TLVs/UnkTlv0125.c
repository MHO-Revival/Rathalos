// ============================================================
// Name: TLV::UnkTlv0125::Read_0xAA
// Address Name: SUB_10173760
// ============================================================
//----- (10173760) --------------------------------------------------------
int __thiscall sub_10173760(int *this, _DWORD *Size, _DWORD *a3)
{
  _DWORD *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // ebx
  _DWORD *v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // ebx
  _DWORD *v20; // ecx
  int v21; // eax
  char *v22; // [esp+Ch] [ebp-14h]
  int v23; // [esp+10h] [ebp-10h]
  int v24; // [esp+10h] [ebp-10h]
  int v25; // [esp+10h] [ebp-10h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v28; // [esp+18h] [ebp-8h] BYREF
  int *v29; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v29 = this;
  *(int *)((char *)this + 39146) = 0;
  v28 = 0;
  v7 = (char *)v3 + v6[1];
  v22 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_71;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 39146) & 1) == 0 )
          *(int *)((char *)v4 + 39146) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_69;
      case 2u:
        if ( (*(int *)((char *)v4 + 39146) & 2) == 0 )
          *(int *)((char *)v4 + 39146) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v23 = v6[1];
        a3 = v29 + 1;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016B8A0((int)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (_DWORD *)((char *)Size + v23) )
            return -34;
          if ( v11 == (_DWORD *)((char *)Size + v23) )
            break;
          a3 = (_DWORD *)((char *)a3 + 73);
          if ( ++v10 >= 500 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v12 = v10 + 1;
        v4 = v29;
        *v29 = v12;
        goto LABEL_70;
      case 3u:
        if ( (*(int *)((char *)v4 + 39146) & 4) == 0 )
          *(int *)((char *)v4 + 39146) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 9126);
        goto LABEL_69;
      case 4u:
        if ( (*(int *)((char *)v4 + 39146) & 8) == 0 )
          *(int *)((char *)v4 + 39146) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v13 = 0;
        v24 = v6[1];
        a3 = v29 + 9127;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016C500((int)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v14 = (_DWORD *)v6[1];
          if ( v14 > (_DWORD *)((char *)Size + v24) )
            return -34;
          if ( v14 == (_DWORD *)((char *)Size + v24) )
            break;
          a3 = (_DWORD *)((char *)a3 + 57);
          if ( ++v13 >= 20 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v15 = v13 + 1;
        v4 = v29;
        v29[9126] = v15;
        goto LABEL_70;
      case 5u:
        if ( (*(int *)((char *)v4 + 39146) & 0x10) == 0 )
          *(int *)((char *)v4 + 39146) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 9412);
        goto LABEL_69;
      case 6u:
        if ( (*(int *)((char *)v4 + 39146) & 0x20) == 0 )
          *(int *)((char *)v4 + 39146) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v16 = 0;
        v25 = v6[1];
        a3 = v29 + 9413;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016CFC0(a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v17 = (_DWORD *)v6[1];
          if ( v17 > (_DWORD *)((char *)Size + v25) )
            return -34;
          if ( v17 == (_DWORD *)((char *)Size + v25) )
            break;
          a3 += 14;
          if ( ++v16 >= 20 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v18 = v16 + 1;
        v4 = v29;
        v29[9412] = v18;
        goto LABEL_70;
      case 7u:
        if ( (*(int *)((char *)v4 + 39146) & 0x40) == 0 )
          *(int *)((char *)v4 + 39146) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v6, v4 + 9693);
        goto LABEL_69;
      case 8u:
        if ( (*(int *)((char *)v4 + 39146) & 0x80) == 0 )
          *(int *)((char *)v4 + 39146) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v19 = 0;
        v26 = v6[1];
        a3 = v29 + 9694;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016D8D0((char *)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v20 = (_DWORD *)v6[1];
          if ( v20 > (_DWORD *)((char *)Size + v26) )
            return -34;
          if ( v20 == (_DWORD *)((char *)Size + v26) )
            break;
          a3 = (_DWORD *)((char *)a3 + 37);
          if ( ++v19 >= 10 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v21 = v19 + 1;
        v4 = v29;
        v29[9693] = v21;
LABEL_70:
        v7 = v22;
        if ( v6[1] < (unsigned int)v22 )
          continue;
LABEL_71:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_69:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_70;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0125::Read_0x99
// Address Name: SUB_10173BC0
// ============================================================
//----- (10173BC0) --------------------------------------------------------
int __thiscall sub_10173BC0(_DWORD *this, _DWORD *Size, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // ebx
  _DWORD *v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // ecx
  int v18; // eax
  int v19; // ebx
  _DWORD *v20; // ecx
  int v21; // eax
  char *v22; // [esp+Ch] [ebp-14h]
  int v23; // [esp+10h] [ebp-10h]
  int v24; // [esp+10h] [ebp-10h]
  int v25; // [esp+10h] [ebp-10h]
  int v26; // [esp+10h] [ebp-10h]
  int v27; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v28; // [esp+18h] [ebp-8h] BYREF
  char *v29; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v29 = (char *)this;
  *(_DWORD *)((char *)this + 39146) = 0;
  v28 = 0;
  v7 = &v3[v6[1]];
  v22 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_71;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v28);
    if ( result )
      return result;
    switch ( v28 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 39146) & 1) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_69;
      case 2u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 2) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v23 = v6[1];
        a3 = v29 + 4;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016BAE0((int)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v11 = (_DWORD *)v6[1];
          if ( v11 > (_DWORD *)((char *)Size + v23) )
            return -34;
          if ( v11 == (_DWORD *)((char *)Size + v23) )
            break;
          a3 += 73;
          if ( ++v10 >= 500 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v12 = v10 + 1;
        v4 = v29;
        *(_DWORD *)v29 = v12;
        goto LABEL_70;
      case 3u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 4) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 36504);
        goto LABEL_69;
      case 4u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 8) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v13 = 0;
        v24 = v6[1];
        a3 = v29 + 36508;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016C6E0((int)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v14 = (_DWORD *)v6[1];
          if ( v14 > (_DWORD *)((char *)Size + v24) )
            return -34;
          if ( v14 == (_DWORD *)((char *)Size + v24) )
            break;
          a3 += 57;
          if ( ++v13 >= 20 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v15 = v13 + 1;
        v4 = v29;
        *((_DWORD *)v29 + 9126) = v15;
        goto LABEL_70;
      case 5u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 0x10) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 37648);
        goto LABEL_69;
      case 6u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 0x20) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v16 = 0;
        v25 = v6[1];
        a3 = v29 + 37652;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016D130((int)a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v17 = (_DWORD *)v6[1];
          if ( v17 > (_DWORD *)((char *)Size + v25) )
            return -34;
          if ( v17 == (_DWORD *)((char *)Size + v25) )
            break;
          a3 += 56;
          if ( ++v16 >= 20 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v18 = v16 + 1;
        v4 = v29;
        *((_DWORD *)v29 + 9412) = v18;
        goto LABEL_70;
      case 7u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 0x40) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 38772);
        goto LABEL_69;
      case 8u:
        if ( (*(_DWORD *)((char *)v4 + 39146) & 0x80) == 0 )
          *(_DWORD *)((char *)v4 + 39146) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v19 = 0;
        v26 = v6[1];
        a3 = v29 + 38776;
        while ( 1 )
        {
          v27 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v27);
          if ( v5 )
            return v5;
          if ( v27 )
          {
            v5 = sub_1016DA60(a3, (size_t)v6, v27);
            if ( v5 )
              return v5;
          }
          v20 = (_DWORD *)v6[1];
          if ( v20 > (_DWORD *)((char *)Size + v26) )
            return -34;
          if ( v20 == (_DWORD *)((char *)Size + v26) )
            break;
          a3 += 37;
          if ( ++v19 >= 10 )
          {
            v4 = v29;
            goto LABEL_70;
          }
        }
        v21 = v19 + 1;
        v4 = v29;
        *((_DWORD *)v29 + 9693) = v21;
LABEL_70:
        v7 = v22;
        if ( v6[1] < (unsigned int)v22 )
          continue;
LABEL_71:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v28 & 0xF);
LABEL_69:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_70;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0125::DoDebugFormat
// Address Name: SUB_10174040
// ============================================================
//----- (10174040) --------------------------------------------------------
int __thiscall sub_10174040(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101740F0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0125::DebugFormat
// Address Name: SUB_101740F0
// ============================================================
//----- (101740F0) --------------------------------------------------------
int __thiscall sub_101740F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *v9; // eax
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v16; // [esp+1Ch] [ebp+Ch]
  int v17; // [esp+1Ch] [ebp+Ch]
  int v18; // [esp+1Ch] [ebp+Ch]
  int v19; // [esp+1Ch] [ebp+Ch]
  unsigned __int8 *v20; // [esp+20h] [ebp+10h]
  unsigned __int8 *v21; // [esp+20h] [ebp+10h]
  _QWORD *v22; // [esp+20h] [ebp+10h]
  const char *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[iFriendCount]", "%d", *this);
  if ( result )
    return result;
  v7 = this;
  v8 = *this;
  if ( (int)*this < 0 )
    return -6;
  if ( v8 > 500 )
    return -7;
  v16 = 0;
  if ( v8 <= 0 )
  {
LABEL_17:
    result = print_field(a2, a3, a4, "[iPasserbyCount]", "%d", v7[9126]);
    if ( result )
      return result;
    v9 = this;
    v10 = *(this + 9126);
    if ( v10 < 0 )
      return -6;
    if ( v10 <= 20 )
    {
      v17 = 0;
      if ( v10 > 0 )
      {
        v21 = (unsigned __int8 *)(this + 9127);
        do
        {
          if ( !"[astPasserbyData]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            return result;
          result = Printf(a2, "%s[%u]%c", "[astPasserbyData]", v17, a4);
          if ( result )
            return result;
          result = a3 >= 0 ? sub_1016C990(v21, a2, a3 + 1, a4) : sub_1016C990(v21, a2, a3, a4);
          if ( result )
            return result;
          v9 = this;
          v21 += 57;
        }
        while ( ++v17 < *(this + 9126) );
      }
      result = print_field(a2, a3, a4, "[iBlacklistCount]", "%d", v9[9412]);
      if ( result )
        return result;
      v11 = this;
      v12 = *(this + 9412);
      if ( v12 < 0 )
        return -6;
      if ( v12 <= 20 )
      {
        v13 = 0;
        v18 = 0;
        if ( v12 > 0 )
        {
          v22 = this + 9413;
          do
          {
            result = sub_1024A230(a2, a3, a4, "[astBlacklistData]", v13);
            if ( result )
              return result;
            result = a3 >= 0 ? sub_1016D370(v22, a2, a3 + 1, a4) : sub_1016D370(v22, a2, a3, a4);
            if ( result )
              return result;
            v11 = this;
            v13 = v18 + 1;
            v22 += 7;
            v18 = v13;
          }
          while ( v13 < *(this + 9412) );
        }
        result = print_field(a2, a3, a4, "[iFriendGroupCount]", "%d", v11[9693]);
        if ( result )
          return result;
        v14 = *(this + 9693);
        if ( v14 < 0 )
          return -6;
        if ( v14 <= 10 )
        {
          v19 = 0;
          if ( v14 <= 0 )
            return 0;
          for ( i = (const char *)(this + 9694); ; i += 37 )
          {
            result = sub_1024A230(a2, a3, a4, "[astFriendGroupData]", result);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1016DCF0(i, a2, a3 + 1, a4) : sub_1016DCF0(i, a2, a3, a4);
            if ( result )
              break;
            result = v19 + 1;
            v19 = result;
            if ( result >= *(this + 9693) )
              return 0;
          }
          return result;
        }
      }
    }
    return -7;
  }
  v20 = (unsigned __int8 *)(this + 1);
  while ( 1 )
  {
    if ( !"[astFriendData]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      return result;
    result = Printf(a2, "%s[%u]%c", "[astFriendData]", v16, a4);
    if ( result )
      return result;
    result = a3 >= 0 ? sub_1016BDF0(v20, a2, a3 + 1, a4) : sub_1016BDF0(v20, a2, a3, a4);
    if ( result )
      return result;
    v7 = this;
    v20 += 73;
    if ( ++v16 >= *this )
      goto LABEL_17;
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016B8A0
// ============================================================
//----- (1016B8A0) --------------------------------------------------------
int __thiscall sub_1016B8A0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 69) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 69) & 1) == 0 )
            *(_DWORD *)(this + 69) |= 1u;
          VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)this);
          goto LABEL_38;
        case 2u:
          if ( (*(_DWORD *)(this + 69) & 2) == 0 )
            *(_DWORD *)(this + 69) |= 2u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 8));
          goto LABEL_38;
        case 3u:
          if ( (*(_DWORD *)(this + 69) & 4) == 0 )
            *(_DWORD *)(this + 69) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_39:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_40;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 69) & 8) == 0 )
            *(_DWORD *)(this + 69) |= 8u;
          VarULong = TdrBuf::ReadByte(v4, (_BYTE *)(this + 44));
          goto LABEL_38;
        case 5u:
          if ( (*(_DWORD *)(this + 69) & 0x10) == 0 )
            *(_DWORD *)(this + 69) |= 0x10u;
          VarULong = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 45));
          goto LABEL_38;
        case 6u:
          if ( (*(_DWORD *)(this + 69) & 0x20) == 0 )
            *(_DWORD *)(this + 69) |= 0x20u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 49));
          goto LABEL_38;
        case 7u:
          if ( (*(_DWORD *)(this + 69) & 0x40) == 0 )
            *(_DWORD *)(this + 69) |= 0x40u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 53));
          goto LABEL_38;
        case 8u:
          if ( (*(_DWORD *)(this + 69) & 0x80) == 0 )
            *(_DWORD *)(this + 69) |= 0x80u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 57));
          goto LABEL_38;
        case 9u:
          if ( (*(_DWORD *)(this + 69) & 0x100) == 0 )
            *(_DWORD *)(this + 69) |= 0x100u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 61));
          goto LABEL_38;
        case 0xAu:
          if ( (*(_DWORD *)(this + 69) & 0x200) == 0 )
            *(_DWORD *)(this + 69) |= 0x200u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 65));
          goto LABEL_38;
        default:
          VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_38:
          Bytes = VarULong;
          if ( !VarULong )
            goto LABEL_39;
          return Bytes;
      }
    }
  }
LABEL_40:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016CFC0
// ============================================================
//----- (1016CFC0) --------------------------------------------------------
int __thiscall sub_1016CFC0(_DWORD *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 13) & 1) == 0 )
            *(this + 13) |= 1u;
          VarULong = TdrBuf::ReadVarULong(v4, this);
          goto LABEL_23;
        case 2u:
          if ( (*(this + 13) & 2) == 0 )
            *(this + 13) |= 2u;
          VarULong = TdrBuf::ReadVarInt(v4, this + 2);
          goto LABEL_23;
        case 3u:
          if ( (*(this + 13) & 4) == 0 )
            *(this + 13) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 3, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 12) = 0;
LABEL_24:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_25;
          break;
        case 4u:
          if ( (*(this + 13) & 8) == 0 )
            *(this + 13) |= 8u;
          VarULong = TdrBuf::ReadVarInt(v4, this + 11);
          goto LABEL_23;
        case 5u:
          if ( (*(this + 13) & 0x10) == 0 )
            *(this + 13) |= 0x10u;
          VarULong = TdrBuf::ReadVarInt(v4, this + 12);
          goto LABEL_23;
        default:
          VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_23:
          Bytes = VarULong;
          if ( !VarULong )
            goto LABEL_24;
          return Bytes;
      }
    }
  }
LABEL_25:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016C500
// ============================================================
//----- (1016C500) --------------------------------------------------------
int __thiscall sub_1016C500(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v11 = 0;
  *(_DWORD *)(this + 53) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v11);
      if ( result )
        return result;
      switch ( v11 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 53) & 1) == 0 )
            *(_DWORD *)(this + 53) |= 1u;
          VarULong = TdrBuf::ReadVarULong(v4, (_DWORD *)this);
          goto LABEL_29;
        case 2u:
          if ( (*(_DWORD *)(this + 53) & 2) == 0 )
            *(_DWORD *)(this + 53) |= 2u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 8));
          goto LABEL_29;
        case 3u:
          if ( (*(_DWORD *)(this + 53) & 4) == 0 )
            *(_DWORD *)(this + 53) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
          goto LABEL_30;
        case 4u:
          if ( (*(_DWORD *)(this + 53) & 8) == 0 )
            *(_DWORD *)(this + 53) |= 8u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 44) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          Bytes = 0;
LABEL_30:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_31;
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 53) & 0x10) == 0 )
            *(_DWORD *)(this + 53) |= 0x10u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 45));
          goto LABEL_29;
        case 6u:
          if ( (*(_DWORD *)(this + 53) & 0x20) == 0 )
            *(_DWORD *)(this + 53) |= 0x20u;
          VarULong = TdrBuf::ReadVarInt(v4, (int *)(this + 49));
          goto LABEL_29;
        default:
          VarULong = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_29:
          Bytes = VarULong;
          if ( !VarULong )
            goto LABEL_30;
          return Bytes;
      }
    }
  }
LABEL_31:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016D8D0
// ============================================================
//----- (1016D8D0) --------------------------------------------------------
int __thiscall sub_1016D8D0(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v12 = 0;
  *(_DWORD *)(this + 33) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      break;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 33) & 1) == 0 )
        *(_DWORD *)(this + 33) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v11 = v4[1];
      if ( v4[2] == v11 )
        return -2;
      *this = *(_BYTE *)(v11 + *v4);
      ++v4[1];
    }
    else if ( v12 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 33) & 2) == 0 )
        *(_DWORD *)(this + 33) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x20 )
        return -3;
      if ( this == (char *)-1 )
        return -8;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this + 1, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9 + 1) = 0;
      v6 = a3;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016BAE0
// ============================================================
//----- (1016BAE0) --------------------------------------------------------
int __thiscall sub_1016BAE0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 69) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 69) & 1) == 0 )
            *(_DWORD *)(this + 69) |= 1u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
          goto LABEL_38;
        case 2u:
          if ( (*(_DWORD *)(this + 69) & 2) == 0 )
            *(_DWORD *)(this + 69) |= 2u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
          goto LABEL_38;
        case 3u:
          if ( (*(_DWORD *)(this + 69) & 4) == 0 )
            *(_DWORD *)(this + 69) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_39:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_40;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 69) & 8) == 0 )
            *(_DWORD *)(this + 69) |= 8u;
          Int64 = TdrBuf::ReadByte(v4, (_BYTE *)(this + 44));
          goto LABEL_38;
        case 5u:
          if ( (*(_DWORD *)(this + 69) & 0x10) == 0 )
            *(_DWORD *)(this + 69) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 45));
          goto LABEL_38;
        case 6u:
          if ( (*(_DWORD *)(this + 69) & 0x20) == 0 )
            *(_DWORD *)(this + 69) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 49));
          goto LABEL_38;
        case 7u:
          if ( (*(_DWORD *)(this + 69) & 0x40) == 0 )
            *(_DWORD *)(this + 69) |= 0x40u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 53));
          goto LABEL_38;
        case 8u:
          if ( (*(_DWORD *)(this + 69) & 0x80) == 0 )
            *(_DWORD *)(this + 69) |= 0x80u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 57));
          goto LABEL_38;
        case 9u:
          if ( (*(_DWORD *)(this + 69) & 0x100) == 0 )
            *(_DWORD *)(this + 69) |= 0x100u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 61));
          goto LABEL_38;
        case 0xAu:
          if ( (*(_DWORD *)(this + 69) & 0x200) == 0 )
            *(_DWORD *)(this + 69) |= 0x200u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 65));
          goto LABEL_38;
        default:
          Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_38:
          Bytes = Int64;
          if ( !Int64 )
            goto LABEL_39;
          return Bytes;
      }
    }
  }
LABEL_40:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016D130
// ============================================================
//----- (1016D130) --------------------------------------------------------
int __thiscall sub_1016D130(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 52) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 52) & 1) == 0 )
            *(_DWORD *)(this + 52) |= 1u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
          goto LABEL_23;
        case 2u:
          if ( (*(_DWORD *)(this + 52) & 2) == 0 )
            *(_DWORD *)(this + 52) |= 2u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
          goto LABEL_23;
        case 3u:
          if ( (*(_DWORD *)(this + 52) & 4) == 0 )
            *(_DWORD *)(this + 52) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_24:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_25;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 52) & 8) == 0 )
            *(_DWORD *)(this + 52) |= 8u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 44));
          goto LABEL_23;
        case 5u:
          if ( (*(_DWORD *)(this + 52) & 0x10) == 0 )
            *(_DWORD *)(this + 52) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 48));
          goto LABEL_23;
        default:
          Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_23:
          Bytes = Int64;
          if ( !Int64 )
            goto LABEL_24;
          return Bytes;
      }
    }
  }
LABEL_25:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016DA60
// ============================================================
//----- (1016DA60) --------------------------------------------------------
int __thiscall sub_1016DA60(char *this, size_t Size, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  size_t v9; // ebx
  int v10; // edx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  v12 = 0;
  *(_DWORD *)(this + 33) = 0;
  v6 = v4[1] + v3;
  a3 = v6;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v12);
    if ( result )
      break;
    if ( v12 >> 4 == 1 )
    {
      if ( (*(this + 33) & 1) == 0 )
        *(_DWORD *)(this + 33) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v11 = v4[1];
      if ( v4[2] == v11 )
        return -2;
      *this = *(_BYTE *)(v11 + *v4);
      ++v4[1];
    }
    else if ( v12 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 33) & 2) == 0 )
        *(_DWORD *)(this + 33) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 0x20 )
        return -3;
      if ( this == (char *)-1 )
        return -8;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2F8u);
      v10 = v4[1];
      if ( Size > v4[2] - v10 )
        return -2;
      memmove(this + 1, (const void *)(v10 + *v4), Size);
      v4[1] += v9;
      *(this + v9 + 1) = 0;
      v6 = a3;
    }
    else
    {
      result = TdrBuf::SkipField(v4, v12 & 0xF);
      if ( result )
        return result;
    }
    if ( v4[1] >= v6 )
    {
      v7 = v6 < v4[1];
      return v7 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016C6E0
// ============================================================
//----- (1016C6E0) --------------------------------------------------------
int __thiscall sub_1016C6E0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v11 = 0;
  *(_DWORD *)(this + 53) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v11);
      if ( result )
        return result;
      switch ( v11 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 53) & 1) == 0 )
            *(_DWORD *)(this + 53) |= 1u;
          Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this);
          goto LABEL_29;
        case 2u:
          if ( (*(_DWORD *)(this + 53) & 2) == 0 )
            *(_DWORD *)(this + 53) |= 2u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
          goto LABEL_29;
        case 3u:
          if ( (*(_DWORD *)(this + 53) & 4) == 0 )
            *(_DWORD *)(this + 53) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
          goto LABEL_30;
        case 4u:
          if ( (*(_DWORD *)(this + 53) & 8) == 0 )
            *(_DWORD *)(this + 53) |= 8u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 44) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          Bytes = 0;
LABEL_30:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_31;
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 53) & 0x10) == 0 )
            *(_DWORD *)(this + 53) |= 0x10u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 45));
          goto LABEL_29;
        case 6u:
          if ( (*(_DWORD *)(this + 53) & 0x20) == 0 )
            *(_DWORD *)(this + 53) |= 0x20u;
          Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 49));
          goto LABEL_29;
        default:
          Int64 = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_29:
          Bytes = Int64;
          if ( !Int64 )
            goto LABEL_30;
          return Bytes;
      }
    }
  }
LABEL_31:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
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
// Address Name: SUB_1016DCF0
// ============================================================
//----- (1016DCF0) --------------------------------------------------------
int __thiscall sub_1016DCF0(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[bGroupID]", "0x%02x", *(unsigned __int8 *)this);
  if ( !result )
    return sub_1024A410(a2, a3, a4, "[szGroupName]", this + 1);
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1016BDF0
// ============================================================
//----- (1016BDF0) --------------------------------------------------------
int __thiscall sub_1016BDF0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[ullRoleDBID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iLevel]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[szRoleName]", (const char *)this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[bGroupID]", "0x%02x", *(this + 44));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[dwFriendly]", "%u", *(_DWORD *)(this + 45));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[iFarmPoint]", "%d", *(_DWORD *)(this + 49));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[iFarmCanBeGatheredCount]", "%d", *(_DWORD *)(this + 53));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[iHRLevel]", "%d", *(_DWORD *)(this + 57));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[iAddTime]", "%d", *(_DWORD *)(this + 61));
                  if ( !result )
                    return print_field(a2, a3, a4, "[dwSvrId]", "%d", *(_DWORD *)(this + 65));
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
// Address Name: SUB_1016D370
// ============================================================
//----- (1016D370) --------------------------------------------------------
int __thiscall sub_1016D370(_QWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[ullRoleDBID]", "%I64u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iLevel]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[szRoleName]", (const char *)this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iHRLevel]", "%d", *((_DWORD *)this + 11));
        if ( !result )
          return print_field(a2, a3, a4, "[iSvrId]", "%d", *((_DWORD *)this + 12));
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
// Address Name: SUB_1016C990
// ============================================================
//----- (1016C990) --------------------------------------------------------
int __thiscall sub_1016C990(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[ullRoleDBID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iLevel]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[szRoleName]", (const char *)this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[bMeetWay]", "0x%02x", *(this + 44));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[iHRLevel]", "%d", *(_DWORD *)(this + 45));
          if ( !result )
            return print_field(a2, a3, a4, "[iSvrId]", "%d", *(_DWORD *)(this + 49));
        }
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1024A410
// ============================================================
//----- (1024A410) --------------------------------------------------------
int __fastcall sub_1024A410(_DWORD *a1, int a2, char a3, const char *ArgList, const char *a5)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xAFu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s: ", ArgList);
    if ( !result )
    {
      result = Printf(a1, "%s", a5);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
    }
  }
  return result;
}



