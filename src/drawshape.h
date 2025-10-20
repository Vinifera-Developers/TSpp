/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DRAWSHAPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Shape drawing functions.
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


class Surface;
class ConvertClass;
class ShapeSet;
class Blitter;
enum ShapeFlags_Type;

/**
 *  All draw shape calls will route through these functions. It handles all
 *  draws for the C&C engine.
 */
void Draw_Shape(Surface& surface,                       // Destination surface to draw the shape to.
                ConvertClass& convert,
                const ShapeSet* shapefile,              // Pointer to the shape data file. This data file contains all the embedded shapes.
                int shapenum,                           // The shape number within the shapefile that will be drawn.
                const Point2D& point,                   // The pixel coordinates to draw the shape.
                const Rect& window,                     // The clipping rect/window to use.
                ShapeFlags_Type flags = SHAPE_NORMAL,   // The custom draw shape flags. This controls how the data is drawn to the surface.
                const char* remap = nullptr,
                int height_offset = 0,                  // looks like it's the z adjustment value.
                ZGradientType zgrad = ZGRAD_GROUND,
                int intensity = 1000,                   // some sort of color intensity 0 - 2000 (def 1000)
                const ShapeSet* z_shapefile = nullptr,
                int z_shapenum = 0,                     // The shape number within the z shape that will be drawn.
                Point2D z_off = Point2D(0, 0));

void Blit_Block(Surface& surface, ConvertClass& convert, Surface const& source, Rect const& sourcerect, Point2D const& point, Rect const& clipwindow, unsigned char const* remap = NULL, Blitter const* blitter = NULL, int = 0, ZGradientType zgrad = ZGRAD_GROUND, int = 1000, int = 0);
