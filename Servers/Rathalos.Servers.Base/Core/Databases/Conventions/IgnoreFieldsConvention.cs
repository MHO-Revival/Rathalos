using MongoDB.Bson.Serialization;
using MongoDB.Bson.Serialization.Conventions;
using System.Reflection;

namespace Rathalos.Servers.Base.Core.Databases.Conventions
{
	public class IgnoreFieldsConvention : ConventionBase, IMemberMapConvention
	{
		public static readonly ConventionPack Pack = new()
		{
			new IgnoreFieldsConvention() 
		};
		public void Apply(BsonMemberMap memberMap)
		{ // more checks will go here for the case above, e.g. type check
			if (memberMap.MemberInfo is not PropertyInfo)
			{
				memberMap.SetShouldSerializeMethod(o => false);
			}
		}
	}
}
