/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for animation types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "animtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


AnimType AnimTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return ANIM_NONE;
    }

    if (name != nullptr) {
        for (AnimType index = ANIM_FIRST; index < AnimTypes.Count(); ++index) {
            if (!strcasecmp(AnimTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return ANIM_NONE;
}


const char* AnimTypeClass::Name_From(AnimType type)
{
    return (type != ANIM_NONE && type < AnimTypes.Count() ? AnimTypes[type]->Name() : "<none>");
}


AnimTypeClass* AnimTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (AnimType index = ANIM_FIRST; index < AnimTypes.Count(); ++index) {
        if (!strcasecmp(AnimTypes[index]->Name(), name)) {
            return AnimTypes[index];
        }
    }

    AnimTypeClass* ptr = new AnimTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
