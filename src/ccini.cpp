/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CCINI.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Advanced version of the INI database manager which handles
 *                 the C&C engine types and identifiers.
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
#include "ccini.h"
#include "aircrafttype.h"
#include "animtype.h"
#include "buildingtype.h"
#include "infantrytype.h"
#include "mission.h"
#include "overlaytype.h"
#include "particlesystype.h"
#include "particletype.h"
#include "tiberium.h"
#include "tibsun_functions.h"
#include "tibsun_globals.h"
#include "unittype.h"
#include "voc.h"
#include "warheadtype.h"
#include "weapontype.h"


/**
 *  Fetch a land identifier from the INI database.
 *
 *  @author: CCHyper
 */
LayerType CCINIClass::Get_LayerType(const char* section, const char* entry, LayerType defvalue) const
{
    char buffer[1024];

    if (Get_String(section, entry, Name_From_Layer(defvalue), buffer, sizeof(buffer)) > 0) {
        return Layer_From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Store a land identifier to the INI database.
 *
 *  @author: CCHyper
 */
bool CCINIClass::Put_LayerType(const char* section, const char* entry, LayerType value)
{
    return Put_String(section, entry, Name_From_Layer(value));
}