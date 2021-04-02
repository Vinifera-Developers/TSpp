/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CCTOOLTIP.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Game tooltip handler.
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
#include "tooltip.h"
#include "textprint.h"


class CCToolTip : public ToolTipManager
{
    public:
        CCToolTip(HWND hWnd);
        virtual ~CCToolTip();

        virtual bool Update(const ToolTipText *text);
        virtual void Reset(const ToolTipText *text);
        virtual void entry_C(bool update = false);
        virtual void Draw(const ToolTipText *text);
        virtual const char *ToolTip_Text(int id);

    protected:
        bool field_15C;
        TextPrintType Style;
};
