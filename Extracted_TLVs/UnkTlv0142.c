// ============================================================
// Name: TLV::UnkTlv0142::Read_0xAA
// Address Name: SUB_1017EC70
// ============================================================
//----- (1017EC70) --------------------------------------------------------
int __thiscall sub_1017EC70(int *this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int VarInt; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(this + 12) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_43:
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
          if ( (*(_BYTE *)(this + 12) & 1) == 0 )
            *(this + 12) |= 1u;
          VarInt = TdrBuf::ReadVarInt(a2, this);
          break;
        case 2u:
          if ( (*(this + 12) & 2) == 0 )
            *(this + 12) |= 2u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 1);
          break;
        case 3u:
          if ( (*(this + 12) & 4) == 0 )
            *(this + 12) |= 4u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 2);
          break;
        case 4u:
          if ( (*(this + 12) & 8) == 0 )
            *(this + 12) |= 8u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 3);
          break;
        case 5u:
          if ( (*(this + 12) & 0x10) == 0 )
            *(this + 12) |= 0x10u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 4);
          break;
        case 6u:
          if ( (*(this + 12) & 0x20) == 0 )
            *(this + 12) |= 0x20u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 5);
          break;
        case 7u:
          if ( (*(this + 12) & 0x40) == 0 )
            *(this + 12) |= 0x40u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 6);
          break;
        case 8u:
          if ( (*(this + 12) & 0x80) == 0 )
            *(this + 12) |= 0x80u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 7);
          break;
        case 9u:
          if ( (*(this + 12) & 0x100) == 0 )
            *(this + 12) |= 0x100u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 8);
          break;
        case 0xAu:
          if ( (*(this + 12) & 0x200) == 0 )
            *(this + 12) |= 0x200u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 9);
          break;
        case 0xBu:
          if ( (*(this + 12) & 0x400) == 0 )
            *(this + 12) |= 0x400u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 10);
          break;
        case 0xCu:
          if ( (*(this + 12) & 0x800) == 0 )
            *(this + 12) |= 0x800u;
          VarInt = TdrBuf::ReadVarInt(a2, this + 11);
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
        goto LABEL_43;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0142::Read_0x99
// Address Name: SUB_1017EEC0
// ============================================================
//----- (1017EEC0) --------------------------------------------------------
int __thiscall sub_1017EEC0(int this, _DWORD *a2, int a3)
{
  int v5; // esi
  unsigned int v6; // eax
  int result; // eax
  int Int32; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF
  unsigned int v10; // [esp+18h] [ebp+8h]

  v5 = 0;
  v9 = 0;
  *(_DWORD *)(this + 48) = 0;
  v6 = a2[1] + a3;
  v10 = v6;
  if ( a2[1] >= v6 )
  {
LABEL_43:
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
          if ( (*(_BYTE *)(this + 48) & 1) == 0 )
            *(_DWORD *)(this + 48) |= 1u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)this);
          break;
        case 2u:
          if ( (*(_DWORD *)(this + 48) & 2) == 0 )
            *(_DWORD *)(this + 48) |= 2u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 4));
          break;
        case 3u:
          if ( (*(_DWORD *)(this + 48) & 4) == 0 )
            *(_DWORD *)(this + 48) |= 4u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 8));
          break;
        case 4u:
          if ( (*(_DWORD *)(this + 48) & 8) == 0 )
            *(_DWORD *)(this + 48) |= 8u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 12));
          break;
        case 5u:
          if ( (*(_DWORD *)(this + 48) & 0x10) == 0 )
            *(_DWORD *)(this + 48) |= 0x10u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 16));
          break;
        case 6u:
          if ( (*(_DWORD *)(this + 48) & 0x20) == 0 )
            *(_DWORD *)(this + 48) |= 0x20u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 20));
          break;
        case 7u:
          if ( (*(_DWORD *)(this + 48) & 0x40) == 0 )
            *(_DWORD *)(this + 48) |= 0x40u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 24));
          break;
        case 8u:
          if ( (*(_DWORD *)(this + 48) & 0x80) == 0 )
            *(_DWORD *)(this + 48) |= 0x80u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 28));
          break;
        case 9u:
          if ( (*(_DWORD *)(this + 48) & 0x100) == 0 )
            *(_DWORD *)(this + 48) |= 0x100u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 32));
          break;
        case 0xAu:
          if ( (*(_DWORD *)(this + 48) & 0x200) == 0 )
            *(_DWORD *)(this + 48) |= 0x200u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 36));
          break;
        case 0xBu:
          if ( (*(_DWORD *)(this + 48) & 0x400) == 0 )
            *(_DWORD *)(this + 48) |= 0x400u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 40));
          break;
        case 0xCu:
          if ( (*(_DWORD *)(this + 48) & 0x800) == 0 )
            *(_DWORD *)(this + 48) |= 0x800u;
          Int32 = TdrBuf::ReadInt32(a2, (_BYTE *)(this + 44));
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
        goto LABEL_43;
    }
  }
  return result;
}



// ============================================================
// Name: TLV::UnkTlv0142::DoDebugFormat
// Address Name: SUB_1017F130
// ============================================================
//----- (1017F130) --------------------------------------------------------
int __thiscall sub_1017F130(_DWORD *this, signed __int32 a2, int a3, _DWORD *a4, int a5, char a6)
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
  v7 = sub_1017F1E0(this, &v8, a5, a6);
  if ( a4 )
    *a4 = v9;
  if ( v11 )
    sub_10C3DA30(v8);
  return v7;
}



// ============================================================
// Name: TLV::UnkTlv0142::DebugFormat
// Address Name: SUB_1017F1E0
// ============================================================
//----- (1017F1E0) --------------------------------------------------------
int __thiscall sub_1017F1E0(_DWORD *this, _DWORD *a2, int a3, char a4)
{
  int result; // eax

  result = print_field(a2, a3, a4, "[iCurSeason]", "%d", *this);
  if ( !result )
  {
    result = print_field(a2, a3, a4, "[iScore]", "%d", *(this + 1));
    if ( !result )
    {
      result = print_field(a2, a3, a4, "[iScoreTop]", "%d", *(this + 2));
      if ( !result )
      {
        result = print_field(a2, a3, a4, "[iWeekReward]", "%d", *(this + 3));
        if ( !result )
        {
          result = print_field(a2, a3, a4, "[iStreak]", "%d", *(this + 4));
          if ( !result )
          {
            result = print_field(a2, a3, a4, "[iWinNum]", "%d", *(this + 5));
            if ( !result )
            {
              result = print_field(a2, a3, a4, "[iLoseNum]", "%d", *(this + 6));
              if ( !result )
              {
                result = print_field(a2, a3, a4, "[iTotalNum]", "%d", *(this + 7));
                if ( !result )
                {
                  result = print_field(a2, a3, a4, "[iRewardMask]", "%d", *(this + 8));
                  if ( !result )
                  {
                    result = print_field(a2, a3, a4, "[iExRewardCount]", "%d", *(this + 9));
                    if ( !result )
                    {
                      result = print_field(a2, a3, a4, "[iStepReward]", "%d", *(this + 10));
                      if ( !result )
                        return print_field(a2, a3, a4, "[iExMedalCount]", "%d", *(this + 11));
                    }
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



