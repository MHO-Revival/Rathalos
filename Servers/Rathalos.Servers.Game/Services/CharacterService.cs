using Microsoft.EntityFrameworkCore;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Databases.Records;
using Rathalos.Servers.World.Core.Network;

namespace Rathalos.Servers.World.Services
{
    [WarmupDependencies(typeof(RathalosDbService))]
    public sealed class CharacterService : WarmupService<CharacterService>
    {
        private Dictionary<long, InitAttributeRecord> _initAttrs = [];
        private Dictionary<long, InitItemRecord> _initItems = [];
        private Dictionary<long, InitShortcutRecord> _initShortcuts = [];
        private Dictionary<long, InitQuickSupplyRecord> _initQuickSupplies = [];
        private Dictionary<long, UnderclothesInfoRecord> _underclothes = [];
        private Dictionary<long, FaceInfoRecord> _faces = [];
        private Dictionary<long, HairInfoRecord> _hairs = [];
        private Dictionary<long, TattooInfoRecord> _tattoos = [];
        private Dictionary<PlayerAttributeEnum, PlayerAttributeRecord> _playerAttributes = [];

        /// <summary>
        /// Gets all player attribute definitions indexed by AttributeId.
        /// </summary>
        public IReadOnlyDictionary<PlayerAttributeEnum, PlayerAttributeRecord> PlayerAttributes => _playerAttributes;

        public override async Task Initialize()
        {
            _initAttrs = await RathalosDbService.Instance.QueryNoTracking<InitAttributeRecord>().ToDictionaryAsync(x => x.Id);
            _initItems = await RathalosDbService.Instance.QueryNoTracking<InitItemRecord>().ToDictionaryAsync(x => x.Id);
            _initShortcuts = await RathalosDbService.Instance.QueryNoTracking<InitShortcutRecord>().ToDictionaryAsync(x => x.Id);
            _initQuickSupplies = await RathalosDbService.Instance.QueryNoTracking<InitQuickSupplyRecord>().ToDictionaryAsync(x => x.Id);
            _underclothes = await RathalosDbService.Instance.QueryNoTracking<UnderclothesInfoRecord>().ToDictionaryAsync(x => x.Id);
            _faces = await RathalosDbService.Instance.QueryNoTracking<FaceInfoRecord>().ToDictionaryAsync(x => x.Id);
            _hairs = await RathalosDbService.Instance.QueryNoTracking<HairInfoRecord>().ToDictionaryAsync(x => x.Id);
            _tattoos = await RathalosDbService.Instance.QueryNoTracking<TattooInfoRecord>().ToDictionaryAsync(x => x.Id);
            _playerAttributes = await RathalosDbService.Instance.QueryNoTracking<PlayerAttributeRecord>().ToDictionaryAsync(x => (PlayerAttributeEnum)x.AttributeId);
        }

        /// <summary>
        /// Gets a player attribute definition by its enum value.
        /// </summary>
        public PlayerAttributeRecord? GetPlayerAttributeDefinition(PlayerAttributeEnum attrId)
        {
            return _playerAttributes.GetValueOrDefault(attrId);
        }

        /// <summary>
        /// Gets the initial value for a player attribute.
        /// </summary>
        public string? GetPlayerAttributeInitValue(PlayerAttributeEnum attrId)
        {
            return GetPlayerAttributeDefinition(attrId)?.InitVal;
        }

        /// <summary>
        /// Builds the default attributes dictionary for a new character based on PlayerAttributeRecord definitions.
        /// </summary>
        public Dictionary<PlayerAttributeEnum, string> BuildDefaultAttributes()
        {
            var attributes = new Dictionary<PlayerAttributeEnum, string>();

            foreach (var kvp in _playerAttributes)
            {
                var record = kvp.Value;

                // Only include attributes that are in use and have an initial value
                if (record.InUse != 1)
                    continue;

                // Skip if InitVal is NA or empty
                if (string.IsNullOrEmpty(record.InitVal) || record.InitVal == "NA")
                    continue;

                attributes[(PlayerAttributeEnum)record.AttributeId] = record.InitVal;
            }

            return attributes;
        }

        public CreateErrorResultEnum CreateCharacter(WorldClient client, CSRoleCreateInfo message)
        {
            if (message.UnderclothesId != 0 && !_underclothes.ContainsKey(message.UnderclothesId))
                return CreateErrorResultEnum.Error;

            if(message.HairId != 0 && !_hairs.ContainsKey(message.HairId))
                return CreateErrorResultEnum.Error;

            if(message.FaceId != 0 && !_faces.ContainsKey(message.FaceId))
                return CreateErrorResultEnum.Error;

            if(message.FaceTattooIndex != 0 && !_tattoos.ContainsKey(message.FaceTattooIndex))
                return CreateErrorResultEnum.Error;

            // Start with default attributes from PlayerAttributeRecord definitions
            var attributes = BuildDefaultAttributes();

            // Override with character creation values
            attributes[PlayerAttributeEnum.CharSex] = message.Gender.ToString();

            // Appearance from creation message
            attributes[PlayerAttributeEnum.MaleFace] = message.FaceId.ToString();
            attributes[PlayerAttributeEnum.MaleHair] = message.HairId.ToString();
            attributes[PlayerAttributeEnum.UnderClothes] = message.UnderclothesId.ToString();
            attributes[PlayerAttributeEnum.SkinColor] = message.SkinColor.ToString();
            attributes[PlayerAttributeEnum.HairColor] = message.HairColor.ToString();
            attributes[PlayerAttributeEnum.InnerColor] = message.InnerColor.ToString();
            attributes[PlayerAttributeEnum.EyeBall] = message.EyeBall.ToString();
            attributes[PlayerAttributeEnum.EyeColor] = message.EyeColor.ToString();
            attributes[PlayerAttributeEnum.FaceTattooIndex] = message.FaceTattooIndex.ToString();
            attributes[PlayerAttributeEnum.FaceTattooColor] = message.FaceTattooColor.ToString();

            // Add facial info attributes (FacialInfo1 = 247)
            if (message.FacialInfo != null)
            {
                for (int i = 0; i < Math.Min(message.FacialInfo.Length, 47); i++)
                {
                    attributes[PlayerAttributeEnum.FacialInfo1 + i] = message.FacialInfo[i].ToString();
                }
            }

            RathalosDbService.Instance.ExecuteInTransaction(db =>
            {
                db.Add(new CharacterRecord
                {
                    AccountId = client.Account.Id,
                    Name = message.Name,
                    Account = client.Account,
                    AvatarSetId = 0,
                    CreatedAt = DateTime.UtcNow,
                    StarLevel = string.Empty,
                    Attributes = attributes,
                });
            });

            return CreateErrorResultEnum.OK;
        }
    }
}
