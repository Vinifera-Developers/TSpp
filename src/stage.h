/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Staged timer used by animations.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ftimer.h"
#include "ttimer.h"


class StageClass
{
public:
    StageClass() : Stage(0), Timer(0), Rate(0), Step(1) {}
    StageClass(const NoInitClass& x) : Timer(x) {}

    int Fetch_Stage() const { return Stage; }
    int Fetch_Rate() const { return Rate; }
    int Fetch_Step() const { return Step; }

    void Set_Stage(int stage) { Stage = stage; }
    void Set_Rate(int rate)
    {
        Timer = rate;
        Rate = rate;
    }
    void Set_Step(int step) { Step = step; }

    void AI() {}
    bool About_To_Change() const { return Timer.Expired() && Rate != 0; }

    bool Graphic_Logic()
    {
        if (About_To_Change()) {
            Stage += Step;
            Timer = Rate;
            return true;
        }
        return false;
    };

private:
    unsigned Stage;
    CDTimerClass<FrameTimerClass> Timer;
    int Rate;
    int Step;
};
