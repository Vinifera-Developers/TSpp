/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Unit crew and kill tracker.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class NoInitClass;


class CrewClass
{
public:
    CrewClass() {}
    CrewClass(const NoInitClass& noinit) {}
    ~CrewClass() {}

    int Made_A_Kill()
    {
        Kills++;
        return Kills;
    };

public:
    unsigned short Kills;
};
