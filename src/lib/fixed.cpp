/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A simple fixed point class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "fixed.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>


const fixed fixed::_1_2(1, 2); // 1/2
const fixed fixed::_1_3(1, 3); // 1/3
const fixed fixed::_1_4(1, 4); // 1/4
const fixed fixed::_3_4(3, 4); // 3/4
const fixed fixed::_2_3(2, 3); // 2/3


fixed::fixed(int numerator, int denominator)
{
    if (denominator == 0) {
        Data.Raw = 0U;
    } else {
        Data.Raw = (unsigned int)(((unsigned __int64)numerator * PRECISION) / denominator);
    }
}


fixed::fixed(const char* ascii)
{
    if (ascii == nullptr) {
        Data.Raw = 0U;
        return;
    }

    char const* wholepart = ascii;

    while (isspace(*ascii)) {
        ascii++;
    }

    char const* tptr = ascii;
    while (isdigit(*tptr)) {
        tptr++;
    }

    if (*tptr == '%') {
        Data.Raw = (unsigned short)(((unsigned __int64)std::atoi(ascii) * PRECISION) / 100ULL);
    } else {

        Data.Composite.Whole = Data.Composite.Fraction = 0U;
        if (wholepart && *wholepart != '.') {
            Data.Composite.Whole = (unsigned char)std::atoi(wholepart);
        }

        const char* fracpart = std::strchr(ascii, '.');
        if (fracpart) fracpart++;
        if (fracpart) {
            unsigned short frac = (unsigned short)std::atoi(fracpart);

            int len = 0;
            unsigned int base = 1;
            char const* fptr = fracpart;
            while (isdigit(*fptr)) {
                fptr++;
                len++;
                base *= 10U;
            }

            Data.Composite.Fraction = (unsigned char)(((unsigned __int64)frac * PRECISION) / base);
        }
    }
}


int fixed::To_ASCII(char* buffer, int maxlen) const
{
    if (buffer == nullptr) return 0;

    unsigned int whole = Data.Composite.Whole;
    unsigned int frac = ((unsigned int)Data.Composite.Fraction * 1000U) / PRECISION;
    char tbuffer[32];

    if (frac == 0) {
        std::sprintf(tbuffer, "%u", whole);
    } else {
        std::sprintf(tbuffer, "%u.%02u", whole, frac);

        char* ptr = &tbuffer[std::strlen(tbuffer) - 1];
        while (*ptr == '0') {
            *ptr = '\0';
            ptr--;
        }
    }

    if (maxlen == -1) {
        maxlen = std::strlen(tbuffer) + 1;
    }

    std::strncpy(buffer, tbuffer, maxlen);

    int len = std::strlen(tbuffer);
    if (len < maxlen - 1) return (len);
    return (maxlen - 1);
}


const char* fixed::As_ASCII() const
{
    static char buffer[32];

    To_ASCII(buffer, sizeof(buffer));
    return buffer;
}
