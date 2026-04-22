/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for smudge types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "smudgetype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


SmudgeType SmudgeTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SMUDGE_NONE;
    }

    if (name != nullptr) {
        for (SmudgeType index = SMUDGE_FIRST; index < SmudgeTypes.Count(); ++index) {
            if (!strcasecmp(SmudgeTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return SMUDGE_NONE;
}


const char* SmudgeTypeClass::Name_From(SmudgeType type)
{
    return (type != SMUDGE_NONE && type < SmudgeTypes.Count() ? SmudgeTypes[type]->Name() : "<none>");
}


SmudgeTypeClass* SmudgeTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, SmudgeTypes);
}
