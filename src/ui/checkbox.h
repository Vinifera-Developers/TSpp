/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Like a Windows CheckBox structure.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "toggle.h"


class CheckBoxClass : public ToggleClass
{
public:
    CheckBoxClass(unsigned id, int x, int y);
    virtual ~CheckBoxClass();

    virtual bool Draw_Me(bool forced = false) override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;
};
