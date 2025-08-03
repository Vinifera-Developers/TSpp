/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ANIMTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for animation types.
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
#include "animtype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


AnimType AnimTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return ANIM_NONE;
    }

    if (name != nullptr) {
        for (AnimType index = ANIM_FIRST; index < AnimTypes.Count(); ++index) {
            if (!strcasecmp(AnimTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return ANIM_NONE;
}


const char* AnimTypeClass::Name_From(AnimType type)
{
    return (type != ANIM_NONE && type < AnimTypes.Count() ? AnimTypes[type]->Name() : "<none>");
}


const AnimTypeClass* AnimTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (AnimType index = ANIM_FIRST; index < AnimTypes.Count(); ++index) {
        if (!strcasecmp(AnimTypes[index]->Name(), name)) {
            return AnimTypes[index];
        }
    }

    AnimTypeClass* ptr = new AnimTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
