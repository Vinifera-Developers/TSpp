/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DOOR.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Door system for buildings and units.
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
#include "ftimer.h"
#include "ttimer.h"


class DoorClass
{
public:
    DoorClass();
    ~DoorClass();

    bool Is_Door_Opening() const;
    bool Is_Door_Closing() const;
    bool Has_Finished() const;
    bool Is_Door_Open() const;
    bool Is_Door_Closed() const;
    void Open_Door(double rate);
    void Close_Door(double rate);
    void Flip_State();
    void Force_Open();
    void Force_Close();
    double Get_Percent_Complete() const;
    void AI();

    bool Func1() const { return !Is_Door_Opening() && !Is_Door_Closing() && !Is_Door_Open(); }
    bool Func2() const { return !Is_Door_Opening() && !Is_Door_Closing() && !Is_Door_Open() && !Is_Door_Closed(); }


public:
    double Rate;
    CDRateTimerClass<FrameTimerClass> Timer;
    bool IsActive;    // in transition?
    bool IsToCountUp; // 0 == closed, 1 == open.
};
