/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for infantry types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "infantrytype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


InfantryType InfantryTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return INFANTRY_NONE;
    }

    if (name != nullptr) {
        for (InfantryType index = INFANTRY_FIRST; index < InfantryTypes.Count(); ++index) {
            if (!strcasecmp(InfantryTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return INFANTRY_NONE;
}


const char* InfantryTypeClass::Name_From(InfantryType type)
{
    return (type != INFANTRY_NONE && type < InfantryTypes.Count() ? InfantryTypes[type]->Name() : "<none>");
}


InfantryTypeClass* InfantryTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, InfantryTypes);
}
