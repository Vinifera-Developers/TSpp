/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for the game powerbar interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "radar.h"
#include "ttimer.h"


class PowerClass : public RadarClass
{
public:
    PowerClass();
    PowerClass(const NoInitClass& x);
    ~PowerClass();

    /**
     *  GScreenClass
     */
    virtual void One_Time() override;
    virtual void Init_Clear() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;
    virtual void Draw_It(bool forced = false) override;

    /**
     *  DisplayClass
     */
    virtual const char* Help_Text(int text) override;
    virtual void Shift_Sidebar() override;

    /**
     *  RadarClass
     */
    virtual void Init_For_House() override;

    // 005AB100
    // 005AB140
    // 005AB1F0
    // 005AB240
    // 005AB260
    // 005AB6E0
    // 005AB750

    void Redraw_Power()
    {
        IsToRedraw = true;
        Flag_To_Redraw(false);
    }

public:
    bool IsToRedraw;
    CDTimerClass<SystemTimerClass> FlashTimer;
    int field_1504;
    CDTimerClass<SystemTimerClass> field_1508;
    int field_1514;
    int field_1518;
    int field_151C;
    bool field_1520;
    int RecordedPower;
    int RecordedDrain;
};
