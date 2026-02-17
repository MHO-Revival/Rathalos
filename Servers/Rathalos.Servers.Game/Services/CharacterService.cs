using Microsoft.EntityFrameworkCore;
using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Servers.Base.Services;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Databases.Records;
using Rathalos.Servers.World.Core.Game.Actors;
using Rathalos.Servers.World.Core.Game.Stats;
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
        private readonly int MaxCharactersPerAccount = 6;

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

        public CreateErrorResultEnum CreateCharacter(WorldClient client, CSRoleCreateInfo message)
        {
            if (message.UnderclothesId != 0 && !_underclothes.ContainsKey(message.UnderclothesId))
                return CreateErrorResultEnum.UnderclothesInvalid;

            if (message.HairId != 0 && !_hairs.ContainsKey(message.HairId))
                return CreateErrorResultEnum.HairInvalid;

            if (message.FaceId != 0 && !_faces.ContainsKey(message.FaceId))
                return CreateErrorResultEnum.FaceInvalid;

            if (message.FaceTattooIndex != 0 && !_tattoos.Any(x => x.Value.MaleModelId == message.FaceTattooIndex || x.Value.FemaleModelId == message.FaceTattooIndex))
                return CreateErrorResultEnum.TattooInvalid;

            var existingCharacterWithName = RathalosDbService.Instance.Query<CharacterRecord>(x => x.Name == message.Name).FirstOrDefault();
            if (existingCharacterWithName is not null)
                return CreateErrorResultEnum.NameAlreadyTaken;

            if (client.Characters.Count >= MaxCharactersPerAccount)
                return CreateErrorResultEnum.MaxCharacterReached;

            if (message.Name.TrimEnd('\0').Contains('\0') || message.Name.Length > CsprotoConstants.CS_MAX_ROLE_NAME)
                return CreateErrorResultEnum.NameContainsIllegalCharacters;

            var attrs = new PlayerAttributes();
            attrs.InitializeDefaults();

            foreach(var initAttr in _initAttrs.Values)
            {
                if (Enum.TryParse<PlayerAttributeEnum>(initAttr.AttrName, out var attrEnum))
                {
                    attrs.InitializeAttributeFromDefinition(_playerAttributes[attrEnum], initAttr.AttrValue);
                }
            }

            // Override with character creation values
            attrs.CharSex = message.Gender;
            attrs.CharName = message.Name;
            attrs.CharLevel = 1;
            // Appearance from creation message
            attrs.MaleFace = message.FaceId;
            attrs.MaleHair = message.HairId;
            attrs.UnderClothes = message.UnderclothesId;
            attrs.SkinColor = message.SkinColor;
            attrs.HairColor = message.HairColor;
            attrs.InnerColor = message.InnerColor;
            attrs.EyeBall = message.EyeBall;
            attrs.EyeColor = message.EyeColor;
            attrs.FaceTattooIndex = message.FaceTattooIndex;
            attrs.FaceTattooColor = message.FaceTattooColor;
            attrs.SetAllFacialInfo(message.FacialInfo);

            RathalosDbService.Instance.Execute(db =>
            {
                var character = new CharacterRecord
                {
                    Name = message.Name,
                    AccountId = client.Account.Id,
                    AvatarSetId = 0,
                    CreatedAt = DateTime.UtcNow,
                    StarLevel = string.Empty,
                    Attributes = attrs.GetRecord(),
                };
                db.Insert(character);
                client.Characters.Add(new Character(client, character));
            });

            return CreateErrorResultEnum.OK;
        }

        public void DeleteCharacter(WorldClient client, int roleIndex)
        {
            if (roleIndex < 0 || roleIndex >= client.Characters.Count)
                return;

            var character = client.Characters[roleIndex];
            if (character is null)
                return;

            RathalosDbService.Instance.Execute(db =>
            {
                db.Delete(character.Record);
                client.Characters.Remove(character);
            });
        }
    }
}
