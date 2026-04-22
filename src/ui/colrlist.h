/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  ListClass where each item can have a different color.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "list.h"


class ColorListClass : public ListClass
{
public:
    typedef enum SelectEnum {
        SELECT_NORMAL,    // Selected items aren't drawn differently.
        SELECT_HIGHLIGHT, // Item is highlighted.
        SELECT_BOX,       // Draw a box around the item.
        SELECT_BAR,       // Draw a bar behind the item.
        SELECT_INVERT     // Draw the string inverted.
    } SelectStyleType;

public:
    ColorListClass(int id, int x, int y, int w, int h, TextPrintType flags, const void* up, const void* down);
    virtual ~ColorListClass();

    virtual int Add_Item(int text) override;
    virtual int Add_Item(const char* text) override;
    virtual void Remove_Item(int index) override;
    virtual void Remove_Item(const char* text) override;

    virtual void Draw_Entry(int index, int x, int y, int width, bool selected);
    virtual int Add_Item(int text, ColorSchemeType color = COLORSCHEME_FIRST);
    virtual int Add_Item(const char* text, ColorSchemeType color = COLORSCHEME_FIRST);
    virtual void Set_Selected_Style(SelectStyleType style, ColorSchemeType color = COLORSCHEME_FIRST);

public:
    DynamicVectorClass<ColorSchemeType*> Colors;
    SelectStyleType Style;
    ColorSchemeType SelectColor;
};
