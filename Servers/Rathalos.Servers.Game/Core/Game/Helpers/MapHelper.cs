using System.Numerics;

namespace Rathalos.Servers.World.Core.Game.Helpers
{
    /// <summary>
    /// Provides utility methods for map-related calculations such as distance and range checks.
    /// </summary>
    public static class MapHelper
    {
        /// <summary>
        /// Calculates the distance between two 3D positions.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <returns>The distance between the two positions.</returns>
        public static float Distance(Vector3 from, Vector3 to)
        {
            return Vector3.Distance(from, to);
        }

        /// <summary>
        /// Calculates the squared distance between two 3D positions (faster, avoids square root).
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <returns>The squared distance between the two positions.</returns>
        public static float DistanceSquared(Vector3 from, Vector3 to)
        {
            return Vector3.DistanceSquared(from, to);
        }

        /// <summary>
        /// Checks if a position is within range of another position.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <param name="range">The range to check.</param>
        /// <returns>True if within range.</returns>
        public static bool IsInRange(Vector3 from, Vector3 to, float range)
        {
            return DistanceSquared(from, to) <= range * range;
        }

        /// <summary>
        /// Calculates the rotation angle (in degrees) to face a target position from a source position.
        /// Assumes Y is up and rotation is around the Y axis.
        /// </summary>
        /// <param name="from">The source position.</param>
        /// <param name="to">The target position to face.</param>
        /// <returns>The rotation angle in degrees (0-360).</returns>
        public static float CalculateRotationTowards(Vector3 from, Vector3 to)
        {
            var direction = to - from;
            if (direction.LengthSquared() <= 0)
                return 0f;

            var angle = MathF.Atan2(direction.X, direction.Z) * (180f / MathF.PI);
            return NormalizeRotation(angle);
        }

        /// <summary>
        /// Normalizes a rotation angle to be within 0-360 degrees.
        /// </summary>
        /// <param name="rotation">The rotation angle in degrees.</param>
        /// <returns>The normalized rotation angle (0-360).</returns>
        public static float NormalizeRotation(float rotation)
        {
            rotation %= 360f;
            if (rotation < 0) rotation += 360f;
            return rotation;
        }

        /// <summary>
        /// Calculates the 2D distance (ignoring Y axis) between two positions.
        /// Useful for ground-based distance checks.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <returns>The 2D distance between the two positions.</returns>
        public static float Distance2D(Vector3 from, Vector3 to)
        {
            var dx = to.X - from.X;
            var dz = to.Z - from.Z;
            return MathF.Sqrt(dx * dx + dz * dz);
        }

        /// <summary>
        /// Checks if a position is within 2D range (ignoring Y axis) of another position.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <param name="range">The range to check.</param>
        /// <returns>True if within 2D range.</returns>
        public static bool IsInRange2D(Vector3 from, Vector3 to, float range)
        {
            var dx = to.X - from.X;
            var dz = to.Z - from.Z;
            return (dx * dx + dz * dz) <= range * range;
        }

        /// <summary>
        /// Calculates a position moved towards a target by a specified distance.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <param name="maxDistance">The maximum distance to move.</param>
        /// <returns>The new position after moving.</returns>
        public static Vector3 MoveTowards(Vector3 from, Vector3 to, float maxDistance)
        {
            var direction = to - from;
            var distance = direction.Length();

            if (distance <= 0 || distance <= maxDistance)
                return to;

            return from + Vector3.Normalize(direction) * maxDistance;
        }

        /// <summary>
        /// Linearly interpolates between two positions.
        /// </summary>
        /// <param name="from">The starting position.</param>
        /// <param name="to">The target position.</param>
        /// <param name="t">The interpolation factor (0-1).</param>
        /// <returns>The interpolated position.</returns>
        public static Vector3 Lerp(Vector3 from, Vector3 to, float t)
        {
            t = Math.Clamp(t, 0f, 1f);
            return Vector3.Lerp(from, to, t);
        }
    }
}
