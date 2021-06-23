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
#include "voc.h"
#include "unittype.h"


/**
 *  Fetch a voc (sound effect) from the INI database.
 * 
 *  @author: CCHyper
 */
VocType CCINIClass::Get_VocType(const char *section, const char *entry, const VocType defvalue)
{
	char buffer[1024];

	INIClass::Get_String(section, entry, VocClass::Name_From(defvalue), buffer, sizeof(buffer));

	return VocClass::From_Name(buffer);
}


/**
 *  Fetch the unit type identifier from the INI database.
 * 
 *  @author: CCHyper
 */
const UnitTypeClass *CCINIClass::Get_Unit(const char *section, const char *entry, const UnitTypeClass *defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {
        return UnitTypeClass::Find_Or_Make(buffer);
    }

    return defvalue;
}


/**
 *  Store the unit type identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Unit(const char *section, const char *entry, const UnitTypeClass *value)
{
    if (value) {
        return INIClass::Put_String(section, entry, value->Name());
    } else {
        return INIClass::Put_String(section, entry, "<none>");
    }
}
