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
#include "tibsun_defines.h"


class XSurface;
class Buffer;
class Blitter;
class RLEBlitter;


int Buffer_Size(Surface& surface, int width, int height);
bool To_Buffer(Surface& surface, Rect const& rect, Buffer const& buffer);
bool From_Buffer(Surface& surface, Rect const& rect, Buffer const& buffer);

bool Bit_Blit(Surface& dest, Rect const& destrect, Surface& source, Rect const& sourcerect, Blitter const& blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);
bool Bit_Blit(Surface& dest, Rect const& dcliprect, Rect const& ddrect, Surface const& source, Rect const& scliprect, Rect const& ssrect, Blitter const& blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);

bool RLE_Blit(Surface& dest, Rect const& destrect, Surface const& source, Rect const& sourcerect, RLEBlitter const& blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);
bool RLE_Blit(Surface& dest, Rect const& dcliprect, Rect const& ddrect, Surface const& source, Rect const& scliprect, Rect const& ssrect, RLEBlitter const& blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0, Surface* z_shape_surface = nullptr, Point2D zoff = Point2D(0, 0));
