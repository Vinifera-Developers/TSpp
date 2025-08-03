/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TAB.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game tab bar interface.
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


#include "credits.h"
#include "sidebar.h"


class TabClass : public SidebarClass
{
public:
    enum {
        TAB_HEIGHT = 16
    };

public:
    TabClass();
    TabClass(const NoInitClass& x);
    ~TabClass();

    /**
     *  GScreenClass
     */
    virtual void One_Time() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;
    virtual void Draw_It(bool forced = false) override;

    /**
     *  RadarClass
     */
    virtual void Init_For_House() override;

    void Set_Active(int select); // 0060EA60
    void Flash_Money();          // 0060EAC0

    void Redraw_Tab()
    {
        IsToRedraw = true;
        Flag_To_Redraw(false);
    }

    static void Draw_Credits_Tab();  // 0060E690
    static void Hilite_Tab(int tab); // 0060E8B0

public:
    CreditClass Credits;
    CDTimerClass<FrameTimerClass> FlasherTimer;
    bool IsToRedraw;
    CDTimerClass<FrameTimerClass> MoneyFlashTimer;
};
