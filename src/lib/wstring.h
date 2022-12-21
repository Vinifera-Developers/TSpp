/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WSTRING.H
 *
 *  @author        Neijwiert
 *
 *  @contributors  CCHyper
 *
 *  @brief         A base implementation for dealing with strings without
 *                 directly interacting with c-style character arrays.
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
#include "tspp_assert.h"
#include <ostream>


class Wstring
{
    friend Wstring operator+(const Wstring &lhs, const char *rhs);
    friend Wstring operator+(const char *lhs, const Wstring &rhs);
    friend Wstring operator+(const Wstring &lhs, char *rhs);
    friend Wstring operator+(char *lhs, const Wstring &rhs);
    friend Wstring operator+(const Wstring &lhs, const Wstring &rhs);

    public:
        Wstring();
        Wstring(char c);
        Wstring(const char *string);
        Wstring(const Wstring &that);
        Wstring(Wstring &&that) noexcept;
        ~Wstring();

        Wstring &operator=(const Wstring &that);
        Wstring &operator=(Wstring &&that) noexcept;
        Wstring &operator=(char c);
        Wstring &operator=(const char *string);
        Wstring &operator+=(char c);
        Wstring &operator+=(const char *string);
        Wstring &operator+=(const Wstring &that);

        inline bool operator==(const char *string) const;
        inline bool operator==(const Wstring &that) const;
        inline bool operator!=(const char *string) const;
        inline bool operator!=(const Wstring &that) const;
        inline bool operator>(const char *string) const;
        inline bool operator>(const Wstring &that) const;
        inline bool operator>=(const char *string) const;
        inline bool operator>=(const Wstring &that) const;
        inline bool operator<(const char *string) const;
        inline bool operator<(const Wstring &that) const;
        inline bool operator<=(const char *string) const;
        inline bool operator<=(const Wstring &that) const;

        const char &operator[](int index) const
        {
            return Get_Char(index);
        }

        void Release_Buffer();
        char *Peek_Buffer();
        const char *Peek_Buffer() const;
        void Get_Buffer(char *string, int length) const;
        int Get_Length() const;
        bool Is_Empty() const;
        bool Is_Not_Empty() const;
        bool Resize(int new_length);
        void Reserve(int length);
        void To_Lower();
        Wstring As_Lower() const;
        void To_Upper();
        Wstring As_Upper() const;
        int Compare(const char *string) const;
        int Compare(const Wstring &that) const;
        int Compare_No_Case(const char *string) const;
        int Compare_No_Case(const Wstring &that) const;
        bool Contains(const char *delimiters) const;
        bool Contains(const Wstring &delimiters) const;
        bool Contains_String(const char *string) const;
        bool Contains_String(const Wstring &that) const;
        bool Set(char c);
        bool Set(const char *string);
        bool Set(const Wstring &that);
        bool Set(Wstring &&that) noexcept;
        bool Set(int length, const char *string);
        bool Set(int length, const Wstring &that);
        char Get_Char(int index);
        const char Get_Char(int index) const;
        bool Set_Char(char c, int index);
        bool Concat(const char *string);
        bool Concat(int length, const char *string);
        bool Concat(const Wstring &that);
        bool Concat(int length, const Wstring &that);
        bool Concat(char c);
        bool Remove_Character(char c);
        void Remove_Whitespace();
        int Split(int start_index, const char *delimiters, Wstring &split_string) const;
        int Split(int start_index, const Wstring &delimiters, Wstring &split_string) const;
        int Next_Line(int start_index, Wstring &line) const;
        bool Trim_To_Char(char c);
        bool Trim_Range(int start_index, int length);
        void Trim_To_First_Difference(const char *delimiters);
        void Trim_To_First_Difference(const Wstring &delimiters);
        void Trim_After_First_Difference(const char *delimiters);
        void Trim_After_First_Difference(const Wstring &delimiters);
        int As_Integer() const;
        bool Insert(char c, int index);
        bool Insert(const char *string, int index);
        bool Insert(const Wstring &that, int index);
        bool Replace(const char *str_to_replace, const char *replacement_str);
        bool Replace(const Wstring &str_to_replace, const Wstring &replacement_str);

        static Wstring Number_To_String(int value);
        static Wstring Number_To_String(int value, int leading_zeros);

    private:
        bool Internal_Set(int length, const char *string);
        bool Internal_Insert(const char *string, int index, int length);
        bool Internal_Concat(int length, const char *string);

        static bool Combine_Strings(const char *lhs, int lhs_length, const char *rhs, int rhs_length, char *&result);

    protected:
        char *Buffer;

    private:
        static const char NullChar;
        static const char *EmptyString;
};


bool Wstring::operator==(const char *string) const
{
    return Compare(string) == 0;
}


bool Wstring::operator==(const Wstring &that) const
{
    return Compare(that) == 0;
}


bool Wstring::operator!=(const char *string) const
{
    return Compare(string) != 0;
}


bool Wstring::operator!=(const Wstring &that) const
{
    return Compare(that) != 0;
}


bool Wstring::operator>(const char *string) const
{
    return Compare(string) > 0;
}


bool Wstring::operator>(const Wstring &that) const
{
    return Compare(that) > 0;
}


bool Wstring::operator>=(const char *string) const
{
    return Compare(string) >= 0;
}


bool Wstring::operator>=(const Wstring &that) const
{
    return Compare(that) >= 0;
}


bool Wstring::operator<(const char *string) const
{
    return Compare(string) < 0;
}


bool Wstring::operator<(const Wstring &that) const
{
    return Compare(that) < 0;
}


bool Wstring::operator<=(const char *string) const
{
    return Compare(string) <= 0;
}


bool Wstring::operator<=(const Wstring &that) const
{
    return Compare(that) <= 0;
}


inline Wstring operator+(const Wstring &lhs, const char *rhs)
{
    char *new_string = nullptr;
    bool result = Wstring::Combine_Strings(lhs.Buffer, lhs.Get_Length(), rhs, rhs == nullptr ? 0 : std::strlen(rhs), new_string);
    TSPP_ASSERT(result);

    return Wstring(new_string);
}


inline Wstring operator+(const char *lhs, const Wstring &rhs)
{
    char *new_string = nullptr;
    bool result = Wstring::Combine_Strings(lhs, lhs == nullptr ? 0 : std::strlen(lhs), rhs.Buffer, rhs.Get_Length(), new_string);
    TSPP_ASSERT(result);

    return Wstring(new_string);
}


inline Wstring operator+(const Wstring &lhs, char *rhs)
{
    char *new_string = nullptr;
    bool result = Wstring::Combine_Strings(lhs.Buffer, lhs.Get_Length(), rhs, 1, new_string);
    TSPP_ASSERT(result);

    return Wstring(new_string);
}


inline Wstring operator+(char *lhs, const Wstring &rhs)
{
    char *new_string = nullptr;
    bool result = Wstring::Combine_Strings(lhs, 1, rhs.Buffer, rhs.Get_Length(), new_string);
    TSPP_ASSERT(result);

    return Wstring(new_string);
}


inline Wstring operator+(const Wstring &lhs, const Wstring &rhs)
{
    char *new_string = nullptr;
    bool result = Wstring::Combine_Strings(lhs.Buffer, lhs.Get_Length(), rhs.Buffer, rhs.Get_Length(), new_string);
    TSPP_ASSERT(result);

    return Wstring(new_string);
}


inline std::ostream &operator<<(std::ostream &stream, const Wstring &that)
{
    return stream << that.Peek_Buffer();
}
