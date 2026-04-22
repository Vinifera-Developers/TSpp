/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for trigger types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "triggertype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TriggerType TriggerTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TRIGGER_NONE;
    }

    if (name != nullptr) {
        for (TriggerType index = TRIGGER_FIRST; index < TriggerTypes.Count(); ++index) {
            if (!strcasecmp(TriggerTypes[index]->Name(), name)) {
                return index;
            }
            if (!strcasecmp(TriggerTypes[index]->Full_Name(), name)) {
                return index;
            }
        }
    }

    return TRIGGER_NONE;
}


const char* TriggerTypeClass::Name_From(TriggerType type)
{
    return (type != TRIGGER_NONE && type < TriggerTypes.Count() ? TriggerTypes[type]->Name() : "<none>");
}


TriggerTypeClass* TriggerTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TriggerTypes);
}
