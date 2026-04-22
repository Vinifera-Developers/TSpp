/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for taks force types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "taskforce.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TaskForceType TaskForceClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TASKFORCE_NONE;
    }

    if (name != nullptr) {
        for (TaskForceType index = TASKFORCE_FIRST; index < TaskForces.Count(); ++index) {
            if (!strcasecmp(TaskForces[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TASKFORCE_NONE;
}


TaskForceType TaskForceClass::From_Full_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TASKFORCE_NONE;
    }

    if (name != nullptr) {
        for (TaskForceType index = TASKFORCE_FIRST; index < TaskForces.Count(); ++index) {
            if (!strcasecmp(TaskForces[index]->Full_Name(), name)) {
                return index;
            }
        }
    }

    return TASKFORCE_NONE;
}


const char* TaskForceClass::Name_From(TaskForceType type)
{
    return (type != TASKFORCE_NONE && type < TaskForces.Count() ? TaskForces[type]->Name() : "<none>");
}


TaskForceClass* TaskForceClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TaskForces);
}
