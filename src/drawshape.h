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


class XSurface;
class ConvertClass;
struct ShapeFileStruct;
class Point2D;
class Rect;


/**
 *  All draw shape calls will route through these functions. It handles all
 *  draws for the C&C engine.	
 */
void CC_Draw_Shape(
	XSurface *surface,						// Destination surface to draw the shape to.
	ConvertClass *drawer,
	const ShapeFileStruct *shapefile,		// Pointer to the shape data file. This data file contains all the embedded shapes.
	int shapenum,							// The shape number within the shapefile that will be drawn.
	Point2D *xy,							// The pixel coordinates to draw the shape.
	Rect *rect,								// The clipping rect/window to use.
	ShapeFlagsType flags = SHAPE_NORMAL,	// The custom draw shape flags. This controls how the data is drawn to the surface.
	int a8 = 0,
	int a9 = 0,								// looks like its the z adjustment value.
	int a10 = 0,
	int a11 = 1000,							// some sort of color intensity 0 - 2000 (def 1000)
	ShapeFileStruct *z_shape = nullptr,
	int z_framenum = 0,						// The shape number within the z shape that will be drawn.
	int z_xoff = 0,
	int z_yoff = 0);
