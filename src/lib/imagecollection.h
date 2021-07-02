/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PCXIMAGES.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         
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
#include "dict.h"
#include "dsurface.h"


class Rect;
class Surface;
class BSurface;


/**
 *  The default transparency color (RGB purple).
 */
#define DEFUALT_TRANSPARENT_COLOR (unsigned)(255 >> DSurface::RedRight << DSurface::RedLeft) \
                                          | (0 >> DSurface::GreenRight << DSurface::GreenLeft) \
                                          | (255 >> DSurface::BlueRight << DSurface::BlueLeft)


class ImageCollectionClass
{
    public:
        ImageCollectionClass();
        ~ImageCollectionClass();

        bool Load_PCX(const char *filename, int bpp, bool apply_palette = false);
        bool Load_Paletted_PCX(const char *filename);
        bool Load_Bitmap(const char *filename, void *bitmap_file, int bitmap_file_size, int bpp);

        bool Exits(const char *filename) { return Get_Image_Surface(filename) != nullptr; }

        BSurface *Get_Image_Surface(const char *filename, void *palette = nullptr);

        bool Draw(Rect &rect, Surface &dest_surface, Surface &image, int width = 0, int height = 0);
        bool Draw_Trans(Rect &rect, Surface &dest_surface, Surface &image, unsigned trans = DEFUALT_TRANSPARENT_COLOR);
        bool Draw_Alpha(Rect &rect, Surface &dest_surface, Surface &image, Surface &mask, void *palette = nullptr, bool center = false, int x_offset = 0, int y_offset = 0);

    public:
        Dictionary ImageDictionary;
};
