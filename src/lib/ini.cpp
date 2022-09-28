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
#include "wstring.h"
#include "wwmath.h"
#include "tspp_assert.h"
#include <sstream>
#include <algorithm>


/**
 *  These defines control precision format of floating and double point values.
 *  This only effects output from the ini database, not input.
 *  
 *  Currently: #.###, leading zeros are trimmed.
 */
#define FLOAT_FORMAT "%.3g" // "%.3f"
#define DOUBLE_FORMAT "%.3lg" // "%.3lf"


/**
 *  Checks whether or not a section or entry is present.
 * 
 *  @author: CCHyper
 */
bool INIClass::Is_Present(const char *section, const char *entry) const
{
    if (!entry) {
        return Find_Section(section) != nullptr;
    } else {
        return Find_Entry(section, entry) != nullptr;
    }
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


/**
 *  The following are implementations of the Wstring variations.
 * 
 *  @author: CCHyper, Neijwiert
 */


int INIClass::Entry_Count(const Wstring &section) const
{
    return Entry_Count(section.Peek_Buffer());
}


Wstring INIClass::Get_Entry(const Wstring &section, int index) const
{
    return Wstring(Get_Entry(section.Peek_Buffer(), index));
}


int INIClass::Get_String(const Wstring &section, const Wstring &entry, const Wstring &defvalue, Wstring &buffer) const
{
    char buff[INI_MAX_LINE_LENGTH];

    int len = Get_String(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue.Peek_Buffer(), buff, INI_MAX_LINE_LENGTH);
    if (len == 0) {
        buff[0] = '\0';
    }

    buffer = buff;

    return len;
}


int INIClass::Get_String(const Wstring &section, const Wstring &entry, Wstring &buffer) const
{
    char buff[INI_MAX_LINE_LENGTH];

    int len = Get_String(section.Peek_Buffer(), entry.Peek_Buffer(), "", buff, INI_MAX_LINE_LENGTH);
    if (len == 0) {
        buff[0] = '\0';
    }

    buffer = buff;

    return len;
}


bool INIClass::Put_String(const Wstring &section, const Wstring &entry, const Wstring &string)
{
    return Put_String(section.Peek_Buffer(), entry.Peek_Buffer(), string.Peek_Buffer());
}


int INIClass::Get_Int(const Wstring &section, const Wstring &entry, int defvalue) const
{
    return Get_Int(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Int(const Wstring &section, const Wstring &entry, int number, IntegerFormatMode format)
{
    return Put_Int(section.Peek_Buffer(), entry.Peek_Buffer(), number, format);
}


int INIClass::Get_Hex(const Wstring &section, const Wstring &entry, int defvalue) const
{
    return Get_Hex(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Hex(const Wstring &section, const Wstring &entry, int number)
{
    return Put_Hex(section.Peek_Buffer(), entry.Peek_Buffer(), number);
}


bool INIClass::Get_Bool(const Wstring &section, const Wstring &entry, bool defvalue) const
{
    return Get_Bool(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Bool(const Wstring &section, const Wstring &entry, bool value)
{
    return Put_Bool(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


float INIClass::Get_Float(const Wstring &section, const Wstring &entry, float defvalue) const
{
    return Get_Float(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


float INIClass::Get_Float_Clamp(const Wstring &section, const Wstring &entry, float lo, float hi, float defvalue) const
{
    return Get_Float_Clamp(section.Peek_Buffer(), entry.Peek_Buffer(), lo, hi, defvalue);
}


bool INIClass::Put_Float(const Wstring &section, const Wstring &entry, float value)
{
    return Put_Float(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


double INIClass::Get_Double(const Wstring &section, const Wstring &entry, double defvalue) const
{
    return Get_Double(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


double INIClass::Get_Double_Clamp(const Wstring &section, const Wstring &entry, double lo, double hi, double defvalue) const
{
    return Get_Double_Clamp(section.Peek_Buffer(), entry.Peek_Buffer(), lo, hi, defvalue);
}


bool INIClass::Put_Double(const Wstring &section, const Wstring &entry, double value)
{
    return Put_Double(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


int INIClass::Get_TextBlock(const Wstring &section, Wstring &buffer) const
{
    std::ostringstream oss;

    int elen = Entry_Count(section);
    int total = 0;
    for (int index = 0; index < elen; index++) {

        if (index > 0) {
            oss << ' ';
            total++;
        }

        char buff[INI_MAX_LINE_LENGTH];
        Get_String(section.Peek_Buffer(), Get_Entry(section.Peek_Buffer(), index), buff, INI_MAX_LINE_LENGTH);

        int partial = strlen(buff);
        total += partial;
        oss << buff;
    }

    const std::string block = oss.str();
    buffer = block.c_str();
    return total;
}


bool INIClass::Put_TextBlock(const Wstring &section, const Wstring &text)
{
    return Put_TextBlock(section.Peek_Buffer(), text.Peek_Buffer());
}


int INIClass::Get_UUBlock(const Wstring &section, void *buffer, int length) const
{
    return Get_UUBlock(section.Peek_Buffer(), buffer, length);
}


bool INIClass::Put_UUBlock(const Wstring &section, const void *block, int length)
{
    return Put_UUBlock(section.Peek_Buffer(), block, length);
}


TRect<int> INIClass::Get_Rect(const Wstring &section, const Wstring &entry, const TRect<int> &defvalue) const
{
    return Get_Rect(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Rect(const Wstring &section, const Wstring &entry, const TRect<int> &value)
{
    return Put_Rect(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


const TPoint2D<int> INIClass::Get_Point(const Wstring &section, const Wstring &entry, const TPoint2D<int> &defvalue) const
{
    return Get_Point(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Point(const Wstring &section, const Wstring &entry, const TPoint2D<int> &value)
{
    return Put_Point(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


const TPoint3D<int> INIClass::Get_Point(const Wstring &section, const Wstring &entry, const TPoint3D<int> &defvalue) const
{
    return Get_Point(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_Point(const Wstring &section, const Wstring &entry, const TPoint3D<int> &value)
{
    return Put_Point(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}


unsigned INIClass::Get_Time(const char *section, const char *entry, unsigned defvalue) const
{
    TSPP_ASSERT(section != nullptr);
    TSPP_ASSERT(entry != nullptr);

    if (section == nullptr || entry == nullptr) {
        return defvalue;
    }

    const INIEntry *entryptr = Find_Entry(section, entry);
    if (entryptr == nullptr || entryptr->Value == nullptr) {
        return defvalue;
    }

    unsigned int h = ((defvalue / 60) / 60) / 60;
    unsigned int m = ((defvalue / 60) / 60) % 60;
    unsigned int s = (defvalue / 60) % 60;

    if (std::sscanf(entryptr->Value, "%02d:%02d:%02d", &h, &m, &s) == 3) {
        return (60 * ((s + 60) * (m + (60 * h))));
    }

    return defvalue;
}


bool INIClass::Put_Time(const char *section, const char *entry, unsigned value)
{
    char buffer[INI_MAX_LINE_LENGTH];

    unsigned int h = ((value / 60) / 60) / 60;
    unsigned int m = ((value / 60) / 60) % 60;
    unsigned int s = (value / 60) % 60;

    std::snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", h, m, s);

    return Put_String(section, entry, buffer);
}


unsigned INIClass::Get_Degree(const char *section, const char *entry, unsigned defvalue) const
{
    char buffer[INI_MAX_LINE_LENGTH];

    if (Get_String(section, entry, buffer, sizeof(buffer)) > 0) {
        return (std::strtol(buffer, nullptr, 10) * 256) / 360;
    }

    return defvalue;
}


bool INIClass::Put_Degree(const char *section, const char *entry, unsigned value)
{
    char buffer[INI_MAX_LINE_LENGTH];

    std::snprintf(buffer, sizeof(buffer), "%d", 360 * value / 256);

    return Put_String(section, entry, buffer);
}


float INIClass::Get_Angle(const char *section, const char *entry, float defvalue) const
{
    float value = Get_Float(section, entry, defvalue);
    if (value != -1.0f) {
        return DEG_TO_RADF(value);
    }

    return defvalue;
}


bool INIClass::Put_Angle(const char *section, const char *entry, float value)
{
    char buffer[INI_MAX_LINE_LENGTH];

    std::snprintf(buffer, sizeof(buffer), FLOAT_FORMAT, (value != -1.0f ? RAD_TO_DEGF(value) : 0.0f));

    return Put_String(section, entry, buffer);
}


const CLSID INIClass::Get_UUID(const Wstring &section, const Wstring &entry, const CLSID defvalue) const
{
    return Get_UUID(section.Peek_Buffer(), entry.Peek_Buffer(), defvalue);
}


bool INIClass::Put_UUID(const Wstring &section, const Wstring &entry, const CLSID value)
{
    return Put_UUID(section.Peek_Buffer(), entry.Peek_Buffer(), value);
}
