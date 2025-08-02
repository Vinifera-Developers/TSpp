/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ISOTILETYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for isometric tile types.
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
#include "isotiletype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


IsometricTileType IsometricTileTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return ISOTILE_NONE;
    }

    if (name != nullptr) {
        for (IsometricTileType index = ISOTILE_FIRST; index < IsoTileTypes.Count(); ++index) {
            if (!strcasecmp(IsoTileTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return ISOTILE_NONE;
}


const char *IsometricTileTypeClass::Name_From(IsometricTileType type)
{
    return (type != ISOTILE_NONE && type < IsoTileTypes.Count() ? IsoTileTypes[type]->Name() : "<none>");
}
