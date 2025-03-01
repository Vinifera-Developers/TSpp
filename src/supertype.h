/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SUPERTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for super weapon types.
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
#include "tibsun_defines.h"


class ObjectClass;
class CCINIClass;
class WeaponTypeClass;
class BuildingTypeClass;


class DECLSPEC_UUID("0CF2BCE7-36E4-11D2-B8D8-006008C809ED")
SuperWeaponTypeClass : public AbstractTypeClass
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
        SuperWeaponTypeClass(const char *ini_name = nullptr);
        SuperWeaponTypeClass(const NoInitClass &noinit);
        virtual ~SuperWeaponTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        virtual ActionType What_Action(Cell& cell, ObjectClass* object) const;

        static const SuperWeaponTypeClass *From_Action(ActionType action);

        static const SuperWeaponTypeClass &As_Reference(SpecialWeaponType type);
        static const SuperWeaponTypeClass *As_Pointer(SpecialWeaponType type);
        static const SuperWeaponTypeClass &As_Reference(const char *name);
        static const SuperWeaponTypeClass *As_Pointer(const char *name);
        static SpecialWeaponType From_Name(const char *name);
        static const char *Name_From(SpecialWeaponType type);
        static const SuperWeaponTypeClass *Find_Or_Make(const char *name);

    public:
        SpecialWeaponType Type;
        WeaponTypeClass *Weapon;
        VoxType VoxRecharge;
        VoxType VoxCharging;
        VoxType VoxImpatient;
        VoxType VoxSuspend;
        int RechargeTime;
        SpecialWeaponType ActsLike;
        ShapeFileStruct *SidebarIcon;
        ActionType Action;
        BuildingTypeClass *AuxBuilding;
        char SidebarImage[25];
        bool IsUseChargeDrain;
        bool IsPowered;
        bool IsManualControl;
};
