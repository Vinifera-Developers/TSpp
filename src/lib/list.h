/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LIST.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Like a Windows ListBox structure
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

#include "control.h"
#include "shapebtn.h"
#include "slider.h"
#include "textprint.h"


class ListClass : public ControlClass
{
    public:
        ListClass(int id, int x, int y, int w, int h, TextPrintType flags, void const * up, void const * down);
        ListClass(const ListClass &list);
        virtual ~ListClass();

        virtual LinkClass &Add(LinkClass &object) override;
        virtual LinkClass &Add_Tail(LinkClass &object) override;
        virtual LinkClass &Add_Head(LinkClass &object) override;
        virtual GadgetClass *Remove() override;
        virtual void Flag_To_Redraw() override;
        virtual void Peer_To_Peer(unsigned flags, KeyNumType &key, ControlClass &whom) override;
        virtual void Set_Position(int x, int y) override;
        virtual bool Draw_Me(bool forced = false) override;
        virtual bool Action(unsigned flags, KeyNumType &key) override;

        virtual int Add_Item(const char *text);
        virtual int Add_Item(int text);
        virtual int Add_Scroll_Bar();
        virtual void Bump(int up);
        virtual int Count() const;
        virtual int Current_Index() const;
        virtual char const *Current_Item() const;
        virtual char const *Get_Item(int index) const;
        virtual int Step_Selected_Index(int forward);
        virtual void Remove_Item(const char *text);
        virtual void Remove_Item(int index);
        virtual int Remove_Scroll_Bar();
        virtual void Set_Selected_Index(int index);
        virtual void Set_Selected_Index(const char *text);
        virtual void Set_Tabs(const int *tabs);
        virtual int Set_View_Index(int index);
        virtual void Step(int up);
        virtual void Draw_Entry(int index, int x, int y, int width, bool selected);

    public:
        TextPrintType TextFlags;
        const int *Tabs;
        DynamicVectorClass<const char *> List;
        int LineHeight;
        int LineCount;
        bool IsScrollActive;
        ShapeButtonClass UpGadget;
        ShapeButtonClass DownGadget;
        SliderClass ScrollGadget;
        int SelectedIndex;
        int CurrentTopIndex;
};
