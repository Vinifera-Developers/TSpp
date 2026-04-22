/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic demand driven data carrier.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class Straw
{
    Straw(const Straw&) = delete;
    Straw& operator=(const Straw&) = delete;

public:
    Straw();
    virtual ~Straw();

    virtual void Get_From(Straw* pipe);
    virtual int Get(void* buffer, int slen);

    inline void Get_From(Straw& pipe) { Get_From(&pipe); }

public:
    Straw* ChainTo;
    Straw* ChainFrom;
};
