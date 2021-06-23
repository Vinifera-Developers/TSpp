/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TRIGGERTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for trigger types.
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
#include "triggertype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const TriggerTypeClass &TriggerTypeClass::As_Reference(TriggerType type)
{
    TSPP_ASSERT(type != TRIGGER_NONE && type < TriggerTypes.Count());
    return *TriggerTypes[type];
}


const TriggerTypeClass *TriggerTypeClass::As_Pointer(TriggerType type)
{
    TSPP_ASSERT(type != TRIGGER_NONE && type < TriggerTypes.Count());
    return type != TRIGGER_NONE && type < TriggerTypes.Count() ? TriggerTypes[type] : nullptr;
}


const TriggerTypeClass &TriggerTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const TriggerTypeClass *TriggerTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


TriggerType TriggerTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TRIGGER_NONE;
    }

    if (name != nullptr) {
        for (TriggerType index = TRIGGER_FIRST; index < TriggerTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
            if (!strcasecmp(As_Reference(index).Full_Name(), name)) {
                return index;
            }
        }
    }

    return TRIGGER_NONE;
}


const char *TriggerTypeClass::Name_From(TriggerType type)
{
    return (type != TRIGGER_NONE && type < TriggerTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const TriggerTypeClass *TriggerTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (TriggerType index = TRIGGER_FIRST; index < TriggerTypes.Count(); ++index) {
        if (!strcasecmp(TriggerTypes[index]->Name(), name)) {
            return TriggerTypes[index];
        }
        if (!strcasecmp(TriggerTypes[index]->Full_Name(), name)) {
            return TriggerTypes[index];
        }
    }

    TriggerTypeClass *ptr = new TriggerTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
