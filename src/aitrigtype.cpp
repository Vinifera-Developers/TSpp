/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for ai trigger types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "aitrigtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


AITriggerType AITriggerTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return AITRIGGER_NONE;
    }

    if (name != nullptr) {
        for (AITriggerType index = AITRIGGER_FIRST; index < AITriggerTypes.Count(); ++index) {
            if (!strcasecmp(AITriggerTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return AITRIGGER_NONE;
}


const char* AITriggerTypeClass::Name_From(AITriggerType type)
{
    return (type != AITRIGGER_NONE && type < AITriggerTypes.Count() ? AITriggerTypes[type]->Name() : "<none>");
}


AITriggerTypeClass* AITriggerTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (AITriggerType index = AITRIGGER_FIRST; index < AITriggerTypes.Count(); ++index) {
        if (!strcasecmp(AITriggerTypes[index]->Name(), name)) {
            return AITriggerTypes[index];
        }
    }

    AITriggerTypeClass* ptr = new AITriggerTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
