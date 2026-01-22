using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Rathalos.Core.ORM.Attributes
{
	[AttributeUsage(AttributeTargets.Property | AttributeTargets.Field)]
	public class PrimaryKeyAttribute : Attribute
	{
		public PrimaryKeyAttribute(string keyName, bool autoIncrement = false)
		{
			KeyName = keyName;
			AutoIncrement = autoIncrement;
		}

		public string KeyName { get; set; }
		public bool AutoIncrement { get; set; }
	}
}