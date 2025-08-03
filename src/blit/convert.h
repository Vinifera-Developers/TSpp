/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONVERT.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Palette drawer.
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

#include "surface.h"
#include "vector.h"


class PaletteClass;
class XSurface;
class Blitter;
class RLEBlitter;


class ConvertClass
{
public:
    ConvertClass();
    ConvertClass(PaletteClass* a1, PaletteClass* a2, XSurface* surface, int a4, bool a5 = false);
    ConvertClass(const NoInitClass& noinit);
    virtual ~ConvertClass();

    void Alloc_Blitters();
    void Dealloc_Blitters();

    Blitter* Select_Blitter(int flags);
    RLEBlitter* Select_RLE_Blitter(int flags);

    static void Recalc_Color_Remap_Tables(int a1, int a2, int a3, int a4);

    inline unsigned inline_01(unsigned index)
    {
        switch (BytesPerPixel) {
        default:
        case 1:
            return reinterpret_cast<uint8_t*>(field_178)[index];
        case 2:
            return reinterpret_cast<uint16_t*>(field_178)[index];
        };
    }

    inline unsigned inline_02(unsigned index)
    {
        switch (BytesPerPixel) {
        default:
        case 1:
            return reinterpret_cast<uint8_t*>(Palette)[index];
        case 2:
            return reinterpret_cast<uint16_t*>(Palette)[index];
        };
    }

    static ConvertClass* Create_Drawer(const char* pal_filename, PaletteClass* pal, XSurface* surface);
    static ConvertClass* Create_Drawer(const char* pal_filename);

protected:
    int BytesPerPixel;
    Blitter* BlitPlainXlatPtr;
    Blitter* BlitTransXlatPtr;
    Blitter* BlitTransDarkenPtr;
    Blitter* BlitTransZRemapXlatPtr;
    Blitter* BlitTransLucent75Ptr;
    Blitter* BlitTransLucent50Ptr;
    Blitter* BlitTransLucent25Ptr;
    Blitter* BlitPlainXlatZReadPtr;
    Blitter* BlitTransXlatZReadPtr;
    Blitter* BlitTransDarkenZReadPtr;
    Blitter* BlitTransZRemapXlatZReadPtr;
    Blitter* BlitTransLucent75ZReadPtr;
    Blitter* BlitTransLucent50ZReadPtr;
    Blitter* BlitTransLucent25ZReadPtr;
    Blitter* BlitTransLucent75ZReadWarpPtr;
    Blitter* BlitTransLucent50ZReadWarpPtr;
    Blitter* BlitTransLucent25ZReadWarpPtr;
    Blitter* BlitPlainXlatZReadWritePtr;
    Blitter* BlitTransXlatZReadWritePtr;
    Blitter* BlitTransDarkenZReadWritePtr;
    Blitter* BlitTransZRemapXlatZReadWritePtr;
    Blitter* BlitTransLucent75ZReadWritePtr;
    Blitter* BlitTransLucent50ZReadWritePtr;
    Blitter* BlitTransLucent25ZReadWritePtr;
    Blitter* BlitPlainXlatAlphaPtr;
    Blitter* BlitTransXlatAlphaPtr;
    Blitter* BlitTransZRemapXlatAlphaPtr;
    Blitter* BlitTransLucent75AlphaPtr;
    Blitter* BlitTransLucent50AlphaPtr;
    Blitter* BlitTransLucent25AlphaPtr;
    Blitter* BlitTransXlatWriteAlphaPtr;
    Blitter* BlitTransXlatMultWriteAlphaPtr;
    Blitter* BlitTranslucentWriteAlphaPtr;
    Blitter* BlitTranslucent50NonzeroAlphaPtr;
    Blitter* BlitTranslucent50ZeroAlphaPtr;
    Blitter* BlitTranslucent75NonzeroAlphaPtr;
    Blitter* BlitTranslucent75ZeroAlphaPtr;
    Blitter* BlitPlainXlatAlpha_2Ptr;
    Blitter* BlitTransXlatAlphaZReadPtr;
    Blitter* BlitTransZRemapXlatAlphaZReadPtr;
    Blitter* BlitTransLucent75AlphaZReadPtr;
    Blitter* BlitTransLucent50AlphaZReadPtr;
    Blitter* BlitTransLucent25AlphaZReadPtr;
    Blitter* BlitTransLucent75AlphaZReadWarpPtr;
    Blitter* BlitTransLucent50AlphaZReadWarpPtr;
    Blitter* BlitTransLucent25AlphaZReadWarpPtr;
    Blitter* BlitPlainXlatAlpha_3Ptr;
    Blitter* BlitTransXlatAlphaZReadWritePtr;
    Blitter* BlitTransZRemapXlatAlphaZReadWritePtr;
    Blitter* BlitTransLucent75AlphaZReadWritePtr;
    Blitter* BlitTransLucent50AlphaZReadWritePtr;
    Blitter* BlitTransLucent25AlphaZReadWritePtr;
    RLEBlitter* RLEBlitTransXlatPtr;
    RLEBlitter* RLEBlitTransDarkenPtr;
    RLEBlitter* RLEBlitTransZRemapXlatPtr;
    RLEBlitter* RLEBlitTransLucent75Ptr;
    RLEBlitter* RLEBlitTransLucent50Ptr;
    RLEBlitter* RLEBlitTransLucent25Ptr;
    RLEBlitter* RLEBlitTransXlatZReadPtr;
    RLEBlitter* RLEBlitTransZRemapXlatZReadPtr;
    RLEBlitter* RLEBlitTransDarkenZReadPtr;
    RLEBlitter* RLEBlitTransLucent75ZReadPtr;
    RLEBlitter* RLEBlitTransLucent50ZReadPtr;
    RLEBlitter* RLEBlitTransLucent25ZReadPtr;
    RLEBlitter* RLEBlitTransLucent75ZReadWarpPtr;
    RLEBlitter* RLEBlitTransLucent50ZReadWarpPtr;
    RLEBlitter* RLEBlitTransLucent25ZReadWarpPtr;
    RLEBlitter* RLEBlitTransXlatZReadWritePtr;
    RLEBlitter* RLEBlitTransZRemapXlatZReadWritePtr;
    RLEBlitter* RLEBlitTransDarkenZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent75ZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent50ZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent25ZReadWritePtr;
    RLEBlitter* RLEBlitTransXlatAlphaPtr;
    RLEBlitter* RLEBlitTransZRemapXlatAlphaPtr;
    RLEBlitter* RLEBlitTransLucent75AlphaPtr;
    RLEBlitter* RLEBlitTransLucent50AlphaPtr;
    RLEBlitter* RLEBlitTransLucent25AlphaPtr;
    RLEBlitter* RLEBlitTransXlatAlphaZReadPtr;
    RLEBlitter* RLEBlitTransZRemapXlatAlphaZReadPtr;
    RLEBlitter* RLEBlitTransLucent75AlphaZReadPtr;
    RLEBlitter* RLEBlitTransLucent50AlphaZReadPtr;
    RLEBlitter* RLEBlitTransLucent25AlphaZReadPtr;
    RLEBlitter* RLEBlitTransLucent75AlphaZReadWarpPtr;
    RLEBlitter* RLEBlitTransLucent50AlphaZReadWarpPtr;
    RLEBlitter* RLEBlitTransLucent25AlphaZReadWarpPtr;
    RLEBlitter* RLEBlitTransXlatAlphaZReadWritePtr;
    RLEBlitter* RLEBlitTransZRemapXlatAlphaZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent75AlphaZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent50AlphaZReadWritePtr;
    RLEBlitter* RLEBlitTransLucent25AlphaZReadWritePtr;

public:
    int field_174;
    void* field_178;
    void* Palette;
    int field_180;
    int field_184;
    int field_188;
    int field_18C;
};
