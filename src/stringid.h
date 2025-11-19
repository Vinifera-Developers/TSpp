/*******************************************************************************
/*                 O P E N  S O U R C E  --  V I N I F E R A                  **
/*******************************************************************************
 *
 *  @project       Vinifera
 *
 *  @file          STRINGID.H
 *
 *  @authors       ZivDero
 *
 *  @brief         String container with a fixed buffer size.
 *
 *  @license       Vinifera is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 Vinifera is distributed in the hope that it will be
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
#include <algorithm>
#include <string>
#include "noinit.h"
#include "tspp_assert.h"

template<std::size_t N> class FixedString;

/**
 *  Modern implementation of the TStringID static string wrapper,
 *  used primarily for INI names of object types.
 *  Modeled after std::string. Has no cached length to maintain
 *  backwards compatibility.
 */
template<std::size_t N>
class TStringID
{
    static_assert(N > 0, "TStringID size must be > 0");

public:
    using value_type = char;
    using size_type = std::size_t;
    using iterator = char*;
    using const_iterator = const char*;

    /**
     *  Construction
     */
    constexpr TStringID() noexcept { Data[0] = '\0'; }
    constexpr TStringID(const NoInitClass& x) noexcept {}

    TStringID(const char* str) noexcept { assign(str); }
    TStringID& operator=(const char* str) noexcept { assign(str); return *this; }

    TStringID(std::string_view sv) noexcept { assign(sv); }
    TStringID& operator=(std::string_view sv) noexcept { assign(sv); return *this; }

    constexpr TStringID(const TStringID&) noexcept = default;
    constexpr TStringID& operator=(const TStringID&) noexcept = default;

    constexpr TStringID(TStringID&&) noexcept = default;
    constexpr TStringID& operator=(TStringID&&) noexcept = default;

    /**
     *  Conversions
     */
    constexpr operator std::string_view() const noexcept { return std::string_view(Data, size()); }
    explicit operator std::string() const { return std::string(Data, size()); }

    /**
     *  Capacity
     */
    static constexpr size_type capacity() noexcept { return N; }
    constexpr size_type size() const noexcept { return std::char_traits<char>::length(Data); }
    constexpr bool empty() const noexcept { return Data[0] == '\0'; }

    /**
     *  Access
     */
    constexpr const char* c_str() const noexcept { return Data; }
    constexpr const char* data() const noexcept { return Data; }
    constexpr char* data() noexcept { return Data; }

    constexpr char& operator[](size_type pos) noexcept { return Data[pos]; }
    constexpr const char& operator[](size_type pos) const noexcept { return Data[pos]; }

    constexpr char& at(size_type pos) noexcept
    {
        TSPP_ASSERT(pos < size());
        return Data[pos];
    }
    constexpr const char& at(size_type pos) const noexcept
    {
        TSPP_ASSERT(pos < size());
        return Data[pos];
    }

    constexpr char& front() noexcept { return Data[0]; }
    constexpr const char& front() const noexcept { return Data[0]; }

    constexpr char& back() noexcept { TSPP_ASSERT(!empty()); return Data[size() - 1]; }
    constexpr const char& back() const noexcept { TSPP_ASSERT(!empty()); return Data[size() - 1]; }

    /**
     *  Iterators
     */
    constexpr iterator begin() noexcept { return Data; }
    constexpr const_iterator begin() const noexcept { return Data; }
    constexpr const_iterator cbegin() const noexcept { return Data; }

    constexpr iterator end() noexcept { return Data + size(); }
    constexpr const_iterator end() const noexcept { return Data + size(); }
    constexpr const_iterator cend() const noexcept { return Data + size(); }

    /**
     *  Modification
     */
    constexpr void clear() noexcept { Data[0] = '\0'; }

    void assign(std::string_view sv) noexcept
    {
        const auto len = std::min(sv.size(), capacity());
        if (sv.data() != Data) {
            std::memcpy(Data, sv.data(), len);
            Data[len] = '\0';
        }
    }

    void assign(const char* str) noexcept { assign(std::string_view(str)); }

    void push_back(char c) noexcept
    {
        const auto len = size();
        if (len < capacity()) {
            Data[len] = c;
            Data[len + 1] = '\0';
        }
    }

    void pop_back() noexcept
    {
        const auto len = size();
        if (len > 0) {
            Data[len - 1] = '\0';
        }
    }

    TStringID& operator+=(std::string_view sv) noexcept
    {
        const auto len = size();
        const auto to_copy = std::min(sv.size(), capacity() - len);
        std::memcpy(Data + len, sv.data(), to_copy);
        Data[len + to_copy] = '\0';
        return *this;
    }

    TStringID& operator+=(char c) noexcept
    {
        push_back(c);
        return *this;
    }

    /**
     *  Comparison
     */
    constexpr int compare(std::string_view rhs) const noexcept { return std::string_view(*this).compare(rhs); }

    constexpr bool operator==(std::string_view rhs) const noexcept { return std::string_view(*this) == rhs; }
    constexpr bool operator!=(std::string_view rhs) const noexcept { return !(*this == rhs); }
    constexpr bool operator<(std::string_view rhs) const noexcept { return std::string_view(*this) < rhs; }
    constexpr bool operator>(std::string_view rhs) const noexcept { return rhs < *this; }
    constexpr bool operator<=(std::string_view rhs) const noexcept { return !(*this > rhs); }
    constexpr bool operator>=(std::string_view rhs) const noexcept { return !(*this < rhs); }

    /**
     *  Read-only helpers
     */
    constexpr bool starts_with(std::string_view prefix) const noexcept { return std::string_view(*this).starts_with(prefix); }
    constexpr bool ends_with(std::string_view suffix) const noexcept { return std::string_view(*this).ends_with(suffix); }
    constexpr bool contains(std::string_view needle) const noexcept { return std::string_view(*this).find(needle) != std::string_view::npos; }
    constexpr size_type find(std::string_view sv, size_type pos = 0) const noexcept { return std::string_view(*this).find(sv, pos); }
    constexpr size_type rfind(std::string_view sv, size_type pos = std::string_view::npos) const noexcept { return std::string_view(*this).rfind(sv, pos); }
    constexpr std::string_view substr(size_type pos, size_type count = std::string_view::npos) const noexcept { return std::string_view(*this).substr(pos, count); }

protected:
    char Data[N + 1]; // N visible chars + '\0'
};

/**
 *  Free operator+
 */
template<std::size_t N>
constexpr TStringID<N> operator+(TStringID<N> lhs, std::string_view rhs) noexcept
{
    lhs += rhs;
    return lhs;
}

/**
 *  An extension of TStringID that caches the string's length.
 *  Should be used in any new applications.
 */
template<std::size_t N>
class FixedString : public TStringID<N>
{
public:
    using Base = TStringID<N>;
    using size_type = typename Base::size_type;
    using value_type = typename Base::value_type;
    using Base::Data;

    constexpr FixedString() noexcept : Base(), Length(0) { }
    constexpr FixedString(const NoInitClass& x) noexcept : Base(x) {}
    
    FixedString(const char* str) noexcept { assign(str); }
    FixedString& operator=(const char* str) noexcept { assign(str); return *this; }

    FixedString(std::string_view sv) noexcept { assign(sv); }
    FixedString& operator=(std::string_view sv) noexcept { assign(sv); return *this; }

    constexpr FixedString(const FixedString&) noexcept = default;
    constexpr FixedString& operator=(const FixedString&) noexcept = default;

    constexpr FixedString(FixedString&&) noexcept = default;
    constexpr FixedString& operator=(FixedString&&) noexcept = default;

    /**
     *  Capacity
     */
    constexpr size_type size() const noexcept { return Length; }

    /**
     *  Modification overrides
     */
    constexpr void clear() noexcept
    {
        Data[0] = '\0';
        Length = 0;
    }

    void assign(std::string_view sv) noexcept
    {
        const auto len = std::min(sv.size(), Base::capacity());
        if (sv.data() != Data) {
            std::memcpy(Data, sv.data(), len);
            Data[len] = '\0';
            Length = len;
        }
    }

    void assign(const char* str) noexcept { assign(std::string_view(str)); }

    constexpr void push_back(char c) noexcept
    {
        if (Length < Base::capacity()) {
            Data[Length++] = c;
            Data[Length] = '\0';
        }
    }

    constexpr void pop_back() noexcept
    {
        if (Length > 0) {
            Data[--Length] = '\0';
        }
    }

    FixedString& operator+=(std::string_view sv) noexcept
    {
        const auto to_copy = std::min(sv.size(), Base::capacity() - Length);
        std::memcpy(Data + Length, sv.data(), to_copy);
        Length += to_copy;
        Data[Length] = '\0';
        return *this;
    }

    constexpr FixedString& operator+=(char c) noexcept
    {
        push_back(c);
        return *this;
    }

    /**
     *  Length maintenance helper (useful if Data is manipulated directly)
     */
    constexpr void Recalculate_Length() noexcept { Length = std::char_traits<char>::length(Data); }

private:
    size_type Length;
};
