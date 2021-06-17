/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WAYPOINTPATH.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Waypoint path container.
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
#include "abstract.h"
#include "vector.h"
#include "waypoint.h"


class WaypointClass;


class DECLSPEC_UUID("F73125BA-1054-11D2-8172-006008055BB5")
WaypointPathClass : public AbstractClass
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
        WaypointPathClass();
        WaypointPathClass(int index);
        WaypointPathClass(const NoInitClass &noinit);
        virtual ~WaypointPathClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        Coordinate *Get_Waypoint_Coord(int index) const; // 00673600
        // 00673620
        // 006736D0
        // 00673770
        // 006737B0
        // 00673820
        // 00673860

    public:
        int field_14; // 0x14
        DynamicVectorClass<WaypointClass> Waypoints;
};
