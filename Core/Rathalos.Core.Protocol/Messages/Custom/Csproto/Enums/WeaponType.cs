using System;
using System.Collections.Generic;
using System.Text;

namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum WeaponType : int
    {
        None = 0,
        GreatSword = 1,      // 大剑
        Tachi = 2,           // 太刀 (Longsword)
        Hammer = 3,          // 锤
        Lance = 4,           // 长枪
        SwordAndShield = 5,  // 片手 (Sword & Shield)
        DualBlades = 6,      // 双刀
        HuntingHorn = 7,     // 狩猎笛
        Gunlance = 8,        // 铳枪
        SwitchAxe = 9,       // 斩斧
        Bow = 10,            // 弓
        LightBowgun = 11,    // 弩 (Light Bowgun)
        HeavyBowgun = 12,    // 弩 (Heavy Bowgun)
        // Add more if discovered in future sheets
    }
}
