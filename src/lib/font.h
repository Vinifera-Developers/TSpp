/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Westwood font file handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
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
