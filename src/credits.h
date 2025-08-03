/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CREDITS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         The animating credit counter display.
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
