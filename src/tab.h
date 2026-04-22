/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for the game tab bar interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "credits.h"
#include "sidebar.h"


class TabClass : public SidebarClass
{
public:
    enum {
        TAB_HEIGHT = 16
    };

public:
    TabClass();
    TabClass(const NoInitClass& x);
    ~TabClass();

    /**
     *  GScreenClass
     */
    virtual void One_Time() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;
    virtual void Draw_It(bool forced = false) override;

    /**
     *  RadarClass
     */
    virtual void Init_For_House() override;

    void Set_Active(int select); // 0060EA60
    void Flash_Money();          // 0060EAC0

    void Redraw_Tab()
    {
        IsToRedraw = true;
        Flag_To_Redraw(false);
    }

    static void Draw_Credits_Tab();  // 0060E690
    static void Hilite_Tab(int tab); // 0060E8B0

public:
    CreditClass Credits;
    CDTimerClass<FrameTimerClass> FlasherTimer;
    bool IsToRedraw;
    CDTimerClass<FrameTimerClass> MoneyFlashTimer;
};
