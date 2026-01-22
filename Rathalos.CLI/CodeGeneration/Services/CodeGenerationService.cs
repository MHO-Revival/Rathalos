using Rathalos.CLI.CodeGeneration.Models;

namespace Rathalos.CLI.CodeGeneration.Services
{
    /// <summary>
    /// Service for generating C# code from templates and models
    /// </summary>
    public class CodeGenerationService
    {
        private readonly TemplateEngine _templateEngine;

        public CodeGenerationService()
        {
            _templateEngine = new TemplateEngine();
        }

        public async Task<(Dictionary<string, string>Classes, Dictionary<string, string> Enums)> GenerateCodeFilesAsync(GeneratedCodeModel codeModel)
        {
            var generatedFiles = new Dictionary<string, string>();
            var generatedEnumFiles = new Dictionary<string, string>();

            // Generate constants file using template
            if (codeModel.Constants.Any())
            {
                var constantsCode = _templateEngine.ProcessConstantsTemplate(codeModel.Constants, codeModel.TargetNamespace);
                generatedFiles["MetaLibConstants.cs"] = constantsCode;
            }

            // Generate enum files using template
            foreach (var enumModel in codeModel.Enums)
            {
                var enumCode = _templateEngine.ProcessEnumTemplate(enumModel);
                generatedEnumFiles[$"{enumModel.Name}.cs"] = enumCode;
            }

            // Generate interface files using template
            foreach (var interfaceModel in codeModel.Interfaces)
            {
                var interfaceCode = _templateEngine.ProcessInterfaceTemplate(interfaceModel);
                generatedFiles[$"{interfaceModel.Name}.cs"] = interfaceCode;
            }

            // Generate class files using template
            foreach (var classModel in codeModel.Classes)
            {
                var classCode = _templateEngine.ProcessClassTemplate(classModel);
                generatedFiles[$"{classModel.Name}.cs"] = classCode;
            }

            return (generatedFiles, generatedEnumFiles);
        }

        public async Task SaveGeneratedFilesAsync(Dictionary<string, string> generatedFiles, string outputDirectory)
        {
            if (!Directory.Exists(outputDirectory))
            {
                Directory.CreateDirectory(outputDirectory);
            }

            foreach (var file in generatedFiles)
            {
                var filePath = Path.Combine(outputDirectory, file.Key);
                await File.WriteAllTextAsync(filePath, file.Value);
            }
        }
    }
}