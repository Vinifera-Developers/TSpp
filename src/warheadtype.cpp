/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for weapon types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "warheadtype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


WarheadType WarheadTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return WARHEAD_NONE;
    }

    if (name != nullptr) {
        for (WarheadType index = WARHEAD_FIRST; index < Warheads.Count(); ++index) {
            if (!strcasecmp(Warheads[index]->Name(), name)) {
                return index;
            }
        }
    }

    return WARHEAD_NONE;
}


const char* WarheadTypeClass::Name_From(WarheadType type)
{
    return (type != WARHEAD_NONE && type < Warheads.Count() ? Warheads[type]->Name() : "<none>");
}


WarheadTypeClass* WarheadTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, Warheads);
}
