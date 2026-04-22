/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Instance of a goodie crate on the map.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "ftimer.h"
#include "tibsun_defines.h"
#include "ttimer.h"


class CrateClass
{
public:
    CrateClass();
    ~CrateClass();

    void Init();
    bool Create_Crate(Cell& cell);
    bool Is_Here(Cell& cell) const;
    bool Remove_It();

    bool Is_Expired() const;
    bool Is_Valid() const;
    void Make_Invalid();

    static bool Put_Crate(Cell& cell);
    static bool Get_Crate(Cell& cell);

private:
    CDTimerClass<FrameTimerClass> Timer;
    Cell Location;
};
