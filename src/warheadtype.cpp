/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WARHEADTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for weapon types.
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
#include "warheadtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const WarheadTypeClass &WarheadTypeClass::As_Reference(WarheadType type)
{
    TSPP_ASSERT(type != INFANTRY_NONE && type < WarheadTypes.Count());
    return *WarheadTypes[type];
}


const WarheadTypeClass *WarheadTypeClass::As_Pointer(WarheadType type)
{
    TSPP_ASSERT(type != INFANTRY_NONE && type < WarheadTypes.Count());
    return type != INFANTRY_NONE && type < WarheadTypes.Count() ? WarheadTypes[type] : nullptr;
}


const WarheadTypeClass &WarheadTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const WarheadTypeClass *WarheadTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


WarheadType WarheadTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return WARHEAD_NONE;
    }

    if (name != nullptr) {
        for (WarheadType index = WARHEAD_FIRST; index < WarheadTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return WARHEAD_NONE;
}


const char *WarheadTypeClass::Name_From(WarheadType type)
{
    return (type != WARHEAD_NONE && type < WarheadTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const WarheadTypeClass *WarheadTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    WarheadType type = From_Name(name);
    if (type != WARHEAD_NONE) {
        return As_Pointer(type);
    }

    WarheadTypeClass *ptr = new WarheadTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
