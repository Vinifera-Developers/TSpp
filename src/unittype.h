/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          UNITTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for unit types.
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

#include "technotype.h"
#include "tpoint.h"
#include "tibsun_defines.h"


class DECLSPEC_UUID("DCBD42EA-0546-11D2-ACA4-006008055BB5")
UnitTypeClass : public TechnoTypeClass
{
    public:
        enum UnitTypeClassEnums
        {
            FIRING_SYNC_FRAME_MAX = 2
        };

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
        UnitTypeClass(const char *ini_name = nullptr);
        UnitTypeClass(const NoInitClass &noinit);
        virtual ~UnitTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual int entry_34() const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Coordinate Coord_Fixup(Coordinate *coord) const override;
        virtual Point3D Pixel_Dimensions() const override;
        virtual Point3D Lepton_Dimensions() const override;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;

        /**
         *  TechnoTypeClass
         */
		virtual int Repair_Step() const override;

        const TPoint3D<int> Turret_Adjust(DirType dir, TPoint3D<int> &pos) const;

        static const UnitTypeClass &As_Reference(UnitType type);
        static const UnitTypeClass *As_Pointer(UnitType type);
        static const UnitTypeClass &As_Reference(const char *name);
        static const UnitTypeClass *As_Pointer(const char *name);
        static UnitType From_Name(const char *name);
        static const char *Name_From(UnitType type);
        static const UnitTypeClass *Find_Or_Make(const char *name);

    public:
		UnitType Type;
        LandType MovementRestrictedTo;
        TPoint3D<int> HalfDamageSmokeLocation;
        bool IsPassive;
        bool IsCrateGoodie;
        bool IsToHarvest;
        bool IsWeeder;
        bool IsFireAnim;
        bool IsLockTurret;
        bool IsNoFireWhileMoving;
        bool IsDeployToFire;
        bool IsTilter;
        bool UseTurretShadow;
        bool IsTooBigToFitUnderBridge;
        bool IsSmallVisceroid;
        bool IsLargeVisceroid;
        bool IsCarriesCrate;
        ShapeFileStruct *AltImage;
        bool IsNonVehicle;
        bool IsJellyfish;
        bool IsLimpetDrone;
        bool IsMobileEMP;
        bool IsCoreDefender;
        char StandingFrames;
        char DeathFrames;
        char DeathFrameRate;
        int MaxCharge;
        int StartCharge;
        int FiringSyncFrame[FIRING_SYNC_FRAME_MAX];
        int StartStandFrame;
        int StartWalkFrame;
        int StartFiringFrame;
        int StartDeathFrame;
        int MaxDeathCounter;
        int Facings;
        char WalkFrames;
        char FiringFrames;
        char AltImageFile[21 + 4];
};
