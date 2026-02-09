using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Design;
using Rathalos.Core.ORM;
using Rathalos.Core.ORM.Extensions;
using Rathalos.Servers.World;

namespace Rathalos.Core.Migrations;

/// <summary>
/// Design-time factory for creating <see cref="RathalosDbContext"/> instances.
/// Used by EF Core tools for migrations.
/// 
/// # Add a new migration
/// dotnet ef migrations add MigrationName --startup-project Core\Rathalos.Core.Migrations
/// 
/// # Apply migrations only (using EF CLI)
/// dotnet ef database update --startup-project Core\Rathalos.Core.Migrations
/// 
/// </summary>
public class RathalosDbContextFactory : IDesignTimeDbContextFactory<RathalosDbContext>
{
    public RathalosDbContext CreateDbContext(string[] args)
    {
        var connectionString = args.Length > 0
            ? args[0]
            : "Host=localhost;Database=rathalos-world;Username=postgres;Password=mxRUYSSc745J{vUbU6e}}C";

        var optionsBuilder = new DbContextOptionsBuilder<RathalosDbContext>();
        optionsBuilder.UseNpgsql(connectionString, npgsqlOptions =>
        {
            npgsqlOptions.MigrationsAssembly(typeof(RathalosDbContextFactory).Assembly.FullName);
        });

        optionsBuilder.UseRathalosConfiguration(WorldStartup.ConfigureDatabaseEntities);

        return new RathalosDbContext(optionsBuilder.Options);
    }
}
