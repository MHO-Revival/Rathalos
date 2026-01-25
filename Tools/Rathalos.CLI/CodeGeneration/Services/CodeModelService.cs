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
            // Signed integer types
            { "tinyint", "byte" },
            { "int8", "byte" },
            { "smallint", "short" },
            { "int16", "short" },
            { "int32", "int" },
            { "bigint", "long" },
            { "int64", "long" },
            
            // Unsigned integer types
            { "tinyuint", "byte" },
            { "uint8", "byte" },
            { "uchar", "byte" },
            { "ushort", "ushort" },
            { "uint16", "ushort" },
            { "uint", "uint" },
            { "uint32", "uint" },
            { "biguint", "ulong" },
            { "ulong", "ulong" },
            { "uint64", "ulong" },
            { "ulonglong", "ulong" },
        };

        public GeneratedCodeModel ConvertToCodeModel(MetaLib metaLib, string targetNamespace)
        {
            var codeModel = new GeneratedCodeModel
            {
                TargetNamespace = $"Rathalos.Core.Protocol.{targetNamespace}.{CleanName(metaLib.Name)}",
                TargetName = CleanName(metaLib.Name),
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
                    UsingStatements = { "System", "Rathalos.Core.Utils.IO" }
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
                var interfaces = metaLib.Unions
                    .SelectMany(x => x.Entries.Select(y => (Entry:y, Union:x)))
                    .Where(x => x.Entry.Type == structDef.Name)
                    .Distinct();

                if (interfaces.Count() > 0)
                {
                    foreach (var @interface in interfaces)
                    {
                        GeneratedClass generatedClass = CreateClassModel(metaLib, codeModel, structDef, @interface, interfaces.Count() > 1, interfaces.Count(x => x.Union.Name == @interface.Union.Name) > 1);

                        var interfaceName = CleanName(@interface.Union.Name);
                        generatedClass.Interfaces.Add(interfaceName);

                        // Add ProtocolId const field using the enum value from id attribute
                        if (!string.IsNullOrWhiteSpace(@interface.Entry.Id))
                        {
                            if (generatedClass.Properties.All(p => !p.IsProtocolId))
                            {
                                // Find the corresponding enum value
                                var enumName = FindEnumForId(@interface.Entry.Id, metaLib);
                                var protocolIdValue = enumName != null ? $"{enumName}.{CleanName(@interface.Entry.Id)}" : @interface.Entry.Id;

                                generatedClass.Properties.Insert(0, new GeneratedProperty
                                {
                                    Name = "ProtocolId",
                                    Type = enumName,
                                    Description = "Protocol identifier for this message type",
                                    DefaultValue = $"{protocolIdValue}",
                                    IsProtocolId = true
                                });
                            }
                        }

                        codeModel.Classes.Add(generatedClass);
                    }

                    if(interfaces.Count() > 1 && metaLib.Structs.SelectMany(x => x.Entries).Any(x => x.Type == structDef.Name))
                    {
                        // Also generate a base class without interface suffix
                        var baseClass = CreateClassModel(metaLib, codeModel, structDef);
                        codeModel.Classes.Add(baseClass);
                    }
                }
                else
                {
                    var generatedClass = CreateClassModel(metaLib, codeModel, structDef);
                    codeModel.Classes.Add(generatedClass);
                }
            }

            var notMappedUnionEntries = metaLib.Unions
                    .SelectMany(x => x.Entries.Select(y => (Entry: y, Union: x)))
                    .Where(x => metaLib.Structs.All(y => y.Name != x.Entry.Type))
                    .Distinct();

            foreach(var entry in notMappedUnionEntries)
            {
                var generatedClass = new GeneratedClass
                {
                    Name = CleanName(entry.Entry.Name + entry.Union.Name),
                    Description = entry.Entry.Description,
                    Namespace = codeModel.TargetNamespace,
                    UsingStatements = { "System", "System.Collections.Generic", "Rathalos.Core.Utils.IO" },
                    IsStruct = false, // Generate as classes for better OOP support
                    Interfaces = [CleanName(entry.Union.Name)]
                };
                var property = ConvertEntryToProperty(entry.Entry, metaLib);
                property.Name = "Value";

                generatedClass.Properties.Add(property);

                codeModel.Classes.Add(generatedClass);
            }

        }

        private GeneratedClass CreateClassModel(MetaLib metaLib, GeneratedCodeModel codeModel, Struct structDef, (Entry Entry, Union Union)? @interface = null, bool hasMultipleInterfaces = false, bool hasMultipleSameInterface = false)
        {
            var generatedClass = new GeneratedClass
            {
                Name = CleanName(structDef.Name),
                Description = structDef.Description,
                Namespace = codeModel.TargetNamespace,
                UsingStatements = { "System", "System.Collections.Generic", "Rathalos.Core.Utils.IO" },
                IsStruct = false, // Generate as classes for better OOP support
            };

            if (@interface is not null && @interface?.Entry.Name is not null)
            {
                if (hasMultipleInterfaces && hasMultipleSameInterface)
                {
                    generatedClass.Name = CleanName(@interface?.Union.Name!) + CleanName(@interface?.Entry.Name!);
                }
                else if(hasMultipleInterfaces)
                {
                    generatedClass.Name += CleanName(@interface?.Union.Name!);
                }
            }

            foreach (var entry in structDef.Entries)
            {
                if (entry.Name == generatedClass.Name)
                {
                    // Avoid property name clash with class name
                    entry.Name += "Value";
                }
                var property = ConvertEntryToProperty(entry, metaLib);
                generatedClass.Properties.Add(property);
            }

            return generatedClass;
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
                Type = GetFinalType(entry.Type, entry.BindMacrosGroup, metaLib),
                RealType = GetRealType(entry.Type, metaLib),
                ArraySize = entry.Count,
                StringMaxSize = entry.Size,
                Select = string.IsNullOrWhiteSpace(entry.Select) ? null : CleanName(entry.Select),
                Refer = string.IsNullOrWhiteSpace(entry.Refer) ? null : CleanName(entry.Refer)
            };

            if(entry.Name.ToLowerInvariant() == "bool")
            {
                property.Type = "bool";
            }

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

        public string GetFinalType(string type, string bindMacrosGroup, MetaLib metaLib)
        {
            if (!string.IsNullOrWhiteSpace(bindMacrosGroup))
                return bindMacrosGroup;
            else
                return GetRealType(type, metaLib);
        }

        public string GetRealType(string type, MetaLib metaLib)
        {
            if (_typeMapping.ContainsKey(type))
            {
                return _typeMapping[type];
            }
            else if (IsCustomType(type, metaLib))
            {
                return CleanName(type);
            }
            else
            {
                return type; // Fallback for unknown types
            }
        }

        public string GetSubsidiaryType(Entry entry)
        {
            return string.Empty;
        }

        public string CleanName(string name)
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