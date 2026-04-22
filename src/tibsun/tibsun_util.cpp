/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game world utility functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "tibsun_util.h"
#include "language.h"
#include "msgbox.h"
#include "tactical.h"
#include "tibsun_globals.h"
#include "tibsun_inline.h"
#include "wwmouse.h"


/**
 *  Fetch the cell position from the current mouse pixel position.
 *
 *  @author: CCHyper
 */
Cell Get_Cell_Under_Mouse()
{
    Cell screen_cell(-1, -1);

    /**
     *  Fetch the mouse position.
     */
    Point2D mouse = MouseCursor->Get_Mouse_Point();

    /**
     *  If mouse position is valid, convert to world coordinates and return.
     */
    if (mouse != Point2D(0, 0)) {
        screen_cell = TacticalMap->Click_Cell_Calc(mouse);
    }

    return screen_cell;
}


/**
 *  Fetch the coord position from the current mouse pixel position.
 *
 *  @author: CCHyper
 */
Coord Get_Coord_Under_Mouse()
{
    Coord mouse_coord(-1, -1, -1);

    /**
     *  Fetch the mouse position.
     */
    Point2D mouse = MouseCursor->Get_Mouse_Point();

    /**
     *  If mouse position is valid, convert to world coordinates and return.
     */
    if (mouse != Point2D(0, 0)) {
        mouse_coord = TacticalMap->Click_Cell_Calc(mouse).As_Coord();
    }

    return mouse_coord;
}


/**
 *  Displays a simple message box, returns true on "Yes" being clicked.
 *
 *  @author: CCHyper
 */
bool Simple_YesNo_WWMessageBox(const char* msg)
{
    const char* btn1 = Text_String(TXT_YES);
    const char* btn2 = Text_String(TXT_NO);
    return WWMessageBox().Process(msg, 0, btn1, btn2) == 0; // 0 == button 1
}


/**
 *  Converts a keyboard input number into a facing value.
 */
FacingType KN_To_Facing(KeyNumType input)
{
    input &= ~(KN_ALT_BIT | KN_SHIFT_BIT | KN_CTRL_BIT);

    switch (input) {
    case KN_LEFT:
        return FACING_W;

    case KN_RIGHT:
        return FACING_E;

    case KN_UP:
        return FACING_N;

    case KN_DOWN:
        return FACING_S;

    case KN_UPLEFT:
        return FACING_NW;

    case KN_UPRIGHT:
        return FACING_NE;

    case KN_DOWNLEFT:
        return FACING_SW;

    case KN_DOWNRIGHT:
        return FACING_SE;
    }

    return FACING_NONE;
}
