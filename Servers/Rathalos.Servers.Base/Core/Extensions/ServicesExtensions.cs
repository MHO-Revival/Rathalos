using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;
using Rathalos.Core.ORM;
using Rathalos.Core.Utils.Extensions;
using Rathalos.Servers.Base.Handlers;
using Rathalos.Servers.Base.Services;
using System.Reflection;
using System.Runtime;

namespace Rathalos.Servers.Base.Core.Extensions
{
	public static class ServicesExtensions
	{
        public static IServiceCollection AddMhoServices(this IServiceCollection services, Assembly asm)
		{
			var types = asm.GetTypes()
							.Where(_ => _.HasInterface<IMessageHandler>() && !_.IsAbstract);

			foreach (var type in types)
			{
				services.AddSingleton(type);
			}

			return services;
		}

		public static IServiceCollection AddBaseServices(this IServiceCollection services, Assembly asm)
		{
			GCSettings.LatencyMode = GCSettings.IsServerGC ? GCLatencyMode.Batch : GCLatencyMode.Interactive;

			ConfigureWarmupServices(services, asm);

			return services
				.AddSingleton<ORMDatabase>();
		}

		private static void ConfigureWarmupServices(IServiceCollection services, Assembly asm)
		{
			var types = Assembly.GetExecutingAssembly().GetTypes().Concat(asm.GetTypes())
							.Where(_ => _.IsAssignableTo(typeof(IWarmupService)) && !_.IsAbstract);

			foreach (var type in types)
			{
				services.AddSingleton(type, (provider) =>
				{
					var ctorParams = type.GetConstructors().FirstOrDefault()?.GetParameters();
					var inst = ctorParams?.Select(_ =>
					{
						return provider.GetService(_.ParameterType);
					}).ToArray();

					var factory = provider.GetRequiredService<ILoggerFactory>();
					var logger = factory.CreateLogger("Services");
					logger.LogInformation($"Initialize {type.Name}...");

					return ActivatorUtilities.CreateInstance(provider, type, inst);
				});
			}
		}

		public static IEnumerable<ISaveService> WarmUp(this IServiceProvider provider, params Assembly[] additionalAssemblies)
		{
			if (provider == null)
                return [];

			var loggerFactory = provider.GetRequiredService<ILoggerFactory>();
			var logger = loggerFactory.CreateLogger("Warmup");

			var types = Assembly.GetExecutingAssembly()
                .GetTypes()
				.Concat(Assembly.GetCallingAssembly().GetTypes())
				.Concat(additionalAssemblies.SelectMany(a => a.GetTypes()))
                .Where(_ => _.IsAssignableTo(typeof(IWarmupService)) && !_.IsAbstract);

			List<ISaveService> saveServices = new List<ISaveService>();
			foreach (var type in types)
			{
				var service = WarmupService(provider, type, logger);
				if(service is ISaveService saveService)
					saveServices.Add(saveService);
			}
			return saveServices;
		}

		private static IWarmupService WarmupService(IServiceProvider provider, Type type, ILogger logger)
		{
			if (type.HasCustomAttribute<WarmupDependenciesAttribute>())
			{
				var dependancies = type.GetCustomAttribute<WarmupDependenciesAttribute>().TypeDependancies ?? Array.Empty<Type>();

				foreach (var dependancy in dependancies)
				{
					WarmupService(provider, dependancy, logger);
				}
			}

			var instanceProp = typeof(WarmupService<>).MakeGenericType(type).GetProperty("Instance");
			if (instanceProp is null)
				throw new Exception($"The service {type.Name} doesn't inherit from WarmupService !");

			if (instanceProp.GetValue(null) is not null)
				return null;

			var service = provider.GetService(type) as IWarmupService;

			var setInstanceMethod = type.GetMethod("SetInstance") ?? throw new Exception($"There is no method named 'SetInstance' inside the class '{type.Name}' or its base classes.");
			setInstanceMethod.Invoke(service, new[] { service });

			try
			{
				service.Initialize();
				return service;
			}
			catch (Exception ex)
			{
				logger.LogError($"An error occured on initialization of the service {type.Name} : {ex.Message}\nStacktrace : {ex.StackTrace}");
			}

			return null;
		}
	}
}
