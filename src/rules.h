/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RULES.H
 *
 *  @authors       CCHyper
 *
 *  @brief         General rules that control the game.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include "typelist.h"


class NoInitClass;
struct IStream;
class CCINIClass;
class UnitTypeClass;
class BuildingTypeClass;
class AnimTypeClass;
class WeaponTypeClass;
class VoxelAnimTypeClass;
class ParticleSystemTypeClass;
class OverlayTypeClass;
class SmudgeTypeClass;
class AircraftTypeClass;
class InfantryTypeClass;
class WarheadTypeClass;
class BulletTypeClass;
class TerrainTypeClass;


class DifficultyClass
{
public:
    double FirepowerBias;
    double GroundspeedBias;
    double AirspeedBias;
    double ArmorBias;
    double ROFBias;
    double CostBias;
    double BuildSpeedBias;
    double RepairDelay;
    double BuildDelay;
    bool IsBuildSlowdown;
    bool IsWallDestroyer;
    bool IsContentScan;
};


class RulesClass
{
public:
    RulesClass();
    RulesClass(const NoInitClass& x);
    ~RulesClass();

    void Process(CCINIClass& ini);
    void Initialize(CCINIClass& ini);

    void Addition(CCINIClass& ini) { Process(ini); }

    void Save(IStream* pStm);
    void Load(IStream* pStm);

    void Detach(AbstractClass* target, bool all = true);

    static int Get_Art_Unique_ID();
    static int Get_AI_Unique_ID();
    static void Load_Art_INI();
    static void Load_ArtFS_INI();
    static void Load_FSRule_INI();

public:
    bool SpecialWeapons(CCINIClass& ini);
    bool AudioVisual(CCINIClass& ini);
    bool CrateRules(CCINIClass& ini);
    bool CombatDamage(CCINIClass& ini);
    bool Colors(CCINIClass& ini);
    bool General(CCINIClass& ini);
    bool MPlayer(CCINIClass& ini);
    bool Heap_Maximums(CCINIClass& ini);
    bool Infantry(CCINIClass& ini);
    bool Houses(CCINIClass& ini);
    bool Vehicles(CCINIClass& ini);
    bool Aircraft(CCINIClass& ini);
    bool Sides(CCINIClass& ini);
    bool SuperWeapons(CCINIClass& ini);
    bool Buildings(CCINIClass& ini);
    bool Terrains(CCINIClass& ini);
    bool Teams(CCINIClass& ini);
    bool Smudges(CCINIClass& ini);
    bool Overlays(CCINIClass& ini);
    bool Animations(CCINIClass& ini);
    bool VoxelAnims(CCINIClass& ini);
    bool Warheads(CCINIClass& ini);
    bool Particles(CCINIClass& ini);
    bool ParticleSystems(CCINIClass& ini);
    bool AI(CCINIClass& ini);
    bool Powerups(CCINIClass& ini);
    bool Land_Types(CCINIClass& ini);
    bool IQ(CCINIClass& ini);
    bool JumpjetControls(CCINIClass& ini);
    bool Difficulty(CCINIClass& ini);
    bool Movies(CCINIClass& ini);
    bool Objects(CCINIClass& ini);

public:
    int AmmoCrateDamage;
    UnitTypeClass* LargeVisceroid;
    UnitTypeClass* SmallVisceroid;
    UnitTypeClass* UnloadingHarvester;
    int AttackingAircraftSightRange;
    double TunnelSpeed;
    double TiberiumHeal;
    TypeList<BuildingTypeClass*> HSBuilding;
    bool IsFreeMCV;
    bool IsBerzerkAllowed;
    Dir256 PoseDir;
    AnimTypeClass* DropPodPuff;
    int WaypointAnimationSpeed;
    AnimTypeClass* BarrelExplode;
    TypeList<VoxelAnimTypeClass*> BarrelDebris;
    ParticleSystemTypeClass* BarrelParticle;
    float RadarEventColorSpeed;
    int RadarEventMinRadius;
    float RadarEventSpeed;
    float RadarEventRotationSpeed;
    int FlashFrameTime;
    int RadarCombatFlashTime;
    int MaxWaypointPathLength;
    AnimTypeClass* Wake;
    AnimTypeClass* FlamingInfantry;
    double AITriggerSuccessWeightDelta;
    double AITriggerFailureWeightDelta;
    double AITriggerTrackRecordCoefficient;
    int VeinholeMonsterStrength;
    int MaxVeinholeGrowth;
    int VeinholeGrowthRate;
    int VeinholeShrinkRate;
    AnimTypeClass* VeinAttack;
    int VeinDamage;
    int MaximumQueuedObjects;
    int AircraftFogReveal;
    const OverlayTypeClass* WoodCrateImage;
    const OverlayTypeClass* SteelCrateImage;
    TypeList<AnimTypeClass*> DropPod;
    TypeList<AnimTypeClass*> DeadBodies;
    TypeList<AnimTypeClass*> MetallicDebris;
    TypeList<AnimTypeClass*> BridgeExplosions;
    VocType DigSound;
    AnimTypeClass* Dig;
    AnimTypeClass* IonBlast;
    AnimTypeClass* IonBeam;
    AnimTypeClass* InfantryExplode;
    AnimTypeClass* AtmosphereEntry;
    TypeList<int> PrerequisitePower;
    TypeList<int> PrerequisiteFactory;
    TypeList<int> PrerequisiteBarracks;
    TypeList<int> PrerequisiteRadar;
    TypeList<int> PrerequisiteTech;
    VocType GateUpSound;
    VocType GateDownSound;
    int JumpjetTurnRate;
    int JumpjetSpeed;
    double JumpjetClimb;
    int JumpjetCruiseHeight;
    double JumpjetAcceleration;
    double JumpjetWobblesPerSecond;
    int JumpjetWobbleDeviation;
    TypeList<int> RadarEventSuppressionDistances;
    TypeList<int> RadarEventVisibilityDurations;
    TypeList<int> RadarEventDurations;
    int IonCannonDamage;
    int RailgunDamageRadius;
    double ZoomInFactor;
    double ConditionRedSparkingProbability;
    double ConditionYellowSparkingProbability;
    int TiberiumExplosionDamage;
    int TiberiumStrength;
    double MinProductionSpeed;
    double MultipleFactory;
    int CraterLevel;
    double TreeFlammability;
    double MissileSpeedVar;
    double MissileROTVar;
    WeaponTypeClass* DropPodWeapon;
    int DropPodHeight;
    int DropPodSpeed;
    double DropPodAngle;
    double ScrollMultiplier;
    double CrewEscape;
    int ShakeScreen;
    int HoverHeight;
    double HoverBob;
    double HoverBoost;
    double HoverAcceleration;
    double HoverBrake;
    double HoverDampen;
    double PlacementDelay;
    TypeList<VoxelAnimTypeClass*> ExplosiveVoxelDebris;
    VoxelAnimTypeClass* TireVoxelDebris;
    VoxelAnimTypeClass* ScrapVoxelDebris;
    int BridgeVoxelMax;
    int CloakingStages;
    int RevealTriggerRadius;
    double IceCrackingWeight;
    double IceBreakingWeight;
    TypeList<VocType> IceCrackSounds;
    unsigned char CliffBackImpassability;
    double VeteranRatio;
    double VeteranCombat;
    double VeteranSpeed;
    double VeteranSight;
    double VeteranArmor;
    double VeteranROF;
    double VeteranCap;
    VocType CloakSound;
    VocType SellSound;
    VocType GameClosed;
    VocType IncomingMessage;
    VocType SystemError;
    VocType OptionsChanged;
    VocType GameForming;
    VocType PlayerLeft;
    VocType PlayerJoined;
    VocType Construction;
    TypeList<VocType> CreditTicks;
    VocType CrumbleSound;
    VocType BuildingSlam;
    VocType RadarOn;
    VocType RadarOff;
    VocType ScoldSound;
    VocType TeslaCharge;
    VocType TeslaZap;
    VocType GenericClick;
    VocType GenericBeep;
    VocType BlowupSound;
    VocType HealCrateSound;
    VocType ChuteSound;
    VocType StopSound;
    VocType GuardSound;
    VocType ScatterSound;
    VocType DeploySound;
    VocType LightningSound;
    double WorstLowPowerBuildRateCoefficient;
    double BestLowPowerBuildRateCoefficient;
    double WallBuildSpeedCoefficient;
    double ChargeToDrainRatio;
    double DamageToFirestormDamageCoefficient;
    double TrackedUphill;
    double TrackedDownhill;
    double WheeledUphill;
    double WheeledDownhill;
    int SpotlightMovementRadius;
    int SpotlightLocationRadius;
    double SpotlightSpeed;
    double SpotlightAcceleration;
    double SpotlightAngle;
    int SpotlightRadius;
    FacingType WindDirection;
    LEPTON CameraRange;
    int FlightLevel;
    VocType BuildingDrop;
    TypeList<SmudgeTypeClass*> Scorches;
    TypeList<SmudgeTypeClass*> Scorches1;
    TypeList<SmudgeTypeClass*> Scorches2;
    TypeList<SmudgeTypeClass*> Scorches3;
    TypeList<SmudgeTypeClass*> Scorches4;
    TypeList<SmudgeTypeClass*> Craters;
    BuildingTypeClass* RepairBay;
    BuildingTypeClass* GDIGateOne;
    BuildingTypeClass* GDIGateTwo;
    BuildingTypeClass* NodGateOne;
    BuildingTypeClass* NodGateTwo;
    BuildingTypeClass* WallTower;
    BuildingTypeClass* GDIPowerPlant;
    BuildingTypeClass* GDIPowerTurbine;
    BuildingTypeClass* NodRegularPower;
    BuildingTypeClass* NodAdvancedPower;
    BuildingTypeClass* GDIFirestormGenerator;
    UnitTypeClass* GDIHunterSeeker;
    UnitTypeClass* NodHunterSeeker;
    TypeList<BuildingTypeClass*> BuildConst;
    TypeList<BuildingTypeClass*> BuildPower;
    TypeList<BuildingTypeClass*> BuildRefinery;
    TypeList<BuildingTypeClass*> BuildBarracks;
    TypeList<BuildingTypeClass*> BuildTech;
    TypeList<BuildingTypeClass*> BuildWeapons;
    TypeList<BuildingTypeClass*> BuildDefense;
    TypeList<BuildingTypeClass*> BuildPDefense;
    TypeList<BuildingTypeClass*> BuildAA;
    TypeList<BuildingTypeClass*> BuildHelipad;
    TypeList<BuildingTypeClass*> BuildRadar;
    TypeList<BuildingTypeClass*> ConcreteWalls;
    TypeList<BuildingTypeClass*> NSGates;
    TypeList<BuildingTypeClass*> EWGates;
    double GDIWallDefense;
    double GDIWallDefenseCoefficient;
    double NodBaseDefenseCoefficient;
    double GDIBaseDefenseCoefficient;
    int ComputerBaseDefenseResponse;
    int MaximumBaseDefenseValue;
    UnitTypeClass* BaseUnit;
    TypeList<UnitTypeClass*> HarvesterUnit;
    TypeList<AircraftTypeClass*> PadAircraft;
    TypeList<AnimTypeClass*> OnFire;
    TypeList<AnimTypeClass*> TreeFire;
    AnimTypeClass* field_7D4;
    AnimTypeClass* Smoke;
    AnimTypeClass* FirestormActiveAnim;
    AnimTypeClass* FirestormIdleAnim;
    AnimTypeClass* FirestormAirAnim;
    AnimTypeClass* FirestormGroundAnim;
    AnimTypeClass* MoveFlash;
    AnimTypeClass* BombParachute;
    AnimTypeClass* Parachute;
    TypeList<AnimTypeClass*> SplashList;
    AnimTypeClass* SmallFire;
    AnimTypeClass* LargeFire;
    InfantryTypeClass* Paratrooper;
    InfantryTypeClass* Disguise;
    InfantryTypeClass* Technician;
    InfantryTypeClass* Engineer;
    InfantryTypeClass* Pilot;
    InfantryTypeClass* Crew;
    WarheadTypeClass* FlameDamage;
    WarheadTypeClass* FlameDamage2;
    WarheadTypeClass* NukeWarhead;
    BulletTypeClass* NukeProjectile;
    BulletTypeClass* NukeDown;
    WarheadTypeClass* EMPulseWarhead;
    WarheadTypeClass* EMPulseProjectile;
    WarheadTypeClass* C4Warhead;
    WarheadTypeClass* IonCannonWarhead;
    WarheadTypeClass* FirestormWarhead;
    WarheadTypeClass* VeinholeWarhead;
    WarheadTypeClass* IonStormWarhead;
    TerrainTypeClass* VeinholeTypeClass;
    ParticleSystemTypeClass* DefaultLargeGreySmokeSystem;
    ParticleSystemTypeClass* DefaultSmallGreySmokeSystem;
    ParticleSystemTypeClass* DefaultSparkSystem;
    ParticleSystemTypeClass* DefaultLargeRedSmokeSystem;
    ParticleSystemTypeClass* DefaultSmallRedSmokeSystem;
    ParticleSystemTypeClass* DefaultDebrisSmokeSystem;
    ParticleSystemTypeClass* DefaultFireStreamSystem;
    ParticleSystemTypeClass* DefaultFirestormExplosionSystem;
    ParticleSystemTypeClass* DefaultTestParticleSystem;
    ParticleSystemTypeClass* DefaultRepairParticleSystem;
    double MyEffectivenessCoefficientDefault;
    double TargetEffectivenessCoefficientDefault;
    double TargetSpecialThreatCoefficientDefault;
    double TargetStrengthCoefficientDefault;
    double TargetDistanceCoefficientDefault;
    double DumbMyEffectivenessCoefficient;
    double DumbTargetEffectivenessCoefficient;
    double DumbTargetSpecialThreatCoefficient;
    double DumbTargetStrengthCoefficient;
    double DumbTargetDistanceCoefficient;
    double EnemyHouseThreatBonus;
    int HunterSeekerDetonateProximity;
    int HunterSeekerDescendProximity;
    int HunterSeekerDescentSpeed;
    int HunterSeekerAscentSpeed;
    int HunterSeekerEmergeSpeed;
    double TurboBoost;
    double AttackInterval;
    double AttackDelay;
    double PowerEmergencyFraction;
    double AirstripRatio;
    int AirstripLimit;
    double HelipadRatio;
    int HelipadLimit;
    double TeslaRatio;
    int TeslaLimit;
    double AARatio;
    int AALimit;
    double DefenseRatio;
    int DefenseLimit;
    double WarRatio;
    int WarLimit;
    double BarracksRatio;
    int BarracksLimit;
    int RefineryLimit;
    double RefineryRatio;
    int BaseSizeAdd;
    int PowerSurplus;
    int InfantryReserve;
    int InfantryBaseMult;
    int SoloCrateMoney;
    int TreeStrength;
    const UnitTypeClass* UnitCrateType;
    double PatrolTime;
    TypeList<int> TeamDelays;
    TypeList<int> AIHateDelays;
    int DissolveUnfilledTeamDelay;
    TypeList<int> AIIonCannonConYardValue;
    TypeList<int> AIIonCannonWarFactoryValue;
    TypeList<int> AIIonCannonPowerValue;
    TypeList<int> AIIonCannonEngineerValue;
    TypeList<int> AIIonCannonThiefValue;
    TypeList<int> AIIonCannonHarvesterValue;
    TypeList<int> AIIonCannonMCVValue;
    TypeList<int> AIIonCannonAPCValue;
    TypeList<int> AIIonCannonBaseDefenseValue;
    TypeList<int> AIIonCannonPlugValue;
    TypeList<int> AIIonCannonHelipadValue;
    TypeList<int> AIIonCannonTempleValue;
    int AIAlternateProductionCreditCutoff;
    TypeList<int> MultiplayerAICM;
    TypeList<int> MinimumAIDefensiveTeams;
    TypeList<int> MaximumAIDefensiveTeams;
    TypeList<int> TotalAITeamCap;
    double AIUseTurbineUpgradeProbability;
    TypeList<int> FillEarliestTeamProbability;
    double CloakDelay;
    double GameSpeedBias;
    double NervousBias;
    double ExplosionSpread;
    LEPTON SupressRadius;
    int MaxIQ;
    int IQSuperWeapons;
    int IQProduction;
    int IQGuardArea;
    int IQRepairSell;
    int IQCrush;
    int IQScatter;
    int IQContentScan;
    int IQAircraft;
    int IQHarvester;
    int IQSellBack;
    int AIBaseSpacing;
    CrateType SilverCrate;
    CrateType WoodCrate;
    int CrateMinimum;
    int CrateMaximum;
    LEPTON LZScanRadius;
    AnimTypeClass* DropZoneAnim;
    int MPDefaultMoney;
    int MPMaxMoney;
    int MPUnitCount;
    int MPTechLevel;
    LEPTON DropZoneRadius;
    double MessageDelay;
    double SavourDelay;
    int MaxPlayers;
    double BaseDefenseDelay;
    int SuspendPriority;
    double SuspendDelay;
    double SurvivorFraction;
    int SurvivorDivisor;
    double ReloadRate;
    double AutocreateTime;
    double BuildupTime;
    int HarvesterLoadRate;
    double HarvesterDumpRate;
    int AtomDamage;
    DifficultyClass Diff[DIFF_COUNT];
    double QuakeDamagePercent;
    double QuakeChance;
    double GrowthRate;
    double ShroudRate;
    double FogRate;
    double IceGrowthRate;
    double VeinGrowthRate;
    int IceSolidifyFrameTime;
    double AmbientChangeRate;
    double AmbientChangeStep;
    double CrateTime;
    double TimerWarning;
    int TiberiumTransmogrify;
    double NukeTime;
    double EMPulseTime;
    double IonCannonTime;
    double FirestormTime;
    double SpeakDelay;
    double DamageDelay;
    int Gravity;
    int LeptonsPerSightIncrease;
    MPHType Incoming;
    int MinDamage;
    int MaxDamage;
    int RepairStep;
    double RepairPercent;
    int IRepairStep;
    double RepairRate;
    double URepairRate;
    double IRepairRate;
    double ConditionGreen;
    double ConditionYellow;
    double ConditionRed;
    double RandomAnimateTime;
    LEPTON CloseEnoughDistance;
    LEPTON StrayDistance;
    LEPTON CrushDistance;
    LEPTON CrateRadius;
    LEPTON HomingScatter;
    LEPTON BallisticScatter;
    double RefundPercent;
    int BridgeStrength;
    double BuildSpeedBias;
    double C4Delay;
    int RepairThreshhold;
    double PathDelay;
    int BlockagePathDelay;
    double MovieTime;
    LEPTON TiberiumShortScan;
    LEPTON TiberiumLongScan;
    int IonLightningFrequency;
    int IonLightningRandomness;
    int IonLightningDamage;
    int IonStormDuration;
    int IonStormWarning;
    int CollapseChance;
    int WeedCapacity;
    int ExtraUnitLight;
    int ExtraInfantryLight;
    int ExtraAircraftLight;
    bool IsComputerParanoid;
    bool IsCurleyShuffle;
    bool IsBlendedFog;
    bool IsCompEasyBonus;
    bool IsFineDifficulty;
    bool IsExplosiveHarvester;
    bool IsHealthBar;
    bool IsAllyReveal;
    bool IsSeparate;
    bool IsTreeTarget;
    bool IsNamed;
    bool IsAutoCrush;
    bool IsSmartDefense;
    bool IsScatter;
    bool IsRevealByHeight;
    bool IsShroudedSubteranneanMovesAllowed;
    bool ShroudGrow;
    bool IsMPShadowGrow;
    bool IsMPBasesOn;
    bool IsMPTiberiumGrow;
    bool IsMPCrates;
    bool IsMPAIPlayers;
    bool IsMPCaptureTheFlag;
    bool IsMPBridgeDestruction;
    bool NodAIBuildsWalls;
    bool AIBuildsWalls;
    bool UseMinDefenseRule;
    AnimTypeClass* EMPulseSparkles;
    AnimTypeClass* WebbedInfantry;
    int JumpjetCloakDetectionRadius;
    int DropPodInfantryMinimum;
    int DropPodInfantryMaximum;
    int TalkBubbleTime;
    TypeList<int> PrerequisiteGDIFactory;
    TypeList<int> PrerequisiteNodFactory;
    float EngineerCaptureLevel;
    float EngineerDamage;
};

void Difficulty_Get(CCINIClass& ini, DifficultyClass& diff, char const* section);


/**
 *  Putting these here as they are loaded in RulesClass.
 */
extern double& Levitation_Drag;
extern double& Levitation_MaxVelocityWhenHappy;
extern double& Levitation_MaxVelocityWhenFollowing;
extern double& Levitation_MaxVelocityWhenPissedOff;
extern double& Levitation_AccelerationProbability;
extern int& Levitation_AccelerationDuration;
extern double& Levitation_Acceleration;
extern double& Levitation_InitialBoost;
extern int& Levitation_MaxBlockCount;
extern double& Levitation_IntentionalDeacceleration;
extern double& Levitation_IntentionalDriftVelocity;
extern double& Levitation_ProximityDistance;
extern TypeList<VocType>& Levitation_PropulsionSoundEffect;
