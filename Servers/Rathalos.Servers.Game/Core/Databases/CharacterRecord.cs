using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;
using System.Numerics;

namespace Rathalos.Servers.World.Core.Databases
{
    [Table("characters")]
    public record CharacterRecord : BaseRecord
    {
        /// <summary>
        /// Foreign key to the account that owns this character.
        /// </summary>
        public long AccountId { get; set; }

        /// <summary>
        /// Role ID (unique identifier for the character).
        /// </summary>
        public ulong RoleId { get; set; }

        /// <summary>
        /// Role Index (slot index for the character).
        /// </summary>
        public int RoleIndex { get; set; }

        /// <summary>
        /// Character name.
        /// </summary>
        public string Name { get; set; } = string.Empty;

        /// <summary>
        /// Character gender (0 = Male, 1 = Female).
        /// </summary>
        public byte Gender { get; set; }

        /// <summary>
        /// Character level.
        /// </summary>
        public int Level { get; set; } = 1;

        /// <summary>
        /// Character HR (Hunter Rank) level.
        /// </summary>
        public int HRLevel { get; set; }

        /// <summary>
        /// Character state.
        /// </summary>
        public int RoleState { get; set; }

        /// <summary>
        /// Avatar Set ID.
        /// </summary>
        public byte AvatarSetId { get; set; }

        /// <summary>
        /// Face type ID.
        /// </summary>
        public ushort FaceId { get; set; }

        /// <summary>
        /// Hair style ID.
        /// </summary>
        public ushort HairId { get; set; }

        /// <summary>
        /// Underclothes ID.
        /// </summary>
        public ushort UnderclothesId { get; set; }

        /// <summary>
        /// Skin color.
        /// </summary>
        public int SkinColor { get; set; }

        /// <summary>
        /// Hair color.
        /// </summary>
        public int HairColor { get; set; }

        /// <summary>
        /// Inner color.
        /// </summary>
        public int InnerColor { get; set; }

        /// <summary>
        /// Eye ball type.
        /// </summary>
        public int EyeBall { get; set; }

        /// <summary>
        /// Eye color.
        /// </summary>
        public int EyeColor { get; set; }

        /// <summary>
        /// Face tattoo index.
        /// </summary>
        public int FaceTattooIndex { get; set; }

        /// <summary>
        /// Face tattoo color.
        /// </summary>
        public int FaceTattooColor { get; set; }

        /// <summary>
        /// Whether to hide helmet.
        /// </summary>
        public bool HideHelm { get; set; }

        /// <summary>
        /// Whether to hide fashion.
        /// </summary>
        public bool HideFashion { get; set; }

        /// <summary>
        /// Whether to hide suite.
        /// </summary>
        public bool HideSuite { get; set; }

        /// <summary>
        /// Star level.
        /// </summary>
        public string StarLevel { get; set; } = string.Empty;

        /// <summary>
        /// Soul stone level.
        /// </summary>
        public int SoulStoneLv { get; set; }

        /// <summary>
        /// Facial customization info stored as JSON.
        /// </summary>
        [Column(TypeName = "jsonb")]
        public short[] FacialInfo { get; set; } = [];

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
        /// Experience points.
        /// </summary>
        public long Experience { get; set; }

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
        /// Navigation property to account.
        /// </summary>
        [ForeignKey(nameof(AccountId))]
        public virtual AccountRecord? Account { get; set; }
    }
}
