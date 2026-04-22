/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game tooltip handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "textprint.h"
#include "tooltip.h"


class CCToolTip : public ToolTipManager
{
public:
    CCToolTip(HWND hWnd);
    virtual ~CCToolTip();

    virtual bool Update(const ToolTipText* text);
    virtual void Reset(const ToolTipText* text);
    virtual void Force_Redraw(bool sidebar = false);
    virtual void Draw(const ToolTipText* text);
    virtual const char* ToolTip_Text(int id);

protected:
    bool DrawOnSidebar;
    TextPrintType Style;
};
