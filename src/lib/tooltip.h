/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TOOLTIP.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Basic tooltip handler.
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
#include "rect.h"
#include "point.h"
#include "vector.h"
#include "search.h"
#include "textprint.h"
#include <Windows.h>


struct ToolTip
{
    ToolTip() : ID(0), Region(), Text(0) {}

    int ID;
    Rect Region;
    int Text;
};


struct ToolTipText
{
    ToolTipText() : Pos(), TextWidth(0), TextHeight(0), ToolTip() {}

    Point2D Pos;
    int TextWidth;
    int TextHeight;
    char ToolTip[256];
};


class ToolTipManager
{
    public:
        enum {
            TIMER_ID = 'TTIP', // Timer identifier.
        };

    public:
        ToolTipManager(HWND hWnd);
        virtual ~ToolTipManager();

        virtual bool Update(const ToolTipText *text);
        virtual void Reset(const ToolTipText *text);
        virtual void entry_C(bool update = false);
        virtual void Draw(const ToolTipText *text);
        virtual const char *ToolTip_Text(int id);

        void Set_Active(bool state);
        void Message_Handler(MSG *msg);

        int Get_Timer_Delay() const;
        void Set_Timer_Delay(int delay);

        int Get_Lifetime() const;
        void Set_Lifetime(int life);

        bool Find(int id, ToolTip *tooltip);
        bool Add(const ToolTip *tooltip);
        void Remove(int id);

        int Get_Count() const;

        bool Is_ToolTip_Showing() { return CurrentToolTip != nullptr; }

        ToolTip * Find_From_Pos(Point2D &point);
        bool Process();

    public:
        HWND Window;
        bool IsActive;
        Point2D LastMousePos;
        ToolTip *CurrentToolTip;
        ToolTipText CurrentToolTipInfo;
        int ToolTipDelay;
        int ToolTipLifetime;
        DynamicVectorClass<ToolTip *> ToolTips;
        IndexClass<int, ToolTip *> ToolTipIndex;
};
