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
#include <algorithm>


/**
 *  Checks whether or not a section or entry is present.
 * 
 *  @author: CCHyper
 */
bool INIClass::Is_Present(const char *section, const char *entry) const
{
    if (!entry) {
        return Find_Section(section) != nullptr;
    }
    return Find_Entry(section, entry) != nullptr;
}


/**
 *  Fetch the value of a particular entry in a specified section.
 * 
 *  @author: CCHyper
 */
int INIClass::Get_String(const char *section, const char *entry, char *buffer, int length) const
{
    static const char *_null_char = "";
    return Get_String(section, entry, "", buffer, length);
}


/**
 *  Fetch a integer entry from the specified section and then clamps it.
 * 
 *  @author: CCHyper
 */
int INIClass::Get_Int_Clamp(const char *section, const char *entry, int lo, int hi, int defvalue) const
{
    return std::clamp(Get_Int(section, entry, defvalue), lo, hi);
}


/**
 *  Fetch a float entry from the specified section.
 * 
 *  @author: CCHyper
 */
float INIClass::Get_Float(const char *section, const char *entry, float defvalue) const
{
    return Get_Double(section, entry, defvalue);
}


/**
 *  Fetch a float entry from the specified section and then clamps it.
 * 
 *  @author: CCHyper
 */
float INIClass::Get_Float_Clamp(const char *section, const char *entry, float lo, float hi, float defvalue) const
{
    return std::clamp(Get_Float(section, entry, defvalue), lo, hi);
}


/**
 *  Stores a float into the INI database.
 * 
 *  @author: CCHyper
 */
bool INIClass::Put_Float(const char *section, const char *entry, float value)
{
    return Put_Double(section, entry, value);
}


/**
 *  Fetch a double entry from the specified section and then clamps it.
 * 
 *  @author: CCHyper
 */
double INIClass::Get_Double_Clamp(const char *section, const char *entry, double lo, double hi, double defvalue) const
{
    return std::clamp(Get_Double(section, entry, defvalue), lo, hi);
}
