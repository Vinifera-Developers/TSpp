/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MAP.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game map interface.
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
#include "map.h"
#include "tibsun_defines.h"


/**
 *  Places a crate at cell location on map.
 *
 *  @author: CCHyper
 */
bool MapClass::Place_Crate(Cell where)
{
    /**
     *  Check the location is valid.
     */
    CellClass* cell = &(*this)[where];
    if (!cell) {
        return false;
    }

    /**
     *  Find a nearby location if this one is taken.
     */
    Cell newcell = Nearby_Location(where, cell->Land == LAND_WATER ? SPEED_FLOAT : SPEED_TRACK);

    /**
     *  Find a crate index that is free for assignment. If there are
     *  no free slots, then return with failure to place crate.
     */
    int crateindex = 0;
    for (crateindex = 0; crateindex < std::size(Crates); crateindex++) {
        if (!Crates[crateindex].Is_Valid()) break;
    }
    if (crateindex == std::size(Crates)) {
        return false;
    }

    /**
     *  Place the crate down on the map.
     */
    if (!Crates[crateindex].Create_Crate(newcell)) {
        return false;
    }

    return true;
}
