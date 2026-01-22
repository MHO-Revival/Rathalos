namespace Rathalos.CLI.Menu
{
    /// <summary>
    /// Interface for menu option handlers
    /// </summary>
    public interface IMenuOption
    {
        /// <summary>
        /// Display name for the menu option
        /// </summary>
        string DisplayName { get; }

        /// <summary>
        /// Execute the menu option handler
        /// </summary>
        /// <returns>True to continue the menu, false to exit</returns>
        Task<bool> ExecuteAsync();
    }
}