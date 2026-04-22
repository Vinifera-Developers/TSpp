/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base class for the game screen interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "igamemap.h"
#include "point.h"
#include "tibsun_defines.h"
#include "wwkeyboard.h"


class NoInitClass;
class GadgetClass;
class Surface;


class GScreenClass : public IGameMap
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

public:
    GScreenClass();
    GScreenClass(const NoInitClass& noinit);
    virtual ~GScreenClass();

    virtual void One_Time();
    virtual void Init_Theater(TheaterType theater = THEATER_NONE);
    virtual void Init_Clear();
    virtual void Init_IO();
    virtual void Input(KeyNumType& key, int& x, int& y);
    virtual void AI(KeyNumType& input, Point2D& xy);
    virtual void Add_A_Button(GadgetClass& gadget);
    virtual void Remove_A_Button(GadgetClass& gadget);
    virtual void Flag_To_Redraw(int flags = 0);
    virtual void Render();
    virtual void Draw_It(bool forced = false);
    virtual void Blit_Display();
    virtual void Set_Default_Mouse(MouseType mouse, bool wsmall = false) = 0;
    virtual bool Override_Mouse_Shape(MouseType mouse, bool wsmall = false) = 0;
    virtual void Revert_Mouse_Shape() = 0;
    virtual void Mouse_Small(bool wsmall = true) = 0;

    void Set_Screen_Pos(int x, int y)
    {
        ScreenX = x;
        ScreenY = y;
    }

public:
    static GadgetClass*& Buttons;

public:
    int ScreenX;
    int ScreenY;
    GScreenRedrawFlags DrawFlags;

private:
    // Copy and assignment not implemented; prevent their use by declaring as private.
    GScreenClass(const GScreenClass&);
    GScreenClass& operator=(const GScreenClass&);
};

extern Surface*& HiddenSurface;
void Update_Visible_Surface(bool flip_mouse = true, Surface* surface = HiddenSurface, Rect* rect = nullptr);
