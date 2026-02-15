using Rathalos.Core.ORM;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using System.ComponentModel.DataAnnotations.Schema;
using System.Numerics;

namespace Rathalos.Servers.World.Core.Databases;

[Table("characters")]
public record CharacterRecord : BaseRecord
{
    /// <summary>
    /// Foreign key to the account that owns this character.
    /// </summary>
    public long AccountId { get; set; }

    /// <summary>
    /// Character name.
    /// </summary>
    public string Name { get; set; }

    /// <summary>
    /// Character state.
    /// </summary>
    public int RoleState { get; set; }

    /// <summary>
    /// Avatar Set ID.
    /// </summary>
    public byte AvatarSetId { get; set; }

    /// <summary>
    /// Star level stored as string representation.
    /// </summary>
    public string StarLevel { get; set; } = string.Empty;

    /// <summary>
    /// Current map ID where the character is located.
    /// </summary>
    public int MapId { get; set; }

    /// <summary>
    /// Current position (X, Y, Z) and rotation (W) on the map stored as a Quaternion.
    /// X = PositionX, Y = PositionY, Z = PositionZ, W = Rotation (in degrees).
    /// </summary>
    [Column(TypeName = "jsonb")]
    public Quaternion Position { get; set; }

    /// <summary>
    /// Character creation timestamp.
    /// </summary>
    public DateTime CreatedAt { get; set; } = DateTime.UtcNow;

    /// <summary>
    /// Last login timestamp.
    /// </summary>
    public DateTime? LastLogin { get; set; }

    /// <summary>
    /// Total playtime in seconds.
    /// </summary>
    public long PlaytimeSeconds { get; set; }

    /// <summary>
    /// Character attributes stored as a dictionary (attribute ID -> value as string).
    /// This includes appearance, stats, and other player attributes.
    /// </summary>
    [Column(TypeName = "jsonb")]
    public Dictionary<PlayerAttributeEnum, string> Attributes { get; set; } = [];
}
