using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;
using System.Xml.Linq;
using Rathalos.Core.Protocol.Tools;

namespace Rathalos.CLI.IIPS;

public class IfsExtractor : IDisposable
{
    private IntPtr _hModule;
    private readonly string _dllPath;

    static IfsExtractor()
    {
        // Register the code pages provider for CJK encoding support in .NET Core/.NET 5+
        Encoding.RegisterProvider(CodePagesEncodingProvider.Instance);
    }

    // Offsets from the original C++ script
    private const int OFF_OPEN_ARC = 0x16370;
    private const int OFF_OPEN_FILE = 0x1FA20;
    private const int OFF_READ_FILE = 0x220C0;
    private const int OFF_CLOSE_FILE = 0x20BF0;
    private const int OFF_ADD_FILE = 0x4A60;
    private const int OFF_CREATE_ARC = 0xFCC0;
    private const int OFF_FLUSH_ARC = 0x17DF0;

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

    public void Extract(string archiveName, string targetDir, Action<int, int, string>? onProgress = null)
    {
        Console.WriteLine("Opening Archive ..");

        IntPtr hArchive = Call_OpenArchive(archiveName);
        if (hArchive == IntPtr.Zero)
        {
            Console.WriteLine("[!] Failed to open archive.");
            return;
        }

        try
        {
            if (Call_OpenFile(hArchive, "(listfile)", out IntPtr hListFile))
            {
                byte[] buffer = new byte[1024 * 1024 * 64];
                uint readLen = Call_ReadFile(hListFile, buffer);
                Call_CloseFile(hListFile);

                Console.WriteLine("Parse list_file ..");

                // Use GBK encoding for Chinese character support
                string listData = Encoding.UTF8.GetString(buffer, 0, (int)readLen);
                string[] files = listData.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.RemoveEmptyEntries);

                if (!Directory.Exists(targetDir)) Directory.CreateDirectory(targetDir);

                // Build a set of directories to skip (entries that are prefixes of other entries)
                var normalizedPaths = files
                    //.Select(f => f.TrimEnd('\0').Replace('/', '\\').TrimEnd('\\'))
                    .Where(f => !string.IsNullOrWhiteSpace(f))
                    .ToList();

                var directories = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                foreach (var path in normalizedPaths)
                {
                    var prefix = path + "\\";
                    if (normalizedPaths.Any(p => p.StartsWith(path, StringComparison.OrdinalIgnoreCase) && !p.Equals(path, StringComparison.OrdinalIgnoreCase)))
                    {
                        directories.Add(path);
                    }
                }

                // Filter to only actual files (not directory entries)
                var actualFiles = normalizedPaths.Where(f => !directories.Contains(f)).ToList();

                for (int i = 0; i < actualFiles.Count; i++)
                {
                    string cleanFile = actualFiles[i];

                    // Trigger the progress update
                    onProgress?.Invoke(i + 1, actualFiles.Count, cleanFile);

                    try
                    {
                        ExtractFile(hArchive, cleanFile, targetDir, buffer);
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"[!] Error extracting {cleanFile}: {ex.Message}");
                    }
                }
            }
            else
            {
                Console.WriteLine("[!] Failed to open listfile.");
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error 0 ({ex.Message})");
        }
    }

    private void ExtractFile(IntPtr hArchive, string fileName, string targetDir, byte[] buffer)
    {
        if (!Call_OpenFile(hArchive, fileName, out IntPtr hFile))
        {
            Console.WriteLine($"[!] Could not open file: {fileName}");
            return;
        }

        try
        {
            uint size = Call_ReadFile(hFile, buffer);
            Call_CloseFile(hFile);

            if (size == 0)
            {
                Console.WriteLine($"[!] Empty file or read error: {fileName}");
                return;
            }

            // Check for buffer overflow like in C++
            if (size > buffer.Length)
            {
                Console.WriteLine($"warning: need to read more! file too long (atm)!");
            }

            byte[] fileContent = buffer[..(int)size];
            string outPath = Path.Combine(targetDir, fileName);
            string dir = Path.GetDirectoryName(outPath);
            if (!Directory.Exists(dir)) Directory.CreateDirectory(dir);

            // Try to decrypt and determine the real file type
            var (processedContent, newExtension) = ProcessFileContent(fileName, fileContent);

            // Update the output path with the new extension if needed
            if (!string.IsNullOrEmpty(newExtension))
            {
                string currentExtension = Path.GetExtension(outPath);
                if (!currentExtension.Equals(newExtension, StringComparison.OrdinalIgnoreCase))
                {
                    outPath = Path.ChangeExtension(outPath, newExtension);
                }
            }

            File.WriteAllBytes(outPath, processedContent);
            // Match C++ output format: file (filename): size: N
            Console.WriteLine($"file ({fileName}): size: {processedContent.Length}");
        }
        catch (Exception ex)
        {
            // Ensure file is closed even on error
            try { Call_CloseFile(hFile); } catch { }
            throw new Exception($"Failed to read/process file: {ex.Message}", ex);
        }
    }

    /// <summary>
    /// Processes file content, decrypting if necessary and determining the correct extension
    /// </summary>
    private (byte[] content, string? newExtension) ProcessFileContent(string fileName, byte[] rawContent)
    {
        string extension = Path.GetExtension(fileName).ToLowerInvariant();

        try
        {
            // Handle .dat files
            if (extension == ".dat")
            {
                return ProcessDatFile(rawContent);
            }

            // Handle .xml files (might be encrypted CryXml)
            if (extension == ".xml")
            {
                return ProcessXmlFile(rawContent);
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"[!] Warning: Could not process {fileName}: {ex.Message}. Saving raw content.");
        }

        // Return original content for other file types
        return (rawContent, null);
    }

    /// <summary>
    /// Processes a .dat file, decrypts it and determines the correct extension
    /// </summary>
    private (byte[] content, string? newExtension) ProcessDatFile(byte[] rawContent)
    {
        // Decrypt the DAT file
        var datReader = DatReader.Create(rawContent);
        string decryptedContent = datReader.Content;
        byte[] contentBytes = Encoding.UTF8.GetBytes(decryptedContent);

        // Determine the correct extension based on content
        string trimmedContent = decryptedContent.TrimStart();

        if (trimmedContent.StartsWith("#TSV", StringComparison.OrdinalIgnoreCase))
        {
            return (contentBytes, ".tsv");
        }

        // Try to parse as XML
        if (TryParseAsXml(trimmedContent))
        {
            return (contentBytes, ".xml");
        }

        if (trimmedContent.StartsWith("{") || trimmedContent.StartsWith("["))
        {
            // Likely JSON
            return (contentBytes, ".json");
        }

        // Keep as .dat but with decrypted content
        return (contentBytes, ".dat");
    }

    /// <summary>
    /// Processes an .xml file, decrypts if it's CryXml format
    /// </summary>
    private (byte[] content, string? newExtension) ProcessXmlFile(byte[] rawContent)
    {
        // Check if this is an encrypted CryXml file
        if (rawContent.Length >= 4 && BitConverter.ToUInt32(rawContent, 0) == CryXmlReader.Magic)
        {
            // Encrypted CryXml format - decrypt it
            var cryXmlReader = CryXmlReader.Create(rawContent);
            byte[] decryptedContent = Encoding.UTF8.GetBytes(cryXmlReader.Content);
            return (decryptedContent, ".xml");
        }

        // Plain XML file, return as-is
        return (rawContent, null);
    }

    /// <summary>
    /// Attempts to parse content as XML using XDocument
    /// </summary>
    private bool TryParseAsXml(string content)
    {
        if (string.IsNullOrWhiteSpace(content))
            return false;

        // Quick check: XML should start with < (after trimming)
        if (!content.TrimStart().StartsWith("<"))
            return false;

        try
        {
            XDocument.Parse(content);
            return true;
        }
        catch
        {
            return false;
        }
    }

    public string GetFileList(string archiveName)
    {
        // 1. Open Archive
        IntPtr hArchive = Call_OpenArchive(archiveName);
        if (hArchive == IntPtr.Zero)
            return string.Empty;

        // 2. Open (listfile) with flags=0 as per C++ code
        if (Call_OpenFile(hArchive, "(listfile)", out IntPtr hListFile))
        {
            byte[] buffer = new byte[1024 * 1024 * 64]; // 64MB Buffer
            uint readLen = Call_ReadFile(hListFile, buffer);
            Call_CloseFile(hListFile);

            // Use GBK encoding for Chinese character support
            return Encoding.UTF8.GetString(buffer, 0, (int)readLen);
        }

        return string.Empty;
    }

    /// <summary>
    /// Reads a single file's content from the archive
    /// </summary>
    /// <param name="archiveName">Path to the IFS archive</param>
    /// <param name="fileName">File path within the archive</param>
    /// <returns>File content as byte array, or null if not found</returns>
    public byte[]? ReadFile(string archiveName, string fileName)
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

    /// <summary>
    /// Creates a new IFS archive from a folder
    /// </summary>
    /// <param name="archivePath">Path where the archive will be created</param>
    /// <param name="sourceFolder">Folder containing files to add to the archive</param>
    /// <param name="maxFileCount">Maximum number of files the archive can hold (default: 256)</param>
    /// <param name="onProgress">Optional progress callback (current, total, filename)</param>
    /// <returns>True if successful, false otherwise</returns>
    public bool CreateArchive(string archivePath, string sourceFolder, uint maxFileCount = 256, Action<int, int, string>? onProgress = null)
    {
        if (!Directory.Exists(sourceFolder))
        {
            Console.WriteLine($"[!] Source folder not found: {sourceFolder}");
            return false;
        }

        try
        {
            // Remove existing archive if it exists (like C++)
            if (File.Exists(archivePath))
            {
                File.Delete(archivePath);
                Console.WriteLine($"Removed existing archive: {archivePath}");
            }

            // Create the archive with flags 0x1000000 as per C++
            Console.WriteLine($"Creating archive: {archivePath}");
            Call_CreateArchive(archivePath, 0x1000000, maxFileCount, out IntPtr hArchive);

            if (hArchive == IntPtr.Zero)
            {
                Console.WriteLine("[!] Failed to create archive.");
                return false;
            }

            // Get all files from the source folder recursively
            var files = Directory.GetFiles(sourceFolder, "*", SearchOption.AllDirectories);
            int totalFiles = files.Length;
            int currentFile = 0;

            foreach (var filePath in files)
            {
                currentFile++;

                // Get the relative path (destination path inside the archive)
                string relativePath = Path.GetRelativePath(sourceFolder, filePath);

                // Normalize path separators to backslashes
                relativePath = relativePath.Replace('/', '\\');

                // Trigger progress update
                onProgress?.Invoke(currentFile, totalFiles, relativePath);

                // Add file to archive
                Call_AddFile(hArchive, filePath, relativePath);
                Console.WriteLine($"{relativePath} patched!");
            }

            // Flush/close the archive
            Call_FlushArchive(hArchive);
            Console.WriteLine($"Archive created successfully with {totalFiles} files.");

            return true;
        }
        catch (Exception ex)
        {
            Console.WriteLine($"[!] Error creating archive: {ex.Message}");
            return false;
        }
    }

    /// <summary>
    /// Creates a patch archive from a "patch" folder (convenience method matching C++ createPatch)
    /// </summary>
    /// <param name="patchArchiveName">Name of the patch archive to create (default: "patch.ifs")</param>
    /// <param name="patchFolder">Folder containing patch files (default: "patch")</param>
    /// <returns>True if successful, false otherwise</returns>
    public bool CreatePatch(string patchArchiveName = "patch.ifs", string patchFolder = "patch")
    {
        return CreateArchive(patchArchiveName, patchFolder);
    }

    #region ASM Bridge Calls

    /// <summary>
    /// Allocates a native string using the appropriate encoding for MHO (GBK for Chinese support)
    /// </summary>
    private IntPtr StringToNativeAnsi(string str)
    {
        byte[] bytes = Encoding.UTF8.GetBytes(str + '\0'); // Null-terminated
        IntPtr ptr = Marshal.AllocHGlobal(bytes.Length);
        Marshal.Copy(bytes, 0, ptr, bytes.Length);
        return ptr;
    }

    private IntPtr Call_OpenArchive(string path)
    {
        IntPtr pPath = StringToNativeAnsi(path);
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
        IntPtr pName = StringToNativeAnsi(fileName);
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
        // Validate file handle
        if (hFile == IntPtr.Zero)
        {
            Console.WriteLine("[!] Invalid file handle in Call_ReadFile");
            return 0;
        }

        GCHandle pin = GCHandle.Alloc(buffer, GCHandleType.Pinned);
        IntPtr pReadLen = Marshal.AllocHGlobal(4);
        try
        {
            using var asm = new AsmBuilder();
            // C++ assembly pattern:
            // push 1
            // lea eax, [read_length]
            // push eax
            // mov ecx, buf_size
            // push ecx
            // mov edx, buf
            // mov ecx, file
            // call ifsReadFile
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

    private void Call_CreateArchive(string archivePath, uint flags, uint maxFileCount, out IntPtr hArchive)
    {
        IntPtr pPath = StringToNativeAnsi(archivePath);
        IntPtr pOutHandle = Marshal.AllocHGlobal(4);
        try
        {
            using var asm = new AsmBuilder();
            // C++: mov eax, flags; push eax; mov ebx, max_file_count; push ebx; mov ecx, pName; mov edx, archive; call ifsCreateArchive
            asm.Mov(Reg.EAX, (int)flags)
               .Push(Reg.EAX)
               .Mov(Reg.EBX, (int)maxFileCount)
               .Push(Reg.EBX)
               .Mov(Reg.ECX, pPath.ToInt32())
               .Mov(Reg.EDX, pOutHandle.ToInt32())
               .Mov(Reg.EAX, _hModule.ToInt32() + OFF_CREATE_ARC)
               .Call(Reg.EAX)
               .Emit(Op.Ret)
               .Run();

            hArchive = (IntPtr)Marshal.ReadInt32(pOutHandle);
        }
        finally
        {
            Marshal.FreeHGlobal(pPath);
            Marshal.FreeHGlobal(pOutHandle);
        }
    }

    private void Call_AddFile(IntPtr hArchive, string sourceFilePath, string storeAsName)
    {
        IntPtr pSource = StringToNativeAnsi(sourceFilePath);
        IntPtr pStoreName = StringToNativeAnsi(storeAsName);
        try
        {
            using var asm = new AsmBuilder();
            // C++: mov eax, archive; push eax; mov edx, filename; mov ecx, storename; mov esi, archive; call ifsAddFile
            asm.Mov(Reg.EAX, hArchive.ToInt32())
               .Push(Reg.EAX)
               .Mov(Reg.EDX, pSource.ToInt32())
               .Mov(Reg.ECX, pStoreName.ToInt32())
               .Mov(Reg.ESI, hArchive.ToInt32())
               .Mov(Reg.EAX, _hModule.ToInt32() + OFF_ADD_FILE)
               .Call(Reg.EAX)
               .Emit(Op.Ret)
               .Run();
        }
        finally
        {
            Marshal.FreeHGlobal(pSource);
            Marshal.FreeHGlobal(pStoreName);
        }
    }

    private void Call_FlushArchive(IntPtr hArchive)
    {
        using var asm = new AsmBuilder();
        // C++: __asm mov esi, archive; call ifsFlushArchive
        asm.Mov(Reg.ESI, hArchive.ToInt32())
           .Mov(Reg.EAX, _hModule.ToInt32() + OFF_FLUSH_ARC)
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
