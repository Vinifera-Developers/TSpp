/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCROLL.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game tactical scrolling interface.
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

#include "tab.h"
#include "ttimer.h"


class ScrollClass : public TabClass
{
public:
    ScrollClass();
    ScrollClass(const NoInitClass& x);
    ~ScrollClass();

    /**
     *  GScreenClass
     */
    virtual void Init_IO() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;

    /**
     *  MapClass
     */
    virtual bool entry_64() const override;

    /**
     *  DisplayClass
     */
    virtual void Abort_Drag_Select() override;
    virtual void Mouse_Right_Press(Point2D& xy = Point2D(0, 0)) override;
    virtual void Mouse_Right_Up(Point2D& xy = Point2D(0, 0)) override;

    // 005E8600
    // 005E8910
    // 005E8DD0
    // 005E91A0
    void Message_Handler(HWND hwnd, UINT& message, UINT& wParam, LONG& lParam);
    // 005E9660

public:
    int Inertia;
    bool field_1D0C;    // is scrolling allowed?
    Point2D field_1D10; // the point of the right-click location when scrolling started.
    bool field_1D18;    // to redraw or to scroll?
    bool field_1D19;    // inertia scroll related, could be IsAutoScroll.
    bool field_1D1A;    // is currently coasting or mouse button down?
};
