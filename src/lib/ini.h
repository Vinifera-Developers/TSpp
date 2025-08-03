/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INI.H
 *
 *  @authors       CCHyper
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
#pragma once

#include "always.h"
#include "listnode.h"
#include "pk.h"
#include "point.h"
#include "rect.h"
#include "search.h"
#include "wstring.h"
#include <objbase.h>


class FileClass;
class Straw;
class Pipe;
class Wstring;


#define INI_MAX_LINE_LENGTH 512


class INIClass
{
public:
    typedef enum IntegerFormatMode {
        DECIMAL_NOTATION = 0,      // Use decimal notation (i.e. 16)
        INTEL_HEX_NOTATION = 1,    // Use Intel's HEX notation (i.e. 10h)
        MOTOROLA_HEX_NOTATION = 2, // Use Motorola's HEX notation (i.e. $10)
    } IntegerFormatMode;

protected:
    struct INIComment {
        char* Value;
        INIComment* Next;
    };

    struct INIEntry : Node<const INIEntry*> {
        char* Entry;
        char* Value;
        INIComment* Comments;
        char* CommentString;
        int PreIndentCursor;
        int PostIndentCursor;
        int CommentCursor;
    };

    struct INISection : Node<const INISection*> {
        char* Section;
        List<INIEntry*> EntryList;
        IndexClass<int, const INIEntry*> EntryIndex;
        INIComment* Comments;
    };

public:
    INIClass();
    INIClass(FileClass& file, bool load_comments = false);
    virtual ~INIClass();

    bool Load(FileClass& file, bool load_comments = false);
    bool Load(Straw& straw, bool load_comments = false);
    int Save(FileClass& file, bool save_comments = false) const;
    int Save(Pipe& straw, bool save_comments = false) const;

    bool Clear(const char* section = nullptr, const char* entry = nullptr);

    bool Is_Loaded() const { return !SectionList.Is_Empty(); }
    bool Is_Present(const char* section, const char* entry = nullptr) const;
    bool Is_Present(const Wstring& section, Wstring& entry = Wstring()) const;

    int Entry_Count(const char* section) const;
    int Entry_Count(const Wstring& section) const;
    const char* Get_Entry(const char* section, int index) const;
    Wstring Get_Entry(const Wstring& section, int index) const;

    int Get_String(const char* section, const char* entry, const char* defvalue, char* buffer, int length) const;
    int Get_String(const char* section, const char* entry, char* buffer, int length) const;
    int Get_String(const Wstring& section, const Wstring& entry, const Wstring& defvalue, Wstring& buffer) const;
    int Get_String(const Wstring& section, const Wstring& entry, Wstring& buffer) const;
    bool Put_String(const char* section, const char* entry, const char* string);
    bool Put_String(const Wstring& section, const Wstring& entry, const Wstring& string);

    int Get_Int(const char* section, const char* entry, int defvalue = 0) const;
    int Get_Int(const Wstring& section, const Wstring& entry, int defvalue = 0) const;
    int Get_Int_Clamp(const char* section, const char* entry, int lo, int hi, int defvalue = 0) const;
    bool Put_Int(const char* section, const char* entry, int number, IntegerFormatMode format = DECIMAL_NOTATION);
    bool Put_Int(const Wstring& section, const Wstring& entry, int number, IntegerFormatMode format = DECIMAL_NOTATION);

    int Get_Hex(const char* section, const char* entry, int defvalue = 0) const;
    int Get_Hex(const Wstring& section, const Wstring& entry, int defvalue = 0) const;
    bool Put_Hex(const char* section, const char* entry, int number);
    bool Put_Hex(const Wstring& section, const Wstring& entry, int number);

    bool Get_Bool(const char* section, const char* entry, bool defvalue = false) const;
    bool Get_Bool(const Wstring& section, const Wstring& entry, bool defvalue = false) const;
    bool Put_Bool(const char* section, const char* entry, bool value);
    bool Put_Bool(const Wstring& section, const Wstring& entry, bool value);

    float Get_Float(const char* section, const char* entry, float defvalue = 0.0) const;
    float Get_Float(const Wstring& section, const Wstring& entry, float defvalue = 0.0f) const;
    float Get_Float_Clamp(const char* section, const char* entry, float lo, float hi, float defvalue = 0.0f) const;
    float Get_Float_Clamp(const Wstring& section, const Wstring& entry, float lo, float hi, float defvalue = 0.0f) const;
    bool Put_Float(const char* section, const char* entry, float value);
    bool Put_Float(const Wstring& section, const Wstring& entry, float value);

    double Get_Double(const char* section, const char* entry, double defvalue = 0.0) const;
    double Get_Double(const Wstring& section, const Wstring& entry, double defvalue = 0.0) const;
    double Get_Double_Clamp(const char* section, const char* entry, double lo, double hi, double defvalue = 0.0) const;
    double Get_Double_Clamp(const Wstring& section, const Wstring& entry, double lo, double hi, double defvalue = 0.0f) const;
    bool Put_Double(const char* section, const char* entry, double value);
    bool Put_Double(const Wstring& section, const Wstring& entry, double value);

    int Get_TextBlock(const char* section, char* buffer, int length) const;
    int Get_TextBlock(const Wstring& section, Wstring& buffer) const;
    bool Put_TextBlock(const char* section, const char* text);
    bool Put_TextBlock(const Wstring& section, const Wstring& text);

    int Get_UUBlock(const char* section, void* buffer, int length) const;
    int Get_UUBlock(const Wstring& section, void* buffer, int length) const;
    bool Put_UUBlock(const char* section, const void* block, int length);
    bool Put_UUBlock(const Wstring& section, const void* block, int length);

    const TRect<int> Get_Rect(const char* section, const char* entry, const TRect<int>& defvalue) const;
    TRect<int> Get_Rect(const Wstring& section, const Wstring& entry, const TRect<int>& defvalue) const;
    bool Put_Rect(const char* section, const char* entry, const TRect<int>& value);
    bool Put_Rect(const Wstring& section, const Wstring& entry, const TRect<int>& value);

    const TPoint2D<int> Get_Point(const char* section, const char* entry, const TPoint2D<int>& defvalue) const;
    const TPoint2D<int> Get_Point(const Wstring& section, const Wstring& entry, const TPoint2D<int>& defvalue) const;
    bool Put_Point(const char* section, const char* entry, const TPoint2D<int>& value);
    bool Put_Point(const Wstring& section, const Wstring& entry, const TPoint2D<int>& value);

    const TPoint3D<int> Get_Point(const char* section, const char* entry, const TPoint3D<int>& defvalue) const;
    const TPoint3D<int> Get_Point(const Wstring& section, const Wstring& entry, const TPoint3D<int>& defvalue) const;
    bool Put_Point(const char* section, const char* entry, const TPoint3D<int>& value);
    bool Put_Point(const Wstring& section, const Wstring& entry, const TPoint3D<int>& value);

    const TPoint3D<double> Get_Point(const char* section, const char* entry, const TPoint3D<double>& defvalue) const;
    const TPoint3D<double> Get_Point(const Wstring& section, const Wstring& entry, const TPoint3D<double>& defvalue) const;
    bool Put_Point(const char* section, const char* entry, const TPoint3D<double>& value);
    bool Put_Point(const Wstring& section, const Wstring& entry, const TPoint3D<double>& value);

    unsigned Get_Time(const char* section, const char* entry, unsigned defvalue = 0) const;
    bool Put_Time(const char* section, const char* entry, unsigned value);

    unsigned Get_Degree(const char* section, const char* entry, unsigned defvalue = 0) const;
    bool Put_Degree(const char* section, const char* entry, unsigned value);

    float Get_Angle(const char* section, const char* entry, float defvalue = 0.0f) const;
    bool Put_Angle(const char* section, const char* entry, float value);

    const CLSID Get_UUID(const char* section, const char* entry, const CLSID defvalue) const;
    const CLSID Get_UUID(const Wstring& section, const Wstring& entry, const CLSID defvalue) const;
    bool Put_UUID(const char* section, const char* entry, const CLSID value);
    bool Put_UUID(const Wstring& section, const Wstring& entry, const CLSID value);

    PKey Get_PKey(bool fast) const;
    bool Put_PKey(const PKey& key);

protected:
    const INISection* Find_Section(const char* section) const;
    const INIEntry* Find_Entry(const char* section, const char* entry) const;

public:
    List<const INISection*> SectionList;
    IndexClass<int, const INISection*> SectionIndex;
    INIComment* LineComments;
};


INIClass* Get_INI(const char* filename);
INIClass* Get_INI(FileClass& file);

bool Save_INI(INIClass* ini, const char* filename);
bool Save_INI(INIClass* ini, FileClass& file);

void Release_INI(INIClass* ini);
