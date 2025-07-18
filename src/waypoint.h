/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WAYPOINT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Waypoint location container.
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


class WaypointClass
{
    public:
        WaypointClass();
        ~WaypointClass();

        bool operator==(const WaypointClass &that) const { return Location == that.Location; }
        bool operator!=(const WaypointClass &that) const { return Location != that.Location; }

    public:
        Coord Location;
};


const char *Waypoint_As_String(int num);
int Waypoint_From_String(const char *string);
