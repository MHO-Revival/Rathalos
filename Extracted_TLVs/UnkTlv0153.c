// ============================================================
// Name: TLV::UnkTlv0153::Read
// Address Name: SUB_10187CD0
// ============================================================
//----- (10187CD0) --------------------------------------------------------
int __thiscall sub_10187CD0(int *this, size_t a2, unsigned int a3, _DWORD *a4)
{
  int result; // eax
  size_t v6; // esi
  char v7; // bl
  _DWORD *v8; // [esp-Ch] [ebp-1Ch]
  size_t Size; // [esp+4h] [ebp-Ch] BYREF
  int v10; // [esp+8h] [ebp-8h]
  unsigned int v11; // [esp+Ch] [ebp-4h]

  if ( !a2 )
    return -19;
  v6 = a3;
  if ( a3 < 5 )
    return -2;
  Size = a2;
  v10 = 0;
  v11 = a3;
  HIBYTE(a2) = 0;
  TdrBuf::ReadByte(&Size, (_BYTE *)&a2 + 3);
  v7 = HIBYTE(a2);
  if ( HIBYTE(a2) != 0xAA && HIBYTE(a2) != 0x99 )
    return -32;
  a2 = 0;
  TdrBuf::ReadInt32(&Size, &a2);
  if ( v6 < a2 )
    return -2;
  v8 = (_DWORD *)(a2 - 5);
  if ( v7 == -86 )
    result = sub_10187DA0(this, (size_t)&Size, v8);
  else
    result = sub_10188290(this, (size_t)&Size, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0153::Read_0xAA
// Address Name: SUB_10187DA0
// ============================================================
//----- (10187DA0) --------------------------------------------------------
int __thiscall sub_10187DA0(int *this, size_t Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  int *v11; // eax
  size_t v12; // ecx
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  int *v17; // eax
  size_t v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ebx
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // ecx
  unsigned int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch] BYREF
  int v28; // [esp+18h] [ebp-8h]
  int *v29; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Byte = 0;
  v29 = this;
  v27 = 0;
  *(int *)((char *)this + 542) = 0;
  v7 = v4[1] + v3;
  v25 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_82;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v27);
    if ( result )
      return result;
    switch ( v27 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 542) & 1) == 0 )
          *(int *)((char *)v5 + 542) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v4, v5);
        goto LABEL_80;
      case 2u:
        if ( (*(int *)((char *)v5 + 542) & 2) == 0 )
          *(int *)((char *)v5 + 542) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v28 = v4[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        while ( 1 )
        {
          Byte = TdrBuf::ReadVarInt(v4, v11);
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > v28 + Size )
            return -34;
          if ( v12 == v28 + Size )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 40 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v13 = v10 + 1;
        v5 = v29;
        *v29 = v13;
        goto LABEL_81;
      case 3u:
        if ( (*(int *)((char *)v5 + 542) & 4) == 0 )
          *(int *)((char *)v5 + 542) |= 4u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 41);
        goto LABEL_80;
      case 4u:
        if ( (*(int *)((char *)v5 + 542) & 8) == 0 )
          *(int *)((char *)v5 + 542) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 168);
          if ( Byte )
            return Byte;
          v15 = (_DWORD *)v4[1];
          if ( v15 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v15 == (_DWORD *)((char *)a3 + Size) )
            goto LABEL_31;
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 5u:
        if ( (*(int *)((char *)v5 + 542) & 0x10) == 0 )
          *(int *)((char *)v5 + 542) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        v28 = v4[1];
        v17 = v29 + 47;
        a3 = v29 + 47;
        do
        {
          Byte = TdrBuf::ReadVarInt(v4, v17);
          if ( Byte )
            return Byte;
          v18 = v4[1];
          if ( v18 > v28 + Size )
            return -34;
          if ( v18 == v28 + Size )
            goto LABEL_31;
          ++v14;
          v17 = ++a3;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 6u:
        if ( (*(int *)((char *)v5 + 542) & 0x20) == 0 )
          *(int *)((char *)v5 + 542) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 268);
          if ( Byte )
            return Byte;
          v19 = (_DWORD *)v4[1];
          if ( v19 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v19 == (_DWORD *)((char *)a3 + Size) )
          {
LABEL_31:
            v16 = v14 + 1;
            v5 = v29;
            v29[41] = v16;
            goto LABEL_81;
          }
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 7u:
        if ( (*(int *)((char *)v5 + 542) & 0x40) == 0 )
          *(int *)((char *)v5 + 542) |= 0x40u;
        VarInt = TdrBuf::ReadVarInt(v4, v5 + 72);
        goto LABEL_80;
      case 8u:
        if ( (*(int *)((char *)v5 + 542) & 0x80) == 0 )
          *(int *)((char *)v5 + 542) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v20 = 0;
        a3 = (_DWORD *)v4[1];
        while ( 1 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v20 + 292);
          if ( Byte )
            return Byte;
          v21 = (_DWORD *)v4[1];
          if ( v21 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v21 == (_DWORD *)((char *)a3 + Size) )
            break;
          if ( ++v20 >= 10 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v22 = v20 + 1;
        v5 = v29;
        v29[72] = v22;
        goto LABEL_81;
      case 9u:
        if ( (*(int *)((char *)v5 + 542) & 0x100) == 0 )
          *(int *)((char *)v5 + 542) |= 0x100u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v26 = v4[1];
        v28 = 0;
        v23 = 0;
        break;
      default:
        VarInt = TdrBuf::SkipField(v4, v27 & 0xF);
LABEL_80:
        Byte = VarInt;
        if ( !VarInt )
          goto LABEL_81;
        return Byte;
    }
    while ( 1 )
    {
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      if ( Size >= 0x18 )
        return -3;
      Byte = TdrBuf::ReadBytes(v4, (char *)&v29[v23 + 75] + 2, Size);
      if ( Byte )
        return Byte;
      *((_BYTE *)&v29[v23 + 75] + Size + 2) = 0;
      v24 = v4[1];
      if ( v24 > (unsigned int)a3 + v26 )
        return -34;
      if ( (_DWORD *)v24 == (_DWORD *)((char *)a3 + v26) )
        break;
      ++v28;
      v23 += 6;
      if ( v23 >= 60 )
      {
        v5 = v29;
        goto LABEL_81;
      }
    }
    v5 = v29;
    v29[72] = v28 + 1;
LABEL_81:
    v7 = v25;
    if ( v4[1] >= v25 )
    {
LABEL_82:
      if ( v4[1] > v7 )
        return -34;
      return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0153::Read_0x99
// Address Name: SUB_10188290
// ============================================================
//----- (10188290) --------------------------------------------------------
int __thiscall sub_10188290(int *this, size_t Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int *v5; // ebx
  int Byte; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _BYTE *v11; // eax
  size_t v12; // ecx
  int v13; // eax
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  _BYTE *v17; // eax
  size_t v18; // ecx
  _DWORD *v19; // ecx
  int v20; // ebx
  _DWORD *v21; // ecx
  int v22; // eax
  int v23; // ebx
  unsigned int v24; // ecx
  unsigned int v25; // [esp+Ch] [ebp-14h]
  int v26; // [esp+10h] [ebp-10h]
  unsigned int v27; // [esp+14h] [ebp-Ch] BYREF
  int v28; // [esp+18h] [ebp-8h]
  int *v29; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = (_DWORD *)Size;
  v5 = this;
  Byte = 0;
  v29 = this;
  v27 = 0;
  *(int *)((char *)this + 542) = 0;
  v7 = v4[1] + v3;
  v25 = v7;
  if ( v4[1] >= v7 )
    goto LABEL_82;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v27);
    if ( result )
      return result;
    switch ( v27 >> 4 )
    {
      case 1u:
        if ( (*((_BYTE *)v5 + 542) & 1) == 0 )
          *(int *)((char *)v5 + 542) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_80;
      case 2u:
        if ( (*(int *)((char *)v5 + 542) & 2) == 0 )
          *(int *)((char *)v5 + 542) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v28 = v4[1];
        v11 = v29 + 1;
        a3 = v29 + 1;
        while ( 1 )
        {
          Byte = TdrBuf::ReadInt32(v4, v11);
          if ( Byte )
            return Byte;
          v12 = v4[1];
          if ( v12 > v28 + Size )
            return -34;
          if ( v12 == v28 + Size )
            break;
          ++v10;
          v11 = ++a3;
          if ( v10 >= 40 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v13 = v10 + 1;
        v5 = v29;
        *v29 = v13;
        goto LABEL_81;
      case 3u:
        if ( (*(int *)((char *)v5 + 542) & 4) == 0 )
          *(int *)((char *)v5 + 542) |= 4u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 164);
        goto LABEL_80;
      case 4u:
        if ( (*(int *)((char *)v5 + 542) & 8) == 0 )
          *(int *)((char *)v5 + 542) |= 8u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 168);
          if ( Byte )
            return Byte;
          v15 = (_DWORD *)v4[1];
          if ( v15 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v15 == (_DWORD *)((char *)a3 + Size) )
            goto LABEL_31;
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 5u:
        if ( (*(int *)((char *)v5 + 542) & 0x10) == 0 )
          *(int *)((char *)v5 + 542) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        v28 = v4[1];
        v17 = v29 + 47;
        a3 = v29 + 47;
        do
        {
          Byte = TdrBuf::ReadInt32(v4, v17);
          if ( Byte )
            return Byte;
          v18 = v4[1];
          if ( v18 > v28 + Size )
            return -34;
          if ( v18 == v28 + Size )
            goto LABEL_31;
          ++v14;
          v17 = ++a3;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 6u:
        if ( (*(int *)((char *)v5 + 542) & 0x20) == 0 )
          *(int *)((char *)v5 + 542) |= 0x20u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v14 = 0;
        a3 = (_DWORD *)v4[1];
        do
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v14 + 268);
          if ( Byte )
            return Byte;
          v19 = (_DWORD *)v4[1];
          if ( v19 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v19 == (_DWORD *)((char *)a3 + Size) )
          {
LABEL_31:
            v16 = v14 + 1;
            v5 = v29;
            v29[41] = v16;
            goto LABEL_81;
          }
          ++v14;
        }
        while ( v14 < 20 );
        v5 = v29;
        goto LABEL_81;
      case 7u:
        if ( (*(int *)((char *)v5 + 542) & 0x40) == 0 )
          *(int *)((char *)v5 + 542) |= 0x40u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 288);
        goto LABEL_80;
      case 8u:
        if ( (*(int *)((char *)v5 + 542) & 0x80) == 0 )
          *(int *)((char *)v5 + 542) |= 0x80u;
        Size = 0;
        result = TdrBuf::ReadInt32(v4, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v20 = 0;
        a3 = (_DWORD *)v4[1];
        while ( 1 )
        {
          Byte = TdrBuf::ReadByte(v4, (_BYTE *)v29 + v20 + 292);
          if ( Byte )
            return Byte;
          v21 = (_DWORD *)v4[1];
          if ( v21 > (_DWORD *)((char *)a3 + Size) )
            return -34;
          if ( v21 == (_DWORD *)((char *)a3 + Size) )
            break;
          if ( ++v20 >= 10 )
          {
            v5 = v29;
            goto LABEL_81;
          }
        }
        v22 = v20 + 1;
        v5 = v29;
        v29[72] = v22;
        goto LABEL_81;
      case 9u:
        if ( (*(int *)((char *)v5 + 542) & 0x100) == 0 )
          *(int *)((char *)v5 + 542) |= 0x100u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v26 = v4[1];
        v28 = 0;
        v23 = 0;
        break;
      default:
        Int32 = TdrBuf::SkipField(v4, v27 & 0xF);
LABEL_80:
        Byte = Int32;
        if ( !Int32 )
          goto LABEL_81;
        return Byte;
    }
    while ( 1 )
    {
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      if ( Size >= 0x18 )
        return -3;
      Byte = TdrBuf::ReadBytes(v4, (char *)&v29[v23 + 75] + 2, Size);
      if ( Byte )
        return Byte;
      *((_BYTE *)&v29[v23 + 75] + Size + 2) = 0;
      v24 = v4[1];
      if ( v24 > (unsigned int)a3 + v26 )
        return -34;
      if ( (_DWORD *)v24 == (_DWORD *)((char *)a3 + v26) )
        break;
      ++v28;
      v23 += 6;
      if ( v23 >= 60 )
      {
        v5 = v29;
        goto LABEL_81;
      }
    }
    v5 = v29;
    v29[72] = v28 + 1;
LABEL_81:
    v7 = v25;
    if ( v4[1] >= v25 )
    {
LABEL_82:
      if ( v4[1] > v7 )
        return -34;
      return Byte;
    }
  }
}



// ============================================================
// Name: TLV::UnkTlv0153::DoDebugFormat
// Address Name: SUB_101887A0
// ============================================================
//----- (101887A0) --------------------------------------------------------
int __thiscall sub_101887A0(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10188850(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0153::DebugFormat
// Address Name: SUB_10188850
// ============================================================
//----- (10188850) --------------------------------------------------------
int __thiscall sub_10188850(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ebx
  _DWORD *v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ebx
  int v21; // ecx
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // ebx
  const char *v26; // eax
  int v27; // [esp+14h] [ebp+8h]
  int v28; // [esp+14h] [ebp+8h]
  int i; // [esp+14h] [ebp+8h]

  result = print_field(a2, a3, a4, "[autoCount]", "%d", *this);
  if ( !result )
  {
    v8 = *this;
    if ( (int)*this < 0 )
      return -6;
    if ( v8 > 40 )
      return -7;
    result = sub_1024A3B0(a2, a3, v7, "[autoSpeak]", v8);
    if ( !result )
    {
      v9 = 0;
      if ( (int)*this <= 0 )
      {
LABEL_11:
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[quickCount]", "%d", *(this + 41));
        if ( result )
          return result;
        v12 = *(this + 41);
        if ( v12 < 0 )
          return -6;
        if ( v12 <= 20 )
        {
          result = sub_1024A3B0(a2, a3, v11, "[quickSpeakIndex]", v12);
          if ( result )
            return result;
          v13 = 0;
          if ( (int)*(this + 41) > 0 )
          {
            do
            {
              result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v13 + 168));
              if ( result )
                return result;
            }
            while ( ++v13 < *(this + 41) );
          }
          result = TdrBuf::WriteChar(a2, a4);
          if ( result )
            return result;
          v15 = *(this + 41);
          if ( v15 < 0 )
            return -6;
          if ( v15 <= 20 )
          {
            result = sub_1024A3B0(a2, a3, v14, "[quickSpeakId]", v15);
            if ( result )
              return result;
            v16 = 0;
            if ( (int)*(this + 41) > 0 )
            {
              v17 = this + 47;
              v28 = (int)(this + 47);
              do
              {
                result = Printf(a2, " %d", *v17);
                if ( result )
                  return result;
                ++v16;
                v17 = (_DWORD *)(v28 + 4);
                v28 += 4;
              }
              while ( v16 < *(this + 41) );
            }
            result = TdrBuf::WriteChar(a2, a4);
            if ( result )
              return result;
            v19 = *(this + 41);
            if ( v19 < 0 )
              return -6;
            if ( v19 <= 20 )
            {
              result = sub_1024A3B0(a2, a3, v18, "[quickSpeakType]", v19);
              if ( result )
                return result;
              v20 = 0;
              if ( (int)*(this + 41) > 0 )
              {
                do
                {
                  result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v20 + 268));
                  if ( result )
                    return result;
                }
                while ( ++v20 < *(this + 41) );
              }
              result = TdrBuf::WriteChar(a2, a4);
              if ( result )
                return result;
              result = print_field(a2, a3, a4, "[selfDefCount]", "%d", *(this + 72));
              if ( result )
                return result;
              v22 = *(this + 72);
              if ( v22 < 0 )
                return -6;
              if ( v22 <= 10 )
              {
                result = sub_1024A3B0(a2, a3, v21, "[selfDefIndex]", v22);
                if ( result )
                  return result;
                v23 = 0;
                if ( (int)*(this + 72) > 0 )
                {
                  do
                  {
                    result = Printf(a2, " 0x%02x", *((unsigned __int8 *)this + v23 + 292));
                    if ( result )
                      return result;
                  }
                  while ( ++v23 < *(this + 72) );
                }
                result = TdrBuf::WriteChar(a2, a4);
                if ( result )
                  return result;
                v24 = *(this + 72);
                if ( v24 < 0 )
                  return -6;
                if ( v24 <= 10 )
                {
                  v25 = 0;
                  if ( v24 <= 0 )
                    return 0;
                  v26 = (char *)this + 302;
                  for ( i = (int)this + 302; ; i += 24 )
                  {
                    result = sub_1024A480(a2, a3, a4, "[selfDefContent]", v25, v26);
                    if ( result )
                      break;
                    ++v25;
                    v26 = (const char *)(i + 24);
                    if ( v25 >= *(this + 72) )
                      return 0;
                  }
                  return result;
                }
              }
            }
          }
        }
        return -7;
      }
      v10 = this + 1;
      v27 = (int)(this + 1);
      while ( 1 )
      {
        result = Printf(a2, " %d", *v10);
        if ( result )
          break;
        ++v9;
        v10 = (_DWORD *)(v27 + 4);
        v27 += 4;
        if ( v9 >= *this )
          goto LABEL_11;
      }
    }
  }
  return result;
}
// 101888AF: variable 'v7' is possibly undefined
// 10188953: variable 'v11' is possibly undefined
// 101889CF: variable 'v14' is possibly undefined
// 10188A53: variable 'v18' is possibly undefined
// 10188AF5: variable 'v21' is possibly undefined



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
// Address Name: SUB_1024A480
// ============================================================
//----- (1024A480) --------------------------------------------------------
int __fastcall sub_1024A480(_DWORD *a1, int a2, char a3, const char *ArgList, int a5, const char *a6)
{
  int result; // eax

  if ( !ArgList )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0xCBu);
  result = sub_1024A140(a2);
  if ( !result )
  {
    result = Printf(a1, "%s[%u]: ", ArgList, a5);
    if ( !result )
    {
      result = Printf(a1, "%s", a6);
      if ( !result )
        return TdrBuf::WriteChar(a1, a3);
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



