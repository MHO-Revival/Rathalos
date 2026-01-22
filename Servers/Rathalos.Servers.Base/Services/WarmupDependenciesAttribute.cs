namespace Rathalos.Servers.Base.Services
{
	[AttributeUsage(AttributeTargets.Class)]
	public sealed class WarmupDependenciesAttribute : Attribute
	{
		public WarmupDependenciesAttribute(params Type[] typeDependancies)
		{
			TypeDependancies = typeDependancies;
		}

		public Type[] TypeDependancies { get; }
	}
}
