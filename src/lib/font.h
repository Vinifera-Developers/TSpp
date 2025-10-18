/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWFONT.H
 *
 *  @author        Byon_g (see notes below)
 *
 *  @contributors  tomsons26, ZivDero
 *
 *  @brief         Westwood font file handler.
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
 *  @note          This file contains modified code for C&C Generals released
 *                 by Electronic Arts under the GPL3 license. Source:
 *                 https://github.com/electronicarts/CnC_Generals_Zero_Hour
 *
 ******************************************************************************/
#pragma once

#include "rect.h"

class Surface;
class ConvertClass;

/*
**  A font object represent the data that comprises the individual characters as well
**  as drawing text in the font to a surface. This is an abstract base class that is to be
**  derived into a concrete version.
*/
class FontClass
{
public:
    virtual ~FontClass() {}

    virtual int Char_Pixel_Width(char chr) const = 0;
    virtual int String_Pixel_Width(char const* string) const = 0;
    virtual void String_Pixel_Bounds(const char* string, Rect& bounds) const = 0;
    virtual int Get_Width() const = 0;
    virtual int Get_Height() const = 0;
    virtual Point2D Print(char const* string, Surface& surface, Rect const& cliprect, Point2D const& point, ConvertClass const& converter, unsigned char const* remap = nullptr) const = 0;

    virtual int Set_XSpacing(int x) = 0;
    virtual int Set_YSpacing(int y) = 0;
};
