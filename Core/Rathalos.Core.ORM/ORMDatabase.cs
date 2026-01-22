using Rathalos.Core.ORM.Attributes;
using Rathalos.Core.ORM.Config;
using Rathalos.Core.ORM.Interfaces;
using Rathalos.Core.Utils.Extensions;
using MongoDB.Bson;
using MongoDB.Bson.Serialization;
using MongoDB.Driver;
using Org.BouncyCastle.Asn1.X509.Qualified;
using System.Collections;
using System.Collections.Concurrent;
using System.Data;
using System.Linq.Expressions;
using System.Reflection;

namespace Rathalos.Core.ORM
{
    public sealed class ORMDatabase
    {
        private readonly ConcurrentDictionary<string, long> _typeLastIndex = new ConcurrentDictionary<string, long>();
        private IMongoDatabase _database;

        public ORMDatabase()
        {
        }

        public IMongoDatabase MongoDatabase => _database;

        public void Initialize(ORMConfiguration configuration)
        {
            _database = new MongoClient(configuration.GetConnectionString()).GetDatabase(configuration.DbName);
        }

        public void GetTransaction(Action action)
        {
            using (var session = _database.Client.StartSession())
            {
                session.StartTransaction();
                try
                {
                    action();
                    session.CommitTransaction();
                }
                catch
                {
                    session.AbortTransaction();
                    throw;
                }
            }
        }

        public int Count<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            return GetCollection<T>().AsQueryable().Count(expression);
        }

        public T FirstOrDefault<T>(Expression<Func<T, bool>> expression = null) where T : BaseRecord
        {
            var collection = GetCollection<T>().AsQueryable();
            if (expression == null)
                return collection.FirstOrDefault();

            return collection.FirstOrDefault(expression);
        }

        public IEnumerable<T> Fetch<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            return GetCollection<T>().AsQueryable().Where(expression);
        }

        public IEnumerable<T> Fetch<T>(Expression<Func<T, bool>> expression, int skip, int take) where T : BaseRecord
        {
            return GetCollection<T>().AsQueryable().Where(expression).Skip(skip).Take(take);
        }

        public IEnumerable<T> FetchAll<T>()
        {
            return GetCollection<T>().AsQueryable();
        }


        public IQueryable<T> Query<T>(Expression<Func<T, bool>> expression)
        {
            return GetCollection<T>().AsQueryable().Where(expression);
        }

        public ICollection<object> FetchAll(Type type)
        {
            return GetCollection(type)
                    .AsQueryable()
                    .ToArray()
                    .Select(_ => BsonSerializer.Deserialize(_, type))
                    .ToArray();
        }

        public bool Save<T>(T poco) where T : BaseRecord
        {
            if (FirstOrDefault<T>(_ => _.Id == poco.Id) == null)
                Insert(poco);
            else
                Update(poco);

            return true;
        }

        public bool SaveMany<T>(IEnumerable<T> pocos) where T : BaseRecord
        {
            foreach (var poco in pocos)
            {
                if (FirstOrDefault<T>(_ => _.Id == poco.Id) == null)
                    Insert(poco);
                else
                    Update(poco);
            }

            return true;
        }

        public T Insert<T>(T poco) where T : BaseRecord
        {
            var collection = GetCollection<T>();
            UpdatePoco(poco);

            if (poco is ISaveInterceptor saveIntercepter)
                saveIntercepter.BeforeSave(true);

            collection.InsertOne(poco);

            return poco;

        }

        public void InsertMany<T>(IEnumerable<T> pocos) where T : BaseRecord
        {
            if (pocos.Count() <= 0)
                return;

            var collection = GetCollection<T>();

            Parallel.ForEach(pocos, poco =>
            {
                UpdatePoco(poco);
                if (poco is ISaveInterceptor saveIntercepter)
                    saveIntercepter.BeforeSave(true);
            });

            collection.InsertMany(pocos);
        }

        public bool Update<T>(T poco) where T : BaseRecord
        {
            var collection = GetCollection<T>();
            UpdatePoco(poco);

            if (poco is ISaveInterceptor saveIntercepter)
                saveIntercepter.BeforeSave(false);

            FilterDefinitionBuilder<T> eqfilter = Builders<T>.Filter;
            FilterDefinition<T> eqFilterDefinition = eqfilter.Eq(x => x.Id, poco.Id);

            var result = collection.ReplaceOne(eqFilterDefinition, poco);
            return result.ModifiedCount > 0;
        }

        public bool Update(Type type, object poco, Expression<Func<BsonDocument, bool>> expression)
        {
            var collection = GetCollection(type);

            if (poco is ISaveInterceptor saveIntercepter)
                saveIntercepter.BeforeSave(false);

            var result = collection.ReplaceOne(expression, BsonDocument.Create(poco));
            return result.ModifiedCount > 0;
        }

        public bool Delete<T>(T poco) where T : BaseRecord
        {
            var collection = GetCollection<T>();

            var result = collection.DeleteOne(_ => _.Id == poco.Id);
            return result.DeletedCount > 0;

        }

        public bool Delete<T>(Expression<Func<T, bool>> expression) where T : BaseRecord
        {
            var collection = GetCollection<T>();

            var result = collection.DeleteMany(expression);
            return result.DeletedCount > 0;
        }

        public void EmptyCollection<T>() where T : BaseRecord
        {
            Delete<T>(_ => true);
        }

        public void EmptyCollection(Type type)
        {
            var collection = GetCollection(type);
            collection.DeleteMany(_ => true);
        }

        private void UpdatePoco<T>(T poco) where T : BaseRecord
        {
            if (poco.Id == 0)
                poco.Id = ++_typeLastIndex[poco.GetType().Name];

            poco.LastTimeModified = DateTime.Now;
        }

        private bool IsCollectionExists(string name)
        {
            var filter = new BsonDocument("name", BsonValue.Create(name));
            //filter by collection name
            var collections = _database.ListCollectionNames(new ListCollectionNamesOptions { Filter = filter });
            //check for existence
            return collections.Any();
        }

        private IMongoCollection<T> GetCollection<T>()
        {
            Type type = typeof(T);
            if (!type.HasCustomAttribute<CollectionNameAttribute>())
                throw new Exception("This class record doesn't have CollectionNameAttribute as attribute, you can't use it to retrieve collection !");

            var attribute = type.GetCustomAttribute<CollectionNameAttribute>();

            if (!_typeLastIndex.ContainsKey(type.Name))
            {
                var collection = _database.GetCollection<BsonDocument>(attribute.Name).AsQueryable();
                long lastId = 0;
                if (collection.Any())
                    lastId = collection.Max(x => (long)x["_id"]);

                _typeLastIndex.TryAdd(type.Name, lastId);
            }


            GenerateCollection(type);

            return _database.GetCollection<T>(attribute.Name);
        }

        private IMongoCollection<BsonDocument> GetCollection(Type type)
        {
            if (!type.HasCustomAttribute<CollectionNameAttribute>())
                throw new Exception("This class record doesn't have CollectionNameAttribute as attribute, you can't use it to retrieve collection !");

            var attribute = type.GetCustomAttribute<CollectionNameAttribute>();

            if (!_typeLastIndex.ContainsKey(type.Name))
            {
                var collection = _database.GetCollection<BsonDocument>(attribute.Name).AsQueryable();
                long lastId = 0;
                try { lastId = collection.Max(x => (long)x["_id"]); } catch { }
                _typeLastIndex.TryAdd(type.Name, lastId);
            }


            GenerateCollection(type);

            return _database.GetCollection<BsonDocument>(attribute.Name);
        }


        private void GenerateCollection(Type type)
        {
            if (type.HasCustomAttribute<CollectionNameAttribute>())
            {
                var collectionName = type.GetCustomAttribute<CollectionNameAttribute>()!.Name;
                if (!IsCollectionExists(collectionName))
                {
                    _database.CreateCollection(collectionName);

                    var propsIndexes = type.GetProperties().Where(_ => _.GetCustomAttribute<IndexAttribute>() is not null || _.GetCustomAttribute<PrimaryKeyAttribute>() is not null);
                    foreach (var index in propsIndexes)
                    {
                        var collection = _database.GetCollection<BsonDocument>(collectionName);
                        var indexKeysDefine = Builders<BsonDocument>.IndexKeys.Ascending(indexKey => indexKey[index.Name]);
                        collection.Indexes.CreateOne(new CreateIndexModel<BsonDocument>(indexKeysDefine, new CreateIndexOptions { Unique = index.GetCustomAttribute<PrimaryKeyAttribute>() is not null }));
                    }
                }
            }
        }

    }
}
