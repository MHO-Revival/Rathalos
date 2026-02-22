using Rathalos.Core.Protocol.Data.EquipData.Rathalos.Core.Protocol.Tools;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using System.Collections.ObjectModel;

namespace Rathalos.Servers.World.Core.Game.Storage.Items
{
    public class GameItem
    {
        private static readonly ReadOnlyDictionary<EquipmentSubCategory, ItemEquipmentPosition> SubCategoryToPosition =
            new ReadOnlyDictionary<EquipmentSubCategory, ItemEquipmentPosition>(new Dictionary<EquipmentSubCategory, ItemEquipmentPosition>
            {
                // Weapons
                { EquipmentSubCategory.GreatSword,     ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.Tachi,          ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.Hammer,         ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.Lance,          ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.SwordAndShield, ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.DualBlades,     ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.HuntingHorn,    ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.Gunlance,       ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.SwitchAxe,      ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.Bow,            ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.LightBowgun,    ItemEquipmentPosition.Weapon },
                { EquipmentSubCategory.HeavyBowgun,    ItemEquipmentPosition.Weapon },

                // Armor
                { EquipmentSubCategory.Head,           ItemEquipmentPosition.Helmet },
                { EquipmentSubCategory.Chest,          ItemEquipmentPosition.Chest },
                { EquipmentSubCategory.Arms,           ItemEquipmentPosition.Hands },
                { EquipmentSubCategory.Waist,          ItemEquipmentPosition.Waist },
                { EquipmentSubCategory.Legs,           ItemEquipmentPosition.Legs },

                // Jewelry
                { EquipmentSubCategory.Ring,           ItemEquipmentPosition.Ring },
                { EquipmentSubCategory.Necklace,       ItemEquipmentPosition.Necklace },
                { EquipmentSubCategory.Talisman,       ItemEquipmentPosition.Talisman },
                
                // Special case for Earring (MHO often puts earrings in the Helmet slot)
                { EquipmentSubCategory.Earring,        ItemEquipmentPosition.Helmet }
            });

        private EquipmentData _data;
        public GameItem(EquipmentData data)
        {
            _data = data;
        }



        /// <summary>
        /// Returns the equipment slot position for a given subcategory.
        /// Returns null if the subcategory is not an equippable item.
        /// </summary>
        public static ItemEquipmentPosition? GetPosition(EquipmentSubCategory? subCategory)
        {
            if (subCategory.HasValue && SubCategoryToPosition.TryGetValue(subCategory.Value, out var position))
            {
                return position;
            }
            return null;
        }
    }
}
