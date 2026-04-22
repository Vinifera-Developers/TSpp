/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A simple fixed point class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


__declspec(align(4)) class fixed
{
    static constexpr unsigned int PRECISION = 1 << 8;
    typedef unsigned char data_type;

public:
    fixed() {}
    fixed(const fixed& rvalue) { Data.Raw = rvalue.Data.Raw; }
    fixed(int numerator, int denominator);
    fixed(int value)
    {
        Data.Composite.Fraction = 0U;
        Data.Composite.Whole = (unsigned char)value;
    }
    fixed(unsigned int value)
    {
        Data.Composite.Fraction = 0U;
        Data.Composite.Whole = (unsigned char)value;
    }
    fixed(float value)
    {
        value += 1.0f / (PRECISION << 1);
        Data.Composite.Fraction = (unsigned char)((value - (unsigned char)value) * PRECISION);
        Data.Composite.Whole = (unsigned char)value;
    }
    fixed(const char* ascii);

    operator unsigned() const { return (unsigned)(((unsigned __int64)Data.Raw + (PRECISION >> 1)) / PRECISION); }

    fixed& operator*=(const fixed& rvalue)
    {
        Data.Raw = (unsigned int)(((unsigned __int64)Data.Raw * rvalue.Data.Raw) / PRECISION);
        return (*this);
    }
    fixed& operator*=(int rvalue)
    {
        Data.Raw *= (unsigned int)rvalue;
        return (*this);
    }
    fixed& operator/=(const fixed& rvalue)
    {
        if (rvalue.Data.Raw != 0U && rvalue.Data.Raw != PRECISION) Data.Raw = (unsigned int)((((unsigned __int64)Data.Raw * PRECISION) + (PRECISION >> 1)) / rvalue.Data.Raw);
        return (*this);
    }
    fixed& operator/=(int rvalue)
    {
        if (rvalue) Data.Raw /= (unsigned int)rvalue;
        return (*this);
    }
    fixed& operator+=(const fixed& rvalue)
    {
        Data.Raw += rvalue.Data.Raw;
        return (*this);
    }
    fixed& operator-=(const fixed& rvalue)
    {
        Data.Raw -= rvalue.Data.Raw;
        return (*this);
    }

    const fixed operator*(const fixed& rvalue) const { return fixed(*this) *= rvalue; }
    const int operator*(int rvalue) const { return fixed(*this) *= rvalue; }
    const fixed operator/(const fixed& rvalue) const { return fixed(*this) /= rvalue; }
    const int operator/(int rvalue) const { return fixed(*this) /= rvalue; }
    const fixed operator+(const fixed& rvalue) const { return fixed(*this) += rvalue; }
    const int operator+(int rvalue) const { return fixed(*this) += rvalue; }
    const fixed operator-(const fixed& rvalue) const { return fixed(*this) -= rvalue; }
    const int operator-(int rvalue) const { return fixed(*this) -= rvalue; }

    fixed& operator>>=(unsigned rvalue)
    {
        Data.Raw >>= rvalue;
        return (*this);
    }
    fixed& operator<<=(unsigned rvalue)
    {
        Data.Raw <<= rvalue;
        return (*this);
    }
    const fixed operator>>(unsigned rvalue) const { return fixed(*this) >>= rvalue; }
    const fixed operator<<(unsigned rvalue) const { return fixed(*this) <<= rvalue; }

    bool operator==(const fixed& rvalue) const { return Data.Raw == rvalue.Data.Raw; }
    bool operator!=(const fixed& rvalue) const { return Data.Raw != rvalue.Data.Raw; }
    bool operator<(const fixed& rvalue) const { return Data.Raw < rvalue.Data.Raw; }
    bool operator>(const fixed& rvalue) const { return Data.Raw > rvalue.Data.Raw; }
    bool operator<=(const fixed& rvalue) const { return Data.Raw <= rvalue.Data.Raw; }
    bool operator>=(const fixed& rvalue) const { return Data.Raw >= rvalue.Data.Raw; }
    bool operator!() const { return Data.Raw == 0U; }

    bool operator<(int rvalue) const { return Data.Raw < ((unsigned int)rvalue * PRECISION); }
    bool operator>(int rvalue) const { return Data.Raw > ((unsigned int)rvalue * PRECISION); }
    bool operator<=(int rvalue) const { return Data.Raw <= ((unsigned int)rvalue * PRECISION); }
    bool operator>=(int rvalue) const { return Data.Raw >= ((unsigned int)rvalue * PRECISION); }
    bool operator==(int rvalue) const { return Data.Raw == ((unsigned int)rvalue * PRECISION); }
    bool operator!=(int rvalue) const { return Data.Raw != ((unsigned int)rvalue * PRECISION); }

    friend const int operator*(int lvalue, const fixed& rvalue) { return fixed(lvalue) * rvalue; }
    friend const int operator/(int lvalue, const fixed& rvalue) { return fixed(lvalue) / rvalue; }
    friend const int operator+(int lvalue, const fixed& rvalue) { return fixed(lvalue) + rvalue; }
    friend const int operator-(int lvalue, const fixed& rvalue) { return fixed(lvalue) - rvalue; }
    friend bool operator<(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) < rvalue; }
    friend bool operator>(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) > rvalue; }
    friend bool operator<=(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) <= rvalue; }
    friend bool operator>=(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) >= rvalue; }
    friend bool operator==(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) == rvalue; }
    friend bool operator!=(unsigned lvalue, const fixed& rvalue) { return fixed(lvalue) != rvalue; }
    friend int operator*=(int& lvalue, const fixed& rvalue)
    {
        lvalue = lvalue * rvalue;
        return lvalue;
    }
    friend int operator/=(int& lvalue, const fixed& rvalue)
    {
        lvalue = lvalue / rvalue;
        return lvalue;
    }
    friend int operator+=(int& lvalue, const fixed& rvalue)
    {
        lvalue = lvalue + rvalue;
        return lvalue;
    }
    friend int operator-=(int& lvalue, const fixed& rvalue)
    {
        lvalue = lvalue - rvalue;
        return lvalue;
    }

    void Round_Up()
    {
        Data.Raw += (PRECISION - 1U);
        Data.Composite.Fraction = 0U;
    }
    void Round_Down() { Data.Composite.Fraction = 0U; }
    void Round()
    {
        if (Data.Composite.Fraction >= PRECISION >> 1) Round_Up();
        Round_Down();
    }
    void Saturate(unsigned capvalue)
    {
        if (Data.Raw > (capvalue * PRECISION)) Data.Raw = capvalue * PRECISION;
    }
    void Saturate(const fixed& capvalue)
    {
        if (*this > capvalue) *this = capvalue;
    }
    void Sub_Saturate(unsigned capvalue)
    {
        if (Data.Raw >= (capvalue * PRECISION)) Data.Raw = (capvalue * PRECISION) - 1U;
    }
    void Sub_Saturate(const fixed& capvalue)
    {
        if (*this >= capvalue) Data.Raw = capvalue.Data.Raw - 1U;
    }
    void Inverse() { *this = fixed(1) / *this; }

    friend const fixed Round_Up(const fixed& value)
    {
        fixed temp = value;
        temp.Round_Up();
        return temp;
    }
    friend const fixed Round_Down(const fixed& value)
    {
        fixed temp = value;
        temp.Round_Down();
        return temp;
    }
    friend const fixed Round(const fixed& value)
    {
        fixed temp = value;
        temp.Round();
        return temp;
    }
    friend const fixed Saturate(const fixed& value, unsigned capvalue)
    {
        fixed temp = value;
        temp.Saturate(capvalue);
        return temp;
    }
    friend const fixed Saturate(const fixed& value, const fixed& capvalue)
    {
        fixed temp = value;
        temp.Saturate(capvalue);
        return temp;
    }
    friend const fixed Sub_Saturate(const fixed& value, unsigned capvalue)
    {
        fixed temp = value;
        temp.Sub_Saturate(capvalue);
        return temp;
    }
    friend const fixed Sub_Saturate(const fixed& value, const fixed& capvalue)
    {
        fixed temp = value;
        temp.Sub_Saturate(capvalue);
        return temp;
    }
    friend const fixed Inverse(const fixed& value)
    {
        fixed temp = value;
        temp.Inverse();
        return temp;
    }

    unsigned short Get_Raw() const { return Data.Raw; }
    void Set_Raw(unsigned short raw) { Data.Raw = raw; }

    int To_ASCII(char* buffer, int maxlen = -1) const;
    char const* As_ASCII() const;

    static const fixed _1_2;
    static const fixed _1_3;
    static const fixed _1_4;
    static const fixed _3_4;
    static const fixed _2_3;

public:
#pragma pack(4) // Ensure union member is padded to 4 byte alignment.
    union {
        struct {
#ifdef SYSTEM_BIG_ENDIAN
            unsigned char Whole;
            unsigned char Fraction;
#else
            unsigned char Fraction;
            unsigned char Whole;
#endif
        } Composite;
        unsigned short Raw;
    } Data;
#pragma pack()
};
