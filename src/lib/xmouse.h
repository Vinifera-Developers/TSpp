/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          XMOUSE.H
 *
 *  @author        Byon_g (see notes below)
 *
 *  @contributors  tomsons26, ZivDero
 *
 *  @brief         Westwood mouse interface.
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
 *  @note          This file contains modified code for C&C Generals released
 *                 by Electronic Arts under the GPL3 license. Source:
 *                 https://github.com/electronicarts/CnC_Generals_Zero_Hour
 *
 ******************************************************************************/
#pragma once

#include "rect.h"

class ShapeSet;
class Surface;

/*
**  This class manages the "mouse cursor". It presumes the mouse behaves in the traditional
**  manner, but requires more manual management than a traditional mouse.
**
**  The mouse interface is designed with the following requirements:
**
**  1> The interface (coordinate system) must be consistent with respect to the game user.
**     This means that coordinate 0,0 is the upper left pixel of the drawable client area.
**
**  2> It must support arbitrary mouse cursor artwork size and hotspot positioning. Mouse shape
**     animation should be a simple process of just changing the mouse shape.
**
**  3> The mouse must be able to break free of the game constraints where necessary in order
**     to interface with the operating system. The transition should be easy to manage.
**
**  4> The game mouse "active" region may be a subset rectangle of the normal visible surface.
**     This bounding requirement should be transparent to system's functionality.
**
**  The system assumes that the sub-rectangle that binds the mouse to the visible surface will
**  exactly match the dimensions of any hidden surface that the mouse may have occasion to be
**  drawn upon.
*/
class Mouse
{
public:
    virtual ~Mouse() {}

    /*
    **  Sets the game-drawn mouse imagery.
    */
    virtual void Set_Cursor(Point2D const& hotspot, ShapeSet const* cursor, int shape) = 0;

    /*
    **  Controls visibility of the game-drawn mouse.
    */
    virtual bool Is_Hidden() const = 0;
    virtual void Hide_Mouse() = 0;
    virtual void Show_Mouse() = 0;

    /*
    **  Takes control of and releases control of the mouse with
    **  respect to the operating system. The mouse must be released
    **  during operations with the operating system. When the mouse is
    **  relased, it may move outside of the confining rectangle and its
    **  shape is controlled by the operating sytem.
    */
    virtual void Release_Mouse() = 0;
    virtual void Capture_Mouse() = 0;
    virtual bool Is_Captured() const = 0;

    /*
    **  Hide the mouse if it falls within this game screen region.
    */
    virtual void Conditional_Hide_Mouse(Rect region) = 0;
    virtual void Conditional_Show_Mouse() = 0;

    /*
    **  Query about the mouse visiblity state and location. If the mouse
    **  state is zero or greater, then the mouse is visible.
    */
    virtual int Get_Mouse_State() const = 0;
    virtual int Get_Mouse_X() const = 0;
    virtual int Get_Mouse_Y() const = 0;
    virtual Point2D Get_Mouse_Point() const = 0;

    /*
    ** The following two routines can be used to render the mouse onto an alternate
    **  surface.
    */
    virtual void Draw_Mouse(Surface* scr, bool issidebarsurface = false) = 0;
    virtual void Erase_Mouse(Surface* scr, bool issidebarsurface = false) = 0;

    /*
    **  Converts O/S screen coordinates into game coordinates.
    */
    virtual void Convert_Coordinate(int& x, int& y) const = 0;
};
