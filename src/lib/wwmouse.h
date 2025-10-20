/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWMOUSE.H
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

#include "xmouse.h"
#include <mmsystem.h>

class BSurface;
class ShapeSet;

/*
**  Handles the mouse as it relates to the C&C game engine. It is expected that only
**  one object of this type will be created during the lifetime of the game.
*/
class WWMouseClass : public Mouse
{
public:
    /*
    **  Private constructor.
    */
    WWMouseClass(Surface* surfaceptr, HWND window);
    ~WWMouseClass() override;

    /*
    **  Maintenance callback routine.
    */
    void Process_Mouse();

    /*
    **  Sets the game-drawn mouse imagery.
    */
    void Set_Cursor(Point2D const& hotspot, ShapeSet const* cursor, int shape) override;

    /*
    **  Controls visibility of the game-drawn mouse.
    */
    bool Is_Hidden() const override;
    void Hide_Mouse() override;
    void Show_Mouse() override;

    /*
    **  Takes control of and releases control of the mouse with
    **  respect to the operating system. The mouse must be released
    **  during operations with the operating system. When the mouse is
    **  relased, it may move outside of the confining rectangle and its
    **  shape is controlled by the operating sytem.
    */
    void Release_Mouse() override;
    void Capture_Mouse() override;
    bool Is_Captured() const override;

    /*
    **  Hide the mouse if it falls within this game screen region.
    */
    void Conditional_Hide_Mouse(Rect region) override;
    void Conditional_Show_Mouse() override;

    /*
    **  Query about the mouse visiblity state and location.
    */
    int Get_Mouse_State() const override;
    int Get_Mouse_X() const override;
    int Get_Mouse_Y() const override;
    Point2D Get_Mouse_Point() const override;

    /*
    ** The following two routines can be used to render the mouse onto an alternate
    **  surface.
    */
    void Draw_Mouse(Surface* scr, bool issidebarsurface = false) override;
    void Erase_Mouse(Surface* scr, bool issidebarsurface = false) override;

    /*
    **  Converts O/S screen coordinates into game coordinates.
    */
    void Convert_Coordinate(int& x, int& y) const override;

    /*
    **  Recalculate the confining rectangle from the window.
    */
    void Calc_Confining_Rect();

protected:
    /*
    **  This specifies the mouse shape data. It records the shape set
    **  data as well as the particular image contained within.
    */
    ShapeSet const* MouseShape;
    int ShapeNumber;

    /*
    **  Used to prevent conflict between the processing callback and
    **  the normal mouse processing routines. The only potential conflict
    **  would be with the maintenance callback routine. Since this callback
    **  and the mouse class maintain a strict master/slave relationship, a
    **  simple critial section flag is all that is needed.
    */
    HANDLE MouseMutex;

    /*
    **  Mouse hide/show state. If zero or greater, the mouse is visible. Otherwise
    **  it is invisible.
    */
    long MouseState;

    /*
    **  If the mouse is being managed by this class (for the game), then this flag
    **  will be true. When the mouse has been released to be managed by the operating
    **  system, this flag will be false. However, this class will still track the mouse
    **  position.
    */
    bool IsCaptured;

    /*
    **  This is the last recorded mouse position that it was drawn to.
    */
    int MouseX;
    int MouseY;

    /*
    **  Points to the main display surface that the mouse will be drawn
    **  to as it moves.
    */
    Surface* SurfacePtr;

    /*
    **  This is the window handle that is used to bind and bias the mouse
    **  position and drawing procedures.
    */
    HWND Window;

    /*
    **  This specifies the rectangle that the game oriented mouse will be
    **  confined to on the visible surface. If the mouse is manually drawn
    **  on another surface, then this rectangle cooresponds to the hidden
    **  surface area where the mouse is to be drawn.
    */
    Rect ConfiningRect;

    /*
    **  Specifies the hot spot where the image click maps to. This is an
    **  offset from the upper left corner of the shape image.
    */
    int MouseXHot;
    int MouseYHot;

    /*
    **  Holds the background image behind the mouse to be used for
    **  restoring the surface pixels.
    */
    BSurface* Background;
    Rect SavedRegion;

    /*
    **  This is the alternate mouse background buffer to be used when the
    **  mouse is manually drawn to an alternate surface by the Draw_Mouse()
    **  function.
    */
    BSurface* Alternate;
    Rect AltRegion;

    /*
    ** This is another alternate buffer for drawing the mouse pointer across a second, adjoining
    ** offscreen buffer.
    */
    BSurface* SidebarAlternate;
    Rect SidebarAltRegion;

    /*
    **  Conditional hide mouse bounding rectangle and mouse state
    **  flag.
    */
    Rect ConditionalRect;
    int ConditionalState;

    /*
    **  Maintenance timer handle.
    */
    MMRESULT TimerHandle;

    // Determines if there is valid mouse shape data available.
    bool Is_Data_Valid() const;
    bool Validate_Copy_Buffer();

    void Save_Background();
    void Restore_Background();

    Rect Matching_Rect() const;
    void Raw_Draw_Mouse(Surface* surface, int xoffset, int yoffset);
    void Get_Bounded_Position(int& x, int& y) const;
    void Update_Mouse_Position(int x, int y, bool forced);

    void Low_Show_Mouse();
    void Low_Hide_Mouse();

    void Block_Mouse();
    void Unblock_Mouse();
    // bool Is_Blocked() const {return(Blocked != 0);}
};

extern Mouse*& MouseCursor;
inline void Hide_Mouse() {MouseCursor->Hide_Mouse();}
inline void Show_Mouse() {MouseCursor->Show_Mouse();}
inline void Conditional_Hide_Mouse(Rect rect) {MouseCursor->Conditional_Hide_Mouse(rect);}
inline void Conditional_Show_Mouse() {MouseCursor->Conditional_Show_Mouse();}
inline int Get_Mouse_State() {return MouseCursor->Get_Mouse_State();}
inline void Set_Mouse_Cursor(Point2D const & hotspot, ShapeSet const * cursor, int shape) {MouseCursor->Set_Cursor(hotspot, cursor, shape);}
inline int Get_Mouse_X() {return MouseCursor->Get_Mouse_X();}
inline int Get_Mouse_Y() {return MouseCursor->Get_Mouse_Y();}
inline Point2D Get_Mouse_Point() {return MouseCursor->Get_Mouse_Point();}
