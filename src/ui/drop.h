/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
