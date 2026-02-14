using Rathalos.Servers.World;

namespace Rathalos.UI.World
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
           await WorldStart.Start(args);
        }
    }
}
