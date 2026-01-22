using Rathalos.CLI.CodeGeneration.Models;
using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.CLI.CodeGeneration.Templates
{
    public partial class InterfaceTemplate
    {
        public GeneratedInterface Model { get; set; }

        public string GenerateUsingDirectives()
        {
            var sb = new StringBuilder();
            foreach (var usable in Model.UsingStatements)
            {
                sb.AppendLine($"using {usable};");
            }
            return sb.ToString();
        }
    }
}
