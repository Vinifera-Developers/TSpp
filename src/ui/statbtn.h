/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STATBTN.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         
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
#include "buff.h"
#include "textprint.h"


class StaticButtonClass : public GadgetClass
{
    public:
        StaticButtonClass();
        StaticButtonClass(unsigned id, const char *text, TextPrintType style, int x, int y, int w = -1, int h = -1);
        virtual ~StaticButtonClass();

        virtual bool Draw_Me(bool forced = false) override;

        virtual void Set_Text(const char *text, bool resize = false);
        virtual void Draw_Background();
        virtual void Draw_Text(const char *text);

    public:
        Buffer Background;
        char *String;
        TextPrintType PrintFlags;
};
