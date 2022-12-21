/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *   @project       TS++
 *
 *   @file          WSTRING.CPP
 *
 *   @author        Neijwiert
 *
 *   @contributors  CCHyper
 *
 *   @brief         A base implementation for dealing with strings without
 *                  directly interacting with c-style character arrays.
 *
 *   @license       TS++ is free software: you can redistribute it and/or
 *                  modify it under the terms of the GNU General Public License
 *                  as published by the Free Software Foundation, either version
 *                  3 of the License, or (at your option) any later version.
 *
 *                  TS++ is distributed in the hope that it will be
 *                  useful, but WITHOUT ANY WARRANTY; without even the implied
 *                  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                  PURPOSE. See the GNU General Public License for more details.
 *
 *                  You should have received a copy of the GNU General Public
 *                  License along with this program.
 *                  If not, see <http://www.gnu.org/licenses/>.
 *
 ***************************************************************************** */
#include "wstring.h"
#include <cctype>


static const char SpaceChar = ' ';
static const char TabChar = '\t';
static const char NewLineChar = '\n';


const char Wstring::NullChar = '\0';
const char *Wstring::EmptyString = &Wstring::NullChar;


Wstring::Wstring() :
    Buffer(nullptr)
{
}


Wstring::Wstring(char c) :
   Wstring()
{
    bool result = Set(c);
    TSPP_ASSERT(result);
}


Wstring::Wstring(const char *string) :
    Wstring()
{
    bool result = Set(string);
    TSPP_ASSERT(result);
}


Wstring::Wstring(const Wstring &that) :
    Wstring()
{
    bool result = Set(that);
    TSPP_ASSERT(result);
}


Wstring::Wstring(Wstring &&that) noexcept :
    Buffer(that.Buffer)
{
    that.Buffer = nullptr;
}


Wstring::~Wstring()
{
    Release_Buffer();
}


Wstring &Wstring::operator=(const Wstring &that)
{
    bool result = Set(that);
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator=(Wstring &&that) noexcept
{
    bool result = Set(std::move(that));
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator=(char c)
{
    bool result = Set(c);
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator=(const char *string)
{
    bool result = Set(string);
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator+=(char c)
{
    bool result = Concat(c);
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator+=(const char *string)
{
    bool result = Concat(string);
    TSPP_ASSERT(result);

    return *this;
}


Wstring &Wstring::operator+=(const Wstring &that)
{
    bool result = Concat(that);
    TSPP_ASSERT(result);

    return *this;
}


void Wstring::Release_Buffer()
{
    delete[] Buffer;
    Buffer = nullptr;
}


char *Wstring::Peek_Buffer()
{
    if (Buffer == nullptr) {
        return const_cast<char *>(EmptyString);
    }
    return Buffer;
}


const char *Wstring::Peek_Buffer() const
{
    if (Buffer == nullptr) {
        return EmptyString;
    }
    return Buffer;
}


void Wstring::Get_Buffer(char *string, int length) const
{
    TSPP_ASSERT(string != nullptr);
    TSPP_ASSERT(length >= 0);

    int buffer_length = Get_Length();
    int copy_count = std::min(buffer_length, length);

    if (buffer_length > 0) {
        std::memcpy(string, Buffer, copy_count * sizeof(char));
    }

    std::memset(string + copy_count, static_cast<int>(SpaceChar), length - copy_count - 1);

    string[length] = NullChar;
}


int Wstring::Get_Length() const
{
    return (Is_Empty() ? 0 : std::strlen(Buffer));
}


bool Wstring::Is_Empty() const
{
    return (Buffer == nullptr || Buffer[0] == NullChar);
}


bool Wstring::Is_Not_Empty() const
{
    return !Is_Empty();
}


bool Wstring::Resize(int new_length)
{
    TSPP_ASSERT(new_length >= 0);

    if (new_length == 0) {
        Release_Buffer();
        return true;
    }

    int old_length = Get_Length();
    if (old_length >= new_length) {
        Buffer[new_length] = NullChar;
        return true;
    }

    char *new_buffer = new char [new_length + 1];

    if (new_buffer == nullptr) {
        return false;
    }
    
    if (Is_Not_Empty()) {
        std::memcpy(new_buffer, Buffer, old_length * sizeof(char));
    }
    
    std::memset(new_buffer, static_cast<int>(NullChar), (new_length - old_length + 1) * sizeof(char));
    
    Release_Buffer();
    Buffer = new_buffer;
    
    return true;
}


void Wstring::Reserve(int length)
{
    TSPP_ASSERT(length >= 0);

    Release_Buffer();

    if (length >= 0) {
        Buffer = new char [length];
        TSPP_ASSERT(Buffer != nullptr);
        std::memset(Buffer, static_cast<int>(NullChar), length * sizeof(char));
    }
}


void Wstring::To_Lower()
{
    if (Is_Empty()) {
        return;
    }

    const int length = Get_Length();
    for (int i = 0; i < length; ++i) {
        Buffer[i] = static_cast<char>(std::tolower((Buffer[i])));
    }
}


Wstring Wstring::As_Lower() const
{
    Wstring tmp(*this);
    tmp.To_Lower();
    return tmp;
}


void Wstring::To_Upper()
{
    if (Is_Empty()) {
        return;
    }

    const int length = Get_Length();
    for (int i = 0; i < length; ++i) {
        Buffer[i] = static_cast<char>(std::toupper((Buffer[i])));
    }
}


Wstring Wstring::As_Upper() const
{
    Wstring tmp(*this);
    tmp.To_Upper();
    return tmp;
}


int Wstring::Compare(const char *string) const
{
    if ((Buffer == nullptr && string == nullptr) ||
        (Buffer == string)) {
        return 0;
    }

    if (Buffer == nullptr && string != nullptr) {
        if (string[0] == NullChar) {
            return 0;
        } else {
            return -1;
        }
    }

    if (Buffer != nullptr && string == nullptr) {
        if (Buffer[0] == NullChar) {
            return 0;
        } else {
            return 1;
        }
    }

    TSPP_ASSERT(Buffer != nullptr);
    TSPP_ASSERT(string != nullptr);

    return std::strcmp(Buffer, string);
}


int Wstring::Compare(const Wstring &that) const
{
    return Compare(that.Buffer);
}


int Wstring::Compare_No_Case(const char *string) const
{
    if ((Buffer == nullptr && string == nullptr) ||
        (Buffer == string)) {
        return 0;
    }

    if (Buffer == nullptr && string != nullptr) {
        if (string[0] == NullChar) {
            return 0;
        } else {
            return -1;
        }
    }

    if (Buffer != nullptr && string == nullptr) {
        if (Buffer[0] == NullChar) {
            return 0;
        } else {
            return 1;
        }
    }

    TSPP_ASSERT(Buffer != nullptr);
    TSPP_ASSERT(string != nullptr);

    return stricmp(Buffer, string);
}


int Wstring::Compare_No_Case(const Wstring &that) const
{
    return Compare_No_Case(that.Buffer);
}


bool Wstring::Contains(const char *delimiters) const
{
    if (Buffer == nullptr || delimiters == nullptr || delimiters[0] == NullChar) {
        return false;
    }
    return (std::strcspn(Buffer, delimiters) < std::strlen(Buffer));
}


bool Wstring::Contains(const Wstring &delimiters) const
{
    return Contains(delimiters.Buffer);
}


bool Wstring::Contains_String(const char *string) const
{
    if (Buffer == nullptr || string == nullptr || string[0] == NullChar) {
        return false;
    }
    return (std::strstr(Buffer, string) != nullptr);
}


bool Wstring::Contains_String(const Wstring &that) const
{
    return Contains(that.Buffer);
}


bool Wstring::Set(char c)
{
    return Internal_Set(1, &c);
}


bool Wstring::Set(const char *string)
{
    return Internal_Set(string == nullptr ? 0 : std::strlen(string), string);
}


bool Wstring::Set(const Wstring &that)
{
    bool result;
    if (this != &that) {
        result = Set(that.Buffer);
    } else {
        result = true;
    }
    return result;
}


bool Wstring::Set(Wstring &&that) noexcept
{
    if (this != &that) {
        Release_Buffer();
        std::swap(Buffer, that.Buffer);
    }
    return true;
}


bool Wstring::Set(int length, const char *string)
{
    return Internal_Set(std::min<unsigned int>(string == nullptr ? 0 : std::strlen(string), length), string);
}


bool Wstring::Set(int length, const Wstring &that)
{
    return Set(length, that.Buffer);
}


const char Wstring::Get_Char(int index) const
{
    TSPP_ASSERT(index >= 0);
    TSPP_ASSERT(index < Get_Length());

    if (index < Get_Length()) {
        return Buffer[index];
    }
    return NullChar;
}


char Wstring::Get_Char(int index)
{
    TSPP_ASSERT(index >= 0);
    TSPP_ASSERT(index < Get_Length());

    if (index < Get_Length()) {
        return Buffer[index];
    }

    return Buffer[index];
}


bool Wstring::Set_Char(char c, int index)
{
    TSPP_ASSERT(index >= 0);
    TSPP_ASSERT(index < Get_Length());

    Buffer[index] = c;
    return true;
}


bool Wstring::Concat(const char *string)
{
    return Internal_Concat(string == nullptr ? 0 : std::strlen(string), string);
}


bool Wstring::Concat(int length, const char *string)
{
    return Internal_Concat(std::min<unsigned int>(string == nullptr ? 0 : std::strlen(string), length), string);
}


bool Wstring::Concat(const Wstring &that)
{
    return Concat(that.Buffer);
}


bool Wstring::Concat(int length, const Wstring &that)
{
    return Concat(length, that.Buffer);
}


bool Wstring::Concat(char  c)
{
    return Internal_Concat(1, &c);
}


bool Wstring::Remove_Character(char c)
{
    TSPP_ASSERT(c != NullChar);

    int length = Get_Length();
    if (length <= 0) {
        return false;
    }

    bool result = false;
    char *bufferptr = Buffer;
    for (char *pch = std::strchr(Buffer, c); pch != nullptr; pch = std::strchr(Buffer, c)) {
        result = true;
        std::memmove(pch, pch + 1, (Buffer - pch + length--) * sizeof(char));
    }

    return result;
}


void Wstring::Remove_Whitespace()
{
    Remove_Character(SpaceChar);
    Remove_Character(TabChar);
}


int Wstring::Split(int start_index, const char *delimiters, Wstring &split_string) const
{
    TSPP_ASSERT(start_index >= 0);
    TSPP_ASSERT(delimiters != nullptr);
    TSPP_ASSERT(this != &split_string);

    int length = Get_Length();

    while (start_index < length && std::strchr(delimiters, Buffer[start_index]) != nullptr) {
        ++start_index;
    }

    if (start_index >= length) {
        return -1;
    }

    int split_start_index = start_index;

    while (start_index < length && std::strchr(delimiters, Buffer[start_index]) == nullptr) {
        ++start_index;
    }

    int first_delimiter_index_after_split = start_index;
    int split_string_length = first_delimiter_index_after_split - split_start_index;
    if (!split_string.Set(split_string_length, Buffer + split_start_index)) {
        return -1;
    }

    return first_delimiter_index_after_split;
}


int Wstring::Split(int start_index, const Wstring &delimiters, Wstring &split_string) const
{
    return Split(start_index, delimiters.Peek_Buffer(), split_string);
}


int Wstring::Next_Line(int start_index, Wstring &line) const
{
    TSPP_ASSERT(start_index >= 0);
    TSPP_ASSERT(this != &line);

    int length = Get_Length();

    while (start_index < length && std::strchr(&NewLineChar, Buffer[start_index]) != nullptr) {
        ++start_index;
    }

    if (start_index >= length) {
        return -1;
    }

    if (start_index + sizeof(char) <= length) {
        if (Buffer[start_index] == NewLineChar) {
            start_index += sizeof(char);
        }
    }
    
    if (!line.Set(Buffer + start_index)) {
        return -1;
    }

    return start_index + 1;
}


bool Wstring::Trim_To_Char(char c)
{
    if (Is_Empty()) {
        return false;
    }

    char *pch = std::strchr(Buffer, c);
    if (pch == nullptr) {
        return false;
    }

    pch[0] = NullChar;

    return true;
}


bool Wstring::Trim_Range(int start_index, int length)
{
    int old_length = Get_Length();

    if (old_length <= 0) {
        return false;
    }

    if (start_index + length > old_length) {
        start_index = old_length - length;
    }

    if (start_index < 0) {
        length += start_index;
        start_index = 0;
    }

    if (length <= 0) {
        return false;
    }

    TSPP_ASSERT(start_index >= 0 && start_index <= old_length);
    TSPP_ASSERT(length >= 0 && start_index + length <= old_length);

    int trailing_string_length = old_length - length - start_index + 1;
    std::memmove(Buffer + start_index, Buffer + start_index + length, trailing_string_length * sizeof(char));

    return true;
}


void Wstring::Trim_To_First_Difference(const char *delimiters)
{
    TSPP_ASSERT(delimiters != nullptr);

    if (delimiters[0] == NullChar) {
        return;
    }

    int index = 0;
    int length = Get_Length();
    while (index < length && std::strchr(delimiters, Buffer[index]) != nullptr) {
        ++index;
    }

    if (index > 0) {
        bool result = Trim_Range(0, index);
        TSPP_ASSERT(result);
    }
}


void Wstring::Trim_To_First_Difference(const Wstring &delimiters)
{
    return Trim_To_First_Difference(delimiters.Peek_Buffer());
}


void Wstring::Trim_After_First_Difference(const char *delimiters)
{
    TSPP_ASSERT(delimiters != nullptr);

    int length = Get_Length();

    if (length <= 0 || delimiters[0] == NullChar) {
        return;
    }

    int index = 0;
    while (index < length && std::strchr(delimiters, Buffer[index]) != nullptr) {
        ++index;
    }

    Buffer[index] = NullChar;
}


void Wstring::Trim_After_First_Difference(const Wstring &delimiters)
{
    Trim_After_First_Difference(delimiters.Peek_Buffer());
}


int Wstring::As_Integer() const
{
    if (Is_Empty()) {
        return 0;
    }
    return std::atoi(Buffer);
}


bool Wstring::Insert(char c, int index)
{
    return Internal_Insert(&c, index, 1);
}


bool Wstring::Insert(const char *string, int index)
{
    return Internal_Insert(string, index, string == nullptr ? 0 : std::strlen(string));
}


bool Wstring::Insert(const Wstring &that, int index)
{
    return Insert(that.Buffer, index);
}


bool Wstring::Replace(const char *str_to_replace, const char *replacement_str)
{
    TSPP_ASSERT(str_to_replace != nullptr);
    
    if (str_to_replace[0] == NullChar) {
        return true;
    }

    Wstring tmp;

    char *original_string_remainder = Peek_Buffer();
    int str_to_replace_length = std::strlen(str_to_replace);

    while (original_string_remainder != nullptr && original_string_remainder[0] != NullChar) {

        char *pointer_to_str_to_replace = std::strstr(original_string_remainder, str_to_replace);
        
        if (pointer_to_str_to_replace == nullptr) {

            if (tmp.Is_Empty()) {
                return true;
            }

            if (!tmp.Concat(original_string_remainder)) {
                return false;
            }

            break;
        }
        
        if (!tmp.Concat(pointer_to_str_to_replace - original_string_remainder, original_string_remainder)) {
            return false;
        }

        if (!tmp.Concat(replacement_str)) {
            return false;
        }

        original_string_remainder = pointer_to_str_to_replace + str_to_replace_length;
    }

    return Set(std::move(tmp));
}


bool Wstring::Replace(const Wstring &str_to_replace, const Wstring &replacement_str)
{
    return Replace(str_to_replace.Peek_Buffer(), replacement_str.Buffer);
}


bool Wstring::Internal_Set(int length, const char *string)
{
    TSPP_ASSERT(length >= 0);
    TSPP_ASSERT(Buffer == nullptr || Buffer != string);

    if (length == 0 || string == nullptr || string[0] == NullChar) {
        Release_Buffer();
        return true;
    }

    char *new_buffer = new char [length + 1];

    if (new_buffer == nullptr) {
        return false;
    }

    std::memcpy(new_buffer, string, length * sizeof(char));
    new_buffer[length] = NullChar;

    Release_Buffer();
    Buffer = new_buffer;

    return true;
}


bool Wstring::Internal_Insert(const char *string, int index, int length)
{
    TSPP_ASSERT(string != nullptr);
    TSPP_ASSERT(index >= 0);
    TSPP_ASSERT(length >= 0);

    if (length == 0 || string == nullptr || string[0] == NullChar) {
        return true;
    }

    int old_length = Get_Length();

    if (old_length <= 0) {
        return Internal_Set(length, string);
    }

    index = std::min(old_length, index);

    int new_length = old_length + length;
    char *new_buffer = new char [new_length + 1];

    if (new_buffer == nullptr) {
        return false;
    }

    std::memcpy(new_buffer, Buffer, old_length * sizeof(char));

    std::memmove(new_buffer + length + index, new_buffer + index, (old_length - index) * sizeof(char));

    std::memcpy(new_buffer + index, string, length * sizeof(char));

    new_buffer[new_length] = NullChar;

    Release_Buffer();
    Buffer = new_buffer;

    return true;
}


bool Wstring::Internal_Concat(int length, const char *string)
{
    TSPP_ASSERT(length >= 0);

    if (length == 0 || string == nullptr || string[0] == NullChar) {
        return true;
    }

    char *new_string = nullptr;
    if (!Combine_Strings(Buffer, Get_Length(), string, length, new_string))
    {
        return false;
    }

    Release_Buffer();
    Buffer = new_string;

    return true;
}


bool Wstring::Combine_Strings(const char *lhs, int lhs_length, const char *rhs, int rhs_length, char *&result)
{
    TSPP_ASSERT(lhs_length >= 0);
    TSPP_ASSERT(rhs_length >= 0);

    if (lhs != nullptr && lhs_length > 0 && lhs[0] == NullChar) {
        lhs_length = 0;
    }

    if (rhs != nullptr && rhs_length > 0 && rhs[0] == NullChar) {
        rhs_length = 0;
    }

    int new_length = lhs_length + rhs_length;
    if (new_length == 0) {
        return true;
    }

    char *new_string = new char [new_length + 1];
    if (new_string == nullptr) {
        return false;
    }

    char *new_string_ptr = new_string;
    if (lhs != nullptr && lhs_length > 0) {
        std::memcpy(new_string_ptr, lhs, lhs_length * sizeof(char));
        new_string_ptr += lhs_length;
    }

    if (rhs != nullptr && rhs_length > 0) {
        std::memcpy(new_string_ptr, rhs, rhs_length * sizeof(char));
        new_string_ptr += rhs_length;
    }

    new_string_ptr[0] = NullChar;
    result = new_string;

    return true;
}


Wstring Wstring::Number_To_String(int value)
{
    char buffer[16];

    std::snprintf(buffer, sizeof(buffer), "%d", value);

    return Wstring(buffer);
}


Wstring Wstring::Number_To_String(int value, int leading_zeros)
{
    TSPP_ASSERT(leading_zeros < 16);

    char buffer[16];

    std::snprintf(buffer, sizeof(buffer), "%%0%dd", leading_zeros);
    std::snprintf(buffer, sizeof(buffer), buffer, value);

    return Wstring(buffer);
}
