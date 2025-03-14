/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AIRCRAFTTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for aircraft types.
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
#include "tibsun_defines.h"


class DECLSPEC_UUID("AE8B33D9-061C-11D2-ACA4-006008055BB5")
AircraftTypeClass : public TechnoTypeClass
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
        AircraftTypeClass(const char *ini_name = nullptr);
        AircraftTypeClass(const NoInitClass &noinit);
        virtual ~AircraftTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Point3D Lepton_Dimensions() const override;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;
        virtual Cell *Occupy_List(bool placement = false) const;

        static const AircraftTypeClass &As_Reference(AircraftType type);
        static const AircraftTypeClass *As_Pointer(AircraftType type);
        static const AircraftTypeClass &As_Reference(const char *name);
        static const AircraftTypeClass *As_Pointer(const char *name);
        static AircraftType From_Name(const char *name);
        static const char *Name_From(AircraftType type);
        static const AircraftTypeClass *Find_Or_Make(const char *name);

    public:
        static const void *&LRotorData;
        static const void *&RRotorData;

	public:
		AircraftType Type;
		bool IsCarryall;
        bool IsRotorEquipped;
        bool IsRotorCustom;
        bool IsLandable;
};
