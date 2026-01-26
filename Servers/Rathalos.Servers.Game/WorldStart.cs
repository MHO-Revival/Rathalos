using Rathalos.Core.ORM;
using Rathalos.Servers.Base.Core.Extensions;
using Rathalos.Servers.World.Core.Extensions;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World
{
    public static class WorldStart
    {
        public static void Start(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);
                builder.Configuration
                .AddJsonFile("appsettings.json")
                .AddEnvironmentVariables()
                .AddCommandLine(args);

            builder.Logging.ClearProviders()
                .AddCustomFormatter();

            builder.AddNpgsqlDbContext<ORMDatabase>("rathalos-world");

            var startup = new WorldStartup(builder.Configuration);
            startup.ConfigureServices(builder.Services);

            //builder.WebHost.UseUrls($"http://+:{builder.Configuration["Server:WebApiPort"]}");

            // Add service defaults & Aspire client integrations.
            builder.AddServiceDefaults();

            var app = builder.Build();
            startup.Configure(app, app.Environment);
            WorldServer.SaveableServices = app.Services.WarmUp();

            app.Run();
        }
    }
}
