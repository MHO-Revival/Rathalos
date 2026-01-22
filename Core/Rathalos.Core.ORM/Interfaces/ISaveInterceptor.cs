using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Rathalos.Core.ORM.Interfaces
{
	public interface ISaveInterceptor
	{
		void BeforeSave(bool insert);
	}
}