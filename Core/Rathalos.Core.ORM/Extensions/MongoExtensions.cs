using System.Drawing;
using MongoDB.Bson;

namespace Rathalos.Core.Utils.Extensions;

public static class MongoExtensions
{
	public static long ToInt64(this ObjectId id)
	{
		var bytes = id.ToByteArray();
		byte[] truncatedBytes = [.. bytes[..4], .. bytes[9..]];
		return BitConverter.ToInt64(truncatedBytes);
	}
}