/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for house types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "housetype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


HousesType HouseTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return HOUSE_NONE;
    }

    if (name != nullptr) {
        for (HousesType index = HOUSE_FIRST; index < HouseTypes.Count(); ++index) {
            if (!strcasecmp(HouseTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return HOUSE_NONE;
}


const char* HouseTypeClass::Name_From(HousesType type)
{
    return (type != HOUSE_NONE && type < HouseTypes.Count() ? HouseTypes[type]->Name() : "<none>");
}


HouseTypeClass* HouseTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, HouseTypes);
}
