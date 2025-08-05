/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OWNRDRAW.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Owner draw user interface.
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
