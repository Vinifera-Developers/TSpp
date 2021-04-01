/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HSV.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         HSV color container class.
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


class RGBClass;


class HSVClass
{
    public:
        HSVClass();
        HSVClass(const HSVStruct &that);
        HSVClass(const HSVClass &that);
        HSVClass(unsigned char hue, unsigned char saturation, unsigned char value);

        operator RGBClass () const;

        bool operator==(const HSVClass &that) const { return Hue == that.Hue && Saturation == that.Saturation && Value == that.Value; }
        bool operator!=(const HSVClass &that) const { return Hue != that.Hue && Saturation != that.Saturation && Value != that.Value; }
        HSVClass &operator=(const HSVClass &that);

        void Adjust(int ratio, const HSVClass & hsv);
        int Difference(const HSVClass & hsv) const;

        enum {
            MAX_VALUE = 255
        };

    public:
        unsigned char Hue;
        unsigned char Saturation;
        unsigned char Value;
};


inline HSVClass &HSVClass::operator=(const HSVClass &that)
{
    if (this != &that) {
        Hue = that.Hue;
        Saturation = that.Saturation;
        Value = that.Value;
    }
    return *this;
}
