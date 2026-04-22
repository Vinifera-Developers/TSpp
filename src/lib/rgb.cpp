/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  RGB color container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "rgb.h"
#include <algorithm>


RGBClass RGBClass::Interpolate(RGBClass& from, RGBClass& towards, float amount)
{
    RGBClass tmp;
    tmp.Red = std::clamp(from.Red * (1.0f - amount) + towards.Red * amount, 0.0f, 255.0f);
    tmp.Green = std::clamp(from.Green * (1.0f - amount) + towards.Green * amount, 0.0f, 255.0f);
    tmp.Blue = std::clamp(from.Blue * (1.0f - amount) + towards.Blue * amount, 0.0f, 255.0f);
    return tmp;
}
