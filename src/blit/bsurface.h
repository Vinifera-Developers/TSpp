/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Buffered data surface class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "xsurface.h"


class BSurface : public XSurface
{
public:
    BSurface(int width, int height, int bbp, void* buffer = nullptr);

    void* Lock(Point2D point = Point2D(0, 0)) const override;
    int Bytes_Per_Pixel() const override;
    int Stride() const override;

public:
    int BBP;
    Buffer Buff;
};
