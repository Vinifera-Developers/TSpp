/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COLRLIST.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         ListClass where each item can have a different color.
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

#include "list.h"


class ColorListClass : public ListClass
{
    public:
        typedef enum SelectEnum {
            SELECT_NORMAL,        // Selected items aren't drawn differently.
            SELECT_HIGHLIGHT,     // Item is highlighted.
            SELECT_BOX,           // Draw a box around the item.
            SELECT_BAR,           // Draw a bar behind the item.
            SELECT_INVERT         // Draw the string inverted.
        } SelectStyleType;

    public:
        ColorListClass(int id, int x, int y, int w, int h, TextPrintType flags, const void *up, const void *down);
        virtual ~ColorListClass();

        virtual int Add_Item(int text) override;
        virtual int Add_Item(const char *text) override;
        virtual void Remove_Item(int index) override;
        virtual void Remove_Item(const char *text) override;

        virtual void Draw_Entry(int index, int x, int y, int width, bool selected);
        virtual int Add_Item(int text, ColorSchemeType color = COLORSCHEME_FIRST);
        virtual int Add_Item(const char *text, ColorSchemeType color = COLORSCHEME_FIRST);
        virtual void Set_Selected_Style(SelectStyleType style, ColorSchemeType color = COLORSCHEME_FIRST);

    public:
        DynamicVectorClass<ColorSchemeType *> Colors;
        SelectStyleType Style;
        ColorSchemeType SelectColor;
};
