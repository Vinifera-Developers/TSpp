/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for building types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "buildingtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


StructType BuildingTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return STRUCT_NONE;
    }

    if (name != nullptr) {
        for (StructType index = STRUCT_FIRST; index < BuildingTypes.Count(); ++index) {
            if (!strcasecmp(BuildingTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return STRUCT_NONE;
}


const char* BuildingTypeClass::Name_From(StructType type)
{
    return (type != STRUCT_NONE && type < BuildingTypes.Count() ? BuildingTypes[type]->Name() : "<none>");
}


BuildingTypeClass* BuildingTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (StructType index = STRUCT_FIRST; index < BuildingTypes.Count(); ++index) {
        if (!strcasecmp(BuildingTypes[index]->Name(), name)) {
            return BuildingTypes[index];
        }
    }

    BuildingTypeClass* ptr = new BuildingTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
