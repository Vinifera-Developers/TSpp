/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Text button gadget.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "textprint.h"
#include "toggle.h"


class TextButtonClass : public ToggleClass
{
public:
    TextButtonClass();
    TextButtonClass(unsigned id, const char* text, TextPrintType style, int x, int y, int w = -1, int h = -1, bool blackborder = false, bool nobackground = true);
    TextButtonClass(unsigned id, int text, TextPrintType style, int x, int y, int w = -1, int h = -1, bool blackborder = false, bool nobackground = true);
    ~TextButtonClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual void Set_Text(const char* text, bool resize = false);
    virtual void Set_Text(int text, bool resize = false);
    virtual void Set_Style(TextPrintType style);
    virtual void Draw_Background();
    virtual void Draw_Text(const char* text);

protected:
    bool IsBlackBorder;
    bool NoDrawBackground;
    const char* String;
    TextPrintType PrintFlags;
};
