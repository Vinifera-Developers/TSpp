/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  HSV color container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


class RGBClass;


class HSVClass
{
public:
    HSVClass();
    HSVClass(const HSVStruct& that);
    HSVClass(const HSVClass& that);
    HSVClass(unsigned char hue, unsigned char saturation, unsigned char value);

    operator RGBClass() const;

    bool operator==(const HSVClass& that) const { return Hue == that.Hue && Saturation == that.Saturation && Value == that.Value; }
    bool operator!=(const HSVClass& that) const { return Hue != that.Hue && Saturation != that.Saturation && Value != that.Value; }
    HSVClass& operator=(const HSVClass& that);

    void Adjust(int ratio, const HSVClass& hsv);
    int Difference(const HSVClass& hsv) const;

    enum {
        MAX_VALUE = 255
    };

public:
    unsigned char Hue;
    unsigned char Saturation;
    unsigned char Value;
};


inline HSVClass& HSVClass::operator=(const HSVClass& that)
{
    if (this != &that) {
        Hue = that.Hue;
        Saturation = that.Saturation;
        Value = that.Value;
    }
    return *this;
}
