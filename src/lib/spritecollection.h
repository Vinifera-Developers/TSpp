/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "dict.h"
#include "dsurface.h"
#include "tibsun_defines.h"


class Surface;
class BSurface;


/**
 *  The default transparency color (RGB purple).
 */
#define DEFUALT_TRANSPARENT_COLOR (unsigned)(255 >> DSurface::RedRight << DSurface::RedLeft) | (0 >> DSurface::GreenRight << DSurface::GreenLeft) | (255 >> DSurface::BlueRight << DSurface::BlueLeft)


class SpriteCollectionClass : public Dictionary
{
public:
    bool Load_PCX(const char* filename, int bpp, bool apply_palette = false);
    bool Load_Paletted_PCX(const char* filename) { return Load_PCX(filename, 2, true); }
    bool Load_Mono_PCX(const char* filename);
    bool Load_Bitmap(const char* filename, void* bitmap_file, int bitmap_file_size, int bpp);

    bool File_Loaded(const char* filename) { return Get_Image_Surface(filename) != nullptr; }

    BSurface* Get_Image_Surface(const char* filename, void* palette = nullptr);

    bool Draw(Rect& rect, Surface& dest_surface, Surface& image, int width = 0, int height = 0);
    bool Draw_Trans(Rect& rect, Surface& dest_surface, Surface& image, unsigned trans = DEFUALT_TRANSPARENT_COLOR);
    bool Draw_Alpha(Rect& rect, Surface& dest_surface, Surface& image, Surface& mask, void* palette = nullptr, bool center = false, int x_offset = 0, int y_offset = 0);
};


BSurface* Get_PCX_Image_Surface(const char* filename);
BSurface* Get_BMP_Image_Surface(const char* filename);
