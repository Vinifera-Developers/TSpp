/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for tiberium types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "tiberium.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TiberiumType TiberiumClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TIBERIUM_NONE;
    }

    if (name != nullptr) {
        for (TiberiumType index = TIBERIUM_FIRST; index < Tiberiums.Count(); ++index) {
            if (!strcasecmp(Tiberiums[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TIBERIUM_NONE;
}


const char* TiberiumClass::Name_From(TiberiumType type)
{
    return (type != TIBERIUM_NONE && type < Tiberiums.Count() ? Tiberiums[type]->Name() : "<none>");
}


TiberiumClass* TiberiumClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, Tiberiums);
}
