// ============================================================
// Name: TLV::UnkTlv0056::Read
// Address Name: SUB_1013CD80
// ============================================================
//----- (1013CD80) --------------------------------------------------------
int __thiscall sub_1013CD80(int *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_1013CE50(this, &v9, v8);
  else
    result = sub_1013D040((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0056::Read_0xAA
// Address Name: SUB_1013CE50
// ============================================================
//----- (1013CE50) --------------------------------------------------------
int __thiscall sub_1013CE50(int *this, _DWORD *a2, int a3)
{
  int Bytes; // esi
  unsigned int v5; // eax
  int result; // eax
  int VarInt; // eax
  size_t Size; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  Bytes = 0;
  v9 = 0;
  *(int *)((char *)this + 1666) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*((_BYTE *)this + 1666) & 1) == 0 )
            *(int *)((char *)this + 1666) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          goto LABEL_27;
        case 2u:
          if ( (*(int *)((char *)this + 1666) & 2) == 0 )
            *(int *)((char *)this + 1666) |= 2u;
          VarInt = TdrBuf::ReadVarULong(a2, this + 1);
          goto LABEL_27;
        case 3u:
          if ( (*(int *)((char *)this + 1666) & 4) == 0 )
            *(int *)((char *)this + 1666) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(a2, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(a2, this + 3, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 12) = 0;
LABEL_28:
          v5 = v10;
          if ( a2[1] >= v10 )
            goto LABEL_29;
          break;
        case 4u:
          if ( (*(int *)((char *)this + 1666) & 8) == 0 )
            *(int *)((char *)this + 1666) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          VarInt = sub_1013BAB0(this + 11, a2, (int *)Size);
          goto LABEL_27;
        case 5u:
          if ( (*(int *)((char *)this + 1666) & 0x10) == 0 )
            *(int *)((char *)this + 1666) |= 0x10u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          VarInt = sub_1013C390(this + 93, a2, Size);
LABEL_27:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_28;
          return Bytes;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          goto LABEL_27;
      }
    }
  }
LABEL_29:
  if ( a2[1] > v5 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0056::Read_0x99
// Address Name: SUB_1013D040
// ============================================================
//----- (1013D040) --------------------------------------------------------
int __thiscall sub_1013D040(int this, _DWORD *a2, int a3)
{
  int Bytes; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  size_t Size; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v9; // [esp+10h] [ebp-8h] BYREF
  unsigned int v10; // [esp+14h] [ebp-4h]

  Bytes = 0;
  v9 = 0;
  *(_DWORD *)(this + 1666) = 0;
  v5 = a2[1] + a3;
  v10 = v5;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 1666) & 1) == 0 )
            *(_DWORD *)(this + 1666) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          goto LABEL_27;
        case 2u:
          if ( (*(_DWORD *)(this + 1666) & 2) == 0 )
            *(_DWORD *)(this + 1666) |= 2u;
          Int32 = TdrBuf::ReadInt64(a2, (_BYTE *)(this + 4));
          goto LABEL_27;
        case 3u:
          if ( (*(_DWORD *)(this + 1666) & 4) == 0 )
            *(_DWORD *)(this + 1666) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(a2, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(a2, (void *)(this + 12), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 12) = 0;
LABEL_28:
          v5 = v10;
          if ( a2[1] >= v10 )
            goto LABEL_29;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 1666) & 8) == 0 )
            *(_DWORD *)(this + 1666) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          Int32 = sub_1013BC20((_DWORD *)(this + 44), a2, Size);
          goto LABEL_27;
        case 5u:
          if ( (*(_DWORD *)(this + 1666) & 0x10) == 0 )
            *(_DWORD *)(this + 1666) |= 0x10u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(a2, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_28;
          Int32 = sub_1013C510(this + 372, a2, Size);
LABEL_27:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_28;
          return Bytes;
        default:
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
          goto LABEL_27;
      }
    }
  }
LABEL_29:
  if ( a2[1] > v5 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: TLV::UnkTlv0056::DoDebugFormat
// Address Name: SUB_1013D250
// ============================================================
//----- (1013D250) --------------------------------------------------------
int __thiscall sub_1013D250(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_1013D300(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0056::DebugFormat
// Address Name: SUB_1013D300
// ============================================================
//----- (1013D300) --------------------------------------------------------
int __thiscall sub_1013D300(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // ecx
  unsigned int *v6; // ecx

  result = print_field(a2, a3, a4, "[sex]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 4));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[name]", this + 12);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[equips]");
        if ( !result )
        {
          v5 = this + 44;
          if ( a3 >= 0 )
            result = sub_1013BE60(v5, a2, a3 + 1, a4);
          else
            result = sub_1013BE60(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[attrs]");
            if ( !result )
            {
              v6 = (unsigned int *)(this + 372);
              if ( a3 >= 0 )
                return sub_1013C760(v6, a2, a3 + 1, a4);
              else
                return sub_1013C760(v6, a2, a3, a4);
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
// Address Name: SUB_1013C390
// ============================================================
//----- (1013C390) --------------------------------------------------------
int __thiscall sub_1013C390(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)((char *)this + 1290) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (*((_BYTE *)this + 1290) & 1) == 0 )
          *(_DWORD *)((char *)this + 1290) |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, this);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)((char *)this + 1290) & 2) == 0 )
            *(_DWORD *)((char *)this + 1290) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *((_BYTE *)this + v11 + 4) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *this = v11 + 1;
                  goto LABEL_23;
                }
                if ( (unsigned int)++v11 >= 0x506 )
                {
                  v6 = a3;
                  goto LABEL_23;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        VarUInt = TdrBuf::SkipField(v4, v16 & 0xF);
      }
      v6 = VarUInt;
      if ( VarUInt )
        return v6;
LABEL_23:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BAB0
// ============================================================
//----- (1013BAB0) --------------------------------------------------------
int __thiscall sub_1013BAB0(_DWORD *this, _DWORD *a2, int *a3)
{
  int *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 81) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
  {
LABEL_24:
    if ( v6[1] > (unsigned int)v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[81] & 1) == 0 )
          v4[81] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[81] & 2) == 0 )
            v4[81] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = v17 + 1;
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1013B3B0(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 2;
            if ( (unsigned int)++v10 >= 0x28 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarUInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarUInt;
      if ( VarUInt )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BC20
// ============================================================
//----- (1013BC20) --------------------------------------------------------
int __thiscall sub_1013BC20(_DWORD *this, _DWORD *a2, int a3)
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
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 81) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_24:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (v4[81] & 1) == 0 )
          v4[81] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[81] & 2) == 0 )
            v4[81] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (int)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_1013B430(a3, v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = v6[1];
            if ( v11 > (unsigned int)a2 + v14 )
              return -34;
            if ( (_DWORD *)v11 == (_DWORD *)((char *)a2 + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 8;
            if ( (unsigned int)++v10 >= 0x28 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        Int32 = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
LABEL_23:
      v7 = v13;
      if ( v6[1] >= v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013C510
// ============================================================
//----- (1013C510) --------------------------------------------------------
int __thiscall sub_1013C510(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // esi
  int v6; // ecx
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  _DWORD *v10; // edx
  int v11; // edi
  int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // [esp+Ch] [ebp-Ch]
  int v15; // [esp+10h] [ebp-8h]
  unsigned int v16; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)(this + 1290) = 0;
  v7 = v4[1] + v3;
  v14 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( result )
        break;
      if ( v16 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1290) & 1) == 0 )
          *(_DWORD *)(this + 1290) |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (*(_DWORD *)(this + 1290) & 2) == 0 )
            *(_DWORD *)(this + 1290) |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v4, &a2);
          if ( !result )
          {
            v10 = a2;
            if ( a2 )
            {
              v11 = 0;
              v15 = v4[1];
              a3 = 0;
              while ( 1 )
              {
                if ( v4[1] > v4[2] )
                  _wassert(
                    L"position <= length",
                    L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
                    0x290u);
                v12 = v4[1];
                if ( v4[2] == v12 )
                  return -2;
                *(_BYTE *)(v11 + this + 4) = *(_BYTE *)(v12 + *v4);
                v13 = ++v4[1];
                if ( v13 > (unsigned int)v10 + v15 )
                  return -34;
                if ( (_DWORD *)v13 == (_DWORD *)((char *)v10 + v15) )
                {
                  v6 = a3;
                  *(_DWORD *)this = v11 + 1;
                  goto LABEL_23;
                }
                if ( (unsigned int)++v11 >= 0x506 )
                {
                  v6 = a3;
                  goto LABEL_23;
                }
              }
            }
            else
            {
              return -37;
            }
          }
          return result;
        }
        Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
      }
      v6 = Int32;
      if ( Int32 )
        return v6;
LABEL_23:
      v7 = v14;
      if ( v4[1] >= v14 )
        goto LABEL_24;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013BE60
// ============================================================
//----- (1013BE60) --------------------------------------------------------
int __thiscall sub_1013BE60(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // esi
  int *i; // edi
  int v8; // [esp-8h] [ebp-14h]

  result = print_field(a2, a3, a4, "[count]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 0x28u )
    {
      v6 = 0;
      if ( *this )
      {
        for ( i = this + 1; ; i += 2 )
        {
          if ( !"[equips]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[equips]", v6, a4);
          if ( result )
            break;
          v8 = *i;
          result = a3 >= 0
                 ? print_field(a2, a3 + 1, a4, "[itemType]", "%d", v8)
                 : print_field(a2, a3, a4, "[itemType]", "%d", v8);
          if ( result )
            break;
          if ( (unsigned int)++v6 >= *this )
            return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013C760
// ============================================================
//----- (1013C760) --------------------------------------------------------
int __thiscall sub_1013C760(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // esi

  result = print_field(a2, a3, a4, "[attrSize]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 0x506 )
    {
      result = sub_1024A3B0(a2, a3, v6, "[attrs]", *this);
      if ( !result )
      {
        v7 = 0;
        if ( *this )
        {
          while ( 1 )
          {
            result = Printf(a2, " %d", *((unsigned __int8 *)this + v7 + 4));
            if ( result )
              break;
            if ( ++v7 >= *this )
              return TdrBuf::WriteChar(a2, a4);
          }
        }
        else
        {
          return TdrBuf::WriteChar(a2, a4);
        }
      }
    }
    else
    {
      return -7;
    }
  }
  return result;
}
// 1013C7AD: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013B3B0
// ============================================================
//----- (1013B3B0) --------------------------------------------------------
int __thiscall sub_1013B3B0(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 1) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 1) & 1) == 0 )
          *(this + 1) |= 1u;
        VarInt = TdrBuf::ReadVarInt(a2, this);
      }
      else
      {
        VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1013B430
// ============================================================
//----- (1013B430) --------------------------------------------------------
int __thiscall sub_1013B430(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_10:
    if ( a2[1] > v6 )
      return -34;
    return v5;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        break;
      if ( v9 >> 4 == 1 )
      {
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(_DWORD *)(this + 4) |= 1u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
      }
      else
      {
        Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_10;
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



