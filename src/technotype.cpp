/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TECHNOTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class which all buildable game object types derive from.
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
#include "technotype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const TechnoTypeClass *TechnoTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    if (name != nullptr) {
        for (int index = 0; index < TechnoTypes.Count(); ++index) {
            const TechnoTypeClass *ttype = TechnoTypes[index];
            if (!strcasecmp(ttype->Name(), name)) {
                return ttype;
            }
        }
    }

    return nullptr;
}
