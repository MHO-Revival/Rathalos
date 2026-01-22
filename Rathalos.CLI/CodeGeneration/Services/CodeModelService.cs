using Rathalos.CLI.CodeGeneration.Models;

namespace Rathalos.CLI.CodeGeneration.Services
{
    /// <summary>
    /// Service for converting XML metalib definitions to code generation models
    /// </summary>
    public class CodeModelService
    {
        private readonly Dictionary<string, string> _typeMapping = new()
        {
            { "tinyint", "sbyte" },
            { "tinyuint", "byte" },
            { "short", "short" },
            { "ushort", "ushort" },
            { "int", "int" },
            { "uint", "uint" },
            { "char", "char" }
        };

        public GeneratedCodeModel ConvertToCodeModel(MetaLib metaLib, string targetNamespace)
        {
            var codeModel = new GeneratedCodeModel
            {
                TargetNamespace = targetNamespace
            };

            // Convert constants (macros)
            ConvertConstants(metaLib, codeModel);

            // Convert enums (macros groups)
            ConvertEnums(metaLib, codeModel);

            // Convert interfaces (unions)
            ConvertInterfaces(metaLib, codeModel);

            // Convert classes (structs)
            ConvertClasses(metaLib, codeModel);

            return codeModel;
        }

        private void ConvertConstants(MetaLib metaLib, GeneratedCodeModel codeModel)
        {
            foreach (var macro in metaLib.Macros)
            {
                codeModel.Constants[macro.Name] = macro.Value;
            }
        }

        private void ConvertEnums(MetaLib metaLib, GeneratedCodeModel codeModel)
        {
            foreach (var macroGroup in metaLib.MacrosGroups)
            {
                var generatedEnum = new GeneratedEnum
                {
                    Name = CleanName(macroGroup.Name),
                    Description = macroGroup.Description,
                    Namespace = codeModel.TargetNamespace,
                    UnderlyingType = "int"
                };

                foreach (var macro in macroGroup.Macros)
                {
                    generatedEnum.Values.Add(new GeneratedEnumValue
                    {
                        Name = CleanName(macro.Name),
                        Value = macro.Value,
                        Description = macro.Description
                    });
                }

                codeModel.Enums.Add(generatedEnum);
            }
        }

        private void ConvertInterfaces(MetaLib metaLib, GeneratedCodeModel codeModel)
        {
            foreach (var union in metaLib.Unions)
            {
                var generatedInterface = new GeneratedInterface
                {
                    Name = CleanName(union.Name),
                    Description = union.Description,
                    Namespace = codeModel.TargetNamespace,
                    UsingStatements = { "System" }
                };

                // Track which classes should implement this interface
                foreach (var entry in union.Entries)
                {
                    if (!string.IsNullOrWhiteSpace(entry.Type))
                    {
                        generatedInterface.ImplementingClasses.Add(CleanName(entry.Type));
                    }
                }

                codeModel.Interfaces.Add(generatedInterface);
            }
        }

        private void ConvertClasses(MetaLib metaLib, GeneratedCodeModel codeModel)
        {
            foreach (var structDef in metaLib.Structs)
            {
                var generatedClass = new GeneratedClass
                {
                    Name = CleanName(structDef.Name),
                    Description = structDef.Description,
                    Namespace = codeModel.TargetNamespace,
                    UsingStatements = { "System", "System.Collections.Generic" },
                    IsStruct = false // Generate as classes for better OOP support
                };

                foreach (var entry in structDef.Entries)
                {
                    var property = ConvertEntryToProperty(entry, metaLib);
                    generatedClass.Properties.Add(property);
                }

                // Check if this class should implement an interface (based on unions)
                // and add ProtocolId const field
                foreach (var union in metaLib.Unions)
                {
                    foreach (var unionEntry in union.Entries)
                    {
                        if (unionEntry.Type == structDef.Name)
                        {
                            var interfaceName = CleanName(union.Name);
                            generatedClass.Interfaces.Add(interfaceName);

                            // Add ProtocolId const field using the enum value from id attribute
                            if (!string.IsNullOrWhiteSpace(unionEntry.Id))
                            {
                                // Find the corresponding enum value
                                var enumName = FindEnumForId(unionEntry.Id, metaLib);
                                var protocolIdValue = enumName != null ? $"{enumName}.{CleanName(unionEntry.Id)}" : unionEntry.Id;

                                generatedClass.Properties.Insert(0, new GeneratedProperty
                                {
                                    Name = "ProtocolId",
                                    Type = "ushort",
                                    Description = "Protocol identifier for this message type",
                                    DefaultValue = $"(ushort){protocolIdValue}",
                                    IsProtocolId = true
                                });
                            }
                        }
                    }
                }

                codeModel.Classes.Add(generatedClass);
            }
        }

        private string? FindEnumForId(string idValue, MetaLib metaLib)
        {
            foreach (var macroGroup in metaLib.MacrosGroups)
            {
                if (macroGroup.Macros.Any(m => m.Name == idValue))
                {
                    return CleanName(macroGroup.Name);
                }
            }
            return null;
        }

        private GeneratedProperty ConvertEntryToProperty(Entry entry, MetaLib metaLib)
        {
            var property = new GeneratedProperty
            {
                Name = CleanName(entry.Name),
                Description = entry.Description + (string.IsNullOrWhiteSpace(entry.Version) ? string.Empty : $" (version:{entry.Version})"),
                DefaultValue = GetDefaultValue(entry),
                IsArray = IsArrayProperty(entry),
                Type = GetFinalType(entry, metaLib),
                RealType = GetRealType(entry, metaLib),
                ArraySize = entry.Count
            };

            return property;
        }

        private bool IsArrayProperty(Entry entry)
        {
            // An entry is an array if:
            // 1. It has a count attribute set, OR
            // 2. It has a refer attribute that points to a length property in another class
            return !string.IsNullOrWhiteSpace(entry.Count) || !string.IsNullOrWhiteSpace(entry.Refer);
        }

        private bool IsCustomType(string typeName, MetaLib metaLib)
        {
            return metaLib.Structs.Any(s => s.Name == typeName) ||
                   metaLib.Unions.Any(u => u.Name == typeName);
        }

        private string? GetDefaultValue(Entry entry)
        {
            if (!string.IsNullOrWhiteSpace(entry.Default))
            {
                return entry.Default;
            }

            if (IsArrayProperty(entry))
            {
                // It's an array, so default to empty array
                return null; // Will be handled in template
            }

            return null;
        }

        public string GetFinalType(Entry entry, MetaLib metaLib)
        {
            if (!string.IsNullOrWhiteSpace(entry.BindMacrosGroup))
                return entry.BindMacrosGroup;
            else
                return GetRealType(entry, metaLib);
        }

        public string GetRealType(Entry entry, MetaLib metaLib)
        {
            if (_typeMapping.ContainsKey(entry.Type))
            {
                return _typeMapping[entry.Type];
            }
            else if (IsCustomType(entry.Type, metaLib))
            {
                return CleanName(entry.Type);
            }
            else
            {
                return "object"; // Fallback for unknown types
            }
        }

        public string GetSubsidiaryType(Entry entry)
        {
            return string.Empty;
        }

        private string CleanName(string name)
        {
            // Remove special characters and ensure valid C# identifier
            var cleaned = name.Replace("-", "_");

            // Ensure first character is uppercase for Pascal case
            if (cleaned.Length > 0 && char.IsLower(cleaned[0]))
            {
                cleaned = char.ToUpper(cleaned[0]) + cleaned[1..];
            }

            return cleaned;
        }
    }
}