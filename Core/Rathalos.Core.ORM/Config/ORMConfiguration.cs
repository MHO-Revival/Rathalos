namespace Rathalos.Core.ORM.Config
{
	[Serializable]
	public class ORMConfiguration
	{
		public string Username { get; set; }

		public string Password { get; set; }

		public string DbName { get; set; }

		public string Host { get; set; }

		public int Port { get; set; } = 5432;

		public string GetConnectionString()
		{
			if (!string.IsNullOrEmpty(Username))
				return $"Host={Host};Port={Port};Database={DbName};Username={Username};Password={Password}";

			return $"Host={Host};Port={Port};Database={DbName}";
		}
	}
}
