/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic 256 color palette container.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "rgb.h"
#include "tspp_assert.h"


class PaletteClass
{
public:
    enum {
        COLOR_COUNT = 256 // Number of color indices on the palette.
    };

public:
    PaletteClass();
    PaletteClass(const RGBClass& rgb);
    PaletteClass(const PaletteClass& that);
    PaletteClass(const char* filename);
    ~PaletteClass();

    operator const unsigned char*() const { return (const unsigned char*)&Palette[0]; }
    operator unsigned char*() { return (unsigned char*)&Palette[0]; }

    RGBClass& operator[](int index)
    {
        TSPP_ASSERT(index < COLOR_COUNT);
        return Palette[index % COLOR_COUNT];
    }
    const RGBClass& operator[](int index) const
    {
        TSPP_ASSERT(index < COLOR_COUNT);
        return Palette[index % COLOR_COUNT];
    }

    bool operator==(const PaletteClass& that) const { return std::memcmp(Palette, that.Palette, sizeof(Palette)) == 0; }
    bool operator!=(const PaletteClass& that) const { return std::memcmp(Palette, that.Palette, sizeof(Palette)) != 0; }
    PaletteClass& operator=(const PaletteClass& that);

    void Adjust(int ratio);
    void Adjust(int ratio, const PaletteClass& palette);

    void Partial_Adjust(int ratio, char* palette);
    void Partial_Adjust(int ratio, const PaletteClass& palette, char* lut);

    int Closest_Color(RGBClass& rgb) const;

private:
    RGBClass Palette[COLOR_COUNT];
};


inline PaletteClass& PaletteClass::operator=(const PaletteClass& that)
{
    if (this != &that) {
        std::memcpy(Palette, that.Palette, sizeof(Palette));
    }
    return *this;
}
