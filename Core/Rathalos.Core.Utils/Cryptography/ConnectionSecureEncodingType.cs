using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Rathalos.Core.Utils.Cryptography
{
    public enum ConnectionSecureEncodingType
    {
        TCONN_SEC_NONE = 0,
        TCONN_SEC_TEA = 1,
        TCONN_SEC_QQ = 2,
        TCONN_SEC_AES = 3,
        TCONN_SEC_AES2 = 4, // 与TCONN_SEC_AES算法不同的是修改了数据填充算法
    }
}
