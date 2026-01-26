using Rathalos.Core.Protocol.Messages.Tqqapi;
using System.Linq.Expressions;
using System.Reflection;

namespace Rathalos.Core.Protocol.Messages
{
    public static class ProtocolTypeManager
    {
        private static Dictionary<string, Dictionary<int, Func<object>>> _typesData = [];

        public static void Initialize()
        {
            Assembly asm = Assembly.GetAssembly(typeof(TPDUExtAuthInfo));

            foreach (Type type in asm.GetTypes().Where(x => !x.IsAbstract && !x.IsInterface))
            {
                FieldInfo field = type.GetField(nameof(TPDUExtAuthInfo.ProtocolIdConst));

                if (field != null)
                {
                    int id = (int)field.GetValue(type);

                    ConstructorInfo ctor = type.GetConstructor(Type.EmptyTypes);

                    if (ctor == null)
                        throw new Exception(string.Format("'{0}' doesn't implemented a parameterless constructor", type));

                    var typeKey = type.GetInterfaces().FirstOrDefault().Name + "_" + field.FieldType.Name;

                    var funcCtor = Expression.Lambda<Func<object>>(Expression.New(ctor)).Compile();
                    if(!_typesData.TryGetValue(typeKey, out var dict))
                    {
                        _typesData.Add(typeKey, []);
                    }

                    _typesData[typeKey].Add(id, funcCtor);
                }
            }
        }

        public static TOut Get<TOut>(object value)
            where TOut : class
        {
            var typeKey = typeof(TOut).Name + "_" + value.GetType().Name;
            if (_typesData.TryGetValue(typeKey, out var dict))
            {
                if (dict.TryGetValue(Convert.ToInt32(value), out var ctor))
                {
                    return ctor() as TOut;
                }
            }

            return null;
        }
    }
}
