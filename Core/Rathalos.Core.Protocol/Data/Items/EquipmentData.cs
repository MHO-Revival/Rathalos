using Rathalos.Core.Protocol.Data.Items;
using Rathalos.Core.Protocol.Messages.Custom.Csproto.Enums;
using Rathalos.Core.Protocol.Tools;
using System;

namespace Rathalos.Core.Protocol.Data.EquipData
{

    public sealed class EquipmentData : ItemBaseData
    {
        // --- Classification ---
        [TsvColumn("物品子类")] public EquipmentSubCategory? SubCategory { get; set; }
        
        // --- [CORE IDENTITY] ---
        [TsvColumn("材质")] public int? Material { get; set; }
        [TsvColumn("备注")] public string? Remarks { get; set; }
        [TsvColumn("武器类型")] public WeaponType? WeaponType { get; set; }
        [TsvColumn("默认武器")] public int? IsDefaultWeapon { get; set; }

        // --- [UPGRADES & FORTIFICATION] ---
        [TsvColumn("可否升级Rank")] public int? CanUpgradeRank { get; set; }
        [TsvColumn("Rank升级规则")] public int? RankUpgradeRule { get; set; }
        [TsvColumn("可否升级等级")] public int? CanUpgradeLevel { get; set; }
        [TsvColumn("等级升级规则")] public int? LevelUpgradeRule { get; set; }
        [TsvColumn("可否升级")] public int? CanUpgrade { get; set; }
        [TsvColumn("可否强化")] public int? CanFortify { get; set; }
        [TsvColumn("可强化等级")] public int? MaxFortifyLevel { get; set; }
        [TsvColumn("可突破等级")] public int? MaxBreakthroughLevel { get; set; }
        [TsvColumn("突破所需强化等级")] public int? BreakthroughReqFortify { get; set; }
        [TsvColumn("强化规则")] public int? FortifyRule { get; set; }
        [TsvColumn("强化特效1")] public string? FortifyEffect1 { get; set; }
        [TsvColumn("强化特效2")] public string? FortifyEffect2 { get; set; }
        [TsvColumn("强化特效3")] public string? FortifyEffect3 { get; set; }
        [TsvColumn("突破特效1")] public string? BreakthroughEffect1 { get; set; }
        [TsvColumn("突破特效2")] public string? BreakthroughEffect2 { get; set; }
        [TsvColumn("突破特效3")] public string? BreakthroughEffect3 { get; set; }
        [TsvColumn("觉醒索引编号")] public int? AwakenIndex { get; set; }
        [TsvColumn("觉醒等级1")] public int? AwakenLv1 { get; set; }
        [TsvColumn("觉醒等级2")] public int? AwakenLv2 { get; set; }
        [TsvColumn("觉醒等级3")] public int? AwakenLv3 { get; set; }
        [TsvColumn("直升规则集")] public string? DirectUpgradeRule { get; set; }

        // --- [COMBAT STATS] ---
        [TsvColumn("近远程类型")] public RangeType? RangeType { get; set; }
        [TsvColumn("武器长度")] public int? WeaponLength { get; set; }
        [TsvColumn("初始孔数")] public int? InitialSlots { get; set; }
        [TsvColumn("最大孔数")] public int? MaxSlots { get; set; }
        [TsvColumn("攻击力")] public int? Attack { get; set; }
        [TsvColumn("防御力")] public int? Defense { get; set; }
        [TsvColumn("会心等级")] public int? Affinity { get; set; }
        [TsvColumn("耐久度")] public int? Durability { get; set; }
        [TsvColumn("附加生命")] public int? BonusHp { get; set; }

        // --- [SHARPNESS] ---
        [TsvColumn("最大斩味值")] public int? MaxSharpness { get; set; }
        [TsvColumn("红色斩味数值")] public int? SharpRed { get; set; }
        [TsvColumn("橙色斩味数值")] public int? SharpOrange { get; set; }
        [TsvColumn("黄色斩味数值")] public int? SharpYellow { get; set; }
        [TsvColumn("绿色斩味数值")] public int? SharpGreen { get; set; }
        [TsvColumn("蓝色斩味数值")] public int? SharpBlue { get; set; }
        [TsvColumn("白色斩味数值")] public int? SharpWhite { get; set; }
        [TsvColumn("紫色斩味数值")] public int? SharpPurple { get; set; }
        [TsvColumn("铜色斩味数值")] public int? SharpBronze { get; set; }
        [TsvColumn("银色斩味数值")] public int? SharpSilver { get; set; }
        [TsvColumn("金色斩味数值")] public int? SharpGold { get; set; }

        // --- [ELEMENTS & RESISTANCES] ---
        [TsvColumn("水属性攻击力")] public int? AtkWater { get; set; }
        [TsvColumn("火属性攻击力")] public int? AtkFire { get; set; }
        [TsvColumn("雷属性攻击力")] public int? AtkThunder { get; set; }
        [TsvColumn("龙属性攻击力")] public int? AtkDragon { get; set; }
        [TsvColumn("冰属性攻击力")] public int? AtkIce { get; set; }
        [TsvColumn("毒附加")] public int? AtkPoison { get; set; }
        [TsvColumn("眠附加")] public int? AtkSleep { get; set; }
        [TsvColumn("麻附加")] public int? AtkPara { get; set; }
        [TsvColumn("爆破附加")] public int? AtkBlast { get; set; }
        [TsvColumn("水抗性")] public int? ResWater { get; set; }
        [TsvColumn("火抗性")] public int? ResFire { get; set; }
        [TsvColumn("雷抗性")] public int? ResThunder { get; set; }
        [TsvColumn("龙抗性")] public int? ResDragon { get; set; }
        [TsvColumn("冰抗性")] public int? ResIce { get; set; }

        // --- [ATTRIBUTES & PASSIVES] ---
        [TsvColumn("力量")] public int? Strength { get; set; }
        [TsvColumn("爆发")] public int? Burst { get; set; }
        [TsvColumn("运气")] public int? Luck { get; set; }
        [TsvColumn("体力")] public int? Constitution { get; set; }
        [TsvColumn("附加属性基因1ID")] public int? Gene1 { get; set; }
        [TsvColumn("附加属性基因2ID")] public int? Gene2 { get; set; }
        [TsvColumn("附加属性基因3ID")] public int? Gene3 { get; set; }
        [TsvColumn("附加属性基因4ID")] public int? Gene4 { get; set; }
        [TsvColumn("附加属性基因5ID")] public int? Gene5 { get; set; }
        [TsvColumn("附加属性基因6ID")] public int? Gene6 { get; set; }
        [TsvColumn("装备被动技1ID")] public int? Skill1Id { get; set; }
        [TsvColumn("值1")] public float? Skill1Val { get; set; }
        [TsvColumn("装备被动技2ID")] public int? Skill2Id { get; set; }
        [TsvColumn("值2")] public float? Skill2Val { get; set; }
        [TsvColumn("装备被动技3ID")] public int? Skill3Id { get; set; }
        [TsvColumn("值3")] public float? Skill3Val { get; set; }
        [TsvColumn("装备被动技4ID")] public int? Skill4Id { get; set; }
        [TsvColumn("值4")] public float? Skill4Val { get; set; }
        [TsvColumn("装备被动技5ID")] public int? Skill5Id { get; set; }
        [TsvColumn("值5")] public float? Skill5Val { get; set; }
        [TsvColumn("装备被动技6ID")] public int? Skill6Id { get; set; }
        [TsvColumn("值6")] public float? Skill6Val { get; set; }
        [TsvColumn("随机被动技大组")] public int? RandomSkillGroup { get; set; }

        // --- [MELEE GAUGES] ---
        [TsvColumn("气刃槽最大值")] public int? SpiritGaugeMax { get; set; }
        [TsvColumn("衰减速度")] public float? DecayRate { get; set; }
        [TsvColumn("LV1时间")] public int? SpiritLv1Time { get; set; }
        [TsvColumn("LV2时间")] public int? SpiritLv2Time { get; set; }
        [TsvColumn("LV3时间")] public int? SpiritLv3Time { get; set; }
        [TsvColumn("维持满状态时间")] public int? FullSpiritTime { get; set; }
        [TsvColumn("劲力槽1段")] public int? PowerGauge1 { get; set; }
        [TsvColumn("劲力槽2段")] public int? PowerGauge2 { get; set; }
        [TsvColumn("附加劲力值")] public int? ExtraPowerValue { get; set; }
        [TsvColumn("超耐槽最大值")] public int? HyperGaugeMax { get; set; }
        [TsvColumn("超耐值转化系数")] public float? HyperRatio { get; set; }
        [TsvColumn("额外增加值")] public int? ExtraAdd { get; set; }

        // --- [BOW MECHANICS] ---
        [TsvColumn("LV1蓄力")] public string? ChargeLv1 { get; set; }
        [TsvColumn("LV2蓄力")] public string? ChargeLv2 { get; set; }
        [TsvColumn("LV3蓄力")] public string? ChargeLv3 { get; set; }
        [TsvColumn("LV4蓄力")] public string? ChargeLv4 { get; set; }
        [TsvColumn("积攒满次数")] public int? AccumulateCount { get; set; }
        [TsvColumn("满槽速度")] public int? FillSpeed { get; set; }
        [TsvColumn("弓满槽值")] public int? BowFillValue { get; set; }
        [TsvColumn("箭筒")] public string? Quiver { get; set; }
        [TsvColumn("携带数量")] public int? CarryQuantity { get; set; }
        [TsvColumn("弦韧度")] public int? StringToughness { get; set; }
        [TsvColumn("曲射类型1")] public ArcShotType? ArcShot1 { get; set; }
        [TsvColumn("曲射类型2")] public ArcShotType? ArcShot2 { get; set; }
        [TsvColumn("曲射类型3")] public ArcShotType? ArcShot3 { get; set; }
        [TsvColumn("曲射类型4")] public ArcShotType? ArcShot4 { get; set; }
        [TsvColumn("携带瓶1种类")] public int? Bottle1Type { get; set; }
        [TsvColumn("携带瓶1数量")] public int? Bottle1Count { get; set; }
        [TsvColumn("携带瓶2种类")] public int? Bottle2Type { get; set; }
        [TsvColumn("携带瓶2数量")] public int? Bottle2Count { get; set; }
        [TsvColumn("携带瓶3种类")] public int? Bottle3Type { get; set; }
        [TsvColumn("携带瓶3数量")] public int? Bottle3Count { get; set; }
        [TsvColumn("携带瓶4种类")] public int? Bottle4Type { get; set; }
        [TsvColumn("携带瓶4数量")] public int? Bottle4Count { get; set; }
        [TsvColumn("携带瓶5种类")] public int? Bottle5Type { get; set; }
        [TsvColumn("携带瓶5数量")] public int? Bottle5Count { get; set; }
        [TsvColumn("特殊箭种类1")] public int? SpecArrow1Type { get; set; }
        [TsvColumn("特殊箭数量1")] public int? SpecArrow1Count { get; set; }
        [TsvColumn("特殊箭种类2")] public int? SpecArrow2Type { get; set; }
        [TsvColumn("特殊箭数量2")] public int? SpecArrow2Count { get; set; }
        [TsvColumn("特殊箭种类3")] public int? SpecArrow3Type { get; set; }
        [TsvColumn("特殊箭数量3")] public int? SpecArrow3Count { get; set; }

        // --- [BOWGUN MECHANICS] ---
        [TsvColumn("装填速度")] public string? ReloadSpeed { get; set; }
        [TsvColumn("晃动偏移")] public string? Deviation { get; set; }
        [TsvColumn("反动大小")] public string? Recoil { get; set; }
        [TsvColumn("射速")] public string? FireRate { get; set; }
        [TsvColumn("可用配件1")] public int? Mod1 { get; set; }
        [TsvColumn("可用配件2")] public int? Mod2 { get; set; }
        [TsvColumn("可用配件3")] public int? Mod3 { get; set; }
        [TsvColumn("配件3参数")] public string? Mod3Param { get; set; }
        [TsvColumn("可用配件4")] public int? Mod4 { get; set; }

        // --- [AMMO SLOT 1] ---
        [TsvColumn("可用子弹1")] public int? Ammo1 { get; set; }
        [TsvColumn("子弹1装填数量")] public int? Ammo1Count { get; set; }
        [TsvColumn("子弹1发射类型")] public AmmoFireType? Ammo1FireType { get; set; }
        [TsvColumn("子弹1后坐力")] public int? Ammo1Recoil { get; set; }

        // --- [AMMO SLOT 2] ---
        [TsvColumn("可用子弹2")] public int? Ammo2 { get; set; }
        [TsvColumn("子弹2装填数量")] public int? Ammo2Count { get; set; }
        [TsvColumn("子弹2发射类型")] public AmmoFireType? Ammo2FireType { get; set; }
        [TsvColumn("子弹2后坐力")] public int? Ammo2Recoil { get; set; }

        // --- [AMMO SLOT 3] ---
        [TsvColumn("可用子弹3")] public int? Ammo3 { get; set; }
        [TsvColumn("子弹3装填数量")] public int? Ammo3Count { get; set; }
        [TsvColumn("子弹3发射类型")] public AmmoFireType? Ammo3FireType { get; set; }
        [TsvColumn("子弹3后坐力")] public int? Ammo3Recoil { get; set; }

        // --- [AMMO SLOT 4] ---
        [TsvColumn("可用子弹4")] public int? Ammo4 { get; set; }
        [TsvColumn("子弹4装填数量")] public int? Ammo4Count { get; set; }
        [TsvColumn("子弹4发射类型")] public AmmoFireType? Ammo4FireType { get; set; }
        [TsvColumn("子弹4后坐力")] public int? Ammo4Recoil { get; set; }

        // --- [AMMO SLOT 5] ---
        [TsvColumn("可用子弹5")] public int? Ammo5 { get; set; }
        [TsvColumn("子弹5装填数量")] public int? Ammo5Count { get; set; }
        [TsvColumn("子弹5发射类型")] public AmmoFireType? Ammo5FireType { get; set; }
        [TsvColumn("子弹5后坐力")] public int? Ammo5Recoil { get; set; }

        // --- [AMMO SLOT 6] ---
        [TsvColumn("可用子弹6")] public int? Ammo6 { get; set; }
        [TsvColumn("子弹6装填数量")] public int? Ammo6Count { get; set; }
        [TsvColumn("子弹6发射类型")] public AmmoFireType? Ammo6FireType { get; set; }
        [TsvColumn("子弹6后坐力")] public int? Ammo6Recoil { get; set; }

        // --- [AMMO SLOT 7] ---
        [TsvColumn("可用子弹7")] public int? Ammo7 { get; set; }
        [TsvColumn("子弹7装填数量")] public int? Ammo7Count { get; set; }
        [TsvColumn("子弹7发射类型")] public AmmoFireType? Ammo7FireType { get; set; }
        [TsvColumn("子弹7后坐力")] public int? Ammo7Recoil { get; set; }

        // --- [AMMO SLOT 8] ---
        [TsvColumn("可用子弹8")] public int? Ammo8 { get; set; }
        [TsvColumn("子弹8装填数量")] public int? Ammo8Count { get; set; }
        [TsvColumn("子弹8发射类型")] public AmmoFireType? Ammo8FireType { get; set; }
        [TsvColumn("子弹8后坐力")] public int? Ammo8Recoil { get; set; }

        // --- [AMMO SLOT 9] ---
        [TsvColumn("可用子弹9")] public int? Ammo9 { get; set; }
        [TsvColumn("子弹9装填数量")] public int? Ammo9Count { get; set; }
        [TsvColumn("子弹9发射类型")] public AmmoFireType? Ammo9FireType { get; set; }
        [TsvColumn("子弹9后坐力")] public int? Ammo9Recoil { get; set; }

        // --- [AMMO SLOT 10] ---
        [TsvColumn("可用子弹10")] public int? Ammo10 { get; set; }
        [TsvColumn("子弹10装填数量")] public int? Ammo10Count { get; set; }
        [TsvColumn("子弹10发射类型")] public AmmoFireType? Ammo10FireType { get; set; }
        [TsvColumn("子弹10后坐力")] public int? Ammo10Recoil { get; set; }

        // --- [AMMO SLOT 11] ---
        [TsvColumn("可用子弹11")] public int? Ammo11 { get; set; }
        [TsvColumn("子弹11装填数量")] public int? Ammo11Count { get; set; }
        [TsvColumn("子弹11发射类型")] public AmmoFireType? Ammo11FireType { get; set; }
        [TsvColumn("子弹11后坐力")] public int? Ammo11Recoil { get; set; }

        // --- [AMMO SLOT 12] ---
        [TsvColumn("可用子弹12")] public int? Ammo12 { get; set; }
        [TsvColumn("子弹12装填数量")] public int? Ammo12Count { get; set; }
        [TsvColumn("子弹12发射类型")] public AmmoFireType? Ammo12FireType { get; set; }
        [TsvColumn("子弹12后坐力")] public int? Ammo12Recoil { get; set; }

        // --- [AMMO SLOT 13] ---
        [TsvColumn("可用子弹13")] public int? Ammo13 { get; set; }
        [TsvColumn("子弹13装填数量")] public int? Ammo13Count { get; set; }
        [TsvColumn("子弹13发射类型")] public AmmoFireType? Ammo13FireType { get; set; }
        [TsvColumn("子弹13后坐力")] public int? Ammo13Recoil { get; set; }

        // --- [AMMO SLOT 14] ---
        [TsvColumn("可用子弹14")] public int? Ammo14 { get; set; }
        [TsvColumn("子弹14装填数量")] public int? Ammo14Count { get; set; }
        [TsvColumn("子弹14发射类型")] public AmmoFireType? Ammo14FireType { get; set; }
        [TsvColumn("子弹14后坐力")] public int? Ammo14Recoil { get; set; }

        // --- [AMMO SLOT 15] ---
        [TsvColumn("可用子弹15")] public int? Ammo15 { get; set; }
        [TsvColumn("子弹15装填数量")] public int? Ammo15Count { get; set; }
        [TsvColumn("子弹15发射类型")] public AmmoFireType? Ammo15FireType { get; set; }
        [TsvColumn("子弹15后坐力")] public int? Ammo15Recoil { get; set; }

        // --- [HORN & GUNLANCE] ---
        [TsvColumn("音符1")] public int? MusicNote1 { get; set; }
        [TsvColumn("音符2")] public int? MusicNote2 { get; set; }
        [TsvColumn("音符3")] public int? MusicNote3 { get; set; }
        [TsvColumn("旋律1")] public int? Melody1 { get; set; }
        [TsvColumn("旋律2")] public int? Melody2 { get; set; }
        [TsvColumn("旋律3")] public int? Melody3 { get; set; }
        [TsvColumn("旋律4")] public int? Melody4 { get; set; }
        [TsvColumn("旋律5")] public int? Melody5 { get; set; }
        [TsvColumn("旋律6")] public int? Melody6 { get; set; }
        [TsvColumn("旋律7")] public int? Melody7 { get; set; }
        [TsvColumn("旋律8")] public int? Melody8 { get; set; }
        [TsvColumn("旋律9")] public int? Melody9 { get; set; }
        [TsvColumn("旋律10")] public int? Melody10 { get; set; }
        [TsvColumn("炮击类型")] public ShellingType? ShellingType { get; set; }
        [TsvColumn("炮击等级")] public int? ShellingLevel { get; set; }
        [TsvColumn("最大弹数")] public int? MaxShells { get; set; }

        // --- [COSMETIC & SYSTEM] ---
        [TsvColumn("染色规则")] public int? DyeRule { get; set; }
        [TsvColumn("是否投放")] public int? IsReleased { get; set; }
        [TsvColumn("高跟鞋")] public int? HighHeels { get; set; }
        [TsvColumn("套装ID")] public int? SetId { get; set; }
        [TsvColumn("是否被幻化")] public int? IsTransmogged { get; set; }
        [TsvColumn("是否幻化")] public int? CanTransmog { get; set; }
        [TsvColumn("幻化消耗")] public string? TransmogCost { get; set; }
        [TsvColumn("淬炼规则")] public int? RefineRule { get; set; }
        [TsvColumn("淬炼等级上限")] public int? RefineMaxLevel { get; set; }
        [TsvColumn("是否允许退火")] public int? AllowAnneal { get; set; }
        [TsvColumn("升级消耗规则")] public int? UpgradeCostRule { get; set; }
        [TsvColumn("等级提升上限")] public int? LevelCapIncrease { get; set; }
        [TsvColumn("粘合剂id")] public int? AdhesiveId { get; set; }
        [TsvColumn("粘合剂数量")] public int? AdhesiveCount { get; set; }
        [TsvColumn("是否为残兵")] public int? IsBrokenWeapon { get; set; }
        [TsvColumn("护石熔炼规则")] public int? TalismanRule { get; set; }

        // --- [GROWTH STATS] ---
        [TsvColumn("攻击力成长")] public float? G_Attack { get; set; }
        [TsvColumn("防御力成长")] public float? G_Defense { get; set; }
        [TsvColumn("附加生命成长")] public float? G_Hp { get; set; }
        [TsvColumn("水属性攻击力成长")] public float? G_WaterAtk { get; set; }
        [TsvColumn("火属性攻击力成长")] public float? G_FireAtk { get; set; }
        [TsvColumn("雷属性攻击力成长")] public float? G_ThunderAtk { get; set; }
        [TsvColumn("龙属性攻击力成长")] public float? G_DragonAtk { get; set; }
        [TsvColumn("冰属性攻击力成长")] public float? G_IceAtk { get; set; }
        [TsvColumn("水抗性成长")] public float? G_WaterRes { get; set; }
        [TsvColumn("火抗性成长")] public float? G_FireRes { get; set; }
        [TsvColumn("雷抗性成长")] public float? G_ThunderRes { get; set; }
        [TsvColumn("龙抗性成长")] public float? G_DragonRes { get; set; }
        [TsvColumn("冰抗性成长")] public float? G_IceRes { get; set; }
        [TsvColumn("力量成长")] public float? G_Strength { get; set; }
        [TsvColumn("爆发成长")] public float? G_Burst { get; set; }
        [TsvColumn("运气成长")] public float? G_Luck { get; set; }
        [TsvColumn("体力成长")] public float? G_Constitution { get; set; }
        [TsvColumn("毒附加成长")] public float? G_Poison { get; set; }
        [TsvColumn("眠附加成长")] public float? G_Sleep { get; set; }
        [TsvColumn("麻附加成长")] public float? G_Para { get; set; }
        [TsvColumn("爆破附加成长")] public float? G_Blast { get; set; }
    }
}
