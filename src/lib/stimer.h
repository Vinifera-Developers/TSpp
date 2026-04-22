/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic Windows system timer interfaces.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "always.h"
#include <mmsystem.h>
#include <windows.h>


class SystemTimerClass
{
public:
    long operator()() const { return timeGetTime() / 16; }
    operator long() const { return timeGetTime() / 16; }
};


/**
 *  Higher precision system timer (1ms).
 */
class MSTimerClass
{
public:
    MSTimerClass() { timeBeginPeriod(1); }
    ~MSTimerClass() { timeEndPeriod(1); }

    long operator()() const { return timeGetTime(); }
    operator long() const { return timeGetTime(); }
};
