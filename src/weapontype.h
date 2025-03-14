/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WEAPONTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for weapon types.
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

#include "abstracttype.h"
#include "typelist.h"


class BulletTypeClass;
class WarheadTypeClass;
class AnimTypeClass;
class ParticleSystemTypeClass;


class DECLSPEC_UUID("9FD219CA-0F7B-11D2-8172-006008055BB5")
WeaponTypeClass : public AbstractTypeClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

    public:
        WeaponTypeClass(const char *ini_name = nullptr);
        WeaponTypeClass(const NoInitClass &noinit);
        virtual ~WeaponTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        void Set_Speed();
        bool Is_Wall_Destroyer() const;
        ThreatType Allowed_Threats() const;

        static const WeaponTypeClass &As_Reference(WeaponType type);
        static const WeaponTypeClass *As_Pointer(WeaponType type);
        static const WeaponTypeClass &As_Reference(const char *name);
        static const WeaponTypeClass *As_Pointer(const char *name);
        static WeaponType From_Name(const char *name);
        static const char *Name_From(WeaponType type);
        static const WeaponTypeClass *Find_Or_Make(const char *name);

    public:
        int AmbientDamage;
        int Burst;
        BulletTypeClass *Bullet;
        int Attack;
        MPHType MaxSpeed;
        WarheadTypeClass *WarheadPtr;
        int ROF;
        LEPTON Range;
        LEPTON ProjectileRange;
        int BurstDelay[4];
        LEPTON MinimumRange;
        TypeList<VocType> Sound;
        TypeList<AnimTypeClass *> Anim;
        ParticleSystemTypeClass *AttachedParticleSystem;
        RGBStruct LaserInnerColor;
        RGBStruct LaserOuterColor;
        RGBStruct LaserOuterSpread;
        bool IsUseFireParticles;
        bool IsUseSparkParticles;
        bool IsRailgun;
        bool IsLobber;
        bool IsBright;
        unsigned char LaserDuration;
        bool IsBigLaser;
        bool IsSonic;
        bool IsTurboBoosted;
        bool IsSupressed;
        bool IsCamera;
        bool IsElectric;
        bool IsLaser;
        bool IsIonSensitive;
};
