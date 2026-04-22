/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Functions for blitting, scaling, and rotating bitmaps.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "point.h"


class Surface;


class BitmapClass
{
public:
    BitmapClass(int w, int h, unsigned char* data) : Width(w), Height(h), Data(data) {}

public:
    int Width;
    int Height;
    unsigned char* Data;
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
bool Scale_Rotate(Surface& src, BitmapClass& bmp, TPoint2D<int>& pt, int scale, unsigned char angle);
