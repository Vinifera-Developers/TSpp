/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for the game map interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
