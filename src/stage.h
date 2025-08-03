/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STAGE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Staged timer used by animations.
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

#include "ftimer.h"
#include "ttimer.h"


class StageClass
{
public:
    StageClass() : Stage(0), Timer(0), Rate(0), Step(1) {}
    StageClass(const NoInitClass& x) : Timer(x) {}

    int Fetch_Stage() const { return Stage; }
    int Fetch_Rate() const { return Rate; }
    int Fetch_Step() const { return Step; }

    void Set_Stage(int stage) { Stage = stage; }
    void Set_Rate(int rate)
    {
        Timer = rate;
        Rate = rate;
    }
    void Set_Step(int step) { Step = step; }

    void AI() {}
    bool About_To_Change() const { return Timer.Expired() && Rate != 0; }

    bool Graphic_Logic()
    {
        if (About_To_Change()) {
            Stage += Step;
            Timer = Rate;
            return true;
        }
        return false;
    };

private:
    unsigned Stage;
    CDTimerClass<FrameTimerClass> Timer;
    int Rate;
    int Step;
};
