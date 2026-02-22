namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum EquipmentSubCategory : int
    {
        None = 0,

        // --- Weapons (Matches WeaponType IDs) ---
        GreatSword = 1,
        Tachi = 2,
        Hammer = 3,
        Lance = 4,
        SwordAndShield = 5,
        DualBlades = 6,
        HuntingHorn = 7,
        Gunlance = 8,
        SwitchAxe = 9,
        Bow = 10,
        LightBowgun = 11,
        HeavyBowgun = 12,

        // --- Armor Slots ---
        Head = 21,
        Chest = 22,
        Arms = 23,
        Waist = 24,
        Legs = 25,

        // --- Jewelry ---
        Ring = 31,
        Necklace = 32,
        Earring = 33,
        Talisman = 34,

        // --- Fashion ---
        FashionSuit = 41,
        FashionWeapon = 42
    }
}
