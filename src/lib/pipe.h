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


class Pipe
{
    Pipe(const Pipe&) = delete;
    Pipe& operator=(const Pipe&) = delete;

public:
    Pipe();
    virtual ~Pipe();

    virtual int Flush();
    virtual int End();
    virtual void Put_To(Pipe* pipe);
    virtual int Put(const void* source, int slen);

    inline void Put_To(Pipe& pipe) { Put_To(&pipe); }

public:
    Pipe* ChainTo;
    Pipe* ChainFrom;
};
