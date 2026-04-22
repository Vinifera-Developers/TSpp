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
#include "point.h"
#include "rect.h"
#include "tibsun_defines.h"


class BSurface;


struct DataStruct {
    TRect<unsigned short> Area;
    void* BufferPos;
};

struct AreaStruct {
    Point2D Pos;
    Rect Size;
};


class StaticBufferClass
{
public:
    StaticBufferClass(unsigned int size);
    ~StaticBufferClass();

    DataStruct* Write_To_Surface(BSurface& surface, AreaStruct& bounds);
    DataStruct* Write_To_Surface(BSurface& surface, Rect& rect, TPoint2D<unsigned short>);

public:
    int BufferSize;
    void* BufferPtr;
    void* CurrentBufferPtr;
};
