/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STATICBUFFER.H
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
#include "tibsun_defines.h"
#include "rect.h"
#include "trect.h"
#include "point.h"


class BSurface;


struct DataStruct
{
    TRect<unsigned short> Area;
    void * BufferPos;
};

struct AreaStruct
{
    Point2D Pos;
    Rect Size;
};


class StaticBufferClass
{
    public:
        StaticBufferClass(unsigned int size);
        ~StaticBufferClass();

        DataStruct * Write_To_Surface(BSurface &surface, AreaStruct &bounds);
        DataStruct * Write_To_Surface(BSurface &surface, Rect &rect, TPoint<unsigned short> xy);

    public:
        int BufferSize;
        void * BufferPtr;
        void * CurrentBufferPtr;
};
