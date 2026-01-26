using Rathalos.Core.ORM;
using Rathalos.Core.ORM.Config;
using Microsoft.Extensions.Options;
using System.Linq.Expressions;

namespace Rathalos.Servers.Base.Services
{
	public class DatabaseService : WarmupService<DatabaseService>
	{
		protected readonly ORMDatabase database;

		public DatabaseService(ORMDatabase database)
		{
			this.database = database;
		}

		public ORMDatabase ORM => database;

		public int Count<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
		{
			return database.Count(expression);
		}

		public T FirstOrDefault<T>(Expression<Func<T, bool>> expression = null) where T : BaseRecord
		{
			return database.FirstOrDefault(expression);
		}

        public IEnumerable<T> Fetch<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
		{
			return database.Fetch(expression);
		}

		public IEnumerable<T> Fetch<T>(Expression<Func<T, bool>> expression, int limit, int offset = 0) where T : BaseRecord
		{
			return database.Fetch(expression, offset, limit);
        }

        public IEnumerable<T> FetchAll<T>() where T : BaseRecord
		{
			return database.FetchAll<T>();
		}

        public IQueryable<T> Query<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            return database.Query(expression);
        }

        public bool Save<T>(T poco) where T : BaseRecord
		{
			return database.Save(poco);
		}

		public T Insert<T>(T poco) where T : BaseRecord
		{
			return database.Insert(poco);
		}

		public void InsertMany<T>(IEnumerable<T> poco) where T : BaseRecord
		{
			database.InsertMany(poco);
		}

		public bool Update<T>(T poco) where T : BaseRecord
		{
			return database.Update(poco);
		}

		public bool Delete<T>(T poco) where T : BaseRecord
		{
			return database.Delete(poco);
		}

		public void EmptyCollection<T>() where T : BaseRecord
		{
			database.EmptyCollection<T>();
		}

    }
}
