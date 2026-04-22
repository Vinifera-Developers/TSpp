/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for unit types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "unittype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


UnitType UnitTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return UNIT_NONE;
    }

    if (name != nullptr) {
        for (UnitType index = UNIT_FIRST; index < UnitTypes.Count(); ++index) {
            if (!strcasecmp(UnitTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return UNIT_NONE;
}


const char* UnitTypeClass::Name_From(UnitType type)
{
    return (type != UNIT_NONE && type < UnitTypes.Count() ? UnitTypes[type]->Name() : "<none>");
}


UnitTypeClass* UnitTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, UnitTypes);
}
