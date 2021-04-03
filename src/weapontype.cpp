/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WEAPONTYPE.CPP
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
#include "weapontype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const WeaponTypeClass &WeaponTypeClass::As_Reference(WeaponType type)
{
    TSPP_ASSERT(type != WEAPON_NONE && type < WeaponTypes.Count());
    return *WeaponTypes[type];
}


const WeaponTypeClass *WeaponTypeClass::As_Pointer(WeaponType type)
{
    TSPP_ASSERT(type != WEAPON_NONE && type < WeaponTypes.Count());
    return type != WEAPON_NONE && type < WeaponTypes.Count() ? WeaponTypes[type] : nullptr;
}


const WeaponTypeClass &WeaponTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const WeaponTypeClass *WeaponTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


WeaponType WeaponTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return WEAPON_NONE;
    }

    if (name != nullptr) {
        for (WeaponType index = WEAPON_FIRST; index < WeaponTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return WEAPON_NONE;
}


const char *WeaponTypeClass::Name_From(WeaponType type)
{
    return (type != WEAPON_NONE && type < WeaponTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const WeaponTypeClass *WeaponTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    WeaponType type = From_Name(name);
    if (type != WEAPON_NONE) {
        return As_Pointer(type);
    }

    WeaponTypeClass *ptr = new WeaponTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
