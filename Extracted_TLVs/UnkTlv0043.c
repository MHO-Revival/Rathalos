// ============================================================
// Name: TLV::UnkTlv0043::Read_0xAA
// Address Name: SUB_1012FF50
// ============================================================
//----- (1012FF50) --------------------------------------------------------
int __thiscall sub_1012FF50(int *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  char *v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v20; // [esp+18h] [ebp-8h] BYREF
  int *v21; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v21 = this;
  *(int *)((char *)this + 246) = 0;
  v20 = 0;
  v7 = (char *)v3 + v6[1];
  v16 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_45;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 246) & 1) == 0 )
          *(int *)((char *)v4 + 246) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
        goto LABEL_43;
      case 2u:
        if ( (*(int *)((char *)v4 + 246) & 2) == 0 )
          *(int *)((char *)v4 + 246) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        a3 = v21 + 1;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1012ED80((int)a3, v6, v19);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 = (int *)((char *)a3 + 17);
          if ( ++v10 >= 10 )
          {
            v4 = v21;
            goto LABEL_44;
          }
        }
        v12 = v10 + 1;
        v4 = v21;
        *v21 = v12;
        goto LABEL_44;
      case 3u:
        if ( (*(int *)((char *)v4 + 246) & 4) == 0 )
          *(int *)((char *)v4 + 246) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)((char *)v4 + 174));
        goto LABEL_43;
      case 4u:
        if ( (*(int *)((char *)v4 + 246) & 8) == 0 )
          *(int *)((char *)v4 + 246) |= 8u;
        VarInt = TdrBuf::ReadVarUInt(v6, (int *)((char *)v4 + 178));
        goto LABEL_43;
      case 5u:
        if ( (*(int *)((char *)v4 + 246) & 0x10) == 0 )
          *(int *)((char *)v4 + 246) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(v6, (int *)((char *)v4 + 182));
        goto LABEL_43;
      case 6u:
        if ( (*(int *)((char *)v4 + 246) & 0x20) == 0 )
          *(int *)((char *)v4 + 246) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v18 = v6[1];
        a3 = (int *)((char *)v21 + 186);
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1012F510(a3, v6, v19);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
            break;
          a3 += 3;
          if ( ++v13 >= 5 )
          {
            v4 = v21;
            goto LABEL_44;
          }
        }
        v15 = v13 + 1;
        v4 = v21;
        *(int *)((char *)v21 + 182) = v15;
LABEL_44:
        v7 = v16;
        if ( v6[1] < (unsigned int)v16 )
          continue;
LABEL_45:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return v5;
      default:
        VarInt = TdrBuf::SkipField(v6, v20 & 0xF);
LABEL_43:
        v5 = VarInt;
        if ( !VarInt )
          goto LABEL_44;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0043::Read_0x99
// Address Name: SUB_10130220
// ============================================================
//----- (10130220) --------------------------------------------------------
int __thiscall sub_10130220(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // ebx
  unsigned int v14; // ecx
  int v15; // eax
  unsigned int v16; // [esp+Ch] [ebp-14h]
  int v17; // [esp+10h] [ebp-10h]
  int v18; // [esp+10h] [ebp-10h]
  int v19; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v20; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v21; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v21 = this;
  *(_DWORD *)((char *)this + 246) = 0;
  v20 = 0;
  v7 = v6[1] + v3;
  v16 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_45;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v20);
    if ( result )
      return result;
    switch ( v20 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v4 + 246) & 1) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
        goto LABEL_43;
      case 2u:
        if ( (*(_DWORD *)((char *)v4 + 246) & 2) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 2u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v10 = 0;
        v17 = v6[1];
        a3 = (int)(v21 + 1);
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1012EED0(a3, v6, v19);
            if ( v5 )
              return v5;
          }
          v11 = v6[1];
          if ( v11 > (unsigned int)a2 + v17 )
            return -34;
          if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v17) )
            break;
          a3 += 17;
          if ( ++v10 >= 10 )
          {
            v4 = v21;
            goto LABEL_44;
          }
        }
        v12 = v10 + 1;
        v4 = v21;
        *v21 = v12;
        goto LABEL_44;
      case 3u:
        if ( (*(_DWORD *)((char *)v4 + 246) & 4) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 4u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 174);
        goto LABEL_43;
      case 4u:
        if ( (*(_DWORD *)((char *)v4 + 246) & 8) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 8u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 178);
        goto LABEL_43;
      case 5u:
        if ( (*(_DWORD *)((char *)v4 + 246) & 0x10) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)v4 + 182);
        goto LABEL_43;
      case 6u:
        if ( (*(_DWORD *)((char *)v4 + 246) & 0x20) == 0 )
          *(_DWORD *)((char *)v4 + 246) |= 0x20u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v6, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v13 = 0;
        v18 = v6[1];
        a3 = (int)v21 + 186;
        while ( 1 )
        {
          v19 = 0;
          v5 = TdrBuf::ReadInt32(v6, &v19);
          if ( v5 )
            return v5;
          if ( v19 )
          {
            v5 = sub_1012F5B0(a3, v6, v19);
            if ( v5 )
              return v5;
          }
          v14 = v6[1];
          if ( v14 > (unsigned int)a2 + v18 )
            return -34;
          if ( (_DWORD *)v14 == (_DWORD *)((char *)a2 + v18) )
            break;
          a3 += 12;
          if ( ++v13 >= 5 )
          {
            v4 = v21;
            goto LABEL_44;
          }
        }
        v15 = v13 + 1;
        v4 = v21;
        *(_DWORD *)((char *)v21 + 182) = v15;
LABEL_44:
        v7 = v16;
        if ( v6[1] < v16 )
          continue;
LABEL_45:
        if ( v6[1] > v7 )
          return -34;
        return v5;
      default:
        Int32 = TdrBuf::SkipField(v6, v20 & 0xF);
LABEL_43:
        v5 = Int32;
        if ( !Int32 )
          goto LABEL_44;
        return v5;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0043::DoDebugFormat
// Address Name: SUB_10130510
// ============================================================
//----- (10130510) --------------------------------------------------------
int __thiscall sub_10130510(int *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101305C0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0043::DebugFormat
// Address Name: SUB_101305C0
// ============================================================
//----- (101305C0) --------------------------------------------------------
int __thiscall sub_101305C0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int *v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ebx
  int v12; // [esp+18h] [ebp+8h]
  _DWORD *v13; // [esp+1Ch] [ebp+Ch]
  _DWORD *i; // [esp+1Ch] [ebp+Ch]

  result = print_field(a2, a3, a4, "[commerceCount]", "%d", *this);
  if ( !result )
  {
    v7 = this;
    v8 = *this;
    if ( *this < 0 )
      return -6;
    if ( v8 > 10 )
      return -7;
    v12 = 0;
    if ( v8 <= 0 )
    {
LABEL_18:
      result = print_field(a2, a3, a4, "[selectCommerceId]", "%d", *(int *)((char *)v7 + 174));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[guildWarHistoryInfo]", "%u", *(int *)((char *)this + 178));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[buffCount]", "%d", *(int *)((char *)this + 182));
          if ( !result )
          {
            v9 = *(int *)((char *)this + 182);
            if ( v9 < 0 )
              return -6;
            if ( v9 > 5 )
              return -7;
            v10 = 0;
            if ( v9 <= 0 )
            {
              return 0;
            }
            else
            {
              for ( i = (int *)((char *)this + 186); ; i += 3 )
              {
                result = sub_1024A230(a2, a3, a4, "[commerceBuffInfo]", v10);
                if ( result )
                  break;
                result = a3 >= 0 ? sub_1012F750(i, a2, a3 + 1, a4) : sub_1012F750(i, a2, a3, a4);
                if ( result )
                  break;
                if ( ++v10 >= *(int *)((char *)this + 182) )
                  return 0;
              }
            }
          }
        }
      }
    }
    else
    {
      v13 = this + 1;
      while ( 1 )
      {
        if ( !"[commerceInfo]" )
          _wassert(
            L"NULL != variable",
            L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
            0x43u);
        result = sub_1024A140(a3);
        if ( result )
          break;
        result = Printf(a2, "%s[%u]%c", "[commerceInfo]", v12, a4);
        if ( result )
          break;
        result = a3 >= 0 ? sub_1012F0F0(v13, a2, a3 + 1, a4) : sub_1012F0F0(v13, a2, a3, a4);
        if ( result )
          break;
        v13 = (_DWORD *)((char *)v13 + 17);
        if ( ++v12 >= *this )
        {
          v7 = this;
          goto LABEL_18;
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012F510
// ============================================================
//----- (1012F510) --------------------------------------------------------
int __thiscall sub_1012F510(int *this, _DWORD *a2, int a3)
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
// Address Name: SUB_1012ED80
// ============================================================
//----- (1012ED80) --------------------------------------------------------
int __thiscall sub_1012ED80(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 13) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 13) & 1) == 0 )
            *(_DWORD *)(this + 13) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, (int *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 13) & 2) == 0 )
            *(_DWORD *)(this + 13) |= 2u;
          VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 4));
          goto LABEL_20;
        case 3u:
          if ( (*(_DWORD *)(this + 13) & 4) == 0 )
            *(_DWORD *)(this + 13) |= 4u;
          VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(this + 8));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 13) & 8) == 0 )
            *(_DWORD *)(this + 13) |= 8u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 12) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = VarInt;
          if ( !VarInt )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012F5B0
// ============================================================
//----- (1012F5B0) --------------------------------------------------------
int __thiscall sub_1012F5B0(int this, _DWORD *a2, int a3)
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
// Address Name: SUB_1012EED0
// ============================================================
//----- (1012EED0) --------------------------------------------------------
int __thiscall sub_1012EED0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  int v9; // ecx
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v11; // [esp+18h] [ebp+8h]

  v5 = 0;
  v10 = 0;
  *(_DWORD *)(this + 13) = 0;
  v6 = a2[1] + a3;
  v11 = v6;
  if ( a2[1] < v6 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v10);
      if ( result )
        return result;
      switch ( v10 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 13) & 1) == 0 )
            *(_DWORD *)(this + 13) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          goto LABEL_20;
        case 2u:
          if ( (*(_DWORD *)(this + 13) & 2) == 0 )
            *(_DWORD *)(this + 13) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          goto LABEL_20;
        case 3u:
          if ( (*(_DWORD *)(this + 13) & 4) == 0 )
            *(_DWORD *)(this + 13) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          goto LABEL_20;
        case 4u:
          if ( (*(_DWORD *)(this + 13) & 8) == 0 )
            *(_DWORD *)(this + 13) |= 8u;
          if ( a2[1] > a2[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v9 = a2[1];
          if ( a2[2] == v9 )
            return -2;
          *(_BYTE *)(this + 12) = *(_BYTE *)(v9 + *a2);
          ++a2[1];
          v5 = 0;
LABEL_21:
          v6 = v11;
          if ( a2[1] >= v11 )
            goto LABEL_22;
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v10 & 0xF);
LABEL_20:
          v5 = Int32;
          if ( !Int32 )
            goto LABEL_21;
          return v5;
      }
    }
  }
LABEL_22:
  if ( a2[1] > v6 )
    return -34;
  return v5;
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
// Address Name: SUB_1012F750
// ============================================================
//----- (1012F750) --------------------------------------------------------
int __thiscall sub_1012F750(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commerceId]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[timeoutDate]", "%u", *(this + 1));
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
// Address Name: SUB_1012F0F0
// ============================================================
//----- (1012F0F0) --------------------------------------------------------
int __thiscall sub_1012F0F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[goodsNumber]", "%u", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[lastChangeTime]", "%u", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[isOwned]", "0x%02x", *((char *)this + 12));
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



