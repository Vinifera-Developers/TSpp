/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Easy windows font creation.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


/**
 *  Available font attribute styles.
 */
#define WINFONT_ATTR_BOLD      1
#define WINFONT_ATTR_ITALIC    2
#define WINFONT_ATTR_UNDERLINE 4
#define WINFONT_ATTR_STRIKEOUT 8


HFONT WinCreateFont(HDC hdc, TCHAR* szFaceName, int iDeciPtWidth, int iDeciPtHeight, int iAttributes);
