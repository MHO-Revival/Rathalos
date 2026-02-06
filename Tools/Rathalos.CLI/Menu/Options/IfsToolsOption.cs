using Rathalos.CLI.IIPS;
using Rathalos.CLI.Utils;
using Rathalos.Core.Protocol.Tools;

namespace Rathalos.CLI.Menu.Options
{
    /// <summary>
    /// Menu option handler for IFS archive tools
    /// </summary>
    public class IfsToolsOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Folder} IFS Archive Tools";

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Folder} IFS Archive Tools");
            Console.WriteLine("Tools for working with IFS archive files");
            Console.WriteLine(new string('=', 70));
            Console.WriteLine();

            // Create sub-menu options
            var subMenuOptions = new List<IMenuOption>
            {
                new IfsExtractSubOption(this),
                new IfsViewerSubOption(this),
                new IfsReturnToMainMenuSubOption()
            };

            // Create and run the sub-menu system
            var subMenuSystem = new ConsoleMenuSystem(subMenuOptions, "=== IFS Archive Tools ===");
            await subMenuSystem.RunAsync();

            return true; // Always return true to continue the main menu
        }

        internal async Task ExtractArchiveAsync()
        {
            Console.Clear();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Folder} IFS Archive Extractor");
            Console.WriteLine(new string('=', 50));
            Console.WriteLine();

            Console.Write("Enter path to IFS archive file (or folder containing .ifs files): ");
            var inputPath = Console.ReadLine()?.Trim();

            if (string.IsNullOrWhiteSpace(inputPath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Invalid path.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the IFS Tools menu...");
                Console.ReadKey(true);
                return;
            }

            Console.Write("Enter output folder path: ");
            var outputPath = Console.ReadLine()?.Trim();

            if (string.IsNullOrWhiteSpace(outputPath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Invalid output path.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the IFS Tools menu...");
                Console.ReadKey(true);
                return;
            }

            await ExtractFilesAsync(inputPath, outputPath);

            Console.WriteLine();
            Console.WriteLine("Press any key to return to the IFS Tools menu...");
            Console.ReadKey(true);
        }

        private async Task ExtractFilesAsync(string inputPath, string outputPath)
        {
            try
            {
                var ifsFiles = new List<string>();

                if (Directory.Exists(inputPath))
                {
                    ifsFiles.AddRange(Directory.GetFiles(inputPath, "*.ifs", SearchOption.AllDirectories));

                    if (ifsFiles.Count == 0)
                    {
                        Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} No .ifs files found in the specified folder.");
                        return;
                    }

                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Search} Found {ifsFiles.Count} IFS archive(s).");
                }
                else if (File.Exists(inputPath))
                {
                    ifsFiles.Add(inputPath);
                }
                else
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Path not found: {inputPath}");
                    return;
                }

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Starting extraction...");
                Console.WriteLine();

                using var extractor = new IfsExtractor();

                int successCount = 0;
                int failCount = 0;

                foreach (var ifsFile in ifsFiles)
                {
                    try
                    {
                        var fileName = Path.GetFileNameWithoutExtension(ifsFile);
                        var archiveOutputPath = Path.Combine(outputPath, fileName);

                        Console.WriteLine($"{ConsoleDisplayHelper.Icons.File} Extracting: {Path.GetFileName(ifsFile)}");

                        await Task.Run(() => extractor.Extract(ifsFile, archiveOutputPath));

                        Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Extracted to: {archiveOutputPath}");
                        successCount++;
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to extract {Path.GetFileName(ifsFile)}: {ex.Message}");
                        failCount++;
                    }
                }

                Console.WriteLine();
                Console.WriteLine(new string('-', 40));
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Party} Extraction complete!");
                Console.WriteLine($"   Successful: {successCount}");
                if (failCount > 0)
                {
                    Console.WriteLine($"   Failed: {failCount}");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Extraction failed: {ex.Message}");
            }
        }

        internal async Task ViewArchiveAsync()
        {
            Console.Clear();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Search} IFS Archive Viewer");
            Console.WriteLine(new string('=', 50));
            Console.WriteLine();

            Console.Write("Enter path to IFS archive file: ");
            var inputPath = Console.ReadLine()?.Trim();

            if (string.IsNullOrWhiteSpace(inputPath) || !File.Exists(inputPath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} File not found.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the IFS Tools menu...");
                Console.ReadKey(true);
                return;
            }

            await ViewArchiveTreeAsync(inputPath);
        }

        private async Task ViewArchiveTreeAsync(string archivePath)
        {
            try
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Loading archive...");

                var fileList = await Task.Run(() => GetArchiveFileList(archivePath));

                if (fileList.Count == 0)
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} No files found in archive or failed to read listfile.");
                    Console.WriteLine();
                    Console.WriteLine("Press any key to return to the IFS Tools menu...");
                    Console.ReadKey(true);
                    return;
                }

                // Build tree structure
                var tree = BuildFileTree(fileList);

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Loaded {fileList.Count} files from archive.");
                Console.WriteLine();

                // Navigate the tree
                await NavigateTreeAsync(tree, archivePath);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to view archive: {ex.Message}");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the IFS Tools menu...");
                Console.ReadKey(true);
            }
        }

        private List<string> GetArchiveFileList(string archivePath)
        {
            var files = new List<string>();

            using var extractor = new IfsExtractor();
            var listData = extractor.GetFileList(archivePath);

            if (!string.IsNullOrEmpty(listData))
            {
                var fileNames = listData.Split(["\r\n", "\r", "\n"], StringSplitOptions.RemoveEmptyEntries);
                foreach (var fileName in fileNames)
                {
                    var cleanName = fileName.TrimEnd('\0', '\r', '\n');
                    if (!string.IsNullOrWhiteSpace(cleanName) && !cleanName.Contains("\\."))
                    {
                        files.Add(cleanName);
                    }
                }
            }

            return files;
        }

        private FileTreeNode BuildFileTree(List<string> files)
        {
            var root = new FileTreeNode { Name = "(root)", IsDirectory = true };

            // Normalize all paths and identify directories
            var normalizedPaths = files
                .Select(f => f.Replace('/', '\\').TrimEnd('\\'))
                .Where(f => !string.IsNullOrWhiteSpace(f))
                .ToHashSet(StringComparer.OrdinalIgnoreCase);

            // A path is a directory if another path starts with it + backslash
            var directories = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (var path in normalizedPaths)
            {
                // Check if any other path has this as a prefix
                var prefix = path + "\\";
                if (normalizedPaths.Any(p => p.StartsWith(prefix, StringComparison.OrdinalIgnoreCase)))
                {
                    directories.Add(path);
                }

                // Also add all parent directories
                var parts = path.Split('\\');
                for (int i = 1; i < parts.Length; i++)
                {
                    var parentPath = string.Join("\\", parts.Take(i));
                    directories.Add(parentPath);
                }
            }

            // Build the tree, skipping entries that are just directory listings
            foreach (var file in normalizedPaths)
            {
                // Skip if this is a directory-only entry (we'll create dirs from actual file paths)
                if (directories.Contains(file))
                    continue;

                var parts = file.Split('\\');
                var current = root;

                for (int i = 0; i < parts.Length; i++)
                {
                    var part = parts[i];
                    var isLast = i == parts.Length - 1;
                    var currentPath = string.Join("/", parts.Take(i + 1));

                    var existing = current.Children.FirstOrDefault(c => 
                        c.Name.Equals(part, StringComparison.OrdinalIgnoreCase));

                    if (existing == null)
                    {
                        existing = new FileTreeNode
                        {
                            Name = part,
                            IsDirectory = !isLast,
                            FullPath = currentPath
                        };
                        current.Children.Add(existing);
                    }
                    current = existing;
                }
            }

            // Sort children: directories first, then files, both alphabetically
            SortTree(root);
            return root;
        }

        private void SortTree(FileTreeNode node)
        {
            node.Children = [.. node.Children
                .OrderByDescending(c => c.IsDirectory)
                .ThenBy(c => c.Name)];

            foreach (var child in node.Children.Where(c => c.IsDirectory))
            {
                SortTree(child);
            }
        }

        private async Task NavigateTreeAsync(FileTreeNode root, string archivePath)
        {
            await ShowFolderMenuAsync(root, archivePath, Path.GetFileName(archivePath));
        }

        private async Task ShowFolderMenuAsync(FileTreeNode folder, string archivePath, string currentPath)
        {
            var menuOptions = new List<IMenuOption>();

            // Add children as menu options
            foreach (var child in folder.Children)
            {
                if (child.IsDirectory)
                {
                    menuOptions.Add(new FolderMenuOption(child, archivePath, this));
                }
                else
                {
                    menuOptions.Add(new FileMenuOption(child, archivePath));
                }
            }

            // Add back option
            menuOptions.Add(new TreeBackMenuOption());

            var menuSystem = new ConsoleMenuSystem(menuOptions, $"=== {currentPath} ===");
            await menuSystem.RunAsync();
        }

        internal async Task ShowChildFolderAsync(FileTreeNode folder, string archivePath)
        {
            var path = $"{Path.GetFileName(archivePath)}/{folder.FullPath}";
            await ShowFolderMenuAsync(folder, archivePath, path);
        }
    }

    /// <summary>
    /// Menu option for a folder in the tree
    /// </summary>
    internal class FolderMenuOption : IMenuOption
    {
        private readonly FileTreeNode _folder;
        private readonly string _archivePath;
        private readonly IfsToolsOption _parent;

        public FolderMenuOption(FileTreeNode folder, string archivePath, IfsToolsOption parent)
        {
            _folder = folder;
            _archivePath = archivePath;
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Folder} {_folder.Name} ({_folder.GetTotalFileCount()} files)";

        public async Task<bool> ExecuteAsync()
        {
            await _parent.ShowChildFolderAsync(_folder, _archivePath);
            return true;
        }
    }

    /// <summary>
    /// Menu option for a file in the tree
    /// </summary>
    internal class FileMenuOption : IMenuOption
    {
        private readonly FileTreeNode _file;
        private readonly string _archivePath;

        public FileMenuOption(FileTreeNode file, string archivePath)
        {
            _file = file;
            _archivePath = archivePath;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Document} {_file.Name}";

        public async Task<bool> ExecuteAsync()
        {
            Console.Clear();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Document} File Details");
            Console.WriteLine(new string('=', 50));
            Console.WriteLine();
            Console.WriteLine($"   Name: {_file.Name}");
            Console.WriteLine($"   Path: {_file.FullPath}");
            Console.WriteLine();

            // Check file extension and display appropriate content
            if (_file.Name.EndsWith(".dat", StringComparison.OrdinalIgnoreCase))
            {
                await DisplayDatFileContentAsync();
            }
            else if (_file.Name.EndsWith(".xml", StringComparison.OrdinalIgnoreCase))
            {
                await DisplayXmlFileContentAsync();
            }

            Console.WriteLine();
            Console.WriteLine("Press any key to continue...");
            Console.ReadKey(true);

            return true;
        }

        private async Task<byte[]?> ReadFileFromArchiveAsync()
        {
            return await Task.Run(() =>
            {
                using var extractor = new IfsExtractor();
                return extractor.ReadFile(_archivePath, _file.FullPath);
            });
        }

        private async Task DisplayDatFileContentAsync()
        {
            try
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Reading DAT file content...");
                Console.WriteLine();

                byte[]? fileContent = await ReadFileFromArchiveAsync();

                if (fileContent == null || fileContent.Length == 0)
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to read file from archive.");
                    return;
                }

                // Parse the DAT file
                var datReader = DatReader.Create(fileContent);

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} DAT file decrypted successfully!");
                Console.WriteLine($"   Size: {fileContent.Length} bytes");
                Console.WriteLine();
                Console.WriteLine(new string('-', 50));
                Console.WriteLine("Content:");
                Console.WriteLine(new string('-', 50));
                Console.WriteLine();

                // Display content
                Console.WriteLine(datReader.Content);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to parse DAT file: {ex.Message}");
            }
        }

        private async Task DisplayXmlFileContentAsync()
        {
            try
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Reading XML file content...");
                Console.WriteLine();

                byte[]? fileContent = await ReadFileFromArchiveAsync();

                if (fileContent == null || fileContent.Length == 0)
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to read file from archive.");
                    return;
                }

                string xmlContent;

                // Check if this is an encrypted CryXml file (magic: 0x686DFFFF
                var magicHeader = BitConverter.ToInt32(fileContent.AsSpan()[..4]);
                if (magicHeader == CryXmlReader.Magic)
                {
                    // Encrypted CryXml format
                    var cryXmlReader = CryXmlReader.Create(fileContent);
                    xmlContent = cryXmlReader.Content;

                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} CryXML file decrypted successfully!");
                }
                else
                {
                    // Plain XML file
                    xmlContent = System.Text.Encoding.UTF8.GetString(fileContent);

                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} XML file loaded successfully!");
                }

                Console.WriteLine($"   Size: {fileContent.Length} bytes");
                Console.WriteLine();
                Console.WriteLine(new string('-', 50));
                Console.WriteLine("Content:");
                Console.WriteLine(new string('-', 50));
                Console.WriteLine();

                // Display content
                Console.WriteLine(xmlContent);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to parse XML file: {ex.Message}");
            }
        }
    }

    /// <summary>
    /// Menu option to go back in tree navigation
    /// </summary>
    internal class TreeBackMenuOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Go back";

        public Task<bool> ExecuteAsync()
        {
            return Task.FromResult(false);
        }
    }

    /// <summary>
    /// Tree node for file structure navigation
    /// </summary>
    internal class FileTreeNode
    {
        public string Name { get; set; } = string.Empty;
        public string FullPath { get; set; } = string.Empty;
        public bool IsDirectory { get; set; }
        public List<FileTreeNode> Children { get; set; } = [];

        public int GetTotalFileCount()
        {
            if (!IsDirectory) return 1;
            return Children.Sum(c => c.GetTotalFileCount());
        }
    }

    /// <summary>
    /// Sub-menu option for extracting IFS archives
    /// </summary>
    internal class IfsExtractSubOption : IMenuOption
    {
        private readonly IfsToolsOption _parent;

        public IfsExtractSubOption(IfsToolsOption parent)
        {
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Folder} Extract archive(s)";

        public async Task<bool> ExecuteAsync()
        {
            await _parent.ExtractArchiveAsync();
            return true;
        }
    }

    /// <summary>
    /// Sub-menu option for viewing IFS archive contents
    /// </summary>
    internal class IfsViewerSubOption : IMenuOption
    {
        private readonly IfsToolsOption _parent;

        public IfsViewerSubOption(IfsToolsOption parent)
        {
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Search} View archive contents (Tree)";

        public async Task<bool> ExecuteAsync()
        {
            await _parent.ViewArchiveAsync();
            return true;
        }
    }

    /// <summary>
    /// Sub-menu option for returning to main menu
    /// </summary>
    internal class IfsReturnToMainMenuSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Return to main menu";

        public Task<bool> ExecuteAsync()
        {
            return Task.FromResult(false);
        }
    }
}
