using Rathalos.CLI.CodeGeneration.Models;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.CLI.CodeGeneration.Templates
{
    public partial class EnumTemplate
    {
        public GeneratedEnum Model { get; set; }

        public string WriteEnumValue(GeneratedEnumValue value, bool isLast)
        {
            StringBuilder sb = new StringBuilder();
            if (!string.IsNullOrEmpty(value.Description))
            {
                sb.AppendLine("\t\t/// <summary>");
                sb.AppendLine($"\t\t/// {value.Description}");
                sb.AppendLine("\t\t/// </summary>");
            }
            sb.Append($"\t\t{value.Name}");
            if (!string.IsNullOrEmpty(value.Value))
            {
                sb.Append($" = {value.Value}");
            }
            if (!isLast)
                sb.AppendLine(",");
            return sb.ToString();
        }
    }
}
