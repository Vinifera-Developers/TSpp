/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for aircraft types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "aircrafttype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


AircraftType AircraftTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return AIRCRAFT_NONE;
    }

    if (name != nullptr) {
        for (AircraftType index = AIRCRAFT_FIRST; index < AircraftTypes.Count(); ++index) {
            if (!strcasecmp(AircraftTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return AIRCRAFT_NONE;
}


const char* AircraftTypeClass::Name_From(AircraftType type)
{
    return (type != AIRCRAFT_NONE && type < AircraftTypes.Count() ? AircraftTypes[type]->Name() : "<none>");
}


AircraftTypeClass* AircraftTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (AircraftType index = AIRCRAFT_FIRST; index < AircraftTypes.Count(); ++index) {
        if (!strcasecmp(AircraftTypes[index]->Name(), name)) {
            return AircraftTypes[index];
        }
    }

    AircraftTypeClass* ptr = new AircraftTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
