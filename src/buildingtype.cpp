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
#include "tspp_assert.h"


const BuildingTypeClass &BuildingTypeClass::As_Reference(StructType type)
{
    TSPP_ASSERT(type != STRUCT_NONE && type < BuildingTypes.Count());
    return *BuildingTypes[type];
}


const BuildingTypeClass *BuildingTypeClass::As_Pointer(StructType type)
{
    TSPP_ASSERT(type != STRUCT_NONE && type < BuildingTypes.Count());
    return type != STRUCT_NONE && type < BuildingTypes.Count() ? BuildingTypes[type] : nullptr;
}


const BuildingTypeClass &BuildingTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const BuildingTypeClass *BuildingTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


StructType BuildingTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return STRUCT_NONE;
    }

    if (name != nullptr) {
        for (StructType index = STRUCT_FIRST; index < BuildingTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return STRUCT_NONE;
}


const char *BuildingTypeClass::Name_From(StructType type)
{
    return (type != STRUCT_NONE && type < BuildingTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const BuildingTypeClass *BuildingTypeClass::Find_Or_Make(const char *name)
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

    BuildingTypeClass *ptr = new BuildingTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
