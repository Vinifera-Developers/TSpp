/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Text label gadget.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "colorscheme.h"
#include "gadget.h"
#include "textprint.h"


class TextLabelClass : public GadgetClass
{
public:
    TextLabelClass(const char* txt, int x, int y, ColorSchemeType color, TextPrintType style);
    ~TextLabelClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual void Set_Text(const char* txt);

public:
    unsigned long UserData1;
    unsigned long UserData2;
    TextPrintType Style;
    const char* Text;
    ColorSchemeType Color;
    int PixWidth;
};
