/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Timer interface which uses the game frame.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "ttimer.h"


extern long& Frame;


class FrameTimerClass
{
public:
    long operator()(void) const { return Frame; }
    operator long(void) const { return Frame; }
};
