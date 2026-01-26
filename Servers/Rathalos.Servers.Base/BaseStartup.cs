using Rathalos.Core.ORM.Config;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Core.Configurations;
using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using System.Text.Json;
using System.Text.Json.Serialization;
using Rathalos.Servers.Base.Core.Network;

namespace Rathalos.Servers.Base
{
	public abstract class BaseStartup<TConfiguration>
		where TConfiguration : BaseServerConfiguration, new()
	{
		private const string _configPath = "appsettings.json";

		public IConfiguration Configuration { get; }

		public BaseStartup(IConfiguration configuration)
		{
			Console.Title = this.GetType().Name;

			AsciiArtExtensions
				.RathalosArt()
				.PrintCenteredAsciiArt();


			if (!File.Exists(_configPath))
			{
				File.WriteAllText(_configPath, JsonSerializer.Serialize(new { Server = new TConfiguration() }, new JsonSerializerOptions
                {
					WriteIndented = true,
					Converters = { new JsonStringEnumConverter() }
				}));
			}

			ConfigureConfiguration(configuration.GetSection("Server").Get<TConfiguration>());
			Configuration = configuration;
		}

		public virtual void ConfigureServices(IServiceCollection services)
		{
			services.AddOptions<TConfiguration>()
					.BindConfiguration("Server");
			services.AddOptions<ORMConfiguration>()
					.BindConfiguration("Server:Database");
		}

		protected virtual void ConfigureConfiguration(TConfiguration configuration) 
		{
			
        }
	}
}
