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
        /// Generates property code with XML documentation, attributes, and proper syntax
        /// </summary>
        /// <param name="property">The property to generate code for</param>
        /// <returns>Generated property code as string</returns>
        public string GeneratePropertyCode(GeneratedProperty property)
        {
            var sb = new StringBuilder();

            if(property.IsProtocolId)
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

            if(Model.Properties.Last() != property)
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
                sb.AppendLine($"\t\t\t// Write array: {property.Name}");
                
                // Determine array length constraint
                string lengthVar = $"{property.Name}?.Length ?? 0";
                string maxLength = GetArrayMaxLength(property);
                
                if (!string.IsNullOrWhiteSpace(maxLength))
                {
                    sb.AppendLine($"\t\t\tvar {property.Name}Count = Math.Min({lengthVar}, {maxLength});");
                    lengthVar = $"{property.Name}Count";
                }
                else if (!string.IsNullOrWhiteSpace(property.Refer))
                {
                    // Array length is determined by another property (refer attribute)
                    sb.AppendLine($"\t\t\tvar {property.Name}Count = {lengthVar};");
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
                    // Array length is determined by another property (refer attribute)
                    lengthExpr = property.Refer;
                    
                    if (!string.IsNullOrWhiteSpace(maxLength))
                    {
                        lengthExpr = $"Math.Min((int){property.Refer}, {maxLength})";
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
                    sb.AppendLine($"\t\t\t\t{property.Name}[i] = new {realType}();");
                    sb.AppendLine($"\t\t\t\t{property.Name}[i].Deserialize(reader);");
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
                sb.AppendLine($"\t\t\t{property.Name} = new {realType}();");
                sb.AppendLine($"\t\t\t{property.Name}.Deserialize(reader);");
            }

            return sb.ToString();
        }

        /// <summary>
        /// Gets the maximum array length from the ArraySize property
        /// </summary>
        private string GetArrayMaxLength(GeneratedProperty property)
        {
            if (string.IsNullOrWhiteSpace(property.ArraySize))
                return string.Empty;

            // If ArraySize is a number, return it directly
            if (int.TryParse(property.ArraySize, out _))
                return property.ArraySize;

            // If it's a reference to a constant or macro, return as-is
            return property.ArraySize;
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
