using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum ItemBoxTypeEnum
    {
        Item = 0,
        Store = 1,

        /// <summary>
        /// 'Box/Equip'-Tab of inventory menu (i)
        /// </summary>
        BoxEquip = 2,

        /// <summary>
        /// Paperdoll 'Equip'-Tab of character menu
        /// </summary>
        Equipment = 3,
        Quest = 5,
    }
}
