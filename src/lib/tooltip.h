/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic tooltip handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "point.h"
#include "rect.h"
#include "search.h"
#include "textprint.h"
#include "vector.h"
#include <Windows.h>


struct ToolTip {
    ToolTip() : ID(0), Region(), Text(0) {}

    int ID;
    Rect Region;
    int Text;
};


struct ToolTipText {
    ToolTipText() : Pos(), TextWidth(0), TextHeight(0), ToolTip() {}

    Point2D Pos;
    int TextWidth;
    int TextHeight;
    char ToolTip[256];
};


class ToolTipManager
{
public:
    enum {
        TIMER_ID = 'TTIP', // Timer identifier.
    };

public:
    ToolTipManager(HWND hWnd);
    virtual ~ToolTipManager();

    virtual bool Update(const ToolTipText* text);
    virtual void Reset(const ToolTipText* text);
    virtual void Force_Redraw(bool update = false);
    virtual void Draw(const ToolTipText* text);
    virtual const char* ToolTip_Text(int id);

    void Set_Active(bool state);
    void Message_Handler(MSG* msg);

    int Get_Timer_Delay() const;
    void Set_Timer_Delay(int delay);

    int Get_Lifetime() const;
    void Set_Lifetime(int life);

    bool Find(int id, ToolTip* tooltip);
    bool Add(const ToolTip* tooltip);
    void Remove(int id);

    int Get_Count() const;

    bool Is_ToolTip_Showing() { return CurrentToolTip != nullptr; }

    ToolTip* Find_From_Pos(Point2D& point);
    bool Process();

public:
    HWND Window;
    bool IsActive;
    Point2D LastMousePos;
    ToolTip* CurrentToolTip;
    ToolTipText CurrentToolTipInfo;
    int ToolTipDelay;
    int ToolTipLifetime;
    DynamicVectorClass<ToolTip*> ToolTips;
    IndexClass<int, ToolTip*> ToolTipIndex;
};
