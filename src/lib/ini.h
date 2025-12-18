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
#include "wwcrc.h"
#include <objbase.h>
#include <string>


class FileClass;
class Straw;
class Pipe;


class INIClass
{
public:
    typedef enum IntegerFormatMode {
        DECIMAL_NOTATION = 0,      // Use decimal notation (i.e. 16)
        INTEL_HEX_NOTATION = 1,    // Use Intel's HEX notation (i.e. 10h)
        MOTOROLA_HEX_NOTATION = 2, // Use Motorola's HEX notation (i.e. $10)
    } IntegerFormatMode;

public:
    INIClass();
    virtual ~INIClass();

    /**
     *  Fetch and store INI data.
     */
    bool Load(FileClass& file, bool keepcomments = false);
    bool Load(Straw& straw, bool keepcomments = false);
    int Save(FileClass& file) const;
    int Save(Pipe& straw) const;

    /**
     *  Erase all data within this INI file manager.
     */
    bool Clear(const char* section = nullptr, const char* entry = nullptr);

    bool Is_Loaded() const { return !SectionList.Is_Empty(); }
    bool Is_Present(const char* section, const char* entry = nullptr) const;

    /**
     *  Fetch the number of sections in the INI file or verify if a specific
     *  section is present.
     */
    int Section_Count() const;
    bool Section_Present(char const* section) const { return Find_Section(section) != nullptr; }

    /**
     *  Fetch the number of entries in a section or get a particular entry in a section.
     */
    int Entry_Count(const char* section) const;
    const char* Get_Entry(const char* section, int index) const;

    /**
     *  Get the various data types from the section and entry specified.
     */
    int Get_String(char const* section, char const* entry, char const* defvalue, char* buffer, int size) const;
    int Get_Int(char const* section, char const* entry, int defvalue = 0) const;
    int Get_Hex(char const* section, char const* entry, int defvalue = 0) const;
    bool Get_Bool(char const* section, char const* entry, bool defvalue = false) const;
    int Get_TextBlock(char const* section, char* buffer, int len) const;
    int Get_UUBlock(char const* section, void* buffer, int len) const;
    PKey Get_PKey(bool fast) const;
    double Get_Float(char const* section, char const* entry, double defvalue = 0.0) const;
    TPoint2D<int> const Get_Point(char const* section, char const* entry, TPoint2D<int> const& defvalue) const;
    TPoint3D<int> const Get_Point(char const* section, char const* entry, TPoint3D<int> const& defvalue) const;
    TPoint3D<float> const Get_Point(char const* section, char const* entry, TPoint3D<float> const& defvalue) const;
    Rect const Get_Rect(char const* section, char const* entry, Rect const& defvalue) const;
    CLSID const Get_UUID(char const* section, char const* entry, CLSID defvalue) const;

    std::string Get_String(char const* section, char const* entry, std::string const& defvalue) const;
    std::string Get_TextBlock(char const* section) const;

    /**
     *  Put a data type to the section and entry specified.
     */
    bool Put_String(char const* section, char const* entry, char const* string);
    bool Put_Hex(char const* section, char const* entry, int number);
    bool Put_Int(char const* section, char const* entry, int number, IntegerFormatMode format = DECIMAL_NOTATION);
    bool Put_Bool(char const* section, char const* entry, bool value);
    bool Put_TextBlock(char const* section, char const* text);
    bool Put_UUBlock(char const* section, void const* block, int len);
    bool Put_PKey(PKey const& key);
    bool Put_Float(char const* section, char const* entry, double value);
    bool Put_Point(char const* section, char const* entry, TPoint2D<int> const& value);
    bool Put_Point(char const* section, char const* entry, TPoint3D<int> const& value);
    bool Put_Point(char const* section, char const* entry, TPoint3D<float> const& value);
    bool Put_Rect(char const* section, char const* entry, Rect const& value);
    bool Put_UUID(char const* section, char const* entry, CLSID const& value);

    bool Put_String(char const* section, char const* entry, std::string const& string);
    bool Put_TextBlock(char const* section, std::string const& text);

public:
    enum {
        MAX_LINE_LENGTH = 512
    };

    struct INIComment {
        INIComment() : Comment(nullptr), Next(nullptr) {}

        char* Comment;
        INIComment* Next;
    };

    /**
     *  The value entries for the INI file are stored as objects of this type.
     *  The entry identifier and value string are combined into this object.
     */
    struct INIEntry : public Node<INIEntry*> {
        INIEntry(char* entry = nullptr, char* value = nullptr, INIComment* comments = nullptr, char* commentstring = nullptr, int commentcursor = 0, int preindentcursor = 0, int postindentcursor = 0) :
            Entry(entry),
            Value(value),
            Comments(comments),
            CommentString(commentstring),
            PreIndentCursor(preindentcursor),
            PostIndentCursor(postindentcursor),
            CommentCursor(commentcursor)
        {
        }

        ~INIEntry();
        int Index_ID() const { return CRCEngine()(Entry, strlen(Entry)); }

        char* Entry;
        char* Value;
        INIComment* Comments;
        char* CommentString;
        int PreIndentCursor;
        int PostIndentCursor;
        int CommentCursor;

    private:
        /**
         *  Explicitly disable the copy constructor and the assignment operator.
         */
        INIEntry(INIEntry const& rvalue) = delete;
        INIEntry operator=(INIEntry const& that) = delete;
    };

    /**
     *  Each section (bracketed) is represented by an object of this type. All entries
     *  subordinate to this section are attached.
     */
    struct INISection : public Node<INISection*> {
        INISection(char* section, INIComment* comments = nullptr) : Section(section), Comments(comments) {}

        ~INISection();
        INIEntry* Find_Entry(char const* entry) const;
        int Index_ID() const { return CRCEngine()(Section, strlen(Section)); };

        char* Section;
        List<INIEntry*> EntryList;
        IndexClass<int, INIEntry*> EntryIndex;
        INIComment* Comments;

    private:
        /**
         *  Explicitly disable the copy constructor and the assignment operator.
         */
        INISection(INISection const& rvalue);
        INISection operator=(INISection const& that);
    };

    /**
     *  Utility routines to help find the appropriate section and entry objects.
     */
    INISection* Find_Section(char const* section) const;
    INIEntry* Find_Entry(char const* section, char const* entry) const;
    static void Strip_Comments(char* buffer);
    static bool Line_Contains_Section(char* buffer);
    static char* Extract_Line_Comment(char* buffer, int& assign, int& value, int& comment);

public:
    /**
     *  This is the list of all sections within this INI file.
     */
    List<const INISection*> SectionList;
    IndexClass<int, const INISection*> SectionIndex;
    INIComment* LineComments;

private:
    /**
     *  Explicitly disable the copy constructor and the assignment operator.
     */
    INIClass(INIClass const& rvalue) = delete;
    INIClass operator=(INIClass const& that) = delete;
};
