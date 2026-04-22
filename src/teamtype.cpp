/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for team types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "teamtype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TeamType TeamTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TEAM_NONE;
    }

    if (name != nullptr) {
        for (TeamType index = TEAM_FIRST; index < TeamTypes.Count(); ++index) {
            if (!strcasecmp(TeamTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TEAM_NONE;
}


const char* TeamTypeClass::Name_From(TeamType type)
{
    return (type != TEAM_NONE && type < TeamTypes.Count() ? TeamTypes[type]->Name() : "<none>");
}


TeamTypeClass* TeamTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TeamTypes);
}
