/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Gadgets that behave like the Windows buttons.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gcntrl.h"


class ToggleClass : public ControlClass
{
public:
    ToggleClass(unsigned id, int x, int y, int w, int h);
    ~ToggleClass();

    virtual bool Action(unsigned flags, KeyNumType& key) override;

    void Turn_On();
    void Turn_Off();

public:
    bool IsPressed;
    bool IsOn;
    bool IsToggleType;
};
