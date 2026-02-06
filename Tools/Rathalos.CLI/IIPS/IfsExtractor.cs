using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace Rathalos.CLI.IIPS;

public class IfsExtractor : IDisposable
{
    private IntPtr _hModule;
    private readonly string _dllPath;

    // Offsets from the original C++ script
    private const int OFF_OPEN_ARC = 0x16370;
    private const int OFF_OPEN_FILE = 0x1FA20;
    private const int OFF_READ_FILE = 0x220C0;
    private const int OFF_CLOSE_FILE = 0x20BF0;

    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Ansi)]
    private static extern IntPtr LoadLibrary(string lpLibFileName);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern bool FreeLibrary(IntPtr hModule);

    public IfsExtractor(string dllPath = "libs\\IFS2.dll")
    {
        _dllPath = dllPath;
        _hModule = LoadLibrary(dllPath);
        if (_hModule == IntPtr.Zero)
            throw new FileNotFoundException($"Could not load {_dllPath}. Ensure it's in the bin folder and you are running as x86.");
    }

    public void Extract(string archiveName, string targetDir, Action<int, int, string> onProgress = null)
    {
        Console.WriteLine($"[+] Opening Archive: {archiveName}");

        IntPtr hArchive = Call_OpenArchive(archiveName);
        if (hArchive == IntPtr.Zero) return;

        if (Call_OpenFile(hArchive, "(listfile)", out IntPtr hListFile))
        {
            byte[] buffer = new byte[1024 * 1024 * 64];
            uint readLen = Call_ReadFile(hListFile, buffer);
            Call_CloseFile(hListFile);

            string listData = Encoding.ASCII.GetString(buffer, 0, (int)readLen);
            string[] files = listData.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries);

            if (!Directory.Exists(targetDir)) Directory.CreateDirectory(targetDir);

            for (int i = 0; i < files.Length; i++)
            {
                string cleanFile = files[i].TrimEnd('\0');
                if (string.IsNullOrEmpty(cleanFile) || cleanFile.Contains("\\.")) continue;

                // Trigger the progress update
                onProgress?.Invoke(i + 1, files.Length, cleanFile);

                ExtractFile(hArchive, cleanFile, targetDir, buffer);
            }
        }
    }

    private void ExtractFile(IntPtr hArchive, string fileName, string targetDir, byte[] buffer)
    {
        if (Call_OpenFile(hArchive, fileName, out IntPtr hFile))
        {
            uint size = Call_ReadFile(hFile, buffer);
            Call_CloseFile(hFile);

            string outPath = Path.Combine(targetDir, fileName);
            string dir = Path.GetDirectoryName(outPath);
            if (!Directory.Exists(dir)) Directory.CreateDirectory(dir);

            File.WriteAllBytes(outPath, buffer[..(int)size]);
            Console.WriteLine($"[-] Extracted: {fileName} ({size} bytes)");
        }
    }

    public string GetFileList(string archiveName)
    {
        // 1. Open Archive
        IntPtr hArchive = Call_OpenArchive(archiveName);
        if (hArchive == IntPtr.Zero)
            return string.Empty;

        // 2. Open (listfile)
        if (Call_OpenFile(hArchive, "(listfile)", out IntPtr hListFile))
        {
            byte[] buffer = new byte[1024 * 1024 * 64]; // 64MB Buffer
            uint readLen = Call_ReadFile(hListFile, buffer);
            Call_CloseFile(hListFile);

            return Encoding.ASCII.GetString(buffer, 0, (int)readLen);
        }

        return string.Empty;
    }

    /// <summary>
    /// Reads a single file's content from the archive
    /// </summary>
    /// <param name="archiveName">Path to the IFS archive</param>
    /// <param name="fileName">File path within the archive</param>
    /// <returns>File content as byte array, or null if not found</returns>
    public byte[] ReadFile(string archiveName, string fileName)
    {
        IntPtr hArchive = Call_OpenArchive(archiveName);
        if (hArchive == IntPtr.Zero)
            return null;

        // Normalize the file path (use backslashes like in the archive)
        string normalizedFileName = fileName.Replace('/', '\\');

        if (Call_OpenFile(hArchive, normalizedFileName, out IntPtr hFile))
        {
            byte[] buffer = new byte[1024 * 1024 * 64]; // 64MB Buffer
            uint readLen = Call_ReadFile(hFile, buffer);
            Call_CloseFile(hFile);

            // Return only the bytes that were read
            byte[] result = new byte[readLen];
            Array.Copy(buffer, result, readLen);
            return result;
        }

        return null;
    }

    #region ASM Bridge Calls

    private IntPtr Call_OpenArchive(string path)
    {
        IntPtr pPath = Marshal.StringToHGlobalAnsi(path);
        try
        {
            using var asm = new AsmBuilder();
            return asm.Push(0)                 // Flags
                      .Push(pPath.ToInt32())   // pName
                      .Mov(Reg.EAX, _hModule.ToInt32() + OFF_OPEN_ARC)
                      .Call(Reg.EAX)
                      .Emit(Op.Ret)
                      .Run();
        }
        finally { Marshal.FreeHGlobal(pPath); }
    }

    private bool Call_OpenFile(IntPtr hArchive, string fileName, out IntPtr hFile)
    {
        IntPtr pName = Marshal.StringToHGlobalAnsi(fileName);
        IntPtr pOutHandle = Marshal.AllocHGlobal(4);
        try
        {
            using var asm = new AsmBuilder();
            asm.Push(0)                        // Unk
               .Push(pOutHandle.ToInt32())     // out *file
               .Push(1)                        // Flags
               .Push(pName.ToInt32())          // filename
               .Push(hArchive.ToInt32())       // archive
               .Mov(Reg.EAX, _hModule.ToInt32() + OFF_OPEN_FILE)
               .Call(Reg.EAX)
               .Emit(Op.Ret)
               .Run();

            hFile = (IntPtr)Marshal.ReadInt32(pOutHandle);
            return hFile != IntPtr.Zero;
        }
        finally
        {
            Marshal.FreeHGlobal(pName);
            Marshal.FreeHGlobal(pOutHandle);
        }
    }

    private uint Call_ReadFile(IntPtr hFile, byte[] buffer)
    {
        GCHandle pin = GCHandle.Alloc(buffer, GCHandleType.Pinned);
        IntPtr pReadLen = Marshal.AllocHGlobal(4);
        try
        {
            using var asm = new AsmBuilder();
            // C++: push 1; lea eax, [read_length]; push eax; mov ecx, size; push ecx; mov edx, buf; mov ecx, file;
            asm.Push(1)
               .Push(pReadLen.ToInt32())
               .Push(buffer.Length)
               .Mov(Reg.EDX, pin.AddrOfPinnedObject().ToInt32())
               .Mov(Reg.ECX, hFile.ToInt32())
               .Mov(Reg.EAX, _hModule.ToInt32() + OFF_READ_FILE)
               .Call(Reg.EAX)
               .Emit(Op.Ret)
               .Run();

            return (uint)Marshal.ReadInt32(pReadLen);
        }
        finally
        {
            pin.Free();
            Marshal.FreeHGlobal(pReadLen);
        }
    }

    private void Call_CloseFile(IntPtr hFile)
    {
        using var asm = new AsmBuilder();
        // C++: __asm mov esi, file; call ifsCloseFile
        asm.Mov(Reg.ESI, hFile.ToInt32())
           .Mov(Reg.EAX, _hModule.ToInt32() + OFF_CLOSE_FILE)
           .Call(Reg.EAX)
           .Emit(Op.Ret)
           .Run();
    }
    #endregion

    public void Dispose()
    {
        if (_hModule != IntPtr.Zero) FreeLibrary(_hModule);
    }
}