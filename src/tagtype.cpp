/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for object trigger-tag types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "tagtype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TagType TagTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TAG_NONE;
    }

    if (name != nullptr) {
        for (TagType index = TAG_FIRST; index < TagTypes.Count(); ++index) {
            if (!strcasecmp(TagTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TAG_NONE;
}


const char* TagTypeClass::Name_From(TagType type)
{
    return (type != TAG_NONE && type < TagTypes.Count() ? TagTypes[type]->Name() : "<none>");
}


TagTypeClass* TagTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TagTypes);
}
