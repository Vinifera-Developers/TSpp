/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ABUFFER.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Alpha panning buffer. 
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
#include "rect.h"


class BSurface;


class ABuffer
{
    public:
        ABuffer(Rect rect);
        ~ABuffer();

        int Unoffset(int pos) const { return BufferOffset - pos; }
        void Copy_To(BSurface *surface, int x, int y, int w, int h);
        void Set(unsigned int dst, int size, unsigned value);
        void Pan(int x_speed, int y_speed, unsigned value);
        bool Fill(unsigned value);
        bool Fill(unsigned value, Rect a2);
        void Update(int x, int y, int w, int h);
        unsigned int Get_Buffer_Offset(Point2D pos);
        BSurface *Get_Surface() const { return SurfacePtr; }
        const Rect &Get_Area() const { return Area; }
        unsigned int Get_Buffer_Width() const { return BufferWidth; }

    public:
        Rect Area;
        unsigned int SurfaceOffset;
        BSurface *SurfacePtr;
        unsigned int BufferStart;
        unsigned int BufferEnd;
        unsigned int BufferSize;
        unsigned int BufferOffset;
        unsigned int BufferWidth;
        unsigned int BufferHeight;
};
