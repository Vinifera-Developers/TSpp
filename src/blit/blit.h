/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BLIT.H
 *
 *  @authors       CCHyper
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
