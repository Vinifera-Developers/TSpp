/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Depth panning buffer.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "point.h"
#include "rect.h"


class Surface;


class ZBuffer
{
public:
    ZBuffer(Rect rect);
    ~ZBuffer();

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

    unsigned int ZBuffer::Wrap_Overflow(unsigned int position) const
    {
        if (position >= BufferEnd) {
            position -= BufferSize;
        }
        return position;
    }


    unsigned int ZBuffer::Wrap_Underflow(unsigned int position) const
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
