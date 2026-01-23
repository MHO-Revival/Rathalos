using Rathalos.CLI.CodeGeneration.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Rathalos.CLI.CodeGeneration.Templates
{
    public partial class ClassTemplate
    {
        public GeneratedClass Model { get; set; }

        /// <summary>
        /// The full code model containing all classes, enums, and constants for reference resolution
        /// </summary>
        public GeneratedCodeModel? CodeModel { get; set; }

        /// <summary>
        /// Generates property code with XML documentation, attributes, and proper syntax
        /// </summary>
        /// <param name="property">The property to generate code for</param>
        /// <returns>Generated property code as string</returns>
        public string GeneratePropertyCode(GeneratedProperty property)
        {
            var sb = new StringBuilder();

            if (property.IsProtocolId)
            {
                sb.AppendLine($"\t\tpublic const {property.Type} {property.Name}Const = {property.DefaultValue};");
            }

            // Generate XML documentation if description exists
            if (!string.IsNullOrWhiteSpace(property.Description))
            {
                sb.AppendLine("\t\t/// <summary>");
                sb.AppendLine($"\t\t/// {property.Description}");
                sb.AppendLine("\t\t/// </summary>");
            }

            // Generate attributes
            foreach (var attribute in property.Attributes)
            {
                sb.AppendLine($"\t\t{attribute}");
            }

            // Generate property declaration
            if (property.IsProtocolId)
            {
                // Protocol ID properties get a const and a property that returns the const
                sb.Append($"\t\tpublic ushort {property.Name} => (ushort){property.Name}Const;");
            }
            else
            {
                // Regular property with getter/setter
                sb.Append($"\t\tpublic {property.Type}{(property.IsArray ? "[]" : "")} {property.Name} {{ get; set; }}");

                // Handle default value or array initialization
                if (!string.IsNullOrWhiteSpace(property.DefaultValue))
                {
                    sb.Append($" = {property.DefaultValue};");
                }
                else if (property.IsArray)
                {
                    sb.Append($" = Array.Empty<{property.Type}>();");
                }
                else
                {
                    // No initialization needed for regular properties without default values
                }
            }

            if (Model.Properties.Last() != property)
            {
                sb.AppendLine();
            }

            return sb.ToString();
        }

        /// <summary>
        /// Type mapping for read operations from IDataReader
        /// </summary>
        private static readonly Dictionary<string, string> _readMethodMapping = new()
        {
            { "sbyte", "ReadSByte" },
            { "byte", "ReadByte" },
            { "short", "ReadShort" },
            { "ushort", "ReadUShort" },
            { "int", "ReadInt" },
            { "uint", "ReadUInt" },
            { "long", "ReadLong" },
            { "ulong", "ReadULong" },
            { "float", "ReadFloat" },
            { "double", "ReadDouble" },
            { "bool", "ReadBoolean" },
            { "char", "ReadChar" },
            { "string", "ReadUTF" }
        };

        /// <summary>
        /// Type mapping for write operations to IDataWriter
        /// </summary>
        private static readonly Dictionary<string, string> _writeMethodMapping = new()
        {
            { "sbyte", "WriteSByte" },
            { "byte", "WriteByte" },
            { "short", "WriteShort" },
            { "ushort", "WriteUShort" },
            { "int", "WriteInt" },
            { "uint", "WriteUInt" },
            { "long", "WriteLong" },
            { "ulong", "WriteULong" },
            { "float", "WriteFloat" },
            { "double", "WriteDouble" },
            { "bool", "WriteBoolean" },
            { "char", "WriteChar" },
            { "string", "WriteUTF" }
        };

        public string GenerateUsingDirectives()
        {
            var sb = new StringBuilder();
            foreach (var usable in Model.UsingStatements)
            {
                sb.AppendLine($"using {usable};");
            }
            return sb.ToString();
        }

        /// <summary>
        /// Generates the Serialize method that writes all properties to an IDataWriter
        /// </summary>
        /// <returns>Generated Serialize method code</returns>
        public string GenerateSerializeMethod()
        {
            var sb = new StringBuilder();

            sb.AppendLine("\t\t/// <summary>");
            sb.AppendLine("\t\t/// Serializes this instance to the specified data writer.");
            sb.AppendLine("\t\t/// </summary>");
            sb.AppendLine("\t\t/// <param name=\"writer\">The data writer to serialize to.</param>");
            sb.AppendLine("\t\tpublic void Serialize(IDataWriter writer)");
            sb.AppendLine("\t\t{");

            foreach (var property in Model.Properties)
            {
                if (property.IsProtocolId)
                {
                    // Skip ProtocolId as it's typically handled separately at message level
                    continue;
                }

                var writeCode = GenerateWriteCode(property);
                sb.Append(writeCode);
            }

            sb.AppendLine("\t\t}");

            return sb.ToString();
        }

        /// <summary>
        /// Generates the Deserialize method that reads all properties from an IDataReader
        /// </summary>
        /// <returns>Generated Deserialize method code</returns>
        public string GenerateDeserializeMethod()
        {
            var sb = new StringBuilder();

            sb.AppendLine("\t\t/// <summary>");
            sb.AppendLine("\t\t/// Deserializes this instance from the specified data reader.");
            sb.AppendLine("\t\t/// </summary>");
            sb.AppendLine("\t\t/// <param name=\"reader\">The data reader to deserialize from.</param>");
            sb.AppendLine("\t\tpublic void Deserialize(IDataReader reader)");
            sb.AppendLine("\t\t{");

            foreach (var property in Model.Properties)
            {
                if (property.IsProtocolId)
                {
                    // Skip ProtocolId as it's typically handled separately at message level
                    continue;
                }

                var readCode = GenerateReadCode(property);
                sb.Append(readCode);
            }

            sb.AppendLine("\t\t}");

            return sb.ToString();
        }

        /// <summary>
        /// Generates write code for a single property
        /// </summary>
        private string GenerateWriteCode(GeneratedProperty property)
        {
            var sb = new StringBuilder();
            var realType = property.RealType;

            // Add comment if select attribute is present
            if (!string.IsNullOrWhiteSpace(property.Select))
            {
                sb.AppendLine($"\t\t\t// Selected by: {property.Select}");
            }

            if (property.IsArray)
            {
                // Determine array length constraint
                string lengthVar = $"({property.Name}?.Length ?? 0)";
                string maxLength = GetArrayMaxLength(property);
                
                if(!string.IsNullOrWhiteSpace(maxLength))
                {
                    sb.AppendLine($"\t\t\tif ({lengthVar} > {maxLength})");
                    sb.AppendLine("\t\t\t{");
                    sb.AppendLine($"\t\t\t\tthrow new InvalidOperationException($\"Array length of '{property.Name}' exceeds maximum allowed length of {maxLength}.\");");
                    sb.AppendLine("\t\t\t}");
                }

                if (!string.IsNullOrWhiteSpace(property.Refer))
                {
                    var refer = ResolveRealLength(property.Refer);
                    // Array length is determined by another property (refer attribute)
                    
                    if (!string.IsNullOrWhiteSpace(maxLength))
                    {
                        // Both Refer and ArraySize are set - use Math.Min to cap at max length
                        sb.AppendLine($"\t\t\tvar {property.Name}Count = Math.Min((long){refer}, (long){maxLength});");
                    }
                    else
                    {
                        // Only Refer is set - use it directly
                        sb.AppendLine($"\t\t\tvar {property.Name}Count = (long){refer};");
                    }
                    lengthVar = $"{property.Name}Count";
                }
                else if (!string.IsNullOrWhiteSpace(maxLength))
                {
                    // Only ArraySize is set - cap at max length
                    sb.AppendLine($"\t\t\tvar {property.Name}Count = Math.Min({lengthVar}, {maxLength});");
                    lengthVar = $"{property.Name}Count";
                }

                // Write array elements
                sb.AppendLine($"\t\t\tfor (var i = 0; i < {lengthVar}; i++)");
                sb.AppendLine("\t\t\t{");

                if (IsPrimitiveType(realType))
                {
                    var writeMethod = GetWriteMethod(realType);
                    sb.AppendLine($"\t\t\t\twriter.{writeMethod}({property.Name}[i]);");
                }
                else
                {
                    // Custom type - call its Serialize method
                    sb.AppendLine($"\t\t\t\t{property.Name}[i]?.Serialize(writer);");
                }

                sb.AppendLine("\t\t\t}");
            }
            else if (IsPrimitiveType(realType))
            {
                var writeMethod = GetWriteMethod(realType);
                // Handle enum types - cast to underlying type
                if (property.Type != realType && !_writeMethodMapping.ContainsKey(property.Type))
                {
                    sb.AppendLine($"\t\t\twriter.{writeMethod}(({realType}){property.Name});");
                }
                else
                {
                    sb.AppendLine($"\t\t\twriter.{writeMethod}({property.Name});");
                }
            }
            else
            {
                // Custom type - call its Serialize method
                sb.AppendLine($"\t\t\t{property.Name}?.Serialize(writer);");
            }

            return sb.ToString();
        }

        /// <summary>
        /// Generates read code for a single property
        /// </summary>
        private string GenerateReadCode(GeneratedProperty property)
        {
            var sb = new StringBuilder();
            var realType = property.RealType;

            // Add comment if select attribute is present
            if (!string.IsNullOrWhiteSpace(property.Select))
            {
                sb.AppendLine($"\t\t\t// Selected by: {property.Select}");
            }

            if (property.IsArray)
            {
                sb.AppendLine($"\t\t\t// Read array: {property.Name}");

                // Determine array length
                string lengthExpr;
                string maxLength = GetArrayMaxLength(property);

                if (!string.IsNullOrWhiteSpace(property.Refer))
                {
                    var refer = ResolveRealLength(property.Refer);
                    // Array length is determined by another property (refer attribute)
                    lengthExpr = refer;

                    if (!string.IsNullOrWhiteSpace(maxLength))
                    {
                        lengthExpr = $"Math.Min((int){refer}, {maxLength})";
                    }
                }
                else if (!string.IsNullOrWhiteSpace(maxLength))
                {
                    lengthExpr = maxLength;
                }
                else
                {
                    // Fallback - this shouldn't happen for well-formed data
                    lengthExpr = "0";
                }

                sb.AppendLine($"\t\t\t{property.Name} = new {realType}[{lengthExpr}];");
                sb.AppendLine($"\t\t\tfor (var i = 0; i < {property.Name}.Length; i++)");
                sb.AppendLine("\t\t\t{");

                if (IsPrimitiveType(realType))
                {
                    var readMethod = GetReadMethod(realType);
                    sb.AppendLine($"\t\t\t\t{property.Name}[i] = reader.{readMethod}();");
                }
                else
                {
                    // Custom type - create instance and call its Deserialize method
                    GenerateDeserializeCustomObject(property, 4, sb, isArrayElement: true);
                }

                sb.AppendLine("\t\t\t}");
            }
            else if (IsPrimitiveType(realType))
            {
                var readMethod = GetReadMethod(realType);
                // Handle enum types - cast from underlying type
                if (property.Type != realType && !_readMethodMapping.ContainsKey(property.Type))
                {
                    sb.AppendLine($"\t\t\t{property.Name} = ({property.Type})reader.{readMethod}();");
                }
                else
                {
                    sb.AppendLine($"\t\t\t{property.Name} = reader.{readMethod}();");
                }
            }
            else
            {
                // Custom type - create instance and call its Deserialize method
                GenerateDeserializeCustomObject(property, 3, sb, isArrayElement: false);
            }

            return sb.ToString();
        }

        private void GenerateDeserializeCustomObject(GeneratedProperty property, int tabCount, StringBuilder sb, bool isArrayElement = false)
        {
            tabCount = Math.Max(tabCount, 0);
            var indent = new string('\t', tabCount);
            
            // Check if the property's RealType class contains a property with IsProtocolId = true
            var hasProtocolId = IsInterface(property.RealType);
            
            if (hasProtocolId && !string.IsNullOrWhiteSpace(property.Select))
            {
                // Use ProtocolTypeManager to get the instance based on the Select property
                var selectPath = ResolveRealLength(property.Select);
                if (isArrayElement)
                {
                    sb.AppendLine($"{indent}{property.Name}[i] = ProtocolTypeManager.Get<{property.RealType}>({selectPath});");
                    sb.AppendLine($"{indent}{property.Name}[i].Deserialize(reader);");
                }
                else
                {
                    sb.AppendLine($"{indent}{property.Name} = ProtocolTypeManager.Get<{property.RealType}>({selectPath});");
                    sb.AppendLine($"{indent}{property.Name}.Deserialize(reader);");
                }
            }
            else
            {
                // Use normal constructor
                if (isArrayElement)
                {
                    sb.AppendLine($"{indent}{property.Name}[i] = new {property.RealType}();");
                    sb.AppendLine($"{indent}{property.Name}[i].Deserialize(reader);");
                }
                else
                {
                    sb.AppendLine($"{indent}{property.Name} = new {property.RealType}();");
                    sb.AppendLine($"{indent}{property.Name}.Deserialize(reader);");
                }
            }
        }

        /// <summary>
        /// Checks if the specified class is interface then it means that it has been generated from union 
        /// then it has a ProtocolId property for inhereted classes for that interface
        /// </summary>
        private bool IsInterface(string typeName)
        {
            if (CodeModel == null)
                return false;

            return CodeModel.Interfaces.Any(c => c.Name == typeName);
        }

        /// <summary>
        /// Gets the maximum array length from the ArraySize property.
        /// Resolves references to constants (MetaLibConstants.X) and properties in the current class or nested custom types.
        /// </summary>
        private string GetArrayMaxLength(GeneratedProperty property)
        {
            if (string.IsNullOrWhiteSpace(property.ArraySize))
                return string.Empty;

            var arraySize = property.ArraySize;

            // If ArraySize is a number, return it directly
            if (int.TryParse(arraySize, out _))
                return arraySize;

            // Check if it's a reference to a constant (macro)
            if (CodeModel != null && CodeModel.Constants.ContainsKey(arraySize))
            {
                // It's a constant, prefix with MetaLibConstants class
                return $"MetaLibConstants.{arraySize}";
            }

            return ResolveRealLength(arraySize);
        }

        public string ResolveRealLength(string refer)
        {
            // Check if it's a property in the current class
            var currentClassProp = Model.Properties.FirstOrDefault(p => p.Name == refer);
            if (currentClassProp != null)
            {
                // It's a property in the current class, return as-is
                return refer;
            }

            // Try to resolve nested property path (e.g., "PropA.PropB.Count")
            var resolvedPath = ResolveNestedPropertyPath(refer);
            if (!string.IsNullOrWhiteSpace(resolvedPath))
            {
                return resolvedPath;
            }

            // Fallback: return as-is (might be a constant or property we couldn't resolve)
            return refer;
        }

        /// <summary>
        /// Resolves a nested property path by navigating through custom class properties.
        /// For example, if ArraySize is "Header.Count", it navigates Header -> Count.
        /// Also searches through all custom class properties of the Model to find the reference.
        /// </summary>
        private string ResolveNestedPropertyPath(string reference)
        {
            if (string.IsNullOrWhiteSpace(reference) || CodeModel == null)
                return reference;

            // Split by dots to check for nested paths
            var parts = reference.Split('.');

            // Navigate through nested properties starting from Model
            var resolvedPath = NavigatePropertyPath(parts, Model);
            if (!string.IsNullOrWhiteSpace(resolvedPath))
                return resolvedPath;

            // If direct path navigation failed, try searching in all custom class properties
            // This handles cases where the first part of the path is inside a custom class
            var searchPath = SearchPropertyPathInCustomClasses(parts);
            if (!string.IsNullOrWhiteSpace(searchPath))
                return searchPath;

            // Fallback: return as-is
            return reference;
        }

        /// <summary>
        /// Searches for a property name in all custom class properties of the Model.
        /// Returns the full path (e.g., "Header.Count") if found.
        /// </summary>
        private string? SearchPropertyInCustomClasses(string propertyName)
        {
            if (CodeModel == null)
                return null;

            // Iterate through all properties in the Model
            foreach (var modelProp in Model.Properties)
            {
                // Skip primitive types
                if (IsPrimitiveType(modelProp.RealType))
                    continue;

                // Find the class definition for this custom type
                var customClass = CodeModel.Classes.FirstOrDefault(c => c.Name == modelProp.RealType);
                if (customClass == null)
                    continue;

                // Check if the property exists in this custom class
                var foundProp = customClass.Properties.FirstOrDefault(p => p.Name == propertyName);
                if (foundProp != null)
                {
                    return $"{modelProp.Name}.{propertyName}";
                }

                // Recursively search in nested custom classes
                var nestedPath = SearchPropertyInNestedClasses(propertyName, customClass, modelProp.Name, new HashSet<string> { Model.Name, customClass.Name });
                if (!string.IsNullOrWhiteSpace(nestedPath))
                    return nestedPath;
            }

            return null;
        }

        /// <summary>
        /// Recursively searches for a property in nested custom classes.
        /// </summary>
        private string? SearchPropertyInNestedClasses(string propertyName, GeneratedClass currentClass, string currentPath, HashSet<string> visitedClasses)
        {
            if (CodeModel == null)
                return null;

            foreach (var prop in currentClass.Properties)
            {
                // Skip primitive types
                if (IsPrimitiveType(prop.RealType))
                    continue;

                // Avoid circular references
                if (visitedClasses.Contains(prop.RealType))
                    continue;

                // Find the class definition for this custom type
                var nestedClass = CodeModel.Classes.FirstOrDefault(c => c.Name == prop.RealType);
                if (nestedClass == null)
                    continue;

                var newPath = $"{currentPath}.{prop.Name}";
                visitedClasses.Add(nestedClass.Name);

                // Check if the property exists in this nested class
                var foundProp = nestedClass.Properties.FirstOrDefault(p => p.Name == propertyName);
                if (foundProp != null)
                {
                    return $"{newPath}.{propertyName}";
                }

                // Continue searching deeper
                var deeperPath = SearchPropertyInNestedClasses(propertyName, nestedClass, newPath, visitedClasses);
                if (!string.IsNullOrWhiteSpace(deeperPath))
                    return deeperPath;
            }

            return null;
        }

        /// <summary>
        /// Searches for a property path in all custom class properties of the Model.
        /// </summary>
        private string? SearchPropertyPathInCustomClasses(string[] parts)
        {
            if (CodeModel == null || parts.Length == 0)
                return null;

            var firstPart = parts[0];

            // Iterate through all properties in the Model
            foreach (var modelProp in Model.Properties)
            {
                // Skip primitive types
                if (IsPrimitiveType(modelProp.RealType))
                    continue;

                // Find the class definition for this custom type
                var customClass = CodeModel.Classes.FirstOrDefault(c => c.Name == modelProp.RealType);
                if (customClass == null)
                    continue;

                // Check if the first part of the path exists in this custom class
                var foundProp = customClass.Properties.FirstOrDefault(p => p.Name == firstPart);
                if (foundProp != null)
                {
                    // Navigate the rest of the path from here
                    var remainingPath = NavigatePropertyPath(parts, customClass);
                    if (!string.IsNullOrWhiteSpace(remainingPath))
                    {
                        return $"{modelProp.Name}.{remainingPath}";
                    }
                }
            }

            return null;
        }

        /// <summary>
        /// Navigates a property path starting from a given class.
        /// Returns the validated path or null if navigation fails.
        /// </summary>
        private string? NavigatePropertyPath(string[] parts, GeneratedClass startClass)
        {
            if (CodeModel == null)
                return null;

            var pathBuilder = new StringBuilder();
            GeneratedClass? currentClass = startClass;

            for (int i = 0; i < parts.Length; i++)
            {
                var partName = parts[i];

                if (currentClass == null)
                    return null;

                var prop = currentClass.Properties.FirstOrDefault(p => p.Name == partName);
                if (prop == null)
                {
                    // Property not found in current class
                    return null;
                }

                if (pathBuilder.Length > 0)
                    pathBuilder.Append('.');
                pathBuilder.Append(partName);

                // If not the last part, navigate to the nested class
                if (i < parts.Length - 1)
                {
                    // Find the class that matches the property type
                    currentClass = CodeModel.Classes.FirstOrDefault(c => c.Name == prop.RealType);
                    if (currentClass == null)
                    {
                        // Custom class not found, can't navigate further
                        return null;
                    }
                }
            }

            return pathBuilder.Length > 0 ? pathBuilder.ToString() : null;
        }

        /// <summary>
        /// Checks if a type is a primitive type that has a direct read/write method
        /// </summary>
        private bool IsPrimitiveType(string typeName)
        {
            return _readMethodMapping.ContainsKey(typeName);
        }

        /// <summary>
        /// Gets the appropriate read method for a type
        /// </summary>
        private string GetReadMethod(string typeName)
        {
            return _readMethodMapping.TryGetValue(typeName, out var method) ? method : "ReadByte";
        }

        /// <summary>
        /// Gets the appropriate write method for a type
        /// </summary>
        private string GetWriteMethod(string typeName)
        {
            return _writeMethodMapping.TryGetValue(typeName, out var method) ? method : "WriteByte";
        }
    }
}
