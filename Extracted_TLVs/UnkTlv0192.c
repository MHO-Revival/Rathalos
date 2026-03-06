// ============================================================
// Name: TLV::UnkTlv0192::Read
// Address Name: SUB_101B4380
// ============================================================
//----- (101B4380) --------------------------------------------------------
int __thiscall sub_101B4380(void *this, unsigned int a2, unsigned int a3, _DWORD *a4)
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
    result = sub_101B4450((int)this, &v9, v8);
  else
    result = sub_101B6660((int)this, &v9, v8);
  if ( a4 )
    *a4 = v10;
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0192::Read_0xAA
// Address Name: SUB_101B4450
// ============================================================
//----- (101B4450) --------------------------------------------------------
int __thiscall sub_101B4450(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v5; // edx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int VarULong; // eax
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v10 = 0;
  *(_OWORD *)(this + 564) = 0;
  *(_QWORD *)(this + 580) = 0;
  v7 = v6[1] + v3;
  if ( v6[1] >= v7 )
  {
LABEL_512:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 564) & 1) == 0 )
              *(_DWORD *)(this + 564) |= 1u;
            VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)this);
            goto LABEL_510;
          case 2u:
            if ( (*(_DWORD *)(this + 564) & 2) == 0 )
              *(_DWORD *)(this + 564) |= 2u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 8));
            goto LABEL_510;
          case 6u:
            if ( (*(_DWORD *)(this + 564) & 4) == 0 )
              *(_DWORD *)(this + 564) |= 4u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 12));
            goto LABEL_510;
          case 7u:
            if ( (*(_DWORD *)(this + 564) & 8) == 0 )
              *(_DWORD *)(this + 564) |= 8u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 16));
            goto LABEL_510;
          case 0x10u:
            if ( (*(_DWORD *)(this + 564) & 0x10) == 0 )
              *(_DWORD *)(this + 564) |= 0x10u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 20));
            goto LABEL_510;
          case 0x11u:
            if ( (*(_DWORD *)(this + 564) & 0x20) == 0 )
              *(_DWORD *)(this + 564) |= 0x20u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 24));
            goto LABEL_510;
          case 0x1Au:
            if ( (*(_DWORD *)(this + 564) & 0x40) == 0 )
              *(_DWORD *)(this + 564) |= 0x40u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 28));
            goto LABEL_510;
          case 0x1Bu:
            if ( (*(_DWORD *)(this + 564) & 0x80) == 0 )
              *(_DWORD *)(this + 564) |= 0x80u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 32));
            goto LABEL_510;
          case 0x1Cu:
            if ( (*(_DWORD *)(this + 564) & 0x100) == 0 )
              *(_DWORD *)(this + 564) |= 0x100u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 36));
            goto LABEL_510;
          case 0x1Du:
            if ( (*(_DWORD *)(this + 564) & 0x200) == 0 )
              *(_DWORD *)(this + 564) |= 0x200u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 40));
            goto LABEL_510;
          case 0x20u:
            if ( (*(_DWORD *)(this + 564) & 0x400) == 0 )
              *(_DWORD *)(this + 564) |= 0x400u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 44));
            goto LABEL_510;
          case 0x4Cu:
            if ( (*(_DWORD *)(this + 564) & 0x800) == 0 )
              *(_DWORD *)(this + 564) |= 0x800u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 48));
            goto LABEL_510;
          case 0x4Du:
            if ( (*(_DWORD *)(this + 564) & 0x1000) == 0 )
              *(_DWORD *)(this + 564) |= 0x1000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 52));
            goto LABEL_510;
          case 0x4Eu:
            if ( (*(_DWORD *)(this + 564) & 0x2000) == 0 )
              *(_DWORD *)(this + 564) |= 0x2000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 56));
            goto LABEL_510;
          case 0x4Fu:
            if ( (*(_DWORD *)(this + 564) & 0x4000) == 0 )
              *(_DWORD *)(this + 564) |= 0x4000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 60));
            goto LABEL_510;
          case 0x56u:
            if ( (*(_DWORD *)(this + 564) & 0x8000) == 0 )
              *(_DWORD *)(this + 564) |= 0x8000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 64));
            goto LABEL_510;
          case 0x57u:
            if ( (*(_DWORD *)(this + 564) & 0x10000) == 0 )
              *(_DWORD *)(this + 564) |= 0x10000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 68));
            goto LABEL_510;
          case 0x5Au:
            if ( (*(_DWORD *)(this + 564) & 0x20000) == 0 )
              *(_DWORD *)(this + 564) |= 0x20000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 72));
            goto LABEL_510;
          case 0x5Bu:
            if ( (*(_DWORD *)(this + 564) & 0x40000) == 0 )
              *(_DWORD *)(this + 564) |= 0x40000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 76));
            goto LABEL_510;
          case 0x5Cu:
            if ( (*(_DWORD *)(this + 564) & 0x80000) == 0 )
              *(_DWORD *)(this + 564) |= 0x80000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 80));
            goto LABEL_510;
          case 0x5Du:
            if ( (*(_DWORD *)(this + 564) & 0x100000) == 0 )
              *(_DWORD *)(this + 564) |= 0x100000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 84));
            goto LABEL_510;
          case 0x5Eu:
            if ( (*(_DWORD *)(this + 564) & 0x200000) == 0 )
              *(_DWORD *)(this + 564) |= 0x200000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 88));
            goto LABEL_510;
          case 0x5Fu:
            if ( (*(_DWORD *)(this + 564) & 0x400000) == 0 )
              *(_DWORD *)(this + 564) |= 0x400000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 92));
            goto LABEL_510;
          case 0x60u:
            if ( (*(_DWORD *)(this + 564) & 0x800000) == 0 )
              *(_DWORD *)(this + 564) |= 0x800000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 96));
            goto LABEL_510;
          case 0x61u:
            if ( (*(_DWORD *)(this + 564) & 0x1000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x1000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 100));
            goto LABEL_510;
          case 0x62u:
            if ( (*(_DWORD *)(this + 564) & 0x2000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x2000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 104));
            goto LABEL_510;
          case 0x63u:
            if ( (*(_DWORD *)(this + 564) & 0x4000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x4000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 108));
            goto LABEL_510;
          case 0x6Cu:
            if ( (*(_DWORD *)(this + 564) & 0x8000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x8000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 112));
            goto LABEL_510;
          case 0x6Du:
            if ( (*(_DWORD *)(this + 564) & 0x10000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x10000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 116));
            goto LABEL_510;
          case 0x99u:
            if ( (*(_DWORD *)(this + 564) & 0x20000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x20000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 120));
            goto LABEL_510;
          case 0xADu:
            if ( (*(_DWORD *)(this + 564) & 0x40000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x40000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 124));
            goto LABEL_510;
          case 0xAEu:
            if ( *(int *)(this + 564) >= 0 )
              *(_DWORD *)(this + 564) |= 0x80000000;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 128));
            goto LABEL_510;
          case 0xB4u:
            if ( (*(_BYTE *)(this + 568) & 1) == 0 )
              *(_DWORD *)(this + 568) |= 1u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 132));
            goto LABEL_510;
          case 0xC8u:
            if ( (*(_DWORD *)(this + 568) & 2) == 0 )
              *(_DWORD *)(this + 568) |= 2u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 136));
            goto LABEL_510;
          case 0xC9u:
            if ( (*(_DWORD *)(this + 568) & 4) == 0 )
              *(_DWORD *)(this + 568) |= 4u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 140));
            goto LABEL_510;
          case 0xCAu:
            if ( (*(_DWORD *)(this + 568) & 8) == 0 )
              *(_DWORD *)(this + 568) |= 8u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 142));
            goto LABEL_510;
          case 0xCBu:
            if ( (*(_DWORD *)(this + 568) & 0x10) == 0 )
              *(_DWORD *)(this + 568) |= 0x10u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 146));
            goto LABEL_510;
          case 0xCCu:
            if ( (*(_DWORD *)(this + 568) & 0x20) == 0 )
              *(_DWORD *)(this + 568) |= 0x20u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 150));
            goto LABEL_510;
          case 0xCDu:
            if ( (*(_DWORD *)(this + 568) & 0x40) == 0 )
              *(_DWORD *)(this + 568) |= 0x40u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 154));
            goto LABEL_510;
          case 0xCEu:
            if ( (*(_DWORD *)(this + 568) & 0x80) == 0 )
              *(_DWORD *)(this + 568) |= 0x80u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 158));
            goto LABEL_510;
          case 0xCFu:
            if ( (*(_DWORD *)(this + 568) & 0x100) == 0 )
              *(_DWORD *)(this + 568) |= 0x100u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 162));
            goto LABEL_510;
          case 0xD0u:
            if ( (*(_DWORD *)(this + 568) & 0x200) == 0 )
              *(_DWORD *)(this + 568) |= 0x200u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 166));
            goto LABEL_510;
          case 0xD1u:
            if ( (*(_DWORD *)(this + 568) & 0x400) == 0 )
              *(_DWORD *)(this + 568) |= 0x400u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 170));
            goto LABEL_510;
          case 0xD4u:
            if ( (*(_DWORD *)(this + 568) & 0x800) == 0 )
              *(_DWORD *)(this + 568) |= 0x800u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 174));
            goto LABEL_510;
          case 0xDCu:
            if ( (*(_DWORD *)(this + 568) & 0x1000) == 0 )
              *(_DWORD *)(this + 568) |= 0x1000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 178));
            goto LABEL_510;
          case 0xDDu:
            if ( (*(_DWORD *)(this + 568) & 0x2000) == 0 )
              *(_DWORD *)(this + 568) |= 0x2000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 182));
            goto LABEL_510;
          case 0xE3u:
            if ( (*(_DWORD *)(this + 568) & 0x4000) == 0 )
              *(_DWORD *)(this + 568) |= 0x4000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 186));
            goto LABEL_510;
          case 0xE4u:
            if ( (*(_DWORD *)(this + 568) & 0x8000) == 0 )
              *(_DWORD *)(this + 568) |= 0x8000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 188));
            goto LABEL_510;
          case 0xE5u:
            if ( (*(_DWORD *)(this + 568) & 0x10000) == 0 )
              *(_DWORD *)(this + 568) |= 0x10000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 190));
            goto LABEL_510;
          case 0xE6u:
            if ( (*(_DWORD *)(this + 568) & 0x20000) == 0 )
              *(_DWORD *)(this + 568) |= 0x20000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 192));
            goto LABEL_510;
          case 0xE7u:
            if ( (*(_DWORD *)(this + 568) & 0x40000) == 0 )
              *(_DWORD *)(this + 568) |= 0x40000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 196));
            goto LABEL_510;
          case 0xF1u:
            if ( (*(_DWORD *)(this + 568) & 0x80000) == 0 )
              *(_DWORD *)(this + 568) |= 0x80000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 200));
            goto LABEL_510;
          case 0xF3u:
            if ( (*(_DWORD *)(this + 568) & 0x100000) == 0 )
              *(_DWORD *)(this + 568) |= 0x100000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 204));
            goto LABEL_510;
          case 0xFCu:
            if ( (*(_DWORD *)(this + 568) & 0x200000) == 0 )
              *(_DWORD *)(this + 568) |= 0x200000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 208));
            goto LABEL_510;
          case 0xFDu:
            if ( (*(_DWORD *)(this + 568) & 0x400000) == 0 )
              *(_DWORD *)(this + 568) |= 0x400000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 210));
            goto LABEL_510;
          case 0xFEu:
            if ( (*(_DWORD *)(this + 568) & 0x800000) == 0 )
              *(_DWORD *)(this + 568) |= 0x800000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 212));
            goto LABEL_510;
          case 0xFFu:
            if ( (*(_DWORD *)(this + 568) & 0x1000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x1000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 214));
            goto LABEL_510;
          case 0x100u:
            if ( (*(_DWORD *)(this + 568) & 0x2000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x2000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 216));
            goto LABEL_510;
          case 0x101u:
            if ( (*(_DWORD *)(this + 568) & 0x4000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x4000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 218));
            goto LABEL_510;
          case 0x102u:
            if ( (*(_DWORD *)(this + 568) & 0x8000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x8000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 220));
            goto LABEL_510;
          case 0x103u:
            if ( (*(_DWORD *)(this + 568) & 0x10000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x10000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 222));
            goto LABEL_510;
          case 0x104u:
            if ( (*(_DWORD *)(this + 568) & 0x20000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x20000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 224));
            goto LABEL_510;
          case 0x105u:
            if ( (*(_DWORD *)(this + 568) & 0x40000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x40000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 226));
            goto LABEL_510;
          case 0x106u:
            if ( *(int *)(this + 568) >= 0 )
              *(_DWORD *)(this + 568) |= 0x80000000;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 228));
            goto LABEL_510;
          case 0x107u:
            if ( (*(_BYTE *)(this + 572) & 1) == 0 )
              *(_DWORD *)(this + 572) |= 1u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 230));
            goto LABEL_510;
          case 0x108u:
            if ( (*(_DWORD *)(this + 572) & 2) == 0 )
              *(_DWORD *)(this + 572) |= 2u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 232));
            goto LABEL_510;
          case 0x109u:
            if ( (*(_DWORD *)(this + 572) & 4) == 0 )
              *(_DWORD *)(this + 572) |= 4u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 234));
            goto LABEL_510;
          case 0x10Au:
            if ( (*(_DWORD *)(this + 572) & 8) == 0 )
              *(_DWORD *)(this + 572) |= 8u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 236));
            goto LABEL_510;
          case 0x10Bu:
            if ( (*(_DWORD *)(this + 572) & 0x10) == 0 )
              *(_DWORD *)(this + 572) |= 0x10u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 238));
            goto LABEL_510;
          case 0x10Cu:
            if ( (*(_DWORD *)(this + 572) & 0x20) == 0 )
              *(_DWORD *)(this + 572) |= 0x20u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 240));
            goto LABEL_510;
          case 0x10Du:
            if ( (*(_DWORD *)(this + 572) & 0x40) == 0 )
              *(_DWORD *)(this + 572) |= 0x40u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 242));
            goto LABEL_510;
          case 0x10Eu:
            if ( (*(_DWORD *)(this + 572) & 0x80) == 0 )
              *(_DWORD *)(this + 572) |= 0x80u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 244));
            goto LABEL_510;
          case 0x10Fu:
            if ( (*(_DWORD *)(this + 572) & 0x100) == 0 )
              *(_DWORD *)(this + 572) |= 0x100u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 246));
            goto LABEL_510;
          case 0x110u:
            if ( (*(_DWORD *)(this + 572) & 0x200) == 0 )
              *(_DWORD *)(this + 572) |= 0x200u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 248));
            goto LABEL_510;
          case 0x111u:
            if ( (*(_DWORD *)(this + 572) & 0x400) == 0 )
              *(_DWORD *)(this + 572) |= 0x400u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 250));
            goto LABEL_510;
          case 0x112u:
            if ( (*(_DWORD *)(this + 572) & 0x800) == 0 )
              *(_DWORD *)(this + 572) |= 0x800u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 252));
            goto LABEL_510;
          case 0x113u:
            if ( (*(_DWORD *)(this + 572) & 0x1000) == 0 )
              *(_DWORD *)(this + 572) |= 0x1000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 254));
            goto LABEL_510;
          case 0x114u:
            if ( (*(_DWORD *)(this + 572) & 0x2000) == 0 )
              *(_DWORD *)(this + 572) |= 0x2000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 256));
            goto LABEL_510;
          case 0x11Cu:
            if ( (*(_DWORD *)(this + 572) & 0x4000) == 0 )
              *(_DWORD *)(this + 572) |= 0x4000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 258));
            goto LABEL_510;
          case 0x11Fu:
            if ( (*(_DWORD *)(this + 572) & 0x8000) == 0 )
              *(_DWORD *)(this + 572) |= 0x8000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 260));
            goto LABEL_510;
          case 0x120u:
            if ( (*(_DWORD *)(this + 572) & 0x10000) == 0 )
              *(_DWORD *)(this + 572) |= 0x10000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 264));
            goto LABEL_510;
          case 0x121u:
            if ( (*(_DWORD *)(this + 572) & 0x20000) == 0 )
              *(_DWORD *)(this + 572) |= 0x20000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 268));
            goto LABEL_510;
          case 0x122u:
            if ( (*(_DWORD *)(this + 572) & 0x40000) == 0 )
              *(_DWORD *)(this + 572) |= 0x40000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 272));
            goto LABEL_510;
          case 0x123u:
            if ( (*(_DWORD *)(this + 572) & 0x80000) == 0 )
              *(_DWORD *)(this + 572) |= 0x80000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 276));
            goto LABEL_510;
          case 0x124u:
            if ( (*(_DWORD *)(this + 572) & 0x100000) == 0 )
              *(_DWORD *)(this + 572) |= 0x100000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 280));
            goto LABEL_510;
          case 0x125u:
            if ( (*(_DWORD *)(this + 572) & 0x200000) == 0 )
              *(_DWORD *)(this + 572) |= 0x200000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 284));
            goto LABEL_510;
          case 0x126u:
            if ( (*(_DWORD *)(this + 572) & 0x400000) == 0 )
              *(_DWORD *)(this + 572) |= 0x400000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 288));
            goto LABEL_510;
          case 0x127u:
            if ( (*(_DWORD *)(this + 572) & 0x800000) == 0 )
              *(_DWORD *)(this + 572) |= 0x800000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 292));
            goto LABEL_510;
          case 0x128u:
            if ( (*(_DWORD *)(this + 572) & 0x1000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x1000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 296));
            goto LABEL_510;
          case 0x129u:
            if ( (*(_DWORD *)(this + 572) & 0x2000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x2000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 300));
            goto LABEL_510;
          case 0x12Au:
            if ( (*(_DWORD *)(this + 572) & 0x4000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x4000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 304));
            goto LABEL_510;
          case 0x12Bu:
            if ( (*(_DWORD *)(this + 572) & 0x8000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x8000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 308));
            goto LABEL_510;
          case 0x12Cu:
            if ( (*(_DWORD *)(this + 572) & 0x10000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x10000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 310));
            goto LABEL_510;
          case 0x12Du:
            if ( (*(_DWORD *)(this + 572) & 0x20000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x20000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 312));
            goto LABEL_510;
          case 0x12Eu:
            if ( (*(_DWORD *)(this + 572) & 0x40000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x40000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 314));
            goto LABEL_510;
          case 0x12Fu:
            if ( *(int *)(this + 572) >= 0 )
              *(_DWORD *)(this + 572) |= 0x80000000;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 316));
            goto LABEL_510;
          case 0x131u:
            if ( (*(_BYTE *)(this + 576) & 1) == 0 )
              *(_DWORD *)(this + 576) |= 1u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 320));
            goto LABEL_510;
          case 0x132u:
            if ( (*(_DWORD *)(this + 576) & 2) == 0 )
              *(_DWORD *)(this + 576) |= 2u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 322));
            goto LABEL_510;
          case 0x138u:
            if ( (*(_DWORD *)(this + 576) & 4) == 0 )
              *(_DWORD *)(this + 576) |= 4u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 326));
            goto LABEL_510;
          case 0x139u:
            if ( (*(_DWORD *)(this + 576) & 8) == 0 )
              *(_DWORD *)(this + 576) |= 8u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 330));
            goto LABEL_510;
          case 0x13Au:
            if ( (*(_DWORD *)(this + 576) & 0x10) == 0 )
              *(_DWORD *)(this + 576) |= 0x10u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 334));
            goto LABEL_510;
          case 0x13Bu:
            if ( (*(_DWORD *)(this + 576) & 0x20) == 0 )
              *(_DWORD *)(this + 576) |= 0x20u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 338));
            goto LABEL_510;
          case 0x142u:
            if ( (*(_DWORD *)(this + 576) & 0x40) == 0 )
              *(_DWORD *)(this + 576) |= 0x40u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 342));
            goto LABEL_510;
          case 0x143u:
            if ( (*(_DWORD *)(this + 576) & 0x80) == 0 )
              *(_DWORD *)(this + 576) |= 0x80u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 346));
            goto LABEL_510;
          case 0x144u:
            if ( (*(_DWORD *)(this + 576) & 0x100) == 0 )
              *(_DWORD *)(this + 576) |= 0x100u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 350));
            goto LABEL_510;
          case 0x146u:
            if ( (*(_DWORD *)(this + 576) & 0x200) == 0 )
              *(_DWORD *)(this + 576) |= 0x200u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 354));
            goto LABEL_510;
          case 0x149u:
            if ( (*(_DWORD *)(this + 576) & 0x400) == 0 )
              *(_DWORD *)(this + 576) |= 0x400u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 358));
            goto LABEL_510;
          case 0x14Au:
            if ( (*(_DWORD *)(this + 576) & 0x800) == 0 )
              *(_DWORD *)(this + 576) |= 0x800u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 360));
            goto LABEL_510;
          case 0x14Bu:
            if ( (*(_DWORD *)(this + 576) & 0x1000) == 0 )
              *(_DWORD *)(this + 576) |= 0x1000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 362));
            goto LABEL_510;
          case 0x14Cu:
            if ( (*(_DWORD *)(this + 576) & 0x2000) == 0 )
              *(_DWORD *)(this + 576) |= 0x2000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 364));
            goto LABEL_510;
          case 0x14Du:
            if ( (*(_DWORD *)(this + 576) & 0x4000) == 0 )
              *(_DWORD *)(this + 576) |= 0x4000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 366));
            goto LABEL_510;
          case 0x14Eu:
            if ( (*(_DWORD *)(this + 576) & 0x8000) == 0 )
              *(_DWORD *)(this + 576) |= 0x8000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 368));
            goto LABEL_510;
          case 0x14Fu:
            if ( (*(_DWORD *)(this + 576) & 0x10000) == 0 )
              *(_DWORD *)(this + 576) |= 0x10000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 370));
            goto LABEL_510;
          case 0x150u:
            if ( (*(_DWORD *)(this + 576) & 0x20000) == 0 )
              *(_DWORD *)(this + 576) |= 0x20000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 372));
            goto LABEL_510;
          case 0x151u:
            if ( (*(_DWORD *)(this + 576) & 0x40000) == 0 )
              *(_DWORD *)(this + 576) |= 0x40000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 374));
            goto LABEL_510;
          case 0x152u:
            if ( (*(_DWORD *)(this + 576) & 0x80000) == 0 )
              *(_DWORD *)(this + 576) |= 0x80000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 376));
            goto LABEL_510;
          case 0x153u:
            if ( (*(_DWORD *)(this + 576) & 0x100000) == 0 )
              *(_DWORD *)(this + 576) |= 0x100000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 378));
            goto LABEL_510;
          case 0x154u:
            if ( (*(_DWORD *)(this + 576) & 0x200000) == 0 )
              *(_DWORD *)(this + 576) |= 0x200000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 380));
            goto LABEL_510;
          case 0x155u:
            if ( (*(_DWORD *)(this + 576) & 0x400000) == 0 )
              *(_DWORD *)(this + 576) |= 0x400000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 382));
            goto LABEL_510;
          case 0x156u:
            if ( (*(_DWORD *)(this + 576) & 0x800000) == 0 )
              *(_DWORD *)(this + 576) |= 0x800000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 384));
            goto LABEL_510;
          case 0x157u:
            if ( (*(_DWORD *)(this + 576) & 0x1000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x1000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 386));
            goto LABEL_510;
          case 0x158u:
            if ( (*(_DWORD *)(this + 576) & 0x2000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x2000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 388));
            goto LABEL_510;
          case 0x159u:
            if ( (*(_DWORD *)(this + 576) & 0x4000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x4000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 390));
            goto LABEL_510;
          case 0x15Au:
            if ( (*(_DWORD *)(this + 576) & 0x8000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x8000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 392));
            goto LABEL_510;
          case 0x15Bu:
            if ( (*(_DWORD *)(this + 576) & 0x10000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x10000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 394));
            goto LABEL_510;
          case 0x15Cu:
            if ( (*(_DWORD *)(this + 576) & 0x20000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x20000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 396));
            goto LABEL_510;
          case 0x15Du:
            if ( (*(_DWORD *)(this + 576) & 0x40000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x40000000u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 398));
            goto LABEL_510;
          case 0x15Eu:
            if ( *(int *)(this + 576) >= 0 )
              *(_DWORD *)(this + 576) |= 0x80000000;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 400));
            goto LABEL_510;
          case 0x16Cu:
            if ( (*(_BYTE *)(this + 580) & 1) == 0 )
              *(_DWORD *)(this + 580) |= 1u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 402));
            goto LABEL_510;
          case 0x16Du:
            if ( (*(_DWORD *)(this + 580) & 2) == 0 )
              *(_DWORD *)(this + 580) |= 2u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 406));
            goto LABEL_510;
          case 0x16Eu:
            if ( (*(_DWORD *)(this + 580) & 4) == 0 )
              *(_DWORD *)(this + 580) |= 4u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 410));
            goto LABEL_510;
          case 0x16Fu:
            if ( (*(_DWORD *)(this + 580) & 8) == 0 )
              *(_DWORD *)(this + 580) |= 8u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 414));
            goto LABEL_510;
          case 0x170u:
            if ( (*(_DWORD *)(this + 580) & 0x10) == 0 )
              *(_DWORD *)(this + 580) |= 0x10u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 418));
            goto LABEL_510;
          case 0x171u:
            if ( (*(_DWORD *)(this + 580) & 0x20) == 0 )
              *(_DWORD *)(this + 580) |= 0x20u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 422));
            goto LABEL_510;
          case 0x172u:
            if ( (*(_DWORD *)(this + 580) & 0x40) == 0 )
              *(_DWORD *)(this + 580) |= 0x40u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 426));
            goto LABEL_510;
          case 0x173u:
            if ( (*(_DWORD *)(this + 580) & 0x80) == 0 )
              *(_DWORD *)(this + 580) |= 0x80u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 430));
            goto LABEL_510;
          case 0x174u:
            if ( (*(_DWORD *)(this + 580) & 0x100) == 0 )
              *(_DWORD *)(this + 580) |= 0x100u;
            VarULong = TdrBuf::ReadVarULong(v6, (_DWORD *)(this + 434));
            goto LABEL_510;
          case 0x175u:
            if ( (*(_DWORD *)(this + 580) & 0x200) == 0 )
              *(_DWORD *)(this + 580) |= 0x200u;
            v5 = TdrBuf::ReadInt32(v6, &a2);
            if ( v5 )
              return v5;
            *(_DWORD *)(this + 442) = a2;
            goto LABEL_511;
          case 0x176u:
            if ( (*(_DWORD *)(this + 580) & 0x400) == 0 )
              *(_DWORD *)(this + 580) |= 0x400u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 446));
            goto LABEL_510;
          case 0x177u:
            if ( (*(_DWORD *)(this + 580) & 0x800) == 0 )
              *(_DWORD *)(this + 580) |= 0x800u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 450));
            goto LABEL_510;
          case 0x178u:
            if ( (*(_DWORD *)(this + 580) & 0x1000) == 0 )
              *(_DWORD *)(this + 580) |= 0x1000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 454));
            goto LABEL_510;
          case 0x179u:
            if ( (*(_DWORD *)(this + 580) & 0x2000) == 0 )
              *(_DWORD *)(this + 580) |= 0x2000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 458));
            goto LABEL_510;
          case 0x17Au:
            if ( (*(_DWORD *)(this + 580) & 0x4000) == 0 )
              *(_DWORD *)(this + 580) |= 0x4000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 462));
            goto LABEL_510;
          case 0x17Bu:
            if ( (*(_DWORD *)(this + 580) & 0x8000) == 0 )
              *(_DWORD *)(this + 580) |= 0x8000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 466));
            goto LABEL_510;
          case 0x17Cu:
            if ( (*(_DWORD *)(this + 580) & 0x10000) == 0 )
              *(_DWORD *)(this + 580) |= 0x10000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 470));
            goto LABEL_510;
          case 0x17Du:
            if ( (*(_DWORD *)(this + 580) & 0x20000) == 0 )
              *(_DWORD *)(this + 580) |= 0x20000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 474));
            goto LABEL_510;
          case 0x17Fu:
            if ( (*(_DWORD *)(this + 580) & 0x40000) == 0 )
              *(_DWORD *)(this + 580) |= 0x40000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 478));
            goto LABEL_510;
          case 0x181u:
            if ( (*(_DWORD *)(this + 580) & 0x80000) == 0 )
              *(_DWORD *)(this + 580) |= 0x80000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 482));
            goto LABEL_510;
          case 0x182u:
            if ( (*(_DWORD *)(this + 580) & 0x100000) == 0 )
              *(_DWORD *)(this + 580) |= 0x100000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 486));
            goto LABEL_510;
          case 0x183u:
            if ( (*(_DWORD *)(this + 580) & 0x200000) == 0 )
              *(_DWORD *)(this + 580) |= 0x200000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 490));
            goto LABEL_510;
          case 0x185u:
            if ( (*(_DWORD *)(this + 580) & 0x400000) == 0 )
              *(_DWORD *)(this + 580) |= 0x400000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 494));
            goto LABEL_510;
          case 0x186u:
            if ( (*(_DWORD *)(this + 580) & 0x800000) == 0 )
              *(_DWORD *)(this + 580) |= 0x800000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 498));
            goto LABEL_510;
          case 0x187u:
            if ( (*(_DWORD *)(this + 580) & 0x1000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x1000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 502));
            goto LABEL_510;
          case 0x188u:
            if ( (*(_DWORD *)(this + 580) & 0x2000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x2000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 506));
            goto LABEL_510;
          case 0x190u:
            if ( (*(_DWORD *)(this + 580) & 0x4000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x4000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 510));
            goto LABEL_510;
          case 0x191u:
            if ( (*(_DWORD *)(this + 580) & 0x8000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x8000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 514));
            goto LABEL_510;
          case 0x192u:
            if ( (*(_DWORD *)(this + 580) & 0x10000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x10000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 518));
            goto LABEL_510;
          case 0x193u:
            if ( (*(_DWORD *)(this + 580) & 0x20000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x20000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 522));
            goto LABEL_510;
          case 0x194u:
            if ( (*(_DWORD *)(this + 580) & 0x40000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x40000000u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 526));
            goto LABEL_510;
          case 0x195u:
            if ( *(int *)(this + 580) >= 0 )
              *(_DWORD *)(this + 580) |= 0x80000000;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 530));
            goto LABEL_510;
          case 0x196u:
            if ( (*(_BYTE *)(this + 584) & 1) == 0 )
              *(_DWORD *)(this + 584) |= 1u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 534));
            goto LABEL_510;
          case 0x197u:
            if ( (*(_DWORD *)(this + 584) & 2) == 0 )
              *(_DWORD *)(this + 584) |= 2u;
            VarULong = TdrBuf::ReadVarShort(v6, (_WORD *)(this + 538));
            goto LABEL_510;
          case 0x198u:
            if ( (*(_DWORD *)(this + 584) & 4) == 0 )
              *(_DWORD *)(this + 584) |= 4u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 540));
            goto LABEL_510;
          case 0x199u:
            if ( (*(_DWORD *)(this + 584) & 8) == 0 )
              *(_DWORD *)(this + 584) |= 8u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 544));
            goto LABEL_510;
          case 0x19Au:
            if ( (*(_DWORD *)(this + 584) & 0x10) == 0 )
              *(_DWORD *)(this + 584) |= 0x10u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 548));
            goto LABEL_510;
          case 0x19Cu:
            if ( (*(_DWORD *)(this + 584) & 0x20) == 0 )
              *(_DWORD *)(this + 584) |= 0x20u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 552));
            goto LABEL_510;
          case 0x19Du:
            if ( (*(_DWORD *)(this + 584) & 0x40) == 0 )
              *(_DWORD *)(this + 584) |= 0x40u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 556));
            goto LABEL_510;
          case 0x19Eu:
            if ( (*(_DWORD *)(this + 584) & 0x80) == 0 )
              *(_DWORD *)(this + 584) |= 0x80u;
            VarULong = TdrBuf::ReadVarInt(v6, (int *)(this + 560));
            goto LABEL_510;
          default:
            VarULong = TdrBuf::SkipField(v6, v10 & 0xF);
LABEL_510:
            v5 = VarULong;
            if ( VarULong )
              return v5;
LABEL_511:
            if ( v6[1] >= v7 )
              goto LABEL_512;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0192::Read_0x99
// Address Name: SUB_101B6660
// ============================================================
//----- (101B6660) --------------------------------------------------------
int __thiscall sub_101B6660(int this, _DWORD *a2, int a3)
{
  int v3; // ebx
  int v5; // edx
  _DWORD *v6; // edi
  unsigned int v7; // ebx
  int result; // eax
  int Int64; // eax
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v3 = a3;
  v5 = 0;
  v6 = a2;
  v10 = 0;
  *(_OWORD *)(this + 564) = 0;
  *(_QWORD *)(this + 580) = 0;
  v7 = v6[1] + v3;
  if ( v6[1] >= v7 )
  {
LABEL_512:
    if ( v6[1] > v7 )
      return -34;
    return v5;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v6, &v10);
      if ( !result )
      {
        switch ( v10 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 564) & 1) == 0 )
              *(_DWORD *)(this + 564) |= 1u;
            Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)this);
            goto LABEL_510;
          case 2u:
            if ( (*(_DWORD *)(this + 564) & 2) == 0 )
              *(_DWORD *)(this + 564) |= 2u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 8));
            goto LABEL_510;
          case 6u:
            if ( (*(_DWORD *)(this + 564) & 4) == 0 )
              *(_DWORD *)(this + 564) |= 4u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 12));
            goto LABEL_510;
          case 7u:
            if ( (*(_DWORD *)(this + 564) & 8) == 0 )
              *(_DWORD *)(this + 564) |= 8u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 16));
            goto LABEL_510;
          case 0x10u:
            if ( (*(_DWORD *)(this + 564) & 0x10) == 0 )
              *(_DWORD *)(this + 564) |= 0x10u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 20));
            goto LABEL_510;
          case 0x11u:
            if ( (*(_DWORD *)(this + 564) & 0x20) == 0 )
              *(_DWORD *)(this + 564) |= 0x20u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 24));
            goto LABEL_510;
          case 0x1Au:
            if ( (*(_DWORD *)(this + 564) & 0x40) == 0 )
              *(_DWORD *)(this + 564) |= 0x40u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 28));
            goto LABEL_510;
          case 0x1Bu:
            if ( (*(_DWORD *)(this + 564) & 0x80) == 0 )
              *(_DWORD *)(this + 564) |= 0x80u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 32));
            goto LABEL_510;
          case 0x1Cu:
            if ( (*(_DWORD *)(this + 564) & 0x100) == 0 )
              *(_DWORD *)(this + 564) |= 0x100u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 36));
            goto LABEL_510;
          case 0x1Du:
            if ( (*(_DWORD *)(this + 564) & 0x200) == 0 )
              *(_DWORD *)(this + 564) |= 0x200u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 40));
            goto LABEL_510;
          case 0x20u:
            if ( (*(_DWORD *)(this + 564) & 0x400) == 0 )
              *(_DWORD *)(this + 564) |= 0x400u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 44));
            goto LABEL_510;
          case 0x4Cu:
            if ( (*(_DWORD *)(this + 564) & 0x800) == 0 )
              *(_DWORD *)(this + 564) |= 0x800u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 48));
            goto LABEL_510;
          case 0x4Du:
            if ( (*(_DWORD *)(this + 564) & 0x1000) == 0 )
              *(_DWORD *)(this + 564) |= 0x1000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 52));
            goto LABEL_510;
          case 0x4Eu:
            if ( (*(_DWORD *)(this + 564) & 0x2000) == 0 )
              *(_DWORD *)(this + 564) |= 0x2000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 56));
            goto LABEL_510;
          case 0x4Fu:
            if ( (*(_DWORD *)(this + 564) & 0x4000) == 0 )
              *(_DWORD *)(this + 564) |= 0x4000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 60));
            goto LABEL_510;
          case 0x56u:
            if ( (*(_DWORD *)(this + 564) & 0x8000) == 0 )
              *(_DWORD *)(this + 564) |= 0x8000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 64));
            goto LABEL_510;
          case 0x57u:
            if ( (*(_DWORD *)(this + 564) & 0x10000) == 0 )
              *(_DWORD *)(this + 564) |= 0x10000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 68));
            goto LABEL_510;
          case 0x5Au:
            if ( (*(_DWORD *)(this + 564) & 0x20000) == 0 )
              *(_DWORD *)(this + 564) |= 0x20000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 72));
            goto LABEL_510;
          case 0x5Bu:
            if ( (*(_DWORD *)(this + 564) & 0x40000) == 0 )
              *(_DWORD *)(this + 564) |= 0x40000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 76));
            goto LABEL_510;
          case 0x5Cu:
            if ( (*(_DWORD *)(this + 564) & 0x80000) == 0 )
              *(_DWORD *)(this + 564) |= 0x80000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 80));
            goto LABEL_510;
          case 0x5Du:
            if ( (*(_DWORD *)(this + 564) & 0x100000) == 0 )
              *(_DWORD *)(this + 564) |= 0x100000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 84));
            goto LABEL_510;
          case 0x5Eu:
            if ( (*(_DWORD *)(this + 564) & 0x200000) == 0 )
              *(_DWORD *)(this + 564) |= 0x200000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 88));
            goto LABEL_510;
          case 0x5Fu:
            if ( (*(_DWORD *)(this + 564) & 0x400000) == 0 )
              *(_DWORD *)(this + 564) |= 0x400000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 92));
            goto LABEL_510;
          case 0x60u:
            if ( (*(_DWORD *)(this + 564) & 0x800000) == 0 )
              *(_DWORD *)(this + 564) |= 0x800000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 96));
            goto LABEL_510;
          case 0x61u:
            if ( (*(_DWORD *)(this + 564) & 0x1000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x1000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 100));
            goto LABEL_510;
          case 0x62u:
            if ( (*(_DWORD *)(this + 564) & 0x2000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x2000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 104));
            goto LABEL_510;
          case 0x63u:
            if ( (*(_DWORD *)(this + 564) & 0x4000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x4000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 108));
            goto LABEL_510;
          case 0x6Cu:
            if ( (*(_DWORD *)(this + 564) & 0x8000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x8000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 112));
            goto LABEL_510;
          case 0x6Du:
            if ( (*(_DWORD *)(this + 564) & 0x10000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x10000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 116));
            goto LABEL_510;
          case 0x99u:
            if ( (*(_DWORD *)(this + 564) & 0x20000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x20000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 120));
            goto LABEL_510;
          case 0xADu:
            if ( (*(_DWORD *)(this + 564) & 0x40000000) == 0 )
              *(_DWORD *)(this + 564) |= 0x40000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 124));
            goto LABEL_510;
          case 0xAEu:
            if ( *(int *)(this + 564) >= 0 )
              *(_DWORD *)(this + 564) |= 0x80000000;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 128));
            goto LABEL_510;
          case 0xB4u:
            if ( (*(_BYTE *)(this + 568) & 1) == 0 )
              *(_DWORD *)(this + 568) |= 1u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 132));
            goto LABEL_510;
          case 0xC8u:
            if ( (*(_DWORD *)(this + 568) & 2) == 0 )
              *(_DWORD *)(this + 568) |= 2u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 136));
            goto LABEL_510;
          case 0xC9u:
            if ( (*(_DWORD *)(this + 568) & 4) == 0 )
              *(_DWORD *)(this + 568) |= 4u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 140));
            goto LABEL_510;
          case 0xCAu:
            if ( (*(_DWORD *)(this + 568) & 8) == 0 )
              *(_DWORD *)(this + 568) |= 8u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 142));
            goto LABEL_510;
          case 0xCBu:
            if ( (*(_DWORD *)(this + 568) & 0x10) == 0 )
              *(_DWORD *)(this + 568) |= 0x10u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 146));
            goto LABEL_510;
          case 0xCCu:
            if ( (*(_DWORD *)(this + 568) & 0x20) == 0 )
              *(_DWORD *)(this + 568) |= 0x20u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 150));
            goto LABEL_510;
          case 0xCDu:
            if ( (*(_DWORD *)(this + 568) & 0x40) == 0 )
              *(_DWORD *)(this + 568) |= 0x40u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 154));
            goto LABEL_510;
          case 0xCEu:
            if ( (*(_DWORD *)(this + 568) & 0x80) == 0 )
              *(_DWORD *)(this + 568) |= 0x80u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 158));
            goto LABEL_510;
          case 0xCFu:
            if ( (*(_DWORD *)(this + 568) & 0x100) == 0 )
              *(_DWORD *)(this + 568) |= 0x100u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 162));
            goto LABEL_510;
          case 0xD0u:
            if ( (*(_DWORD *)(this + 568) & 0x200) == 0 )
              *(_DWORD *)(this + 568) |= 0x200u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 166));
            goto LABEL_510;
          case 0xD1u:
            if ( (*(_DWORD *)(this + 568) & 0x400) == 0 )
              *(_DWORD *)(this + 568) |= 0x400u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 170));
            goto LABEL_510;
          case 0xD4u:
            if ( (*(_DWORD *)(this + 568) & 0x800) == 0 )
              *(_DWORD *)(this + 568) |= 0x800u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 174));
            goto LABEL_510;
          case 0xDCu:
            if ( (*(_DWORD *)(this + 568) & 0x1000) == 0 )
              *(_DWORD *)(this + 568) |= 0x1000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 178));
            goto LABEL_510;
          case 0xDDu:
            if ( (*(_DWORD *)(this + 568) & 0x2000) == 0 )
              *(_DWORD *)(this + 568) |= 0x2000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 182));
            goto LABEL_510;
          case 0xE3u:
            if ( (*(_DWORD *)(this + 568) & 0x4000) == 0 )
              *(_DWORD *)(this + 568) |= 0x4000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 186));
            goto LABEL_510;
          case 0xE4u:
            if ( (*(_DWORD *)(this + 568) & 0x8000) == 0 )
              *(_DWORD *)(this + 568) |= 0x8000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 188));
            goto LABEL_510;
          case 0xE5u:
            if ( (*(_DWORD *)(this + 568) & 0x10000) == 0 )
              *(_DWORD *)(this + 568) |= 0x10000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 190));
            goto LABEL_510;
          case 0xE6u:
            if ( (*(_DWORD *)(this + 568) & 0x20000) == 0 )
              *(_DWORD *)(this + 568) |= 0x20000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 192));
            goto LABEL_510;
          case 0xE7u:
            if ( (*(_DWORD *)(this + 568) & 0x40000) == 0 )
              *(_DWORD *)(this + 568) |= 0x40000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 196));
            goto LABEL_510;
          case 0xF1u:
            if ( (*(_DWORD *)(this + 568) & 0x80000) == 0 )
              *(_DWORD *)(this + 568) |= 0x80000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 200));
            goto LABEL_510;
          case 0xF3u:
            if ( (*(_DWORD *)(this + 568) & 0x100000) == 0 )
              *(_DWORD *)(this + 568) |= 0x100000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 204));
            goto LABEL_510;
          case 0xFCu:
            if ( (*(_DWORD *)(this + 568) & 0x200000) == 0 )
              *(_DWORD *)(this + 568) |= 0x200000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 208));
            goto LABEL_510;
          case 0xFDu:
            if ( (*(_DWORD *)(this + 568) & 0x400000) == 0 )
              *(_DWORD *)(this + 568) |= 0x400000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 210));
            goto LABEL_510;
          case 0xFEu:
            if ( (*(_DWORD *)(this + 568) & 0x800000) == 0 )
              *(_DWORD *)(this + 568) |= 0x800000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 212));
            goto LABEL_510;
          case 0xFFu:
            if ( (*(_DWORD *)(this + 568) & 0x1000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x1000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 214));
            goto LABEL_510;
          case 0x100u:
            if ( (*(_DWORD *)(this + 568) & 0x2000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x2000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 216));
            goto LABEL_510;
          case 0x101u:
            if ( (*(_DWORD *)(this + 568) & 0x4000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x4000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 218));
            goto LABEL_510;
          case 0x102u:
            if ( (*(_DWORD *)(this + 568) & 0x8000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x8000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 220));
            goto LABEL_510;
          case 0x103u:
            if ( (*(_DWORD *)(this + 568) & 0x10000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x10000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 222));
            goto LABEL_510;
          case 0x104u:
            if ( (*(_DWORD *)(this + 568) & 0x20000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x20000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 224));
            goto LABEL_510;
          case 0x105u:
            if ( (*(_DWORD *)(this + 568) & 0x40000000) == 0 )
              *(_DWORD *)(this + 568) |= 0x40000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 226));
            goto LABEL_510;
          case 0x106u:
            if ( *(int *)(this + 568) >= 0 )
              *(_DWORD *)(this + 568) |= 0x80000000;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 228));
            goto LABEL_510;
          case 0x107u:
            if ( (*(_BYTE *)(this + 572) & 1) == 0 )
              *(_DWORD *)(this + 572) |= 1u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 230));
            goto LABEL_510;
          case 0x108u:
            if ( (*(_DWORD *)(this + 572) & 2) == 0 )
              *(_DWORD *)(this + 572) |= 2u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 232));
            goto LABEL_510;
          case 0x109u:
            if ( (*(_DWORD *)(this + 572) & 4) == 0 )
              *(_DWORD *)(this + 572) |= 4u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 234));
            goto LABEL_510;
          case 0x10Au:
            if ( (*(_DWORD *)(this + 572) & 8) == 0 )
              *(_DWORD *)(this + 572) |= 8u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 236));
            goto LABEL_510;
          case 0x10Bu:
            if ( (*(_DWORD *)(this + 572) & 0x10) == 0 )
              *(_DWORD *)(this + 572) |= 0x10u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 238));
            goto LABEL_510;
          case 0x10Cu:
            if ( (*(_DWORD *)(this + 572) & 0x20) == 0 )
              *(_DWORD *)(this + 572) |= 0x20u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 240));
            goto LABEL_510;
          case 0x10Du:
            if ( (*(_DWORD *)(this + 572) & 0x40) == 0 )
              *(_DWORD *)(this + 572) |= 0x40u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 242));
            goto LABEL_510;
          case 0x10Eu:
            if ( (*(_DWORD *)(this + 572) & 0x80) == 0 )
              *(_DWORD *)(this + 572) |= 0x80u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 244));
            goto LABEL_510;
          case 0x10Fu:
            if ( (*(_DWORD *)(this + 572) & 0x100) == 0 )
              *(_DWORD *)(this + 572) |= 0x100u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 246));
            goto LABEL_510;
          case 0x110u:
            if ( (*(_DWORD *)(this + 572) & 0x200) == 0 )
              *(_DWORD *)(this + 572) |= 0x200u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 248));
            goto LABEL_510;
          case 0x111u:
            if ( (*(_DWORD *)(this + 572) & 0x400) == 0 )
              *(_DWORD *)(this + 572) |= 0x400u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 250));
            goto LABEL_510;
          case 0x112u:
            if ( (*(_DWORD *)(this + 572) & 0x800) == 0 )
              *(_DWORD *)(this + 572) |= 0x800u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 252));
            goto LABEL_510;
          case 0x113u:
            if ( (*(_DWORD *)(this + 572) & 0x1000) == 0 )
              *(_DWORD *)(this + 572) |= 0x1000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 254));
            goto LABEL_510;
          case 0x114u:
            if ( (*(_DWORD *)(this + 572) & 0x2000) == 0 )
              *(_DWORD *)(this + 572) |= 0x2000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 256));
            goto LABEL_510;
          case 0x11Cu:
            if ( (*(_DWORD *)(this + 572) & 0x4000) == 0 )
              *(_DWORD *)(this + 572) |= 0x4000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 258));
            goto LABEL_510;
          case 0x11Fu:
            if ( (*(_DWORD *)(this + 572) & 0x8000) == 0 )
              *(_DWORD *)(this + 572) |= 0x8000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 260));
            goto LABEL_510;
          case 0x120u:
            if ( (*(_DWORD *)(this + 572) & 0x10000) == 0 )
              *(_DWORD *)(this + 572) |= 0x10000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 264));
            goto LABEL_510;
          case 0x121u:
            if ( (*(_DWORD *)(this + 572) & 0x20000) == 0 )
              *(_DWORD *)(this + 572) |= 0x20000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 268));
            goto LABEL_510;
          case 0x122u:
            if ( (*(_DWORD *)(this + 572) & 0x40000) == 0 )
              *(_DWORD *)(this + 572) |= 0x40000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 272));
            goto LABEL_510;
          case 0x123u:
            if ( (*(_DWORD *)(this + 572) & 0x80000) == 0 )
              *(_DWORD *)(this + 572) |= 0x80000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 276));
            goto LABEL_510;
          case 0x124u:
            if ( (*(_DWORD *)(this + 572) & 0x100000) == 0 )
              *(_DWORD *)(this + 572) |= 0x100000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 280));
            goto LABEL_510;
          case 0x125u:
            if ( (*(_DWORD *)(this + 572) & 0x200000) == 0 )
              *(_DWORD *)(this + 572) |= 0x200000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 284));
            goto LABEL_510;
          case 0x126u:
            if ( (*(_DWORD *)(this + 572) & 0x400000) == 0 )
              *(_DWORD *)(this + 572) |= 0x400000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 288));
            goto LABEL_510;
          case 0x127u:
            if ( (*(_DWORD *)(this + 572) & 0x800000) == 0 )
              *(_DWORD *)(this + 572) |= 0x800000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 292));
            goto LABEL_510;
          case 0x128u:
            if ( (*(_DWORD *)(this + 572) & 0x1000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x1000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 296));
            goto LABEL_510;
          case 0x129u:
            if ( (*(_DWORD *)(this + 572) & 0x2000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x2000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 300));
            goto LABEL_510;
          case 0x12Au:
            if ( (*(_DWORD *)(this + 572) & 0x4000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x4000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 304));
            goto LABEL_510;
          case 0x12Bu:
            if ( (*(_DWORD *)(this + 572) & 0x8000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x8000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 308));
            goto LABEL_510;
          case 0x12Cu:
            if ( (*(_DWORD *)(this + 572) & 0x10000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x10000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 310));
            goto LABEL_510;
          case 0x12Du:
            if ( (*(_DWORD *)(this + 572) & 0x20000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x20000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 312));
            goto LABEL_510;
          case 0x12Eu:
            if ( (*(_DWORD *)(this + 572) & 0x40000000) == 0 )
              *(_DWORD *)(this + 572) |= 0x40000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 314));
            goto LABEL_510;
          case 0x12Fu:
            if ( *(int *)(this + 572) >= 0 )
              *(_DWORD *)(this + 572) |= 0x80000000;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 316));
            goto LABEL_510;
          case 0x131u:
            if ( (*(_BYTE *)(this + 576) & 1) == 0 )
              *(_DWORD *)(this + 576) |= 1u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 320));
            goto LABEL_510;
          case 0x132u:
            if ( (*(_DWORD *)(this + 576) & 2) == 0 )
              *(_DWORD *)(this + 576) |= 2u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 322));
            goto LABEL_510;
          case 0x138u:
            if ( (*(_DWORD *)(this + 576) & 4) == 0 )
              *(_DWORD *)(this + 576) |= 4u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 326));
            goto LABEL_510;
          case 0x139u:
            if ( (*(_DWORD *)(this + 576) & 8) == 0 )
              *(_DWORD *)(this + 576) |= 8u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 330));
            goto LABEL_510;
          case 0x13Au:
            if ( (*(_DWORD *)(this + 576) & 0x10) == 0 )
              *(_DWORD *)(this + 576) |= 0x10u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 334));
            goto LABEL_510;
          case 0x13Bu:
            if ( (*(_DWORD *)(this + 576) & 0x20) == 0 )
              *(_DWORD *)(this + 576) |= 0x20u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 338));
            goto LABEL_510;
          case 0x142u:
            if ( (*(_DWORD *)(this + 576) & 0x40) == 0 )
              *(_DWORD *)(this + 576) |= 0x40u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 342));
            goto LABEL_510;
          case 0x143u:
            if ( (*(_DWORD *)(this + 576) & 0x80) == 0 )
              *(_DWORD *)(this + 576) |= 0x80u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 346));
            goto LABEL_510;
          case 0x144u:
            if ( (*(_DWORD *)(this + 576) & 0x100) == 0 )
              *(_DWORD *)(this + 576) |= 0x100u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 350));
            goto LABEL_510;
          case 0x146u:
            if ( (*(_DWORD *)(this + 576) & 0x200) == 0 )
              *(_DWORD *)(this + 576) |= 0x200u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 354));
            goto LABEL_510;
          case 0x149u:
            if ( (*(_DWORD *)(this + 576) & 0x400) == 0 )
              *(_DWORD *)(this + 576) |= 0x400u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 358));
            goto LABEL_510;
          case 0x14Au:
            if ( (*(_DWORD *)(this + 576) & 0x800) == 0 )
              *(_DWORD *)(this + 576) |= 0x800u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 360));
            goto LABEL_510;
          case 0x14Bu:
            if ( (*(_DWORD *)(this + 576) & 0x1000) == 0 )
              *(_DWORD *)(this + 576) |= 0x1000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 362));
            goto LABEL_510;
          case 0x14Cu:
            if ( (*(_DWORD *)(this + 576) & 0x2000) == 0 )
              *(_DWORD *)(this + 576) |= 0x2000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 364));
            goto LABEL_510;
          case 0x14Du:
            if ( (*(_DWORD *)(this + 576) & 0x4000) == 0 )
              *(_DWORD *)(this + 576) |= 0x4000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 366));
            goto LABEL_510;
          case 0x14Eu:
            if ( (*(_DWORD *)(this + 576) & 0x8000) == 0 )
              *(_DWORD *)(this + 576) |= 0x8000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 368));
            goto LABEL_510;
          case 0x14Fu:
            if ( (*(_DWORD *)(this + 576) & 0x10000) == 0 )
              *(_DWORD *)(this + 576) |= 0x10000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 370));
            goto LABEL_510;
          case 0x150u:
            if ( (*(_DWORD *)(this + 576) & 0x20000) == 0 )
              *(_DWORD *)(this + 576) |= 0x20000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 372));
            goto LABEL_510;
          case 0x151u:
            if ( (*(_DWORD *)(this + 576) & 0x40000) == 0 )
              *(_DWORD *)(this + 576) |= 0x40000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 374));
            goto LABEL_510;
          case 0x152u:
            if ( (*(_DWORD *)(this + 576) & 0x80000) == 0 )
              *(_DWORD *)(this + 576) |= 0x80000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 376));
            goto LABEL_510;
          case 0x153u:
            if ( (*(_DWORD *)(this + 576) & 0x100000) == 0 )
              *(_DWORD *)(this + 576) |= 0x100000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 378));
            goto LABEL_510;
          case 0x154u:
            if ( (*(_DWORD *)(this + 576) & 0x200000) == 0 )
              *(_DWORD *)(this + 576) |= 0x200000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 380));
            goto LABEL_510;
          case 0x155u:
            if ( (*(_DWORD *)(this + 576) & 0x400000) == 0 )
              *(_DWORD *)(this + 576) |= 0x400000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 382));
            goto LABEL_510;
          case 0x156u:
            if ( (*(_DWORD *)(this + 576) & 0x800000) == 0 )
              *(_DWORD *)(this + 576) |= 0x800000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 384));
            goto LABEL_510;
          case 0x157u:
            if ( (*(_DWORD *)(this + 576) & 0x1000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x1000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 386));
            goto LABEL_510;
          case 0x158u:
            if ( (*(_DWORD *)(this + 576) & 0x2000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x2000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 388));
            goto LABEL_510;
          case 0x159u:
            if ( (*(_DWORD *)(this + 576) & 0x4000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x4000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 390));
            goto LABEL_510;
          case 0x15Au:
            if ( (*(_DWORD *)(this + 576) & 0x8000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x8000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 392));
            goto LABEL_510;
          case 0x15Bu:
            if ( (*(_DWORD *)(this + 576) & 0x10000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x10000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 394));
            goto LABEL_510;
          case 0x15Cu:
            if ( (*(_DWORD *)(this + 576) & 0x20000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x20000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 396));
            goto LABEL_510;
          case 0x15Du:
            if ( (*(_DWORD *)(this + 576) & 0x40000000) == 0 )
              *(_DWORD *)(this + 576) |= 0x40000000u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 398));
            goto LABEL_510;
          case 0x15Eu:
            if ( *(int *)(this + 576) >= 0 )
              *(_DWORD *)(this + 576) |= 0x80000000;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 400));
            goto LABEL_510;
          case 0x16Cu:
            if ( (*(_BYTE *)(this + 580) & 1) == 0 )
              *(_DWORD *)(this + 580) |= 1u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 402));
            goto LABEL_510;
          case 0x16Du:
            if ( (*(_DWORD *)(this + 580) & 2) == 0 )
              *(_DWORD *)(this + 580) |= 2u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 406));
            goto LABEL_510;
          case 0x16Eu:
            if ( (*(_DWORD *)(this + 580) & 4) == 0 )
              *(_DWORD *)(this + 580) |= 4u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 410));
            goto LABEL_510;
          case 0x16Fu:
            if ( (*(_DWORD *)(this + 580) & 8) == 0 )
              *(_DWORD *)(this + 580) |= 8u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 414));
            goto LABEL_510;
          case 0x170u:
            if ( (*(_DWORD *)(this + 580) & 0x10) == 0 )
              *(_DWORD *)(this + 580) |= 0x10u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 418));
            goto LABEL_510;
          case 0x171u:
            if ( (*(_DWORD *)(this + 580) & 0x20) == 0 )
              *(_DWORD *)(this + 580) |= 0x20u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 422));
            goto LABEL_510;
          case 0x172u:
            if ( (*(_DWORD *)(this + 580) & 0x40) == 0 )
              *(_DWORD *)(this + 580) |= 0x40u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 426));
            goto LABEL_510;
          case 0x173u:
            if ( (*(_DWORD *)(this + 580) & 0x80) == 0 )
              *(_DWORD *)(this + 580) |= 0x80u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 430));
            goto LABEL_510;
          case 0x174u:
            if ( (*(_DWORD *)(this + 580) & 0x100) == 0 )
              *(_DWORD *)(this + 580) |= 0x100u;
            Int64 = TdrBuf::ReadInt64(v6, (_BYTE *)(this + 434));
            goto LABEL_510;
          case 0x175u:
            if ( (*(_DWORD *)(this + 580) & 0x200) == 0 )
              *(_DWORD *)(this + 580) |= 0x200u;
            v5 = TdrBuf::ReadInt32(v6, &a2);
            if ( v5 )
              return v5;
            *(_DWORD *)(this + 442) = a2;
            goto LABEL_511;
          case 0x176u:
            if ( (*(_DWORD *)(this + 580) & 0x400) == 0 )
              *(_DWORD *)(this + 580) |= 0x400u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 446));
            goto LABEL_510;
          case 0x177u:
            if ( (*(_DWORD *)(this + 580) & 0x800) == 0 )
              *(_DWORD *)(this + 580) |= 0x800u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 450));
            goto LABEL_510;
          case 0x178u:
            if ( (*(_DWORD *)(this + 580) & 0x1000) == 0 )
              *(_DWORD *)(this + 580) |= 0x1000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 454));
            goto LABEL_510;
          case 0x179u:
            if ( (*(_DWORD *)(this + 580) & 0x2000) == 0 )
              *(_DWORD *)(this + 580) |= 0x2000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 458));
            goto LABEL_510;
          case 0x17Au:
            if ( (*(_DWORD *)(this + 580) & 0x4000) == 0 )
              *(_DWORD *)(this + 580) |= 0x4000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 462));
            goto LABEL_510;
          case 0x17Bu:
            if ( (*(_DWORD *)(this + 580) & 0x8000) == 0 )
              *(_DWORD *)(this + 580) |= 0x8000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 466));
            goto LABEL_510;
          case 0x17Cu:
            if ( (*(_DWORD *)(this + 580) & 0x10000) == 0 )
              *(_DWORD *)(this + 580) |= 0x10000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 470));
            goto LABEL_510;
          case 0x17Du:
            if ( (*(_DWORD *)(this + 580) & 0x20000) == 0 )
              *(_DWORD *)(this + 580) |= 0x20000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 474));
            goto LABEL_510;
          case 0x17Fu:
            if ( (*(_DWORD *)(this + 580) & 0x40000) == 0 )
              *(_DWORD *)(this + 580) |= 0x40000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 478));
            goto LABEL_510;
          case 0x181u:
            if ( (*(_DWORD *)(this + 580) & 0x80000) == 0 )
              *(_DWORD *)(this + 580) |= 0x80000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 482));
            goto LABEL_510;
          case 0x182u:
            if ( (*(_DWORD *)(this + 580) & 0x100000) == 0 )
              *(_DWORD *)(this + 580) |= 0x100000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 486));
            goto LABEL_510;
          case 0x183u:
            if ( (*(_DWORD *)(this + 580) & 0x200000) == 0 )
              *(_DWORD *)(this + 580) |= 0x200000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 490));
            goto LABEL_510;
          case 0x185u:
            if ( (*(_DWORD *)(this + 580) & 0x400000) == 0 )
              *(_DWORD *)(this + 580) |= 0x400000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 494));
            goto LABEL_510;
          case 0x186u:
            if ( (*(_DWORD *)(this + 580) & 0x800000) == 0 )
              *(_DWORD *)(this + 580) |= 0x800000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 498));
            goto LABEL_510;
          case 0x187u:
            if ( (*(_DWORD *)(this + 580) & 0x1000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x1000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 502));
            goto LABEL_510;
          case 0x188u:
            if ( (*(_DWORD *)(this + 580) & 0x2000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x2000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 506));
            goto LABEL_510;
          case 0x190u:
            if ( (*(_DWORD *)(this + 580) & 0x4000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x4000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 510));
            goto LABEL_510;
          case 0x191u:
            if ( (*(_DWORD *)(this + 580) & 0x8000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x8000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 514));
            goto LABEL_510;
          case 0x192u:
            if ( (*(_DWORD *)(this + 580) & 0x10000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x10000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 518));
            goto LABEL_510;
          case 0x193u:
            if ( (*(_DWORD *)(this + 580) & 0x20000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x20000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 522));
            goto LABEL_510;
          case 0x194u:
            if ( (*(_DWORD *)(this + 580) & 0x40000000) == 0 )
              *(_DWORD *)(this + 580) |= 0x40000000u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 526));
            goto LABEL_510;
          case 0x195u:
            if ( *(int *)(this + 580) >= 0 )
              *(_DWORD *)(this + 580) |= 0x80000000;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 530));
            goto LABEL_510;
          case 0x196u:
            if ( (*(_BYTE *)(this + 584) & 1) == 0 )
              *(_DWORD *)(this + 584) |= 1u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 534));
            goto LABEL_510;
          case 0x197u:
            if ( (*(_DWORD *)(this + 584) & 2) == 0 )
              *(_DWORD *)(this + 584) |= 2u;
            Int64 = TdrBuf::ReadInt16(v6, (_BYTE *)(this + 538));
            goto LABEL_510;
          case 0x198u:
            if ( (*(_DWORD *)(this + 584) & 4) == 0 )
              *(_DWORD *)(this + 584) |= 4u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 540));
            goto LABEL_510;
          case 0x199u:
            if ( (*(_DWORD *)(this + 584) & 8) == 0 )
              *(_DWORD *)(this + 584) |= 8u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 544));
            goto LABEL_510;
          case 0x19Au:
            if ( (*(_DWORD *)(this + 584) & 0x10) == 0 )
              *(_DWORD *)(this + 584) |= 0x10u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 548));
            goto LABEL_510;
          case 0x19Cu:
            if ( (*(_DWORD *)(this + 584) & 0x20) == 0 )
              *(_DWORD *)(this + 584) |= 0x20u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 552));
            goto LABEL_510;
          case 0x19Du:
            if ( (*(_DWORD *)(this + 584) & 0x40) == 0 )
              *(_DWORD *)(this + 584) |= 0x40u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 556));
            goto LABEL_510;
          case 0x19Eu:
            if ( (*(_DWORD *)(this + 584) & 0x80) == 0 )
              *(_DWORD *)(this + 584) |= 0x80u;
            Int64 = TdrBuf::ReadInt32(v6, (_BYTE *)(this + 560));
            goto LABEL_510;
          default:
            Int64 = TdrBuf::SkipField(v6, v10 & 0xF);
LABEL_510:
            v5 = Int64;
            if ( Int64 )
              return v5;
LABEL_511:
            if ( v6[1] >= v7 )
              goto LABEL_512;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0192::DoDebugFormat
// Address Name: SUB_101B8890
// ============================================================
//----- (101B8890) --------------------------------------------------------
int __thiscall sub_101B8890(__int16 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_101B8940(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0192::DebugFormat
// Address Name: SUB_101B8940
// ============================================================
//----- (101B8940) --------------------------------------------------------
int __thiscall sub_101B8940(__int16 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[roleGID]", "%I64u", *(_QWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[oCharLevel]", "%d", *((_DWORD *)this + 2));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[oCharExp]", "%d", *((_DWORD *)this + 3));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[oStarLevel]", "%d", *((_DWORD *)this + 4));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[oCharHP]", "%d", *((_DWORD *)this + 5));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[oCharMaxHP]", "%d", *((_DWORD *)this + 6));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[oCharStr]", "%d", *((_DWORD *)this + 7));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[oCharBst]", "%d", *((_DWORD *)this + 8));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[oCharLck]", "%d", *((_DWORD *)this + 9));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[oCharVgr]", "%d", *((_DWORD *)this + 10));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[oCharDefence]", "%d", *((_DWORD *)this + 11));
                      if ( !result )
                      {
                        result = print_field(a2, a3, a4, "[oCharMoney]", "%d", *((_DWORD *)this + 12));
                        if ( !result )
                        {
                          result = print_field(a2, a3, a4, "[oCharBoundMoney]", "%d", *((_DWORD *)this + 13));
                          if ( !result )
                          {
                            result = print_field(a2, a3, a4, "[oCharCredit]", "%d", *((_DWORD *)this + 14));
                            if ( !result )
                            {
                              result = print_field(a2, a3, a4, "[oCharBoundCredit]", "%d", *((_DWORD *)this + 15));
                              if ( !result )
                              {
                                result = print_field(a2, a3, a4, "[oCharFatigue]", "%d", *((_DWORD *)this + 16));
                                if ( !result )
                                {
                                  result = print_field(a2, a3, a4, "[oCharMaxFatigue]", "%d", *((_DWORD *)this + 17));
                                  if ( !result )
                                  {
                                    result = print_field(a2, a3, a4, "[oClaymoreExp]", "%d", *((_DWORD *)this + 18));
                                    if ( !result )
                                    {
                                      result = print_field(a2, a3, a4, "[oHammerExp]", "%d", *((_DWORD *)this + 19));
                                      if ( !result )
                                      {
                                        result = print_field(a2, a3, a4, "[oKatanaExp]", "%d", *((_DWORD *)this + 20));
                                        if ( !result )
                                        {
                                          result = print_field(
                                                     a2,
                                                     a3,
                                                     a4,
                                                     "[oDuelSwordExp]",
                                                     "%d",
                                                     *((_DWORD *)this + 21));
                                          if ( !result )
                                          {
                                            result = print_field(
                                                       a2,
                                                       a3,
                                                       a4,
                                                       "[oSwordExp]",
                                                       "%d",
                                                       *((_DWORD *)this + 22));
                                            if ( !result )
                                            {
                                              result = print_field(
                                                         a2,
                                                         a3,
                                                         a4,
                                                         "[oSpearExp]",
                                                         "%d",
                                                         *((_DWORD *)this + 23));
                                              if ( !result )
                                              {
                                                result = print_field(
                                                           a2,
                                                           a3,
                                                           a4,
                                                           "[oGunExp]",
                                                           "%d",
                                                           *((_DWORD *)this + 24));
                                                if ( !result )
                                                {
                                                  result = print_field(
                                                             a2,
                                                             a3,
                                                             a4,
                                                             "[oBowExp]",
                                                             "%d",
                                                             *((_DWORD *)this + 25));
                                                  if ( !result )
                                                  {
                                                    result = print_field(
                                                               a2,
                                                               a3,
                                                               a4,
                                                               "[oCrossbowExp]",
                                                               "%d",
                                                               *((_DWORD *)this + 26));
                                                    if ( !result )
                                                    {
                                                      result = print_field(
                                                                 a2,
                                                                 a3,
                                                                 a4,
                                                                 "[oFluteExp]",
                                                                 "%d",
                                                                 *((_DWORD *)this + 27));
                                                      if ( !result )
                                                      {
                                                        result = print_field(
                                                                   a2,
                                                                   a3,
                                                                   a4,
                                                                   "[oMaleFace]",
                                                                   "%d",
                                                                   *((_DWORD *)this + 28));
                                                        if ( !result )
                                                        {
                                                          result = print_field(
                                                                     a2,
                                                                     a3,
                                                                     a4,
                                                                     "[oMaleHair]",
                                                                     "%d",
                                                                     *((_DWORD *)this + 29));
                                                          if ( !result )
                                                          {
                                                            result = print_field(
                                                                       a2,
                                                                       a3,
                                                                       a4,
                                                                       "[oEquipFoundDay]",
                                                                       "%d",
                                                                       *((_DWORD *)this + 30));
                                                            if ( !result )
                                                            {
                                                              result = print_field(
                                                                         a2,
                                                                         a3,
                                                                         a4,
                                                                         "[oUnderClothes]",
                                                                         "%d",
                                                                         *((_DWORD *)this + 31));
                                                              if ( !result )
                                                              {
                                                                result = print_field(
                                                                           a2,
                                                                           a3,
                                                                           a4,
                                                                           "[oNewbie]",
                                                                           "%d",
                                                                           *((_DWORD *)this + 32));
                                                                if ( !result )
                                                                {
                                                                  result = print_field(
                                                                             a2,
                                                                             a3,
                                                                             a4,
                                                                             "[oCharContribution]",
                                                                             "%d",
                                                                             *((_DWORD *)this + 33));
                                                                  if ( !result )
                                                                  {
                                                                    result = print_field(
                                                                               a2,
                                                                               a3,
                                                                               a4,
                                                                               "[oCharRemainsExp]",
                                                                               "%d",
                                                                               *((_DWORD *)this + 34));
                                                                    if ( !result )
                                                                    {
                                                                      result = print_field(
                                                                                 a2,
                                                                                 a3,
                                                                                 a4,
                                                                                 "[oFarmOpenFlag]",
                                                                                 "%d",
                                                                                 *(this + 70));
                                                                      if ( !result )
                                                                      {
                                                                        result = print_field(
                                                                                   a2,
                                                                                   a3,
                                                                                   a4,
                                                                                   "[oFarmExp]",
                                                                                   "%d",
                                                                                   *(_DWORD *)(this + 71));
                                                                        if ( !result )
                                                                        {
                                                                          result = print_field(
                                                                                     a2,
                                                                                     a3,
                                                                                     a4,
                                                                                     "[oFarmEvaluation]",
                                                                                     "%d",
                                                                                     *(_DWORD *)(this + 73));
                                                                          if ( !result )
                                                                          {
                                                                            result = print_field(
                                                                                       a2,
                                                                                       a3,
                                                                                       a4,
                                                                                       "[oLastResetTime]",
                                                                                       "%d",
                                                                                       *(_DWORD *)(this + 75));
                                                                            if ( !result )
                                                                            {
                                                                              result = print_field(
                                                                                         a2,
                                                                                         a3,
                                                                                         a4,
                                                                                         "[oSkinColor]",
                                                                                         "%d",
                                                                                         *(_DWORD *)(this + 77));
                                                                              if ( !result )
                                                                              {
                                                                                result = print_field(
                                                                                           a2,
                                                                                           a3,
                                                                                           a4,
                                                                                           "[oHairColor]",
                                                                                           "%d",
                                                                                           *(_DWORD *)(this + 79));
                                                                                if ( !result )
                                                                                {
                                                                                  result = print_field(
                                                                                             a2,
                                                                                             a3,
                                                                                             a4,
                                                                                             "[oInnerColor]",
                                                                                             "%d",
                                                                                             *(_DWORD *)(this + 81));
                                                                                  if ( !result )
                                                                                  {
                                                                                    result = print_field(
                                                                                               a2,
                                                                                               a3,
                                                                                               a4,
                                                                                               "[oFaceTattooIndex]",
                                                                                               "%d",
                                                                                               *(_DWORD *)(this + 83));
                                                                                    if ( !result )
                                                                                    {
                                                                                      result = print_field(
                                                                                                 a2,
                                                                                                 a3,
                                                                                                 a4,
                                                                                                 "[oEyeBall]",
                                                                                                 "%d",
                                                                                                 *(_DWORD *)(this + 85));
                                                                                      if ( !result )
                                                                                      {
                                                                                        result = print_field(
                                                                                                   a2,
                                                                                                   a3,
                                                                                                   a4,
                                                                                                   "[oFarmFriendGatherCount]",
                                                                                                   "%d",
                                                                                                   *(_DWORD *)(this + 87));
                                                                                        if ( !result )
                                                                                        {
                                                                                          result = print_field(
                                                                                                     a2,
                                                                                                     a3,
                                                                                                     a4,
                                                                                                     "[oFaceTattooColor]",
                                                                                                     "%d",
                                                                                                     *(_DWORD *)(this + 89));
                                                                                          if ( !result )
                                                                                          {
                                                                                            result = print_field(a2, a3, a4, "[oEyeColor]", "%d", *(_DWORD *)(this + 91));
                                                                                            if ( !result )
                                                                                            {
                                                                                              result = print_field(a2, a3, a4, "[oHideFashion]", "%d", *(this + 93));
                                                                                              if ( !result )
                                                                                              {
                                                                                                result = print_field(a2, a3, a4, "[oHideSuite]", "%d", *(this + 94));
                                                                                                if ( !result )
                                                                                                {
                                                                                                  result = print_field(a2, a3, a4, "[oHideHelm]", "%d", *(this + 95));
                                                                                                  if ( !result )
                                                                                                  {
                                                                                                    result = print_field(a2, a3, a4, "[oCharCatCredit]", "%d", *((_DWORD *)this + 48));
                                                                                                    if ( !result )
                                                                                                    {
                                                                                                      result = print_field(a2, a3, a4, "[oCharReviveCredit]", "%d", *((_DWORD *)this + 49));
                                                                                                      if ( !result )
                                                                                                      {
                                                                                                        result = print_field(a2, a3, a4, "[oSystemUnlockData]", "%d", *((_DWORD *)this + 50));
                                                                                                        if ( !result )
                                                                                                        {
                                                                                                          result = print_field(a2, a3, a4, "[oExtDailyExp]", "%d", *((_DWORD *)this + 51));
                                                                                                          if ( !result )
                                                                                                          {
                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo1]", "%d", *(this + 104));
                                                                                                            if ( !result )
                                                                                                            {
                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo2]", "%d", *(this + 105));
                                                                                                              if ( !result )
                                                                                                              {
                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo3]", "%d", *(this + 106));
                                                                                                                if ( !result )
                                                                                                                {
                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo4]", "%d", *(this + 107));
                                                                                                                  if ( !result )
                                                                                                                  {
                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo5]", "%d", *(this + 108));
                                                                                                                    if ( !result )
                                                                                                                    {
                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo6]", "%d", *(this + 109));
                                                                                                                      if ( !result )
                                                                                                                      {
                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo7]", "%d", *(this + 110));
                                                                                                                        if ( !result )
                                                                                                                        {
                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo8]", "%d", *(this + 111));
                                                                                                                          if ( !result )
                                                                                                                          {
                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo9]", "%d", *(this + 112));
                                                                                                                            if ( !result )
                                                                                                                            {
                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo10]", "%d", *(this + 113));
                                                                                                                              if ( !result )
                                                                                                                              {
                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo11]", "%d", *(this + 114));
                                                                                                                                if ( !result )
                                                                                                                                {
                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo12]", "%d", *(this + 115));
                                                                                                                                  if ( !result )
                                                                                                                                  {
                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo13]", "%d", *(this + 116));
                                                                                                                                    if ( !result )
                                                                                                                                    {
                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo14]", "%d", *(this + 117));
                                                                                                                                      if ( !result )
                                                                                                                                      {
                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo15]", "%d", *(this + 118));
                                                                                                                                        if ( !result )
                                                                                                                                        {
                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo16]", "%d", *(this + 119));
                                                                                                                                          if ( !result )
                                                                                                                                          {
                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo17]", "%d", *(this + 120));
                                                                                                                                            if ( !result )
                                                                                                                                            {
                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo18]", "%d", *(this + 121));
                                                                                                                                              if ( !result )
                                                                                                                                              {
                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo19]", "%d", *(this + 122));
                                                                                                                                                if ( !result )
                                                                                                                                                {
                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo20]", "%d", *(this + 123));
                                                                                                                                                  if ( !result )
                                                                                                                                                  {
                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo21]", "%d", *(this + 124));
                                                                                                                                                    if ( !result )
                                                                                                                                                    {
                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo22]", "%d", *(this + 125));
                                                                                                                                                      if ( !result )
                                                                                                                                                      {
                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo23]", "%d", *(this + 126));
                                                                                                                                                        if ( !result )
                                                                                                                                                        {
                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo24]", "%d", *(this + 127));
                                                                                                                                                          if ( !result )
                                                                                                                                                          {
                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo25]", "%d", *(this + 128));
                                                                                                                                                            if ( !result )
                                                                                                                                                            {
                                                                                                                                                              result = print_field(a2, a3, a4, "[oVIP]", "%d", *(this + 129));
                                                                                                                                                              if ( !result )
                                                                                                                                                              {
                                                                                                                                                                result = print_field(a2, a3, a4, "[oEntrustMoney1]", "%d", *((_DWORD *)this + 65));
                                                                                                                                                                if ( !result )
                                                                                                                                                                {
                                                                                                                                                                  result = print_field(a2, a3, a4, "[oEntrustMoney2]", "%d", *((_DWORD *)this + 66));
                                                                                                                                                                  if ( !result )
                                                                                                                                                                  {
                                                                                                                                                                    result = print_field(a2, a3, a4, "[oCharmFoundTimes]", "%d", *((_DWORD *)this + 67));
                                                                                                                                                                    if ( !result )
                                                                                                                                                                    {
                                                                                                                                                                      result = print_field(a2, a3, a4, "[oWeapSysUnlockFlag]", "%d", *((_DWORD *)this + 68));
                                                                                                                                                                      if ( !result )
                                                                                                                                                                      {
                                                                                                                                                                        result = print_field(a2, a3, a4, "[oCharRemainsDoubleExp]", "%d", *((_DWORD *)this + 69));
                                                                                                                                                                        if ( !result )
                                                                                                                                                                        {
                                                                                                                                                                          result = print_field(a2, a3, a4, "[oExtDailyDoubleExp]", "%d", *((_DWORD *)this + 70));
                                                                                                                                                                          if ( !result )
                                                                                                                                                                          {
                                                                                                                                                                            result = print_field(a2, a3, a4, "[oVIPLevel]", "%d", *((_DWORD *)this + 71));
                                                                                                                                                                            if ( !result )
                                                                                                                                                                            {
                                                                                                                                                                              result = print_field(a2, a3, a4, "[oVIPExp]", "%d", *((_DWORD *)this + 72));
                                                                                                                                                                              if ( !result )
                                                                                                                                                                              {
                                                                                                                                                                                result = print_field(a2, a3, a4, "[oVIPBaseEndTime]", "%d", *((_DWORD *)this + 73));
                                                                                                                                                                                if ( !result )
                                                                                                                                                                                {
                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oVIPGrowthEndTime]", "%d", *((_DWORD *)this + 74));
                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                  {
                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oVIPProfitEndTime]", "%d", *((_DWORD *)this + 75));
                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                    {
                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oBanChatEndTime]", "%d", *((_DWORD *)this + 76));
                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                      {
                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oVIPVASFrozen]", "%d", *(this + 154));
                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                        {
                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oVIPBaseCanUse]", "%d", *(this + 155));
                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                          {
                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oVIPGrowthCanUse]", "%d", *(this + 156));
                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                            {
                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oVIPProfitCanUse]", "%d", *(this + 157));
                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                              {
                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oSystemUnlockExtData1]", "%d", *((_DWORD *)this + 79));
                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                {
                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oIsVIPBaseExpireNtf]", "%d", *(this + 160));
                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                  {
                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oVIPBaseExpireLastNtfTime]", "%d", *(_DWORD *)(this + 161));
                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                    {
                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oVIPVASFrozenTime]", "%d", *(_DWORD *)(this + 163));
                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                      {
                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oClanScore]", "%d", *(_DWORD *)(this + 165));
                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                        {
                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oClanScoreMax]", "%d", *(_DWORD *)(this + 167));
                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                          {
                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oClanMoney]", "%d", *(_DWORD *)(this + 169));
                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                            {
                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oCharHRLevel]", "%d", *(_DWORD *)(this + 171));
                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                              {
                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oCharHRPoint]", "%d", *(_DWORD *)(this + 173));
                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                {
                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oClanMoneyPVP]", "%d", *(_DWORD *)(this + 175));
                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oClanLeaveTime]", "%d", *(_DWORD *)(this + 177));
                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo26]", "%d", *(this + 179));
                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo27]", "%d", *(this + 180));
                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo28]", "%d", *(this + 181));
                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                          {
                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo29]", "%d", *(this + 182));
                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo30]", "%d", *(this + 183));
                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo31]", "%d", *(this + 184));
                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo32]", "%d", *(this + 185));
                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo33]", "%d", *(this + 186));
                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo34]", "%d", *(this + 187));
                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo35]", "%d", *(this + 188));
                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo36]", "%d", *(this + 189));
                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo37]", "%d", *(this + 190));
                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo38]", "%d", *(this + 191));
                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo39]", "%d", *(this + 192));
                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oFacialInfo40]", "%d", *(this + 193));
                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oFacialInfo41]", "%d", *(this + 194));
                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oFacialInfo42]", "%d", *(this + 195));
                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFacialInfo43]", "%d", *(this + 196));
                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oFacialInfo44]", "%d", *(this + 197));
                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oFacialInfo45]", "%d", *(this + 198));
                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oFacialInfo46]", "%d", *(this + 199));
                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oFacialInfo47]", "%d", *(this + 200));
                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oPersonalELO]", "%d", *(_DWORD *)(this + 201));
                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oPVPMoney]", "%d", *(_DWORD *)(this + 203));
                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oCharCatMoney]", "%d", *(_DWORD *)(this + 205));
                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oCharCatMoneyWeek]", "%d", *(_DWORD *)(this + 207));
                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oCharCatMoneyWeekMax]", "%d", *(_DWORD *)(this + 209));
                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oHuntSoul]", "%d", *(_DWORD *)(this + 211));
                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oWildHuntCamp]", "%d", *(_DWORD *)(this + 213));
                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oWildHuntPhase]", "%d", *(_DWORD *)(this + 215));
                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oWildHuntGuild]", "%I64u", *(_QWORD *)(this + 217));
                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oTotalCredit]", "%f", *(float *)(this + 221));
                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oBattleCount]", "%d", *(_DWORD *)(this + 223));
                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oFirstLoginTime]", "%d", *(_DWORD *)(this + 225));
                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oLastHuntSoul]", "%d", *(_DWORD *)(this + 227));
                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oTotalHRPoint]", "%d", *(_DWORD *)(this + 229));
                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oLikeHunterOfficer]", "%d", *(_DWORD *)(this + 231));
                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oPetSkillMoral]", "%d", *(_DWORD *)(this + 233));
                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oPetSkillUpgradeMoral]", "%d", *(_DWORD *)(this + 235));
                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oHuntingCreditExchange]", "%d", *(_DWORD *)(this + 237));
                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oLevelShowType]", "%d", *(_DWORD *)(this + 239));
                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oMonolopyRoundCount]", "%d", *(_DWORD *)(this + 241));
                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oMonolopyActivity]", "%d", *(_DWORD *)(this + 243));
                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oMonolopyCurGrid]", "%d", *(_DWORD *)(this + 245));
                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oShouHunPoint]", "%d", *(_DWORD *)(this + 247));
                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oLieHunPoint]", "%d", *(_DWORD *)(this + 249));
                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oMVPPoint]", "%d", *(_DWORD *)(this + 251));
                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oXHunterScore]", "%d", *(_DWORD *)(this + 253));
                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oMonolopyAccStep]", "%d", *(_DWORD *)(this + 255));
                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oXHunterHighScore]", "%d", *(_DWORD *)(this + 257));
                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oSoulStoneLevel]", "%d", *(_DWORD *)(this + 259));
                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oWeeklyRefreshTime]", "%d", *(_DWORD *)(this + 261));
                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oWeekMoneyGain]", "%d", *(_DWORD *)(this + 263));
                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                                                                                                                result = print_field(a2, a3, a4, "[oSoulStoneAtkLevel]", "%d", *(_DWORD *)(this + 265));
                                                                                                                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                  result = print_field(a2, a3, a4, "[oXHunterActivity]", "%d", *(_DWORD *)(this + 267));
                                                                                                                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                    result = print_field(a2, a3, a4, "[oIsNewbie]", "%d", *(this + 269));
                                                                                                                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                                      result = print_field(a2, a3, a4, "[oLevelHuntSoul]", "%d", *((_DWORD *)this + 135));
                                                                                                                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                                                                                        result = print_field(a2, a3, a4, "[oTaskHuntSoul]", "%d", *((_DWORD *)this + 136));
                                                                                                                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                          result = print_field(a2, a3, a4, "[oCampHuntSoul]", "%d", *((_DWORD *)this + 137));
                                                                                                                                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                                                            result = print_field(a2, a3, a4, "[oHideWeaponBreakEffect]", "%d", *((_DWORD *)this + 138));
                                                                                                                                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                              result = print_field(a2, a3, a4, "[oIllustratePoint]", "%d", *((_DWORD *)this + 139));
                                                                                                                                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                                                                                                                                                return print_field(a2, a3, a4, "[oGuildBanChatEndTime]", "%d", *((_DWORD *)this + 140));
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



