/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AITRIGTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for ai trigger types.
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
#include "aitrigtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


AITriggerType AITriggerTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return AITRIGGER_NONE;
    }

    if (name != nullptr) {
        for (AITriggerType index = AITRIGGER_FIRST; index < AITriggerTypes.Count(); ++index) {
            if (!strcasecmp(AITriggerTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return AITRIGGER_NONE;
}


const char* AITriggerTypeClass::Name_From(AITriggerType type)
{
    return (type != AITRIGGER_NONE && type < AITriggerTypes.Count() ? AITriggerTypes[type]->Name() : "<none>");
}


const AITriggerTypeClass* AITriggerTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (AITriggerType index = AITRIGGER_FIRST; index < AITriggerTypes.Count(); ++index) {
        if (!strcasecmp(AITriggerTypes[index]->Name(), name)) {
            return AITriggerTypes[index];
        }
    }

    AITriggerTypeClass* ptr = new AITriggerTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
