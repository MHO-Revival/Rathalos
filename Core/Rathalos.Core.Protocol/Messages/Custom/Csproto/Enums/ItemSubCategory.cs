namespace Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums
{
    public enum ItemSubCategory : int
    {
        None = 0,
        Medicine = 1,        // 药品
        Food = 2,            // 熟食/食物
        TrapTool = 3,        // 陷阱/捕获工具
        SupportItem = 4,     // 辅助道具
        Ammo = 5,            // 弹药 (弩车/炮弹)
        GatheringTool = 6,   // 采集工具 (镐/网)
        Gem = 7,             // 宝石
        Material = 8,        // 素材 (General)
        MonsterPart = 9,     // 怪物部位素材
        CurrencyItem = 10,   // 货币/代币类
    }
}
