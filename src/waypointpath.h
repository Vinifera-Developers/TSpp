/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Waypoint path container.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
