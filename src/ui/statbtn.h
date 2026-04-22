/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "gadget.h"
#include "textprint.h"


class StaticButtonClass : public GadgetClass
{
public:
    StaticButtonClass();
    StaticButtonClass(unsigned id, const char* text, TextPrintType style, int x, int y, int w = -1, int h = -1);
    virtual ~StaticButtonClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual void Set_Text(const char* text, bool resize = false);
    virtual void Draw_Background();
    virtual void Draw_Text(const char* text);

public:
    Buffer Background;
    char* String;
    TextPrintType PrintFlags;
};
