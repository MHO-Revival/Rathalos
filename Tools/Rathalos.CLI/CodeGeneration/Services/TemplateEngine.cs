using System.Text;
using Rathalos.CLI.CodeGeneration.Models;
using Rathalos.CLI.CodeGeneration.Templates;

namespace Rathalos.CLI.CodeGeneration.Services
{
    /// <summary>
    /// T4 template engine for generating code using actual T4 templates
    /// </summary>
    public class TemplateEngine
    {
        public string ProcessClassTemplate(GeneratedClass classModel, GeneratedCodeModel? codeModel = null)
        {
            try
            {
                var template = new ClassTemplate()
                {
                    Model = classModel,
                    CodeModel = codeModel
                };
                return template.TransformText();
            }
            catch (Exception ex)
            {
                // Fallback to manual generation if T4 fails
                Console.WriteLine($"T4 template failed, using fallback: {ex.Message}");
                throw;
            }
        }

        public string ProcessEnumTemplate(GeneratedEnum enumModel)
        {
            try
            {
                var template = new EnumTemplate()
                {
                    Model = enumModel,
                };
                return template.TransformText();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"T4 template failed, using fallback: {ex.Message}");
                throw;
            }
        }

        public string ProcessInterfaceTemplate(GeneratedInterface interfaceModel)
        {
            try
            {
                var template = new InterfaceTemplate()
                {
                    Model = interfaceModel,
                };
                return template.TransformText();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"T4 template failed, using fallback: {ex.Message}");
                throw;
            }
        }

        public string ProcessConstantsTemplate(Dictionary<string, string> constants, string targetNamespace, string metalibName)
        {
            try
            {
                var template = new ConstantsTemplate()
                {
                    Constants = constants,
                    TargetNamespace = targetNamespace,
                    MetalibName = metalibName
                };
                return template.TransformText();
            }
            catch (Exception ex)
            {
                Console.WriteLine($"T4 template failed, using fallback: {ex.Message}");
                throw;
            }
        }
    }
}