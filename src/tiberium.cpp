/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBERIUM.CPP
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for tiberium types.
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
#include "tiberium.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


TiberiumType TiberiumClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return TIBERIUM_NONE;
    }

    if (name != nullptr) {
        for (TiberiumType index = TIBERIUM_FIRST; index < Tiberiums.Count(); ++index) {
            if (!strcasecmp(Tiberiums[index]->Name(), name)) {
                return index;
            }
        }
    }

    return TIBERIUM_NONE;
}


const char* TiberiumClass::Name_From(TiberiumType type)
{
    return (type != TIBERIUM_NONE && type < Tiberiums.Count() ? Tiberiums[type]->Name() : "<none>");
}


const TiberiumClass* TiberiumClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, Tiberiums);
}
