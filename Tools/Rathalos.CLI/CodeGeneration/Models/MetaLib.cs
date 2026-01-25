using System.Xml.Serialization;

namespace Rathalos.CLI.CodeGeneration.Models
{
    [XmlRoot("metalib")]
    public class MetaLib
    {
        [XmlAttribute("tagsetversion")]
        public string TagSetVersion { get; set; } = string.Empty;

        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("version")]
        public string Version { get; set; } = string.Empty;

        [XmlElement("macro")]
        public List<Macro> Macros { get; set; } = new List<Macro>();

        [XmlElement("macrosgroup")]
        public List<MacrosGroup> MacrosGroups { get; set; } = new List<MacrosGroup>();

        [XmlElement("struct")]
        public List<Struct> Structs { get; set; } = new List<Struct>();

        [XmlElement("union")]
        public List<Union> Unions { get; set; } = new List<Union>();
    }

    public class Macro
    {
        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("value")]
        public string Value { get; set; } = string.Empty;

        [XmlAttribute("desc")]
        public string Description { get; set; } = string.Empty;
    }

    public class MacrosGroup
    {
        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("desc")]
        public string Description { get; set; } = string.Empty;

        [XmlElement("macro")]
        public List<Macro> Macros { get; set; } = new List<Macro>();
    }

    public class Struct
    {
        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("version")]
        public string Version { get; set; } = string.Empty;

        [XmlAttribute("desc")]
        public string Description { get; set; } = string.Empty;

        [XmlAttribute("versionindicator")]
        public string VersionIndicator { get; set; } = string.Empty;

        [XmlAttribute("sizeinfo")]
        public string SizeInfo { get; set; } = string.Empty;

        [XmlElement("entry")]
        public List<Entry> Entries { get; set; } = new List<Entry>();
    }

    public class Union
    {
        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("version")]
        public string Version { get; set; } = string.Empty;

        [XmlAttribute("desc")]
        public string Description { get; set; } = string.Empty;

        [XmlElement("entry")]
        public List<Entry> Entries { get; set; } = new List<Entry>();
    }

    public class Entry
    {
        [XmlAttribute("name")]
        public string Name { get; set; } = string.Empty;

        [XmlAttribute("type")]
        public string Type { get; set; } = string.Empty;

        [XmlAttribute("count")]
        public string Count { get; set; } = string.Empty;

        [XmlAttribute("version")]
        public string Version { get; set; } = string.Empty;

        [XmlAttribute("desc")]
        public string Description { get; set; } = string.Empty;

        [XmlAttribute("refer")]
        public string Refer { get; set; } = string.Empty;

        [XmlAttribute("select")]
        public string Select { get; set; } = string.Empty;

        [XmlAttribute("id")]
        public string Id { get; set; } = string.Empty;

        [XmlAttribute("default")]
        public string Default { get; set; } = string.Empty;

        [XmlAttribute("bindmacrosgroup")]
        public string BindMacrosGroup { get; set; } = string.Empty;

        [XmlAttribute("size")]
        public string Size { get; set; } = string.Empty;
    }
}