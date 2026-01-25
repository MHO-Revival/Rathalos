using Microsoft.Extensions.Configuration;
using Microsoft.Extensions.DependencyInjection;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Servers.Base;
using Rathalos.Servers.Base.Core.Extensions;
using Rathalos.Servers.World.Core.Configurations;
using Rathalos.Servers.World.Core.Network;
using System.Reflection;

namespace Rathalos.Servers.World
{
    public sealed class WorldStartup : BaseStartup<WorldServerConfiguration>
    {
        public WorldStartup(IConfiguration configuration) : base(configuration)
        {
        }

        public override void ConfigureServices(IServiceCollection services)
        {
            base.ConfigureServices(services);
            MessageReceiver.Initialize();
            ProtocolTypeManager.Initialize();

            Assembly asm = Assembly.GetExecutingAssembly();

            services
                .AddBaseServices(asm)
                .AddMhoServices(asm)
                .AddHostedService<WorldServer>();
        }
    }
}
