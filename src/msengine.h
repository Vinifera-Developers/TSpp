/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Graphic menu instance class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "rect.h"
#include "vector.h"


class MSAnim;
class MSSfx;


class MSEngine
{
public:
    MSEngine();
    virtual ~MSEngine();

public:
    int field_4;
    VectorClass<TRect<int>> Rects;
    DynamicVectorClass<MSAnim*> Anims;
    DynamicVectorClass<MSSfx*> Sounds;
};
