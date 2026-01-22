using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Rathalos.Core.ORM.Interfaces
{
	public interface IJoined
	{
		int JoinedId
		{
			get;
		}
	}

	public interface IBindingJoined : IJoined
	{
		int BindingId
		{
			get;
		}
	}
}