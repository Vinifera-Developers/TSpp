/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Container for color remap schemes.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "hsv.h"
#include "palette.h"
#include "tibsun_defines.h"


class Surface;
class ConvertClass;


class ColorScheme
{
public:
    ColorScheme();
    ColorScheme(const char* name, HSVClass* hsv, PaletteClass* pal1, PaletteClass* pal2, int id);
    ~ColorScheme();

    bool operator==(const char* their_name) { return strcmpi(Name, their_name) == 0; }
    bool operator!=(const char* their_name) { return strcmpi(Name, their_name) != 0; }

    void Build_Light_Converters(PaletteClass* pal1, PaletteClass* pal2, int r, int g, int b);

    static ConvertClass* Build_Light_Converter(HSVClass* hsv, PaletteClass* pal1, PaletteClass* pal2, PaletteClass* pal3, Surface* surface, int shade_count, int r, int g, int b, bool* indexes);
    static ConvertClass* Build_Converter(HSVClass* hsv, PaletteClass* pal1, PaletteClass* pal2, Surface* surface, PaletteClass* pal3);

    static ColorScheme* Find_Or_Make(const char* name, HSVClass&, PaletteClass* a2, PaletteClass* a3, int a4 = 63);

public:
    int ID;
    PaletteClass Palette;
    const char* Name;
    HSVClass HSV;
    ConvertClass* Converter;
    unsigned int field_310;
    unsigned int Color;
    unsigned int BrightColor;
    unsigned int Shadow;
    unsigned int Background;
    unsigned int Corners;
    unsigned int Highlight;
    unsigned int Box;
    unsigned int Bright;
    unsigned int Underline;
    unsigned int Bar;
};

ColorScheme* Fetch_Scheme_By_Name(const char* name, int a2 = 1);
ColorSchemeType Fetch_Scheme_Index_By_Name(const char* name, int a2 = 1);
