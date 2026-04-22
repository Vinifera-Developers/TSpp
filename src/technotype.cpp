/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class which all buildable game object types derive from.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "technotype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const TechnoTypeClass* TechnoTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    if (name != nullptr) {
        for (int index = 0; index < TechnoTypes.Count(); ++index) {
            const TechnoTypeClass* ttype = TechnoTypes[index];
            if (!strcasecmp(ttype->Name(), name)) {
                return ttype;
            }
        }
    }

    return nullptr;
}
