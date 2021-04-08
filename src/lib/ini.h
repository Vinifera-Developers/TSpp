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
#include "search.h"
#include "trect.h"
#include "tpoint.h"
#include "pk.h"
#include <objbase.h>


class FileClass;
class Straw;
class Pipe;


#define INI_MAX_LINE_LENGTH 512


class INIClass
{
    protected:
        struct INIComment
        {
            char *Value;
            INIComment *Next;
        };

        struct INIEntry : Node<const INIEntry *>
        {
            char *Entry;
            char *Value;
            INIComment *Comments;
            char *CommentString;
            int PreIndentCursor;
            int PostIndentCursor;
            int CommentCursor;
        };

        struct INISection : Node<const INISection *>
        {
            char *Section;
            List<INIEntry *> EntryList;
            IndexClass<int, const INIEntry *> EntryIndex;
            INIComment *Comments;
        };

    public:
        INIClass();
        INIClass(FileClass &file, bool load_comments = false);
        virtual ~INIClass();

        bool Load(FileClass &file, bool load_comments = false);
        bool Load(Straw &straw, bool load_comments = false);
        int Save(FileClass &file, bool save_comments = false) const;
        int Save(Pipe &straw, bool save_comments = false) const;

        bool Clear(const char *section = nullptr, const char *entry = nullptr);

        bool Is_Loaded() const { return !SectionList.Is_Empty(); }
        bool Is_Present(const char *section, const char *entry = nullptr) const
        {
            if (entry == nullptr) return Find_Section(section) != nullptr;
            return Find_Entry(section, entry) != nullptr;
        }

        int Entry_Count(const char *section) const;
        const char *Get_Entry(const char *section, int index) const;

        int Get_String(const char *section, const char *entry, const char *defvalue, char *buffer, int length) const;
        inline int Get_String(const char *section, const char *entry, char *buffer, int length) const
        {
            static const char *_null_char = "";
            return Get_String(section, entry, "", buffer, length);
        }
        bool Put_String(const char *section, const char *entry, const char *string);

        int Get_Int(const char *section, const char *entry, int defvalue = 0) const;
        bool Put_Int(const char *section, const char *entry, int number, int format = 0);
        
        int Get_Hex(const char *section, const char *entry, int defvalue = 0) const;
        bool Put_Hex(const char *section, const char *entry, int number);
        
        bool Get_Bool(const char *section, const char *entry, bool defvalue = false) const;
        bool Put_Bool(const char *section, const char *entry, bool value);

        inline float Get_Float(const char *section, const char *entry, float defvalue = 0.0) const
        {
            return Get_Double(section, entry, defvalue);
        }
        inline float Get_Float_Clamp(const char *section, const char *entry, float lo, float hi, float defvalue = 0.0f) const
        {
            return std::clamp(Get_Float(section, entry, defvalue), lo, hi);
        }
        inline bool Put_Float(const char *section, const char *entry, float value)
        {
            return Put_Double(section, entry, value);
        }

        double Get_Double(const char *section, const char *entry, double defvalue = 0.0) const;
        inline double Get_Double_Clamp(const char *section, const char *entry, double lo, double hi, double defvalue = 0.0) const
        {
            return std::clamp(Get_Double(section, entry, defvalue), lo, hi);
        }
        bool Put_Double(const char *section, const char *entry, double value);

        int Get_TextBlock(const char *section, char *buffer, int length) const;
        bool Put_TextBlock(const char *section, const char *text);

        int Get_UUBlock(const char *section, void *buffer, int length) const;
        bool Put_UUBlock(const char *section, const void * block, int length);

        const TRect<int> Get_Rect(const char *section, const char *entry, const TRect<int> &defvalue) const;
        bool Put_Rect(const char *section, const char *entry, const TRect<int> &value);
        const TPoint2D<int> Get_Point(const char *section, const char *entry, const TPoint2D<int> &defvalue) const;
        bool Put_Point(const char *section, const char *entry, const TPoint2D<int> &value);
        const TPoint3D<int> Get_Point(const char *section, const char *entry, const TPoint3D<int> &defvalue) const;
        bool Put_Point(const char *section, const char *entry, const TPoint3D<int> &value);
        const TPoint3D<double> Get_Point(const char *section, const char *entry, const TPoint3D<double> &defvalue) const;
        bool Put_Point(const char *section, const char *entry, const TPoint3D<double> &value);

        const CLSID Get_UUID(const char *section, const char *entry, const CLSID defvalue) const;
        bool Put_UUID(const char *section, const char *entry, const CLSID value);

        PKey Get_PKey(bool fast) const;
        bool Put_PKey(const PKey &key);

    protected:
        const INISection * Find_Section(const char *section) const;
        const INIEntry * Find_Entry(const char *section, const char *entry) const;

    protected:
        List<const INISection *> SectionList;
        IndexClass<int, const INISection *> SectionIndex;
        INIComment *LineComments;
};
