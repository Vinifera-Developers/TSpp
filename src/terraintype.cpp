/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for terrain types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "terraintype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TerrainType TerrainTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TERRAIN_NONE;
    }

    if (name != nullptr) {
        for (TerrainType index = TERRAIN_FIRST; index < TerrainTypes.Count(); ++index) {
            if (!strcasecmp(TerrainTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TERRAIN_NONE;
}


const char* TerrainTypeClass::Name_From(TerrainType type)
{
    return (type != TERRAIN_NONE && type < TerrainTypes.Count() ? TerrainTypes[type]->Name() : "<none>");
}


TerrainTypeClass* TerrainTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TerrainTypes);
}
