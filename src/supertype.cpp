/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SUPERTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for super weapon types.
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
#include "supertype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const SuperWeaponTypeClass &SuperWeaponTypeClass::As_Reference(SuperWeaponType type)
{
    TSPP_ASSERT(type != SUPER_NONE && type < SuperWeaponTypes.Count());
    return *SuperWeaponTypes[type];
}


const SuperWeaponTypeClass *SuperWeaponTypeClass::As_Pointer(SuperWeaponType type)
{
    TSPP_ASSERT(type != SUPER_NONE && type < SuperWeaponTypes.Count());
    return type != SUPER_NONE && type < SuperWeaponTypes.Count() ? SuperWeaponTypes[type] : nullptr;
}


const SuperWeaponTypeClass &SuperWeaponTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const SuperWeaponTypeClass *SuperWeaponTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


SuperWeaponType SuperWeaponTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SUPER_NONE;
    }

    if (name != nullptr) {
        for (SuperWeaponType index = SUPER_FIRST; index < SuperWeaponTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return SUPER_NONE;
}


const char *SuperWeaponTypeClass::Name_From(SuperWeaponType type)
{
    return (type != SUPER_NONE && type < SuperWeaponTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const SuperWeaponTypeClass *SuperWeaponTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (SuperWeaponType index = SUPER_FIRST; index < SuperWeaponTypes.Count(); ++index) {
        if (!strcasecmp(SuperWeaponTypes[index]->Name(), name)) {
            return SuperWeaponTypes[index];
        }
    }

    SuperWeaponTypeClass *ptr = new SuperWeaponTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
