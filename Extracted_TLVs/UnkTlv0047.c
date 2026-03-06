// ============================================================
// Name: TLV::UnkTlv0047::Read_0xAA
// Address Name: SUB_10134AC0
// ============================================================
//----- (10134AC0) --------------------------------------------------------
int __thiscall sub_10134AC0(int this, size_t Size, int a3)
{
  int v3; // eax
  int Bytes; // edx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarULong; // eax
  size_t v10; // ebx
  size_t v11; // ebx
  int v12; // ebx
  size_t v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h] BYREF
  unsigned int v17; // [esp+18h] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v17 = 0;
  v6 = (_DWORD *)Size;
  *(_QWORD *)(this + 534735) = 0;
  *(_DWORD *)(this + 534743) = 0;
  v7 = v6[1] + v3;
  v14 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_267:
    if ( v6[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 534735) & 1) == 0 )
          *(_DWORD *)(this + 534735) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)this);
        goto LABEL_265;
      case 3u:
        if ( (*(_DWORD *)(this + 534735) & 2) == 0 )
          *(_DWORD *)(this + 534735) |= 2u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 8));
        goto LABEL_265;
      case 4u:
        if ( (*(_DWORD *)(this + 534735) & 4) == 0 )
          *(_DWORD *)(this + 534735) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 12), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + v10 + 12) = 0;
        goto LABEL_266;
      case 5u:
        if ( (*(_DWORD *)(this + 534735) & 8) == 0 )
          *(_DWORD *)(this + 534735) |= 8u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 44));
        goto LABEL_265;
      case 6u:
        if ( (*(_DWORD *)(this + 534735) & 0x10) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        v11 = Size;
        if ( Size >= 0x1F4 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 48), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + v11 + 48) = 0;
          goto LABEL_266;
        }
        return Bytes;
      case 7u:
        if ( (*(_DWORD *)(this + 534735) & 0x20) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 548));
        goto LABEL_265;
      case 8u:
        if ( (*(_DWORD *)(this + 534735) & 0x40) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 552));
        goto LABEL_265;
      case 9u:
        if ( (*(_DWORD *)(this + 534735) & 0x80) == 0 )
          *(_DWORD *)(this + 534735) |= 0x80u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 556));
        goto LABEL_265;
      case 0xAu:
        if ( (*(_DWORD *)(this + 534735) & 0x100) == 0 )
          *(_DWORD *)(this + 534735) |= 0x100u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 560));
        goto LABEL_265;
      case 0xBu:
        if ( (*(_DWORD *)(this + 534735) & 0x200) == 0 )
          *(_DWORD *)(this + 534735) |= 0x200u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 564));
        goto LABEL_265;
      case 0xCu:
        if ( (*(_DWORD *)(this + 534735) & 0x400) == 0 )
          *(_DWORD *)(this + 534735) |= 0x400u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 568));
        goto LABEL_265;
      case 0xDu:
        if ( (*(_DWORD *)(this + 534735) & 0x800) == 0 )
          *(_DWORD *)(this + 534735) |= 0x800u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 572));
        goto LABEL_265;
      case 0xEu:
        if ( (*(_DWORD *)(this + 534735) & 0x1000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x1000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 576));
        goto LABEL_265;
      case 0xFu:
        if ( (*(_DWORD *)(this + 534735) & 0x2000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x2000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 580));
        goto LABEL_265;
      case 0x10u:
        if ( (*(_DWORD *)(this + 534735) & 0x4000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x4000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_1011F3B0((int *)(this + 588), v6, (int *)Size);
        goto LABEL_265;
      case 0x11u:
        if ( (*(_DWORD *)(this + 534735) & 0x8000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x8000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_101227B0((int *)(this + 4052), v6, (int *)Size);
        goto LABEL_265;
      case 0x12u:
        if ( (*(_DWORD *)(this + 534735) & 0x10000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_10124020((int *)(this + 163036), v6, (int *)Size);
        goto LABEL_265;
      case 0x13u:
        if ( (*(_DWORD *)(this + 534735) & 0x20000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221924));
        goto LABEL_265;
      case 0x14u:
        if ( (*(_DWORD *)(this + 534735) & 0x40000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40000u;
        VarULong = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221932));
        goto LABEL_265;
      case 0x15u:
        if ( (*(_DWORD *)(this + 534735) & 0x80000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x80000u;
        VarULong = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221933));
        goto LABEL_265;
      case 0x16u:
        if ( (*(_DWORD *)(this + 534735) & 0x100000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x100000u;
        VarULong = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221934));
        goto LABEL_265;
      case 0x17u:
        if ( (*(_DWORD *)(this + 534735) & 0x200000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x200000u;
        VarULong = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221935));
        goto LABEL_265;
      case 0x18u:
        if ( (*(_DWORD *)(this + 534735) & 0x400000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x400000u;
        VarULong = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221936));
        goto LABEL_265;
      case 0x19u:
        if ( (*(_DWORD *)(this + 534735) & 0x800000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x800000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 221937));
        goto LABEL_265;
      case 0x1Au:
        if ( (*(_DWORD *)(this + 534735) & 0x1000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x1000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221941));
        goto LABEL_265;
      case 0x1Bu:
        if ( (*(_DWORD *)(this + 534735) & 0x2000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x2000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221949));
        goto LABEL_265;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 534735) & 0x4000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x4000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221957));
        goto LABEL_265;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 534735) & 0x8000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x8000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221965));
        goto LABEL_265;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 534735) & 0x10000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 221973));
        goto LABEL_265;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 534735) & 0x20000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20000000u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 221981));
        goto LABEL_265;
      case 0x20u:
        if ( (*(_DWORD *)(this + 534735) & 0x40000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40000000u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 221985));
        goto LABEL_265;
      case 0x21u:
        if ( *(int *)(this + 534735) >= 0 )
          *(_DWORD *)(this + 534735) |= 0x80000000;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 221989));
        goto LABEL_265;
      case 0x22u:
        if ( (*(_BYTE *)(this + 534739) & 1) == 0 )
          *(_DWORD *)(this + 534739) |= 1u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 221993));
        goto LABEL_265;
      case 0x23u:
        if ( (*(_DWORD *)(this + 534739) & 2) == 0 )
          *(_DWORD *)(this + 534739) |= 2u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 221997));
        goto LABEL_265;
      case 0x24u:
        if ( (*(_DWORD *)(this + 534739) & 4) == 0 )
          *(_DWORD *)(this + 534739) |= 4u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222001));
        goto LABEL_265;
      case 0x25u:
        if ( (*(_DWORD *)(this + 534739) & 8) == 0 )
          *(_DWORD *)(this + 534739) |= 8u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222005));
        goto LABEL_265;
      case 0x26u:
        if ( (*(_DWORD *)(this + 534739) & 0x10) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222009));
        goto LABEL_265;
      case 0x27u:
        if ( (*(_DWORD *)(this + 534739) & 0x20) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222013));
        goto LABEL_265;
      case 0x28u:
        if ( (*(_DWORD *)(this + 534739) & 0x40) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222017));
        goto LABEL_265;
      case 0x29u:
        if ( (*(_DWORD *)(this + 534739) & 0x80) == 0 )
          *(_DWORD *)(this + 534739) |= 0x80u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222021));
        goto LABEL_265;
      case 0x2Au:
        if ( (*(_DWORD *)(this + 534739) & 0x100) == 0 )
          *(_DWORD *)(this + 534739) |= 0x100u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222025));
        goto LABEL_265;
      case 0x2Bu:
        if ( (*(_DWORD *)(this + 534739) & 0x200) == 0 )
          *(_DWORD *)(this + 534739) |= 0x200u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222029));
        goto LABEL_265;
      case 0x2Cu:
        if ( (*(_DWORD *)(this + 534739) & 0x400) == 0 )
          *(_DWORD *)(this + 534739) |= 0x400u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222033));
        goto LABEL_265;
      case 0x2Du:
        if ( (*(_DWORD *)(this + 534739) & 0x800) == 0 )
          *(_DWORD *)(this + 534739) |= 0x800u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222037));
        goto LABEL_265;
      case 0x2Eu:
        if ( (*(_DWORD *)(this + 534739) & 0x1000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x1000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222041));
        goto LABEL_265;
      case 0x2Fu:
        if ( (*(_DWORD *)(this + 534739) & 0x2000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x2000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222045));
        goto LABEL_265;
      case 0x30u:
        if ( (*(_DWORD *)(this + 534739) & 0x4000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x4000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222049));
        goto LABEL_265;
      case 0x31u:
        if ( (*(_DWORD *)(this + 534739) & 0x8000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x8000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 222053));
        goto LABEL_265;
      case 0x32u:
        if ( (*(_DWORD *)(this + 534739) & 0x10000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_101267A0(this + 222057, v6, Size);
        goto LABEL_265;
      case 0x33u:
        if ( (*(_DWORD *)(this + 534739) & 0x20000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_10128250((int *)(this + 232214), v6, Size);
        goto LABEL_265;
      case 0x34u:
        if ( (*(_DWORD *)(this + 534739) & 0x40000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 232922));
        goto LABEL_265;
      case 0x35u:
        if ( (*(_DWORD *)(this + 534739) & 0x80000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x80000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size )
        {
          v12 = 0;
          v15 = v6[1];
          a3 = this + 232926;
          while ( 1 )
          {
            v16 = 0;
            Bytes = TdrBuf::ReadInt32(v6, &v16);
            if ( Bytes )
              return Bytes;
            if ( v16 )
            {
              Bytes = sub_1012BFD0(a3, (size_t)v6, (_DWORD *)v16);
              if ( Bytes )
                return Bytes;
            }
            v13 = v6[1];
            if ( v13 > v15 + Size )
              break;
            if ( v13 == v15 + Size )
            {
              *(_DWORD *)(this + 232922) = v12 + 1;
LABEL_266:
              v7 = v14;
              if ( v6[1] >= v14 )
                goto LABEL_267;
              goto LABEL_2;
            }
            a3 += 269;
            if ( ++v12 >= 64 )
              goto LABEL_266;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 0x36u:
        if ( (*(_DWORD *)(this + 534739) & 0x100000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x100000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_10129750(this + 250142, v6, Size);
        goto LABEL_265;
      case 0x37u:
        if ( (*(_DWORD *)(this + 534739) & 0x200000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x200000u;
        VarULong = TdrBuf::ReadByte_2(v6, (_BYTE *)(this + 450256));
        goto LABEL_265;
      case 0x38u:
        if ( (*(_DWORD *)(this + 534739) & 0x400000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x400000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_1012A330((int *)(this + 450257), v6, Size);
        goto LABEL_265;
      case 0x39u:
        if ( (*(_DWORD *)(this + 534739) & 0x800000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x800000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_1012AB70((int *)(this + 450385), v6, Size);
        goto LABEL_265;
      case 0x3Au:
        if ( (*(_DWORD *)(this + 534739) & 0x1000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x1000000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450405));
        goto LABEL_265;
      case 0x3Bu:
        if ( (*(_DWORD *)(this + 534739) & 0x2000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x2000000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450409));
        goto LABEL_265;
      case 0x3Cu:
        if ( (*(_DWORD *)(this + 534739) & 0x4000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x4000000u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 450413));
        goto LABEL_265;
      case 0x3Du:
        if ( (*(_DWORD *)(this + 534739) & 0x8000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x8000000u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 450417));
        goto LABEL_265;
      case 0x3Eu:
        if ( (*(_DWORD *)(this + 534739) & 0x10000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10000000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450425));
        goto LABEL_265;
      case 0x3Fu:
        if ( (*(_DWORD *)(this + 534739) & 0x20000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20000000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450429));
        goto LABEL_265;
      case 0x40u:
        if ( (*(_DWORD *)(this + 534739) & 0x40000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40000000u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450433));
        goto LABEL_265;
      case 0x41u:
        if ( *(int *)(this + 534739) >= 0 )
          *(_DWORD *)(this + 534739) |= 0x80000000;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450437));
        goto LABEL_265;
      case 0x42u:
        if ( (*(_BYTE *)(this + 534743) & 1) == 0 )
          *(_DWORD *)(this + 534743) |= 1u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450441));
        goto LABEL_265;
      case 0x43u:
        if ( (*(_DWORD *)(this + 534743) & 2) == 0 )
          *(_DWORD *)(this + 534743) |= 2u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450445));
        goto LABEL_265;
      case 0x44u:
        if ( (*(_DWORD *)(this + 534743) & 4) == 0 )
          *(_DWORD *)(this + 534743) |= 4u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450449));
        goto LABEL_265;
      case 0x45u:
        if ( (*(_DWORD *)(this + 534743) & 8) == 0 )
          *(_DWORD *)(this + 534743) |= 8u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 450453));
        goto LABEL_265;
      case 0x46u:
        if ( (*(_DWORD *)(this + 534743) & 0x10) == 0 )
          *(_DWORD *)(this + 534743) |= 0x10u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 450457));
        goto LABEL_265;
      case 0x47u:
        if ( (*(_DWORD *)(this + 534743) & 0x20) == 0 )
          *(_DWORD *)(this + 534743) |= 0x20u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 450461));
        goto LABEL_265;
      case 0x48u:
        if ( (*(_DWORD *)(this + 534743) & 0x40) == 0 )
          *(_DWORD *)(this + 534743) |= 0x40u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(this + 450465));
        goto LABEL_265;
      case 0x49u:
        if ( (*(_DWORD *)(this + 534743) & 0x80) == 0 )
          *(_DWORD *)(this + 534743) |= 0x80u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_1012FF50((int *)(this + 450469), v6, (int *)Size);
        goto LABEL_265;
      case 0x4Au:
        if ( (*(_DWORD *)(this + 534743) & 0x100) == 0 )
          *(_DWORD *)(this + 534743) |= 0x100u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_10131860((int *)(this + 450719), v6, (int *)Size);
        goto LABEL_265;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 534743) & 0x200) == 0 )
          *(_DWORD *)(this + 534743) |= 0x200u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        VarULong = sub_10132240((int *)(this + 492727), v6, (int *)Size);
LABEL_265:
        Bytes = VarULong;
        if ( !VarULong )
          goto LABEL_266;
        return Bytes;
      default:
        VarULong = TdrBuf::SkipField(v6, v17 & 0xF);
        goto LABEL_265;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0047::Read_0x99
// Address Name: SUB_10135C20
// ============================================================
//----- (10135C20) --------------------------------------------------------
int __thiscall sub_10135C20(int this, size_t Size, int a3)
{
  int v3; // eax
  int Bytes; // edx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  size_t v10; // ebx
  size_t v11; // ebx
  int v12; // ebx
  size_t v13; // ecx
  unsigned int v14; // [esp+Ch] [ebp-10h]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h] BYREF
  unsigned int v17; // [esp+18h] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v17 = 0;
  v6 = (_DWORD *)Size;
  *(_QWORD *)(this + 534735) = 0;
  *(_DWORD *)(this + 534743) = 0;
  v7 = v6[1] + v3;
  v14 = v7;
  if ( v6[1] >= v7 )
  {
LABEL_267:
    if ( v6[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
LABEL_2:
    result = TdrBuf::ReadVarUInt(v6, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 2u:
        if ( (*(_BYTE *)(this + 534735) & 1) == 0 )
          *(_DWORD *)(this + 534735) |= 1u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)this);
        goto LABEL_265;
      case 3u:
        if ( (*(_DWORD *)(this + 534735) & 2) == 0 )
          *(_DWORD *)(this + 534735) |= 2u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 8));
        goto LABEL_265;
      case 4u:
        if ( (*(_DWORD *)(this + 534735) & 4) == 0 )
          *(_DWORD *)(this + 534735) |= 4u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        v10 = Size;
        if ( Size >= 0x20 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 12), Size);
        if ( Bytes )
          return Bytes;
        *(_BYTE *)(this + v10 + 12) = 0;
        goto LABEL_266;
      case 5u:
        if ( (*(_DWORD *)(this + 534735) & 8) == 0 )
          *(_DWORD *)(this + 534735) |= 8u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 44));
        goto LABEL_265;
      case 6u:
        if ( (*(_DWORD *)(this + 534735) & 0x10) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        v11 = Size;
        if ( Size >= 0x1F4 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 48), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(this + v11 + 48) = 0;
          goto LABEL_266;
        }
        return Bytes;
      case 7u:
        if ( (*(_DWORD *)(this + 534735) & 0x20) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 548));
        goto LABEL_265;
      case 8u:
        if ( (*(_DWORD *)(this + 534735) & 0x40) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 552));
        goto LABEL_265;
      case 9u:
        if ( (*(_DWORD *)(this + 534735) & 0x80) == 0 )
          *(_DWORD *)(this + 534735) |= 0x80u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 556));
        goto LABEL_265;
      case 0xAu:
        if ( (*(_DWORD *)(this + 534735) & 0x100) == 0 )
          *(_DWORD *)(this + 534735) |= 0x100u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 560));
        goto LABEL_265;
      case 0xBu:
        if ( (*(_DWORD *)(this + 534735) & 0x200) == 0 )
          *(_DWORD *)(this + 534735) |= 0x200u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 564));
        goto LABEL_265;
      case 0xCu:
        if ( (*(_DWORD *)(this + 534735) & 0x400) == 0 )
          *(_DWORD *)(this + 534735) |= 0x400u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 568));
        goto LABEL_265;
      case 0xDu:
        if ( (*(_DWORD *)(this + 534735) & 0x800) == 0 )
          *(_DWORD *)(this + 534735) |= 0x800u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 572));
        goto LABEL_265;
      case 0xEu:
        if ( (*(_DWORD *)(this + 534735) & 0x1000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x1000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 576));
        goto LABEL_265;
      case 0xFu:
        if ( (*(_DWORD *)(this + 534735) & 0x2000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x2000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 580));
        goto LABEL_265;
      case 0x10u:
        if ( (*(_DWORD *)(this + 534735) & 0x4000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x4000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_1011F520((_DWORD *)(this + 588), v6, (_DWORD *)Size);
        goto LABEL_265;
      case 0x11u:
        if ( (*(_DWORD *)(this + 534735) & 0x8000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x8000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_10122920((_DWORD *)(this + 4052), v6, (char *)Size);
        goto LABEL_265;
      case 0x12u:
        if ( (*(_DWORD *)(this + 534735) & 0x10000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_10124190((_DWORD *)(this + 163036), v6, (_DWORD *)Size);
        goto LABEL_265;
      case 0x13u:
        if ( (*(_DWORD *)(this + 534735) & 0x20000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221924));
        goto LABEL_265;
      case 0x14u:
        if ( (*(_DWORD *)(this + 534735) & 0x40000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40000u;
        Int64 = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221932));
        goto LABEL_265;
      case 0x15u:
        if ( (*(_DWORD *)(this + 534735) & 0x80000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x80000u;
        Int64 = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221933));
        goto LABEL_265;
      case 0x16u:
        if ( (*(_DWORD *)(this + 534735) & 0x100000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x100000u;
        Int64 = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221934));
        goto LABEL_265;
      case 0x17u:
        if ( (*(_DWORD *)(this + 534735) & 0x200000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x200000u;
        Int64 = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221935));
        goto LABEL_265;
      case 0x18u:
        if ( (*(_DWORD *)(this + 534735) & 0x400000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x400000u;
        Int64 = TdrBuf::ReadByte(v6, (_BYTE *)(this + 221936));
        goto LABEL_265;
      case 0x19u:
        if ( (*(_DWORD *)(this + 534735) & 0x800000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x800000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221937));
        goto LABEL_265;
      case 0x1Au:
        if ( (*(_DWORD *)(this + 534735) & 0x1000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x1000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221941));
        goto LABEL_265;
      case 0x1Bu:
        if ( (*(_DWORD *)(this + 534735) & 0x2000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x2000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221949));
        goto LABEL_265;
      case 0x1Cu:
        if ( (*(_DWORD *)(this + 534735) & 0x4000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x4000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221957));
        goto LABEL_265;
      case 0x1Du:
        if ( (*(_DWORD *)(this + 534735) & 0x8000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x8000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221965));
        goto LABEL_265;
      case 0x1Eu:
        if ( (*(_DWORD *)(this + 534735) & 0x10000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x10000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 221973));
        goto LABEL_265;
      case 0x1Fu:
        if ( (*(_DWORD *)(this + 534735) & 0x20000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x20000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221981));
        goto LABEL_265;
      case 0x20u:
        if ( (*(_DWORD *)(this + 534735) & 0x40000000) == 0 )
          *(_DWORD *)(this + 534735) |= 0x40000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221985));
        goto LABEL_265;
      case 0x21u:
        if ( *(int *)(this + 534735) >= 0 )
          *(_DWORD *)(this + 534735) |= 0x80000000;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221989));
        goto LABEL_265;
      case 0x22u:
        if ( (*(_BYTE *)(this + 534739) & 1) == 0 )
          *(_DWORD *)(this + 534739) |= 1u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221993));
        goto LABEL_265;
      case 0x23u:
        if ( (*(_DWORD *)(this + 534739) & 2) == 0 )
          *(_DWORD *)(this + 534739) |= 2u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 221997));
        goto LABEL_265;
      case 0x24u:
        if ( (*(_DWORD *)(this + 534739) & 4) == 0 )
          *(_DWORD *)(this + 534739) |= 4u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222001));
        goto LABEL_265;
      case 0x25u:
        if ( (*(_DWORD *)(this + 534739) & 8) == 0 )
          *(_DWORD *)(this + 534739) |= 8u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222005));
        goto LABEL_265;
      case 0x26u:
        if ( (*(_DWORD *)(this + 534739) & 0x10) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222009));
        goto LABEL_265;
      case 0x27u:
        if ( (*(_DWORD *)(this + 534739) & 0x20) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222013));
        goto LABEL_265;
      case 0x28u:
        if ( (*(_DWORD *)(this + 534739) & 0x40) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222017));
        goto LABEL_265;
      case 0x29u:
        if ( (*(_DWORD *)(this + 534739) & 0x80) == 0 )
          *(_DWORD *)(this + 534739) |= 0x80u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222021));
        goto LABEL_265;
      case 0x2Au:
        if ( (*(_DWORD *)(this + 534739) & 0x100) == 0 )
          *(_DWORD *)(this + 534739) |= 0x100u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222025));
        goto LABEL_265;
      case 0x2Bu:
        if ( (*(_DWORD *)(this + 534739) & 0x200) == 0 )
          *(_DWORD *)(this + 534739) |= 0x200u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222029));
        goto LABEL_265;
      case 0x2Cu:
        if ( (*(_DWORD *)(this + 534739) & 0x400) == 0 )
          *(_DWORD *)(this + 534739) |= 0x400u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222033));
        goto LABEL_265;
      case 0x2Du:
        if ( (*(_DWORD *)(this + 534739) & 0x800) == 0 )
          *(_DWORD *)(this + 534739) |= 0x800u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222037));
        goto LABEL_265;
      case 0x2Eu:
        if ( (*(_DWORD *)(this + 534739) & 0x1000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x1000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222041));
        goto LABEL_265;
      case 0x2Fu:
        if ( (*(_DWORD *)(this + 534739) & 0x2000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x2000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222045));
        goto LABEL_265;
      case 0x30u:
        if ( (*(_DWORD *)(this + 534739) & 0x4000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x4000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222049));
        goto LABEL_265;
      case 0x31u:
        if ( (*(_DWORD *)(this + 534739) & 0x8000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x8000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 222053));
        goto LABEL_265;
      case 0x32u:
        if ( (*(_DWORD *)(this + 534739) & 0x10000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_10126D00(this + 222057, v6, Size);
        goto LABEL_265;
      case 0x33u:
        if ( (*(_DWORD *)(this + 534739) & 0x20000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_101283C0((_DWORD *)(this + 232214), v6, (char *)Size);
        goto LABEL_265;
      case 0x34u:
        if ( (*(_DWORD *)(this + 534739) & 0x40000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 232922));
        goto LABEL_265;
      case 0x35u:
        if ( (*(_DWORD *)(this + 534739) & 0x80000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x80000u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size )
        {
          v12 = 0;
          v15 = v6[1];
          a3 = this + 232926;
          while ( 1 )
          {
            v16 = 0;
            Bytes = TdrBuf::ReadInt32(v6, &v16);
            if ( Bytes )
              return Bytes;
            if ( v16 )
            {
              Bytes = sub_1012C300(a3, (size_t)v6, v16);
              if ( Bytes )
                return Bytes;
            }
            v13 = v6[1];
            if ( v13 > v15 + Size )
              break;
            if ( v13 == v15 + Size )
            {
              *(_DWORD *)(this + 232922) = v12 + 1;
LABEL_266:
              v7 = v14;
              if ( v6[1] >= v14 )
                goto LABEL_267;
              goto LABEL_2;
            }
            a3 += 269;
            if ( ++v12 >= 64 )
              goto LABEL_266;
          }
          result = -34;
        }
        else
        {
          result = -37;
        }
        break;
      case 0x36u:
        if ( (*(_DWORD *)(this + 534739) & 0x100000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x100000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_101299D0(this + 250142, v6, Size);
        goto LABEL_265;
      case 0x37u:
        if ( (*(_DWORD *)(this + 534739) & 0x200000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x200000u;
        Int64 = TdrBuf::ReadByte_2(v6, (_BYTE *)(this + 450256));
        goto LABEL_265;
      case 0x38u:
        if ( (*(_DWORD *)(this + 534739) & 0x400000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x400000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_1012A460((_DWORD *)(this + 450257), v6, Size);
        goto LABEL_265;
      case 0x39u:
        if ( (*(_DWORD *)(this + 534739) & 0x800000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x800000u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_1012ACA0((_DWORD *)(this + 450385), v6, Size);
        goto LABEL_265;
      case 0x3Au:
        if ( (*(_DWORD *)(this + 534739) & 0x1000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x1000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450405));
        goto LABEL_265;
      case 0x3Bu:
        if ( (*(_DWORD *)(this + 534739) & 0x2000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x2000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450409));
        goto LABEL_265;
      case 0x3Cu:
        if ( (*(_DWORD *)(this + 534739) & 0x4000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x4000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450413));
        goto LABEL_265;
      case 0x3Du:
        if ( (*(_DWORD *)(this + 534739) & 0x8000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x8000000u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 450417));
        goto LABEL_265;
      case 0x3Eu:
        if ( (*(_DWORD *)(this + 534739) & 0x10000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x10000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450425));
        goto LABEL_265;
      case 0x3Fu:
        if ( (*(_DWORD *)(this + 534739) & 0x20000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x20000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450429));
        goto LABEL_265;
      case 0x40u:
        if ( (*(_DWORD *)(this + 534739) & 0x40000000) == 0 )
          *(_DWORD *)(this + 534739) |= 0x40000000u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450433));
        goto LABEL_265;
      case 0x41u:
        if ( *(int *)(this + 534739) >= 0 )
          *(_DWORD *)(this + 534739) |= 0x80000000;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450437));
        goto LABEL_265;
      case 0x42u:
        if ( (*(_BYTE *)(this + 534743) & 1) == 0 )
          *(_DWORD *)(this + 534743) |= 1u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450441));
        goto LABEL_265;
      case 0x43u:
        if ( (*(_DWORD *)(this + 534743) & 2) == 0 )
          *(_DWORD *)(this + 534743) |= 2u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450445));
        goto LABEL_265;
      case 0x44u:
        if ( (*(_DWORD *)(this + 534743) & 4) == 0 )
          *(_DWORD *)(this + 534743) |= 4u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450449));
        goto LABEL_265;
      case 0x45u:
        if ( (*(_DWORD *)(this + 534743) & 8) == 0 )
          *(_DWORD *)(this + 534743) |= 8u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450453));
        goto LABEL_265;
      case 0x46u:
        if ( (*(_DWORD *)(this + 534743) & 0x10) == 0 )
          *(_DWORD *)(this + 534743) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450457));
        goto LABEL_265;
      case 0x47u:
        if ( (*(_DWORD *)(this + 534743) & 0x20) == 0 )
          *(_DWORD *)(this + 534743) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450461));
        goto LABEL_265;
      case 0x48u:
        if ( (*(_DWORD *)(this + 534743) & 0x40) == 0 )
          *(_DWORD *)(this + 534743) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450465));
        goto LABEL_265;
      case 0x49u:
        if ( (*(_DWORD *)(this + 534743) & 0x80) == 0 )
          *(_DWORD *)(this + 534743) |= 0x80u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_10130220((_DWORD *)(this + 450469), v6, Size);
        goto LABEL_265;
      case 0x4Au:
        if ( (*(_DWORD *)(this + 534743) & 0x100) == 0 )
          *(_DWORD *)(this + 534743) |= 0x100u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_101319D0((_DWORD *)(this + 450719), v6, (_DWORD *)Size);
        goto LABEL_265;
      case 0x4Bu:
        if ( (*(_DWORD *)(this + 534743) & 0x200) == 0 )
          *(_DWORD *)(this + 534743) |= 0x200u;
        Size = 0;
        Bytes = TdrBuf::ReadInt32(v6, &Size);
        if ( Bytes )
          return Bytes;
        if ( !Size )
          goto LABEL_266;
        Int64 = sub_101323B0((_DWORD *)(this + 492727), v6, (_DWORD *)Size);
LABEL_265:
        Bytes = Int64;
        if ( !Int64 )
          goto LABEL_266;
        return Bytes;
      default:
        Int64 = TdrBuf::SkipField(v6, v17 & 0xF);
        goto LABEL_265;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0047::DoDebugFormat
// Address Name: SUB_10136DA0
// ============================================================
//----- (10136DA0) --------------------------------------------------------
int __thiscall sub_10136DA0(char *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_10136E50(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0047::DebugFormat
// Address Name: SUB_10136E50
// ============================================================
//----- (10136E50) --------------------------------------------------------
int __thiscall sub_10136E50(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v7; // ecx
  int *v8; // ecx
  _DWORD *v9; // ecx
  char *v10; // ecx
  _DWORD *v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned __int8 *v14; // ecx
  int *v15; // ecx
  int *v16; // ecx
  int *v17; // ecx
  _DWORD *v18; // ecx
  _DWORD *v19; // ecx
  int v21; // [esp+1Ch] [ebp+Ch]
  char *v22; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[id]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[seed]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[name]", this + 12);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[icon]", "%d", *((_DWORD *)this + 11));
        if ( !result )
        {
          result = sub_1024A410(a2, a3, a4, "[note]", this + 48);
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[level]", "%d", *((_DWORD *)this + 137));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[exp]", "%d", *((_DWORD *)this + 138));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[repute]", "%d", *((_DWORD *)this + 139));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[fund]", "%d", *((_DWORD *)this + 140));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[arena]", "%d", *((_DWORD *)this + 141));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[resA]", "%d", *((_DWORD *)this + 142));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[resB]", "%d", *((_DWORD *)this + 143));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[joinLevel]", "%d", *((_DWORD *)this + 144));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[leader]", "%I64u", *(_QWORD *)(this + 580));
                            if ( !result )
                            {
                              result = print_structure((int)a2, a3, a4, (int)"[titles]");
                              if ( !result )
                              {
                                v7 = this + 588;
                                result = a3 >= 0 ? sub_1011F760(v7, a2, a3 + 1, a4) : sub_1011F760(v7, a2, a3, a4);
                                if ( !result )
                                {
                                  result = print_structure((int)a2, a3, a4, (int)"[guilders]");
                                  if ( !result )
                                  {
                                    v8 = (int *)(this + 4052);
                                    result = a3 >= 0 ? sub_10122B60(v8, a2, a3 + 1, a4) : sub_10122B60(v8, a2, a3, a4);
                                    if ( !result )
                                    {
                                      result = print_structure((int)a2, a3, a4, (int)"[applys]");
                                      if ( !result )
                                      {
                                        v9 = this + 163036;
                                        result = a3 >= 0
                                               ? sub_101243D0(v9, a2, a3 + 1, a4)
                                               : sub_101243D0(v9, a2, a3, a4);
                                        if ( !result )
                                        {
                                          result = print_field(
                                                     a2,
                                                     a3,
                                                     a4,
                                                     "[fundMax]",
                                                     "%I64u",
                                                     *(_QWORD *)(this + 221924));
                                          if ( !result )
                                          {
                                            result = print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[hallLevel]",
                                                       "%d",
                                                       (unsigned __int8)*(this + 221932));
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[recruitingLevel]",
                                                         "%d",
                                                         (unsigned __int8)*(this + 221933));
                                              if ( !result )
                                              {
                                                result = print_field(
                                                           a2,
                                                           a3,
                                                           a4,
                                                           "[resourcingLevel]",
                                                           "%d",
                                                           (unsigned __int8)*(this + 221934));
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[tradingLevel]",
                                                             "%d",
                                                             (unsigned __int8)*(this + 221935));
                                                  if ( !result )
                                                  {
                                                    result = print_field(
                                                               a2,
                                                               a3,
                                                               a4,
                                                               "[trainingLevel]",
                                                               "%d",
                                                               (unsigned __int8)*(this + 221936));
                                                    if ( !result )
                                                    {
                                                      result = print_field(
                                                                 a2,
                                                                 a3,
                                                                 a4,
                                                                 "[guilderCountMax]",
                                                                 "%d",
                                                                 *(_DWORD *)(this + 221937));
                                                      if ( !result )
                                                      {
                                                        result = print_field(
                                                                   a2,
                                                                   a3,
                                                                   a4,
                                                                   "[fundDaily]",
                                                                   "%I64u",
                                                                   *(_QWORD *)(this + 221941));
                                                        if ( !result )
                                                        {
                                                          result = print_field(
                                                                     a2,
                                                                     a3,
                                                                     a4,
                                                                     "[fundWeekly]",
                                                                     "%I64u",
                                                                     *(_QWORD *)(this + 221949));
                                                          if ( !result )
                                                          {
                                                            result = print_field(
                                                                       a2,
                                                                       a3,
                                                                       a4,
                                                                       "[commodityUnlock1]",
                                                                       "%I64u",
                                                                       *(_QWORD *)(this + 221957));
                                                            if ( !result )
                                                            {
                                                              result = print_field(
                                                                         a2,
                                                                         a3,
                                                                         a4,
                                                                         "[commodityUnlock2]",
                                                                         "%I64u",
                                                                         *(_QWORD *)(this + 221965));
                                                              if ( !result )
                                                              {
                                                                result = print_field(
                                                                           a2,
                                                                           a3,
                                                                           a4,
                                                                           "[commodityUnlock3]",
                                                                           "%I64u",
                                                                           *(_QWORD *)(this + 221973));
                                                                if ( !result )
                                                                {
                                                                  result = print_field(
                                                                             a2,
                                                                             a3,
                                                                             a4,
                                                                             "[fundDailyTime]",
                                                                             "%u",
                                                                             *(_DWORD *)(this + 221981));
                                                                  if ( !result )
                                                                  {
                                                                    result = print_field(
                                                                               a2,
                                                                               a3,
                                                                               a4,
                                                                               "[fundWeeklyTime]",
                                                                               "%u",
                                                                               *(_DWORD *)(this + 221985));
                                                                    if ( !result )
                                                                    {
                                                                      result = print_field(
                                                                                 a2,
                                                                                 a3,
                                                                                 a4,
                                                                                 "[resC]",
                                                                                 "%d",
                                                                                 *(_DWORD *)(this + 221989));
                                                                      if ( !result )
                                                                      {
                                                                        result = print_field(
                                                                                   a2,
                                                                                   a3,
                                                                                   a4,
                                                                                   "[resD]",
                                                                                   "%d",
                                                                                   *(_DWORD *)(this + 221993));
                                                                        if ( !result )
                                                                        {
                                                                          result = print_field(
                                                                                     a2,
                                                                                     a3,
                                                                                     a4,
                                                                                     "[resADaily]",
                                                                                     "%d",
                                                                                     *(_DWORD *)(this + 221997));
                                                                          if ( !result )
                                                                          {
                                                                            result = print_field(
                                                                                       a2,
                                                                                       a3,
                                                                                       a4,
                                                                                       "[resBDaily]",
                                                                                       "%d",
                                                                                       *(_DWORD *)(this + 222001));
                                                                            if ( !result )
                                                                            {
                                                                              result = print_field(
                                                                                         a2,
                                                                                         a3,
                                                                                         a4,
                                                                                         "[resCDaily]",
                                                                                         "%d",
                                                                                         *(_DWORD *)(this + 222005));
                                                                              if ( !result )
                                                                              {
                                                                                result = print_field(
                                                                                           a2,
                                                                                           a3,
                                                                                           a4,
                                                                                           "[resDDaily]",
                                                                                           "%d",
                                                                                           *(_DWORD *)(this + 222009));
                                                                                if ( !result )
                                                                                {
                                                                                  result = print_field(
                                                                                             a2,
                                                                                             a3,
                                                                                             a4,
                                                                                             "[resAWeekly]",
                                                                                             "%d",
                                                                                             *(_DWORD *)(this + 222013));
                                                                                  if ( !result )
                                                                                  {
                                                                                    result = print_field(
                                                                                               a2,
                                                                                               a3,
                                                                                               a4,
                                                                                               "[resBWeekly]",
                                                                                               "%d",
                                                                                               *(_DWORD *)(this + 222017));
                                                                                    if ( !result )
                                                                                    {
                                                                                      result = print_field(
                                                                                                 a2,
                                                                                                 a3,
                                                                                                 a4,
                                                                                                 "[resCWeekly]",
                                                                                                 "%d",
                                                                                                 *(_DWORD *)(this + 222021));
                                                                                      if ( !result )
                                                                                      {
                                                                                        result = print_field(
                                                                                                   a2,
                                                                                                   a3,
                                                                                                   a4,
                                                                                                   "[resDWeekly]",
                                                                                                   "%d",
                                                                                                   *(_DWORD *)(this + 222025));
                                                                                        if ( !result )
                                                                                        {
                                                                                          result = print_field(
                                                                                                     a2,
                                                                                                     a3,
                                                                                                     a4,
                                                                                                     "[resAMax]",
                                                                                                     "%d",
                                                                                                     *(_DWORD *)(this + 222029));
                                                                                          if ( !result )
                                                                                          {
                                                                                            result = print_field(a2, a3, a4, "[resBMax]", "%d", *(_DWORD *)(this + 222033));
                                                                                            if ( !result )
                                                                                            {
                                                                                              result = print_field(a2, a3, a4, "[resCMax]", "%d", *(_DWORD *)(this + 222037));
                                                                                              if ( !result )
                                                                                              {
                                                                                                result = print_field(a2, a3, a4, "[resDMax]", "%d", *(_DWORD *)(this + 222041));
                                                                                                if ( !result )
                                                                                                {
                                                                                                  result = print_field(a2, a3, a4, "[addFundWithDay]", "%d", *(_DWORD *)(this + 222045));
                                                                                                  if ( !result )
                                                                                                  {
                                                                                                    result = print_field(a2, a3, a4, "[consumeFundWithDay]", "%d", *(_DWORD *)(this + 222049));
                                                                                                    if ( !result )
                                                                                                    {
                                                                                                      result = print_field(a2, a3, a4, "[plot]", "%d", *(_DWORD *)(this + 222053));
                                                                                                      if ( !result )
                                                                                                      {
                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[tasks]");
                                                                                                        if ( !result )
                                                                                                        {
                                                                                                          v10 = this + 222057;
                                                                                                          result = a3 >= 0 ? sub_10127330(v10, a2, a3 + 1, a4) : sub_10127330(v10, a2, a3, a4);
                                                                                                          if ( !result )
                                                                                                          {
                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[skills]");
                                                                                                            if ( !result )
                                                                                                            {
                                                                                                              v11 = this + 232214;
                                                                                                              result = a3 >= 0 ? sub_10128600(v11, a2, a3 + 1, a4) : sub_10128600(v11, a2, a3, a4);
                                                                                                              if ( !result )
                                                                                                              {
                                                                                                                result = print_field(a2, a3, a4, "[signUpCount]", "%d", *(_DWORD *)(this + 232922));
                                                                                                                if ( !result )
                                                                                                                {
                                                                                                                  v12 = *(_DWORD *)(this + 232922);
                                                                                                                  if ( v12 >= 0 )
                                                                                                                  {
                                                                                                                    if ( v12 <= 64 )
                                                                                                                    {
                                                                                                                      v13 = 0;
                                                                                                                      v21 = 0;
                                                                                                                      if ( v12 <= 0 )
                                                                                                                      {
LABEL_84:
                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[stores]");
                                                                                                                        if ( !result )
                                                                                                                        {
                                                                                                                          v14 = (unsigned __int8 *)(this + 250142);
                                                                                                                          result = a3 >= 0 ? sub_10129D20(v14, a2, a3 + 1, a4) : sub_10129D20(v14, a2, a3, a4);
                                                                                                                          if ( !result )
                                                                                                                          {
                                                                                                                            result = print_field(a2, a3, a4, "[depotOpenFlag]", "0x%02x", (unsigned __int8)*(this + 450256));
                                                                                                                            if ( !result )
                                                                                                                            {
                                                                                                                              result = print_structure((int)a2, a3, a4, (int)"[randCommodities]");
                                                                                                                              if ( !result )
                                                                                                                              {
                                                                                                                                v15 = (int *)(this + 450257);
                                                                                                                                result = a3 >= 0 ? sub_1012A660(v15, a2, a3 + 1, a4) : sub_1012A660(v15, a2, a3, a4);
                                                                                                                                if ( !result )
                                                                                                                                {
                                                                                                                                  result = print_structure((int)a2, a3, a4, (int)"[quest]");
                                                                                                                                  if ( !result )
                                                                                                                                  {
                                                                                                                                    v16 = (int *)(this + 450385);
                                                                                                                                    result = a3 >= 0 ? sub_1012AEA0(v16, a2, a3 + 1, a4) : sub_1012AEA0(v16, a2, a3, a4);
                                                                                                                                    if ( !result )
                                                                                                                                    {
                                                                                                                                      result = print_field(a2, a3, a4, "[questPrize]", "%d", *(_DWORD *)(this + 450405));
                                                                                                                                      if ( !result )
                                                                                                                                      {
                                                                                                                                        result = print_field(a2, a3, a4, "[contribution]", "%d", *(_DWORD *)(this + 450409));
                                                                                                                                        if ( !result )
                                                                                                                                        {
                                                                                                                                          result = print_field(a2, a3, a4, "[createTime]", "%u", *(_DWORD *)(this + 450413));
                                                                                                                                          if ( !result )
                                                                                                                                          {
                                                                                                                                            result = print_field(a2, a3, a4, "[huntSoul]", "%I64u", *(_QWORD *)(this + 450417));
                                                                                                                                            if ( !result )
                                                                                                                                            {
                                                                                                                                              result = print_field(a2, a3, a4, "[wildHuntCamp]", "%d", *(_DWORD *)(this + 450425));
                                                                                                                                              if ( !result )
                                                                                                                                              {
                                                                                                                                                result = print_field(a2, a3, a4, "[wildHuntPhase]", "%d", *(_DWORD *)(this + 450429));
                                                                                                                                                if ( !result )
                                                                                                                                                {
                                                                                                                                                  result = print_field(a2, a3, a4, "[celebrationTaskA]", "%d", *(_DWORD *)(this + 450433));
                                                                                                                                                  if ( !result )
                                                                                                                                                  {
                                                                                                                                                    result = print_field(a2, a3, a4, "[celebrationTaskB]", "%d", *(_DWORD *)(this + 450437));
                                                                                                                                                    if ( !result )
                                                                                                                                                    {
                                                                                                                                                      result = print_field(a2, a3, a4, "[celebrationTaskC]", "%d", *(_DWORD *)(this + 450441));
                                                                                                                                                      if ( !result )
                                                                                                                                                      {
                                                                                                                                                        result = print_field(a2, a3, a4, "[celebrationTaskD]", "%d", *(_DWORD *)(this + 450445));
                                                                                                                                                        if ( !result )
                                                                                                                                                        {
                                                                                                                                                          result = print_field(a2, a3, a4, "[celebrationScore]", "%d", *(_DWORD *)(this + 450449));
                                                                                                                                                          if ( !result )
                                                                                                                                                          {
                                                                                                                                                            result = print_field(a2, a3, a4, "[celebrationDailyUpdate]", "%u", *(_DWORD *)(this + 450453));
                                                                                                                                                            if ( !result )
                                                                                                                                                            {
                                                                                                                                                              result = print_field(a2, a3, a4, "[celebrationWeeklyScoreUpdate]", "%u", *(_DWORD *)(this + 450457));
                                                                                                                                                              if ( !result )
                                                                                                                                                              {
                                                                                                                                                                result = print_field(a2, a3, a4, "[celebrationDailyScore]", "%u", *(_DWORD *)(this + 450461));
                                                                                                                                                                if ( !result )
                                                                                                                                                                {
                                                                                                                                                                  result = print_field(a2, a3, a4, "[celebrationWeeklyRewardUpdate]", "%u", *(_DWORD *)(this + 450465));
                                                                                                                                                                  if ( !result )
                                                                                                                                                                  {
                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[guildWar]");
                                                                                                                                                                    if ( !result )
                                                                                                                                                                    {
                                                                                                                                                                      v17 = (int *)(this + 450469);
                                                                                                                                                                      result = a3 >= 0 ? sub_101305C0(v17, a2, a3 + 1, a4) : sub_101305C0(v17, a2, a3, a4);
                                                                                                                                                                      if ( !result )
                                                                                                                                                                      {
                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[guildOperateRecord]");
                                                                                                                                                                        if ( !result )
                                                                                                                                                                        {
                                                                                                                                                                          v18 = this + 450719;
                                                                                                                                                                          if ( a3 >= 0 )
                                                                                                                                                                            result = sub_10131C10(v18, a2, a3 + 1, a4);
                                                                                                                                                                          else
                                                                                                                                                                            result = sub_10131C10(v18, a2, a3, a4);
                                                                                                                                                                          if ( !result )
                                                                                                                                                                          {
                                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[guildBuyRecord]");
                                                                                                                                                                            if ( !result )
                                                                                                                                                                            {
                                                                                                                                                                              v19 = this + 492727;
                                                                                                                                                                              if ( a3 >= 0 )
                                                                                                                                                                                return sub_101325F0(v19, a2, a3 + 1, a4);
                                                                                                                                                                              else
                                                                                                                                                                                return sub_101325F0(v19, a2, a3, a4);
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
                                                                                                                        v22 = this + 232926;
                                                                                                                        while ( 1 )
                                                                                                                        {
                                                                                                                          result = sub_1024A230(a2, a3, a4, "[signUps]", v13);
                                                                                                                          if ( result )
                                                                                                                            break;
                                                                                                                          result = a3 >= 0 ? sub_1012C700(v22, a2, a3 + 1, a4) : sub_1012C700(v22, a2, a3, a4);
                                                                                                                          if ( result )
                                                                                                                            break;
                                                                                                                          v13 = v21 + 1;
                                                                                                                          v22 += 269;
                                                                                                                          v21 = v13;
                                                                                                                          if ( v13 >= *(_DWORD *)(this + 232922) )
                                                                                                                            goto LABEL_84;
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
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124020
// ============================================================
//----- (10124020) --------------------------------------------------------
int __thiscall sub_10124020(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 14721) = 0;
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
        if ( (v4[14721] & 1) == 0 )
          v4[14721] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[14721] & 2) == 0 )
            v4[14721] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10123390(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 115;
            if ( ++v10 >= 128 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_101267A0
// ============================================================
//----- (101267A0) --------------------------------------------------------
int __thiscall sub_101267A0(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
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
  int v14; // ebx
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // ecx
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h] BYREF
  int v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  int v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 10153) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_84;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 10153) & 1) == 0 )
          *(_DWORD *)(v3 + 10153) |= 1u;
        VarInt = sub_10115A30(a2, (_BYTE *)v3);
        goto LABEL_82;
      case 2u:
        if ( (*(_DWORD *)(v3 + 10153) & 2) == 0 )
          *(_DWORD *)(v3 + 10153) |= 2u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 1));
        goto LABEL_82;
      case 3u:
        if ( (*(_DWORD *)(v3 + 10153) & 4) == 0 )
          *(_DWORD *)(v3 + 10153) |= 4u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 5));
        goto LABEL_82;
      case 4u:
        if ( (*(_DWORD *)(v3 + 10153) & 8) == 0 )
          *(_DWORD *)(v3 + 10153) |= 8u;
        VarInt = TdrBuf::ReadVarUInt(a2, (_DWORD *)(v3 + 9));
        goto LABEL_82;
      case 5u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x10) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x10u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 13));
        goto LABEL_82;
      case 6u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x20) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x20u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 17));
        goto LABEL_82;
      case 7u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x40) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x40u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = this + 21;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124840(v22, a2, v24);
            if ( v4 )
              return v4;
          }
          v9 = a2[1];
          if ( v9 > v25 + v21 )
            return -34;
          if ( v9 == v25 + v21 )
            break;
          v22 += 7;
          if ( ++v8 >= 64 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *(_DWORD *)(this + 17) = v10;
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x80) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x80u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 469));
        goto LABEL_82;
      case 9u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x100) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x100u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = this + 473;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124F90(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v12 = a2[1];
          if ( v12 > v25 + v22 )
            return -34;
          if ( v12 == v25 + v22 )
            break;
          v21 += 9;
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(_DWORD *)(this + 469) = v13;
        goto LABEL_83;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x200) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x200u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 2777));
        goto LABEL_82;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x400) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x400u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v14 = 0;
        v25 = a2[1];
        while ( 1 )
        {
          v4 = sub_10115A30(a2, (_BYTE *)(v14 + this + 2781));
          if ( v4 )
            return v4;
          v15 = a2[1];
          if ( v15 > v25 + v22 )
            return -34;
          if ( v15 == v25 + v22 )
            break;
          if ( ++v14 >= 200 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(_DWORD *)(this + 2777) = v16;
        goto LABEL_83;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x800) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x800u;
        VarInt = TdrBuf::ReadVarInt(a2, (int *)(v3 + 2981));
        goto LABEL_82;
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x1000u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = this + 2985;
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_101257D0(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v18 = a2[1];
          if ( v18 > v25 + v22 )
            return -34;
          if ( v18 == v25 + v22 )
            break;
          v21 += 7;
          if ( ++v17 >= 1024 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(_DWORD *)(this + 2981) = v19;
LABEL_83:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_84:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        VarInt = TdrBuf::SkipField(a2, v23 & 0xF);
LABEL_82:
        v4 = VarInt;
        if ( !VarInt )
          goto LABEL_83;
        return v4;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10132240
// ============================================================
//----- (10132240) --------------------------------------------------------
int __thiscall sub_10132240(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 10501) = 0;
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
        if ( (v4[10501] & 1) == 0 )
          v4[10501] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10501] & 2) == 0 )
            v4[10501] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10130DE0(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 21;
            if ( ++v10 >= 500 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_1012AB70
// ============================================================
//----- (1012AB70) --------------------------------------------------------
int __thiscall sub_1012AB70(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // esi
  int *v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  int *v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v14 = this;
  *(this + 4) = 0;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(this + 4) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
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
            v5 = TdrBuf::ReadVarInt(v6, v11);
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
            ++v11;
            if ( v10 >= 3 )
            {
              this = v14;
              goto LABEL_21;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_1012BFD0
// ============================================================
//----- (1012BFD0) --------------------------------------------------------
int __thiscall sub_1012BFD0(int this, size_t Size, _DWORD *a3)
{
  _DWORD *v3; // eax
  int v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarULong; // eax
  int v10; // ebx
  size_t v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v17 = this;
  *(_DWORD *)(this + 265) = 0;
  v16 = 0;
  v7 = (char *)v3 + v6[1];
  v13 = v7;
  if ( v6[1] >= (unsigned int)v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 265) & 1) == 0 )
          *(_DWORD *)(v4 + 265) |= 1u;
        VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)v4);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v4 + 265) & 2) == 0 )
          *(_DWORD *)(v4 + 265) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x28 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(v4 + 8), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(v4 + Size + 8) = 0;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (*(_DWORD *)(v4 + 265) & 4) == 0 )
          *(_DWORD *)(v4 + 265) |= 4u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 48));
        goto LABEL_48;
      case 4u:
        if ( (*(_DWORD *)(v4 + 265) & 8) == 0 )
          *(_DWORD *)(v4 + 265) |= 8u;
        VarULong = TdrBuf::ReadVarUInt(v6, (_DWORD *)(v4 + 52));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v4 + 265) & 0x10) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x10u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(v4 + 265) & 0x20) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x20u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 60));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(v4 + 265) & 0x40) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x40u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 64));
        goto LABEL_48;
      case 8u:
        if ( (*(_DWORD *)(v4 + 265) & 0x80) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x80u;
        VarULong = TdrBuf::ReadVarInt(v6, (int *)(v4 + 68));
        goto LABEL_48;
      case 9u:
        if ( (*(_DWORD *)(v4 + 265) & 0x100) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x100u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = (_DWORD *)(v17 + 72);
        while ( 1 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1012B400(a3, (size_t)v6, v15);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          a3 += 12;
          if ( ++v10 >= 4 )
          {
            v4 = v17;
            goto LABEL_49;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        *(_DWORD *)(v17 + 68) = v12;
LABEL_49:
        v7 = v13;
        if ( v6[1] < (unsigned int)v13 )
          continue;
LABEL_50:
        if ( v6[1] > (unsigned int)v7 )
          return -34;
        return Bytes;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 265) & 0x200) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x200u;
        VarULong = sub_10115A30(v6, (_BYTE *)(v4 + 264));
        goto LABEL_48;
      default:
        VarULong = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_48:
        Bytes = VarULong;
        if ( !VarULong )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
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
// Name: Internal Helper Function
// Address Name: SUB_1011F3B0
// ============================================================
//----- (1011F3B0) --------------------------------------------------------
int __thiscall sub_1011F3B0(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 865) = 0;
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
        if ( (v4[865] & 1) == 0 )
          v4[865] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[865] & 2) == 0 )
            v4[865] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_1011E910(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 54;
            if ( ++v10 >= 16 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_10128250
// ============================================================
//----- (10128250) --------------------------------------------------------
int __thiscall sub_10128250(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 176) = 0;
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
        if ( (v4[176] & 1) == 0 )
          v4[176] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[176] & 2) == 0 )
            v4[176] |= 2u;
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
              v5 = sub_10127A20(a3, v6, v15);
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
            a3 += 7;
            if ( ++v10 >= 100 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_10131860
// ============================================================
//----- (10131860) --------------------------------------------------------
int __thiscall sub_10131860(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 10501) = 0;
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
        if ( (v4[10501] & 1) == 0 )
          v4[10501] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10501] & 2) == 0 )
            v4[10501] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10130DE0(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 21;
            if ( ++v10 >= 500 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_10129750
// ============================================================
//----- (10129750) --------------------------------------------------------
int __thiscall sub_10129750(int this, _DWORD *Size, int a3)
{
  int result; // eax
  int v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // [esp+10h] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-14h]
  unsigned int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h]
  unsigned int v18; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v15 = 0;
  v14 = this;
  *(_DWORD *)(this + 200110) = 0;
  v5 = Size[1] + a3;
  v18 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 200110) & 1) == 0 )
          *(_DWORD *)(v4 + 200110) |= 1u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 200110) & 2) == 0 )
          *(_DWORD *)(v4 + 200110) |= 2u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)(v4 + 1));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 200110) & 4) == 0 )
          *(_DWORD *)(v4 + 200110) |= 4u;
        v13 = 0;
        result = TdrBuf::ReadInt32(Size, &v13);
        if ( result )
          return result;
        if ( !v13 )
          return -37;
        v6 = 0;
        v17 = Size[1];
        while ( 2 )
        {
          v16 = 0;
          result = TdrBuf::ReadInt32(Size, &v16);
          if ( result )
            return result;
          if ( v16 )
          {
            result = sub_10128BA0((char *)(v4 + 13 * v6 + 2), (size_t)Size, v16);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v17 + v13 )
            return -34;
          if ( v7 != v17 + v13 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)(v4 + 1) = v6 + 1;
        goto LABEL_39;
      case 4u:
        if ( (*(_DWORD *)(v4 + 200110) & 8) == 0 )
          *(_DWORD *)(v4 + 200110) |= 8u;
        result = TdrBuf::ReadVarUInt(Size, (_DWORD *)(v4 + 106));
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(v4 + 200110) & 0x10) == 0 )
          *(_DWORD *)(v4 + 200110) |= 0x10u;
        v16 = 0;
        result = TdrBuf::ReadInt32(Size, &v16);
        if ( result )
          return result;
        v8 = v16;
        if ( !v16 )
          return -37;
        v9 = 0;
        v10 = v14 + 110;
        v17 = Size[1];
        v16 = v14 + 110;
        while ( 1 )
        {
          result = TdrBuf::ReadByte(Size, (_BYTE *)(v10 + v9));
          if ( result )
            return result;
          v11 = Size[1];
          if ( v11 > v8 + v17 )
            return -34;
          if ( v11 == v8 + v17 )
            break;
          v10 = v16;
          if ( (unsigned int)++v9 >= 0x30D40 )
          {
            v4 = v14;
            goto LABEL_39;
          }
        }
        v12 = v9 + 1;
        v4 = v14;
        *(_DWORD *)(v14 + 106) = v12;
LABEL_39:
        v5 = v18;
        if ( Size[1] < v18 )
          continue;
LABEL_40:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v15 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101227B0
// ============================================================
//----- (101227B0) --------------------------------------------------------
int __thiscall sub_101227B0(int *this, _DWORD *Size, int *a3)
{
  int *v3; // eax
  int *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 39745) = 0;
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
        if ( (v4[39745] & 1) == 0 )
          v4[39745] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[39745] & 2) == 0 )
            v4[39745] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10121050(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 = (int *)((char *)a3 + 621);
            if ( ++v10 >= 256 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_1012A330
// ============================================================
//----- (1012A330) --------------------------------------------------------
int __thiscall sub_1012A330(int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  int v10; // esi
  int *v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // [esp+Ch] [ebp-Ch]
  int *v14; // [esp+10h] [ebp-8h]
  unsigned int v15; // [esp+14h] [ebp-4h] BYREF

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v14 = this;
  *(this + 31) = 0;
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
        if ( (*(_BYTE *)(this + 31) & 1) == 0 )
          *(this + 31) |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 31) & 2) == 0 )
            *(this + 31) |= 2u;
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
            v5 = TdrBuf::ReadVarInt(v6, v11);
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
            ++v11;
            if ( v10 >= 30 )
            {
              this = v14;
              goto LABEL_21;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v15 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Name: Internal Helper Function
// Address Name: SUB_10124190
// ============================================================
//----- (10124190) --------------------------------------------------------
int __thiscall sub_10124190(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 14721) = 0;
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
        if ( (v4[14721] & 1) == 0 )
          v4[14721] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[14721] & 2) == 0 )
            v4[14721] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10123600((int)a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 115;
            if ( ++v10 >= 128 )
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
// Address Name: SUB_101299D0
// ============================================================
//----- (101299D0) --------------------------------------------------------
int __thiscall sub_101299D0(int this, _DWORD *Size, int a3)
{
  int result; // eax
  int v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 v6; // bl
  unsigned int v7; // edx
  int v8; // ebx
  int v9; // edi
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // [esp+10h] [ebp-18h] BYREF
  int v14; // [esp+14h] [ebp-14h]
  unsigned int v15; // [esp+18h] [ebp-10h] BYREF
  int v16; // [esp+1Ch] [ebp-Ch] BYREF
  int v17; // [esp+20h] [ebp-8h]
  unsigned int v18; // [esp+24h] [ebp-4h]

  result = 0;
  v4 = this;
  v15 = 0;
  v14 = this;
  *(_DWORD *)(this + 200110) = 0;
  v5 = Size[1] + a3;
  v18 = v5;
  if ( Size[1] >= v5 )
    goto LABEL_40;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(Size, &v15);
    if ( result )
      return result;
    switch ( v15 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 200110) & 1) == 0 )
          *(_DWORD *)(v4 + 200110) |= 1u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)v4);
        goto LABEL_38;
      case 2u:
        if ( (*(_DWORD *)(v4 + 200110) & 2) == 0 )
          *(_DWORD *)(v4 + 200110) |= 2u;
        result = TdrBuf::ReadByte_2(Size, (_BYTE *)(v4 + 1));
        goto LABEL_38;
      case 3u:
        if ( (*(_DWORD *)(v4 + 200110) & 4) == 0 )
          *(_DWORD *)(v4 + 200110) |= 4u;
        v13 = 0;
        result = TdrBuf::ReadInt32(Size, &v13);
        if ( result )
          return result;
        if ( !v13 )
          return -37;
        v6 = 0;
        v17 = Size[1];
        while ( 2 )
        {
          v16 = 0;
          result = TdrBuf::ReadInt32(Size, &v16);
          if ( result )
            return result;
          if ( v16 )
          {
            result = sub_10128D30((char *)(v4 + 13 * v6 + 2), (size_t)Size, v16);
            if ( result )
              return result;
          }
          v7 = Size[1];
          if ( v7 > v17 + v13 )
            return -34;
          if ( v7 != v17 + v13 )
          {
            if ( ++v6 >= 8u )
              goto LABEL_39;
            continue;
          }
          break;
        }
        *(_BYTE *)(v4 + 1) = v6 + 1;
        goto LABEL_39;
      case 4u:
        if ( (*(_DWORD *)(v4 + 200110) & 8) == 0 )
          *(_DWORD *)(v4 + 200110) |= 8u;
        result = TdrBuf::ReadInt32(Size, (_BYTE *)(v4 + 106));
        goto LABEL_38;
      case 5u:
        if ( (*(_DWORD *)(v4 + 200110) & 0x10) == 0 )
          *(_DWORD *)(v4 + 200110) |= 0x10u;
        v16 = 0;
        result = TdrBuf::ReadInt32(Size, &v16);
        if ( result )
          return result;
        v8 = v16;
        if ( !v16 )
          return -37;
        v9 = 0;
        v10 = v14 + 110;
        v17 = Size[1];
        v16 = v14 + 110;
        while ( 1 )
        {
          result = TdrBuf::ReadByte(Size, (_BYTE *)(v10 + v9));
          if ( result )
            return result;
          v11 = Size[1];
          if ( v11 > v8 + v17 )
            return -34;
          if ( v11 == v8 + v17 )
            break;
          v10 = v16;
          if ( (unsigned int)++v9 >= 0x30D40 )
          {
            v4 = v14;
            goto LABEL_39;
          }
        }
        v12 = v9 + 1;
        v4 = v14;
        *(_DWORD *)(v14 + 106) = v12;
LABEL_39:
        v5 = v18;
        if ( Size[1] < v18 )
          continue;
LABEL_40:
        if ( Size[1] > v5 )
          return -34;
        return result;
      default:
        result = TdrBuf::SkipField(Size, v15 & 0xF);
LABEL_38:
        if ( !result )
          goto LABEL_39;
        return result;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101319D0
// ============================================================
//----- (101319D0) --------------------------------------------------------
int __thiscall sub_101319D0(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 10501) = 0;
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
        if ( (v4[10501] & 1) == 0 )
          v4[10501] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10501] & 2) == 0 )
            v4[10501] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10130FB0((int)a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 21;
            if ( ++v10 >= 500 )
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
// Address Name: SUB_1012A460
// ============================================================
//----- (1012A460) --------------------------------------------------------
int __thiscall sub_1012A460(_DWORD *this, _DWORD *a2, int a3)
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
  *(this + 31) = 0;
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
        if ( (*(_BYTE *)(this + 31) & 1) == 0 )
          *(this + 31) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 31) & 2) == 0 )
            *(this + 31) |= 2u;
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
            if ( v10 >= 30 )
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
// Address Name: SUB_10126D00
// ============================================================
//----- (10126D00) --------------------------------------------------------
int __thiscall sub_10126D00(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  int Int32; // eax
  int v8; // ebx
  char *v9; // ecx
  int v10; // eax
  int v11; // ebx
  char *v12; // ecx
  int v13; // eax
  int v14; // ebx
  char *v15; // ecx
  int v16; // eax
  int v17; // ebx
  char *v18; // ecx
  int v19; // eax
  char *v21; // [esp+10h] [ebp-18h] BYREF
  char *v22; // [esp+14h] [ebp-14h] BYREF
  unsigned int v23; // [esp+18h] [ebp-10h] BYREF
  int v24; // [esp+1Ch] [ebp-Ch] BYREF
  int v25; // [esp+20h] [ebp-8h]
  unsigned int v26; // [esp+24h] [ebp-4h]

  v3 = this;
  v4 = 0;
  *(_DWORD *)(this + 10153) = 0;
  v23 = 0;
  v5 = a2[1] + a3;
  v26 = v5;
  if ( a2[1] >= v5 )
    goto LABEL_84;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v23);
    if ( result )
      return result;
    switch ( v23 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v3 + 10153) & 1) == 0 )
          *(_DWORD *)(v3 + 10153) |= 1u;
        Int32 = sub_10115A30(a2, (_BYTE *)v3);
        goto LABEL_82;
      case 2u:
        if ( (*(_DWORD *)(v3 + 10153) & 2) == 0 )
          *(_DWORD *)(v3 + 10153) |= 2u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 1));
        goto LABEL_82;
      case 3u:
        if ( (*(_DWORD *)(v3 + 10153) & 4) == 0 )
          *(_DWORD *)(v3 + 10153) |= 4u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 5));
        goto LABEL_82;
      case 4u:
        if ( (*(_DWORD *)(v3 + 10153) & 8) == 0 )
          *(_DWORD *)(v3 + 10153) |= 8u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 9));
        goto LABEL_82;
      case 5u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x10) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x10u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 13));
        goto LABEL_82;
      case 6u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x20) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x20u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 17));
        goto LABEL_82;
      case 7u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x40) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x40u;
        v21 = 0;
        result = TdrBuf::ReadInt32(a2, &v21);
        if ( result )
          return result;
        if ( !v21 )
          return -37;
        v8 = 0;
        v25 = a2[1];
        v22 = (char *)(this + 21);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10124930(v22, a2, v24);
            if ( v4 )
              return v4;
          }
          v9 = (char *)a2[1];
          if ( v9 > &v21[v25] )
            return -34;
          if ( v9 == &v21[v25] )
            break;
          v22 += 7;
          if ( ++v8 >= 64 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v10 = v8 + 1;
        v3 = this;
        *(_DWORD *)(this + 17) = v10;
        goto LABEL_83;
      case 8u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x80) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x80u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 469));
        goto LABEL_82;
      case 9u:
        if ( (*(_DWORD *)(v3 + 10153) & 0x100) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x100u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v11 = 0;
        v25 = a2[1];
        v21 = (char *)(this + 473);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_10125140((int)v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v12 = (char *)a2[1];
          if ( v12 > &v22[v25] )
            return -34;
          if ( v12 == &v22[v25] )
            break;
          v21 += 9;
          if ( ++v11 >= 256 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v13 = v11 + 1;
        v3 = this;
        *(_DWORD *)(this + 469) = v13;
        goto LABEL_83;
      case 0xAu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x200) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x200u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 2777));
        goto LABEL_82;
      case 0xBu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x400) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x400u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v14 = 0;
        v25 = a2[1];
        while ( 1 )
        {
          v4 = sub_10115A30(a2, (_BYTE *)(v14 + this + 2781));
          if ( v4 )
            return v4;
          v15 = (char *)a2[1];
          if ( v15 > &v22[v25] )
            return -34;
          if ( v15 == &v22[v25] )
            break;
          if ( ++v14 >= 200 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v16 = v14 + 1;
        v3 = this;
        *(_DWORD *)(this + 2777) = v16;
        goto LABEL_83;
      case 0xCu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x800) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x800u;
        Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(v3 + 2981));
        goto LABEL_82;
      case 0xDu:
        if ( (*(_DWORD *)(v3 + 10153) & 0x1000) == 0 )
          *(_DWORD *)(v3 + 10153) |= 0x1000u;
        v22 = 0;
        result = TdrBuf::ReadInt32(a2, &v22);
        if ( result )
          return result;
        if ( !v22 )
          return -37;
        v17 = 0;
        v25 = a2[1];
        v21 = (char *)(this + 2985);
        while ( 1 )
        {
          v24 = 0;
          v4 = TdrBuf::ReadInt32(a2, &v24);
          if ( v4 )
            return v4;
          if ( v24 )
          {
            v4 = sub_101258C0(v21, a2, v24);
            if ( v4 )
              return v4;
          }
          v18 = (char *)a2[1];
          if ( v18 > &v22[v25] )
            return -34;
          if ( v18 == &v22[v25] )
            break;
          v21 += 7;
          if ( ++v17 >= 1024 )
          {
            v3 = this;
            goto LABEL_83;
          }
        }
        v19 = v17 + 1;
        v3 = this;
        *(_DWORD *)(this + 2981) = v19;
LABEL_83:
        v5 = v26;
        if ( a2[1] < v26 )
          continue;
LABEL_84:
        if ( a2[1] > v5 )
          return -34;
        return v4;
      default:
        Int32 = TdrBuf::SkipField(a2, v23 & 0xF);
LABEL_82:
        v4 = Int32;
        if ( !Int32 )
          goto LABEL_83;
        return v4;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011F520
// ============================================================
//----- (1011F520) --------------------------------------------------------
int __thiscall sub_1011F520(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 865) = 0;
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
        if ( (v4[865] & 1) == 0 )
          v4[865] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[865] & 2) == 0 )
            v4[865] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_1011EAD0((int)a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 54;
            if ( ++v10 >= 16 )
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
// Address Name: SUB_1012C300
// ============================================================
//----- (1012C300) --------------------------------------------------------
int __thiscall sub_1012C300(int this, size_t Size, int a3)
{
  int v3; // eax
  int v4; // ebx
  int Bytes; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int64; // eax
  int v10; // ebx
  size_t v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v17 = this;
  *(_DWORD *)(this + 265) = 0;
  v16 = 0;
  v7 = v6[1] + v3;
  v13 = v7;
  if ( v6[1] >= v7 )
    goto LABEL_50;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v6, &v16);
    if ( result )
      return result;
    switch ( v16 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(v4 + 265) & 1) == 0 )
          *(_DWORD *)(v4 + 265) |= 1u;
        Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)v4);
        goto LABEL_48;
      case 2u:
        if ( (*(_DWORD *)(v4 + 265) & 2) == 0 )
          *(_DWORD *)(v4 + 265) |= 2u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( Size >= 0x28 )
          return -3;
        Bytes = TdrBuf::ReadBytes(v6, (void *)(v4 + 8), Size);
        if ( !Bytes )
        {
          *(_BYTE *)(v4 + Size + 8) = 0;
          goto LABEL_49;
        }
        return Bytes;
      case 3u:
        if ( (*(_DWORD *)(v4 + 265) & 4) == 0 )
          *(_DWORD *)(v4 + 265) |= 4u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 48));
        goto LABEL_48;
      case 4u:
        if ( (*(_DWORD *)(v4 + 265) & 8) == 0 )
          *(_DWORD *)(v4 + 265) |= 8u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 52));
        goto LABEL_48;
      case 5u:
        if ( (*(_DWORD *)(v4 + 265) & 0x10) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x10u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 56));
        goto LABEL_48;
      case 6u:
        if ( (*(_DWORD *)(v4 + 265) & 0x20) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x20u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 60));
        goto LABEL_48;
      case 7u:
        if ( (*(_DWORD *)(v4 + 265) & 0x40) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x40u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 64));
        goto LABEL_48;
      case 8u:
        if ( (*(_DWORD *)(v4 + 265) & 0x80) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x80u;
        Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(v4 + 68));
        goto LABEL_48;
      case 9u:
        if ( (*(_DWORD *)(v4 + 265) & 0x100) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x100u;
        Size = 0;
        result = TdrBuf::ReadInt32(v6, &Size);
        if ( result )
          return result;
        if ( !Size )
          return -37;
        v10 = 0;
        v14 = v6[1];
        a3 = v17 + 72;
        while ( 1 )
        {
          v15 = 0;
          Bytes = TdrBuf::ReadInt32(v6, &v15);
          if ( Bytes )
            return Bytes;
          if ( v15 )
          {
            Bytes = sub_1012B510(a3, (size_t)v6, v15);
            if ( Bytes )
              return Bytes;
          }
          v11 = v6[1];
          if ( v11 > v14 + Size )
            return -34;
          if ( v11 == v14 + Size )
            break;
          a3 += 48;
          if ( ++v10 >= 4 )
          {
            v4 = v17;
            goto LABEL_49;
          }
        }
        v12 = v10 + 1;
        v4 = v17;
        *(_DWORD *)(v17 + 68) = v12;
LABEL_49:
        v7 = v13;
        if ( v6[1] < v13 )
          continue;
LABEL_50:
        if ( v6[1] > v7 )
          return -34;
        return Bytes;
      case 0xAu:
        if ( (*(_DWORD *)(v4 + 265) & 0x200) == 0 )
          *(_DWORD *)(v4 + 265) |= 0x200u;
        Int64 = sub_10115A30(v6, (_BYTE *)(v4 + 264));
        goto LABEL_48;
      default:
        Int64 = TdrBuf::SkipField(v6, v16 & 0xF);
LABEL_48:
        Bytes = Int64;
        if ( !Int64 )
          goto LABEL_49;
        return Bytes;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101323B0
// ============================================================
//----- (101323B0) --------------------------------------------------------
int __thiscall sub_101323B0(_DWORD *this, _DWORD *Size, _DWORD *a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ebx
  _DWORD *v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = (int)a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 10501) = 0;
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
        if ( (v4[10501] & 1) == 0 )
          v4[10501] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[10501] & 2) == 0 )
            v4[10501] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
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
              v5 = sub_10130FB0((int)a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 21;
            if ( ++v10 >= 500 )
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
// Address Name: SUB_10122920
// ============================================================
//----- (10122920) --------------------------------------------------------
int __thiscall sub_10122920(_DWORD *this, _DWORD *Size, char *a3)
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
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = Size;
  v17 = this;
  *(this + 39745) = 0;
  v16 = 0;
  v7 = &v3[v6[1]];
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
        if ( (v4[39745] & 1) == 0 )
          v4[39745] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[39745] & 2) == 0 )
            v4[39745] |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v6, &Size);
          if ( result )
            return result;
          if ( !Size )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (char *)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10121660(a3, (size_t)v6, v15);
              if ( v5 )
                return v5;
            }
            v11 = (_DWORD *)v6[1];
            if ( v11 > (_DWORD *)((char *)Size + v14) )
              return -34;
            if ( v11 == (_DWORD *)((char *)Size + v14) )
            {
              v12 = v10 + 1;
              v4 = v17;
              *v17 = v12;
              goto LABEL_23;
            }
            a3 += 621;
            if ( ++v10 >= 256 )
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
      if ( v6[1] >= (unsigned int)v13 )
        goto LABEL_24;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012ACA0
// ============================================================
//----- (1012ACA0) --------------------------------------------------------
int __thiscall sub_1012ACA0(_DWORD *this, _DWORD *a2, int a3)
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
  *(this + 4) = 0;
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
        if ( (*(_BYTE *)(this + 4) & 1) == 0 )
          *(this + 4) |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, this);
      }
      else
      {
        if ( v15 >> 4 == 2 )
        {
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
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
            if ( v10 >= 3 )
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
// Address Name: SUB_101283C0
// ============================================================
//----- (101283C0) --------------------------------------------------------
int __thiscall sub_101283C0(_DWORD *this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // ebx
  int v5; // esi
  _DWORD *v6; // edi
  char *v7; // eax
  int result; // eax
  int Int32; // eax
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
  *(this + 176) = 0;
  v16 = 0;
  v7 = &v3[v6[1]];
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
        if ( (v4[176] & 1) == 0 )
          v4[176] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[176] & 2) == 0 )
            v4[176] |= 2u;
          a2 = 0;
          result = TdrBuf::ReadInt32(v6, &a2);
          if ( result )
            return result;
          if ( !a2 )
            return -37;
          v10 = 0;
          v14 = v6[1];
          a3 = (char *)(v17 + 1);
          while ( 1 )
          {
            v15 = 0;
            v5 = TdrBuf::ReadInt32(v6, &v15);
            if ( v5 )
              return v5;
            if ( v15 )
            {
              v5 = sub_10127B10(a3, v6, v15);
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
            a3 += 7;
            if ( ++v10 >= 100 )
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
      if ( v6[1] >= (unsigned int)v13 )
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
// Address Name: SUB_1011F760
// ============================================================
//----- (1011F760) --------------------------------------------------------
int __thiscall sub_1011F760(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  char *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 16 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (char *)(this + 1); ; i += 216 )
          {
            if ( !"[titles]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[titles]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1011ED60(i, a2, a3 + 1, a4) : sub_1011ED60(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10127330
// ============================================================
//----- (10127330) --------------------------------------------------------
int __thiscall sub_10127330(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char *v7; // eax
  int v8; // edx
  int v9; // ecx
  char *v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  char *v16; // eax
  int v17; // edx
  int v18; // ecx
  int v20; // [esp+1Ch] [ebp+Ch]
  int v21; // [esp+1Ch] [ebp+Ch]
  int v22; // [esp+1Ch] [ebp+Ch]
  __int16 *v23; // [esp+20h] [ebp+10h]
  __int16 *v24; // [esp+20h] [ebp+10h]
  int v25; // [esp+20h] [ebp+10h]
  __int16 *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[openFlag]", "0x%02x", *this);
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[lib]", "%d", *(_DWORD *)(this + 1));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[group]", "%d", *(_DWORD *)(this + 5));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[refreshTime]", "%u", *(_DWORD *)(this + 9));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[curLibFinishCount]", "%d", *(_DWORD *)(this + 13));
  if ( result )
    return result;
  result = print_field(a2, a3, a4, "[taskCount]", "%d", *(_DWORD *)(this + 17));
  if ( result )
    return result;
  v7 = this;
  v8 = *(_DWORD *)(this + 17);
  if ( v8 < 0 )
    return -6;
  if ( v8 > 64 )
    return -7;
  v9 = 0;
  v20 = 0;
  if ( v8 <= 0 )
  {
LABEL_19:
    result = print_field(a2, a3, a4, "[contentCount]", "%d", *(_DWORD *)(v7 + 469));
    if ( result )
      return result;
    v10 = this;
    v11 = *(_DWORD *)(this + 469);
    if ( v11 < 0 )
      return -6;
    if ( v11 <= 256 )
    {
      v12 = 0;
      v21 = 0;
      if ( v11 > 0 )
      {
        v24 = (__int16 *)(this + 473);
        do
        {
          result = sub_1024A230(a2, a3, a4, "[content]", v12);
          if ( result )
            return result;
          result = a3 >= 0 ? sub_101253C0(v24, a2, a3 + 1, a4) : sub_101253C0(v24, a2, a3, a4);
          if ( result )
            return result;
          v10 = this;
          v12 = v21 + 1;
          v24 = (__int16 *)((char *)v24 + 9);
          v21 = v12;
        }
        while ( v12 < *(_DWORD *)(this + 469) );
      }
      result = print_field(a2, a3, a4, "[completeBitCount]", "%d", *(_DWORD *)(v10 + 2777));
      if ( result )
        return result;
      v14 = *(_DWORD *)(this + 2777);
      if ( v14 < 0 )
        return -6;
      if ( v14 <= 200 )
      {
        result = sub_1024A3B0(a2, a3, v13, "[completeBit]", v14);
        if ( result )
          return result;
        v15 = 0;
        v25 = 0;
        if ( *(int *)(this + 2777) > 0 )
        {
          v16 = this + 2781;
          do
          {
            result = Printf(a2, " 0x%02x", v16[v15]);
            if ( result )
              return result;
            v15 = v25 + 1;
            v25 = v15;
            v16 = this + 2781;
          }
          while ( v15 < *(_DWORD *)(this + 2777) );
        }
        result = TdrBuf::WriteChar(a2, a4);
        if ( result )
          return result;
        result = print_field(a2, a3, a4, "[completeCount]", "%d", *(_DWORD *)(this + 2981));
        if ( result )
          return result;
        v17 = *(_DWORD *)(this + 2981);
        if ( v17 < 0 )
          return -6;
        if ( v17 <= 1024 )
        {
          v18 = 0;
          v22 = 0;
          if ( v17 <= 0 )
            return 0;
          for ( i = (__int16 *)(this + 2985); ; i = (__int16 *)((char *)i + 7) )
          {
            result = sub_1024A230(a2, a3, a4, "[complete]", v18);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10125AF0(i, a2, a3 + 1, a4) : sub_10125AF0(i, a2, a3, a4);
            if ( result )
              break;
            v18 = v22 + 1;
            v22 = v18;
            if ( v18 >= *(_DWORD *)(this + 2981) )
              return 0;
          }
          return result;
        }
      }
    }
    return -7;
  }
  v23 = (__int16 *)(this + 21);
  while ( 1 )
  {
    result = sub_1024A230(a2, a3, a4, "[task]", v9);
    if ( result )
      return result;
    result = a3 >= 0 ? sub_10124B60(v23, a2, a3 + 1, a4) : sub_10124B60(v23, a2, a3, a4);
    if ( result )
      return result;
    v7 = this;
    v9 = v20 + 1;
    v23 = (__int16 *)((char *)v23 + 7);
    v20 = v9;
    if ( v9 >= *(_DWORD *)(this + 17) )
      goto LABEL_19;
  }
}
// 1012758B: variable 'v13' is possibly undefined



// ============================================================
// Name: Internal Helper Function
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
// Address Name: SUB_1012AEA0
// ============================================================
//----- (1012AEA0) --------------------------------------------------------
int __thiscall sub_1012AEA0(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[prizeCount]", "%d", *this);
  if ( !result )
  {
    v7 = *this;
    if ( *this >= 0 )
    {
      if ( v7 <= 3 )
      {
        result = sub_1024A3B0(a2, a3, v6, "[prizes]", v7);
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
              result = Printf(a2, " %d", *i);
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
// 1012AEFB: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012C700
// ============================================================
//----- (1012C700) --------------------------------------------------------
int __thiscall sub_1012C700(char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  char *v7; // ecx
  int v8; // edx
  int v9; // eax
  int v11; // [esp+1Ch] [ebp+Ch]
  _QWORD *i; // [esp+20h] [ebp+10h]

  result = print_field(a2, a3, a4, "[guildID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[teamName]", this + 8);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[matchID]", "%d", *((_DWORD *)this + 12));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[signUpID]", "%u", *((_DWORD *)this + 13));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[signUpTM]", "%d", *((_DWORD *)this + 14));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[bestScore]", "%d", *((_DWORD *)this + 15));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[bestScoreTm]", "%d", *((_DWORD *)this + 16));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[count]", "%d", *((_DWORD *)this + 17));
                if ( !result )
                {
                  v7 = this;
                  v8 = *((_DWORD *)this + 17);
                  if ( v8 >= 0 )
                  {
                    if ( v8 <= 4 )
                    {
                      v9 = 0;
                      v11 = 0;
                      if ( v8 <= 0 )
                      {
                        return print_field(a2, a3, a4, "[acceptRound]", "0x%02x", v7[264]);
                      }
                      else
                      {
                        for ( i = this + 72; ; i += 6 )
                        {
                          result = sub_1024A230(a2, a3, a4, "[members]", v9);
                          if ( result )
                            break;
                          result = a3 >= 0 ? sub_1012B6F0(i, a2, a3 + 1, a4) : sub_1012B6F0(i, a2, a3, a4);
                          if ( result )
                            break;
                          v7 = this;
                          v9 = v11 + 1;
                          v11 = v9;
                          if ( v9 >= *((_DWORD *)this + 17) )
                            return print_field(a2, a3, a4, "[acceptRound]", "0x%02x", v7[264]);
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
          }
        }
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
// Address Name: SUB_101325F0
// ============================================================
//----- (101325F0) --------------------------------------------------------
int __thiscall sub_101325F0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  const char *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 500 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (const char *)(this + 1); ; i += 84 )
          {
            if ( !"[guildBuyRecordInfosPkg]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guildBuyRecordInfosPkg]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10131250(i, a2, a3 + 1, a4) : sub_10131250(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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
// Address Name: SUB_10129D20
// ============================================================
//----- (10129D20) --------------------------------------------------------
int __thiscall sub_10129D20(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  unsigned __int8 v8; // cl
  unsigned __int8 v9; // al
  const char *v10; // ecx
  int v11; // ecx
  unsigned int v12; // eax
  int v13; // esi
  int v14; // [esp+14h] [ebp+8h]
  unsigned __int8 v15; // [esp+1Bh] [ebp+Fh]

  result = print_field(a2, a3, a4, "[curNum]", "0x%02x", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[count]", "0x%02x", *(this + 1));
    if ( !result )
    {
      v8 = *(this + 1);
      if ( v8 > 8u )
        return -7;
      v9 = 0;
      v15 = 0;
      if ( v8 )
      {
        while ( 1 )
        {
          v14 = v9;
          if ( !"[stores]" )
            _wassert(
              L"NULL != variable",
              L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
              0x43u);
          result = sub_1024A140(a3);
          if ( result )
            break;
          result = Printf(a2, "%s[%u]%c", "[stores]", v14, a4);
          if ( result )
            break;
          v10 = (const char *)(this + 13 * v14 + 2);
          result = a3 >= 0 ? sub_10128FC0(v10, a2, a3 + 1, a4) : sub_10128FC0(v10, a2, a3, a4);
          if ( result )
            break;
          v9 = v15 + 1;
          v15 = v9;
          if ( v9 >= *(this + 1) )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        result = print_field(a2, a3, a4, "[storeSize]", "%u", *(_DWORD *)(this + 106));
        if ( !result )
        {
          v12 = *(_DWORD *)(this + 106);
          if ( v12 > 0x30D40 )
            return -7;
          result = sub_1024A3B0(a2, a3, v11, "[storeData]", v12);
          if ( !result )
          {
            v13 = 0;
            if ( *(_DWORD *)(this + 106) )
            {
              while ( 1 )
              {
                result = Printf(a2, " %d", *(this + v13 + 110));
                if ( result )
                  break;
                if ( (unsigned int)++v13 >= *(_DWORD *)(this + 106) )
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
  return result;
}
// 10129E61: variable 'v11' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10131C10
// ============================================================
//----- (10131C10) --------------------------------------------------------
int __thiscall sub_10131C10(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  const char *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 500 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (const char *)(this + 1); ; i += 84 )
          {
            if ( !"[guildFuncRecordInfosPkg]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guildFuncRecordInfosPkg]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10131250(i, a2, a3 + 1, a4) : sub_10131250(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012A660
// ============================================================
//----- (1012A660) --------------------------------------------------------
int __thiscall sub_1012A660(int *this, _DWORD *a2, int a3, char a4)
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
      if ( v7 <= 30 )
      {
        result = sub_1024A3B0(a2, a3, v6, "[items]", v7);
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
              result = Printf(a2, " %d", *i);
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
// 1012A6BB: variable 'v6' is possibly undefined



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10122B60
// ============================================================
//----- (10122B60) --------------------------------------------------------
int __thiscall sub_10122B60(int *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  int i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 256 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (int)(this + 1); ; i += 621 )
          {
            if ( !"[guilders]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[guilders]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10121D40(i, a2, a3 + 1, a4) : sub_10121D40(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10128600
// ============================================================
//----- (10128600) --------------------------------------------------------
int __thiscall sub_10128600(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  __int16 *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 100 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (__int16 *)(this + 1); ; i = (__int16 *)((char *)i + 7) )
          {
            if ( !"[skills]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[skills]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10127D40(i, a2, a3 + 1, a4) : sub_10127D40(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101243D0
// ============================================================
//----- (101243D0) --------------------------------------------------------
int __thiscall sub_101243D0(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  const char *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( (int)*this >= 0 )
    {
      if ( v6 <= 128 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = (const char *)(this + 1); ; i += 460 )
          {
            if ( !"[applys]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[applys]", v7, (char)a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_10123940(i, a2, a3 + 1, a4) : sub_10123940(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10123390
// ============================================================
//----- (10123390) --------------------------------------------------------
int __thiscall sub_10123390(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 114) = 0;
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
          if ( (*(_BYTE *)(this + 114) & 1) == 0 )
            *(this + 114) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_34;
        case 2u:
          if ( (*(this + 114) & 2) == 0 )
            *(this + 114) |= 2u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_35;
          VarInt = sub_10118210(this + 1, (size_t)v4, Size);
LABEL_34:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_35;
          return Bytes;
        case 3u:
          if ( (*(this + 114) & 4) == 0 )
            *(this + 114) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 15);
          goto LABEL_34;
        case 4u:
          if ( (*(this + 114) & 8) == 0 )
            *(this + 114) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 16, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 64) = 0;
          goto LABEL_35;
        case 5u:
          if ( (*(this + 114) & 0x10) == 0 )
            *(this + 114) |= 0x10u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 48, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 192) = 0;
LABEL_35:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_36;
          break;
        case 6u:
          if ( (*(this + 114) & 0x20) == 0 )
            *(this + 114) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 112);
          goto LABEL_34;
        case 7u:
          if ( (*(this + 114) & 0x40) == 0 )
            *(this + 114) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 113);
          goto LABEL_34;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_34;
      }
    }
  }
LABEL_36:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124F90
// ============================================================
//----- (10124F90) --------------------------------------------------------
int __thiscall sub_10124F90(int this, _DWORD *a2, int a3)
{
  int v5; // edi
  unsigned int v6; // eax
  int result; // eax
  int VarShort; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v13; // [esp+18h] [ebp+8h]

  v5 = 0;
  v12 = 0;
  *(_DWORD *)(this + 5) = 0;
  v6 = a2[1] + a3;
  v13 = v6;
  while ( a2[1] < v6 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5) & 1) == 0 )
          *(_DWORD *)(this + 5) |= 1u;
        VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 5) & 2) == 0 )
          *(_DWORD *)(this + 5) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 3u:
        if ( (*(_DWORD *)(this + 5) & 4) == 0 )
          *(_DWORD *)(this + 5) |= 4u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = a2[1];
        if ( a2[2] == v10 )
          return -2;
        *(_BYTE *)(this + 3) = *(_BYTE *)(v10 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 4u:
        if ( (*(_DWORD *)(this + 5) & 8) == 0 )
          *(_DWORD *)(this + 5) |= 8u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v11 = a2[1];
        if ( a2[2] == v11 )
          return -2;
        *(_BYTE *)(this + 4) = *(_BYTE *)(v11 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        break;
      default:
        VarShort = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_27:
        v5 = VarShort;
        if ( VarShort )
          return v5;
        v6 = v13;
        continue;
    }
  }
  if ( a2[1] > v6 )
    return -34;
  return v5;
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
// Address Name: SUB_101257D0
// ============================================================
//----- (101257D0) --------------------------------------------------------
int __thiscall sub_101257D0(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124840
// ============================================================
//----- (10124840) --------------------------------------------------------
int __thiscall sub_10124840(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10130DE0
// ============================================================
//----- (10130DE0) --------------------------------------------------------
int __thiscall sub_10130DE0(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 20) = 0;
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
          if ( (*(_BYTE *)(this + 20) & 1) == 0 )
            *(this + 20) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_29;
        case 2u:
          if ( (*(this + 20) & 2) == 0 )
            *(this + 20) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 1, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 4) = 0;
          goto LABEL_30;
        case 3u:
          if ( (*(this + 20) & 4) == 0 )
            *(this + 20) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 9, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 36) = 0;
LABEL_30:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_31;
          break;
        case 4u:
          if ( (*(this + 20) & 8) == 0 )
            *(this + 20) |= 8u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 17);
          goto LABEL_29;
        case 5u:
          if ( (*(this + 20) & 0x10) == 0 )
            *(this + 20) |= 0x10u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 18);
          goto LABEL_29;
        case 6u:
          if ( (*(this + 20) & 0x20) == 0 )
            *(this + 20) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 19);
          goto LABEL_29;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_29:
          Bytes = VarInt;
          if ( !VarInt )
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
// Address Name: SUB_1012B400
// ============================================================
//----- (1012B400) --------------------------------------------------------
int __thiscall sub_1012B400(_DWORD *this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int VarUInt; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(this + 11) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(this + 11) & 2) == 0 )
          *(this + 11) |= 2u;
        VarUInt = TdrBuf::ReadVarUInt(v6, this + 2);
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        VarUInt = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(this + 11) & 4) == 0 )
        *(this + 11) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, this + 3, Size);
      if ( Bytes )
        return Bytes;
      *((_BYTE *)this + v10 + 12) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 11) & 1) == 0 )
      *(this + 11) |= 1u;
    VarUInt = TdrBuf::ReadVarULong(v6, this);
LABEL_19:
    Bytes = VarUInt;
    if ( VarUInt )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
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
// Address Name: SUB_1011E910
// ============================================================
//----- (1011E910) --------------------------------------------------------
int __thiscall sub_1011E910(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(this + 53) = 0;
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
          if ( (*(_BYTE *)(this + 53) & 1) == 0 )
            *(this + 53) |= 1u;
          VarInt = TdrBuf::ReadVarInt(v4, this);
          goto LABEL_25;
        case 2u:
          if ( (*(this + 53) & 2) == 0 )
            *(this + 53) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 1, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 4) = 0;
LABEL_26:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_27;
          break;
        case 3u:
          if ( (*(this + 53) & 4) == 0 )
            *(this + 53) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 9);
          goto LABEL_25;
        case 4u:
          if ( (*(this + 53) & 8) == 0 )
            *(this + 53) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_26;
          VarInt = sub_1011DED0(this + 10, v4, (int *)Size);
LABEL_25:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_26;
          return Bytes;
        case 5u:
          if ( (*(this + 53) & 0x10) == 0 )
            *(this + 53) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 52);
          goto LABEL_25;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_25;
      }
    }
  }
LABEL_27:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10127A20
// ============================================================
//----- (10127A20) --------------------------------------------------------
int __thiscall sub_10127A20(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  unsigned int v5; // ebx
  int result; // eax
  int VarShort; // eax
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = 0;
  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v5 = a2[1] + a3;
  if ( a2[1] < v5 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(a2, &v9);
      if ( result )
        return result;
      if ( v9 >> 4 == 1 )
        break;
      if ( v9 >> 4 != 2 )
      {
        VarShort = TdrBuf::SkipField(a2, v9 & 0xF);
        goto LABEL_15;
      }
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v8 = a2[1];
      if ( a2[2] == v8 )
        return -2;
      *(_BYTE *)(this + 2) = *(_BYTE *)(v8 + *a2);
      ++a2[1];
      v4 = 0;
LABEL_16:
      if ( a2[1] >= v5 )
        goto LABEL_17;
    }
    if ( (*(_BYTE *)(this + 3) & 1) == 0 )
      *(_DWORD *)(this + 3) |= 1u;
    VarShort = TdrBuf::ReadVarShort(a2, (_WORD *)this);
LABEL_15:
    v4 = VarShort;
    if ( VarShort )
      return v4;
    goto LABEL_16;
  }
LABEL_17:
  if ( a2[1] > v5 )
    return -34;
  return v4;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10128BA0
// ============================================================
//----- (10128BA0) --------------------------------------------------------
int __thiscall sub_10128BA0(char *this, size_t Size, int a3)
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
  *(_DWORD *)(this + 9) = 0;
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
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
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
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 8 )
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
// Address Name: SUB_10121050
// ============================================================
//----- (10121050) --------------------------------------------------------
int __thiscall sub_10121050(int *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(int *)((char *)this + 617) = 0;
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
          if ( (*((_BYTE *)this + 617) & 1) == 0 )
            *(int *)((char *)this + 617) |= 1u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          VarInt = sub_10118210(this, (size_t)v4, Size);
          goto LABEL_90;
        case 2u:
          if ( (*(int *)((char *)this + 617) & 2) == 0 )
            *(int *)((char *)this + 617) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 14, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 56) = 0;
          goto LABEL_91;
        case 3u:
          if ( (*(int *)((char *)this + 617) & 4) == 0 )
            *(int *)((char *)this + 617) |= 4u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 78);
          goto LABEL_90;
        case 4u:
          if ( (*(int *)((char *)this + 617) & 8) == 0 )
            *(int *)((char *)this + 617) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 79, Size);
          if ( Bytes )
            return Bytes;
          *((_BYTE *)this + Size + 316) = 0;
LABEL_91:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_92;
          break;
        case 5u:
          if ( (*(int *)((char *)this + 617) & 0x10) == 0 )
            *(int *)((char *)this + 617) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 111);
          goto LABEL_90;
        case 6u:
          if ( (*(int *)((char *)this + 617) & 0x20) == 0 )
            *(int *)((char *)this + 617) |= 0x20u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 112);
          goto LABEL_90;
        case 7u:
          if ( (*(int *)((char *)this + 617) & 0x40) == 0 )
            *(int *)((char *)this + 617) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 114);
          goto LABEL_90;
        case 8u:
          if ( (*(int *)((char *)this + 617) & 0x80) == 0 )
            *(int *)((char *)this + 617) |= 0x80u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 115);
          goto LABEL_90;
        case 9u:
          if ( (*(int *)((char *)this + 617) & 0x100) == 0 )
            *(int *)((char *)this + 617) |= 0x100u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 116);
          goto LABEL_90;
        case 0xAu:
          if ( (*(int *)((char *)this + 617) & 0x200) == 0 )
            *(int *)((char *)this + 617) |= 0x200u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 117);
          goto LABEL_90;
        case 0xBu:
          if ( (*(int *)((char *)this + 617) & 0x400) == 0 )
            *(int *)((char *)this + 617) |= 0x400u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 118);
          goto LABEL_90;
        case 0xCu:
          if ( (*(int *)((char *)this + 617) & 0x800) == 0 )
            *(int *)((char *)this + 617) |= 0x800u;
          VarInt = TdrBuf::ReadVarUInt(v4, this + 119);
          goto LABEL_90;
        case 0xDu:
          if ( (*(int *)((char *)this + 617) & 0x1000) == 0 )
            *(int *)((char *)this + 617) |= 0x1000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 120);
          goto LABEL_90;
        case 0xEu:
          if ( (*(int *)((char *)this + 617) & 0x2000) == 0 )
            *(int *)((char *)this + 617) |= 0x2000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 121);
          goto LABEL_90;
        case 0xFu:
          if ( (*(int *)((char *)this + 617) & 0x4000) == 0 )
            *(int *)((char *)this + 617) |= 0x4000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 122);
          goto LABEL_90;
        case 0x10u:
          if ( (*(int *)((char *)this + 617) & 0x8000) == 0 )
            *(int *)((char *)this + 617) |= 0x8000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 123);
          goto LABEL_90;
        case 0x11u:
          if ( (*(int *)((char *)this + 617) & 0x10000) == 0 )
            *(int *)((char *)this + 617) |= 0x10000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 124);
          goto LABEL_90;
        case 0x12u:
          if ( (*(int *)((char *)this + 617) & 0x20000) == 0 )
            *(int *)((char *)this + 617) |= 0x20000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 125);
          goto LABEL_90;
        case 0x13u:
          if ( (*(int *)((char *)this + 617) & 0x40000) == 0 )
            *(int *)((char *)this + 617) |= 0x40000u;
          VarInt = TdrBuf::ReadVarULong(v4, this + 126);
          goto LABEL_90;
        case 0x14u:
          if ( (*(int *)((char *)this + 617) & 0x80000) == 0 )
            *(int *)((char *)this + 617) |= 0x80000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 128);
          goto LABEL_90;
        case 0x15u:
          if ( (*(int *)((char *)this + 617) & 0x100000) == 0 )
            *(int *)((char *)this + 617) |= 0x100000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 129);
          goto LABEL_90;
        case 0x16u:
          if ( (*(int *)((char *)this + 617) & 0x200000) == 0 )
            *(int *)((char *)this + 617) |= 0x200000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 130);
          goto LABEL_90;
        case 0x17u:
          if ( (*(int *)((char *)this + 617) & 0x400000) == 0 )
            *(int *)((char *)this + 617) |= 0x400000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 131);
          goto LABEL_90;
        case 0x18u:
          if ( (*(int *)((char *)this + 617) & 0x800000) == 0 )
            *(int *)((char *)this + 617) |= 0x800000u;
          VarInt = TdrBuf::ReadVarInt(v4, this + 132);
          goto LABEL_90;
        case 0x19u:
          if ( (*(int *)((char *)this + 617) & 0x1000000) == 0 )
            *(int *)((char *)this + 617) |= 0x1000000u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          VarInt = sub_1011FD30((int)(this + 133), (unsigned int)v4, Size);
LABEL_90:
          Bytes = VarInt;
          if ( !VarInt )
            goto LABEL_91;
          return Bytes;
        default:
          VarInt = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_90;
      }
    }
  }
LABEL_92:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
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
// Address Name: SUB_10123600
// ============================================================
//----- (10123600) --------------------------------------------------------
int __thiscall sub_10123600(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 456) = 0;
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
          if ( (*(_BYTE *)(this + 456) & 1) == 0 )
            *(_DWORD *)(this + 456) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_34;
        case 2u:
          if ( (*(_DWORD *)(this + 456) & 2) == 0 )
            *(_DWORD *)(this + 456) |= 2u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_35;
          Int32 = sub_10118360((_DWORD *)(this + 4), (size_t)v4, Size);
LABEL_34:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_35;
          return Bytes;
        case 3u:
          if ( (*(_DWORD *)(this + 456) & 4) == 0 )
            *(_DWORD *)(this + 456) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 60));
          goto LABEL_34;
        case 4u:
          if ( (*(_DWORD *)(this + 456) & 8) == 0 )
            *(_DWORD *)(this + 456) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 64), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 64) = 0;
          goto LABEL_35;
        case 5u:
          if ( (*(_DWORD *)(this + 456) & 0x10) == 0 )
            *(_DWORD *)(this + 456) |= 0x10u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 192), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 192) = 0;
LABEL_35:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_36;
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 456) & 0x20) == 0 )
            *(_DWORD *)(this + 456) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 448));
          goto LABEL_34;
        case 7u:
          if ( (*(_DWORD *)(this + 456) & 0x40) == 0 )
            *(_DWORD *)(this + 456) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 452));
          goto LABEL_34;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_34;
      }
    }
  }
LABEL_36:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10128D30
// ============================================================
//----- (10128D30) --------------------------------------------------------
int __thiscall sub_10128D30(char *this, size_t Size, int a3)
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
  *(_DWORD *)(this + 9) = 0;
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
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
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
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      Size = 0;
      result = TdrBuf::ReadInt32(v4, &Size);
      if ( result )
        return result;
      v9 = Size;
      if ( Size >= 8 )
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
// Address Name: SUB_10130FB0
// ============================================================
//----- (10130FB0) --------------------------------------------------------
int __thiscall sub_10130FB0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 80) = 0;
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
          if ( (*(_BYTE *)(this + 80) & 1) == 0 )
            *(_DWORD *)(this + 80) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_29;
        case 2u:
          if ( (*(_DWORD *)(this + 80) & 2) == 0 )
            *(_DWORD *)(this + 80) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 4), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 4) = 0;
          goto LABEL_30;
        case 3u:
          if ( (*(_DWORD *)(this + 80) & 4) == 0 )
            *(_DWORD *)(this + 80) |= 4u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 36), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 36) = 0;
LABEL_30:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_31;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 80) & 8) == 0 )
            *(_DWORD *)(this + 80) |= 8u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 68));
          goto LABEL_29;
        case 5u:
          if ( (*(_DWORD *)(this + 80) & 0x10) == 0 )
            *(_DWORD *)(this + 80) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 72));
          goto LABEL_29;
        case 6u:
          if ( (*(_DWORD *)(this + 80) & 0x20) == 0 )
            *(_DWORD *)(this + 80) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 76));
          goto LABEL_29;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_29:
          Bytes = Int32;
          if ( !Int32 )
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
// Address Name: SUB_10125140
// ============================================================
//----- (10125140) --------------------------------------------------------
int __thiscall sub_10125140(int this, _DWORD *a2, int a3)
{
  int v5; // edi
  unsigned int v6; // eax
  int result; // eax
  int Int16; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v13; // [esp+18h] [ebp+8h]

  v5 = 0;
  v12 = 0;
  *(_DWORD *)(this + 5) = 0;
  v6 = a2[1] + a3;
  v13 = v6;
  while ( a2[1] < v6 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v12);
    if ( result )
      return result;
    switch ( v12 >> 4 )
    {
      case 1u:
        if ( (*(_BYTE *)(this + 5) & 1) == 0 )
          *(_DWORD *)(this + 5) |= 1u;
        Int16 = TdrBuf::ReadInt16(a2, (_BYTE *)this);
        goto LABEL_27;
      case 2u:
        if ( (*(_DWORD *)(this + 5) & 2) == 0 )
          *(_DWORD *)(this + 5) |= 2u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v9 = a2[1];
        if ( a2[2] == v9 )
          return -2;
        *(_BYTE *)(this + 2) = *(_BYTE *)(v9 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 3u:
        if ( (*(_DWORD *)(this + 5) & 4) == 0 )
          *(_DWORD *)(this + 5) |= 4u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v10 = a2[1];
        if ( a2[2] == v10 )
          return -2;
        *(_BYTE *)(this + 3) = *(_BYTE *)(v10 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        continue;
      case 4u:
        if ( (*(_DWORD *)(this + 5) & 8) == 0 )
          *(_DWORD *)(this + 5) |= 8u;
        if ( a2[1] > a2[2] )
          _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
        v11 = a2[1];
        if ( a2[2] == v11 )
          return -2;
        *(_BYTE *)(this + 4) = *(_BYTE *)(v11 + *a2);
        ++a2[1];
        v5 = 0;
        v6 = v13;
        break;
      default:
        Int16 = TdrBuf::SkipField(a2, v12 & 0xF);
LABEL_27:
        v5 = Int16;
        if ( Int16 )
          return v5;
        v6 = v13;
        continue;
    }
  }
  if ( a2[1] > v6 )
    return -34;
  return v5;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124930
// ============================================================
//----- (10124930) --------------------------------------------------------
int __thiscall sub_10124930(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101258C0
// ============================================================
//----- (101258C0) --------------------------------------------------------
int __thiscall sub_101258C0(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011EAD0
// ============================================================
//----- (1011EAD0) --------------------------------------------------------
int __thiscall sub_1011EAD0(int this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 212) = 0;
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
          if ( (*(_BYTE *)(this + 212) & 1) == 0 )
            *(_DWORD *)(this + 212) |= 1u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
          goto LABEL_25;
        case 2u:
          if ( (*(_DWORD *)(this + 212) & 2) == 0 )
            *(_DWORD *)(this + 212) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x20 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, (void *)(this + 4), Size);
          if ( Bytes )
            return Bytes;
          *(_BYTE *)(this + Size + 4) = 0;
LABEL_26:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_27;
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 212) & 4) == 0 )
            *(_DWORD *)(this + 212) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 36));
          goto LABEL_25;
        case 4u:
          if ( (*(_DWORD *)(this + 212) & 8) == 0 )
            *(_DWORD *)(this + 212) |= 8u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_26;
          Int32 = sub_1011E040((_DWORD *)(this + 40), v4, Size);
LABEL_25:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_26;
          return Bytes;
        case 5u:
          if ( (*(_DWORD *)(this + 212) & 0x10) == 0 )
            *(_DWORD *)(this + 212) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 208));
          goto LABEL_25;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_25;
      }
    }
  }
LABEL_27:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1012B510
// ============================================================
//----- (1012B510) --------------------------------------------------------
int __thiscall sub_1012B510(int this, size_t Size, int a3)
{
  int v3; // ebx
  int Bytes; // ecx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int Int32; // eax
  size_t v10; // ebx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  Bytes = 0;
  v6 = (_DWORD *)Size;
  v11 = 0;
  *(_DWORD *)(this + 44) = 0;
  v7 = v6[1] + v3;
  a3 = v7;
  if ( v6[1] < v7 )
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v11);
      if ( result )
        return result;
      if ( v11 >> 4 == 1 )
        break;
      if ( v11 >> 4 == 2 )
      {
        if ( (*(_DWORD *)(this + 44) & 2) == 0 )
          *(_DWORD *)(this + 44) |= 2u;
        Int32 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 8));
        goto LABEL_19;
      }
      if ( v11 >> 4 != 3 )
      {
        Int32 = TdrBuf::SkipField(v6, v11 & 0xF);
        goto LABEL_19;
      }
      if ( (*(_DWORD *)(this + 44) & 4) == 0 )
        *(_DWORD *)(this + 44) |= 4u;
      Size = 0;
      result = TdrBuf::ReadInt32(v6, &Size);
      if ( result )
        return result;
      v10 = Size;
      if ( Size >= 0x20 )
        return -3;
      Bytes = TdrBuf::ReadBytes(v6, (void *)(this + 12), Size);
      if ( Bytes )
        return Bytes;
      *(_BYTE *)(this + v10 + 12) = 0;
      v7 = a3;
LABEL_20:
      if ( v6[1] >= v7 )
        goto LABEL_21;
    }
    if ( (*(_BYTE *)(this + 44) & 1) == 0 )
      *(_DWORD *)(this + 44) |= 1u;
    Int32 = TdrBuf::ReadInt64(v6, (_BYTE *)this);
LABEL_19:
    Bytes = Int32;
    if ( Int32 )
      return Bytes;
    goto LABEL_20;
  }
LABEL_21:
  if ( v6[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10121660
// ============================================================
//----- (10121660) --------------------------------------------------------
int __thiscall sub_10121660(char *this, size_t Size, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // ebx
  int Bytes; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)Size;
  Bytes = 0;
  v10 = 0;
  *(_DWORD *)(this + 617) = 0;
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
          if ( (*(this + 617) & 1) == 0 )
            *(_DWORD *)(this + 617) |= 1u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          Int32 = sub_10118360(this, (size_t)v4, Size);
          goto LABEL_90;
        case 2u:
          if ( (*(_DWORD *)(this + 617) & 2) == 0 )
            *(_DWORD *)(this + 617) |= 2u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x100 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 56, Size);
          if ( Bytes )
            return Bytes;
          *(this + Size + 56) = 0;
          goto LABEL_91;
        case 3u:
          if ( (*(_DWORD *)(this + 617) & 4) == 0 )
            *(_DWORD *)(this + 617) |= 4u;
          Int32 = TdrBuf::ReadInt32(v4, this + 312);
          goto LABEL_90;
        case 4u:
          if ( (*(_DWORD *)(this + 617) & 8) == 0 )
            *(_DWORD *)(this + 617) |= 8u;
          Size = 0;
          result = TdrBuf::ReadInt32(v4, &Size);
          if ( result )
            return result;
          if ( Size >= 0x80 )
            return -3;
          Bytes = TdrBuf::ReadBytes(v4, this + 316, Size);
          if ( Bytes )
            return Bytes;
          *(this + Size + 316) = 0;
LABEL_91:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_92;
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 617) & 0x10) == 0 )
            *(_DWORD *)(this + 617) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(v4, this + 444);
          goto LABEL_90;
        case 6u:
          if ( (*(_DWORD *)(this + 617) & 0x20) == 0 )
            *(_DWORD *)(this + 617) |= 0x20u;
          Int32 = TdrBuf::ReadInt64(v4, this + 448);
          goto LABEL_90;
        case 7u:
          if ( (*(_DWORD *)(this + 617) & 0x40) == 0 )
            *(_DWORD *)(this + 617) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(v4, this + 456);
          goto LABEL_90;
        case 8u:
          if ( (*(_DWORD *)(this + 617) & 0x80) == 0 )
            *(_DWORD *)(this + 617) |= 0x80u;
          Int32 = TdrBuf::ReadInt32(v4, this + 460);
          goto LABEL_90;
        case 9u:
          if ( (*(_DWORD *)(this + 617) & 0x100) == 0 )
            *(_DWORD *)(this + 617) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(v4, this + 464);
          goto LABEL_90;
        case 0xAu:
          if ( (*(_DWORD *)(this + 617) & 0x200) == 0 )
            *(_DWORD *)(this + 617) |= 0x200u;
          Int32 = TdrBuf::ReadInt32(v4, this + 468);
          goto LABEL_90;
        case 0xBu:
          if ( (*(_DWORD *)(this + 617) & 0x400) == 0 )
            *(_DWORD *)(this + 617) |= 0x400u;
          Int32 = TdrBuf::ReadInt32(v4, this + 472);
          goto LABEL_90;
        case 0xCu:
          if ( (*(_DWORD *)(this + 617) & 0x800) == 0 )
            *(_DWORD *)(this + 617) |= 0x800u;
          Int32 = TdrBuf::ReadInt32(v4, this + 476);
          goto LABEL_90;
        case 0xDu:
          if ( (*(_DWORD *)(this + 617) & 0x1000) == 0 )
            *(_DWORD *)(this + 617) |= 0x1000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 480);
          goto LABEL_90;
        case 0xEu:
          if ( (*(_DWORD *)(this + 617) & 0x2000) == 0 )
            *(_DWORD *)(this + 617) |= 0x2000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 484);
          goto LABEL_90;
        case 0xFu:
          if ( (*(_DWORD *)(this + 617) & 0x4000) == 0 )
            *(_DWORD *)(this + 617) |= 0x4000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 488);
          goto LABEL_90;
        case 0x10u:
          if ( (*(_DWORD *)(this + 617) & 0x8000) == 0 )
            *(_DWORD *)(this + 617) |= 0x8000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 492);
          goto LABEL_90;
        case 0x11u:
          if ( (*(_DWORD *)(this + 617) & 0x10000) == 0 )
            *(_DWORD *)(this + 617) |= 0x10000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 496);
          goto LABEL_90;
        case 0x12u:
          if ( (*(_DWORD *)(this + 617) & 0x20000) == 0 )
            *(_DWORD *)(this + 617) |= 0x20000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 500);
          goto LABEL_90;
        case 0x13u:
          if ( (*(_DWORD *)(this + 617) & 0x40000) == 0 )
            *(_DWORD *)(this + 617) |= 0x40000u;
          Int32 = TdrBuf::ReadInt64(v4, this + 504);
          goto LABEL_90;
        case 0x14u:
          if ( (*(_DWORD *)(this + 617) & 0x80000) == 0 )
            *(_DWORD *)(this + 617) |= 0x80000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 512);
          goto LABEL_90;
        case 0x15u:
          if ( (*(_DWORD *)(this + 617) & 0x100000) == 0 )
            *(_DWORD *)(this + 617) |= 0x100000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 516);
          goto LABEL_90;
        case 0x16u:
          if ( (*(_DWORD *)(this + 617) & 0x200000) == 0 )
            *(_DWORD *)(this + 617) |= 0x200000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 520);
          goto LABEL_90;
        case 0x17u:
          if ( (*(_DWORD *)(this + 617) & 0x400000) == 0 )
            *(_DWORD *)(this + 617) |= 0x400000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 524);
          goto LABEL_90;
        case 0x18u:
          if ( (*(_DWORD *)(this + 617) & 0x800000) == 0 )
            *(_DWORD *)(this + 617) |= 0x800000u;
          Int32 = TdrBuf::ReadInt32(v4, this + 528);
          goto LABEL_90;
        case 0x19u:
          if ( (*(_DWORD *)(this + 617) & 0x1000000) == 0 )
            *(_DWORD *)(this + 617) |= 0x1000000u;
          Size = 0;
          Bytes = TdrBuf::ReadInt32(v4, &Size);
          if ( Bytes )
            return Bytes;
          if ( !Size )
            goto LABEL_91;
          Int32 = sub_1011FEA0((int)(this + 532), (unsigned int)v4, Size);
LABEL_90:
          Bytes = Int32;
          if ( !Int32 )
            goto LABEL_91;
          return Bytes;
        default:
          Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
          goto LABEL_90;
      }
    }
  }
LABEL_92:
  if ( v4[1] > v7 )
    return -34;
  return Bytes;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10127B10
// ============================================================
//----- (10127B10) --------------------------------------------------------
int __thiscall sub_10127B10(char *this, _DWORD *a2, int a3)
{
  bool v5; // cf
  int result; // eax
  int v7; // ecx
  int v8; // ecx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v9 = 0;
  *(_DWORD *)(this + 3) = 0;
  v10 = a2[1] + a3;
  v5 = v10 < a2[1];
  if ( v10 <= a2[1] )
    return v5 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(a2, &v9);
    if ( result )
      break;
    if ( v9 >> 4 == 1 )
    {
      if ( (*(this + 3) & 1) == 0 )
        *(_DWORD *)(this + 3) |= 1u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x2A4u);
      v8 = a2[1];
      if ( (unsigned int)(a2[2] - v8) < 2 )
        return -2;
      *this = *(_BYTE *)(*a2 + v8 + 1);
      *(this + 1) = *(_BYTE *)(*a2 + a2[1]);
      a2[1] += 2;
    }
    else if ( v9 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 3) & 2) == 0 )
        *(_DWORD *)(this + 3) |= 2u;
      if ( a2[1] > a2[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v7 = a2[1];
      if ( a2[2] == v7 )
        return -2;
      *(this + 2) = *(_BYTE *)(v7 + *a2);
      ++a2[1];
    }
    else
    {
      result = TdrBuf::SkipField(a2, v9 & 0xF);
      if ( result )
        return result;
    }
    if ( a2[1] >= v10 )
    {
      v5 = v10 < a2[1];
      return v5 ? 0xFFFFFFDE : 0;
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
// Address Name: SUB_1011ED60
// ============================================================
//----- (1011ED60) --------------------------------------------------------
int __thiscall sub_1011ED60(char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int *v5; // ecx

  result = print_field(a2, a3, a4, "[title]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[name]", this + 4);
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[rights]", "%d", *((_DWORD *)this + 9));
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[depotRights]");
        if ( !result )
        {
          v5 = (int *)(this + 40);
          if ( a3 >= 0 )
            result = sub_1011E280(v5, a2, a3 + 1, a4);
          else
            result = sub_1011E280(v5, a2, a3, a4);
          if ( !result )
            return print_field(a2, a3, a4, "[depotOpCount]", "%d", *((_DWORD *)this + 52));
        }
      }
    }
  }
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
// Address Name: SUB_101253C0
// ============================================================
//----- (101253C0) --------------------------------------------------------
int __thiscall sub_101253C0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[task]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[id]", "%d", *((unsigned __int8 *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[state]", "%d", *((unsigned __int8 *)this + 3));
      if ( !result )
        return print_field(a2, a3, a4, "[arg1]", "%d", *((unsigned __int8 *)this + 4));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10124B60
// ============================================================
//----- (10124B60) --------------------------------------------------------
int __thiscall sub_10124B60(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[id]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[state]", "%d", *((unsigned __int8 *)this + 2));
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
// Address Name: SUB_10125AF0
// ============================================================
//----- (10125AF0) --------------------------------------------------------
int __thiscall sub_10125AF0(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[task]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[count]", "%d", *((unsigned __int8 *)this + 2));
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
// Address Name: SUB_1012B6F0
// ============================================================
//----- (1012B6F0) --------------------------------------------------------
int __thiscall sub_1012B6F0(_QWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[dBID]", "%I64u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[qQ]", "%u", *((_DWORD *)this + 2));
    if ( !result )
      return sub_1024A410(a2, a3, a4, "[name]", (const char *)this + 12);
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10131250
// ============================================================
//----- (10131250) --------------------------------------------------------
int __thiscall sub_10131250(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[operType]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    result = sub_1024A410(a2, a3, a4, "[executor]", this + 4);
    if ( !result )
    {
      result = sub_1024A410(a2, a3, a4, "[beExecutored]", this + 36);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[args]", "%d", *((_DWORD *)this + 17));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[time]", "%u", *((_DWORD *)this + 18));
          if ( !result )
            return print_field(a2, a3, a4, "[args2]", "%d", *((_DWORD *)this + 19));
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10128FC0
// ============================================================
//----- (10128FC0) --------------------------------------------------------
int __thiscall sub_10128FC0(const char *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[idx]", "0x%02x", *(unsigned __int8 *)this);
  if ( !result )
    return sub_1024A410(a2, a3, a4, "[name]", this + 1);
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10121D40
// ============================================================
//----- (10121D40) --------------------------------------------------------
int __thiscall sub_10121D40(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v6; // ecx

  if ( !"[id]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[id]", (char)a4);
    if ( !result )
    {
      if ( a3 >= 0 )
        result = sub_10118580(this, a2, a3 + 1, a4);
      else
        result = sub_10118580(this, a2, a3, a4);
      if ( !result )
      {
        result = sub_1024A410(a2, a3, a4, "[note]", (const char *)(this + 56));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[level]", "%d", *(_DWORD *)(this + 312));
          if ( !result )
          {
            result = sub_1024A410(a2, a3, a4, "[hunterStar]", (const char *)(this + 316));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[contribution]", "%d", *(_DWORD *)(this + 444));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[contributionAcc]", "%I64u", *(_QWORD *)(this + 448));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[wage]", "%d", *(_DWORD *)(this + 456));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[title]", "%d", *(_DWORD *)(this + 460));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[offlineTime]", "%u", *(_DWORD *)(this + 464));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[depotOpCount]", "%d", *(_DWORD *)(this + 468));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[hRLevel]", "%d", *(_DWORD *)(this + 472));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[joinTime]", "%u", *(_DWORD *)(this + 476));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[wildHuntSoul]", "%d", *(_DWORD *)(this + 480));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[wildHuntPhase]", "%d", *(_DWORD *)(this + 484));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[celebrationTask]", "%d", *(_DWORD *)(this + 488));
                                  if ( !result )
                                  {
                                    result = print_field(
                                               a2,
                                               a3,
                                               a4,
                                               "[preCelebrationTask]",
                                               "%d",
                                               *(_DWORD *)(this + 492));
                                    if ( !result )
                                    {
                                      result = print_field(
                                                 a2,
                                                 a3,
                                                 a4,
                                                 "[celebrationScore]",
                                                 "%d",
                                                 *(_DWORD *)(this + 496));
                                      if ( !result )
                                      {
                                        result = print_field(
                                                   a2,
                                                   a3,
                                                   a4,
                                                   "[celebrationReward]",
                                                   "%d",
                                                   *(_DWORD *)(this + 500));
                                        if ( !result )
                                        {
                                          result = print_field(
                                                     a2,
                                                     a3,
                                                     a4,
                                                     "[contributionWeekAcc]",
                                                     "%I64u",
                                                     *(_QWORD *)(this + 504));
                                          if ( !result )
                                          {
                                            result = print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[levelupAll]",
                                                       "%d",
                                                       *(_DWORD *)(this + 512));
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[hunterCount]",
                                                         "%d",
                                                         *(_DWORD *)(this + 516));
                                              if ( !result )
                                              {
                                                result = print_field(
                                                           a2,
                                                           a3,
                                                           a4,
                                                           "[taskCount]",
                                                           "%d",
                                                           *(_DWORD *)(this + 520));
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[isBaned]",
                                                             "%d",
                                                             *(_DWORD *)(this + 524));
                                                  if ( !result )
                                                  {
                                                    result = print_field(
                                                               a2,
                                                               a3,
                                                               a4,
                                                               "[banedTime]",
                                                               "%d",
                                                               *(_DWORD *)(this + 528));
                                                    if ( !result )
                                                    {
                                                      result = print_structure((int)a2, a3, a4, (int)"[guildWar]");
                                                      if ( !result )
                                                      {
                                                        v6 = this + 532;
                                                        if ( a3 >= 0 )
                                                          return sub_101200E0(v6, a2, a3 + 1, a4);
                                                        else
                                                          return sub_101200E0(v6, a2, a3, a4);
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10127D40
// ============================================================
//----- (10127D40) --------------------------------------------------------
int __thiscall sub_10127D40(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[skill]", "%d", *this);
  if ( !result )
    return print_field(a2, a3, a4, "[level]", "%d", *((unsigned __int8 *)this + 2));
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10123940
// ============================================================
//----- (10123940) --------------------------------------------------------
int __thiscall sub_10123940(const char *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx

  result = print_field(a2, a3, a4, "[id]", "%d", *(_DWORD *)this);
  if ( !result )
  {
    if ( !"[role]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[role]", (char)a4);
      if ( !result )
      {
        v5 = (int)(this + 4);
        if ( a3 >= 0 )
          result = sub_10118580(v5, a2, a3 + 1, a4);
        else
          result = sub_10118580(v5, a2, a3, a4);
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[level]", "%d", *((_DWORD *)this + 15));
          if ( !result )
          {
            result = sub_1024A410(a2, a3, a4, "[hunterStar]", this + 64);
            if ( !result )
            {
              result = sub_1024A410(a2, a3, a4, "[note]", this + 192);
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[time]", "%d", *((_DWORD *)this + 112));
                if ( !result )
                  return print_field(a2, a3, a4, "[hRLevel]", "%d", *((_DWORD *)this + 113));
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
// Address Name: SUB_10118210
// ============================================================
//----- (10118210) --------------------------------------------------------
int __thiscall sub_10118210(_DWORD *this, size_t Size, unsigned int a3)
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
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 8);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            VarULong = TdrBuf::ReadVarUInt(v4, this + 10);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            VarULong = TdrBuf::ReadVarULong(v4, this + 11);
            goto LABEL_20;
          default:
            VarULong = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = VarULong;
            if ( VarULong )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
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
// Address Name: SUB_1011DED0
// ============================================================
//----- (1011DED0) --------------------------------------------------------
int __thiscall sub_1011DED0(int *this, _DWORD *a2, int *a3)
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
  char *v13; // [esp+Ch] [ebp-14h]
  int v14; // [esp+10h] [ebp-10h]
  int v15; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h] BYREF
  int *v17; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = this;
  v5 = 0;
  v6 = a2;
  v17 = this;
  *(this + 41) = 0;
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
        if ( (v4[41] & 1) == 0 )
          v4[41] |= 1u;
        VarInt = TdrBuf::ReadVarInt(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[41] & 2) == 0 )
            v4[41] |= 2u;
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
              v5 = sub_1011D690(a3, v6, v15);
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
            a3 += 5;
            if ( ++v10 >= 8 )
            {
              v4 = v17;
              goto LABEL_23;
            }
          }
        }
        VarInt = TdrBuf::SkipField(v6, v16 & 0xF);
      }
      v5 = VarInt;
      if ( VarInt )
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
// Address Name: SUB_1011FD30
// ============================================================
//----- (1011FD30) --------------------------------------------------------
int __thiscall sub_1011FD30(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v11 = 0;
  *(_DWORD *)(this + 81) = 0;
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
          if ( (*(_BYTE *)(this + 81) & 1) == 0 )
            *(_DWORD *)(this + 81) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_23;
          VarUInt = sub_1011B300((_DWORD *)this, (int)v4, a2);
          goto LABEL_22;
        case 2u:
          if ( (*(_DWORD *)(this + 81) & 2) == 0 )
            *(_DWORD *)(this + 81) |= 2u;
          VarUInt = TdrBuf::ReadVarUInt(v4, (_DWORD *)(this + 72));
          goto LABEL_22;
        case 3u:
          if ( (*(_DWORD *)(this + 81) & 4) == 0 )
            *(_DWORD *)(this + 81) |= 4u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 76) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          v6 = 0;
LABEL_23:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_24;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 81) & 8) == 0 )
            *(_DWORD *)(this + 81) |= 8u;
          VarUInt = TdrBuf::ReadVarInt(v4, (int *)(this + 77));
          goto LABEL_22;
        default:
          VarUInt = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_22:
          v6 = VarUInt;
          if ( !VarUInt )
            goto LABEL_23;
          return v6;
      }
    }
  }
LABEL_24:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10118360
// ============================================================
//----- (10118360) --------------------------------------------------------
int __thiscall sub_10118360(_DWORD *this, size_t Size, unsigned int a3)
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
  *(this + 13) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_22:
    if ( v4[1] > v7 )
      return -34;
    return Bytes;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 13) & 1) == 0 )
              *(this + 13) |= 1u;
            Size = 0;
            result = TdrBuf::ReadInt32(v4, &Size);
            if ( !result )
            {
              if ( Size < 0x20 )
              {
                Bytes = TdrBuf::ReadBytes(v4, this, Size);
                if ( Bytes )
                  return Bytes;
                *((_BYTE *)this + Size) = 0;
                goto LABEL_21;
              }
              return -3;
            }
            return result;
          case 2u:
            if ( (*(this + 13) & 2) == 0 )
              *(this + 13) |= 2u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 32);
            goto LABEL_20;
          case 3u:
            if ( (*(this + 13) & 4) == 0 )
              *(this + 13) |= 4u;
            Int64 = TdrBuf::ReadInt32(v4, (_BYTE *)this + 40);
            goto LABEL_20;
          case 4u:
            if ( (*(this + 13) & 8) == 0 )
              *(this + 13) |= 8u;
            Int64 = TdrBuf::ReadInt64(v4, (_BYTE *)this + 44);
            goto LABEL_20;
          default:
            Int64 = TdrBuf::SkipField(v4, v10 & 0xF);
LABEL_20:
            Bytes = Int64;
            if ( Int64 )
              return Bytes;
LABEL_21:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_22;
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
// Address Name: SUB_1011E040
// ============================================================
//----- (1011E040) --------------------------------------------------------
int __thiscall sub_1011E040(_DWORD *this, _DWORD *a2, int a3)
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
  *(this + 41) = 0;
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
        if ( (v4[41] & 1) == 0 )
          v4[41] |= 1u;
        Int32 = TdrBuf::ReadInt32(v6, v4);
      }
      else
      {
        if ( v16 >> 4 == 2 )
        {
          if ( (v4[41] & 2) == 0 )
            v4[41] |= 2u;
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
              v5 = sub_1011D790(a3, v6, v15);
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
            a3 += 20;
            if ( ++v10 >= 8 )
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
// Address Name: SUB_1011FEA0
// ============================================================
//----- (1011FEA0) --------------------------------------------------------
int __thiscall sub_1011FEA0(int this, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  int v10; // ecx
  unsigned int v11; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v11 = 0;
  *(_DWORD *)(this + 81) = 0;
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
          if ( (*(_BYTE *)(this + 81) & 1) == 0 )
            *(_DWORD *)(this + 81) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_23;
          Int32 = sub_1011B450(this, (int)v4, a2);
          goto LABEL_22;
        case 2u:
          if ( (*(_DWORD *)(this + 81) & 2) == 0 )
            *(_DWORD *)(this + 81) |= 2u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 72));
          goto LABEL_22;
        case 3u:
          if ( (*(_DWORD *)(this + 81) & 4) == 0 )
            *(_DWORD *)(this + 81) |= 4u;
          if ( v4[1] > v4[2] )
            _wassert(
              L"position <= length",
              L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h",
              0x290u);
          v10 = v4[1];
          if ( v4[2] == v10 )
            return -2;
          *(_BYTE *)(this + 76) = *(_BYTE *)(v10 + *v4);
          ++v4[1];
          v6 = 0;
LABEL_23:
          v7 = a3;
          if ( v4[1] >= a3 )
            goto LABEL_24;
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 81) & 8) == 0 )
            *(_DWORD *)(this + 81) |= 8u;
          Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 77));
          goto LABEL_22;
        default:
          Int32 = TdrBuf::SkipField(v4, v11 & 0xF);
LABEL_22:
          v6 = Int32;
          if ( !Int32 )
            goto LABEL_23;
          return v6;
      }
    }
  }
LABEL_24:
  if ( v4[1] > v7 )
    return -34;
  return v6;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011E280
// ============================================================
//----- (1011E280) --------------------------------------------------------
int __thiscall sub_1011E280(int *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  int v6; // eax
  int v7; // esi
  _DWORD *i; // edi

  result = print_field(a2, a3, a4, "[count]", "%d", *this);
  if ( !result )
  {
    v6 = *this;
    if ( *this >= 0 )
    {
      if ( v6 <= 8 )
      {
        v7 = 0;
        if ( v6 <= 0 )
        {
          return 0;
        }
        else
        {
          for ( i = this + 1; ; i += 5 )
          {
            if ( !"[depotsRights]" )
              _wassert(
                L"NULL != variable",
                L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp",
                0x43u);
            result = sub_1024A140(a3);
            if ( result )
              break;
            result = Printf(a2, "%s[%u]%c", "[depotsRights]", v7, a4);
            if ( result )
              break;
            result = a3 >= 0 ? sub_1011D960(i, a2, a3 + 1, a4) : sub_1011D960(i, a2, a3, a4);
            if ( result )
              break;
            if ( ++v7 >= *this )
              return 0;
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



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101200E0
// ============================================================
//----- (101200E0) --------------------------------------------------------
int __thiscall sub_101200E0(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  if ( !"[commerceBoatInfo]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[commerceBoatInfo]", (char)a4);
    if ( !result )
    {
      if ( a3 >= 0 )
        result = sub_1011B670((_DWORD *)this, a2, a3 + 1, a4);
      else
        result = sub_1011B670((_DWORD *)this, a2, a3, a4);
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[contributeResPoint]", "%u", *(_DWORD *)(this + 72));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[challengeTimes]", "0x%02x", *(char *)(this + 76));
          if ( !result )
            return print_field(a2, a3, a4, "[refreshTimestamp]", "%d", *(_DWORD *)(this + 77));
        }
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_10118580
// ============================================================
//----- (10118580) --------------------------------------------------------
int __thiscall sub_10118580(int this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = sub_1024A410((int)a2, a4, (char)"[name]", this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[dbid]", "%I64u", *(_QWORD *)(this + 32));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[rtid]", "%u", *(_DWORD *)(this + 40));
      if ( !result )
        return print_field(a2, a3, a4, "[uin]", "%I64u", *(_QWORD *)(this + 44));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011D690
// ============================================================
//----- (1011D690) --------------------------------------------------------
int __thiscall sub_1011D690(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 4) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 4) & 1) == 0 )
            *(this + 4) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 4) & 2) == 0 )
            *(this + 4) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 4) & 4) == 0 )
            *(this + 4) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 4) & 8) == 0 )
            *(this + 4) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        default:
          VarInt = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = VarInt;
      if ( VarInt )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B300
// ============================================================
//----- (1011B300) --------------------------------------------------------
int __thiscall sub_1011B300(_DWORD *this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(this + 17) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 17) & 1) == 0 )
              *(this + 17) |= 1u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this);
            goto LABEL_22;
          case 2u:
            if ( (*(this + 17) & 2) == 0 )
              *(this + 17) |= 2u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 1);
            goto LABEL_22;
          case 3u:
            if ( (*(this + 17) & 4) == 0 )
              *(this + 17) |= 4u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 2);
            goto LABEL_22;
          case 4u:
            if ( (*(this + 17) & 8) == 0 )
              *(this + 17) |= 8u;
            VarUInt = TdrBuf::ReadVarInt(v4, this + 3);
            goto LABEL_22;
          case 5u:
            if ( (*(this + 17) & 0x10) == 0 )
              *(this + 17) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            VarUInt = sub_1011A940(this + 4, v4, a2);
LABEL_22:
            v6 = VarUInt;
            if ( VarUInt )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            VarUInt = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011D790
// ============================================================
//----- (1011D790) --------------------------------------------------------
int __thiscall sub_1011D790(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 16) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_19:
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
      switch ( v9 >> 4 )
      {
        case 1u:
          if ( (*(_BYTE *)(this + 16) & 1) == 0 )
            *(_DWORD *)(this + 16) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 16) & 2) == 0 )
            *(_DWORD *)(this + 16) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 16) & 4) == 0 )
            *(_DWORD *)(this + 16) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 16) & 8) == 0 )
            *(_DWORD *)(this + 16) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        default:
          Int32 = TdrBuf::SkipField(a2, v9 & 0xF);
          break;
      }
      v5 = Int32;
      if ( Int32 )
        return v5;
      v6 = v10;
      if ( a2[1] >= v10 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B450
// ============================================================
//----- (1011B450) --------------------------------------------------------
int __thiscall sub_1011B450(int this, int a2, unsigned int a3)
{
  unsigned int v3; // eax
  _DWORD *v4; // edi
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_DWORD *)(this + 68) = 0;
  v7 = v4[1] + v3;
  a3 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_24:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 68) & 1) == 0 )
              *(_DWORD *)(this + 68) |= 1u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
            goto LABEL_22;
          case 2u:
            if ( (*(_DWORD *)(this + 68) & 2) == 0 )
              *(_DWORD *)(this + 68) |= 2u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 4));
            goto LABEL_22;
          case 3u:
            if ( (*(_DWORD *)(this + 68) & 4) == 0 )
              *(_DWORD *)(this + 68) |= 4u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 8));
            goto LABEL_22;
          case 4u:
            if ( (*(_DWORD *)(this + 68) & 8) == 0 )
              *(_DWORD *)(this + 68) |= 8u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 12));
            goto LABEL_22;
          case 5u:
            if ( (*(_DWORD *)(this + 68) & 0x10) == 0 )
              *(_DWORD *)(this + 68) |= 0x10u;
            a2 = 0;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            if ( !a2 )
              goto LABEL_23;
            Int32 = sub_1011AAE0((unsigned int *)(this + 16), v4, a2);
LABEL_22:
            v6 = Int32;
            if ( Int32 )
              return v6;
LABEL_23:
            v7 = a3;
            if ( v4[1] >= a3 )
              goto LABEL_24;
            continue;
          default:
            Int32 = TdrBuf::SkipField(v4, v10 & 0xF);
            goto LABEL_22;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011D960
// ============================================================
//----- (1011D960) --------------------------------------------------------
int __thiscall sub_1011D960(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[depot]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[rights]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[fetchCount]", "%d", *(this + 2));
      if ( !result )
        return print_field(a2, a3, a4, "[curFetchCount]", "%d", *(this + 3));
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011B670
// ============================================================
//----- (1011B670) --------------------------------------------------------
int __thiscall sub_1011B670(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[commerceBoatId]", "%u", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[commerceBoatStartTime]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[commerceBoatStatus]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[levelId]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_structure((int)a2, a3, a4, (int)"[grabInfo]");
          if ( !result )
          {
            if ( a3 >= 0 )
              return sub_1011AD50(a2, a3 + 1, a4);
            else
              return sub_1011AD50(a2, a3, a4);
          }
        }
      }
    }
  }
  return result;
}
// 1011AD50: using guessed type _DWORD __stdcall sub_1011AD50(_DWORD, _DWORD, _DWORD);



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011A940
// ============================================================
//----- (1011A940) --------------------------------------------------------
int __thiscall sub_1011A940(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int VarULong; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // edi
  _DWORD *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  VarULong = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          VarULong = TdrBuf::ReadVarULong(v12, v11);
          if ( VarULong )
            return VarULong;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 2;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return VarULong;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        VarUInt = TdrBuf::ReadVarULong(v4, v5 + 9);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        VarUInt = TdrBuf::ReadVarUInt(v4, v5 + 11);
        goto LABEL_25;
      default:
        VarUInt = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        VarULong = VarUInt;
        if ( !VarUInt )
          goto LABEL_26;
        return VarULong;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011AAE0
// ============================================================
//----- (1011AAE0) --------------------------------------------------------
int __thiscall sub_1011AAE0(unsigned int *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  unsigned int *v5; // edi
  int Int64; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // edi
  _BYTE *v11; // ebx
  _DWORD *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // eax
  unsigned int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h] BYREF
  unsigned int *v18; // [esp+18h] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = this;
  Int64 = 0;
  v18 = this;
  v17 = 0;
  *(this + 12) = 0;
  v7 = a2[1] + v3;
  v15 = v7;
  if ( a2[1] >= v7 )
    goto LABEL_27;
  while ( 2 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v17);
    if ( result )
      return result;
    switch ( v17 >> 4 )
    {
      case 1u:
        if ( (v5[12] & 1) == 0 )
          v5[12] |= 1u;
        Int32 = TdrBuf::ReadInt32(v4, v5);
        goto LABEL_25;
      case 2u:
        if ( (v5[12] & 2) == 0 )
          v5[12] |= 2u;
        a3 = 0;
        result = TdrBuf::ReadInt32(v4, &a3);
        if ( result )
          return result;
        if ( !a3 )
          return -37;
        v10 = 0;
        v16 = v4[1];
        v11 = v18 + 1;
        v12 = a2;
        while ( 1 )
        {
          Int64 = TdrBuf::ReadInt64(v12, v11);
          if ( Int64 )
            return Int64;
          v12 = a2;
          v13 = a2[1];
          if ( v13 > a3 + v16 )
            return -34;
          if ( v13 == a3 + v16 )
            break;
          ++v10;
          v11 += 8;
          if ( v10 >= 4 )
          {
            v5 = v18;
            v4 = a2;
            goto LABEL_26;
          }
        }
        v4 = a2;
        v14 = v10 + 1;
        v5 = v18;
        *v18 = v14;
LABEL_26:
        v7 = v15;
        if ( v4[1] < v15 )
          continue;
LABEL_27:
        if ( v4[1] > v7 )
          return -34;
        return Int64;
      case 3u:
        if ( (v5[12] & 4) == 0 )
          v5[12] |= 4u;
        Int32 = TdrBuf::ReadInt64(v4, (_BYTE *)v5 + 36);
        goto LABEL_25;
      case 4u:
        if ( (v5[12] & 8) == 0 )
          v5[12] |= 8u;
        Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)v5 + 44);
        goto LABEL_25;
      default:
        Int32 = TdrBuf::SkipField(v4, v17 & 0xF);
LABEL_25:
        Int64 = Int32;
        if ( !Int32 )
          goto LABEL_26;
        return Int64;
    }
  }
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_1011AD50
// ============================================================
//----- (1011AD50) --------------------------------------------------------
int __thiscall sub_1011AD50(unsigned int *this, _DWORD *a2, int a3, char a4)
{
  _DWORD *v4; // esi
  int result; // eax
  int v7; // ecx
  unsigned int v8; // edi
  _QWORD *v9; // esi

  v4 = a2;
  result = print_field(a2, a3, a4, "[playerCount]", "%u", *this);
  if ( !result )
  {
    if ( *this <= 4 )
    {
      result = sub_1024A3B0(a2, a3, v7, "[playerId]", *this);
      if ( !result )
      {
        v8 = 0;
        if ( *this )
        {
          v9 = this + 1;
          while ( 1 )
          {
            result = Printf(a2, " %I64u", *v9);
            if ( result )
              break;
            ++v8;
            ++v9;
            if ( v8 >= *this )
            {
              v4 = a2;
              goto LABEL_10;
            }
          }
        }
        else
        {
LABEL_10:
          result = TdrBuf::WriteChar(v4, a4);
          if ( !result )
          {
            result = print_field(v4, a3, a4, "[ownGuildId]", "%I64u", *(_QWORD *)(this + 9));
            if ( !result )
              return print_field(v4, a3, a4, "[minTime]", "%u", *(this + 11));
          }
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
// 1011AD9F: variable 'v7' is possibly undefined



