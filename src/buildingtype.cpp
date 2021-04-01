/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUILDINGTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for building types.
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
#include "buildingtype.h"
#include "tibsun_globals.h"
#include <cassert>


const BuildingTypeClass &BuildingTypeClass::As_Reference(BuildingType type)
{
    assert(type != BUILDING_NONE && type < BuildingTypes.Count());
    return *BuildingTypes[type];
}


const BuildingTypeClass *BuildingTypeClass::As_Pointer(BuildingType type)
{
    assert(type != BUILDING_NONE && type < BuildingTypes.Count());
    return type != BUILDING_NONE && type < BuildingTypes.Count() ? BuildingTypes[type] : nullptr;
}


const BuildingTypeClass &BuildingTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const BuildingTypeClass *BuildingTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


BuildingType BuildingTypeClass::From_Name(const char *name)
{
    assert(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return BUILDING_NONE;
    }

    if (name != nullptr) {
        for (BuildingType index = BUILDING_FIRST; index < BuildingTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return BUILDING_NONE;
}


const char *BuildingTypeClass::Name_From(BuildingType type)
{
    return (type != BUILDING_NONE && type < BuildingTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const BuildingTypeClass *BuildingTypeClass::Find_Or_Make(const char *name)
{
    assert(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    BuildingType type = From_Name(name);
    if (type != BUILDING_NONE) {
        return As_Pointer(type);
    }

    BuildingTypeClass *ptr = new BuildingTypeClass(name);
    assert(ptr != nullptr);
    return ptr;
}
