/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Door system for buildings and units.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ftimer.h"
#include "ttimer.h"


class DoorClass
{
public:
    DoorClass();
    ~DoorClass();

    bool Is_Door_Opening() const;
    bool Is_Door_Closing() const;
    bool Has_Finished() const;
    bool Is_Door_Open() const;
    bool Is_Door_Closed() const;
    void Open_Door(double rate);
    void Close_Door(double rate);
    void Flip_State();
    void Force_Open();
    void Force_Close();
    double Get_Percent_Complete() const;
    void AI();

    bool Func1() const { return !Is_Door_Opening() && !Is_Door_Closing() && !Is_Door_Open(); }
    bool Func2() const { return !Is_Door_Opening() && !Is_Door_Closing() && !Is_Door_Open() && !Is_Door_Closed(); }


public:
    double Rate;
    ProgressTimerClass<FrameTimerClass> Timer;
    bool IsActive;    // in transition?
    bool IsToCountUp; // 0 == closed, 1 == open.
};
