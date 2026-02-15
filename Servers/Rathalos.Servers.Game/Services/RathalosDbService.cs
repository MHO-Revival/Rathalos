using Rathalos.Core.ORM;
using Rathalos.Servers.Base.Services;
using System.Linq.Expressions;

namespace Rathalos.Servers.World.Services
{
    /// <summary>
    /// Factory service for creating new RathalosDbContext instances.
    /// Uses IServiceScopeFactory to create properly scoped DbContext instances from singleton context.
    /// </summary>
    public class RathalosDbService : WarmupService<RathalosDbService>
    {
        private readonly IServiceScopeFactory _scopeFactory;

        public RathalosDbService(IServiceScopeFactory scopeFactory)
        {
            _scopeFactory = scopeFactory;
        }

        /// <summary>
        /// Executes a query against the database context and returns the results as an IQueryable of the specified
        /// type.
        /// </summary>
        /// <remarks>This method creates a new scope for the database context, ensuring that the query is
        /// executed within a proper service scope.</remarks>
        /// <typeparam name="T">The type of the records to query, which must inherit from BaseRecord.</typeparam>
        /// <param name="query">An expression that defines the criteria for filtering the records. This expression is applied to each record
        /// of type T.</param>
        /// <returns>An IQueryable<T> representing the filtered records that match the specified query criteria.</returns>
        public QueryContext<T> Query<T>(Expression<Func<T, bool>>? query = null)
            where T : BaseRecord
        {
            var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();
            return new(context, context.Query(query ?? (x => true)));
        }

        /// <summary>
        /// Executes a query against the database context and returns the results as an IQueryable of the specified
        /// type.
        /// </summary>
        /// <remarks>This method creates a new scope for the database context, ensuring that the query is
        /// executed within a proper service scope.</remarks>
        /// <typeparam name="T">The type of the records to query, which must inherit from BaseRecord.</typeparam>
        /// <param name="query">An expression that defines the criteria for filtering the records. This expression is applied to each record
        /// of type T.</param>
        /// <returns>An IQueryable<T> representing the filtered records that match the specified query criteria.</returns>
        public QueryContext<T> QueryNoTracking<T>(Expression<Func<T, bool>>? query = null)
            where T : BaseRecord
        {
            var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();
            return new (context, context.Query(query ?? (x => true), false));
        }

        /// <summary>
        /// Executes an action with a new DbContext instance.
        /// The DbContext is automatically disposed after the action completes.
        /// </summary>
        public void Execute(Action<RathalosDbContext> action)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();
            action(context);
        }

        /// <summary>
        /// Executes a function with a new DbContext instance and returns the result.
        /// The DbContext is automatically disposed after the function completes.
        /// </summary>
        public T Execute<T>(Func<RathalosDbContext, T> func)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();
            return func(context);
        }

        /// <summary>
        /// Executes an action within a database transaction.
        /// If the action completes successfully, the transaction is committed.
        /// If an exception occurs, the transaction is rolled back and the exception is rethrown.
        /// </summary>
        public void ExecuteInTransaction(Action<RathalosDbContext> action)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();

            using var transaction = context.Database.BeginTransaction();
            try
            {
                action(context);
                transaction.Commit();
            }
            catch
            {
                transaction.Rollback();
                throw;
            }
        }

        /// <summary>
        /// Executes a function within a database transaction and returns the result.
        /// If the function completes successfully, the transaction is committed.
        /// If an exception occurs, the transaction is rolled back and the exception is rethrown.
        /// </summary>
        public T ExecuteInTransaction<T>(Func<RathalosDbContext, T> func)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();

            using var transaction = context.Database.BeginTransaction();
            try
            {
                var result = func(context);
                transaction.Commit();
                return result;
            }
            catch
            {
                transaction.Rollback();
                throw;
            }
        }

        /// <summary>
        /// Executes an async action within a database transaction.
        /// If the action completes successfully, the transaction is committed.
        /// If an exception occurs, the transaction is rolled back and the exception is rethrown.
        /// </summary>
        public async Task ExecuteInTransactionAsync(Func<RathalosDbContext, Task> action)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();

            await using var transaction = await context.Database.BeginTransactionAsync();
            try
            {
                await action(context);
                await transaction.CommitAsync();
            }
            catch
            {
                await transaction.RollbackAsync();
                throw;
            }
        }

        /// <summary>
        /// Executes an async function within a database transaction and returns the result.
        /// If the function completes successfully, the transaction is committed.
        /// If an exception occurs, the transaction is rolled back and the exception is rethrown.
        /// </summary>
        public async Task<T> ExecuteInTransactionAsync<T>(Func<RathalosDbContext, Task<T>> func)
        {
            using var scope = _scopeFactory.CreateScope();
            var context = scope.ServiceProvider.GetRequiredService<RathalosDbContext>();

            await using var transaction = await context.Database.BeginTransactionAsync();
            try
            {
                var result = await func(context);
                await transaction.CommitAsync();
                return result;
            }
            catch
            {
                await transaction.RollbackAsync();
                throw;
            }
        }
    }
}
