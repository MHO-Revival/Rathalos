using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.Extensions.DependencyInjection;

namespace Rathalos.Core.ORM.Extensions
{
    public class DatabaseConfigurationExtension : IDbContextOptionsExtension
    {
        public DatabaseConfigurationExtension(Action<ModelBuilder> configureBuilder)
        {
            ConfigureBuilder = configureBuilder;
        }
        public virtual DbContextOptionsExtensionInfo Info => new ORMDbContextOptionsExtensionInfo(this);
        public Action<ModelBuilder> ConfigureBuilder { get; }

        public void ApplyServices(IServiceCollection services)
        {
        }

        public void Validate(IDbContextOptions options)
        {
        }

        private class ORMDbContextOptionsExtensionInfo : DbContextOptionsExtensionInfo
        {
            public ORMDbContextOptionsExtensionInfo(IDbContextOptionsExtension extension) : base(extension)
            {
            }
            public override bool IsDatabaseProvider => false;
            public override string LogFragment => "Using RathalosConfigurationExtensions ";
            public override int GetServiceProviderHashCode()
            {
                return 0;
            }
            public override bool ShouldUseSameServiceProvider(DbContextOptionsExtensionInfo other)
            {
                return other is ORMDbContextOptionsExtensionInfo;
            }
            public override void PopulateDebugInfo(IDictionary<string, string> debugInfo)
            {
                debugInfo["RathalosConfigurationExtensions"] = "Used";
            }
        }
    }
}
