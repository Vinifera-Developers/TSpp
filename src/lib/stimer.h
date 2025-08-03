/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STIMER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic Windows system timer interfaces.
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
#include <mmsystem.h>
#include <windows.h>


class SystemTimerClass
{
public:
    long operator()() const { return timeGetTime() / 16; }
    operator long() const { return timeGetTime() / 16; }
};


/**
 *  Higher precision system timer (1ms).
 */
class MSTimerClass
{
public:
    MSTimerClass() { timeBeginPeriod(1); }
    ~MSTimerClass() { timeEndPeriod(1); }

    long operator()() const { return timeGetTime(); }
    operator long() const { return timeGetTime(); }
};
