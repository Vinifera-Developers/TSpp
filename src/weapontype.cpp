/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for weapon types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "weapontype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


WeaponType WeaponTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return WEAPON_NONE;
    }

    if (name != nullptr) {
        for (WeaponType index = WEAPON_FIRST; index < Weapons.Count(); ++index) {
            if (!strcasecmp(Weapons[index]->Name(), name)) {
                return index;
            }
        }
    }

    return WEAPON_NONE;
}


const char* WeaponTypeClass::Name_From(WeaponType type)
{
    return (type != WEAPON_NONE && type < Weapons.Count() ? Weapons[type]->Name() : "<none>");
}


WeaponTypeClass* WeaponTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, Weapons);
}
