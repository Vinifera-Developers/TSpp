/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HOUSETYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for house types.
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
#include "housetype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"
#include "findmake.h"


HousesType HouseTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return HOUSE_NONE;
    }

    if (name != nullptr) {
        for (HousesType index = HOUSE_FIRST; index < HouseTypes.Count(); ++index) {
            if (!strcasecmp(HouseTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return HOUSE_NONE;
}


const char *HouseTypeClass::Name_From(HousesType type)
{
    return (type != HOUSE_NONE && type < HouseTypes.Count() ? HouseTypes[type]->Name() : "<none>");
}


const HouseTypeClass *HouseTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, HouseTypes);
}
