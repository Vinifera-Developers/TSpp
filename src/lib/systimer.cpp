/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SYSTIMER.CPP
 *
 *  @authors       OmniBlade, CCHyper
 *
 *  @brief         Simple interface for tracking system time.
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
#include "systimer.h"
#include <Windows.h>
#include <mmsystem.h>


// Global timer instance.
SysTimeClass SystemTime;


SysTimeClass::SysTimeClass() :
    StartTime(0),
    NegTime(0)
{
    timeBeginPeriod(1);
}


SysTimeClass::~SysTimeClass()
{
    timeEndPeriod(1);
}


void SysTimeClass::Reset()
{
    int time = timeGetTime();
    StartTime = time;
    NegTime = -time;
}


int SysTimeClass::Get()
{
    static bool _is_init = false;

    if (!_is_init) {
        Reset();
        _is_init = true;
    }

    int time = timeGetTime();

    if (time < StartTime) {
        return NegTime + time;
    }

    return time - StartTime;
}


bool SysTimeClass::Is_Getting_Late()
{
    return Get() >= 0x70000000;
}
