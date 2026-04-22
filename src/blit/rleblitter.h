/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  RLE Blitter base class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class RLEBlitter
{
public:
    RLEBlitter() {}
    virtual ~RLEBlitter() {}

    virtual void Blit(void* dest, void const* source, int length, int leadskip = 0, int z_min = 0, int z_buff = NULL, int a_buff = NULL, int alpha_level = 0, int warp_offset = 0, int zshape = NULL) const = 0;
};
