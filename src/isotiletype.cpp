/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for isometric tile types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "isotiletype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


IsometricTileType IsometricTileTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return ISOTILE_NONE;
    }

    if (name != nullptr) {
        for (IsometricTileType index = ISOTILE_FIRST; index < IsoTileTypes.Count(); ++index) {
            if (!strcasecmp(IsoTileTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return ISOTILE_NONE;
}


const char* IsometricTileTypeClass::Name_From(IsometricTileType type)
{
    return (type != ISOTILE_NONE && type < IsoTileTypes.Count() ? IsoTileTypes[type]->Name() : "<none>");
}
