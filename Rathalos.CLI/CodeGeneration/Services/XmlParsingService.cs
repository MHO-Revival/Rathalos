using System.Xml.Serialization;
using System.Text;
using System.Text.RegularExpressions;
using Rathalos.CLI.CodeGeneration.Models;

namespace Rathalos.CLI.CodeGeneration.Services
{
    /// <summary>
    /// Service for parsing XML metalib files
    /// </summary>
    public class XmlParsingService
    {
        public async Task<MetaLib> ParseXmlAsync(string xmlFilePath)
        {
            if (!File.Exists(xmlFilePath))
            {
                throw new FileNotFoundException($"XML file not found: {xmlFilePath}");
            }

            try
            {
                // Read and preprocess the XML content to fix common encoding issues
                var xmlContent = await File.ReadAllTextAsync(xmlFilePath);
                var processedXml = PreprocessXmlContent(xmlContent);

                return await ParseXmlFromStringAsync(processedXml);
            }
            catch (Exception ex) when (ex.Message.Contains("encoding"))
            {
                // If encoding error, try to fix it and provide helpful message
                throw new InvalidOperationException(
                    "XML encoding error detected. Common issues:\n" +
                    "- Use 'UTF-8' instead of 'UTF8' in XML declaration\n" +
                    "- Ensure file is saved with proper encoding\n" +
                    $"Original error: {ex.Message}", ex);
            }
        }

        public async Task<MetaLib> ParseXmlFromStringAsync(string xmlContent)
        {
            try
            {
                var processedXml = PreprocessXmlContent(xmlContent);
                var serializer = new XmlSerializer(typeof(MetaLib));
                
                using var stringReader = new StringReader(processedXml);
                var metaLib = (MetaLib?)serializer.Deserialize(stringReader);
                
                return metaLib ?? throw new InvalidOperationException("Failed to parse XML content");
            }
            catch (Exception ex) when (ex.Message.Contains("encoding"))
            {
                throw new InvalidOperationException(
                    "XML encoding error. Please check:\n" +
                    "1. XML declaration should use 'UTF-8' not 'UTF8'\n" +
                    "2. File should be saved with UTF-8 encoding\n" +
                    "3. No special characters in file path\n" +
                    $"Original error: {ex.Message}", ex);
            }
        }

        /// <summary>
        /// Preprocesses XML content to fix common encoding and format issues
        /// </summary>
        private string PreprocessXmlContent(string xmlContent)
        {
            // Fix common encoding declaration issues
            // Replace 'encoding="UTF8"' with 'encoding="UTF-8"'
            var encodingPattern = @"encoding=['""]UTF8['""]";
            var correctedXml = Regex.Replace(xmlContent, encodingPattern, "encoding=\"UTF-8\"", RegexOptions.IgnoreCase);
            
            // Also handle other common encoding variants
            correctedXml = Regex.Replace(correctedXml, @"encoding=['""]utf8['""]", "encoding=\"UTF-8\"", RegexOptions.IgnoreCase);
            correctedXml = Regex.Replace(correctedXml, @"encoding=['""]utf-8['""]", "encoding=\"UTF-8\"", RegexOptions.IgnoreCase);
            
            // If no encoding specified, add UTF-8 encoding
            if (!correctedXml.Contains("encoding=") && correctedXml.StartsWith("<?xml"))
            {
                correctedXml = correctedXml.Replace("<?xml version=\"1.0\"", "<?xml version=\"1.0\" encoding=\"UTF-8\"");
            }

            return correctedXml;
        }

        public bool ValidateXmlFile(string xmlFilePath)
        {
            try
            {
                if (!File.Exists(xmlFilePath))
                    return false;

                var content = File.ReadAllText(xmlFilePath);
                return ValidateXmlContent(content);
            }
            catch
            {
                return false;
            }
        }

        public bool ValidateXmlContent(string xmlContent)
        {
            try
            {
                var processedXml = PreprocessXmlContent(xmlContent);
                var serializer = new XmlSerializer(typeof(MetaLib));
                using var stringReader = new StringReader(processedXml);
                var metaLib = serializer.Deserialize(stringReader);
                return metaLib != null;
            }
            catch
            {
                return false;
            }
        }
    }
}