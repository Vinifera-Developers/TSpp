/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WINFONT.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Easy windows font creation.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once

#include "always.h"


/**
 *  Available font attribute styles.
 */
#define WINFONT_ATTR_BOLD       1
#define WINFONT_ATTR_ITALIC     2
#define WINFONT_ATTR_UNDERLINE  4
#define WINFONT_ATTR_STRIKEOUT  8


HFONT WinCreateFont(HDC hdc, TCHAR * szFaceName, int iDeciPtWidth, int iDeciPtHeight, int iAttributes);
