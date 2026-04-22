/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  The animating credit counter display.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class NoInitClass;


class CreditClass
{
public:
    CreditClass();
    CreditClass(const NoInitClass& x);
    ~CreditClass();

    void Update(bool forced = false, bool redraw = false);
    void Graphic_Logic(bool forced = false);
    void AI(bool forced = false);

public:
    long Credits;
    long Current;
    bool IsToRedraw;
    bool IsUp;
    bool IsAudible;
    int Countdown;
};
