/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TXTLABEL.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Text label gadget.
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

#include "gadget.h"
#include "colorscheme.h"
#include "textprint.h"


class TextLabelClass : public GadgetClass
{
    public:
        TextLabelClass(const char *txt, int x, int y, ColorSchemeType color, TextPrintType style);
        ~TextLabelClass();

        virtual bool Draw_Me(bool forced = false) override;

        virtual void Set_Text(const char *txt);

    public:
        unsigned long UserData1;
        unsigned long UserData2;
        TextPrintType Style;
        const char *Text;
        ColorSchemeType Color;
        int PixWidth;
};
