namespace Rathalos.Core.ORM.Config
{
	[Serializable]
	public class ORMConfiguration
	{
		public string Username
		{
			get;
			set;
		}

		public string Password
		{
			get;
			set;
		}

		public string DbName
		{
			get;
			set;
		}

		public string Host
		{
			get;
			set;
		}

		public string GetConnectionString()
		{
			if (!string.IsNullOrEmpty(Username))
				return $"mongodb://{Username}:{Password}@{Host}/";

			return $"mongodb://{Host}/";
		}
	}
}
