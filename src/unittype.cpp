/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          UNITTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for unit types.
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
#include "unittype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


UnitType UnitTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return UNIT_NONE;
    }

    if (name != nullptr) {
        for (UnitType index = UNIT_FIRST; index < UnitTypes.Count(); ++index) {
            if (!strcasecmp(UnitTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return UNIT_NONE;
}


const char* UnitTypeClass::Name_From(UnitType type)
{
    return (type != UNIT_NONE && type < UnitTypes.Count() ? UnitTypes[type]->Name() : "<none>");
}


const UnitTypeClass* UnitTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, UnitTypes);
}
