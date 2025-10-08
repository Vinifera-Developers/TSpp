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


#include "abstract.h"
#include "always.h"
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
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    WaypointPathClass();
    WaypointPathClass(int index);
    WaypointPathClass(const NoInitClass& noinit);
    virtual ~WaypointPathClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    int Current_Waypoint() const { return CurrentWaypoint; }
    int Waypoint_Count() const { return Waypoints.Count(); }
    WaypointClass* Get_Waypoint(int index) const;
    bool Add_Waypoint(Coord const& coord);
    bool Select_Waypoint(Coord const& coord);
    void Replace_Waypoint(int index, Coord const& coord);
    void Delete_Waypoint(int index);
    WaypointClass* Get_Next_Waypoint(WaypointClass* wp);
    void Clear();

    const char* Name() const;

public:
    int CurrentWaypoint;
    DynamicVectorClass<WaypointClass> Waypoints;
};
