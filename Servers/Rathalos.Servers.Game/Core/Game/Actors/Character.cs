using Rathalos.Core.Protocol.Messages.Csproto;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Servers.World.Core.Databases;
using Rathalos.Servers.World.Core.Game.Helpers;
using Rathalos.Servers.World.Core.Game.Stats;
using Rathalos.Servers.World.Core.Network;
using Rathalos.Servers.World.Services;
using System.Numerics;
using Quaternion = System.Numerics.Quaternion;

namespace Rathalos.Servers.World.Core.Game.Actors
{
    /// <summary>
    /// Represents an in-game character actor with movement and map capabilities.
    /// </summary>
    public class Character
    {
        private bool _connected;

        public WorldClient Client { get; }
        public CharacterRecord Record { get; }
        public PlayerAttributes Attributes { get; }
        public Vector3 Position { get; private set; }
        public float Rotation { get; private set; }
        public string Name
        {
            get => Record.Name;
            set
            {
                Attributes.CharName = value;
                Record.Name = value;
            }
        }

        /// <summary>
        /// Creates a new character instance from a database record.
        /// </summary>
        /// <param name="record">The character database record.</param>
        public Character(WorldClient client, CharacterRecord record)
        {
            Client = client;
            Record = record ?? throw new ArgumentNullException(nameof(record));
            Attributes = new PlayerAttributes();
            LoadRecord(record);
        }

        private void LoadRecord(CharacterRecord record)
        {
            Position = new Vector3(record.Position.X, record.Position.Y, record.Position.Z);
            Rotation = record.Position.W;

            // Then load saved attributes from record (overriding defaults where applicable)
            Attributes.LoadFromRecord(record.Attributes);
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

            var moveDistance = Attributes.CharSpeed * deltaTime;

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


        internal void LogIn()
        {
            Record.LastLogin = DateTime.UtcNow;
            //Client.Send(new CSBackToTown { RoleID = Record.Id, Uin = Client.Uin });
            Client.Send(new CSTownSessionStart
            {
                ErrNo = 0,
            });
        }

        public void Save(Rathalos.Core.ORM.RathalosDbContext db)
        {
            // Sync attributes back to record
            Record.Attributes = Attributes.GetRecord();

            Record.Position = new Quaternion
            {
                X = Position.X,
                Y = Position.Y,
                Z = Position.Z,
                W = Rotation
            };

            db.Save(Record);
        }

        public CSRoleBaseInfo GetCSRoleBaseInfo()
        {
            return new CSRoleBaseInfo
            {
                RoleID = (ulong)Record.Id,
                RoleState = Record.RoleState,
                RoleStateEndLeftTime = 0,
                Equip = [
                    new CSAvatarItem{
                        ItemType = 120005,
                        PosIndex = 1,
                    }
                ],
                AvatarSetID = Record.AvatarSetId,
                FacialInfo = Attributes.GetAllFacialInfo(),
                FaceId = (ushort)Attributes.MaleFace,
                HairId = (ushort)Attributes.MaleHair,
                UnderclothesId = (ushort)Attributes.UnderClothes,
                EyeBall = Attributes.EyeBall,
                EyeColor = Attributes.EyeColor,
                FaceTattooIndex = Attributes.FaceTattooIndex,
                FaceTattooColor = Attributes.FaceTattooColor,
                SkinColor = Attributes.SkinColor,
                HairColor = Attributes.HairColor,
                InnerColor = Attributes.InnerColor,
                Gender = (byte)Attributes.CharSex,
                HideFashion = (byte)(Attributes.HideFashion ? 1 : 0),
                HideHelm = (byte)(Attributes.HideHelm ? 1 : 0),
                HideSuite = (byte)(Attributes.HideSuite ? 1 : 0),
                HRLevel = Attributes.CharHRPoint,
                Name = Attributes.CharName,
                Level = ExperienceService.Instance.GetLevelForExperience(Attributes.CharExp),
                StarLevel = Record.StarLevel,
                SoulStoneLv = Attributes.SoulStoneLevel,
                RoleIndex = Client.Characters.FindIndex(c => c.Record.Id == this.Record.Id),
            };
        }

    }
}
