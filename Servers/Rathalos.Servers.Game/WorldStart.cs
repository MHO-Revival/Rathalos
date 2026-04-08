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

            // Apply database migrations on startup
            await ApplyDatabaseMigrationsAsync(app.Services, app.Logger);

            WorldServer.SaveableServices = await app.Services.WarmUp(Assembly.GetExecutingAssembly());

            app.Run();
        }

        /// <summary>
        /// Applies pending database migrations on startup
        /// </summary>
        private static async Task ApplyDatabaseMigrationsAsync(IServiceProvider services, ILogger logger)
        {
            logger.LogInformation("🔍 Checking for pending database migrations...");

            try
            {
                using var scope = services.CreateScope();
                var dbContext = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();

                // Check if database can be connected
                var canConnect = await dbContext.Database.CanConnectAsync();
                if (!canConnect)
                {
                    logger.LogWarning("⚠️ Cannot connect to database. Waiting for database to be ready...");

                    // Wait up to 30 seconds for database to be ready
                    var retries = 0;
                    while (!canConnect && retries < 30)
                    {
                        await Task.Delay(1000);
                        canConnect = await dbContext.Database.CanConnectAsync();
                        retries++;
                    }

                    if (!canConnect)
                    {
                        logger.LogError("❌ Could not connect to database after 30 seconds");
                        throw new InvalidOperationException("Database connection failed");
                    }

                    logger.LogInformation("✅ Database connection established");
                }

                // Get pending migrations
                var pendingMigrations = await dbContext.Database.GetPendingMigrationsAsync();
                var pendingCount = pendingMigrations.Count();

                if (pendingCount > 0)
                {
                    logger.LogInformation("📦 Applying {Count} pending migration(s)...", pendingCount);
                    foreach (var migration in pendingMigrations)
                    {
                        logger.LogInformation("  - {Migration}", migration);
                    }

                    await dbContext.Database.MigrateAsync();
                    logger.LogInformation("✅ Database migrations applied successfully!");
                }
                else
                {
                    logger.LogInformation("✅ Database is up to date - no migrations needed");
                }
            }
            catch (Exception ex)
            {
                logger.LogError(ex, "❌ Failed to apply database migrations");
                throw; // Fail fast - don't start the server if migrations fail
            }
        }
    }
}
