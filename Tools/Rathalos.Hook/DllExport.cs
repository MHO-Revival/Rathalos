using Rathalos.CLI.Launcher.MhoLauncher;
using System.Runtime.InteropServices;

namespace Rathalos.Hook
{
    public static class DllEntry
    {
        // Constants for fdw_reason
        private const uint DLL_PROCESS_ATTACH = 1;
        private const uint DLL_THREAD_ATTACH = 2;
        private const uint DLL_THREAD_DETACH = 3;
        private const uint DLL_PROCESS_DETACH = 0;

        // "DllExport" attribute makes this function visible to Windows as a native export
        [DllExport("DllMain", CallingConvention = CallingConvention.StdCall)]
        public static bool DllMain(IntPtr hModule, uint ul_reason_for_call, IntPtr lpReserved)
        {
            switch (ul_reason_for_call)
            {
                case DLL_PROCESS_ATTACH:
                    // Equivalent to: new std::thread(run);
                    // We start a generic Thread to break out of the "Loader Lock"
                    new Thread(MhoMod.Run).Start();
                    break;

                case DLL_THREAD_ATTACH:
                case DLL_THREAD_DETACH:
                    break;

                case DLL_PROCESS_DETACH:
                    // Perform cleanup
                    // Note: We don't have direct access to "is_running" here unless you make it public static
                    // MhoMod.IsRunning = false; 
                    break;
            }
            return true;
        }
    }
}
