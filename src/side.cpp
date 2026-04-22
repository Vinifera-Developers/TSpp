/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for side types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "side.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


SideType SideClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SIDE_NONE;
    }

    if (name != nullptr) {
        for (SideType index = SIDE_FIRST; index < Sides.Count(); ++index) {
            if (!strcasecmp(Sides[index]->Name(), name)) {
                return index;
            }
        }
    }

    return SIDE_NONE;
}


const char* SideClass::Name_From(SideType type)
{
    return (type != SIDE_NONE && type < Sides.Count() ? Sides[type]->Name() : "<none>");
}


SideClass* SideClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, Sides);
}
