using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Design;
using Rathalos.Core.ORM;
using Rathalos.Core.ORM.Extensions;
using Rathalos.Servers.World;

namespace Rathalos.Core.Migrations;

/// <summary>
/// Design-time factory for creating <see cref="RathalosDbContext"/> instances.
/// Used by EF Core tools for migrations.
/// </summary>
public class RathalosDbContextFactory : IDesignTimeDbContextFactory<RathalosDbContext>
{
    public RathalosDbContext CreateDbContext(string[] args)
    {
        var connectionString = args.Length > 0
            ? args[0]
            : "Host=localhost;Database=rathalos;Username=postgres;Password=postgres";

        var optionsBuilder = new DbContextOptionsBuilder<RathalosDbContext>();
        optionsBuilder.UseNpgsql(connectionString, npgsqlOptions =>
        {
            npgsqlOptions.MigrationsAssembly(typeof(RathalosDbContextFactory).Assembly.FullName);
        });

        optionsBuilder.Options.WithExtension(new DatabaseConfigurationExtension(WorldStartup.ConfigureDatabaseEntities));

        return new RathalosDbContext(optionsBuilder.Options);
    }
}
