namespace Rathalos.Core.ORM.Attributes
{
	[AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
	public class CollectionNameAttribute : Attribute
	{
		public string Name { get; set; }

		public CollectionNameAttribute(string name)
		{
			Name = name;
		}
	}
}