/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Simple interface for tracking system time.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class SysTimeClass
{
public:
    SysTimeClass();
    ~SysTimeClass();

    int Get();
    bool Is_Getting_Late();

private:
    void Reset();

private:
    int StartTime;
    int NegTime;
};

extern SysTimeClass SystemTime;
