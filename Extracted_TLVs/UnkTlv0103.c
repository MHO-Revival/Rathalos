// ============================================================
// Name: TLV::UnkTlv0103::Read_0xAA
// Address Name: SUB_10165440
// ============================================================
//----- (10165440) --------------------------------------------------------
int __thiscall sub_10165440(_DWORD *this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int VarUInt; // eax
  unsigned int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h] BYREF
  unsigned int v16; // [esp+24h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(this + 11) = 0;
  v7 = v4[1] + v3;
  v10 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_47:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( !result )
      {
        switch ( v16 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 11) & 1) == 0 )
              *(this + 11) |= 1u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this);
            goto LABEL_45;
          case 2u:
            if ( (*(this + 11) & 2) == 0 )
              *(this + 11) |= 2u;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            *(this + 1) = a2;
            goto LABEL_46;
          case 3u:
            if ( (*(this + 11) & 4) == 0 )
              *(this + 11) |= 4u;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            *(this + 2) = a3;
            goto LABEL_46;
          case 4u:
            if ( (*(this + 11) & 8) == 0 )
              *(this + 11) |= 8u;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            *(this + 3) = v15;
            goto LABEL_46;
          case 5u:
            if ( (*(this + 11) & 0x10) == 0 )
              *(this + 11) |= 0x10u;
            v6 = TdrBuf::ReadInt32(v4, &v14);
            if ( v6 )
              return v6;
            *(this + 4) = v14;
            goto LABEL_46;
          case 6u:
            if ( (*(this + 11) & 0x20) == 0 )
              *(this + 11) |= 0x20u;
            v6 = TdrBuf::ReadInt32(v4, &v13);
            if ( v6 )
              return v6;
            *(this + 5) = v13;
            goto LABEL_46;
          case 7u:
            if ( (*(this + 11) & 0x40) == 0 )
              *(this + 11) |= 0x40u;
            v6 = TdrBuf::ReadInt32(v4, &v12);
            if ( v6 )
              return v6;
            *(this + 6) = v12;
            goto LABEL_46;
          case 8u:
            if ( (*(this + 11) & 0x80) == 0 )
              *(this + 11) |= 0x80u;
            v6 = TdrBuf::ReadInt32(v4, &v11);
            if ( v6 )
              return v6;
            *(this + 7) = v11;
            goto LABEL_46;
          case 9u:
            if ( (*(this + 11) & 0x100) == 0 )
              *(this + 11) |= 0x100u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this + 8);
            goto LABEL_45;
          case 0xAu:
            if ( (*(this + 11) & 0x200) == 0 )
              *(this + 11) |= 0x200u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this + 9);
            goto LABEL_45;
          case 0xBu:
            if ( (*(this + 11) & 0x400) == 0 )
              *(this + 11) |= 0x400u;
            VarUInt = TdrBuf::ReadVarUInt(v4, this + 10);
            goto LABEL_45;
          default:
            VarUInt = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_45:
            v6 = VarUInt;
            if ( VarUInt )
              return v6;
LABEL_46:
            v7 = v10;
            if ( v4[1] >= v10 )
              goto LABEL_47;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0103::Read_0x99
// Address Name: SUB_101656F0
// ============================================================
//----- (101656F0) --------------------------------------------------------
int __thiscall sub_101656F0(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebx
  int v6; // esi
  unsigned int v7; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h] BYREF
  int v13; // [esp+18h] [ebp-10h] BYREF
  int v14; // [esp+1Ch] [ebp-Ch] BYREF
  int v15; // [esp+20h] [ebp-8h] BYREF
  unsigned int v16; // [esp+24h] [ebp-4h] BYREF

  v3 = a3;
  v4 = a2;
  v6 = 0;
  v16 = 0;
  *(_DWORD *)(this + 44) = 0;
  v7 = v4[1] + v3;
  v10 = v7;
  if ( v4[1] >= v7 )
  {
LABEL_47:
    if ( v4[1] > v7 )
      return -34;
    return v6;
  }
  else
  {
    while ( 2 )
    {
      result = TdrBuf::ReadVarUInt(v4, &v16);
      if ( !result )
      {
        switch ( v16 >> 4 )
        {
          case 1u:
            if ( (*(_BYTE *)(this + 44) & 1) == 0 )
              *(_DWORD *)(this + 44) |= 1u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)this);
            goto LABEL_45;
          case 2u:
            if ( (*(_DWORD *)(this + 44) & 2) == 0 )
              *(_DWORD *)(this + 44) |= 2u;
            v6 = TdrBuf::ReadInt32(v4, &a2);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 4) = a2;
            goto LABEL_46;
          case 3u:
            if ( (*(_DWORD *)(this + 44) & 4) == 0 )
              *(_DWORD *)(this + 44) |= 4u;
            v6 = TdrBuf::ReadInt32(v4, &a3);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 8) = a3;
            goto LABEL_46;
          case 4u:
            if ( (*(_DWORD *)(this + 44) & 8) == 0 )
              *(_DWORD *)(this + 44) |= 8u;
            v6 = TdrBuf::ReadInt32(v4, &v15);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 12) = v15;
            goto LABEL_46;
          case 5u:
            if ( (*(_DWORD *)(this + 44) & 0x10) == 0 )
              *(_DWORD *)(this + 44) |= 0x10u;
            v6 = TdrBuf::ReadInt32(v4, &v14);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 16) = v14;
            goto LABEL_46;
          case 6u:
            if ( (*(_DWORD *)(this + 44) & 0x20) == 0 )
              *(_DWORD *)(this + 44) |= 0x20u;
            v6 = TdrBuf::ReadInt32(v4, &v13);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 20) = v13;
            goto LABEL_46;
          case 7u:
            if ( (*(_DWORD *)(this + 44) & 0x40) == 0 )
              *(_DWORD *)(this + 44) |= 0x40u;
            v6 = TdrBuf::ReadInt32(v4, &v12);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 24) = v12;
            goto LABEL_46;
          case 8u:
            if ( (*(_DWORD *)(this + 44) & 0x80) == 0 )
              *(_DWORD *)(this + 44) |= 0x80u;
            v6 = TdrBuf::ReadInt32(v4, &v11);
            if ( v6 )
              return v6;
            *(_DWORD *)(this + 28) = v11;
            goto LABEL_46;
          case 9u:
            if ( (*(_DWORD *)(this + 44) & 0x100) == 0 )
              *(_DWORD *)(this + 44) |= 0x100u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 32));
            goto LABEL_45;
          case 0xAu:
            if ( (*(_DWORD *)(this + 44) & 0x200) == 0 )
              *(_DWORD *)(this + 44) |= 0x200u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 36));
            goto LABEL_45;
          case 0xBu:
            if ( (*(_DWORD *)(this + 44) & 0x400) == 0 )
              *(_DWORD *)(this + 44) |= 0x400u;
            Int32 = TdrBuf::ReadInt32(v4, (_BYTE *)(this + 40));
            goto LABEL_45;
          default:
            Int32 = TdrBuf::SkipField(v4, v16 & 0xF);
LABEL_45:
            v6 = Int32;
            if ( Int32 )
              return v6;
LABEL_46:
            v7 = v10;
            if ( v4[1] >= v10 )
              goto LABEL_47;
            continue;
        }
      }
      break;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0103::DoDebugFormat
// Address Name: SUB_101659C0
// ============================================================
//----- (101659C0) --------------------------------------------------------
int __thiscall sub_101659C0(float *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_10165A70(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0103::DebugFormat
// Address Name: SUB_10165A70
// ============================================================
//----- (10165A70) --------------------------------------------------------
int __thiscall sub_10165A70(float *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[curLevelID]", "%u", *(_DWORD *)this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[vx]", "%f", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[vy]", "%f", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[vz]", "%f", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[tx]", "%f", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[ty]", "%f", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[tz]", "%f", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[tw]", "%f", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[hubID]", "%u", *((_DWORD *)this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[npcID]", "%u", *((_DWORD *)this + 9));
                    if ( !result )
                      return print_field(a2, a3, a4, "[preLevelID]", "%u", *((_DWORD *)this + 10));
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



