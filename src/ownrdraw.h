/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Owner draw user interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


namespace OwnerDraw
{
void Init_Masks();
void Cache_Images();
void Initialize();

extern int& BorderThickness;
extern int& ColorSteps;
extern int& ScrollBarAdj;
extern COLORREF& TextColor1;
extern COLORREF& TextColor2;
extern COLORREF& CommonColor1;
extern COLORREF& CommonColor2;
extern COLORREF& ListBoxColor;
extern COLORREF& TooltipBoxColor;
extern COLORREF& ColorUnused1;

extern HFONT& FontPtr1;
extern HFONT& FontPtr2;
extern char const*& FontName1;
extern char const*& FontName2;
extern int& FontSize1;
extern int& FontSize2;
}; // namespace OwnerDraw
