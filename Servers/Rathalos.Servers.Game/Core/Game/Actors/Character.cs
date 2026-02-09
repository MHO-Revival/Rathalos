using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Game.Helpers;
using System.Numerics;
using Quaternion = System.Numerics.Quaternion;

namespace Rathalos.Servers.World.Core.Game.Actors
{
    /// <summary>
    /// Represents an in-game character actor with movement and map capabilities.
    /// </summary>
    public class Character
    {
        /// <summary>
        /// The underlying database record for this character.
        /// </summary>
        public CharacterRecord Record { get; }

        /// <summary>
        /// Current position as a 3D vector.
        /// </summary>
        public Vector3 Position { get; private set; }

        /// <summary>
        /// Current rotation/direction in degrees.
        /// </summary>
        public float Rotation { get; private set; }

        /// <summary>
        /// Movement speed (units per second).
        /// </summary>
        public float MovementSpeed { get; set; } = 5.0f;

        /// <summary>
        /// Creates a new character instance from a database record.
        /// </summary>
        /// <param name="record">The character database record.</param>
        public Character(CharacterRecord record)
        {
            Record = record ?? throw new ArgumentNullException(nameof(record));
            Position = new Vector3(record.Position.X, record.Position.Y, record.Position.Z);
            Rotation = record.Position.W;
        }

        /// <summary>
        /// Sets the character's position directly (teleport).
        /// </summary>
        /// <param name="position">The new position.</param>
        public void SetPosition(Quaternion quaternion)
        {
            Position = new Vector3(quaternion.X, quaternion.Y, quaternion.Z);
            Rotation = quaternion.W;
        }

        /// <summary>
        /// Sets the character's position directly (teleport).
        /// </summary>
        /// <param name="x">X coordinate.</param>
        /// <param name="y">Y coordinate.</param>
        /// <param name="z">Z coordinate.</param>
        public void SetPosition(float x, float y, float z)
        {
            SetPosition(new Quaternion(x, y, z, Rotation));
        }

        /// <summary>
        /// Sets the character's rotation/direction.
        /// </summary>
        /// <param name="rotation">The new rotation in degrees.</param>
        public void SetRotation(float rotation)
        {
            SetPosition(new Quaternion(Position.X, Position.Y, Position.Z, MapHelper.NormalizeRotation(rotation)));
        }

        /// <summary>
        /// Moves the character towards a target position by a given delta time.
        /// </summary>
        /// <param name="target">The target position to move towards.</param>
        /// <param name="deltaTime">Time elapsed in seconds.</param>
        /// <returns>True if arrived at destination, false otherwise.</returns>
        public bool MoveTowards(Vector3 target, float deltaTime)
        {
            var distanceToTarget = MapHelper.Distance(Position, target);

            if (distanceToTarget <= 0)
                return true;

            var moveDistance = MovementSpeed * deltaTime;

            if (moveDistance >= distanceToTarget)
            {
                Position = target;
                return true;
            }

            Position = MapHelper.MoveTowards(Position, target, moveDistance);
            SetRotation(MapHelper.CalculateRotationTowards(Position, target));
            return false;
        }

        /// <summary>
        /// Moves the character towards a target position by a given delta time.
        /// </summary>
        /// <param name="x">Target X coordinate.</param>
        /// <param name="y">Target Y coordinate.</param>
        /// <param name="z">Target Z coordinate.</param>
        /// <param name="deltaTime">Time elapsed in seconds.</param>
        /// <returns>True if arrived at destination, false otherwise.</returns>
        public bool MoveTowards(float x, float y, float z, float deltaTime)
        {
            return MoveTowards(new Vector3(x, y, z), deltaTime);
        }

        /// <summary>
        /// Teleports the character to a different map at the specified position.
        /// </summary>
        /// <param name="mapId">The target map ID.</param>
        /// <param name="position">The position on the new map.</param>
        /// <param name="rotation">Optional rotation on the new map.</param>
        public void TeleportToMap(int mapId, Vector3 position, float? rotation = null)
        {
            Record.MapId = mapId;
            Position = position;
            if (rotation.HasValue)
            {
                Rotation = MapHelper.NormalizeRotation(rotation.Value);
            }
        }

        /// <summary>
        /// Teleports the character to a different map at the specified position.
        /// </summary>
        /// <param name="mapId">The target map ID.</param>
        /// <param name="x">X coordinate on the new map.</param>
        /// <param name="y">Y coordinate on the new map.</param>
        /// <param name="z">Z coordinate on the new map.</param>
        /// <param name="rotation">Optional rotation on the new map.</param>
        public void TeleportToMap(int mapId, float x, float y, float z, float? rotation = null)
        {
            TeleportToMap(mapId, new Vector3(x, y, z), rotation);
        }

        public void Save()
        {
            Record.Position = new Quaternion
            {
                X = Position.X,
                Y = Position.Y,
                Z = Position.Z,
                W = Rotation
            };
        }

        public CSRoleBaseInfo GetCSRoleBaseInfo()
        {
            return new CSRoleBaseInfo
            {
                RoleID = (ulong)Record.Id,
                RoleIndex = Record.RoleIndex,
                RoleState = Record.RoleState,
                RoleStateEndLeftTime = 0,
                Equip = [],
                AvatarSetID = Record.AvatarSetId,
                FacialInfo = Record.FacialInfo,
                FaceId = Record.FaceId,
                HairId = Record.HairId,
                UnderclothesId = Record.UnderclothesId,
                EyeBall = Record.EyeBall,
                EyeColor = Record.EyeColor,
                FaceTattooIndex = Record.FaceTattooIndex,
                FaceTattooColor = Record.FaceTattooColor,
                SkinColor = Record.SkinColor,
                HairColor = Record.HairColor,
                InnerColor = Record.InnerColor,
                Gender = Record.Gender,
                HideFashion = (byte)(Record.HideFashion ? 1 : 0),
                HideHelm = (byte)(Record.HideHelm ? 1 : 0),
                HideSuite = (byte)(Record.HideSuite ? 1 : 0),
                HRLevel = Record.HRLevel,
                Name = Record.Name,
                Level = Record.Level,
                StarLevel = Record.StarLevel,
                SoulStoneLv = Record.SoulStoneLv,
            };
        }
    }
}
