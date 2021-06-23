/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SIDE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for side types.
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
#include "side.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const SideClass &SideClass::As_Reference(SideType type)
{
    TSPP_ASSERT(type != SIDE_NONE && type < Sides.Count());
    return *Sides[type];
}


const SideClass *SideClass::As_Pointer(SideType type)
{
    TSPP_ASSERT(type != SIDE_NONE && type < Sides.Count());
    return type != SIDE_NONE && type < Sides.Count() ? Sides[type] : nullptr;
}


const SideClass &SideClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const SideClass *SideClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


SideType SideClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SIDE_NONE;
    }

    if (name != nullptr) {
        for (SideType index = SIDE_FIRST; index < Sides.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return SIDE_NONE;
}


const char *SideClass::Name_From(SideType type)
{
    return (type != SIDE_NONE && type < Sides.Count() ? As_Reference(type).Name() : "<none>");
}


const SideClass *SideClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (SideType index = SIDE_FIRST; index < Sides.Count(); ++index) {
        if (!strcasecmp(Sides[index]->Name(), name)) {
            return Sides[index];
        }
    }

    SideClass *ptr = new SideClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
