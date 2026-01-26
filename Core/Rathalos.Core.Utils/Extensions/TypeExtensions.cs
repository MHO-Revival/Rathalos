using System.Collections;
using System.Linq.Expressions;
using System.Reflection;
using System.Reflection.Emit;

namespace Rathalos.Core.Utils.Extensions
{
	public static class TypeExtensions
	{
		public static bool IsCollection(this Type type)
		{
			return (typeof(IEnumerable).IsAssignableFrom(type)
				|| typeof(IEnumerable<>).IsAssignableFrom(type)) && type != typeof(string);
		}
		public static bool HasInterface<T>(this Type type)
		{
			return type != null && type != typeof(T) && type.IsAssignableTo(typeof(T));
		}
		public static bool IsSubclassOfGeneric(this Type type, Type genericType)
		{
			var t = type.BaseType;

			while (t != null && !t.IsValueType)
			{
				if (t.IsGenericType && t.GetGenericTypeDefinition() == genericType)
					return true;

				t = t.BaseType;
			}

			return false;
		}

		public static bool HasCustomAttribute<TAttribute>(this Type type)
			where TAttribute : Attribute
		{
			return type?.GetCustomAttributes<TAttribute>()?.Any() ?? false;
		}

		public static bool HasCustomAttribute<TAttribute>(this MethodInfo method)
			where TAttribute : Attribute
		{
			return method?.GetCustomAttributes<TAttribute>()?.Any() ?? false;
		}

		public static bool HasCustomAttribute<TAttribute>(this FieldInfo field)
			where TAttribute : Attribute
		{
			return field?.GetCustomAttributes<TAttribute>()?.Any() ?? false;
		}

		public static T CreateDelegate<T>(this ConstructorInfo ctor)
		{
			var parameters = ctor.GetParameters().Select(param => Expression.Parameter(param.ParameterType)).ToList();

			var lamba = Expression.Lambda<T>(Expression.New(ctor, parameters), parameters);
			return lamba.Compile();
		}

		public static Func<object, TFirst, TSecond, TResult> CreateDelegate<TFirst, TSecond, TResult>(this MethodInfo method)
		{
			var returnType = typeof(TResult);

			var methodParameters = method.GetParameters()
										 .Select(p => p.ParameterType)
										 .ToArray();

			var delegateParameters = new[] { typeof(TFirst), typeof(TSecond) };

			var finalParameters = new[] { typeof(object) }.Concat(delegateParameters)
														  .ToArray();

			var dynamicMethod = new DynamicMethod(string.Empty, returnType, finalParameters, true);
			var generator = dynamicMethod.GetILGenerator();

			if (!method.IsStatic)
			{
				generator.Emit(OpCodes.Ldarg_0);
				generator.Emit(
					method.DeclaringType!.IsClass
						? OpCodes.Castclass
						: OpCodes.Unbox, method.DeclaringType);
			}

			for (var i = 0; i < delegateParameters.Length; i++)
			{
				generator.Emit(OpCodes.Ldarg, i + 1);

				var methodParameter = methodParameters[i];
				var delegateParameter = delegateParameters[i];

				if (delegateParameter == methodParameter)
					continue;

				if (!methodParameter.IsAssignableTo(delegateParameter))
					throw new InvalidCastException($"Cannot cast {delegateParameter.Name} to {methodParameter.Name}.");

				generator.Emit(
					methodParameter.IsClass
						? OpCodes.Castclass
						: OpCodes.Unbox, methodParameter);
			}

			generator.Emit(OpCodes.Call, method);

			if (returnType != method.ReturnType)
			{
				if (!method.ReturnType.IsSubclassOf(returnType) && !method.ReturnType.IsAssignableTo(returnType))
					throw new InvalidCastException($"Cannot cast {method.ReturnType.Name} to {returnType.Name}.");
				if (method.ReturnType.IsClass && returnType.IsClass)
					generator.Emit(OpCodes.Castclass, returnType);
				else if (returnType == typeof(object))
					generator.Emit(OpCodes.Box, method.ReturnType);
				else if (method.ReturnType.IsClass)
					generator.Emit(OpCodes.Unbox, returnType);
			}

			generator.Emit(OpCodes.Ret);

			return dynamicMethod.CreateDelegate<Func<object, TFirst, TSecond, TResult>>();
		}

		public static Func<object, TFirst, TResult> CreateDelegate<TFirst, TResult>(this MethodInfo method)
		{
			var returnType = typeof(TResult);

			var methodParameters = method.GetParameters()
										 .Select(p => p.ParameterType)
										 .ToArray();

			var delegateParameters = new[] { typeof(TFirst) };

			var finalParameters = new[] { typeof(object) }.Concat(delegateParameters)
														  .ToArray();

			var dynamicMethod = new DynamicMethod(string.Empty, returnType, finalParameters, true);
			var generator = dynamicMethod.GetILGenerator();

			if (!method.IsStatic)
			{
				generator.Emit(OpCodes.Ldarg_0);
				generator.Emit(
					method.DeclaringType!.IsClass
						? OpCodes.Castclass
						: OpCodes.Unbox, method.DeclaringType);
			}

			for (var i = 0; i < delegateParameters.Length; i++)
			{
				generator.Emit(OpCodes.Ldarg, i + 1);

				var methodParameter = methodParameters[i];
				var delegateParameter = delegateParameters[i];

				if (delegateParameter == methodParameter)
					continue;

				if (!methodParameter.IsSubclassOf(delegateParameter) && methodParameter.IsAssignableTo(delegateParameter))
					throw new InvalidCastException($"Cannot cast {delegateParameter.Name} to {methodParameter.Name}.");

				generator.Emit(
					methodParameter.IsClass
						? OpCodes.Castclass
						: OpCodes.Unbox, methodParameter);
			}

			generator.Emit(OpCodes.Call, method);

			if (returnType != method.ReturnType)
			{
				if (!method.ReturnType.IsSubclassOf(returnType) && !method.ReturnType.IsAssignableTo(returnType))
					throw new InvalidCastException($"Cannot cast {method.ReturnType.Name} to {returnType.Name}.");
				if (method.ReturnType.IsClass && returnType.IsClass)
					generator.Emit(OpCodes.Castclass, returnType);
				else if (returnType == typeof(object))
					generator.Emit(OpCodes.Box, method.ReturnType);
				else if (method.ReturnType.IsClass)
					generator.Emit(OpCodes.Unbox, returnType);
			}

			generator.Emit(OpCodes.Ret);

			return dynamicMethod.CreateDelegate<Func<object, TFirst, TResult>>();
		}

		public static bool CompareCollection<T>(this IEnumerable<T> source, IEnumerable<T> sourceToCompare)
		{
			if (source.Count() != sourceToCompare.Count())
				return false;

			bool flag = true;
			for (int i = 0; i < source.Count(); i++)
			{
				flag = flag && source.ElementAt(i).Compare(sourceToCompare.ElementAt(i));
			}

			return flag;
		}
		public static bool Compare<T>(this T obj, T objToCompare)
		{
			if (obj.GetType() != objToCompare.GetType())
				return false;

			// Get all the properties of the object
			PropertyInfo[] properties = obj.GetType().GetProperties();

			// Set the properties on the clone to be the same as the properties on the original object
			bool flag = true;
			foreach (PropertyInfo property in properties)
			{
				var val = property.GetValue(obj);
				flag = val is null
					? flag && (val == property.GetValue(objToCompare))
					: flag && val.Equals(property.GetValue(objToCompare));

			}

			// Get all the properties of the object
			var fields = obj.GetType().GetFields();

			// Set the properties on the clone to be the same as the properties on the original object
			foreach (var field in fields)
			{
				var val = field.GetValue(obj);

				flag = val is null
					? flag && (val == field.GetValue(objToCompare))
					: flag && val.Equals(field.GetValue(objToCompare));
			}

			return flag;
		}

		public static T DeepClone<T>(this T obj, bool withListItems = false) where T : class
		{
			// If the object is a value type, we don't need to clone it since value types are immutable
			if (obj.GetType().IsValueType)
			{
				return obj;
			}

			// Create a new instance of the object's type
			T clone = (T)Activator.CreateInstance(obj.GetType());

			// Get all the fields of the object
			FieldInfo[] fields = obj.GetType().GetFields();

			// Set the fields on the clone to be the same as the fields on the original object
			foreach (FieldInfo field in fields)
			{
				// Get the value of the field on the original object
				object value = field.GetValue(obj);

				// If the field is a reference type, we need to clone it recursively
				if (value != null && field.FieldType.IsCloneableInternally())
				{
					value = DeepClone(value);
				}

				if (field.FieldType.IsCollection())
				{
					value = (value as IEnumerable).CloneCollection(withListItems);
				}

				// Set the value of the field on the clone
				field.SetValue(clone, value);
			}

			// Get all the properties of the object
			PropertyInfo[] properties = obj.GetType().GetProperties();

			// Set the properties on the clone to be the same as the properties on the original object
			foreach (PropertyInfo property in properties)
			{
				// Make sure the property is readable and writable
				if (property.CanRead && property.CanWrite)
				{
					// Get the value of the property on the original object
					object value = property.GetValue(obj);

					// If the property is a reference type, we need to clone it recursively
					if (value != null && property.PropertyType.IsCloneableInternally())
					{
						value = DeepClone(value);
					}

					if (property.PropertyType.IsCollection())
					{
						value = (value as IEnumerable).CloneCollection(withListItems);
					}

					// Set the value of the property on the clone
					property.SetValue(clone, value);
				}
			}

			return clone;
		}

		private static bool IsCloneableInternally(this Type type)
		{
			return type.IsClass && !type.IsValueType && type != typeof(string) && !type.IsCollection();
		}

		public static IEnumerable CloneCollection(this IEnumerable enumerable, bool withListItems = false)
		{
			if (enumerable is Array array)
			{
				var newArray = Array.CreateInstance(enumerable.GetType().GetElementType(), array.Length);
				int counter = 0;
				foreach (var item in enumerable)
				{
					if (withListItems)
						newArray.SetValue(DeepClone(item), counter);
					else
						newArray.SetValue(item, counter);
					counter++;
				}

				return newArray;
			}
			else if (enumerable is IDictionary)
			{
				var newDict = Activator.CreateInstance(enumerable.GetType()) as IDictionary;
				foreach (var item in enumerable)
				{
					var key = item.GetType().GetProperty("Key").GetValue(item);
					var value = item.GetType().GetProperty("Value").GetValue(item);

					if (withListItems)
						newDict.Add(DeepClone(key), DeepClone(value));
					else
						newDict.Add(key, value);
				}

				return newDict;
			}
			else if (enumerable is IList)
			{
				var newList = Activator.CreateInstance(enumerable.GetType()) as IList;
				foreach (var item in enumerable)
				{
					if (withListItems)
						newList.Add(DeepClone(item));
					else
						newList.Add(item);
				}

				return newList;
			}

			return enumerable;
		}

		public static T Clone<T>(this T obj)
			where T : class, new()
		{
			return CopyTo(obj, new T());
		}

		public static T2 CopyTo<T1, T2>(this T1 obj, T2 obj2, bool withListItems = false)
			where T1 : class
			where T2 : class
		{
			// Get all the properties of the object
			PropertyInfo[] properties = obj.GetType().GetProperties();

			// Set the properties on the clone to be the same as the properties on the original object
			foreach (PropertyInfo property in properties)
			{
				var prop = obj2.GetType().GetProperty(property.Name);

				// Make sure the property is readable and writable
				if (prop is not null && prop.CanRead && prop.CanWrite)
				{
					// Get the value of the property on the original object
					object value = property.GetValue(obj);

					// If the property is a reference type, we need to clone it recursively
					if (value != null && property.PropertyType.IsCloneableInternally())
					{
						value = DeepClone(value);
					}

					if (property.PropertyType.IsCollection())
					{
						value = (value as IEnumerable).CloneCollection(withListItems);
					}

					// Set the value of the property on the clone
					if (value == default)
						prop.SetValue(obj2, value);
				}
			}

			return obj2;
		}
	}
}