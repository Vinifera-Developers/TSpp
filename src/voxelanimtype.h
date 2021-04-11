/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VOXELANIMTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for voxel anim types.
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


class AnimTypeClass;
class WarheadTypeClass;
class ParticleSystemTypeClass;


class DECLSPEC_UUID("2EBB6D66-0D4D-11D2-8172-006008055BB5")
VoxelAnimTypeClass : public ObjectTypeClass
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
        VoxelAnimTypeClass(const char *ini_name = nullptr);
        VoxelAnimTypeClass(const NoInitClass &noinit);
        virtual ~VoxelAnimTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual bool Create_And_Place(CellStruct &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;

        static const VoxelAnimTypeClass &As_Reference(VoxelAnimType type);
        static const VoxelAnimTypeClass *As_Pointer(VoxelAnimType type);
        static const VoxelAnimTypeClass &As_Reference(const char *name);
        static const VoxelAnimTypeClass *As_Pointer(const char *name);
        static VoxelAnimType From_Name(const char *name);
        static const char *Name_From(VoxelAnimType type);
        static const VoxelAnimTypeClass *Find_Or_Make(const char *name);

    public:
        bool IsNormalized;
        bool IsTranslucent;
        bool IsSharesSourceData;
        int VoxelIndex;
        int Duration;
        double Elasticity;
        double MinAngularVelocity;
        double MaxAngularVelocity;
        double MinZVel;
        double MaxZVel;
        double MaxXYVel;
        bool IsMeteor;
        VoxelAnimTypeClass *Spawns;
        int SpawnCount;
        VocType StartSound;
        VocType BounceSound;
        VocType ExpireSound;
        AnimTypeClass *BounceAnim;
        AnimTypeClass *ExpireAnim;
        AnimTypeClass *TrailerAnim;
        int Damage;
        int DamageRadius;
        WarheadTypeClass *Warhead;
        ParticleSystemTypeClass *AttachedSystem;
        bool IsTiberium;
};
