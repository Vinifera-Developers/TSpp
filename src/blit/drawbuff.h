/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DRAWBUFF.H
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
class Rect;
class Buffer;
class Blitter;
class RLEBlitter;


long Surface_Size_Of_Region(XSurface &surface, int w, int h);
bool Surface_To_Buffer(XSurface &surface, Rect &rect, Buffer &src);
bool Buffer_To_Surface(XSurface &surface, Rect &rect, Buffer &src);

bool Copy_To_Surface(XSurface &tosurface, Rect &torect, XSurface &fromsurface, Rect &fromrect, Blitter &blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);
bool Copy_To_Surface(XSurface &tosurface, Rect &toarea, Rect &torect, XSurface &fromsurface, Rect &fromarea, Rect &fromrect, Blitter &blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);

bool Copy_To_Surface_RLE(XSurface &tosurface, Rect &torect, XSurface &fromsurface, Rect &fromrect, RLEBlitter &blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0);
bool Copy_To_Surface_RLE(XSurface &tosurface, Rect &toarea, Rect &torect, XSurface &fromsurface, Rect &fromarea, Rect &fromrect, RLEBlitter &blitter, int z_val = 0, ZGradientType z_gradient = ZGRAD_GROUND, int alpha_level = 1000, int warp_val = 0, XSurface *z_shape_surface = nullptr, int z_xoff = 0, int z_yoff = 0);
