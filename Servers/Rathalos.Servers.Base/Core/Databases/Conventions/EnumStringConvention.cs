using MongoDB.Bson;
using MongoDB.Bson.Serialization.Conventions;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Rathalos.Servers.Base.Core.Databases.Conventions
{
	public class EnumStringConvention
	{
		public static readonly ConventionPack Pack = new()
		{
			new EnumRepresentationConvention(BsonType.String)
		};
	}
}