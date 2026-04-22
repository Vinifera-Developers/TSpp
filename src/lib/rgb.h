/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  RGB color container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


class HSVClass;


class RGBClass
{
public:
    RGBClass();
    RGBClass(const RGBStruct& that);
    RGBClass(const RGBClass& that);
    RGBClass(unsigned char red, unsigned char green, unsigned char blue);

    operator HSVClass() const;
    operator RGBStruct() const { return RGBStruct {Red, Green, Blue}; }

    bool operator==(const RGBClass& that) const { return Red == that.Red && Green == that.Green && Blue == that.Blue; }
    bool operator!=(const RGBClass& that) const { return Red != that.Red && Green != that.Green && Blue != that.Blue; }
    RGBClass& operator=(const RGBClass& that);

    void Adjust(int adjust, const RGBClass& that);
    int Difference(const RGBClass& that) const;
    int Get_Red() const { return Red; }
    int Get_Green() const { return Green; }
    int Get_Blue() const { return Blue; }
    void Set_Red(unsigned char value) { Red = value; }
    void Set_Green(unsigned char value) { Green = value; }
    void Set_Blue(unsigned char value) { Blue = value; }

    RGBClass Adjust_Brightness(RGBClass& color, float adjust);
    RGBClass Lerp(RGBClass& left, RGBClass& right, float adjust);
    static RGBClass Interpolate(RGBClass& from, RGBClass& towards, float adjust);

public:
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};


inline RGBClass& RGBClass::operator=(const RGBClass& that)
{
    if (this != &that) {
        Red = that.Red;
        Green = that.Green;
        Blue = that.Blue;
    }
    return *this;
}
