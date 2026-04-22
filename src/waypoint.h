/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Waypoint location container.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "abstract.h"
#include "always.h"
#include "vector.h"


class WaypointClass
{
public:
    WaypointClass();
    ~WaypointClass();

    bool operator==(const WaypointClass& that) const { return Location == that.Location; }
    bool operator!=(const WaypointClass& that) const { return Location != that.Location; }

public:
    Coord Location;
};


const char* Waypoint_As_String(int num);
int Waypoint_From_String(const char* string);
