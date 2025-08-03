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
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


SuperWeaponType SuperWeaponTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SUPER_NONE;
    }

    if (name != nullptr) {
        for (SuperWeaponType index = SUPER_FIRST; index < SuperWeaponTypes.Count(); ++index) {
            if (!strcasecmp(SuperWeaponTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return SUPER_NONE;
}


const char* SuperWeaponTypeClass::Name_From(SuperWeaponType type)
{
    return (type != SUPER_NONE && type < SuperWeaponTypes.Count() ? SuperWeaponTypes[type]->Name() : "<none>");
}


const SuperWeaponTypeClass* SuperWeaponTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, SuperWeaponTypes);
}
