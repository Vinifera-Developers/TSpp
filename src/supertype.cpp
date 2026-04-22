/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for super weapon types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "supertype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


SuperWeaponType SuperWeaponTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SUPER_NONE;
    }

    if (name != nullptr) {
        for (SuperWeaponType index = SUPER_FIRST; index < SuperWeaponTypes.Count(); ++index) {
            if (!strcasecmp(SuperWeaponTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return SUPER_NONE;
}


const char* SuperWeaponTypeClass::Name_From(SuperWeaponType type)
{
    return (type != SUPER_NONE && type < SuperWeaponTypes.Count() ? SuperWeaponTypes[type]->Name() : "<none>");
}


SuperWeaponTypeClass* SuperWeaponTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, SuperWeaponTypes);
}
