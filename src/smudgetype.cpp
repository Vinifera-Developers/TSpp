/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SMUGETYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for smudge types.
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
#include "smudgetype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const SmudgeTypeClass &SmudgeTypeClass::As_Reference(SmudgeType type)
{
    TSPP_ASSERT(type != SMUDGE_NONE && type < SmudgeTypes.Count());
    return *SmudgeTypes[type];
}


const SmudgeTypeClass *SmudgeTypeClass::As_Pointer(SmudgeType type)
{
    TSPP_ASSERT(type != SMUDGE_NONE && type < SmudgeTypes.Count());
    return type != SMUDGE_NONE && type < SmudgeTypes.Count() ? SmudgeTypes[type] : nullptr;
}


const SmudgeTypeClass &SmudgeTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const SmudgeTypeClass *SmudgeTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


SmudgeType SmudgeTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SMUDGE_NONE;
    }

    if (name != nullptr) {
        for (SmudgeType index = SMUDGE_FIRST; index < SmudgeTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return SMUDGE_NONE;
}


const char *SmudgeTypeClass::Name_From(SmudgeType type)
{
    return (type != SMUDGE_NONE && type < SmudgeTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const SmudgeTypeClass *SmudgeTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    SmudgeType type = From_Name(name);
    if (type != SMUDGE_NONE) {
        return As_Pointer(type);
    }

    SmudgeTypeClass *ptr = new SmudgeTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
