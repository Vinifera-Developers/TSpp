/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RGB.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         RGB color container class.
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

    RGBClass Adjust_Brightness(RGBClass& color, float adjust);
    RGBClass Lerp(RGBClass& left, RGBClass& right, float adjust);
    static RGBClass Interpolate(RGBClass& from, RGBClass& towards, float adjust);

    enum {
        MAX_VALUE = 255
    };

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
