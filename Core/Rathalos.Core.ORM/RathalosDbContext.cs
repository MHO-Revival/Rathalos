using Microsoft.EntityFrameworkCore;
using Rathalos.Core.ORM.Extensions;
using Rathalos.Core.ORM.Interfaces;
using System.Linq.Expressions;

namespace Rathalos.Core.ORM
{
    public sealed class RathalosDbContext : DbContext
    {
        private static readonly HashSet<Type> _registeredTypes = new();
        private readonly Action<ModelBuilder> _configure;

        public RathalosDbContext(DbContextOptions<RathalosDbContext> options) : base(options)
        {
            var ext = options.GetExtension<DatabaseConfigurationExtension>();
            _configure = ext.ConfigureBuilder;
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            _configure?.Invoke(modelBuilder);
            base.OnModelCreating(modelBuilder);
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

        public IQueryable<T> Query<T>(Expression<Func<T, bool>> expression, bool isTracking = true) where T : BaseRecord
        {
            return isTracking 
                ? Set<T>().Where(expression) 
                : Set<T>().AsNoTracking().Where(expression);
        }

        public IQueryable<T> QueryAll<T>(bool isTracking) where T : BaseRecord
        {
            return isTracking 
                ? Set<T>().AsQueryable()
                : Set<T>().AsNoTracking().AsQueryable();
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
