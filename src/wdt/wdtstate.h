/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTSTATE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         
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
#include "vector.h"


class WDTTerritory;


class WDTState
{
    public:
        WDTState(); // 00677E70
        WDTState(char *packet_buffer); // 00677EE0 - ctor from packet info
        ~WDTState(); // 00678210

        // 006782F0 - field_3C is NOT null?
        // 00678300 - is this state previous cycle data?
        // 00678310
        // 006783F0
        const char *To_String() const; // 006788E0
        const char *Build_Territory_String() const; // 00678D80

    public:
        char ShortDesc[4];
        char LongDesc[8];
        char MapID;
        int CycleID;
        int field_14;
        int NumTerritories;
        int NumTicks;
        int TickTime;
        DynamicVectorClass<WDTTerritory *> Territories; // TODO confirm name
        void *field_3C; // an array of sorts...
        bool field_40; // seems to be a flag for if this is the "previous cycle" data or not.
};
