/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base class for the templated blitters.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class Blitter
{
public:
    Blitter() {}
    virtual ~Blitter() {}

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) = 0;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) = 0;
};
