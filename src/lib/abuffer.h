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


class Surface;


class ABuffer
{
public:
    ABuffer(Rect rect);
    ~ABuffer();

    unsigned Get_Scroll() const { return ScrollOffset; }
    void Set_Scroll(int position) { ScrollOffset = position; }
    int Get_Scroll_Delta(int position) const { return ScrollOffset - position; }

    void Copy_To(Surface* surface, int x, int y, int w, int h);
    void Set(unsigned int dst, int size, unsigned value);
    void Pan(int x_speed, int y_speed, unsigned value);
    bool Fill(unsigned value);
    bool Fill(unsigned value, Rect a2);
    void Update(int x, int y, int w, int h);
    unsigned int Get_Buffer_Offset(Point2D pos);

    Surface* Get_Surface() const { return SurfacePtr; }

    Rect const& Get_Bounds() const { return Bounds; }
    unsigned int Get_Buffer_Width() const { return BufferWidth; }
    unsigned int Get_Buffer_End() const { return BufferEnd; }

    unsigned int ABuffer::Wrap_Overflow(unsigned int position) const
    {
        if (position >= BufferEnd) {
            position -= BufferSize;
        }
        return position;
    }


    unsigned int ABuffer::Wrap_Underflow(unsigned int position) const
    {
        if (position < BufferStart) {
            position += BufferSize;
        }
        return position;
    }

public:
    Rect Bounds;
    int SurfaceOffset;
    Surface* SurfacePtr;
    unsigned int BufferStart;
    unsigned int BufferEnd;
    unsigned int BufferSize;
    unsigned int ScrollOffset;
    int BufferWidth;
    int BufferHeight;
};
