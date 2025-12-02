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
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


InfantryType InfantryTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return INFANTRY_NONE;
    }

    if (name != nullptr) {
        for (InfantryType index = INFANTRY_FIRST; index < InfantryTypes.Count(); ++index) {
            if (!strcasecmp(InfantryTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return INFANTRY_NONE;
}


const char* InfantryTypeClass::Name_From(InfantryType type)
{
    return (type != INFANTRY_NONE && type < InfantryTypes.Count() ? InfantryTypes[type]->Name() : "<none>");
}


InfantryTypeClass* InfantryTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, InfantryTypes);
}
