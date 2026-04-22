/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "list.h"


class CheckObject
{
public:
    CheckObject(const char* text = nullptr, bool checked = false) : Text(text), IsChecked(checked) {}

public:
    const char* Text;
    bool IsChecked;
};


class CheckListClass : public ListClass
{
public:
    typedef enum CheckListClassEnum {
        CHECK_CHAR = '\3',
        UNCHECK_CHAR = ' '
    } CheckListClassEnum;

public:
    CheckListClass(int id, int x, int y, int w, int h, TextPrintType flags, const void* up, const void* down);
    virtual ~CheckListClass();

    virtual bool Action(unsigned flags, KeyNumType& key) override;

    virtual int Add_Item(int text) override;
    virtual int Add_Item(const char* text) override;
    virtual const char* Current_Item() const override;
    virtual const char* Get_Item(int index) const override;
    virtual void Remove_Item(int text) override;
    virtual void Remove_Item(const char* text) override;
    virtual void Set_Selected_Index(int index) override;
    virtual void Set_Selected_Index(const char* text) override;
    virtual void Draw_Entry(int index, int x, int y, int width, bool selected) override;

    void Check_Item(int index, bool checked)
    {
        CheckObject* obj = (CheckObject*)ListClass::Get_Item(index);
        if (obj && obj->IsChecked != checked) {
            obj->IsChecked = checked;
            Flag_To_Redraw();
        }
    }

    bool Is_Checked(int index) const
    {
        CheckObject* obj = (CheckObject*)ListClass::Get_Item(index);
        if (obj) {
            return obj->IsChecked;
        }
        return false;
    }

    void Set_Read_Only(int rdonly) { IsReadOnly = rdonly; }

private:
    bool IsReadOnly;
};
