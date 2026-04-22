/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for bullet types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "bullettype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


BulletType BulletTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return BULLET_NONE;
    }

    if (name != nullptr) {
        for (BulletType index = BULLET_FIRST; index < BulletTypes.Count(); ++index) {
            if (!strcasecmp(BulletTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return BULLET_NONE;
}


const char* BulletTypeClass::Name_From(BulletType type)
{
    return (type != BULLET_NONE && type < BulletTypes.Count() ? BulletTypes[type]->Name() : "<none>");
}


BulletTypeClass* BulletTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (BulletType index = BULLET_FIRST; index < BulletTypes.Count(); ++index) {
        if (!strcasecmp(BulletTypes[index]->Name(), name)) {
            return BulletTypes[index];
        }
    }

    BulletTypeClass* ptr = new BulletTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
