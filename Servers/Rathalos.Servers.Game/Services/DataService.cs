using Rathalos.Core.Protocol.Data.AvatarAttrInfo;
using Rathalos.Core.Protocol.Data.HRLevel;
using Rathalos.Core.Protocol.Data.ItemData;
using Rathalos.Core.Protocol.Data.MonsterAttribute;
using Rathalos.Core.Protocol.Data.MonsterData;
using Rathalos.Core.Protocol.Data.NewPlayerInit;
using Rathalos.Core.Protocol.Data.NpcDataNew;
using Rathalos.Core.Protocol.Data.NpcSale;
using Rathalos.Core.Protocol.Data.Pet;
using Rathalos.Core.Protocol.Data.PlayerAttribute;
using Rathalos.Core.Protocol.Tools;
using Rathalos.Servers.Base.Services;

namespace Rathalos.Servers.World.Services
{
    public class DataService : WarmupService<DataService>
    {
        public DataService() { }

        // Avatar Attribute Info
        public List<FaceInfo> Faces { get; private set; } = [];
        public List<HairInfo> Hairs { get; private set; } = [];
        public List<TattooInfo> Tattoos { get; private set; } = [];
        public List<UnderclothesInfo> Underclothes { get; private set; } = [];

        // Player Attribute
        public List<PlayerAttributeInfo> PlayerAttributes { get; private set; } = [];

        // NPC Data
        public List<NpcDailyWork> NpcDailyWorks { get; private set; } = [];
        public List<NpcDataInfo> NpcData { get; private set; } = [];

        // Monster Data
        public List<AbnormalState> MonsterAbnormalStates { get; private set; } = [];
        public List<MonsterEmotion> MonsterEmotions { get; private set; } = [];
        public List<MonsterLemon> MonsterLemons { get; private set; } = [];
        public List<MonsterInfo> Monsters { get; private set; } = [];
        public List<MonsterPartDefence> MonsterPartDefences { get; private set; } = [];
        public List<MonsterPart> MonsterParts { get; private set; } = [];
        public List<MonsterPerception> MonsterPerceptions { get; private set; } = [];
        public List<MonsterState> MonsterStates { get; private set; } = [];

        // Monster Attribute
        public List<MonsterAttributeInfo> MonsterAttributes { get; private set; } = [];

        // Item Data (all sheets share the same structure)
        public List<ItemDataInfo> Consumables { get; private set; } = [];
        public List<ItemDataInfo> Ammo { get; private set; } = [];
        public List<ItemDataInfo> Gems { get; private set; } = [];
        public List<ItemDataInfo> Charms { get; private set; } = [];
        public List<ItemDataInfo> Gifts { get; private set; } = [];
        public List<ItemDataInfo> FarmItems { get; private set; } = [];

        // HR Level
        public List<HRLevelInfo> HRLevels { get; private set; } = [];

        // New Player Init
        public List<InitAttribute> InitAttributes { get; private set; } = [];
        public List<InitItem> InitItems { get; private set; } = [];
        public List<InitQuickSupply> InitQuickSupplies { get; private set; } = [];
        public List<InitShortcut> InitShortcuts { get; private set; } = [];
        public List<InitStore> InitStores { get; private set; } = [];

        // NPC Sale
        public List<NpcShopMapping> NpcShopMappings { get; private set; } = [];
        public List<ShopInfo> ShopInfos { get; private set; } = [];
        public List<RandomGroup> RandomGroups { get; private set; } = [];
        public List<RandomProduct> RandomProducts { get; private set; } = [];
        public List<RandomPool> RandomPools { get; private set; } = [];

        // Pet Data
        public List<PetName> PetNames { get; private set; } = [];
        public List<PetFarewellGift> PetFarewellGifts { get; private set; } = [];
        public List<PetQuality> PetQualities { get; private set; } = [];
        public List<PetInnateSkill> PetInnateSkills { get; private set; } = [];
        public List<PetInnateSkillList> PetInnateSkillLists { get; private set; } = [];
        public List<PetInfo> Pets { get; private set; } = [];
        public List<PetPersonality> PetPersonalities { get; private set; } = [];
        public List<PetCombatSkill> PetCombatSkills { get; private set; } = [];
        public List<PetSkillSlotUnlock> PetSkillSlotUnlocks { get; private set; } = [];
        public List<PetSkillTrigger> PetSkillTriggers { get; private set; } = [];
        public List<PetSupportSkill> PetSupportSkills { get; private set; } = [];
        public List<PetSupportSkillWeight> PetSupportSkillWeights { get; private set; } = [];
        public List<PetSupportCatSkill> PetSupportCatSkills { get; private set; } = [];
        public List<PetAttackTendency> PetAttackTendencies { get; private set; } = [];
        public List<PetAttackMethod> PetAttackMethods { get; private set; } = [];
        public List<PetProductionSkill> PetProductionSkills { get; private set; } = [];
        public List<PetProductionSkillEffect> PetProductionSkillEffects { get; private set; } = [];
        public List<PetSkin> PetSkins { get; private set; } = [];
        public List<PetLevel> PetLevels { get; private set; } = [];
        public List<PetAptitudeQuality> PetAptitudeQualities { get; private set; } = [];

        public override void Initialize()
        {
            var avatarReader = TsvReader.CreateFromFile("./Files/avatarattrinfo.tsv");
            Faces = avatarReader.GetSheet("FaceInfo")?.ReadAs<FaceInfo>() ?? [];
            Hairs = avatarReader.GetSheet("HairInfo")?.ReadAs<HairInfo>() ?? [];
            Tattoos = avatarReader.GetSheet("TattooInfo")?.ReadAs<TattooInfo>() ?? [];
            Underclothes = avatarReader.GetSheet("UnderclothesInfo")?.ReadAs<UnderclothesInfo>() ?? [];

            var playerAttrReader = TsvReader.CreateFromFile("./Files/playerattribute.tsv");
            PlayerAttributes = playerAttrReader.GetSheet("Attribute")?.ReadAs<PlayerAttributeInfo>() ?? [];

            var npcDataReader = TsvReader.CreateFromFile("./Files/npcdatanew.tsv");
            NpcDailyWorks = npcDataReader.GetSheet("NPCDailyWork")?.ReadAs<NpcDailyWork>() ?? [];
            NpcData = npcDataReader.GetSheet("NPCData")?.ReadAs<NpcDataInfo>() ?? [];

            var monsterDataReader = TsvReader.CreateFromFile("./Files/monsterdata.tsv");
            MonsterAbnormalStates = monsterDataReader.GetSheet("AbnormalState")?.ReadAs<AbnormalState>() ?? [];
            MonsterEmotions = monsterDataReader.GetSheet("Emotion")?.ReadAs<MonsterEmotion>() ?? [];
            MonsterLemons = monsterDataReader.GetSheet("Lemon")?.ReadAs<MonsterLemon>() ?? [];
            Monsters = monsterDataReader.GetSheet("Monsters")?.ReadAs<MonsterInfo>() ?? [];
            MonsterPartDefences = monsterDataReader.GetSheet("PartDefence")?.ReadAs<MonsterPartDefence>() ?? [];
            MonsterParts = monsterDataReader.GetSheet("Parts")?.ReadAs<MonsterPart>() ?? [];
            MonsterPerceptions = monsterDataReader.GetSheet("Perceptions")?.ReadAs<MonsterPerception>() ?? [];
            MonsterStates = monsterDataReader.GetSheet("States")?.ReadAs<MonsterState>() ?? [];

            var monsterAttrReader = TsvReader.CreateFromFile("./Files/monsterattribute.tsv");
            MonsterAttributes = monsterAttrReader.GetSheet("Attribute")?.ReadAs<MonsterAttributeInfo>() ?? [];

            var itemDataReader = TsvReader.CreateFromFile("./Files/itemdata.tsv");
            Consumables = itemDataReader.GetSheet("1消耗品")?.ReadAs<ItemDataInfo>() ?? [];
            Ammo = itemDataReader.GetSheet("4弹药")?.ReadAs<ItemDataInfo>() ?? [];
            Gems = itemDataReader.GetSheet("7宝石")?.ReadAs<ItemDataInfo>() ?? [];
            Charms = itemDataReader.GetSheet("10护身符")?.ReadAs<ItemDataInfo>() ?? [];
            Gifts = itemDataReader.GetSheet("11礼物")?.ReadAs<ItemDataInfo>() ?? [];
            FarmItems = itemDataReader.GetSheet("9农场")?.ReadAs<ItemDataInfo>() ?? [];

            var hrLevelReader = TsvReader.CreateFromFile("./Files/hrlevel.tsv");
            HRLevels = hrLevelReader.GetSheet("HRLevel")?.ReadAs<HRLevelInfo>() ?? [];

            var newPlayerInitReader = TsvReader.CreateFromFile("./Files/newplayerinit.tsv");
            InitAttributes = newPlayerInitReader.GetSheet("Attribute")?.ReadAs<InitAttribute>() ?? [];
            InitItems = newPlayerInitReader.GetSheet("Item")?.ReadAs<InitItem>() ?? [];
            InitQuickSupplies = newPlayerInitReader.GetSheet("QuickSupply")?.ReadAs<InitQuickSupply>() ?? [];
            InitShortcuts = newPlayerInitReader.GetSheet("Shortcut")?.ReadAs<InitShortcut>() ?? [];
            InitStores = newPlayerInitReader.GetSheet("Store")?.ReadAs<InitStore>() ?? [];

            var npcSaleReader = TsvReader.CreateFromFile("./Files/npcsale.tsv");
            NpcShopMappings = npcSaleReader.GetSheet("NPC与商店对应关系")?.ReadAs<NpcShopMapping>() ?? [];
            ShopInfos = npcSaleReader.GetSheet("商店信息")?.ReadAs<ShopInfo>() ?? [];
            RandomGroups = npcSaleReader.GetSheet("随机分组")?.ReadAs<RandomGroup>() ?? [];
            RandomProducts = npcSaleReader.GetSheet("随机商品")?.ReadAs<RandomProduct>() ?? [];
            RandomPools = npcSaleReader.GetSheet("随机库")?.ReadAs<RandomPool>() ?? [];

            var petReader = TsvReader.CreateFromFile("./Files/pet.tsv");
            PetNames = petReader.GetSheet("名称")?.ReadAs<PetName>() ?? [];
            PetFarewellGifts = petReader.GetSheet("告别赠礼")?.ReadAs<PetFarewellGift>() ?? [];
            PetQualities = petReader.GetSheet("品质")?.ReadAs<PetQuality>() ?? [];
            PetInnateSkills = petReader.GetSheet("天生技能")?.ReadAs<PetInnateSkill>() ?? [];
            PetInnateSkillLists = petReader.GetSheet("天生技能列表")?.ReadAs<PetInnateSkillList>() ?? [];
            Pets = petReader.GetSheet("宠物信息")?.ReadAs<PetInfo>() ?? [];
            PetPersonalities = petReader.GetSheet("性格")?.ReadAs<PetPersonality>() ?? [];
            PetCombatSkills = petReader.GetSheet("战斗技能")?.ReadAs<PetCombatSkill>() ?? [];
            PetSkillSlotUnlocks = petReader.GetSheet("技能槽解锁条件")?.ReadAs<PetSkillSlotUnlock>() ?? [];
            PetSkillTriggers = petReader.GetSheet("技能触发")?.ReadAs<PetSkillTrigger>() ?? [];
            PetSupportSkills = petReader.GetSheet("支援技能")?.ReadAs<PetSupportSkill>() ?? [];
            PetSupportSkillWeights = petReader.GetSheet("支援技能权重")?.ReadAs<PetSupportSkillWeight>() ?? [];
            PetSupportCatSkills = petReader.GetSheet("支援猫技能")?.ReadAs<PetSupportCatSkill>() ?? [];
            PetAttackTendencies = petReader.GetSheet("攻击倾向")?.ReadAs<PetAttackTendency>() ?? [];
            PetAttackMethods = petReader.GetSheet("攻击方式")?.ReadAs<PetAttackMethod>() ?? [];
            PetProductionSkills = petReader.GetSheet("生产技能")?.ReadAs<PetProductionSkill>() ?? [];
            PetProductionSkillEffects = petReader.GetSheet("生产技能效果")?.ReadAs<PetProductionSkillEffect>() ?? [];
            PetSkins = petReader.GetSheet("皮肤")?.ReadAs<PetSkin>() ?? [];
            PetLevels = petReader.GetSheet("等级")?.ReadAs<PetLevel>() ?? [];
            PetAptitudeQualities = petReader.GetSheet("资质品质")?.ReadAs<PetAptitudeQuality>() ?? [];
        }
    }
}
