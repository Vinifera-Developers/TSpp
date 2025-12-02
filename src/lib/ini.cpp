/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INI.H
 *
 *  @authors       CCHyper, Neijwiert
 *
 *  @brief         INI database manager.
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
#include "ini.h"
#include "rawfile.h"
#include "tspp_assert.h"
#include "wstring.h"
#include "wwmath.h"
#include <algorithm>
#include <sstream>


/**
 *  These defines control precision format of floating and double point values.
 *  This only effects output from the ini database, not input.
 *
 *  Currently: #.###, leading zeros are trimmed.
 */
#define FLOAT_FORMAT  "%.3g"  // "%.3f"
#define DOUBLE_FORMAT "%.3lg" // "%.3lf"


/**
 *  Checks whether or not a section or entry is present.
 *
 *  @author: CCHyper
 */
bool INIClass::Is_Present(const char* section, const char* entry) const
{
    if (!entry) {
        return Find_Section(section) != nullptr;
    } else {
        return Find_Entry(section, entry) != nullptr;
    }
}

