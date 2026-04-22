/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gcntrl.h"
#include "textprint.h"


class EditClass : public ControlClass
{
public:
    typedef enum EditStyle {
        ALPHA = 0x0001,     // Edit accepts alphabetic characters.
        NUMERIC = 0x0002,   // Edit accepts numbers.
        MISC = 0x0004,      // Edit accepts misc graphic characters.
        UPPERCASE = 0x0008, // Force to upper case.
        ALPHANUMERIC = (int)ALPHA | (int)NUMERIC | (int)MISC
    } EditStyle;

public:
    EditClass(int id, char* text, int max_len, TextPrintType flags, int x, int y, int w = -1, int h = -1, EditStyle style = ALPHANUMERIC);
    virtual ~EditClass();

    virtual void Set_Focus() override;
    virtual bool Draw_Me(bool forced = false) override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

    virtual void Set_Text(const char* text, int max_len);
    virtual const char* Get_Text();
    virtual void Draw_Background();
    virtual void Draw_Text(const char* text);
    virtual bool Handle_Key(KeyASCIIType ascii);

    void Set_Color(ColorScheme* color) { Color = color; }
    void Set_Read_Only(bool rdonly) { IsReadOnly = rdonly; }

public:
    TextPrintType TextFlags;
    EditStyle EditFlags;
    char* String;
    int MaxLength;
    int Length;
    ColorScheme* Color;
    int IsReadOnly;
};


DEFINE_ENUMERATION_OPERATORS(EditClass::EditStyle);
DEFINE_ENUMERATION_BITWISE_OPERATORS(EditClass::EditStyle);
