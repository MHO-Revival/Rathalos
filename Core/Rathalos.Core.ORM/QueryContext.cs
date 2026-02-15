using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Query;
using System.Linq.Expressions;

namespace Rathalos.Core.ORM
{
    public sealed class QueryContext<T>
        where T : BaseRecord
    {
        private RathalosDbContext _context;
        private IQueryable<T> _query;

        public QueryContext(RathalosDbContext context, IQueryable<T> query)
        {
            _context = context;
            _query = query;
        }

        public QueryContext<T> Where(Expression<Func<T, bool>> predicate)
        {
            _query = _query.Where(predicate);
            return this;
        }

        public QueryContext<T> OrderBy<TKey>(Expression<Func<T, TKey>> keySelector)
        {
            _query = _query.OrderBy(keySelector);
            return this;
        }

        public QueryContext<T> OrderByDescending<TKey>(Expression<Func<T, TKey>> keySelector)
        {
            _query = _query.OrderByDescending(keySelector);
            return this;
        }

        public QueryContext<T> Take(int count)
        {
            _query = _query.Take(count);
            return this;
        }
        public QueryContext<T> Skip(int count)
        {
            _query = _query.Skip(count);
            return this;
        }

        public QueryContext<T> Include<TProperty>(Expression<Func<T, TProperty>> navigationPropertyPath)
        {
            _query = _query.Include(navigationPropertyPath);
            return this;
        }

        public QueryContext<T> ThenInclude<TPreviousProperty, TProperty>(Expression<Func<TPreviousProperty, TProperty>> navigationPropertyPath)
        {
            if (_query is IIncludableQueryable<T, TPreviousProperty> includable)
            {
                _query = includable.ThenInclude(navigationPropertyPath);
            }
            return this;
        }

        public QueryContext<T> AsNoTracking()
        {
            _query = _query.AsNoTracking();
            return this;
        }

        public List<T> ToList()
        {
            using var context = _context;
            return _query.ToList();
        }

        public T FirstOrDefault(Expression<Func<T, bool>> predicate = null)
        {
            using var context = _context;

            if (predicate is null)
                return _query.FirstOrDefault();
            return _query.FirstOrDefault(predicate);
        }

        public T LastOrDefault(Expression<Func<T, bool>> predicate = null)
        {
            using var context = _context;

            if (predicate is null)
                return _query.LastOrDefault();
            return _query.LastOrDefault(predicate);
        }

        public Dictionary<TKey, T> ToDictionary<TKey>(Func<T, TKey> keySelector)
        {
            using var context = _context;

            return _query.ToDictionary(keySelector);
        }

        public int Count(Expression<Func<T, bool>> predicate = null)
        {
            using var context = _context;

            if (predicate is null)
                return _query.Count();
            return _query.Count(predicate);
        }

        public async Task<List<T>> ToListAsync(CancellationToken cancellationToken = default)
        {
            await using var context = _context;

            return await _query.ToListAsync(cancellationToken);
        }

        public async Task<T> FirstOrDefaultAsync(Expression<Func<T, bool>> predicate = null, CancellationToken cancellationToken = default)
        {
            await using var context = _context;

            if (predicate is null)
                return await _query.FirstOrDefaultAsync(cancellationToken);
            return await _query.FirstOrDefaultAsync(predicate, cancellationToken);
        }

        public async Task<T> LastOrDefaultAsync(Expression<Func<T, bool>> predicate = null, CancellationToken cancellationToken = default)
        {
            await using var context = _context;

            if (predicate is null)
                return await _query.LastOrDefaultAsync(cancellationToken);
            return await _query.LastOrDefaultAsync(predicate, cancellationToken);
        }

        public async Task<Dictionary<TKey, T>> ToDictionaryAsync<TKey>(Func<T, TKey> keySelector, CancellationToken cancellationToken = default)
        {
            await using var context = _context;
            return await _query.ToDictionaryAsync(keySelector, cancellationToken);
        }

        public async Task<int> CountAsync(Expression<Func<T, bool>> predicate = null, CancellationToken cancellationToken = default)
        {
            await using var context = _context;

            if(predicate is null)
                return await _query.CountAsync(cancellationToken);
            return await _query.CountAsync(predicate, cancellationToken);
        }
    }
}
