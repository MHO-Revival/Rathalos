using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Protocol.Tools;

namespace Rathalos.Core.Protocol.Data.Items
{
    public class SkillPearlData : ItemData
    {
        // --- Socketing Logic ---
        [TsvColumn("镶嵌需求孔数")] public int SocketRequirement { get; set; }
        [TsvColumn("镶嵌需求装备等级Min")] public int MinEquipLevel { get; set; }
        [TsvColumn("镶嵌需求装备等级Max")] public int MaxEquipLevel { get; set; }

        // --- Passive Skill Points (1-4) ---
        [TsvColumn("对应技能1ID")] public int Skill1Id { get; set; }
        [TsvColumn("点数1")] public int Skill1Points { get; set; }

        [TsvColumn("对应技能2ID")] public int Skill2Id { get; set; }
        [TsvColumn("点数2")] public int Skill2Points { get; set; }

        [TsvColumn("对应技能3ID")] public int Skill3Id { get; set; }
        [TsvColumn("点数3")] public int Skill3Points { get; set; }

        [TsvColumn("对应技能4ID")] public int Skill4Id { get; set; }
        [TsvColumn("点数4")] public int Skill4Points { get; set; }
    }
}
