/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OVERLAYTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for overlay types.
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
#include "overlaytype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


OverlayType OverlayTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return OVERLAY_NONE;
    }

    if (name != nullptr) {
        for (OverlayType index = OVERLAY_FIRST; index < OverlayTypes.Count(); ++index) {
            if (!strcasecmp(OverlayTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return OVERLAY_NONE;
}


const char* OverlayTypeClass::Name_From(OverlayType type)
{
    return (type != OVERLAY_NONE && type < OverlayTypes.Count() ? OverlayTypes[type]->Name() : "<none>");
}


OverlayTypeClass* OverlayTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, OverlayTypes);
}
