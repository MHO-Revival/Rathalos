using Rathalos.Core.Protocol.Messages.Tqqapi;
using System.Linq.Expressions;
using System.Reflection;

namespace Rathalos.Core.Protocol.Messages
{
    public static class ProtocolTypeManager
    {
        private static Dictionary<Type,Dictionary<ushort, Func<object>>> _typesData = [];

        public static void Initialize()
        {
            Assembly asm = Assembly.GetAssembly(typeof(Version));

            foreach (Type type in asm.GetTypes().Where(x => !x.IsAbstract && !x.IsInterface))
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

                    _typesData[field.FieldType].Add(id, funcCtor);
                }
            }
        }

        public static TOut Get<TOut>(object value)
            where TOut : class
        {
            if (_typesData.TryGetValue(value.GetType(), out var dict))
            {
                if (dict.TryGetValue(Convert.ToUInt16(value), out var ctor))
                {
                    return ctor() as TOut;
                }
                throw new Exception(string.Format("Type id '{0}' not found for '{1}'", value, value.GetType().Name));

            }
            else
            {
                throw new Exception(string.Format("Type '{0}' not found", value.GetType().Name));
            }
        }
    }
}
