using Rathalos.Core.ORM;
using System.ComponentModel.DataAnnotations.Schema;

namespace Rathalos.Servers.World.Core.Databases.Records
{
    [Table("monster_perceptions")]
    public record MonsterPerceptionRecord : BaseRecord
    {
        public int MonsterID { get; set; }
        public string? EyeBoneLeft { get; set; }
        public string? EyeBoneRight { get; set; }
        public string? EyeBoneCenter { get; set; }
        public float VisionConeHeight { get; set; }
        public float VisionConeAngle { get; set; }
        public float VisionConeAngleAlert { get; set; }
        public string? HearingBone { get; set; }
        public float HearingDistance { get; set; }
        public float HearingDistanceExNear { get; set; }
        public float HearingDistanceNear { get; set; }
        public float HearingDistanceMedium { get; set; }
        public float HearingDistanceFar { get; set; }
        public float HearingThredAlert { get; set; }
        public float HearingThredPreComb { get; set; }
    }
}
