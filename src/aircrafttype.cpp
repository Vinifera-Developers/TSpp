/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AIRCRAFTTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for aircraft types.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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


const AircraftTypeClass* AircraftTypeClass::Find_Or_Make(const char* name)
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
