/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Unit target flash handler.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class NoInitClass;


class FlasherClass
{
public:
    FlasherClass() : FlashCount(0), IsBlushing(false) {}
    FlasherClass(const NoInitClass& noinit) {}
    ~FlasherClass() {}

    bool Process()
    {
        if (FlashCount) {
            FlashCount--;
            IsBlushing = false;

            if (FlashCount & 0x01) {
                IsBlushing = true;
            }
            return true;
        }
        return false;
    }

public:
    unsigned FlashCount;
    bool IsBlushing;
};
