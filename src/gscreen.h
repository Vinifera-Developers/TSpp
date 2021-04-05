/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          GSCREEN.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Base class for the game screen interface.
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

#include "igamemap.h"
#include "wwkeyboard.h"
#include "point.h"
#include "tibsun_defines.h"


class NoInitClass;
class GadgetClass;
class Surface;


class GScreenClass : public IGameMap
{
    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);
        IFACEMETHOD_(ULONG, AddRef)();
        IFACEMETHOD_(ULONG, Release)();

    public:
        GScreenClass();
        GScreenClass(const NoInitClass &noinit);
        virtual ~GScreenClass();

        virtual void One_Time();
        virtual void Init_Theater(TheaterType theater = THEATER_NONE);
        virtual void Init_Clear();
        virtual void Init_IO();
        virtual void Input(KeyNumType &key, int &x, int &y);
        virtual void AI(KeyNumType &input, Point2D &xy);
        virtual void Add_A_Button(GadgetClass &gadget);
        virtual void Remove_A_Button(GadgetClass &gadget);
        virtual void Flag_To_Redraw(bool complete = false);
        virtual void Render();
        virtual void Draw_It(bool forced = false);
        virtual void Blit_Display();
        virtual void Set_Default_Mouse(MouseType mouse, bool wsmall = false) = 0;
        virtual bool Override_Mouse_Shape(MouseType mouse, bool wsmall = false) = 0;
        virtual void Revert_Mouse_Shape() = 0;
        virtual void Mouse_Small(bool wsmall = true) = 0;

        void Set_Screen_Pos(int x, int y) { ScreenX = x; ScreenY = y; }

        static void Blit(bool a1, Surface *surface, int a3 = 0);

    public:
        static GadgetClass *&Buttons;

    private:
        int ScreenX;
        int ScreenY;
        unsigned IsToRedraw:1;
        unsigned IsToUpdate:1;

    private:
        // Copy and assignment not implemented; prevent their use by declaring as private.
        GScreenClass(const GScreenClass &);
        GScreenClass &operator=(const GScreenClass &);
};
