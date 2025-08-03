/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RGB.CPP
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         RGB color container class.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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
