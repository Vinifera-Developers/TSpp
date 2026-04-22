/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Monochrome debug monitor support.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class MonoClass
{
public:
    typedef enum MonoAttribute {
        INVISIBLE = 0x00,
        UNDERLINE = 0x01,
        BLINKING = 0x90,
        NORMAL = 0x02,
        INVERSE = 0x70,
    } MonoAttribute;

    MonoClass();
    ~MonoClass();

    void Pan(int cols = 1);
    void Sub_Window(int x = 0, int y = 0, int w = -1, int h = -1);
    void Set_Cursor(int x, int y);
    void Clear();
    void Fill_Attrib(int x, int y, int w, int h, MonoAttribute attrib);
    void Scroll(int lines = 1);
    void Printf(char const* text, ...);
    void Printf(int text, ...);
    void Print(char const* text);
    void Print(int text);
    void Set_Default_Attribute(MonoAttribute attrib);
    void Text_Print(char const* text, int x, int y, MonoAttribute attrib = NORMAL);
    void Text_Print(int text, int x, int y, MonoAttribute attrib = NORMAL);
    void View();

    static void Enable() { Enabled = true; }
    static void Disable() { Enabled = false; }
    static bool Is_Enabled() { return Enabled; }
    static MonoClass* Get_Current() { return Current; }

    MonoClass& operator=(MonoClass const&);
    MonoClass(MonoClass const&);

private:
    HANDLE Driver;

private:
    static MonoClass*& Current;
    static bool& Enabled;
};
