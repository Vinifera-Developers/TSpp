/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INFANTRYTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for infantry types.
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
#include "infantrytype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const InfantryTypeClass &InfantryTypeClass::As_Reference(InfantryType type)
{
    TSPP_ASSERT(type != INFANTRY_NONE && type < InfantryTypes.Count());
    return *InfantryTypes[type];
}


const InfantryTypeClass *InfantryTypeClass::As_Pointer(InfantryType type)
{
    TSPP_ASSERT(type != INFANTRY_NONE && type < InfantryTypes.Count());
    return type != INFANTRY_NONE && type < InfantryTypes.Count() ? InfantryTypes[type] : nullptr;
}


const InfantryTypeClass &InfantryTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const InfantryTypeClass *InfantryTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


InfantryType InfantryTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return INFANTRY_NONE;
    }

    if (name != nullptr) {
        for (InfantryType index = INFANTRY_FIRST; index < InfantryTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return INFANTRY_NONE;
}


const char *InfantryTypeClass::Name_From(InfantryType type)
{
    return (type != INFANTRY_NONE && type < InfantryTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const InfantryTypeClass *InfantryTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (InfantryType index = INFANTRY_FIRST; index < InfantryTypes.Count(); ++index) {
        if (!strcasecmp(InfantryTypes[index]->Name(), name)) {
            return InfantryTypes[index];
        }
    }

    InfantryTypeClass *ptr = new InfantryTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
