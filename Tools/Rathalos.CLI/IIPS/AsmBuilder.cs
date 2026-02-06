using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace Rathalos.CLI.IIPS;

public enum Reg : byte
{
    EAX = 0, ECX = 1, EDX = 2, EBX = 3,
    ESP = 4, EBP = 5, ESI = 6, EDI = 7
}

public enum Op : byte
{
    // Single Byte Instructions
    PushAd = 0x60, PopAd = 0x61,
    Ret = 0xC3, Nop = 0x90,
    PushEax = 0x50, // Base for Push Reg (0x50 + Reg)
    PopEax = 0x58,  // Base for Pop Reg (0x58 + Reg)

    // Multi-byte Instruction Bases
    MovImm = 0xB8,  // Base for Mov Reg, Imm32 (0xB8 + Reg)
    MovReg = 0x8B,  // Mov Reg, Reg
    AddImm = 0x81,  // Add Reg, Imm32
    AddEax = 0x05,  // Add EAX, Imm32 (Special Case)
    XorReg = 0x31,
    CallNear = 0xFF,
    PushImm32 = 0x68,
    PushImm8 = 0x6A
}

public class AsmBuilder : IDisposable
{
    private readonly List<byte> _code = new List<byte>();
    private IntPtr _execPtr = IntPtr.Zero;

    [DllImport("kernel32.dll")]
    static extern bool VirtualProtect(IntPtr lpAddress, uint dwSize, uint flNewProtect, out uint lpflOldProtect);

    // --- Movement ---
    public AsmBuilder Mov(Reg reg, int imm)
    {
        _code.Add((byte)((byte)Op.MovImm + (byte)reg));
        _code.AddRange(BitConverter.GetBytes(imm));
        return this;
    }

    public AsmBuilder Mov(Reg dst, Reg src)
    {
        _code.Add((byte)Op.MovReg);
        _code.Add(MakeModRM(3, (byte)dst, (byte)src));
        return this;
    }

    // --- Stack ---
    public AsmBuilder Push(int imm)
    {
        _code.Add((byte)Op.PushImm32);
        _code.AddRange(BitConverter.GetBytes(imm));
        return this;
    }

    public AsmBuilder Push(Reg reg)
    {
        _code.Add((byte)((byte)Op.PushEax + (byte)reg));
        return this;
    }

    public AsmBuilder Pop(Reg reg)
    {
        _code.Add((byte)((byte)Op.PopEax + (byte)reg));
        return this;
    }

    // --- Arithmetic ---
    public AsmBuilder Add(Reg dst, int imm)
    {
        if (dst == Reg.EAX)
        {
            _code.Add((byte)Op.AddEax);
        }
        else
        {
            _code.Add((byte)Op.AddImm);
            _code.Add(MakeModRM(3, 0, (byte)dst));
        }
        _code.AddRange(BitConverter.GetBytes(imm));
        return this;
    }

    public AsmBuilder Xor(Reg dst, Reg src)
    {
        _code.Add((byte)Op.XorReg);
        _code.Add(MakeModRM(3, (byte)src, (byte)dst));
        return this;
    }

    // --- Control ---
    public AsmBuilder Call(Reg reg)
    {
        _code.Add((byte)Op.CallNear);
        _code.Add((byte)(0xD0 + (byte)reg)); // 0xD0 is the ModR/M for CALL Reg
        return this;
    }

    public AsmBuilder Emit(Op op)
    {
        _code.Add((byte)op);
        return this;
    }

    // --- ModR/M Generation ---
    // This defines how the CPU interprets the relationship between registers
    private byte MakeModRM(byte mod, byte reg, byte rm) => (byte)((mod << 6) | (reg << 3) | rm);



    // --- Execution ---
    private delegate IntPtr AsmDelegate();

    public IntPtr Run()
    {
        _execPtr = Marshal.AllocHGlobal(_code.Count);
        Marshal.Copy(_code.ToArray(), 0, _execPtr, _code.Count);
        VirtualProtect(_execPtr, (uint)_code.Count, 0x40, out _);

        var del = Marshal.GetDelegateForFunctionPointer<AsmDelegate>(_execPtr);
        return del();
    }

    public void Dispose()
    {
        if (_execPtr != IntPtr.Zero) Marshal.FreeHGlobal(_execPtr);
    }
}