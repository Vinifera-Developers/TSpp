/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEAMTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for team types.
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
#include "teamtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"
#include "findmake.h"


TeamType TeamTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TEAM_NONE;
    }

    if (name != nullptr) {
        for (TeamType index = TEAM_FIRST; index < TeamTypes.Count(); ++index) {
            if (!strcasecmp(TeamTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TEAM_NONE;
}


const char *TeamTypeClass::Name_From(TeamType type)
{
    return (type != TEAM_NONE && type < TeamTypes.Count() ? TeamTypes[type]->Name() : "<none>");
}


const TeamTypeClass *TeamTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TeamTypes);
}
