using Rathalos.CLI.CodeGeneration.Services;
using Rathalos.CLI.Menu;
using Rathalos.CLI.Utils;

namespace Rathalos.CLI.Menu.Options
{
    /// <summary>
    /// Menu option handler for XML-based code generation
    /// </summary>
    public class XmlCodeGeneratorOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Wrench} XML Code Generator (T4 Templates)";

        private readonly XmlParsingService _xmlParsingService;
        private readonly CodeModelService _codeModelService;
        private readonly CodeGenerationService _codeGenerationService;

        public XmlCodeGeneratorOption()
        {
            _xmlParsingService = new XmlParsingService();
            _codeModelService = new CodeModelService();
            _codeGenerationService = new CodeGenerationService();
        }

        public async Task<bool> ExecuteAsync()
        {
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Wrench} XML Code Generator");
            Console.WriteLine("Generate C# classes, interfaces, and enums from XML metalib definitions");
            Console.WriteLine(new string('=', 70));
            Console.WriteLine();

            // Create sub-menu options
            var subMenuOptions = new List<IMenuOption>
            {
                new GenerateFromXmlFileSubOption(this),
                new ViewSampleXmlFormatSubOption(this),
                new ReturnToMainMenuSubOption()
            };

            // Create and run the sub-menu system
            var subMenuSystem = new ConsoleMenuSystem(subMenuOptions, "=== XML Code Generator ===");
            await subMenuSystem.RunAsync();

            return true; // Always return true to continue the main menu
        }

        internal async Task GenerateFromXmlFileAsync()
        {
            Console.Clear();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.File} Generate from XML File");
            Console.WriteLine(new string('=', 50));
            Console.WriteLine();

            Console.Write("Enter XML file path: ");
            var xmlFilePath = Console.ReadLine()?.Trim();

            if (string.IsNullOrWhiteSpace(xmlFilePath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Invalid file path.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the XML Generator menu...");
                Console.ReadKey(true);
                return;
            }

            if (!File.Exists(xmlFilePath))
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} File not found.");
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the XML Generator menu...");
                Console.ReadKey(true);
                return;
            }

            await ProcessXmlFileAsync(xmlFilePath);
        }

        private async Task ProcessXmlFileAsync(string xmlFilePath)
        {
            try
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Search} Validating XML file...");
                
                // Pre-validate and give helpful feedback
                if (!_xmlParsingService.ValidateXmlFile(xmlFilePath))
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} XML validation failed.");
                    Console.WriteLine("Attempting to diagnose the issue...");
                    
                    // Try to give specific feedback about the XML file
                    await DiagnoseXmlFile(xmlFilePath);
                    return;
                }

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} XML validation successful!");

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Book} Parsing XML file...");
                var metaLib = await _xmlParsingService.ParseXmlAsync(xmlFilePath);
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Parsed metalib '{metaLib.Name}' version {metaLib.Version}");

                // Get target namespace
                Console.Write($"\nEnter target namespace (e.g., 'Messages', will become 'Rathalos.Core.Protocol.Messages.{_codeModelService.CleanName(metaLib.Name)}'): ");
                var targetNamespace = Console.ReadLine()?.Trim();
                if (string.IsNullOrWhiteSpace(targetNamespace))
                {
                    targetNamespace = "Generated";
                }

                // Get output directory
                Console.Write($"Enter output directory (it will add a folder '{_codeModelService.CleanName(metaLib.Name)}' within the path entered): ");
                var outputDir = Console.ReadLine()?.Trim();
                if (string.IsNullOrWhiteSpace(outputDir))
                {
                    outputDir = Environment.CurrentDirectory;
                }

                outputDir = Path.Combine(outputDir, _codeModelService.CleanName(metaLib.Name));

                Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Cycle} Converting to code model...");
                var codeModel = _codeModelService.ConvertToCodeModel(metaLib, targetNamespace);

                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Code model created:");
                Console.WriteLine($"   - Constants: {codeModel.Constants.Count}");
                Console.WriteLine($"   - Enums: {codeModel.Enums.Count}");
                Console.WriteLine($"   - Interfaces: {codeModel.Interfaces.Count}");
                Console.WriteLine($"   - Classes: {codeModel.Classes.Count}");

                Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Wrench} Generating code files...");
                var generatedFiles = await _codeGenerationService.GenerateCodeFilesAsync(codeModel);

                Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Floppy} Saving generated files...");
                await _codeGenerationService.SaveGeneratedFilesAsync(generatedFiles.Classes, Path.Combine(outputDir, "Classes"));
                await _codeGenerationService.SaveGeneratedFilesAsync(generatedFiles.Enums, Path.Combine(outputDir, "Enums"));

                Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Party} Code generation completed!");
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Folder} Output directory: {outputDir}");
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Document} Generated {generatedFiles.Classes.Count + generatedFiles.Enums.Count} files:");

                foreach (var fileName in generatedFiles.Classes.Keys.Concat(generatedFiles.Enums.Keys))
                {
                    Console.WriteLine($"   - {fileName}");
                }
                
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the XML Generator menu...");
                Console.ReadKey(true);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Error during code generation:");
                
                if (ex.Message.Contains("encoding"))
                {
                    Console.WriteLine("🔧 ENCODING ISSUE DETECTED:");
                    Console.WriteLine("   The XML file has an encoding problem. Common fixes:");
                    Console.WriteLine("   1. Change 'encoding=\"UTF8\"' to 'encoding=\"UTF-8\"' (add hyphen)");
                    Console.WriteLine("   2. Save the file with UTF-8 encoding");
                    Console.WriteLine("   3. Remove special characters from the file path");
                    Console.WriteLine();
                    Console.Write("Would you like me to try fixing the XML file? (y/n): ");
                    var response = Console.ReadLine()?.Trim().ToLowerInvariant();
                    
                    if (response == "y" || response == "yes")
                    {
                        await TryFixXmlFile(xmlFilePath);
                        return;
                    }
                }
                else
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} Details: {ex.Message}");
                }
                
                Console.WriteLine();
                Console.WriteLine("Press any key to return to the XML Generator menu...");
                Console.ReadKey(true);
            }
        }

        private async Task DiagnoseXmlFile(string xmlFilePath)
        {
            try
            {
                var content = await File.ReadAllTextAsync(xmlFilePath);
                var firstLine = content.Split('\n').FirstOrDefault() ?? "";
                
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Search} Diagnosis:");
                Console.WriteLine($"   File size: {new FileInfo(xmlFilePath).Length} bytes");
                Console.WriteLine($"   First line: {firstLine.Trim()}");
                
                if (firstLine.Contains("UTF8") && !firstLine.Contains("UTF-8"))
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Lightbulb} ISSUE FOUND: encoding=\"UTF8\" should be encoding=\"UTF-8\"");
                    Console.Write("Would you like me to fix this automatically? (y/n): ");
                    var response = Console.ReadLine()?.Trim().ToLowerInvariant();
                    
                    if (response == "y" || response == "yes")
                    {
                        await TryFixXmlFile(xmlFilePath);
                    }
                }
                else if (!firstLine.StartsWith("<?xml"))
                {
                    Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} ISSUE: File doesn't start with proper XML declaration");
                    Console.WriteLine("   Expected: <?xml version=\"1.0\" encoding=\"UTF-8\"?>");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Could not diagnose file: {ex.Message}");
            }
        }

        private async Task TryFixXmlFile(string xmlFilePath)
        {
            try
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Wrench} Attempting to fix XML file...");
                
                var content = await File.ReadAllTextAsync(xmlFilePath);
                var fixedContent = content.Replace("encoding=\"UTF8\"", "encoding=\"UTF-8\"");
                
                // Create backup
                var backupPath = xmlFilePath + ".backup";
                await File.WriteAllTextAsync(backupPath, content);
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Backup created: {backupPath}");
                
                // Write fixed content
                await File.WriteAllTextAsync(xmlFilePath, fixedContent, System.Text.Encoding.UTF8);
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.CheckMark} Fixed encoding in XML file");
                
                // Try parsing again
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Cycle} Retrying parsing...");
                await ProcessXmlFileAsync(xmlFilePath);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{ConsoleDisplayHelper.Icons.Error} Failed to fix XML file: {ex.Message}");
            }
        }

        internal void DisplaySampleXmlFormat()
        {
            Console.WriteLine($"\n{ConsoleDisplayHelper.Icons.Book} Sample XML Format");
            Console.WriteLine(new string('-', 40));
            Console.WriteLine();
            Console.WriteLine("The XML metalib format supports the following elements:");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} <macro> - Defines constants");
            Console.WriteLine("   Attributes: name, value, desc");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} <macrosgroup> - Groups macros into enums");
            Console.WriteLine("   Contains multiple <macro> elements");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} <struct> - Defines classes/structures");
            Console.WriteLine("   Contains <entry> elements for properties");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} <union> - Defines interfaces");
            Console.WriteLine("   Contains <entry> elements for common properties");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Diamond} <entry> - Defines properties/fields");
            Console.WriteLine("   Attributes: name, type, count, desc, default, etc.");
            Console.WriteLine();
            Console.WriteLine($"{ConsoleDisplayHelper.Icons.Wrench} IMPORTANT ENCODING NOTES:");
            Console.WriteLine("   • Use 'UTF-8' NOT 'UTF8' in XML declaration");
            Console.WriteLine("   • Save file with UTF-8 encoding");
            Console.WriteLine("   • Avoid special characters in file paths");
            Console.WriteLine();
            Console.WriteLine("📝 Sample structure:");
            Console.WriteLine(@"<?xml version=""1.0"" encoding=""UTF-8""?>
<metalib name=""sample"" version=""1"">
  <macro name=""MAX_SIZE"" value=""256"" desc=""Maximum size""/>
  <macrosgroup name=""MessageType"">
    <macro name=""REQUEST"" value=""1"" desc=""Request message""/>
    <macro name=""RESPONSE"" value=""2"" desc=""Response message""/>
  </macrosgroup>
  <struct name=""SampleStruct"" desc=""Sample structure"">
    <entry name=""Id"" type=""int"" desc=""Identifier""/>
    <entry name=""Name"" type=""char"" count=""32"" desc=""Name field""/>
  </struct>
</metalib>");
        }
    }

    /// <summary>
    /// Sub-menu option for generating from XML file
    /// </summary>
    internal class GenerateFromXmlFileSubOption : IMenuOption
    {
        private readonly XmlCodeGeneratorOption _parent;

        public GenerateFromXmlFileSubOption(XmlCodeGeneratorOption parent)
        {
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.File} Generate from XML file";

        public async Task<bool> ExecuteAsync()
        {
            await _parent.GenerateFromXmlFileAsync();
            return true; // Continue sub-menu
        }
    }

    /// <summary>
    /// Sub-menu option for viewing sample XML format
    /// </summary>
    internal class ViewSampleXmlFormatSubOption : IMenuOption
    {
        private readonly XmlCodeGeneratorOption _parent;

        public ViewSampleXmlFormatSubOption(XmlCodeGeneratorOption parent)
        {
            _parent = parent;
        }

        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Book} View sample XML format";

        public async Task<bool> ExecuteAsync()
        {
            Console.Clear();
            _parent.DisplaySampleXmlFormat();
            
            Console.WriteLine();
            Console.WriteLine("Press any key to return to the XML Generator menu...");
            Console.ReadKey(true);
            
            return true; // Continue sub-menu
        }
    }

    /// <summary>
    /// Sub-menu option for returning to main menu
    /// </summary>
    internal class ReturnToMainMenuSubOption : IMenuOption
    {
        public string DisplayName => $"{ConsoleDisplayHelper.Icons.Back} Return to main menu";

        public async Task<bool> ExecuteAsync()
        {
            return false; // Exit sub-menu
        }
    }
}