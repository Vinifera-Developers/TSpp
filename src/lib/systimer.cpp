/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Simple interface for tracking system time.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "systimer.h"
#include <Windows.h>
#include <mmsystem.h>


// Global timer instance.
SysTimeClass SystemTime;


SysTimeClass::SysTimeClass() :
    StartTime(0),
    NegTime(0)
{
    timeBeginPeriod(1);
}


SysTimeClass::~SysTimeClass()
{
    timeEndPeriod(1);
}


void SysTimeClass::Reset()
{
    int time = timeGetTime();
    StartTime = time;
    NegTime = -time;
}


int SysTimeClass::Get()
{
    static bool _is_init = false;

    if (!_is_init) {
        Reset();
        _is_init = true;
    }

    int time = timeGetTime();

    if (time < StartTime) {
        return NegTime + time;
    }

    return time - StartTime;
}


bool SysTimeClass::Is_Getting_Late()
{
    return Get() >= 0x70000000;
}
