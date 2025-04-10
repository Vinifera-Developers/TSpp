/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWMOUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         System mouse interface.
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
#include "point.h"
#include "rect.h"
#include <windows.h>
#include <mmsystem.h>


class ShapeSet;
class XSurface;


class WWMouseClass
{
    public:
        WWMouseClass(XSurface *scr, HWND hWnd = nullptr);
        virtual ~WWMouseClass();

        virtual void Set_Cursor(Point2D *hotspot, const ShapeSet *cursor, int cursor_index);
        virtual bool Is_Locked() const;
        virtual void Hide_Mouse();
        virtual void Show_Mouse();
        virtual void Release_Mouse();
        virtual void Capture_Mouse();
        virtual bool Is_Captured() const;
        virtual void Conditional_Hide_Mouse(int x_pos, int y_pos, int width, int height);
        virtual void Conditional_Show_Mouse();
        virtual int Get_Mouse_State() const;
        virtual int Get_Mouse_X() const;
        virtual int Get_Mouse_Y() const;
        virtual Point2D Get_Mouse_XY() const;
        virtual void Draw_1(XSurface *surface, bool forced = false);
        virtual void Draw_2(XSurface *surface, bool forced = false);
        virtual void Confine_Pos(int &x, int &y) const;

        void Set_Mouse_XY(int x, int y) { MousePos.X = x; MousePos.Y = y; }
        void Set_Mouse_X(int x) { MousePos.X = x; }
        void Set_Mouse_Y(int y) { MousePos.Y = y; }

        XSurface *Get_Surface() const { return Screen; }
        bool Cursor_Set() const { return MouseCursor != nullptr; }

        void Calc_Confining_Rect();

    private:
        ShapeSet *MouseCursor;
        int MouseCursorIndex;
        HANDLE MouseMutex;
        int MouseLockCount;
        bool MouseCaptured;
        Point2D MousePos;
        XSurface *Screen;
        HWND WindowHandle;
        Rect ConfiningRect;
        Point2D MouseHot;
        XSurface *MouseBuffer;
        Rect MouseBuffRect;
        XSurface *TacticalBuffer;
        Rect TacticalBuffRect;
        XSurface *SidebarBuffer;
        Rect SidebarBuffRect;
        Rect field_7C;
        int field_8C;
        MMRESULT TimerHandle;
};
