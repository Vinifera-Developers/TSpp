/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SPRITE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Functions for blitting, scaling, and rotating bitmaps.
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
#include "point.h"


class Surface;


class BitmapClass
{
    public:
        BitmapClass(int w, int h, unsigned char *data) : Width(w), Height(h), Data(data) {}

    public:
        int Width;
        int Height;
        unsigned char *Data;
};


/**
 *  Using Bi-Linear Interpolation, draws a scaled and rotated
 *  bitmap onto the buffer. No clipping is performed, so beware!
 *  
 *  bmp     - bitmap to draw.
 *  pt      - desired position of the center.
 *  scale   - scale factor.
 *  angle   - 8bit angle (0=0deg, 255=360deg)
 *  
 */
bool Scale_Rotate(Surface &src, BitmapClass &bmp, TPoint2D<int> &pt, int scale, unsigned char angle);
