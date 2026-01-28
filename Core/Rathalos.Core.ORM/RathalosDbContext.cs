using Microsoft.EntityFrameworkCore;
using Rathalos.Core.ORM.Config;
using Rathalos.Core.ORM.Interfaces;
using System.Collections.Concurrent;
using System.Linq.Expressions;

namespace Rathalos.Core.ORM
{
    public sealed class RathalosDbContext : DbContext
    {
        private readonly ConcurrentDictionary<string, bool> _ensuredTables = new();
        private static readonly HashSet<Type> _registeredTypes = new();

        public RathalosDbContext(DbContextOptions<RathalosDbContext> options) : base(options)
        {
            // Ensure the database exists
            Database.EnsureCreated();
        }

        public void RegisterEntityType<T>() where T : BaseRecord
        {
            var type = typeof(T);
            if (!_registeredTypes.Contains(type))
            {
                _registeredTypes.Add(type);
            }
        }

        public void GetTransaction(Action action)
        {
            using var transaction = Database.BeginTransaction();
            try
            {
                action();
                transaction.Commit();
            }
            catch
            {
                transaction.Rollback();
                throw;
            }
        }

        public IQueryable<T> Query<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            return Set<T>().Where(expression);
        }

        public ICollection<object> FetchAll(Type type)
        {
            var method = typeof(DbContext).GetMethod(nameof(Set), Type.EmptyTypes)!.MakeGenericMethod(type);
            var dbSet = method.Invoke(this, null) as IQueryable<object>;
            return dbSet?.ToList() ?? new List<object>();
        }

        public T Insert<T>(T poco) where T : BaseRecord
        {
            UpdatePoco(poco);

            if (poco is ISaveInterceptor saveInterceptor)
                saveInterceptor.BeforeSave(true);

            Set<T>().Add(poco);
            SaveChanges();

            return poco;
        }

        public void InsertMany<T>(IEnumerable<T> pocos) where T : BaseRecord
        {
            if (!pocos.Any())
                return;

            foreach (var poco in pocos)
            {
                UpdatePoco(poco);
                if (poco is ISaveInterceptor saveInterceptor)
                    saveInterceptor.BeforeSave(true);
            }

            Set<T>().AddRange(pocos);
            SaveChanges();
        }

        public bool Update<T>(T poco) where T : BaseRecord
        {
            UpdatePoco(poco);

            if (poco is ISaveInterceptor saveInterceptor)
                saveInterceptor.BeforeSave(false);

            var entry = Entry(poco);
            if (entry.State == EntityState.Detached)
            {
                Set<T>().Attach(poco);
                entry.State = EntityState.Modified;
            }

            return SaveChanges() > 0;
        }

        public bool UpdateMany<T>(IEnumerable<T> pocos) where T : BaseRecord
        {
            if (!pocos.Any())
                return false;

            foreach (var poco in pocos)
            {
                UpdatePoco(poco);
                if (poco is ISaveInterceptor saveInterceptor)
                    saveInterceptor.BeforeSave(true);

                var entry = Entry(poco);
                if (entry.State == EntityState.Detached)
                {
                    Set<T>().Attach(poco);
                    entry.State = EntityState.Modified;
                }
            }


            return SaveChanges() > 0;
        }


        public bool Delete<T>(T poco) where T : BaseRecord
        {
            Set<T>().Remove(poco);
            return SaveChanges() > 0;
        }

        public bool Delete<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            var entities = Set<T>().Where(expression).ToList();
            Set<T>().RemoveRange(entities);
            return SaveChanges() > 0;
        }

        public void EmptyCollection<T>() where T : BaseRecord
        {
            Delete<T>(_ => true);
        }

        public void EmptyCollection(Type type)
        {
            var method = typeof(DbContext).GetMethod(nameof(Set), Type.EmptyTypes)!.MakeGenericMethod(type);
            var dbSet = method.Invoke(this, null);

            var removeRangeMethod = dbSet!.GetType().GetMethod("RemoveRange", [typeof(IEnumerable<>).MakeGenericType(type)]);
            var toListMethod = typeof(Enumerable).GetMethod("ToList")!.MakeGenericMethod(type);
            var entities = toListMethod.Invoke(null, [dbSet]);

            removeRangeMethod?.Invoke(dbSet, [entities]);
            SaveChanges();
        }

        private void UpdatePoco<T>(T poco) where T : BaseRecord
        {
            poco.LastTimeModified = DateTime.UtcNow;
        }
    }
}
