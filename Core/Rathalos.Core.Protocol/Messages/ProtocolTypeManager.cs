using System.Linq.Expressions;
using System.Reflection;

namespace Rathalos.Core.Protocol.Messages
{
    public static class ProtocolTypeManager
    {
        private static Dictionary<Type,Dictionary<ushort, Type>> _typesData = [];

        public static void Initialize()
        {
            Assembly asm = Assembly.GetAssembly(typeof(Version));

            foreach (Type type in asm.GetTypes())
            {
                FieldInfo field = type.GetField(nameof(TPDUExtAuthInfo.ProtocolId));

                if (field != null && field.FieldType == typeof(short))
                {
                    ushort id = (ushort)field.GetValue(type);

                    ConstructorInfo ctor = type.GetConstructor(Type.EmptyTypes);

                    if (ctor == null)
                        throw new Exception(string.Format("'{0}' doesn't implemented a parameterless constructor", type));

                    var funcCtor = Expression.Lambda<Func<object>>(Expression.New(ctor)).Compile();
                    if(!_typesData.TryGetValue(field.FieldType, out var dict))
                    {
                        _typesData.Add(field.FieldType, []);
                    }

                    _typesData[field.FieldType].Add(id, type);
                }
            }
        }

        public static TOut Get<TData, TOut>(TData value)
            where TOut : class, new()
            where TData : struct
        {
            if (_typesData.TryGetValue(typeof(TData), out var dict))
            {
                if (dict.TryGetValue(Convert.ToUInt16(value), out var type))
                {
                    return Activator.CreateInstance(type) as TOut;
                }
                throw new Exception(string.Format("Type id '{0}' not found for '{1}'", value, typeof(TData).Name));

            }
            else
            {
                throw new Exception(string.Format("Type '{0}' not found", typeof(TData).Name));
            }
        }
    }
}
