/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PALETTE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic 256 color palette container.
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
