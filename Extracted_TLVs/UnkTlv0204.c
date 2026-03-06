// ============================================================
// Name: TLV::UnkTlv0204::Read_0xAA
// Address Name: SUB_101F5F60
// ============================================================
//----- (101F5F60) --------------------------------------------------------
int __thiscall sub_101F5F60(int this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // edi
  int v6; // edx
  unsigned int v7; // ebx
  int result; // eax
  int v9; // eax
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_QWORD *)(this + 5800) = 0;
  v7 = v4[1] + v3;
  if ( v4[1] >= v7 )
  {
LABEL_297:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 4u:
          if ( (*(_BYTE *)(this + 5800) & 1) == 0 )
            *(_DWORD *)(this + 5800) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)this, (int)v4, a2);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 5800) & 2) == 0 )
            *(_DWORD *)(this + 5800) |= 2u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 100), (int)v4, a2);
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 5800) & 4) == 0 )
            *(_DWORD *)(this + 5800) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 200), (int)v4, a2);
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 5800) & 8) == 0 )
            *(_DWORD *)(this + 5800) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 300), (int)v4, a2);
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 5800) & 0x10) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 400), (int)v4, a2);
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 5800) & 0x20) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 500), (int)v4, a2);
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 5800) & 0x40) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 600), (int)v4, a2);
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 5800) & 0x80) == 0 )
            *(_DWORD *)(this + 5800) |= 0x80u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 700), (int)v4, a2);
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 5800) & 0x100) == 0 )
            *(_DWORD *)(this + 5800) |= 0x100u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 800), (int)v4, a2);
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 5800) & 0x200) == 0 )
            *(_DWORD *)(this + 5800) |= 0x200u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 900), (int)v4, a2);
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 5800) & 0x400) == 0 )
            *(_DWORD *)(this + 5800) |= 0x400u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1000), (int)v4, a2);
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 5800) & 0x800) == 0 )
            *(_DWORD *)(this + 5800) |= 0x800u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1100), (int)v4, a2);
          break;
        case 0x19u:
          if ( (*(_DWORD *)(this + 5800) & 0x1000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x1000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1200), (int)v4, a2);
          break;
        case 0x1Eu:
          if ( (*(_DWORD *)(this + 5800) & 0x2000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x2000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1300), (int)v4, a2);
          break;
        case 0x1Fu:
          if ( (*(_DWORD *)(this + 5800) & 0x4000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x4000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1400), (int)v4, a2);
          break;
        case 0x20u:
          if ( (*(_DWORD *)(this + 5800) & 0x8000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x8000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1500), (int)v4, a2);
          break;
        case 0x22u:
          if ( (*(_DWORD *)(this + 5800) & 0x10000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1600), (int)v4, a2);
          break;
        case 0x23u:
          if ( (*(_DWORD *)(this + 5800) & 0x20000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1700), (int)v4, a2);
          break;
        case 0x24u:
          if ( (*(_DWORD *)(this + 5800) & 0x40000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1800), (int)v4, a2);
          break;
        case 0x2Au:
          if ( (*(_DWORD *)(this + 5800) & 0x80000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x80000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 1900), (int)v4, a2);
          break;
        case 0x2Bu:
          if ( (*(_DWORD *)(this + 5800) & 0x100000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x100000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2000), (int)v4, a2);
          break;
        case 0x2Cu:
          if ( (*(_DWORD *)(this + 5800) & 0x200000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x200000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2100), (int)v4, a2);
          break;
        case 0x2Du:
          if ( (*(_DWORD *)(this + 5800) & 0x400000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x400000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2200), (int)v4, a2);
          break;
        case 0x2Eu:
          if ( (*(_DWORD *)(this + 5800) & 0x800000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x800000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2300), (int)v4, a2);
          break;
        case 0x2Fu:
          if ( (*(_DWORD *)(this + 5800) & 0x1000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x1000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2400), (int)v4, a2);
          break;
        case 0x30u:
          if ( (*(_DWORD *)(this + 5800) & 0x2000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x2000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2500), (int)v4, a2);
          break;
        case 0x31u:
          if ( (*(_DWORD *)(this + 5800) & 0x4000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x4000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2600), (int)v4, a2);
          break;
        case 0x32u:
          if ( (*(_DWORD *)(this + 5800) & 0x8000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x8000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2700), (int)v4, a2);
          break;
        case 0x33u:
          if ( (*(_DWORD *)(this + 5800) & 0x10000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2800), (int)v4, a2);
          break;
        case 0x34u:
          if ( (*(_DWORD *)(this + 5800) & 0x20000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 2900), (int)v4, a2);
          break;
        case 0x35u:
          if ( (*(_DWORD *)(this + 5800) & 0x40000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3000), (int)v4, a2);
          break;
        case 0x36u:
          if ( *(int *)(this + 5800) >= 0 )
            *(_DWORD *)(this + 5800) |= 0x80000000;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3100), (int)v4, a2);
          break;
        case 0x37u:
          if ( (*(_BYTE *)(this + 5804) & 1) == 0 )
            *(_DWORD *)(this + 5804) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3200), (int)v4, a2);
          break;
        case 0x38u:
          if ( (*(_DWORD *)(this + 5804) & 2) == 0 )
            *(_DWORD *)(this + 5804) |= 2u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3300), (int)v4, a2);
          break;
        case 0x43u:
          if ( (*(_DWORD *)(this + 5804) & 4) == 0 )
            *(_DWORD *)(this + 5804) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3400), (int)v4, a2);
          break;
        case 0x44u:
          if ( (*(_DWORD *)(this + 5804) & 8) == 0 )
            *(_DWORD *)(this + 5804) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3500), (int)v4, a2);
          break;
        case 0x45u:
          if ( (*(_DWORD *)(this + 5804) & 0x10) == 0 )
            *(_DWORD *)(this + 5804) |= 0x10u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3600), (int)v4, a2);
          break;
        case 0x46u:
          if ( (*(_DWORD *)(this + 5804) & 0x20) == 0 )
            *(_DWORD *)(this + 5804) |= 0x20u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3700), (int)v4, a2);
          break;
        case 0x4Cu:
          if ( (*(_DWORD *)(this + 5804) & 0x40) == 0 )
            *(_DWORD *)(this + 5804) |= 0x40u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3800), (int)v4, a2);
          break;
        case 0x4Du:
          if ( (*(_DWORD *)(this + 5804) & 0x80) == 0 )
            *(_DWORD *)(this + 5804) |= 0x80u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 3900), (int)v4, a2);
          break;
        case 0x4Eu:
          if ( (*(_DWORD *)(this + 5804) & 0x100) == 0 )
            *(_DWORD *)(this + 5804) |= 0x100u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4000), (int)v4, a2);
          break;
        case 0x4Fu:
          if ( (*(_DWORD *)(this + 5804) & 0x200) == 0 )
            *(_DWORD *)(this + 5804) |= 0x200u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4100), (int)v4, a2);
          break;
        case 0x50u:
          if ( (*(_DWORD *)(this + 5804) & 0x400) == 0 )
            *(_DWORD *)(this + 5804) |= 0x400u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4200), (int)v4, a2);
          break;
        case 0x51u:
          if ( (*(_DWORD *)(this + 5804) & 0x800) == 0 )
            *(_DWORD *)(this + 5804) |= 0x800u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4300), (int)v4, a2);
          break;
        case 0x52u:
          if ( (*(_DWORD *)(this + 5804) & 0x1000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x1000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4400), (int)v4, a2);
          break;
        case 0x53u:
          if ( (*(_DWORD *)(this + 5804) & 0x2000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x2000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4500), (int)v4, a2);
          break;
        case 0x54u:
          if ( (*(_DWORD *)(this + 5804) & 0x4000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x4000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4600), (int)v4, a2);
          break;
        case 0x55u:
          if ( (*(_DWORD *)(this + 5804) & 0x8000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x8000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4700), (int)v4, a2);
          break;
        case 0x56u:
          if ( (*(_DWORD *)(this + 5804) & 0x10000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x10000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4800), (int)v4, a2);
          break;
        case 0x57u:
          if ( (*(_DWORD *)(this + 5804) & 0x20000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x20000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 4900), (int)v4, a2);
          break;
        case 0x58u:
          if ( (*(_DWORD *)(this + 5804) & 0x40000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x40000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5000), (int)v4, a2);
          break;
        case 0x59u:
          if ( (*(_DWORD *)(this + 5804) & 0x80000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x80000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5100), (int)v4, a2);
          break;
        case 0x5Au:
          if ( (*(_DWORD *)(this + 5804) & 0x100000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x100000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5200), (int)v4, a2);
          break;
        case 0x5Bu:
          if ( (*(_DWORD *)(this + 5804) & 0x200000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x200000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5300), (int)v4, a2);
          break;
        case 0x8Eu:
          if ( (*(_DWORD *)(this + 5804) & 0x400000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x400000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5400), (int)v4, a2);
          break;
        case 0x8Fu:
          if ( (*(_DWORD *)(this + 5804) & 0x800000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x800000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5500), (int)v4, a2);
          break;
        case 0x91u:
          if ( (*(_DWORD *)(this + 5804) & 0x1000000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x1000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5600), (int)v4, a2);
          break;
        case 0x92u:
          if ( (*(_DWORD *)(this + 5804) & 0x2000000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x2000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0400((void *)(this + 5700), (int)v4, a2);
          break;
        default:
          v9 = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = v9;
      if ( v9 )
        return v6;
LABEL_296:
      if ( v4[1] >= v7 )
        goto LABEL_297;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0204::Read_0x99
// Address Name: SUB_101F7430
// ============================================================
//----- (101F7430) --------------------------------------------------------
int __thiscall sub_101F7430(int this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // edi
  int v6; // edx
  unsigned int v7; // ebx
  int result; // eax
  int v9; // eax
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v6 = 0;
  v10 = 0;
  *(_QWORD *)(this + 5800) = 0;
  v7 = v4[1] + v3;
  if ( v4[1] >= v7 )
  {
LABEL_297:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v10);
      if ( result )
        break;
      switch ( v10 >> 4 )
      {
        case 4u:
          if ( (*(_BYTE *)(this + 5800) & 1) == 0 )
            *(_DWORD *)(this + 5800) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)this, (int)v4, a2);
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 5800) & 2) == 0 )
            *(_DWORD *)(this + 5800) |= 2u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 100), (int)v4, a2);
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 5800) & 4) == 0 )
            *(_DWORD *)(this + 5800) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 200), (int)v4, a2);
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 5800) & 8) == 0 )
            *(_DWORD *)(this + 5800) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 300), (int)v4, a2);
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 5800) & 0x10) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 400), (int)v4, a2);
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 5800) & 0x20) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 500), (int)v4, a2);
          break;
        case 0x12u:
          if ( (*(_DWORD *)(this + 5800) & 0x40) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 600), (int)v4, a2);
          break;
        case 0x13u:
          if ( (*(_DWORD *)(this + 5800) & 0x80) == 0 )
            *(_DWORD *)(this + 5800) |= 0x80u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 700), (int)v4, a2);
          break;
        case 0x14u:
          if ( (*(_DWORD *)(this + 5800) & 0x100) == 0 )
            *(_DWORD *)(this + 5800) |= 0x100u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 800), (int)v4, a2);
          break;
        case 0x15u:
          if ( (*(_DWORD *)(this + 5800) & 0x200) == 0 )
            *(_DWORD *)(this + 5800) |= 0x200u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 900), (int)v4, a2);
          break;
        case 0x17u:
          if ( (*(_DWORD *)(this + 5800) & 0x400) == 0 )
            *(_DWORD *)(this + 5800) |= 0x400u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1000), (int)v4, a2);
          break;
        case 0x18u:
          if ( (*(_DWORD *)(this + 5800) & 0x800) == 0 )
            *(_DWORD *)(this + 5800) |= 0x800u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1100), (int)v4, a2);
          break;
        case 0x19u:
          if ( (*(_DWORD *)(this + 5800) & 0x1000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x1000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1200), (int)v4, a2);
          break;
        case 0x1Eu:
          if ( (*(_DWORD *)(this + 5800) & 0x2000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x2000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1300), (int)v4, a2);
          break;
        case 0x1Fu:
          if ( (*(_DWORD *)(this + 5800) & 0x4000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x4000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1400), (int)v4, a2);
          break;
        case 0x20u:
          if ( (*(_DWORD *)(this + 5800) & 0x8000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x8000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1500), (int)v4, a2);
          break;
        case 0x22u:
          if ( (*(_DWORD *)(this + 5800) & 0x10000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1600), (int)v4, a2);
          break;
        case 0x23u:
          if ( (*(_DWORD *)(this + 5800) & 0x20000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1700), (int)v4, a2);
          break;
        case 0x24u:
          if ( (*(_DWORD *)(this + 5800) & 0x40000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1800), (int)v4, a2);
          break;
        case 0x2Au:
          if ( (*(_DWORD *)(this + 5800) & 0x80000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x80000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 1900), (int)v4, a2);
          break;
        case 0x2Bu:
          if ( (*(_DWORD *)(this + 5800) & 0x100000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x100000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2000), (int)v4, a2);
          break;
        case 0x2Cu:
          if ( (*(_DWORD *)(this + 5800) & 0x200000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x200000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2100), (int)v4, a2);
          break;
        case 0x2Du:
          if ( (*(_DWORD *)(this + 5800) & 0x400000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x400000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2200), (int)v4, a2);
          break;
        case 0x2Eu:
          if ( (*(_DWORD *)(this + 5800) & 0x800000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x800000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2300), (int)v4, a2);
          break;
        case 0x2Fu:
          if ( (*(_DWORD *)(this + 5800) & 0x1000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x1000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2400), (int)v4, a2);
          break;
        case 0x30u:
          if ( (*(_DWORD *)(this + 5800) & 0x2000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x2000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2500), (int)v4, a2);
          break;
        case 0x31u:
          if ( (*(_DWORD *)(this + 5800) & 0x4000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x4000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2600), (int)v4, a2);
          break;
        case 0x32u:
          if ( (*(_DWORD *)(this + 5800) & 0x8000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x8000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2700), (int)v4, a2);
          break;
        case 0x33u:
          if ( (*(_DWORD *)(this + 5800) & 0x10000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x10000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2800), (int)v4, a2);
          break;
        case 0x34u:
          if ( (*(_DWORD *)(this + 5800) & 0x20000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x20000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 2900), (int)v4, a2);
          break;
        case 0x35u:
          if ( (*(_DWORD *)(this + 5800) & 0x40000000) == 0 )
            *(_DWORD *)(this + 5800) |= 0x40000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3000), (int)v4, a2);
          break;
        case 0x36u:
          if ( *(int *)(this + 5800) >= 0 )
            *(_DWORD *)(this + 5800) |= 0x80000000;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3100), (int)v4, a2);
          break;
        case 0x37u:
          if ( (*(_BYTE *)(this + 5804) & 1) == 0 )
            *(_DWORD *)(this + 5804) |= 1u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3200), (int)v4, a2);
          break;
        case 0x38u:
          if ( (*(_DWORD *)(this + 5804) & 2) == 0 )
            *(_DWORD *)(this + 5804) |= 2u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3300), (int)v4, a2);
          break;
        case 0x43u:
          if ( (*(_DWORD *)(this + 5804) & 4) == 0 )
            *(_DWORD *)(this + 5804) |= 4u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3400), (int)v4, a2);
          break;
        case 0x44u:
          if ( (*(_DWORD *)(this + 5804) & 8) == 0 )
            *(_DWORD *)(this + 5804) |= 8u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3500), (int)v4, a2);
          break;
        case 0x45u:
          if ( (*(_DWORD *)(this + 5804) & 0x10) == 0 )
            *(_DWORD *)(this + 5804) |= 0x10u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3600), (int)v4, a2);
          break;
        case 0x46u:
          if ( (*(_DWORD *)(this + 5804) & 0x20) == 0 )
            *(_DWORD *)(this + 5804) |= 0x20u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3700), (int)v4, a2);
          break;
        case 0x4Cu:
          if ( (*(_DWORD *)(this + 5804) & 0x40) == 0 )
            *(_DWORD *)(this + 5804) |= 0x40u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3800), (int)v4, a2);
          break;
        case 0x4Du:
          if ( (*(_DWORD *)(this + 5804) & 0x80) == 0 )
            *(_DWORD *)(this + 5804) |= 0x80u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 3900), (int)v4, a2);
          break;
        case 0x4Eu:
          if ( (*(_DWORD *)(this + 5804) & 0x100) == 0 )
            *(_DWORD *)(this + 5804) |= 0x100u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4000), (int)v4, a2);
          break;
        case 0x4Fu:
          if ( (*(_DWORD *)(this + 5804) & 0x200) == 0 )
            *(_DWORD *)(this + 5804) |= 0x200u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4100), (int)v4, a2);
          break;
        case 0x50u:
          if ( (*(_DWORD *)(this + 5804) & 0x400) == 0 )
            *(_DWORD *)(this + 5804) |= 0x400u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4200), (int)v4, a2);
          break;
        case 0x51u:
          if ( (*(_DWORD *)(this + 5804) & 0x800) == 0 )
            *(_DWORD *)(this + 5804) |= 0x800u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4300), (int)v4, a2);
          break;
        case 0x52u:
          if ( (*(_DWORD *)(this + 5804) & 0x1000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x1000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4400), (int)v4, a2);
          break;
        case 0x53u:
          if ( (*(_DWORD *)(this + 5804) & 0x2000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x2000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4500), (int)v4, a2);
          break;
        case 0x54u:
          if ( (*(_DWORD *)(this + 5804) & 0x4000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x4000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4600), (int)v4, a2);
          break;
        case 0x55u:
          if ( (*(_DWORD *)(this + 5804) & 0x8000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x8000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4700), (int)v4, a2);
          break;
        case 0x56u:
          if ( (*(_DWORD *)(this + 5804) & 0x10000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x10000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4800), (int)v4, a2);
          break;
        case 0x57u:
          if ( (*(_DWORD *)(this + 5804) & 0x20000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x20000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 4900), (int)v4, a2);
          break;
        case 0x58u:
          if ( (*(_DWORD *)(this + 5804) & 0x40000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x40000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5000), (int)v4, a2);
          break;
        case 0x59u:
          if ( (*(_DWORD *)(this + 5804) & 0x80000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x80000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5100), (int)v4, a2);
          break;
        case 0x5Au:
          if ( (*(_DWORD *)(this + 5804) & 0x100000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x100000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5200), (int)v4, a2);
          break;
        case 0x5Bu:
          if ( (*(_DWORD *)(this + 5804) & 0x200000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x200000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5300), (int)v4, a2);
          break;
        case 0x8Eu:
          if ( (*(_DWORD *)(this + 5804) & 0x400000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x400000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5400), (int)v4, a2);
          break;
        case 0x8Fu:
          if ( (*(_DWORD *)(this + 5804) & 0x800000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x800000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5500), (int)v4, a2);
          break;
        case 0x91u:
          if ( (*(_DWORD *)(this + 5804) & 0x1000000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x1000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5600), (int)v4, a2);
          break;
        case 0x92u:
          if ( (*(_DWORD *)(this + 5804) & 0x2000000) == 0 )
            *(_DWORD *)(this + 5804) |= 0x2000000u;
          a2 = 0;
          v6 = TdrBuf::ReadInt32(v4, &a2);
          if ( v6 )
            return v6;
          if ( !a2 )
            goto LABEL_296;
          v9 = sub_101B0520((void *)(this + 5700), (int)v4, a2);
          break;
        default:
          v9 = TdrBuf::SkipField(v4, v10 & 0xF);
          break;
      }
      v6 = v9;
      if ( v9 )
        return v6;
LABEL_296:
      if ( v4[1] >= v7 )
        goto LABEL_297;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0204::DoDebugFormat
// Address Name: SUB_101F8920
// ============================================================
//----- (101F8920) --------------------------------------------------------
int __thiscall sub_101F8920(unsigned __int8 *this, signed __int32 a2, int a3, _DWORD *a4, int a5, int a6)
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
  v7 = sub_101F89D0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0204::DebugFormat
// Address Name: SUB_101F89D0
// ============================================================
//----- (101F89D0) --------------------------------------------------------
int __thiscall sub_101F89D0(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // ecx
  unsigned __int8 *v7; // ecx
  unsigned __int8 *v8; // ecx
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // ecx
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned __int8 *v18; // ecx
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // ecx
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // ecx
  unsigned __int8 *v23; // ecx
  unsigned __int8 *v24; // ecx
  unsigned __int8 *v25; // ecx
  unsigned __int8 *v26; // ecx
  unsigned __int8 *v27; // ecx
  unsigned __int8 *v28; // ecx
  unsigned __int8 *v29; // ecx
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // ecx
  unsigned __int8 *v33; // ecx
  unsigned __int8 *v34; // ecx
  unsigned __int8 *v35; // ecx
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // ecx
  unsigned __int8 *v38; // ecx
  unsigned __int8 *v39; // ecx
  unsigned __int8 *v40; // ecx
  unsigned __int8 *v41; // ecx
  unsigned __int8 *v42; // ecx
  unsigned __int8 *v43; // ecx
  unsigned __int8 *v44; // ecx
  unsigned __int8 *v45; // ecx
  unsigned __int8 *v46; // ecx
  unsigned __int8 *v47; // ecx
  unsigned __int8 *v48; // ecx
  unsigned __int8 *v49; // ecx
  unsigned __int8 *v50; // ecx
  unsigned __int8 *v51; // ecx
  unsigned __int8 *v52; // ecx
  unsigned __int8 *v53; // ecx
  unsigned __int8 *v54; // ecx
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v56; // ecx
  unsigned __int8 *v57; // ecx
  unsigned __int8 *v58; // ecx
  unsigned __int8 *v59; // ecx
  unsigned __int8 *v60; // ecx
  unsigned __int8 *v61; // ecx

  if ( !"[oPetName]" )
    _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
  result = sub_1024A140(a3);
  if ( !result )
  {
    result = Printf(a2, "%s%c", "[oPetName]", (char)a4);
    if ( !result )
    {
      result = a3 >= 0 ? sub_101B0710(this, a2, a3 + 1, a4) : sub_101B0710(this, a2, a3, a4);
      if ( !result )
      {
        result = print_structure((int)a2, a3, a4, (int)"[oPetSex]");
        if ( !result )
        {
          v5 = this + 100;
          result = a3 >= 0 ? sub_101B0710(v5, a2, a3 + 1, a4) : sub_101B0710(v5, a2, a3, a4);
          if ( !result )
          {
            result = print_structure((int)a2, a3, a4, (int)"[oOwner]");
            if ( !result )
            {
              v6 = this + 200;
              result = a3 >= 0 ? sub_101B0710(v6, a2, a3 + 1, a4) : sub_101B0710(v6, a2, a3, a4);
              if ( !result )
              {
                result = print_structure((int)a2, a3, a4, (int)"[oPetSignature]");
                if ( !result )
                {
                  v7 = this + 300;
                  result = a3 >= 0 ? sub_101B0710(v7, a2, a3 + 1, a4) : sub_101B0710(v7, a2, a3, a4);
                  if ( !result )
                  {
                    result = print_structure((int)a2, a3, a4, (int)"[oPetExp]");
                    if ( !result )
                    {
                      v8 = this + 400;
                      result = a3 >= 0 ? sub_101B0710(v8, a2, a3 + 1, a4) : sub_101B0710(v8, a2, a3, a4);
                      if ( !result )
                      {
                        result = print_structure((int)a2, a3, a4, (int)"[oPetLevel]");
                        if ( !result )
                        {
                          v9 = this + 500;
                          result = a3 >= 0 ? sub_101B0710(v9, a2, a3 + 1, a4) : sub_101B0710(v9, a2, a3, a4);
                          if ( !result )
                          {
                            result = print_structure((int)a2, a3, a4, (int)"[oSpirit]");
                            if ( !result )
                            {
                              v10 = this + 600;
                              result = a3 >= 0 ? sub_101B0710(v10, a2, a3 + 1, a4) : sub_101B0710(v10, a2, a3, a4);
                              if ( !result )
                              {
                                result = print_structure((int)a2, a3, a4, (int)"[oVigour]");
                                if ( !result )
                                {
                                  v11 = this + 700;
                                  result = a3 >= 0 ? sub_101B0710(v11, a2, a3 + 1, a4) : sub_101B0710(v11, a2, a3, a4);
                                  if ( !result )
                                  {
                                    result = print_structure((int)a2, a3, a4, (int)"[oPetHP]");
                                    if ( !result )
                                    {
                                      v12 = this + 800;
                                      result = a3 >= 0
                                             ? sub_101B0710(v12, a2, a3 + 1, a4)
                                             : sub_101B0710(v12, a2, a3, a4);
                                      if ( !result )
                                      {
                                        result = print_structure((int)a2, a3, a4, (int)"[oPetMaxHP]");
                                        if ( !result )
                                        {
                                          v13 = this + 900;
                                          result = a3 >= 0
                                                 ? sub_101B0710(v13, a2, a3 + 1, a4)
                                                 : sub_101B0710(v13, a2, a3, a4);
                                          if ( !result )
                                          {
                                            result = print_structure((int)a2, a3, a4, (int)"[oPetMelee]");
                                            if ( !result )
                                            {
                                              v14 = this + 1000;
                                              result = a3 >= 0
                                                     ? sub_101B0710(v14, a2, a3 + 1, a4)
                                                     : sub_101B0710(v14, a2, a3, a4);
                                              if ( !result )
                                              {
                                                result = print_structure((int)a2, a3, a4, (int)"[oPetDefence]");
                                                if ( !result )
                                                {
                                                  v15 = this + 1100;
                                                  result = a3 >= 0
                                                         ? sub_101B0710(v15, a2, a3 + 1, a4)
                                                         : sub_101B0710(v15, a2, a3, a4);
                                                  if ( !result )
                                                  {
                                                    result = print_structure((int)a2, a3, a4, (int)"[oCritLevel]");
                                                    if ( !result )
                                                    {
                                                      v16 = this + 1200;
                                                      result = a3 >= 0
                                                             ? sub_101B0710(v16, a2, a3 + 1, a4)
                                                             : sub_101B0710(v16, a2, a3, a4);
                                                      if ( !result )
                                                      {
                                                        result = print_structure(
                                                                   (int)a2,
                                                                   a3,
                                                                   a4,
                                                                   (int)"[oPetExecution]");
                                                        if ( !result )
                                                        {
                                                          v17 = this + 1300;
                                                          result = a3 >= 0
                                                                 ? sub_101B0710(v17, a2, a3 + 1, a4)
                                                                 : sub_101B0710(v17, a2, a3, a4);
                                                          if ( !result )
                                                          {
                                                            result = print_structure(
                                                                       (int)a2,
                                                                       a3,
                                                                       a4,
                                                                       (int)"[oPetObservation]");
                                                            if ( !result )
                                                            {
                                                              v18 = this + 1400;
                                                              result = a3 >= 0
                                                                     ? sub_101B0710(v18, a2, a3 + 1, a4)
                                                                     : sub_101B0710(v18, a2, a3, a4);
                                                              if ( !result )
                                                              {
                                                                result = print_structure(
                                                                           (int)a2,
                                                                           a3,
                                                                           a4,
                                                                           (int)"[oPetLoadBearing]");
                                                                if ( !result )
                                                                {
                                                                  v19 = this + 1500;
                                                                  result = a3 >= 0
                                                                         ? sub_101B0710(v19, a2, a3 + 1, a4)
                                                                         : sub_101B0710(v19, a2, a3, a4);
                                                                  if ( !result )
                                                                  {
                                                                    result = print_structure(
                                                                               (int)a2,
                                                                               a3,
                                                                               a4,
                                                                               (int)"[oPetMaxSp]");
                                                                    if ( !result )
                                                                    {
                                                                      v20 = this + 1600;
                                                                      result = a3 >= 0
                                                                             ? sub_101B0710(v20, a2, a3 + 1, a4)
                                                                             : sub_101B0710(v20, a2, a3, a4);
                                                                      if ( !result )
                                                                      {
                                                                        result = print_structure(
                                                                                   (int)a2,
                                                                                   a3,
                                                                                   a4,
                                                                                   (int)"[oPetSp]");
                                                                        if ( !result )
                                                                        {
                                                                          v21 = this + 1700;
                                                                          result = a3 >= 0
                                                                                 ? sub_101B0710(v21, a2, a3 + 1, a4)
                                                                                 : sub_101B0710(v21, a2, a3, a4);
                                                                          if ( !result )
                                                                          {
                                                                            result = print_structure(
                                                                                       (int)a2,
                                                                                       a3,
                                                                                       a4,
                                                                                       (int)"[oPetPotential]");
                                                                            if ( !result )
                                                                            {
                                                                              v22 = this + 1800;
                                                                              result = a3 >= 0
                                                                                     ? sub_101B0710(v22, a2, a3 + 1, a4)
                                                                                     : sub_101B0710(v22, a2, a3, a4);
                                                                              if ( !result )
                                                                              {
                                                                                result = print_structure(
                                                                                           (int)a2,
                                                                                           a3,
                                                                                           a4,
                                                                                           (int)"[oWaterAtk]");
                                                                                if ( !result )
                                                                                {
                                                                                  v23 = this + 1900;
                                                                                  result = a3 >= 0
                                                                                         ? sub_101B0710(
                                                                                             v23,
                                                                                             a2,
                                                                                             a3 + 1,
                                                                                             a4)
                                                                                         : sub_101B0710(v23, a2, a3, a4);
                                                                                  if ( !result )
                                                                                  {
                                                                                    result = print_structure(
                                                                                               (int)a2,
                                                                                               a3,
                                                                                               a4,
                                                                                               (int)"[oFireAtk]");
                                                                                    if ( !result )
                                                                                    {
                                                                                      v24 = this + 2000;
                                                                                      result = a3 >= 0
                                                                                             ? sub_101B0710(
                                                                                                 v24,
                                                                                                 a2,
                                                                                                 a3 + 1,
                                                                                                 a4)
                                                                                             : sub_101B0710(
                                                                                                 v24,
                                                                                                 a2,
                                                                                                 a3,
                                                                                                 a4);
                                                                                      if ( !result )
                                                                                      {
                                                                                        result = print_structure(
                                                                                                   (int)a2,
                                                                                                   a3,
                                                                                                   a4,
                                                                                                   (int)"[oLightningAtk]");
                                                                                        if ( !result )
                                                                                        {
                                                                                          v25 = this + 2100;
                                                                                          result = a3 >= 0
                                                                                                 ? sub_101B0710(
                                                                                                     v25,
                                                                                                     a2,
                                                                                                     a3 + 1,
                                                                                                     a4)
                                                                                                 : sub_101B0710(
                                                                                                     v25,
                                                                                                     a2,
                                                                                                     a3,
                                                                                                     a4);
                                                                                          if ( !result )
                                                                                          {
                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oDragonAtk]");
                                                                                            if ( !result )
                                                                                            {
                                                                                              v26 = this + 2200;
                                                                                              result = a3 >= 0 ? sub_101B0710(v26, a2, a3 + 1, a4) : sub_101B0710(v26, a2, a3, a4);
                                                                                              if ( !result )
                                                                                              {
                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oIceAtk]");
                                                                                                if ( !result )
                                                                                                {
                                                                                                  v27 = this + 2300;
                                                                                                  result = a3 >= 0 ? sub_101B0710(v27, a2, a3 + 1, a4) : sub_101B0710(v27, a2, a3, a4);
                                                                                                  if ( !result )
                                                                                                  {
                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oWaterRes]");
                                                                                                    if ( !result )
                                                                                                    {
                                                                                                      v28 = this + 2400;
                                                                                                      result = a3 >= 0 ? sub_101B0710(v28, a2, a3 + 1, a4) : sub_101B0710(v28, a2, a3, a4);
                                                                                                      if ( !result )
                                                                                                      {
                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oFireRes]");
                                                                                                        if ( !result )
                                                                                                        {
                                                                                                          v29 = this + 2500;
                                                                                                          result = a3 >= 0 ? sub_101B0710(v29, a2, a3 + 1, a4) : sub_101B0710(v29, a2, a3, a4);
                                                                                                          if ( !result )
                                                                                                          {
                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oLightningRes]");
                                                                                                            if ( !result )
                                                                                                            {
                                                                                                              v30 = this + 2600;
                                                                                                              result = a3 >= 0 ? sub_101B0710(v30, a2, a3 + 1, a4) : sub_101B0710(v30, a2, a3, a4);
                                                                                                              if ( !result )
                                                                                                              {
                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oDragonRes]");
                                                                                                                if ( !result )
                                                                                                                {
                                                                                                                  v31 = this + 2700;
                                                                                                                  result = a3 >= 0 ? sub_101B0710(v31, a2, a3 + 1, a4) : sub_101B0710(v31, a2, a3, a4);
                                                                                                                  if ( !result )
                                                                                                                  {
                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oIceRes]");
                                                                                                                    if ( !result )
                                                                                                                    {
                                                                                                                      v32 = this + 2800;
                                                                                                                      result = a3 >= 0 ? sub_101B0710(v32, a2, a3 + 1, a4) : sub_101B0710(v32, a2, a3, a4);
                                                                                                                      if ( !result )
                                                                                                                      {
                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oWaterThrsh]");
                                                                                                                        if ( !result )
                                                                                                                        {
                                                                                                                          v33 = this + 2900;
                                                                                                                          result = a3 >= 0 ? sub_101B0710(v33, a2, a3 + 1, a4) : sub_101B0710(v33, a2, a3, a4);
                                                                                                                          if ( !result )
                                                                                                                          {
                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oFireThrsh]");
                                                                                                                            if ( !result )
                                                                                                                            {
                                                                                                                              v34 = this + 3000;
                                                                                                                              result = a3 >= 0 ? sub_101B0710(v34, a2, a3 + 1, a4) : sub_101B0710(v34, a2, a3, a4);
                                                                                                                              if ( !result )
                                                                                                                              {
                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oLightningThrsh]");
                                                                                                                                if ( !result )
                                                                                                                                {
                                                                                                                                  v35 = this + 3100;
                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v35, a2, a3 + 1, a4) : sub_101B0710(v35, a2, a3, a4);
                                                                                                                                  if ( !result )
                                                                                                                                  {
                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oDragonThrsh]");
                                                                                                                                    if ( !result )
                                                                                                                                    {
                                                                                                                                      v36 = this + 3200;
                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v36, a2, a3 + 1, a4) : sub_101B0710(v36, a2, a3, a4);
                                                                                                                                      if ( !result )
                                                                                                                                      {
                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oIceThrsh]");
                                                                                                                                        if ( !result )
                                                                                                                                        {
                                                                                                                                          v37 = this + 3300;
                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v37, a2, a3 + 1, a4) : sub_101B0710(v37, a2, a3, a4);
                                                                                                                                          if ( !result )
                                                                                                                                          {
                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oComaThrsh]");
                                                                                                                                            if ( !result )
                                                                                                                                            {
                                                                                                                                              v38 = this + 3400;
                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v38, a2, a3 + 1, a4) : sub_101B0710(v38, a2, a3, a4);
                                                                                                                                              if ( !result )
                                                                                                                                              {
                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oPoisonThrsh]");
                                                                                                                                                if ( !result )
                                                                                                                                                {
                                                                                                                                                  v39 = this + 3500;
                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v39, a2, a3 + 1, a4) : sub_101B0710(v39, a2, a3, a4);
                                                                                                                                                  if ( !result )
                                                                                                                                                  {
                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oSleepingThrsh]");
                                                                                                                                                    if ( !result )
                                                                                                                                                    {
                                                                                                                                                      v40 = this + 3600;
                                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v40, a2, a3 + 1, a4) : sub_101B0710(v40, a2, a3, a4);
                                                                                                                                                      if ( !result )
                                                                                                                                                      {
                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oParaThrsh]");
                                                                                                                                                        if ( !result )
                                                                                                                                                        {
                                                                                                                                                          v41 = this + 3700;
                                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v41, a2, a3 + 1, a4) : sub_101B0710(v41, a2, a3, a4);
                                                                                                                                                          if ( !result )
                                                                                                                                                          {
                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oWindPressureDef]");
                                                                                                                                                            if ( !result )
                                                                                                                                                            {
                                                                                                                                                              v42 = this + 3800;
                                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v42, a2, a3 + 1, a4) : sub_101B0710(v42, a2, a3, a4);
                                                                                                                                                              if ( !result )
                                                                                                                                                              {
                                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oQuakeDef]");
                                                                                                                                                                if ( !result )
                                                                                                                                                                {
                                                                                                                                                                  v43 = this + 3900;
                                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v43, a2, a3 + 1, a4) : sub_101B0710(v43, a2, a3, a4);
                                                                                                                                                                  if ( !result )
                                                                                                                                                                  {
                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oRoarDef]");
                                                                                                                                                                    if ( !result )
                                                                                                                                                                    {
                                                                                                                                                                      v44 = this + 4000;
                                                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v44, a2, a3 + 1, a4) : sub_101B0710(v44, a2, a3, a4);
                                                                                                                                                                      if ( !result )
                                                                                                                                                                      {
                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oPalsyDef]");
                                                                                                                                                                        if ( !result )
                                                                                                                                                                        {
                                                                                                                                                                          v45 = this + 4100;
                                                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v45, a2, a3 + 1, a4) : sub_101B0710(v45, a2, a3, a4);
                                                                                                                                                                          if ( !result )
                                                                                                                                                                          {
                                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oSnowManDef]");
                                                                                                                                                                            if ( !result )
                                                                                                                                                                            {
                                                                                                                                                                              v46 = this + 4200;
                                                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v46, a2, a3 + 1, a4) : sub_101B0710(v46, a2, a3, a4);
                                                                                                                                                                              if ( !result )
                                                                                                                                                                              {
                                                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oTiredDef]");
                                                                                                                                                                                if ( !result )
                                                                                                                                                                                {
                                                                                                                                                                                  v47 = this + 4300;
                                                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v47, a2, a3 + 1, a4) : sub_101B0710(v47, a2, a3, a4);
                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                  {
                                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oAttackLevelDef]");
                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                    {
                                                                                                                                                                                      v48 = this + 4400;
                                                                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v48, a2, a3 + 1, a4) : sub_101B0710(v48, a2, a3, a4);
                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                      {
                                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oPetSkillID]");
                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                        {
                                                                                                                                                                                          v49 = this + 4500;
                                                                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v49, a2, a3 + 1, a4) : sub_101B0710(v49, a2, a3, a4);
                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                          {
                                                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oEquipedSkillID]");
                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                            {
                                                                                                                                                                                              v50 = this + 4600;
                                                                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v50, a2, a3 + 1, a4) : sub_101B0710(v50, a2, a3, a4);
                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                              {
                                                                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oPetWeaponID]");
                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                {
                                                                                                                                                                                                  v51 = this + 4700;
                                                                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v51, a2, a3 + 1, a4) : sub_101B0710(v51, a2, a3, a4);
                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                  {
                                                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oPetHatID]");
                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                    {
                                                                                                                                                                                                      v52 = this + 4800;
                                                                                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v52, a2, a3 + 1, a4) : sub_101B0710(v52, a2, a3, a4);
                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                      {
                                                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oPetBodyID]");
                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                        {
                                                                                                                                                                                                          v53 = this + 4900;
                                                                                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v53, a2, a3 + 1, a4) : sub_101B0710(v53, a2, a3, a4);
                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                          {
                                                                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oFashionWwaponID]");
                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                            {
                                                                                                                                                                                                              v54 = this + 5000;
                                                                                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v54, a2, a3 + 1, a4) : sub_101B0710(v54, a2, a3, a4);
                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                              {
                                                                                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oFashionHatID]");
                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                {
                                                                                                                                                                                                                  v55 = this + 5100;
                                                                                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v55, a2, a3 + 1, a4) : sub_101B0710(v55, a2, a3, a4);
                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                  {
                                                                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oFashionBodyID]");
                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                      v56 = this + 5200;
                                                                                                                                                                                                                      result = a3 >= 0 ? sub_101B0710(v56, a2, a3 + 1, a4) : sub_101B0710(v56, a2, a3, a4);
                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oRegion]");
                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                        {
                                                                                                                                                                                                                          v57 = this + 5300;
                                                                                                                                                                                                                          result = a3 >= 0 ? sub_101B0710(v57, a2, a3 + 1, a4) : sub_101B0710(v57, a2, a3, a4);
                                                                                                                                                                                                                          if ( !result )
                                                                                                                                                                                                                          {
                                                                                                                                                                                                                            result = print_structure((int)a2, a3, a4, (int)"[oPetMana]");
                                                                                                                                                                                                                            if ( !result )
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                              v58 = this + 5400;
                                                                                                                                                                                                                              result = a3 >= 0 ? sub_101B0710(v58, a2, a3 + 1, a4) : sub_101B0710(v58, a2, a3, a4);
                                                                                                                                                                                                                              if ( !result )
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                result = print_structure((int)a2, a3, a4, (int)"[oPetMaxMana]");
                                                                                                                                                                                                                                if ( !result )
                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                  v59 = this + 5500;
                                                                                                                                                                                                                                  result = a3 >= 0 ? sub_101B0710(v59, a2, a3 + 1, a4) : sub_101B0710(v59, a2, a3, a4);
                                                                                                                                                                                                                                  if ( !result )
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                    result = print_structure((int)a2, a3, a4, (int)"[oAnimusHide]");
                                                                                                                                                                                                                                    if ( !result )
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                      v60 = this + 5600;
                                                                                                                                                                                                                                      if ( a3 >= 0 )
                                                                                                                                                                                                                                        result = sub_101B0710(v60, a2, a3 + 1, a4);
                                                                                                                                                                                                                                      else
                                                                                                                                                                                                                                        result = sub_101B0710(v60, a2, a3, a4);
                                                                                                                                                                                                                                      if ( !result )
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                        result = print_structure((int)a2, a3, a4, (int)"[oNoInterupt]");
                                                                                                                                                                                                                                        if ( !result )
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                          v61 = this + 5700;
                                                                                                                                                                                                                                          if ( a3 >= 0 )
                                                                                                                                                                                                                                            return sub_101B0710(v61, a2, a3 + 1, a4);
                                                                                                                                                                                                                                          else
                                                                                                                                                                                                                                            return sub_101B0710(v61, a2, a3, a4);
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
// Address Name: SUB_101B0400
// ============================================================
//----- (101B0400) --------------------------------------------------------
int __thiscall sub_101B0400(void *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *((_DWORD *)this + 24) = 0;
  v6 = v4[1] + v3;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*((_BYTE *)this + 96) & 1) == 0 )
        *((_DWORD *)this + 24) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *(_BYTE *)this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*((_DWORD *)this + 24) & 2) == 0 )
        *((_DWORD *)this + 24) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AFD20((char *)this + 1, &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *(_BYTE *)this = v10;
      }
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
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
// Address Name: SUB_101B0520
// ============================================================
//----- (101B0520) --------------------------------------------------------
int __thiscall sub_101B0520(void *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *((_DWORD *)this + 24) = 0;
  v6 = v4[1] + v3;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*((_BYTE *)this + 96) & 1) == 0 )
        *((_DWORD *)this + 24) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *(_BYTE *)this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*((_DWORD *)this + 24) & 2) == 0 )
        *((_DWORD *)this + 24) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AFE20((char *)this + 1, &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *(_BYTE *)this = v10;
      }
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
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
// Address Name: SUB_101B0710
// ============================================================
//----- (101B0710) --------------------------------------------------------
int __thiscall sub_101B0710(unsigned __int8 *this, _DWORD *a2, int a3, int a4)
{
  int result; // eax
  unsigned __int8 *v5; // ecx

  result = print_field(a2, a3, a4, "[type]", "%d", *this);
  if ( !result )
  {
    if ( !"[value]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[value]", (char)a4);
      if ( !result )
      {
        v5 = this + 1;
        if ( a3 >= 0 )
          return sub_101AFFD0(v5, *this, 0, a2, a3 + 1, a4);
        else
          return sub_101AFFD0(v5, *this, 0, a2, a3, a4);
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AFD20
// ============================================================
//----- (101AFD20) --------------------------------------------------------
int __thiscall sub_101AFD20(char *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  signed int v7; // ebx
  int v8; // esi
  int v9; // [esp+Ch] [ebp-8h]

  if ( !a4 )
    return 0;
  v5 = (_DWORD *)a3;
  v6 = (_DWORD *)a3;
  a3 = 0;
  v9 = v6[1];
  result = TdrBuf::ReadVarUInt(v6, &a3);
  if ( result )
    return result;
  v7 = a3 >> 4;
  if ( a3 >> 4 == 1 )
  {
    a3 = 0;
    result = TdrBuf::ReadInt32(v5, &a3);
    v8 = result;
    if ( result )
      return result;
    if ( a3 )
    {
      result = sub_101AEBA0(this, (int)v5, a3);
      v8 = result;
      if ( result )
        return result;
    }
LABEL_15:
    if ( v5[1] > (unsigned int)(v9 + a4) )
      return -34;
    *a2 = v7;
    return v8;
  }
  if ( a3 >> 4 != 2 )
  {
    result = TdrBuf::SkipField(v5, a3 & 0xF);
    v8 = result;
    if ( result )
      return result;
    goto LABEL_15;
  }
  a3 = 0;
  result = TdrBuf::ReadInt32(v5, &a3);
  v8 = result;
  if ( !result )
  {
    if ( !a3 )
      goto LABEL_15;
    result = sub_101AF510((int)this, v5, (char *)a3);
    v8 = result;
    if ( !result )
      goto LABEL_15;
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AFE20
// ============================================================
//----- (101AFE20) --------------------------------------------------------
int __thiscall sub_101AFE20(char *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  signed int v7; // ebx
  int v8; // esi
  int v9; // [esp+Ch] [ebp-8h]

  if ( !a4 )
    return 0;
  v5 = (_DWORD *)a3;
  v6 = (_DWORD *)a3;
  a3 = 0;
  v9 = v6[1];
  result = TdrBuf::ReadVarUInt(v6, &a3);
  if ( result )
    return result;
  v7 = a3 >> 4;
  if ( a3 >> 4 == 1 )
  {
    a3 = 0;
    result = TdrBuf::ReadInt32(v5, &a3);
    v8 = result;
    if ( result )
      return result;
    if ( a3 )
    {
      result = sub_101AECC0(this, (int)v5, a3);
      v8 = result;
      if ( result )
        return result;
    }
LABEL_15:
    if ( v5[1] > (unsigned int)(v9 + a4) )
      return -34;
    *a2 = v7;
    return v8;
  }
  if ( a3 >> 4 != 2 )
  {
    result = TdrBuf::SkipField(v5, a3 & 0xF);
    v8 = result;
    if ( result )
      return result;
    goto LABEL_15;
  }
  a3 = 0;
  result = TdrBuf::ReadInt32(v5, &a3);
  v8 = result;
  if ( !result )
  {
    if ( !a3 )
      goto LABEL_15;
    result = sub_101AF640((int)this, v5, (char *)a3);
    v8 = result;
    if ( !result )
      goto LABEL_15;
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
// Address Name: SUB_101AFFD0
// ============================================================
//----- (101AFFD0) --------------------------------------------------------
int __thiscall sub_101AFFD0(unsigned __int8 *this, int a2, int a3, _DWORD *a4, int a5, int a6)
{
  int result; // eax

  result = 0;
  if ( a2 != 1 || a3 )
  {
    if ( a2 == 2 && !a3 )
    {
      result = print_structure((int)a4, a5, a6, (int)"[bonus]");
      if ( !result )
      {
        if ( a5 >= 0 )
          return sub_101AF840(this, a4, a5 + 1, a6);
        else
          return sub_101AF840(this, a4, a5, a6);
      }
    }
  }
  else
  {
    if ( !"[base]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a5);
    if ( !result )
    {
      result = Printf(a4, "%s%c", "[base]", (char)a6);
      if ( !result )
      {
        if ( a5 >= 0 )
          return sub_101AEEB0(this, a4, a5 + 1, a6);
        else
          return sub_101AEEB0(this, a4, a5, a6);
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AEBA0
// ============================================================
//----- (101AEBA0) --------------------------------------------------------
int __thiscall sub_101AEBA0(char *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AE4E0((int *)(this + 1), &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *this = v10;
      }
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
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
// Address Name: SUB_101AF510
// ============================================================
//----- (101AF510) --------------------------------------------------------
int __thiscall sub_101AF510(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  char *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  char *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (char *)this;
  v6 = 0;
  v15 = (char *)this;
  v14 = 0;
  *(_DWORD *)(this + 91) = 0;
  v7 = &v3[v4[1]];
  v11 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_19:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v5[91] & 1) == 0 )
          *(_DWORD *)(v5 + 91) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v4[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          v6 = TdrBuf::ReadInt32(v4, &v13);
          if ( v6 )
            return v6;
          if ( v13 )
          {
            v6 = sub_101AEBA0(a3, (int)v4, v13);
            if ( v6 )
              return v6;
          }
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 13;
            if ( (unsigned int)++v9 < 7 )
              continue;
          }
          v5 = v15;
          goto LABEL_18;
        }
      }
      v6 = TdrBuf::SkipField(v4, v14 & 0xF);
      if ( v6 )
        return v6;
LABEL_18:
      v7 = v11;
      if ( v4[1] >= (unsigned int)v11 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AECC0
// ============================================================
//----- (101AECC0) --------------------------------------------------------
int __thiscall sub_101AECC0(char *this, int a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // esi
  unsigned int v6; // ebx
  bool v7; // cf
  int result; // eax
  int v9; // ecx
  __int64 v10; // [esp+10h] [ebp-10h] BYREF
  unsigned int v11; // [esp+1Ch] [ebp-4h] BYREF

  v3 = a3;
  v4 = (_DWORD *)a2;
  v11 = 0;
  *(_DWORD *)(this + 9) = 0;
  v6 = v4[1] + v3;
  v7 = v6 < v4[1];
  if ( v6 <= v4[1] )
    return v7 ? 0xFFFFFFDE : 0;
  while ( 1 )
  {
    result = TdrBuf::ReadVarUInt(v4, &v11);
    if ( result )
      break;
    if ( v11 >> 4 == 1 )
    {
      if ( (*(this + 9) & 1) == 0 )
        *(_DWORD *)(this + 9) |= 1u;
      if ( v4[1] > v4[2] )
        _wassert(L"position <= length", L"d:\\mhfc\\oprelease\\code\\common\\protocols\\packetcode\\TdrBuf.h", 0x290u);
      v9 = v4[1];
      if ( v4[2] == v9 )
        return -2;
      *this = *(_BYTE *)(v9 + *v4);
      ++v4[1];
    }
    else if ( v11 >> 4 == 2 )
    {
      if ( (*(_DWORD *)(this + 9) & 2) == 0 )
        *(_DWORD *)(this + 9) |= 2u;
      a2 = 0;
      result = TdrBuf::ReadInt32(v4, &a2);
      if ( result )
        return result;
      if ( a2 )
      {
        v10 = 0;
        result = sub_101AE5F0(this + 1, &v10, (unsigned int)v4, a2);
        if ( result )
          return result;
        *this = v10;
      }
    }
    else
    {
      result = TdrBuf::SkipField(v4, v11 & 0xF);
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
// Address Name: SUB_101AF640
// ============================================================
//----- (101AF640) --------------------------------------------------------
int __thiscall sub_101AF640(int this, _DWORD *a2, char *a3)
{
  char *v3; // eax
  _DWORD *v4; // esi
  char *v5; // ebx
  int v6; // edi
  char *v7; // eax
  int result; // eax
  int v9; // ebx
  unsigned int v10; // ecx
  char *v11; // [esp+Ch] [ebp-14h]
  int v12; // [esp+10h] [ebp-10h]
  int v13; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v14; // [esp+18h] [ebp-8h] BYREF
  char *v15; // [esp+1Ch] [ebp-4h]

  v3 = a3;
  v4 = a2;
  v5 = (char *)this;
  v6 = 0;
  v15 = (char *)this;
  v14 = 0;
  *(_DWORD *)(this + 91) = 0;
  v7 = &v3[v4[1]];
  v11 = v7;
  if ( v4[1] >= (unsigned int)v7 )
  {
LABEL_19:
    if ( v4[1] > (unsigned int)v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 1 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v14);
      if ( result )
        break;
      if ( v14 >> 4 == 1 )
      {
        if ( (v5[91] & 1) == 0 )
          *(_DWORD *)(v5 + 91) |= 1u;
        a2 = 0;
        result = TdrBuf::ReadInt32(v4, &a2);
        if ( result )
          return result;
        if ( !a2 )
          return -37;
        v9 = 0;
        v12 = v4[1];
        a3 = v15;
        while ( 1 )
        {
          v13 = 0;
          v6 = TdrBuf::ReadInt32(v4, &v13);
          if ( v6 )
            return v6;
          if ( v13 )
          {
            v6 = sub_101AECC0(a3, (int)v4, v13);
            if ( v6 )
              return v6;
          }
          v10 = v4[1];
          if ( v10 > (unsigned int)a2 + v12 )
            return -34;
          if ( (_DWORD *)v10 != (_DWORD *)((char *)a2 + v12) )
          {
            a3 += 13;
            if ( (unsigned int)++v9 < 7 )
              continue;
          }
          v5 = v15;
          goto LABEL_18;
        }
      }
      v6 = TdrBuf::SkipField(v4, v14 & 0xF);
      if ( v6 )
        return v6;
LABEL_18:
      v7 = v11;
      if ( v4[1] >= (unsigned int)v11 )
        goto LABEL_19;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AEEB0
// ============================================================
//----- (101AEEB0) --------------------------------------------------------
int __thiscall sub_101AEEB0(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax
  float *v5; // ecx

  result = print_field(a2, a3, a4, "[wType]", "%d", *this);
  if ( !result )
  {
    if ( !"[stValue]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x2Bu);
    result = sub_1024A140(a3);
    if ( !result )
    {
      result = Printf(a2, "%s%c", "[stValue]", a4);
      if ( !result )
      {
        v5 = (float *)(this + 1);
        if ( a3 >= 0 )
          return sub_101AE7B0(v5, *this, 0, a2, a3 + 1, a4);
        else
          return sub_101AE7B0(v5, *this, 0, a2, a3, a4);
      }
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AF840
// ============================================================
//----- (101AF840) --------------------------------------------------------
int __thiscall sub_101AF840(unsigned __int8 *this, _DWORD *a2, int a3, char a4)
{
  unsigned int i; // esi
  int result; // eax

  for ( i = 0; i < 7; ++i )
  {
    if ( !"[value]" )
      _wassert(L"NULL != variable", L"D:\\MHFC\\OpRelease\\Code\\Common\\Protocols\\PacketCode\\TdrBufUtil.cpp", 0x43u);
    result = sub_1024A140(a3);
    if ( result )
      break;
    result = Printf(a2, "%s[%u]%c", "[value]", i, a4);
    if ( result )
      break;
    result = a3 >= 0 ? sub_101AEEB0(this, a2, a3 + 1, a4) : sub_101AEEB0(this, a2, a3, a4);
    if ( result )
      break;
    this += 13;
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AE4E0
// ============================================================
//----- (101AE4E0) --------------------------------------------------------
int __thiscall sub_101AE4E0(int *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  if ( !a4 )
    return 0;
  v6 = (_DWORD *)a3;
  v7 = (_DWORD *)a3;
  a3 = 0;
  v10 = v7[1];
  result = TdrBuf::ReadVarUInt(v7, &a3);
  if ( !result )
  {
    v9 = a3 >> 4;
    switch ( a3 >> 4 )
    {
      case 1u:
        result = TdrBuf::ReadVarInt(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 2u:
        result = TdrBuf::ReadInt32(v6, &a3);
        v8 = result;
        if ( !result )
        {
          *this = a3;
          goto LABEL_14;
        }
        break;
      case 4u:
        result = TdrBuf::ReadVarShort(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 6u:
        result = TdrBuf::ReadVarULong(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      default:
        result = TdrBuf::SkipField(v6, a3 & 0xF);
        v8 = result;
        if ( !result )
        {
LABEL_14:
          if ( v6[1] <= (unsigned int)(v10 + a4) )
          {
            *a2 = v9;
            result = v8;
          }
          else
          {
            result = -34;
          }
        }
        break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AE5F0
// ============================================================
//----- (101AE5F0) --------------------------------------------------------
int __thiscall sub_101AE5F0(_BYTE *this, _QWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD *v6; // edi
  _DWORD *v7; // ecx
  int v8; // esi
  signed int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  if ( !a4 )
    return 0;
  v6 = (_DWORD *)a3;
  v7 = (_DWORD *)a3;
  a3 = 0;
  v10 = v7[1];
  result = TdrBuf::ReadVarUInt(v7, &a3);
  if ( !result )
  {
    v9 = a3 >> 4;
    switch ( a3 >> 4 )
    {
      case 1u:
        result = TdrBuf::ReadInt32(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 2u:
        result = TdrBuf::ReadInt32(v6, &a3);
        v8 = result;
        if ( !result )
        {
          *(_DWORD *)this = a3;
          goto LABEL_14;
        }
        break;
      case 4u:
        result = TdrBuf::ReadInt16(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      case 6u:
        result = TdrBuf::ReadInt64(v6, this);
        v8 = result;
        if ( !result )
          goto LABEL_14;
        break;
      default:
        result = TdrBuf::SkipField(v6, a3 & 0xF);
        v8 = result;
        if ( !result )
        {
LABEL_14:
          if ( v6[1] <= (unsigned int)(v10 + a4) )
          {
            *a2 = v9;
            result = v8;
          }
          else
          {
            result = -34;
          }
        }
        break;
    }
  }
  return result;
}



// ============================================================
// Name: Internal Helper Function
// Address Name: SUB_101AE7B0
// ============================================================
//----- (101AE7B0) --------------------------------------------------------
int __thiscall sub_101AE7B0(float *this, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int result; // eax

  result = 0;
  if ( a2 == 1 && !a3 )
    return print_field(a4, a5, a6, "[iInt]", "%d", *(_DWORD *)this);
  if ( a2 == 2 && !a3 )
    return print_field(a4, a5, a6, "[fFloat]", "%f", *this);
  if ( a2 == 4 && !a3 )
    return print_field(a4, a5, a6, "[nBool]", "%d", *(__int16 *)this);
  if ( a2 == 6 && !a3 )
    return print_field(a4, a5, a6, "[ullUint64]", "%I64u", *(_QWORD *)this);
  return result;
}



