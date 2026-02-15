using Microsoft.EntityFrameworkCore;
using Npgsql;
using Rathalos.Core.ORM;
using Rathalos.Core.ORM.Extensions;
using Rathalos.Servers.Base.Core.Extensions;
using Rathalos.Servers.World.Core.Extensions;
using Rathalos.Servers.World.Core.Network;
using System.Reflection;

namespace Rathalos.Servers.World
{
    public static class WorldStart
    {
        public static async Task Start(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);
                builder.Configuration
                .AddJsonFile("appsettings.json")
                .AddEnvironmentVariables()
                .AddCommandLine(args);

            builder.Logging.ClearProviders()
                .AddCustomFormatter();

            var startup = new WorldStartup(builder.Configuration);
            startup.ConfigureServices(builder.Services);


            builder.AddNpgsqlDbContext<RathalosDbContext>("rathalos-world", null, ob =>
            {
                ob.UseNpgsql(o =>
                {
                    o.ConfigureDataSource(a =>
                    {
                        a.EnableDynamicJson();
                    });
                });
                ob.UseRathalosConfiguration(startup.ConfigureDatabase);
                
            });

            //builder.WebHost.UseUrls($"http://+:{builder.Configuration["Server:WebApiPort"]}");

            // Add service defaults & Aspire client integrations.
            builder.AddServiceDefaults();

            var app = builder.Build();
            startup.Configure(app, app.Environment);
            WorldServer.SaveableServices = await app.Services.WarmUp(Assembly.GetExecutingAssembly());

            app.Run();
        }
    }
}
