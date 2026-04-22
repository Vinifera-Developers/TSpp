/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Map preview functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class XSurface;
class CCINIClass;


typedef struct PreviewDataStruct {
    int Width;
    int Height;
    char Data[1];
} PreviewDataStruct;


class PreviewClass
{
public:
    PreviewClass();
    ~PreviewClass();

    void Render_Preview(HWND hWnd);
    void Draw_Map();
    bool Write_Preview_INI(CCINIClass& ini);
    bool Read_Preview_INI(CCINIClass& ini);
    bool Read_PCX_Preview(const char* filename);
    bool Read_INI_Preview(const char* filename);
    PreviewDataStruct* Create_Paletted_Preview(int a1, int& size_bytes);
    void Create_Preview_Surface(PreviewDataStruct* a1);

private:
    XSurface* ImageSurface;
};
