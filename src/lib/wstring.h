/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WSTRING.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Simple string container.
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
#include <ostream> // for std::ostream


class Wstring
{
    public:
        Wstring();
        Wstring(const char *string);
        Wstring(const Wstring &string);
        ~Wstring();

        char operator[](int index);

        const Wstring &operator=(const char *string);
        const Wstring &operator=(const Wstring &string);

        Wstring operator+(const char *string) const;
        Wstring operator+(const Wstring &string_src) const;

        Wstring &operator+=(const char *string);
        Wstring &operator+=(const Wstring &string_src);

        bool operator>(const char *string) const { return Compare(string) > 0; }
        bool operator>(const Wstring &string_src) const { return Compare(string_src) > 0; }
        bool operator>=(const char *string) const { return Compare(string) >= 0; }
        bool operator>=(const Wstring &string_src) const { return Compare(string_src) >= 0; }

        bool operator<(const char *string) const { return Compare(string) < 0; }
        bool operator<(const Wstring &string_src) const { return Compare(string_src) < 0; }
        bool operator<=(const char *string) const { return Compare(string) <= 0; }
        bool operator<=(const Wstring &string_src) const { return Compare(string_src) <= 0; }

        bool operator==(const char *) const;
        bool operator==(const Wstring &) const;
        bool operator!=(const char *) const;
        bool operator!=(const Wstring &) const;

        char *Peek_Buffer();
        int Get_Length() const;
        void Release_Buffer();
        bool Is_Empty() const { return Buffer == nullptr || Buffer[0] == '\0' || Get_Length() <= 0; }
        Wstring To_Lower() const;
        Wstring To_Upper() const;
        bool Replace_Char(char to_set, unsigned index);
        bool Replace(unsigned length, const char *string);
        bool Resize(unsigned new_length);
        int Token(int index, char *string_delim, Wstring &out);
        int Next_Line(int index, Wstring &out);
        bool Remove_Character(const char char_to_find);
        void Remove_Spaces();
        bool Trim_To_Char(char string_delim);
        bool Trim_Range(int start, int end);
        bool func_7B54D0(const char *appendstr, unsigned len);
        void Reserve(int length);
        void Merge_Strings(char *string, int count);
        bool Concat(const char *string);
        bool Concat(unsigned size, const char *string);
        bool Concat(const Wstring &string);
        bool func_6A39E0(char a1, unsigned a2);
        bool func_6A3B20(const char *substr, const char *a2);
        bool Set(const char *string);
        inline int Compare(const char *string) const { return std::strcmp(Buffer, string); }
        inline int Compare(const Wstring &string) const { return std::strcmp(Buffer, string.Buffer); }
        inline int Compare_No_Case(const char *string) const { return strcmpi(Buffer, string); }
        inline int Compare_No_Case(const Wstring &string) const { return strcmpi(Buffer, string.Buffer); }

    public:
        char *Buffer;
};


inline bool operator==(const Wstring &left, const Wstring &right) { return left.Compare(right) == 0; }
inline bool operator==(const Wstring &left, const char *right) { return left.Compare(right) == 0; }
inline bool operator==(const char *left, const Wstring &right) { return right.Compare(left) == 0; }

inline bool operator!=(const Wstring &left, const Wstring &right) { return left.Compare(right) != 0; }
inline bool operator!=(const Wstring &left, const char *right) { return left.Compare(right) != 0; }
inline bool operator!=(const char *left, const Wstring &right) { return right.Compare(left) != 0; }

inline bool operator<(const Wstring &left, const Wstring &right) { return left.Compare(right) < 0; }
inline bool operator<(const Wstring &left, const char *right) { return left.Compare(right) < 0; }
inline bool operator<(const char *left, const Wstring &right) { return right.Compare(left) > 0; }

inline bool operator>(const Wstring &left, const Wstring &right) { return left.Compare(right) > 0; }
inline bool operator>(const Wstring &left, const char *right) { return left.Compare(right) < 0; }
inline bool operator>(const char *left, const Wstring &right) { return right.Compare(left) > 0; }

inline std::ofstream & operator<<(std::ofstream &stream, const Wstring &right)
{
    return stream << right.Buffer;
}

inline Wstring operator + (const Wstring &string1, const Wstring &string2)
{
    Wstring tmp(string1);
    tmp += string2;
    return tmp;
}

inline Wstring operator + (const char *string1, const Wstring &string2)
{
    Wstring tmp(string1);
    tmp += string2;
    return tmp;
}

inline Wstring operator + (const Wstring &string1, const char *string2)
{
    Wstring tmp1(string1);
    Wstring tmp2(string2);
    tmp1 += tmp2;
    return tmp1;
}
