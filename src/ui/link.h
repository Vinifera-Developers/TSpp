/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A simple linked list.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include <new>


class NoInitClass;


class LinkClass
{
public:
    LinkClass();
    LinkClass(const NoInitClass& x);
    LinkClass(const LinkClass& link);
    virtual ~LinkClass();

    LinkClass& operator=(const LinkClass& link);

    virtual LinkClass* Get_Next() const;
    virtual LinkClass* Get_Prev() const;
    virtual LinkClass& Add(LinkClass& object);
    virtual LinkClass& Add_Tail(LinkClass& object);
    virtual LinkClass& Add_Head(LinkClass& object);
    virtual LinkClass& Head_Of_List();
    virtual LinkClass& Tail_Of_List();
    virtual void Zap();
    virtual LinkClass* Remove();

private:
    LinkClass* Next;
    LinkClass* Prev;
};
