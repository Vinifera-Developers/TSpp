/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCRIPTTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for script types.
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
#include "scripttype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const ScriptTypeClass &ScriptTypeClass::As_Reference(ScriptType type)
{
    TSPP_ASSERT(type != SCRIPT_NONE && type < ScriptTypes.Count());
    return *ScriptTypes[type];
}


const ScriptTypeClass *ScriptTypeClass::As_Pointer(ScriptType type)
{
    TSPP_ASSERT(type != SCRIPT_NONE && type < ScriptTypes.Count());
    return type != SCRIPT_NONE && type < ScriptTypes.Count() ? ScriptTypes[type] : nullptr;
}


const ScriptTypeClass &ScriptTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const ScriptTypeClass *ScriptTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


ScriptType ScriptTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return SCRIPT_NONE;
    }

    if (name != nullptr) {
        for (ScriptType index = SCRIPT_FIRST; index < ScriptTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return SCRIPT_NONE;
}


const char *ScriptTypeClass::Name_From(ScriptType type)
{
    return (type != SCRIPT_NONE && type < ScriptTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const ScriptTypeClass *ScriptTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    ScriptType type = From_Name(name);
    if (type != SCRIPT_NONE) {
        return As_Pointer(type);
    }

    ScriptTypeClass *ptr = new ScriptTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
