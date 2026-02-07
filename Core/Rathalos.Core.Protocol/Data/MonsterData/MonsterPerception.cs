namespace Rathalos.Core.Protocol.Data.MonsterData
{
    public class MonsterPerception
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
