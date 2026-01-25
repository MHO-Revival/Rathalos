namespace Rathalos.CLI.CodeGeneration.Models
{
    /// <summary>
    /// Generated code model for structs/classes
    /// </summary>
    public class GeneratedClass
    {
        public string Name { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
        public string Namespace { get; set; } = string.Empty;
        public List<GeneratedProperty> Properties { get; set; } = new List<GeneratedProperty>();
        public List<string> UsingStatements { get; set; } = new List<string>();
        public bool IsStruct { get; set; }
        public string? BaseClass { get; set; }
        public List<string> Interfaces { get; set; } = new List<string>();
        public List<GeneratedConstructor> Constructors { get; set; } = new List<GeneratedConstructor>();
        /// <summary>
        /// The wrapped type name when this class is a wrapper for a union entry
        /// </summary>
        public string? WrappedTypeName { get; set; }
    }

    /// <summary>
    /// Generated code model for constructors
    /// </summary>
    public class GeneratedConstructor
    {
        public string Description { get; set; } = string.Empty;
        public List<GeneratedConstructorParameter> Parameters { get; set; } = new List<GeneratedConstructorParameter>();
        /// <summary>
        /// The body of the constructor (lines of code)
        /// </summary>
        public List<string> Body { get; set; } = new List<string>();
    }

    /// <summary>
    /// Generated code model for constructor parameters
    /// </summary>
    public class GeneratedConstructorParameter
    {
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
    }

    /// <summary>
    /// Generated code model for enums
    /// </summary>
    public class GeneratedEnum
    {
        public string Name { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
        public string Namespace { get; set; } = string.Empty;
        public List<GeneratedEnumValue> Values { get; set; } = new List<GeneratedEnumValue>();
        public string UnderlyingType { get; set; } = "int";
    }

    /// <summary>
    /// Generated code model for interfaces (from unions)
    /// </summary>
    public class GeneratedInterface
    {
        public string Name { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
        public string Namespace { get; set; } = string.Empty;
        public List<GeneratedProperty> Properties { get; set; } = new List<GeneratedProperty>();
        public List<string> UsingStatements { get; set; } = new List<string>();
        public List<string> ImplementingClasses { get; set; } = new List<string>();
    }

    public class GeneratedProperty
    {
        public string Name { get; set; } = string.Empty;
        public string Type { get; set; } = string.Empty;
        public string RealType { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
        public string? DefaultValue { get; set; }
        public bool IsArray { get; set; }
        public string? ArraySize { get; set; }
        public bool IsProtocolId { get; set; } = false;
        public List<string> Attributes { get; set; } = new List<string>();
        /// <summary>
        /// The select attribute from XML that identifies which property determines the type of data to serialize/deserialize
        /// </summary>
        public string? Select { get; set; }
        /// <summary>
        /// The refer attribute from XML that points to the property containing the array length
        /// </summary>
        public string? Refer { get; set; }
        public string StringMaxSize { get; internal set; }
    }

    public class GeneratedEnumValue
    {
        public string Name { get; set; } = string.Empty;
        public string Value { get; set; } = string.Empty;
        public string Description { get; set; } = string.Empty;
    }

    /// <summary>
    /// Container for all generated code
    /// </summary>
    public class GeneratedCodeModel
    {
        public List<GeneratedClass> Classes { get; set; } = new List<GeneratedClass>();
        public List<GeneratedEnum> Enums { get; set; } = new List<GeneratedEnum>();
        public List<GeneratedInterface> Interfaces { get; set; } = new List<GeneratedInterface>();
        public Dictionary<string, string> Constants { get; set; } = new Dictionary<string, string>();
        public string TargetNamespace { get; set; } = string.Empty;
        public string TargetName { get; set; }
    }
}