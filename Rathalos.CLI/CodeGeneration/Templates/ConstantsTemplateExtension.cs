using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.CLI.CodeGeneration.Templates
{
    public partial class ConstantsTemplate
    {
        public Dictionary<string, string> Constants { get; set; }
        public string TargetNamespace { get; set; }
    }
}
