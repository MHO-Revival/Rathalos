using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Databases.Records;
using Rathalos.Servers.World.Services;

namespace Rathalos.Servers.World.Core.Game.Stats;

/// <summary>
/// Manages player attributes with typed accessors for common properties.
/// </summary>
public sealed class PlayerAttributes
{
    private readonly AttributesFields<PlayerAttributeEnum> _fields = new();

    /// <summary>
    /// Gets the underlying attribute fields container.
    /// </summary>
    public AttributesFields<PlayerAttributeEnum> Fields => _fields;

    #region Character Info

    public int CharLevel
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharLevel);
        set => _fields.SetValue(PlayerAttributeEnum.CharLevel, value);
    }

    public int CharSex
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharSex);
        set => _fields.SetValue(PlayerAttributeEnum.CharSex, value);
    }

    public int CharExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharExp);
        set => _fields.SetValue(PlayerAttributeEnum.CharExp, value);
    }

    public int StarLevel
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.StarLevel);
        set => _fields.SetValue(PlayerAttributeEnum.StarLevel, value);
    }

    public int CharHRLevel
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharHRLevel);
        set => _fields.SetValue(PlayerAttributeEnum.CharHRLevel, value);
    }

    public int CharHRPoint
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharHRPoint);
        set => _fields.SetValue(PlayerAttributeEnum.CharHRPoint, value);
    }

    public int SoulStoneLevel
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.SoulStoneLevel);
        set => _fields.SetValue(PlayerAttributeEnum.SoulStoneLevel, value);
    }

    public string CharName
    {
        get => _fields.GetStringValue(PlayerAttributeEnum.CharName) ?? string.Empty;
        set => _fields.SetStringValue(PlayerAttributeEnum.CharName, value);
    }

    #endregion

    #region Appearance

    public int MaleFace
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.MaleFace);
        set => _fields.SetValue(PlayerAttributeEnum.MaleFace, value);
    }

    public int MaleHair
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.MaleHair);
        set => _fields.SetValue(PlayerAttributeEnum.MaleHair, value);
    }

    public int UnderClothes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.UnderClothes);
        set => _fields.SetValue(PlayerAttributeEnum.UnderClothes, value);
    }

    public int SkinColor
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.SkinColor);
        set => _fields.SetValue(PlayerAttributeEnum.SkinColor, value);
    }

    public int HairColor
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.HairColor);
        set => _fields.SetValue(PlayerAttributeEnum.HairColor, value);
    }

    public int InnerColor
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.InnerColor);
        set => _fields.SetValue(PlayerAttributeEnum.InnerColor, value);
    }

    public int EyeBall
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.EyeBall);
        set => _fields.SetValue(PlayerAttributeEnum.EyeBall, value);
    }

    public int EyeColor
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.EyeColor);
        set => _fields.SetValue(PlayerAttributeEnum.EyeColor, value);
    }

    public int FaceTattooIndex
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.FaceTattooIndex);
        set => _fields.SetValue(PlayerAttributeEnum.FaceTattooIndex, value);
    }

    public int FaceTattooColor
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.FaceTattooColor);
        set => _fields.SetValue(PlayerAttributeEnum.FaceTattooColor, value);
    }

    #endregion

    #region Display Options

    public bool HideFashion
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.HideFashion) != 0;
        set => _fields.SetValue(PlayerAttributeEnum.HideFashion, value ? 1 : 0);
    }

    public bool HideSuite
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.HideSuite) != 0;
        set => _fields.SetValue(PlayerAttributeEnum.HideSuite, value ? 1 : 0);
    }

    public bool HideHelm
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.HideHelm) != 0;
        set => _fields.SetValue(PlayerAttributeEnum.HideHelm, value ? 1 : 0);
    }

    #endregion

    #region Combat Stats

    public int CharHP
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharHP);
        set => _fields.SetValue(PlayerAttributeEnum.CharHP, value);
    }

    public int CharMaxHP
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharMaxHP);
        set => _fields.SetValue(PlayerAttributeEnum.CharMaxHP, value);
    }

    public float CharSta
    {
        get => _fields.GetValue<float>(PlayerAttributeEnum.CharSta);
        set => _fields.SetValue(PlayerAttributeEnum.CharSta, value);
    }

    public int CharMaxSta
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharMaxSta);
        set => _fields.SetValue(PlayerAttributeEnum.CharMaxSta, value);
    }

    public int CharDefence
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharDefence);
        set => _fields.SetValue(PlayerAttributeEnum.CharDefence, value);
    }

    public float CharMelee
    {
        get => _fields.GetValue<float>(PlayerAttributeEnum.CharMelee);
        set => _fields.SetValue(PlayerAttributeEnum.CharMelee, value);
    }

    public float CharRange
    {
        get => _fields.GetValue<float>(PlayerAttributeEnum.CharRange);
        set => _fields.SetValue(PlayerAttributeEnum.CharRange, value);
    }

    public int CharRage
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharRage);
        set => _fields.SetValue(PlayerAttributeEnum.CharRage, value);
    }

    public int CharMaxRage
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharMaxRage);
        set => _fields.SetValue(PlayerAttributeEnum.CharMaxRage, value);
    }

    public int CritLevel
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CritLevel);
        set => _fields.SetValue(PlayerAttributeEnum.CritLevel, value);
    }

    public int CritDmg
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CritDmg);
        set => _fields.SetValue(PlayerAttributeEnum.CritDmg, value);
    }

    public int Sharpness
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.Sharpness);
        set => _fields.SetValue(PlayerAttributeEnum.Sharpness, value);
    }

    public int MaxSharpness
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.MaxSharpness);
        set => _fields.SetValue(PlayerAttributeEnum.MaxSharpness, value);
    }

    #endregion

    #region Elemental Attack

    public int WaterAttack
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.WaterAttack);
        set => _fields.SetValue(PlayerAttributeEnum.WaterAttack, value);
    }

    public int FireAttack
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.FireAttack);
        set => _fields.SetValue(PlayerAttributeEnum.FireAttack, value);
    }

    public int LightningAttack
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.LightningAttack);
        set => _fields.SetValue(PlayerAttributeEnum.LightningAttack, value);
    }

    public int DragonAttack
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.DragonAttack);
        set => _fields.SetValue(PlayerAttributeEnum.DragonAttack, value);
    }

    public int IceAttack
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.IceAttack);
        set => _fields.SetValue(PlayerAttributeEnum.IceAttack, value);
    }

    #endregion

    #region Elemental Resistance

    public int WaterRes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.WaterRes);
        set => _fields.SetValue(PlayerAttributeEnum.WaterRes, value);
    }

    public int FireRes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.FireRes);
        set => _fields.SetValue(PlayerAttributeEnum.FireRes, value);
    }

    public int LightningRes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.LightningRes);
        set => _fields.SetValue(PlayerAttributeEnum.LightningRes, value);
    }

    public int DragonRes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.DragonRes);
        set => _fields.SetValue(PlayerAttributeEnum.DragonRes, value);
    }

    public int IceRes
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.IceRes);
        set => _fields.SetValue(PlayerAttributeEnum.IceRes, value);
    }

    #endregion

    #region Currency

    public int CharMoney
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharMoney);
        set => _fields.SetValue(PlayerAttributeEnum.CharMoney, value);
    }

    public int CharBoundMoney
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharBoundMoney);
        set => _fields.SetValue(PlayerAttributeEnum.CharBoundMoney, value);
    }

    public int CharCredit
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharCredit);
        set => _fields.SetValue(PlayerAttributeEnum.CharCredit, value);
    }

    public int CharBoundCredit
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharBoundCredit);
        set => _fields.SetValue(PlayerAttributeEnum.CharBoundCredit, value);
    }

    #endregion

    #region Weapon Proficiency

    public int ClaymoreExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.ClaymoreExp);
        set => _fields.SetValue(PlayerAttributeEnum.ClaymoreExp, value);
    }

    public int HammerExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.HammerExp);
        set => _fields.SetValue(PlayerAttributeEnum.HammerExp, value);
    }

    public int KatanaExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.KatanaExp);
        set => _fields.SetValue(PlayerAttributeEnum.KatanaExp, value);
    }

    public int DuelSwordExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.DuelSwordExp);
        set => _fields.SetValue(PlayerAttributeEnum.DuelSwordExp, value);
    }

    public int SwordExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.SwordExp);
        set => _fields.SetValue(PlayerAttributeEnum.SwordExp, value);
    }

    public int SpearExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.SpearExp);
        set => _fields.SetValue(PlayerAttributeEnum.SpearExp, value);
    }

    public int GunExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.GunExp);
        set => _fields.SetValue(PlayerAttributeEnum.GunExp, value);
    }

    public int BowExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.BowExp);
        set => _fields.SetValue(PlayerAttributeEnum.BowExp, value);
    }

    public int CrossbowExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CrossbowExp);
        set => _fields.SetValue(PlayerAttributeEnum.CrossbowExp, value);
    }

    public int FluteExp
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.FluteExp);
        set => _fields.SetValue(PlayerAttributeEnum.FluteExp, value);
    }

    #endregion

    #region Movement

    public int CharSpeed
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharSpeed);
        set => _fields.SetValue(PlayerAttributeEnum.CharSpeed, value);
    }

    public int CharAnimSpeed
    {
        get => _fields.GetValue<int>(PlayerAttributeEnum.CharAnimSpeed);
        set => _fields.SetValue(PlayerAttributeEnum.CharAnimSpeed, value);
    }

    #endregion

    #region Facial Info (FacialInfo1-47)

    public short GetFacialInfo(int index)
    {
        var enumVal = System.Enum.GetValues<PlayerAttributeEnum>()
            .FirstOrDefault(e => e.ToString().StartsWith($"FacialInfo{index}"));
        if (index < 1 || index > CsprotoConstants.CS_MAX_FACIALINFO_COUNT)
            throw new ArgumentOutOfRangeException(nameof(index), $"Facial info index must be between 1 and {CsprotoConstants.CS_MAX_FACIALINFO_COUNT}.");
        return _fields.GetValue<short>(enumVal);
    }

    public void SetFacialInfo(int index, short value)
    {
        var enumVal = System.Enum.GetValues<PlayerAttributeEnum>()
            .FirstOrDefault(e => e.ToString().StartsWith($"FacialInfo{index}"));

        if (index < 1 || index > CsprotoConstants.CS_MAX_FACIALINFO_COUNT)
            throw new ArgumentOutOfRangeException(nameof(index), $"Facial info index must be between 1 and {CsprotoConstants.CS_MAX_FACIALINFO_COUNT}.");

        _fields.SetValue(enumVal, value);
    }

    public short[] GetAllFacialInfo()
    {
        var facialEnums = System.Enum.GetValues<PlayerAttributeEnum>()
            .Where(e => e.ToString().StartsWith("FacialInfo"))
            .OrderBy(e =>
            {
                var name = e.ToString();
                if (int.TryParse(name.Substring("FacialInfo".Length), out var idx))
                    return idx;
                return int.MaxValue;
            })
            .Take(CsprotoConstants.CS_MAX_FACIALINFO_COUNT)
            .ToArray();
        var result = new short[facialEnums.Length];
        for (int i = 0; i < facialEnums.Length; i++)
        {
            result[i] = _fields.GetValue<short>(facialEnums[i]);
        }
        return result;
    }

    public void SetAllFacialInfo(short[] values)
    {
        if (values == null) return;

        var facialEnums = System.Enum.GetValues<PlayerAttributeEnum>()
            .Where(e => e.ToString().StartsWith("FacialInfo"))
            .OrderBy(e =>
            {
                var name = e.ToString();
                if (int.TryParse(name.Substring("FacialInfo".Length), out var idx))
                    return idx;
                return int.MaxValue;
            })
            .Take(CsprotoConstants.CS_MAX_FACIALINFO_COUNT)
            .ToArray();

        for (int i = 0; i < Math.Min(values.Length, facialEnums.Length); i++)
        {
            _fields.SetValue(facialEnums[i], values[i]);
        }
    }

    #endregion

    /// <summary>
    /// Initializes an attribute with its metadata.
    /// </summary>
    public void InitializeAttribute<TValue>(
        PlayerAttributeEnum id,
        TValue value,
        bool self = false,
        bool bonus = false,
        TValue? initialValue = null,
        TValue? lowerBound = null,
        TValue? upperBound = null)
        where TValue : struct
    {
        var attr = new AttributeData<PlayerAttributeEnum, TValue>(
            id, value, self, bonus, initialValue, lowerBound, upperBound);
        _fields.Set(attr);
    }

    /// <summary>
    /// Initializes a string attribute with its metadata.
    /// </summary>
    public void InitializeStringAttribute(
        PlayerAttributeEnum id,
        string? value,
        bool self = false,
        bool bonus = false,
        string? initialValue = null)
    {
        var attr = new StringAttributeData<PlayerAttributeEnum>(id, value, self, bonus, initialValue);
        _fields.SetString(attr);
    }

    /// <summary>
    /// Initializes an attribute from a PlayerAttributeRecord definition with a specified value.
    /// </summary>
    public void InitializeAttributeFromDefinition(PlayerAttributeRecord definition, string? valueStr)
    {
        var attrId = (PlayerAttributeEnum)definition.AttributeId;
        bool self = definition.Self == 1;
        bool bonus = definition.Bonus == 1;

        // Parse bounds
        int? lowerInt = null, upperInt = null;
        float? lowerFloat = null, upperFloat = null;

        if (!string.IsNullOrEmpty(definition.Lower) && definition.Lower != "NA" && definition.Lower != "N/A" && definition.Lower != "n/a")
        {
            if (int.TryParse(definition.Lower, out var l)) lowerInt = l;
            else if (float.TryParse(definition.Lower, System.Globalization.CultureInfo.InvariantCulture, out var lf)) lowerFloat = lf;
        }
        if (!string.IsNullOrEmpty(definition.Upper) && definition.Upper != "NA" && definition.Upper != "N/A" && definition.Upper != "n/a")
        {
            if (int.TryParse(definition.Upper, out var u)) upperInt = u;
            else if (float.TryParse(definition.Upper, System.Globalization.CultureInfo.InvariantCulture, out var uf)) upperFloat = uf;
        }

        // Parse initial value
        string? initValStr = definition.InitVal;
        bool hasInitVal = !string.IsNullOrEmpty(initValStr) && initValStr != "NA" && initValStr != "N/A" && initValStr != "n/a";

        // Determine type and initialize accordingly
        switch (definition.Type.ToLowerInvariant())
        {
            case "int":
                int intVal;
                if (!int.TryParse(valueStr, out intVal))
                    intVal = default;
                int? initInt = hasInitVal && int.TryParse(initValStr, out var ii) ? ii : null;
                InitializeAttribute(attrId, intVal, self, bonus, initInt, lowerInt, upperInt);
                break;

            case "float":
                float floatVal;
                if (!float.TryParse(valueStr, System.Globalization.CultureInfo.InvariantCulture, out floatVal))
                    floatVal = default;
                float? initFloat = hasInitVal && float.TryParse(initValStr, System.Globalization.CultureInfo.InvariantCulture, out var iff) ? iff : null;
                InitializeAttribute(attrId, floatVal, self, bonus, initFloat, lowerFloat, upperFloat);
                break;

            case "short":
                short shortVal;
                if (!short.TryParse(valueStr, out shortVal))
                    shortVal = default;
                short? initShort = hasInitVal && short.TryParse(initValStr, out var iss) ? iss : null;
                short? lowerShort = lowerInt.HasValue ? (short)lowerInt.Value : null;
                short? upperShort = upperInt.HasValue ? (short)upperInt.Value : null;
                InitializeAttribute(attrId, shortVal, self, bonus, initShort, lowerShort, upperShort);
                break;

            case "bool":
                int boolInt;
                bool boolVal;
                if (!bool.TryParse(valueStr, out boolVal))
                {
                    if (!int.TryParse(valueStr, out boolInt))
                        boolVal = default;
                    else
                        boolVal = boolInt != 0;
                }

                bool? initBool = hasInitVal && int.TryParse(initValStr, out var ib) ? ib != 0 : (bool?)null;
                InitializeAttribute(attrId, boolVal, self, bonus, initBool, null, null);
                break;

            case "uint64":
                long longVal;
                if (!long.TryParse(valueStr, out longVal))
                    longVal = default;
                long? initLong = hasInitVal && long.TryParse(initValStr, out var il) ? il : null;
                InitializeAttribute(attrId, longVal, self, bonus, initLong, null, null);
                break;

            case "string":
                InitializeStringAttribute(attrId, valueStr ?? string.Empty, self, bonus, hasInitVal ? initValStr : null);
                break;

            default:
                // Fallback: try int, else use 0
                int fallbackVal;
                if (!int.TryParse(valueStr, out fallbackVal))
                    fallbackVal = default;
                InitializeAttribute(attrId, fallbackVal, self, bonus);
                break;
        }
    }

    /// <summary>
    /// Loads attributes from a character record's attribute dictionary with full metadata from PlayerAttributeRecord definitions.
    /// </summary>
    public void LoadFromRecord(Dictionary<PlayerAttributeEnum, string> record)
    {
        var definitions = CharacterService.Instance.PlayerAttributes;

        if (record == null || record.Count == 0)
        {
            return;
        }

        foreach (var kvp in record)
        {
            var attrId = kvp.Key;
            var valueStr = kvp.Value;

            // Try to get the definition from CharacterService
            if (definitions.TryGetValue(kvp.Key, out var definition))
            {
                InitializeAttributeFromDefinition(definition, valueStr);
            }
            else
            {
                // Fallback: initialize without metadata
                if (int.TryParse(valueStr, out var intVal))
                {
                    InitializeAttribute(attrId, intVal, self: true);
                }
                else if (long.TryParse(valueStr, out var longVal))
                {
                    InitializeAttribute(attrId, longVal, self: true);
                }
                else if (float.TryParse(valueStr, System.Globalization.CultureInfo.InvariantCulture, out var floatVal))
                {
                    InitializeAttribute(attrId, floatVal, self: true);
                }
                else if (short.TryParse(valueStr, out var shortVal))
                {
                    InitializeAttribute(attrId, shortVal, self: true);
                }
                else
                {
                    InitializeStringAttribute(attrId, valueStr, self: true);
                }
            }
        }
    }

    /// <summary>
    /// Initializes all attributes with their default values from PlayerAttributeRecord definitions.
    /// Only attributes that are in use and have valid initial values will be initialized.
    /// </summary>
    public void InitializeDefaults()
    {
        var definitions = CharacterService.Instance.PlayerAttributes;

        foreach (var kvp in definitions)
        {
            var definition = kvp.Value;

            // Only initialize attributes that are in use and have a valid initial value
            if (definition.InUse != 1)
                continue;

            InitializeAttributeFromDefinition(definition, definition.InitVal);
        }
    }

    /// <summary>
    /// Returns a dictionary containing all player attributes and their corresponding string values.
    /// </summary>
    /// <remarks>The returned dictionary includes all attributes present in the underlying data source, with
    /// values converted to strings. This method does not filter or transform the attributes beyond string
    /// conversion.</remarks>
    /// <returns>A dictionary mapping each player attribute to its string representation. If an attribute value is not set, the
    /// corresponding value is an empty string.</returns>
    public Dictionary<PlayerAttributeEnum, string> GetRecord()
    {
        var result = new Dictionary<PlayerAttributeEnum, string>();
        foreach (var key in _fields.Keys)
        {
            var attrId = key;
            result[attrId] = _fields.GetRaw(key)?.ToString() ?? string.Empty;
        }
        return result;
    }

    /// <summary>
    /// Sets a single attribute value by enum ID and saves to dictionary format.
    /// </summary>
    public void SetAttributeValue<TValue>(PlayerAttributeEnum id, TValue value, bool self = false, bool bonus = false)
        where TValue : struct
    {
        InitializeAttribute(id, value, self, bonus);
    }

    /// <summary>
    /// Gets an attribute value by enum ID with a default fallback.
    /// </summary>
    public TValue GetAttributeValue<TValue>(PlayerAttributeEnum id, TValue defaultValue = default)
        where TValue : struct
    {
        return _fields.TryGet<TValue>(id, out var attr) ? attr.Value : defaultValue;
    }
}
