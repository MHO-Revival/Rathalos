using Microsoft.EntityFrameworkCore;
using Rathalos.Core.Protocol.Messages;
using Rathalos.Servers.Base;
using Rathalos.Servers.Base.Core.Extensions;
using Rathalos.Servers.World.Core.Configurations;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Databases.Records;
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
            // Account
            builder.Entity<AccountRecord>();

            // Avatar
            builder.Entity<FaceInfoRecord>();
            builder.Entity<HairInfoRecord>();
            builder.Entity<TattooInfoRecord>();
            builder.Entity<UnderclothesInfoRecord>();

            // NPC
            builder.Entity<NpcDataRecord>();
            builder.Entity<NpcDailyWorkRecord>();
            builder.Entity<PlayerAttributeRecord>();
            builder.Entity<HRLevelRecord>();
            builder.Entity<MonsterAttributeRecord>();

            // NPC Sale
            builder.Entity<NpcShopMappingRecord>();
            builder.Entity<ShopInfoRecord>();
            builder.Entity<RandomGroupRecord>();
            builder.Entity<RandomProductRecord>();
            builder.Entity<RandomPoolRecord>();

            // Pet
            builder.Entity<PetNameRecord>();
            builder.Entity<PetInfoRecord>();
            builder.Entity<PetFarewellGiftRecord>();
            builder.Entity<PetQualityRecord>();
            builder.Entity<PetPersonalityRecord>();
            builder.Entity<PetAttackTendencyRecord>();
            builder.Entity<PetAttackMethodRecord>();
            builder.Entity<PetSkinRecord>();
            builder.Entity<PetLevelRecord>();
            builder.Entity<PetSkillSlotUnlockRecord>();
            builder.Entity<PetAptitudeQualityRecord>();

            // Pet Skills
            builder.Entity<PetInnateSkillRecord>();
            builder.Entity<PetCombatSkillRecord>();
            builder.Entity<PetSupportSkillRecord>();
            builder.Entity<PetSkillTriggerRecord>();
            builder.Entity<PetProductionSkillRecord>();
            builder.Entity<PetProductionSkillEffectRecord>();

            // Monster
            builder.Entity<MonsterAbnormalStateRecord>();
            builder.Entity<MonsterEmotionRecord>();
            builder.Entity<MonsterLemonRecord>();
            builder.Entity<MonsterStateRecord>();
            builder.Entity<MonsterInfoRecord>();
            builder.Entity<MonsterPartRecord>();
            builder.Entity<MonsterPartDefenceRecord>();
            builder.Entity<MonsterPerceptionRecord>();

            // Init
            builder.Entity<InitAttributeRecord>();
            builder.Entity<InitItemRecord>();
            builder.Entity<InitQuickSupplyRecord>();
            builder.Entity<InitShortcutRecord>();
            builder.Entity<InitStoreRecord>();
        }
    }
}
