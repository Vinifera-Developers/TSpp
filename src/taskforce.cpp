/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TASKFORCE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for taks force types.
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
#include "taskforce.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TaskForceType TaskForceClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TASKFORCE_NONE;
    }

    if (name != nullptr) {
        for (TaskForceType index = TASKFORCE_FIRST; index < TaskForces.Count(); ++index) {
            if (!strcasecmp(TaskForces[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TASKFORCE_NONE;
}


TaskForceType TaskForceClass::From_Full_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TASKFORCE_NONE;
    }

    if (name != nullptr) {
        for (TaskForceType index = TASKFORCE_FIRST; index < TaskForces.Count(); ++index) {
            if (!strcasecmp(TaskForces[index]->Full_Name(), name)) {
                return index;
            }
        }
    }

    return TASKFORCE_NONE;
}


const char* TaskForceClass::Name_From(TaskForceType type)
{
    return (type != TASKFORCE_NONE && type < TaskForces.Count() ? TaskForces[type]->Name() : "<none>");
}


TaskForceClass* TaskForceClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, TaskForces);
}
