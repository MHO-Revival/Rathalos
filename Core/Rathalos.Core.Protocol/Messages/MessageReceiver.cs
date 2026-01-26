using Rathalos.Core.Protocol;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Tqqapi;
using Rathalos.Core.Utils.IO;
using System.Linq.Expressions;
using System.Reflection;

namespace Rathalos.Core.Protocol.Messages
{
	public static class MessageReceiver
    {
        private static readonly Dictionary<int, (Type Type, Func<object> Constructor)> _messagesDefinitions = new Dictionary<int, (Type Type, Func<object> Constructor)>();
        private static bool _initialized = false;

		/// <summary>
		///   Initializes this instance.
		/// </summary>
		public static void Initialize()
		{
			if (_initialized)
				return;
			_initialized = true;

            Assembly asm = Assembly.GetAssembly(typeof(MessageReceiver));

			IEnumerable<Type> messageTypes = asm.GetTypes()
				.Where(x => (x.IsAssignableTo(typeof(CSPkgBody)) || x.IsAssignableTo(typeof(TPDUExt))) && !x.IsAbstract);
			foreach (Type type in messageTypes)
			{
				var fieldId = type.GetField(nameof(TPDUExtAuthDataAuthQQV2.ProtocolIdConst));

				if (fieldId != null)
				{
					var id = (int)fieldId.GetValue(type);

					ConstructorInfo ctor = type.GetConstructor(Type.EmptyTypes);

					if (ctor == null)
						throw new Exception(
							string.Format("'{0}' doesn't implemented a parameterless constructor",
											type));

					var funcCtor = Expression.Lambda<Func<object>>(Expression.New(ctor)).Compile();

					if (!_messagesDefinitions.TryGetValue(id, out var message))
						_messagesDefinitions.Add(id, (type, funcCtor));
					else
						throw new Exception(
							string.Format("'{0}' id is already in the list !",
											id));
				}
			}
		}

		/// <summary>
		///   Gets instance of the message defined by id thanks to BigEndianReader.
		/// </summary>
		/// <param name = "id">id.</param>
		/// <returns></returns>
		public static Message BuildMessage(int id, IDataReader reader)
		{
			if (!_messagesDefinitions.TryGetValue(id, out var definition))
				throw new MessageNotFoundException(string.Format("Message <id:{0}> doesn't exist", id));

			Message message = definition.Constructor() as Message;

			if (message == null)
				throw new MessageNotFoundException(string.Format("Constructors[{0}] (delegate {1}) does not exist", id, _messagesDefinitions[id]));

			message.Unpack(reader);

			return message;
		}

		public static Type GetMessageType(int id)
		{
			if (!_messagesDefinitions.TryGetValue(id, out var definition))
				throw new MessageNotFoundException(string.Format("Message <id:{0}> doesn't exist", id));

			return definition.Type;
		}

		[Serializable]
		public class MessageNotFoundException : Exception
		{
			public MessageNotFoundException()
			{
			}

			public MessageNotFoundException(string message)
				: base(message)
			{
			}

			public MessageNotFoundException(string message, Exception inner)
				: base(message, inner)
			{
			}
		}
	}
}