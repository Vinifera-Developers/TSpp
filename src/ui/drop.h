/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DROP.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief
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

#include "edit.h"
#include "list.h"


class DropListClass : public EditClass
{
public:
    DropListClass(int id, char* text, int max_len, TextPrintType flags, int x, int y, int w, int h, const void* up, const void* down);
    virtual ~DropListClass();

    DropListClass& operator=(const DropListClass& list);
    DropListClass(const DropListClass& list);

    virtual DropListClass& Add_Tail(LinkClass& object);
    virtual DropListClass& Add_Head(LinkClass& object);
    virtual DropListClass& Add(LinkClass& object);
    virtual void Zap();
    virtual DropListClass* Remove();

    virtual void Peer_To_Peer(unsigned flags, KeyNumType&, ControlClass& whom);
    virtual void Clear_Focus();
    virtual void Set_Position(int x, int y);

    virtual int Add_Item(const char* text);
    virtual const char* Current_Item();
    virtual int Current_Index();
    virtual void Set_Selected_Index(int index);
    virtual void Set_Selected_Index(const char* text);
    virtual int Count() const;
    virtual const char* Get_Item(int index) const;

    void Expand();
    void Collapse();

public:
    bool IsDropped;
    int ListHeight;
    ShapeButtonClass DropButton;
    ListClass List;
};
