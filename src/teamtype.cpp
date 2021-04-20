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


const TeamTypeClass &TeamTypeClass::As_Reference(TeamType type)
{
    TSPP_ASSERT(type != TEAM_NONE && type < TeamTypes.Count());
    return *TeamTypes[type];
}


const TeamTypeClass *TeamTypeClass::As_Pointer(TeamType type)
{
    TSPP_ASSERT(type != TEAM_NONE && type < TeamTypes.Count());
    return type != TEAM_NONE && type < TeamTypes.Count() ? TeamTypes[type] : nullptr;
}


const TeamTypeClass &TeamTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const TeamTypeClass *TeamTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


TeamType TeamTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TEAM_NONE;
    }

    if (name != nullptr) {
        for (TeamType index = TEAM_FIRST; index < TeamTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return TEAM_NONE;
}


const char *TeamTypeClass::Name_From(TeamType type)
{
    return (type != TEAM_NONE && type < TeamTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const TeamTypeClass *TeamTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    TeamType type = From_Name(name);
    if (type != TEAM_NONE) {
        return As_Pointer(type);
    }

    TeamTypeClass *ptr = new TeamTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
