/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          GADGET.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         The basic gui gadget class.
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
#include "colorscheme.h"
#include "link.h"
#include "options.h"
#include "tibsun_globals.h"
#include "wwkeyboard.h"


class ControlClass;


class GadgetClass : public LinkClass
{
public:
    typedef enum FlagEnum {
        LEFTPRESS = 0x0001,    // Left mouse button press.
        LEFTHELD = 0x0002,     // Left mouse button is being held down.
        LEFTRELEASE = 0x0004,  // Left mouse button released.
        LEFTUP = 0x0008,       // Left mouse button is being held up.
        RIGHTPRESS = 0x0010,   // Right mouse button press.
        RIGHTHELD = 0x0020,    // Right mouse button is being held down.
        RIGHTRELEASE = 0x0040, // Right mouse button released.
        RIGHTUP = 0x0080,      // Right mouse button is being held up.
        KEYBOARD = 0x0100      // Keyboard input processing (maybe).
    } FlagEnum;

    typedef enum KeyModifierFlagEnum {
        KEYMOD_NONE = 0,
        KEYMOD_SHIFT = 0x01,
        KEYMOD_CTRL = 0x02,
        KEYMOD_ALT = 0x04,
    } KeyModifierFlagEnum;

public:
    GadgetClass();
    GadgetClass(int x, int y, int w, int h, unsigned flags, bool sticky = false);
    GadgetClass(const NoInitClass& x);
    GadgetClass(const GadgetClass& gadget);
    virtual ~GadgetClass();

    /**
     *  LinkClass
     */
    virtual GadgetClass* Get_Next() const override;
    virtual GadgetClass* Get_Prev() const override;
    virtual GadgetClass* Remove() override;

    virtual KeyNumType Input();
    virtual void Draw_All(bool forced = true);
    virtual void Delete_List();
    virtual ControlClass* Extract_Gadget(unsigned id);
    virtual void Flag_List_To_Redraw();
    virtual void Disable();
    virtual void Enable();
    virtual unsigned Get_ID() const;
    virtual void Flag_To_Redraw();
    virtual void Peer_To_Peer(unsigned flags, KeyNumType& key, ControlClass& whom);
    virtual void Set_Focus();
    virtual void Clear_Focus();
    virtual bool Has_Focus();
    virtual bool Is_List_To_Redraw();
    virtual bool Is_To_Redraw();
    virtual void Set_Position(int x, int y);
    virtual void Set_Size(int w, int h);
    virtual bool Draw_Me(bool forced = false);
    virtual void Sticky_Process(unsigned flags);
    virtual bool Action(unsigned flags, KeyNumType& key);
    virtual bool Clicked_On(KeyNumType& key, unsigned flags, int mouse_x, int mouse_y);

    bool Is_Enabled() const { return !IsDisabled; }

    GadgetClass* Extract_Gadget_At_Mouse(int mouse_x, int mouse_y)
    {
        int width = Options.ScreenWidth;
        int height = Options.ScreenHeight;

        Point2D mouse(mouse_x, mouse_y);

        GadgetClass* g = this;
        GadgetClass* gadget = nullptr;

        while (g != nullptr) {
            if (!g->IsDisabled) {

                if (Rect(g->X, g->Y, g->Width, g->Height).Is_Point_Within(mouse) && (g->Width * g->Height) <= (width * height)) {
                    width = g->Width;
                    height = g->Height;

                    gadget = g;
                }
            }
            g = g->Get_Next();
        }

        return gadget;
    }

    bool Is_Over_Button(int mouse_x, int mouse_y) { return (unsigned)(mouse_x - X) < (unsigned)Width && (unsigned)(mouse_y - Y) < (unsigned)Height; }

    static void Set_Color_Scheme(char* scheme) { GadgetColorScheme = scheme; }
    static ColorSchemeType Get_Color_Scheme();

public:
    int X;
    int Y;
    int Width;
    int Height;
    bool IsToRepaint;
    bool IsSticky;
    static GadgetClass*& StuckOn;
    bool IsDisabled;
    unsigned Flags;

protected:
    static GadgetClass*& LastList;
    static GadgetClass*& Focused;
    static char*& GadgetColorScheme;
};
