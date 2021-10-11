/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TECHNOTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class which all buildable game object types derive from.
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

#include "objecttype.h"
#include "tibsun_defines.h"
#include "tpoint.h"
#include "typelist.h"


class HouseClass;
class VoxelAnimTypeClass;
class BuildingTypeClass;
class UnitTypeClass;
class ParticleSystemTypeClass;
class AnimTypeClass;
class WeaponTypeClass;


#define WEAPON_SLOT_COUNT 3


class TechnoTypeClass : public ObjectTypeClass
{
    public:
        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);
        IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER *pcbSize);

    public:
        TechnoTypeClass(const char *ini_name = nullptr, SpeedType speed = SPEED_FOOT);
        TechnoTypeClass(const NoInitClass &noinit);
        virtual ~TechnoTypeClass();

        /**
         *  AbstractClass
         */
        virtual int entry_34() const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual int Get_Ownable() const override;
        virtual int Max_Pips() const override;
        virtual int Cost_Of(HouseClass *house = nullptr) const override;
        virtual int Time_To_Build() const override;
        virtual ShapeFileStruct *const Get_Cameo_Data() const override;

        /**
         *  TechnoTypeClass
         */
        virtual bool Legal_Placement(Cell &pos, HouseClass *house = nullptr) const;
		virtual int Raw_Cost() const;
		virtual int Repair_Cost() const;
		virtual int Repair_Step() const;
		virtual int Flight_Level() const;

		bool Is_Two_Shooter() const;
        const WeaponInfoStruct & Fetch_Weapon_Info(WeaponSlotType slot) const;
        bool In_Range(Coordinate &coord, TARGET target, WeaponTypeClass *weapon);

        static const TechnoTypeClass &As_Reference(const char *name);
        static const TechnoTypeClass *As_Pointer(const char *name);
        static const TechnoTypeClass *From_Name(const char *name);

    public:
        double CollateralDamageCoefficient;
        int WalkRate;
        AbilitiesStruct VeteranAbilities;
        AbilitiesStruct EliteAbilities;
        double SpecialThreatValue;
        double MyEffectivenessCoefficient;
        double TargetEffectivenessCoefficient;
        double TargetSpecialThreatCoefficient;
        double TargetStrengthCoefficient;
        double TargetDistanceCoefficient;
        double ThreatAvoidanceCoefficient;
        int SlowdownDistance;
        double DeaccelerationFactor;
        double AccelerationFactor;
        int CloakingSpeed;
        TypeList<VoxelAnimTypeClass *> DebrisTypes;
        TypeList<int> DebrisMaximums;
        CLSID Locomotor;
        double field_1F8;
        double field_200;
        double Weight;
        double PhysicalSize;
        MissionType InitialMission;
        double RollAngle;
        double PitchSpeed;
        double PitchAngle;
        int BuildLimit;
        CategoryType Category;
        int field_240;
        double DeployTime;
        int FireAngle;
        PipScaleType PipScale;
        TypeList<BuildingTypeClass *> Dock;
        BuildingTypeClass *DeploysInto;
        UnitTypeClass *UndeploysInto;
        TypeList<VocType> VoiceSelect;
        TypeList<VocType> VoiceMove;
        TypeList<VocType> VoiceAttack;
        TypeList<VocType> VoiceDie;
        TypeList<VocType> VoiceFeedback;
        VocType AuxSound1;
        VocType AuxSound2;
        MZoneType MZone;
        LEPTON ThreatRange;
        int MaxDebris;
        int MaxPassengers;
        int SightRange;
        int Cost;
        int FlightLevel;
        unsigned TechLevel;
        TypeList<int> Prerequisite;
		int Risk;
        int Reward;
        MPHType MaxSpeed;
        SpeedType Speed;
		int MaxAmmo;
        long Ownable;
        bool IsAllowedToStartInMultiplayer;
        char CameoFilename[21 + 4];
        const ShapeFileStruct *CameoData;
		int Rotation;
        int ROT;
        int TurretOffset;
        int Points;
        TypeList<AnimTypeClass *> Explosion;
        ParticleSystemTypeClass *NaturalParticleSystem;
        TPoint3D<int> NaturalParticleSystemLocation;
        TypeList<ParticleSystemTypeClass *> DamageParticleSystems;
        TPoint3D<int> DamageSmokeOffset;
        int ShadowIndex;
        int Storage;
        bool TurretNotExportedOnGround;
        WeaponInfoStruct Weapons[WEAPON_SLOT_COUNT];
        bool IsTypeImmune;
        bool MoveToShroud;
        bool IsTrainable;
        bool DamageSparks;
        bool TargetLaser;
        bool IsImmuneToVeins;
        bool IsTiberiumHeal;
        bool CloakStop;
        bool IsTrain;
        bool IsDropship;
        bool ToProtect;
        bool Disableable;
        bool Unbuildable_or_CanBuild;
        bool IsDoubleOwned;
        bool IsInvisible;
        bool IsRadarVisible;
        bool IsLeader;
        bool IsScanner;
        bool IsNominal;
        bool IsTurretEquipped;
        bool IsRepairable;
        bool IsCrew;
		bool IsRemappable;
        bool IsCloakable;
        bool IsSelfHealing;
        bool IsExploding;
        bool IsNoAutoFire;
        bool IsTurretSpins;
		bool IsRegulated;
        bool IsManualReload;
        bool IsVisibleLoad;
        bool IsLightningRod;
        bool IsHunterSeeker;
        bool IsCrusher;
        bool IsTiltsWhenCrushes;
        bool IsSubterranean;
        bool IsAutoCrush;
        bool IsAccelerates;
        int ZFudgeCliff;
        int ZFudgeColumn;
        int ZFudgeTunnel;
        int ZFudgeBridge;
};
