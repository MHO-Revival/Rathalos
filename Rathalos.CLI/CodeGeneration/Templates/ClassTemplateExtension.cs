using Rathalos.CLI.CodeGeneration.Models;
using System;
using System.Collections.Generic;
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
                sb.Append($"\t\tpublic {property.Type} {property.Name} => {property.Name}Const;");
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
    }
}
