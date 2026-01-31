using Microsoft.EntityFrameworkCore;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Servers.Base;
using Rathalos.Servers.Base.Core.Extensions;
using Rathalos.Servers.World.Core.Configurations;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Extensions;
using Rathalos.Servers.World.Core.Network;
using Scalar.AspNetCore;
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
            //MessageReceiver.Initialize();
            ProtocolTypeManager.Initialize();

            Assembly asm = Assembly.GetExecutingAssembly();


            services.AddControllers();
            services.AddHttpContextAccessor()
                .AddCors()
                .AddMvc()
                .AddApplicationPart(typeof(WorldStartup).Assembly)
                .AddJsonOptions(options =>
                {
                    options.JsonSerializerOptions.PropertyNamingPolicy = null;
                });


            // Add services to the container.
            services.AddProblemDetails();

            // Learn more about configuring OpenAPI at https://aka.ms/aspnet/openapi
            services.AddOpenApi("v1");

            services
                .AddBaseServices(asm)
                .AddMhoServices(asm)
                .AddHostedService<WorldServer>();
        }

        public void Configure(WebApplication app, IWebHostEnvironment env)
        {

            // Configure the HTTP request pipeline.
            app.UseExceptionHandler();
            app.MapOpenApi();

            if (env.IsDevelopment())
            {
                app.UseDeveloperExceptionPage();

                app.MapScalarApiReference(o =>
                {
                    o.AddDocument("v1");
                });
            }
            else
            {
                app.UseExceptionHandler("/Error");
                app.UseHsts();
            }

            app/*.UseHttpsRedirection()*/
               .UseRouting()
               .UseCors(builder =>
               {
                   builder.AllowAnyHeader()
                          .AllowAnyMethod()
                          .AllowAnyOrigin();
               })
               .UseAuthentication()
               .UseAuthorization()
               .UseHsts()
               .UseEndpoints(endpoints =>
               {
                   endpoints.MapControllers();
                   endpoints.MapDefaultControllerRoute().RequireAuthorization();
               });

            app.MapDefaultEndpoints();
        }

        protected override void ConfigureConfiguration(WorldServerConfiguration configuration)
        {
            WorldServer.Configuration = configuration;
        }

        public override void ConfigureDatabase(ModelBuilder builder)
        {
            ConfigureDatabaseEntities(builder);
            base.ConfigureDatabase(builder);
        }

        /// <summary>
        /// Configures all database entities for the World server.
        /// This method is also used by the migrations project.
        /// </summary>
        public static void ConfigureDatabaseEntities(ModelBuilder builder)
        {
            builder.Entity<AccountRecord>();
        }
    }
}
